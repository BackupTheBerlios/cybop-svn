#
# $RCSfile: Makefile,v $
#
# Copyright (c) 2004-2004. Michael Simon. All rights reserved.
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
# @version $Revision: 1.3 $ $Date: 2004-01-07 11:12:18 $ $Author: christian $
# @author Michael Simon <michael.simon@gmx.net>
#

CC=cc
#-Wall -pedantic
CFLAGS=-g

vpath %.c ../src
vpath %.o ../src

ROOTSOURCES:=$(wildcard ../src/*.c)
ROOTOBJECTS:=$(patsubst ../src/%.c,../lib/%.o,$(ROOTSOURCES))
CYBOLSOURCES:=$(wildcard ../src/cybol/*.c)
CYBOLBJECTS:=$(patsubst ../src/cybol/%.c,../lib/cybol/%.o,$(CYBOLSOURCES))
DYNAMICSSOURCES:=$(wildcard ../src/dynamics/*.c)
DYNAMICSOBJECTS:=$(patsubst ../src/dynamics/%.c,../lib/dynamics/%.o,$(DYNAMICSSOURCES))
LOGGERSOURCES:=$(wildcard ../src/logger/*.c)
LOGGEROBJECTS:=$(patsubst ../src/logger/%.c,../lib/logger/%.o,$(LOGGERSOURCES))
MODELSOURCES:=$(wildcard ../src/model/*.c)
MODELOBJECTS:=$(patsubst ../src/model/%.c,../lib/model/%.o,$(MODELSOURCES))
SIGNALSOURCES:=$(wildcard ../src/signal/*.c)
SIGNALOBJECTS:=$(patsubst ../src/signal/%.c,../lib/signal/%.o,$(SIGNALSOURCES))
STATICSOURCES:=$(wildcard ../src/statics/*.c)
STATICSOBJECTS:=$(patsubst ../src/statics/%.c,../lib/statics/%.o,$(STATICSSOURCES))
X_WINDOWSSOURCES:=$(wildcard ../src/x_windows/*.c)
X_WINDOWSOBJECTS:=$(patsubst ../src/x_windows/%.c,../lib/x_windows/%.o,$(X_WINDOWSSOURCES))

all: $(ROOTOBJECTS) $(CYBOLOBJECTS) $(DYNAMICSOBJECTS) $(LOGGEROBJECTS) $(MODELOBJECTS) $(SIGNALOBJECTS) $(STATICSOBJECTS) $(X_WINDOWSOBJECTS)
    $(CC) -o ../bin/cyboi $(ROOTOBJECTS) $(CYBOLOBJECTS) $(DYNAMICSOBJECTS) $(LOGGEROBJECTS) $(MODELOBJECTS) $(SIGNALOBJECTS) $(STATICSOBJECTS) $(X_WINDOWSOBJECTS)
    @echo -----------------------
    @echo All Sources compiled...
    @echo -----------------------

dist: clean
    -cd ..; mkdir dist
    cd ..; tar -cvzf dist/cybol.tar.gz * -X admin/exclude
    @echo -----------------------------------------------------------------
    @echo All Object-files, Binaries and old Distribution-files deleted...
    @echo New distribution-file cybol.tar.gz generated in directory dist...
    @echo -----------------------------------------------------------------

../lib/%.o : ../src/%.c
    $(CC) -c $(CFLAGS) $< -o $@

../lib/cybol/%.o : ../src/cybol/%.c
    -cd ..; mkdir cybol
    $(CC) -c $(CFLAGS) $< -o $@

../lib/dynamics/%.o : ../src/dynamics/%.c
    -cd ..; mkdir dynamics
    $(CC) -c $(CFLAGS) $< -o $@

../lib/logger/%.o : ../src/logger/%.c
    -cd ..; mkdir logger
    $(CC) -c $(CFLAGS) $< -o $@

../lib/model/%.o : ../src/model/%.c
    -cd ..; mkdir model
    $(CC) -c $(CFLAGS) $< -o $@

../lib/signals/%.o : ../src/signals/%.c
    -cd ..; mkdir signals
    $(CC) -c $(CFLAGS) $< -o $@

../lib/statics/%.o : ../src/statics/%.c
    -cd ..; mkdir statics
    $(CC) -c $(CFLAGS) $< -o $@

../lib/x_windows/%.o : ../src/x_windows/%.c
    -cd ..; mkdir x_windows
    $(CC) -c $(CFLAGS) $< -o $@

test: all
    @echo -----------------
    @echo Starting Cyboi...
    @echo -----------------
    ./../bin/cyboi

.PHONY: clean
clean:
    -rm -r ../lib/cybol
    -rm -r ../lib/dynamics
    -rm -r ../lib/logger
    -rm -r ../lib/model
    -rm -r ../lib/signal
    -rm -r ../lib/statics
    -rm -r ../lib/x_windows
    -rm -f ../lib/*.o
    -rm -f ../bin/cyboi
    -rm -f ../dist/cybol.tar.gz
    @echo ----------------------------------------------------------------
    @echo All Object-files, Binaries and old Distribution-files deleted...
    @echo ----------------------------------------------------------------

