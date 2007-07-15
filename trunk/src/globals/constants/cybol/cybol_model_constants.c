/*
 * $RCSfile: cybol_model_constants.c,v $
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
 * @version $Revision: 1.5 $ $Date: 2007-06-29 22:55:31 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CYBOL_MODEL_CONSTANTS_SOURCE
#define CYBOL_MODEL_CONSTANTS_SOURCE

#include "../../../globals/constants/integer/integer_constants.c"

//
// Special models.
//

/** The empty model. */
static char EMPTY_MODEL_ARRAY[] = {};
static char* EMPTY_MODEL = EMPTY_MODEL_ARRAY;
static int* EMPTY_MODEL_COUNT = NUMBER_0_INTEGER_ARRAY;

//
// Boolean models.
//

/** The false model. */
static char FALSE_MODEL_ARRAY[] = {'f', 'a', 'l', 's', 'e'};
static char* FALSE_MODEL = FALSE_MODEL_ARRAY;
static int* FALSE_MODEL_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The true model. */
static char TRUE_MODEL_ARRAY[] = {'t', 'r', 'u', 'e'};
static char* TRUE_MODEL = TRUE_MODEL_ARRAY;
static int* TRUE_MODEL_COUNT = NUMBER_4_INTEGER_ARRAY;

//
// Terminal colour models.
//

/** The black model. */
static char TERMINAL_COLOUR_BLACK_MODEL_ARRAY[] = {'b', 'l', 'a', 'c', 'k'};
static char* TERMINAL_COLOUR_BLACK_MODEL = TERMINAL_COLOUR_BLACK_MODEL_ARRAY;
static int* TERMINAL_COLOUR_BLACK_MODEL_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The red model. */
static char TERMINAL_COLOUR_RED_MODEL_ARRAY[] = {'r', 'e', 'd'};
static char* TERMINAL_COLOUR_RED_MODEL = TERMINAL_COLOUR_RED_MODEL_ARRAY;
static int* TERMINAL_COLOUR_RED_MODEL_COUNT = NUMBER_3_INTEGER_ARRAY;

/** The green model. */
static char TERMINAL_COLOUR_GREEN_MODEL_ARRAY[] = {'g', 'r', 'e', 'e', 'n'};
static char* TERMINAL_COLOUR_GREEN_MODEL = TERMINAL_COLOUR_GREEN_MODEL_ARRAY;
static int* TERMINAL_COLOUR_GREEN_MODEL_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The yellow model. */
static char TERMINAL_COLOUR_YELLOW_MODEL_ARRAY[] = {'y', 'e', 'l', 'l', 'o', 'w'};
static char* TERMINAL_COLOUR_YELLOW_MODEL = TERMINAL_COLOUR_YELLOW_MODEL_ARRAY;
static int* TERMINAL_COLOUR_YELLOW_MODEL_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The blue model. */
static char TERMINAL_COLOUR_BLUE_MODEL_ARRAY[] = {'b', 'l', 'u', 'e'};
static char* TERMINAL_COLOUR_BLUE_MODEL = TERMINAL_COLOUR_BLUE_MODEL_ARRAY;
static int* TERMINAL_COLOUR_BLUE_MODEL_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The magenta (violet, purple, mauve) model. */
static char TERMINAL_COLOUR_MAGENTA_MODEL_ARRAY[] = {'m', 'a', 'g', 'e', 'n', 't', 'a'};
static char* TERMINAL_COLOUR_MAGENTA_MODEL = TERMINAL_COLOUR_MAGENTA_MODEL_ARRAY;
static int* TERMINAL_COLOUR_MAGENTA_MODEL_COUNT = NUMBER_7_INTEGER_ARRAY;

/** The cobalt blue (china blue) model. */
static char TERMINAL_COLOUR_COBALT_MODEL_ARRAY[] = {'c', 'o', 'b', 'a', 'l', 't'};
static char* TERMINAL_COLOUR_COBALT_MODEL = TERMINAL_COLOUR_COBALT_MODEL_ARRAY;
static int* TERMINAL_COLOUR_COBALT_MODEL_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The white model. */
static char TERMINAL_COLOUR_WHITE_MODEL_ARRAY[] = {'w', 'h', 'i', 't', 'e'};
static char* TERMINAL_COLOUR_WHITE_MODEL = TERMINAL_COLOUR_WHITE_MODEL_ARRAY;
static int* TERMINAL_COLOUR_WHITE_MODEL_COUNT = NUMBER_5_INTEGER_ARRAY;

//
// Data transfer models.
//

/** The copy (set, assign) model. */
static char COPY_MODEL_ARRAY[] = {'c', 'o', 'p', 'y'};
static char* COPY_MODEL = COPY_MODEL_ARRAY;
static int* COPY_MODEL_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The move model. */
static char MOVE_MODEL_ARRAY[] = {'m', 'o', 'v', 'e'};
static char* MOVE_MODEL = MOVE_MODEL_ARRAY;
static int* MOVE_MODEL_COUNT = NUMBER_4_INTEGER_ARRAY;

//
// Program flow models.
//

/** The branch model. */
static char BRANCH_MODEL_ARRAY[] = {'b', 'r', 'a', 'n', 'c', 'h'};
static char* BRANCH_MODEL = BRANCH_MODEL_ARRAY;
static int* BRANCH_MODEL_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The loop model. */
static char LOOP_MODEL_ARRAY[] = {'l', 'o', 'o', 'p'};
static char* LOOP_MODEL = LOOP_MODEL_ARRAY;
static int* LOOP_MODEL_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The count model. */
static char COUNT_MODEL_ARRAY[] = {'c', 'o', 'u', 'n', 't'};
static char* COUNT_MODEL = COUNT_MODEL_ARRAY;
static int* COUNT_MODEL_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The build listname model. */
static char BUILD_LISTNAME_MODEL_ARRAY[] = {'b', 'u', 'i', 'l', 'd', '_', 'l', 'i', 's', 't', 'n', 'a', 'm', 'e'};
static char* BUILD_LISTNAME_MODEL = BUILD_LISTNAME_MODEL_ARRAY;
static int* BUILD_LISTNAME_MODEL_COUNT = NUMBER_14_INTEGER_ARRAY;

/** The get model. */
static char GET_MODEL_ARRAY[] = {'g', 'e', 't'};
static char* GET_MODEL = GET_MODEL_ARRAY;
static int* GET_MODEL_COUNT = NUMBER_3_INTEGER_ARRAY;

//
// Count selection models.
//

/** The count all selection model. */
static char COUNT_ALL_SELECTION_MODEL_ARRAY[] = {'a', 'l', 'l'};
static char* COUNT_ALL_SELECTION_MODEL = COUNT_ALL_SELECTION_MODEL_ARRAY;
static int* COUNT_ALL_SELECTION_MODEL_COUNT = NUMBER_3_INTEGER_ARRAY;

/** The count prefix selection model. */
static char COUNT_PREFIX_SELECTION_MODEL_ARRAY[] = {'p', 'r', 'e', 'f', 'i', 'x'};
static char* COUNT_PREFIX_SELECTION_MODEL = COUNT_PREFIX_SELECTION_MODEL_ARRAY;
static int* COUNT_PREFIX_SELECTION_MODEL_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The count suffix selection model. */
static char COUNT_SUFFIX_SELECTION_MODEL_ARRAY[] = {'s', 'u', 'f', 'f', 'i', 'x'};
static char* COUNT_SUFFIX_SELECTION_MODEL = COUNT_SUFFIX_SELECTION_MODEL_ARRAY;
static int* COUNT_SUFFIX_SELECTION_MODEL_COUNT = NUMBER_6_INTEGER_ARRAY;

//
// Get description models.
//

/** The get name description model. */
static char GET_NAME_DESCRIPTION_MODEL_ARRAY[] = {'n', 'a', 'm', 'e'};
static char* GET_NAME_DESCRIPTION_MODEL = GET_NAME_DESCRIPTION_MODEL_ARRAY;
static int* GET_NAME_DESCRIPTION_MODEL_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The get abstraction description model. */
static char GET_ABSTRACTION_DESCRIPTION_MODEL_ARRAY[] = {'a', 'b', 's', 't', 'r', 'a', 'c', 't', 'i', 'o', 'n'};
static char* GET_ABSTRACTION_DESCRIPTION_MODEL = GET_ABSTRACTION_DESCRIPTION_MODEL_ARRAY;
static int* GET_ABSTRACTION_DESCRIPTION_MODEL_COUNT = NUMBER_11_INTEGER_ARRAY;

//
// Boolean logic models.
//

/** The not model. This is the ones complement (all bits negated). */
static char NOT_MODEL_ARRAY[] = {'n', 'o', 't'};
static char* NOT_MODEL = NOT_MODEL_ARRAY;
static int* NOT_MODEL_COUNT = NUMBER_3_INTEGER_ARRAY;

/** The neg model. This is the two's complement (all bits negated and added one). */
static char NEG_MODEL_ARRAY[] = {'n', 'e', 'g'};
static char* NEG_MODEL = NEG_MODEL_ARRAY;
static int* NEG_MODEL_COUNT = NUMBER_3_INTEGER_ARRAY;

/** The and model. */
static char AND_MODEL_ARRAY[] = {'a', 'n', 'd'};
static char* AND_MODEL = AND_MODEL_ARRAY;
static int* AND_MODEL_COUNT = NUMBER_3_INTEGER_ARRAY;

/** The or model. */
static char OR_MODEL_ARRAY[] = {'o', 'r'};
static char* OR_MODEL = OR_MODEL_ARRAY;
static int* OR_MODEL_COUNT = NUMBER_2_INTEGER_ARRAY;

/** The xor model. */
static char XOR_MODEL_ARRAY[] = {'x', 'o', 'r'};
static char* XOR_MODEL = XOR_MODEL_ARRAY;
static int* XOR_MODEL_COUNT = NUMBER_3_INTEGER_ARRAY;

//
// Bit manipulation models.
//

/** The shift left model. It corresponds to "SHL" assembler command. */
static char SHIFT_LEFT_MODEL_ARRAY[] = {'s', 'h', 'i', 'f', 't', '_', 'l', 'e', 'f', 't'};
static char* SHIFT_LEFT_MODEL = SHIFT_LEFT_MODEL_ARRAY;
static int* SHIFT_LEFT_MODEL_COUNT = NUMBER_10_INTEGER_ARRAY;

/** The shift right model. It corresponds to "SHR" assembler command. */
static char SHIFT_RIGHT_MODEL_ARRAY[] = {'s', 'h', 'i', 'f', 't', '_', 'r', 'i', 'g', 'h', 't'};
static char* SHIFT_RIGHT_MODEL = SHIFT_RIGHT_MODEL_ARRAY;
static int* SHIFT_RIGHT_MODEL_COUNT = NUMBER_11_INTEGER_ARRAY;

/** The rotate left model. It corresponds to "ROL" assembler command. */
static char ROTATE_LEFT_MODEL_ARRAY[] = {'r', 'o', 't', 'a', 't', 'e', '_', 'l', 'e', 'f', 't'};
static char* ROTATE_LEFT_MODEL = ROTATE_LEFT_MODEL_ARRAY;
static int* ROTATE_LEFT_MODEL_COUNT = NUMBER_11_INTEGER_ARRAY;

/** The rotate right model. It corresponds to "ROR" assembler command. */
static char ROTATE_RIGHT_MODEL_ARRAY[] = {'r', 'o', 't', 'a', 't', 'e', '_', 'r', 'i', 'g', 'h', 't'};
static char* ROTATE_RIGHT_MODEL = ROTATE_RIGHT_MODEL_ARRAY;
static int* ROTATE_RIGHT_MODEL_COUNT = NUMBER_12_INTEGER_ARRAY;

/** The set bit model. It corresponds to "BTS" assembler command. */
static char SET_BIT_MODEL_ARRAY[] = {'s', 'e', 't', '_', 'b', 'i', 't'};
static char* SET_BIT_MODEL = SET_BIT_MODEL_ARRAY;
static int* SET_BIT_MODEL_COUNT = NUMBER_7_INTEGER_ARRAY;

/** The reset bit model. It corresponds to "BTR" assembler command. */
static char RESET_BIT_MODEL_ARRAY[] = {'r', 'e', 's', 'e', 't', '_', 'b', 'i', 't'};
static char* RESET_BIT_MODEL = RESET_BIT_MODEL_ARRAY;
static int* RESET_BIT_MODEL_COUNT = NUMBER_9_INTEGER_ARRAY;

/** The get bit model. It corresponds to "BT" assembler command. */
static char GET_BIT_MODEL_ARRAY[] = {'g', 'e', 't', '_', 'b', 'i', 't'};
static char* GET_BIT_MODEL = GET_BIT_MODEL_ARRAY;
static int* GET_BIT_MODEL_COUNT = NUMBER_7_INTEGER_ARRAY;

//
// Comparison models.
//

/** The compare model. */
static char COMPARE_MODEL_ARRAY[] = {'c', 'o', 'm', 'p', 'a', 'r', 'e'};
static char* COMPARE_MODEL = COMPARE_MODEL_ARRAY;
static int* COMPARE_MODEL_COUNT = NUMBER_7_INTEGER_ARRAY;

/** The equal model. */
static char EQUAL_MODEL_ARRAY[] = {'e', 'q', 'u', 'a', 'l'};
static char* EQUAL_MODEL = EQUAL_MODEL_ARRAY;
static int* EQUAL_MODEL_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The smaller model. */
static char SMALLER_MODEL_ARRAY[] = {'s', 'm', 'a', 'l', 'l', 'e', 'r'};
static char* SMALLER_MODEL = SMALLER_MODEL_ARRAY;
static int* SMALLER_MODEL_COUNT = NUMBER_7_INTEGER_ARRAY;

/** The greater model. */
static char GREATER_MODEL_ARRAY[] = {'g', 'r', 'e', 'a', 't', 'e', 'r'};
static char* GREATER_MODEL = GREATER_MODEL_ARRAY;
static int* GREATER_MODEL_COUNT = NUMBER_7_INTEGER_ARRAY;

/** The smaller or equal model. */
static char SMALLER_OR_EQUAL_MODEL_ARRAY[] = {'s', 'm', 'a', 'l', 'l', 'e', 'r', '_', 'o', 'r', '_', 'e', 'q', 'u', 'a', 'l'};
static char* SMALLER_OR_EQUAL_MODEL = SMALLER_OR_EQUAL_MODEL_ARRAY;
static int* SMALLER_OR_EQUAL_MODEL_COUNT = NUMBER_16_INTEGER_ARRAY;

/** The greater or equal model. */
static char GREATER_OR_EQUAL_MODEL_ARRAY[] = {'g', 'r', 'e', 'a', 't', 'e', 'r', '_', 'o', 'r', '_', 'e', 'q', 'u', 'a', 'l'};
static char* GREATER_OR_EQUAL_MODEL = GREATER_OR_EQUAL_MODEL_ARRAY;
static int* GREATER_OR_EQUAL_MODEL_COUNT = NUMBER_16_INTEGER_ARRAY;

//
// Comparison selection models.
//

/** The compare all selection model. */
static char COMPARE_ALL_SELECTION_MODEL_ARRAY[] = {'a', 'l', 'l'};
static char* COMPARE_ALL_SELECTION_MODEL = COMPARE_ALL_SELECTION_MODEL_ARRAY;
static int* COMPARE_ALL_SELECTION_MODEL_COUNT = NUMBER_3_INTEGER_ARRAY;

/** The compare prefix selection model. */
static char COMPARE_PREFIX_SELECTION_MODEL_ARRAY[] = {'p', 'r', 'e', 'f', 'i', 'x'};
static char* COMPARE_PREFIX_SELECTION_MODEL = COMPARE_PREFIX_SELECTION_MODEL_ARRAY;
static int* COMPARE_PREFIX_SELECTION_MODEL_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The compare suffix selection model. */
static char COMPARE_SUFFIX_SELECTION_MODEL_ARRAY[] = {'s', 'u', 'f', 'f', 'i', 'x'};
static char* COMPARE_SUFFIX_SELECTION_MODEL = COMPARE_SUFFIX_SELECTION_MODEL_ARRAY;
static int* COMPARE_SUFFIX_SELECTION_MODEL_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The compare part selection model. */
static char COMPARE_PART_SELECTION_MODEL_ARRAY[] = {'p', 'a', 'r', 't'};
static char* COMPARE_PART_SELECTION_MODEL = COMPARE_PART_SELECTION_MODEL_ARRAY;
static int* COMPARE_PART_SELECTION_MODEL_COUNT = NUMBER_4_INTEGER_ARRAY;

//
// Arithmetic models.
//

/** The add model. */
static char ADD_MODEL_ARRAY[] = {'a', 'd', 'd'};
static char* ADD_MODEL = ADD_MODEL_ARRAY;
static int* ADD_MODEL_COUNT = NUMBER_3_INTEGER_ARRAY;

/** The subtract model. */
static char SUBTRACT_MODEL_ARRAY[] = {'s', 'u', 'b', 't', 'r', 'a', 'c', 't'};
static char* SUBTRACT_MODEL = SUBTRACT_MODEL_ARRAY;
static int* SUBTRACT_MODEL_COUNT = NUMBER_8_INTEGER_ARRAY;

/** The multiply model. */
static char MULTIPLY_MODEL_ARRAY[] = {'m', 'u', 'l', 't', 'i', 'p', 'l', 'y'};
static char* MULTIPLY_MODEL = MULTIPLY_MODEL_ARRAY;
static int* MULTIPLY_MODEL_COUNT = NUMBER_8_INTEGER_ARRAY;

/** The divide model. */
static char DIVIDE_MODEL_ARRAY[] = {'d', 'i', 'v', 'i', 'd', 'e'};
static char* DIVIDE_MODEL = DIVIDE_MODEL_ARRAY;
static int* DIVIDE_MODEL_COUNT = NUMBER_6_INTEGER_ARRAY;

//
// Memory management models.
//

/** The create model. */
static char CREATE_MODEL_ARRAY[] = {'c', 'r', 'e', 'a', 't', 'e'};
static char* CREATE_MODEL = CREATE_MODEL_ARRAY;
static int* CREATE_MODEL_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The create part element model. */
static char CREATE_PART_ELEMENT_MODEL_ARRAY[] = {'p', 'a', 'r', 't'};
static char* CREATE_PART_ELEMENT_MODEL = CREATE_PART_ELEMENT_MODEL_ARRAY;
static int* CREATE_PART_ELEMENT_MODEL_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The create meta element model. */
static char CREATE_META_ELEMENT_MODEL_ARRAY[] = {'m', 'e', 't', 'a'};
static char* CREATE_META_ELEMENT_MODEL = CREATE_META_ELEMENT_MODEL_ARRAY;
static int* CREATE_META_ELEMENT_MODEL_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The destroy model. */
static char DESTROY_MODEL_ARRAY[] = {'d', 'e', 's', 't', 'r', 'o', 'y'};
static char* DESTROY_MODEL = DESTROY_MODEL_ARRAY;
static int* DESTROY_MODEL_COUNT = NUMBER_7_INTEGER_ARRAY;

//
// Lifecycle models.
//

/** The startup model. */
static char STARTUP_MODEL_ARRAY[] = {'s', 't', 'a', 'r', 't', 'u', 'p'};
static char* STARTUP_MODEL = STARTUP_MODEL_ARRAY;
static int* STARTUP_MODEL_COUNT = NUMBER_7_INTEGER_ARRAY;

/** The shutdown model. */
static char SHUTDOWN_MODEL_ARRAY[] = {'s', 'h', 'u', 't', 'd', 'o', 'w', 'n'};
static char* SHUTDOWN_MODEL = SHUTDOWN_MODEL_ARRAY;
static int* SHUTDOWN_MODEL_COUNT = NUMBER_8_INTEGER_ARRAY;

/** The exit model. */
static char EXIT_MODEL_ARRAY[] = {'e', 'x', 'i', 't'};
static char* EXIT_MODEL = EXIT_MODEL_ARRAY;
static int* EXIT_MODEL_COUNT = NUMBER_4_INTEGER_ARRAY;

//
// Communication models.
//

/** The send model. */
static char SEND_MODEL_ARRAY[] = {'s', 'e', 'n', 'd'};
static char* SEND_MODEL = SEND_MODEL_ARRAY;
static int* SEND_MODEL_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The receive model. */
static char RECEIVE_MODEL_ARRAY[] = {'r', 'e', 'c', 'e', 'i', 'v', 'e'};
static char* RECEIVE_MODEL = RECEIVE_MODEL_ARRAY;
static int* RECEIVE_MODEL_COUNT = NUMBER_7_INTEGER_ARRAY;

/** The interrupt model. */
static char INTERRUPT_MODEL_ARRAY[] = {'i', 'n', 't', 'e', 'r', 'r', 'u', 'p', 't'};
static char* INTERRUPT_MODEL = INTERRUPT_MODEL_ARRAY;
static int* INTERRUPT_MODEL_COUNT = NUMBER_9_INTEGER_ARRAY;

/** The refresh url model. */
static char REFRESH_URL_MODEL_ARRAY[] = {'r', 'e', 'f', 'r', 'e', 's', 'h', '_', 'u', 'r', 'l'};
static char* REFRESH_URL_MODEL = REFRESH_URL_MODEL_ARRAY;
static int* REFRESH_URL_MODEL_COUNT = NUMBER_11_INTEGER_ARRAY;

//
// Service models.
//

/** The signal model. */
static char SIGNAL_MODEL_ARRAY[] = {'s', 'i', 'g', 'n', 'a', 'l'};
static char* SIGNAL_MODEL = SIGNAL_MODEL_ARRAY;
static int* SIGNAL_MODEL_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The shell model. */
static char SHELL_MODEL_ARRAY[] = {'s', 'h', 'e', 'l', 'l'};
static char* SHELL_MODEL = SHELL_MODEL_ARRAY;
static int* SHELL_MODEL_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The standard output model. */
static char STANDARD_OUTPUT_MODEL_ARRAY[] = {'s', 't', 'a', 'n', 'd', 'a', 'r', 'd', '_', 'o', 'u', 't', 'p', 'u', 't'};
static char* STANDARD_OUTPUT_MODEL = STANDARD_OUTPUT_MODEL_ARRAY;
static int* STANDARD_OUTPUT_MODEL_COUNT = NUMBER_15_INTEGER_ARRAY;

/** The gnu linux console model. */
static char GNU_LINUX_CONSOLE_MODEL_ARRAY[] = {'g', 'n', 'u', '_', 'l', 'i', 'n', 'u', 'x', '_', 'c', 'o', 'n', 's', 'o', 'l', 'e'};
static char* GNU_LINUX_CONSOLE_MODEL = GNU_LINUX_CONSOLE_MODEL_ARRAY;
static int* GNU_LINUX_CONSOLE_MODEL_COUNT = NUMBER_17_INTEGER_ARRAY;

/** The x window system model. */
static char X_WINDOW_SYSTEM_MODEL_ARRAY[] = {'x', '_', 'w', 'i', 'n', 'd', 'o', 'w', '_', 's', 'y', 's', 't', 'e', 'm'};
static char* X_WINDOW_SYSTEM_MODEL = X_WINDOW_SYSTEM_MODEL_ARRAY;
static int* X_WINDOW_SYSTEM_MODEL_COUNT = NUMBER_15_INTEGER_ARRAY;

/** The world wide web (www) service model. */
static char WWW_SERVICE_MODEL_ARRAY[] = {'w', 'w', 'w'};
static char* WWW_SERVICE_MODEL = WWW_SERVICE_MODEL_ARRAY;
static int* WWW_SERVICE_MODEL_COUNT = NUMBER_3_INTEGER_ARRAY;

/** The cybernetics oriented interpreter (cyboi) service model. */
static char CYBOI_SERVICE_MODEL_ARRAY[] = {'c', 'y', 'b', 'o', 'i'};
static char* CYBOI_SERVICE_MODEL = CYBOI_SERVICE_MODEL_ARRAY;
static int* CYBOI_SERVICE_MODEL_COUNT = NUMBER_5_INTEGER_ARRAY;

//
// Communication mode models.
//

/** The client communication mode model. */
static char CLIENT_COMMUNICATION_MODE_MODEL_ARRAY[] = {'c', 'l', 'i', 'e', 'n', 't'};
static char* CLIENT_COMMUNICATION_MODE_MODEL = CLIENT_COMMUNICATION_MODE_MODEL_ARRAY;
static int* CLIENT_COMMUNICATION_MODE_MODEL_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The server communication mode model. */
static char SERVER_COMMUNICATION_MODE_MODEL_ARRAY[] = {'s', 'e', 'r', 'v', 'e', 'r'};
static char* SERVER_COMMUNICATION_MODE_MODEL = SERVER_COMMUNICATION_MODE_MODEL_ARRAY;
static int* SERVER_COMMUNICATION_MODE_MODEL_COUNT = NUMBER_6_INTEGER_ARRAY;

//
// Namespace models.
//

/** The local namespace model. */
static char LOCAL_NAMESPACE_MODEL_ARRAY[] = {'l', 'o', 'c', 'a', 'l'};
static char* LOCAL_NAMESPACE_MODEL = LOCAL_NAMESPACE_MODEL_ARRAY;
static int* LOCAL_NAMESPACE_MODEL_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The internet protocol version 4 (ipv4) namespace model. */
static char INET_NAMESPACE_MODEL_ARRAY[] = {'i', 'p', 'v', '4'};
static char* INET_NAMESPACE_MODEL = INET_NAMESPACE_MODEL_ARRAY;
static int* INET_NAMESPACE_MODEL_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The internet protocol version 6 (ipv6) namespace model. */
static char INET6_NAMESPACE_MODEL_ARRAY[] = {'i', 'p', 'v', '6'};
static char* INET6_NAMESPACE_MODEL = INET6_NAMESPACE_MODEL_ARRAY;
static int* INET6_NAMESPACE_MODEL_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The xerox network software protocols namespace model. */
static char NS_NAMESPACE_MODEL_ARRAY[] = {'n', 's'};
static char* NS_NAMESPACE_MODEL = NS_NAMESPACE_MODEL_ARRAY;
static int* NS_NAMESPACE_MODEL_COUNT = NUMBER_2_INTEGER_ARRAY;

/** The open systems interconnect (osi) namespace model. */
static char ISO_NAMESPACE_MODEL_ARRAY[] = {'i', 's', 'o'};
static char* ISO_NAMESPACE_MODEL = ISO_NAMESPACE_MODEL_ARRAY;
static int* ISO_NAMESPACE_MODEL_COUNT = NUMBER_3_INTEGER_ARRAY;

/** The ccitt namespace model. */
static char CCITT_NAMESPACE_MODEL_ARRAY[] = {'c', 'c', 'i', 't', 't'};
static char* CCITT_NAMESPACE_MODEL = CCITT_NAMESPACE_MODEL_ARRAY;
static int* CCITT_NAMESPACE_MODEL_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The internet message processor namespace model. */
static char IMPLINK_NAMESPACE_MODEL_ARRAY[] = {'i', 'm', 'p', 'l', 'i', 'n', 'k'};
static char* IMPLINK_NAMESPACE_MODEL = IMPLINK_NAMESPACE_MODEL_ARRAY;
static int* IMPLINK_NAMESPACE_MODEL_COUNT = NUMBER_7_INTEGER_ARRAY;

/** The local area routing protocol namespace model. */
static char ROUTE_NAMESPACE_MODEL_ARRAY[] = {'r', 'o', 'u', 't', 'e'};
static char* ROUTE_NAMESPACE_MODEL = ROUTE_NAMESPACE_MODEL_ARRAY;
static int* ROUTE_NAMESPACE_MODEL_COUNT = NUMBER_5_INTEGER_ARRAY;

//
// Communication style models.
//

/** The stream communication style model. */
static char STREAM_COMMUNICATION_STYLE_MODEL_ARRAY[] = {'s', 't', 'r', 'e', 'a', 'm'};
static char* STREAM_COMMUNICATION_STYLE_MODEL = STREAM_COMMUNICATION_STYLE_MODEL_ARRAY;
static int* STREAM_COMMUNICATION_STYLE_MODEL_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The datagram communication style model. */
static char DATAGRAM_COMMUNICATION_STYLE_MODEL_ARRAY[] = {'d', 'a', 't', 'a', 'g', 'r', 'a', 'm'};
static char* DATAGRAM_COMMUNICATION_STYLE_MODEL = DATAGRAM_COMMUNICATION_STYLE_MODEL_ARRAY;
static int* DATAGRAM_COMMUNICATION_STYLE_MODEL_COUNT = NUMBER_8_INTEGER_ARRAY;

/** The raw communication style model. */
static char RAW_COMMUNICATION_STYLE_MODEL_ARRAY[] = {'r', 'a', 'w'};
static char* RAW_COMMUNICATION_STYLE_MODEL = RAW_COMMUNICATION_STYLE_MODEL_ARRAY;
static int* RAW_COMMUNICATION_STYLE_MODEL_COUNT = NUMBER_3_INTEGER_ARRAY;

//
// Address models.
//

/** The loopback address model. */
static char LOOPBACK_ADDRESS_MODEL_ARRAY[] = {'l', 'o', 'o', 'p', 'b', 'a', 'c', 'k'};
static char* LOOPBACK_ADDRESS_MODEL = LOOPBACK_ADDRESS_MODEL_ARRAY;
static int* LOOPBACK_ADDRESS_MODEL_COUNT = NUMBER_8_INTEGER_ARRAY;

/** The any address model. */
static char ANY_ADDRESS_MODEL_ARRAY[] = {'a', 'n', 'y'};
static char* ANY_ADDRESS_MODEL = ANY_ADDRESS_MODEL_ARRAY;
static int* ANY_ADDRESS_MODEL_COUNT = NUMBER_3_INTEGER_ARRAY;

//
// Protocol models.
//

/** The common object request broker architecture (corba) model. */
static char CORBA_MODEL_ARRAY[] = {'c', 'o', 'r', 'b', 'a'};
static char* CORBA_MODEL = CORBA_MODEL_ARRAY;
static int* CORBA_MODEL_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The file system model. */
static char FILE_SYSTEM_MODEL_ARRAY[] = {'f', 'i', 'l', 'e'};
static char* FILE_SYSTEM_MODEL = FILE_SYSTEM_MODEL_ARRAY;
static int* FILE_SYSTEM_MODEL_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The floppy model. */
static char FLOPPY_MODEL_ARRAY[] = {'f', 'l', 'o', 'p', 'p', 'y'};
static char* FLOPPY_MODEL = FLOPPY_MODEL_ARRAY;
static int* FLOPPY_MODEL_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The imap model. */
static char IMAP_MODEL_ARRAY[] = {'i', 'm', 'a', 'p'};
static char* IMAP_MODEL = IMAP_MODEL_ARRAY;
static int* IMAP_MODEL_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The imaps model. */
static char IMAPS_MODEL_ARRAY[] = {'i', 'm', 'a', 'p', 's'};
static char* IMAPS_MODEL = IMAPS_MODEL_ARRAY;
static int* IMAPS_MODEL_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The java messaging service (jms) model. */
static char JMS_MODEL_ARRAY[] = {'j', 'm', 's'};
static char* JMS_MODEL = JMS_MODEL_ARRAY;
static int* JMS_MODEL_COUNT = NUMBER_3_INTEGER_ARRAY;

/** The latex model. */
static char LATEX_MODEL_ARRAY[] = {'l', 'a', 't', 'e', 'x'};
static char* LATEX_MODEL = LATEX_MODEL_ARRAY;
static int* LATEX_MODEL_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The ldap model. */
static char LDAP_MODEL_ARRAY[] = {'l', 'd', 'a', 'p'};
static char* LDAP_MODEL = LDAP_MODEL_ARRAY;
static int* LDAP_MODEL_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The nfs model. */
static char NFS_MODEL_ARRAY[] = {'n', 'f', 's'};
static char* NFS_MODEL = NFS_MODEL_ARRAY;
static int* NFS_MODEL_COUNT = NUMBER_3_INTEGER_ARRAY;

/** The nntp model. */
static char NNTP_MODEL_ARRAY[] = {'n', 'n', 't', 'p'};
static char* NNTP_MODEL = NNTP_MODEL_ARRAY;
static int* NNTP_MODEL_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The remote method invocation (rmi) model. */
static char RMI_MODEL_ARRAY[] = {'r', 'm', 'i'};
static char* RMI_MODEL = RMI_MODEL_ARRAY;
static int* RMI_MODEL_COUNT = NUMBER_3_INTEGER_ARRAY;

/** The simple object access protocol (soap) model. */
static char SOAP_MODEL_ARRAY[] = {'s', 'o', 'a', 'p'};
static char* SOAP_MODEL = SOAP_MODEL_ARRAY;
static int* SOAP_MODEL_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The smb model. */
static char SMB_MODEL_ARRAY[] = {'s', 'm', 'b'};
static char* SMB_MODEL = SMB_MODEL_ARRAY;
static int* SMB_MODEL_COUNT = NUMBER_3_INTEGER_ARRAY;

/** The smtp model. */
static char SMTP_MODEL_ARRAY[] = {'s', 'm', 't', 'p'};
static char* SMTP_MODEL = SMTP_MODEL_ARRAY;
static int* SMTP_MODEL_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The smtps model. */
static char SMTPS_MODEL_ARRAY[] = {'s', 'm', 't', 'p', 's'};
static char* SMTPS_MODEL = SMTPS_MODEL_ARRAY;
static int* SMTPS_MODEL_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The structured query language (sql). */
static char SQL_MODEL_ARRAY[] = {'s', 'q', 'l'};
static char* SQL_MODEL = SQL_MODEL_ARRAY;
static int* SQL_MODEL_COUNT = NUMBER_3_INTEGER_ARRAY;

//
// Shape models.
//

/** The rectangle shape model. */
static char UI_RECTANGLE_SHAPE_MODEL_ARRAY[] = {'r', 'e', 'c', 't', 'a', 'n', 'g', 'l', 'e'};
static char* UI_RECTANGLE_SHAPE_MODEL = UI_RECTANGLE_SHAPE_MODEL_ARRAY;
static int* UI_RECTANGLE_SHAPE_MODEL_COUNT = NUMBER_9_INTEGER_ARRAY;

/** The circle shape model. */
static char UI_CIRCLE_SHAPE_MODEL_ARRAY[] = {'c', 'i', 'r', 'c', 'l', 'e'};
static char* UI_CIRCLE_SHAPE_MODEL = UI_CIRCLE_SHAPE_MODEL_ARRAY;
static int* UI_CIRCLE_SHAPE_MODEL_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The polygon shape model. */
static char UI_POLYGON_SHAPE_MODEL_ARRAY[] = {'p', 'o', 'l', 'y', 'g', 'o', 'n'};
static char* UI_POLYGON_SHAPE_MODEL = UI_POLYGON_SHAPE_MODEL_ARRAY;
static int* UI_POLYGON_SHAPE_MODEL_COUNT = NUMBER_7_INTEGER_ARRAY;

//
// Layout models.
//

/** The root layout model. */
static char UI_ROOT_LAYOUT_MODEL_ARRAY[] = {'r', 'o', 'o', 't'};
static char* UI_ROOT_LAYOUT_MODEL = UI_ROOT_LAYOUT_MODEL_ARRAY;
static int* UI_ROOT_LAYOUT_MODEL_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The coordinates layout model. */
static char UI_COORDINATES_LAYOUT_MODEL_ARRAY[] = {'c', 'o', 'o', 'r', 'd', 'i', 'n', 'a', 't', 'e', 's'};
static char* UI_COORDINATES_LAYOUT_MODEL = UI_COORDINATES_LAYOUT_MODEL_ARRAY;
static int* UI_COORDINATES_LAYOUT_MODEL_COUNT = NUMBER_11_INTEGER_ARRAY;

/** The compass layout model. */
static char UI_COMPASS_LAYOUT_MODEL_ARRAY[] = {'c', 'o', 'm', 'p', 'a', 's', 's'};
static char* UI_COMPASS_LAYOUT_MODEL = UI_COMPASS_LAYOUT_MODEL_ARRAY;
static int* UI_COMPASS_LAYOUT_MODEL_COUNT = NUMBER_7_INTEGER_ARRAY;

//
// Compass layout cell models.
//

/** The compass layout north cell model. */
static char UI_NORTH_CELL_MODEL_ARRAY[] = {'n', 'o', 'r', 't', 'h'};
static char* UI_NORTH_CELL_MODEL = UI_NORTH_CELL_MODEL_ARRAY;
static int* UI_NORTH_CELL_MODEL_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The compass layout south cell model. */
static char UI_SOUTH_CELL_MODEL_ARRAY[] = {'s', 'o', 'u', 't', 'h'};
static char* UI_SOUTH_CELL_MODEL = UI_SOUTH_CELL_MODEL_ARRAY;
static int* UI_SOUTH_CELL_MODEL_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The compass layout west cell model. */
static char UI_WEST_CELL_MODEL_ARRAY[] = {'w', 'e', 's', 't'};
static char* UI_WEST_CELL_MODEL = UI_WEST_CELL_MODEL_ARRAY;
static int* UI_WEST_CELL_MODEL_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The compass layout east cell model. */
static char UI_EAST_CELL_MODEL_ARRAY[] = {'e', 'a', 's', 't'};
static char* UI_EAST_CELL_MODEL = UI_EAST_CELL_MODEL_ARRAY;
static int* UI_EAST_CELL_MODEL_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The compass layout centre cell model. */
static char UI_CENTRE_CELL_MODEL_ARRAY[] = {'c', 'e', 'n', 't', 'r', 'e'};
static char* UI_CENTRE_CELL_MODEL = UI_CENTRE_CELL_MODEL_ARRAY;
static int* UI_CENTRE_CELL_MODEL_COUNT = NUMBER_6_INTEGER_ARRAY;

//
// Border models.
//

/** The line border model. */
static char TUI_LINE_BORDER_MODEL_ARRAY[] = {'l', 'i', 'n', 'e'};
static char* TUI_LINE_BORDER_MODEL = TUI_LINE_BORDER_MODEL_ARRAY;
static int* TUI_LINE_BORDER_MODEL_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The round line border model. */
static char TUI_ROUND_LINE_BORDER_MODEL_ARRAY[] = {'r', 'o', 'u', 'n', 'd'};
static char* TUI_ROUND_LINE_BORDER_MODEL = TUI_ROUND_LINE_BORDER_MODEL_ARRAY;
static int* TUI_ROUND_LINE_BORDER_MODEL_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The double line border model. */
static char TUI_DOUBLE_LINE_BORDER_MODEL_ARRAY[] = {'d', 'o', 'u', 'b', 'l', 'e'};
static char* TUI_DOUBLE_LINE_BORDER_MODEL = TUI_DOUBLE_LINE_BORDER_MODEL_ARRAY;
static int* TUI_DOUBLE_LINE_BORDER_MODEL_COUNT = NUMBER_6_INTEGER_ARRAY;

//
// Run models.
//

/** The run model. */
static char RUN_MODEL_ARRAY[] = {'r', 'u', 'n'};
static char* RUN_MODEL = RUN_MODEL_ARRAY;
static int* RUN_MODEL_COUNT = NUMBER_3_INTEGER_ARRAY;

/** The run archive model. */
static char RUN_ARCHIVE_MODEL_ARRAY[] = {'a', 'r', 'c', 'h', 'i', 'v', 'e'};
static char* RUN_ARCHIVE_MODEL = RUN_ARCHIVE_MODEL_ARRAY;
static int* RUN_ARCHIVE_MODEL_COUNT = NUMBER_7_INTEGER_ARRAY;

/** The run copy model. */
static char RUN_COPY_MODEL_ARRAY[] = {'c', 'o', 'p', 'y'};
static char* RUN_COPY_MODEL = RUN_COPY_MODEL_ARRAY;
static int* RUN_COPY_MODEL_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The list directory contents model. */
static char RUN_LIST_DIRECTORY_CONTENTS_MODEL_ARRAY[] = {'l', 'i', 's', 't', '_', 'd', 'i', 'r', 'e', 'c', 't', 'o', 'r', 'y', '_', 'c', 'o', 'n', 't', 'e', 'n', 't', 's'};
static char* RUN_LIST_DIRECTORY_CONTENTS_MODEL = RUN_LIST_DIRECTORY_CONTENTS_MODEL_ARRAY;
static int* RUN_LIST_DIRECTORY_CONTENTS_MODEL_COUNT = NUMBER_23_INTEGER_ARRAY;

/** The run program model. */
static char RUN_PROGRAM_MODEL_ARRAY[] = {'p', 'r', 'o', 'g', 'r', 'a', 'm'};
static char* RUN_PROGRAM_MODEL = RUN_PROGRAM_MODEL_ARRAY;
static int* RUN_PROGRAM_MODEL_COUNT = NUMBER_7_INTEGER_ARRAY;

/* CYBOL_MODEL_CONSTANTS_SOURCE */
#endif