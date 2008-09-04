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
 * @version $RCSfile: separator_cybol_name.c,v $ $Revision: 1.2 $ $Date: 2008-09-04 20:31:30 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef SEPARATOR_CYBOL_NAME_SOURCE
#define SEPARATOR_CYBOL_NAME_SOURCE

#include "../../../constant/model/memory/integer_memory_model.c"

/** The compound part separator cybol name. */
static wchar_t PART_SEPARATOR_CYBOL_NAME_ARRAY[] = {L'.'};
static wchar_t* PART_SEPARATOR_CYBOL_NAME = PART_SEPARATOR_CYBOL_NAME_ARRAY;
static int* PART_SEPARATOR_CYBOL_NAME_COUNT = NUMBER_1_INTEGER_MEMORY_MODEL_ARRAY;

/** The compound meta separator cybol name. */
static wchar_t META_SEPARATOR_CYBOL_NAME_ARRAY[] = {L'#'};
static wchar_t* META_SEPARATOR_CYBOL_NAME = META_SEPARATOR_CYBOL_NAME_ARRAY;
static int* META_SEPARATOR_CYBOL_NAME_COUNT = NUMBER_1_INTEGER_MEMORY_MODEL_ARRAY;

/** The operation parameter separator cybol name. */
static wchar_t PARAMETER_SEPARATOR_CYBOL_NAME_ARRAY[] = {L','};
static wchar_t* PARAMETER_SEPARATOR_CYBOL_NAME = PARAMETER_SEPARATOR_CYBOL_NAME_ARRAY;
static int* PARAMETER_SEPARATOR_CYBOL_NAME_COUNT = NUMBER_1_INTEGER_MEMORY_MODEL_ARRAY;

/** The list separator (between base name and index) cybol name. */
static wchar_t LIST_SEPARATOR_CYBOL_NAME_ARRAY[] = {L'_', L'$'};
static wchar_t* LIST_SEPARATOR_CYBOL_NAME = LIST_SEPARATOR_CYBOL_NAME_ARRAY;
static int* LIST_SEPARATOR_CYBOL_NAME_COUNT = NUMBER_2_INTEGER_MEMORY_MODEL_ARRAY;

/* SEPARATOR_CYBOL_NAME_SOURCE */
#endif
