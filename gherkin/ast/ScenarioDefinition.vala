namespace Gherkin.Ast {

	using Gee;

	public abstract class ScenarioDefinition : AbstractNode {
		public ArrayList<Tag> tags {get;set;}
		public string keyword {get;set;}
		public string name {get;set;}
		public string description {get;set;}
		public ArrayList<Step> steps {get;set;}

		public ScenarioDefinition(ArrayList<Tag> tags, Location location, string keyword, string name, string? description, ArrayList<Step> steps) {
			base(location);
			this.tags = tags;
			this.keyword = keyword;
			this.name = name;
			this.description = description;
			this.steps = steps;
		}

		public override Json.Node serialize_property (string property_name, GLib.Value value, GLib.ParamSpec pspec) {

			if (property_name == "tags") {
				var node = new Json.Node (Json.NodeType.ARRAY);
				var array = new Json.Array();
				foreach (var tag in tags)
					array.add_element(Json.gobject_serialize(tag));
				node.init_array(array);
				return node;
			}

			if (property_name == "steps") {
				var node = new Json.Node (Json.NodeType.ARRAY);
				var array = new Json.Array();
				foreach (var step in steps)
					array.add_element(Json.gobject_serialize(step));
				node.init_array(array);
				return node;
			}

			
			return base.serialize_property(property_name, value, pspec);

		}

		public override bool deserialize_property (string property_name, out GLib.Value value, GLib.ParamSpec pspec, Json.Node property_node) {
			
			if (property_name == "tags") {
				var stepvar = new ArrayList<Tag>();
				var array = property_node.get_array();
				array.foreach_element ((a,i,n) => {
					stepvar.add(Json.gobject_deserialize(typeof(Tag), n) as Tag);
				});
				value.init_from_instance(stepvar);
				return true;
			}

			if (property_name == "steps") {
				var stepvar = new ArrayList<Step>();
				var array = property_node.get_array();
				array.foreach_element ((a,i,n) => {
					stepvar.add(Json.gobject_deserialize(typeof(Step), n) as Step);
				});
				value.init_from_instance(stepvar);
				return true;
			}
			
			return base.deserialize_property (property_name, out value, pspec, property_node);
		}


	}
}
