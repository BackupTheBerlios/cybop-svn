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
 * @version $Revision: 1.1 $ $Date: 2004-10-18 20:39:53 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef NAME_CONSTANTS_SOURCE
#define NAME_CONSTANTS_SOURCE

//
// Creation names.
//

/** The name name abstraction. */
static const char NAME_NAME_ABSTRACTION_ARRAY[] = {'n', 'a', 'm', 'e'};
static const char* NAME_NAME_ABSTRACTION = NAME_NAME_ABSTRACTION_ARRAY;
static const int NAME_NAME_ABSTRACTION_COUNT = 4;

/** The channel name abstraction. */
static const char CHANNEL_NAME_ABSTRACTION_ARRAY[] = {'c', 'h', 'a', 'n', 'n', 'e', 'l'};
static const char* CHANNEL_NAME_ABSTRACTION = CHANNEL_NAME_ABSTRACTION_ARRAY;
static const int CHANNEL_NAME_ABSTRACTION_COUNT = 7;

/** The abstraction name abstraction. */
static const char ABSTRACTION_NAME_ABSTRACTION_ARRAY[] = {'a', 'b', 's', 't', 'r', 'a', 'c', 't', 'i', 'o', 'n'};
static const char* ABSTRACTION_NAME_ABSTRACTION = ABSTRACTION_NAME_ABSTRACTION_ARRAY;
static const int ABSTRACTION_NAME_ABSTRACTION_COUNT = 11;

/** The model name abstraction. */
static const char MODEL_NAME_ABSTRACTION_ARRAY[] = {'m', 'o', 'd', 'e', 'l'};
static const char* MODEL_NAME_ABSTRACTION = MODEL_NAME_ABSTRACTION_ARRAY;
static const int MODEL_NAME_ABSTRACTION_COUNT = 5;

/** The whole name abstraction. */
static const char WHOLE_NAME_ABSTRACTION_ARRAY[] = {'w', 'h', 'o', 'l', 'e'};
static const char* WHOLE_NAME_ABSTRACTION = WHOLE_NAME_ABSTRACTION_ARRAY;
static const int WHOLE_NAME_ABSTRACTION_COUNT = 5;

//
// Communication names.
//

/** The language name array, pointer, count. */
static const char LANGUAGE_NAME_ABSTRACTION_ARRAY[] = {'l', 'a', 'n', 'g', 'u', 'a', 'g', 'e'};
static const char* LANGUAGE_NAME_ABSTRACTION = LANGUAGE_NAME_ABSTRACTION_ARRAY;
static const int LANGUAGE_NAME_ABSTRACTION_COUNT = 8;

/** The sender name array, pointer, count. */
static const char SENDER_NAME_ABSTRACTION_ARRAY[] = {'s', 'e', 'n', 'd', 'e', 'r'};
static const char* SENDER_NAME_ABSTRACTION = SENDER_NAME_ABSTRACTION_ARRAY;
static const int SENDER_NAME_ABSTRACTION_COUNT = 6;

/** The receiver name array, pointer, count. */
static const char RECEIVER_NAME_ABSTRACTION_ARRAY[] = {'r', 'e', 'c', 'e', 'i', 'v', 'e', 'r'};
static const char* RECEIVER_NAME_ABSTRACTION = RECEIVER_NAME_ABSTRACTION_ARRAY;
static const int RECEIVER_NAME_ABSTRACTION_COUNT = 8;

/** The message name array, pointer, count. */
static const char MESSAGE_NAME_ABSTRACTION_ARRAY[] = {'m', 'e', 's', 's', 'a', 'g', 'e'};
static const char* MESSAGE_NAME_ABSTRACTION = MESSAGE_NAME_ABSTRACTION_ARRAY;
static const int MESSAGE_NAME_ABSTRACTION_COUNT = 7;

/* NAME_CONSTANTS_SOURCE */
#endif