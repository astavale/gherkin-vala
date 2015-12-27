namespace Gherkin.Ast {

	public class DocString : AbstractNode {
		public string contentType {get;set;}
		public string content {get;set;}

		public DocString(Location location, string? contentType, string content) {
			base(location);
			this.contentType = contentType;
			this.content = content;
		}

	}
}
