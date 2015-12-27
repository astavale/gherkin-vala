namespace Gherkin {

	using Gee;
	using Gherkin.Ast;


	public class GherkinDialectProvider : Object, IGherkinDialectProvider {
		//private static Map<string, Map<string, ArrayList<string>>> DIALECTS;
		private string default_dialect_name;

		private static HashMap<string, GherkinDialect> dialects = new HashMap<string, GherkinDialect>();

		static construct {
			try {
				
				File file = File.new_for_uri("resource:///org/gherkin3/lib/data/gherkin-languages.json");
				
				Json.Parser parser = new Json.Parser();

				parser.load_from_stream(file.read());
				
				var node = parser.get_root();
				var obj = node.get_object();
				foreach (string name in obj.get_members()) {
					var item = obj.get_member(name);
					var dialect = Json.gobject_deserialize(typeof(GherkinDialect), item) as GherkinDialect;
					dialect.language = name;
					dialects.set(name, dialect);
				}


			} catch (Error e) {
				throw new RuntimeException.INTERNAL_ERROR(e.message);
			}
		}

		public GherkinDialectProvider(string default_dialect_name = "en") {
			this.default_dialect_name = default_dialect_name;
		}

		public GherkinDialect get_default_dialect() {
			return get_dialect(default_dialect_name, null);
		}

		public GherkinDialect get_dialect(string language, Location? location) {
		
			if (dialects.has_key(language) != true)
				throw new ParserException.NO_SUCH_LANGUAGE("(%d:%d): %s", location.line, location.column, "Language not supported: "+ language);

			return dialects.get(language);
		}
	}
}
