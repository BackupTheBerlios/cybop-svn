/*
 * $RCSfile: integer_converter.c,v $
 *
 * Copyright (c) 1999-2008. Christian Heller and the CYBOP developers.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 *
 * http://www.cybop.net
 * - Cybernetics Oriented Programming -
 *
 * @version $Revision: 1.25 $ $Date: 2008-07-08 07:11:33 $ $Author: christian $
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
#include "../../globals/constants/character/code/character_code_constants.c"
#include "../../globals/constants/cybol/cybol_abstraction_constants.c"
#include "../../globals/constants/integer/integer_constants.c"
#include "../../globals/constants/log/log_message_constants.c"
#include "../../globals/constants/memory_structure/array_constants.c"
#include "../../globals/constants/memory_structure/memory_structure_constants.c"
#include "../../globals/constants/pointer/pointer_constants.c"
#include "../../globals/logger/logger.c"
#include "../../globals/variables/reallocation_factor_variables.c"
#include "../../memoriser/allocator.c"

/**
 * Decodes the byte stream and creates an integer from it.
 *
 * CAUTION! Do not mix up "integer" and "integer_vector"!
 * The latter is an array storing one or many integer numbers at different indexes.
 *
 * This operation has an integer as result, so a normal integer pointer
 * and NOT an integer pointer pointer (integer array) is handed over as p0.
 *
 * @param p0 the destination integer number (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source character array
 * @param p4 the source count
 */
void decode_integer(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p4 != *NULL_POINTER) {

        int* sc = (int*) p4;

        if (p0 != *NULL_POINTER) {

            int* d = (int*) p0;

            log_terminated_message((void*) INFORMATION_LOG_LEVEL, (void*) L"Decode integer.");

            // The temporary null-terminated string.
            wchar_t* tmp = (wchar_t*) *NULL_POINTER;
            int tmps = *sc + *NUMBER_1_INTEGER;

            // Create temporary null-terminated string.
            allocate_array((void*) &tmp, (void*) &tmps, (void*) WIDE_CHARACTER_ARRAY);

            // Copy original string to temporary null-terminated string.
            set_array_elements((void*) tmp, (void*) NUMBER_0_INTEGER, p3, p4, (void*) WIDE_CHARACTER_ARRAY);
            // Add string termination to temporary null-terminated string.
            // The source count is used as index for the termination character.
            set_array_elements((void*) tmp, p4, (void*) NULL_CONTROL_WIDE_CHARACTER, (void*) PRIMITIVE_COUNT, (void*) WIDE_CHARACTER_ARRAY);

            // The tail variable is useless here and only needed for the string
            // transformation function. If the whole string array consists of
            // many sub strings, separated by space characters, then each sub
            // string gets interpreted as integer number.
            // The tail variable in this case points to the remaining sub string.
            wchar_t* tail = (wchar_t*) *NULL_POINTER;

            // Set integer value.
            //
            // Transform string to integer value.
            // The third parameter is the number base:
            // 0 - tries to automatically identify the correct number base
            // 8 - octal
            // 10 - decimal
            // 16 - hexadecimal
            *d = wcstol(tmp, &tail, *NUMBER_10_INTEGER);

            // Destroy temporary null-terminated string.
            deallocate_array((void*) &tmp, (void*) &tmps, (void*) WIDE_CHARACTER_ARRAY);

        } else {

            log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) L"Could not decode integer. The destination is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) L"Could not decode integer. The source count is null.");
    }
}

/**
 * Encodes the integer model and creates a wide character byte stream from it.
 *
 * @param p0 the destination wide character array (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source integer number
 * @param p4 the source count
 */
void encode_integer(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p2 != *NULL_POINTER) {

        size_t* ds = (size_t*) p2;

        if (p1 != *NULL_POINTER) {

            int* dc = (int*) p1;

            if (p0 != *NULL_POINTER) {

                wchar_t** d = (wchar_t**) p0;

                log_terminated_message((void*) INFORMATION_LOG_LEVEL, (void*) L"Encode integer into wide character.");

                // The integer value.
                int* v = (int*) *NULL_POINTER;

                // Get integer value.
                get_array_elements(p3, (void*) PRIMITIVE_VALUE_INDEX, (void*) &v, (void*) INTEGER_ARRAY);

                // Initialise destination count to -1.
                // CAUTION! It must be negative for the loop to run.
                *dc = *NUMBER_MINUS_1_INTEGER;

                while (*NUMBER_1_INTEGER) {

                    if (*dc >= *NUMBER_0_INTEGER) {

                        break;
                    }

                    // Initialise destination string count to zero.
                    // CAUTION! This is essential because otherwise,
                    // the array reallocation calculates wrong values.
                    *dc = *NUMBER_0_INTEGER;

                    // Set destination string size one greater than the count
                    // to have space for the terminating null character and
                    // to avoid a zero value in case destination string size is zero.
                    *ds = (*dc * *WIDE_CHARACTER_VECTOR_REALLOCATION_FACTOR) + *NUMBER_1_INTEGER;

                    // Reallocate destination string.
                    reallocate_array(p0, p1, p2, (void*) WIDE_CHARACTER_ARRAY);

                    // Transform source integer to destination string.
                    // A null wide character is written to mark the end of the string.
                    // The return value is the number of characters generated
                    // for the given input, excluding the trailing null.
                    // If not all output fits into the provided buffer,
                    // a negative value is returned.
#ifdef CYGWIN_ENVIRONMENT
                    *dc = wsprintfW(*d, L"%i", *v);
/* CYGWIN_ENVIRONMENT */
#else
                    *dc = swprintf(*d, *ds, L"%i", *v);
/* CYGWIN_ENVIRONMENT */
#endif
                }

            } else {

                log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) L"Could not encode integer into wide character. The destination is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) L"Could not encode integer into wide character. The destination count is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) L"Could not encode integer into wide character. The destination size is null.");
    }
}

/* INTEGER_CONVERTER_SOURCE */
#endif
