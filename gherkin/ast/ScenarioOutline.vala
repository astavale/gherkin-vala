namespace Gherkin.Ast {

	using Gee;

	public class ScenarioOutline : ScenarioDefinition {
		public ArrayList<Examples> examples {get;set;default=new ArrayList<Examples>();}

		public ScenarioOutline(ArrayList<Tag> tags, Location location, string keyword, string name, string? description, ArrayList<Step> steps, ArrayList<Examples> examples) {
			base(tags, location, keyword, name, description, steps);
			this.examples = examples;
		}

		public override Json.Node serialize_property (string property_name, GLib.Value value, GLib.ParamSpec pspec) {

			if (property_name == "examples") {
				var node = new Json.Node (Json.NodeType.ARRAY);
				var array = new Json.Array();
				foreach (var example in examples)
					array.add_element(Json.gobject_serialize(example));
				node.init_array(array);
				return node;
			}
			return base.serialize_property(property_name, value, pspec);

		}
		
		public override bool deserialize_property (string property_name, out GLib.Value value, GLib.ParamSpec pspec, Json.Node property_node) {
			
			if (property_name == "examples") {
				var stepvar = new ArrayList<Examples>();
				var array = property_node.get_array();
				array.foreach_element ((a,i,n) => {
					stepvar.add(Json.gobject_deserialize(typeof(Examples), n) as Examples);
				});
				value.init_from_instance(stepvar);
				return true;
			}

			return base.deserialize_property (property_name, out value, pspec, property_node);
		}
		
	}
}
