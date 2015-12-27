namespace Gherkin.Pickles {

	public class PickleLocation : Object {
		public string path {get;set;}
		public int line {get;set;}
		public int column {get;set;}

		public PickleLocation(string path, int line, int column) {
			this.path = path;
			this.line = line;
			this.column = column;
		}
	}
}
