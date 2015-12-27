namespace Gherkin {

	using Gee;

	public class GherkinDialect : Object {
		
		public string[] and {get;set;}
		public string[] background {get;set;}
		public string[] but {get;set;}
		public string[] examples {get;set;}
		public string[] feature {get;set;}
		public string[] given {get;set;}

		public string name {get;set;}
		public string native {get;set;}
		
		public string[] scenario {get;set;}
		public string[] scenarioOutline {get;set;}
		public string[] then {get;set;}
		public string[] when {get;set;}

		public string language {get;set;}

		private Map<string, ArrayList<string>> keywords;

		public GherkinDialect(string language, Map<string, ArrayList<string>> keywords) {
			this.language = language;
			this.keywords = keywords;
		}

		public ArrayList<string> get_feature_keywords() {
			return new ArrayList<string>.wrap(feature);
		}

		public ArrayList<string> get_scenario_keywords() {
			return new ArrayList<string>.wrap(scenario);
		}

		public ArrayList<string> get_step_keywords() {
			ArrayList<string> result = new ArrayList<string>();
			result.add_all(new ArrayList<string>.wrap(given));
			result.add_all(new ArrayList<string>.wrap(when));
			result.add_all(new ArrayList<string>.wrap(then));
			result.add_all(new ArrayList<string>.wrap(and));
			result.add_all(new ArrayList<string>.wrap(but));
			return result;
		}

		public ArrayList<string> get_background_keywords() {
			return new ArrayList<string>.wrap(background);
		}

		public ArrayList<string> get_scenario_outline_keywords() {
			return new ArrayList<string>.wrap(scenarioOutline);
		}

		public ArrayList<string> get_examples_keywords() {
			return new ArrayList<string>.wrap(examples);
		}

	}
}
