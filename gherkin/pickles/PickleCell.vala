namespace Gherkin.Pickles {

	public class PickleCell : Object {
		public PickleLocation location {get;set;}
		public string value {get;set;}

		public PickleCell(PickleLocation location, string value) {
			this.location = location;
			this.value = value;
		}
	}
}
