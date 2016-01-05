namespace Gherkin {

	using Gherkin.Ast;
	using Json;

	public class GenerateAst {
		public static int main(string[] args) {
			
			Parser<Feature> parser = new Parser<Feature>(new AstBuilder());
			TokenMatcher matcher = new TokenMatcher();
			
			TimeVal time = TimeVal();
			time.get_current_time();
			long startTime = time.tv_usec;
			foreach (string fileName in args) {
				if(!fileName.has_suffix(".feature"))
					continue;

				File file = File.new_for_path(fileName);
				
				try {
					//Reader input = new InputStreamReader(new FileInputStream(fileName), "UTF-8");
					FileInputStream input = file.read();
					Feature feature = parser.parse_reader(input, matcher);

					Json.Node root = Json.gobject_serialize(feature);
					Json.Generator generator = new Json.Generator ();
					generator.pretty = true;
					generator.set_root (root);
					stdout.puts(generator.to_data(null));
				} catch (ParserException e) {
					warning(e.message);
					return 1;
				} catch (Error e) {
					warning(e.message);
					continue;
				}
			}
			time.get_current_time();
			long endTime = time.tv_usec;
			if(Environment.get_variable("GHERKIN_PERF") != null) {
				warning((endTime - startTime).to_string());
			}
			return 0;
		}
	}
}
