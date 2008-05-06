/*
 * $RCSfile: cybol_model_constants.c,v $
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
 * @version $Revision: 1.10 $ $Date: 2008-05-06 22:36:53 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CYBOL_MODEL_CONSTANTS_SOURCE
#define CYBOL_MODEL_CONSTANTS_SOURCE

#include "../../../globals/constants/integer/integer_constants.c"

//
// Special models.
//

/** The empty model. */
static wchar_t EMPTY_MODEL_ARRAY[] = {};
static wchar_t* EMPTY_MODEL = EMPTY_MODEL_ARRAY;
static int* EMPTY_MODEL_COUNT = NUMBER_0_INTEGER_ARRAY;

//
// Boolean models.
//

/** The false model. */
static wchar_t FALSE_MODEL_ARRAY[] = {L'f', L'a', L'l', L's', L'e'};
static wchar_t* FALSE_MODEL = FALSE_MODEL_ARRAY;
static int* FALSE_MODEL_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The true model. */
static wchar_t TRUE_MODEL_ARRAY[] = {L't', L'r', L'u', L'e'};
static wchar_t* TRUE_MODEL = TRUE_MODEL_ARRAY;
static int* TRUE_MODEL_COUNT = NUMBER_4_INTEGER_ARRAY;

//
// Terminal colour models.
//

/** The black model. */
static wchar_t TERMINAL_COLOUR_BLACK_MODEL_ARRAY[] = {L'b', L'l', L'a', L'c', L'k'};
static wchar_t* TERMINAL_COLOUR_BLACK_MODEL = TERMINAL_COLOUR_BLACK_MODEL_ARRAY;
static int* TERMINAL_COLOUR_BLACK_MODEL_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The red model. */
static wchar_t TERMINAL_COLOUR_RED_MODEL_ARRAY[] = {L'r', L'e', L'd'};
static wchar_t* TERMINAL_COLOUR_RED_MODEL = TERMINAL_COLOUR_RED_MODEL_ARRAY;
static int* TERMINAL_COLOUR_RED_MODEL_COUNT = NUMBER_3_INTEGER_ARRAY;

/** The green model. */
static wchar_t TERMINAL_COLOUR_GREEN_MODEL_ARRAY[] = {L'g', L'r', L'e', L'e', L'n'};
static wchar_t* TERMINAL_COLOUR_GREEN_MODEL = TERMINAL_COLOUR_GREEN_MODEL_ARRAY;
static int* TERMINAL_COLOUR_GREEN_MODEL_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The yellow model. */
static wchar_t TERMINAL_COLOUR_YELLOW_MODEL_ARRAY[] = {L'y', L'e', L'l', L'l', L'o', L'w'};
static wchar_t* TERMINAL_COLOUR_YELLOW_MODEL = TERMINAL_COLOUR_YELLOW_MODEL_ARRAY;
static int* TERMINAL_COLOUR_YELLOW_MODEL_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The blue model. */
static wchar_t TERMINAL_COLOUR_BLUE_MODEL_ARRAY[] = {L'b', L'l', L'u', L'e'};
static wchar_t* TERMINAL_COLOUR_BLUE_MODEL = TERMINAL_COLOUR_BLUE_MODEL_ARRAY;
static int* TERMINAL_COLOUR_BLUE_MODEL_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The magenta (violet, purple, mauve) model. */
static wchar_t TERMINAL_COLOUR_MAGENTA_MODEL_ARRAY[] = {L'm', L'a', L'g', L'e', L'n', L't', L'a'};
static wchar_t* TERMINAL_COLOUR_MAGENTA_MODEL = TERMINAL_COLOUR_MAGENTA_MODEL_ARRAY;
static int* TERMINAL_COLOUR_MAGENTA_MODEL_COUNT = NUMBER_7_INTEGER_ARRAY;

/** The cobalt blue (china blue) model. */
static wchar_t TERMINAL_COLOUR_COBALT_MODEL_ARRAY[] = {L'c', L'o', L'b', L'a', L'l', L't'};
static wchar_t* TERMINAL_COLOUR_COBALT_MODEL = TERMINAL_COLOUR_COBALT_MODEL_ARRAY;
static int* TERMINAL_COLOUR_COBALT_MODEL_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The white model. */
static wchar_t TERMINAL_COLOUR_WHITE_MODEL_ARRAY[] = {L'w', L'h', L'i', L't', L'e'};
static wchar_t* TERMINAL_COLOUR_WHITE_MODEL = TERMINAL_COLOUR_WHITE_MODEL_ARRAY;
static int* TERMINAL_COLOUR_WHITE_MODEL_COUNT = NUMBER_5_INTEGER_ARRAY;

//
// Data transfer models.
//

/** The copy (set, assign) model. */
static wchar_t COPY_MODEL_ARRAY[] = {L'c', L'o', L'p', L'y'};
static wchar_t* COPY_MODEL = COPY_MODEL_ARRAY;
static int* COPY_MODEL_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The move model. */
static wchar_t MOVE_MODEL_ARRAY[] = {L'm', L'o', L'v', L'e'};
static wchar_t* MOVE_MODEL = MOVE_MODEL_ARRAY;
static int* MOVE_MODEL_COUNT = NUMBER_4_INTEGER_ARRAY;

//
// Program flow models.
//

/** The branch model. */
static wchar_t BRANCH_MODEL_ARRAY[] = {L'b', L'r', L'a', L'n', L'c', L'h'};
static wchar_t* BRANCH_MODEL = BRANCH_MODEL_ARRAY;
static int* BRANCH_MODEL_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The loop model. */
static wchar_t LOOP_MODEL_ARRAY[] = {L'l', L'o', L'o', L'p'};
static wchar_t* LOOP_MODEL = LOOP_MODEL_ARRAY;
static int* LOOP_MODEL_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The count model. */
static wchar_t COUNT_MODEL_ARRAY[] = {L'c', L'o', L'u', L'n', L't'};
static wchar_t* COUNT_MODEL = COUNT_MODEL_ARRAY;
static int* COUNT_MODEL_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The build listname model. */
static wchar_t BUILD_LISTNAME_MODEL_ARRAY[] = {L'b', L'u', L'i', L'l', L'd', L'_', L'l', L'i', L's', L't', L'n', L'a', L'm', L'e'};
static wchar_t* BUILD_LISTNAME_MODEL = BUILD_LISTNAME_MODEL_ARRAY;
static int* BUILD_LISTNAME_MODEL_COUNT = NUMBER_14_INTEGER_ARRAY;

/** The get model. */
static wchar_t GET_MODEL_ARRAY[] = {L'g', L'e', L't'};
static wchar_t* GET_MODEL = GET_MODEL_ARRAY;
static int* GET_MODEL_COUNT = NUMBER_3_INTEGER_ARRAY;

//
// Count selection models.
//

/** The count all selection model. */
static wchar_t COUNT_ALL_SELECTION_MODEL_ARRAY[] = {L'a', L'l', L'l'};
static wchar_t* COUNT_ALL_SELECTION_MODEL = COUNT_ALL_SELECTION_MODEL_ARRAY;
static int* COUNT_ALL_SELECTION_MODEL_COUNT = NUMBER_3_INTEGER_ARRAY;

/** The count prefix selection model. */
static wchar_t COUNT_PREFIX_SELECTION_MODEL_ARRAY[] = {L'p', L'r', L'e', L'f', L'i', L'x'};
static wchar_t* COUNT_PREFIX_SELECTION_MODEL = COUNT_PREFIX_SELECTION_MODEL_ARRAY;
static int* COUNT_PREFIX_SELECTION_MODEL_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The count suffix selection model. */
static wchar_t COUNT_SUFFIX_SELECTION_MODEL_ARRAY[] = {L's', L'u', L'f', L'f', L'i', L'x'};
static wchar_t* COUNT_SUFFIX_SELECTION_MODEL = COUNT_SUFFIX_SELECTION_MODEL_ARRAY;
static int* COUNT_SUFFIX_SELECTION_MODEL_COUNT = NUMBER_6_INTEGER_ARRAY;

//
// Get description models.
//

/** The get name description model. */
static wchar_t GET_NAME_DESCRIPTION_MODEL_ARRAY[] = {L'n', L'a', L'm', L'e'};
static wchar_t* GET_NAME_DESCRIPTION_MODEL = GET_NAME_DESCRIPTION_MODEL_ARRAY;
static int* GET_NAME_DESCRIPTION_MODEL_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The get abstraction description model. */
static wchar_t GET_ABSTRACTION_DESCRIPTION_MODEL_ARRAY[] = {L'a', L'b', L's', L't', L'r', L'a', L'c', L't', L'i', L'o', L'n'};
static wchar_t* GET_ABSTRACTION_DESCRIPTION_MODEL = GET_ABSTRACTION_DESCRIPTION_MODEL_ARRAY;
static int* GET_ABSTRACTION_DESCRIPTION_MODEL_COUNT = NUMBER_11_INTEGER_ARRAY;

//
// Boolean logic models.
//

/** The not model. This is the ones complement (all bits negated). */
static wchar_t NOT_MODEL_ARRAY[] = {L'n', L'o', L't'};
static wchar_t* NOT_MODEL = NOT_MODEL_ARRAY;
static int* NOT_MODEL_COUNT = NUMBER_3_INTEGER_ARRAY;

/** The neg model. This is the two's complement (all bits negated and added one). */
static wchar_t NEG_MODEL_ARRAY[] = {L'n', L'e', L'g'};
static wchar_t* NEG_MODEL = NEG_MODEL_ARRAY;
static int* NEG_MODEL_COUNT = NUMBER_3_INTEGER_ARRAY;

/** The and model. */
static wchar_t AND_MODEL_ARRAY[] = {L'a', L'n', L'd'};
static wchar_t* AND_MODEL = AND_MODEL_ARRAY;
static int* AND_MODEL_COUNT = NUMBER_3_INTEGER_ARRAY;

/** The or model. */
static wchar_t OR_MODEL_ARRAY[] = {L'o', L'r'};
static wchar_t* OR_MODEL = OR_MODEL_ARRAY;
static int* OR_MODEL_COUNT = NUMBER_2_INTEGER_ARRAY;

/** The xor model. */
static wchar_t XOR_MODEL_ARRAY[] = {L'x', L'o', L'r'};
static wchar_t* XOR_MODEL = XOR_MODEL_ARRAY;
static int* XOR_MODEL_COUNT = NUMBER_3_INTEGER_ARRAY;

//
// Bit manipulation models.
//

/** The shift left model. It corresponds to "SHL" assembler command. */
static wchar_t SHIFT_LEFT_MODEL_ARRAY[] = {L's', L'h', L'i', L'f', L't', L'_', L'l', L'e', L'f', L't'};
static wchar_t* SHIFT_LEFT_MODEL = SHIFT_LEFT_MODEL_ARRAY;
static int* SHIFT_LEFT_MODEL_COUNT = NUMBER_10_INTEGER_ARRAY;

/** The shift right model. It corresponds to "SHR" assembler command. */
static wchar_t SHIFT_RIGHT_MODEL_ARRAY[] = {L's', L'h', L'i', L'f', L't', L'_', L'r', L'i', L'g', L'h', L't'};
static wchar_t* SHIFT_RIGHT_MODEL = SHIFT_RIGHT_MODEL_ARRAY;
static int* SHIFT_RIGHT_MODEL_COUNT = NUMBER_11_INTEGER_ARRAY;

/** The rotate left model. It corresponds to "ROL" assembler command. */
static wchar_t ROTATE_LEFT_MODEL_ARRAY[] = {L'r', L'o', L't', L'a', L't', L'e', L'_', L'l', L'e', L'f', L't'};
static wchar_t* ROTATE_LEFT_MODEL = ROTATE_LEFT_MODEL_ARRAY;
static int* ROTATE_LEFT_MODEL_COUNT = NUMBER_11_INTEGER_ARRAY;

/** The rotate right model. It corresponds to "ROR" assembler command. */
static wchar_t ROTATE_RIGHT_MODEL_ARRAY[] = {L'r', L'o', L't', L'a', L't', L'e', L'_', L'r', L'i', L'g', L'h', L't'};
static wchar_t* ROTATE_RIGHT_MODEL = ROTATE_RIGHT_MODEL_ARRAY;
static int* ROTATE_RIGHT_MODEL_COUNT = NUMBER_12_INTEGER_ARRAY;

/** The set bit model. It corresponds to "BTS" assembler command. */
static wchar_t SET_BIT_MODEL_ARRAY[] = {L's', L'e', L't', L'_', L'b', L'i', L't'};
static wchar_t* SET_BIT_MODEL = SET_BIT_MODEL_ARRAY;
static int* SET_BIT_MODEL_COUNT = NUMBER_7_INTEGER_ARRAY;

/** The reset bit model. It corresponds to "BTR" assembler command. */
static wchar_t RESET_BIT_MODEL_ARRAY[] = {L'r', L'e', L's', L'e', L't', L'_', L'b', L'i', L't'};
static wchar_t* RESET_BIT_MODEL = RESET_BIT_MODEL_ARRAY;
static int* RESET_BIT_MODEL_COUNT = NUMBER_9_INTEGER_ARRAY;

/** The get bit model. It corresponds to "BT" assembler command. */
static wchar_t GET_BIT_MODEL_ARRAY[] = {L'g', L'e', L't', L'_', L'b', L'i', L't'};
static wchar_t* GET_BIT_MODEL = GET_BIT_MODEL_ARRAY;
static int* GET_BIT_MODEL_COUNT = NUMBER_7_INTEGER_ARRAY;

//
// Comparison models.
//

/** The compare model. */
static wchar_t COMPARE_MODEL_ARRAY[] = {L'c', L'o', L'm', L'p', L'a', L'r', L'e'};
static wchar_t* COMPARE_MODEL = COMPARE_MODEL_ARRAY;
static int* COMPARE_MODEL_COUNT = NUMBER_7_INTEGER_ARRAY;

/** The equal model. */
static wchar_t EQUAL_MODEL_ARRAY[] = {L'e', L'q', L'u', L'a', L'l'};
static wchar_t* EQUAL_MODEL = EQUAL_MODEL_ARRAY;
static int* EQUAL_MODEL_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The smaller model. */
static wchar_t SMALLER_MODEL_ARRAY[] = {L's', L'm', L'a', L'l', L'l', L'e', L'r'};
static wchar_t* SMALLER_MODEL = SMALLER_MODEL_ARRAY;
static int* SMALLER_MODEL_COUNT = NUMBER_7_INTEGER_ARRAY;

/** The greater model. */
static wchar_t GREATER_MODEL_ARRAY[] = {L'g', L'r', L'e', L'a', L't', L'e', L'r'};
static wchar_t* GREATER_MODEL = GREATER_MODEL_ARRAY;
static int* GREATER_MODEL_COUNT = NUMBER_7_INTEGER_ARRAY;

/** The smaller or equal model. */
static wchar_t SMALLER_OR_EQUAL_MODEL_ARRAY[] = {L's', L'm', L'a', L'l', L'l', L'e', L'r', L'_', L'o', L'r', L'_', L'e', L'q', L'u', L'a', L'l'};
static wchar_t* SMALLER_OR_EQUAL_MODEL = SMALLER_OR_EQUAL_MODEL_ARRAY;
static int* SMALLER_OR_EQUAL_MODEL_COUNT = NUMBER_16_INTEGER_ARRAY;

/** The greater or equal model. */
static wchar_t GREATER_OR_EQUAL_MODEL_ARRAY[] = {L'g', L'r', L'e', L'a', L't', L'e', L'r', L'_', L'o', L'r', L'_', L'e', L'q', L'u', L'a', L'l'};
static wchar_t* GREATER_OR_EQUAL_MODEL = GREATER_OR_EQUAL_MODEL_ARRAY;
static int* GREATER_OR_EQUAL_MODEL_COUNT = NUMBER_16_INTEGER_ARRAY;

//
// Comparison selection models.
//

/** The compare all selection model. */
static wchar_t COMPARE_ALL_SELECTION_MODEL_ARRAY[] = {L'a', L'l', L'l'};
static wchar_t* COMPARE_ALL_SELECTION_MODEL = COMPARE_ALL_SELECTION_MODEL_ARRAY;
static int* COMPARE_ALL_SELECTION_MODEL_COUNT = NUMBER_3_INTEGER_ARRAY;

/** The compare prefix selection model. */
static wchar_t COMPARE_PREFIX_SELECTION_MODEL_ARRAY[] = {L'p', L'r', L'e', L'f', L'i', L'x'};
static wchar_t* COMPARE_PREFIX_SELECTION_MODEL = COMPARE_PREFIX_SELECTION_MODEL_ARRAY;
static int* COMPARE_PREFIX_SELECTION_MODEL_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The compare suffix selection model. */
static wchar_t COMPARE_SUFFIX_SELECTION_MODEL_ARRAY[] = {L's', L'u', L'f', L'f', L'i', L'x'};
static wchar_t* COMPARE_SUFFIX_SELECTION_MODEL = COMPARE_SUFFIX_SELECTION_MODEL_ARRAY;
static int* COMPARE_SUFFIX_SELECTION_MODEL_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The compare part selection model. */
static wchar_t COMPARE_PART_SELECTION_MODEL_ARRAY[] = {L'p', L'a', L'r', L't'};
static wchar_t* COMPARE_PART_SELECTION_MODEL = COMPARE_PART_SELECTION_MODEL_ARRAY;
static int* COMPARE_PART_SELECTION_MODEL_COUNT = NUMBER_4_INTEGER_ARRAY;

//
// Arithmetic models.
//

/** The add model. */
static wchar_t ADD_MODEL_ARRAY[] = {L'a', L'd', L'd'};
static wchar_t* ADD_MODEL = ADD_MODEL_ARRAY;
static int* ADD_MODEL_COUNT = NUMBER_3_INTEGER_ARRAY;

/** The subtract model. */
static wchar_t SUBTRACT_MODEL_ARRAY[] = {L's', L'u', L'b', L't', L'r', L'a', L'c', L't'};
static wchar_t* SUBTRACT_MODEL = SUBTRACT_MODEL_ARRAY;
static int* SUBTRACT_MODEL_COUNT = NUMBER_8_INTEGER_ARRAY;

/** The multiply model. */
static wchar_t MULTIPLY_MODEL_ARRAY[] = {L'm', L'u', L'l', L't', L'i', L'p', L'l', L'y'};
static wchar_t* MULTIPLY_MODEL = MULTIPLY_MODEL_ARRAY;
static int* MULTIPLY_MODEL_COUNT = NUMBER_8_INTEGER_ARRAY;

/** The divide model. */
static wchar_t DIVIDE_MODEL_ARRAY[] = {L'd', L'i', L'v', L'i', L'd', L'e'};
static wchar_t* DIVIDE_MODEL = DIVIDE_MODEL_ARRAY;
static int* DIVIDE_MODEL_COUNT = NUMBER_6_INTEGER_ARRAY;

//
// Memory management models.
//

/** The create model. */
static wchar_t CREATE_MODEL_ARRAY[] = {L'c', L'r', L'e', L'a', L't', L'e'};
static wchar_t* CREATE_MODEL = CREATE_MODEL_ARRAY;
static int* CREATE_MODEL_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The create part element model. */
static wchar_t CREATE_PART_ELEMENT_MODEL_ARRAY[] = {L'p', L'a', L'r', L't'};
static wchar_t* CREATE_PART_ELEMENT_MODEL = CREATE_PART_ELEMENT_MODEL_ARRAY;
static int* CREATE_PART_ELEMENT_MODEL_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The create meta element model. */
static wchar_t CREATE_META_ELEMENT_MODEL_ARRAY[] = {L'm', L'e', L't', L'a'};
static wchar_t* CREATE_META_ELEMENT_MODEL = CREATE_META_ELEMENT_MODEL_ARRAY;
static int* CREATE_META_ELEMENT_MODEL_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The destroy model. */
static wchar_t DESTROY_MODEL_ARRAY[] = {L'd', L'e', L's', L't', L'r', L'o', L'y'};
static wchar_t* DESTROY_MODEL = DESTROY_MODEL_ARRAY;
static int* DESTROY_MODEL_COUNT = NUMBER_7_INTEGER_ARRAY;

//
// Lifecycle models.
//

/** The startup model. */
static wchar_t STARTUP_MODEL_ARRAY[] = {L's', L't', L'a', L'r', L't', L'u', L'p'};
static wchar_t* STARTUP_MODEL = STARTUP_MODEL_ARRAY;
static int* STARTUP_MODEL_COUNT = NUMBER_7_INTEGER_ARRAY;

/** The shutdown model. */
static wchar_t SHUTDOWN_MODEL_ARRAY[] = {L's', L'h', L'u', L't', L'd', L'o', L'w', L'n'};
static wchar_t* SHUTDOWN_MODEL = SHUTDOWN_MODEL_ARRAY;
static int* SHUTDOWN_MODEL_COUNT = NUMBER_8_INTEGER_ARRAY;

/** The exit model. */
static wchar_t EXIT_MODEL_ARRAY[] = {L'e', L'x', L'i', L't'};
static wchar_t* EXIT_MODEL = EXIT_MODEL_ARRAY;
static int* EXIT_MODEL_COUNT = NUMBER_4_INTEGER_ARRAY;

//
// Communication models.
//

/** The sense model. */
static wchar_t SENSE_MODEL_ARRAY[] = {L's', L'e', L'n', L's', L'e'};
static wchar_t* SENSE_MODEL = SENSE_MODEL_ARRAY;
static int* SENSE_MODEL_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The interrupt model. */
static wchar_t INTERRUPT_MODEL_ARRAY[] = {L'i', L'n', L't', L'e', L'r', L'r', L'u', L'p', L't'};
static wchar_t* INTERRUPT_MODEL = INTERRUPT_MODEL_ARRAY;
static int* INTERRUPT_MODEL_COUNT = NUMBER_9_INTEGER_ARRAY;

/** The receive model. */
static wchar_t RECEIVE_MODEL_ARRAY[] = {L'r', L'e', L'c', L'e', L'i', L'v', L'e'};
static wchar_t* RECEIVE_MODEL = RECEIVE_MODEL_ARRAY;
static int* RECEIVE_MODEL_COUNT = NUMBER_7_INTEGER_ARRAY;

/** The send model. */
static wchar_t SEND_MODEL_ARRAY[] = {L's', L'e', L'n', L'd'};
static wchar_t* SEND_MODEL = SEND_MODEL_ARRAY;
static int* SEND_MODEL_COUNT = NUMBER_4_INTEGER_ARRAY;

//
// Service models.
//

/** The signal model. */
static wchar_t SIGNAL_MODEL_ARRAY[] = {L's', L'i', L'g', L'n', L'a', L'l'};
static wchar_t* SIGNAL_MODEL = SIGNAL_MODEL_ARRAY;
static int* SIGNAL_MODEL_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The shell model. */
static wchar_t SHELL_MODEL_ARRAY[] = {L's', L'h', L'e', L'l', L'l'};
static wchar_t* SHELL_MODEL = SHELL_MODEL_ARRAY;
static int* SHELL_MODEL_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The standard output model. */
static wchar_t STANDARD_OUTPUT_MODEL_ARRAY[] = {L's', L't', L'a', L'n', L'd', L'a', L'r', L'd', L'_', L'o', L'u', L't', L'p', L'u', L't'};
static wchar_t* STANDARD_OUTPUT_MODEL = STANDARD_OUTPUT_MODEL_ARRAY;
static int* STANDARD_OUTPUT_MODEL_COUNT = NUMBER_15_INTEGER_ARRAY;

/** The gnu linux console model. */
static wchar_t GNU_LINUX_CONSOLE_MODEL_ARRAY[] = {L'g', L'n', L'u', L'_', L'l', L'i', L'n', L'u', L'x', L'_', L'c', L'o', L'n', L's', L'o', L'l', L'e'};
static wchar_t* GNU_LINUX_CONSOLE_MODEL = GNU_LINUX_CONSOLE_MODEL_ARRAY;
static int* GNU_LINUX_CONSOLE_MODEL_COUNT = NUMBER_17_INTEGER_ARRAY;

/** The x window system model. */
static wchar_t X_WINDOW_SYSTEM_MODEL_ARRAY[] = {L'x', L'_', L'w', L'i', L'n', L'd', L'o', L'w', L'_', L's', L'y', L's', L't', L'e', L'm'};
static wchar_t* X_WINDOW_SYSTEM_MODEL = X_WINDOW_SYSTEM_MODEL_ARRAY;
static int* X_WINDOW_SYSTEM_MODEL_COUNT = NUMBER_15_INTEGER_ARRAY;

/** The world wide web (www) service model. */
static wchar_t WWW_SERVICE_MODEL_ARRAY[] = {L'w', L'w', L'w'};
static wchar_t* WWW_SERVICE_MODEL = WWW_SERVICE_MODEL_ARRAY;
static int* WWW_SERVICE_MODEL_COUNT = NUMBER_3_INTEGER_ARRAY;

/** The cybernetics oriented interpreter (cyboi) service model. */
static wchar_t CYBOI_SERVICE_MODEL_ARRAY[] = {L'c', L'y', L'b', L'o', L'i'};
static wchar_t* CYBOI_SERVICE_MODEL = CYBOI_SERVICE_MODEL_ARRAY;
static int* CYBOI_SERVICE_MODEL_COUNT = NUMBER_5_INTEGER_ARRAY;

//
// Communication mode models.
//

/** The client communication mode model. */
static wchar_t CLIENT_COMMUNICATION_MODE_MODEL_ARRAY[] = {L'c', L'l', L'i', L'e', L'n', L't'};
static wchar_t* CLIENT_COMMUNICATION_MODE_MODEL = CLIENT_COMMUNICATION_MODE_MODEL_ARRAY;
static int* CLIENT_COMMUNICATION_MODE_MODEL_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The server communication mode model. */
static wchar_t SERVER_COMMUNICATION_MODE_MODEL_ARRAY[] = {L's', L'e', L'r', L'v', L'e', L'r'};
static wchar_t* SERVER_COMMUNICATION_MODE_MODEL = SERVER_COMMUNICATION_MODE_MODEL_ARRAY;
static int* SERVER_COMMUNICATION_MODE_MODEL_COUNT = NUMBER_6_INTEGER_ARRAY;

//
// Namespace models.
//

/** The local namespace model. */
static wchar_t LOCAL_NAMESPACE_MODEL_ARRAY[] = {L'l', L'o', L'c', L'a', L'l'};
static wchar_t* LOCAL_NAMESPACE_MODEL = LOCAL_NAMESPACE_MODEL_ARRAY;
static int* LOCAL_NAMESPACE_MODEL_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The internet protocol version 4 (ipv4) namespace model. */
static wchar_t INET_NAMESPACE_MODEL_ARRAY[] = {L'i', L'p', L'v', L'4'};
static wchar_t* INET_NAMESPACE_MODEL = INET_NAMESPACE_MODEL_ARRAY;
static int* INET_NAMESPACE_MODEL_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The internet protocol version 6 (ipv6) namespace model. */
static wchar_t INET6_NAMESPACE_MODEL_ARRAY[] = {L'i', L'p', L'v', L'6'};
static wchar_t* INET6_NAMESPACE_MODEL = INET6_NAMESPACE_MODEL_ARRAY;
static int* INET6_NAMESPACE_MODEL_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The xerox network software protocols namespace model. */
static wchar_t NS_NAMESPACE_MODEL_ARRAY[] = {L'n', L's'};
static wchar_t* NS_NAMESPACE_MODEL = NS_NAMESPACE_MODEL_ARRAY;
static int* NS_NAMESPACE_MODEL_COUNT = NUMBER_2_INTEGER_ARRAY;

/** The open systems interconnect (osi) namespace model. */
static wchar_t ISO_NAMESPACE_MODEL_ARRAY[] = {L'i', L's', L'o'};
static wchar_t* ISO_NAMESPACE_MODEL = ISO_NAMESPACE_MODEL_ARRAY;
static int* ISO_NAMESPACE_MODEL_COUNT = NUMBER_3_INTEGER_ARRAY;

/** The ccitt namespace model. */
static wchar_t CCITT_NAMESPACE_MODEL_ARRAY[] = {L'c', L'c', L'i', L't', L't'};
static wchar_t* CCITT_NAMESPACE_MODEL = CCITT_NAMESPACE_MODEL_ARRAY;
static int* CCITT_NAMESPACE_MODEL_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The internet message processor namespace model. */
static wchar_t IMPLINK_NAMESPACE_MODEL_ARRAY[] = {L'i', L'm', L'p', L'l', L'i', L'n', L'k'};
static wchar_t* IMPLINK_NAMESPACE_MODEL = IMPLINK_NAMESPACE_MODEL_ARRAY;
static int* IMPLINK_NAMESPACE_MODEL_COUNT = NUMBER_7_INTEGER_ARRAY;

/** The local area routing protocol namespace model. */
static wchar_t ROUTE_NAMESPACE_MODEL_ARRAY[] = {L'r', L'o', L'u', L't', L'e'};
static wchar_t* ROUTE_NAMESPACE_MODEL = ROUTE_NAMESPACE_MODEL_ARRAY;
static int* ROUTE_NAMESPACE_MODEL_COUNT = NUMBER_5_INTEGER_ARRAY;

//
// Communication style models.
//

/** The stream communication style model. */
static wchar_t STREAM_COMMUNICATION_STYLE_MODEL_ARRAY[] = {L's', L't', L'r', L'e', L'a', L'm'};
static wchar_t* STREAM_COMMUNICATION_STYLE_MODEL = STREAM_COMMUNICATION_STYLE_MODEL_ARRAY;
static int* STREAM_COMMUNICATION_STYLE_MODEL_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The datagram communication style model. */
static wchar_t DATAGRAM_COMMUNICATION_STYLE_MODEL_ARRAY[] = {L'd', L'a', L't', L'a', L'g', L'r', L'a', L'm'};
static wchar_t* DATAGRAM_COMMUNICATION_STYLE_MODEL = DATAGRAM_COMMUNICATION_STYLE_MODEL_ARRAY;
static int* DATAGRAM_COMMUNICATION_STYLE_MODEL_COUNT = NUMBER_8_INTEGER_ARRAY;

/** The raw communication style model. */
static wchar_t RAW_COMMUNICATION_STYLE_MODEL_ARRAY[] = {L'r', L'a', L'w'};
static wchar_t* RAW_COMMUNICATION_STYLE_MODEL = RAW_COMMUNICATION_STYLE_MODEL_ARRAY;
static int* RAW_COMMUNICATION_STYLE_MODEL_COUNT = NUMBER_3_INTEGER_ARRAY;

//
// Address models.
//

/** The loopback address model. */
static wchar_t LOOPBACK_ADDRESS_MODEL_ARRAY[] = {L'l', L'o', L'o', L'p', L'b', L'a', L'c', L'k'};
static wchar_t* LOOPBACK_ADDRESS_MODEL = LOOPBACK_ADDRESS_MODEL_ARRAY;
static int* LOOPBACK_ADDRESS_MODEL_COUNT = NUMBER_8_INTEGER_ARRAY;

/** The any address model. */
static wchar_t ANY_ADDRESS_MODEL_ARRAY[] = {L'a', L'n', L'y'};
static wchar_t* ANY_ADDRESS_MODEL = ANY_ADDRESS_MODEL_ARRAY;
static int* ANY_ADDRESS_MODEL_COUNT = NUMBER_3_INTEGER_ARRAY;

//
// Protocol models.
//

/** The common object request broker architecture (corba) model. */
static wchar_t CORBA_MODEL_ARRAY[] = {L'c', L'o', L'r', L'b', L'a'};
static wchar_t* CORBA_MODEL = CORBA_MODEL_ARRAY;
static int* CORBA_MODEL_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The file system model. */
static wchar_t FILE_SYSTEM_MODEL_ARRAY[] = {L'f', L'i', L'l', L'e'};
static wchar_t* FILE_SYSTEM_MODEL = FILE_SYSTEM_MODEL_ARRAY;
static int* FILE_SYSTEM_MODEL_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The floppy model. */
static wchar_t FLOPPY_MODEL_ARRAY[] = {L'f', L'l', L'o', L'p', L'p', L'y'};
static wchar_t* FLOPPY_MODEL = FLOPPY_MODEL_ARRAY;
static int* FLOPPY_MODEL_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The imap model. */
static wchar_t IMAP_MODEL_ARRAY[] = {L'i', L'm', L'a', L'p'};
static wchar_t* IMAP_MODEL = IMAP_MODEL_ARRAY;
static int* IMAP_MODEL_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The imaps model. */
static wchar_t IMAPS_MODEL_ARRAY[] = {L'i', L'm', L'a', L'p', L's'};
static wchar_t* IMAPS_MODEL = IMAPS_MODEL_ARRAY;
static int* IMAPS_MODEL_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The java messaging service (jms) model. */
static wchar_t JMS_MODEL_ARRAY[] = {L'j', L'm', L's'};
static wchar_t* JMS_MODEL = JMS_MODEL_ARRAY;
static int* JMS_MODEL_COUNT = NUMBER_3_INTEGER_ARRAY;

/** The latex model. */
static wchar_t LATEX_MODEL_ARRAY[] = {L'l', L'a', L't', L'e', L'x'};
static wchar_t* LATEX_MODEL = LATEX_MODEL_ARRAY;
static int* LATEX_MODEL_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The ldap model. */
static wchar_t LDAP_MODEL_ARRAY[] = {L'l', L'd', L'a', L'p'};
static wchar_t* LDAP_MODEL = LDAP_MODEL_ARRAY;
static int* LDAP_MODEL_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The nfs model. */
static wchar_t NFS_MODEL_ARRAY[] = {L'n', L'f', L's'};
static wchar_t* NFS_MODEL = NFS_MODEL_ARRAY;
static int* NFS_MODEL_COUNT = NUMBER_3_INTEGER_ARRAY;

/** The nntp model. */
static wchar_t NNTP_MODEL_ARRAY[] = {L'n', L'n', L't', L'p'};
static wchar_t* NNTP_MODEL = NNTP_MODEL_ARRAY;
static int* NNTP_MODEL_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The remote method invocation (rmi) model. */
static wchar_t RMI_MODEL_ARRAY[] = {L'r', L'm', L'i'};
static wchar_t* RMI_MODEL = RMI_MODEL_ARRAY;
static int* RMI_MODEL_COUNT = NUMBER_3_INTEGER_ARRAY;

/** The simple object access protocol (soap) model. */
static wchar_t SOAP_MODEL_ARRAY[] = {L's', L'o', L'a', L'p'};
static wchar_t* SOAP_MODEL = SOAP_MODEL_ARRAY;
static int* SOAP_MODEL_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The smb model. */
static wchar_t SMB_MODEL_ARRAY[] = {L's', L'm', L'b'};
static wchar_t* SMB_MODEL = SMB_MODEL_ARRAY;
static int* SMB_MODEL_COUNT = NUMBER_3_INTEGER_ARRAY;

/** The smtp model. */
static wchar_t SMTP_MODEL_ARRAY[] = {L's', L'm', L't', L'p'};
static wchar_t* SMTP_MODEL = SMTP_MODEL_ARRAY;
static int* SMTP_MODEL_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The smtps model. */
static wchar_t SMTPS_MODEL_ARRAY[] = {L's', L'm', L't', L'p', L's'};
static wchar_t* SMTPS_MODEL = SMTPS_MODEL_ARRAY;
static int* SMTPS_MODEL_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The structured query language (sql). */
static wchar_t SQL_MODEL_ARRAY[] = {L's', L'q', L'l'};
static wchar_t* SQL_MODEL = SQL_MODEL_ARRAY;
static int* SQL_MODEL_COUNT = NUMBER_3_INTEGER_ARRAY;

//
// Shape models.
//

/** The rectangle shape model. */
static wchar_t UI_RECTANGLE_SHAPE_MODEL_ARRAY[] = {L'r', L'e', L'c', L't', L'a', L'n', L'g', L'l', L'e'};
static wchar_t* UI_RECTANGLE_SHAPE_MODEL = UI_RECTANGLE_SHAPE_MODEL_ARRAY;
static int* UI_RECTANGLE_SHAPE_MODEL_COUNT = NUMBER_9_INTEGER_ARRAY;

/** The circle shape model. */
static wchar_t UI_CIRCLE_SHAPE_MODEL_ARRAY[] = {L'c', L'i', L'r', L'c', L'l', L'e'};
static wchar_t* UI_CIRCLE_SHAPE_MODEL = UI_CIRCLE_SHAPE_MODEL_ARRAY;
static int* UI_CIRCLE_SHAPE_MODEL_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The polygon shape model. */
static wchar_t UI_POLYGON_SHAPE_MODEL_ARRAY[] = {L'p', L'o', L'l', L'y', L'g', L'o', L'n'};
static wchar_t* UI_POLYGON_SHAPE_MODEL = UI_POLYGON_SHAPE_MODEL_ARRAY;
static int* UI_POLYGON_SHAPE_MODEL_COUNT = NUMBER_7_INTEGER_ARRAY;

//
// Layout models.
//

/** The root layout model. */
static wchar_t UI_ROOT_LAYOUT_MODEL_ARRAY[] = {L'r', L'o', L'o', L't'};
static wchar_t* UI_ROOT_LAYOUT_MODEL = UI_ROOT_LAYOUT_MODEL_ARRAY;
static int* UI_ROOT_LAYOUT_MODEL_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The coordinates layout model. */
static wchar_t UI_COORDINATES_LAYOUT_MODEL_ARRAY[] = {L'c', L'o', L'o', L'r', L'd', L'i', L'n', L'a', L't', L'e', L's'};
static wchar_t* UI_COORDINATES_LAYOUT_MODEL = UI_COORDINATES_LAYOUT_MODEL_ARRAY;
static int* UI_COORDINATES_LAYOUT_MODEL_COUNT = NUMBER_11_INTEGER_ARRAY;

/** The compass layout model. */
static wchar_t UI_COMPASS_LAYOUT_MODEL_ARRAY[] = {L'c', L'o', L'm', L'p', L'a', L's', L's'};
static wchar_t* UI_COMPASS_LAYOUT_MODEL = UI_COMPASS_LAYOUT_MODEL_ARRAY;
static int* UI_COMPASS_LAYOUT_MODEL_COUNT = NUMBER_7_INTEGER_ARRAY;

//
// Compass layout cell models.
//

/** The compass layout north cell model. */
static wchar_t UI_NORTH_CELL_MODEL_ARRAY[] = {L'n', L'o', L'r', L't', L'h'};
static wchar_t* UI_NORTH_CELL_MODEL = UI_NORTH_CELL_MODEL_ARRAY;
static int* UI_NORTH_CELL_MODEL_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The compass layout south cell model. */
static wchar_t UI_SOUTH_CELL_MODEL_ARRAY[] = {L's', L'o', L'u', L't', L'h'};
static wchar_t* UI_SOUTH_CELL_MODEL = UI_SOUTH_CELL_MODEL_ARRAY;
static int* UI_SOUTH_CELL_MODEL_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The compass layout west cell model. */
static wchar_t UI_WEST_CELL_MODEL_ARRAY[] = {L'w', L'e', L's', L't'};
static wchar_t* UI_WEST_CELL_MODEL = UI_WEST_CELL_MODEL_ARRAY;
static int* UI_WEST_CELL_MODEL_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The compass layout east cell model. */
static wchar_t UI_EAST_CELL_MODEL_ARRAY[] = {L'e', L'a', L's', L't'};
static wchar_t* UI_EAST_CELL_MODEL = UI_EAST_CELL_MODEL_ARRAY;
static int* UI_EAST_CELL_MODEL_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The compass layout centre cell model. */
static wchar_t UI_CENTRE_CELL_MODEL_ARRAY[] = {L'c', L'e', L'n', L't', L'r', L'e'};
static wchar_t* UI_CENTRE_CELL_MODEL = UI_CENTRE_CELL_MODEL_ARRAY;
static int* UI_CENTRE_CELL_MODEL_COUNT = NUMBER_6_INTEGER_ARRAY;

//
// Border models.
//

/** The line border model. */
static wchar_t TUI_LINE_BORDER_MODEL_ARRAY[] = {L'l', L'i', L'n', L'e'};
static wchar_t* TUI_LINE_BORDER_MODEL = TUI_LINE_BORDER_MODEL_ARRAY;
static int* TUI_LINE_BORDER_MODEL_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The round line border model. */
static wchar_t TUI_ROUND_LINE_BORDER_MODEL_ARRAY[] = {L'r', L'o', L'u', L'n', L'd'};
static wchar_t* TUI_ROUND_LINE_BORDER_MODEL = TUI_ROUND_LINE_BORDER_MODEL_ARRAY;
static int* TUI_ROUND_LINE_BORDER_MODEL_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The double line border model. */
static wchar_t TUI_DOUBLE_LINE_BORDER_MODEL_ARRAY[] = {L'd', L'o', L'u', L'b', L'l', L'e'};
static wchar_t* TUI_DOUBLE_LINE_BORDER_MODEL = TUI_DOUBLE_LINE_BORDER_MODEL_ARRAY;
static int* TUI_DOUBLE_LINE_BORDER_MODEL_COUNT = NUMBER_6_INTEGER_ARRAY;

//
// Run models.
//

/** The run model. */
static wchar_t RUN_MODEL_ARRAY[] = {L'r', L'u', L'n'};
static wchar_t* RUN_MODEL = RUN_MODEL_ARRAY;
static int* RUN_MODEL_COUNT = NUMBER_3_INTEGER_ARRAY;

/** The run archive model. */
static wchar_t RUN_ARCHIVE_MODEL_ARRAY[] = {L'a', L'r', L'c', L'h', L'i', L'v', L'e'};
static wchar_t* RUN_ARCHIVE_MODEL = RUN_ARCHIVE_MODEL_ARRAY;
static int* RUN_ARCHIVE_MODEL_COUNT = NUMBER_7_INTEGER_ARRAY;

/** The run copy model. */
static wchar_t RUN_COPY_MODEL_ARRAY[] = {L'c', L'o', L'p', L'y'};
static wchar_t* RUN_COPY_MODEL = RUN_COPY_MODEL_ARRAY;
static int* RUN_COPY_MODEL_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The list directory contents model. */
static wchar_t RUN_LIST_DIRECTORY_CONTENTS_MODEL_ARRAY[] = {L'l', L'i', L's', L't', L'_', L'd', L'i', L'r', L'e', L'c', L't', L'o', L'r', L'y', L'_', L'c', L'o', L'n', L't', L'e', L'n', L't', L's'};
static wchar_t* RUN_LIST_DIRECTORY_CONTENTS_MODEL = RUN_LIST_DIRECTORY_CONTENTS_MODEL_ARRAY;
static int* RUN_LIST_DIRECTORY_CONTENTS_MODEL_COUNT = NUMBER_23_INTEGER_ARRAY;

/** The run program model. */
static wchar_t RUN_PROGRAM_MODEL_ARRAY[] = {L'p', L'r', L'o', L'g', L'r', L'a', L'm'};
static wchar_t* RUN_PROGRAM_MODEL = RUN_PROGRAM_MODEL_ARRAY;
static int* RUN_PROGRAM_MODEL_COUNT = NUMBER_7_INTEGER_ARRAY;

//
// Http request method models.
//

/** The http get request method model. */
static wchar_t HTTP_GET_REQUEST_METHOD_MODEL_ARRAY[] = {L'g', L'e', L't'};
static wchar_t* HTTP_GET_REQUEST_METHOD_MODEL = HTTP_GET_REQUEST_METHOD_MODEL_ARRAY;
static int* HTTP_GET_REQUEST_METHOD_MODEL_COUNT = NUMBER_3_INTEGER_ARRAY;

/** The http post request method model. */
static wchar_t HTTP_POST_REQUEST_METHOD_MODEL_ARRAY[] = {L'p', L'o', L's', L't'};
static wchar_t* HTTP_POST_REQUEST_METHOD_MODEL = HTTP_POST_REQUEST_METHOD_MODEL_ARRAY;
static int* HTTP_POST_REQUEST_METHOD_MODEL_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The http head request method model. */
static wchar_t HTTP_HEAD_REQUEST_METHOD_MODEL_ARRAY[] = {L'h', L'e', L'a', L'd'};
static wchar_t* HTTP_HEAD_REQUEST_METHOD_MODEL = HTTP_HEAD_REQUEST_METHOD_MODEL_ARRAY;
static int* HTTP_HEAD_REQUEST_METHOD_MODEL_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The http put request method model. */
static wchar_t HTTP_PUT_REQUEST_METHOD_MODEL_ARRAY[] = {L'p', L'u', L't'};
static wchar_t* HTTP_PUT_REQUEST_METHOD_MODEL = HTTP_PUT_REQUEST_METHOD_MODEL_ARRAY;
static int* HTTP_PUT_REQUEST_METHOD_MODEL_COUNT = NUMBER_3_INTEGER_ARRAY;

/** The http delete request method model. */
static wchar_t HTTP_DELETE_REQUEST_METHOD_MODEL_ARRAY[] = {L'd', L'e', L'l', L'e', L't', L'e'};
static wchar_t* HTTP_DELETE_REQUEST_METHOD_MODEL = HTTP_DELETE_REQUEST_METHOD_MODEL_ARRAY;
static int* HTTP_DELETE_REQUEST_METHOD_MODEL_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The http trace request method model. */
static wchar_t HTTP_TRACE_REQUEST_METHOD_MODEL_ARRAY[] = {L't', L'r', L'a', L'c', L'e'};
static wchar_t* HTTP_TRACE_REQUEST_METHOD_MODEL = HTTP_TRACE_REQUEST_METHOD_MODEL_ARRAY;
static int* HTTP_TRACE_REQUEST_METHOD_MODEL_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The http options request method model. */
static wchar_t HTTP_OPTIONS_REQUEST_METHOD_MODEL_ARRAY[] = {L'o', L'p', L't', L'i', L'o', L'n', L's'};
static wchar_t* HTTP_OPTIONS_REQUEST_METHOD_MODEL = HTTP_OPTIONS_REQUEST_METHOD_MODEL_ARRAY;
static int* HTTP_OPTIONS_REQUEST_METHOD_MODEL_COUNT = NUMBER_7_INTEGER_ARRAY;

/** The http connect request method model. */
static wchar_t HTTP_CONNECT_REQUEST_METHOD_MODEL_ARRAY[] = {L'c', L'o', L'n', L'n', L'e', L'c', L't'};
static wchar_t* HTTP_CONNECT_REQUEST_METHOD_MODEL = HTTP_CONNECT_REQUEST_METHOD_MODEL_ARRAY;
static int* HTTP_CONNECT_REQUEST_METHOD_MODEL_COUNT = NUMBER_7_INTEGER_ARRAY;

/** The webdav propfind request method model. */
static wchar_t WEBDAV_PROPFIND_REQUEST_METHOD_MODEL_ARRAY[] = {L'p', L'r', L'o', L'p', L'f', L'i', L'n', L'd'};
static wchar_t* WEBDAV_PROPFIND_REQUEST_METHOD_MODEL = WEBDAV_PROPFIND_REQUEST_METHOD_MODEL_ARRAY;
static int* WEBDAV_PROPFIND_REQUEST_METHOD_MODEL_COUNT = NUMBER_8_INTEGER_ARRAY;

/** The webdav proppatch request method model. */
static wchar_t WEBDAV_PROPPATCH_REQUEST_METHOD_MODEL_ARRAY[] = {L'p', L'r', L'o', L'p', L'p', L'a', L't', L'c', L'h'};
static wchar_t* WEBDAV_PROPPATCH_REQUEST_METHOD_MODEL = WEBDAV_PROPPATCH_REQUEST_METHOD_MODEL_ARRAY;
static int* WEBDAV_PROPPATCH_REQUEST_METHOD_MODEL_COUNT = NUMBER_9_INTEGER_ARRAY;

/** The webdav mkcol request method model. */
static wchar_t WEBDAV_MKCOL_REQUEST_METHOD_MODEL_ARRAY[] = {L'm', L'k', L'c', L'o', L'l'};
static wchar_t* WEBDAV_MKCOL_REQUEST_METHOD_MODEL = WEBDAV_MKCOL_REQUEST_METHOD_MODEL_ARRAY;
static int* WEBDAV_MKCOL_REQUEST_METHOD_MODEL_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The webdav copy request method model. */
static wchar_t WEBDAV_COPY_REQUEST_METHOD_MODEL_ARRAY[] = {L'c', L'o', L'p', L'y'};
static wchar_t* WEBDAV_COPY_REQUEST_METHOD_MODEL = WEBDAV_COPY_REQUEST_METHOD_MODEL_ARRAY;
static int* WEBDAV_COPY_REQUEST_METHOD_MODEL_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The webdav move request method model. */
static wchar_t WEBDAV_MOVE_REQUEST_METHOD_MODEL_ARRAY[] = {L'm', L'o', L'v', L'e'};
static wchar_t* WEBDAV_MOVE_REQUEST_METHOD_MODEL = WEBDAV_MOVE_REQUEST_METHOD_MODEL_ARRAY;
static int* WEBDAV_MOVE_REQUEST_METHOD_MODEL_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The webdav lock request method model. */
static wchar_t WEBDAV_LOCK_REQUEST_METHOD_MODEL_ARRAY[] = {L'l', L'o', L'c', L'k'};
static wchar_t* WEBDAV_LOCK_REQUEST_METHOD_MODEL = WEBDAV_LOCK_REQUEST_METHOD_MODEL_ARRAY;
static int* WEBDAV_LOCK_REQUEST_METHOD_MODEL_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The webdav unlock request method model. */
static wchar_t WEBDAV_UNLOCK_REQUEST_METHOD_MODEL_ARRAY[] = {L'u', L'n', L'l', L'o', L'c', L'k'};
static wchar_t* WEBDAV_UNLOCK_REQUEST_METHOD_MODEL = WEBDAV_UNLOCK_REQUEST_METHOD_MODEL_ARRAY;
static int* WEBDAV_UNLOCK_REQUEST_METHOD_MODEL_COUNT = NUMBER_6_INTEGER_ARRAY;

/* CYBOL_MODEL_CONSTANTS_SOURCE */
#endif
