/*
 * $RCSfile: system_executable_constants.c,v $
 *
 * Copyright (c) 1999-2008. Christian Heller and the CYBOP developers.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 *
 * http://www.cybop.net
 * - Cybernetics Oriented Programming -
 *
 * @version $Revision: 1.4 $ $Date: 2008-05-06 22:36:53 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef SYSTEM_EXECUTABLE_CONSTANTS_SOURCE
#define SYSTEM_EXECUTABLE_CONSTANTS_SOURCE

#include "../../../globals/constants/integer/integer_constants.c"

/** The shell system executable. */
static wchar_t SHELL_SYSTEM_EXECUTABLE_ARRAY[] = {L'/', L'b', L'i', L'n', L'/', L's', L'h'};
static wchar_t* SHELL_SYSTEM_EXECUTABLE = SHELL_SYSTEM_EXECUTABLE_ARRAY;
static int* SHELL_SYSTEM_EXECUTABLE_COUNT = NUMBER_7_INTEGER_ARRAY;

/** The shell system executable character argument. */
static wchar_t SHELL_SYSTEM_EXECUTABLE_CHARACTER_ARGUMENT_ARRAY[] = {L'-', L'c'};
static wchar_t* SHELL_SYSTEM_EXECUTABLE_CHARACTER_ARGUMENT = SHELL_SYSTEM_EXECUTABLE_CHARACTER_ARGUMENT_ARRAY;
static int* SHELL_SYSTEM_EXECUTABLE_CHARACTER_ARGUMENT_COUNT = NUMBER_2_INTEGER_ARRAY;

/* SYSTEM_EXECUTABLE_CONSTANTS_SOURCE */
#endif
