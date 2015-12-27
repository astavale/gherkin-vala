namespace Gherkin.Pickles {

	using Gee;

	public class PickleTable : Object, Argument {

		public PickleLocation location {
			get {
				return rows.get(0).cells.get(0).location;
			}
			set {}
		}

		public ArrayList<PickleRow> rows {get;set;}

		public PickleTable(ArrayList<PickleRow> rows) {
			this.rows = rows;
		}

	}
}
