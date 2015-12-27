namespace Gherkin.Pickles {

	public class PickleString : Object, Argument {
		public PickleLocation location {get;set;}
		public string content {get;set;}

		public PickleString(PickleLocation location, string content) {
			this.location = location;
			this.content = content;
		}

	}
}
