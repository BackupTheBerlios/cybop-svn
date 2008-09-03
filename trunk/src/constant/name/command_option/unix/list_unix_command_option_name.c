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
 * @version $RCSfile: list_unix_command_option_name.c,v $ $Revision: 1.1 $ $Date: 2008-09-03 22:04:01 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef LIST_UNIX_COMMAND_OPTION_NAME_SOURCE
#define LIST_UNIX_COMMAND_OPTION_NAME_SOURCE

#include "../../../../constant/model/memory/integer_model.c"

/** The all list unix command option name. */
static wchar_t ALL_LIST_UNIX_COMMAND_OPTION_NAME_ARRAY[] = {L'-', L'-', L'a', L'l', L'l'};
static wchar_t* ALL_LIST_UNIX_COMMAND_OPTION_NAME = ALL_LIST_UNIX_COMMAND_OPTION_NAME_ARRAY;
static int* ALL_LIST_UNIX_COMMAND_OPTION_NAME_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The long listing list unix command option name. */
static wchar_t LONG_LISTING_LIST_UNIX_COMMAND_OPTION_NAME_ARRAY[] = {L'-', L'l'};
static wchar_t* LONG_LISTING_LIST_UNIX_COMMAND_OPTION_NAME = LONG_LISTING_LIST_UNIX_COMMAND_OPTION_NAME_ARRAY;
static int* LONG_LISTING_LIST_UNIX_COMMAND_OPTION_NAME_COUNT = NUMBER_2_INTEGER_ARRAY;

/* LIST_UNIX_COMMAND_OPTION_NAME_SOURCE */
#endif
