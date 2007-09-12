
EXTRA_DIST = handler manager checker.c globaliser.c handler.c initialiser.c manager.c optionaliser.c tester.c

bin_PROGRAMS = cyboi

cyboi_SOURCES = cyboi.c

if LINUX_OPERATING_SYSTEM
    OS = -DLINUX_OPERATING_SYSTEM
endif

if WIN32_OPERATING_SYSTEM
    OS = -DWIN32_OPERATING_SYSTEM
endif

if LINUX_EMULATION
    EMUL = -L/usr/lib32
endif

AM_CFLAGS = -I/usr/include $(LIBXML2_CFLAGS) $(OS)

LDADD = $(EMUL) @LIBXML2_LIBS@

