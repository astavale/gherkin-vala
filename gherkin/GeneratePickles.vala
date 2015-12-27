namespace Gherkin {

	using Gherkin.Pickles;
	using Gherkin.Ast;
	using Gee;

	public class GeneratePickles {
		public static int main(string[] args) {

			Parser<Feature> parser = new Parser<Feature>(new AstBuilder());
			TokenMatcher matcher = new TokenMatcher();
			Compiler compiler = new Compiler();
			ArrayList<Pickle> pickles = new ArrayList<Pickle>();

			foreach (string fileName in args) {
				if(!fileName.has_suffix(".feature"))
					continue;

				File file = File.new_for_path(fileName);
				try {
					FileInputStream input = file.read();
					Feature feature = parser.parse_reader(input, matcher);
					pickles.add_all(compiler.compile(feature, fileName));
				} catch (Error e) {
					warning(e.message);
					continue;
				} catch (ParserException e) {
					warning(e.message);
					return 1;
				}
			}
			
			Json.Node root = Json.gobject_serialize(pickles);
			Json.Generator generator = new Json.Generator ();
			generator.set_root (root);
			message(generator.to_data(null));
			
			return 0;
		}
	}
}
