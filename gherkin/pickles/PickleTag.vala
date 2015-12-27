namespace Gherkin.Pickles {

	public class PickleTag : Object {
		private PickleLocation location {get;set;}
		private string name {get;set;}

		public PickleTag(PickleLocation location, string name) {
			this.location = location;
			this.name = name;
		}

	}
}
