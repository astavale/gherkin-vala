namespace Gherkin {

	using Gherkin;
	using Gherkin.Ast;

	public class AstBuilderTest : TestCase {

		public AstBuilderTest () {
			base ("AstBuilderTest");
			add_test ("is_reusable", is_reusable);
			add_test ("build_ast", build_ast);
		}

		public void is_reusable() {
			Parser<Feature> parser = new Parser<Feature>(new AstBuilder());
			TokenMatcher matcher = new TokenMatcher();

			Feature f1 = parser.parse_string("Feature: 1", matcher);
			Feature f2 = parser.parse_string("Feature: 2", matcher);

			assert("1" == f1.name);
			assert("2" == f2.name);
		}
		
		public void build_ast () {
			Parser<Feature> parser = new Parser<Feature>(new AstBuilder());
			TokenMatcher matcher = new TokenMatcher();
			
			TimeVal time = TimeVal();
			time.get_current_time();
			long startTime = time.tv_usec;
			File file = File.new_for_path("/home/bizarro/Documents/projects/gherkin-vala/tests/testdata/good/several_examples.feature");
			try {
				FileInputStream input = file.read();
				Feature feature = parser.parse_reader(input, matcher);

				Json.Node root = Json.gobject_serialize(feature);
				Json.Generator generator = new Json.Generator ();
				generator.pretty = true;
				generator.set_root (root);
				//message(generator.to_data(null));
			} catch (Error e) {
				warning(e.message);
			} catch (ParserException e) {
				warning(e.message);
			}
			time.get_current_time();
			long endTime = time.tv_usec;
			if(Environment.get_variable("GHERKIN_PERF") != null) {
				warning((endTime - startTime).to_string());
			}
			
		}
		
	}
}
