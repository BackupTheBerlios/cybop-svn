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
 * @version $RCSfile: copy_unix_command_option_name.c,v $ $Revision: 1.3 $ $Date: 2008-10-25 23:20:04 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef COPY_UNIX_COMMAND_OPTION_NAME_SOURCE
#define COPY_UNIX_COMMAND_OPTION_NAME_SOURCE

#include <stddef.h>
#include "../../../../constant/model/memory/integer_memory_model.c"

/** The recursive copy unix command option name. */
static wchar_t RECURSIVE_COPY_UNIX_COMMAND_OPTION_NAME_ARRAY[] = {L'-', L'R'};
static wchar_t* RECURSIVE_COPY_UNIX_COMMAND_OPTION_NAME = RECURSIVE_COPY_UNIX_COMMAND_OPTION_NAME_ARRAY;
static int* RECURSIVE_COPY_UNIX_COMMAND_OPTION_NAME_COUNT = NUMBER_2_INTEGER_MEMORY_MODEL_ARRAY;

/** The source copy unix command option name. */
static wchar_t SOURCE_COPY_UNIX_COMMAND_OPTION_NAME_ARRAY[] = {L's', L'o', L'u', L'r', L'c', L'e'};
static wchar_t* SOURCE_COPY_UNIX_COMMAND_OPTION_NAME = SOURCE_COPY_UNIX_COMMAND_OPTION_NAME_ARRAY;
static int* SOURCE_COPY_UNIX_COMMAND_OPTION_NAME_COUNT = NUMBER_6_INTEGER_MEMORY_MODEL_ARRAY;

/** The destination copy unix command option name. */
static wchar_t DESTINATION_COPY_UNIX_COMMAND_OPTION_NAME_ARRAY[] = {L'd', L'e', L's', L't', L'i', L'n', L'a', L't', L'i', L'o', L'n'};
static wchar_t* DESTINATION_COPY_UNIX_COMMAND_OPTION_NAME = DESTINATION_COPY_UNIX_COMMAND_OPTION_NAME_ARRAY;
static int* DESTINATION_COPY_UNIX_COMMAND_OPTION_NAME_COUNT = NUMBER_11_INTEGER_MEMORY_MODEL_ARRAY;

/* COPY_UNIX_COMMAND_OPTION_NAME_SOURCE */
#endif
