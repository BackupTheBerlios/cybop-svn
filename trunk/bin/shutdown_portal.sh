#!/bin/bash

#
# $RCSfile: shutdown_portal.sh,v $
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
# This file can be used to easily run the specified project.
#
# @see http://www.apache.org
# @version $Revision: 1.2 $ $Date: 2003-02-19 17:15:17 $ $Author: christian $
# @author Michael Simon <michael.simon@gmx.net>
# @author Henrik Brandes <henrik-b@gmx.de>
# @author Christian Heller <christian.heller@tuxtax.de>
#

#
# Set paths.
#
. ./bin/set_home.sh
. ./bin/set_classpath.sh

#
# Shutdown resmedportal using the .jar files in the /lib directory.
#
java -Djava.compiler=javacomp -classpath $CLASSPATH cybop.core.system.family.Launcher -system cybop.core.system.family.Portal -action shutdown_system_action

