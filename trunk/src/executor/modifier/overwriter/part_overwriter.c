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

#ifndef PART_OVERWRITER_SOURCE
#define PART_OVERWRITER_SOURCE

#include "../../../constant/abstraction/cybol/number_cybol_abstraction.c"
#include "../../../constant/abstraction/cybol/path_cybol_abstraction.c"
#include "../../../constant/abstraction/memory/memory_abstraction.c"
#include "../../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../../constant/model/log/message_log_model.c"
#include "../../../constant/model/memory/integer_memory_model.c"
#include "../../../constant/model/memory/pointer_memory_model.c"
#include "../../../constant/name/cybol/separator_cybol_name.c"
#include "../../../constant/name/memory/part_memory_name.c"
#include "../../../executor/modifier/overwriter/item_overwriter.c"
#include "../../../logger/logger.c"
#include "../../../variable/reallocation_factor.c"

/**
 * Overwrites the destination part element given by the
 * destination part element index with the source array.
 *
 * The destination part element may be either of:
 * name, abstraction, model, details.
 *
 * @param p0 the destination part
 * @param p1 the source array
 * @param p2 the abstraction
 * @param p3 the count
 * @param p4 the destination part index
 * @param p5 the source array index
 * @param p6 the destination part element index
 */
void overwrite_part_element(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Overwrite part element.");

    // The destination part element.
    void* e = *NULL_POINTER_MEMORY_MODEL;

    // Get destination part element.
    copy_array_forward((void*) &e, p0, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p6);

    // Overwrite item as element of the part container.
    overwrite_item_element(e, p1, p2, p3, p4, p5, (void*) DATA_ITEM_MEMORY_NAME);
}

/**
 * Overwrites the destination- with the source part.
 *
 * The name, abstraction, details of the destination part
 * remain unchanged. Only the model gets overwritten.
 *
 * @param p0 the destination part
 * @param p1 the source part
 * @param p2 the abstraction
 * @param p3 the count
 * @param p4 the destination index
 * @param p5 the source index
 */
void overwrite_part(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Overwrite part.");

    // The destination model.
    void* dm = *NULL_POINTER_MEMORY_MODEL;
    // The source model.
    void* sm = *NULL_POINTER_MEMORY_MODEL;

    // Get destination model.
    copy_array_forward((void*) &dm, p0, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) MODEL_PART_MEMORY_NAME);
    // Get source model.
    copy_array_forward((void*) &sm, p1, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) MODEL_PART_MEMORY_NAME);

    // Overwrite destination- with source part model item.
    overwrite_item(dm, sm, p2, p3, p4, p5);
}

/**
 * Overwrites the destination- with the source part.
 *
 * This function copies ALL elements: name, abstraction, model, details.
 *
 * @param p0 the destination part
 * @param p1 the source part
 */
void overwrite_part_all(void* p0, void* p1) {

    if (p1 != *NULL_POINTER_MEMORY_MODEL) {

        void** s = (void**) p1;

        if (p0 != *NULL_POINTER_MEMORY_MODEL) {

            void** d = (void**) p0;

            log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Overwrite part all.");

            // The destination name, abstraction, model, details.
            void* dn = *NULL_POINTER_MEMORY_MODEL;
            void* da = *NULL_POINTER_MEMORY_MODEL;
            void* dm = *NULL_POINTER_MEMORY_MODEL;
            void* dd = *NULL_POINTER_MEMORY_MODEL;
            // The source name, abstraction, model, details.
            void* sn = *NULL_POINTER_MEMORY_MODEL;
            void* sa = *NULL_POINTER_MEMORY_MODEL;
            void* sm = *NULL_POINTER_MEMORY_MODEL;
            void* sd = *NULL_POINTER_MEMORY_MODEL;
            // The source part elements data, count.
            void* snc = *NULL_POINTER_MEMORY_MODEL;
            void* sad = *NULL_POINTER_MEMORY_MODEL;
            void* sac = *NULL_POINTER_MEMORY_MODEL;
            void* smc = *NULL_POINTER_MEMORY_MODEL;
            void* sdc = *NULL_POINTER_MEMORY_MODEL;
            // The source part abstraction primitive.
            int sap = *NUMBER_MINUS_1_INTEGER_MEMORY_MODEL;

            // Get source name, abstraction, model, details.
            copy_array_forward((void*) &sn, *s, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) NAME_PART_MEMORY_NAME);
            copy_array_forward((void*) &sa, *s, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) ABSTRACTION_PART_MEMORY_NAME);
            copy_array_forward((void*) &sm, *s, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) MODEL_PART_MEMORY_NAME);
            copy_array_forward((void*) &sd, *s, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) DETAILS_PART_MEMORY_NAME);
            // Get source item data, count.
            copy_array_forward((void*) &snc, sn, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) COUNT_ITEM_MEMORY_NAME);
            copy_array_forward((void*) &sad, sa, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) DATA_ITEM_MEMORY_NAME);
            copy_array_forward((void*) &sac, sa, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) COUNT_ITEM_MEMORY_NAME);
            copy_array_forward((void*) &smc, sm, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) COUNT_ITEM_MEMORY_NAME);
            copy_array_forward((void*) &sdc, sd, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) COUNT_ITEM_MEMORY_NAME);

            // Determine primitive abstraction.
            // CAUTION! The source abstraction arriving here had already been converted
            // from a cybol- to a cyboi abstraction, e.g. "text/plain" into "wide_character".
            // Therefore, decoding is only needed from a cyboi- to a primitive abstraction.
            decode_wide_character_abstraction((void*) &sap, (void*) sad, (void*) sac);

            // Allocate destination part.
            // CAUTION! Use source part abstraction for allocation!
            allocate_part_NEW(p0, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) &sap);

            // Get destination name, abstraction, model, details.
            // CAUTION! These items can only be retrieved AFTER
            // having created the destination part above.
            copy_array_forward((void*) &dn, *d, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) NAME_PART_MEMORY_NAME);
            copy_array_forward((void*) &da, *d, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) ABSTRACTION_PART_MEMORY_NAME);
            copy_array_forward((void*) &dm, *d, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) MODEL_PART_MEMORY_NAME);
            copy_array_forward((void*) &dd, *d, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) DETAILS_PART_MEMORY_NAME);

            // Overwrite destination- with source part model item.
            overwrite_item(dn, sn, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, snc, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
            overwrite_item(da, sa, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, sac, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
            overwrite_item(dm, sm, (void*) &sap, smc, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
            overwrite_item(dd, sd, (void*) PART_PRIMITIVE_MEMORY_ABSTRACTION, sdc, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME);

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not overwrite part all. The destination is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not overwrite part all. The source is null.");
    }
}

/* PART_OVERWRITER_SOURCE */
#endif
