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
 * @version $RCSfile: memory_operation_cybol_model.c,v $ $Revision: 1.5 $ $Date: 2009-01-31 16:06:30 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef MAINTAIN_OPERATION_CYBOL_MODEL_SOURCE
#define MAINTAIN_OPERATION_CYBOL_MODEL_SOURCE

#include <stddef.h>

#include "../../../../constant/model/memory/integer_memory_model.c"

/** The shutdown maintain operation cybol model. */
static wchar_t SHUTDOWN_MAINTAIN_OPERATION_CYBOL_MODEL_ARRAY[] = {L's', L'h', L'u', L't', L'd', L'o', L'w', L'n'};
static wchar_t* SHUTDOWN_MAINTAIN_OPERATION_CYBOL_MODEL = SHUTDOWN_MAINTAIN_OPERATION_CYBOL_MODEL_ARRAY;
static int* SHUTDOWN_MAINTAIN_OPERATION_CYBOL_MODEL_COUNT = NUMBER_8_INTEGER_MEMORY_MODEL_ARRAY;

/** The startup maintain operation cybol model. */
static wchar_t STARTUP_MAINTAIN_OPERATION_CYBOL_MODEL_ARRAY[] = {L's', L't', L'a', L'r', L't', L'u', L'p'};
static wchar_t* STARTUP_MAINTAIN_OPERATION_CYBOL_MODEL = STARTUP_MAINTAIN_OPERATION_CYBOL_MODEL_ARRAY;
static int* STARTUP_MAINTAIN_OPERATION_CYBOL_MODEL_COUNT = NUMBER_7_INTEGER_MEMORY_MODEL_ARRAY;

/* MAINTAIN_OPERATION_CYBOL_MODEL_SOURCE */
#endif
