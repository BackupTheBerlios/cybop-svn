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
 * @version $RCSfile: file_operation_cybol_model.c,v $ $Revision: 1.1 $ $Date: 2009-01-07 01:14:05 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef FILE_OPERATION_CYBOL_MODEL_SOURCE
#define FILE_OPERATION_CYBOL_MODEL_SOURCE

#include <stddef.h>
#include "../../../../constant/model/memory/integer_memory_model.c"

/** The archive file operation cybol model. */
static wchar_t ARCHIVE_FILE_OPERATION_CYBOL_MODEL_ARRAY[] = {L'a', L'r', L'c', L'h', L'i', L'v', L'e'};
static wchar_t* ARCHIVE_FILE_OPERATION_CYBOL_MODEL = ARCHIVE_FILE_OPERATION_CYBOL_MODEL_ARRAY;
static int* ARCHIVE_FILE_OPERATION_CYBOL_MODEL_COUNT = NUMBER_7_INTEGER_MEMORY_MODEL_ARRAY;

/** The copy file operation cybol model. */
static wchar_t COPY_FILE_OPERATION_CYBOL_MODEL_ARRAY[] = {L'c', L'o', L'p', L'y'};
static wchar_t* COPY_FILE_OPERATION_CYBOL_MODEL = COPY_FILE_OPERATION_CYBOL_MODEL_ARRAY;
static int* COPY_FILE_OPERATION_CYBOL_MODEL_COUNT = NUMBER_4_INTEGER_MEMORY_MODEL_ARRAY;

/** The list_directory_contents file operation cybol model. */
static wchar_t LIST_DIRECTORY_CONTENTS_FILE_OPERATION_CYBOL_MODEL_ARRAY[] = {L'l', L'i', L's', L't', L'_', L'd', L'i', L'r', L'e', L'c', L't', L'o', L'r', L'y', L'_', L'c', L'o', L'n', L't', L'e', L'n', L't', L's'};
static wchar_t* LIST_DIRECTORY_CONTENTS_FILE_OPERATION_CYBOL_MODEL = LIST_DIRECTORY_CONTENTS_FILE_OPERATION_CYBOL_MODEL_ARRAY;
static int* LIST_DIRECTORY_CONTENTS_FILE_OPERATION_CYBOL_MODEL_COUNT = NUMBER_23_INTEGER_MEMORY_MODEL_ARRAY;

/* FILE_OPERATION_CYBOL_MODEL_SOURCE */
#endif
