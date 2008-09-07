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
 * @version $RCSfile: lifecycle_operation_cybol_model.c,v $ $Revision: 1.3 $ $Date: 2008-09-07 23:01:38 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef LIFECYCLE_OPERATION_CYBOL_MODEL_SOURCE
#define LIFECYCLE_OPERATION_CYBOL_MODEL_SOURCE

#include "../../../../constant/model/memory/integer_memory_model.c"

/** The exit lifecycle operation cybol model. */
static wchar_t EXIT_LIFECYCLE_OPERATION_CYBOL_MODEL_ARRAY[] = {L'e', L'x', L'i', L't'};
static wchar_t* EXIT_LIFECYCLE_OPERATION_CYBOL_MODEL = EXIT_LIFECYCLE_OPERATION_CYBOL_MODEL_ARRAY;
static int* EXIT_LIFECYCLE_OPERATION_CYBOL_MODEL_COUNT = NUMBER_4_INTEGER_MEMORY_MODEL_ARRAY;

/** The shutdown lifecycle operation cybol model. */
static wchar_t SHUTDOWN_LIFECYCLE_OPERATION_CYBOL_MODEL_ARRAY[] = {L's', L'h', L'u', L't', L'd', L'o', L'w', L'n'};
static wchar_t* SHUTDOWN_LIFECYCLE_OPERATION_CYBOL_MODEL = SHUTDOWN_LIFECYCLE_OPERATION_CYBOL_MODEL_ARRAY;
static int* SHUTDOWN_LIFECYCLE_OPERATION_CYBOL_MODEL_COUNT = NUMBER_8_INTEGER_MEMORY_MODEL_ARRAY;

/** The startup lifecycle operation cybol model. */
static wchar_t STARTUP_LIFECYCLE_OPERATION_CYBOL_MODEL_ARRAY[] = {L's', L't', L'a', L'r', L't', L'u', L'p'};
static wchar_t* STARTUP_LIFECYCLE_OPERATION_CYBOL_MODEL = STARTUP_LIFECYCLE_OPERATION_CYBOL_MODEL_ARRAY;
static int* STARTUP_LIFECYCLE_OPERATION_CYBOL_MODEL_COUNT = NUMBER_7_INTEGER_MEMORY_MODEL_ARRAY;

/* LIFECYCLE_OPERATION_CYBOL_MODEL_SOURCE */
#endif
