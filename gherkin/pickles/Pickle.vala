namespace Gherkin.Pickles {

	using Gee;

	public class Pickle : Object, Json.Serializable {
		public string name {get;set;}
		public ArrayList<PickleStep> steps {get;set;default=new ArrayList<PickleStep>();}
		public ArrayList<PickleTag> tags {get;set;default=new ArrayList<PickleTag>();}
		public ArrayList<PickleLocation> locations {get;set;default=new ArrayList<PickleLocation>();}

		public Pickle(string name, ArrayList<PickleStep> steps, ArrayList<PickleTag> tags, ArrayList<PickleLocation> locations) {
			this.name = name;
			this.steps = steps;
			this.tags = tags;
			this.locations = locations;
		}

		/**
		 * Json.Serializable interface implementation
		 */
		
		public Json.Node serialize_property (string property_name, GLib.Value value, GLib.ParamSpec pspec) {

			if (property_name == "steps") {
				var node = new Json.Node (Json.NodeType.ARRAY);
				var array = new Json.Array();
				foreach (var step in steps)
					array.add_element(Json.gobject_serialize(step));
				node.init_array(array);
				return node;
			}

			if (property_name == "tags") {
				var node = new Json.Node (Json.NodeType.ARRAY);
				var array = new Json.Array();
				foreach (var tag in tags)
					array.add_element(Json.gobject_serialize(tag));
				node.init_array(array);
				return node;
			}

			if (property_name == "locations") {
				var node = new Json.Node (Json.NodeType.ARRAY);
				var array = new Json.Array();
				foreach (var tag in locations)
					array.add_element(Json.gobject_serialize(tag));
				node.init_array(array);
				return node;
			}
			return default_serialize_property (property_name, value, pspec);
		}

		public virtual bool deserialize_property (string property_name, out GLib.Value value, GLib.ParamSpec pspec, Json.Node property_node) {
			
			if (pspec.value_type == typeof(string)) {
				value.init(typeof(string));
				value.set_string(property_node.get_string());
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

			if (property_name == "tags") {
				var stepvar = new ArrayList<PickleTag>();
				var array = property_node.get_array();
				array.foreach_element ((a,i,n) => {
					stepvar.add(Json.gobject_deserialize(typeof(PickleTag), n) as PickleTag);
				});
				value.init_from_instance(stepvar);
				return true;
			}

			if (property_name == "steps") {
				var stepvar = new ArrayList<PickleStep>();
				var array = property_node.get_array();
				array.foreach_element ((a,i,n) => {
					stepvar.add(Json.gobject_deserialize(typeof(PickleStep), n) as PickleStep);
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
