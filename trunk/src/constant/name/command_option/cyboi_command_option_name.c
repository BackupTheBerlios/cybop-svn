/*
 * Copyright (C) 1999-2010. Christian Heller.
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
 * @version $RCSfile: cyboi_command_option_name.c,v $ $Revision: 1.5 $ $Date: 2009-01-31 16:06:30 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CYBOI_COMMAND_OPTION_NAME_SOURCE
#define CYBOI_COMMAND_OPTION_NAME_SOURCE

#include <stddef.h>
#include "../../../constant/model/memory/integer_memory_model.c"

/** The "--help" cyboi command option name. */
static wchar_t HELP_CYBOI_COMMAND_OPTION_NAME_ARRAY[] = {L'-', L'-', L'h', L'e', L'l', L'p'};
static wchar_t* HELP_CYBOI_COMMAND_OPTION_NAME = HELP_CYBOI_COMMAND_OPTION_NAME_ARRAY;
static int* HELP_CYBOI_COMMAND_OPTION_NAME_COUNT = NUMBER_6_INTEGER_MEMORY_MODEL_ARRAY;

/** The "--knowledge" cyboi command option name. */
static wchar_t KNOWLEDGE_CYBOI_COMMAND_OPTION_NAME_ARRAY[] = {L'-', L'-', L'k', L'n', L'o', L'w', L'l', L'e', L'd', L'g', L'e'};
static wchar_t* KNOWLEDGE_CYBOI_COMMAND_OPTION_NAME = KNOWLEDGE_CYBOI_COMMAND_OPTION_NAME_ARRAY;
static int* KNOWLEDGE_CYBOI_COMMAND_OPTION_NAME_COUNT = NUMBER_11_INTEGER_MEMORY_MODEL_ARRAY;

/** The "--logfile" cyboi command option name. */
static wchar_t LOG_FILE_CYBOI_COMMAND_OPTION_NAME_ARRAY[] = {L'-', L'-', L'l', L'o', L'g', L'f', L'i', L'l', L'e'};
static wchar_t* LOG_FILE_CYBOI_COMMAND_OPTION_NAME = LOG_FILE_CYBOI_COMMAND_OPTION_NAME_ARRAY;
static int* LOG_FILE_CYBOI_COMMAND_OPTION_NAME_COUNT = NUMBER_9_INTEGER_MEMORY_MODEL_ARRAY;

/** The "--loglevel" cyboi command option name. */
static wchar_t LOG_LEVEL_CYBOI_COMMAND_OPTION_NAME_ARRAY[] = {L'-', L'-', L'l', L'o', L'g', L'l', L'e', L'v', L'e', L'l'};
static wchar_t* LOG_LEVEL_CYBOI_COMMAND_OPTION_NAME = LOG_LEVEL_CYBOI_COMMAND_OPTION_NAME_ARRAY;
static int* LOG_LEVEL_CYBOI_COMMAND_OPTION_NAME_COUNT = NUMBER_10_INTEGER_MEMORY_MODEL_ARRAY;

/** The "--test" cyboi command option name. */
static wchar_t TEST_CYBOI_COMMAND_OPTION_NAME_ARRAY[] = {L'-', L'-', L't', L'e', L's', L't'};
static wchar_t* TEST_CYBOI_COMMAND_OPTION_NAME = TEST_CYBOI_COMMAND_OPTION_NAME_ARRAY;
static int* TEST_CYBOI_COMMAND_OPTION_NAME_COUNT = NUMBER_6_INTEGER_MEMORY_MODEL_ARRAY;

/** The "--version" cyboi command option name. */
static wchar_t VERSION_CYBOI_COMMAND_OPTION_NAME_ARRAY[] = {L'-', L'-', L'v', L'e', L'r', L's', L'i', L'o', L'n'};
static wchar_t* VERSION_CYBOI_COMMAND_OPTION_NAME = VERSION_CYBOI_COMMAND_OPTION_NAME_ARRAY;
static int* VERSION_CYBOI_COMMAND_OPTION_NAME_COUNT = NUMBER_9_INTEGER_MEMORY_MODEL_ARRAY;

/* CYBOI_COMMAND_OPTION_NAME_SOURCE */
#endif
