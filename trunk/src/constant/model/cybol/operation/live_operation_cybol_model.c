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
 * @version $RCSfile: lifecycle_operation_cybol_model.c,v $ $Revision: 1.6 $ $Date: 2009-01-31 16:06:30 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef LIVE_OPERATION_CYBOL_MODEL_SOURCE
#define LIVE_OPERATION_CYBOL_MODEL_SOURCE

#include <stddef.h>

#include "../../../../constant/model/memory/integer_memory_model.c"

/** The exit live operation cybol model. */
static wchar_t EXIT_LIVE_OPERATION_CYBOL_MODEL_ARRAY[] = {L'e', L'x', L'i', L't'};
static wchar_t* EXIT_LIVE_OPERATION_CYBOL_MODEL = EXIT_LIVE_OPERATION_CYBOL_MODEL_ARRAY;
static int* EXIT_LIVE_OPERATION_CYBOL_MODEL_COUNT = NUMBER_4_INTEGER_MEMORY_MODEL_ARRAY;

/** The interrupt live operation cybol model. */
static wchar_t INTERRUPT_LIVE_OPERATION_CYBOL_MODEL_ARRAY[] = {L'i', L'n', L't', L'e', L'r', L'r', L'u', L'p', L't'};
static wchar_t* INTERRUPT_LIVE_OPERATION_CYBOL_MODEL = INTERRUPT_LIVE_OPERATION_CYBOL_MODEL_ARRAY;
static int* INTERRUPT_LIVE_OPERATION_CYBOL_MODEL_COUNT = NUMBER_9_INTEGER_MEMORY_MODEL_ARRAY;

/** The sense live operation cybol model. */
static wchar_t SENSE_LIVE_OPERATION_CYBOL_MODEL_ARRAY[] = {L's', L'e', L'n', L's', L'e'};
static wchar_t* SENSE_LIVE_OPERATION_CYBOL_MODEL = SENSE_LIVE_OPERATION_CYBOL_MODEL_ARRAY;
static int* SENSE_LIVE_OPERATION_CYBOL_MODEL_COUNT = NUMBER_5_INTEGER_MEMORY_MODEL_ARRAY;

/* LIVE_OPERATION_CYBOL_MODEL_SOURCE */
#endif
