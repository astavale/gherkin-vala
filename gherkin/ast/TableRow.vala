namespace Gherkin.Ast {

	using Gee;

	public class TableRow : AbstractNode {
		public ArrayList<TableCell> cells {get;set;}

		public TableRow(Location location, ArrayList<TableCell> cells) {
			base(location);
			this.cells = cells;
		}

		public override Json.Node serialize_property (string property_name, GLib.Value value, GLib.ParamSpec pspec) {

			if (property_name == "cells") {
				var node = new Json.Node (Json.NodeType.ARRAY);
				var array = new Json.Array();
				foreach (var cell in cells)
					array.add_element(Json.gobject_serialize(cell));
				node.init_array(array);
				return node;
			}
			return base.serialize_property(property_name, value, pspec);

		}

		public override bool deserialize_property (string property_name, out GLib.Value value, GLib.ParamSpec pspec, Json.Node property_node) {
			
			if (property_name == "cells") {
				var stepvar = new ArrayList<TableCell>();
				var array = property_node.get_array();
				array.foreach_element ((a,i,n) => {
					stepvar.add(Json.gobject_deserialize(typeof(TableCell), n) as TableCell);
				});
				value.init_from_instance(stepvar);
				return true;
			}

			return base.deserialize_property (property_name, out value, pspec, property_node);
		}

	}
}
