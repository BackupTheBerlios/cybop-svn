/*
 * $RCSfile: integer_vector_converter.c,v $
 *
 * Copyright (c) 1999-2006. Christian Heller and the CYBOP developers.
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
 * @version $Revision: 1.15 $ $Date: 2006-04-20 22:36:11 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef INTEGER_VECTOR_CONVERTER_SOURCE
#define INTEGER_VECTOR_CONVERTER_SOURCE

#ifdef CYGWIN_ENVIRONMENT
#include <windows.h>
/* CYGWIN_ENVIRONMENT */
#endif

#include <stdio.h>
#include <string.h>
#include <wchar.h>
#include "../../globals/constants/abstraction_constants.c"
#include "../../globals/constants/character_constants.c"
#include "../../globals/constants/log_constants.c"
#include "../../globals/constants/structure_constants.c"
#include "../../globals/logger/logger.c"
#include "../../memoriser/accessor.c"
#include "../../memoriser/allocator.c"

/**
 * Parses the byte stream and creates an integer model from it.
 *
 * @param p0 the destination integer number (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source character array
 * @param p4 the source count
 */
void parse_integer(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p4 != NULL_POINTER) {

        int* sc = (int*) p4;

        if (p0 != NULL_POINTER) {

            void** d = (void**) p0;

            log_message_debug("Parse integer.");

            // The temporary null-terminated string.
            char* tmp = NULL_POINTER;
            int tmps = *sc + 1;

            // Create temporary null-terminated string.
            allocate_array((void*) &tmp, (void*) &tmps, (void*) CHARACTER_ARRAY);

            // The index.
            int i = 0;

            // Copy original string to temporary null-terminated string.
            set_array_elements((void*) tmp, (void*) &i, p3, p4, (void*) CHARACTER_ARRAY);

            // This is used as index to set the termination character.
            i = *sc;

            // Add string termination to temporary null-terminated string.
            set_array_elements((void*) tmp, (void*) &i, (void*) NULL_CONTROL_ASCII_CHARACTER, (void*) PRIMITIVE_COUNT, (void*) CHARACTER_ARRAY);

            // The tail variable is useless here and only needed for the string
            // transformation function. If the whole string array consists of
            // many sub strings, separated by space characters, then each sub
            // string gets interpreted as integer number.
            // The tail variable in this case points to the remaining sub string.
            char* tail = NULL_POINTER;

            // Transform string to integer value.
            // The third parameter is the number base:
            // 0 - tries to automatically identify the correct number base
            // 8 - octal
            // 10 - decimal
            // 16 - hexadecimal
            int v = strtol(tmp, &tail, 10);

            //?? p0 (Hand over as reference!)
            //?? Doesn't p0 need to be reallocated from size 0 to size 1,
            //?? to be able to take the double value?

            // Set integer value.
            set_array_elements(*d, (void*) PRIMITIVE_VALUE_INDEX, (void*) &v, (void*) PRIMITIVE_COUNT, (void*) INTEGER_ARRAY);

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

    if (p2 != NULL_POINTER) {

        int* ds = (int*) p2;

        if (p1 != NULL_POINTER) {

            int* dc = (int*) p1;

            if (p0 != NULL_POINTER) {

                char** d = (char**) p0;

                log_message_debug("Serialise integer.");

                // The integer value.
                int* v = NULL_POINTER;

                // Get integer value.
                get_array_elements(p3, (void*) PRIMITIVE_VALUE_INDEX, (void*) &v, (void*) INTEGER_ARRAY);

                //?? TODO: set_array_elements is missing!
                //?? The get_array_elements procedure does NOT copy values;
                //?? it returns just a reference to the corresponding value!

                // Transform source integer to destination string.
                *dc = snprintf(*d, *ds, "%i", *v);

                // Set destination string size one greater than the count
                // to have space for the terminating null character.
                *ds = *dc + 1;

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

                log_message_debug("Could not serialise integer. The destination is null.");
            }

        } else {

            log_message_debug("Could not serialise integer. The destination count is null.");
        }

    } else {

        log_message_debug("Could not serialise integer. The destination size is null.");
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

    if (p2 != NULL_POINTER) {

        size_t* ds = (size_t*) p2;

        if (p1 != NULL_POINTER) {

            int* dc = (int*) p1;

            if (p0 != NULL_POINTER) {

                wchar_t** d = (wchar_t**) p0;

                log_message_debug("Serialise integer into wide character.");

                // The integer value.
                int* v = NULL_POINTER;

                // Get integer value.
                get_array_elements(p3, (void*) PRIMITIVE_VALUE_INDEX, (void*) &v, (void*) INTEGER_ARRAY);

                // Initialise destination count to -1.
                // CAUTION! It must be negative for the loop to run.
                *dc = -1;

                while (1) {

                    if (*dc >= 0) {

                        break;
                    }

                    // Initialise destination string count to zero.
                    // CAUTION! This is essential because otherwise,
                    // the array reallocation calculates wrong values.
                    *dc = 0;

                    // Set destination string size one greater than the count
                    // to have space for the terminating null character and
                    // to avoid a zero value in case destination string size is zero.
                    *ds = *ds * *WIDE_CHARACTER_VECTOR_REALLOCATE_FACTOR + 1;

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

/**
 * Parses the byte stream and creates an integer vector model from it.
 *
 * @param p0 the destination vector model (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source byte stream
 * @param p4 the source count
 */
void parse_integer_vector(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p4 != NULL_POINTER) {

        int* sc = (int*) p4;

        if (p2 != NULL_POINTER) {

            int* ds = (int*) p2;

            if (p1 != NULL_POINTER) {

                int* dc = (int*) p1;

                if (p0 != NULL_POINTER) {

                    void** d = (void**) p0;

                    log_message_debug("Parse integer vector.");

                    // The comma index.
                    int i = -1;
                    // The first element count.
                    int fec = 0;
                    // The integer number.
                    void* n = NULL_POINTER;
                    // The remaining vector elements.
                    void* e = NULL_POINTER;
                    int ec = 0;

                    // Find comma character index.
                    get_array_elements_index(p3, p4, (void*) COMMA_ASCII_CHARACTER, (void*) PRIMITIVE_COUNT, (void*) &i, (void*) CHARACTER_ARRAY);

                    // CAUTION! Do NOT change this comparison to greater than >
                    // or something else, because -1 must be allowed! See below.
                    if (i != 0) {

                        if (i != -1) {

                            // Set first element count to comma index, if comma was found.
                            fec = i;

                        } else {

                            // Set first element count to source count, if no comma was found.
                            fec = *sc;
                        }

                        // Allocate integer number.
                        allocate((void*) &n, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);

                        // Parse integer.
                        // Example:
                        // Vector elements: "200,300,400"
                        // The number 200 character array length is 3.
                        // Index of first comma: 3
                        // Handed over as first element source count fec: index i
                        // (which is 3, as needed for the length)
                        parse_integer((void*) &n, (void*) PRIMITIVE_COUNT, (void*) PRIMITIVE_COUNT, p3, (void*) &fec);

                        // Check vector size.
                        if (*dc >= *ds) {

                            // Calculate new vector size.
                            *ds = *ds * *POINTER_VECTOR_REALLOCATE_FACTOR + 1;

                            // Reallocate vector.
                            reallocate(p0, p1, p2, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
                        }

                        // Add integer to end of vector.
                        set(*d, p1, &n, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

                        // Increase integer vector count by one, because of new element.
                        (*dc)++;

                        if (i > 0) {

                            // The next vector element.
                            // Example:
                            // Vector elements: "200,300,400"
                            // The number 200 character array length is 3.
                            // Index of first comma: 3
                            // Next vector element starts at index: 4
                            // (which is the comma index plus 1)
                            e = p3 + i + 1;
                            ec = *sc - (i + 1);

                            // Recursively call this procedure for the remaining
                            // integer vector elements, if comma was found.
                            parse_integer_vector(p0, p1, p2, e, (void*) &ec);
                        }

                    } else {

                        log_message_debug("Could not parse integer vector. The source string starts with a comma character.");
                    }

                } else {

                    log_message_debug("Could not parse integer vector. The destination is null.");
                }

            } else {

                log_message_debug("Could not parse integer vector. The destination count is null.");
            }

        } else {

            log_message_debug("Could not parse integer vector. The destination size is null.");
        }

    } else {

        log_message_debug("Could not parse integer vector. The source count is null.");
    }
}

/**
 * Serialises the integer vector model and creates a byte stream from it.
 *
 * @param p0 the destination byte stream (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source vector model
 * @param p4 the source count
 */
void serialise_integer_vector(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p4 != NULL_POINTER) {

        int* sc = (int*) p4;

        if (p2 != NULL_POINTER) {

            int* ds = (int*) p2;

            if (p1 != NULL_POINTER) {

                int* dc = (int*) p1;

                if (p0 != NULL_POINTER) {

                    void** d = (void**) p0;

                    log_message_debug("Serialise integer vector.");

                    // The integer.
                    void** i = &NULL_POINTER;
                    // The integer character.
                    void* c = NULL_POINTER;
                    int cc = *NUMBER_0_INTEGER;
                    int cs = *NUMBER_0_INTEGER;
                    // The remaining vector elements.
                    void* e = p3 + 1;
                    int ec = *sc - 1;

                    if (*sc > *NUMBER_0_INTEGER) {

                        // Get integer from vector.
                        get(p3, (void*) NUMBER_0_INTEGER, &i, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

                        serialise_integer((void*) &c, (void*) &cc, (void*) &cs, *i, (void*) PRIMITIVE_COUNT);

                        if ((*dc + cc + 1) >= *ds) {

                            *ds = *ds + cc + 1;

                            reallocate_array(p0, p1, p2, (void*) CHARACTER_ARRAY);
                        }

                        // Set integer characters.
                        set_array_elements(*d, p1, c, (void*) &cc, (void*) CHARACTER_ARRAY);
                        *dc = *dc + cc;

                        // Set comma character.
                        set_array_elements(*d, p1, (void*) COMMA_ASCII_CHARACTER, (void*) PRIMITIVE_COUNT, (void*) CHARACTER_ARRAY);
                        *dc = *dc + *PRIMITIVE_COUNT;

                        // Recursively call this procedure for further integer numbers.
                        serialise_integer_vector(p0, p1, p2, e, (void*) &ec);

                    } else {

                        log_message_debug("Could not serialise integer vector. The source count is zero.");
                    }

                } else {

                    log_message_debug("Could not serialise integer vector. The destination is null.");
                }

            } else {

                log_message_debug("Could not serialise integer vector. The destination count is null.");
            }

        } else {

            log_message_debug("Could not serialise integer vector. The destination size is null.");
        }

    } else {

        log_message_debug("Could not serialise integer vector. The source count is null.");
    }
}

/* INTEGER_VECTOR_CONVERTER_SOURCE */
#endif
