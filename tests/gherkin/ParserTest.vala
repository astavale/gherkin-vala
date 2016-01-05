namespace Gherkin {

	using Gherkin.Ast;

	public class ParserTest : TestCase {

		public ParserTest() {
			base("ParserTest");
			add_test ("parses_feature_after_parse_error", parses_feature_after_parse_error);
			add_test ("change_default_language", change_default_language);
		}

		public void parses_feature_after_parse_error() {

			string in1 = "" +
					"# a comment\n" +
					"Feature: Foo\n" +
					"  Scenario: Bar\n" +
					"    Given x\n" +
					"      ```\n" +
					"      unclosed docstring\n";
			string in2 = "" +
					"Feature: Foo\n" +
					"  Scenario: Bar\n" +
					"    Given x\n" +
					"      \"\"\"\n" +
					"      closed docstring\n" +
					"      \"\"\"";
			TokenMatcher matcher = new TokenMatcher();
			Parser<Feature> parser = new Parser<Feature>(new AstBuilder());

			try {
				parser.parse_string(in1, matcher);
				assert_not_reached();
				//fail("ParserException expected");
			} catch (ParserException e) {
				// pass
			}
			Feature feature = parser.parse_string(in2, matcher);

			Json.Node root = Json.gobject_serialize(feature);
			Json.Generator generator = new Json.Generator ();
			generator.pretty = true;
			generator.set_root (root);

			var testfeature1 = generator.to_data(null);

			var feature_test = Json.gobject_from_data(typeof(Feature), "" +
				"{\"tags\":[]," +
				"\"language\":\"en\"," +
				"\"keyword\":\"Feature\"," +
				"\"name\":\"Foo\"," +
				"\"scenarioDefinitions\":[{" +
				"    \"tags\":[]," +
				"    \"keyword\":\"Scenario\"," +
				"    \"name\":\"Bar\"," +
				"    \"steps\":[{" +
				"        \"keyword\":\"Given \"," +
				"        \"text\":\"x\"," +
				"        \"argument\":{" +
				"            \"content\":\"closed docstring\"," +
				"            \"node-type\":\"DocString\"," +
				"            \"location\":{\"line\":4,\"column\":7}}," +
				"        \"node-type\":\"Step\"," +
				"        \"location\":{\"line\":3,\"column\":5}}]," +
				"    \"node-type\":\"Scenario\"," +
				"    \"location\":{\"line\":2,\"column\":3}}]," +
				"\"comments\":[]," +
				"\"node-type\":\"Feature\"," +
				"\"location\":{\"line\":1,\"column\":1}}");
				
				
			root = Json.gobject_serialize(feature_test);
			generator.set_root (root);
			var testfeature2 = generator.to_data(null);
			//message (testfeature2);
			//message (testfeature1);
			//assert (testfeature1 == testfeature2);
		}

		public void change_default_language() {

			TokenMatcher matcher = new TokenMatcher("no");
			Parser<Feature> parser = new Parser<Feature>(new AstBuilder());

			Feature feature = parser.parse_string("Egenskap: i18n support\n", matcher);

			Json.Node root = Json.gobject_serialize(feature);
			Json.Generator generator = new Json.Generator ();
			generator.pretty = true;
			generator.set_root (root);

			var testfeature1 = generator.to_data(null);

			var feature_test = Json.gobject_from_data(typeof(Feature), "" +
				"{\"tags\":[]," +
				"\"language\":\"no\"," +
				"\"keyword\":\"Egenskap\"," +
				"\"name\":\"i18n support\"," +
				"\"scenarioDefinitions\":[]," +
				"\"comments\":[]," +
				"\"node-type\":\"Feature\"," +
				"\"location\":{\"line\":1,\"column\":1}}");
			
			root = Json.gobject_serialize(feature_test);
			generator.set_root (root);
			var testfeature2 = generator.to_data(null);
			
			assert (testfeature1 == testfeature2);

		}

	}
}
