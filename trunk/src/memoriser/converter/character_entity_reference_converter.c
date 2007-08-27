/*
 * $RCSfile: character_entity_reference_converter.c,v $
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
 * @version $Revision: 1.1 $ $Date: 2007-08-27 07:07:37 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CHARACTER_ENTITY_REFERENCE_CONVERTER_SOURCE
#define CHARACTER_ENTITY_REFERENCE_CONVERTER_SOURCE

#include "../../globals/constants/character/character_constants.c"
#include "../../globals/constants/character/html_character_entity_constants.c"
#include "../../globals/constants/cybol/cybol_abstraction_constants.c"
#include "../../globals/constants/integer/integer_constants.c"
#include "../../globals/constants/memory_structure/array_constants.c"
#include "../../globals/constants/memory_structure/memory_structure_constants.c"
#include "../../globals/constants/pointer/pointer_constants.c"
#include "../../globals/variables/reallocation_factor_variables.c"

/**
 * Decodes a character entity reference (html escape reference) into a character.
 *
 * @param p0 the destination character
 * @param p1 the destination character count
 * @param p2 the destination character size
 * @param p3 the source character entity reference (html escape reference)
 * @param p4 the source character entity reference (html escape reference) count
 */
void decode_character_entity_reference(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p2 != *NULL_POINTER) {

        int* ds = (int*) p2;

        if (p1 != *NULL_POINTER) {

            int* dc = (int*) p1;

            if (p0 != *NULL_POINTER) {

                void** d = (void**) p0;

                // The temporary value.
                void** t = NULL_POINTER;
                int tc = *NUMBER_0_INTEGER;
                int ts = *NUMBER_0_INTEGER;
                // The comparison result.
                int r = *NUMBER_0_INTEGER;

                //
                // Set actual destination, using the temporary value.
                //

                if (r != *NUMBER_0_INTEGER) {

                    if ((*dc + tc) > *ds) {

                        // Calculate destination size.
                        *ds = (*CHARACTER_VECTOR_REALLOCATION_FACTOR * (*dc)) + tc;

                        // Reallocate destination.
                        reallocate(p0, p1, p2, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT);
                    }

                    // Add temporary value to destination.
                    set_element(*d, p1, (void*) t, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT);

                    // Increase destination count.
                    *dc = *dc + tc;
                }

            } else {

                log_message_debug("Could not decode character entity reference. The destination is null.");
            }

        } else {

            log_message_debug("Could not decode character entity reference. The destination count is null.");
        }

    } else {

        log_message_debug("Could not decode character entity reference. The destination size is null.");
    }
}

/**
 * Encodes a character into a character entity reference (html escape reference).
 *
 * @param p0 the destination character entity reference (html escape reference)
 * @param p1 the destination character entity reference (html escape reference) count
 * @param p2 the destination character entity reference (html escape reference) size
 * @param p3 the source character
 * @param p4 the source character count
 */
void encode_character_entity_reference(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p2 != *NULL_POINTER) {

        int* ds = (int*) p2;

        if (p1 != *NULL_POINTER) {

            int* dc = (int*) p1;

            if (p0 != *NULL_POINTER) {

                void** d = (void**) p0;

                // The temporary value.
                void** t = NULL_POINTER;
                int tc = *NUMBER_0_INTEGER;
                int ts = *NUMBER_0_INTEGER;
                // The comparison result.
                int r = *NUMBER_0_INTEGER;

/*??
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) SPACE_CHARACTER, (void*) PRIMITIVE_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &SPACE_URL_ESCAPE_CODE;
                        tc = *SPACE_URL_ESCAPE_CODE_COUNT;
                        ts = tc;
                    }
                }
*/

                //
                // Set actual destination, using the temporary value.
                //

                if (r != *NUMBER_0_INTEGER) {

                    if ((*dc + tc) > *ds) {

                        // Calculate destination size.
                        *ds = (*CHARACTER_VECTOR_REALLOCATION_FACTOR * (*dc)) + tc;

                        // Reallocate destination.
                        reallocate(p0, p1, p2, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT);
                    }

                    // Add temporary value to destination.
                    set_element(*d, p1, (void*) t, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT);

                    // Increase destination count.
                    *dc = *dc + tc;
                }

            } else {

                log_message_debug("Could not encode character entity reference. The destination is null.");
            }

        } else {

            log_message_debug("Could not encode character entity reference. The destination count is null.");
        }

    } else {

        log_message_debug("Could not encode character entity reference. The destination size is null.");
    }
}

/* CHARACTER_ENTITY_REFERENCE_CONVERTER_SOURCE */
#endif
