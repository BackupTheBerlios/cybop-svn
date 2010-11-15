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
 * @version $RCSfile: globaliser.c,v $ $Revision: 1.13 $ $Date: 2009-01-31 16:06:30 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef LOG_UNGLOBALISER_SOURCE
#define LOG_UNGLOBALISER_SOURCE

#include <stdlib.h>

/**
 * Deallocates log global variables.
 */
void unglobalise_log() {

    // Free log level.
    free((void*) LOG_LEVEL);

    // Free log message count.
    free((void*) LOG_MESSAGE_COUNT);

    // Free log message.
    free((void*) LOG_MESSAGE);

    // CAUTION! Do NOT try to free the log output of type FILE!
    // It was already closed in module "optionaliser.c".
    //
    // FILE objects are allocated and managed internally by the input/ output
    // library functions. The library creates objects of type FILE.
    // Programs should deal only with pointers to these objects (FILE* values),
    // rather than the objects themselves.
    //
    // Hence, the following line would not make sense and is FORBIDDEN:
    // free(LOG_OUTPUT);
}

/* LOG_UNGLOBALISER_SOURCE */
#endif
