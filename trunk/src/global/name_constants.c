/*
 * $RCSfile: name_constants.c,v $
 *
 * Copyright (c) 1999-2005. Christian Heller. All rights reserved.
 *
 * This software is published under the GPL GNU General Public License.
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
 * @version $Revision: 1.9 $ $Date: 2005-03-02 07:17:27 $ $Author: rholzmueller $
 * @author Christian Heller <christian.heller@tuxtax.de>
 * @author Rolf Holzmueller <rolf.holzmueller@gmx.de>
 */

#ifndef NAME_CONSTANTS_SOURCE
#define NAME_CONSTANTS_SOURCE

//
// Configuration names.
//

/** The startup channel configuration name. */
static const char STARTUP_CHANNEL_CONFIGURATION_NAME_ARRAY[] = {'s', 't', 'a', 'r', 't', 'u', 'p', '_', 'c', 'h', 'a', 'n', 'n', 'e', 'l'};
static const char* STARTUP_CHANNEL_CONFIGURATION_NAME = STARTUP_CHANNEL_CONFIGURATION_NAME_ARRAY;
static const int STARTUP_CHANNEL_CONFIGURATION_NAME_COUNT_ARRAY[] = {15};
static const int* STARTUP_CHANNEL_CONFIGURATION_NAME_COUNT = STARTUP_CHANNEL_CONFIGURATION_NAME_COUNT_ARRAY;

/** The startup abstraction configuration name. */
static const char STARTUP_ABSTRACTION_CONFIGURATION_NAME_ARRAY[] = {'s', 't', 'a', 'r', 't', 'u', 'p', '_', 'a', 'b', 's', 't', 'r', 'a', 'c', 't', 'i', 'o', 'n'};
static const char* STARTUP_ABSTRACTION_CONFIGURATION_NAME = STARTUP_ABSTRACTION_CONFIGURATION_NAME_ARRAY;
static const int STARTUP_ABSTRACTION_CONFIGURATION_NAME_COUNT_ARRAY[] = {19};
static const int* STARTUP_ABSTRACTION_CONFIGURATION_NAME_COUNT = STARTUP_ABSTRACTION_CONFIGURATION_NAME_COUNT_ARRAY;

/** The startup model configuration name. */
static const char STARTUP_MODEL_CONFIGURATION_NAME_ARRAY[] = {'s', 't', 'a', 'r', 't', 'u', 'p', '_', 'm', 'o', 'd', 'e', 'l'};
static const char* STARTUP_MODEL_CONFIGURATION_NAME = STARTUP_MODEL_CONFIGURATION_NAME_ARRAY;
static const int STARTUP_MODEL_CONFIGURATION_NAME_COUNT_ARRAY[] = {13};
static const int* STARTUP_MODEL_CONFIGURATION_NAME_COUNT = STARTUP_MODEL_CONFIGURATION_NAME_COUNT_ARRAY;

/** The unix server socket active configuration name. */
static const char UNIX_SERVER_SOCKET_ACTIVE_CONFIGURATION_NAME_ARRAY[] = {'u', 'n', 'i', 'x', '_', 's', 'e', 'r', 'v', 'e', 'r', '_', 's', 'o', 'c', 'k', 'e', 't', '_', 'a', 'c', 't', 'i', 'v', 'e'};
static const char* UNIX_SERVER_SOCKET_ACTIVE_CONFIGURATION_NAME = UNIX_SERVER_SOCKET_ACTIVE_CONFIGURATION_NAME_ARRAY;
static const int UNIX_SERVER_SOCKET_ACTIVE_CONFIGURATION_NAME_COUNT_ARRAY[] = {25};
static const int* UNIX_SERVER_SOCKET_ACTIVE_CONFIGURATION_NAME_COUNT = UNIX_SERVER_SOCKET_ACTIVE_CONFIGURATION_NAME_COUNT_ARRAY;

/** The unix server socket filename configuration name. */
static const char UNIX_SERVER_SOCKET_FILENAME_CONFIGURATION_NAME_ARRAY[] = {'u', 'n', 'i', 'x', '_', 's', 'e', 'r', 'v', 'e', 'r', '_', 's', 'o', 'c', 'k', 'e', 't', '_', 'f', 'i', 'l', 'e', 'n', 'a', 'm', 'e'};
static const char* UNIX_SERVER_SOCKET_FILENAME_CONFIGURATION_NAME = UNIX_SERVER_SOCKET_FILENAME_CONFIGURATION_NAME_ARRAY;
static const int UNIX_SERVER_SOCKET_FILENAME_CONFIGURATION_NAME_COUNT_ARRAY[] = {27};
static const int* UNIX_SERVER_SOCKET_FILENAME_CONFIGURATION_NAME_COUNT = UNIX_SERVER_SOCKET_FILENAME_CONFIGURATION_NAME_COUNT_ARRAY;

/** The tcp server socket active configuration name. */
static const char TCP_SERVER_SOCKET_ACTIVE_CONFIGURATION_NAME_ARRAY[] = {'t', 'c', 'p', '_', 's', 'e', 'r', 'v', 'e', 'r', '_', 's', 'o', 'c', 'k', 'e', 't', '_', 'a', 'c', 't', 'i', 'v', 'e'};
static const char* TCP_SERVER_SOCKET_ACTIVE_CONFIGURATION_NAME = TCP_SERVER_SOCKET_ACTIVE_CONFIGURATION_NAME_ARRAY;
static const int TCP_SERVER_SOCKET_ACTIVE_CONFIGURATION_NAME_COUNT_ARRAY[] = {24};
static const int* TCP_SERVER_SOCKET_ACTIVE_CONFIGURATION_NAME_COUNT = TCP_SERVER_SOCKET_ACTIVE_CONFIGURATION_NAME_COUNT_ARRAY;

/** The tcp server socket port configuration name. */
static const char TCP_SERVER_SOCKET_PORT_CONFIGURATION_NAME_ARRAY[] = {'t', 'c', 'p', '_', 's', 'e', 'r', 'v', 'e', 'r', '_', 's', 'o', 'c', 'k', 'e', 't', '_', 'p', 'o', 'r', 't'};
static const char* TCP_SERVER_SOCKET_PORT_CONFIGURATION_NAME = TCP_SERVER_SOCKET_PORT_CONFIGURATION_NAME_ARRAY;
static const int TCP_SERVER_SOCKET_PORT_CONFIGURATION_NAME_COUNT_ARRAY[] = {22};
static const int* TCP_SERVER_SOCKET_PORT_CONFIGURATION_NAME_COUNT = TCP_SERVER_SOCKET_PORT_CONFIGURATION_NAME_COUNT_ARRAY;

/** The x windows server active configuration name. */
static const char X_WINDOWS_SERVER_ACTIVE_CONFIGURATION_NAME_ARRAY[] = {'x', '_', 'w', 'i', 'n', 'd', 'o', 'w', 's', '_', 's', 'e', 'r', 'v', 'e', 'r', '_', 'a', 'c', 't', 'i', 'v', 'e'};
static const char* X_WINDOWS_SERVER_ACTIVE_CONFIGURATION_NAME = X_WINDOWS_SERVER_ACTIVE_CONFIGURATION_NAME_ARRAY;
static const int X_WINDOWS_SERVER_ACTIVE_CONFIGURATION_NAME_COUNT_ARRAY[] = {23};
static const int* X_WINDOWS_SERVER_ACTIVE_CONFIGURATION_NAME_COUNT = X_WINDOWS_SERVER_ACTIVE_CONFIGURATION_NAME_COUNT_ARRAY;

//
// Creation names.
//

/** The name name abstraction. */
static const char NAME_NAME_ABSTRACTION_ARRAY[] = {'n', 'a', 'm', 'e'};
static const char* NAME_NAME_ABSTRACTION = NAME_NAME_ABSTRACTION_ARRAY;
static const int NAME_NAME_ABSTRACTION_COUNT_ARRAY[] = {4};
static const int* NAME_NAME_ABSTRACTION_COUNT = NAME_NAME_ABSTRACTION_COUNT_ARRAY;

/** The channel name abstraction. */
static const char CHANNEL_NAME_ABSTRACTION_ARRAY[] = {'c', 'h', 'a', 'n', 'n', 'e', 'l'};
static const char* CHANNEL_NAME_ABSTRACTION = CHANNEL_NAME_ABSTRACTION_ARRAY;
static const int CHANNEL_NAME_ABSTRACTION_COUNT_ARRAY[] = {7};
static const int* CHANNEL_NAME_ABSTRACTION_COUNT = CHANNEL_NAME_ABSTRACTION_COUNT_ARRAY;

/** The abstraction name abstraction. */
static const char ABSTRACTION_NAME_ABSTRACTION_ARRAY[] = {'a', 'b', 's', 't', 'r', 'a', 'c', 't', 'i', 'o', 'n'};
static const char* ABSTRACTION_NAME_ABSTRACTION = ABSTRACTION_NAME_ABSTRACTION_ARRAY;
static const int ABSTRACTION_NAME_ABSTRACTION_COUNT_ARRAY[] = {11};
static const int* ABSTRACTION_NAME_ABSTRACTION_COUNT = ABSTRACTION_NAME_ABSTRACTION_COUNT_ARRAY;

/** The model name abstraction. */
static const char MODEL_NAME_ABSTRACTION_ARRAY[] = {'m', 'o', 'd', 'e', 'l'};
static const char* MODEL_NAME_ABSTRACTION = MODEL_NAME_ABSTRACTION_ARRAY;
static const int MODEL_NAME_ABSTRACTION_COUNT_ARRAY[] = {5};
static const int* MODEL_NAME_ABSTRACTION_COUNT = MODEL_NAME_ABSTRACTION_COUNT_ARRAY;

/** The whole name abstraction. */
static const char WHOLE_NAME_ABSTRACTION_ARRAY[] = {'w', 'h', 'o', 'l', 'e'};
static const char* WHOLE_NAME_ABSTRACTION = WHOLE_NAME_ABSTRACTION_ARRAY;
static const int WHOLE_NAME_ABSTRACTION_COUNT_ARRAY[] = {5};
static const int* WHOLE_NAME_ABSTRACTION_COUNT = WHOLE_NAME_ABSTRACTION_COUNT_ARRAY;

//
// Communication names.
//

/** The language name array, pointer, count. */
static const char LANGUAGE_NAME_ABSTRACTION_ARRAY[] = {'l', 'a', 'n', 'g', 'u', 'a', 'g', 'e'};
static const char* LANGUAGE_NAME_ABSTRACTION = LANGUAGE_NAME_ABSTRACTION_ARRAY;
static const int LANGUAGE_NAME_ABSTRACTION_COUNT_ARRAY[] = {8};
static const int* LANGUAGE_NAME_ABSTRACTION_COUNT = LANGUAGE_NAME_ABSTRACTION_COUNT_ARRAY;

/** The sender name array, pointer, count. */
static const char SENDER_NAME_ABSTRACTION_ARRAY[] = {'s', 'e', 'n', 'd', 'e', 'r'};
static const char* SENDER_NAME_ABSTRACTION = SENDER_NAME_ABSTRACTION_ARRAY;
static const int SENDER_NAME_ABSTRACTION_COUNT_ARRAY[] = {6};
static const int* SENDER_NAME_ABSTRACTION_COUNT = SENDER_NAME_ABSTRACTION_COUNT_ARRAY;

/** The receiver name array, pointer, count. */
static const char RECEIVER_NAME_ABSTRACTION_ARRAY[] = {'r', 'e', 'c', 'e', 'i', 'v', 'e', 'r'};
static const char* RECEIVER_NAME_ABSTRACTION = RECEIVER_NAME_ABSTRACTION_ARRAY;
static const int RECEIVER_NAME_ABSTRACTION_COUNT_ARRAY[] = {8};
static const int* RECEIVER_NAME_ABSTRACTION_COUNT = RECEIVER_NAME_ABSTRACTION_COUNT_ARRAY;

/** The message name array, pointer, count. */
static const char MESSAGE_NAME_ABSTRACTION_ARRAY[] = {'m', 'e', 's', 's', 'a', 'g', 'e'};
static const char* MESSAGE_NAME_ABSTRACTION = MESSAGE_NAME_ABSTRACTION_ARRAY;
static const int MESSAGE_NAME_ABSTRACTION_COUNT_ARRAY[] = {7};
static const int* MESSAGE_NAME_ABSTRACTION_COUNT = MESSAGE_NAME_ABSTRACTION_COUNT_ARRAY;

//
// Property names names for html.
//
static const char HTML_TAG_NAME_ABSTRACTION_ARRAY[] = {'h', 't', 'm', 'l', '_', 't', 'a', 'g' };
static const char* HTML_TAG_NAME_ABSTRACTION = HTML_TAG_NAME_ABSTRACTION_ARRAY;
static const int HTML_TAG_NAME_ABSTRACTION_COUNT_ARRAY[] = {8};
static const int* HTML_TAG_NAME_ABSTRACTION_COUNT = HTML_TAG_NAME_ABSTRACTION_COUNT_ARRAY;


//
// Property names operation compare.
//
/** The operand_1 name array, pointer, count. */
static const char COMPARE_OPERAND_1_NAME_ABSTRACTION_ARRAY[] = {'o', 'p', 'e', 'r', 'a', 'n', 'd', '_', '1' };
static const char* COMPARE_OPERAND_1_NAME_ABSTRACTION = COMPARE_OPERAND_1_NAME_ABSTRACTION_ARRAY;
static const int COMPARE_OPERAND_1_NAME_ABSTRACTION_COUNT_ARRAY[] = {9};
static const int* COMPARE_OPERAND_1_NAME_ABSTRACTION_COUNT = COMPARE_OPERAND_1_NAME_ABSTRACTION_COUNT_ARRAY;


/** The operand_2 name array, pointer, count. */
static const char COMPARE_OPERAND_2_NAME_ABSTRACTION_ARRAY[] = {'o', 'p', 'e', 'r', 'a', 'n', 'd', '_', '2' };
static const char* COMPARE_OPERAND_2_NAME_ABSTRACTION = COMPARE_OPERAND_2_NAME_ABSTRACTION_ARRAY;
static const int COMPARE_OPERAND_2_NAME_ABSTRACTION_COUNT_ARRAY[] = {9};
static const int* COMPARE_OPERAND_2_NAME_ABSTRACTION_COUNT = COMPARE_OPERAND_2_NAME_ABSTRACTION_COUNT_ARRAY;

/** The operator name array, pointer, count. */
static const char COMPARE_OPERATOR_NAME_ABSTRACTION_ARRAY[] = {'o', 'p', 'e', 'r', 'a', 't', 'o', 'r' };
static const char* COMPARE_OPERATOR_NAME_ABSTRACTION = COMPARE_OPERATOR_NAME_ABSTRACTION_ARRAY;
static const int COMPARE_OPERATOR_NAME_ABSTRACTION_COUNT_ARRAY[] = {8};
static const int* COMPARE_OPERATOR_NAME_ABSTRACTION_COUNT = COMPARE_OPERATOR_NAME_ABSTRACTION_COUNT_ARRAY;


/** The operator name array, pointer, count. */
static const char COMPARE_RESULT_NAME_ABSTRACTION_ARRAY[] = {'r', 'e', 's', 'u', 'l', 't' };
static const char* COMPARE_RESULT_NAME_ABSTRACTION = COMPARE_RESULT_NAME_ABSTRACTION_ARRAY;
static const int COMPARE_RESULT_NAME_ABSTRACTION_COUNT_ARRAY[] = {6};
static const int* COMPARE_RESULT_NAME_ABSTRACTION_COUNT = COMPARE_RESULT_NAME_ABSTRACTION_COUNT_ARRAY;


//
// Property names operation set.
//

/** The source name array, pointer, count. */
static const char SET_SOURCE_NAME_ABSTRACTION_ARRAY[] = {'s', 'o', 'u', 'r', 'c', 'e' };
static const char* SET_SOURCE_NAME_ABSTRACTION = SET_SOURCE_NAME_ABSTRACTION_ARRAY;
static const int SET_SOURCE_NAME_ABSTRACTION_COUNT_ARRAY[] = {6};
static const int* SET_SOURCE_NAME_ABSTRACTION_COUNT = SET_SOURCE_NAME_ABSTRACTION_COUNT_ARRAY;

/** The destination name array, pointer, count. */
static const char SET_DESTINATION_NAME_ABSTRACTION_ARRAY[] = {'d', 'e', 's', 't', 'i', 'n', 'a', 't', 'i', 'o', 'n' };
static const char* SET_DESTINATION_NAME_ABSTRACTION = SET_DESTINATION_NAME_ABSTRACTION_ARRAY;
static const int SET_DESTINATION_NAME_ABSTRACTION_COUNT_ARRAY[] = {11};
static const int* SET_DESTINATION_NAME_ABSTRACTION_COUNT = SET_DESTINATION_NAME_ABSTRACTION_COUNT_ARRAY;

//
// Property names operation loop.
//

/** The breakflag name array, pointer, count. */
static const char LOOP_BREAKFLAG_NAME_ABSTRACTION_ARRAY[] = {'b', 'r', 'e', 'a', 'k' };
static const char* LOOP_BREAKFLAG_NAME_ABSTRACTION = LOOP_BREAKFLAG_NAME_ABSTRACTION_ARRAY;
static const int LOOP_BREAKFLAG_NAME_ABSTRACTION_COUNT_ARRAY[] = {5};
static const int* LOOP_BREAKFLAG_NAME_ABSTRACTION_COUNT = LOOP_BREAKFLAG_NAME_ABSTRACTION_COUNT_ARRAY;

/** The loop index name array, pointer, count. */
static const char LOOP_INDEX_NAME_ABSTRACTION_ARRAY[] = {'i', 'n', 'd', 'e', 'x'};
static const char* LOOP_INDEX_NAME_ABSTRACTION = LOOP_INDEX_NAME_ABSTRACTION_ARRAY;
static const int LOOP_INDEX_NAME_ABSTRACTION_COUNT_ARRAY[] = {5};
static const int* LOOP_INDEX_NAME_ABSTRACTION_COUNT = LOOP_INDEX_NAME_ABSTRACTION_COUNT_ARRAY;

/** The loop model name array, pointer, count. */
static const char LOOP_MODEL_NAME_ABSTRACTION_ARRAY[] = {'m', 'o', 'd', 'e', 'l'};
static const char* LOOP_MODEL_NAME_ABSTRACTION = LOOP_MODEL_NAME_ABSTRACTION_ARRAY;
static const int LOOP_MODEL_NAME_ABSTRACTION_COUNT_ARRAY[] = {5};
static const int* LOOP_MODEL_NAME_ABSTRACTION_COUNT = LOOP_MODEL_NAME_ABSTRACTION_COUNT_ARRAY;

//
// Property names operation add.
//

/** The operand_1 name array, pointer, count. */
static const char ADD_OPERAND_1_NAME_ABSTRACTION_ARRAY[] = {'o', 'p', 'e', 'r', 'a', 'n', 'd', '_', '1' };
static const char* ADD_OPERAND_1_NAME_ABSTRACTION = ADD_OPERAND_1_NAME_ABSTRACTION_ARRAY;
static const int ADD_OPERAND_1_NAME_ABSTRACTION_COUNT_ARRAY[] = {9};
static const int* ADD_OPERAND_1_NAME_ABSTRACTION_COUNT = ADD_OPERAND_1_NAME_ABSTRACTION_COUNT_ARRAY;


/** The operand_2 name array, pointer, count. */
static const char ADD_OPERAND_2_NAME_ABSTRACTION_ARRAY[] = {'o', 'p', 'e', 'r', 'a', 'n', 'd', '_', '2' };
static const char* ADD_OPERAND_2_NAME_ABSTRACTION = ADD_OPERAND_2_NAME_ABSTRACTION_ARRAY;
static const int ADD_OPERAND_2_NAME_ABSTRACTION_COUNT_ARRAY[] = {9};
static const int* ADD_OPERAND_2_NAME_ABSTRACTION_COUNT = ADD_OPERAND_2_NAME_ABSTRACTION_COUNT_ARRAY;

/** The operator name array, pointer, count. */
static const char ADD_RESULT_NAME_ABSTRACTION_ARRAY[] = {'r', 'e', 's', 'u', 'l', 't' };
static const char* ADD_RESULT_NAME_ABSTRACTION = ADD_RESULT_NAME_ABSTRACTION_ARRAY;
static const int ADD_RESULT_NAME_ABSTRACTION_COUNT_ARRAY[] = {6};
static const int* ADD_RESULT_NAME_ABSTRACTION_COUNT = ADD_RESULT_NAME_ABSTRACTION_COUNT_ARRAY;


/* NAME_CONSTANTS_SOURCE */
#endif
