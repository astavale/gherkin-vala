namespace Gherkin.Pickles {

	using Gee;
	using Gherkin;
	using Gherkin.Ast;

	public class Compiler {

		public ArrayList<Pickle> compile(Feature feature, string path) {
			ArrayList<Pickle> pickles = new ArrayList<Pickle>();
			GherkinDialect dialect = new GherkinDialectProvider().get_dialect(feature.language, null);

			ArrayList<Tag> featureTags = feature.tags;
			ArrayList<PickleStep> backgroundSteps = getBackgroundSteps(feature.background, path);

			foreach (ScenarioDefinition scenarioDefinition in feature.scenarioDefinitions) {
				if (scenarioDefinition is Scenario) {
					compileScenario(pickles, backgroundSteps, (Scenario) scenarioDefinition, featureTags, path);
				} else {
					compileScenarioOutline(pickles, backgroundSteps, (ScenarioOutline) scenarioDefinition, featureTags, path, dialect);
				}
			}
			return pickles;
		}

		private void compileScenario(ArrayList<Pickle> pickles, ArrayList<PickleStep> backgroundSteps, Scenario scenario, ArrayList<Tag> featureTags, string path) {
			ArrayList<PickleStep> steps = new ArrayList<PickleStep>();
			steps.add_all(backgroundSteps);

			ArrayList<Tag> scenarioTags = new ArrayList<Tag>();
			scenarioTags.add_all(featureTags);
			scenarioTags.add_all(scenario.tags);

			foreach (Step step in scenario.steps) {
				steps.add(pickleStep(step, path));
			}

			Pickle pickle = new Pickle(
					scenario.keyword + ": " + scenario.name,
					steps,
					pickleTags(scenarioTags, path),
					new ArrayList<PickleLocation>.wrap({pickleLocation(scenario.location, path)})
			);
			pickles.add(pickle);
		}

		private void compileScenarioOutline(ArrayList<Pickle> pickles, ArrayList<PickleStep> backgroundSteps, ScenarioOutline scenarioOutline, ArrayList<Tag> featureTags, string path, GherkinDialect dialect) {
			string keyword = dialect.get_scenario_keywords().get(0);
			foreach (Examples examples in scenarioOutline.examples) {
				ArrayList<TableCell> variableCells = examples.tableHeader.cells;
				foreach (TableRow values in examples.tableBody) {
					ArrayList<TableCell> valueCells = values.cells;

					ArrayList<PickleStep> steps = new ArrayList<PickleStep>();
					steps.add_all(backgroundSteps);

					ArrayList<Tag> tags = new ArrayList<Tag>();
					tags.add_all(featureTags);
					tags.add_all(scenarioOutline.tags);
					tags.add_all(examples.tags);

					foreach (Step scenarioOutlineStep in scenarioOutline.steps) {
						string stepText = interpolate(scenarioOutlineStep.text, variableCells, valueCells);

						// TODO: Use an Array of location in DataTable/DocString as well.
						// If the Gherkin AST classes supported
						// a list of locations, we could just reuse the same classes

						PickleStep pickleStep = new PickleStep(
								stepText,
								createPickleArgumentsWithCells(scenarioOutlineStep.argument, variableCells, valueCells, path),
								new ArrayList<PickleLocation>.wrap({
										pickleLocation(values.location, path),
										pickleStepLocation(scenarioOutlineStep, path)
								})
						);
						steps.add(pickleStep);
					}

					Pickle pickle = new Pickle(
							keyword + ": " + interpolate(scenarioOutline.name, variableCells, valueCells),
							steps,
							pickleTags(tags, path),
							new ArrayList<PickleLocation>.wrap({
									pickleLocation(values.location, path),
									pickleLocation(scenarioOutline.location, path)
							})
					);

					pickles.add(pickle);
				}
			}
		}

		private ArrayList<Argument> createPickleArguments(AbstractNode? argument, string path) {
			ArrayList<TableCell> noCells = new ArrayList<TableCell>();
			return createPickleArgumentsWithCells(argument, noCells, noCells, path);
		}

		private ArrayList<Argument> createPickleArgumentsWithCells(AbstractNode? argument, ArrayList<TableCell> variableCells, ArrayList<TableCell> valueCells, string path) {
			ArrayList<Argument> result = new ArrayList<Argument>();
			if (argument == null) return result;
			if (argument is DataTable) {
				DataTable t = (DataTable) argument;
				ArrayList<TableRow> rows = t.rows;
				ArrayList<PickleRow> newRows = new ArrayList<PickleRow>();
				foreach (TableRow row in rows) {
					ArrayList<TableCell> cells = row.cells;
					ArrayList<PickleCell> newCells = new ArrayList<PickleCell>();
					foreach (TableCell cell in cells) {
						newCells.add(
								new PickleCell(
										pickleLocation(cell.location, path),
										interpolate(cell.value, variableCells, valueCells)
								)
						);
					}
					newRows.add(new PickleRow(newCells));
				}
				result.add(new PickleTable(newRows));
			} else if (argument is DocString) {
				DocString ds = (DocString) argument;
				result.add(
						new PickleString(
								pickleLocation(ds.location, path),
								interpolate(ds.content, variableCells, valueCells)
						)
				);
			} else {
				throw new RuntimeException.UNEXPECTED_ARGUMENT("Unexpected argument type: %s", argument.to_string());
			}
			return result;
		}

		private ArrayList<PickleStep> getBackgroundSteps(Background? background, string path) {
			ArrayList<PickleStep> result = new ArrayList<PickleStep>();
			if (background != null) {
				foreach (Step step in background.steps) {
					result.add(pickleStep(step, path));
				}
			}
			return result;
		}

		private PickleStep pickleStep(Step step, string path) {
			return new PickleStep(
					step.text,
					createPickleArguments(step.argument, path),
					new ArrayList<PickleLocation>.wrap({pickleStepLocation(step, path)})
			);
		}

		private string interpolate(string name, ArrayList<TableCell> variableCells, ArrayList<TableCell> valueCells) {
			int col = 0;
			
			string iname = name;
			
			foreach (TableCell variableCell in variableCells) {
				TableCell valueCell = valueCells.get(col++);
				string header = variableCell.value;
				string value = valueCell.value;
				iname = iname.replace("<" + header + ">", value);
			}
			return iname;
		}

		private PickleLocation pickleStepLocation(Step step, string path) {
			return new PickleLocation(
					path,
					step.location.line,
					step.location.column + (step.keyword != null ? SymbolCounter.count_symbols(step.keyword) : 0)
			);
		}

		private PickleLocation pickleLocation(Location location, string path) {
			return new PickleLocation(path, location.line, location.column);
		}

		private ArrayList<PickleTag> pickleTags(ArrayList<Tag> tags, string path) {
			ArrayList<PickleTag> result = new ArrayList<PickleTag>();
			foreach (Tag tag in tags) {
				result.add(pickleTag(tag, path));
			}
			return result;
		}

		private PickleTag pickleTag(Tag tag, string path) {
			return new PickleTag(pickleLocation(tag.location, path), tag.name);
		}
	}
}
