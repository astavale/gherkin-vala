AC_PREREQ(2.63)
AC_INIT([libgherkin3],
        [0.1],
        [https://github.com/chebizarro/gherkin3/issues],
        [dia3],
        [https://github.com/chebizarro/gherkin3])

AC_CONFIG_SRCDIR([Makefile.am])
AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_HEADERS([config.h])
AM_INIT_AUTOMAKE([1.11 foreign subdir-objects])
AM_MAINTAINER_MODE([enable])

dnl AM_SILENT_RULES([yes])

AC_PROG_CC
AM_PROG_AR
AM_PROG_VALAC

dnl ***************************************************************************
dnl Check for Windows
dnl ***************************************************************************
AC_CANONICAL_HOST

case $host_os in
  *mingw*)
    platform_win32=yes
    native_win32=yes
    ;;
  pw32* | *cygwin*)
    platform_win32=yes
    native_win32=no
    ;;
  *)
    platform_win32=no
    native_win32=no
    ;;
esac
AM_CONDITIONAL(PLATFORM_WIN32, test x"$platform_win32" = "xyes")
AM_CONDITIONAL(NATIVE_WIN32, test x"$native_win32" = "xyes")

LT_INIT([disable-static])

AC_PATH_PROG(GLIB_COMPILE_RESOURCES, glib-compile-resources)

pkg_modules="glib-2.0 gobject-2.0 json-glib-1.0 gee-0.8"
AC_SUBST(pkg_modules)

GHERKIN_DATA_DIR='$(datadir)/Gherkin'
AC_SUBST(GHERKIN_DATA_DIR)
GHERKIN_TEST_DIR=[${PWD}/Gherkin.Specs]
AC_SUBST(GHERKIN_TEST_DIR)
GHERKIN_SRC_DIR=[${PWD}/Gherkin]
AC_SUBST(GHERKIN_SRC_DIR)

PKG_CHECK_MODULES([LIBGHERKIN3], [$pkg_modules])
AC_SUBST(LIBGHERKIN3_CFLAGS)

AC_CONFIG_FILES([
	Makefile
	libgherkin3-0.1.pc
])

AC_OUTPUT
