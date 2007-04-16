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
 * @version $Revision: 1.2 $ $Date: 2007-04-16 21:28:50 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef COMMAND_LINE_CONSTANTS_SOURCE
#define COMMAND_LINE_CONSTANTS_SOURCE

#include "../../../globals/constants/integer/integer_constants.c"

//
// Command line arguments.
//

/** The command line arguments count. */
static int* COMMAND_LINE_ARGUMENTS_COUNT = NUMBER_2_INTEGER_ARRAY;

/** The command command line argument index. */
static int* COMMAND_COMMAND_LINE_ARGUMENT_INDEX = NUMBER_0_INTEGER_ARRAY;

/** The option command line argument index. */
static int* OPTION_COMMAND_LINE_ARGUMENT_INDEX = NUMBER_1_INTEGER_ARRAY;

//
// Command line options.
//

/** The "--version" command line option. */
static char VERSION_COMMAND_LINE_OPTION_ARRAY[] = {'-', '-', 'v', 'e', 'r', 's', 'i', 'o', 'n'};
static char* VERSION_COMMAND_LINE_OPTION = VERSION_COMMAND_LINE_OPTION_ARRAY;
static int* VERSION_COMMAND_LINE_OPTION_COUNT = NUMBER_9_INTEGER_ARRAY;

/** The "--help" command line option. */
static char HELP_COMMAND_LINE_OPTION_ARRAY[] = {'-', '-', 'h', 'e', 'l', 'p'};
static char* HELP_COMMAND_LINE_OPTION = HELP_COMMAND_LINE_OPTION_ARRAY;
static int* HELP_COMMAND_LINE_OPTION_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The "--test" command line option. */
static char TEST_COMMAND_LINE_OPTION_ARRAY[] = {'-', '-', 't', 'e', 's', 't'};
static char* TEST_COMMAND_LINE_OPTION = TEST_COMMAND_LINE_OPTION_ARRAY;
static int* TEST_COMMAND_LINE_OPTION_COUNT = NUMBER_6_INTEGER_ARRAY;

/* COMMAND_LINE_CONSTANTS_SOURCE */
#endif
