namespace Gherkin {

	public class GherkinDialectProviderTest : TestCase {

		public GherkinDialectProviderTest () {
			base ("GherkinDialectProviderTest");
			add_test ("providesEmojiDialect", providesEmojiDialect);
		}

		public void providesEmojiDialect() {
			GherkinDialect em = new GherkinDialectProvider().get_dialect("em", null);
			// Need to verify a utf-8 character is 4 bytes and not 1...
			//assert(1 == em.get_scenario_keywords().get(0).length);
			assert(4 == em.get_scenario_keywords().get(0).length);
		}
	}
}
