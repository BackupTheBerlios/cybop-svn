/*
 * Copyright (C) 1999-2008. Christian Heller.
 *
 * This file is part of the Cybernetics Oriented Interpreter (CYBOI).
 *
 * CYBOI is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * CYBOI is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with CYBOI.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Cybernetics Oriented Programming (CYBOP) <http://www.cybop.org>
 * Christian Heller <christian.heller@tuxtax.de>
 *
 * @version $RCSfile: send_communication_operation_cybol_name.c,v $ $Revision: 1.2 $ $Date: 2008-09-04 20:31:30 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef SEND_COMMUNICATION_OPERATION_CYBOL_NAME_SOURCE
#define SEND_COMMUNICATION_OPERATION_CYBOL_NAME_SOURCE

#include "../../../../../constant/model/memory/integer_memory_model.c"

/** The channel send communication operation cybol name. */
static wchar_t CHANNEL_SEND_COMMUNICATION_OPERATION_CYBOL_NAME_ARRAY[] = {L'c', L'h', L'a', L'n', L'n', L'e', L'l'};
static wchar_t* CHANNEL_SEND_COMMUNICATION_OPERATION_CYBOL_NAME = CHANNEL_SEND_COMMUNICATION_OPERATION_CYBOL_NAME_ARRAY;
static int* CHANNEL_SEND_COMMUNICATION_OPERATION_CYBOL_NAME_COUNT = NUMBER_7_INTEGER_MEMORY_MODEL_ARRAY;

/** The language send communication operation cybol name. */
static wchar_t LANGUAGE_SEND_COMMUNICATION_OPERATION_CYBOL_NAME_ARRAY[] = {L'l', L'a', L'n', L'g', L'u', L'a', L'g', L'e'};
static wchar_t* LANGUAGE_SEND_COMMUNICATION_OPERATION_CYBOL_NAME = LANGUAGE_SEND_COMMUNICATION_OPERATION_CYBOL_NAME_ARRAY;
static int* LANGUAGE_SEND_COMMUNICATION_OPERATION_CYBOL_NAME_COUNT = NUMBER_8_INTEGER_MEMORY_MODEL_ARRAY;

/** The communication mode send communication operation cybol name. */
static wchar_t MODE_SEND_COMMUNICATION_OPERATION_CYBOL_NAME_ARRAY[] = {L'm', L'o', L'd', L'e'};
static wchar_t* MODE_SEND_COMMUNICATION_OPERATION_CYBOL_NAME = MODE_SEND_COMMUNICATION_OPERATION_CYBOL_NAME_ARRAY;
static int* MODE_SEND_COMMUNICATION_OPERATION_CYBOL_NAME_COUNT = NUMBER_4_INTEGER_MEMORY_MODEL_ARRAY;

/** The socket namespace send communication operation cybol name. */
static wchar_t NAMESPACE_SEND_COMMUNICATION_OPERATION_CYBOL_NAME_ARRAY[] = {L'n', L'a', L'm', L'e', L's', L'p', L'a', L'c', L'e'};
static wchar_t* NAMESPACE_SEND_COMMUNICATION_OPERATION_CYBOL_NAME = NAMESPACE_SEND_COMMUNICATION_OPERATION_CYBOL_NAME_ARRAY;
static int* NAMESPACE_SEND_COMMUNICATION_OPERATION_CYBOL_NAME_COUNT = NUMBER_9_INTEGER_MEMORY_MODEL_ARRAY;

/** The communication style send communication operation cybol name. */
static wchar_t STYLE_SEND_COMMUNICATION_OPERATION_CYBOL_NAME_ARRAY[] = {L's', L't', L'y', L'l', L'e'};
static wchar_t* STYLE_SEND_COMMUNICATION_OPERATION_CYBOL_NAME = STYLE_SEND_COMMUNICATION_OPERATION_CYBOL_NAME_ARRAY;
static int* STYLE_SEND_COMMUNICATION_OPERATION_CYBOL_NAME_COUNT = NUMBER_5_INTEGER_MEMORY_MODEL_ARRAY;

/** The sender send communication operation cybol name. */
static wchar_t SENDER_SEND_COMMUNICATION_OPERATION_CYBOL_NAME_ARRAY[] = {L's', L'e', L'n', L'd', L'e', L'r'};
static wchar_t* SENDER_SEND_COMMUNICATION_OPERATION_CYBOL_NAME = SENDER_SEND_COMMUNICATION_OPERATION_CYBOL_NAME_ARRAY;
static int* SENDER_SEND_COMMUNICATION_OPERATION_CYBOL_NAME_COUNT = NUMBER_6_INTEGER_MEMORY_MODEL_ARRAY;

/** The receiver send communication operation cybol name. */
static wchar_t RECEIVER_SEND_COMMUNICATION_OPERATION_CYBOL_NAME_ARRAY[] = {L'r', L'e', L'c', L'e', L'i', L'v', L'e', L'r'};
static wchar_t* RECEIVER_SEND_COMMUNICATION_OPERATION_CYBOL_NAME = RECEIVER_SEND_COMMUNICATION_OPERATION_CYBOL_NAME_ARRAY;
static int* RECEIVER_SEND_COMMUNICATION_OPERATION_CYBOL_NAME_COUNT = NUMBER_8_INTEGER_MEMORY_MODEL_ARRAY;

/** The message send communication operation cybol name. */
static wchar_t MESSAGE_SEND_COMMUNICATION_OPERATION_CYBOL_NAME_ARRAY[] = {L'm', L'e', L's', L's', L'a', L'g', L'e'};
static wchar_t* MESSAGE_SEND_COMMUNICATION_OPERATION_CYBOL_NAME = MESSAGE_SEND_COMMUNICATION_OPERATION_CYBOL_NAME_ARRAY;
static int* MESSAGE_SEND_COMMUNICATION_OPERATION_CYBOL_NAME_COUNT = NUMBER_7_INTEGER_MEMORY_MODEL_ARRAY;

/** The area send communication operation cybol name. */
static wchar_t AREA_SEND_COMMUNICATION_OPERATION_CYBOL_NAME_ARRAY[] = {L'a', L'r', L'e', L'a'};
static wchar_t* AREA_SEND_COMMUNICATION_OPERATION_CYBOL_NAME = AREA_SEND_COMMUNICATION_OPERATION_CYBOL_NAME_ARRAY;
static int* AREA_SEND_COMMUNICATION_OPERATION_CYBOL_NAME_COUNT = NUMBER_4_INTEGER_MEMORY_MODEL_ARRAY;

/** The clean send communication operation cybol name. */
static wchar_t CLEAN_SEND_COMMUNICATION_OPERATION_CYBOL_NAME_ARRAY[] = {L'c', L'l', L'e', L'a', L'n'};
static wchar_t* CLEAN_SEND_COMMUNICATION_OPERATION_CYBOL_NAME = CLEAN_SEND_COMMUNICATION_OPERATION_CYBOL_NAME_ARRAY;
static int* CLEAN_SEND_COMMUNICATION_OPERATION_CYBOL_NAME_COUNT = NUMBER_5_INTEGER_MEMORY_MODEL_ARRAY;

/** The new line send communication operation cybol name. */
static wchar_t NEW_LINE_SEND_COMMUNICATION_OPERATION_CYBOL_NAME_ARRAY[] = {L'n', L'e', L'w', L'_', L'l', L'i', L'n', L'e'};
static wchar_t* NEW_LINE_SEND_COMMUNICATION_OPERATION_CYBOL_NAME = NEW_LINE_SEND_COMMUNICATION_OPERATION_CYBOL_NAME_ARRAY;
static int* NEW_LINE_SEND_COMMUNICATION_OPERATION_CYBOL_NAME_COUNT = NUMBER_8_INTEGER_MEMORY_MODEL_ARRAY;

/** The url send communication operation cybol name. */
/*??
static wchar_t URL_SEND_COMMUNICATION_OPERATION_CYBOL_NAME_ARRAY[] = {L'u', L'r', L'l'};
static wchar_t* URL_SEND_COMMUNICATION_OPERATION_CYBOL_NAME = URL_SEND_COMMUNICATION_OPERATION_CYBOL_NAME_ARRAY;
static int* URL_SEND_COMMUNICATION_OPERATION_CYBOL_NAME_COUNT = NUMBER_3_INTEGER_MEMORY_MODEL_ARRAY;
*/

/* SEND_COMMUNICATION_OPERATION_CYBOL_NAME_SOURCE */
#endif
