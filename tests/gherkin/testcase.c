/* testcase.c generated by valac 0.30.0, the Vala compiler
 * generated from testcase.vala, do not modify */

/* testcase.vala
 * Modified for Dia3 (changed namespace)
 * Copyright (C) 2009 Julien Peeters
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.

 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.

 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301  USA
 *
 * Author:
 * 	Julien Peeters <contact@julienpeeters.fr>
 */

#include <glib.h>
#include <glib-object.h>
#include <stdlib.h>
#include <string.h>
#include <gobject/gvaluecollector.h>


#define GHERKIN_TYPE_TEST_CASE (gherkin_test_case_get_type ())
#define GHERKIN_TEST_CASE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), GHERKIN_TYPE_TEST_CASE, GherkinTestCase))
#define GHERKIN_TEST_CASE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), GHERKIN_TYPE_TEST_CASE, GherkinTestCaseClass))
#define GHERKIN_IS_TEST_CASE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GHERKIN_TYPE_TEST_CASE))
#define GHERKIN_IS_TEST_CASE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), GHERKIN_TYPE_TEST_CASE))
#define GHERKIN_TEST_CASE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), GHERKIN_TYPE_TEST_CASE, GherkinTestCaseClass))

typedef struct _GherkinTestCase GherkinTestCase;
typedef struct _GherkinTestCaseClass GherkinTestCaseClass;
typedef struct _GherkinTestCasePrivate GherkinTestCasePrivate;

#define GHERKIN_TEST_CASE_TYPE_ADAPTOR (gherkin_test_case_adaptor_get_type ())
#define GHERKIN_TEST_CASE_ADAPTOR(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), GHERKIN_TEST_CASE_TYPE_ADAPTOR, GherkinTestCaseAdaptor))
#define GHERKIN_TEST_CASE_ADAPTOR_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), GHERKIN_TEST_CASE_TYPE_ADAPTOR, GherkinTestCaseAdaptorClass))
#define GHERKIN_TEST_CASE_IS_ADAPTOR(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GHERKIN_TEST_CASE_TYPE_ADAPTOR))
#define GHERKIN_TEST_CASE_IS_ADAPTOR_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), GHERKIN_TEST_CASE_TYPE_ADAPTOR))
#define GHERKIN_TEST_CASE_ADAPTOR_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), GHERKIN_TEST_CASE_TYPE_ADAPTOR, GherkinTestCaseAdaptorClass))

typedef struct _GherkinTestCaseAdaptor GherkinTestCaseAdaptor;
typedef struct _GherkinTestCaseAdaptorClass GherkinTestCaseAdaptorClass;
#define _gherkin_test_case_adaptor_unref0(var) ((var == NULL) ? NULL : (var = (gherkin_test_case_adaptor_unref (var), NULL)))
typedef struct _GherkinTestCaseAdaptorPrivate GherkinTestCaseAdaptorPrivate;
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
typedef struct _GherkinTestCaseParamSpecAdaptor GherkinTestCaseParamSpecAdaptor;

struct _GherkinTestCase {
	GObject parent_instance;
	GherkinTestCasePrivate * priv;
};

struct _GherkinTestCaseClass {
	GObjectClass parent_class;
	void (*set_up) (GherkinTestCase* self);
	void (*tear_down) (GherkinTestCase* self);
};

struct _GherkinTestCasePrivate {
	GTestSuite* suite;
	GherkinTestCaseAdaptor** adaptors;
	gint adaptors_length1;
	gint _adaptors_size_;
};

typedef void (*GherkinTestCaseTestMethod) (void* user_data);
struct _GherkinTestCaseAdaptor {
	GTypeInstance parent_instance;
	volatile int ref_count;
	GherkinTestCaseAdaptorPrivate * priv;
};

struct _GherkinTestCaseAdaptorClass {
	GTypeClass parent_class;
	void (*finalize) (GherkinTestCaseAdaptor *self);
};

struct _GherkinTestCaseAdaptorPrivate {
	gchar* _name;
	GherkinTestCaseTestMethod test;
	gpointer test_target;
	GDestroyNotify test_target_destroy_notify;
	GherkinTestCase* test_case;
};

struct _GherkinTestCaseParamSpecAdaptor {
	GParamSpec parent_instance;
};


static gpointer gherkin_test_case_parent_class = NULL;
static gpointer gherkin_test_case_adaptor_parent_class = NULL;

GType gherkin_test_case_get_type (void) G_GNUC_CONST;
static gpointer gherkin_test_case_adaptor_ref (gpointer instance);
static void gherkin_test_case_adaptor_unref (gpointer instance);
static GParamSpec* gherkin_test_case_param_spec_adaptor (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags) G_GNUC_UNUSED;
static void gherkin_test_case_value_set_adaptor (GValue* value, gpointer v_object) G_GNUC_UNUSED;
static void gherkin_test_case_value_take_adaptor (GValue* value, gpointer v_object) G_GNUC_UNUSED;
static gpointer gherkin_test_case_value_get_adaptor (const GValue* value) G_GNUC_UNUSED;
static GType gherkin_test_case_adaptor_get_type (void) G_GNUC_CONST G_GNUC_UNUSED;
#define GHERKIN_TEST_CASE_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), GHERKIN_TYPE_TEST_CASE, GherkinTestCasePrivate))
enum  {
	GHERKIN_TEST_CASE_DUMMY_PROPERTY
};
GherkinTestCase* gherkin_test_case_construct (GType object_type, const gchar* name);
void gherkin_test_case_add_test (GherkinTestCase* self, const gchar* name, GherkinTestCaseTestMethod test, void* test_target, GDestroyNotify test_target_destroy_notify);
static GherkinTestCaseAdaptor* gherkin_test_case_adaptor_new (const gchar* name, GherkinTestCaseTestMethod test, void* test_target, GDestroyNotify test_target_destroy_notify, GherkinTestCase* test_case);
static GherkinTestCaseAdaptor* gherkin_test_case_adaptor_construct (GType object_type, const gchar* name, GherkinTestCaseTestMethod test, void* test_target, GDestroyNotify test_target_destroy_notify, GherkinTestCase* test_case);
static void _vala_array_add1 (GherkinTestCaseAdaptor*** array, int* length, int* size, GherkinTestCaseAdaptor* value);
static const gchar* gherkin_test_case_adaptor_get_name (GherkinTestCaseAdaptor* self);
static void gherkin_test_case_adaptor_set_up (GherkinTestCaseAdaptor* self, void* fixture);
static void _gherkin_test_case_adaptor_set_up_gtest_fixture_func (void* fixture, gpointer self);
static void gherkin_test_case_adaptor_run (GherkinTestCaseAdaptor* self, void* fixture);
static void _gherkin_test_case_adaptor_run_gtest_fixture_func (void* fixture, gpointer self);
static void gherkin_test_case_adaptor_tear_down (GherkinTestCaseAdaptor* self, void* fixture);
static void _gherkin_test_case_adaptor_tear_down_gtest_fixture_func (void* fixture, gpointer self);
void gherkin_test_case_set_up (GherkinTestCase* self);
static void gherkin_test_case_real_set_up (GherkinTestCase* self);
void gherkin_test_case_tear_down (GherkinTestCase* self);
static void gherkin_test_case_real_tear_down (GherkinTestCase* self);
GTestSuite* gherkin_test_case_get_suite (GherkinTestCase* self);
#define GHERKIN_TEST_CASE_ADAPTOR_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), GHERKIN_TEST_CASE_TYPE_ADAPTOR, GherkinTestCaseAdaptorPrivate))
enum  {
	GHERKIN_TEST_CASE_ADAPTOR_DUMMY_PROPERTY
};
static void gherkin_test_case_adaptor_set_name (GherkinTestCaseAdaptor* self, const gchar* value);
static void gherkin_test_case_adaptor_finalize (GherkinTestCaseAdaptor* obj);
static void gherkin_test_case_finalize (GObject* obj);
static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func);
static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func);


GherkinTestCase* gherkin_test_case_construct (GType object_type, const gchar* name) {
	GherkinTestCase * self = NULL;
	const gchar* _tmp0_ = NULL;
	GTestSuite* _tmp1_ = NULL;
#line 32 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	g_return_val_if_fail (name != NULL, NULL);
#line 32 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	self = (GherkinTestCase*) g_object_new (object_type, NULL);
#line 33 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	_tmp0_ = name;
#line 33 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	_tmp1_ = g_test_create_suite (_tmp0_);
#line 33 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	self->priv->suite = _tmp1_;
#line 32 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	return self;
#line 162 "testcase.c"
}


static gpointer _gherkin_test_case_adaptor_ref0 (gpointer self) {
#line 38 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	return self ? gherkin_test_case_adaptor_ref (self) : NULL;
#line 169 "testcase.c"
}


static void _vala_array_add1 (GherkinTestCaseAdaptor*** array, int* length, int* size, GherkinTestCaseAdaptor* value) {
#line 38 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	if ((*length) == (*size)) {
#line 38 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
		*size = (*size) ? (2 * (*size)) : 4;
#line 38 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
		*array = g_renew (GherkinTestCaseAdaptor*, *array, (*size) + 1);
#line 180 "testcase.c"
	}
#line 38 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	(*array)[(*length)++] = value;
#line 38 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	(*array)[*length] = NULL;
#line 186 "testcase.c"
}


static void _gherkin_test_case_adaptor_set_up_gtest_fixture_func (void* fixture, gpointer self) {
#line 40 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	gherkin_test_case_adaptor_set_up ((GherkinTestCaseAdaptor*) self, fixture);
#line 193 "testcase.c"
}


static void _gherkin_test_case_adaptor_run_gtest_fixture_func (void* fixture, gpointer self) {
#line 40 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	gherkin_test_case_adaptor_run ((GherkinTestCaseAdaptor*) self, fixture);
#line 200 "testcase.c"
}


static void _gherkin_test_case_adaptor_tear_down_gtest_fixture_func (void* fixture, gpointer self) {
#line 40 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	gherkin_test_case_adaptor_tear_down ((GherkinTestCaseAdaptor*) self, fixture);
#line 207 "testcase.c"
}


void gherkin_test_case_add_test (GherkinTestCase* self, const gchar* name, GherkinTestCaseTestMethod test, void* test_target, GDestroyNotify test_target_destroy_notify) {
	GherkinTestCaseAdaptor* adaptor = NULL;
	const gchar* _tmp0_ = NULL;
	GherkinTestCaseTestMethod _tmp1_ = NULL;
	void* _tmp1__target = NULL;
	GDestroyNotify _tmp1__target_destroy_notify = NULL;
	GherkinTestCaseAdaptor* _tmp2_ = NULL;
	GherkinTestCaseAdaptor** _tmp3_ = NULL;
	gint _tmp3__length1 = 0;
	GherkinTestCaseAdaptor* _tmp4_ = NULL;
	GTestSuite* _tmp5_ = NULL;
	const gchar* _tmp6_ = NULL;
	const gchar* _tmp7_ = NULL;
	GTestCase* _tmp8_ = NULL;
#line 36 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	g_return_if_fail (self != NULL);
#line 36 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	g_return_if_fail (name != NULL);
#line 37 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	_tmp0_ = name;
#line 37 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	_tmp1_ = test;
#line 37 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	_tmp1__target = test_target;
#line 37 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	_tmp1__target_destroy_notify = test_target_destroy_notify;
#line 37 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	test_target_destroy_notify = NULL;
#line 37 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	_tmp2_ = gherkin_test_case_adaptor_new (_tmp0_, _tmp1_, _tmp1__target, _tmp1__target_destroy_notify, self);
#line 37 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	adaptor = _tmp2_;
#line 38 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	_tmp3_ = self->priv->adaptors;
#line 38 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	_tmp3__length1 = self->priv->adaptors_length1;
#line 38 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	_tmp4_ = _gherkin_test_case_adaptor_ref0 (adaptor);
#line 38 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	_vala_array_add1 (&self->priv->adaptors, &self->priv->adaptors_length1, &self->priv->_adaptors_size_, _tmp4_);
#line 40 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	_tmp5_ = self->priv->suite;
#line 40 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	_tmp6_ = gherkin_test_case_adaptor_get_name (adaptor);
#line 40 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	_tmp7_ = _tmp6_;
#line 40 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	_tmp8_ = g_test_create_case (_tmp7_, (gsize) 0, adaptor, _gherkin_test_case_adaptor_set_up_gtest_fixture_func, _gherkin_test_case_adaptor_run_gtest_fixture_func, _gherkin_test_case_adaptor_tear_down_gtest_fixture_func);
#line 40 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	g_test_suite_add (_tmp5_, _tmp8_);
#line 36 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	_gherkin_test_case_adaptor_unref0 (adaptor);
#line 36 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	(test_target_destroy_notify == NULL) ? NULL : (test_target_destroy_notify (test_target), NULL);
#line 36 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	test = NULL;
#line 36 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	test_target = NULL;
#line 36 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	test_target_destroy_notify = NULL;
#line 271 "testcase.c"
}


static void gherkin_test_case_real_set_up (GherkinTestCase* self) {
}


void gherkin_test_case_set_up (GherkinTestCase* self) {
#line 46 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	g_return_if_fail (self != NULL);
#line 46 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	GHERKIN_TEST_CASE_GET_CLASS (self)->set_up (self);
#line 284 "testcase.c"
}


static void gherkin_test_case_real_tear_down (GherkinTestCase* self) {
}


void gherkin_test_case_tear_down (GherkinTestCase* self) {
#line 49 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	g_return_if_fail (self != NULL);
#line 49 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	GHERKIN_TEST_CASE_GET_CLASS (self)->tear_down (self);
#line 297 "testcase.c"
}


GTestSuite* gherkin_test_case_get_suite (GherkinTestCase* self) {
	GTestSuite* result = NULL;
	GTestSuite* _tmp0_ = NULL;
#line 52 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	g_return_val_if_fail (self != NULL, NULL);
#line 53 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	_tmp0_ = self->priv->suite;
#line 53 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	result = _tmp0_;
#line 53 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	return result;
#line 312 "testcase.c"
}


static gpointer _g_object_ref0 (gpointer self) {
#line 68 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	return self ? g_object_ref (self) : NULL;
#line 319 "testcase.c"
}


static GherkinTestCaseAdaptor* gherkin_test_case_adaptor_construct (GType object_type, const gchar* name, GherkinTestCaseTestMethod test, void* test_target, GDestroyNotify test_target_destroy_notify, GherkinTestCase* test_case) {
	GherkinTestCaseAdaptor* self = NULL;
	const gchar* _tmp0_ = NULL;
	GherkinTestCaseTestMethod _tmp1_ = NULL;
	void* _tmp1__target = NULL;
	GDestroyNotify _tmp1__target_destroy_notify = NULL;
	GherkinTestCase* _tmp2_ = NULL;
	GherkinTestCase* _tmp3_ = NULL;
#line 63 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	g_return_val_if_fail (name != NULL, NULL);
#line 63 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	g_return_val_if_fail (test_case != NULL, NULL);
#line 63 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	self = (GherkinTestCaseAdaptor*) g_type_create_instance (object_type);
#line 66 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	_tmp0_ = name;
#line 66 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	gherkin_test_case_adaptor_set_name (self, _tmp0_);
#line 67 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	_tmp1_ = test;
#line 67 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	_tmp1__target = test_target;
#line 67 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	_tmp1__target_destroy_notify = test_target_destroy_notify;
#line 67 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	test_target_destroy_notify = NULL;
#line 67 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	(self->priv->test_target_destroy_notify == NULL) ? NULL : (self->priv->test_target_destroy_notify (self->priv->test_target), NULL);
#line 67 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	self->priv->test = NULL;
#line 67 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	self->priv->test_target = NULL;
#line 67 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	self->priv->test_target_destroy_notify = NULL;
#line 67 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	self->priv->test = _tmp1_;
#line 67 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	self->priv->test_target = _tmp1__target;
#line 67 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	self->priv->test_target_destroy_notify = _tmp1__target_destroy_notify;
#line 68 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	_tmp2_ = test_case;
#line 68 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	_tmp3_ = _g_object_ref0 (_tmp2_);
#line 68 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	_g_object_unref0 (self->priv->test_case);
#line 68 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	self->priv->test_case = _tmp3_;
#line 63 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	(test_target_destroy_notify == NULL) ? NULL : (test_target_destroy_notify (test_target), NULL);
#line 63 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	test = NULL;
#line 63 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	test_target = NULL;
#line 63 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	test_target_destroy_notify = NULL;
#line 63 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	return self;
#line 381 "testcase.c"
}


static GherkinTestCaseAdaptor* gherkin_test_case_adaptor_new (const gchar* name, GherkinTestCaseTestMethod test, void* test_target, GDestroyNotify test_target_destroy_notify, GherkinTestCase* test_case) {
#line 63 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	return gherkin_test_case_adaptor_construct (GHERKIN_TEST_CASE_TYPE_ADAPTOR, name, test, test_target, test_target_destroy_notify, test_case);
#line 388 "testcase.c"
}


static void gherkin_test_case_adaptor_set_up (GherkinTestCaseAdaptor* self, void* fixture) {
	GherkinTestCase* _tmp0_ = NULL;
#line 71 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	g_return_if_fail (self != NULL);
#line 72 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	_tmp0_ = self->priv->test_case;
#line 72 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	gherkin_test_case_set_up (_tmp0_);
#line 400 "testcase.c"
}


static void gherkin_test_case_adaptor_run (GherkinTestCaseAdaptor* self, void* fixture) {
	GherkinTestCaseTestMethod _tmp0_ = NULL;
	void* _tmp0__target = NULL;
#line 75 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	g_return_if_fail (self != NULL);
#line 76 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	_tmp0_ = self->priv->test;
#line 76 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	_tmp0__target = self->priv->test_target;
#line 76 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	_tmp0_ (_tmp0__target);
#line 415 "testcase.c"
}


static void gherkin_test_case_adaptor_tear_down (GherkinTestCaseAdaptor* self, void* fixture) {
	GherkinTestCase* _tmp0_ = NULL;
#line 79 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	g_return_if_fail (self != NULL);
#line 80 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	_tmp0_ = self->priv->test_case;
#line 80 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	gherkin_test_case_tear_down (_tmp0_);
#line 427 "testcase.c"
}


static const gchar* gherkin_test_case_adaptor_get_name (GherkinTestCaseAdaptor* self) {
	const gchar* result;
	const gchar* _tmp0_ = NULL;
#line 59 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	g_return_val_if_fail (self != NULL, NULL);
#line 59 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	_tmp0_ = self->priv->_name;
#line 59 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	result = _tmp0_;
#line 59 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	return result;
#line 442 "testcase.c"
}


static void gherkin_test_case_adaptor_set_name (GherkinTestCaseAdaptor* self, const gchar* value) {
	const gchar* _tmp0_ = NULL;
	gchar* _tmp1_ = NULL;
#line 59 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	g_return_if_fail (self != NULL);
#line 59 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	_tmp0_ = value;
#line 59 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	_tmp1_ = g_strdup (_tmp0_);
#line 59 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	_g_free0 (self->priv->_name);
#line 59 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	self->priv->_name = _tmp1_;
#line 459 "testcase.c"
}


static void gherkin_test_case_value_adaptor_init (GValue* value) {
#line 57 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	value->data[0].v_pointer = NULL;
#line 466 "testcase.c"
}


static void gherkin_test_case_value_adaptor_free_value (GValue* value) {
#line 57 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	if (value->data[0].v_pointer) {
#line 57 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
		gherkin_test_case_adaptor_unref (value->data[0].v_pointer);
#line 475 "testcase.c"
	}
}


static void gherkin_test_case_value_adaptor_copy_value (const GValue* src_value, GValue* dest_value) {
#line 57 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	if (src_value->data[0].v_pointer) {
#line 57 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
		dest_value->data[0].v_pointer = gherkin_test_case_adaptor_ref (src_value->data[0].v_pointer);
#line 485 "testcase.c"
	} else {
#line 57 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
		dest_value->data[0].v_pointer = NULL;
#line 489 "testcase.c"
	}
}


static gpointer gherkin_test_case_value_adaptor_peek_pointer (const GValue* value) {
#line 57 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	return value->data[0].v_pointer;
#line 497 "testcase.c"
}


static gchar* gherkin_test_case_value_adaptor_collect_value (GValue* value, guint n_collect_values, GTypeCValue* collect_values, guint collect_flags) {
#line 57 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	if (collect_values[0].v_pointer) {
#line 504 "testcase.c"
		GherkinTestCaseAdaptor* object;
		object = collect_values[0].v_pointer;
#line 57 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
		if (object->parent_instance.g_class == NULL) {
#line 57 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
			return g_strconcat ("invalid unclassed object pointer for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
#line 511 "testcase.c"
		} else if (!g_value_type_compatible (G_TYPE_FROM_INSTANCE (object), G_VALUE_TYPE (value))) {
#line 57 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
			return g_strconcat ("invalid object type `", g_type_name (G_TYPE_FROM_INSTANCE (object)), "' for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
#line 515 "testcase.c"
		}
#line 57 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
		value->data[0].v_pointer = gherkin_test_case_adaptor_ref (object);
#line 519 "testcase.c"
	} else {
#line 57 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
		value->data[0].v_pointer = NULL;
#line 523 "testcase.c"
	}
#line 57 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	return NULL;
#line 527 "testcase.c"
}


static gchar* gherkin_test_case_value_adaptor_lcopy_value (const GValue* value, guint n_collect_values, GTypeCValue* collect_values, guint collect_flags) {
	GherkinTestCaseAdaptor** object_p;
	object_p = collect_values[0].v_pointer;
#line 57 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	if (!object_p) {
#line 57 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
		return g_strdup_printf ("value location for `%s' passed as NULL", G_VALUE_TYPE_NAME (value));
#line 538 "testcase.c"
	}
#line 57 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	if (!value->data[0].v_pointer) {
#line 57 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
		*object_p = NULL;
#line 544 "testcase.c"
	} else if (collect_flags & G_VALUE_NOCOPY_CONTENTS) {
#line 57 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
		*object_p = value->data[0].v_pointer;
#line 548 "testcase.c"
	} else {
#line 57 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
		*object_p = gherkin_test_case_adaptor_ref (value->data[0].v_pointer);
#line 552 "testcase.c"
	}
#line 57 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	return NULL;
#line 556 "testcase.c"
}


static GParamSpec* gherkin_test_case_param_spec_adaptor (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags) {
	GherkinTestCaseParamSpecAdaptor* spec;
#line 57 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	g_return_val_if_fail (g_type_is_a (object_type, GHERKIN_TEST_CASE_TYPE_ADAPTOR), NULL);
#line 57 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	spec = g_param_spec_internal (G_TYPE_PARAM_OBJECT, name, nick, blurb, flags);
#line 57 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	G_PARAM_SPEC (spec)->value_type = object_type;
#line 57 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	return G_PARAM_SPEC (spec);
#line 570 "testcase.c"
}


static gpointer gherkin_test_case_value_get_adaptor (const GValue* value) {
#line 57 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	g_return_val_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, GHERKIN_TEST_CASE_TYPE_ADAPTOR), NULL);
#line 57 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	return value->data[0].v_pointer;
#line 579 "testcase.c"
}


static void gherkin_test_case_value_set_adaptor (GValue* value, gpointer v_object) {
	GherkinTestCaseAdaptor* old;
#line 57 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, GHERKIN_TEST_CASE_TYPE_ADAPTOR));
#line 57 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	old = value->data[0].v_pointer;
#line 57 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	if (v_object) {
#line 57 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, GHERKIN_TEST_CASE_TYPE_ADAPTOR));
#line 57 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
#line 57 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
		value->data[0].v_pointer = v_object;
#line 57 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
		gherkin_test_case_adaptor_ref (value->data[0].v_pointer);
#line 599 "testcase.c"
	} else {
#line 57 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
		value->data[0].v_pointer = NULL;
#line 603 "testcase.c"
	}
#line 57 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	if (old) {
#line 57 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
		gherkin_test_case_adaptor_unref (old);
#line 609 "testcase.c"
	}
}


static void gherkin_test_case_value_take_adaptor (GValue* value, gpointer v_object) {
	GherkinTestCaseAdaptor* old;
#line 57 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, GHERKIN_TEST_CASE_TYPE_ADAPTOR));
#line 57 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	old = value->data[0].v_pointer;
#line 57 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	if (v_object) {
#line 57 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, GHERKIN_TEST_CASE_TYPE_ADAPTOR));
#line 57 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
#line 57 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
		value->data[0].v_pointer = v_object;
#line 628 "testcase.c"
	} else {
#line 57 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
		value->data[0].v_pointer = NULL;
#line 632 "testcase.c"
	}
#line 57 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	if (old) {
#line 57 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
		gherkin_test_case_adaptor_unref (old);
#line 638 "testcase.c"
	}
}


static void gherkin_test_case_adaptor_class_init (GherkinTestCaseAdaptorClass * klass) {
#line 57 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	gherkin_test_case_adaptor_parent_class = g_type_class_peek_parent (klass);
#line 57 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	((GherkinTestCaseAdaptorClass *) klass)->finalize = gherkin_test_case_adaptor_finalize;
#line 57 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	g_type_class_add_private (klass, sizeof (GherkinTestCaseAdaptorPrivate));
#line 650 "testcase.c"
}


static void gherkin_test_case_adaptor_instance_init (GherkinTestCaseAdaptor * self) {
#line 57 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	self->priv = GHERKIN_TEST_CASE_ADAPTOR_GET_PRIVATE (self);
#line 57 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	self->ref_count = 1;
#line 659 "testcase.c"
}


static void gherkin_test_case_adaptor_finalize (GherkinTestCaseAdaptor* obj) {
	GherkinTestCaseAdaptor * self;
#line 57 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, GHERKIN_TEST_CASE_TYPE_ADAPTOR, GherkinTestCaseAdaptor);
#line 57 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	g_signal_handlers_destroy (self);
#line 59 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	_g_free0 (self->priv->_name);
#line 60 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	(self->priv->test_target_destroy_notify == NULL) ? NULL : (self->priv->test_target_destroy_notify (self->priv->test_target), NULL);
#line 60 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	self->priv->test = NULL;
#line 60 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	self->priv->test_target = NULL;
#line 60 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	self->priv->test_target_destroy_notify = NULL;
#line 61 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	_g_object_unref0 (self->priv->test_case);
#line 681 "testcase.c"
}


static GType gherkin_test_case_adaptor_get_type (void) {
	static volatile gsize gherkin_test_case_adaptor_type_id__volatile = 0;
	if (g_once_init_enter (&gherkin_test_case_adaptor_type_id__volatile)) {
		static const GTypeValueTable g_define_type_value_table = { gherkin_test_case_value_adaptor_init, gherkin_test_case_value_adaptor_free_value, gherkin_test_case_value_adaptor_copy_value, gherkin_test_case_value_adaptor_peek_pointer, "p", gherkin_test_case_value_adaptor_collect_value, "p", gherkin_test_case_value_adaptor_lcopy_value };
		static const GTypeInfo g_define_type_info = { sizeof (GherkinTestCaseAdaptorClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) gherkin_test_case_adaptor_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (GherkinTestCaseAdaptor), 0, (GInstanceInitFunc) gherkin_test_case_adaptor_instance_init, &g_define_type_value_table };
		static const GTypeFundamentalInfo g_define_type_fundamental_info = { (G_TYPE_FLAG_CLASSED | G_TYPE_FLAG_INSTANTIATABLE | G_TYPE_FLAG_DERIVABLE | G_TYPE_FLAG_DEEP_DERIVABLE) };
		GType gherkin_test_case_adaptor_type_id;
		gherkin_test_case_adaptor_type_id = g_type_register_fundamental (g_type_fundamental_next (), "GherkinTestCaseAdaptor", &g_define_type_info, &g_define_type_fundamental_info, 0);
		g_once_init_leave (&gherkin_test_case_adaptor_type_id__volatile, gherkin_test_case_adaptor_type_id);
	}
	return gherkin_test_case_adaptor_type_id__volatile;
}


static gpointer gherkin_test_case_adaptor_ref (gpointer instance) {
	GherkinTestCaseAdaptor* self;
	self = instance;
#line 57 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	g_atomic_int_inc (&self->ref_count);
#line 57 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	return instance;
#line 706 "testcase.c"
}


static void gherkin_test_case_adaptor_unref (gpointer instance) {
	GherkinTestCaseAdaptor* self;
	self = instance;
#line 57 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	if (g_atomic_int_dec_and_test (&self->ref_count)) {
#line 57 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
		GHERKIN_TEST_CASE_ADAPTOR_GET_CLASS (self)->finalize (self);
#line 57 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
		g_type_free_instance ((GTypeInstance *) self);
#line 719 "testcase.c"
	}
}


static void gherkin_test_case_class_init (GherkinTestCaseClass * klass) {
#line 25 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	gherkin_test_case_parent_class = g_type_class_peek_parent (klass);
#line 25 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	g_type_class_add_private (klass, sizeof (GherkinTestCasePrivate));
#line 25 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	((GherkinTestCaseClass *) klass)->set_up = gherkin_test_case_real_set_up;
#line 25 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	((GherkinTestCaseClass *) klass)->tear_down = gherkin_test_case_real_tear_down;
#line 25 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	G_OBJECT_CLASS (klass)->finalize = gherkin_test_case_finalize;
#line 735 "testcase.c"
}


static void gherkin_test_case_instance_init (GherkinTestCase * self) {
	GherkinTestCaseAdaptor** _tmp0_ = NULL;
#line 25 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	self->priv = GHERKIN_TEST_CASE_GET_PRIVATE (self);
#line 28 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	_tmp0_ = g_new0 (GherkinTestCaseAdaptor*, 0 + 1);
#line 28 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	self->priv->adaptors = _tmp0_;
#line 28 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	self->priv->adaptors_length1 = 0;
#line 28 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	self->priv->_adaptors_size_ = self->priv->adaptors_length1;
#line 751 "testcase.c"
}


static void gherkin_test_case_finalize (GObject* obj) {
	GherkinTestCase * self;
#line 25 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, GHERKIN_TYPE_TEST_CASE, GherkinTestCase);
#line 28 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	self->priv->adaptors = (_vala_array_free (self->priv->adaptors, self->priv->adaptors_length1, (GDestroyNotify) gherkin_test_case_adaptor_unref), NULL);
#line 25 "/home/bizarro/Documents/projects/gherkin-vala/tests/gherkin/testcase.vala"
	G_OBJECT_CLASS (gherkin_test_case_parent_class)->finalize (obj);
#line 763 "testcase.c"
}


GType gherkin_test_case_get_type (void) {
	static volatile gsize gherkin_test_case_type_id__volatile = 0;
	if (g_once_init_enter (&gherkin_test_case_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (GherkinTestCaseClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) gherkin_test_case_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (GherkinTestCase), 0, (GInstanceInitFunc) gherkin_test_case_instance_init, NULL };
		GType gherkin_test_case_type_id;
		gherkin_test_case_type_id = g_type_register_static (G_TYPE_OBJECT, "GherkinTestCase", &g_define_type_info, G_TYPE_FLAG_ABSTRACT);
		g_once_init_leave (&gherkin_test_case_type_id__volatile, gherkin_test_case_type_id);
	}
	return gherkin_test_case_type_id__volatile;
}


static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func) {
	if ((array != NULL) && (destroy_func != NULL)) {
		int i;
		for (i = 0; i < array_length; i = i + 1) {
			if (((gpointer*) array)[i] != NULL) {
				destroy_func (((gpointer*) array)[i]);
			}
		}
	}
}


static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func) {
	_vala_array_destroy (array, array_length, destroy_func);
	g_free (array);
}



