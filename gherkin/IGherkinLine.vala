namespace Gherkin {

	using Gee;

	public interface IGherkinLine : Object {
		public abstract int indent();

		public abstract void detach();

		public abstract string get_line_text(int indentToRemove);

		public abstract bool is_empty();

		public abstract bool starts_with(string prefix);

		public abstract string get_rest_trimmed(int length);

		public abstract ArrayList<GherkinLineSpan> get_tags();

		public abstract bool starts_with_title_keyword(string keyword);

		public abstract ArrayList<GherkinLineSpan> get_table_cells();
	}
}
