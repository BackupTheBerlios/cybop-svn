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
 * @version $Revision: 1.9 $ $Date: 2007-05-26 21:19:58 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef MODEL_DIAGRAM_CONVERTER_SOURCE
#define MODEL_DIAGRAM_CONVERTER_SOURCE

#include "../../globals/constants/cybol/cybol_abstraction_constants.c"
#include "../../globals/constants/integer/integer_constants.c"
#include "../../globals/constants/log/log_message_constants.c"
#include "../../globals/constants/memory_structure/memory_structure_constants.c"
#include "../../globals/constants/pointer/pointer_constants.c"
#include "../../globals/logger/logger.c"

//
// Forward declarations.
//

/**
 * Serialises the model diagram node.
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
 * @param p11 the tree level
 * @param p12 the details flag
 */
void serialise_model_diagram_node(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12);

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
 * Serialises the model diagram indentation.
 *
 * @param p0 the destination model diagram (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the tree level
 * @param p4 the details flag
 */
void serialise_model_diagram_indentation(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p4 != *NULL_POINTER) {

        int* d = (int*) p4;

        if (p3 != *NULL_POINTER) {

            int* l = (int*) p3;

            log_message_debug("Information: Serialise model diagram indentation.");

            // The loop variable.
            int j = *NUMBER_0_INTEGER;

            while (*NUMBER_1_INTEGER) {

                if (j >= *l) {

                    break;
                }

                // Check if the last of many indentations has been reached.
                if ((j + *NUMBER_1_INTEGER) < *l) {

                    // This is one of many indentations before the actual part appears.
                    // Therefore, use a pipe- and space character.

                    // Add pipe character to destination array.
                    serialise_character_vector(p0, p1, p2, (void*) VERTICAL_LINE_CHARACTER, (void*) PRIMITIVE_COUNT);

                    // Add space character to destination array.
                    serialise_character_vector(p0, p1, p2, (void*) SPACE_CHARACTER, (void*) PRIMITIVE_COUNT);

                } else {

                    // This is the last indentation. Special characters are used for it.

                    if (*d == *NUMBER_0_INTEGER) {

                        // This is the part model, so that a plus- and minus character are used.

                        // Add plus character to destination array.
                        serialise_character_vector(p0, p1, p2, (void*) PLUS_SIGN_CHARACTER, (void*) PRIMITIVE_COUNT);

                        // Add minus character to destination array.
                        serialise_character_vector(p0, p1, p2, (void*) HYPHEN_MINUS_CHARACTER, (void*) PRIMITIVE_COUNT);

                    } else {

                        // This is the part details, so that a number sign- and minus character are used.

                        // Add plus character to destination array.
                        serialise_character_vector(p0, p1, p2, (void*) NUMBER_SIGN_CHARACTER, (void*) PRIMITIVE_COUNT);

                        // Add minus character to destination array.
                        serialise_character_vector(p0, p1, p2, (void*) HYPHEN_MINUS_CHARACTER, (void*) PRIMITIVE_COUNT);
                    }
                }

                // Increment loop variable.
                j++;
            }

        } else {

            log_message_debug("Error: Could not serialise model diagram indentation. The tree level is null.");
        }

    } else {

        log_message_debug("Error: Could not serialise model diagram indentation. The details flag is null.");
    }
}

/**
 * Serialises the model diagram compound.
 *
 * @param p0 the destination model diagram (Hand over as reference!)
 * @param p1 the destination model diagram count
 * @param p2 the destination model diagram size
 * @param p3 the source compound model
 * @param p4 the source compound model count
 * @param p5 the tree level
 * @param p6 the details flag
 */
void serialise_model_diagram_compound(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    if (p5 != *NULL_POINTER) {

        int* l = (int*) p5;

        if (p4 != *NULL_POINTER) {

            int* sc = (int*) p4;

            log_message_debug("Information: Serialise model diagram compound.");

            // The loop variable.
            int j = *NUMBER_0_INTEGER;

            // The part name, abstraction, model, details.
            void** n = NULL_POINTER;
            void** nc = NULL_POINTER;
            void** ns = NULL_POINTER;
            void** a = NULL_POINTER;
            void** ac = NULL_POINTER;
            void** as = NULL_POINTER;
            void** m = NULL_POINTER;
            void** mc = NULL_POINTER;
            void** ms = NULL_POINTER;
            void** d = NULL_POINTER;
            void** dc = NULL_POINTER;
            void** ds = NULL_POINTER;

            // The new tree level.
            //
            // It gets initialised with the current tree level increment by one.
            //
            // CAUTION! Do NOT manipulate the original tree level that was handed over as parameter!
            // Otherwise, it would never be decremented anymore leading to wrong indentation.
            int nl = *l + *NUMBER_1_INTEGER;

            while (*NUMBER_1_INTEGER) {

                if (j >= *sc) {

                    break;
                }

                // Get part abstraction, model, details at current index.
                get_compound_element_by_index(p3, p4, (void*) &j,
                    (void*) &n, (void*) &nc, (void*) &ns,
                    (void*) &a, (void*) &ac, (void*) &as,
                    (void*) &m, (void*) &mc, (void*) &ms,
                    (void*) &d, (void*) &dc, (void*) &ds);

                // Add line feed character to destination array.
                serialise_character_vector(p0, p1, p2, (void*) LINE_FEED_CONTROL_CHARACTER, (void*) PRIMITIVE_COUNT);

                // Serialise part.
                serialise_model_diagram_node(p0, p1, p2, *n, *nc, *a, *ac, *m, *mc, *d, *dc, (void*) &nl, p6);

                // Increment loop variable.
                j++;
            }

        } else {

            log_message_debug("Error: Could not serialise model diagram compound. The source count is null.");
        }

    } else {

        log_message_debug("Error: Could not serialise model diagram compound. The tree level is null.");
    }
}

/**
 * Serialises the model diagram node.
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
 * @param p11 the tree level
 * @param p12 the details flag
 */
void serialise_model_diagram_node(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12) {

    if (p10 != *NULL_POINTER) {

        int* dc = (int*) p10;

        if (p8 != *NULL_POINTER) {

            int* mc = (int*) p8;

            log_message_debug("Debug: Serialise model diagram node.");

            // Add indentation.
            serialise_model_diagram_indentation(p0, p1, p2, p11, p12);

            // Add part name to destination array.
            serialise_character_vector(p0, p1, p2, p3, p4);

            // Add space character to destination array.
            serialise_character_vector(p0, p1, p2, (void*) SPACE_CHARACTER, (void*) PRIMITIVE_COUNT);

            // Add pipe character to destination array.
            serialise_character_vector(p0, p1, p2, (void*) VERTICAL_LINE_CHARACTER, (void*) PRIMITIVE_COUNT);

            // Add space character to destination array.
            serialise_character_vector(p0, p1, p2, (void*) SPACE_CHARACTER, (void*) PRIMITIVE_COUNT);

            // Add part abstraction to destination array.
            serialise_character_vector(p0, p1, p2, p5, p6);

            // The comparison result.
            int r = *NUMBER_0_INTEGER;

            if (r == *NUMBER_0_INTEGER) {

                compare_arrays(p5, p6, (void*) COMPOUND_ABSTRACTION, (void*) COMPOUND_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                if (r != *NUMBER_0_INTEGER) {

                    if (*mc > *NUMBER_0_INTEGER) {

                        // Only process the following code, if the model compound contains at least one part.

                        // Add part model to destination array.
                        serialise_model_diagram_compound(p0, p1, p2, p7, p8, p11, (void*) NUMBER_0_INTEGER);
                    }
                }
            }

            if (r == *NUMBER_0_INTEGER) {

                compare_arrays(p5, p6, (void*) XDT_ABSTRACTION, (void*) XDT_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                if (r != *NUMBER_0_INTEGER) {

                    if (*mc > *NUMBER_0_INTEGER) {

                        // Only process the following code, if the model compound contains at least one part.

                        // Add part model to destination array.
                        serialise_model_diagram_compound(p0, p1, p2, p7, p8, p11, (void*) NUMBER_0_INTEGER);
                    }
                }
            }

            if (r == *NUMBER_0_INTEGER) {

                compare_arrays(p5, p6, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                if (r != *NUMBER_0_INTEGER) {

                    // Add space character to destination array.
                    serialise_character_vector(p0, p1, p2, (void*) SPACE_CHARACTER, (void*) PRIMITIVE_COUNT);

                    // Add pipe character to destination array.
                    serialise_character_vector(p0, p1, p2, (void*) VERTICAL_LINE_CHARACTER, (void*) PRIMITIVE_COUNT);

                    // Add space character to destination array.
                    serialise_character_vector(p0, p1, p2, (void*) SPACE_CHARACTER, (void*) PRIMITIVE_COUNT);

                    // Add part model to destination array.
                    serialise_character_vector(p0, p1, p2, p7, p8);
                }
            }

            if (r == *NUMBER_0_INTEGER) {

                compare_arrays(p5, p6, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                if (r != *NUMBER_0_INTEGER) {

                    // Add space character to destination array.
                    serialise_character_vector(p0, p1, p2, (void*) SPACE_CHARACTER, (void*) PRIMITIVE_COUNT);

                    // Add pipe character to destination array.
                    serialise_character_vector(p0, p1, p2, (void*) VERTICAL_LINE_CHARACTER, (void*) PRIMITIVE_COUNT);

                    // Add space character to destination array.
                    serialise_character_vector(p0, p1, p2, (void*) SPACE_CHARACTER, (void*) PRIMITIVE_COUNT);

                    // Add part model to destination array.
                    serialise_integer_vector(p0, p1, p2, p7, p8);
                }
            }

            if (r == *NUMBER_0_INTEGER) {

                compare_arrays(p5, p6, (void*) BOOLEAN_ABSTRACTION, (void*) BOOLEAN_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                if (r != *NUMBER_0_INTEGER) {

                    // Add space character to destination array.
                    serialise_character_vector(p0, p1, p2, (void*) SPACE_CHARACTER, (void*) PRIMITIVE_COUNT);

                    // Add pipe character to destination array.
                    serialise_character_vector(p0, p1, p2, (void*) VERTICAL_LINE_CHARACTER, (void*) PRIMITIVE_COUNT);

                    // Add space character to destination array.
                    serialise_character_vector(p0, p1, p2, (void*) SPACE_CHARACTER, (void*) PRIMITIVE_COUNT);

                    // Add part model to destination array.
                    serialise_boolean(p0, p1, p2, p7, p8);
                }
            }

            if (r == *NUMBER_0_INTEGER) {

                compare_arrays(p5, p6, (void*) DOUBLE_VECTOR_ABSTRACTION, (void*) DOUBLE_VECTOR_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                if (r != *NUMBER_0_INTEGER) {

                    // Add space character to destination array.
                    serialise_character_vector(p0, p1, p2, (void*) SPACE_CHARACTER, (void*) PRIMITIVE_COUNT);

                    // Add pipe character to destination array.
                    serialise_character_vector(p0, p1, p2, (void*) VERTICAL_LINE_CHARACTER, (void*) PRIMITIVE_COUNT);

                    // Add space character to destination array.
                    serialise_character_vector(p0, p1, p2, (void*) SPACE_CHARACTER, (void*) PRIMITIVE_COUNT);

                    // Add part model to destination array.
                    serialise_double_vector(p0, p1, p2, p7, p8);
                }
            }

            if (*dc > *NUMBER_0_INTEGER) {

                // Only process the following code, if the details compound contains at least one part.

                // Add part details to destination array.
                serialise_model_diagram_compound(p0, p1, p2, p9, p10, p11, (void*) NUMBER_1_INTEGER);
            }

        } else {

            log_message_debug("Error: Could not serialise model diagram node. The model count is null.");
        }

    } else {

        log_message_debug("Error: Could not serialise model diagram node. The details count is null.");
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
 */
void serialise_model_diagram(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10) {

    log_message_debug("Information: Serialise model diagram.");

    // The tree level.
    int l = *NUMBER_0_INTEGER;

    // Serialise model diagram root node.
    serialise_model_diagram_node(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, (void*) &l, (void*) NUMBER_0_INTEGER);
}

/* MODEL_DIAGRAM_CONVERTER_SOURCE */
#endif
