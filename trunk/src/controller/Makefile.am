## Makefile.am -- Process this file with automake to produce Makefile.in

# The sub directories to be built.
SUBDIRS = handler \
    manager

# The binary program file.
bin_PROGRAMS = cyboi

cyboi_SOURCES = cyboi.c \
    optionaliser.c \
    tester.c \
    manager.c \
    checker.c \
    handler.c

# Link with libraries.
# CAUTION! Extra objects which are passed to the linker.
# This is only used by programs and shared libraries.
# Use -l only to list third-party libraries,
# not when referring to libraries built by your package.
cyboi_LDADD = -L/lib -L/usr/lib -L/usr/X11R6/lib -l/usr/include -lpthread -lxml2 -lX11

# Like `_LDADD', but used for static libraries and not programs.
#cyboi_LIBADD =

# Include header files when compiling this directory.
AM_CPPFLAGS = -I/usr/include/libxml2 -I/usr/X11R6/include

# The source files to be built into an executable.
# This line causes each mentioned .c file to be compiled into the corresponding .o.
# Afterwards, all are linked to produce the executable.
#
# One FAQ is about hierarchical sources, held in sub directories.
# The following would bring an error:
# cyboi_SOURCES = subdir/something.c ...
# For programs, there is no simple solution.
# But recent versions of automake should address this.
cyboi_SOURCES = cyboi.c optionaliser.c tester.c manager.c checker.c handler.c
