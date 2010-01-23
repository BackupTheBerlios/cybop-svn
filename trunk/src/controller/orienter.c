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
 * @version $RCSfile: orienter.c,v $ $Revision: 1.7 $ $Date: 2009-01-31 16:06:31 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef ORIENTER_SOURCE
#define ORIENTER_SOURCE

#include "../constant/model/memory/pointer_memory_model.c"

/**
 * Deoptionalises the given command line argument options.
 *
 * @param p0 the stream
 * @param p1 the orientation (positive value: wide character; negative value: narrow character)
 */
void orient(void* p0, void* p1) {

    if (p1 != *NULL_POINTER_MEMORY_MODEL) {

        int* o = (int*) p1;

        if (p0 != *NULL_POINTER_MEMORY_MODEL) {

            FILE* s = (FILE*) p0;

            // CAUTION! DO NOT use logging functionality here!
            // The logger will not work before its options are set.
            // Do NOT show the following error message, as it would only disturb the user!
            // log_write_terminated_message(stdout, L"Information: Orient stream.\n");

            // Set stream orientation.
            fwide(s, *o);

        } else {

            // CAUTION! DO NOT use logging functionality here!
            // The logger will not work before its options are set.
            // Do NOT show the following error message, as it would only disturb the user!
            // log_write_terminated_message(stdout, L"Error: Could not orient stream. The stream is null.\n");
        }

    } else {

        // CAUTION! DO NOT use logging functionality here!
        // The logger will not work before its options are set.
        // log_write_terminated_message(stdout, L"Error: Could not orient stream. The orientation is null.\n");
    }
}

/* ORIENTER_SOURCE */
#endif
