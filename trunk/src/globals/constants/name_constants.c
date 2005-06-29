/*
 * $RCSfile: name_constants.c,v $
 *
 * Copyright (c) 1999-2005. Christian Heller and the CYBOP developers.
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
 * @version $Revision: 1.4 $ $Date: 2005-06-29 18:48:46 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 * @author Rolf Holzmueller <rolf.holzmueller@gmx.de>
 */

#ifndef NAME_CONSTANTS_SOURCE
#define NAME_CONSTANTS_SOURCE

//
// Web user interface (wui) names.
//

/** Tag name. */
static const char TAG_NAME_ARRAY[] = {'t', 'a', 'g'};
static const char* TAG_NAME = TAG_NAME_ARRAY;
static const int TAG_NAME_COUNT_ARRAY[] = {3};
static const int* TAG_NAME_COUNT = TAG_NAME_COUNT_ARRAY;

/** Property name. */
static const char PROPERTY_NAME_ARRAY[] = {'p', 'r', 'o', 'p', 'e', 'r', 't', 'y'};
static const char* PROPERTY_NAME = PROPERTY_NAME_ARRAY;
static const int PROPERTY_NAME_COUNT_ARRAY[] = {8};
static const int* PROPERTY_NAME_COUNT = PROPERTY_NAME_COUNT_ARRAY;

//
// Boolean names.
//

/** The input 1 name. */
static const char INPUT_1_NAME_ARRAY[] = {'i', 'n', 'p', 'u', 't', '_', '1'};
static const char* INPUT_1_NAME = INPUT_1_NAME_ARRAY;
static const int INPUT_1_NAME_COUNT_ARRAY[] = {7};
static const int* INPUT_1_NAME_COUNT = INPUT_1_NAME_COUNT_ARRAY;

/** The input 2 name. */
static const char INPUT_2_NAME_ARRAY[] = {'i', 'n', 'p', 'u', 't', '_', '2'};
static const char* INPUT_2_NAME = INPUT_2_NAME_ARRAY;
static const int INPUT_2_NAME_COUNT_ARRAY[] = {7};
static const int* INPUT_2_NAME_COUNT = INPUT_2_NAME_COUNT_ARRAY;

/** The output name. */
static const char OUTPUT_NAME_ARRAY[] = {'o', 'u', 't', 'p', 'u', 't'};
static const char* OUTPUT_NAME = OUTPUT_NAME_ARRAY;
static const int OUTPUT_NAME_COUNT_ARRAY[] = {6};
static const int* OUTPUT_NAME_COUNT = OUTPUT_NAME_COUNT_ARRAY;

//
// Compare names.
//

/** The left side name. */
static const char LEFT_SIDE_NAME_ARRAY[] = {'l', 'e', 'f', 't'};
static const char* LEFT_SIDE_NAME = LEFT_SIDE_NAME_ARRAY;
static const int LEFT_SIDE_NAME_COUNT_ARRAY[] = {4};
static const int* LEFT_SIDE_NAME_COUNT = LEFT_SIDE_NAME_COUNT_ARRAY;

/** The right side name. */
static const char RIGHT_SIDE_NAME_ARRAY[] = {'r', 'i', 'g', 'h', 't'};
static const char* RIGHT_SIDE_NAME = RIGHT_SIDE_NAME_ARRAY;
static const int RIGHT_SIDE_NAME_COUNT_ARRAY[] = {5};
static const int* RIGHT_SIDE_NAME_COUNT = RIGHT_SIDE_NAME_COUNT_ARRAY;

/** The result name. */
static const char RESULT_NAME_ARRAY[] = {'r', 'e', 's', 'u', 'l', 't'};
static const char* RESULT_NAME = RESULT_NAME_ARRAY;
static const int RESULT_NAME_COUNT_ARRAY[] = {6};
static const int* RESULT_NAME_COUNT = RESULT_NAME_COUNT_ARRAY;

//
// Arithmetic names.
//

/** The operand 1 name. */
static const char OPERAND_1_NAME_ARRAY[] = {'o', 'p', 'e', 'r', 'a', 'n', 'd', '_', '1'};
static const char* OPERAND_1_NAME = OPERAND_1_NAME_ARRAY;
static const int OPERAND_1_NAME_COUNT_ARRAY[] = {9};
static const int* OPERAND_1_NAME_COUNT = OPERAND_1_NAME_COUNT_ARRAY;

/** The operand 2 name. */
static const char OPERAND_2_NAME_ARRAY[] = {'o', 'p', 'e', 'r', 'a', 'n', 'd', '_', '2'};
static const char* OPERAND_2_NAME = OPERAND_2_NAME_ARRAY;
static const int OPERAND_2_NAME_COUNT_ARRAY[] = {9};
static const int* OPERAND_2_NAME_COUNT = OPERAND_2_NAME_COUNT_ARRAY;

/** The result operand name. */
static const char RESULT_OPERAND_NAME_ARRAY[] = {'r', 'e', 's', 'u', 'l', 't'};
static const char* RESULT_OPERAND_NAME = RESULT_OPERAND_NAME_ARRAY;
static const int RESULT_OPERAND_NAME_COUNT_ARRAY[] = {6};
static const int* RESULT_OPERAND_NAME_COUNT = RESULT_OPERAND_NAME_COUNT_ARRAY;

//
// Copy and move names.
//

/** The source name. */
static const char SOURCE_NAME_ARRAY[] = {'s', 'o', 'u', 'r', 'c', 'e'};
static const char* SOURCE_NAME = SOURCE_NAME_ARRAY;
static const int SOURCE_NAME_COUNT_ARRAY[] = {6};
static const int* SOURCE_NAME_COUNT = SOURCE_NAME_COUNT_ARRAY;

/** The destination name. */
static const char DESTINATION_NAME_ARRAY[] = {'d', 'e', 's', 't', 'i', 'n', 'a', 't', 'i', 'o', 'n'};
static const char* DESTINATION_NAME = DESTINATION_NAME_ARRAY;
static const int DESTINATION_NAME_COUNT_ARRAY[] = {11};
static const int* DESTINATION_NAME_COUNT = DESTINATION_NAME_COUNT_ARRAY;

/** The destination property name. */
static const char DESTINATION_PROPERTY_NAME_ARRAY[] = {'d', 'e', 's', 't', 'i', 'n', 'a', 't', 'i', 'o', 'n', '_', 'p', 'r', 'o', 'p', 'e', 'r', 't', 'y'};
static const char* DESTINATION_PROPERTY_NAME = DESTINATION_PROPERTY_NAME_ARRAY;
static const int DESTINATION_PROPERTY_NAME_COUNT_ARRAY[] = {20};
static const int* DESTINATION_PROPERTY_NAME_COUNT = DESTINATION_PROPERTY_NAME_COUNT_ARRAY;

//
// Branch names.
//

/** The criterion name. */
static const char CRITERION_NAME_ARRAY[] = {'c', 'r', 'i', 't', 'e', 'r', 'i', 'o', 'n'};
static const char* CRITERION_NAME = CRITERION_NAME_ARRAY;
static const int CRITERION_NAME_COUNT_ARRAY[] = {9};
static const int* CRITERION_NAME_COUNT = CRITERION_NAME_COUNT_ARRAY;

/** The true model name. */
static const char TRUE_MODEL_NAME_ARRAY[] = {'t', 'r', 'u', 'e', '_', 'm', 'o', 'd', 'e', 'l'};
static const char* TRUE_MODEL_NAME = TRUE_MODEL_NAME_ARRAY;
static const int TRUE_MODEL_NAME_COUNT_ARRAY[] = {10};
static const int* TRUE_MODEL_NAME_COUNT = TRUE_MODEL_NAME_COUNT_ARRAY;

/** The false model name. */
static const char FALSE_MODEL_NAME_ARRAY[] = {'f', 'a', 'l', 's', 'e', '_', 'm', 'o', 'd', 'e', 'l'};
static const char* FALSE_MODEL_NAME = FALSE_MODEL_NAME_ARRAY;
static const int FALSE_MODEL_NAME_COUNT_ARRAY[] = {11};
static const int* FALSE_MODEL_NAME_COUNT = FALSE_MODEL_NAME_COUNT_ARRAY;

//
// Loop names.
//

/** The break flag name. */
static const char BREAK_FLAG_NAME_ARRAY[] = {'b', 'r', 'e', 'a', 'k'};
static const char* BREAK_FLAG_NAME = BREAK_FLAG_NAME_ARRAY;
static const int BREAK_FLAG_NAME_COUNT_ARRAY[] = {5};
static const int* BREAK_FLAG_NAME_COUNT = BREAK_FLAG_NAME_COUNT_ARRAY;

/** The loop model name. */
static const char LOOP_MODEL_NAME_ARRAY[] = {'m', 'o', 'd', 'e', 'l'};
static const char* LOOP_MODEL_NAME = LOOP_MODEL_NAME_ARRAY;
static const int LOOP_MODEL_NAME_COUNT_ARRAY[] = {5};
static const int* LOOP_MODEL_NAME_COUNT = LOOP_MODEL_NAME_COUNT_ARRAY;

//
// Build listname names.
//

/** The base name name. */
static const char BASE_NAME_NAME_ARRAY[] = {'b', 'a', 's', 'e'};
static const char* BASE_NAME_NAME = BASE_NAME_NAME_ARRAY;
static const int BASE_NAME_NAME_COUNT_ARRAY[] = {4};
static const int* BASE_NAME_NAME_COUNT = BASE_NAME_NAME_COUNT_ARRAY;

/** The index name name. */
static const char INDEX_NAME_NAME_ARRAY[] = {'i', 'n', 'd', 'e', 'x'};
static const char* INDEX_NAME_NAME = INDEX_NAME_NAME_ARRAY;
static const int INDEX_NAME_NAME_COUNT_ARRAY[] = {5};
static const int* INDEX_NAME_NAME_COUNT = INDEX_NAME_NAME_COUNT_ARRAY;

/** The composed name name. */
static const char COMPOSED_NAME_NAME_ARRAY[] = {'c', 'o', 'm', 'p', 'o', 's', 'e', 'd'};
static const char* COMPOSED_NAME_NAME = COMPOSED_NAME_NAME_ARRAY;
static const int COMPOSED_NAME_NAME_COUNT_ARRAY[] = {8};
static const int* COMPOSED_NAME_NAME_COUNT = COMPOSED_NAME_NAME_COUNT_ARRAY;

//
// Count parts names.
//

/** The whole model name. */
static const char WHOLE_MODEL_NAME_ARRAY[] = {'w', 'h', 'o', 'l', 'e'};
static const char* WHOLE_MODEL_NAME = WHOLE_MODEL_NAME_ARRAY;
static const int WHOLE_MODEL_NAME_COUNT_ARRAY[] = {5};
static const int* WHOLE_MODEL_NAME_COUNT = WHOLE_MODEL_NAME_COUNT_ARRAY;

/** The part name name. */
static const char PART_NAME_NAME_ARRAY[] = {'n', 'a', 'm', 'e'};
static const char* PART_NAME_NAME = PART_NAME_NAME_ARRAY;
static const int PART_NAME_NAME_COUNT_ARRAY[] = {4};
static const int* PART_NAME_NAME_COUNT = PART_NAME_NAME_COUNT_ARRAY;

/** The counter name. */
static const char COUNTER_NAME_ARRAY[] = {'c', 'o', 'u', 'n', 't', 'e', 'r'};
static const char* COUNTER_NAME = COUNTER_NAME_ARRAY;
static const int COUNTER_NAME_COUNT_ARRAY[] = {7};
static const int* COUNTER_NAME_COUNT = COUNTER_NAME_COUNT_ARRAY;

//
// Create and destroy names.
//

/** The name name. */
static const char NAME_NAME_ARRAY[] = {'n', 'a', 'm', 'e'};
static const char* NAME_NAME = NAME_NAME_ARRAY;
static const int NAME_NAME_COUNT_ARRAY[] = {4};
static const int* NAME_NAME_COUNT = NAME_NAME_COUNT_ARRAY;

/** The channel name. */
static const char CHANNEL_NAME_ARRAY[] = {'c', 'h', 'a', 'n', 'n', 'e', 'l'};
static const char* CHANNEL_NAME = CHANNEL_NAME_ARRAY;
static const int CHANNEL_NAME_COUNT_ARRAY[] = {7};
static const int* CHANNEL_NAME_COUNT = CHANNEL_NAME_COUNT_ARRAY;

/** The abstraction name. */
static const char ABSTRACTION_NAME_ARRAY[] = {'a', 'b', 's', 't', 'r', 'a', 'c', 't', 'i', 'o', 'n'};
static const char* ABSTRACTION_NAME = ABSTRACTION_NAME_ARRAY;
static const int ABSTRACTION_NAME_COUNT_ARRAY[] = {11};
static const int* ABSTRACTION_NAME_COUNT = ABSTRACTION_NAME_COUNT_ARRAY;

/** The model name. */
static const char MODEL_NAME_ARRAY[] = {'m', 'o', 'd', 'e', 'l'};
static const char* MODEL_NAME = MODEL_NAME_ARRAY;
static const int MODEL_NAME_COUNT_ARRAY[] = {5};
static const int* MODEL_NAME_COUNT = MODEL_NAME_COUNT_ARRAY;

/** The whole name. */
static const char WHOLE_NAME_ARRAY[] = {'w', 'h', 'o', 'l', 'e'};
static const char* WHOLE_NAME = WHOLE_NAME_ARRAY;
static const int WHOLE_NAME_COUNT_ARRAY[] = {5};
static const int* WHOLE_NAME_COUNT = WHOLE_NAME_COUNT_ARRAY;

//
// Startup and shutdown names.
//

/** The service name. */
static const char SERVICE_NAME_ARRAY[] = {'s', 'e', 'r', 'v', 'i', 'c', 'e'};
static const char* SERVICE_NAME = SERVICE_NAME_ARRAY;
static const int SERVICE_NAME_COUNT_ARRAY[] = {7};
static const int* SERVICE_NAME_COUNT = SERVICE_NAME_COUNT_ARRAY;

/** The platform name. */
static const char PLATFORM_NAME_ARRAY[] = {'p', 'l', 'a', 't', 'f', 'o', 'r', 'm'};
static const char* PLATFORM_NAME = PLATFORM_NAME_ARRAY;
static const int PLATFORM_NAME_COUNT_ARRAY[] = {8};
static const int* PLATFORM_NAME_COUNT = PLATFORM_NAME_COUNT_ARRAY;

/** The port name. */
static const char PORT_NAME_ARRAY[] = {'p', 'o', 'r', 't'};
static const char* PORT_NAME = PORT_NAME_ARRAY;
static const int PORT_NAME_COUNT_ARRAY[] = {4};
static const int* PORT_NAME_COUNT = PORT_NAME_COUNT_ARRAY;

//
// Send and receive names.
//

/** The language name. */
static const char LANGUAGE_NAME_ARRAY[] = {'l', 'a', 'n', 'g', 'u', 'a', 'g', 'e'};
static const char* LANGUAGE_NAME = LANGUAGE_NAME_ARRAY;
static const int LANGUAGE_NAME_COUNT_ARRAY[] = {8};
static const int* LANGUAGE_NAME_COUNT = LANGUAGE_NAME_COUNT_ARRAY;

/** The sender name. */
static const char SENDER_NAME_ARRAY[] = {'s', 'e', 'n', 'd', 'e', 'r'};
static const char* SENDER_NAME = SENDER_NAME_ARRAY;
static const int SENDER_NAME_COUNT_ARRAY[] = {6};
static const int* SENDER_NAME_COUNT = SENDER_NAME_COUNT_ARRAY;

/** The receiver name. */
static const char RECEIVER_NAME_ARRAY[] = {'r', 'e', 'c', 'e', 'i', 'v', 'e', 'r'};
static const char* RECEIVER_NAME = RECEIVER_NAME_ARRAY;
static const int RECEIVER_NAME_COUNT_ARRAY[] = {8};
static const int* RECEIVER_NAME_COUNT = RECEIVER_NAME_COUNT_ARRAY;

/** The message name. */
static const char MESSAGE_NAME_ARRAY[] = {'m', 'e', 's', 's', 'a', 'g', 'e'};
static const char* MESSAGE_NAME = MESSAGE_NAME_ARRAY;
static const int MESSAGE_NAME_COUNT_ARRAY[] = {7};
static const int* MESSAGE_NAME_COUNT = MESSAGE_NAME_COUNT_ARRAY;

/** The url name. */
static const char URL_NAME_ARRAY[] = {'u', 'r', 'l'};
static const char* URL_NAME = URL_NAME_ARRAY;
static const int URL_NAME_COUNT_ARRAY[] = {3};
static const int* URL_NAME_COUNT = URL_NAME_COUNT_ARRAY;

/** The blocking name. */
static const char BLOCKING_NAME_ARRAY[] = {'b', 'l', 'o', 'c', 'k', 'i', 'n', 'g'};
static const char* BLOCKING_NAME = BLOCKING_NAME_ARRAY;
static const int BLOCKING_NAME_COUNT_ARRAY[] = {8};
static const int* BLOCKING_NAME_COUNT = BLOCKING_NAME_COUNT_ARRAY;

/* NAME_CONSTANTS_SOURCE */
#endif
