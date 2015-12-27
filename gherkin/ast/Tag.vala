namespace Gherkin.Ast {

	public class Tag : AbstractNode {
		public string name {get;set;}

		public Tag(Location location, string name) {
			base(location);
			this.name = name;
		}

	}
}
