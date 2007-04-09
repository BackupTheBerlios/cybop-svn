/*
 * $RCSfile: integer_vector_converter.c,v $
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
 * @version $Revision: 1.19 $ $Date: 2007-04-09 08:48:44 $ $Author: christian $
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
#include "../../memoriser/converter/integer_converter.c"

/**
 * Parses the byte stream and creates an integer vector model from it.
 *
 * CAUTION! Do not mix up "integer" and "integer_vector"!
 * The latter is an array storing one or many integer numbers at different indexes.
 *
 * @param p0 the destination integer vector (Hand over as reference!)
 * @param p1 the destination integer vector count
 * @param p2 the destination integer vector size
 * @param p3 the source byte stream
 * @param p4 the source byte stream count
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
                    int i = *NUMBER_MINUS_1_INTEGER;
                    // The first element count.
                    int fec = *NUMBER_0_INTEGER;
                    // The integer value.
                    int v = *NUMBER_0_INTEGER;
                    // The remaining vector elements.
                    void* e = NULL_POINTER;
                    int ec = *NUMBER_0_INTEGER;

                    // Find comma character index.
                    get_array_elements_index(p3, p4, (void*) COMMA_CHARACTER, (void*) PRIMITIVE_COUNT, (void*) &i, (void*) CHARACTER_ARRAY);

                    // CAUTION! Do NOT change this comparison to greater than >
                    // or something else, because -1 must be allowed! See below.
                    if (i != *NUMBER_0_INTEGER) {

                        if (i != *NUMBER_MINUS_1_INTEGER) {

                            // Set first element count to comma index, if comma was found.
                            fec = i;

                        } else {

                            // Set first element count to source count, if no comma was found.
                            fec = *sc;
                        }

                        // Check vector size.
                        if (*dc >= *ds) {

                            // Calculate new vector size.
                            //
                            // CAUTION! Add number one as summand at the end to
                            // avoid a zero result, since the initial size is zero!
                            *ds = *ds * *INTEGER_VECTOR_REALLOCATE_FACTOR + *NUMBER_1_INTEGER;

                            // Reallocate vector.
                            reallocate(p0, p1, p2, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
                        }

                        // Parse integer.
                        //
                        // Example:
                        // Vector elements: "200,300,400"
                        // The number 200 character array length is 3.
                        // Index of first comma: 3
                        // Handed over as first element source count fec: index i
                        // (which is 3, as needed for the length)
                        parse_integer((void*) &v, NULL_POINTER, NULL_POINTER, p3, (void*) &fec);

                        // Set integer value.
                        set(*d, (void*) dc, (void*) &v, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);

                        // Increment integer vector count, because of new element.
                        (*dc)++;

                        if (i > *NUMBER_0_INTEGER) {

                            // The next vector element.
                            //
                            // Example:
                            // Vector elements: "200,300,400"
                            // The number 200 character array length is 3.
                            // Index of first comma: 3
                            // Next vector element starts at index: 4
                            // (which is the comma index plus 1)
                            e = p3 + i + *NUMBER_1_INTEGER;
                            ec = *sc - (i + *NUMBER_1_INTEGER);

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
                    void* e = p3 + *NUMBER_1_INTEGER;
                    int ec = *sc - *NUMBER_1_INTEGER;

                    if (*sc > *NUMBER_0_INTEGER) {

                        // Get integer from vector.
                        get(p3, (void*) NUMBER_0_INTEGER, &i, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

                        serialise_integer((void*) &c, (void*) &cc, (void*) &cs, *i, (void*) PRIMITIVE_COUNT);

                        if ((*dc + cc + *NUMBER_1_INTEGER) >= *ds) {

                            *ds = *ds + cc + *NUMBER_1_INTEGER;

                            reallocate_array(p0, p1, p2, (void*) CHARACTER_ARRAY);
                        }

                        // Set integer characters.
                        set_array_elements(*d, p1, c, (void*) &cc, (void*) CHARACTER_ARRAY);
                        *dc = *dc + cc;

                        // Set comma character.
                        set_array_elements(*d, p1, (void*) COMMA_CHARACTER, (void*) PRIMITIVE_COUNT, (void*) CHARACTER_ARRAY);
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
