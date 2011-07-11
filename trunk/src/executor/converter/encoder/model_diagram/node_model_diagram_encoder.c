/*
 * Copyright (C) 1999-2011. Christian Heller.
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
 * @version $RCSfile: model_diagram_converter.c,v $ $Revision: 1.29 $ $Date: 2009-10-06 21:25:27 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef NODE_MODEL_DIAGRAM_ENCODER_SOURCE
#define NODE_MODEL_DIAGRAM_ENCODER_SOURCE

#include "../../../../constant/abstraction/cybol/text_cybol_abstraction.c"
#include "../../../../constant/abstraction/memory/memory_abstraction.c"
#include "../../../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../../../constant/abstraction/operation/primitive_operation_abstraction.c"
#include "../../../../constant/model/character_code/unicode/unicode_character_code_model.c"
#include "../../../../constant/model/log/message_log_model.c"
#include "../../../../constant/model/memory/integer_memory_model.c"
#include "../../../../constant/model/memory/pointer_memory_model.c"
#include "../../../../executor/converter/encoder/model_diagram/compound_model_diagram_encoder.c"
#include "../../../../executor/converter/encoder/model_diagram/indentation_model_diagram_encoder.c"
#include "../../../../executor/converter/encoder/model_diagram/line_model_diagram_encoder.c"
#include "../../../../executor/converter/encoder/integer_vector_encoder.c"
#include "../../../../executor/converter/encoder/double_vector_encoder.c"
#include "../../../../executor/copier/array_copier.c"
#include "../../../../executor/modifier/appender.c"
#include "../../../../logger/logger.c"

/**
 * Encodes the model diagram node.
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
 * @param p11 the tree level
 * @param p12 the details flag
 */
void encode_model_diagram_node(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12) {

    if (p8 != *NULL_POINTER_MEMORY_MODEL) {

        int* mc = (int*) p8;

        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Encode model diagram node.");

        // Add indentation.
        encode_model_diagram_indentation(p0, p1, p2, p11, p12);

        // Add part name to destination array.
        append(p0, p1, p2, p3, p4, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT);

        // Add line.
        encode_model_diagram_line(p0, p1, p2);

        // Add part abstraction to destination array.
        append(p0, p1, p2, p5, p6, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT);

        // The comparison result.
        int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            compare_array_count((void*) &r, p5, p6, (void*) COMPOUND_MEMORY_ABSTRACTION, (void*) COMPOUND_MEMORY_ABSTRACTION_COUNT, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

            if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                if (*mc > *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    // Only process the following code, if the model compound contains at least one part.

                    // Add part model to destination array.
                    encode_model_diagram_compound(p0, p1, p2, p7, p8, p11, (void*) NUMBER_0_INTEGER_MEMORY_MODEL);
                }
            }
        }

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            compare_array_count((void*) &r, p5, p6, (void*) ENCAPSULATED_KNOWLEDGE_PATH_MEMORY_ABSTRACTION, (void*) ENCAPSULATED_KNOWLEDGE_PATH_MEMORY_ABSTRACTION_COUNT, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

            if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                encode_model_diagram_line(p0, p1, p2);
                append(p0, p1, p2, p7, p8, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT);
            }
        }

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            compare_array_count((void*) &r, p5, p6, (void*) FRACTION_MEMORY_ABSTRACTION, (void*) FRACTION_MEMORY_ABSTRACTION_COUNT, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

            if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                encode_model_diagram_line(p0, p1, p2);
                encode_double_vector(p0, p1, p2, p7, p8);
            }
        }

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            compare_array_count((void*) &r, p5, p6, (void*) INTEGER_MEMORY_ABSTRACTION, (void*) INTEGER_MEMORY_ABSTRACTION_COUNT, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

            if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                encode_model_diagram_line(p0, p1, p2);
                encode_integer_vector(p0, p1, p2, p7, p8);
            }
        }

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            compare_array_count((void*) &r, p5, p6, (void*) KNOWLEDGE_PATH_MEMORY_ABSTRACTION, (void*) KNOWLEDGE_PATH_MEMORY_ABSTRACTION_COUNT, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

            if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                encode_model_diagram_line(p0, p1, p2);
                append(p0, p1, p2, p7, p8, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT);
            }
        }

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            compare_array_count((void*) &r, p5, p6, (void*) OPERATION_MEMORY_ABSTRACTION, (void*) OPERATION_MEMORY_ABSTRACTION_COUNT, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

            if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                encode_model_diagram_line(p0, p1, p2);
                append(p0, p1, p2, p7, p8, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT);
            }
        }

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            compare_array_count((void*) &r, p5, p6, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

            if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                encode_model_diagram_line(p0, p1, p2);
                append(p0, p1, p2, p7, p8, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT);
            }
        }

/*??
    //?? TEST BEGIN
    fwprintf(stdout, L"TEST node *n: %ls\n", (wchar_t*) p3);
    if (p4 != *NULL_POINTER_MEMORY_MODEL) {
        fwprintf(stdout, L"TEST node *nc: %i\n", *((int*) p4));
    }

    int test = 0;
    compare_array_count((void*) &test, p3, p4, (void*) L"uri", (void*) NUMBER_3_INTEGER_MEMORY_MODEL, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);
    if (test != 0) {
        fwprintf(stdout, L"TEST node *a: %ls\n", (wchar_t*) p5);
        fwprintf(stdout, L"TEST node *ac: %i\n", *((int*) p6));
        fwprintf(stdout, L"TEST node *m: %i\n", p7);
        fwprintf(stdout, L"TEST node *mc: %i\n", *((int*) p8));
        fwprintf(stdout, L"TEST node *d: %i\n", p9);
        fwprintf(stdout, L"TEST node *dc: %i\n", *((int*) p10));
        fwprintf(stdout, L"TEST node l: %i\n", *((int*) p11));
    }
    //?? TEST END
*/

        // CAUTION! Do NOT move this test to the beginning of the function!
        // Otherwise, a model will not be processed, if the details happen to be null.
        if (p10 != *NULL_POINTER_MEMORY_MODEL) {

            int* dc = (int*) p10;

            if (*dc > *NUMBER_0_INTEGER_MEMORY_MODEL) {

                // Only process the following code, if the details compound contains at least one part.

                // Add part details to destination array.
                encode_model_diagram_compound(p0, p1, p2, p9, p10, p11, (void*) NUMBER_1_INTEGER_MEMORY_MODEL);
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not encode model diagram node. The details count is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not encode model diagram node. The model count is null.");
    }
}

/**
 * Encodes the model diagram node.
 *
 * @param p0 the destination model diagram (Hand over as reference!)
 * @param p1 the destination model diagram count
 * @param p2 the destination model diagram size
 * @param p3 the source name data
 * @param p4 the source name count
 * @param p5 the source abstraction data
 * @param p6 the source abstraction count
 * @param p7 the source model data
 * @param p8 the source model count
 * @param p9 the source details data
 * @param p10 the source details count
 * @param p11 the tree level
 * @param p12 the details flag
 */
void encode_model_diagram_node_NEW(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12) {

    if (p8 != *NULL_POINTER_MEMORY_MODEL) {

        int* mc = (int*) p8;

        if (p0 != *NULL_POINTER_MEMORY_MODEL) {

            void** d = (void**) p0;

            log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Encode model diagram node.");

            // Add indentation.
            encode_model_diagram_indentation_NEW(p0, p1, p2, p11, p12);

            // Add part name to destination array.
            copy_array_append(p0, p3, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p4, p1, p2);

            // Add line.
            encode_model_diagram_line_NEW(p0, p1, p2);

            // Add part abstraction to destination array.
            copy_array_append(p0, p5, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p6, p1, p2);

            // The comparison result.
            int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

            if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                compare_array_count((void*) &r, p5, p6, (void*) PART_MEMORY_ABSTRACTION, (void*) PART_MEMORY_ABSTRACTION_COUNT, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    if (*mc > *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        // Only process the following code, if the model compound contains at least one part.

                        // Add part model to destination array.
                        encode_model_diagram_compound_NEW(p0, p1, p2, p7, p8, p11, (void*) NUMBER_0_INTEGER_MEMORY_MODEL);
                    }
                }
            }

            if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                compare_array_count((void*) &r, p5, p6, (void*) ENCAPSULATED_KNOWLEDGE_PATH_MEMORY_ABSTRACTION, (void*) ENCAPSULATED_KNOWLEDGE_PATH_MEMORY_ABSTRACTION_COUNT, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    encode_model_diagram_line_NEW(p0, p1, p2);
                    copy_array_append(p0, p7, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p8, p1, p2);
                }
            }

            if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                compare_array_count((void*) &r, p5, p6, (void*) FRACTION_MEMORY_ABSTRACTION, (void*) FRACTION_MEMORY_ABSTRACTION_COUNT, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    encode_model_diagram_line_NEW(p0, p1, p2);
                    encode_double_vector(p0, p1, p2, p7, p8);
                }
            }

            if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                compare_array_count((void*) &r, p5, p6, (void*) INTEGER_MEMORY_ABSTRACTION, (void*) INTEGER_MEMORY_ABSTRACTION_COUNT, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    encode_model_diagram_line_NEW(p0, p1, p2);
                    encode_integer_vector(p0, p1, p2, p7, p8);
                }
            }

            if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                compare_array_count((void*) &r, p5, p6, (void*) KNOWLEDGE_PATH_MEMORY_ABSTRACTION, (void*) KNOWLEDGE_PATH_MEMORY_ABSTRACTION_COUNT, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    encode_model_diagram_line_NEW(p0, p1, p2);
                    copy_array_append(p0, p7, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p8, p1, p2);
                }
            }

            if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                compare_array_count((void*) &r, p5, p6, (void*) OPERATION_MEMORY_ABSTRACTION, (void*) OPERATION_MEMORY_ABSTRACTION_COUNT, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    encode_model_diagram_line_NEW(p0, p1, p2);
                    copy_array_append(p0, p7, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p8, p1, p2);
                }
            }

            if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                compare_array_count((void*) &r, p5, p6, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    encode_model_diagram_line_NEW(p0, p1, p2);
                    copy_array_append(p0, p7, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p8, p1, p2);
                }
            }

/*??
    //?? TEST BEGIN
    fwprintf(stdout, L"TEST node *n: %ls\n", (wchar_t*) p3);
    if (p4 != *NULL_POINTER_MEMORY_MODEL) {
        fwprintf(stdout, L"TEST node *nc: %i\n", *((int*) p4));
    }

    int test = 0;
    compare_array_count((void*) &test, p3, p4, (void*) L"uri", (void*) NUMBER_3_INTEGER_MEMORY_MODEL, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);
    if (test != 0) {
        fwprintf(stdout, L"TEST node *a: %ls\n", (wchar_t*) p5);
        fwprintf(stdout, L"TEST node *ac: %i\n", *((int*) p6));
        fwprintf(stdout, L"TEST node *m: %i\n", p7);
        fwprintf(stdout, L"TEST node *mc: %i\n", *((int*) p8));
        fwprintf(stdout, L"TEST node *d: %i\n", p9);
        fwprintf(stdout, L"TEST node *dc: %i\n", *((int*) p10));
        fwprintf(stdout, L"TEST node l: %i\n", *((int*) p11));
    }
    //?? TEST END
*/

            // CAUTION! Do NOT move this test to the beginning of the function!
            // Otherwise, a model will not be processed, if the details happen to be null.
            if (p10 != *NULL_POINTER_MEMORY_MODEL) {

                int* dc = (int*) p10;

                if (*dc > *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    // Only process the following code, if the details compound contains at least one part.

                    // Add part details to destination array.
                    encode_model_diagram_compound_NEW(p0, p1, p2, p9, p10, p11, (void*) NUMBER_1_INTEGER_MEMORY_MODEL);
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not encode model diagram node. The details count is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not encode model diagram node. The model diagram is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not encode model diagram node. The model count is null.");
    }
}

/* NODE_MODEL_DIAGRAM_ENCODER_SOURCE */
#endif
