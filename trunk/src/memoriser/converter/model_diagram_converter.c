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
 * @version $RCSfile: model_diagram_converter.c,v $ $Revision: 1.22 $ $Date: 2008-11-14 23:21:18 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef MODEL_DIAGRAM_CONVERTER_SOURCE
#define MODEL_DIAGRAM_CONVERTER_SOURCE

#include "../../constant/model/character_code/unicode/unicode_character_code_model.c"
#include "../../constant/abstraction/cybol/text_cybol_abstraction.c"
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../constant/model/log/message_log_model.c"
#include "../../constant/abstraction/memory/array_memory_abstraction.c"
#include "../../constant/abstraction/memory/memory_abstraction.c"
#include "../../constant/abstraction/memory/memory_abstraction.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../logger/logger.c"

//
// Forward declarations.
//

void encode_model_diagram_node(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12);

/**
 * Decodes the model diagram and creates a knowledge model from it.
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
void decode_model_diagram(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Decode model diagram.");
}

/**
 * Encodes the model diagram indentation.
 *
 * @param p0 the destination model diagram (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the tree level
 * @param p4 the details flag
 */
void encode_model_diagram_indentation(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p4 != *NULL_POINTER_MEMORY_MODEL) {

        int* d = (int*) p4;

        if (p3 != *NULL_POINTER_MEMORY_MODEL) {

            int* l = (int*) p3;

            log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Encode model diagram indentation.");

            // The loop variable.
            int j = *NUMBER_0_INTEGER_MEMORY_MODEL;

            while (*NUMBER_1_INTEGER_MEMORY_MODEL) {

                if (j >= *l) {

                    break;
                }

                // Check if the last of many indentations has been reached.
                if ((j + *NUMBER_1_INTEGER_MEMORY_MODEL) < *l) {

                    // This is one of many indentations before the actual part appears.
                    // Therefore, use a pipe- and space character.

                    // Add pipe character to destination array.
                    append_wide_character_vector(p0, p1, p2, (void*) VERTICAL_LINE_UNICODE_CHARACTER_CODE_MODEL, (void*) PRIMITIVE_MEMORY_MODEL_COUNT);

                    // Add space character to destination array.
                    append_wide_character_vector(p0, p1, p2, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) PRIMITIVE_MEMORY_MODEL_COUNT);

                } else {

                    // This is the last indentation. Special characters are used for it.

                    if (*d == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        // This is the part model, so that a plus- and minus character are used.

                        // Add plus character to destination array.
                        append_wide_character_vector(p0, p1, p2, (void*) PLUS_SIGN_UNICODE_CHARACTER_CODE_MODEL, (void*) PRIMITIVE_MEMORY_MODEL_COUNT);

                        // Add minus character to destination array.
                        append_wide_character_vector(p0, p1, p2, (void*) HYPHEN_MINUS_UNICODE_CHARACTER_CODE_MODEL, (void*) PRIMITIVE_MEMORY_MODEL_COUNT);

                    } else {

                        // This is the part details, so that a number sign- and minus character are used.

                        // Add plus character to destination array.
                        append_wide_character_vector(p0, p1, p2, (void*) NUMBER_SIGN_UNICODE_CHARACTER_CODE_MODEL, (void*) PRIMITIVE_MEMORY_MODEL_COUNT);

                        // Add minus character to destination array.
                        append_wide_character_vector(p0, p1, p2, (void*) HYPHEN_MINUS_UNICODE_CHARACTER_CODE_MODEL, (void*) PRIMITIVE_MEMORY_MODEL_COUNT);
                    }
                }

                // Increment loop variable.
                j++;
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not encode model diagram indentation. The tree level is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not encode model diagram indentation. The details flag is null.");
    }
}

/**
 * Encodes the model diagram compound.
 *
 * @param p0 the destination model diagram (Hand over as reference!)
 * @param p1 the destination model diagram count
 * @param p2 the destination model diagram size
 * @param p3 the source compound model
 * @param p4 the source compound model count
 * @param p5 the tree level
 * @param p6 the details flag
 */
void encode_model_diagram_compound(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    if (p5 != *NULL_POINTER_MEMORY_MODEL) {

        int* l = (int*) p5;

        if (p4 != *NULL_POINTER_MEMORY_MODEL) {

            int* sc = (int*) p4;

            log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Encode model diagram compound.");

    fwprintf(stderr, L"TEST encode model diagram compound 0: %i\n", *((int*) p5));

            // The loop variable.
            int j = *NUMBER_0_INTEGER_MEMORY_MODEL;

            // The part name, abstraction, model, details.
            void** n = NULL_POINTER_MEMORY_MODEL;
            void** nc = NULL_POINTER_MEMORY_MODEL;
            void** ns = NULL_POINTER_MEMORY_MODEL;
            void** a = NULL_POINTER_MEMORY_MODEL;
            void** ac = NULL_POINTER_MEMORY_MODEL;
            void** as = NULL_POINTER_MEMORY_MODEL;
            void** m = NULL_POINTER_MEMORY_MODEL;
            void** mc = NULL_POINTER_MEMORY_MODEL;
            void** ms = NULL_POINTER_MEMORY_MODEL;
            void** d = NULL_POINTER_MEMORY_MODEL;
            void** dc = NULL_POINTER_MEMORY_MODEL;
            void** ds = NULL_POINTER_MEMORY_MODEL;

    fwprintf(stderr, L"TEST encode model diagram compound 1 j: %i\n", j);

            // The new tree level.
            //
            // It gets initialised with the current tree level incremented by one.
            //
            // CAUTION! Do NOT manipulate the original tree level that was handed over as parameter!
            // Otherwise, it would never be decremented anymore leading to wrong indentation.
            int nl = *l + *NUMBER_1_INTEGER_MEMORY_MODEL;

    fwprintf(stderr, L"TEST encode model diagram compound 2 nl: %i\n", nl);

            while (*NUMBER_1_INTEGER_MEMORY_MODEL) {

                if (j >= *sc) {

                    break;
                }

    fwprintf(stderr, L"TEST encode model diagram compound 3 j: %i\n", j);

                // Get part abstraction, model, details at current index.
                get_compound_element_by_index(p3, p4, (void*) &j,
                    (void*) &n, (void*) &nc, (void*) &ns,
                    (void*) &a, (void*) &ac, (void*) &as,
                    (void*) &m, (void*) &mc, (void*) &ms,
                    (void*) &d, (void*) &dc, (void*) &ds);

    fwprintf(stderr, L"TEST encode model diagram compound 4 j: %i\n", j);
    fwprintf(stderr, L"TEST encode model diagram compound 4 p1: %i\n", *((int*) p1));
    fwprintf(stderr, L"TEST encode model diagram compound 4 p0: %i\n", p0);
    fwprintf(stderr, L"TEST encode model diagram compound 4 p0 as wchar_t: %ls\n", *((wchar_t**) p0));

                // Add line feed character to destination array.
                append_wide_character_vector(p0, p1, p2, (void*) LINE_FEED_CONTROL_UNICODE_CHARACTER_CODE_MODEL, (void*) PRIMITIVE_MEMORY_MODEL_COUNT);

    fwprintf(stderr, L"TEST encode model diagram compound 5 j: %i\n", j);

                // Encode part.
                encode_model_diagram_node(p0, p1, p2, *n, *nc, *a, *ac, *m, *mc, *d, *dc, (void*) &nl, p6);

    fwprintf(stderr, L"TEST encode model diagram compound 6 j: %i\n", j);

                // Increment loop variable.
                j++;
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not encode model diagram compound. The source count is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not encode model diagram compound. The tree level is null.");
    }
}

/**
 * Encodes the model diagram node.
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
void encode_model_diagram_node(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12) {

    if (p10 != *NULL_POINTER_MEMORY_MODEL) {

        int* dc = (int*) p10;

        if (p8 != *NULL_POINTER_MEMORY_MODEL) {

            int* mc = (int*) p8;

            log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Encode model diagram node.");

    fwprintf(stderr, L"TEST encode model diagram 0: %i\n", *((int*) p11));

            // Add indentation.
            encode_model_diagram_indentation(p0, p1, p2, p11, p12);

    fwprintf(stderr, L"TEST encode model diagram 1: %i\n", *((int*) p11));

            // Add part name to destination array.
            append_wide_character_vector(p0, p1, p2, p3, p4);

    fwprintf(stderr, L"TEST encode model diagram 2: %i\n", *((int*) p11));

            // Add space character to destination array.
            append_wide_character_vector(p0, p1, p2, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) PRIMITIVE_MEMORY_MODEL_COUNT);

    fwprintf(stderr, L"TEST encode model diagram 3: %i\n", *((int*) p11));

            // Add pipe character to destination array.
            append_wide_character_vector(p0, p1, p2, (void*) VERTICAL_LINE_UNICODE_CHARACTER_CODE_MODEL, (void*) PRIMITIVE_MEMORY_MODEL_COUNT);

            // Add space character to destination array.
            append_wide_character_vector(p0, p1, p2, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) PRIMITIVE_MEMORY_MODEL_COUNT);

            // Add part abstraction to destination array.
            append_wide_character_vector(p0, p1, p2, p5, p6);

            // The comparison result.
            int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

    fwprintf(stderr, L"TEST encode model diagram 4: %i\n", *((int*) p11));

            if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                compare_arrays(p5, p6, (void*) COMPOUND_MEMORY_ABSTRACTION, (void*) COMPOUND_MEMORY_ABSTRACTION_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

                if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    if (*mc > *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        // Only process the following code, if the model compound contains at least one part.

                        // Add part model to destination array.
                        encode_model_diagram_compound(p0, p1, p2, p7, p8, p11, (void*) NUMBER_0_INTEGER_MEMORY_MODEL);
                    }
                }
            }

    fwprintf(stderr, L"TEST encode model diagram 5: %i\n", *((int*) p11));

            if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                compare_arrays(p5, p6, (void*) XDT_TEXT_CYBOL_ABSTRACTION, (void*) XDT_TEXT_CYBOL_ABSTRACTION_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

                if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    if (*mc > *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        // Only process the following code, if the model compound contains at least one part.

                        // Add part model to destination array.
                        encode_model_diagram_compound(p0, p1, p2, p7, p8, p11, (void*) NUMBER_0_INTEGER_MEMORY_MODEL);
                    }
                }
            }

    fwprintf(stderr, L"TEST encode model diagram 6: %i\n", *((int*) p11));

            if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                compare_arrays(p5, p6, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

                if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    // Add space character to destination array.
                    append_wide_character_vector(p0, p1, p2, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) PRIMITIVE_MEMORY_MODEL_COUNT);

                    // Add pipe character to destination array.
                    append_wide_character_vector(p0, p1, p2, (void*) VERTICAL_LINE_UNICODE_CHARACTER_CODE_MODEL, (void*) PRIMITIVE_MEMORY_MODEL_COUNT);

                    // Add space character to destination array.
                    append_wide_character_vector(p0, p1, p2, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) PRIMITIVE_MEMORY_MODEL_COUNT);

                    // Add part model to destination array.
                    append_wide_character_vector(p0, p1, p2, p7, p8);
                }
            }

    fwprintf(stderr, L"TEST encode model diagram 7: %i\n", *((int*) p11));

            if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                compare_arrays(p5, p6, (void*) INTEGER_VECTOR_MEMORY_ABSTRACTION, (void*) INTEGER_VECTOR_MEMORY_ABSTRACTION_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

                if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    // Add space character to destination array.
                    append_wide_character_vector(p0, p1, p2, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) PRIMITIVE_MEMORY_MODEL_COUNT);

                    // Add pipe character to destination array.
                    append_wide_character_vector(p0, p1, p2, (void*) VERTICAL_LINE_UNICODE_CHARACTER_CODE_MODEL, (void*) PRIMITIVE_MEMORY_MODEL_COUNT);

                    // Add space character to destination array.
                    append_wide_character_vector(p0, p1, p2, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) PRIMITIVE_MEMORY_MODEL_COUNT);

                    // Add part model to destination array.
                    encode_integer_vector(p0, p1, p2, p7, p8);
                }
            }

    fwprintf(stderr, L"TEST encode model diagram 8: %i\n", *((int*) p11));

            if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                compare_arrays(p5, p6, (void*) BOOLEAN_LOGICVALUE_CYBOL_ABSTRACTION, (void*) BOOLEAN_LOGICVALUE_CYBOL_ABSTRACTION_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

                if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    // Add space character to destination array.
                    append_wide_character_vector(p0, p1, p2, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) PRIMITIVE_MEMORY_MODEL_COUNT);

                    // Add pipe character to destination array.
                    append_wide_character_vector(p0, p1, p2, (void*) VERTICAL_LINE_UNICODE_CHARACTER_CODE_MODEL, (void*) PRIMITIVE_MEMORY_MODEL_COUNT);

                    // Add space character to destination array.
                    append_wide_character_vector(p0, p1, p2, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) PRIMITIVE_MEMORY_MODEL_COUNT);

                    // Add part model to destination array.
                    encode_boolean(p0, p1, p2, p7, p8);
                }
            }

    fwprintf(stderr, L"TEST encode model diagram 9: %i\n", *((int*) p11));

            if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                compare_arrays(p5, p6, (void*) FRACTION_MEMORY_ABSTRACTION, (void*) FRACTION_MEMORY_ABSTRACTION_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

                if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    // Add space character to destination array.
                    append_wide_character_vector(p0, p1, p2, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) PRIMITIVE_MEMORY_MODEL_COUNT);

                    // Add pipe character to destination array.
                    append_wide_character_vector(p0, p1, p2, (void*) VERTICAL_LINE_UNICODE_CHARACTER_CODE_MODEL, (void*) PRIMITIVE_MEMORY_MODEL_COUNT);

                    // Add space character to destination array.
                    append_wide_character_vector(p0, p1, p2, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) PRIMITIVE_MEMORY_MODEL_COUNT);

                    // Add part model to destination array.
                    encode_double_vector(p0, p1, p2, p7, p8);
                }
            }

    fwprintf(stderr, L"TEST encode model diagram 10: %i\n", *((int*) p11));

            if (*dc > *NUMBER_0_INTEGER_MEMORY_MODEL) {

                // Only process the following code, if the details compound contains at least one part.

                // Add part details to destination array.
                encode_model_diagram_compound(p0, p1, p2, p9, p10, p11, (void*) NUMBER_1_INTEGER_MEMORY_MODEL);
            }

    fwprintf(stderr, L"TEST encode model diagram 11: %i\n", *((int*) p11));

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not encode model diagram node. The model count is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not encode model diagram node. The details count is null.");
    }
}

/**
 * Encodes the knowledge model and creates a model diagram from it.
 *
 * A model diagram in this case is a textual representation of a knowledge model,
 * in form of many line feed-separated lines representing a model part each.
 *
 * @param p0 the destination model diagram (Hand over as reference!)
 * @param p1 the destination model diagram count
 * @param p2 the destination model diagram size
 * @param p3 the source name
 * @param p4 the source name count
 * @param p5 the source abstraction
 * @param p6 the source abstraction count
 * @param p7 the source model
 * @param p8 the source model count
 * @param p9 the source details
 * @param p10 the source details count
 */
void encode_model_diagram(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Encode model diagram.");

    // The tree level.
    int l = *NUMBER_0_INTEGER_MEMORY_MODEL;

    // Encode model diagram root node.
    encode_model_diagram_node(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, (void*) &l, (void*) NUMBER_0_INTEGER_MEMORY_MODEL);
}

/* MODEL_DIAGRAM_CONVERTER_SOURCE */
#endif
