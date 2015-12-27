namespace Gherkin.Ast {

	using Gee;

	public class Feature : AbstractNode {
		public ArrayList<Tag> tags {get;set;default=new ArrayList<Tag>();}
		public string language {get;set;}
		public string keyword {get;set;}
		public string name {get;set;}
		public string description {get;set;}
		public Background background {get;set;}
		public ArrayList<ScenarioDefinition> scenarioDefinitions {get;set;default=new ArrayList<ScenarioDefinition>();}
		public ArrayList<Comment> comments {get;set;default=new ArrayList<Comment>();}

		public Feature(
				ArrayList<Tag> tags,
				Location location,
				string language,
				string keyword,
				string name,
				string? description,
				Background? background,
				ArrayList<ScenarioDefinition> scenarioDefinitions,
				ArrayList<Comment> comments) {
			base(location);
			this.tags = tags;
			this.language = language;
			this.keyword = keyword;
			this.name = name;
			this.description = description;
			this.background = background;
			this.scenarioDefinitions = scenarioDefinitions;
			this.comments = comments;
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

			if (property_name == "scenarioDefinitions") {
				var node = new Json.Node (Json.NodeType.ARRAY);
				var array = new Json.Array();
				foreach (var def in scenarioDefinitions)
					array.add_element(Json.gobject_serialize(def));
				node.init_array(array);
				return node;
			}

			if (property_name == "comments") {
				var node = new Json.Node (Json.NodeType.ARRAY);
				var array = new Json.Array();
				foreach (var comment in comments)
					array.add_element(Json.gobject_serialize(comment));
				node.init_array(array);
				return node;
			}
			
			if (property_name == "background" && background != null) {
				return Json.gobject_serialize(background);
			}
			
			return base.serialize_property(property_name, value, pspec);

		}

	}
}
