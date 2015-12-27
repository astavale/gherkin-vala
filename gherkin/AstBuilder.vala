namespace Gherkin {

	using Gherkin.Ast;
	using Gee;

	public class AstBuilder : Object, Builder<Feature> {
		private ArrayQueue<AstNode> stack;
		private ArrayList<Comment> comments;

		internal class String : Object {
			
			public string str {get;set;}
			
			public String (string str) {
				this.str = str;
			}
			
		}

		public AstBuilder() {
			reset();
		}

		public void reset() {
			stack = new ArrayQueue<AstNode>();
			stack.add(new AstNode(Parser.RuleType.None));

			comments = new ArrayList<Comment>();
		}

		private AstNode current_node() {
			return stack.peek();
		}

		public void build(Token token) {
			Parser.RuleType ruleType = (Parser.RuleType)token.matched_type;
			if (token.matched_type == Parser.TokenType.Comment) {
				comments.add(new Comment(get_location(token, 0), token.matched_text));
			} else {
				current_node().add(ruleType, token);
			}
		}

		public void start_rule(Parser.RuleType ruleType) {
			stack.offer_head(new AstNode(ruleType));
		}

		public void end_rule(Parser.RuleType ruleType) {
			AstNode node = stack.poll();
			Object transformedNode = get_transformed_node(node);
			current_node().add(node.ruleType, transformedNode);
		}

		private Object get_transformed_node(AstNode node) {
			switch (node.ruleType) {
				case Parser.RuleType.Step: {
					Token stepLine = node.get_token(Parser.TokenType.StepLine);
					AbstractNode stepArg = node.get_single(Parser.RuleType.DataTable, null);
					if (stepArg == null) {
						stepArg = node.get_single(Parser.RuleType.DocString, null);
					}
					return new Step(get_location(stepLine, 0), stepLine.matched_keyword, stepLine.matched_text, stepArg);
				}
				case Parser.RuleType.DocString: {
					Token separatorToken = node.get_tokens(Parser.TokenType.DocStringSeparator).get(0);
					string contentType = separatorToken.matched_text.length > 0 ? separatorToken.matched_text : null;
					ArrayList<Token> lineTokens = node.get_tokens(Parser.TokenType.Other);
					StringBuilder content = new StringBuilder();
					bool newLine = false;
					foreach (Token lineToken in lineTokens) {
						if (newLine) content.append("\n");
						newLine = true;
						content.append(lineToken.matched_text);
					}
					return new DocString(get_location(separatorToken, 0), contentType, content.str);
				}
				case Parser.RuleType.DataTable: {
					ArrayList<TableRow> rows = get_table_rows(node);
					return new DataTable(rows);
				}
				case Parser.RuleType.Background: {
					Token backgroundLine = node.get_token(Parser.TokenType.BackgroundLine);
					string description = get_description(node);
					ArrayList<Step> steps = get_steps(node);
					return new Background(get_location(backgroundLine, 0), backgroundLine.matched_keyword, backgroundLine.matched_text, description, steps);
				}
				case Parser.RuleType.Scenario_Definition: {
					ArrayList<Tag> tags = get_tags(node);
					AstNode scenarioNode = node.get_single(Parser.RuleType.Scenario, null);

					if (scenarioNode != null) {
						Token scenarioLine = scenarioNode.get_token(Parser.TokenType.ScenarioLine);
						string description = get_description(scenarioNode);
						ArrayList<Step> steps = get_steps(scenarioNode);

						return new Scenario(tags, get_location(scenarioLine, 0), scenarioLine.matched_keyword, scenarioLine.matched_text, description, steps);
					} else {
						AstNode scenarioOutlineNode = node.get_single(Parser.RuleType.ScenarioOutline, null);
						if (scenarioOutlineNode == null) {
							throw new RuntimeException.INTERNAL_ERROR("Internal grammar error");
						}
						Token scenarioOutlineLine = scenarioOutlineNode.get_token(Parser.TokenType.ScenarioOutlineLine);
						string description = get_description(scenarioOutlineNode);
						ArrayList<Step> steps = get_steps(scenarioOutlineNode);

						ArrayList<Examples> examplesList = scenarioOutlineNode.get_items(Parser.RuleType.Examples_Definition);

						return new ScenarioOutline(tags, get_location(scenarioOutlineLine, 0), scenarioOutlineLine.matched_keyword, scenarioOutlineLine.matched_text, description, steps, examplesList);

					}
				}
				case Parser.RuleType.Examples_Definition: {
					ArrayList<Tag> tags = get_tags(node);
					AstNode examplesNode = node.get_single(Parser.RuleType.Examples, null);
					Token examplesLine = examplesNode.get_token(Parser.TokenType.ExamplesLine);
					string description = get_description(examplesNode);
					ArrayList<TableRow> rows = get_table_rows(examplesNode);
					return new Examples(get_location(examplesLine, 0), tags, examplesLine.matched_keyword, examplesLine.matched_text, description, rows.get(0), rows.slice(1, rows.size) as ArrayList<TableRow>);
				}
				case Parser.RuleType.Description: {
					ArrayList<Token> lineTokens = node.get_tokens(Parser.TokenType.Other);
					// Trim trailing empty lines
					int end = lineTokens.size;
					while (end > 0 && Regex.match_simple("\\s*", lineTokens.get(end - 1).matched_text)) {
						end--;
					}
					lineTokens = lineTokens.slice(0, end) as ArrayList<Token>;

					var str = new String(StringUtils.join<Token>((t) => {return t.matched_text;}, "\n", lineTokens));
					
					return str;

				}
				case Parser.RuleType.Feature: {
					AstNode header = node.get_single(Parser.RuleType.Feature_Header, new AstNode(Parser.RuleType.Feature_Header));
					if (header == null) return null;
					ArrayList<Tag> tags = get_tags(header);
					Token featureLine = header.get_token(Parser.TokenType.FeatureLine);
					if (featureLine == null) return null;
					Background background = node.get_single(Parser.RuleType.Background, null);
					ArrayList<ScenarioDefinition> scenarioDefinitions = node.get_items(Parser.RuleType.Scenario_Definition);
					string description = get_description(header);
					if (featureLine.matched_gherkin_dialect == null) return null;
					string language = featureLine.matched_gherkin_dialect.language;

					return new Feature(tags, get_location(featureLine, 0), language, featureLine.matched_keyword, featureLine.matched_text, description, background, scenarioDefinitions, comments);
				}

			}
			return node;
		}

		private ArrayList<TableRow> get_table_rows(AstNode node) {
			ArrayList<TableRow> rows = new ArrayList<TableRow>();
			foreach (Token token in node.get_tokens(Parser.TokenType.TableRow)) {
				rows.add(new TableRow(get_location(token, 0), get_cells(token)));
			}
			ensure_cell_count(rows);
			return rows;
		}

		private void ensure_cell_count(ArrayList<TableRow> rows) {
			if (rows.is_empty) return;

			int cellCount = rows.get(0).cells.size;
			foreach (TableRow row in rows) {
				if (row.cells.size != cellCount) {
					var location = row.location;
					throw new ParserException.AST_BUILDER("(%d:%d): %s", location.line, location.column, "inconsistent cell count within the table");
				}
			}
		}

		private ArrayList<TableCell> get_cells(Token token) {
			ArrayList<TableCell> cells = new ArrayList<TableCell>();
			foreach (GherkinLineSpan cellItem in token.matched_items) {
				cells.add(new TableCell(get_location(token, cellItem.column), cellItem.text));
			}
			return cells;
		}

		private ArrayList<Step> get_steps(AstNode node) {
			return node.get_items(Parser.RuleType.Step);
		}

		private Location get_location(Token token, int column) {
			return column == 0 ? token.location : new Location(token.location.line, column);
		}

		private string get_description(AstNode node) {
			return node.get_single(Parser.RuleType.Description, null);
		}

		private ArrayList<Tag> get_tags(AstNode node) {
			AstNode tagsNode = node.get_single(Parser.RuleType.Tags, new AstNode(Parser.RuleType.None));
			if (tagsNode == null)
				return new ArrayList<Tag>();

			ArrayList<Token> tokens = tagsNode.get_tokens(Parser.TokenType.TagLine);
			ArrayList<Tag> tags = new ArrayList<Tag>();
			foreach (Token token in tokens) {
				foreach (GherkinLineSpan tagItem in token.matched_items) {
					tags.add(new Tag(get_location(token, tagItem.column), tagItem.text));
				}
			}
			return tags;
		}

		public Feature get_result() {
			return current_node().get_single(Parser.RuleType.Feature, null);
		}
	}
}
