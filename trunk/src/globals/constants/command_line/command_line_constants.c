/*
 * $RCSfile: command_line_constants.c,v $
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
 * @version $Revision: 1.6 $ $Date: 2008-05-12 10:58:58 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef COMMAND_LINE_CONSTANTS_SOURCE
#define COMMAND_LINE_CONSTANTS_SOURCE

#include "../../../globals/constants/integer/integer_constants.c"

//
// Command line arguments.
//

/** The command command line argument index. */
static int* COMMAND_COMMAND_LINE_ARGUMENT_INDEX = NUMBER_0_INTEGER_ARRAY;

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

/** The "--loglevel" command line option. */
static char LOG_LEVEL_COMMAND_LINE_OPTION_ARRAY[] = {'-', '-', 'l', 'o', 'g', 'l', 'e', 'v', 'e', 'l'};
static char* LOG_LEVEL_COMMAND_LINE_OPTION = LOG_LEVEL_COMMAND_LINE_OPTION_ARRAY;
static int* LOG_LEVEL_COMMAND_LINE_OPTION_COUNT = NUMBER_10_INTEGER_ARRAY;

/** The "--logfile" command line option. */
static char LOG_FILE_COMMAND_LINE_OPTION_ARRAY[] = {'-', '-', 'l', 'o', 'g', 'f', 'i', 'l', 'e'};
static char* LOG_FILE_COMMAND_LINE_OPTION = LOG_FILE_COMMAND_LINE_OPTION_ARRAY;
static int* LOG_FILE_COMMAND_LINE_OPTION_COUNT = NUMBER_9_INTEGER_ARRAY;

/** The "--knowledge" command line option. */
static char KNOWLEDGE_COMMAND_LINE_OPTION_ARRAY[] = {'-', '-', 'k', 'n', 'o', 'w', 'l', 'e', 'd', 'g', 'e'};
static char* KNOWLEDGE_COMMAND_LINE_OPTION = KNOWLEDGE_COMMAND_LINE_OPTION_ARRAY;
static int* KNOWLEDGE_COMMAND_LINE_OPTION_COUNT = NUMBER_11_INTEGER_ARRAY;

//
// Log level command line values.
//

/** The "off" log level command line value. */
static char OFF_LOG_LEVEL_COMMAND_LINE_VALUE_ARRAY[] = {'o', 'f', 'f'};
static char* OFF_LOG_LEVEL_COMMAND_LINE_VALUE = OFF_LOG_LEVEL_COMMAND_LINE_VALUE_ARRAY;
static int* OFF_LOG_LEVEL_COMMAND_LINE_VALUE_COUNT = NUMBER_3_INTEGER_ARRAY;

/** The "error" log level command line value. */
static char ERROR_LOG_LEVEL_COMMAND_LINE_VALUE_ARRAY[] = {'e', 'r', 'r', 'o', 'r'};
static char* ERROR_LOG_LEVEL_COMMAND_LINE_VALUE = ERROR_LOG_LEVEL_COMMAND_LINE_VALUE_ARRAY;
static int* ERROR_LOG_LEVEL_COMMAND_LINE_VALUE_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The "warning" log level command line value. */
static char WARNING_LOG_LEVEL_COMMAND_LINE_VALUE_ARRAY[] = {'w', 'a', 'r', 'n', 'i', 'n', 'g'};
static char* WARNING_LOG_LEVEL_COMMAND_LINE_VALUE = WARNING_LOG_LEVEL_COMMAND_LINE_VALUE_ARRAY;
static int* WARNING_LOG_LEVEL_COMMAND_LINE_VALUE_COUNT = NUMBER_7_INTEGER_ARRAY;

/** The "information" log level command line value. */
static char INFORMATION_LOG_LEVEL_COMMAND_LINE_VALUE_ARRAY[] = {'i', 'n', 'f', 'o', 'r', 'm', 'a', 't', 'i', 'o', 'n'};
static char* INFORMATION_LOG_LEVEL_COMMAND_LINE_VALUE = INFORMATION_LOG_LEVEL_COMMAND_LINE_VALUE_ARRAY;
static int* INFORMATION_LOG_LEVEL_COMMAND_LINE_VALUE_COUNT = NUMBER_11_INTEGER_ARRAY;

/** The "debug" log level command line value. */
static char DEBUG_LOG_LEVEL_COMMAND_LINE_VALUE_ARRAY[] = {'d', 'e', 'b', 'u', 'g'};
static char* DEBUG_LOG_LEVEL_COMMAND_LINE_VALUE = DEBUG_LOG_LEVEL_COMMAND_LINE_VALUE_ARRAY;
static int* DEBUG_LOG_LEVEL_COMMAND_LINE_VALUE_COUNT = NUMBER_5_INTEGER_ARRAY;

/* COMMAND_LINE_CONSTANTS_SOURCE */
#endif
