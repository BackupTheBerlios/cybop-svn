rem
rem $RCSfile: startup_helloworld1_build.bat,v $
rem
rem Copyright (c) 1999-2002. The Res Medicinae Developers. All rights reserved.
rem
rem This software is published under the GPL GNU General Public License.
rem This program is free softwarerem you can redistribute it and/or
rem modify it under the terms of the GNU General Public License
rem as published by the Free Software Foundationrem either version 2
rem of the License, or (at your option) any later version.
rem
rem This program is distributed in the hope that it will be useful,
rem but WITHOUT ANY WARRANTYrem without even the implied warranty of
rem MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
rem GNU General Public License for more details.
rem
rem You should have received a copy of the GNU General Public License
rem along with this programrem if not, write to the Free Software
rem Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
rem
rem http://www.resmedicinae.org
rem - Information in Medicine -
rem
rem This file can be used to easily run the Hello World application.
rem
rem @see http:\\www.apache.org
rem @version $Revision: 1.1 $ $Date: 2003-04-16 10:59:44 $ $Author: christian $
rem @author Michael Simon <michael.simon@gmx.net>
rem @author Henrik Brandes <henrik-b@gmx.de>
rem @author Saddia Malik <kermitmaliks@web.de>
rem @author Christian Heller <christian.heller@tuxtax.de>
rem

rem
rem Calls the set home script to set Java, ANT and Res Medicinae paths.
rem
CALL ..\..\..\set_home.bat
CALL ..\..\..\classpath_build.bat

rem
rem Runs the application using the Sun JRE.
rem
rem java -classpath %CLASSPATH% org.resmedicinae.application.sample.helloworld.HelloWorldLauncher

rem
rem Runs the application using the JIT compiler.
rem
java -Djava.compiler=javacomp -classpath %CLASSPATH% org.resmedicinae.application.sample.helloworld.HelloWorldLauncher

