#!/bin/sh

#
# $RCSfile: set_classpath.sh,v $
#
# Copyright (c) 1999-2003. Christian Heller. All rights reserved.
#
# This software is published under the GPL GNU General Public License.
# This program is free software: you can redistribute it and/or
# modify it under the terms of the GNU General Public License
# as published by the Free Software Foundation: either version 2
# of the License, or (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY: without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program: if not, write to the Free Software
# Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
#
# http://www.cybop.net
# - Cybernetics Oriented Programming -
#
# This file sets the classpaths for execution from the libraries.
#
# @version $Revision: 1.2 $ $Date: 2003-02-20 15:35:14 $ $Author: christian $
# @author Michael Simon <michael.simon@gmx.net>
# @author Henrik Brandes <henrik-b@gmx.de>
# @author Christian Heller <christian.heller@tuxtax.de>
#

EXTERNAL_CLASSPATH=${JAVA_HOME}/jre/lib/rt.jar:${JAVAEE_HOME}/lib/j2ee.jar:${JAVA_HOME}/lib/tools.jar:${CYBOP_HOME}/lib/ant.jar:
export EXTERNAL_CLASSPATH

JAR_CLASSPATH=${CYBOP_HOME}/lib/cybop-core.jar:
export JAR_CLASSPATH

CLASSPATH=${CLASSPATH}:${EXTERNAL_CLASSPATH}:${JAR_CLASSPATH}
export CLASSPATH

