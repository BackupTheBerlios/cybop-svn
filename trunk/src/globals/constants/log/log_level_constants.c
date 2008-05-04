/*
 * $RCSfile: log_level_constants.c,v $
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
 * @version $Revision: 1.3 $ $Date: 2008-05-04 00:18:12 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef LOG_LEVEL_CONSTANTS_SOURCE
#define LOG_LEVEL_CONSTANTS_SOURCE

#include "../../../globals/constants/integer/integer_constants.c"

//
// Log levels.
//

/** The off log level. */
static int* OFF_LOG_LEVEL = NUMBER_0_INTEGER_ARRAY;

/** The error log level. */
static int* ERROR_LOG_LEVEL = NUMBER_1_INTEGER_ARRAY;

/** The warning log level. */
static int* WARNING_LOG_LEVEL = NUMBER_2_INTEGER_ARRAY;

/** The info log level. */
static int* INFORMATION_LOG_LEVEL = NUMBER_3_INTEGER_ARRAY;

/** The debug log level. */
static int* DEBUG_LOG_LEVEL = NUMBER_4_INTEGER_ARRAY;

/* LOG_LEVEL_CONSTANTS_SOURCE */
#endif
