/*
 * $RCSfile: destroy.c,v $
 *
 * Copyright (c) 1999-2008. Christian Heller and the CYBOP developers.
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
 * This file destroys a transient model to a persistent model.
 *
 * @version $Revision: 1.28 $ $Date: 2008-05-04 00:18:09 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef DESTROY_SOURCE
#define DESTROY_SOURCE

#include "../globals/constants/cybol/cybol_abstraction_constants.c"
#include "../globals/constants/cybol/cybol_name_constants.c"
#include "../globals/constants/integer/integer_constants.c"
#include "../globals/constants/log/log_message_constants.c"
#include "../globals/constants/pointer/pointer_constants.c"
#include "../globals/logger/logger.c"
#include "../memoriser/accessor/compound_accessor.c"
#include "../memoriser/array.c"

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

    if (p0 != *NULL_POINTER) {

        int* p = (int*) p0;

        if (*p != *NUMBER_1_INTEGER) {

            compare_arrays(p1, p2, (void*) COMPOUND_ABSTRACTION, (void*) COMPOUND_ABSTRACTION_COUNT, p0, (void*) CHARACTER_ARRAY);
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

    log_terminated_message((void*) DEBUG_LOG_LEVEL, (void*) L"Destroy primitive model.");

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

    int compound_counter = *NUMBER_0_INTEGER;

    // The element name.
    void** en = NULL_POINTER;
    void** enc = NULL_POINTER;
    void** ens = NULL_POINTER;
    // The element abstraction.
    void** ea = NULL_POINTER;
    void** eac = NULL_POINTER;
    void** eas = NULL_POINTER;
    // The element model.
    void** em = NULL_POINTER;
    void** emc = NULL_POINTER;
    void** ems = NULL_POINTER;
    // The element details.
    void** ed = NULL_POINTER;
    void** edc = NULL_POINTER;
    void** eds = NULL_POINTER;

    while (*NUMBER_1_INTEGER) {

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

        compound_counter = compound_counter + *NUMBER_1_INTEGER;
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
    int r = *NUMBER_0_INTEGER;

    // Check for compound (later better for primitive!!) model.
    check_compound_model((void*) &r, model_abstr, model_abstr_count);

    if (r == *NUMBER_0_INTEGER) {

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
void destroy(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_terminated_message((void*) INFORMATION_LOG_LEVEL, (void*) L"Destroy knowledge model.");

    // The knowledge model name name, abstraction, model, details.
    void** nn = NULL_POINTER;
    void** nnc = NULL_POINTER;
    void** nns = NULL_POINTER;
    void** na = NULL_POINTER;
    void** nac = NULL_POINTER;
    void** nas = NULL_POINTER;
    void** nm = NULL_POINTER;
    void** nmc = NULL_POINTER;
    void** nms = NULL_POINTER;
    void** nd = NULL_POINTER;
    void** ndc = NULL_POINTER;
    void** nds = NULL_POINTER;

    // Get knowledge model name.
    get_universal_compound_element_by_name(p0, p1,
        (void*) DESTROY_MODEL_NAME, (void*) DESTROY_MODEL_NAME_COUNT,
        (void*) &nn, (void*) &nnc, (void*) &nns,
        (void*) &na, (void*) &nac, (void*) &nas,
        (void*) &nm, (void*) &nmc, (void*) &nms,
        (void*) &nd, (void*) &ndc, (void*) &nds,
        p2, p3);

    // The knowledge model name, abstraction, model, details.
    void** en = NULL_POINTER;
    void** enc = NULL_POINTER;
    void** ens = NULL_POINTER;
    void** ea = NULL_POINTER;
    void** eac = NULL_POINTER;
    void** eas = NULL_POINTER;
    void** em = NULL_POINTER;
    void** emc = NULL_POINTER;
    void** ems = NULL_POINTER;
    void** ed = NULL_POINTER;
    void** edc = NULL_POINTER;
    void** eds = NULL_POINTER;

    // Get knowledge model.
    get_universal_compound_element_by_name(p2, p3,
        (void*) *nm, (void*) *nmc,
        (void*) &en, (void*) &enc, (void*) &ens,
        (void*) &ea, (void*) &eac, (void*) &eas,
        (void*) &em, (void*) &emc, (void*) &ems,
        (void*) &ed, (void*) &edc, (void*) &eds,
        p2, p3);

    // Destroy knowledge model.
    destroy_model(em, *emc, *ems , *ea, *eac);

    // Remove knowledge model from given whole model.
    remove_compound_element_by_name(p2, p3, p4, *NULL_POINTER, *NULL_POINTER, *NULL_POINTER, (void*) *nm, (void*) *nmc);
}

/* DESTROY_SOURCE */
#endif
