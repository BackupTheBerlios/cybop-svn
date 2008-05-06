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
 * @version $Revision: 1.5 $ $Date: 2008-05-06 22:36:52 $ $Author: christian $
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
static wchar_t VERSION_COMMAND_LINE_OPTION_ARRAY[] = {L'-', L'-', L'v', L'e', L'r', L's', L'i', L'o', L'n'};
static wchar_t* VERSION_COMMAND_LINE_OPTION = VERSION_COMMAND_LINE_OPTION_ARRAY;
static int* VERSION_COMMAND_LINE_OPTION_COUNT = NUMBER_9_INTEGER_ARRAY;

/** The "--help" command line option. */
static wchar_t HELP_COMMAND_LINE_OPTION_ARRAY[] = {L'-', L'-', L'h', L'e', L'l', L'p'};
static wchar_t* HELP_COMMAND_LINE_OPTION = HELP_COMMAND_LINE_OPTION_ARRAY;
static int* HELP_COMMAND_LINE_OPTION_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The "--test" command line option. */
static wchar_t TEST_COMMAND_LINE_OPTION_ARRAY[] = {L'-', L'-', L't', L'e', L's', L't'};
static wchar_t* TEST_COMMAND_LINE_OPTION = TEST_COMMAND_LINE_OPTION_ARRAY;
static int* TEST_COMMAND_LINE_OPTION_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The "--loglevel" command line option. */
static wchar_t LOG_LEVEL_COMMAND_LINE_OPTION_ARRAY[] = {L'-', L'-', L'l', L'o', L'g', L'l', L'e', L'v', L'e', L'l'};
static wchar_t* LOG_LEVEL_COMMAND_LINE_OPTION = LOG_LEVEL_COMMAND_LINE_OPTION_ARRAY;
static int* LOG_LEVEL_COMMAND_LINE_OPTION_COUNT = NUMBER_10_INTEGER_ARRAY;

/** The "--logfile" command line option. */
static wchar_t LOG_FILE_COMMAND_LINE_OPTION_ARRAY[] = {L'-', L'-', L'l', L'o', L'g', L'f', L'i', L'l', L'e'};
static wchar_t* LOG_FILE_COMMAND_LINE_OPTION = LOG_FILE_COMMAND_LINE_OPTION_ARRAY;
static int* LOG_FILE_COMMAND_LINE_OPTION_COUNT = NUMBER_9_INTEGER_ARRAY;

/** The "--knowledge" command line option. */
static wchar_t KNOWLEDGE_COMMAND_LINE_OPTION_ARRAY[] = {L'-', L'-', L'k', L'n', L'o', L'w', L'l', L'e', L'd', L'g', L'e'};
static wchar_t* KNOWLEDGE_COMMAND_LINE_OPTION = KNOWLEDGE_COMMAND_LINE_OPTION_ARRAY;
static int* KNOWLEDGE_COMMAND_LINE_OPTION_COUNT = NUMBER_11_INTEGER_ARRAY;

//
// Log level command line values.
//

/** The "off" log level command line value. */
static wchar_t OFF_LOG_LEVEL_COMMAND_LINE_VALUE_ARRAY[] = {L'o', L'f', L'f'};
static wchar_t* OFF_LOG_LEVEL_COMMAND_LINE_VALUE = OFF_LOG_LEVEL_COMMAND_LINE_VALUE_ARRAY;
static int* OFF_LOG_LEVEL_COMMAND_LINE_VALUE_COUNT = NUMBER_3_INTEGER_ARRAY;

/** The "error" log level command line value. */
static wchar_t ERROR_LOG_LEVEL_COMMAND_LINE_VALUE_ARRAY[] = {L'e', L'r', L'r', L'o', L'r'};
static wchar_t* ERROR_LOG_LEVEL_COMMAND_LINE_VALUE = ERROR_LOG_LEVEL_COMMAND_LINE_VALUE_ARRAY;
static int* ERROR_LOG_LEVEL_COMMAND_LINE_VALUE_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The "warning" log level command line value. */
static wchar_t WARNING_LOG_LEVEL_COMMAND_LINE_VALUE_ARRAY[] = {L'w', L'a', L'r', L'n', L'i', L'n', L'g'};
static wchar_t* WARNING_LOG_LEVEL_COMMAND_LINE_VALUE = WARNING_LOG_LEVEL_COMMAND_LINE_VALUE_ARRAY;
static int* WARNING_LOG_LEVEL_COMMAND_LINE_VALUE_COUNT = NUMBER_7_INTEGER_ARRAY;

/** The "information" log level command line value. */
static wchar_t INFORMATION_LOG_LEVEL_COMMAND_LINE_VALUE_ARRAY[] = {L'i', L'n', L'f', L'o', L'r', L'm', L'a', L't', L'i', L'o', L'n'};
static wchar_t* INFORMATION_LOG_LEVEL_COMMAND_LINE_VALUE = INFORMATION_LOG_LEVEL_COMMAND_LINE_VALUE_ARRAY;
static int* INFORMATION_LOG_LEVEL_COMMAND_LINE_VALUE_COUNT = NUMBER_11_INTEGER_ARRAY;

/** The "debug" log level command line value. */
static wchar_t DEBUG_LOG_LEVEL_COMMAND_LINE_VALUE_ARRAY[] = {L'd', L'e', L'b', L'u', L'g'};
static wchar_t* DEBUG_LOG_LEVEL_COMMAND_LINE_VALUE = DEBUG_LOG_LEVEL_COMMAND_LINE_VALUE_ARRAY;
static int* DEBUG_LOG_LEVEL_COMMAND_LINE_VALUE_COUNT = NUMBER_5_INTEGER_ARRAY;

/* COMMAND_LINE_CONSTANTS_SOURCE */
#endif
