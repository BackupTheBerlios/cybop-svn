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
 * @version $RCSfile: unix_command_model.c,v $ $Revision: 1.2 $ $Date: 2008-09-04 20:31:30 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef UNIX_COMMAND_MODEL_SOURCE
#define UNIX_COMMAND_MODEL_SOURCE

#include "../../../constant/model/memory/integer_memory_model.c"

/** The shell unix command model. */
static wchar_t SHELL_UNIX_COMMAND_MODEL_ARRAY[] = {L'/', L'b', L'i', L'n', L'/', L's', L'h'};
static wchar_t* SHELL_UNIX_COMMAND_MODEL = SHELL_UNIX_COMMAND_MODEL_ARRAY;
static int* SHELL_UNIX_COMMAND_MODEL_COUNT = NUMBER_7_INTEGER_MEMORY_MODEL_ARRAY;

/** The archive unix command model. */
static wchar_t ARCHIVE_UNIX_COMMAND_MODEL_ARRAY[] = {L'a', L'r', L'c', L'h', L'i', L'v', L'e'};
static wchar_t* ARCHIVE_UNIX_COMMAND_MODEL = ARCHIVE_UNIX_COMMAND_MODEL_ARRAY;
static int* ARCHIVE_UNIX_COMMAND_MODEL_COUNT = NUMBER_7_INTEGER_MEMORY_MODEL_ARRAY;

/** The copy unix command model. */
static wchar_t COPY_UNIX_COMMAND_MODEL_ARRAY[] = {L'c', L'o', L'p', L'y'};
static wchar_t* COPY_UNIX_COMMAND_MODEL = COPY_UNIX_COMMAND_MODEL_ARRAY;
static int* COPY_UNIX_COMMAND_MODEL_COUNT = NUMBER_4_INTEGER_MEMORY_MODEL_ARRAY;

/** The list directory contents unix command model. */
static wchar_t LIST_DIRECTORY_CONTENTS_UNIX_COMMAND_MODEL_ARRAY[] = {L'l', L's'};
static wchar_t* LIST_DIRECTORY_CONTENTS_UNIX_COMMAND_MODEL = LIST_DIRECTORY_CONTENTS_UNIX_COMMAND_MODEL_ARRAY;
static int* LIST_DIRECTORY_CONTENTS_UNIX_COMMAND_MODEL_COUNT = NUMBER_2_INTEGER_MEMORY_MODEL_ARRAY;

/* UNIX_COMMAND_MODEL_SOURCE */
#endif
