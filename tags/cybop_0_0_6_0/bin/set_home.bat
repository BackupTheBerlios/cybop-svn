@echo on

REM !/bin/sh

REM
REM $RCSfile: set_home.bat,v $
REM
REM Copyright (c) 1999-2002. The Res Medicinae Developers. All rights reserved.
REM
REM This software is published under the GPL GNU General Public License.
REM This program is free software; you can redistribute it and/or
REM modify it under the terms of the GNU General Public License
REM as published by the Free Software Foundation; either version 2
REM of the License, or (at your option) any later version.
REM
REM This program is distributed in the hope that it will be useful,
REM but WITHOUT ANY WARRANTY; without even the implied warranty of
REM MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
REM GNU General Public License for more details.
REM
REM You should have received a copy of the GNU General Public License
REM along with this program; if not, write to the Free Software
REM Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
REM
REM http://www.resmedicinae.org
REM - Information in Medicine -
REM

REM
REM This script sets the home paths of Java, Java EE, ANT and Res Medicinae.
REM
REM 1 There are two possibilities to use this script:
REM
REM 1.1 If you have installed Resmedicinae with the IzPack-installer, everything should be set correctly and you don't have to edit this file.
REM
REM     or
REM
REM 1.2  Edit this script in the line where RESMEDICINAE_HOME and JAVA_HOME are set, e.g.:
REM       RESMEDICINAE_HOME=c:\Program Files\resmedicinae
REM       JAVA_HOME=c:\Program Files\J2SDK_1.4.0
REM
REM
REM 2 Now, build/start your system.
REM The build/start scripts use this set_home script automatically.
REM
REM @version $Revision: 1.1 $ $Date: 2003-04-16 08:00:38 $ $Author: christian $
REM @author Christian Heller <christian.heller@tuxtax.de>
REM @author Henrik Brandes <henrik-b@gmx.de>
REM @author Michael Simon <michael.simon@gmx.net>
REM

REM
REM Sets and exports the Res Medicinae home path.
REM
REM Example for absolute path:
REM set RESMEDICINAE_HOME=c:\Program Files\resmedicinae
REM
set RESMEDICINAE_HOME=d:\resmedicinae

REM
REM Sets and exports the Java home path.
REM
REM Example:
REM set JAVA_HOME=c:\Program Files\J2SDK_1.4.0
REM
set JAVA_HOME=C:\java2


REM
REM Sets and exports the msql home path.
REM
REM Example:
REM set JAVA_HOME=c:\Program Files\J2SDK_1.4.0
REM
set MYSQL_HOME=c:\wampp2c\mysql


REM
REM Sets and exports the Java Enterprise home path.
REM
REM Example:
REM set JAVAEE_HOME=c:\Program Files\javaee
REM
set JAVAEE_HOME=c:\j2ee

REM
REM Sets and exports the path for executables.
REM
REM Some sub directories (e.g. \bin) are important and have to be added to the
REM path variable!
REM
REM For Java, two paths are set. The standard JAVA_HOME is the location of the
REM JDK and basically necessary for developers to build the system. The JRE path
REM on the other hand points to the sub directory \jre of Res Medicinae and is
REM necessary for normal users who don't have a JDK in their system.
REM
set PATH=%PATH%;%JAVA_HOME%\bin;%RESMEDICINAE_HOME%\bin;%JAVAEE_HOME%\bin;%MYSQL_HOME%\bin

REM
REM Sets and exports the class path.

set CLASSPATH=%RESMEDICINAE_HOME%\lib\ant.jar;%RESMEDICINAE_HOME%\lib\compiler.jar;%JAVA_HOME%\jre\lib\rt.jar;%JAVAEE_HOME%\lib\j2ee.jar;%JAVA_HOME%\lib\tools.jar;
