namespace Gherkin.Ast {

	using Gee;

	public class DataTable : AbstractNode {
		public ArrayList<TableRow> rows {get;set;}

		public DataTable(ArrayList<TableRow> rows) {
			base(rows.get(0).location);
			this.rows = rows;
		}

		public override Json.Node serialize_property (string property_name, GLib.Value value, GLib.ParamSpec pspec) {

			if (property_name == "rows") {
				var node = new Json.Node (Json.NodeType.ARRAY);
				var array = new Json.Array();
				foreach (var row in rows)
					array.add_element(Json.gobject_serialize(row));
				node.init_array(array);
				return node;
			}
			return base.serialize_property(property_name, value, pspec);
		}

		public override bool deserialize_property (string property_name, out GLib.Value value, GLib.ParamSpec pspec, Json.Node property_node) {
			
			if (property_name == "rows") {
				var stepvar = new ArrayList<TableRow>();
				var array = property_node.get_array();
				array.foreach_element ((a,i,n) => {
					stepvar.add(Json.gobject_deserialize(typeof(TableRow), n) as TableRow);
				});
				value.init_from_instance(stepvar);
				return true;
			}
			
			return base.deserialize_property (property_name, out value, pspec, property_node);
		}

	}
}
