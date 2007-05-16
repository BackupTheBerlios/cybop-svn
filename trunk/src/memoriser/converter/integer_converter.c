/*
 * $RCSfile: integer_converter.c,v $
 *
 * Copyright (c) 1999-2007. Christian Heller and the CYBOP developers.
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
 * @version $Revision: 1.15 $ $Date: 2007-05-16 19:29:02 $ $Author: christian $
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
#include "../../globals/constants/cybol/cybol_abstraction_constants.c"
#include "../../globals/constants/character/character_constants.c"
#include "../../globals/constants/log_message/log_message_constants.c"
#include "../../globals/constants/memory_structure/memory_structure_constants.c"
#include "../../globals/constants/pointer/pointer_constants.c"
#include "../../globals/logger/logger.c"
#include "../../memoriser/accessor.c"
#include "../../memoriser/allocator.c"

/**
 * Parses the byte stream and creates an integer from it.
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
void parse_integer(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p4 != *NULL_POINTER) {

        int* sc = (int*) p4;

        if (p0 != *NULL_POINTER) {

            int* d = (int*) p0;

            log_message_debug("Information: Parse integer.");

            // The temporary null-terminated string.
            char* tmp = (char*) *NULL_POINTER;
            int tmps = *sc + *NUMBER_1_INTEGER;

            // Create temporary null-terminated string.
            allocate_array((void*) &tmp, (void*) &tmps, (void*) CHARACTER_ARRAY);

            // Copy original string to temporary null-terminated string.
            set_array_elements((void*) tmp, (void*) NUMBER_0_INTEGER, p3, p4, (void*) CHARACTER_ARRAY);
            // Add string termination to temporary null-terminated string.
            // The source count is used as index for the termination character.
            set_array_elements((void*) tmp, p4, (void*) NULL_CONTROL_CHARACTER, (void*) PRIMITIVE_COUNT, (void*) CHARACTER_ARRAY);

            // The tail variable is useless here and only needed for the string
            // transformation function. If the whole string array consists of
            // many sub strings, separated by space characters, then each sub
            // string gets interpreted as integer number.
            // The tail variable in this case points to the remaining sub string.
            char* tail = (char*) *NULL_POINTER;

            // Set integer value.
            //
            // Transform string to integer value.
            // The third parameter is the number base:
            // 0 - tries to automatically identify the correct number base
            // 8 - octal
            // 10 - decimal
            // 16 - hexadecimal
            *d = strtol(tmp, &tail, *NUMBER_10_INTEGER);

            // Destroy temporary null-terminated string.
            deallocate_array((void*) &tmp, (void*) &tmps, (void*) CHARACTER_ARRAY);

        } else {

            log_message_debug("Could not parse integer. The destination is null.");
        }

    } else {

        log_message_debug("Could not parse integer. The source count is null.");
    }
}

/**
 * Serialises the integer model and creates a byte stream from it.
 *
 * @param p0 the destination character array (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source integer number
 * @param p4 the source count
 */
void serialise_integer(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p4 != *NULL_POINTER) {

        int* sc = (int*) p4;

        if (p2 != *NULL_POINTER) {

            int* ds = (int*) p2;

            if (p1 != *NULL_POINTER) {

                int* dc = (int*) p1;

                if (p0 != *NULL_POINTER) {

                    char** d = (char**) p0;

                    log_message_debug("Information: Serialise integer.");

                    if (*sc > *NUMBER_0_INTEGER) {

                        // CAUTION! Only serialise integer, if one exists!
                        // Otherwise, the "snprintf" function call will cause a segmentation fault.

                        // The integer value.
                        int* v = (int*) *NULL_POINTER;

                        // Get integer value.
                        get_array_elements(p3, (void*) PRIMITIVE_VALUE_INDEX, (void*) &v, (void*) INTEGER_ARRAY);

                        // Transform source integer to destination string.
                        *dc = snprintf(*d, *ds, "%i", *v);

                        // Set destination string size one greater than the count
                        // to have space for the terminating null character.
                        *ds = *dc + *NUMBER_1_INTEGER;

                        // Reallocate destination string.
                        reallocate_array(p0, p1, p2, (void*) CHARACTER_ARRAY);

                        // Transform source integer to destination string.
                        *dc = snprintf(*d, *ds, "%i", *v);

                        // CAUTION! Recalculate string count because only in versions
                        // of the GNU C library prior to 2.1, the snprintf function
                        // returns the number of characters stored, not including the
                        // terminating null; unless there was not enough space in the
                        // string to store the result in which case -1 is returned.
                        // This was CHANGED in order to comply with the ISO C99 standard.
                        // As usual, the string count does NOT contain the terminating
                        // null character.
                        *dc = strlen(*d);

                    } else {

                        log_message_debug("Could not serialise integer. The source count is zero.");
                    }

                } else {

                    log_message_debug("Could not serialise integer. The destination is null.");
                }

            } else {

                log_message_debug("Could not serialise integer. The destination count is null.");
            }

        } else {

            log_message_debug("Could not serialise integer. The destination size is null.");
        }

    } else {

        log_message_debug("Could not serialise integer. The source count is null.");
    }
}

/**
 * Serialises the integer model and creates a wide character byte stream from it.
 *
 * @param p0 the destination wide character array (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source integer number
 * @param p4 the source count
 */
void serialise_integer_wide(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p2 != *NULL_POINTER) {

        size_t* ds = (size_t*) p2;

        if (p1 != *NULL_POINTER) {

            int* dc = (int*) p1;

            if (p0 != *NULL_POINTER) {

                wchar_t** d = (wchar_t**) p0;

                log_message_debug("Serialise integer into wide character.");

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
                    *ds = *ds * *WIDE_CHARACTER_VECTOR_REALLOCATE_FACTOR + *NUMBER_1_INTEGER;

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

                log_message_debug("Could not serialise integer into wide character. The destination is null.");
            }

        } else {

            log_message_debug("Could not serialise integer into wide character. The destination count is null.");
        }

    } else {

        log_message_debug("Could not serialise integer into wide character. The destination size is null.");
    }
}

/* INTEGER_CONVERTER_SOURCE */
#endif
