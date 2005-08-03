/*
 * $RCSfile: integer_vector_converter.c,v $
 *
 * Copyright (c) 1999-2005. Christian Heller and the CYBOP developers.
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
 * @version $Revision: 1.4 $ $Date: 2005-08-03 08:45:33 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef INTEGER_VECTOR_CONVERTER_SOURCE
#define INTEGER_VECTOR_CONVERTER_SOURCE

#include "../../globals/constants/abstraction_constants.c"
#include "../../globals/constants/character_constants.c"
#include "../../globals/constants/log_constants.c"
#include "../../globals/logger/logger.c"
#include "../../memoriser/accessor.c"
#include "../../memoriser/allocator.c"

//
// Forward declarations.
//

/**
 * Parses the byte stream according to the given document type
 * and creates a document model from it.
 *
 * @param p0 the destination (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source
 * @param p4 the source count
 * @param p5 the type
 * @param p6 the type count
 */
void parse(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6);

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
                    get_array_elements_index(p3, p4, (void*) COMMA_CHARACTER, (void*) COMMA_CHARACTER_COUNT, (void*) &i, (void*) CHARACTER_ARRAY);

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
                        allocate((void*) &n, (void*) INTEGER_COUNT, (void*) INTEGER_ABSTRACTION, (void*) INTEGER_ABSTRACTION_COUNT);

                        // Parse integer.
                        // Example:
                        // Vector elements: "200,300,400"
                        // The number 200 character array length is 3.
                        // Index of first comma: 3
                        // Handed over as first element source count fec: index i
                        // (which is 3, as needed for the length)
                        parse((void*) &n, (void*) INTEGER_COUNT, (void*) INTEGER_COUNT, p3, (void*) &fec, (void*) INTEGER_ABSTRACTION, (void*) INTEGER_ABSTRACTION_COUNT);

                        // Check integer vector size.
                        if (*dc >= *ds) {

                            // Calculate new integer vector size.
                            *ds = *ds * *INTEGER_VECTOR_RESIZE_FACTOR + 1;

                            // Reallocate integer vector.
                            resize(p0, p2, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
                        }

                        // Add integer to end of integer vector.
                        set(*d, p1, n, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);

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

/*??
//??    log_message((void*) &INFO_LOG_LEVEL, (void*) &"Finalise integer vector.");

    // Write output stream and transform from integer vector.

    // Initialise elements.
    int z = 0;
    int y = 0;
    int x = 0;

    // Get elements.
    get_array_elements(p0, (void*) INTEGER_ARRAY, (void*) &Z_INDEX, (void*) &z);
    get_array_elements(p0, (void*) INTEGER_ARRAY, (void*) &Y_INDEX, (void*) &y);
    get_array_elements(p0, (void*) INTEGER_ARRAY, (void*) &X_INDEX, (void*) &x);

    // Remove elements.
    remove_array_elements(p0, (void*) INTEGER_ARRAY, (void*) &INTEGER_VECTOR_COUNT, (void*) &Z_INDEX);
    remove_array_elements(p0, (void*) INTEGER_ARRAY, (void*) &INTEGER_VECTOR_COUNT, (void*) &Y_INDEX);
    remove_array_elements(p0, (void*) INTEGER_ARRAY, (void*) &INTEGER_VECTOR_COUNT, (void*) &X_INDEX);

//??    fprintf(p1, %d, &(m->x));
//??    fprintf(p1, %d, &(m->y));
//??    fprintf(p1, %d, &(m->z));
*/
}

/* INTEGER_VECTOR_CONVERTER_SOURCE */
#endif
