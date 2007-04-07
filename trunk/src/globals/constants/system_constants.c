/*
 * $RCSfile: system_constants.c,v $
 *
 * Copyright (c) 1999-2007. Christian Heller and the CYBOP developers.
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
 * @version $Revision: 1.5 $ $Date: 2007-04-07 12:15:28 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef SYSTEM_CONSTANTS_SOURCE
#define SYSTEM_CONSTANTS_SOURCE

#include "../../globals/constants/integer_constants.c"

//
// Special values.
//

/** The invalid value. */
static int* INVALID_VALUE = NUMBER_MINUS_1_INTEGER_ARRAY;

//
// Standard input, output, error output.
//

/** The standard input. */
static char STANDARD_INPUT_FILE_NAME_ARRAY[] = {'s', 't', 'a', 'n', 'd', 'a', 'r', 'd', '_', 'i', 'n', 'p', 'u', 't'};
static char* STANDARD_INPUT_FILE_NAME = STANDARD_INPUT_FILE_NAME_ARRAY;
static int* STANDARD_INPUT_FILE_NAME_COUNT = NUMBER_14_INTEGER_ARRAY;

/** The standard output. */
static char STANDARD_OUTPUT_FILE_NAME_ARRAY[] = {'s', 't', 'a', 'n', 'd', 'a', 'r', 'd', '_', 'o', 'u', 't', 'p', 'u', 't'};
static char* STANDARD_OUTPUT_FILE_NAME = STANDARD_OUTPUT_FILE_NAME_ARRAY;
static int* STANDARD_OUTPUT_FILE_NAME_COUNT = NUMBER_15_INTEGER_ARRAY;

/** The standard error output. */
static char STANDARD_ERROR_OUTPUT_FILE_NAME_ARRAY[] = {'s', 't', 'a', 'n', 'd', 'a', 'r', 'd', '_', 'e', 'r', 'r', 'o', 'r', '_', 'o', 'u', 't', 'p', 'u', 't'};
static char* STANDARD_ERROR_OUTPUT_FILE_NAME = STANDARD_ERROR_OUTPUT_FILE_NAME_ARRAY;
static int* STANDARD_ERROR_OUTPUT_FILE_NAME_COUNT = NUMBER_21_INTEGER_ARRAY;

//
// Shell.
//

/** The system shell. */
static char SYSTEM_SHELL_ARRAY[] = {'/', 'b', 'i', 'n', '/', 's', 'h'};
static char* SYSTEM_SHELL = SYSTEM_SHELL_ARRAY;
static int* SYSTEM_SHELL_COUNT = NUMBER_7_INTEGER_ARRAY;

/** The system shell character argument. */
static char SYSTEM_SHELL_CHARACTER_ARGUMENT_ARRAY[] = {'-', 'c'};
static char* SYSTEM_SHELL_CHARACTER_ARGUMENT = SYSTEM_SHELL_CHARACTER_ARGUMENT_ARRAY;
static int* SYSTEM_SHELL_CHARACTER_ARGUMENT_COUNT = NUMBER_2_INTEGER_ARRAY;

/* SYSTEM_CONSTANTS_SOURCE */
#endif
