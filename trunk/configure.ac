#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ(2.61)
AC_INIT([cybop], [0.9.0], [christian.heller@tuxtax.de])
AC_CONFIG_SRCDIR([src/controller/cyboi.c])
AC_CONFIG_AUX_DIR([build-aux])
AM_INIT_AUTOMAKE([gnu dist-bzip2 tar-ustar])
#AC_CONFIG_HEADER([config.h])

AC_CANONICAL_HOST

AC_MSG_CHECKING([Host cpu])
AC_MSG_RESULT([$host_cpu])

AC_MSG_CHECKING([For target cpu])

case $host in
    x86_64*linux*)
	test -n "$CC" || CC="gcc -m32"
	test -n "$LD" || LD="ld -m elf_i386"
	test -n "$AS" || AS="as --32"
	host_32bits_emulation="yes"
	host_cpu="i386"
    ;;
esac

AC_MSG_RESULT([$host_cpu])

AC_MSG_CHECKING([For operating system])
case $host_os in
    linux*)
	cybop_os_linux=yes
	AC_MSG_RESULT([Linux])
    ;;
    mingw*)
	cybop_os_win32=yes
	AC_MSG_RESULT([Win32])
    ;;
esac

AM_CONDITIONAL(LINUX_OPERATING_SYSTEM, [test "$cybop_os_linux" = "yes"])
AM_CONDITIONAL(WIN32_OPERATING_SYSTEM, [test "$cybop_os_win32" = "yes"])
AM_CONDITIONAL(LINUX_EMULATION, [test "$host_32bits_emulation" = "yes"])

# Checks for programs.
AC_PROG_CC
AC_PROG_CPP
AC_PROG_INSTALL
AC_PROG_LN_S
AC_PROG_MAKE_SET

AC_PROG_LIBTOOL

#AC_PKG_PROG_PKG_CONFIG

# Checks for libraries.
AC_CHECK_LIB([GL], [glClear])
AC_CHECK_LIB([GLU], [main])
AC_CHECK_LIB([X11], [XOpenDisplay])
AC_CHECK_LIB([glut], [glutInit])
AC_CHECK_LIB([pthread], [pthread_exit])
#AC_CHECK_LIB([xml2], [xmlParseFile])

PKG_CHECK_MODULES(LIBXML2,libxml-2.0 >= 2.4.30)
AC_SUBST(LIBXML2_CFLAGS)
AC_SUBST(LIBXML2_LIBS)

# Checks for header files.
AC_PATH_X
AC_HEADER_STDC
AC_HEADER_SYS_WAIT
AC_CHECK_HEADERS([arpa/inet.h fcntl.h locale.h netinet/in.h stddef.h stdlib.h string.h sys/socket.h termios.h unistd.h wchar.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_HEADER_STDBOOL
AC_TYPE_SIZE_T
AC_STRUCT_TM
AC_TYPE_UINT16_T
AC_C_VOLATILE

# Checks for library functions.
AC_FUNC_CHOWN
AC_FUNC_MALLOC
AC_FUNC_REALLOC
AC_FUNC_STRTOD
AC_CHECK_FUNCS([memset setlocale socket strtol])

AC_CONFIG_FILES([Makefile
		 src/Makefile
		 src/controller/Makefile])
AC_OUTPUT
