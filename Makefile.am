ACLOCAL_AMFLAGS  = -I m4 ${ACLOCAL_FLAGS}
AUTOMAKE_OPTIONS = subdir-objects

AM_CFLAGS =\
	$(LIBGHERKIN3_CFLAGS) \
	-I$(top_srcdir)

AM_CPPFLAGS = \
	$(addprefix -I ,$(LIBGHERKIN_LIBS)) \
	`pkg-config --cflags --libs $(pkg_modules)` \
	-DGHERKIN_SRC_DIR=\""$(GHERKIN_SRC_DIR)"\" \
	-DGHERKIN_DATA_DIR=\""$(GHERKIN_DATA_DIR)"\" \
	-DGHERKIN_TEST_DIR=\""$(GHERKIN_TEST_DIR)"\" \
	-w \
	-g \
	$(LIBGHERKIN3_CPPFLAGS)


AM_VALAFLAGS = $(LIBGHERKIN3_VALAFLAGS) \
	--pkg config \
	-g

# --- resources ---
data/gherkin3-resource.c: $(top_srcdir)/data/gherkin3.gresource.xml $(shell $(GLIB_COMPILE_RESOURCES) --generate-dependencies \
--sourcedir=$(top_srcdir)/data/ $(top_srcdir)/data/gherkin3.gresource.xml)
	$(AM_V_GEN) $(GLIB_COMPILE_RESOURCES) --target=$@ --sourcedir=$(top_srcdir)/data/ --generate-source $<


# --- libgherkin3 ---

lib_LTLIBRARIES = libgherkin3.la

libgherkin3_la_SOURCES = \
	data/gherkin3-resource.c \
	gherkin/GherkinLanguageConstants.vala \
	gherkin/SymbolCounter.vala \
	gherkin/ParserException.vala \
	gherkin/IGherkinDialectProvider.vala \
	gherkin/TokenScanner.vala \
	gherkin/GherkinDialect.vala \
	gherkin/StringUtils.vala \
	gherkin/AstBuilder.vala \
	gherkin/TokenMatcher.vala \
	gherkin/TokenFormatter.vala \
	gherkin/AstNode.vala \
	gherkin/IGherkinLine.vala \
	gherkin/Func.vala \
	gherkin/GherkinLineSpan.vala \
	gherkin/GherkinLine.vala \
	gherkin/GherkinDialectProvider.vala \
	gherkin/TokenFormatterBuilder.vala \
	gherkin/Parser.vala \
	gherkin/Token.vala \
	gherkin/ast/Feature.vala \
	gherkin/ast/Examples.vala \
	gherkin/ast/TableCell.vala \
	gherkin/ast/Node.vala \
	gherkin/ast/Comment.vala \
	gherkin/ast/Background.vala \
	gherkin/ast/Scenario.vala \
	gherkin/ast/ScenarioDefinition.vala \
	gherkin/ast/Step.vala \
	gherkin/ast/Location.vala \
	gherkin/ast/ScenarioOutline.vala \
	gherkin/ast/Tag.vala \
	gherkin/ast/TableRow.vala \
	gherkin/ast/DocString.vala \
	gherkin/ast/DataTable.vala \
	gherkin/pickles/Argument.vala \
	gherkin/pickles/Compiler.vala \
	gherkin/pickles/PickleTable.vala \
	gherkin/pickles/PickleTag.vala \
	gherkin/pickles/PickleRow.vala \
	gherkin/pickles/PickleCell.vala \
	gherkin/pickles/PickleLocation.vala \
	gherkin/pickles/PickleString.vala \
	gherkin/pickles/Pickle.vala \
	gherkin/pickles/PickleStep.vala


libgherkin3_la_VALAFLAGS = \
	--library libgherkin3-0.1 \
	--vapi libgherkin3-0.1.vapi \
	-H libgherkin3.h \
	--gir=Gherkin3-1.0.gir \
	--pkg gio-2.0 \
	--pkg glib-2.0 \
	--pkg json-glib-1.0 \
	--pkg gee-0.8 \
	--pkg config \
	--vapidir $(top_builddir)\
	--target-glib=2.44.0 \
	--gresources $(top_srcdir)/data/gherkin3.gresource.xml \
	-g

libgherkin3_la_LIBADD = $(LIBGHERKIN3_LIBS)

libgherkin3_la_includedir = $(includedir)/libgherkin3-0.1
libgherkin3_la_include_HEADERS = libgherkin3.h

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = libgherkin3-0.1.pc

# --- generators ---

bin_PROGRAMS = build/gherkin-generate-ast build/gherkin-generate-pickles build/gherkin-generate-tokens

build_gherkin_generate_ast_SOURCES = \
	gherkin/GenerateAst.vala

build_gherkin_generate_ast_VALAFLAGS = \
	--pkg gio-2.0 \
	--pkg glib-2.0 \
	--pkg json-glib-1.0 \
	--pkg gee-0.8 \
	--pkg config \
	--pkg libgherkin3-0.1 \
	--vapidir $(top_builddir)\
	--target-glib=2.44.0 \
	--gresources $(top_srcdir)/data/gherkin3.gresource.xml

build_gherkin_generate_ast_LDADD = \
	$(LIBGHERKIN3_LIBS) \
	$(top_builddir)/libgherkin3.la

build_gherkin_generate_ast_CFLAGS = $(LIBGHERKIN3_CFLAGS)

build_gherkin_generate_ast_CPPFLAGS = $(LIBGHERKIN3_CPPFLAGS)

#--- pickles! ---

build_gherkin_generate_pickles_SOURCES = \
	gherkin/GeneratePickles.vala

build_gherkin_generate_pickles_VALAFLAGS = $(build_gherkin_generate_ast_VALAFLAGS)
build_gherkin_generate_pickles_CFLAGS = $(LIBGHERKIN3_CFLAGS)
build_gherkin_generate_pickles_CPPFLAGS = $(LIBGHERKIN3_CPPFLAGS)
build_gherkin_generate_pickles_LDADD= $(build_gherkin_generate_ast_LDADD)

#--- tokens ---

build_gherkin_generate_tokens_SOURCES = \
	gherkin/GenerateTokens.vala

build_gherkin_generate_tokens_VALAFLAGS = $(build_gherkin_generate_ast_VALAFLAGS)
build_gherkin_generate_tokens_CFLAGS = $(LIBGHERKIN3_CFLAGS)
build_gherkin_generate_tokens_CPPFLAGS = $(LIBGHERKIN3_CPPFLAGS)
build_gherkin_generate_tokens_LDADD= $(build_gherkin_generate_ast_LDADD)


GTESTER = gtester 
GTESTER_REPORT = gtester-report
TEST_PROGS = test_libgherkin3
check_PROGRAMS = test_libgherkin3

test_libgherkin3_SOURCES =  \
	tests/gherkin/test-main.vala \
	tests/gherkin/testcase.vala \
	tests/gherkin/AstBuilderTest.vala \
	tests/gherkin/GherkinDialectProviderTest.vala \
	tests/gherkin/GherkinLineTest.vala \
	tests/gherkin/ParserTest.vala \
	tests/gherkin/pickles/CompilerTest.vala
	
test_libgherkin3_VALAFLAGS = \
	--pkg gio-2.0 \
	--pkg glib-2.0 \
	--pkg libgherkin3-0.1 \
	--pkg json-glib-1.0 \
	--pkg gee-0.8 \
	--pkg config \
	--target-glib=2.44.0 \
	--vapidir $(top_builddir) \
	--gresources $(top_srcdir)/data/gherkin3.gresource.xml \
	-g

test_libgherkin3_LDADD = \
	$(LIBGHERKIN3_LIBS) \
	$(top_builddir)/libgherkin3.la

CLEANFILES = \
	data/gherkin3-resource.c \
	$(libgherkin3_la_SOURCES:.vala=.c) \
	$(build_gherkin_generate_ast_SOURCES:.vala=.c) \
	$(test_libgherkin3_SOURCES:.vala=.c) \
	libgherkin3-0.1.vapi \
	libgherkin3.h \
	Gherkin3-1.0.gir \
	*.stamp

test: ${TEST_PROGS}
	@test -z "${TEST_PROGS}" || ${GTESTER} --verbose ${TEST_PROGS}
	@ for subdir in $(SUBDIRS) . ; do \
		test "$$subdir" = "." -o "$$subdir" = "po" || \
		( cd $$subdir && $(MAKE) $(AM_MAKEFLAGS) $@ ) || exit $? ; \
	done

# test-report: run tests in subdirs and generate report
# perf-report: run tests in subdirs with -m perf and generate report
# full-report: like test-report: with -m perf and -m slow
test-report perf-report full-report:	${TEST_PROGS}
	@test -z "${TEST_PROGS}" || { \
	  case $@ in \
	  test-report) test_options="-k";; \
	  perf-report) test_options="-k -m=perf";; \
	  full-report) test_options="-k -m=perf -m=slow";; \
	  esac ; \
	  if test -z "$$GTESTER_LOGDIR" ; then	\
	    ${GTESTER} --verbose $$test_options -o test-report.xml ${TEST_PROGS} ; \
	  elif test -n "${TEST_PROGS}" ; then \
	    ${GTESTER} --verbose $$test_options -o `mktemp "$$GTESTER_LOGDIR/log-XXXXXX"` ${TEST_PROGS} ; \
	  fi ; \
	}
	@ ignore_logdir=true ; \
	  if test -z "$$GTESTER_LOGDIR" ; then \
	    GTESTER_LOGDIR=`mktemp -d "\`pwd\`/.testlogs-XXXXXX"`; export GTESTER_LOGDIR ; \
	    ignore_logdir=false ; \
	  fi ; \
	  for subdir in $(SUBDIRS) . ; do \
	    test "$$subdir" = "." -o "$$subdir" = "po" || \
	    ( cd $$subdir && $(MAKE) $(AM_MAKEFLAGS) $@ ) || exit $? ; \
	  done ; \
	  $$ignore_logdir || { \
	    echo '<?xml version="1.0"?>' > $@.xml ; \
	    echo '<report-collection>'  >> $@.xml ; \
	    for lf in `ls -L "$$GTESTER_LOGDIR"/.` ; do \
	      sed '1,1s/^<?xml\b[^>?]*?>//' <"$$GTESTER_LOGDIR"/"$$lf" >> $@.xml ; \
	    done ; \
	    echo >> $@.xml ; \
	    echo '</report-collection>' >> $@.xml ; \
	    rm -rf "$$GTESTER_LOGDIR"/ ; \
	    ${GTESTER_REPORT} --version 2>/dev/null 1>&2 ; test "$$?" != 0 || ${GTESTER_REPORT} $@.xml >$@.html ; \
	  }
.PHONY: test test-report perf-report full-report
# run make test as part of make check
check-local: test

-include $(top_srcdir)/git.mk
