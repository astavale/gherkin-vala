namespace Gherkin.Ast {

	public class Location : Object {
		public int line {get;set;}
		public int column {get;set;}

		public Location(int line, int column) {
			this.line = line;
			this.column = column;
		}
	}
}
