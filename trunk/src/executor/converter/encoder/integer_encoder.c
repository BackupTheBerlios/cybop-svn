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
 * @version $RCSfile: integer_converter.c,v $ $Revision: 1.37 $ $Date: 2009-01-31 16:06:33 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef INTEGER_ENCODER_SOURCE
#define INTEGER_ENCODER_SOURCE

#ifdef CYGWIN_ENVIRONMENT
#include <windows.h>
/* CYGWIN_ENVIRONMENT */
#endif

#include <stdio.h>
#include <string.h>
#include <wchar.h>
#include "../../../constant/abstraction/cybol/text_cybol_abstraction.c"
#include "../../../constant/abstraction/memory/memory_abstraction.c"
#include "../../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../../constant/model/character_code/unicode/unicode_character_code_model.c"
#include "../../../constant/model/log/message_log_model.c"
#include "../../../constant/model/memory/integer_memory_model.c"
#include "../../../constant/model/memory/pointer_memory_model.c"
#include "../../../constant/name/memory/primitive_memory_name.c"
#include "../../../executor/memoriser/allocator.c"
#include "../../../logger/logger.c"

/**
 * Encodes the integer model and creates a wide character array from it.
 *
 * @param p0 the destination wide character array (Hand over as reference!)
 * @param p1 the destination wide character array count
 * @param p2 the destination wide character array size
 * @param p3 the source integer number
 * @param p4 the source integer number count
 */
void encode_integer(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p2 != *NULL_POINTER_MEMORY_MODEL) {

        int* ds = (int*) p2;

        if (p1 != *NULL_POINTER_MEMORY_MODEL) {

            int* dc = (int*) p1;

            if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                wchar_t** d = (wchar_t**) p0;

                log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Encode integer into wide character.");

/*??
    fwprintf(stdout, L"TEST encode integer into wide character 0 ds: %i\n", *ds);
    fwprintf(stdout, L"TEST encode integer into wide character 0 dc: %i\n", *dc);
    fwprintf(stdout, L"TEST encode integer into wide character 0 d: %ls\n", *d);
*/

                // The integer value.
                void* v = *NULL_POINTER_MEMORY_MODEL;

                // Get integer value.
                get_array_elements((void*) &v, p3, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) INTEGER_PRIMITIVE_MEMORY_ABSTRACTION);

/*??
    fwprintf(stdout, L"TEST encode integer into wide character 1 v: %i\n", *v);
*/

                // Set destination size.
                // CAUTION! The old destination size is used as summand,
                // so that it can grow stepwise, in case this function
                // has been called recursively by itself.
                // CAUTION! Do NOT use the destination count here,
                // since it is left at its initial value
                // as long as the conversion was not successful,
                // so that the size would not grow here.
                *ds = *ds + *NUMBER_1_INTEGER_MEMORY_MODEL;

/*??
    fwprintf(stdout, L"TEST encode integer into wide character 2 ds: %i\n", *ds);
    fwprintf(stdout, L"TEST encode integer into wide character 2 dc: %i\n", *dc);
    fwprintf(stdout, L"TEST encode integer into wide character 2 d: %ls\n", *d);
*/

                // Reallocate destination string.
                reallocate_array(p0, p1, p2, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                // Transform source integer to destination string.
                // A null wide character is written to mark the end of the string.
                // The return value is the number of characters generated
                // for the given input, excluding the trailing null.
                // If not all output fits into the provided buffer,
                // a negative value is returned.
#ifdef CYGWIN_ENVIRONMENT
                int test = wsprintfW(*d, L"%i", *((int*) v));
/* CYGWIN_ENVIRONMENT */
#else
                int test = swprintf(*d, *ds, L"%i", *((int*) v));
/* CYGWIN_ENVIRONMENT */
#endif

/*??
    fwprintf(stdout, L"TEST encode integer into wide character 3 ds: %i\n", *ds);
    fwprintf(stdout, L"TEST encode integer into wide character 3 dc: %i\n", *dc);
    fwprintf(stdout, L"TEST encode integer into wide character 3 d: %ls\n", *d);
*/

                if (test >= *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    // The integer was converted successfully.

                    // Set destination count.
                    *dc = test;

/*??
    fwprintf(stdout, L"TEST encode integer into wide character 4 dc: %i\n", *dc);
*/

                } else {

                    // The value returned by the conversion function is negative,
                    // which means that the integer was NOT converted successfully.

                    // Call this function itself recursively.
                    // This is done every time again, until the integer
                    // gets finally converted successfully.
                    // The only argument that grows is the destination size p2 (== *ds).
                    encode_integer(p0, p1, p2, p3, p4);
                }

/*??
    fwprintf(stdout, L"TEST encode integer into wide character 5 dc: %i\n", *dc);
*/

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not encode integer into wide character. The destination is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not encode integer into wide character. The destination count is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not encode integer into wide character. The destination size is null.");
    }
}

/* INTEGER_ENCODER_SOURCE */
#endif
