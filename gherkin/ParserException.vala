namespace Gherkin {

	using Gee;
	using Gherkin.Ast;


	public errordomain ParserException {
		AST_BUILDER,
		NO_SUCH_LANGUAGE,
		UNEXPECTED_TOKEN,
		UNEXPECTED_EOF,
		COMPOSITE_PARSER;
		
	}

	public static ParserException UnexpectedEOFException(Token receivedToken, ArrayList<string> expectedTokenTypes, string stateComment) {
		var location = receivedToken.location;
		return new ParserException.UNEXPECTED_EOF("(%d:%d): unexpected end of file, expected: %s",
			location.line, location.column, string.joinv(", ", expectedTokenTypes.to_array()));
	}

	public static ParserException UnexpectedTokenException(Token receivedToken, ArrayList<string> expectedTokenTypes, string stateComment) {
		var location = receivedToken.location.column > 1 
			? receivedToken.location
			: new Location(receivedToken.location.line, receivedToken.line.indent() + 1);
		return new ParserException.UNEXPECTED_TOKEN(
			"(%d:%d): expected: %s, got '%s'",
			location.line,
			location.column,
			string.joinv(", ", expectedTokenTypes.to_array()),
			receivedToken.get_token_value().strip()
		);
	}


	public errordomain RuntimeException {
		INTERNAL_ERROR,
		UNEXPECTED_ARGUMENT,
		ILLEGAL_STATE
	}

}
