namespace Gherkin.Ast {

	public class TableCell : AbstractNode {
		public string value {get;set;}

		public TableCell(Location location, string value) {
			base(location);
			this.value = value;
		}

	}
}
