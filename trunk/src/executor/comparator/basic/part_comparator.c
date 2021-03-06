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
 * @version $RCSfile: compound_accessor.c,v $ $Revision: 1.64 $ $Date: 2009-10-06 21:25:26 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef PART_COMPARATOR_SOURCE
#define PART_COMPARATOR_SOURCE

#include "../../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../../constant/model/log/message_log_model.c"
#include "../../../constant/model/memory/integer_memory_model.c"
#include "../../../constant/model/memory/pointer_memory_model.c"
#include "../../../constant/model/memory_model.c"
#include "../../../constant/name/memory/part_memory_name.c"
#include "../../../constant/name/memory/primitive_memory_name.c"
#include "../../../logger/logger.c"

//
// Forward declarations.
//

void compare_all_part_all(void* p0, void* p1, void* p2, void* p3);

/**
 * Compares left- with right part.
 *
 * Compares both parts' name, abstraction, model, details.
 *
 * This is DEEP COMPARISON, i.e. all child nodes will be compared as well.
 *
 * @param p0 the result (number 1 if true; unchanged otherwise)
 * @param p1 the left value
 * @param p2 the right value
 * @param p3 the operation abstraction
 */
void compare_part(void* p0, void* p1, void* p2, void* p3) {

    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Compare part.");

    //
    // Recursively call a comparison function, which in turn
    // may call this comparison function and so forth.
    // This is necessary when processing knowledge tree hierarchies.
    //

    compare_all_part_all(p0, p1, p2, p3);

/*??
    //??
    //?? The code below is an ALTERNATIVE to the "overwrite_part_all" function.
    //?? It may be deleted later, if not needed.
    //?? If reactivated, then it STILL NEEDS TO BE DEBUGGED,
    //?? since it was not quite complete yet.
    //??

    if (p2 != *NULL_POINTER_MEMORY_MODEL) {

        void** rp = (void**) p2;

        if (p1 != *NULL_POINTER_MEMORY_MODEL) {

            void** lp = (void**) p1;

            if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                int* r = (int*) p0;

                log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Compare part.");

                // The source part name, abstraction, model, details.
                void* sn = *NULL_POINTER_MEMORY_MODEL;
                void* sa = *NULL_POINTER_MEMORY_MODEL;
                void* sm = *NULL_POINTER_MEMORY_MODEL;
                void* sd = *NULL_POINTER_MEMORY_MODEL;
                // The source part elements data, count.
                void* snd = *NULL_POINTER_MEMORY_MODEL;
                void* snc = *NULL_POINTER_MEMORY_MODEL;
                void* sad = *NULL_POINTER_MEMORY_MODEL;
                void* sac = *NULL_POINTER_MEMORY_MODEL;
                void* smd = *NULL_POINTER_MEMORY_MODEL;
                void* smc = *NULL_POINTER_MEMORY_MODEL;
                void* sdd = *NULL_POINTER_MEMORY_MODEL;
                void* sdc = *NULL_POINTER_MEMORY_MODEL;
                // The source part abstraction primitive.
                int sap = *NUMBER_MINUS_1_INTEGER_MEMORY_MODEL;

                // Get source part name, abstraction, model, details.
                copy_array_forward((void*) &sn, *s, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) NAME_PART_MEMORY_NAME);
                copy_array_forward((void*) &sa, *s, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) ABSTRACTION_PART_MEMORY_NAME);
                copy_array_forward((void*) &sm, *s, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) MODEL_PART_MEMORY_NAME);
                copy_array_forward((void*) &sd, *s, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) DETAILS_PART_MEMORY_NAME);
                // Get source item data, count.
                copy_array_forward((void*) &snd, sn, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) DATA_ITEM_MEMORY_NAME);
                copy_array_forward((void*) &snc, sn, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) COUNT_ITEM_MEMORY_NAME);
                copy_array_forward((void*) &sad, sa, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) DATA_ITEM_MEMORY_NAME);
                copy_array_forward((void*) &sac, sa, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) COUNT_ITEM_MEMORY_NAME);
                copy_array_forward((void*) &smd, sm, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) DATA_ITEM_MEMORY_NAME);
                copy_array_forward((void*) &smc, sm, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) COUNT_ITEM_MEMORY_NAME);
                copy_array_forward((void*) &sdd, sd, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) DATA_ITEM_MEMORY_NAME);
                copy_array_forward((void*) &sdc, sd, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) COUNT_ITEM_MEMORY_NAME);

                // Determine primitive abstraction.
                // CAUTION! The source abstraction arriving here had already been converted
                // from a cybol- to a cyboi abstraction, e.g. "text/plain" into "wide_character".
                // Therefore, decoding is only needed from a cyboi- to a primitive abstraction.
                decode_wide_character_abstraction((void*) &sap, (void*) sad, (void*) sac);

                // Allocate destination part.
                // CAUTION! Use source part abstraction for allocation!
                allocate_part(p0, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) &sap);

                // Copy source part name, abstraction, model, details to destination.
                // The name is always of abstraction "wide_character".
                overwrite_part_element(*d, snd, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, snc, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) NAME_PART_MEMORY_NAME);
                // The abstraction is always of abstraction "wide_character".
                overwrite_part_element(*d, sad, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, sac, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) ABSTRACTION_PART_MEMORY_NAME);
                // The model is always of the abstraction determined above.
                overwrite_part_element(*d, smd, (void*) &sap, smc, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) MODEL_PART_MEMORY_NAME);
                // The details is always of abstraction "part" (whole, compound).
                overwrite_part_element(*d, sdd, (void*) PART_PRIMITIVE_MEMORY_ABSTRACTION, sdc, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) DETAILS_PART_MEMORY_NAME);

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not compare part. The result is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not compare part. The left part is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not compare part. The right part is null.");
    }
*/
}

/* PART_COMPARATOR_SOURCE */
#endif
