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
 * @version $RCSfile: destructing_memoriser.c,v $ $Revision: 1.6 $ $Date: 2009-01-31 16:06:29 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef DESTRUCTING_MEMORISER_SOURCE
#define DESTRUCTING_MEMORISER_SOURCE

#include "../../constant/abstraction/cybol/text_cybol_abstraction.c"
#include "../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../constant/model/log/message_log_model.c"
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../constant/name/cybol/operation/memory/destroy_memory_operation_cybol_name.c"
#include "../../executor/accessor/getter/compound_getter.c"
#include "../../executor/accessor/remover/compound_remover.c"
#include "../../executor/comparator/array_equality_comparator.c"
#include "../../logger/logger.c"

//
// Forward declarations.
//

/**
 * Destroys a transient destination model.
 *
 * @param p0 the model
 * @param p1 the model count
 * @param p2 the model size
 * @param p3 the model abstraction
 * @param p4 the model abstraction count
 */
void destroy_model(void** model, void* model_count, void* model_size, void* model_abstr, void* model_abstr_count);

/**
 * Checks for a compound model.
 *
 * @param p0 the primitive flag (1 if primitive; unchanged otherwise)
 * @param p1 the abstraction
 * @param p2 the abstraction count
 */
void check_compound_model(void* p0, void* p1, void* p2) {

    if (p0 != *NULL_POINTER_MEMORY_MODEL) {

        int* p = (int*) p0;

        if (*p != *NUMBER_1_INTEGER_MEMORY_MODEL) {

            compare_equal_arrays(p0, p1, p2, (void*) COMPOUND_MEMORY_ABSTRACTION, (void*) COMPOUND_MEMORY_ABSTRACTION_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);
        }
    }
}

/**
 * Destroys a primitive model.
 *
 * @param p0 the model
 * @param p1 the model count
 * @param p2 the model size
 * @param p3 the model abstraction
 * @param p4 the model abstraction count
 */
void destroy_primitive_model(void** model, void* model_count, void* model_size,
    void* model_abstr, void* model_abstr_count) {

    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Destroy primitive model.");

    // Destroy model of type given as abstraction.
    deallocate(model, model_size, model_abstr, model_abstr_count);
}

/**
 * Destroys a compound model.
 *
 * @param p0 the model
 * @param p1 the model count
 * @param p2 the model size
 * @param p3 the model abstraction
 * @param p4 the model abstraction count
 */
void destroy_compound_model(void** model, void* model_count, void* model_size,
    void* model_abstr, void* model_abstr_count) {

    // das gesamte Compound durchgehen und f?r jedes Element im Compound wieder destroy model aufrufen

    int compound_counter = *NUMBER_0_INTEGER_MEMORY_MODEL;

    // The element name.
    void** en = NULL_POINTER_MEMORY_MODEL;
    void** enc = NULL_POINTER_MEMORY_MODEL;
    void** ens = NULL_POINTER_MEMORY_MODEL;
    // The element abstraction.
    void** ea = NULL_POINTER_MEMORY_MODEL;
    void** eac = NULL_POINTER_MEMORY_MODEL;
    void** eas = NULL_POINTER_MEMORY_MODEL;
    // The element model.
    void** em = NULL_POINTER_MEMORY_MODEL;
    void** emc = NULL_POINTER_MEMORY_MODEL;
    void** ems = NULL_POINTER_MEMORY_MODEL;
    // The element details.
    void** ed = NULL_POINTER_MEMORY_MODEL;
    void** edc = NULL_POINTER_MEMORY_MODEL;
    void** eds = NULL_POINTER_MEMORY_MODEL;

    while (*NUMBER_1_INTEGER_MEMORY_MODEL) {

        if (compound_counter >= *((int*) model_count)) {

            break;
        }

        // Get element.
        get_compound_element_by_index(*model, model_count, (void*) &compound_counter,
            (void*) &en, (void*) &enc, (void*) &ens,
            (void*) &ea, (void*) &eac, (void*) &eas,
            (void*) &em, (void*) &emc, (void*) &ems,
            (void*) &ed, (void*) &edc, (void*) &eds);

        destroy_model(em, *emc, *ems, *ea, *eac);

        compound_counter = compound_counter + *NUMBER_1_INTEGER_MEMORY_MODEL;
    }
}

/**
 * Destroys a transient destination model.
 *
 * @param p0 the model
 * @param p1 the model count
 * @param p2 the model size
 * @param p3 the model abstraction
 * @param p4 the model abstraction count
 */
void destroy_model(void** model, void* model_count, void* model_size, void* model_abstr, void* model_abstr_count) {

    // The comparison result.
    int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

    // Check for compound (later better for primitive!!) model.
    check_compound_model((void*) &r, model_abstr, model_abstr_count);

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        destroy_primitive_model(model, model_count, model_size, model_abstr, model_abstr_count);

    } else {

        destroy_compound_model(model, model_count, model_size, model_abstr, model_abstr_count);
    }
}

/**
 * Destroys a part and removes it from the knowledge model.
 *
 * Primitive models need a different creation than compound models.
 *
 * persistent:
 * - stored permanently
 * - outside CYBOI
 * - longer than CYBOI lives
 *
 * transient:
 * - stored in computer memory (RAM)
 * - only accessible from within CYBOI
 * - created and destroyed by CYBOI
 * - not available anymore after CYBOI has been destroyed
 *
 * Expected parameters:
 * - model (required): the knowledge model to be destroyed
 *
 * @param p0 the parameters
 * @param p1 the parameters count
 * @param p2 the knowledge
 * @param p3 the knowledge count
 * @param p4 the knowledge size
 */
void memorise_destructing(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Destroy knowledge model.");

    // The knowledge model name name, abstraction, model, details.
    void** nn = NULL_POINTER_MEMORY_MODEL;
    void** nnc = NULL_POINTER_MEMORY_MODEL;
    void** nns = NULL_POINTER_MEMORY_MODEL;
    void** na = NULL_POINTER_MEMORY_MODEL;
    void** nac = NULL_POINTER_MEMORY_MODEL;
    void** nas = NULL_POINTER_MEMORY_MODEL;
    void** nm = NULL_POINTER_MEMORY_MODEL;
    void** nmc = NULL_POINTER_MEMORY_MODEL;
    void** nms = NULL_POINTER_MEMORY_MODEL;
    void** nd = NULL_POINTER_MEMORY_MODEL;
    void** ndc = NULL_POINTER_MEMORY_MODEL;
    void** nds = NULL_POINTER_MEMORY_MODEL;

    // Get knowledge model name.
    get_universal_compound_element_by_name(
        (void*) &nn, (void*) &nnc, (void*) &nns,
        (void*) &na, (void*) &nac, (void*) &nas,
        (void*) &nm, (void*) &nmc, (void*) &nms,
        (void*) &nd, (void*) &ndc, (void*) &nds,
        p0, p1,
        (void*) MODEL_DESTROY_MEMORY_OPERATION_CYBOL_NAME, (void*) MODEL_DESTROY_MEMORY_OPERATION_CYBOL_NAME_COUNT,
        p2, p3);

    // The knowledge model name, abstraction, model, details.
    void** en = NULL_POINTER_MEMORY_MODEL;
    void** enc = NULL_POINTER_MEMORY_MODEL;
    void** ens = NULL_POINTER_MEMORY_MODEL;
    void** ea = NULL_POINTER_MEMORY_MODEL;
    void** eac = NULL_POINTER_MEMORY_MODEL;
    void** eas = NULL_POINTER_MEMORY_MODEL;
    void** em = NULL_POINTER_MEMORY_MODEL;
    void** emc = NULL_POINTER_MEMORY_MODEL;
    void** ems = NULL_POINTER_MEMORY_MODEL;
    void** ed = NULL_POINTER_MEMORY_MODEL;
    void** edc = NULL_POINTER_MEMORY_MODEL;
    void** eds = NULL_POINTER_MEMORY_MODEL;

    // Get knowledge model.
    get_universal_compound_element_by_name(
        (void*) &en, (void*) &enc, (void*) &ens,
        (void*) &ea, (void*) &eac, (void*) &eas,
        (void*) &em, (void*) &emc, (void*) &ems,
        (void*) &ed, (void*) &edc, (void*) &eds,
        p2, p3,
        (void*) *nm, (void*) *nmc,
        p2, p3);

    // Destroy knowledge model.
    destroy_model(em, *emc, *ems , *ea, *eac);

    // Remove knowledge model from given whole model.
    remove_compound_element_by_name(p2, p3, p4, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, (void*) *nm, (void*) *nmc);
}

/* DESTRUCTING_MEMORISER_SOURCE */
#endif
