/*
 * Copyright (C) 1999-2010. Christian Heller.
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
 * @version $RCSfile: creating_memoriser.c,v $ $Revision: 1.13 $ $Date: 2009-10-06 21:25:26 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CREATING_MEMORISER_SOURCE
#define CREATING_MEMORISER_SOURCE

#include "../../constant/abstraction/cybol/text_cybol_abstraction.c"
#include "../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../constant/channel/cybol_channel.c"
#include "../../constant/model/cybol/compound_element_cybol_model.c"
#include "../../constant/model/log/message_log_model.c"
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../constant/name/cybol/operation/memory/create_memory_operation_cybol_name.c"
#include "../../executor/accessor/getter/compound_getter.c"
#include "../../executor/communicator/receiver.c"
#include "../../executor/comparator/array_equality_comparator.c"
#include "../../executor/converter/decoder.c"
#include "../../executor/memoriser/allocator.c"
#include "../../logger/logger.c"

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

    // Allocate part.
    allocate_part((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
        (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
        (void*) NUMBER_0_INTEGER_MEMORY_MODEL, p9, p10);

/*??
    fwprintf(stdout, L"TEST creating pre na: %ls\n", (wchar_t*) p3);
    fwprintf(stdout, L"TEST creating pre nac: %i\n", *((int*) p4));
    fwprintf(stdout, L"TEST creating pre nm: %ls\n", (wchar_t*) p5);
    fwprintf(stdout, L"TEST creating pre nmc: %i\n", *((int*) p6));
*/
    // Copy part name.
    // CAUTION! The abstraction arriving here has already been converted
    // from a cybol- to a cyboi abstraction, e.g. "text/plain" into "wide_character".
    // Therefore, decoding is not needed here.
    set((void*) &n, nc, ns, p5, p6, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, p3, p4);
/*??
    fwprintf(stdout, L"TEST creating post nm: %ls\n", (wchar_t*) n);
    fwprintf(stdout, L"TEST creating post nmc: %i\n", nc);
*/

/*??
    fwprintf(stdout, L"TEST creating pre aa: %ls\n", (wchar_t*) p7);
    fwprintf(stdout, L"TEST creating pre aac: %i\n", *((int*) p8));
    fwprintf(stdout, L"TEST creating pre am: %ls\n", (wchar_t*) p9);
    fwprintf(stdout, L"TEST creating pre amc: %i\n", *((int*) p10));
*/
    // Copy part abstraction.
    // CAUTION! The abstraction arriving here has already been converted
    // from a cybol- to a cyboi abstraction, e.g. "text/plain" into "wide_character".
    // Therefore, decoding is not needed here.
    set((void*) &a, ac, as, p9, p10, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, p7, p8);
/*??
    fwprintf(stdout, L"TEST creating post am: %ls\n", (wchar_t*) a);
    fwprintf(stdout, L"TEST creating post amc: %i\n", ac);
*/

    //
    // CAUTION! Do NOT consider part model here!
    // This function's purpose is only to allocate an empty part.
    // The part model may get filled with data in the "decode" operation,
    // which is called when a "receive" logic operation is found in cybol.
    //
    // CAUTION! Do NOT consider part details here!
    // This function's purpose is only to allocate an empty part.
    // The part details are left empty.
    //

    // Add part to whole model.
    // CAUTION! Hand over name as reference.
    append_compound_element_by_name(p0, p1, p2, (void*) &n, nc, ns, a, ac, as, m, mc, ms, d, dc, ds);
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
    get_universal_compound_element_by_name(
        (void*) &nn, (void*) &nnc, (void*) &nns,
        (void*) &na, (void*) &nac, (void*) &nas,
        (void*) &nm, (void*) &nmc, (void*) &nms,
        (void*) &nd, (void*) &ndc, (void*) &nds,
        p0, p1,
        (void*) NAME_CREATE_MEMORY_OPERATION_CYBOL_NAME, (void*) NAME_CREATE_MEMORY_OPERATION_CYBOL_NAME_COUNT,
        p2, p3);
    // Get abstraction.
    get_universal_compound_element_by_name(
        (void*) &an, (void*) &anc, (void*) &ans,
        (void*) &aa, (void*) &aac, (void*) &aas,
        (void*) &am, (void*) &amc, (void*) &ams,
        (void*) &ad, (void*) &adc, (void*) &ads,
        p0, p1,
        (void*) ABSTRACTION_CREATE_MEMORY_OPERATION_CYBOL_NAME, (void*) ABSTRACTION_CREATE_MEMORY_OPERATION_CYBOL_NAME_COUNT,
        p2, p3);
    // Get element.
    get_universal_compound_element_by_name(
        (void*) &en, (void*) &enc, (void*) &ens,
        (void*) &ea, (void*) &eac, (void*) &eas,
        (void*) &em, (void*) &emc, (void*) &ems,
        (void*) &ed, (void*) &edc, (void*) &eds,
        p0, p1,
        (void*) ELEMENT_CREATE_MEMORY_OPERATION_CYBOL_NAME, (void*) ELEMENT_CREATE_MEMORY_OPERATION_CYBOL_NAME_COUNT,
        p2, p3);
    // Get whole.
    get_universal_compound_element_by_name(
        (void*) &wn, (void*) &wnc, (void*) &wns,
        (void*) &wa, (void*) &wac, (void*) &was,
        (void*) &wm, (void*) &wmc, (void*) &wms,
        (void*) &wd, (void*) &wdc, (void*) &wds,
        p0, p1,
        (void*) WHOLE_CREATE_MEMORY_OPERATION_CYBOL_NAME, (void*) WHOLE_CREATE_MEMORY_OPERATION_CYBOL_NAME_COUNT,
        p2, p3);

/*??
    fwprintf(stdout, L"TEST creating param count: %i\n", *((int*) p1));

    fwprintf(stdout, L"TEST creating wac: %i\n", *wac);
    fwprintf(stdout, L"TEST creating wa: %ls\n", (wchar_t*) *wa);
    fwprintf(stdout, L"TEST creating wmc: %i\n", *wmc);
    fwprintf(stdout, L"TEST creating wm: %ls\n", (wchar_t*) *wm);
*/

    // The comparison result.
    int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_arrays((void*) &r, *em, *emc, (void*) PART_COMPOUND_ELEMENT_CYBOL_MODEL, (void*) PART_COMPOUND_ELEMENT_CYBOL_MODEL_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

//??    fwprintf(stdout, L"TEST creating part r: %i\n", r);

            if (*wm != *NULL_POINTER_MEMORY_MODEL) {

//??    fwprintf(stdout, L"TEST creating part whole r: %i\n", r);

                log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Add part knowledge model to whole model.");

                // Use the determined whole model, if it exists.
                create_set(*wm, *wmc, *wms, *na, *nac, *nm, *nmc, *aa, *aac, *am, *amc);

            } else {

//??    fwprintf(stdout, L"TEST creating part root r: %i\n", r);

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

        compare_equal_arrays((void*) &r, *em, *emc, (void*) META_COMPOUND_ELEMENT_CYBOL_MODEL, (void*) META_COMPOUND_ELEMENT_CYBOL_MODEL_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

//??    fwprintf(stdout, L"TEST creating meta r: %i\n", r);

            log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Add meta knowledge model to whole details.");

            create_set(*wd, *wdc, *wds, *na, *nac, *nm, *nmc, *aa, *aac, *am, *amc);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

//??    fwprintf(stdout, L"TEST creating empty r: %i\n", r);

        log_terminated_message((void*) WARNING_LEVEL_LOG_MODEL, (void*) L"Could not create knowledge model. The element model is unknown.");
    }

/*??
//?? TEST BEGIN
    // The model diagram.
    void* md = *NULL_POINTER_MEMORY_MODEL;
    int mdc = *NUMBER_0_INTEGER_MEMORY_MODEL;
    int mds = *NUMBER_0_INTEGER_MEMORY_MODEL;
    // Allocate model diagram.
    allocate((void*) &md, (void*) &mds, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT);
    // Encode model into model diagram.
    encode_model_diagram((void*) &md, (void*) &mdc, (void*) &mds,
        *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, (void*) COMPOUND_MEMORY_ABSTRACTION, (void*) COMPOUND_MEMORY_ABSTRACTION_COUNT,
        p2, p3, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL);
    // The multibyte character stream.
    void* mb = *NULL_POINTER_MEMORY_MODEL;
    int mbc = *NUMBER_0_INTEGER_MEMORY_MODEL;
    int mbs = *NUMBER_0_INTEGER_MEMORY_MODEL;
    // Allocate multibyte character stream.
    allocate((void*) &mb, (void*) &mbs, (void*) CHARACTER_MEMORY_ABSTRACTION, (void*) CHARACTER_MEMORY_ABSTRACTION_COUNT);
    // Encode model diagram into multibyte character stream.
    encode_utf_8_unicode_character_vector((void*) &mb, (void*) &mbc, (void*) &mbs, md, (void*) &mdc);
    // The file name.
    void* fn = L"TEST_CREATING_MEMORISER.txt";
    int fnc = *NUMBER_27_INTEGER_MEMORY_MODEL;
    int fns = *NUMBER_28_INTEGER_MEMORY_MODEL;
    // Write multibyte character stream as message to file system.
    send_file((void*) &fn, (void*) &fnc, (void*) &fns, mb, (void*) &mbc);
    // Deallocate model diagram.
    deallocate((void*) &md, (void*) &mds, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT);
    // Deallocate multibyte character stream.
    deallocate((void*) &mb, (void*) &mbs, (void*) CHARACTER_MEMORY_ABSTRACTION, (void*) CHARACTER_MEMORY_ABSTRACTION_COUNT);
//?? TEST END
*/
}

/* CREATING_MEMORISER_SOURCE */
#endif
