/*
 * $RCSfile: log_level_name_constants.c,v $
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
 * @version $Revision: 1.2 $ $Date: 2007-05-26 21:19:58 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef LOG_LEVEL_NAME_CONSTANTS_SOURCE
#define LOG_LEVEL_NAME_CONSTANTS_SOURCE

#include "../../../globals/constants/integer/integer_constants.c"

//
// Log level names.
//

/** The error log level name. */
static char ERROR_LOG_LEVEL_NAME_ARRAY[] = {'E', 'r', 'r', 'o', 'r'};
static char* ERROR_LOG_LEVEL_NAME = ERROR_LOG_LEVEL_NAME_ARRAY;
static int* ERROR_LOG_LEVEL_NAME_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The warning log level name. */
static char WARNING_LOG_LEVEL_NAME_ARRAY[] = {'W', 'a', 'r', 'n', 'i', 'n', 'g'};
static char* WARNING_LOG_LEVEL_NAME = WARNING_LOG_LEVEL_NAME_ARRAY;
static int* WARNING_LOG_LEVEL_NAME_COUNT = NUMBER_7_INTEGER_ARRAY;

/** The information log level name. */
static char INFORMATION_LOG_LEVEL_NAME_ARRAY[] = {'I', 'n', 'f', 'o', 'r', 'm', 'a', 't', 'i', 'o', 'n'};
static char* INFORMATION_LOG_LEVEL_NAME = INFORMATION_LOG_LEVEL_NAME_ARRAY;
static int* INFORMATION_LOG_LEVEL_NAME_COUNT = NUMBER_11_INTEGER_ARRAY;

/** The debug log level name. */
static char DEBUG_LOG_LEVEL_NAME_ARRAY[] = {'D', 'e', 'b', 'u', 'g'};
static char* DEBUG_LOG_LEVEL_NAME = DEBUG_LOG_LEVEL_NAME_ARRAY;
static int* DEBUG_LOG_LEVEL_NAME_COUNT = NUMBER_5_INTEGER_ARRAY;

/* LOG_LEVEL_NAME_CONSTANTS_SOURCE */
#endif
