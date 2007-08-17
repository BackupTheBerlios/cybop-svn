/*
 * $RCSfile: log_variables.c,v $
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
 * @version $Revision: 1.1 $ $Date: 2007-08-17 03:15:32 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef LOG_VARIABLES_SOURCE
#define LOG_VARIABLES_SOURCE

#include "../../globals/constants/integer/integer_constants.c"

// The log level.
//
// CAUTION! Do NOT try to use *OFF_LOG_LEVEL or *NUMBER_0_INTEGER here instead of the value 0!
// Otherwise, the system would show the following error, as it expects a constant value:
// "error: initializer element is not constant"
static int LOG_LEVEL = 0;

// The log output.
//
// CAUTION! Do NOT try to use *NUMBER_MINUS_1_INTEGER here instead of the value -1!
// Otherwise, the system would show the following error, as it expects a constant value:
// "error: initializer element is not constant"
static int LOG_OUTPUT = -1;

/* LOG_VARIABLES_SOURCE */
#endif
