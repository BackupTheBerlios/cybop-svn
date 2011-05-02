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

#ifndef MODEL_SETTER_SOURCE
#define MODEL_SETTER_SOURCE

#include "../../../constant/abstraction/cybol/number_cybol_abstraction.c"
#include "../../../constant/abstraction/cybol/path_cybol_abstraction.c"
#include "../../../constant/abstraction/memory/memory_abstraction.c"
#include "../../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../../constant/model/log/message_log_model.c"
#include "../../../constant/model/memory/integer_memory_model.c"
#include "../../../constant/model/memory/pointer_memory_model.c"
#include "../../../constant/name/cybol/separator_cybol_name.c"
#include "../../../constant/name/memory/model_memory_name.c"
#include "../../../executor/comparator/wide_character_equal_array_comparator.c"
#include "../../../executor/memoriser/reallocator/compound_reallocator.c"
#include "../../../logger/logger.c"
#include "../../../variable/reallocation_factor.c"

/**
 * Sets the source model into the destination model at position index.
 *
 * CAUTION! The size of the destination has to be adjusted BEFORE calling
 * this function. The validity of the given index is NOT tested here.
 *
 * @param p0 the destination model
 * @param p1 the source model
 * @param p2 the count
 * @param p3 the destination model index
 */
void set_model(void* p0, void* p1, void* p2, void* p3) {

    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Set model.");

    // The destination names, abstractions, models, details.
    void* dn = *NULL_POINTER_MEMORY_MODEL;
    void* da = *NULL_POINTER_MEMORY_MODEL;
    void* dm = *NULL_POINTER_MEMORY_MODEL;
    void* dd = *NULL_POINTER_MEMORY_MODEL;
    // The source names, abstractions, models, details.
    void* sn = *NULL_POINTER_MEMORY_MODEL;
    void* sa = *NULL_POINTER_MEMORY_MODEL;
    void* sm = *NULL_POINTER_MEMORY_MODEL;
    void* sd = *NULL_POINTER_MEMORY_MODEL;

    // Get destination names, abstractions, models, details.
    get((void*) &dn, p0, (void*) NAMES_MODEL_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);
    get((void*) &da, p0, (void*) ABSTRACTIONS_MODEL_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);
    get((void*) &dm, p0, (void*) MODELS_MODEL_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);
    get((void*) &dd, p0, (void*) DETAILS_MODEL_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);
    // Get source names, abstractions, models, details.
    get((void*) &sn, p1, (void*) NAMES_MODEL_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);
    get((void*) &sa, p1, (void*) ABSTRACTIONS_MODEL_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);
    get((void*) &sm, p1, (void*) MODELS_MODEL_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);
    get((void*) &sd, p1, (void*) DETAILS_MODEL_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);

    // The source abstraction data, count.
    void* sad = *NULL_POINTER_MEMORY_MODEL;
    void* sac = *NULL_POINTER_MEMORY_MODEL;

    // Get source abstraction data, count.
    get((void*) &sad, sa, (void*) DATA_ITEM_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);
    get((void*) &sac, sa, (void*) COUNT_ITEM_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);

    // Set source model into destination model.
    set_item(dn, sn, p2, p3, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT);
    set_item(da, sa, p2, p3, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT);
    set_item(dm, sm, p2, p3, sad, sac);
    set_item(dd, sd, p2, p3, (void*) MODEL_MEMORY_ABSTRACTION, (void*) MODEL_MEMORY_ABSTRACTION_COUNT);
}

/**
 * Replaces the compound element by name.
 *
 * @param p0 the compound
 * @param p1 the compound count
 * @param p2 the compound size
 * @param p3 the name
 * @param p4 the name count
 * @param p5 the name size
 * @param p6 the abstraction
 * @param p7 the abstraction count
 * @param p8 the abstraction size
 * @param p9 the model
 * @param p10 the model count
 * @param p11 the model size
 * @param p12 the details
 * @param p13 the details count
 * @param p14 the details size
 */
void replace_compound_by_name(void* p0, void* p1, void* p2,
    void* p3, void* p4, void* p5, void* p6, void* p7, void* p8,
    void* p9, void* p10, void* p11, void* p12, void* p13, void* p14) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Replace compound element by name.");

    // The element name index.
    int i = *NUMBER_MINUS_1_INTEGER_MEMORY_MODEL;

    // Get compound element index.
    //
    // CAUTION! The name is given WITHOUT prefix here!
    // Correct example: "patient"
    // Incorrect examples: ".patient", "#patient"
    get_compound_element_index(p0, p1, p3, p4, (void*) &i);

//??    fwprintf(stdout, L"TEST element index %i\n", i);

    if (i >= *NUMBER_0_INTEGER_MEMORY_MODEL) {

        log_terminated_message((void*) WARNING_LEVEL_LOG_MODEL, (void*) L"Could not replace compound element by name. A compound element with that name does already exist.");

    } else {

        // Could not get compound element index.
        // An element with that name does not exist.
        // Therefore, add compound element by name here.

        // CAUTION! Use compound count as index for adding new elements.
        replace_compound_by_index(p0, p1, p2, p1, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14);
    }
}

/* MODEL_SETTER_SOURCE */
#endif
