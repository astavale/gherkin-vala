namespace Gherkin.Ast {

	using Gee;

	public class Scenario : ScenarioDefinition {
		public Scenario(ArrayList<Tag> tags, Location location, string keyword, string name, string? description, ArrayList<Step> steps) {
			base(tags, location, keyword, name, description, steps);
		}
	}
}
