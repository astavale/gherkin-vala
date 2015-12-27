namespace Gherkin.Ast {

	using Gee;

	public abstract class AbstractNode : Object, Json.Serializable {
		public string node_type {get;set;}
		public Location location {get;set;}

		protected AbstractNode(Location location) {
			this.location = location;
			this.node_type = this.get_type().name().replace("GherkinAst","");
		}

		public string to_string() {
			return "(%d:%d) %s".printf(location.line, location.column, node_type);
		}

		/**
		 * Json.Serializable interface implementation
		 */
		
		public virtual Json.Node serialize_property (string property_name, GLib.Value value, GLib.ParamSpec pspec) {
			return default_serialize_property (property_name, value, pspec);
		}

		public virtual bool deserialize_property (string property_name, out GLib.Value value, GLib.ParamSpec pspec, Json.Node property_node) {
			
			if (pspec.value_type == typeof(string)) {
				value.init(typeof(string));
				value.set_string(property_node.get_string());
				return true;
			}
			
			if (property_name == "location") {
				value.init_from_instance (Json.gobject_deserialize(typeof(Location), property_node) as Location);
				return true;
			}

			if (property_name == "node-type") {
				value.init_from_instance (this.get_type().name().replace("GherkinAst",""));
				return true;
			}

			if (property_name == "tags") {
				var stepvar = new ArrayList<Tag>();
				var array = property_node.get_array();
				array.foreach_element ((a,i,n) => {
					stepvar.add(Json.gobject_deserialize(typeof(Tag), n) as Tag);
				});
				value.init_from_instance(stepvar);
				return true;
			}

			if (property_name == "scenarioDefinitions") {
				var stepvar = new ArrayList<ScenarioDefinition>();
				var array = property_node.get_array();
				array.foreach_element ((a,i,n) => {
					stepvar.add(Json.gobject_deserialize(typeof(Scenario), n) as ScenarioDefinition);
				});
				value.init_from_instance(stepvar);
				return true;
			}

			if (property_name == "comments") {
				var stepvar = new ArrayList<Comment>();
				var array = property_node.get_array();
				array.foreach_element ((a,i,n) => {
					stepvar.add(Json.gobject_deserialize(typeof(Comment), n) as Comment);
				});
				value.init_from_instance(stepvar);
				return true;
			}
			
			if (property_name == "background") {
				value.init_from_instance(Json.gobject_deserialize(typeof(Background), property_node) as Background);
				return true;
			}

			if (property_name == "argument") {
				var objtype = "GherkinAst" + property_node.get_object().get_string_member("node-type");
				value.init_from_instance(Json.gobject_deserialize(Type.from_name(objtype), property_node) as AbstractNode);
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
