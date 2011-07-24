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

#ifndef COMPOUND_MODEL_DIAGRAM_ENCODER_SOURCE
#define COMPOUND_MODEL_DIAGRAM_ENCODER_SOURCE

#include "../../../../constant/abstraction/cybol/text_cybol_abstraction.c"
#include "../../../../constant/abstraction/memory/memory_abstraction.c"
#include "../../../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../../../constant/model/character_code/unicode/unicode_character_code_model.c"
#include "../../../../constant/model/log/message_log_model.c"
#include "../../../../constant/model/memory/integer_memory_model.c"
#include "../../../../constant/model/memory/pointer_memory_model.c"
#include "../../../../executor/converter/encoder/integer_vector_encoder.c"
#include "../../../../executor/converter/encoder/double_vector_encoder.c"
#include "../../../../executor/modifier/inserter/array_inserter.c"
#include "../../../../executor/modifier/appender.c"
#include "../../../../logger/logger.c"

//
// Forward declarations.
//

void encode_model_diagram_node(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12);

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

            // The new tree level.
            //
            // It gets initialised with the current tree level incremented by one.
            //
            // CAUTION! Do NOT manipulate the original tree level that was handed over as parameter!
            // Otherwise, it would never be decremented anymore leading to wrong indentation.
            int nl = *l + *NUMBER_1_INTEGER_MEMORY_MODEL;

            while (*NUMBER_1_INTEGER_MEMORY_MODEL) {

                if (j >= *sc) {

                    break;
                }

                // Get part abstraction, model, details at current index.
                get_compound_element_by_index(p3, p4, (void*) &j,
                    (void*) &n, (void*) &nc, (void*) &ns,
                    (void*) &a, (void*) &ac, (void*) &as,
                    (void*) &m, (void*) &mc, (void*) &ms,
                    (void*) &d, (void*) &dc, (void*) &ds);

/*??
    fwprintf(stdout, L"TEST encode model diagram compound p0: %i\n", p0);
    fwprintf(stdout, L"TEST encode model diagram compound p1: %i\n", p1);
    fwprintf(stdout, L"TEST encode model diagram compound p2: %i\n", p2);
    fwprintf(stdout, L"TEST encode model diagram compound *n: %i\n", *n);
    fwprintf(stdout, L"TEST encode model diagram compound *nc: %i\n", *nc);
    fwprintf(stdout, L"TEST encode model diagram compound *a: %i\n", *a);
    fwprintf(stdout, L"TEST encode model diagram compound *ac: %i\n", *ac);
    fwprintf(stdout, L"TEST encode model diagram compound *m: %i\n", *m);
    fwprintf(stdout, L"TEST encode model diagram compound *mc: %i\n", *mc);
    fwprintf(stdout, L"TEST encode model diagram compound *d: %i\n", *d);
    fwprintf(stdout, L"TEST encode model diagram compound *dc: %i\n", *dc);
    fwprintf(stdout, L"TEST encode model diagram compound nl: %i\n", nl);
    fwprintf(stdout, L"TEST encode model diagram compound &nl: %i\n", &nl);
    fwprintf(stdout, L"TEST encode model diagram compound p6: %i\n", p6);
*/

                // Add line feed character to destination array.
                append(p0, p1, p2, (void*) LINE_FEED_CONTROL_UNICODE_CHARACTER_CODE_MODEL, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT);

                // Encode part.
                encode_model_diagram_node(p0, p1, p2, *n, *nc, *a, *ac, *m, *mc, *d, *dc, (void*) &nl, p6);

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
void encode_model_diagram_compound_NEW(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    if (p4 != *NULL_POINTER_MEMORY_MODEL) {

        int* sc = (int*) p4;

        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Encode model diagram compound.");

        // The loop variable.
        int j = *NUMBER_0_INTEGER_MEMORY_MODEL;
        // The part retrieved as reference.
        void* p = *NULL_POINTER_MEMORY_MODEL;
        // The part elements retrieved as reference.
        void* n = *NULL_POINTER_MEMORY_MODEL;
        void* a = *NULL_POINTER_MEMORY_MODEL;
        void* m = *NULL_POINTER_MEMORY_MODEL;
        void* d = *NULL_POINTER_MEMORY_MODEL;
        // The part elements data, count retrieved as reference.
        void* nd = *NULL_POINTER_MEMORY_MODEL;
        void* nc = *NULL_POINTER_MEMORY_MODEL;
        void* ad = *NULL_POINTER_MEMORY_MODEL;
        void* ac = *NULL_POINTER_MEMORY_MODEL;
        void* md = *NULL_POINTER_MEMORY_MODEL;
        void* mc = *NULL_POINTER_MEMORY_MODEL;
        void* dd = *NULL_POINTER_MEMORY_MODEL;
        void* dc = *NULL_POINTER_MEMORY_MODEL;

        // The new tree level.
        //
        // It gets initialised with the current tree level incremented by one.
        //
        // CAUTION! Do NOT manipulate the original tree level that was handed over as parameter!
        // Otherwise, it would never be decremented anymore leading to wrong indentation.
        int l = *NUMBER_0_INTEGER_MEMORY_MODEL;

        // Add memory area to current position.
        add_integer((void*) &l, p5, (void*) INTEGER_PRIMITIVE_MEMORY_ABSTRACTION);
        // Add memory area to current position.
        add_integer((void*) &l, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) INTEGER_PRIMITIVE_MEMORY_ABSTRACTION);

        while (*NUMBER_1_INTEGER_MEMORY_MODEL) {

            if (j >= *sc) {

                break;
            }

            // Get part from source whole at current index.
            copy_array_forward((void*) &p, p3, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) &j);

            // Get part elements.
            copy_array_forward((void*) &n, p, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) NAME_PART_MEMORY_NAME);
            copy_array_forward((void*) &a, p, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) ABSTRACTION_PART_MEMORY_NAME);
            copy_array_forward((void*) &m, p, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) MODEL_PART_MEMORY_NAME);
            copy_array_forward((void*) &d, p, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) DETAILS_PART_MEMORY_NAME);

            // Get part elements data, count retrieved as reference.
            copy_array_forward((void*) &nd, n, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) DATA_ITEM_MEMORY_NAME);
            copy_array_forward((void*) &nc, n, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) COUNT_ITEM_MEMORY_NAME);
            copy_array_forward((void*) &ad, a, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) DATA_ITEM_MEMORY_NAME);
            copy_array_forward((void*) &ac, a, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) COUNT_ITEM_MEMORY_NAME);
            copy_array_forward((void*) &md, m, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) DATA_ITEM_MEMORY_NAME);
            copy_array_forward((void*) &mc, m, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) COUNT_ITEM_MEMORY_NAME);
            copy_array_forward((void*) &dd, d, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) DATA_ITEM_MEMORY_NAME);
            copy_array_forward((void*) &dc, d, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) COUNT_ITEM_MEMORY_NAME);

            // Add line feed character to destination array.
            insert_array(p0, (void*) LINE_FEED_CONTROL_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);

            // Encode part.
            encode_model_diagram_node_NEW(p0, p1, p2, nd, nc, ad, ac, md, mc, dd, dc, (void*) &l, p6);

            // Increment loop variable.
            j++;
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not encode model diagram compound. The source count is null.");
    }
}

/* COMPOUND_MODEL_DIAGRAM_ENCODER_SOURCE */
#endif
