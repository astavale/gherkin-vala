namespace Gherkin {

	using Gherkin.Ast;

	public interface IGherkinDialectProvider : Object {
		public abstract GherkinDialect get_default_dialect();

		public abstract GherkinDialect get_dialect(string language, Location? location);
	}
}
