#!/bin/sh

#
# $RCSfile: set_home.sh,v $
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
# http://www.cybop.net
# - Cybernetics Oriented Programming -
#
# This file sets the path and classpath.
#
# @version $Revision: 1.3 $ $Date: 2003-07-17 23:26:15 $ $Author: christian $
# @author Michael Simon <michael.simon@gmx.net>
# @author Henrik Brandes <henrik-b@gmx.de>
# @author Christian Heller <christian.heller@tuxtax.de>
#

#
# This script sets the home paths of Java, Java EE, ANT and Res Medicinae.
#
# 1 There are two possibilities to use this script:
#
# 1.1 Change the work directory to the location where you installed Res Medicinae in your system, e.g.:
#       cd /usr/local/resmedicinae
#   or:
#       cd /opt/resmedicinae
#   or:
#       cd /home/resmedicinae
#
# 1.2 Edit this script in the line where RESMEDICINAE_HOME is set, e.g.:
#       RESMEDICINAE_HOME=/usr/local/resmedicinae
#   or:
#       RESMEDICINAE_HOME=/opt/resmedicinae
#   or:
#       RESMEDICINAE_HOME=/home/resmedicinae
#
# 2 Now, build/start your system.
# The build/start scripts use this set_home script automatically.
#
# @version $Revision: 1.3 $ $Date: 2003-07-17 23:26:15 $ $Author: christian $
# @author Christian Heller <christian.heller@tuxtax.de>
#

#
# Sets and exports the CYBOP home path.
#
# Example for current work directory:
# CYBOP_HOME='pwd'
#
# Examples for absolute path:
# CYBOP_HOME="/usr/local/cybop"
# CYBOP_HOME="/opt/cybop"
# CYBOP_HOME="/home/cybop"
#
CYBOP_HOME=/home/cybop
export CYBOP_HOME

#
# Sets and exports the Java home path.
#
# Examples:
# JAVA_HOME=/usr/local/java
# JAVA_HOME=/usr/lib/java
# JAVA_HOME=/usr/java
#
JAVA_HOME=/usr/local/java
export JAVA_HOME

#
# Sets and exports the Java Enterprise home path.
#
# Examples:
# JAVA_HOME=/usr/local/javaee
# JAVA_HOME=/usr/lib/javaee
# JAVA_HOME=/usr/javaee
#
JAVAEE_HOME=/usr/local/javaee
export JAVAEE_HOME

#
# Sets and exports the MySQL home path.
#
# Examples:
# MYSQL_HOME=/usr/mysql
#
#MYSQL_HOME=/usr/mysql
#export MYSQL_HOME

#
# Sets and exports the path for executables.
#
# Some sub directories (e.g. /bin) are important and have to be added to the
# path variable!
#
# For Java, two paths are set. The standard JAVA_HOME is the location of the
# JDK and basically necessary for developers to build the system. The JRE path
# on the other hand points to the sub directory /jre of Res Medicinae and is
# necessary for normal users who don't have a JDK in their system.
#
PATH=${PATH}:${JAVA_HOME}/bin:${JAVAEE_HOME}/bin:${CYBOP_HOME}/bin
export PATH

#
# Sets and exports the class path.
#
CLASSPATH=${CLASSPATH}:${JAVA_HOME}/jre/lib/rt.jar:${JAVA_HOME}/lib/tools.jar:${JAVAEE_HOME}/lib/j2ee.jar:${CYBOP_HOME}/lib/ant.jar:${CYBOP_HOME}/lib/xerces.jar
export CLASSPATH

