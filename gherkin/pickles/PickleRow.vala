namespace Gherkin.Pickles {

	using Gee;

	public class PickleRow : Object {
		public ArrayList<PickleCell> cells {get;set;}

		public PickleRow(ArrayList<PickleCell> cells) {
			this.cells = cells;
		}

	}
}
