@echo off

rem !\bin\sh

rem
rem $RCSfile: set_build_classpath.bat,v $
rem
rem Copyright (c) 1999-2002. The Res Medicinae Developers. All rights reserved.
rem
rem This software is published under the GPL GNU General Public License.
rem This program is free software; you can redistribute it and\or
rem modify it under the terms of the GNU General Public License
rem as published by the Free Software Foundation; either version 2
rem of the License, or (at your option) any later version.
rem
rem This program is distributed in the hope that it will be useful,
rem but WITHOUT ANY WARRANTY; without even the implied warranty of
rem MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
rem GNU General Public License for more details.
rem
rem You should have received a copy of the GNU General Public License
rem along with this program; if not, write to the Free Software
rem Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
rem
rem http:\\www.resmedicinae.org
rem - Information in Medicine -
rem
rem This file can be used to easily build the specified project.
rem The project's directory must contain a "build.xml" file.
rem The building is done by the "Ant" tool of the "Jakarta" tool suite.
rem
rem @see http:\\www.apache.org
rem @version $Revision: 1.1 $ $Date: 2003-04-16 08:00:38 $ $Author: christian $
rem @author Michael Simon <michael.simon@gmx.net>
rem @author Henrik Brandes <henrik-b@gmx.de>
rem

set CLASSPATH_BUILD=%RESMEDICINAE_HOME%\build\application\common\basic;%RESMEDICINAE_HOME%\build\application\common\main;%RESMEDICINAE_HOME%\build\application\controller\about;%RESMEDICINAE_HOME%\build\application\controller\basic;%RESMEDICINAE_HOME%\build\application\controller\login;%RESMEDICINAE_HOME%\build\application\controller\splash;%RESMEDICINAE_HOME%\build\application\healthcare\record;%RESMEDICINAE_HOME%\build\application\healthcare\reform;%RESMEDICINAE_HOME%\build\application\healthcare\restore;%RESMEDICINAE_HOME%\build\application\healthcare\resadmin;%RESMEDICINAE_HOME%\build\application\sample\helloworld;%RESMEDICINAE_HOME%\build\domain\healthcare;%RESMEDICINAE_HOME%\build\resmedlib;

set EXTERNAL_JAR=%JAVA_HOME%\jre\lib\rt.jar;%JAVAEE_HOME%\lib\j2ee.jar;%JAVA_HOME%\lib\tools.jar;%RESMEDICINAE_HOME%\lib\ant.jar;%RESMEDICINAE_HOME%\lib\compiler.jar;%RESMEDICINAE_HOME%\lib\xerces.jar;%RESMEDICINAE_HOME%\lib\jcommon-0.6.1.jar;%RESMEDICINAE_HOME%\lib\jfreechart-0.7.3.jar;%RESMEDICINAE_HOME%\lib\mm.mysql-2.0.14-bin.jar;%RESMEDICINAE_HOME%\lib\protomatter-1.1.7.jar;

set CLASSPATH=%CLASSPATH%;%CLASSPATH_BUILD%;%EXTERNAL_JAR%
