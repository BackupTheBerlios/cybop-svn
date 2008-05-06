/*
 * $RCSfile: system_file_name_constants.c,v $
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

#ifndef SYSTEM_FILE_NAME_CONSTANTS_SOURCE
#define SYSTEM_FILE_NAME_CONSTANTS_SOURCE

#include "../../../globals/constants/integer/integer_constants.c"

/** The input system file name. */
static wchar_t INPUT_SYSTEM_FILE_NAME_ARRAY[] = {L's', L't', L'a', L'n', L'd', L'a', L'r', L'd', L'_', L'i', L'n', L'p', L'u', L't'};
static wchar_t* INPUT_SYSTEM_FILE_NAME = INPUT_SYSTEM_FILE_NAME_ARRAY;
static int* INPUT_SYSTEM_FILE_NAME_COUNT = NUMBER_14_INTEGER_ARRAY;

/** The output system file name. */
static wchar_t OUTPUT_SYSTEM_FILE_NAME_ARRAY[] = {L's', L't', L'a', L'n', L'd', L'a', L'r', L'd', L'_', L'o', L'u', L't', L'p', L'u', L't'};
static wchar_t* OUTPUT_SYSTEM_FILE_NAME = OUTPUT_SYSTEM_FILE_NAME_ARRAY;
static int* OUTPUT_SYSTEM_FILE_NAME_COUNT = NUMBER_15_INTEGER_ARRAY;

/** The error output system file name. */
static wchar_t ERROR_OUTPUT_SYSTEM_FILE_NAME_ARRAY[] = {L's', L't', L'a', L'n', L'd', L'a', L'r', L'd', L'_', L'e', L'r', L'r', L'o', L'r', L'_', L'o', L'u', L't', L'p', L'u', L't'};
static wchar_t* ERROR_OUTPUT_SYSTEM_FILE_NAME = ERROR_OUTPUT_SYSTEM_FILE_NAME_ARRAY;
static int* ERROR_OUTPUT_SYSTEM_FILE_NAME_COUNT = NUMBER_21_INTEGER_ARRAY;

/* SYSTEM_FILE_NAME_CONSTANTS_SOURCE */
#endif
