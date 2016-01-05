/* GeneratePickles.c generated by valac 0.30.0, the Vala compiler
 * generated from GeneratePickles.vala, do not modify */


#include <glib.h>
#include <glib-object.h>
#include <stdlib.h>
#include <string.h>
#include <libgherkin3.h>
#include <gee.h>
#include <gio/gio.h>
#include <json-glib/json-glib.h>
#include <stdio.h>
#include <gobject/gvaluecollector.h>


#define GHERKIN_TYPE_GENERATE_PICKLES (gherkin_generate_pickles_get_type ())
#define GHERKIN_GENERATE_PICKLES(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), GHERKIN_TYPE_GENERATE_PICKLES, GherkinGeneratePickles))
#define GHERKIN_GENERATE_PICKLES_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), GHERKIN_TYPE_GENERATE_PICKLES, GherkinGeneratePicklesClass))
#define GHERKIN_IS_GENERATE_PICKLES(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GHERKIN_TYPE_GENERATE_PICKLES))
#define GHERKIN_IS_GENERATE_PICKLES_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), GHERKIN_TYPE_GENERATE_PICKLES))
#define GHERKIN_GENERATE_PICKLES_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), GHERKIN_TYPE_GENERATE_PICKLES, GherkinGeneratePicklesClass))

typedef struct _GherkinGeneratePickles GherkinGeneratePickles;
typedef struct _GherkinGeneratePicklesClass GherkinGeneratePicklesClass;
typedef struct _GherkinGeneratePicklesPrivate GherkinGeneratePicklesPrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))
#define _gherkin_pickles_compiler_unref0(var) ((var == NULL) ? NULL : (var = (gherkin_pickles_compiler_unref (var), NULL)))
#define _gherkin_parser_unref0(var) ((var == NULL) ? NULL : (var = (gherkin_parser_unref (var), NULL)))
#define __vala_JsonNode_free0(var) ((var == NULL) ? NULL : (var = (_vala_JsonNode_free (var), NULL)))
typedef struct _GherkinParamSpecGeneratePickles GherkinParamSpecGeneratePickles;

struct _GherkinGeneratePickles {
	GTypeInstance parent_instance;
	volatile int ref_count;
	GherkinGeneratePicklesPrivate * priv;
};

struct _GherkinGeneratePicklesClass {
	GTypeClass parent_class;
	void (*finalize) (GherkinGeneratePickles *self);
};

struct _GherkinParamSpecGeneratePickles {
	GParamSpec parent_instance;
};


static gpointer gherkin_generate_pickles_parent_class = NULL;

gpointer gherkin_generate_pickles_ref (gpointer instance);
void gherkin_generate_pickles_unref (gpointer instance);
GParamSpec* gherkin_param_spec_generate_pickles (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void gherkin_value_set_generate_pickles (GValue* value, gpointer v_object);
void gherkin_value_take_generate_pickles (GValue* value, gpointer v_object);
gpointer gherkin_value_get_generate_pickles (const GValue* value);
GType gherkin_generate_pickles_get_type (void) G_GNUC_CONST;
enum  {
	GHERKIN_GENERATE_PICKLES_DUMMY_PROPERTY
};
gint gherkin_generate_pickles_main (gchar** args, int args_length1);
static void _vala_JsonNode_free (JsonNode* self);
GherkinGeneratePickles* gherkin_generate_pickles_new (void);
GherkinGeneratePickles* gherkin_generate_pickles_construct (GType object_type);
static void gherkin_generate_pickles_finalize (GherkinGeneratePickles* obj);


static void _vala_JsonNode_free (JsonNode* self) {
	g_boxed_free (json_node_get_type (), self);
}


gint gherkin_generate_pickles_main (gchar** args, int args_length1) {
	gint result = 0;
	GherkinParser* parser = NULL;
	GherkinAstBuilder* _tmp0_ = NULL;
	GherkinAstBuilder* _tmp1_ = NULL;
	GherkinParser* _tmp2_ = NULL;
	GherkinParser* _tmp3_ = NULL;
	GherkinTokenMatcher* matcher = NULL;
	GherkinTokenMatcher* _tmp4_ = NULL;
	GherkinPicklesCompiler* compiler = NULL;
	GherkinPicklesCompiler* _tmp5_ = NULL;
	GeeArrayList* pickles = NULL;
	GeeArrayList* _tmp6_ = NULL;
	gchar** _tmp7_ = NULL;
	gint _tmp7__length1 = 0;
	JsonNode* root = NULL;
	GeeArrayList* _tmp29_ = NULL;
	JsonNode* _tmp30_ = NULL;
	JsonGenerator* generator = NULL;
	JsonGenerator* _tmp31_ = NULL;
	FILE* _tmp32_ = NULL;
	gchar* _tmp33_ = NULL;
	gchar* _tmp34_ = NULL;
	GError * _inner_error_ = NULL;
	_tmp0_ = gherkin_ast_builder_new ();
	_tmp1_ = _tmp0_;
	_tmp2_ = gherkin_parser_new (GHERKIN_AST_TYPE_FEATURE, (GBoxedCopyFunc) g_object_ref, g_object_unref, (GherkinBuilder*) _tmp1_);
	_tmp3_ = _tmp2_;
	_g_object_unref0 (_tmp1_);
	parser = _tmp3_;
	_tmp4_ = gherkin_token_matcher_new ("en");
	matcher = _tmp4_;
	_tmp5_ = gherkin_pickles_compiler_new ();
	compiler = _tmp5_;
	_tmp6_ = gee_array_list_new (GHERKIN_PICKLES_TYPE_PICKLE, (GBoxedCopyFunc) g_object_ref, g_object_unref, NULL, NULL, NULL);
	pickles = _tmp6_;
	_tmp7_ = args;
	_tmp7__length1 = args_length1;
	{
		gchar** fileName_collection = NULL;
		gint fileName_collection_length1 = 0;
		gint _fileName_collection_size_ = 0;
		gint fileName_it = 0;
		fileName_collection = _tmp7_;
		fileName_collection_length1 = _tmp7__length1;
		for (fileName_it = 0; fileName_it < _tmp7__length1; fileName_it = fileName_it + 1) {
			gchar* _tmp8_ = NULL;
			gchar* fileName = NULL;
			_tmp8_ = g_strdup (fileName_collection[fileName_it]);
			fileName = _tmp8_;
			{
				const gchar* _tmp9_ = NULL;
				gboolean _tmp10_ = FALSE;
				GFile* file = NULL;
				const gchar* _tmp11_ = NULL;
				GFile* _tmp12_ = NULL;
				_tmp9_ = fileName;
				_tmp10_ = g_str_has_suffix (_tmp9_, ".feature");
				if (!_tmp10_) {
					_g_free0 (fileName);
					continue;
				}
				_tmp11_ = fileName;
				_tmp12_ = g_file_new_for_path (_tmp11_);
				file = _tmp12_;
				{
					GFileInputStream* input = NULL;
					GFile* _tmp13_ = NULL;
					GFileInputStream* _tmp14_ = NULL;
					GherkinAstFeature* feature = NULL;
					GherkinParser* _tmp15_ = NULL;
					GFileInputStream* _tmp16_ = NULL;
					GherkinTokenMatcher* _tmp17_ = NULL;
					gpointer _tmp18_ = NULL;
					GeeArrayList* _tmp19_ = NULL;
					GherkinPicklesCompiler* _tmp20_ = NULL;
					GherkinAstFeature* _tmp21_ = NULL;
					const gchar* _tmp22_ = NULL;
					GeeArrayList* _tmp23_ = NULL;
					GeeArrayList* _tmp24_ = NULL;
					_tmp13_ = file;
					_tmp14_ = g_file_read (_tmp13_, NULL, &_inner_error_);
					input = _tmp14_;
					if (G_UNLIKELY (_inner_error_ != NULL)) {
						goto __catch0_g_error;
					}
					_tmp15_ = parser;
					_tmp16_ = input;
					_tmp17_ = matcher;
					_tmp18_ = gherkin_parser_parse_reader (_tmp15_, (GInputStream*) _tmp16_, (GherkinITokenMatcher*) _tmp17_, &_inner_error_);
					feature = (GherkinAstFeature*) _tmp18_;
					if (G_UNLIKELY (_inner_error_ != NULL)) {
						_g_object_unref0 (input);
						goto __catch0_g_error;
					}
					_tmp19_ = pickles;
					_tmp20_ = compiler;
					_tmp21_ = feature;
					_tmp22_ = fileName;
					_tmp23_ = gherkin_pickles_compiler_compile (_tmp20_, _tmp21_, _tmp22_);
					_tmp24_ = _tmp23_;
					gee_array_list_add_all (_tmp19_, (GeeCollection*) _tmp24_);
					_g_object_unref0 (_tmp24_);
					_g_object_unref0 (feature);
					_g_object_unref0 (input);
				}
				goto __finally0;
				__catch0_g_error:
				{
					GError* e = NULL;
					GError* _tmp25_ = NULL;
					const gchar* _tmp26_ = NULL;
					e = _inner_error_;
					_inner_error_ = NULL;
					_tmp25_ = e;
					_tmp26_ = _tmp25_->message;
					g_warning ("GeneratePickles.vala:25: %s", _tmp26_);
					_g_error_free0 (e);
					_g_object_unref0 (file);
					_g_free0 (fileName);
					continue;
				}
				goto __finally0;
				__catch0_gherkin_parser_exception:
				{
					GError* e = NULL;
					GError* _tmp27_ = NULL;
					const gchar* _tmp28_ = NULL;
					e = _inner_error_;
					_inner_error_ = NULL;
					_tmp27_ = e;
					_tmp28_ = _tmp27_->message;
					g_warning ("GeneratePickles.vala:28: %s", _tmp28_);
					result = 1;
					_g_error_free0 (e);
					_g_object_unref0 (file);
					_g_free0 (fileName);
					_g_object_unref0 (pickles);
					_gherkin_pickles_compiler_unref0 (compiler);
					_g_object_unref0 (matcher);
					_gherkin_parser_unref0 (parser);
					return result;
				}
				__finally0:
				if (G_UNLIKELY (_inner_error_ != NULL)) {
					_g_object_unref0 (file);
					_g_free0 (fileName);
					_g_object_unref0 (pickles);
					_gherkin_pickles_compiler_unref0 (compiler);
					_g_object_unref0 (matcher);
					_gherkin_parser_unref0 (parser);
					g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
					g_clear_error (&_inner_error_);
					return 0;
				}
				_g_object_unref0 (file);
				_g_free0 (fileName);
			}
		}
	}
	_tmp29_ = pickles;
	_tmp30_ = json_gobject_serialize ((GObject*) _tmp29_);
	root = _tmp30_;
	_tmp31_ = json_generator_new ();
	generator = _tmp31_;
	json_generator_set_root (generator, root);
	_tmp32_ = stdout;
	_tmp33_ = json_generator_to_data (generator, NULL);
	_tmp34_ = _tmp33_;
	fputs (_tmp34_, _tmp32_);
	_g_free0 (_tmp34_);
	result = 0;
	_g_object_unref0 (generator);
	__vala_JsonNode_free0 (root);
	_g_object_unref0 (pickles);
	_gherkin_pickles_compiler_unref0 (compiler);
	_g_object_unref0 (matcher);
	_gherkin_parser_unref0 (parser);
	return result;
}


int main (int argc, char ** argv) {
#if !GLIB_CHECK_VERSION (2,35,0)
	g_type_init ();
#endif
	return gherkin_generate_pickles_main (argv, argc);
}


GherkinGeneratePickles* gherkin_generate_pickles_construct (GType object_type) {
	GherkinGeneratePickles* self = NULL;
	self = (GherkinGeneratePickles*) g_type_create_instance (object_type);
	return self;
}


GherkinGeneratePickles* gherkin_generate_pickles_new (void) {
	return gherkin_generate_pickles_construct (GHERKIN_TYPE_GENERATE_PICKLES);
}


static void gherkin_value_generate_pickles_init (GValue* value) {
	value->data[0].v_pointer = NULL;
}


static void gherkin_value_generate_pickles_free_value (GValue* value) {
	if (value->data[0].v_pointer) {
		gherkin_generate_pickles_unref (value->data[0].v_pointer);
	}
}


static void gherkin_value_generate_pickles_copy_value (const GValue* src_value, GValue* dest_value) {
	if (src_value->data[0].v_pointer) {
		dest_value->data[0].v_pointer = gherkin_generate_pickles_ref (src_value->data[0].v_pointer);
	} else {
		dest_value->data[0].v_pointer = NULL;
	}
}


static gpointer gherkin_value_generate_pickles_peek_pointer (const GValue* value) {
	return value->data[0].v_pointer;
}


static gchar* gherkin_value_generate_pickles_collect_value (GValue* value, guint n_collect_values, GTypeCValue* collect_values, guint collect_flags) {
	if (collect_values[0].v_pointer) {
		GherkinGeneratePickles* object;
		object = collect_values[0].v_pointer;
		if (object->parent_instance.g_class == NULL) {
			return g_strconcat ("invalid unclassed object pointer for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
		} else if (!g_value_type_compatible (G_TYPE_FROM_INSTANCE (object), G_VALUE_TYPE (value))) {
			return g_strconcat ("invalid object type `", g_type_name (G_TYPE_FROM_INSTANCE (object)), "' for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
		}
		value->data[0].v_pointer = gherkin_generate_pickles_ref (object);
	} else {
		value->data[0].v_pointer = NULL;
	}
	return NULL;
}


static gchar* gherkin_value_generate_pickles_lcopy_value (const GValue* value, guint n_collect_values, GTypeCValue* collect_values, guint collect_flags) {
	GherkinGeneratePickles** object_p;
	object_p = collect_values[0].v_pointer;
	if (!object_p) {
		return g_strdup_printf ("value location for `%s' passed as NULL", G_VALUE_TYPE_NAME (value));
	}
	if (!value->data[0].v_pointer) {
		*object_p = NULL;
	} else if (collect_flags & G_VALUE_NOCOPY_CONTENTS) {
		*object_p = value->data[0].v_pointer;
	} else {
		*object_p = gherkin_generate_pickles_ref (value->data[0].v_pointer);
	}
	return NULL;
}


GParamSpec* gherkin_param_spec_generate_pickles (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags) {
	GherkinParamSpecGeneratePickles* spec;
	g_return_val_if_fail (g_type_is_a (object_type, GHERKIN_TYPE_GENERATE_PICKLES), NULL);
	spec = g_param_spec_internal (G_TYPE_PARAM_OBJECT, name, nick, blurb, flags);
	G_PARAM_SPEC (spec)->value_type = object_type;
	return G_PARAM_SPEC (spec);
}


gpointer gherkin_value_get_generate_pickles (const GValue* value) {
	g_return_val_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, GHERKIN_TYPE_GENERATE_PICKLES), NULL);
	return value->data[0].v_pointer;
}


void gherkin_value_set_generate_pickles (GValue* value, gpointer v_object) {
	GherkinGeneratePickles* old;
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, GHERKIN_TYPE_GENERATE_PICKLES));
	old = value->data[0].v_pointer;
	if (v_object) {
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, GHERKIN_TYPE_GENERATE_PICKLES));
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
		value->data[0].v_pointer = v_object;
		gherkin_generate_pickles_ref (value->data[0].v_pointer);
	} else {
		value->data[0].v_pointer = NULL;
	}
	if (old) {
		gherkin_generate_pickles_unref (old);
	}
}


void gherkin_value_take_generate_pickles (GValue* value, gpointer v_object) {
	GherkinGeneratePickles* old;
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, GHERKIN_TYPE_GENERATE_PICKLES));
	old = value->data[0].v_pointer;
	if (v_object) {
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, GHERKIN_TYPE_GENERATE_PICKLES));
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
		value->data[0].v_pointer = v_object;
	} else {
		value->data[0].v_pointer = NULL;
	}
	if (old) {
		gherkin_generate_pickles_unref (old);
	}
}


static void gherkin_generate_pickles_class_init (GherkinGeneratePicklesClass * klass) {
	gherkin_generate_pickles_parent_class = g_type_class_peek_parent (klass);
	((GherkinGeneratePicklesClass *) klass)->finalize = gherkin_generate_pickles_finalize;
}


static void gherkin_generate_pickles_instance_init (GherkinGeneratePickles * self) {
	self->ref_count = 1;
}


static void gherkin_generate_pickles_finalize (GherkinGeneratePickles* obj) {
	GherkinGeneratePickles * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, GHERKIN_TYPE_GENERATE_PICKLES, GherkinGeneratePickles);
	g_signal_handlers_destroy (self);
}


GType gherkin_generate_pickles_get_type (void) {
	static volatile gsize gherkin_generate_pickles_type_id__volatile = 0;
	if (g_once_init_enter (&gherkin_generate_pickles_type_id__volatile)) {
		static const GTypeValueTable g_define_type_value_table = { gherkin_value_generate_pickles_init, gherkin_value_generate_pickles_free_value, gherkin_value_generate_pickles_copy_value, gherkin_value_generate_pickles_peek_pointer, "p", gherkin_value_generate_pickles_collect_value, "p", gherkin_value_generate_pickles_lcopy_value };
		static const GTypeInfo g_define_type_info = { sizeof (GherkinGeneratePicklesClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) gherkin_generate_pickles_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (GherkinGeneratePickles), 0, (GInstanceInitFunc) gherkin_generate_pickles_instance_init, &g_define_type_value_table };
		static const GTypeFundamentalInfo g_define_type_fundamental_info = { (G_TYPE_FLAG_CLASSED | G_TYPE_FLAG_INSTANTIATABLE | G_TYPE_FLAG_DERIVABLE | G_TYPE_FLAG_DEEP_DERIVABLE) };
		GType gherkin_generate_pickles_type_id;
		gherkin_generate_pickles_type_id = g_type_register_fundamental (g_type_fundamental_next (), "GherkinGeneratePickles", &g_define_type_info, &g_define_type_fundamental_info, 0);
		g_once_init_leave (&gherkin_generate_pickles_type_id__volatile, gherkin_generate_pickles_type_id);
	}
	return gherkin_generate_pickles_type_id__volatile;
}


gpointer gherkin_generate_pickles_ref (gpointer instance) {
	GherkinGeneratePickles* self;
	self = instance;
	g_atomic_int_inc (&self->ref_count);
	return instance;
}


void gherkin_generate_pickles_unref (gpointer instance) {
	GherkinGeneratePickles* self;
	self = instance;
	if (g_atomic_int_dec_and_test (&self->ref_count)) {
		GHERKIN_GENERATE_PICKLES_GET_CLASS (self)->finalize (self);
		g_type_free_instance ((GTypeInstance *) self);
	}
}



