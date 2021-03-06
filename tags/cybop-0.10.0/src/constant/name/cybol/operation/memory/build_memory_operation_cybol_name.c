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
 * @version $RCSfile: build_memory_operation_cybol_name.c,v $ $Revision: 1.3 $ $Date: 2009-01-31 16:06:30 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef BUILD_FLOW_OPERATION_CYBOL_NAME_SOURCE
#define BUILD_FLOW_OPERATION_CYBOL_NAME_SOURCE

#include <stddef.h>
#include "../../../../../constant/model/memory/integer_memory_model.c"

/** The base build flow operation cybol name. */
static wchar_t BASE_BUILD_FLOW_OPERATION_CYBOL_NAME_ARRAY[] = {L'b', L'a', L's', L'e'};
static wchar_t* BASE_BUILD_FLOW_OPERATION_CYBOL_NAME = BASE_BUILD_FLOW_OPERATION_CYBOL_NAME_ARRAY;
static int* BASE_BUILD_FLOW_OPERATION_CYBOL_NAME_COUNT = NUMBER_4_INTEGER_MEMORY_MODEL_ARRAY;

/** The index build flow operation cybol name. */
static wchar_t INDEX_BUILD_FLOW_OPERATION_CYBOL_NAME_ARRAY[] = {L'i', L'n', L'd', L'e', L'x'};
static wchar_t* INDEX_BUILD_FLOW_OPERATION_CYBOL_NAME = INDEX_BUILD_FLOW_OPERATION_CYBOL_NAME_ARRAY;
static int* INDEX_BUILD_FLOW_OPERATION_CYBOL_NAME_COUNT = NUMBER_5_INTEGER_MEMORY_MODEL_ARRAY;

/** The composed build flow operation cybol name. */
static wchar_t COMPOSITION_BUILD_FLOW_OPERATION_CYBOL_NAME_ARRAY[] = {L'c', L'o', L'm', L'p', L'o', L's', L'i', L't', L'i', L'o', L'n'};
static wchar_t* COMPOSITION_BUILD_FLOW_OPERATION_CYBOL_NAME = COMPOSITION_BUILD_FLOW_OPERATION_CYBOL_NAME_ARRAY;
static int* COMPOSITION_BUILD_FLOW_OPERATION_CYBOL_NAME_COUNT = NUMBER_11_INTEGER_MEMORY_MODEL_ARRAY;

/* BUILD_FLOW_OPERATION_CYBOL_NAME_SOURCE */
#endif
