
CALAOS_VERSION
AC_INIT([calaos], [calaos_version], [team@calaos.fr])
AC_PREREQ([2.59])
AC_CONFIG_SRCDIR([configure.ac])
AC_CONFIG_MACRO_DIR([m4])

AC_CONFIG_HEADERS([config.h])

AM_INIT_AUTOMAKE([tar-ustar 1.6 dist-xz subdir-objects foreign])
m4_ifdef([AM_SILENT_RULES], [AM_SILENT_RULES([yes])])

AC_GNU_SOURCE
AC_SYS_LARGEFILE

LT_PREREQ([2.2])
LT_INIT([win32-dll])

AM_GNU_GETTEXT_VERSION([0.17])

m4_ifdef([AM_GNU_GETTEXT], [
AM_GNU_GETTEXT([external])
po_makefile_in=po/Makefile.in
have_po="yes"
],[
have_po="no"
])
AC_SUBST(LTLIBINTL)

if test "x${POSUB}" = "x" ; then
   have_po="no"
fi

AM_CONDITIONAL([HAVE_PO], [test "x${have_po}" = "xyes"])


### Needed information

AC_CANONICAL_BUILD
AC_CANONICAL_HOST

### Checks for programs
AC_PROG_CXX
AC_PROG_CC
AM_PROG_CC_C_O
AX_CXX_COMPILE_STDCXX_11([noext],[mandatory])

# pkg-config
PKG_PROG_PKG_CONFIG

### Checks for libraries

efl_ver="1.7.10"

requirements_calaos_common="eina >= ${efl_ver} eet >= ${efl_ver} ecore >= ${efl_ver} ecore-file >= ${efl_ver} ecore-con >= ${efl_ver} sigc++-2.0 >= 2.4.1 jansson >= 2.5 libcurl >= 7.20.0 luajit"
PKG_CHECK_MODULES([CALAOS_COMMON], [${requirements_calaos_common}])
AC_SUBST([requirements_calaos_common])

requirements_calaos_server="eina >= ${efl_ver} eet >= ${efl_ver} ecore >= ${efl_ver} ecore-file >= ${efl_ver} ecore-con >= ${efl_ver} libcurl"
PKG_CHECK_MODULES([CALAOS_SERVER], [${requirements_calaos_server}])
AC_SUBST([requirements_calaos_server])

CALAOS_COMMON_LIBS="${CALAOS_COMMON_LIBS} ${LUA_LIBS} ${lua_libs}"
CALAOS_COMMON_CFLAGS="${CALAOS_COMMON_CFLAGS} ${LUA_CFLAGS}"

requirements_calaos_home="evas >= ${efl_ver} edje >= ${efl_ver} eina >= ${efl_ver} eet >= ${efl_ver} ecore >= ${efl_ver} ecore-file >= ${efl_ver} ecore-con >= ${efl_ver} elementary >= ${efl_ver} openssl >= 1.0.0 libcurl"
PKG_CHECK_MODULES([CALAOS_HOME], [${requirements_calaos_home}], [have_calaos_home_dep="yes"], [have_calaos_home_dep="no"])
AM_CONDITIONAL([HAVE_CALAOS_HOME_BIN], [test "x${have_calaos_home_dep}" = "xyes"])

AC_SUBST([requirements_calaos_home])


### Check if elm_web_url_get is present. This function has been added in efl 1.8 and elm_web_uri_get
### has been deprecated and  elm_web_uri_get has been removed in efl 1.10
PKG_CHECK_MODULES([ELM_WEB_URL], [elementary >= 1.7.99], [have_elm_web_url="yes"], [have_elm_web_url="no"])
AM_CONDITIONAL([HAVE_ELM_WEB_URL], [test "x${have_elm_web_url}" = "xyes"])
if test "x${have_elm_web_url}" == "xyes"
then 
     AC_DEFINE([HAVE_ELM_WEB_URL], [1], [elm_web_url])
fi

EFL_CHECK_FUNCS([CALAOS_HOME], [dlopen])

## Theme
AC_ARG_ENABLE([theme],
   [AC_HELP_STRING(
       [--disable-theme],
       [disable theme. @<:@default=enabled@:>@])],
   [
    if test "x${enableval}" = "xyes"; then
       build_theme="yes"
    else
       build_theme="no"
    fi
   ],
   [build_theme="yes"])

AM_CONDITIONAL([CALAOS_BUILD_THEME], [test "x${build_theme}" = "xyes"])

AC_MSG_CHECKING([whether Theme is to be built])
AC_MSG_RESULT([${build_theme}])

AM_CONDITIONAL([ENNA_BUILD_THEME], [test "x${build_theme}" = "xyes"])
### Checks for compiler characteristics
AC_C_BIGENDIAN
AC_C_INLINE

### Checks for linker characteristics
lt_enable_auto_import=""
case "${host_os}" in
   mingw*)
      lt_enable_auto_import="-Wl,--enable-auto-import"
   ;;
esac
AC_SUBST([lt_enable_auto_import])

EFL_CHECK_COMPILER_FLAGS([CALAOS_COMMON], [-Wall -Wextra -Wno-unused-parameter -Wshadow -Wpointer-arith -Wno-missing-field-initializers -fvisibility=hidden -fdata-sections -ffunction-sections])

### Checks for header files
AC_HEADER_ASSERT
AC_CHECK_HEADERS([unistd.h])

have_owcapi="no"

AC_CHECK_HEADERS([owcapi.h], [have_owcapi="yes"])
AM_CONDITIONAL([HAVE_OWCAPI], [test "x${have_owcapi}" = "xyes"])
if test "x${have_owcapi}" == "xyes"
then
    AC_CHECK_LIB([owcapi], [OW_init],, AC_ERROR([Misssing owfs library]))
fi

have_ewebkit="no"
PKG_CHECK_MODULES([EWEBKIT], [ewebkit], [have_ewebkit="yes"], [have_ewebkit="no"])
AM_CONDITIONAL([HAVE_EWEBKIT], [test "x${have_ewebkit}" = "xyes"])
if test "x${have_ewebkit}" == "xyes"
then 
     AC_DEFINE([HAVE_EWEBKIT], [1], [ewebkit])
fi

have_ecore_x="no"
PKG_CHECK_MODULES([ECORE_X], [ecore-x x11 xext], [have_ecore_x="yes"], [have_ecore_x="no"])
AM_CONDITIONAL([HAVE_ECORE_X], [test "x${have_ecore_x}" = "xyes"])
if test "x${have_ecore_x}" == "xyes"
then 
     AC_DEFINE([HAVE_ECORE_X], [1], [ecore_x])
fi

have_libusb="no"
PKG_CHECK_MODULES([LIBUSB], [libusb-1.0], [have_libusb="yes"], [have_libusb="no"])
AM_CONDITIONAL([HAVE_LIBUSB], [test "x${have_libusb}" = "xyes"])
if test "x${have_libusb}" == "xyes"
then 
     AC_DEFINE([HAVE_LIBUSB], [1], [libusb])
fi

have_libola="no"
PKG_CHECK_MODULES([LIBOLA], [libola], [have_libola="yes"], [have_libola="no"])
AM_CONDITIONAL([HAVE_LIBOLA], [test "x${have_libola}" = "xyes"])
if test "x${have_libola}" == "xyes"
then
     AC_DEFINE([HAVE_LIBOLA], [1], [libola])
fi

have_knx="no"
PKG_CHECK_MODULES([LIBKNX], [libeibnetmux], [have_libknx="yes"], [have_libknx="no"])
AM_CONDITIONAL([HAVE_LIBKNX], [test "x${have_libknx}" = "xyes"])
if test "x${have_libknx}" == "xyes"
then
     AC_DEFINE([HAVE_LIBKNX], [1], [libknx])
fi

# Configure pthreads.
ACX_PTHREAD([have_pthread=yes])

#check for gtest
AC_LANG_PUSH([C++])
AC_CHECK_HEADERS([gtest/gtest.h], [have_gtest="yes"])
AM_CONDITIONAL([HAVE_GTEST], [test "x${have_gtest}" = "xyes"])
AC_LANG_POP([C++])
if test "x${have_gtest}" == "xyes"
then
     GTEST_INFO="make check"
else
     GTEST_INFO="install gtest to run this test"
fi

#check for autobahn test suite
AC_CHECK_PROG(HAVE_AUTOBAHN, wstest, yes)
AM_CONDITIONAL([HAVE_AUTOBAHN], [test "x${HAVE_AUTOBAHN}" = "xyes"])
if test "x${HAVE_AUTOBAHN}" == "xyes"
then
     WS_INFO="make check"
else
     WS_INFO="install autobahn testsuite to run this test"
fi

CALAOS_LTMODULE_FLAGS="-shared -module -avoid-version -export-dynamic"
AC_SUBST([CALAOS_LTMODULE_FLAGS])

AC_CONFIG_FILES([
Makefile
tests/Makefile
src/Makefile
src/lib/Makefile
src/bin/Makefile
src/bin/calaos_server/Makefile
src/bin/calaos_home/Makefile
src/bin/tools/Makefile
src/widgets/Makefile
src/widgets/clock/Makefile
src/widgets/note/Makefile
data/Makefile
data/debug/Makefile
data/debug/dist/Makefile
data/themes/Makefile
data/themes/default/Makefile
data/themes/widgets/Makefile
data/themes/widgets/clock/Makefile
data/themes/widgets/note/Makefile
$po_makefile_in
])

AC_OUTPUT

#####################################################################
## Info

echo
echo
echo "------------------------------------------------------------------------"
echo "$PACKAGE $VERSION"
echo "------------------------------------------------------------------------"
echo
echo
echo "Configuration Options Summary:"
echo
echo "Compilation............................: make (or gmake)"
echo "  CPPFLAGS.............................: $CPPFLAGS"
echo "  CFLAGS...............................: $CFLAGS"
echo "  LDFLAGS..............................: $LDFLAGS"
echo
echo "Test Suite:"
echo "  gtest library........................: $GTEST_INFO"
echo "  Autobahn Websocket test suite........: $WS_INFO"
echo
echo "Installation...........................: make install (as root if needed, with 'su' or 'sudo')"
echo "  prefix...............................: $prefix"
echo
echo " Build Calaos Server...................: yes"
echo " Build Calaos Home.....................: $have_calaos_home_dep"
echo " Build theme...........................: $build_theme"
echo
echo " One Wire support......................: ${have_owcapi}"
echo " EWebkit support.......................: ${have_ewebkit}"
echo " Ecore_X support.......................: ${have_ecore_x}"
echo " Libusb support........................: ${have_libusb}"
echo " Open Lightning Architecture support...: ${have_libola}"
echo " Eib/KNX support (libeibnetmux)........: ${have_libknx}"

echo
