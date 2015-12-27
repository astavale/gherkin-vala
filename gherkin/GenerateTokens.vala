namespace Gherkin {

	public class GenerateTokens {
		public static int main(string[] args) {
			TokenFormatterBuilder builder = new TokenFormatterBuilder();
			Parser<string> parser = new Parser<string>(builder);
			TokenMatcher matcher = new TokenMatcher();
			foreach (string fileName in args) {
				if(!fileName.has_suffix(".feature"))
					continue;
				File file = File.new_for_path(fileName);
				try {
					FileInputStream input = file.read();
					string result = parser.parse_reader(input, matcher);
					message(result);
				} catch (Error e) {
					warning (e.message);
				}
			}
			return 0;
		}
	}
}
