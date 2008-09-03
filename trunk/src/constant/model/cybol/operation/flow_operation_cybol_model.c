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
 * @version $RCSfile: flow_operation_cybol_model.c,v $ $Revision: 1.1 $ $Date: 2008-09-03 22:04:01 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef FLOW_OPERATION_CYBOL_MODEL_SOURCE
#define FLOW_OPERATION_CYBOL_MODEL_SOURCE

#include "../../../../constant/model/memory/integer_model.c"

/** The branch flow operation cybol model. */
static wchar_t BRANCH_FLOW_OPERATION_CYBOL_MODEL_ARRAY[] = {L'b', L'r', L'a', L'n', L'c', L'h'};
static wchar_t* BRANCH_FLOW_OPERATION_CYBOL_MODEL = BRANCH_FLOW_OPERATION_CYBOL_MODEL_ARRAY;
static int* BRANCH_FLOW_OPERATION_CYBOL_MODEL_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The loop flow operation cybol model. */
static wchar_t LOOP_FLOW_OPERATION_CYBOL_MODEL_ARRAY[] = {L'l', L'o', L'o', L'p'};
static wchar_t* LOOP_FLOW_OPERATION_CYBOL_MODEL = LOOP_FLOW_OPERATION_CYBOL_MODEL_ARRAY;
static int* LOOP_FLOW_OPERATION_CYBOL_MODEL_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The count flow operation cybol model. */
static wchar_t COUNT_FLOW_OPERATION_CYBOL_MODEL_ARRAY[] = {L'c', L'o', L'u', L'n', L't'};
static wchar_t* COUNT_FLOW_OPERATION_CYBOL_MODEL = COUNT_FLOW_OPERATION_CYBOL_MODEL_ARRAY;
static int* COUNT_FLOW_OPERATION_CYBOL_MODEL_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The build listname flow operation cybol model. */
static wchar_t BUILD_LISTNAME_FLOW_OPERATION_CYBOL_MODEL_ARRAY[] = {L'b', L'u', L'i', L'l', L'd', L'_', L'l', L'i', L's', L't', L'n', L'a', L'm', L'e'};
static wchar_t* BUILD_LISTNAME_FLOW_OPERATION_CYBOL_MODEL = BUILD_LISTNAME_FLOW_OPERATION_CYBOL_MODEL_ARRAY;
static int* BUILD_LISTNAME_FLOW_OPERATION_CYBOL_MODEL_COUNT = NUMBER_14_INTEGER_ARRAY;

/** The get flow operation cybol model. */
static wchar_t GET_FLOW_OPERATION_CYBOL_MODEL_ARRAY[] = {L'g', L'e', L't'};
static wchar_t* GET_FLOW_OPERATION_CYBOL_MODEL = GET_FLOW_OPERATION_CYBOL_MODEL_ARRAY;
static int* GET_FLOW_OPERATION_CYBOL_MODEL_COUNT = NUMBER_3_INTEGER_ARRAY;

/* FLOW_OPERATION_CYBOL_MODEL_SOURCE */
#endif
