dnl Process this file with autoconf to produce a configure script.

AC_PREREQ(2.59)

# Initialise autoconf with project name, version, email contact.
AC_INIT([cyboi], [0.8.0], [cybop-developers@lists.berlios.de])

# Force automake and autoconf to search auxiliary scripts in the given directory first.
# Specify the "config" directory to store many of the GNU Autotools
# intermediate files, such as install-sh.
# It may also be used to store all project specific Autoconf M4 macros.
#
# The historical default was to search auxiliary scripts in the immediate parent
# and grand-parent directories. If a sub package's `AC_CONFIG_AUX_DIR([.])' line was
# removed from subdir/configure.ac, that sub package would share the auxiliary script of the parent package.
# This may looks like a gain in size (a few kilobytes), but it is actually a loss of modularity as the
# sub package is no longer self-contained (`make dist' in the subdirectory will not work anymore).
AC_CONFIG_AUX_DIR([.])

# Initialise automake.
AM_INIT_AUTOMAKE([-Wall -Werror foreign])

# Specify c compiler.
AC_PROG_CC

# Add header files.
AC_CONFIG_HEADERS([config.h])

# Specify sub directories' makefiles.
AC_CONFIG_FILES([
Makefile
#src/Makefile
#src/controller/Makefile
])

# Call sub directories' ./configure scripts recursively.
AC_CONFIG_SUBDIRS([src])

# Write the configure file.
AC_OUTPUT
