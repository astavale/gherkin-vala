/* SymbolCounter.c generated by valac 0.30.0, the Vala compiler
 * generated from SymbolCounter.vala, do not modify */


#include <glib.h>
#include <glib-object.h>
#include <stdlib.h>
#include <string.h>
#include <gobject/gvaluecollector.h>


#define GHERKIN_TYPE_SYMBOL_COUNTER (gherkin_symbol_counter_get_type ())
#define GHERKIN_SYMBOL_COUNTER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), GHERKIN_TYPE_SYMBOL_COUNTER, GherkinSymbolCounter))
#define GHERKIN_SYMBOL_COUNTER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), GHERKIN_TYPE_SYMBOL_COUNTER, GherkinSymbolCounterClass))
#define GHERKIN_IS_SYMBOL_COUNTER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GHERKIN_TYPE_SYMBOL_COUNTER))
#define GHERKIN_IS_SYMBOL_COUNTER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), GHERKIN_TYPE_SYMBOL_COUNTER))
#define GHERKIN_SYMBOL_COUNTER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), GHERKIN_TYPE_SYMBOL_COUNTER, GherkinSymbolCounterClass))

typedef struct _GherkinSymbolCounter GherkinSymbolCounter;
typedef struct _GherkinSymbolCounterClass GherkinSymbolCounterClass;
typedef struct _GherkinSymbolCounterPrivate GherkinSymbolCounterPrivate;
typedef struct _GherkinParamSpecSymbolCounter GherkinParamSpecSymbolCounter;

struct _GherkinSymbolCounter {
	GTypeInstance parent_instance;
	volatile int ref_count;
	GherkinSymbolCounterPrivate * priv;
};

struct _GherkinSymbolCounterClass {
	GTypeClass parent_class;
	void (*finalize) (GherkinSymbolCounter *self);
};

struct _GherkinParamSpecSymbolCounter {
	GParamSpec parent_instance;
};


static gpointer gherkin_symbol_counter_parent_class = NULL;

gpointer gherkin_symbol_counter_ref (gpointer instance);
void gherkin_symbol_counter_unref (gpointer instance);
GParamSpec* gherkin_param_spec_symbol_counter (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void gherkin_value_set_symbol_counter (GValue* value, gpointer v_object);
void gherkin_value_take_symbol_counter (GValue* value, gpointer v_object);
gpointer gherkin_value_get_symbol_counter (const GValue* value);
GType gherkin_symbol_counter_get_type (void) G_GNUC_CONST;
enum  {
	GHERKIN_SYMBOL_COUNTER_DUMMY_PROPERTY
};
gint gherkin_symbol_counter_count_symbols (const gchar* str);
GherkinSymbolCounter* gherkin_symbol_counter_new (void);
GherkinSymbolCounter* gherkin_symbol_counter_construct (GType object_type);
static void gherkin_symbol_counter_finalize (GherkinSymbolCounter* obj);


gint gherkin_symbol_counter_count_symbols (const gchar* str) {
	gint result = 0;
	const gchar* _tmp0_ = NULL;
	gint _tmp1_ = 0;
	gint _tmp2_ = 0;
#line 4 "/home/bizarro/Documents/projects/gherkin-vala/gherkin/SymbolCounter.vala"
	g_return_val_if_fail (str != NULL, 0);
#line 5 "/home/bizarro/Documents/projects/gherkin-vala/gherkin/SymbolCounter.vala"
	_tmp0_ = str;
#line 5 "/home/bizarro/Documents/projects/gherkin-vala/gherkin/SymbolCounter.vala"
	_tmp1_ = strlen (_tmp0_);
#line 5 "/home/bizarro/Documents/projects/gherkin-vala/gherkin/SymbolCounter.vala"
	_tmp2_ = _tmp1_;
#line 5 "/home/bizarro/Documents/projects/gherkin-vala/gherkin/SymbolCounter.vala"
	result = _tmp2_;
#line 5 "/home/bizarro/Documents/projects/gherkin-vala/gherkin/SymbolCounter.vala"
	return result;
#line 76 "SymbolCounter.c"
}


GherkinSymbolCounter* gherkin_symbol_counter_construct (GType object_type) {
	GherkinSymbolCounter* self = NULL;
#line 3 "/home/bizarro/Documents/projects/gherkin-vala/gherkin/SymbolCounter.vala"
	self = (GherkinSymbolCounter*) g_type_create_instance (object_type);
#line 3 "/home/bizarro/Documents/projects/gherkin-vala/gherkin/SymbolCounter.vala"
	return self;
#line 86 "SymbolCounter.c"
}


GherkinSymbolCounter* gherkin_symbol_counter_new (void) {
#line 3 "/home/bizarro/Documents/projects/gherkin-vala/gherkin/SymbolCounter.vala"
	return gherkin_symbol_counter_construct (GHERKIN_TYPE_SYMBOL_COUNTER);
#line 93 "SymbolCounter.c"
}


static void gherkin_value_symbol_counter_init (GValue* value) {
#line 3 "/home/bizarro/Documents/projects/gherkin-vala/gherkin/SymbolCounter.vala"
	value->data[0].v_pointer = NULL;
#line 100 "SymbolCounter.c"
}


static void gherkin_value_symbol_counter_free_value (GValue* value) {
#line 3 "/home/bizarro/Documents/projects/gherkin-vala/gherkin/SymbolCounter.vala"
	if (value->data[0].v_pointer) {
#line 3 "/home/bizarro/Documents/projects/gherkin-vala/gherkin/SymbolCounter.vala"
		gherkin_symbol_counter_unref (value->data[0].v_pointer);
#line 109 "SymbolCounter.c"
	}
}


static void gherkin_value_symbol_counter_copy_value (const GValue* src_value, GValue* dest_value) {
#line 3 "/home/bizarro/Documents/projects/gherkin-vala/gherkin/SymbolCounter.vala"
	if (src_value->data[0].v_pointer) {
#line 3 "/home/bizarro/Documents/projects/gherkin-vala/gherkin/SymbolCounter.vala"
		dest_value->data[0].v_pointer = gherkin_symbol_counter_ref (src_value->data[0].v_pointer);
#line 119 "SymbolCounter.c"
	} else {
#line 3 "/home/bizarro/Documents/projects/gherkin-vala/gherkin/SymbolCounter.vala"
		dest_value->data[0].v_pointer = NULL;
#line 123 "SymbolCounter.c"
	}
}


static gpointer gherkin_value_symbol_counter_peek_pointer (const GValue* value) {
#line 3 "/home/bizarro/Documents/projects/gherkin-vala/gherkin/SymbolCounter.vala"
	return value->data[0].v_pointer;
#line 131 "SymbolCounter.c"
}


static gchar* gherkin_value_symbol_counter_collect_value (GValue* value, guint n_collect_values, GTypeCValue* collect_values, guint collect_flags) {
#line 3 "/home/bizarro/Documents/projects/gherkin-vala/gherkin/SymbolCounter.vala"
	if (collect_values[0].v_pointer) {
#line 138 "SymbolCounter.c"
		GherkinSymbolCounter* object;
		object = collect_values[0].v_pointer;
#line 3 "/home/bizarro/Documents/projects/gherkin-vala/gherkin/SymbolCounter.vala"
		if (object->parent_instance.g_class == NULL) {
#line 3 "/home/bizarro/Documents/projects/gherkin-vala/gherkin/SymbolCounter.vala"
			return g_strconcat ("invalid unclassed object pointer for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
#line 145 "SymbolCounter.c"
		} else if (!g_value_type_compatible (G_TYPE_FROM_INSTANCE (object), G_VALUE_TYPE (value))) {
#line 3 "/home/bizarro/Documents/projects/gherkin-vala/gherkin/SymbolCounter.vala"
			return g_strconcat ("invalid object type `", g_type_name (G_TYPE_FROM_INSTANCE (object)), "' for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
#line 149 "SymbolCounter.c"
		}
#line 3 "/home/bizarro/Documents/projects/gherkin-vala/gherkin/SymbolCounter.vala"
		value->data[0].v_pointer = gherkin_symbol_counter_ref (object);
#line 153 "SymbolCounter.c"
	} else {
#line 3 "/home/bizarro/Documents/projects/gherkin-vala/gherkin/SymbolCounter.vala"
		value->data[0].v_pointer = NULL;
#line 157 "SymbolCounter.c"
	}
#line 3 "/home/bizarro/Documents/projects/gherkin-vala/gherkin/SymbolCounter.vala"
	return NULL;
#line 161 "SymbolCounter.c"
}


static gchar* gherkin_value_symbol_counter_lcopy_value (const GValue* value, guint n_collect_values, GTypeCValue* collect_values, guint collect_flags) {
	GherkinSymbolCounter** object_p;
	object_p = collect_values[0].v_pointer;
#line 3 "/home/bizarro/Documents/projects/gherkin-vala/gherkin/SymbolCounter.vala"
	if (!object_p) {
#line 3 "/home/bizarro/Documents/projects/gherkin-vala/gherkin/SymbolCounter.vala"
		return g_strdup_printf ("value location for `%s' passed as NULL", G_VALUE_TYPE_NAME (value));
#line 172 "SymbolCounter.c"
	}
#line 3 "/home/bizarro/Documents/projects/gherkin-vala/gherkin/SymbolCounter.vala"
	if (!value->data[0].v_pointer) {
#line 3 "/home/bizarro/Documents/projects/gherkin-vala/gherkin/SymbolCounter.vala"
		*object_p = NULL;
#line 178 "SymbolCounter.c"
	} else if (collect_flags & G_VALUE_NOCOPY_CONTENTS) {
#line 3 "/home/bizarro/Documents/projects/gherkin-vala/gherkin/SymbolCounter.vala"
		*object_p = value->data[0].v_pointer;
#line 182 "SymbolCounter.c"
	} else {
#line 3 "/home/bizarro/Documents/projects/gherkin-vala/gherkin/SymbolCounter.vala"
		*object_p = gherkin_symbol_counter_ref (value->data[0].v_pointer);
#line 186 "SymbolCounter.c"
	}
#line 3 "/home/bizarro/Documents/projects/gherkin-vala/gherkin/SymbolCounter.vala"
	return NULL;
#line 190 "SymbolCounter.c"
}


GParamSpec* gherkin_param_spec_symbol_counter (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags) {
	GherkinParamSpecSymbolCounter* spec;
#line 3 "/home/bizarro/Documents/projects/gherkin-vala/gherkin/SymbolCounter.vala"
	g_return_val_if_fail (g_type_is_a (object_type, GHERKIN_TYPE_SYMBOL_COUNTER), NULL);
#line 3 "/home/bizarro/Documents/projects/gherkin-vala/gherkin/SymbolCounter.vala"
	spec = g_param_spec_internal (G_TYPE_PARAM_OBJECT, name, nick, blurb, flags);
#line 3 "/home/bizarro/Documents/projects/gherkin-vala/gherkin/SymbolCounter.vala"
	G_PARAM_SPEC (spec)->value_type = object_type;
#line 3 "/home/bizarro/Documents/projects/gherkin-vala/gherkin/SymbolCounter.vala"
	return G_PARAM_SPEC (spec);
#line 204 "SymbolCounter.c"
}


gpointer gherkin_value_get_symbol_counter (const GValue* value) {
#line 3 "/home/bizarro/Documents/projects/gherkin-vala/gherkin/SymbolCounter.vala"
	g_return_val_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, GHERKIN_TYPE_SYMBOL_COUNTER), NULL);
#line 3 "/home/bizarro/Documents/projects/gherkin-vala/gherkin/SymbolCounter.vala"
	return value->data[0].v_pointer;
#line 213 "SymbolCounter.c"
}


void gherkin_value_set_symbol_counter (GValue* value, gpointer v_object) {
	GherkinSymbolCounter* old;
#line 3 "/home/bizarro/Documents/projects/gherkin-vala/gherkin/SymbolCounter.vala"
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, GHERKIN_TYPE_SYMBOL_COUNTER));
#line 3 "/home/bizarro/Documents/projects/gherkin-vala/gherkin/SymbolCounter.vala"
	old = value->data[0].v_pointer;
#line 3 "/home/bizarro/Documents/projects/gherkin-vala/gherkin/SymbolCounter.vala"
	if (v_object) {
#line 3 "/home/bizarro/Documents/projects/gherkin-vala/gherkin/SymbolCounter.vala"
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, GHERKIN_TYPE_SYMBOL_COUNTER));
#line 3 "/home/bizarro/Documents/projects/gherkin-vala/gherkin/SymbolCounter.vala"
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
#line 3 "/home/bizarro/Documents/projects/gherkin-vala/gherkin/SymbolCounter.vala"
		value->data[0].v_pointer = v_object;
#line 3 "/home/bizarro/Documents/projects/gherkin-vala/gherkin/SymbolCounter.vala"
		gherkin_symbol_counter_ref (value->data[0].v_pointer);
#line 233 "SymbolCounter.c"
	} else {
#line 3 "/home/bizarro/Documents/projects/gherkin-vala/gherkin/SymbolCounter.vala"
		value->data[0].v_pointer = NULL;
#line 237 "SymbolCounter.c"
	}
#line 3 "/home/bizarro/Documents/projects/gherkin-vala/gherkin/SymbolCounter.vala"
	if (old) {
#line 3 "/home/bizarro/Documents/projects/gherkin-vala/gherkin/SymbolCounter.vala"
		gherkin_symbol_counter_unref (old);
#line 243 "SymbolCounter.c"
	}
}


void gherkin_value_take_symbol_counter (GValue* value, gpointer v_object) {
	GherkinSymbolCounter* old;
#line 3 "/home/bizarro/Documents/projects/gherkin-vala/gherkin/SymbolCounter.vala"
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, GHERKIN_TYPE_SYMBOL_COUNTER));
#line 3 "/home/bizarro/Documents/projects/gherkin-vala/gherkin/SymbolCounter.vala"
	old = value->data[0].v_pointer;
#line 3 "/home/bizarro/Documents/projects/gherkin-vala/gherkin/SymbolCounter.vala"
	if (v_object) {
#line 3 "/home/bizarro/Documents/projects/gherkin-vala/gherkin/SymbolCounter.vala"
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, GHERKIN_TYPE_SYMBOL_COUNTER));
#line 3 "/home/bizarro/Documents/projects/gherkin-vala/gherkin/SymbolCounter.vala"
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
#line 3 "/home/bizarro/Documents/projects/gherkin-vala/gherkin/SymbolCounter.vala"
		value->data[0].v_pointer = v_object;
#line 262 "SymbolCounter.c"
	} else {
#line 3 "/home/bizarro/Documents/projects/gherkin-vala/gherkin/SymbolCounter.vala"
		value->data[0].v_pointer = NULL;
#line 266 "SymbolCounter.c"
	}
#line 3 "/home/bizarro/Documents/projects/gherkin-vala/gherkin/SymbolCounter.vala"
	if (old) {
#line 3 "/home/bizarro/Documents/projects/gherkin-vala/gherkin/SymbolCounter.vala"
		gherkin_symbol_counter_unref (old);
#line 272 "SymbolCounter.c"
	}
}


static void gherkin_symbol_counter_class_init (GherkinSymbolCounterClass * klass) {
#line 3 "/home/bizarro/Documents/projects/gherkin-vala/gherkin/SymbolCounter.vala"
	gherkin_symbol_counter_parent_class = g_type_class_peek_parent (klass);
#line 3 "/home/bizarro/Documents/projects/gherkin-vala/gherkin/SymbolCounter.vala"
	((GherkinSymbolCounterClass *) klass)->finalize = gherkin_symbol_counter_finalize;
#line 282 "SymbolCounter.c"
}


static void gherkin_symbol_counter_instance_init (GherkinSymbolCounter * self) {
#line 3 "/home/bizarro/Documents/projects/gherkin-vala/gherkin/SymbolCounter.vala"
	self->ref_count = 1;
#line 289 "SymbolCounter.c"
}


static void gherkin_symbol_counter_finalize (GherkinSymbolCounter* obj) {
	GherkinSymbolCounter * self;
#line 3 "/home/bizarro/Documents/projects/gherkin-vala/gherkin/SymbolCounter.vala"
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, GHERKIN_TYPE_SYMBOL_COUNTER, GherkinSymbolCounter);
#line 3 "/home/bizarro/Documents/projects/gherkin-vala/gherkin/SymbolCounter.vala"
	g_signal_handlers_destroy (self);
#line 299 "SymbolCounter.c"
}


GType gherkin_symbol_counter_get_type (void) {
	static volatile gsize gherkin_symbol_counter_type_id__volatile = 0;
	if (g_once_init_enter (&gherkin_symbol_counter_type_id__volatile)) {
		static const GTypeValueTable g_define_type_value_table = { gherkin_value_symbol_counter_init, gherkin_value_symbol_counter_free_value, gherkin_value_symbol_counter_copy_value, gherkin_value_symbol_counter_peek_pointer, "p", gherkin_value_symbol_counter_collect_value, "p", gherkin_value_symbol_counter_lcopy_value };
		static const GTypeInfo g_define_type_info = { sizeof (GherkinSymbolCounterClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) gherkin_symbol_counter_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (GherkinSymbolCounter), 0, (GInstanceInitFunc) gherkin_symbol_counter_instance_init, &g_define_type_value_table };
		static const GTypeFundamentalInfo g_define_type_fundamental_info = { (G_TYPE_FLAG_CLASSED | G_TYPE_FLAG_INSTANTIATABLE | G_TYPE_FLAG_DERIVABLE | G_TYPE_FLAG_DEEP_DERIVABLE) };
		GType gherkin_symbol_counter_type_id;
		gherkin_symbol_counter_type_id = g_type_register_fundamental (g_type_fundamental_next (), "GherkinSymbolCounter", &g_define_type_info, &g_define_type_fundamental_info, 0);
		g_once_init_leave (&gherkin_symbol_counter_type_id__volatile, gherkin_symbol_counter_type_id);
	}
	return gherkin_symbol_counter_type_id__volatile;
}


gpointer gherkin_symbol_counter_ref (gpointer instance) {
	GherkinSymbolCounter* self;
	self = instance;
#line 3 "/home/bizarro/Documents/projects/gherkin-vala/gherkin/SymbolCounter.vala"
	g_atomic_int_inc (&self->ref_count);
#line 3 "/home/bizarro/Documents/projects/gherkin-vala/gherkin/SymbolCounter.vala"
	return instance;
#line 324 "SymbolCounter.c"
}


void gherkin_symbol_counter_unref (gpointer instance) {
	GherkinSymbolCounter* self;
	self = instance;
#line 3 "/home/bizarro/Documents/projects/gherkin-vala/gherkin/SymbolCounter.vala"
	if (g_atomic_int_dec_and_test (&self->ref_count)) {
#line 3 "/home/bizarro/Documents/projects/gherkin-vala/gherkin/SymbolCounter.vala"
		GHERKIN_SYMBOL_COUNTER_GET_CLASS (self)->finalize (self);
#line 3 "/home/bizarro/Documents/projects/gherkin-vala/gherkin/SymbolCounter.vala"
		g_type_free_instance ((GTypeInstance *) self);
#line 337 "SymbolCounter.c"
	}
}



