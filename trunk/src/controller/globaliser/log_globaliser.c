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
 * @version $RCSfile: globaliser.c,v $ $Revision: 1.13 $ $Date: 2009-01-31 16:06:30 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef LOG_GLOBALISER_SOURCE
#define LOG_GLOBALISER_SOURCE

#include "../../constant/model/log/level_log_model.c"
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../variable/type_size/integral_type_size.c"
#include "../../variable/log_setting.c"

/**
 * Allocates and initialises log global variables.
 */
void globalise_log() {

    // Allocate and initialise log level.
    LOG_LEVEL = (signed char*) malloc(*SIGNED_CHARACTER_INTEGRAL_TYPE_SIZE);
    *LOG_LEVEL = *OFF_LEVEL_LOG_MODEL;

    // Allocate and initialise log message count.
    LOG_MESSAGE_COUNT = (signed short int*) malloc(*SIGNED_SHORT_INTEGER_INTEGRAL_TYPE_SIZE);
    *LOG_MESSAGE_COUNT = *NUMBER_10000_INTEGER_MEMORY_MODEL;

    // Allocate log message.
    LOG_MESSAGE = (wchar_t*) malloc(*LOG_MESSAGE_COUNT);

    // CAUTION! Do NOT try to allocate or initialise the log output of type FILE!
    //
    // FILE objects are allocated and managed internally by the input/ output
    // library functions. The library creates objects of type FILE.
    // Programs should deal only with pointers to these objects (FILE* values),
    // rather than the objects themselves.
    //
    // See module "optionaliser.c", which cares about log file creation!
    //
    // Hence, the following line would not make sense and is FORBIDDEN:
    // LOG_OUTPUT = (FILE*) malloc(sizeof(FILE));
    LOG_OUTPUT = *NULL_POINTER_MEMORY_MODEL;
}

/* LOG_GLOBALISER_SOURCE */
#endif
