EXTRA_DIST = handler manager tester checker.c globaliser.c handler.c helper.c informant.c initialiser.c manager.c optionaliser.c orienter.c tester.c

bin_PROGRAMS = cyboi

cyboi_SOURCES = cyboi.c

if LINUX_OPERATING_SYSTEM
    OS = -DGNU_LINUX_OPERATING_SYSTEM
endif

if WIN32_OPERATING_SYSTEM
    OS = -DWIN32_OPERATING_SYSTEM
endif

AM_CFLAGS = -I/usr/include $(OS)
