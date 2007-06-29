#
# $RCSfile: Makefile,v $
#
# Copyright (c) 2003. Michael Simon. All rights reserved.
# Copyright (c) 2004-2007. Christian Heller. All rights reserved.
#
# This software is published under the GPL GNU General Public License.
# This program is free software; you can redistribute it and/or
# modify it under the terms of the GNU General Public License
# as published by the Free Software Foundation; either version 2
# of the License, or (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
#
# http://www.cybop.net
# - Cybernetics Oriented Programming -
#
# @version $Revision: 1.47 $ $Date: 2007-06-29 22:55:30 $ $Author: christian $
# @author Michael Simon <michael.simon@gmx.net>
# @author Christian Heller <christian.heller@tuxtax.de>
#

#
# Required packages:
# - gcc
# - libc6-dev
# - libxml2
# - xlibs-dev
# - libgl1-mesa-dev
#
# CAUTION! TABS must NOT be replaced with SPACES!
# Otherwise, the makefile will not work.
#
# Example for compiling a program:
# gcc hello.c -o hello.exe
#
# if SYSTEM_1
#     include "system_1.h"
# elif SYSTEM_2
#     include "system_2.h"
# elif SYSTEM_3
#     ...
# endif
#
# define FOO 4
# x = FOO;        expands to x = 4;
# undef FOO
# x = FOO;        expands to x = FOO;
#
# #if, #ifdef, or #ifndef
#
# Conditionals can be nested. Example:
#
# ifdef MACRO
#     controlled text
# endif /* MACRO */
#
# if i >= 10
#     text-if-true
# else /* Not expression */
#     text-if-false
# endif /* Not expression */
#
# if X == 1
#     ...
# elif X == 2
#     ...
# else /* X != 2 and X != 1 */
# ...
# endif /* X != 2 and X != 1 */
#
# The #else is allowed after any number of #elif directives, but #elif may not follow #else.
#

#
# Path constants.
#

ROOT = ..
ADMIN = $(ROOT)/admin
BIN = $(ROOT)/bin
DIST = $(ROOT)/dist
DOC = $(ROOT)/doc
OBJ = $(ROOT)/obj
SRC = $(ROOT)/src

#
# File constants.
#

BINARY = cyboi
# Normal compiler to generate a gnu/linux executable.
COMPILER = gcc
# Cross-compiler to generate a windows executable.
#COMPILER = /usr/bin/i586-mingw32msvc-gcc
#-Wall -pedantic

# The "-I" option forces the compiler to look for uninstalled headers in the
# current source directory before searching the system directories for
# installed headers of the same name.
COMPILER_FLAGS = -g -l/usr/include -I/usr/include/libxml2 -I/usr/X11R6/include -l/usr/include/GL \
	-D GNU_LINUX_OPERATING_SYSTEM
#	-D WIN32_OPERATING_SYSTEM
# INTEL_300_PROCESSOR // 80386
# INTEL_400_PROCESSOR // 80486
# BLEND_500_PROCESSOR
# PENTIUM_500_PROCESSOR
# PENTIUM_PRO_600_PROCESSOR

#
# Wildcards.
#

#vpath %.c $(SRC)
#vpath %.o $(OBJ)

MAIN_SOURCE = $(SRC)/controller/cyboi.c

# Applicator.
APPLICATOR_SOURCES = $(wildcard $(SRC)/applicator/*.c)
APPLICATOR_OBJECTS = $(patsubst $(SRC)/applicator/%.c,$(OBJ)/applicator/%.o,$(APPLICATOR_SOURCES))
APPLICATOR_COMPARE_SOURCES = $(wildcard $(SRC)/applicator/compare/*.c)
APPLICATOR_COMPARE_OBJECTS = $(patsubst $(SRC)/applicator/compare/%.c,$(OBJ)/applicator/compare/%.o,$(APPLICATOR_COMPARE_SOURCES))
APPLICATOR_COMPARE_EQUAL_SOURCES = $(wildcard $(SRC)/applicator/compare/equal/*.c)
APPLICATOR_COMPARE_EQUAL_OBJECTS = $(patsubst $(SRC)/applicator/compare/equal/%.c,$(OBJ)/applicator/compare/equal/%.o,$(APPLICATOR_COMPARE_EQUAL_SOURCES))
APPLICATOR_COPY_SOURCES = $(wildcard $(SRC)/applicator/copy/*.c)
APPLICATOR_COPY_OBJECTS = $(patsubst $(SRC)/applicator/copy/%.c,$(OBJ)/applicator/copy/%.o,$(APPLICATOR_COPY_SOURCES))
APPLICATOR_COUNT_SOURCES = $(wildcard $(SRC)/applicator/count/*.c)
APPLICATOR_COUNT_OBJECTS = $(patsubst $(SRC)/applicator/count/%.c,$(OBJ)/applicator/count/%.o,$(APPLICATOR_COUNT_SOURCES))
APPLICATOR_GET_SOURCES = $(wildcard $(SRC)/applicator/get/*.c)
APPLICATOR_GET_OBJECTS = $(patsubst $(SRC)/applicator/get/%.c,$(OBJ)/applicator/get/%.o,$(APPLICATOR_GET_SOURCES))
APPLICATOR_INTERRUPT_SOURCES = $(wildcard $(SRC)/applicator/interrupt/*.c)
APPLICATOR_INTERRUPT_OBJECTS = $(patsubst $(SRC)/applicator/interrupt/%.c,$(OBJ)/applicator/interrupt/%.o,$(APPLICATOR_INTERRUPT_SOURCES))
APPLICATOR_RECEIVE_SOURCES = $(wildcard $(SRC)/applicator/receive/*.c)
APPLICATOR_RECEIVE_OBJECTS = $(patsubst $(SRC)/applicator/receive/%.c,$(OBJ)/applicator/receive/%.o,$(APPLICATOR_RECEIVE_SOURCES))
APPLICATOR_RUN_SOURCES = $(wildcard $(SRC)/applicator/run/*.c)
APPLICATOR_RUN_OBJECTS = $(patsubst $(SRC)/applicator/run/%.c,$(OBJ)/applicator/run/%.o,$(APPLICATOR_RUN_SOURCES))
APPLICATOR_SEND_SOURCES = $(wildcard $(SRC)/applicator/send/*.c)
APPLICATOR_SEND_OBJECTS = $(patsubst $(SRC)/applicator/send/%.c,$(OBJ)/applicator/send/%.o,$(APPLICATOR_SEND_SOURCES))
APPLICATOR_SHUTDOWN_SOURCES = $(wildcard $(SRC)/applicator/shutdown/*.c)
APPLICATOR_SHUTDOWN_OBJECTS = $(patsubst $(SRC)/applicator/shutdown/%.c,$(OBJ)/applicator/shutdown/%.o,$(APPLICATOR_SHUTDOWN_SOURCES))
APPLICATOR_STARTUP_SOURCES = $(wildcard $(SRC)/applicator/startup/*.c)
APPLICATOR_STARTUP_OBJECTS = $(patsubst $(SRC)/applicator/startup/%.c,$(OBJ)/applicator/startup/%.o,$(APPLICATOR_STARTUP_SOURCES))
APPLICATOR_SUSPEND_SOURCES = $(wildcard $(SRC)/applicator/suspend/*.c)
APPLICATOR_SUSPEND_OBJECTS = $(patsubst $(SRC)/applicator/suspend/%.c,$(OBJ)/applicator/suspend/%.o,$(APPLICATOR_SUSPEND_SOURCES))

# Controller.
CONTROLLER_SOURCES = $(wildcard $(SRC)/controller/*.c)
CONTROLLER_OBJECTS = $(patsubst $(SRC)/controller/%.c,$(OBJ)/controller/%.o,$(CONTROLLER_SOURCES))
CONTROLLER_HANDLER_SOURCES = $(wildcard $(SRC)/controller/handler/*.c)
CONTROLLER_HANDLER_OBJECTS = $(patsubst $(SRC)/controller/handler/%.c,$(OBJ)/controller/handler/%.o,$(CONTROLLER_HANDLER_SOURCES))
CONTROLLER_MANAGER_SOURCES = $(wildcard $(SRC)/controller/manager/*.c)
CONTROLLER_MANAGER_OBJECTS = $(patsubst $(SRC)/controller/manager/%.c,$(OBJ)/controller/manager/%.o,$(CONTROLLER_MANAGER_SOURCES))

# Globals.
GLOBALS_CONSTANTS_SOURCES = $(wildcard $(SRC)/globals/constants/*.c)
GLOBALS_CONSTANTS_OBJECTS = $(patsubst $(SRC)/globals/constants/%.c,$(OBJ)/globals/constants/%.o,$(GLOBALS_CONSTANTS_SOURCES))
GLOBALS_CONSTANTS_BOOLEAN_SOURCES = $(wildcard $(SRC)/globals/constants/boolean/*.c)
GLOBALS_CONSTANTS_BOOLEAN_OBJECTS = $(patsubst $(SRC)/globals/constants/boolean/%.c,$(OBJ)/globals/constants/boolean/%.o,$(GLOBALS_CONSTANTS_BOOLEAN_SOURCES))
GLOBALS_CONSTANTS_CHARACTER_SOURCES = $(wildcard $(SRC)/globals/constants/character/*.c)
GLOBALS_CONSTANTS_CHARACTER_OBJECTS = $(patsubst $(SRC)/globals/constants/character/%.c,$(OBJ)/globals/constants/character/%.o,$(GLOBALS_CONSTANTS_CHARACTER_SOURCES))
GLOBALS_CONSTANTS_COMMAND_LINE_SOURCES = $(wildcard $(SRC)/globals/constants/command_line/*.c)
GLOBALS_CONSTANTS_COMMAND_LINE_OBJECTS = $(patsubst $(SRC)/globals/constants/command_line/%.c,$(OBJ)/globals/constants/command_line/%.o,$(GLOBALS_CONSTANTS_COMMAND_LINE_SOURCES))
GLOBALS_CONSTANTS_CONSOLE_SOURCES = $(wildcard $(SRC)/globals/constants/console/*.c)
GLOBALS_CONSTANTS_CONSOLE_OBJECTS = $(patsubst $(SRC)/globals/constants/console/%.c,$(OBJ)/globals/constants/console/%.o,$(GLOBALS_CONSTANTS_CONSOLE_SOURCES))
GLOBALS_CONSTANTS_CYBOL_SOURCES = $(wildcard $(SRC)/globals/constants/cybol/*.c)
GLOBALS_CONSTANTS_CYBOL_OBJECTS = $(patsubst $(SRC)/globals/constants/cybol/%.c,$(OBJ)/globals/constants/cybol/%.o,$(GLOBALS_CONSTANTS_CYBOL_SOURCES))
GLOBALS_CONSTANTS_FLOAT_SOURCES = $(wildcard $(SRC)/globals/constants/float/*.c)
GLOBALS_CONSTANTS_FLOAT_OBJECTS = $(patsubst $(SRC)/globals/constants/float/%.c,$(OBJ)/globals/constants/float/%.o,$(GLOBALS_CONSTANTS_FLOAT_SOURCES))
GLOBALS_CONSTANTS_HTTP_SOURCES = $(wildcard $(SRC)/globals/constants/http/*.c)
GLOBALS_CONSTANTS_HTTP_OBJECTS = $(patsubst $(SRC)/globals/constants/http/%.c,$(OBJ)/globals/constants/http/%.o,$(GLOBALS_CONSTANTS_HTTP_SOURCES))
GLOBALS_CONSTANTS_INTEGER_SOURCES = $(wildcard $(SRC)/globals/constants/integer/*.c)
GLOBALS_CONSTANTS_INTEGER_OBJECTS = $(patsubst $(SRC)/globals/constants/integer/%.c,$(OBJ)/globals/constants/integer/%.o,$(GLOBALS_CONSTANTS_INTEGER_SOURCES))
GLOBALS_CONSTANTS_LOG_MESSAGE_SOURCES = $(wildcard $(SRC)/globals/constants/log_message/*.c)
GLOBALS_CONSTANTS_LOG_MESSAGE_OBJECTS = $(patsubst $(SRC)/globals/constants/log_message/%.c,$(OBJ)/globals/constants/log_message/%.o,$(GLOBALS_CONSTANTS_LOG_MESSAGE_SOURCES))
GLOBALS_CONSTANTS_MEMORY_STRUCTURE_SOURCES = $(wildcard $(SRC)/globals/constants/memory_structure/*.c)
GLOBALS_CONSTANTS_MEMORY_STRUCTURE_OBJECTS = $(patsubst $(SRC)/globals/constants/memory_structure/%.c,$(OBJ)/globals/constants/memory_structure/%.o,$(GLOBALS_CONSTANTS_MEMORY_STRUCTURE_SOURCES))
GLOBALS_CONSTANTS_SHELL_COMMAND_SOURCES = $(wildcard $(SRC)/globals/constants/shell_command/*.c)
GLOBALS_CONSTANTS_SHELL_COMMAND_OBJECTS = $(patsubst $(SRC)/globals/constants/shell_command/%.c,$(OBJ)/globals/constants/shell_command/%.o,$(GLOBALS_CONSTANTS_SHELL_COMMAND_SOURCES))
GLOBALS_CONSTANTS_XDT_SOURCES = $(wildcard $(SRC)/globals/constants/xdt/*.c)
GLOBALS_CONSTANTS_XDT_OBJECTS = $(patsubst $(SRC)/globals/constants/xdt/%.c,$(OBJ)/globals/constants/xdt/%.o,$(GLOBALS_CONSTANTS_XDT_SOURCES))
GLOBALS_LOGGER_SOURCES = $(wildcard $(SRC)/globals/logger/*.c)
GLOBALS_LOGGER_OBJECTS = $(patsubst $(SRC)/globals/logger/%.c,$(OBJ)/globals/logger/%.o,$(GLOBALS_LOGGER_SOURCES))
GLOBALS_VARIABLES_SOURCES = $(wildcard $(SRC)/globals/variables/*.c)
GLOBALS_VARIABLES_OBJECTS = $(patsubst $(SRC)/globals/variables/%.c,$(OBJ)/globals/variables/%.o,$(GLOBALS_VARIABLES_SOURCES))

# Memoriser.
MEMORISER_SOURCES = $(wildcard $(SRC)/memoriser/*.c)
MEMORISER_OBJECTS = $(patsubst $(SRC)/memoriser/%.c,$(OBJ)/memoriser/%.o,$(MEMORISER_SOURCES))
MEMORISER_ACCESSOR_SOURCES = $(wildcard $(SRC)/memoriser/accessor/*.c)
MEMORISER_ACCESSOR_OBJECTS = $(patsubst $(SRC)/memoriser/accessor/%.c,$(OBJ)/memoriser/accessor/%.o,$(MEMORISER_ACCESSOR_SOURCES))
MEMORISER_ALLOCATOR_SOURCES = $(wildcard $(SRC)/memoriser/allocator/*.c)
MEMORISER_ALLOCATOR_OBJECTS = $(patsubst $(SRC)/memoriser/allocator/%.c,$(OBJ)/memoriser/allocator/%.o,$(MEMORISER_ALLOCATOR_SOURCES))
MEMORISER_ARRAY_SOURCES = $(wildcard $(SRC)/memoriser/array/*.c)
MEMORISER_ARRAY_OBJECTS = $(patsubst $(SRC)/memoriser/array/%.c,$(OBJ)/memoriser/array/%.o,$(MEMORISER_ARRAY_SOURCES))
MEMORISER_COMMUNICATOR_SOURCES = $(wildcard $(SRC)/memoriser/communicator/*.c)
MEMORISER_COMMUNICATOR_OBJECTS = $(patsubst $(SRC)/memoriser/communicator/%.c,$(OBJ)/memoriser/communicator/%.o,$(MEMORISER_COMMUNICATOR_SOURCES))
MEMORISER_CONVERTER_SOURCES = $(wildcard $(SRC)/memoriser/converter/*.c)
MEMORISER_CONVERTER_OBJECTS = $(patsubst $(SRC)/memoriser/converter/%.c,$(OBJ)/memoriser/converter/%.o,$(MEMORISER_CONVERTER_SOURCES))
MEMORISER_MAPPER_SOURCES = $(wildcard $(SRC)/memoriser/mapper/*.c)
MEMORISER_MAPPER_OBJECTS = $(patsubst $(SRC)/memoriser/mapper/%.c,$(OBJ)/memoriser/mapper/%.o,$(MEMORISER_MAPPER_SOURCES))
MEMORISER_TRANSLATOR_SOURCES = $(wildcard $(SRC)/memoriser/translator/*.c)
MEMORISER_TRANSLATOR_OBJECTS = $(patsubst $(SRC)/memoriser/translator/%.c,$(OBJ)/memoriser/translator/%.o,$(MEMORISER_TRANSLATOR_SOURCES))

#
# Compiles all cyboi source files.
#
# - compiles sources
# - creates objects
# - creates binary
#
# CAUTION! Do NOT add a "$@" at the end!
# Otherwise, a compiler error will occur, because "make $@" is already used internally.
#
all: export \
	create \
	$(APPLICATOR_OBJECTS) \
	$(APPLICATOR_COMPARE_OBJECTS) \
	$(APPLICATOR_COMPARE_EQUAL_OBJECTS) \
	$(APPLICATOR_COPY_OBJECTS) \
	$(APPLICATOR_COUNT_OBJECTS) \
	$(APPLICATOR_GET_OBJECTS) \
	$(APPLICATOR_INTERRUPT_OBJECTS) \
	$(APPLICATOR_RECEIVE_OBJECTS) \
	$(APPLICATOR_RUN_OBJECTS) \
	$(APPLICATOR_SEND_OBJECTS) \
	$(APPLICATOR_SHUTDOWN_OBJECTS) \
	$(APPLICATOR_STARTUP_OBJECTS) \
	$(APPLICATOR_SUSPEND_OBJECTS) \
	$(CONTROLLER_OBJECTS) \
	$(CONTROLLER_HANDLER_OBJECTS) \
	$(CONTROLLER_MANAGER_OBJECTS) \
	$(GLOBALS_CONSTANTS_OBJECTS) \
	$(GLOBALS_CONSTANTS_BOOLEAN_OBJECTS) \
	$(GLOBALS_CONSTANTS_CHARACTER_OBJECTS) \
	$(GLOBALS_CONSTANTS_COMMAND_LINE_OBJECTS) \
	$(GLOBALS_CONSTANTS_CONSOLE_OBJECTS) \
	$(GLOBALS_CONSTANTS_CYBOL_OBJECTS) \
	$(GLOBALS_CONSTANTS_FLOAT_OBJECTS) \
	$(GLOBALS_CONSTANTS_HTTP_OBJECTS) \
	$(GLOBALS_CONSTANTS_INTEGER_OBJECTS) \
	$(GLOBALS_CONSTANTS_LOG_MESSAGE_OBJECTS) \
	$(GLOBALS_CONSTANTS_MEMORY_STRUCTURE_OBJECTS) \
	$(GLOBALS_CONSTANTS_SHELL_COMMAND_OBJECTS) \
	$(GLOBALS_CONSTANTS_XDT_OBJECTS) \
	$(GLOBALS_LOGGER_OBJECTS) \
	$(GLOBALS_VARIABLES_OBJECTS) \
	$(MEMORISER_OBJECTS) \
	$(MEMORISER_ACCESSOR_OBJECTS) \
	$(MEMORISER_ALLOCATOR_OBJECTS) \
	$(MEMORISER_ARRAY_OBJECTS) \
	$(MEMORISER_COMMUNICATOR_OBJECTS) \
	$(MEMORISER_CONVERTER_OBJECTS) \
	$(MEMORISER_MAPPER_OBJECTS) \
	$(MEMORISER_TRANSLATOR_OBJECTS) \
# Compile source files.
# The -mwindows switch is needed to create Windows executables instead of console applications.
# It assures the appropriate Windows libraries are linked in for you. To get a console screen
# along with a standard windows application, add the -mconsole flag as well as -mwindows.
	$(COMPILER) -c $(COMPILER_FLAGS) $(SRC)/controller/cyboi.c \
		-o $(OBJ)/controller/cyboi.o
# Link object files.
	$(COMPILER) -L/lib -L/usr/lib -L/usr/X11R6/lib \
		-o $(BIN)/$(BINARY) $(OBJ)/controller/cyboi.o -lpthread -lxml2 -lX11 -lGL -lGLU -lglut
# Print ready message.
	@echo Compiled cyboi files.

#
# Exports variables for cross-compilation under gnu/linux.
#
# If working with configure, then use the following flags:
# ./configure --host=i586-mingw32 --build=$(./config.guess) \
# --with-included-gettext --enable-client=win32 --prefix=.
#
export:
	export CC=i586-mingw32-gcc
	export AR=i586-mingw32-ar
	export RANLIB=i586-mingw32-ranlib

#
# Creates object directories and compiles cyboi source files into these.
#
# The commands have to stand in ONE line (or separated by "\"), because otherwise
# the "cd" command of the first line has no effect for the following lines.
#
create:
	-cd ..; mkdir obj; mkdir bin
	-cd $(OBJ); mkdir applicator
	-cd $(OBJ); mkdir applicator/compare
	-cd $(OBJ); mkdir applicator/compare/equal
	-cd $(OBJ); mkdir applicator/copy
	-cd $(OBJ); mkdir applicator/count
	-cd $(OBJ); mkdir applicator/get
	-cd $(OBJ); mkdir applicator/interrupt
	-cd $(OBJ); mkdir applicator/receive
	-cd $(OBJ); mkdir applicator/run
	-cd $(OBJ); mkdir applicator/send
	-cd $(OBJ); mkdir applicator/shutdown
	-cd $(OBJ); mkdir applicator/startup
	-cd $(OBJ); mkdir applicator/suspend
	-cd $(OBJ); mkdir controller
	-cd $(OBJ); mkdir controller/handler
	-cd $(OBJ); mkdir controller/manager
	-cd $(OBJ); mkdir globals
	-cd $(OBJ); mkdir globals/constants
	-cd $(OBJ); mkdir globals/constants/boolean
	-cd $(OBJ); mkdir globals/constants/character
	-cd $(OBJ); mkdir globals/constants/command_line
	-cd $(OBJ); mkdir globals/constants/console
	-cd $(OBJ); mkdir globals/constants/cybol
	-cd $(OBJ); mkdir globals/constants/float
	-cd $(OBJ); mkdir globals/constants/http
	-cd $(OBJ); mkdir globals/constants/integer
	-cd $(OBJ); mkdir globals/constants/log_message
	-cd $(OBJ); mkdir globals/constants/memory_structure
	-cd $(OBJ); mkdir globals/constants/shell_command
	-cd $(OBJ); mkdir globals/constants/xdt
	-cd $(OBJ); mkdir globals/logger
	-cd $(OBJ); mkdir globals/variables
	-cd $(OBJ); mkdir memoriser
	-cd $(OBJ); mkdir memoriser/accessor
	-cd $(OBJ); mkdir memoriser/allocator
	-cd $(OBJ); mkdir memoriser/array
	-cd $(OBJ); mkdir memoriser/communicator
	-cd $(OBJ); mkdir memoriser/converter
	-cd $(OBJ); mkdir memoriser/mapper
	-cd $(OBJ); mkdir memoriser/translator

#$(OBJ)/%.o: $(SRC)/%.c
#       $(COMPILER) -c $(COMPILER_FLAGS) $< -o $@

$(OBJ)/applicator/%.o: $(SRC)/applicator/%.c
	$(COMPILER) -c $(COMPILER_FLAGS) $< -o $@

$(OBJ)/applicator/compare/%.o: $(SRC)/applicator/compare/%.c
	$(COMPILER) -c $(COMPILER_FLAGS) $< -o $@

$(OBJ)/applicator/compare/equal/%.o: $(SRC)/applicator/compare/equal/%.c
	$(COMPILER) -c $(COMPILER_FLAGS) $< -o $@

$(OBJ)/applicator/copy/%.o: $(SRC)/applicator/copy/%.c
	$(COMPILER) -c $(COMPILER_FLAGS) $< -o $@

$(OBJ)/applicator/count/%.o: $(SRC)/applicator/count/%.c
	$(COMPILER) -c $(COMPILER_FLAGS) $< -o $@

$(OBJ)/applicator/get/%.o: $(SRC)/applicator/get/%.c
	$(COMPILER) -c $(COMPILER_FLAGS) $< -o $@

$(OBJ)/applicator/interrupt/%.o: $(SRC)/applicator/interrupt/%.c
	$(COMPILER) -c $(COMPILER_FLAGS) $< -o $@

$(OBJ)/applicator/receive/%.o: $(SRC)/applicator/receive/%.c
	$(COMPILER) -c $(COMPILER_FLAGS) $< -o $@

$(OBJ)/applicator/run/%.o: $(SRC)/applicator/run/%.c
	$(COMPILER) -c $(COMPILER_FLAGS) $< -o $@

$(OBJ)/applicator/send/%.o: $(SRC)/applicator/send/%.c
	$(COMPILER) -c $(COMPILER_FLAGS) $< -o $@

$(OBJ)/applicator/shutdown/%.o: $(SRC)/applicator/shutdown/%.c
	$(COMPILER) -c $(COMPILER_FLAGS) $< -o $@

$(OBJ)/applicator/startup/%.o: $(SRC)/applicator/startup/%.c
	$(COMPILER) -c $(COMPILER_FLAGS) $< -o $@

$(OBJ)/applicator/suspend/%.o: $(SRC)/applicator/suspend/%.c
	$(COMPILER) -c $(COMPILER_FLAGS) $< -o $@

$(OBJ)/controller/%.o: $(SRC)/controller/%.c
	$(COMPILER) -c $(COMPILER_FLAGS) $< -o $@

$(OBJ)/controller/handler/%.o: $(SRC)/controller/handler/%.c
	$(COMPILER) -c $(COMPILER_FLAGS) $< -o $@

$(OBJ)/controller/manager/%.o: $(SRC)/controller/manager/%.c
	$(COMPILER) -c $(COMPILER_FLAGS) $< -o $@

$(OBJ)/globals/constants/%.o: $(SRC)/globals/constants/%.c
	$(COMPILER) -c $(COMPILER_FLAGS) $< -o $@

$(OBJ)/globals/constants/boolean/%.o: $(SRC)/globals/constants/boolean/%.c
	$(COMPILER) -c $(COMPILER_FLAGS) $< -o $@

$(OBJ)/globals/constants/character/%.o: $(SRC)/globals/constants/character/%.c
	$(COMPILER) -c $(COMPILER_FLAGS) $< -o $@

$(OBJ)/globals/constants/command_line/%.o: $(SRC)/globals/constants/command_line/%.c
	$(COMPILER) -c $(COMPILER_FLAGS) $< -o $@

$(OBJ)/globals/constants/console/%.o: $(SRC)/globals/constants/console/%.c
	$(COMPILER) -c $(COMPILER_FLAGS) $< -o $@

$(OBJ)/globals/constants/cybol/%.o: $(SRC)/globals/constants/cybol/%.c
	$(COMPILER) -c $(COMPILER_FLAGS) $< -o $@

$(OBJ)/globals/constants/float/%.o: $(SRC)/globals/constants/float/%.c
	$(COMPILER) -c $(COMPILER_FLAGS) $< -o $@

$(OBJ)/globals/constants/http/%.o: $(SRC)/globals/constants/http/%.c
	$(COMPILER) -c $(COMPILER_FLAGS) $< -o $@

$(OBJ)/globals/constants/integer/%.o: $(SRC)/globals/constants/integer/%.c
	$(COMPILER) -c $(COMPILER_FLAGS) $< -o $@

$(OBJ)/globals/constants/log_message/%.o: $(SRC)/globals/constants/log_message/%.c
	$(COMPILER) -c $(COMPILER_FLAGS) $< -o $@

$(OBJ)/globals/constants/memory_structure/%.o: $(SRC)/globals/constants/memory_structure/%.c
	$(COMPILER) -c $(COMPILER_FLAGS) $< -o $@

$(OBJ)/globals/constants/shell_command/%.o: $(SRC)/globals/constants/shell_command/%.c
	$(COMPILER) -c $(COMPILER_FLAGS) $< -o $@

$(OBJ)/globals/constants/xdt/%.o: $(SRC)/globals/constants/xdt/%.c
	$(COMPILER) -c $(COMPILER_FLAGS) $< -o $@

$(OBJ)/globals/logger/%.o: $(SRC)/globals/logger/%.c
	$(COMPILER) -c $(COMPILER_FLAGS) $< -o $@

$(OBJ)/globals/variables/%.o: $(SRC)/globals/variables/%.c
	$(COMPILER) -c $(COMPILER_FLAGS) $< -o $@

$(OBJ)/memoriser/%.o: $(SRC)/memoriser/%.c
	$(COMPILER) -c $(COMPILER_FLAGS) $< -o $@

$(OBJ)/memoriser/accessor/%.o: $(SRC)/memoriser/accessor/%.c
	$(COMPILER) -c $(COMPILER_FLAGS) $< -o $@

$(OBJ)/memoriser/allocator/%.o: $(SRC)/memoriser/allocator/%.c
	$(COMPILER) -c $(COMPILER_FLAGS) $< -o $@

$(OBJ)/memoriser/array/%.o: $(SRC)/memoriser/array/%.c
	$(COMPILER) -c $(COMPILER_FLAGS) $< -o $@

$(OBJ)/memoriser/communicator/%.o: $(SRC)/memoriser/communicator/%.c
	$(COMPILER) -c $(COMPILER_FLAGS) $< -o $@

$(OBJ)/memoriser/converter/%.o: $(SRC)/memoriser/converter/%.c
	$(COMPILER) -c $(COMPILER_FLAGS) $< -o $@

$(OBJ)/memoriser/mapper/%.o: $(SRC)/memoriser/mapper/%.c
	$(COMPILER) -c $(COMPILER_FLAGS) $< -o $@

$(OBJ)/memoriser/translator/%.o: $(SRC)/memoriser/translator/%.c
	$(COMPILER) -c $(COMPILER_FLAGS) $< -o $@

#
# Creates cybop distribution tarball.
#
cybop-dist:
	@echo Create cybop distribution tarball.
	-cd ..; mkdir dist
	-cd ..; tar --create --verbose --gzip --file=dist/cybop.tar.gz --exclude-from admin/cybop-exclude --files-from admin/cybop-include
	@echo Successfully finished creating cybop distribution tarball.

#
# Creates cyboi distribution tarball.
#
cyboi-dist:
	@echo Create cyboi distribution tarball.
	-cd ..; mkdir dist
	-cd ..; tar --create --verbose --gzip --file=dist/cyboi.tar.gz --exclude-from admin/cyboi-exclude --files-from admin/cyboi-include
	@echo Successfully finished creating cyboi distribution tarball.

#
# Creates cybol distribution tarball.
#
cybol-dist:
	@echo Create cybol distribution tarball.
	-cd ..; mkdir dist
	-cd ..; tar --create --verbose --gzip --file=dist/cybol.tar.gz --exclude-from admin/cybol-exclude --files-from admin/cybol-include
	@echo Successfully finished creating cybol distribution tarball.

#
# Cleans cyboi files.
#
# - objects
# - binaries
# - distribution
#
.PHONY: clean
clean:
	-rm -f $(BIN)/cyboi
	-rm -r $(OBJ)
	@echo Cleaned compiled cyboi object files and binary.
