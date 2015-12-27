namespace Gherkin {

	using Gee;

	public class AstNode : Object {
		private HashMap<Parser.RuleType, ArrayList<Object>> subItems = new HashMap<Parser.RuleType, ArrayList<Object>>();
		public Parser.RuleType ruleType;

		public AstNode(Parser.RuleType ruleType) {
			this.ruleType = ruleType;
		}

		public void add(Parser.RuleType ruleType, Object obj) {
			ArrayList<Object> items = subItems.get(ruleType);
			if (items == null) {
				items = new ArrayList<Object>();
				subItems.set(ruleType, items);
			}
			items.add(obj);
		}

		public T get_single<T>(Parser.RuleType ruleType, T defaultResult) {
			ArrayList<Object> items = get_items(ruleType);
			return (T) (items.is_empty ? defaultResult : items.get(0));
		}

		public ArrayList<T> get_items<T>(Parser.RuleType ruleType) {
			ArrayList<T> items = (ArrayList<T>) subItems.get(ruleType);
			if (items == null) {
				return new ArrayList<T>();
			}
			return items;
		}

		public Token get_token(Parser.TokenType tokenType) {
			Parser.RuleType ruleType = (Parser.RuleType)tokenType;
			return get_single(ruleType, new Token(null, null));
		}

		public ArrayList<Token> get_tokens(Parser.TokenType tokenType) {
			return get_items((Parser.RuleType)tokenType);
		}
	}
}
