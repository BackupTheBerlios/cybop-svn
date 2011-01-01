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
 * @version $RCSfile: shell_unix_command_option_name.c,v $ $Revision: 1.4 $ $Date: 2009-01-31 16:06:30 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef SHELL_UNIX_COMMAND_OPTION_NAME_SOURCE
#define SHELL_UNIX_COMMAND_OPTION_NAME_SOURCE

#include <stddef.h>
#include "../../../../constant/model/memory/integer_memory_model.c"

/** The character shell unix command option name. */
static wchar_t CHARACTER_SHELL_UNIX_COMMAND_OPTION_NAME_ARRAY[] = {L'-', L'c'};
static wchar_t* CHARACTER_SHELL_UNIX_COMMAND_OPTION_NAME = CHARACTER_SHELL_UNIX_COMMAND_OPTION_NAME_ARRAY;
static int* CHARACTER_SHELL_UNIX_COMMAND_OPTION_NAME_COUNT = NUMBER_2_INTEGER_MEMORY_MODEL_ARRAY;

/* SHELL_UNIX_COMMAND_OPTION_NAME_SOURCE */
#endif
