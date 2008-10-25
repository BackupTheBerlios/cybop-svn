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
 * @version $RCSfile: receive_communication_operation_cybol_name.c,v $ $Revision: 1.3 $ $Date: 2008-10-25 23:20:04 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef RECEIVE_COMMUNICATION_OPERATION_CYBOL_NAME_SOURCE
#define RECEIVE_COMMUNICATION_OPERATION_CYBOL_NAME_SOURCE

#include <stddef.h>
#include "../../../../../constant/model/memory/integer_memory_model.c"

/** The channel receive communication operation cybol name. */
static wchar_t CHANNEL_RECEIVE_COMMUNICATION_OPERATION_CYBOL_NAME_ARRAY[] = {L'c', L'h', L'a', L'n', L'n', L'e', L'l'};
static wchar_t* CHANNEL_RECEIVE_COMMUNICATION_OPERATION_CYBOL_NAME = CHANNEL_RECEIVE_COMMUNICATION_OPERATION_CYBOL_NAME_ARRAY;
static int* CHANNEL_RECEIVE_COMMUNICATION_OPERATION_CYBOL_NAME_COUNT = NUMBER_7_INTEGER_MEMORY_MODEL_ARRAY;

/** The handler receive communication operation cybol name. */
static wchar_t HANDLER_RECEIVE_COMMUNICATION_OPERATION_CYBOL_NAME_ARRAY[] = {L'h', L'a', L'n', L'd', L'l', L'e', L'r'};
static wchar_t* HANDLER_RECEIVE_COMMUNICATION_OPERATION_CYBOL_NAME = HANDLER_RECEIVE_COMMUNICATION_OPERATION_CYBOL_NAME_ARRAY;
static int* HANDLER_RECEIVE_COMMUNICATION_OPERATION_CYBOL_NAME_COUNT = NUMBER_7_INTEGER_MEMORY_MODEL_ARRAY;

/** The language receive communication operation cybol name. */
static wchar_t LANGUAGE_RECEIVE_COMMUNICATION_OPERATION_CYBOL_NAME_ARRAY[] = {L'l', L'a', L'n', L'g', L'u', L'a', L'g', L'e'};
static wchar_t* LANGUAGE_RECEIVE_COMMUNICATION_OPERATION_CYBOL_NAME = LANGUAGE_RECEIVE_COMMUNICATION_OPERATION_CYBOL_NAME_ARRAY;
static int* LANGUAGE_RECEIVE_COMMUNICATION_OPERATION_CYBOL_NAME_COUNT = NUMBER_8_INTEGER_MEMORY_MODEL_ARRAY;

/** The message receive communication operation cybol name. */
static wchar_t MESSAGE_RECEIVE_COMMUNICATION_OPERATION_CYBOL_NAME_ARRAY[] = {L'm', L'e', L's', L's', L'a', L'g', L'e'};
static wchar_t* MESSAGE_RECEIVE_COMMUNICATION_OPERATION_CYBOL_NAME = MESSAGE_RECEIVE_COMMUNICATION_OPERATION_CYBOL_NAME_ARRAY;
static int* MESSAGE_RECEIVE_COMMUNICATION_OPERATION_CYBOL_NAME_COUNT = NUMBER_7_INTEGER_MEMORY_MODEL_ARRAY;

/** The meta receive communication operation cybol name. */
static wchar_t META_RECEIVE_COMMUNICATION_OPERATION_CYBOL_NAME_ARRAY[] = {L'm', L'e', L't', L'a'};
static wchar_t* META_RECEIVE_COMMUNICATION_OPERATION_CYBOL_NAME = META_RECEIVE_COMMUNICATION_OPERATION_CYBOL_NAME_ARRAY;
static int* META_RECEIVE_COMMUNICATION_OPERATION_CYBOL_NAME_COUNT = NUMBER_4_INTEGER_MEMORY_MODEL_ARRAY;

/** The model receive communication operation cybol name. */
static wchar_t MODEL_RECEIVE_COMMUNICATION_OPERATION_CYBOL_NAME_ARRAY[] = {L'm', L'o', L'd', L'e', L'l'};
static wchar_t* MODEL_RECEIVE_COMMUNICATION_OPERATION_CYBOL_NAME = MODEL_RECEIVE_COMMUNICATION_OPERATION_CYBOL_NAME_ARRAY;
static int* MODEL_RECEIVE_COMMUNICATION_OPERATION_CYBOL_NAME_COUNT = NUMBER_5_INTEGER_MEMORY_MODEL_ARRAY;

/** The root receive communication operation cybol name. */
static wchar_t ROOT_RECEIVE_COMMUNICATION_OPERATION_CYBOL_NAME_ARRAY[] = {L'r', L'o', L'o', L't'};
static wchar_t* ROOT_RECEIVE_COMMUNICATION_OPERATION_CYBOL_NAME = ROOT_RECEIVE_COMMUNICATION_OPERATION_CYBOL_NAME_ARRAY;
static int* ROOT_RECEIVE_COMMUNICATION_OPERATION_CYBOL_NAME_COUNT = NUMBER_4_INTEGER_MEMORY_MODEL_ARRAY;

/** The style receive communication operation cybol name. */
static wchar_t STYLE_RECEIVE_COMMUNICATION_OPERATION_CYBOL_NAME_ARRAY[] = {L's', L't', L'y', L'l', L'e'};
static wchar_t* STYLE_RECEIVE_COMMUNICATION_OPERATION_CYBOL_NAME = STYLE_RECEIVE_COMMUNICATION_OPERATION_CYBOL_NAME_ARRAY;
static int* STYLE_RECEIVE_COMMUNICATION_OPERATION_CYBOL_NAME_COUNT = NUMBER_5_INTEGER_MEMORY_MODEL_ARRAY;

/** The commands receive communication operation cybol name. */
static wchar_t COMMANDS_RECEIVE_COMMUNICATION_OPERATION_CYBOL_NAME_ARRAY[] = {L'c', L'o', L'm', L'm', L'a', L'n', L'd', L's'};
static wchar_t* COMMANDS_RECEIVE_COMMUNICATION_OPERATION_CYBOL_NAME = COMMANDS_RECEIVE_COMMUNICATION_OPERATION_CYBOL_NAME_ARRAY;
static int* COMMANDS_RECEIVE_COMMUNICATION_OPERATION_CYBOL_NAME_COUNT = NUMBER_8_INTEGER_MEMORY_MODEL_ARRAY;

/** The blocking receive communication operation cybol name. */
static wchar_t BLOCKING_RECEIVE_COMMUNICATION_OPERATION_CYBOL_NAME_ARRAY[] = {L'b', L'l', L'o', L'c', L'k', L'i', L'n', L'g'};
static wchar_t* BLOCKING_RECEIVE_COMMUNICATION_OPERATION_CYBOL_NAME = BLOCKING_RECEIVE_COMMUNICATION_OPERATION_CYBOL_NAME_ARRAY;
static int* BLOCKING_RECEIVE_COMMUNICATION_OPERATION_CYBOL_NAME_COUNT = NUMBER_8_INTEGER_MEMORY_MODEL_ARRAY;

/* RECEIVE_COMMUNICATION_OPERATION_CYBOL_NAME_SOURCE */
#endif
