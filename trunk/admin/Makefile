#
# $RCSfile: Makefile,v $
#
# Copyright (c) 2003-2004. Michael Simon. All rights reserved.
# Copyright (c) 2004-2004. Christian Heller. All rights reserved.
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
# @version $Revision: 1.4 $ $Date: 2004-01-26 00:13:46 $ $Author: christian $
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
COMPILER_FLAGS = -g

#
# Wildcards.
#

#vpath %.c $(SRC)
#vpath %.o $(OBJ)

ROOT_SOURCES = $(wildcard $(SRC)/*.c)
ROOT_OBJECTS = $(patsubst $(SRC)/%.c,$(OBJ)/%.o,$(ROOT_SOURCES))
CYBOL_SOURCES = $(wildcard $(SRC)/cybol/*.c)
CYBOL_OBJECTS = $(patsubst $(SRC)/cybol/%.c,$(OBJ)/cybol/%.o,$(CYBOL_SOURCES))
DYNAMICS_SOURCES = $(wildcard $(SRC)/dynamics/*.c)
DYNAMICS_OBJECTS = $(patsubst $(SRC)/dynamics/%.c,$(OBJ)/dynamics/%.o,$(DYNAMICS_SOURCES))
LOGGER_SOURCES = $(wildcard $(SRC)/logger/*.c)
LOGGER_OBJECTS = $(patsubst $(SRC)/logger/%.c,$(OBJ)/logger/%.o,$(LOGGER_SOURCES))
MODEL_SOURCES = $(wildcard $(SRC)/model/*.c)
MODEL_OBJECTS = $(patsubst $(SRC)/model/%.c,$(OBJ)/model/%.o,$(MODEL_SOURCES))
SIGNAL_SOURCES = $(wildcard $(SRC)/signal/*.c)
SIGNAL_OBJECTS = $(patsubst $(SRC)/signal/%.c,$(OBJ)/signal/%.o,$(SIGNAL_SOURCES))
STATICS_SOURCES = $(wildcard $(SRC)/statics/*.c)
STATICS_OBJECTS = $(patsubst $(SRC)/statics/%.c,$(OBJ)/statics/%.o,$(STATICS_SOURCES))
X_WINDOWS_SOURCES = $(wildcard $(SRC)/x_windows/*.c)
X_WINDOWS_OBJECTS = $(patsubst $(SRC)/x_windows/%.c,$(OBJ)/x_windows/%.o,$(X_WINDOWS_SOURCES))

#
# Compiles all cyboi source files.
#
# - compiles sources
# - creates objects
# - creates binary
#
all: $(ROOT_OBJECTS) $(CYBOL_OBJECTS) $(DYNAMICS_OBJECTS) $(LOGGER_OBJECTS) $(MODEL_OBJECTS) $(SIGNAL_OBJECTS) $(STATICS_OBJECTS) $(X_WINDOWS_OBJECTS)
	$(COMPILER) -o $(BIN)/$(BINARY) $(ROOT_OBJECTS) $(CYBOL_OBJECTS) $(DYNAMICS_OBJECTS) $(LOGGER_OBJECTS) $(MODEL_OBJECTS) $(SIGNAL_OBJECTS) $(STATICS_OBJECTS) $(X_WINDOWS_OBJECTS) $@
	@echo Compiled cyboi files.

$(OBJ)/%.o : $(SRC)/%.c
	$(COMPILER) -c $(COMPILER_FLAGS) $< -o $@

$(OBJ)/cybol/%.o : $(SRC)/cybol/%.c
#	-cd $(OBJ);
#	mkdir cybol
	$(COMPILER) -c $(COMPILER_FLAGS) $< -o $@

$(OBJ)/dynamics/%.o : $(SRC)/dynamics/%.c
	-cd ..;
	mkdir dynamics
	$(COMPILER) -c $(COMPILER_FLAGS) $< -o $@

$(OBJ)/logger/%.o : $(SRC)/logger/%.c
	-cd ..;
	mkdir logger
	$(COMPILER) -c $(COMPILER_FLAGS) $< -o $@

$(OBJ)/model/%.o : $(SRC)/model/%.c
	-cd ..;
	mkdir model
	$(COMPILER) -c $(COMPILER_FLAGS) $< -o $@

$(OBJ)/signals/%.o : $(SRC)/signals/%.c
	-cd ..;
	mkdir signals
	$(COMPILER) -c $(COMPILER_FLAGS) $< -o $@

$(OBJ)/statics/%.o : $(SRC)/statics/%.c
	-cd ..;
	mkdir statics
	$(COMPILER) -c $(COMPILER_FLAGS) $< -o $@

$(OBJ)/x_windows/%.o : $(SRC)/x_windows/%.c
	-cd ..;
	mkdir x_windows
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
	-cd ..;
	mkdir dist
	cd ..;
	tar -cvzf dist/cybol.tar.gz * -X admin/exclude
	@echo Created distribution file.

#
# Cleans cyboi files.
#
# - objects
# - binaries
# - distribution
#
#.PHONY: clean
clean:
	-rm -r $(OBJ)/cybol
	-rm -r $(OBJ)/dynamics
	-rm -r $(OBJ)/logger
	-rm -r $(OBJ)/model
	-rm -r $(OBJ)/signal
	-rm -r $(OBJ)/statics
	-rm -r $(OBJ)/x_windows
	-rm -f $(OBJ)/*.o
	-rm -f $(BINARY)
	-rm -f $(DIST)/cybol.tar.gz
	@echo Cleaned cyboi files.

