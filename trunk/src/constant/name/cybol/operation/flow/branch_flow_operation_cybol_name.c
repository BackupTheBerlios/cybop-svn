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
 * @version $RCSfile: branch_flow_operation_cybol_name.c,v $ $Revision: 1.3 $ $Date: 2008-10-25 23:20:04 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef BRANCH_FLOW_OPERATION_CYBOL_NAME_SOURCE
#define BRANCH_FLOW_OPERATION_CYBOL_NAME_SOURCE

#include <stddef.h>
#include "../../../../../constant/model/memory/integer_memory_model.c"

/** The criterion branch flow operation cybol name. */
static wchar_t CRITERION_BRANCH_FLOW_OPERATION_CYBOL_NAME_ARRAY[] = {L'c', L'r', L'i', L't', L'e', L'r', L'i', L'o', L'n'};
static wchar_t* CRITERION_BRANCH_FLOW_OPERATION_CYBOL_NAME = CRITERION_BRANCH_FLOW_OPERATION_CYBOL_NAME_ARRAY;
static int* CRITERION_BRANCH_FLOW_OPERATION_CYBOL_NAME_COUNT = NUMBER_9_INTEGER_MEMORY_MODEL_ARRAY;

/** The true branch flow operation cybol name. */
static wchar_t TRUE_BRANCH_FLOW_OPERATION_CYBOL_NAME_ARRAY[] = {L't', L'r', L'u', L'e'};
static wchar_t* TRUE_BRANCH_FLOW_OPERATION_CYBOL_NAME = TRUE_BRANCH_FLOW_OPERATION_CYBOL_NAME_ARRAY;
static int* TRUE_BRANCH_FLOW_OPERATION_CYBOL_NAME_COUNT = NUMBER_4_INTEGER_MEMORY_MODEL_ARRAY;

/** The false branch flow operation cybol name. */
static wchar_t FALSE_BRANCH_FLOW_OPERATION_CYBOL_NAME_ARRAY[] = {L'f', L'a', L'l', L's', L'e'};
static wchar_t* FALSE_BRANCH_FLOW_OPERATION_CYBOL_NAME = FALSE_BRANCH_FLOW_OPERATION_CYBOL_NAME_ARRAY;
static int* FALSE_BRANCH_FLOW_OPERATION_CYBOL_NAME_COUNT = NUMBER_5_INTEGER_MEMORY_MODEL_ARRAY;

/* BRANCH_FLOW_OPERATION_CYBOL_NAME_SOURCE */
#endif
