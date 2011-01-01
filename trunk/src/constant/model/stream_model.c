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
 * @version $RCSfile: stream_model.c,v $ $Revision: 1.4 $ $Date: 2009-01-31 16:06:30 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef STREAM_MODEL_SOURCE
#define STREAM_MODEL_SOURCE

#include <stddef.h>
#include "../../constant/model/memory/integer_memory_model.c"

/** The standard input stream model. */
static wchar_t STANDARD_INPUT_STREAM_MODEL_ARRAY[] = {L's', L't', L'a', L'n', L'd', L'a', L'r', L'd', L'_', L'i', L'n', L'p', L'u', L't'};
static wchar_t* STANDARD_INPUT_STREAM_MODEL = STANDARD_INPUT_STREAM_MODEL_ARRAY;
static int* STANDARD_INPUT_STREAM_MODEL_COUNT = NUMBER_14_INTEGER_MEMORY_MODEL_ARRAY;

/** The standard output stream model. */
static wchar_t STANDARD_OUTPUT_STREAM_MODEL_ARRAY[] = {L's', L't', L'a', L'n', L'd', L'a', L'r', L'd', L'_', L'o', L'u', L't', L'p', L'u', L't'};
static wchar_t* STANDARD_OUTPUT_STREAM_MODEL = STANDARD_OUTPUT_STREAM_MODEL_ARRAY;
static int* STANDARD_OUTPUT_STREAM_MODEL_COUNT = NUMBER_15_INTEGER_MEMORY_MODEL_ARRAY;

/** The standard error output stream model. */
static wchar_t STANDARD_ERROR_OUTPUT_STREAM_MODEL_ARRAY[] = {L's', L't', L'a', L'n', L'd', L'a', L'r', L'd', L'_', L'e', L'r', L'r', L'o', L'r', L'_', L'o', L'u', L't', L'p', L'u', L't'};
static wchar_t* STANDARD_ERROR_OUTPUT_STREAM_MODEL = STANDARD_ERROR_OUTPUT_STREAM_MODEL_ARRAY;
static int* STANDARD_ERROR_OUTPUT_STREAM_MODEL_COUNT = NUMBER_21_INTEGER_MEMORY_MODEL_ARRAY;

/* STREAM_MODEL_SOURCE */
#endif
