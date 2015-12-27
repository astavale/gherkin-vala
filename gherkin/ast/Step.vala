namespace Gherkin.Ast {

	public class Step : AbstractNode {
		public string keyword {get;set;}
		public string text {get;set;}
		public AbstractNode argument {get;set;}

		public Step(Location location, string keyword, string text, AbstractNode? argument) {
			base(location);
			this.keyword = keyword;
			this.text = text;
			this.argument = argument;
		}

	}
}
