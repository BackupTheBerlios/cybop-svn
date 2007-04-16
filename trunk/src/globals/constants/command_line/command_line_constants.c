/*
 * $RCSfile: command_line_constants.c,v $
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
 * @version $Revision: 1.1 $ $Date: 2007-04-16 16:45:37 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef COMMAND_LINE_CONSTANTS_SOURCE
#define COMMAND_LINE_CONSTANTS_SOURCE

#include "../../../globals/constants/integer/integer_constants.c"

//
// Startup command line parameters/arguments.
//

/** The startup parameters count. */
static int* STARTUP_PARAMETERS_COUNT = NUMBER_2_INTEGER_ARRAY;

/** The command parameter index. */
static int* COMMAND_PARAMETER_INDEX = NUMBER_0_INTEGER_ARRAY;

/** The run file parameter index. */
static int* RUN_FILE_PARAMETER_INDEX = NUMBER_1_INTEGER_ARRAY;

/* COMMAND_LINE_CONSTANTS_SOURCE */
#endif
