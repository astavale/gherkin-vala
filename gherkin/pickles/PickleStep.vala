namespace Gherkin.Pickles {

	using Gee;

	public class PickleStep : Object, Json.Serializable {
		public string text {get;set;}
		public ArrayList<Argument> arguments {get;set;}
		public ArrayList<PickleLocation> locations {get;set;}

		public PickleStep(string text, ArrayList<Argument> arguments, ArrayList<PickleLocation> locations) {
			this.text = text;
			this.arguments = arguments;
			this.locations = locations;
		}

		/**
		 * Json.Serializable interface implementation
		 */
		
		public Json.Node serialize_property (string property_name, GLib.Value value, GLib.ParamSpec pspec) {

			if (property_name == "arguments") {
				var node = new Json.Node (Json.NodeType.ARRAY);
				var array = new Json.Array();
				foreach (var tag in arguments)
					array.add_element(Json.gobject_serialize(tag));
				node.init_array(array);
				return node;
			}

			if (property_name == "locations") {
				var node = new Json.Node (Json.NodeType.ARRAY);
				var array = new Json.Array();
				foreach (var def in locations)
					array.add_element(Json.gobject_serialize(def));
				node.init_array(array);
				return node;
			}
			return default_serialize_property (property_name, value, pspec);
		}

		public bool deserialize_property (string property_name, out GLib.Value value, GLib.ParamSpec pspec, Json.Node property_node) {
			
			if (pspec.value_type == typeof(string)) {
				value.init(typeof(string));
				value.set_string(property_node.get_string());
				return true;
			}
			
			if (property_name == "arguments") {
				var stepvar = new ArrayList<Argument>();
				var array = property_node.get_array();
				array.foreach_element ((a,i,n) => {
					stepvar.add(Json.gobject_deserialize(typeof(PickleTable), n) as Argument);
				});
				value.init_from_instance(stepvar);
				return true;
			}

			if (property_name == "locations") {
				var stepvar = new ArrayList<PickleLocation>();
				var array = property_node.get_array();
				array.foreach_element ((a,i,n) => {
					stepvar.add(Json.gobject_deserialize(typeof(PickleLocation), n) as PickleLocation);
				});
				value.init_from_instance(stepvar);
				return true;
			}
		
			return default_deserialize_property (property_name, value, pspec, property_node);
		}

		public unowned GLib.ParamSpec find_property (string name) {
			GLib.Type type = this.get_type();
			GLib.ObjectClass ocl = (GLib.ObjectClass)type.class_ref();
			unowned GLib.ParamSpec? spec = ocl.find_property (name); 
			return spec;
		}

	}
}
