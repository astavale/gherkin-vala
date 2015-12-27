namespace Gherkin {

	public class GherkinLineSpan : Object {
		// One-based line position
		public int column;

		// text part of the line
		public string text;

		public GherkinLineSpan(int column, string text) {
			this.column = column;
			this.text = text;
		}

		public bool equals(GherkinLineSpan o) {
			if (this == o) return true;
			return column == o.column && text == o.text;

		}

		public int hash_code() {
			int result = column;
			result = 31 * result + (int)text.hash();
			return result;
		}
	}
}
