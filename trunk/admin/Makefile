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
# @version $Revision: 1.23 $ $Date: 2005-03-20 01:43:33 $ $Author: christian $
# @author Christian Heller <christian.heller@tuxtax.de>
# @author Michael Simon <michael.simon@gmx.net>
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

MAIN_SOURCE = $(SRC)/cyboi/cyboi.c
#ROOT_SOURCES = $(wildcard $(SRC)/*.c)
#ROOT_OBJECTS = $(patsubst $(SRC)/%.c,$(OBJ)/%.o,$(ROOT_SOURCES))
ACCESSOR_SOURCES = $(wildcard $(SRC)/accessor/*.c)
ACCESSOR_OBJECTS = $(patsubst $(SRC)/accessor/%.c,$(OBJ)/accessor/%.o,$(ACCESSOR_SOURCES))
ARRAY_SOURCES = $(wildcard $(SRC)/array/*.c)
ARRAY_OBJECTS = $(patsubst $(SRC)/array/%.c,$(OBJ)/array/%.o,$(ARRAY_SOURCES))
COMMUNICATOR_SOURCES = $(wildcard $(SRC)/communicator/*.c)
COMMUNICATOR_OBJECTS = $(patsubst $(SRC)/communicator/%.c,$(OBJ)/communicator/%.o,$(COMMUNICATOR_SOURCES))
CREATOR_SOURCES = $(wildcard $(SRC)/creator/*.c)
CREATOR_OBJECTS = $(patsubst $(SRC)/creator/%.c,$(OBJ)/creator/%.o,$(CREATOR_SOURCES))
CYBOI_SOURCES = $(wildcard $(SRC)/cyboi/*.c)
CYBOI_OBJECTS = $(patsubst $(SRC)/cyboi/%.c,$(OBJ)/cyboi/%.o,$(CYBOI_SOURCES))
GLOBAL_SOURCES = $(wildcard $(SRC)/global/*.c)
GLOBAL_OBJECTS = $(patsubst $(SRC)/global/%.c,$(OBJ)/global/%.o,$(GLOBAL_SOURCES))
LOGGER_SOURCES = $(wildcard $(SRC)/logger/*.c)
LOGGER_OBJECTS = $(patsubst $(SRC)/logger/%.c,$(OBJ)/logger/%.o,$(LOGGER_SOURCES))
LOGIC_SOURCES = $(wildcard $(SRC)/logic/*.c)
LOGIC_OBJECTS = $(patsubst $(SRC)/logic/%.c,$(OBJ)/logic/%.o,$(LOGIC_SOURCES))
LOGIC_STARTUP_SOURCES = $(wildcard $(SRC)/logic/startup/*.c)
LOGIC_STARTUP_OBJECTS = $(patsubst $(SRC)/logic/startup/%.c,$(OBJ)/logic/startup/%.o,$(LOGIC_STARTUP_SOURCES))
PARSER_SOURCES = $(wildcard $(SRC)/parser/*.c)
PARSER_OBJECTS = $(patsubst $(SRC)/parser/%.c,$(OBJ)/parser/%.o,$(PARSER_SOURCES))
SIGNAL_SOURCES = $(wildcard $(SRC)/signal/*.c)
SIGNAL_OBJECTS = $(patsubst $(SRC)/signal/%.c,$(OBJ)/signal/%.o,$(SIGNAL_SOURCES))
SOCKET_SOURCES = $(wildcard $(SRC)/socket/*.c)
SOCKET_OBJECTS = $(patsubst $(SRC)/socket/%.c,$(OBJ)/socket/%.o,$(SOCKET_SOURCES))
STATE_SOURCES = $(wildcard $(SRC)/state/*.c)
STATE_OBJECTS = $(patsubst $(SRC)/state/%.c,$(OBJ)/state/%.o,$(STATE_SOURCES))
TEST_SOURCES = $(wildcard $(SRC)/test/*.c)
TEST_OBJECTS = $(patsubst $(SRC)/test/%.c,$(OBJ)/test/%.o,$(TEST_SOURCES))
TRANSLATOR_SOURCES = $(wildcard $(SRC)/translator/*.c)
TRANSLATOR_OBJECTS = $(patsubst $(SRC)/translator/%.c,$(OBJ)/translator/%.o,$(TRANSLATOR_SOURCES))
X_WINDOWS_SOURCES = $(wildcard $(SRC)/x_windows/*.c)
X_WINDOWS_OBJECTS = $(patsubst $(SRC)/x_windows/%.c,$(OBJ)/x_windows/%.o,$(X_WINDOWS_SOURCES))

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
#all: create $(ACCESSOR_OBJECTS) $(ARRAY_OBJECTS) $(COMMUNICATOR_OBJECTS) $(CREATOR_OBJECTS) $(CYBOI_OBJECTS) $(GLOBAL_OBJECTS) $(LOGGER_OBJECTS) $(LOGIC_OBJECTS) $(PARSER_OBJECTS) $(SIGNAL_OBJECTS) $(SOCKET_OBJECTS) $(STATE_OBJECTS) $(TEST_OBJECTS) $(TRANSLATOR_OBJECTS) $(X_WINDOWS_OBJECTS)
#	$(COMPILER) -L/usr/X11R6/lib -L/usr/lib \
#		-o $(BIN)/$(BINARY) $(OBJ)/cyboi/cyboi.o -lX11 -lxml2
#
all: create $(ACCESSOR_OBJECTS) $(ARRAY_OBJECTS) $(COMMUNICATOR_OBJECTS) $(CREATOR_OBJECTS) $(CYBOI_OBJECTS) $(GLOBAL_OBJECTS) $(LOGGER_OBJECTS) $(LOGIC_OBJECTS) $(LOGIC_STARTUP_OBJECTS) $(PARSER_OBJECTS) $(SIGNAL_OBJECTS) $(SOCKET_OBJECTS) $(STATE_OBJECTS) $(TEST_OBJECTS) $(TRANSLATOR_OBJECTS) $(X_WINDOWS_OBJECTS)
# Compile source files.
	$(COMPILER) -c $(COMPILER_FLAGS) $(SRC)/cyboi/cyboi.c \
		-o $(OBJ)/cyboi/cyboi.o
# Link object files.
	$(COMPILER) -L/usr/X11R6/lib -L/usr/lib \
		-o $(BIN)/$(BINARY) $(OBJ)/cyboi/cyboi.o -lX11 -lxml2
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
	-cd $(OBJ); mkdir accessor
	-cd $(OBJ); mkdir array
	-cd $(OBJ); mkdir communicator
	-cd $(OBJ); mkdir creator
	-cd $(OBJ); mkdir cyboi
	-cd $(OBJ); mkdir global
	-cd $(OBJ); mkdir logger
	-cd $(OBJ); mkdir logic
	-cd $(OBJ)/logic; mkdir startup
	-cd $(OBJ); mkdir parser
	-cd $(OBJ); mkdir signal
	-cd $(OBJ); mkdir socket
	-cd $(OBJ); mkdir state
	-cd $(OBJ); mkdir test
	-cd $(OBJ); mkdir translator
	-cd $(OBJ); mkdir x_windows

#$(OBJ)/%.o: $(SRC)/%.c
#	$(COMPILER) -c $(COMPILER_FLAGS) $< -o $@

$(OBJ)/accessor/%.o: $(SRC)/accessor/%.c
	$(COMPILER) -c $(COMPILER_FLAGS) $< -o $@

$(OBJ)/array/%.o: $(SRC)/array/%.c
	$(COMPILER) -c $(COMPILER_FLAGS) $< -o $@

$(OBJ)/creator/%.o: $(SRC)/creator/%.c
	$(COMPILER) -c $(COMPILER_FLAGS) $< -o $@

$(OBJ)/communicator/%.o: $(SRC)/communicator/%.c
	$(COMPILER) -c $(COMPILER_FLAGS) $< -o $@

$(OBJ)/cyboi/%.o: $(SRC)/cyboi/%.c
	$(COMPILER) -c $(COMPILER_FLAGS) $< -o $@

$(OBJ)/global/%.o: $(SRC)/global/%.c
	$(COMPILER) -c $(COMPILER_FLAGS) $< -o $@

$(OBJ)/logger/%.o: $(SRC)/logger/%.c
	$(COMPILER) -c $(COMPILER_FLAGS) $< -o $@

$(OBJ)/logic/%.o: $(SRC)/logic/%.c
	$(COMPILER) -c $(COMPILER_FLAGS) $< -o $@

$(OBJ)/logic/startup/%.o: $(SRC)/logic/startup/%.c
	$(COMPILER) -c $(COMPILER_FLAGS) $< -o $@

$(OBJ)/parser/%.o: $(SRC)/parser/%.c
	$(COMPILER) -c $(COMPILER_FLAGS) $< -o $@

$(OBJ)/signal/%.o: $(SRC)/signal/%.c
	$(COMPILER) -c $(COMPILER_FLAGS) $< -o $@

$(OBJ)/socket/%.o: $(SRC)/socket/%.c
	$(COMPILER) -c $(COMPILER_FLAGS) $< -o $@

$(OBJ)/state/%.o: $(SRC)/state/%.c
	$(COMPILER) -c $(COMPILER_FLAGS) $< -o $@

$(OBJ)/test/%.o: $(SRC)/test/%.c
	$(COMPILER) -c $(COMPILER_FLAGS) $< -o $@

$(OBJ)/translator/%.o: $(SRC)/translator/%.c
	$(COMPILER) -c $(COMPILER_FLAGS) $< -o $@

$(OBJ)/x_windows/%.o: $(SRC)/x_windows/%.c
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
#	-rm -r $(BIN)
	-rm -f $(BIN)/cyboi
	-rm -f $(DIST)/cybol.tar.gz
	-rm -r $(OBJ)
#	-rm -r $(OBJ)/logic
#	-rm -r $(OBJ)/logger
#	-rm -r $(OBJ)/model
#	-rm -r $(OBJ)/signal
#	-rm -r $(OBJ)/state
#	-rm -r $(OBJ)/test
#	-rm -r $(OBJ)/x_windows
#	-rm -f $(OBJ)/*.o
	@echo Cleaned cyboi files.

