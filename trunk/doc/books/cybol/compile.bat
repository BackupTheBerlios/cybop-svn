::
:: $RCSfile: compile.bat,v $
::
:: Copyright (c) 2002-2007. Christian Heller. All rights reserved.
::
:: Permission is granted to copy, distribute and/or modify this document
:: under the terms of the GNU Free Documentation License, Version 1.1 or
:: any later version published by the Free Software Foundation:: with no
:: Invariant Sections, with no Front-Cover Texts and with no Back-Cover
:: Texts. A copy of the license is included in the section entitled
:: "GNU Free Documentation License".
::
:: http://www.cybop.net
:: - Cybernetics Oriented Programming -
::
:: Version: $Revision: 1.1 $ $Date: 2007-07-17 20:02:36 $ $Author: christian $
:: Authors: Christian Heller <christian.heller@tuxtax.de>
::

:: Change drive.
d:

:: Change directory.
cd \tmp\c\latex

:: Compile latex files into dvi format.
:: latex cybol

:: Compile latex files into pdf format.
pdflatex cybol

:: Change back to root directory.
cd \