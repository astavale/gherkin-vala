namespace Gherkin.Pickles {

	using Gee;
	using Gherkin;
	using Gherkin.Ast;

	public class CompilerTest : TestCase {
		
		private Parser<Feature> parser = new Parser<Feature>(new AstBuilder());
		private Compiler compiler = new Compiler();

		public CompilerTest() {
			base("CompilerTest");
			add_test("compiles_a_scenario", compiles_a_scenario);
		}

		public void compiles_a_scenario() {
			ArrayList<Pickle> pickles = compiler.compile(parser.parse_string("" +
					"Feature: f\n" +
					"  Scenario: s\n" +
					"    Given passing\n"), "features/hello.feature");

			Json.Array array = new Json.Array.sized(pickles.size);
			
			foreach (var pickle in pickles) {
				array.add_element(Json.gobject_serialize(pickle));
			}

			Json.Node root = new Json.Node.alloc();
			root.init_array(array);
			Json.Generator generator = new Json.Generator ();
			generator.set_root (root);

			var testfeature1 = generator.to_data(null);

			var feature_test = Json.gobject_from_data(typeof(Pickle),"" +
				"  {\n" +
				"    \"name\": \"Scenario: s\",\n" +
				"    \"steps\": [\n" +
				"      {\n" +
				"        \"text\": \"passing\",\n" +
				"        \"arguments\": [],\n" +
				"        \"locations\": [\n" +
				"          {\n" +
				"            \"path\": \"features/hello.feature\",\n" +
				"            \"line\": 3,\n" +
				"            \"column\": 11\n" +
				"          }\n" +
				"        ]\n" +
				"      }\n" +
				"    ],\n" +
				"    \"tags\": [],\n" +
				"    \"locations\": [\n" +
				"      {\n" +
				"        \"path\": \"features/hello.feature\",\n" +
				"        \"line\": 2,\n" +
				"        \"column\": 3\n" +
				"      }\n" +
				"    ]\n" +
				"  }\n");

			root = Json.gobject_serialize(feature_test);
			generator.set_root (root);
			var testfeature2 = "[%s]".printf(generator.to_data(null)).strip();
			
			assert (testfeature1.strip() == testfeature2);

		}
	}
}
