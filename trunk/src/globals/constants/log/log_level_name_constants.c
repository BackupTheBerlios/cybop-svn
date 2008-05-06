/*
 * $RCSfile: log_level_name_constants.c,v $
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

#ifndef LOG_LEVEL_NAME_CONSTANTS_SOURCE
#define LOG_LEVEL_NAME_CONSTANTS_SOURCE

#include "../../../globals/constants/integer/integer_constants.c"

//
// Log level names.
//

/** The error log level name. */
static wchar_t ERROR_LOG_LEVEL_NAME_ARRAY[] = {L'E', L'r', L'r', L'o', L'r'};
static wchar_t* ERROR_LOG_LEVEL_NAME = ERROR_LOG_LEVEL_NAME_ARRAY;
static int* ERROR_LOG_LEVEL_NAME_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The warning log level name. */
static wchar_t WARNING_LOG_LEVEL_NAME_ARRAY[] = {L'W', L'a', L'r', L'n', L'i', L'n', L'g'};
static wchar_t* WARNING_LOG_LEVEL_NAME = WARNING_LOG_LEVEL_NAME_ARRAY;
static int* WARNING_LOG_LEVEL_NAME_COUNT = NUMBER_7_INTEGER_ARRAY;

/** The information log level name. */
static wchar_t INFORMATION_LOG_LEVEL_NAME_ARRAY[] = {L'I', L'n', L'f', L'o', L'r', L'm', L'a', L't', L'i', L'o', L'n'};
static wchar_t* INFORMATION_LOG_LEVEL_NAME = INFORMATION_LOG_LEVEL_NAME_ARRAY;
static int* INFORMATION_LOG_LEVEL_NAME_COUNT = NUMBER_11_INTEGER_ARRAY;

/** The debug log level name. */
static wchar_t DEBUG_LOG_LEVEL_NAME_ARRAY[] = {L'D', L'e', L'b', L'u', L'g'};
static wchar_t* DEBUG_LOG_LEVEL_NAME = DEBUG_LOG_LEVEL_NAME_ARRAY;
static int* DEBUG_LOG_LEVEL_NAME_COUNT = NUMBER_5_INTEGER_ARRAY;

/* LOG_LEVEL_NAME_CONSTANTS_SOURCE */
#endif
