#!/bin/sh

#
# $RCSfile: build_cybop.sh,v $
#
# Copyright (c) 1999-2003. Christian Heller. All rights reserved.
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
# http://www.resmedicinae.org
# - Information in Medicine -
#
# This file can be used to easily build the specified project.
# The project's source directory must contain a "build.xml" file.
# The building is done by the "Ant" tool of the "Jakarta" tool suite.
#
# @see http://www.apache.org
# @version $Revision: 1.2 $ $Date: 2003-02-19 17:15:17 $ $Author: christian $
# @author Christian Heller <christian.heller@tuxtax.de>
#

#
# Calls the set home script to set Java, ANT and CYBOP paths.
#
. ./bin/set_home.sh
. ./bin/set_build_classpath.sh

#
# Starts build process.
#
java -mx64m -classpath ${CLASSPATH} -Dant.home=${CYBOP_HOME}/lib org.apache.tools.ant.Main "${*}" -buildfile ${CYBOP_HOME}/src/build_cybop.xml

