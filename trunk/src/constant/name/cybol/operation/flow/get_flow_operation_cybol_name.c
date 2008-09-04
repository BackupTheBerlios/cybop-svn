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
 * @version $RCSfile: get_flow_operation_cybol_name.c,v $ $Revision: 1.2 $ $Date: 2008-09-04 20:31:30 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef GET_FLOW_OPERATION_CYBOL_NAME_SOURCE
#define GET_FLOW_OPERATION_CYBOL_NAME_SOURCE

#include "../../../../../constant/model/memory/integer_memory_model.c"

/** The compound get flow operation cybol name. */
static wchar_t COMPOUND_GET_FLOW_OPERATION_CYBOL_NAME_ARRAY[] = {L'c', L'o', L'm', L'p', L'o', L'u', L'n', L'd'};
static wchar_t* COMPOUND_GET_FLOW_OPERATION_CYBOL_NAME = COMPOUND_GET_FLOW_OPERATION_CYBOL_NAME_ARRAY;
static int* COMPOUND_GET_FLOW_OPERATION_CYBOL_NAME_COUNT = NUMBER_8_INTEGER_MEMORY_MODEL_ARRAY;

/** The index get flow operation cybol name. */
static wchar_t INDEX_GET_FLOW_OPERATION_CYBOL_NAME_ARRAY[] = {L'i', L'n', L'd', L'e', L'x'};
static wchar_t* INDEX_GET_FLOW_OPERATION_CYBOL_NAME = INDEX_GET_FLOW_OPERATION_CYBOL_NAME_ARRAY;
static int* INDEX_GET_FLOW_OPERATION_CYBOL_NAME_COUNT = NUMBER_5_INTEGER_MEMORY_MODEL_ARRAY;

/** The description get flow operation cybol name. */
static wchar_t DESCRIPTION_GET_FLOW_OPERATION_CYBOL_NAME_ARRAY[] = {L'd', L'e', L's', L'c', L'r', L'i', L'p', L't', L'i', L'o', L'n'};
static wchar_t* DESCRIPTION_GET_FLOW_OPERATION_CYBOL_NAME = DESCRIPTION_GET_FLOW_OPERATION_CYBOL_NAME_ARRAY;
static int* DESCRIPTION_GET_FLOW_OPERATION_CYBOL_NAME_COUNT = NUMBER_11_INTEGER_MEMORY_MODEL_ARRAY;

/** The result get flow operation cybol name. */
static wchar_t RESULT_GET_FLOW_OPERATION_CYBOL_NAME_ARRAY[] = {L'r', L'e', L's', L'u', L'l', L't'};
static wchar_t* RESULT_GET_FLOW_OPERATION_CYBOL_NAME = RESULT_GET_FLOW_OPERATION_CYBOL_NAME_ARRAY;
static int* RESULT_GET_FLOW_OPERATION_CYBOL_NAME_COUNT = NUMBER_6_INTEGER_MEMORY_MODEL_ARRAY;

/* GET_FLOW_OPERATION_CYBOL_NAME_SOURCE */
#endif
