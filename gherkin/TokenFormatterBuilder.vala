namespace Gherkin {

	public class TokenFormatterBuilder : Object, Builder<string> {
		private TokenFormatter formatter = new TokenFormatter();
		private StringBuilder tokensTextBuilder = new StringBuilder();

		public void build(Token token) {
			tokensTextBuilder.append(formatter.format_token(token)).append("\n");
		}

		public void start_rule(Parser.RuleType ruleType) {
		}

		public void end_rule(Parser.RuleType ruleType) {
		}

		public string get_result() {
			return tokensTextBuilder.str;
		}

		public void reset() {
		}
	}
}
