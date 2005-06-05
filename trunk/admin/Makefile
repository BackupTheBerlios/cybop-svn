#
# $RCSfile: Makefile,v $
#
# Copyright (c) 2003. Michael Simon. All rights reserved.
# Copyright (c) 2004-2005. Christian Heller. All rights reserved.
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
# @version $Revision: 1.30 $ $Date: 2005-06-05 11:12:17 $ $Author: christian $
# @author Michael Simon <michael.simon@gmx.net>
# @author Christian Heller <christian.heller@tuxtax.de>
#

#
# CAUTION!
#
# TABS must not be replaced with SPACES!
# Otherwise, the makefile will not work.
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
COMPILER = gcc
#-Wall -pedantic
COMPILER_FLAGS = -g -I/usr/X11R6/include -I/usr/include/libxml2 # -fsjlj-exceptions
# Compile with profiling support.
#COMPILER_FLAGS = -pg -I/usr/X11R6/include
#-pedantic

#
# Wildcards.
#

#vpath %.c $(SRC)
#vpath %.o $(OBJ)

MAIN_SOURCE = $(SRC)/controller/cyboi/cyboi.c
#ROOT_SOURCES = $(wildcard $(SRC)/*.c)
#ROOT_OBJECTS = $(patsubst $(SRC)/%.c,$(OBJ)/%.o,$(ROOT_SOURCES))

# Computer.
COMPUTER_SOURCES = $(wildcard $(SRC)/computer/*.c)
COMPUTER_OBJECTS = $(patsubst $(SRC)/computer/%.c,$(OBJ)/computer/%.o,$(COMPUTER_SOURCES))
COMPUTER_INTERRUPT_SOURCES = $(wildcard $(SRC)/computer/interrupt/*.c)
COMPUTER_INTERRUPT_OBJECTS = $(patsubst $(SRC)/computer/interrupt/%.c,$(OBJ)/computer/interrupt/%.o,$(COMPUTER_INTERRUPT_SOURCES))
COMPUTER_RECEIVE_SOURCES = $(wildcard $(SRC)/computer/receive/*.c)
COMPUTER_RECEIVE_OBJECTS = $(patsubst $(SRC)/computer/receive/%.c,$(OBJ)/computer/receive/%.o,$(COMPUTER_RECEIVE_SOURCES))
COMPUTER_SEND_SOURCES = $(wildcard $(SRC)/computer/send/*.c)
COMPUTER_SEND_OBJECTS = $(patsubst $(SRC)/computer/send/%.c,$(OBJ)/computer/send/%.o,$(COMPUTER_SEND_SOURCES))
COMPUTER_SHUTDOWN_SOURCES = $(wildcard $(SRC)/computer/shutdown/*.c)
COMPUTER_SHUTDOWN_OBJECTS = $(patsubst $(SRC)/computer/shutdown/%.c,$(OBJ)/computer/shutdown/%.o,$(COMPUTER_SHUTDOWN_SOURCES))
COMPUTER_STARTUP_SOURCES = $(wildcard $(SRC)/computer/startup/*.c)
COMPUTER_STARTUP_OBJECTS = $(patsubst $(SRC)/computer/startup/%.c,$(OBJ)/computer/startup/%.o,$(COMPUTER_STARTUP_SOURCES))
COMPUTER_SUSPEND_SOURCES = $(wildcard $(SRC)/computer/suspend/*.c)
COMPUTER_SUSPEND_OBJECTS = $(patsubst $(SRC)/computer/suspend/%.c,$(OBJ)/computer/suspend/%.o,$(COMPUTER_SUSPEND_SOURCES))

# Controller.
CONTROLLER_COMMUNICATOR_SOURCES = $(wildcard $(SRC)/controller/communicator/*.c)
CONTROLLER_COMMUNICATOR_OBJECTS = $(patsubst $(SRC)/controller/communicator/%.c,$(OBJ)/controller/communicator/%.o,$(CONTROLLER_COMMUNICATOR_SOURCES))
CONTROLLER_CONVERTER_SOURCES = $(wildcard $(SRC)/controller/converter/*.c)
CONTROLLER_CONVERTER_OBJECTS = $(patsubst $(SRC)/controller/converter/%.c,$(OBJ)/controller/converter/%.o,$(CONTROLLER_CONVERTER_SOURCES))
CONTROLLER_CYBOI_SOURCES = $(wildcard $(SRC)/controller/cyboi/*.c)
CONTROLLER_CYBOI_OBJECTS = $(patsubst $(SRC)/controller/cyboi/%.c,$(OBJ)/controller/cyboi/%.o,$(CONTROLLER_CYBOI_SOURCES))
CONTROLLER_TRANSLATOR_SOURCES = $(wildcard $(SRC)/controller/translator/*.c)
CONTROLLER_TRANSLATOR_OBJECTS = $(patsubst $(SRC)/controller/translator/%.c,$(OBJ)/controller/translator/%.o,$(CONTROLLER_TRANSLATOR_SOURCES))

# Globals.
GLOBALS_CONSTANTS_SOURCES = $(wildcard $(SRC)/globals/constants/*.c)
GLOBALS_CONSTANTS_OBJECTS = $(patsubst $(SRC)/globals/constants/%.c,$(OBJ)/globals/constants/%.o,$(GLOBALS_CONSTANTS_SOURCES))
GLOBALS_LOGGER_SOURCES = $(wildcard $(SRC)/globals/logger/*.c)
GLOBALS_LOGGER_OBJECTS = $(patsubst $(SRC)/globals/logger/%.c,$(OBJ)/globals/logger/%.o,$(GLOBALS_LOGGER_SOURCES))
GLOBALS_VARIABLES_SOURCES = $(wildcard $(SRC)/globals/variables/*.c)
GLOBALS_VARIABLES_OBJECTS = $(patsubst $(SRC)/globals/variables/%.c,$(OBJ)/globals/variables/%.o,$(GLOBALS_VARIABLES_SOURCES))

# Memory.
MEMORY_ACCESSOR_SOURCES = $(wildcard $(SRC)/memory/accessor/*.c)
MEMORY_ACCESSOR_OBJECTS = $(patsubst $(SRC)/memory/accessor/%.c,$(OBJ)/memory/accessor/%.o,$(MEMORY_ACCESSOR_SOURCES))
MEMORY_ARRAY_SOURCES = $(wildcard $(SRC)/memory/array/*.c)
MEMORY_ARRAY_OBJECTS = $(patsubst $(SRC)/memory/array/%.c,$(OBJ)/memory/array/%.o,$(MEMORY_ARRAY_SOURCES))
MEMORY_CREATOR_SOURCES = $(wildcard $(SRC)/memory/creator/*.c)
MEMORY_CREATOR_OBJECTS = $(patsubst $(SRC)/memory/creator/%.c,$(OBJ)/memory/creator/%.o,$(MEMORY_CREATOR_SOURCES))

# Tester.
TESTER_SOURCES = $(wildcard $(SRC)/tester/*.c)
TESTER_OBJECTS = $(patsubst $(SRC)/tester/%.c,$(OBJ)/tester/%.o,$(TESTER_SOURCES))

# OLD stuff to be deleted!
SOCKET_SOURCES = $(wildcard $(SRC)/socket/*.c)
SOCKET_OBJECTS = $(patsubst $(SRC)/socket/%.c,$(OBJ)/socket/%.o,$(SOCKET_SOURCES))
WEB_SOURCES = $(wildcard $(SRC)/web/*.c)
WEB_OBJECTS = $(patsubst $(SRC)/web/%.c,$(OBJ)/web/%.o,$(WEB_SOURCES))

#
# Compiles all cyboi source files.
#
# - compiles sources
# - creates objects
# - creates binary
#
# Do NOT add a "$@" at the end!
# Otherwise, a compiler error will occur, because "make $@" is already used internally.
#
#	$(COMPILER) -I /usr/X11R6/include -L /usr/X11R6/lib $(OBJ)/cyboi.o -o $(BIN)/$(BINARY)
#
#all: create $(ACCESSOR_OBJECTS) $(ARRAY_OBJECTS) $(COMMUNICATOR_OBJECTS) $(CREATOR_OBJECTS) $(CYBOI_OBJECTS) $(CONSTANTS_OBJECTS) $(LOGGER_OBJECTS) $(COMPUTER_OBJECTS) $(CONVERTER_OBJECTS) $(SIGNAL_OBJECTS) $(SOCKET_OBJECTS) $(STATE_OBJECTS) $(TESTER_OBJECTS) $(TRANSLATOR_OBJECTS) $(X_WINDOWS_OBJECTS)
#	$(COMPILER) -L/usr/X11R6/lib -L/usr/lib \
#		-o $(BIN)/$(BINARY) $(OBJ)/cyboi/cyboi.o -lX11 -lxml2
#
all: create \
	$(COMPUTER_OBJECTS) \
	$(COMPUTER_INTERRUPT_OBJECTS) \
	$(COMPUTER_RECEIVE_OBJECTS) \
	$(COMPUTER_SEND_OBJECTS) \
	$(COMPUTER_SHUTDOWN_OBJECTS) \
	$(COMPUTER_STARTUP_OBJECTS) \
	$(COMPUTER_SUSPEND_OBJECTS) \
	$(CONTROLLER_COMMUNICATOR_OBJECTS) \
	$(CONTROLLER_CONVERTER_OBJECTS) \
	$(CONTROLLER_CYBOI_OBJECTS) \
	$(CONTROLLER_TRANSLATOR_OBJECTS) \
	$(GLOBALS_CONSTANTS_OBJECTS) \
	$(GLOBALS_LOGGER_OBJECTS) \
	$(GLOBALS_VARIABLES_OBJECTS) \
	$(MEMORY_ACCESSOR_OBJECTS) \
	$(MEMORY_ARRAY_OBJECTS) \
	$(MEMORY_CREATOR_OBJECTS) \
	$(TESTER_OBJECTS) \
	$(SOCKET_OBJECTS) \
	$(WEB_OBJECTS) \
# Compile source files.
	$(COMPILER) -c $(COMPILER_FLAGS) $(SRC)/controller/cyboi/cyboi.c \
		-o $(OBJ)/controller/cyboi/cyboi.o
# Link object files.
	$(COMPILER) -L/usr/X11R6/lib -L/usr/lib \
		-o $(BIN)/$(BINARY) $(OBJ)/controller/cyboi/cyboi.o -lX11 -lxml2
# Print ready message.
	@echo Compiled cyboi files.

#
# Creates object directories and compiles cyboi source files into these.
#
# The commands have to stand in ONE line (or separated by "\"), because otherwise
# the "cd" command of the first line has no effect for the following lines.
#
create:
	-cd ..; mkdir obj; mkdir bin
	-cd $(OBJ); mkdir computer
	-cd $(OBJ); mkdir computer/interrupt
	-cd $(OBJ); mkdir computer/receive
	-cd $(OBJ); mkdir computer/send
	-cd $(OBJ); mkdir computer/shutdown
	-cd $(OBJ); mkdir computer/startup
	-cd $(OBJ); mkdir computer/suspend
	-cd $(OBJ); mkdir controller
	-cd $(OBJ); mkdir controller/communicator
	-cd $(OBJ); mkdir controller/converter
	-cd $(OBJ); mkdir controller/cyboi
	-cd $(OBJ); mkdir controller/translator
	-cd $(OBJ); mkdir globals
	-cd $(OBJ); mkdir globals/constants
	-cd $(OBJ); mkdir globals/logger
	-cd $(OBJ); mkdir globals/variables
	-cd $(OBJ); mkdir memory
	-cd $(OBJ); mkdir memory/accessor
	-cd $(OBJ); mkdir memory/array
	-cd $(OBJ); mkdir memory/creator
	-cd $(OBJ); mkdir tester
	-cd $(OBJ); mkdir socket
	-cd $(OBJ); mkdir web

#$(OBJ)/%.o: $(SRC)/%.c
#	$(COMPILER) -c $(COMPILER_FLAGS) $< -o $@

$(OBJ)/computer/%.o: $(SRC)/computer/%.c
	$(COMPILER) -c $(COMPILER_FLAGS) $< -o $@

$(OBJ)/computer/interrupt/%.o: $(SRC)/computer/interrupt/%.c
	$(COMPILER) -c $(COMPILER_FLAGS) $< -o $@

$(OBJ)/computer/receive/%.o: $(SRC)/computer/receive/%.c
	$(COMPILER) -c $(COMPILER_FLAGS) $< -o $@

$(OBJ)/computer/send/%.o: $(SRC)/computer/send/%.c
	$(COMPILER) -c $(COMPILER_FLAGS) $< -o $@

$(OBJ)/computer/shutdown/%.o: $(SRC)/computer/shutdown/%.c
	$(COMPILER) -c $(COMPILER_FLAGS) $< -o $@

$(OBJ)/computer/startup/%.o: $(SRC)/computer/startup/%.c
	$(COMPILER) -c $(COMPILER_FLAGS) $< -o $@

$(OBJ)/computer/suspend/%.o: $(SRC)/computer/suspend/%.c
	$(COMPILER) -c $(COMPILER_FLAGS) $< -o $@

$(OBJ)/controller/communicator/%.o: $(SRC)/controller/communicator/%.c
	$(COMPILER) -c $(COMPILER_FLAGS) $< -o $@

$(OBJ)/controller/converter/%.o: $(SRC)/controller/converter/%.c
	$(COMPILER) -c $(COMPILER_FLAGS) $< -o $@

$(OBJ)/controller/cyboi/%.o: $(SRC)/controller/cyboi/%.c
	$(COMPILER) -c $(COMPILER_FLAGS) $< -o $@

$(OBJ)/controller/translator/%.o: $(SRC)/controller/translator/%.c
	$(COMPILER) -c $(COMPILER_FLAGS) $< -o $@

$(OBJ)/globals/constants/%.o: $(SRC)/globals/constants/%.c
	$(COMPILER) -c $(COMPILER_FLAGS) $< -o $@

$(OBJ)/globals/logger/%.o: $(SRC)/globals/logger/%.c
	$(COMPILER) -c $(COMPILER_FLAGS) $< -o $@

$(OBJ)/globals/variables/%.o: $(SRC)/globals/variables/%.c
	$(COMPILER) -c $(COMPILER_FLAGS) $< -o $@

$(OBJ)/memory/accessor/%.o: $(SRC)/memory/accessor/%.c
	$(COMPILER) -c $(COMPILER_FLAGS) $< -o $@

$(OBJ)/memory/array/%.o: $(SRC)/memory/array/%.c
	$(COMPILER) -c $(COMPILER_FLAGS) $< -o $@

$(OBJ)/memory/creator/%.o: $(SRC)/memory/creator/%.c
	$(COMPILER) -c $(COMPILER_FLAGS) $< -o $@

$(OBJ)/tester/%.o: $(SRC)/tester/%.c
	$(COMPILER) -c $(COMPILER_FLAGS) $< -o $@

$(OBJ)/socket/%.o: $(SRC)/socket/%.c
	$(COMPILER) -c $(COMPILER_FLAGS) $< -o $@

$(OBJ)/web/%.o: $(SRC)/web/%.c
	$(COMPILER) -c $(COMPILER_FLAGS) $< -o $@

#
# Creates distribution file.
#
# - packs objects
# - packs binaries
# - packs cybol libraries
# - packs documentation
# - writes distribution file cyboi.tar.gz to directory /dist
#
dist:
	clean
	-cd ..; mkdir dist
	tar -cvzf dist/cyboi.tar.gz * -X admin/exclude
	@echo Created distribution file.

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
	-rm -f $(DIST)/cybol.tar.gz
	-rm -r $(OBJ)
	@echo Cleaned cyboi files.

