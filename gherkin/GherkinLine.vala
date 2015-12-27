namespace Gherkin {

	using Gee;

	public class GherkinLine : Object, IGherkinLine {
		private string lineText;
		private string trimmedLineText;

		public GherkinLine(string lineText) {
			this.lineText = lineText;
			this.trimmedLineText = lineText.chug();
		}

		public int indent() {
			return SymbolCounter.count_symbols(lineText) - SymbolCounter.count_symbols(trimmedLineText);
		}

		public void detach() {

		}

		public string get_line_text(int indentToRemove) {
			if (indentToRemove < 0 || indentToRemove > indent())
				return trimmedLineText;
			return lineText.substring(indentToRemove);
		}

		public bool is_empty() {
			return trimmedLineText.length == 0;
		}

		public bool starts_with(string prefix) {
			return trimmedLineText.has_prefix(prefix);
		}

		public string get_rest_trimmed(int length) {
			return trimmedLineText.substring(length).strip();
		}

		public ArrayList<GherkinLineSpan> get_tags() {
			return get_spans("\\s+");
		}

		public bool starts_with_title_keyword(string text) {
			int textLength = text.length;
			return trimmedLineText.length > textLength &&
					trimmedLineText.has_prefix(text) &&
					trimmedLineText.substring(textLength, GherkinLanguageConstants.TITLE_KEYWORD_SEPARATOR.length)
							 == GherkinLanguageConstants.TITLE_KEYWORD_SEPARATOR;
			// TODO aslak: extract startsWithFrom method for clarity
		}

		public ArrayList<GherkinLineSpan> get_table_cells() {
			ArrayList<GherkinLineSpan> lineSpans = new ArrayList<GherkinLineSpan>();
			StringBuilder cell = new StringBuilder();
			bool beforeFirst = true;
			int startCol = 0;
			for (int col = 0; col < trimmedLineText.length; col++) {
				char c = trimmedLineText.get(col);
				if (c == '|') {
					if (beforeFirst) {
						// Skip the first empty span
						beforeFirst = false;
					} else {
						int contentStart = 0;
						while (contentStart < cell.len && ((char)cell.data[contentStart]).isspace()) {
							contentStart++;
						}
						if (contentStart == cell.len) {
							contentStart = 0;
						}
						lineSpans.add(new GherkinLineSpan(indent() + startCol + contentStart + 2, cell.str.strip()));
						startCol = col;
					}
					cell = new StringBuilder();
				} else if (c == '\\') {
					col++;
					c = trimmedLineText.get(col);
					if (c == 'n') {
						cell.append_c('\n');
					} else {
						cell.append_c(c);
					}
				} else {
					cell.append_c(c);
				}
			}

			return lineSpans;
		}

		private ArrayList<GherkinLineSpan> get_spans(string delimiter) {
			ArrayList<GherkinLineSpan> lineSpans = new ArrayList<GherkinLineSpan>();
			Scanner scanner = new Scanner(null);
			scanner.config.cset_identifier_first = "@" + (string)scanner.config.cset_identifier_first;
			scanner.input_text(trimmedLineText, trimmedLineText.length); 
			while (!scanner.eof()) {
				scanner.get_next_token();

				if (scanner.token != TokenType.IDENTIFIER)
					continue;
				
				string cell = scanner.value.string;
				int column = (int)scanner.position - cell.length + indent() + 1;
				lineSpans.add(new GherkinLineSpan(column, cell));
			}
			return lineSpans;
		}
	}
}
