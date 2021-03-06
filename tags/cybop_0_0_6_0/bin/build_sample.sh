#!/bin/sh

#
# $RCSfile: build_sample.sh,v $
#
# Copyright (c) 1999-2002. The Res Medicinae Developers. All rights reserved.
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
# This file can be used to easily build the Hello World application.
# The project's directory must contain a "build.xml" file.
# The building is done by the "Ant" tool of the "Jakarta" tool suite.
#
# @see http://jakarta.apache.org/ant/index.html
# @version $Revision: 1.1 $ $Date: 2003-04-16 10:59:44 $ $Author: christian $
# @author Michael Simon <michael.simon@gmx.net>
# @author Henrik Brandes <henrik-b@gmx.de>
# @author Christian Heller <christian.heller@tuxtax.de>
#

#
# Calls the set home script to set Java, ANT and Res Medicinae paths.
#
. ./bin/set_home.sh

#
# Sets and exports the class path.
#
CLASSPATH=${CLASSPATH}
export CLASSPATH

#
# Starts build process.
#
java -mx64m -classpath ${CLASSPATH} -Dant.home=${RESMEDICINAE_HOME}/lib org.apache.tools.ant.Main "${*}" -buildfile ${RESMEDICINAE_HOME}/bin/application/sample/helloworld/build.xml

