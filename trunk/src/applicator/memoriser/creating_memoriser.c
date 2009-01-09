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
 * @version $RCSfile: creating_memoriser.c,v $ $Revision: 1.8 $ $Date: 2009-01-09 00:36:13 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CREATING_MEMORISER_SOURCE
#define CREATING_MEMORISER_SOURCE

#include <libxml/tree.h>
#include "../../constant/abstraction/cybol/text_cybol_abstraction.c"
#include "../../constant/channel/cybol_channel.c"
#include "../../constant/model/cybol/compound_element_cybol_model.c"
#include "../../constant/model/log/message_log_model.c"
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../constant/name/cybol/operation/memory/create_memory_operation_cybol_name.c"
#include "../../logger/logger.c"
#include "../../memoriser/accessor/compound_accessor.c"
#include "../../memoriser/array.c"
#include "../../memoriser/communicator.c"
#include "../../memoriser/converter/cybol_converter.c"
#include "../../memoriser/converter.c"
#include "../../memoriser/allocator.c"

/**
 * Creates a part and adds it to the given compound.
 *
 * @param p0 the compound
 * @param p1 the compound count
 * @param p2 the compound size
 * @param p3 the name abstraction
 * @param p4 the name abstraction count
 * @param p5 the name model
 * @param p6 the name model count
 * @param p7 the abstraction abstraction
 * @param p8 the abstraction abstraction count
 * @param p9 the abstraction model
 * @param p10 the abstraction model count
 */
void create_set(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10) {

    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Create and set part.");

    // The part name.
    void* n = *NULL_POINTER_MEMORY_MODEL;
    void* nc = *NULL_POINTER_MEMORY_MODEL;
    void* ns = *NULL_POINTER_MEMORY_MODEL;
    // The part abstraction.
    void* a = *NULL_POINTER_MEMORY_MODEL;
    void* ac = *NULL_POINTER_MEMORY_MODEL;
    void* as = *NULL_POINTER_MEMORY_MODEL;
    // The part model.
    void* m = *NULL_POINTER_MEMORY_MODEL;
    void* mc = *NULL_POINTER_MEMORY_MODEL;
    void* ms = *NULL_POINTER_MEMORY_MODEL;
    // The part details.
    void* d = *NULL_POINTER_MEMORY_MODEL;
    void* dc = *NULL_POINTER_MEMORY_MODEL;
    void* ds = *NULL_POINTER_MEMORY_MODEL;

    // The temporary runtime abstraction.
    void* ra = *NULL_POINTER_MEMORY_MODEL;
    int rac = *NUMBER_0_INTEGER_MEMORY_MODEL;
    int ras = *NUMBER_0_INTEGER_MEMORY_MODEL;

    // Allocate temporary runtime abstraction.
    allocate_array((void*) &ra, (void*) &ras, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

    // Decode source- into temporary runtime abstraction.
    // A cybol abstraction is NOT equal to the runtime cyboi abstraction.
    // For example, "memory/compound" is converted into just "compound".
    // Therefore, the abstraction has to be converted here.
    decode((void*) &ra, (void*) &rac, (void*) &ras, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, p9, p10, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, (void*) ABSTRACTION_TEXT_CYBOL_ABSTRACTION, (void*) ABSTRACTION_TEXT_CYBOL_ABSTRACTION_COUNT);

    // Allocate part.
    allocate_part((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
        (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
        (void*) NUMBER_0_INTEGER_MEMORY_MODEL, ra, (void*) &rac);

    // Decode part name.
    decode((void*) &n, (void*) nc, (void*) ns, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, p5, p6, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, p3, p4);

    // Decode (in this case just copy) part abstraction.
    // CAUTION! Use the temporary RUNTIME abstraction as source here!
    // CAUTION! Use WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION as abstraction here!
    replace((void*) &a, (void*) ac, (void*) as, p9, p10, p7, p8);

    // Deallocate temporary runtime abstraction.
    deallocate_array((void*) &ra, (void*) &ras, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

    //
    // CAUTION! Do NOT decode part model here!
    // This function's purpose is only to allocate an empty part.
    // The part model may get filled with data in the "decode" operation,
    // which is called when a "receive" logic operation is found in cybol.
    //
    // CAUTION! Do NOT decode part details here!
    // This function's purpose is only to allocate an empty part.
    // The part details are left empty.
    //

    // Use the determined whole model, if it exists.
    set_compound_element_by_name(p0, p1, p2, n, nc, ns, a, ac, as, m, mc, ms, d, dc, ds);
}

/**
 * Creates a part.
 *
 * The new knowledge model gets added to either of:
 * - whole element's part models
 * - knowledge memory's root directly, if no whole element is given
 * - whole element's meta models
 *
 * Expected parameters:
 * - name (required): the name of the knowledge model to be created
 * - abstraction (required): the abstraction (type) of the knowledge model to be created
 * - element (required): the kind of element (knowledge model) to be created (part, meta);
 *   a part element will be added to the model's part hierarchy; a meta element to the model's details hierarchy
 * - compound / whole (optional; if null, the new element will be added to the knowledge memory root):
 *   the compound to which to add to the new part/ meta element
 *
 * @param p0 the parameters
 * @param p1 the parameters count
 * @param p2 the knowledge memory
 * @param p3 the knowledge memory count
 * @param p4 the knowledge memory size
 */
void memorise_creating(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Create knowledge model.");

    // The name name, abstraction, model, details.
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
    // The abstraction name, abstraction, model, details.
    void** an = NULL_POINTER_MEMORY_MODEL;
    void** anc = NULL_POINTER_MEMORY_MODEL;
    void** ans = NULL_POINTER_MEMORY_MODEL;
    void** aa = NULL_POINTER_MEMORY_MODEL;
    void** aac = NULL_POINTER_MEMORY_MODEL;
    void** aas = NULL_POINTER_MEMORY_MODEL;
    void** am = NULL_POINTER_MEMORY_MODEL;
    void** amc = NULL_POINTER_MEMORY_MODEL;
    void** ams = NULL_POINTER_MEMORY_MODEL;
    void** ad = NULL_POINTER_MEMORY_MODEL;
    void** adc = NULL_POINTER_MEMORY_MODEL;
    void** ads = NULL_POINTER_MEMORY_MODEL;
    // The element name, abstraction, model, details.
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
    // The whole name, abstraction, model, details.
    void** wn = NULL_POINTER_MEMORY_MODEL;
    void** wnc = NULL_POINTER_MEMORY_MODEL;
    void** wns = NULL_POINTER_MEMORY_MODEL;
    void** wa = NULL_POINTER_MEMORY_MODEL;
    void** wac = NULL_POINTER_MEMORY_MODEL;
    void** was = NULL_POINTER_MEMORY_MODEL;
    void** wm = NULL_POINTER_MEMORY_MODEL;
    void** wmc = NULL_POINTER_MEMORY_MODEL;
    void** wms = NULL_POINTER_MEMORY_MODEL;
    void** wd = NULL_POINTER_MEMORY_MODEL;
    void** wdc = NULL_POINTER_MEMORY_MODEL;
    void** wds = NULL_POINTER_MEMORY_MODEL;

    // Get name.
    get_universal_compound_element_by_name(p0, p1,
        (void*) NAME_CREATE_MEMORY_OPERATION_CYBOL_NAME, (void*) NAME_CREATE_MEMORY_OPERATION_CYBOL_NAME_COUNT,
        (void*) &nn, (void*) &nnc, (void*) &nns,
        (void*) &na, (void*) &nac, (void*) &nas,
        (void*) &nm, (void*) &nmc, (void*) &nms,
        (void*) &nd, (void*) &ndc, (void*) &nds,
        p2, p3);
    // Get abstraction.
    get_universal_compound_element_by_name(p0, p1,
        (void*) ABSTRACTION_CREATE_MEMORY_OPERATION_CYBOL_NAME, (void*) ABSTRACTION_CREATE_MEMORY_OPERATION_CYBOL_NAME_COUNT,
        (void*) &an, (void*) &anc, (void*) &ans,
        (void*) &aa, (void*) &aac, (void*) &aas,
        (void*) &am, (void*) &amc, (void*) &ams,
        (void*) &ad, (void*) &adc, (void*) &ads,
        p2, p3);
    // Get element.
    get_universal_compound_element_by_name(p0, p1,
        (void*) ELEMENT_CREATE_MEMORY_OPERATION_CYBOL_NAME, (void*) ELEMENT_CREATE_MEMORY_OPERATION_CYBOL_NAME_COUNT,
        (void*) &en, (void*) &enc, (void*) &ens,
        (void*) &ea, (void*) &eac, (void*) &eas,
        (void*) &em, (void*) &emc, (void*) &ems,
        (void*) &ed, (void*) &edc, (void*) &eds,
        p2, p3);
    // Get whole.
    get_universal_compound_element_by_name(p0, p1,
        (void*) WHOLE_CREATE_MEMORY_OPERATION_CYBOL_NAME, (void*) WHOLE_CREATE_MEMORY_OPERATION_CYBOL_NAME_COUNT,
        (void*) &wn, (void*) &wnc, (void*) &wns,
        (void*) &wa, (void*) &wac, (void*) &was,
        (void*) &wm, (void*) &wmc, (void*) &wms,
        (void*) &wd, (void*) &wdc, (void*) &wds,
        p2, p3);

    // The comparison result.
    int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(*em, *emc, (void*) PART_COMPOUND_ELEMENT_CYBOL_MODEL, (void*) PART_COMPOUND_ELEMENT_CYBOL_MODEL_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            if (*wm != *NULL_POINTER_MEMORY_MODEL) {

                log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Add part knowledge model to whole model.");

                // Use the determined whole model, if it exists.
                create_set(*wm, *wmc, *wms, *na, *nac, *nm, *nmc, *aa, *aac, *am, *amc);

            } else {

                log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Add part knowledge model to knowledge memory root.");

                // Use the knowledge memory root if the determined whole model is null.
                //
                // CAUTION! It is NOT possible to use an empty string to identify and return the
                // knowledge memory root as result of the "get_universal_compound_element_by_name" function,
                // since the knowledge memory pointer/ count/ size would have to be handed over as
                // (pointer pointer) reference, in order to be able to assign the REAL pointer and
                // not just the temporary parameter pointer in "get_universal_compound_element_by_name".
                //
                // CAUTION! The new model allocated above HAS TO BE added somewhere in the
                // knowledge tree, so that it can be deallocated properly at system shutdown
                // and is not lost somewhere in Random Access Memory (RAM). So, if the determined
                // whole model is null, the knowledge memory root has to be used instead.
                create_set(p2, p3, p4, *na, *nac, *nm, *nmc, *aa, *aac, *am, *amc);
            }
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(*em, *emc, (void*) META_COMPOUND_ELEMENT_CYBOL_MODEL, (void*) META_COMPOUND_ELEMENT_CYBOL_MODEL_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Add meta knowledge model to whole details.");

            create_set(*wd, *wdc, *wds, *na, *nac, *nm, *nmc, *aa, *aac, *am, *amc);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        log_terminated_message((void*) WARNING_LEVEL_LOG_MODEL, (void*) L"Could not create knowledge model. The element model is unknown.");
    }
}

/* CREATING_MEMORISER_SOURCE */
#endif
