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
 * @version $RCSfile: integer_converter.c,v $ $Revision: 1.34 $ $Date: 2008-11-29 23:14:25 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef INTEGER_CONVERTER_SOURCE
#define INTEGER_CONVERTER_SOURCE

#ifdef CYGWIN_ENVIRONMENT
#include <windows.h>
/* CYGWIN_ENVIRONMENT */
#endif

#include <stdio.h>
#include <string.h>
#include <wchar.h>
#include "../../constant/model/character_code/unicode/unicode_character_code_model.c"
#include "../../constant/abstraction/cybol/text_cybol_abstraction.c"
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../constant/model/log/message_log_model.c"
#include "../../constant/abstraction/memory/array_memory_abstraction.c"
#include "../../constant/abstraction/memory/memory_abstraction.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../logger/logger.c"
#include "../../variable/reallocation_factor.c"
#include "../../memoriser/allocator.c"

/**
 * Decodes the wide character array and creates an integer from it.
 *
 * CAUTION! Do not mix up "integer" and "integer_vector"!
 * The latter is an array storing one or many integer numbers at different indexes.
 *
 * This operation has an integer as result, so a normal integer pointer
 * and NOT an integer pointer pointer (integer array) is handed over as p0.
 *
 * @param p0 the destination integer number (Hand over as reference!)
 * @param p1 the destination integer number count
 * @param p2 the destination integer number size
 * @param p3 the source wide character array
 * @param p4 the source wide character array count
 */
void decode_integer(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p4 != *NULL_POINTER_MEMORY_MODEL) {

        int* sc = (int*) p4;

        if (p0 != *NULL_POINTER_MEMORY_MODEL) {

            int* d = (int*) p0;

            log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Decode integer.");

            // The temporary null-terminated string.
            wchar_t* tmp = (wchar_t*) *NULL_POINTER_MEMORY_MODEL;
            int tmps = *sc + *NUMBER_1_INTEGER_MEMORY_MODEL;

            // Create temporary null-terminated string.
            allocate_array((void*) &tmp, (void*) &tmps, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

            // Copy original string to temporary null-terminated string.
            set_array_elements((void*) tmp, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, p3, p4, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
            // Add string termination to temporary null-terminated string.
            // The source count is used as index for the termination character.
            set_array_elements((void*) tmp, p4, (void*) NULL_CONTROL_UNICODE_CHARACTER_CODE_MODEL, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

            // The tail variable is useless here and only needed for the string
            // transformation function. If the whole string array consists of
            // many sub strings, separated by space characters, then each sub
            // string gets interpreted as integer number.
            // The tail variable in this case points to the remaining sub string.
            wchar_t* tail = (wchar_t*) *NULL_POINTER_MEMORY_MODEL;

            // Set integer value.
            //
            // Transform string to integer value.
            // The third parameter is the number base:
            // 0 - tries to automatically identify the correct number base
            // 8 - octal
            // 10 - decimal
            // 16 - hexadecimal
            *d = wcstol(tmp, &tail, *NUMBER_10_INTEGER_MEMORY_MODEL);

            // Destroy temporary null-terminated string.
            deallocate_array((void*) &tmp, (void*) &tmps, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode integer. The destination is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode integer. The source count is null.");
    }
}

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

    fwprintf(stdout, L"TEST encode integer into wide character 0 ds: %i\n", *ds);
    fwprintf(stdout, L"TEST encode integer into wide character 0 dc: %i\n", *dc);
    fwprintf(stdout, L"TEST encode integer into wide character 0 d: %ls\n", *d);

                // The integer value.
                int* v = (int*) *NULL_POINTER_MEMORY_MODEL;

                // Get integer value.
                get_array_elements(p3, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) &v, (void*) INTEGER_ARRAY_MEMORY_ABSTRACTION);

    fwprintf(stdout, L"TEST encode integer into wide character 1 v: %i\n", *v);

                // Set destination size.
                // CAUTION! The old destination size is used as summand,
                // so that it can grow stepwise, in case this function
                // has been called recursively by itself.
                // The addition of number one, on the other hand,
                // is necessary to avoid a zero size resulting from
                // a possible multiplication with zero.
                *ds = *ds + (*dc * *WIDE_CHARACTER_VECTOR_REALLOCATION_FACTOR) + *NUMBER_1_INTEGER_MEMORY_MODEL;

    fwprintf(stdout, L"TEST encode integer into wide character 2 ds: %i\n", *ds);
    fwprintf(stdout, L"TEST encode integer into wide character 2 dc: %i\n", *dc);
    fwprintf(stdout, L"TEST encode integer into wide character 2 d: %ls\n", *d);

                // Reallocate destination string.
                reallocate_array(p0, p1, p2, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

                // Transform source integer to destination string.
                // A null wide character is written to mark the end of the string.
                // The return value is the number of characters generated
                // for the given input, excluding the trailing null.
                // If not all output fits into the provided buffer,
                // a negative value is returned.
#ifdef CYGWIN_ENVIRONMENT
                int test = wsprintfW(*d, L"%i", *v);
/* CYGWIN_ENVIRONMENT */
#else
                int test = swprintf(*d, *ds, L"%i", *v);
/* CYGWIN_ENVIRONMENT */
#endif

    fwprintf(stdout, L"TEST encode integer into wide character 3 ds: %i\n", *ds);
    fwprintf(stdout, L"TEST encode integer into wide character 3 dc: %i\n", *dc);
    fwprintf(stdout, L"TEST encode integer into wide character 3 d: %ls\n", *d);

                if (test >= *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    // The integer was converted successfully.

                    // Set destination count.
                    *dc = test;

    fwprintf(stdout, L"TEST encode integer into wide character 4 dc: %i\n", *dc);

                } else {

                    // The value returned by the conversion function is negative,
                    // which means that the integer was NOT converted successfully.

                    // Call this function itself recursively.
                    // This is done every time again, until the integer
                    // gets finally converted successfully.
                    // The only argument that grows is the destination size p2 (== *ds).
                    encode_integer(p0, p1, p2, p3, p4);
                }

    fwprintf(stdout, L"TEST encode integer into wide character 5 dc: %i\n", *dc);

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

/* INTEGER_CONVERTER_SOURCE */
#endif
