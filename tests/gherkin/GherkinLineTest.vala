namespace Gherkin {

	using Gee;

	public class GherkinLineTest : TestCase {

		public GherkinLineTest () {
			base("GherkinLineTest");
			add_test ("finds_tags", finds_tags);
		}

		public void finds_tags() {
			GherkinLine gherkinLine = new GherkinLine("""    @this @is  @atag  """);
			ArrayList<GherkinLineSpan> gherkinLineSpans = gherkinLine.get_tags();

			assert(gherkinLineSpans[0].equals(new GherkinLineSpan(5, "@this")));
			assert(gherkinLineSpans[1].equals(new GherkinLineSpan(11, "@is")));
			assert(gherkinLineSpans[2].equals(new GherkinLineSpan(16, "@atag")));
		}

	}
}
