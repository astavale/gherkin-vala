namespace Gherkin {

	using Gherkin.Ast;

	/**
	 * <p>
	 * The scanner reads a gherkin doc (typically read from a .feature file) and creates a token 
	 * for each line. The tokens are passed to the parser, which outputs an AST (Abstract Syntax Tree).</p>
	 *
	 * <p>
	 * If the scanner sees a # language header, it will reconfigure itself dynamically to look for 
	 * Gherkin keywords for the associated language. The keywords are defined in gherkin-languages.json.</p>
	 */
	public class TokenScanner : Object, ITokenScanner {

		private DataInputStream reader;
		private int lineNumber;

		public TokenScanner(InputStream source) {
			this.reader = new DataInputStream(source);
		}

		public Token read() {
			try {
				string line = reader.read_line();
				Location location = new Location(++lineNumber, 0);
				return line == null ? new Token(null, location) : new Token(new GherkinLine(line), location);
			} catch (Error e) {
				throw e; //new RuntimeException(e);
			}
		}
	}
}
