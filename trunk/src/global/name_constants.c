/*
 * $RCSfile: name_constants.c,v $
 *
 * Copyright (c) 1999-2004. Christian Heller. All rights reserved.
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
 * This file defines global communication channel constants.
 *
 * It was decided to keep them bundled in this place to ease their maintenance.
 * One day, they can be burnt together with the cyboi implementation into a
 * hardware chip, just like operation codes of a central processing unit (cpu).
 * This would tremendously increase performance.
 *
 * @version $Revision: 1.6 $ $Date: 2005-01-07 11:59:48 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
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

/** The tcp server socket port configuration name. */
static const char TCP_SERVER_SOCKET_PORT_CONFIGURATION_NAME_ARRAY[] = {'t', 'c', 'p', '_', 's', 'e', 'r', 'v', 'e', 'r', '_', 's', 'o', 'c', 'k', 'e', 't', '_', 'p', 'o', 'r', 't'};
static const char* TCP_SERVER_SOCKET_PORT_CONFIGURATION_NAME = TCP_SERVER_SOCKET_PORT_CONFIGURATION_NAME_ARRAY;
static const int TCP_SERVER_SOCKET_PORT_CONFIGURATION_NAME_COUNT_ARRAY[] = {22};
static const int* TCP_SERVER_SOCKET_PORT_CONFIGURATION_NAME_COUNT = TCP_SERVER_SOCKET_PORT_CONFIGURATION_NAME_COUNT_ARRAY;

/** The tcp server socket active configuration name. */
static const char TCP_SERVER_SOCKET_ACTIVE_CONFIGURATION_NAME_ARRAY[] = {'t', 'c', 'p', '_', 's', 'e', 'r', 'v', 'e', 'r', '_', 's', 'o', 'c', 'k', 'e', 't', '_', 'a', 'c', 't', 'i', 'v', 'e'};
static const char* TCP_SERVER_SOCKET_ACTIVE_CONFIGURATION_NAME = TCP_SERVER_SOCKET_ACTIVE_CONFIGURATION_NAME_ARRAY;
static const int TCP_SERVER_SOCKET_ACTIVE_CONFIGURATION_NAME_COUNT_ARRAY[] = {24};
static const int* TCP_SERVER_SOCKET_ACTIVE_CONFIGURATION_NAME_COUNT = TCP_SERVER_SOCKET_ACTIVE_CONFIGURATION_NAME_COUNT_ARRAY;

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

/* NAME_CONSTANTS_SOURCE */
#endif
