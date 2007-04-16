/*
 * $RCSfile: model_diagram_converter.c,v $
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
 * @version $Revision: 1.3 $ $Date: 2007-04-16 15:50:29 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef MODEL_DIAGRAM_CONVERTER_SOURCE
#define MODEL_DIAGRAM_CONVERTER_SOURCE

#include "../../globals/constants/integer/integer_constants.c"
#include "../../globals/constants/log_message/log_message_constants.c"
#include "../../globals/logger/logger.c"

//
// Forward declarations.
//

/**
 * Serialises the knowledge model according to the given knowledge type
 * and creates a byte stream from it.
 *
 * @param p0 the destination (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source name
 * @param p4 the source name count
 * @param p5 the source abstraction
 * @param p6 the source abstraction count
 * @param p7 the source model
 * @param p8 the source model count
 * @param p9 the source details
 * @param p10 the source details count
 * @param p11 the knowledge memory
 * @param p12 the knowledge memory count
 */
void serialise(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12);

/**
 * Parses the model diagram and creates a knowledge model from it.
 *
 * A model diagram in this case is a textual representation of a knowledge model,
 * in form of many line feed-separated lines representing a model part each.
 *
 * @param p0 the destination knowledge model (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source model diagram
 * @param p4 the source count
 */
void parse_model_diagram(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message_debug("Information: Parse model diagram.");
}

/**
 * Serialises the compound.
 *
 * @param p0 the destination model diagram byte stream (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source model
 * @param p4 the source model count
 * @param p5 the knowledge memory
 * @param p6 the knowledge memory count
 */
void serialise_model_diagram_compound(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    if (p4 != NULL_POINTER) {

        int* smc = (int*) p4;

        log_message_debug("Debug: Serialise model diagram compound.");

/*??
        // The loop variable.
        int j = *NUMBER_0_INTEGER;

        // The part name, abstraction, model, details.
        void** n = &NULL_POINTER;
        void** nc = &NULL_POINTER;
        void** ns = &NULL_POINTER;
        void** a = &NULL_POINTER;
        void** ac = &NULL_POINTER;
        void** as = &NULL_POINTER;
        void** m = &NULL_POINTER;
        void** mc = &NULL_POINTER;
        void** ms = &NULL_POINTER;
        void** d = &NULL_POINTER;
        void** dc = &NULL_POINTER;
        void** ds = &NULL_POINTER;

        while (*NUMBER_1_INTEGER) {

            if (j >= *smc) {

                break;
            }

            // Get part name at current index.
            get_compound_element_name_by_index(p7, p8, (void*) &j, (void*) &n, (void*) &nc, (void*) &ns);

            // Get part abstraction, model, details at current index.
            get_compound_element_by_index(p7, p8, (void*) &j,
                (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms,
                (void*) &d, (void*) &dc, (void*) &ds);

            // Recursively call this procedure for compound part model.
            serialise_model_diagram(p0, p1, p2, *n, *nc, *a, *ac, *m, *mc, *d, *dc, p11, p12);

            // Increment loop variable.
            j++;
        }
*/

    } else {

        log_message_debug("Error: Could not serialise model diagram compound. The source model count is null.");
    }
}

/**
 * Serialises the knowledge model and creates a model diagram from it.
 *
 * A model diagram in this case is a textual representation of a knowledge model,
 * in form of many line feed-separated lines representing a model part each.
 *
 * @param p0 the destination model diagram (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source name
 * @param p4 the source name count
 * @param p5 the source abstraction
 * @param p6 the source abstraction count
 * @param p7 the source model
 * @param p8 the source model count
 * @param p9 the source details
 * @param p10 the source details count
 * @param p11 the knowledge memory
 * @param p12 the knowledge memory count
 */
void serialise_model_diagram(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12) {

    if (p10 != NULL_POINTER) {

        int* sdc = (int*) p10;

        if (p8 != NULL_POINTER) {

            int* smc = (int*) p8;

            log_message_debug("Information: Serialise model diagram.");

/*??
            // The comparison result.
            int r = *NUMBER_0_INTEGER;

            // Add minus character to destination array.
            serialise(p0, p1, p2, (void*) HYPHEN_MINUS_CHARACTER, (void*) HYPHEN_MINUS_CHARACTER_COUNT, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION_COUNT, p11, p12);

            // Add space character to destination array.
            serialise(p0, p1, p2, (void*) SPACE_CHARACTER, (void*) SPACE_CHARACTER_COUNT, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION_COUNT, p11, p12);

            // Add part name to destination array.
            serialise(p0, p1, p2, p3, p4, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION_COUNT, p11, p12);

            // Add space character to destination array.
            serialise(p0, p1, p2, (void*) SPACE_CHARACTER, (void*) SPACE_CHARACTER_COUNT, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION_COUNT, p11, p12);

            // Add pipe character to destination array.
            serialise(p0, p1, p2, (void*) LATIN_LETTER_DENTAL_CLICK_CHARACTER, (void*) LATIN_LETTER_DENTAL_CLICK_CHARACTER_COUNT, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION_COUNT, p11, p12);

            // Add space character to destination array.
            serialise(p0, p1, p2, (void*) SPACE_CHARACTER, (void*) SPACE_CHARACTER_COUNT, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION_COUNT, p11, p12);

            // Add part abstraction to destination array.
            serialise(p0, p1, p2, p5, p6, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION_COUNT, p11, p12);

            compare_arrays(p5, p6, (void*) COMPOUND_ABSTRACTION, (void*) COMPOUND_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

            if (r != *NUMBER_0_INTEGER) {

                if (*smc > *NUMBER_0_INTEGER) {

                    // Only process the following code, if the model compound contains at least one part.

                    // Add line feed character to destination array.
                    serialise(p0, p1, p2, (void*) LINE_FEED_CONTROL_CHARACTER, (void*) LINE_FEED_CONTROL_CHARACTER_COUNT, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION_COUNT, p11, p12);

                    // Add part model to destination array.
                    serialise_model_diagram_compound(p0, p1, p2, p7, p8, p11, p12);
                }

            } else {

                // Add space character to destination array.
                serialise(p0, p1, p2, p3, p4, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION_COUNT, p11, p12);

                // Add pipe character to destination array.
                serialise(p0, p1, p2, p3, p4, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION_COUNT, p11, p12);

                // Add space character to destination array.
                serialise(p0, p1, p2, p3, p4, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION_COUNT, p11, p12);

                // Add part model to destination array.
                serialise(p0, p1, p2, p7, p8, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION_COUNT, p11, p12);
            }

            if (*sdc > *NUMBER_0_INTEGER) {

                // Only process the following code, if the details compound contains at least one part.

                // Add line feed character to destination array.
                serialise(p0, p1, p2, (void*) LINE_FEED_CONTROL_CHARACTER, (void*) LINE_FEED_CONTROL_CHARACTER_COUNT, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION_COUNT, p11, p12);

                // Add part details to destination array.
                serialise_model_diagram_compound(p0, p1, p2, p9, p10, p11, p12);
            }
*/

        } else {

            log_message_debug("Error: Could not serialise model diagram. The source model count is null.");
        }

    } else {

        log_message_debug("Error: Could not serialise model diagram. The source details count is null.");
    }
}

/* MODEL_DIAGRAM_CONVERTER_SOURCE */
#endif
