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
 * @version $RCSfile: flow_operation_cybol_model.c,v $ $Revision: 1.4 $ $Date: 2008-10-25 23:20:04 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef FLOW_OPERATION_CYBOL_MODEL_SOURCE
#define FLOW_OPERATION_CYBOL_MODEL_SOURCE

#include <stddef.h>
#include "../../../../constant/model/memory/integer_memory_model.c"

/** The branch flow operation cybol model. */
static wchar_t BRANCH_FLOW_OPERATION_CYBOL_MODEL_ARRAY[] = {L'b', L'r', L'a', L'n', L'c', L'h'};
static wchar_t* BRANCH_FLOW_OPERATION_CYBOL_MODEL = BRANCH_FLOW_OPERATION_CYBOL_MODEL_ARRAY;
static int* BRANCH_FLOW_OPERATION_CYBOL_MODEL_COUNT = NUMBER_6_INTEGER_MEMORY_MODEL_ARRAY;

/** The loop flow operation cybol model. */
static wchar_t LOOP_FLOW_OPERATION_CYBOL_MODEL_ARRAY[] = {L'l', L'o', L'o', L'p'};
static wchar_t* LOOP_FLOW_OPERATION_CYBOL_MODEL = LOOP_FLOW_OPERATION_CYBOL_MODEL_ARRAY;
static int* LOOP_FLOW_OPERATION_CYBOL_MODEL_COUNT = NUMBER_4_INTEGER_MEMORY_MODEL_ARRAY;

/* FLOW_OPERATION_CYBOL_MODEL_SOURCE */
#endif
