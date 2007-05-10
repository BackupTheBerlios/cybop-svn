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
 * @version $Revision: 1.22 $ $Date: 2007-05-10 22:57:55 $ $Author: christian $
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
#include "../../globals/constants/cybol/cybol_abstraction_constants.c"
#include "../../globals/constants/character/character_constants.c"
#include "../../globals/constants/log_message/log_message_constants.c"
#include "../../globals/constants/memory_structure/memory_structure_constants.c"
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

                    log_message_debug("Information: Parse integer vector.");

                    // CAUTION! This check is necessary since otherwise,
                    // the array border gets crossed and a comma might be found
                    // that actually does not belong to the array.
                    if (*sc > *NUMBER_0_INTEGER) {

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

                        if (i > *NUMBER_0_INTEGER) {

                            // Set first element count to comma index only if a comma
                            // was found at a position greater than the zero index.
                            fec = i;

                        } else {

                            // Set first element count to source count, if no comma
                            // was found, or if the string started with a comma.
                            fec = *sc;
                        }

                        // The variable fec is in any case greater than zero.
                        // Either, it is equal to the source count, which was checked
                        // to be greater than zero above, or it is the comma index,
                        // in which case it is also greater than zero.

                        // Parse integer.
                        //
                        // Example:
                        // Vector elements: "200,300,400"
                        // The number 200 character array length is 3.
                        // Index of first comma: 3
                        // Handed over as first element source count fec: index i
                        // (which is 3, as needed for the length)
                        parse_integer((void*) &v, NULL_POINTER, NULL_POINTER, p3, (void*) &fec);

                        // Check vector size.
                        if (*dc >= *ds) {

                            // Calculate new vector size.
                            //
                            // CAUTION! Add number one as summand at the end to
                            // avoid a zero result, since the initial size is zero!
                            *ds = (*ds * *INTEGER_VECTOR_REALLOCATE_FACTOR) + *NUMBER_1_INTEGER;

                            // Reallocate vector.
                            reallocate(p0, p1, p2, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
                        }

                        // Set integer value.
                        set(*d, (void*) dc, (void*) &v, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);

                        // Increment integer vector count, because of new element.
                        (*dc)++;

                        if (i > *NUMBER_0_INTEGER) {

                            // If a comma was found, then process the remaining integer vector elements.

                            // The next vector element.
                            //
                            // Example:
                            // Character vector elements: "200,300,400"
                            // The number 200 character array length is 3.
                            // Index of first comma: 3
                            // Next vector element starts at index: 4
                            // (which is the comma index plus 1)
                            e = p3 + (i + *NUMBER_1_INTEGER);
                            ec = *sc - (i + *NUMBER_1_INTEGER);

                            // Recursively call this function.
                            parse_integer_vector(p0, p1, p2, e, (void*) &ec);
                        }

                    } else {

                        log_message_debug("Error: Could not parse integer vector. The source count is zero.");
                    }

                } else {

                    log_message_debug("Error: Could not parse integer vector. The destination is null.");
                }

            } else {

                log_message_debug("Error: Could not parse integer vector. The destination count is null.");
            }

        } else {

            log_message_debug("Error: Could not parse integer vector. The destination size is null.");
        }

    } else {

        log_message_debug("Error: Could not parse integer vector. The source count is null.");
    }
}

/**
 * Serialises the integer vector elements and creates a byte stream from it.
 *
 * @param p0 the destination byte stream (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source integer vector model
 * @param p4 the source integer vector model count
 * @param p5 the iteration count
 */
void serialise_integer_vector_elements(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    if (p5 != NULL_POINTER) {

        int* it = (int*) p5;

        if (p4 != NULL_POINTER) {

            int* sc = (int*) p4;

            if (p2 != NULL_POINTER) {

                int* ds = (int*) p2;

                if (p1 != NULL_POINTER) {

                    int* dc = (int*) p1;

                    if (p0 != NULL_POINTER) {

                        void** d = (void**) p0;

                        log_message_debug("Debug: Serialise integer vector elements.");

                        // The integer.
                        void* i = NULL_POINTER;
                        // The integer character.
                        void* c = NULL_POINTER;
                        int cc = *NUMBER_0_INTEGER;
                        int cs = *NUMBER_0_INTEGER;

                        if (*sc > *NUMBER_0_INTEGER) {

                            // Get first integer from vector.
                            get(p3, (void*) NUMBER_0_INTEGER, &i, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);

                            // Serialise first integer.
                            serialise_integer((void*) &c, (void*) &cc, (void*) &cs, i, (void*) PRIMITIVE_COUNT);

                            // CAUTION! Add one for the comma character added further below!
                            if ((*dc + *NUMBER_1_INTEGER + cc) >= *ds) {

                                // The new destination integer vector size.
                                // CAUTION! Add one for the comma character added further below!
                                // CAUTION! Add constant in case *dc is zero!
                                *ds = (*dc * *INTEGER_VECTOR_REALLOCATE_FACTOR) + *NUMBER_1_INTEGER + cc;

                                // Reallocate destination character array.
                                reallocate_array(p0, p1, p2, (void*) CHARACTER_ARRAY);
                            }

                            if (*it > *NUMBER_0_INTEGER) {

                                // If this is NOT the first iteration cycle through the source array,
                                // then add a comma character before adding a new integer element,
                                // in order to separate from already existing elements.

                                // Set comma character.
                                set_array_elements(*d, p1, (void*) COMMA_CHARACTER, (void*) PRIMITIVE_COUNT, (void*) CHARACTER_ARRAY);
                                *dc = *dc + *PRIMITIVE_COUNT;
                            }

                            // Set integer characters.
                            set_array_elements(*d, p1, c, (void*) &cc, (void*) CHARACTER_ARRAY);
                            *dc = *dc + cc;

                            // Determine remaining vector elements.
                            //
                            // CAUTION! The source count has to be greater than zero!
                            // However, this does not have to be checked here,
                            // as it is already checked further above.
                            void* e = p3 + (*NUMBER_1_INTEGER * *INTEGER_PRIMITIVE_SIZE);
                            int ec = *sc - *NUMBER_1_INTEGER;

                            // Increment iteration count.
                            (*it)++;

                            // Recursively call this procedure for further integer numbers.
                            serialise_integer_vector_elements(p0, p1, p2, e, (void*) &ec, p5);

                        } else {

                            log_message_debug("Error: Could not serialise integer vector elements. The source count is zero.");
                        }

                    } else {

                        log_message_debug("Error: Could not serialise integer vector elements. The destination is null.");
                    }

                } else {

                    log_message_debug("Error: Could not serialise integer vector elements. The destination count is null.");
                }

            } else {

                log_message_debug("Error: Could not serialise integer vector elements. The destination size is null.");
            }

        } else {

            log_message_debug("Error: Could not serialise integer vector elements. The source count is null.");
        }

    } else {

        log_message_debug("Error: Could not serialise integer vector elements. The iteration count is null.");
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

    log_message_debug("Information: Serialise integer vector.");

    // The iteration count.
    int i = *NUMBER_0_INTEGER;

    // Serialise integer vector elements.
    // Hand over zero iteration value, since this is the initial call.
    serialise_integer_vector_elements(p0, p1, p2, p3, p4, (void*) &i);
}

/* INTEGER_VECTOR_CONVERTER_SOURCE */
#endif
