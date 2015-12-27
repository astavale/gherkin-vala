namespace Gherkin.Ast {

	public class Comment : AbstractNode {
		private string text {get;set;}

		public Comment(Location location, string text) {
			base(location);
			this.text = text;
		}
	}
}
