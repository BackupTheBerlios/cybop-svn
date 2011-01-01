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
 * @version $RCSfile: lifecycle_operation_cybol_name.c,v $ $Revision: 1.4 $ $Date: 2009-01-31 16:06:30 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef LIFECYCLE_OPERATION_CYBOL_NAME_SOURCE
#define LIFECYCLE_OPERATION_CYBOL_NAME_SOURCE

#include <stddef.h>
#include "../../../../constant/model/memory/integer_memory_model.c"

/** The service lifecycle operation cybol name. */
static wchar_t SERVICE_LIFECYCLE_OPERATION_CYBOL_NAME_ARRAY[] = {L's', L'e', L'r', L'v', L'i', L'c', L'e'};
static wchar_t* SERVICE_LIFECYCLE_OPERATION_CYBOL_NAME = SERVICE_LIFECYCLE_OPERATION_CYBOL_NAME_ARRAY;
static int* SERVICE_LIFECYCLE_OPERATION_CYBOL_NAME_COUNT = NUMBER_7_INTEGER_MEMORY_MODEL_ARRAY;

/** The namespace lifecycle operation cybol name. */
static wchar_t NAMESPACE_LIFECYCLE_OPERATION_CYBOL_NAME_ARRAY[] = {L'n', L'a', L'm', L'e', L's', L'p', L'a', L'c', L'e'};
static wchar_t* NAMESPACE_LIFECYCLE_OPERATION_CYBOL_NAME = NAMESPACE_LIFECYCLE_OPERATION_CYBOL_NAME_ARRAY;
static int* NAMESPACE_LIFECYCLE_OPERATION_CYBOL_NAME_COUNT = NUMBER_9_INTEGER_MEMORY_MODEL_ARRAY;

/** The style lifecycle operation cybol name. */
static wchar_t STYLE_LIFECYCLE_OPERATION_CYBOL_NAME_ARRAY[] = {L's', L't', L'y', L'l', L'e'};
static wchar_t* STYLE_LIFECYCLE_OPERATION_CYBOL_NAME = STYLE_LIFECYCLE_OPERATION_CYBOL_NAME_ARRAY;
static int* STYLE_LIFECYCLE_OPERATION_CYBOL_NAME_COUNT = NUMBER_5_INTEGER_MEMORY_MODEL_ARRAY;

/** The address lifecycle operation cybol name. */
static wchar_t ADDRESS_LIFECYCLE_OPERATION_CYBOL_NAME_ARRAY[] = {L'a', L'd', L'd', L'r', L'e', L's', L's'};
static wchar_t* ADDRESS_LIFECYCLE_OPERATION_CYBOL_NAME = ADDRESS_LIFECYCLE_OPERATION_CYBOL_NAME_ARRAY;
static int* ADDRESS_LIFECYCLE_OPERATION_CYBOL_NAME_COUNT = NUMBER_7_INTEGER_MEMORY_MODEL_ARRAY;

/* LIFECYCLE_OPERATION_CYBOL_NAME_SOURCE */
#endif
