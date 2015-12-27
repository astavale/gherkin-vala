namespace Gherkin {

	using Gherkin.Ast;
	using Gee;

	public class TokenMatcher : Object, ITokenMatcher {
		public GherkinDialect current_dialect{get;private set;}


		private static Regex LANGUAGE_PATTERN; 
		private IGherkinDialectProvider dialectProvider;
		private string activeDocStringSeparator = null;
		private int indentToRemove = 0;

		static construct {
			try {
				LANGUAGE_PATTERN = new Regex("""^\\s*#\\s*language\\s*:\\s*([a-zA-Z\\-_]+)\\s*$""");
			} catch (RegexError e) {
				warning (e.message);
			}
		}

		public TokenMatcher(string default_dialect_name = "en") {
			this.dialectProvider = new GherkinDialectProvider(default_dialect_name);
			current_dialect = dialectProvider.get_default_dialect();
		}

		public void reset() {
			activeDocStringSeparator = null;
			indentToRemove = 0;
			current_dialect = dialectProvider.get_default_dialect();
		}

		protected void setTokenMatched(Token token, Parser.TokenType matched_type, string? text, string? keyword, int? indent, ArrayList<GherkinLineSpan>? items) {
			token.matched_type = matched_type;
			token.matched_keyword = keyword ?? "";
			token.matched_text =  text ?? "";
			token.matched_items = items;
			token.matched_gherkin_dialect = current_dialect;
			token.matched_indent = indent != null ? indent : (token.line == null ? 0 : token.line.indent());
			token.location = new Location(token.location.line, token.matched_indent + 1);
		}

		public bool match_EOF(Token token) {
			if (token.is_EOF()) {
				setTokenMatched(token, Parser.TokenType.EOF, null, null, null, null);
				return true;
			}
			return false;
		}

		public bool match_Other(Token token) {
			string text = token.line.get_line_text(indentToRemove); //take the entire line, except removing DocString indents
			setTokenMatched(token, Parser.TokenType.Other, unescapeDocString(text), null, 0, null);
			return true;
		}

		public bool match_Empty(Token token) {
			if (token.line.is_empty()) {
				setTokenMatched(token, Parser.TokenType.Empty, null, null, null, null);
				return true;
			}
			return false;
		}

		public bool match_Comment(Token token) {
			if (token.line.starts_with(GherkinLanguageConstants.COMMENT_PREFIX)) {
				string text = token.line.get_line_text(0); //take the entire line
				setTokenMatched(token, Parser.TokenType.Comment, text, null, 0, null);
				return true;
			}
			return false;
		}

		public bool match_Language(Token token) {
			MatchInfo matcher;
			LANGUAGE_PATTERN.match(token.line.get_line_text(0), 0, out matcher);
			if (matcher.matches()) {
				string language = matcher.fetch(1);
				setTokenMatched(token, Parser.TokenType.Language, language, null, null, null);

				current_dialect = dialectProvider.get_dialect(language, token.location);
				return true;
			}
			return false;
		}

		public bool match_TagLine(Token token) {
			if (token.line.starts_with(GherkinLanguageConstants.TAG_PREFIX)) {
				setTokenMatched(token, Parser.TokenType.TagLine, null, null, null, token.line.get_tags());
				return true;
			}
			return false;
		}

		public bool match_FeatureLine(Token token) {
			return matchTitleLine(token, Parser.TokenType.FeatureLine, current_dialect.get_feature_keywords());
		}

		public bool match_BackgroundLine(Token token) {
			return matchTitleLine(token, Parser.TokenType.BackgroundLine, current_dialect.get_background_keywords());
		}

		public bool match_ScenarioLine(Token token) {
			return matchTitleLine(token, Parser.TokenType.ScenarioLine, current_dialect.get_scenario_keywords());
		}

		public bool match_ScenarioOutlineLine(Token token) {
			return matchTitleLine(token, Parser.TokenType.ScenarioOutlineLine, current_dialect.get_scenario_outline_keywords());
		}

		public bool match_ExamplesLine(Token token) {
			return matchTitleLine(token, Parser.TokenType.ExamplesLine, current_dialect.get_examples_keywords());
		}

		private bool matchTitleLine(Token token, Parser.TokenType tokenType, ArrayList<string> keywords) {
			foreach (string keyword in keywords) {
				if (token.line.starts_with_title_keyword(keyword)) {
					string title = token.line.get_rest_trimmed(keyword.length + GherkinLanguageConstants.TITLE_KEYWORD_SEPARATOR.length);
					setTokenMatched(token, tokenType, title, keyword, null, null);
					return true;
				}
			}
			return false;
		}

		public bool match_DocStringSeparator(Token token) {
			return activeDocStringSeparator == null
					// open
					? match_docStringSeparator_with_separator(token, GherkinLanguageConstants.DOCSTRING_SEPARATOR, true) ||
					match_docStringSeparator_with_separator(token, GherkinLanguageConstants.DOCSTRING_ALTERNATIVE_SEPARATOR, true)
					// close
					: match_docStringSeparator_with_separator(token, activeDocStringSeparator, false);
		}

		private bool match_docStringSeparator_with_separator(Token token, string separator, bool isOpen) {
			if (token.line.starts_with(separator)) {
				string contentType = null;
				if (isOpen) {
					contentType = token.line.get_rest_trimmed(separator.length);
					activeDocStringSeparator = separator;
					indentToRemove = token.line.indent();
				} else {
					activeDocStringSeparator = null;
					indentToRemove = 0;
				}

				setTokenMatched(token, Parser.TokenType.DocStringSeparator, contentType, null, null, null);
				return true;
			}
			return false;
		}

		public bool match_StepLine(Token token) {
			ArrayList<string> keywords = current_dialect.get_step_keywords();
			foreach (string keyword in keywords) {
				if (token.line.starts_with(keyword)) {
					string stepText = token.line.get_rest_trimmed(keyword.length);
					setTokenMatched(token, Parser.TokenType.StepLine, stepText, keyword, null, null);
					return true;
				}
			}
			return false;
		}

		public bool match_TableRow(Token token) {
			if (token.line.starts_with(GherkinLanguageConstants.TABLE_CELL_SEPARATOR)) {
				setTokenMatched(token, Parser.TokenType.TableRow, null, null, null, token.line.get_table_cells());
				return true;
			}
			return false;
		}

		private string unescapeDocString(string text) {
			return activeDocStringSeparator != null ? text.replace("\\\"\\\"\\\"", "\"\"\"") : text;
		}
	}
}
