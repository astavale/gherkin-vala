namespace Gherkin.Ast {

	using Gee;

	public class Examples : AbstractNode {
		public ArrayList<Tag> tags {get;set;}
		public string keyword {get;set;}
		public string name {get;set;}
		public string description {get;set;}
		public TableRow tableHeader {get;set;}
		public ArrayList<TableRow> tableBody {get;set;}

		public Examples(Location location, ArrayList<Tag> tags, string keyword, string name, string? description, TableRow tableHeader, ArrayList<TableRow>? tableBody) {
			base(location);
			this.tags = tags;
			this.keyword = keyword;
			this.name = name;
			this.description = description;
			this.tableHeader = tableHeader;
			this.tableBody = tableBody;
		}

		/**
		 * Json.Serializable interface implementation
		 */
		
		public override Json.Node serialize_property (string property_name, GLib.Value value, GLib.ParamSpec pspec) {

			if (property_name == "tags") {
				var node = new Json.Node (Json.NodeType.ARRAY);
				var array = new Json.Array();
				foreach (var tag in tags)
					array.add_element(Json.gobject_serialize(tag));
				node.init_array(array);
				return node;
			}

			if (property_name == "tableBody") {
				var node = new Json.Node (Json.NodeType.ARRAY);
				var array = new Json.Array();
				foreach (var table in tableBody)
					array.add_element(Json.gobject_serialize(table));
				node.init_array(array);
				return node;
			}
			
			if (property_name == "tableHeader" && tableHeader != null) {
				return Json.gobject_serialize(tableHeader);
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

			if (property_name == "tableBody") {
				var stepvar = new ArrayList<TableRow>();
				var array = property_node.get_array();
				array.foreach_element ((a,i,n) => {
					stepvar.add(Json.gobject_deserialize(typeof(TableRow), n) as TableRow);
				});
				value.init_from_instance(stepvar);
				return true;
			}
			
			if (property_name == "tableHeader" && tableHeader != null) {
				value.init_from_instance(Json.gobject_deserialize(typeof(TableRow), property_node) as TableRow);
				return true;
			}

			return base.deserialize_property (property_name, out value, pspec, property_node);
		}


	}
}
