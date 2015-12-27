/* CompilerTest.c generated by valac 0.30.0, the Vala compiler
 * generated from CompilerTest.vala, do not modify */


#include <glib.h>
#include <glib-object.h>
#include <libgherkin3.h>
#include <stdlib.h>
#include <string.h>
#include <gee.h>
#include <json-glib/json-glib.h>


#define GHERKIN_TYPE_TEST_CASE (gherkin_test_case_get_type ())
#define GHERKIN_TEST_CASE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), GHERKIN_TYPE_TEST_CASE, GherkinTestCase))
#define GHERKIN_TEST_CASE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), GHERKIN_TYPE_TEST_CASE, GherkinTestCaseClass))
#define GHERKIN_IS_TEST_CASE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GHERKIN_TYPE_TEST_CASE))
#define GHERKIN_IS_TEST_CASE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), GHERKIN_TYPE_TEST_CASE))
#define GHERKIN_TEST_CASE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), GHERKIN_TYPE_TEST_CASE, GherkinTestCaseClass))

typedef struct _GherkinTestCase GherkinTestCase;
typedef struct _GherkinTestCaseClass GherkinTestCaseClass;
typedef struct _GherkinTestCasePrivate GherkinTestCasePrivate;

#define GHERKIN_PICKLES_TYPE_COMPILER_TEST (gherkin_pickles_compiler_test_get_type ())
#define GHERKIN_PICKLES_COMPILER_TEST(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), GHERKIN_PICKLES_TYPE_COMPILER_TEST, GherkinPicklesCompilerTest))
#define GHERKIN_PICKLES_COMPILER_TEST_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), GHERKIN_PICKLES_TYPE_COMPILER_TEST, GherkinPicklesCompilerTestClass))
#define GHERKIN_PICKLES_IS_COMPILER_TEST(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GHERKIN_PICKLES_TYPE_COMPILER_TEST))
#define GHERKIN_PICKLES_IS_COMPILER_TEST_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), GHERKIN_PICKLES_TYPE_COMPILER_TEST))
#define GHERKIN_PICKLES_COMPILER_TEST_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), GHERKIN_PICKLES_TYPE_COMPILER_TEST, GherkinPicklesCompilerTestClass))

typedef struct _GherkinPicklesCompilerTest GherkinPicklesCompilerTest;
typedef struct _GherkinPicklesCompilerTestClass GherkinPicklesCompilerTestClass;
typedef struct _GherkinPicklesCompilerTestPrivate GherkinPicklesCompilerTestPrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _gherkin_parser_unref0(var) ((var == NULL) ? NULL : (var = (gherkin_parser_unref (var), NULL)))
#define _gherkin_pickles_compiler_unref0(var) ((var == NULL) ? NULL : (var = (gherkin_pickles_compiler_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))
#define __vala_JsonNode_free0(var) ((var == NULL) ? NULL : (var = (_vala_JsonNode_free (var), NULL)))
#define _json_array_unref0(var) ((var == NULL) ? NULL : (var = (json_array_unref (var), NULL)))
#define _vala_assert(expr, msg) if G_LIKELY (expr) ; else g_assertion_message_expr (G_LOG_DOMAIN, __FILE__, __LINE__, G_STRFUNC, msg);
#define _vala_return_if_fail(expr, msg) if G_LIKELY (expr) ; else { g_return_if_fail_warning (G_LOG_DOMAIN, G_STRFUNC, msg); return; }
#define _vala_return_val_if_fail(expr, msg, val) if G_LIKELY (expr) ; else { g_return_if_fail_warning (G_LOG_DOMAIN, G_STRFUNC, msg); return val; }
#define _vala_warn_if_fail(expr, msg) if G_LIKELY (expr) ; else g_warn_message (G_LOG_DOMAIN, __FILE__, __LINE__, G_STRFUNC, msg);

struct _GherkinTestCase {
	GObject parent_instance;
	GherkinTestCasePrivate * priv;
};

struct _GherkinTestCaseClass {
	GObjectClass parent_class;
	void (*set_up) (GherkinTestCase* self);
	void (*tear_down) (GherkinTestCase* self);
};

struct _GherkinPicklesCompilerTest {
	GherkinTestCase parent_instance;
	GherkinPicklesCompilerTestPrivate * priv;
};

struct _GherkinPicklesCompilerTestClass {
	GherkinTestCaseClass parent_class;
};

struct _GherkinPicklesCompilerTestPrivate {
	GherkinParser* parser;
	GherkinPicklesCompiler* compiler;
};

typedef void (*GherkinTestCaseTestMethod) (void* user_data);

static gpointer gherkin_pickles_compiler_test_parent_class = NULL;

GType gherkin_test_case_get_type (void) G_GNUC_CONST;
GType gherkin_pickles_compiler_test_get_type (void) G_GNUC_CONST;
#define GHERKIN_PICKLES_COMPILER_TEST_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), GHERKIN_PICKLES_TYPE_COMPILER_TEST, GherkinPicklesCompilerTestPrivate))
enum  {
	GHERKIN_PICKLES_COMPILER_TEST_DUMMY_PROPERTY
};
GherkinPicklesCompilerTest* gherkin_pickles_compiler_test_new (void);
GherkinPicklesCompilerTest* gherkin_pickles_compiler_test_construct (GType object_type);
GherkinTestCase* gherkin_test_case_construct (GType object_type, const gchar* name);
void gherkin_test_case_add_test (GherkinTestCase* self, const gchar* name, GherkinTestCaseTestMethod test, void* test_target, GDestroyNotify test_target_destroy_notify);
void gherkin_pickles_compiler_test_compiles_a_scenario (GherkinPicklesCompilerTest* self);
static void _gherkin_pickles_compiler_test_compiles_a_scenario_gherkin_test_case_test_method (gpointer self);
static void _vala_JsonNode_free (JsonNode* self);
static void gherkin_pickles_compiler_test_finalize (GObject* obj);


static void _gherkin_pickles_compiler_test_compiles_a_scenario_gherkin_test_case_test_method (gpointer self) {
#line 14 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/pickles/CompilerTest.vala"
	gherkin_pickles_compiler_test_compiles_a_scenario ((GherkinPicklesCompilerTest*) self);
#line 95 "CompilerTest.c"
}


GherkinPicklesCompilerTest* gherkin_pickles_compiler_test_construct (GType object_type) {
	GherkinPicklesCompilerTest * self = NULL;
#line 13 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/pickles/CompilerTest.vala"
	self = (GherkinPicklesCompilerTest*) gherkin_test_case_construct (object_type, "CompilerTest");
#line 14 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/pickles/CompilerTest.vala"
	gherkin_test_case_add_test ((GherkinTestCase*) self, "compiles_a_scenario", _gherkin_pickles_compiler_test_compiles_a_scenario_gherkin_test_case_test_method, g_object_ref (self), g_object_unref);
#line 12 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/pickles/CompilerTest.vala"
	return self;
#line 107 "CompilerTest.c"
}


GherkinPicklesCompilerTest* gherkin_pickles_compiler_test_new (void) {
#line 12 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/pickles/CompilerTest.vala"
	return gherkin_pickles_compiler_test_construct (GHERKIN_PICKLES_TYPE_COMPILER_TEST);
#line 114 "CompilerTest.c"
}


static gpointer _g_object_ref0 (gpointer self) {
#line 25 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/pickles/CompilerTest.vala"
	return self ? g_object_ref (self) : NULL;
#line 121 "CompilerTest.c"
}


static void _vala_JsonNode_free (JsonNode* self) {
#line 36 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/pickles/CompilerTest.vala"
	g_boxed_free (json_node_get_type (), self);
#line 128 "CompilerTest.c"
}


static gchar* string_strip (const gchar* self) {
	gchar* result = NULL;
	gchar* _result_ = NULL;
	gchar* _tmp0_ = NULL;
	const gchar* _tmp1_ = NULL;
#line 1115 "/usr/share/vala-0.30/vapi/glib-2.0.vapi"
	g_return_val_if_fail (self != NULL, NULL);
#line 1116 "/usr/share/vala-0.30/vapi/glib-2.0.vapi"
	_tmp0_ = g_strdup (self);
#line 1116 "/usr/share/vala-0.30/vapi/glib-2.0.vapi"
	_result_ = _tmp0_;
#line 1117 "/usr/share/vala-0.30/vapi/glib-2.0.vapi"
	_tmp1_ = _result_;
#line 1117 "/usr/share/vala-0.30/vapi/glib-2.0.vapi"
	g_strstrip (_tmp1_);
#line 1118 "/usr/share/vala-0.30/vapi/glib-2.0.vapi"
	result = _result_;
#line 1118 "/usr/share/vala-0.30/vapi/glib-2.0.vapi"
	return result;
#line 151 "CompilerTest.c"
}


void gherkin_pickles_compiler_test_compiles_a_scenario (GherkinPicklesCompilerTest* self) {
	GherkinAstFeature* _tmp0_ = NULL;
	GherkinParser* _tmp1_ = NULL;
	gpointer _tmp2_ = NULL;
	GeeArrayList* pickles = NULL;
	GherkinPicklesCompiler* _tmp3_ = NULL;
	GeeArrayList* _tmp4_ = NULL;
	JsonArray* array = NULL;
	GeeArrayList* _tmp5_ = NULL;
	gint _tmp6_ = 0;
	gint _tmp7_ = 0;
	JsonArray* _tmp8_ = NULL;
	JsonNode* root = NULL;
	JsonNode* _tmp23_ = NULL;
	JsonNode* _tmp24_ = NULL;
	JsonArray* _tmp25_ = NULL;
	JsonGenerator* generator = NULL;
	JsonGenerator* _tmp26_ = NULL;
	JsonGenerator* _tmp27_ = NULL;
	JsonNode* _tmp28_ = NULL;
	gchar* testfeature1 = NULL;
	JsonGenerator* _tmp29_ = NULL;
	gchar* _tmp30_ = NULL;
	GObject* feature_test = NULL;
	GObject* _tmp31_ = NULL;
	GObject* _tmp32_ = NULL;
	JsonNode* _tmp33_ = NULL;
	JsonGenerator* _tmp34_ = NULL;
	JsonNode* _tmp35_ = NULL;
	gchar* testfeature2 = NULL;
	JsonGenerator* _tmp36_ = NULL;
	gchar* _tmp37_ = NULL;
	gchar* _tmp38_ = NULL;
	gchar* _tmp39_ = NULL;
	gchar* _tmp40_ = NULL;
	gchar* _tmp41_ = NULL;
	gchar* _tmp42_ = NULL;
	const gchar* _tmp43_ = NULL;
	gchar* _tmp44_ = NULL;
	gchar* _tmp45_ = NULL;
	const gchar* _tmp46_ = NULL;
	GError * _inner_error_ = NULL;
#line 17 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/pickles/CompilerTest.vala"
	g_return_if_fail (self != NULL);
#line 18 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/pickles/CompilerTest.vala"
	_tmp1_ = self->priv->parser;
#line 18 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/pickles/CompilerTest.vala"
	_tmp2_ = gherkin_parser_parse_string (_tmp1_, "" "Feature: f\n" "  Scenario: s\n" "    Given passing\n", NULL, &_inner_error_);
#line 18 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/pickles/CompilerTest.vala"
	_tmp0_ = (GherkinAstFeature*) _tmp2_;
#line 18 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/pickles/CompilerTest.vala"
	if (G_UNLIKELY (_inner_error_ != NULL)) {
#line 18 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/pickles/CompilerTest.vala"
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
#line 18 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/pickles/CompilerTest.vala"
		g_clear_error (&_inner_error_);
#line 18 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/pickles/CompilerTest.vala"
		return;
#line 213 "CompilerTest.c"
	}
#line 18 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/pickles/CompilerTest.vala"
	_tmp3_ = self->priv->compiler;
#line 18 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/pickles/CompilerTest.vala"
	_tmp4_ = gherkin_pickles_compiler_compile (_tmp3_, _tmp0_, "features/hello.feature");
#line 18 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/pickles/CompilerTest.vala"
	pickles = _tmp4_;
#line 23 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/pickles/CompilerTest.vala"
	_tmp5_ = pickles;
#line 23 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/pickles/CompilerTest.vala"
	_tmp6_ = gee_abstract_collection_get_size ((GeeCollection*) _tmp5_);
#line 23 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/pickles/CompilerTest.vala"
	_tmp7_ = _tmp6_;
#line 23 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/pickles/CompilerTest.vala"
	_tmp8_ = json_array_sized_new ((guint) _tmp7_);
#line 23 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/pickles/CompilerTest.vala"
	array = _tmp8_;
#line 231 "CompilerTest.c"
	{
		GeeArrayList* _pickle_list = NULL;
		GeeArrayList* _tmp9_ = NULL;
		GeeArrayList* _tmp10_ = NULL;
		gint _pickle_size = 0;
		GeeArrayList* _tmp11_ = NULL;
		gint _tmp12_ = 0;
		gint _tmp13_ = 0;
		gint _pickle_index = 0;
#line 25 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/pickles/CompilerTest.vala"
		_tmp9_ = pickles;
#line 25 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/pickles/CompilerTest.vala"
		_tmp10_ = _g_object_ref0 (_tmp9_);
#line 25 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/pickles/CompilerTest.vala"
		_pickle_list = _tmp10_;
#line 25 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/pickles/CompilerTest.vala"
		_tmp11_ = _pickle_list;
#line 25 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/pickles/CompilerTest.vala"
		_tmp12_ = gee_abstract_collection_get_size ((GeeCollection*) _tmp11_);
#line 25 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/pickles/CompilerTest.vala"
		_tmp13_ = _tmp12_;
#line 25 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/pickles/CompilerTest.vala"
		_pickle_size = _tmp13_;
#line 25 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/pickles/CompilerTest.vala"
		_pickle_index = -1;
#line 25 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/pickles/CompilerTest.vala"
		while (TRUE) {
#line 259 "CompilerTest.c"
			gint _tmp14_ = 0;
			gint _tmp15_ = 0;
			gint _tmp16_ = 0;
			GherkinPicklesPickle* pickle = NULL;
			GeeArrayList* _tmp17_ = NULL;
			gint _tmp18_ = 0;
			gpointer _tmp19_ = NULL;
			JsonArray* _tmp20_ = NULL;
			GherkinPicklesPickle* _tmp21_ = NULL;
			JsonNode* _tmp22_ = NULL;
#line 25 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/pickles/CompilerTest.vala"
			_tmp14_ = _pickle_index;
#line 25 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/pickles/CompilerTest.vala"
			_pickle_index = _tmp14_ + 1;
#line 25 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/pickles/CompilerTest.vala"
			_tmp15_ = _pickle_index;
#line 25 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/pickles/CompilerTest.vala"
			_tmp16_ = _pickle_size;
#line 25 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/pickles/CompilerTest.vala"
			if (!(_tmp15_ < _tmp16_)) {
#line 25 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/pickles/CompilerTest.vala"
				break;
#line 282 "CompilerTest.c"
			}
#line 25 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/pickles/CompilerTest.vala"
			_tmp17_ = _pickle_list;
#line 25 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/pickles/CompilerTest.vala"
			_tmp18_ = _pickle_index;
#line 25 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/pickles/CompilerTest.vala"
			_tmp19_ = gee_abstract_list_get ((GeeAbstractList*) _tmp17_, _tmp18_);
#line 25 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/pickles/CompilerTest.vala"
			pickle = (GherkinPicklesPickle*) _tmp19_;
#line 26 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/pickles/CompilerTest.vala"
			_tmp20_ = array;
#line 26 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/pickles/CompilerTest.vala"
			_tmp21_ = pickle;
#line 26 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/pickles/CompilerTest.vala"
			_tmp22_ = json_gobject_serialize ((GObject*) _tmp21_);
#line 26 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/pickles/CompilerTest.vala"
			json_array_add_element (_tmp20_, _tmp22_);
#line 25 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/pickles/CompilerTest.vala"
			_g_object_unref0 (pickle);
#line 302 "CompilerTest.c"
		}
#line 25 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/pickles/CompilerTest.vala"
		_g_object_unref0 (_pickle_list);
#line 306 "CompilerTest.c"
	}
#line 29 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/pickles/CompilerTest.vala"
	_tmp23_ = json_node_alloc ();
#line 29 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/pickles/CompilerTest.vala"
	root = _tmp23_;
#line 30 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/pickles/CompilerTest.vala"
	_tmp24_ = root;
#line 30 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/pickles/CompilerTest.vala"
	_tmp25_ = array;
#line 30 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/pickles/CompilerTest.vala"
	json_node_init_array (_tmp24_, _tmp25_);
#line 31 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/pickles/CompilerTest.vala"
	_tmp26_ = json_generator_new ();
#line 31 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/pickles/CompilerTest.vala"
	generator = _tmp26_;
#line 32 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/pickles/CompilerTest.vala"
	_tmp27_ = generator;
#line 32 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/pickles/CompilerTest.vala"
	_tmp28_ = root;
#line 32 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/pickles/CompilerTest.vala"
	json_generator_set_root (_tmp27_, _tmp28_);
#line 34 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/pickles/CompilerTest.vala"
	_tmp29_ = generator;
#line 34 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/pickles/CompilerTest.vala"
	_tmp30_ = json_generator_to_data (_tmp29_, NULL);
#line 34 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/pickles/CompilerTest.vala"
	testfeature1 = _tmp30_;
#line 36 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/pickles/CompilerTest.vala"
	_tmp31_ = json_gobject_from_data (GHERKIN_PICKLES_TYPE_PICKLE, "" "  {\n" "    \"name\": \"Scenario: s\",\n" "    \"steps\": [\n" "      {\n" "        \"text\": \"passing\",\n" "        \"arguments\": [],\n" "        \"locations\": [\n" "          {\n" "            \"path\": \"features/hello.feature\",\n" "            \"line\": 3,\n" "            \"column\": 11\n" "          }\n" "        ]\n" "      }\n" "    ],\n" "    \"tags\": [],\n" "    \"locations\": [\n" "      {\n" "        \"path\": \"features/hello.feature\",\n" "        \"line\": 2,\n" "        \"column\": 3\n" "      }\n" "    ]\n" "  }\n", (gssize) -1, &_inner_error_);
#line 36 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/pickles/CompilerTest.vala"
	feature_test = _tmp31_;
#line 36 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/pickles/CompilerTest.vala"
	if (G_UNLIKELY (_inner_error_ != NULL)) {
#line 36 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/pickles/CompilerTest.vala"
		_g_free0 (testfeature1);
#line 36 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/pickles/CompilerTest.vala"
		_g_object_unref0 (generator);
#line 36 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/pickles/CompilerTest.vala"
		__vala_JsonNode_free0 (root);
#line 36 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/pickles/CompilerTest.vala"
		_json_array_unref0 (array);
#line 36 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/pickles/CompilerTest.vala"
		_g_object_unref0 (pickles);
#line 36 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/pickles/CompilerTest.vala"
		_g_object_unref0 (_tmp0_);
#line 36 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/pickles/CompilerTest.vala"
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
#line 36 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/pickles/CompilerTest.vala"
		g_clear_error (&_inner_error_);
#line 36 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/pickles/CompilerTest.vala"
		return;
#line 358 "CompilerTest.c"
	}
#line 62 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/pickles/CompilerTest.vala"
	_tmp32_ = feature_test;
#line 62 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/pickles/CompilerTest.vala"
	_tmp33_ = json_gobject_serialize (_tmp32_);
#line 62 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/pickles/CompilerTest.vala"
	__vala_JsonNode_free0 (root);
#line 62 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/pickles/CompilerTest.vala"
	root = _tmp33_;
#line 63 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/pickles/CompilerTest.vala"
	_tmp34_ = generator;
#line 63 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/pickles/CompilerTest.vala"
	_tmp35_ = root;
#line 63 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/pickles/CompilerTest.vala"
	json_generator_set_root (_tmp34_, _tmp35_);
#line 64 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/pickles/CompilerTest.vala"
	_tmp36_ = generator;
#line 64 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/pickles/CompilerTest.vala"
	_tmp37_ = json_generator_to_data (_tmp36_, NULL);
#line 64 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/pickles/CompilerTest.vala"
	_tmp38_ = _tmp37_;
#line 64 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/pickles/CompilerTest.vala"
	_tmp39_ = g_strdup_printf ("[%s]", _tmp38_);
#line 64 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/pickles/CompilerTest.vala"
	_tmp40_ = _tmp39_;
#line 64 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/pickles/CompilerTest.vala"
	_tmp41_ = string_strip (_tmp40_);
#line 64 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/pickles/CompilerTest.vala"
	_tmp42_ = _tmp41_;
#line 64 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/pickles/CompilerTest.vala"
	_g_free0 (_tmp40_);
#line 64 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/pickles/CompilerTest.vala"
	_g_free0 (_tmp38_);
#line 64 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/pickles/CompilerTest.vala"
	testfeature2 = _tmp42_;
#line 66 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/pickles/CompilerTest.vala"
	_tmp43_ = testfeature1;
#line 66 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/pickles/CompilerTest.vala"
	_tmp44_ = string_strip (_tmp43_);
#line 66 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/pickles/CompilerTest.vala"
	_tmp45_ = _tmp44_;
#line 66 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/pickles/CompilerTest.vala"
	_tmp46_ = testfeature2;
#line 66 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/pickles/CompilerTest.vala"
	_vala_assert (g_strcmp0 (_tmp45_, _tmp46_) == 0, "testfeature1.strip() == testfeature2");
#line 66 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/pickles/CompilerTest.vala"
	_g_free0 (_tmp45_);
#line 17 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/pickles/CompilerTest.vala"
	_g_free0 (testfeature2);
#line 17 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/pickles/CompilerTest.vala"
	_g_object_unref0 (feature_test);
#line 17 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/pickles/CompilerTest.vala"
	_g_free0 (testfeature1);
#line 17 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/pickles/CompilerTest.vala"
	_g_object_unref0 (generator);
#line 17 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/pickles/CompilerTest.vala"
	__vala_JsonNode_free0 (root);
#line 17 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/pickles/CompilerTest.vala"
	_json_array_unref0 (array);
#line 17 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/pickles/CompilerTest.vala"
	_g_object_unref0 (pickles);
#line 17 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/pickles/CompilerTest.vala"
	_g_object_unref0 (_tmp0_);
#line 422 "CompilerTest.c"
}


static void gherkin_pickles_compiler_test_class_init (GherkinPicklesCompilerTestClass * klass) {
#line 7 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/pickles/CompilerTest.vala"
	gherkin_pickles_compiler_test_parent_class = g_type_class_peek_parent (klass);
#line 7 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/pickles/CompilerTest.vala"
	g_type_class_add_private (klass, sizeof (GherkinPicklesCompilerTestPrivate));
#line 7 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/pickles/CompilerTest.vala"
	G_OBJECT_CLASS (klass)->finalize = gherkin_pickles_compiler_test_finalize;
#line 433 "CompilerTest.c"
}


static void gherkin_pickles_compiler_test_instance_init (GherkinPicklesCompilerTest * self) {
	GherkinAstBuilder* _tmp0_ = NULL;
	GherkinAstBuilder* _tmp1_ = NULL;
	GherkinParser* _tmp2_ = NULL;
	GherkinPicklesCompiler* _tmp3_ = NULL;
#line 7 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/pickles/CompilerTest.vala"
	self->priv = GHERKIN_PICKLES_COMPILER_TEST_GET_PRIVATE (self);
#line 9 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/pickles/CompilerTest.vala"
	_tmp0_ = gherkin_ast_builder_new ();
#line 9 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/pickles/CompilerTest.vala"
	_tmp1_ = _tmp0_;
#line 9 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/pickles/CompilerTest.vala"
	_tmp2_ = gherkin_parser_new (GHERKIN_AST_TYPE_FEATURE, (GBoxedCopyFunc) g_object_ref, g_object_unref, (GherkinBuilder*) _tmp1_);
#line 9 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/pickles/CompilerTest.vala"
	self->priv->parser = _tmp2_;
#line 9 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/pickles/CompilerTest.vala"
	_g_object_unref0 (_tmp1_);
#line 10 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/pickles/CompilerTest.vala"
	_tmp3_ = gherkin_pickles_compiler_new ();
#line 10 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/pickles/CompilerTest.vala"
	self->priv->compiler = _tmp3_;
#line 458 "CompilerTest.c"
}


static void gherkin_pickles_compiler_test_finalize (GObject* obj) {
	GherkinPicklesCompilerTest * self;
#line 7 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/pickles/CompilerTest.vala"
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, GHERKIN_PICKLES_TYPE_COMPILER_TEST, GherkinPicklesCompilerTest);
#line 9 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/pickles/CompilerTest.vala"
	_gherkin_parser_unref0 (self->priv->parser);
#line 10 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/pickles/CompilerTest.vala"
	_gherkin_pickles_compiler_unref0 (self->priv->compiler);
#line 7 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/pickles/CompilerTest.vala"
	G_OBJECT_CLASS (gherkin_pickles_compiler_test_parent_class)->finalize (obj);
#line 472 "CompilerTest.c"
}


GType gherkin_pickles_compiler_test_get_type (void) {
	static volatile gsize gherkin_pickles_compiler_test_type_id__volatile = 0;
	if (g_once_init_enter (&gherkin_pickles_compiler_test_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (GherkinPicklesCompilerTestClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) gherkin_pickles_compiler_test_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (GherkinPicklesCompilerTest), 0, (GInstanceInitFunc) gherkin_pickles_compiler_test_instance_init, NULL };
		GType gherkin_pickles_compiler_test_type_id;
		gherkin_pickles_compiler_test_type_id = g_type_register_static (GHERKIN_TYPE_TEST_CASE, "GherkinPicklesCompilerTest", &g_define_type_info, 0);
		g_once_init_leave (&gherkin_pickles_compiler_test_type_id__volatile, gherkin_pickles_compiler_test_type_id);
	}
	return gherkin_pickles_compiler_test_type_id__volatile;
}



