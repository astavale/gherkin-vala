namespace Gherkin {

	public class TokenFormatter {

		public string format_token(Token token) {
			if (token.is_EOF())
				return "EOF";

			return "(%s:%s)%s:%s/%s/%s".printf(
					token.location.line.to_string(),
					token.location.column.to_string(),
					token.matched_type.to_string(),
					token.matched_keyword,
					token.matched_text,
					token.matched_items == null ? "" : StringUtils.join<GherkinLineSpan>((o)=>{return o.column.to_string() + ":" + o.text;}, ",", token.matched_items)
			);
		}

		private string to_string(Token o) {
			return o == null ? "" : o.to_string();
		}
	}
}
