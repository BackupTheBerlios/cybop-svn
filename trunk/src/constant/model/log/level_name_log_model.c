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
 * @version $RCSfile: level_name_log_model.c,v $ $Revision: 1.2 $ $Date: 2008-09-04 20:31:30 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef LEVEL_NAME_LOG_MODEL_SOURCE
#define LEVEL_NAME_LOG_MODEL_SOURCE

#include "../../../constant/model/memory/integer_memory_model.c"

/** The error level name log model. */
static wchar_t ERROR_LEVEL_NAME_LOG_MODEL_ARRAY[] = {L'E', L'r', L'r', L'o', L'r'};
static wchar_t* ERROR_LEVEL_NAME_LOG_MODEL = ERROR_LEVEL_NAME_LOG_MODEL_ARRAY;
static int* ERROR_LEVEL_NAME_LOG_MODEL_COUNT = NUMBER_5_INTEGER_MEMORY_MODEL_ARRAY;

/** The warning level name log model. */
static wchar_t WARNING_LEVEL_NAME_LOG_MODEL_ARRAY[] = {L'W', L'a', L'r', L'n', L'i', L'n', L'g'};
static wchar_t* WARNING_LEVEL_NAME_LOG_MODEL = WARNING_LEVEL_NAME_LOG_MODEL_ARRAY;
static int* WARNING_LEVEL_NAME_LOG_MODEL_COUNT = NUMBER_7_INTEGER_MEMORY_MODEL_ARRAY;

/** The information level name log model. */
static wchar_t INFORMATION_LEVEL_NAME_LOG_MODEL_ARRAY[] = {L'I', L'n', L'f', L'o', L'r', L'm', L'a', L't', L'i', L'o', L'n'};
static wchar_t* INFORMATION_LEVEL_NAME_LOG_MODEL = INFORMATION_LEVEL_NAME_LOG_MODEL_ARRAY;
static int* INFORMATION_LEVEL_NAME_LOG_MODEL_COUNT = NUMBER_11_INTEGER_MEMORY_MODEL_ARRAY;

/** The debug level name log model. */
static wchar_t DEBUG_LEVEL_NAME_LOG_MODEL_ARRAY[] = {L'D', L'e', L'b', L'u', L'g'};
static wchar_t* DEBUG_LEVEL_NAME_LOG_MODEL = DEBUG_LEVEL_NAME_LOG_MODEL_ARRAY;
static int* DEBUG_LEVEL_NAME_LOG_MODEL_COUNT = NUMBER_5_INTEGER_MEMORY_MODEL_ARRAY;

/* LEVEL_NAME_LOG_MODEL_SOURCE */
#endif
