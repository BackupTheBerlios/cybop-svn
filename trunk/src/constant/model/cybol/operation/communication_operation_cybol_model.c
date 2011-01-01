/*
 * Copyright (C) 1999-2011. Christian Heller.
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
 * @version $RCSfile: communication_operation_cybol_model.c,v $ $Revision: 1.6 $ $Date: 2009-01-31 16:06:30 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef COMMUNICATION_OPERATION_CYBOL_MODEL_SOURCE
#define COMMUNICATION_OPERATION_CYBOL_MODEL_SOURCE

#include <stddef.h>
#include "../../../../constant/model/memory/integer_memory_model.c"

/** The receive communication operation cybol model. */
static wchar_t RECEIVE_COMMUNICATION_OPERATION_CYBOL_MODEL_ARRAY[] = {L'r', L'e', L'c', L'e', L'i', L'v', L'e'};
static wchar_t* RECEIVE_COMMUNICATION_OPERATION_CYBOL_MODEL = RECEIVE_COMMUNICATION_OPERATION_CYBOL_MODEL_ARRAY;
static int* RECEIVE_COMMUNICATION_OPERATION_CYBOL_MODEL_COUNT = NUMBER_7_INTEGER_MEMORY_MODEL_ARRAY;

/** The send communication operation cybol model. */
static wchar_t SEND_COMMUNICATION_OPERATION_CYBOL_MODEL_ARRAY[] = {L's', L'e', L'n', L'd'};
static wchar_t* SEND_COMMUNICATION_OPERATION_CYBOL_MODEL = SEND_COMMUNICATION_OPERATION_CYBOL_MODEL_ARRAY;
static int* SEND_COMMUNICATION_OPERATION_CYBOL_MODEL_COUNT = NUMBER_4_INTEGER_MEMORY_MODEL_ARRAY;

/** The sense communication operation cybol model. */
static wchar_t SENSE_COMMUNICATION_OPERATION_CYBOL_MODEL_ARRAY[] = {L's', L'e', L'n', L's', L'e'};
static wchar_t* SENSE_COMMUNICATION_OPERATION_CYBOL_MODEL = SENSE_COMMUNICATION_OPERATION_CYBOL_MODEL_ARRAY;
static int* SENSE_COMMUNICATION_OPERATION_CYBOL_MODEL_COUNT = NUMBER_5_INTEGER_MEMORY_MODEL_ARRAY;

/* COMMUNICATION_OPERATION_CYBOL_MODEL_SOURCE */
#endif
