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
 * @version $RCSfile: operation_cybol_model.c,v $ $Revision: 1.5 $ $Date: 2009-01-31 16:06:30 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef OPERATION_CYBOL_MODEL_SOURCE
#define OPERATION_CYBOL_MODEL_SOURCE

#include <stddef.h>

#include "../../../constant/model/memory/integer_memory_model.c"

/** The calculate operation cybol model. */
static wchar_t CALCULATE_OPERATION_CYBOL_MODEL_ARRAY[] = {L'c', L'a', L'l', L'c', L'u', L'l', L'a', L't', L'e'};
static wchar_t* CALCULATE_OPERATION_CYBOL_MODEL = CALCULATE_OPERATION_CYBOL_MODEL_ARRAY;
static int* CALCULATE_OPERATION_CYBOL_MODEL_COUNT = NUMBER_9_INTEGER_MEMORY_MODEL_ARRAY;

/** The communicate operation cybol model. */
static wchar_t COMMUNICATE_OPERATION_CYBOL_MODEL_ARRAY[] = {L'c', L'o', L'm', L'm', L'u', L'n', L'i', L'c', L'a', L't', L'e'};
static wchar_t* COMMUNICATE_OPERATION_CYBOL_MODEL = COMMUNICATE_OPERATION_CYBOL_MODEL_ARRAY;
static int* COMMUNICATE_OPERATION_CYBOL_MODEL_COUNT = NUMBER_11_INTEGER_MEMORY_MODEL_ARRAY;

/** The compare operation cybol model. */
static wchar_t COMPARE_OPERATION_CYBOL_MODEL_ARRAY[] = {L'c', L'o', L'm', L'p', L'a', L'r', L'e'};
static wchar_t* COMPARE_OPERATION_CYBOL_MODEL = COMPARE_OPERATION_CYBOL_MODEL_ARRAY;
static int* COMPARE_OPERATION_CYBOL_MODEL_COUNT = NUMBER_7_INTEGER_MEMORY_MODEL_ARRAY;

/** The file operation cybol model. */
static wchar_t FILE_OPERATION_CYBOL_MODEL_ARRAY[] = {L'f', L'i', L'l', L'e'};
static wchar_t* FILE_OPERATION_CYBOL_MODEL = FILE_OPERATION_CYBOL_MODEL_ARRAY;
static int* FILE_OPERATION_CYBOL_MODEL_COUNT = NUMBER_4_INTEGER_MEMORY_MODEL_ARRAY;

/** The flow operation cybol model. */
static wchar_t FLOW_OPERATION_CYBOL_MODEL_ARRAY[] = {L'f', L'l', L'o', L'w'};
static wchar_t* FLOW_OPERATION_CYBOL_MODEL = FLOW_OPERATION_CYBOL_MODEL_ARRAY;
static int* FLOW_OPERATION_CYBOL_MODEL_COUNT = NUMBER_4_INTEGER_MEMORY_MODEL_ARRAY;

/** The live operation cybol model. */
static wchar_t LIVE_OPERATION_CYBOL_MODEL_ARRAY[] = {L'l', L'i', L'v', L'e'};
static wchar_t* LIVE_OPERATION_CYBOL_MODEL = LIVE_OPERATION_CYBOL_MODEL_ARRAY;
static int* LIVE_OPERATION_CYBOL_MODEL_COUNT = NUMBER_4_INTEGER_MEMORY_MODEL_ARRAY;

/** The maintain operation cybol model. */
static wchar_t MAINTAIN_OPERATION_CYBOL_MODEL_ARRAY[] = {L'm', L'a', L'i', L'n', L't', L'a', L'i', L'n'};
static wchar_t* MAINTAIN_OPERATION_CYBOL_MODEL = MAINTAIN_OPERATION_CYBOL_MODEL_ARRAY;
static int* MAINTAIN_OPERATION_CYBOL_MODEL_COUNT = NUMBER_8_INTEGER_MEMORY_MODEL_ARRAY;

/** The memorise operation cybol model. */
static wchar_t MEMORISE_OPERATION_CYBOL_MODEL_ARRAY[] = {L'm', L'e', L'm', L'o', L'r', L'i', L's', L'e'};
static wchar_t* MEMORISE_OPERATION_CYBOL_MODEL = MEMORISE_OPERATION_CYBOL_MODEL_ARRAY;
static int* MEMORISE_OPERATION_CYBOL_MODEL_COUNT = NUMBER_8_INTEGER_MEMORY_MODEL_ARRAY;

/** The modify operation cybol model. */
static wchar_t MODIFY_OPERATION_CYBOL_MODEL_ARRAY[] = {L'm', L'o', L'd', L'i', L'f', L'y'};
static wchar_t* MODIFY_OPERATION_CYBOL_MODEL = MODIFY_OPERATION_CYBOL_MODEL_ARRAY;
static int* MODIFY_OPERATION_CYBOL_MODEL_COUNT = NUMBER_6_INTEGER_MEMORY_MODEL_ARRAY;

/** The run operation cybol model. */
static wchar_t RUN_OPERATION_CYBOL_MODEL_ARRAY[] = {L'r', L'u', L'n'};
static wchar_t* RUN_OPERATION_CYBOL_MODEL = RUN_OPERATION_CYBOL_MODEL_ARRAY;
static int* RUN_OPERATION_CYBOL_MODEL_COUNT = NUMBER_3_INTEGER_MEMORY_MODEL_ARRAY;

/* OPERATION_CYBOL_MODEL_SOURCE */
#endif
