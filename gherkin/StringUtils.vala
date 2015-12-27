namespace Gherkin {

	using Gee;

	public class StringUtils {
		
		public static string joinv(string separator, ArrayList<string> items) {
			return join<string>((s)=>{return s;}, separator, items);
		}

		public static string join<T>(ToString<T> toString, string separator, Iterable<T> items) {
			StringBuilder sb = new StringBuilder();
			bool useSeparator = false;
			foreach (T item in items) {
				if (useSeparator) sb.append(separator);
				useSeparator = true;
				sb.append(toString(item));
			}
			return sb.str;
		}

		public static string ltrim(string s) {
			int i = 0;
			while (i < s.length && s.get(i).isspace()) {
				i++;
			}
			return s.substring(i);
		}

	}
	
	public delegate string ToString<T>(T t);
	
}
