namespace Gherkin {

	using Gee;
	using Gherkin.Ast;

	public class Token : Object {
		public IGherkinLine line {get;set;}
		public Parser.TokenType matched_type {get;set;}
		public string matched_keyword {get;set;}
		public string matched_text {get;set;}
		public ArrayList<GherkinLineSpan> matched_items {get;set;}
		public int matched_indent {get;set;}
		public GherkinDialect matched_gherkin_dialect {get;set;}
		public Location location {get;set;}

		public Token(IGherkinLine? line, Location? location) {
			this.line = line;
			this.location = location;
		}

		public bool is_EOF() {
			return line == null;
		}

		public void detach() {
			if (line != null)
				line.detach();
		}

		public string get_token_value() {
			return is_EOF() ? "EOF" : line.get_line_text(-1);
		}

		public string to_string() {
			return "%s: %s/%s".printf(matched_type.to_string(), matched_keyword, matched_text);
		}
	}
}
