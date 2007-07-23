/*
 * $RCSfile: create.c,v $
 *
 * Copyright (c) 1999-2007. Christian Heller and the CYBOP developers.
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
 * This file creates a transient model from a persistent model.
 *
 * @version $Revision: 1.32 $ $Date: 2007-07-23 23:47:57 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CREATE_SOURCE
#define CREATE_SOURCE

#include <libxml/tree.h>
#include "../globals/constants/cybol/cybol_abstraction_constants.c"
#include "../globals/constants/cybol/cybol_channel_constants.c"
#include "../globals/constants/cybol/cybol_name_constants.c"
#include "../globals/constants/integer/integer_constants.c"
#include "../globals/constants/log/log_message_constants.c"
#include "../globals/constants/pointer/pointer_constants.c"
#include "../globals/logger/logger.c"
#include "../memoriser/accessor/compound_accessor.c"
#include "../memoriser/array.c"
#include "../memoriser/communicator.c"
#include "../memoriser/converter/compound_converter.c"
#include "../memoriser/converter.c"
#include "../memoriser/allocator.c"

/**
 * Creates a knowledge model and adds it to the given whole element,
 * or to the knowledge memory root directly, if no whole element is given.
 *
 * Parameters:
 * - name (required)
 * - abstraction (required)
 * - element (required, may be "part" or "meta")
 * - whole (required, if empty the model will be added to the knowledge root)
 *
 * @param p0 the parameters
 * @param p1 the parameters count
 * @param p2 the knowledge memory
 * @param p3 the knowledge memory count
 * @param p4 the knowledge memory size
 */
void create(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message_debug("Information: Create knowledge model.");

    // The name name, abstraction, model, details.
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
    // The abstraction name, abstraction, model, details.
    void** an = NULL_POINTER;
    void** anc = NULL_POINTER;
    void** ans = NULL_POINTER;
    void** aa = NULL_POINTER;
    void** aac = NULL_POINTER;
    void** aas = NULL_POINTER;
    void** am = NULL_POINTER;
    void** amc = NULL_POINTER;
    void** ams = NULL_POINTER;
    void** ad = NULL_POINTER;
    void** adc = NULL_POINTER;
    void** ads = NULL_POINTER;
    // The element name, abstraction, model, details.
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
    // The whole name, abstraction, model, details.
    void** wn = NULL_POINTER;
    void** wnc = NULL_POINTER;
    void** wns = NULL_POINTER;
    void** wa = NULL_POINTER;
    void** wac = NULL_POINTER;
    void** was = NULL_POINTER;
    void** wm = NULL_POINTER;
    void** wmc = NULL_POINTER;
    void** wms = NULL_POINTER;
    void** wd = NULL_POINTER;
    void** wdc = NULL_POINTER;
    void** wds = NULL_POINTER;

    // Get name.
    get_universal_compound_element_by_name(p0, p1,
        (void*) CREATE_NAME_NAME, (void*) CREATE_NAME_NAME_COUNT,
        (void*) &nn, (void*) &nnc, (void*) &nns,
        (void*) &na, (void*) &nac, (void*) &nas,
        (void*) &nm, (void*) &nmc, (void*) &nms,
        (void*) &nd, (void*) &ndc, (void*) &nds,
        p2, p3);

    // Get abstraction.
    get_universal_compound_element_by_name(p0, p1,
        (void*) CREATE_ABSTRACTION_NAME, (void*) CREATE_ABSTRACTION_NAME_COUNT,
        (void*) &an, (void*) &anc, (void*) &ans,
        (void*) &aa, (void*) &aac, (void*) &aas,
        (void*) &am, (void*) &amc, (void*) &ams,
        (void*) &ad, (void*) &adc, (void*) &ads,
        p2, p3);

    // Get element.
    get_universal_compound_element_by_name(p0, p1,
        (void*) CREATE_ELEMENT_NAME, (void*) CREATE_ELEMENT_NAME_COUNT,
        (void*) &en, (void*) &enc, (void*) &ens,
        (void*) &ea, (void*) &eac, (void*) &eas,
        (void*) &em, (void*) &emc, (void*) &ems,
        (void*) &ed, (void*) &edc, (void*) &eds,
        p2, p3);

    // Get whole.
    get_universal_compound_element_by_name(p0, p1,
        (void*) CREATE_WHOLE_NAME, (void*) CREATE_WHOLE_NAME_COUNT,
        (void*) &wn, (void*) &wnc, (void*) &wns,
        (void*) &wa, (void*) &wac, (void*) &was,
        (void*) &wm, (void*) &wmc, (void*) &wms,
        (void*) &wd, (void*) &wdc, (void*) &wds,
        p2, p3);

    // The knowledge model name, abstraction, model, details.
    void* kmn = *NULL_POINTER;
    int* kmnc = (int*) *NULL_POINTER;
    int* kmns = (int*) *NULL_POINTER;
    void* kma = *NULL_POINTER;
    int* kmac = (int*) *NULL_POINTER;
    int* kmas = (int*) *NULL_POINTER;
    void* kmm = *NULL_POINTER;
    int* kmmc = (int*) *NULL_POINTER;
    int* kmms = (int*) *NULL_POINTER;
    void* kmd = *NULL_POINTER;
    int* kmdc = (int*) *NULL_POINTER;
    int* kmds = (int*) *NULL_POINTER;

    //
    // Name.
    //

    // Allocate knowledge model name.
    allocate((void*) &kmnc, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
    *kmnc = *NUMBER_0_INTEGER;
    allocate((void*) &kmns, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
    *kmns = *NUMBER_0_INTEGER;
    allocate((void*) &kmn, (void*) kmns, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT);
    // Parse knowledge model name.
    // CAUTION! The abstraction always HAS TO BE "character".
    parse((void*) &kmn, (void*) kmnc, (void*) kmns, *NULL_POINTER, *NULL_POINTER, *NULL_POINTER, *nm, *nmc, *na, *nac);

    //
    // Channel.
    //
    // CAUTION! A (transient) knowledge model channel is not created,
    // since that is only needed temporarily for model loading.
    //

    // Allocate knowledge model abstraction.
    allocate((void*) &kmac, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
    *kmac = *NUMBER_0_INTEGER;
    allocate((void*) &kmas, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
    *kmas = *NUMBER_0_INTEGER;
    allocate((void*) &kma, (void*) kmas, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT);
    // Parse knowledge model abstraction.
    // CAUTION! The abstraction always HAS TO BE "character".
    parse((void*) &kma, (void*) kmac, (void*) kmas, *NULL_POINTER, *NULL_POINTER, *NULL_POINTER, *am, *amc, *aa, *aac);

    // Allocate knowledge model model.
    allocate((void*) &kmmc, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
    *kmmc = *NUMBER_0_INTEGER;
    allocate((void*) &kmms, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
    *kmms = *NUMBER_0_INTEGER;
    allocate((void*) &kmm, (void*) kmms, *am, *amc);
    // CAUTION! Do NOT parse knowledge model model here!
    // This function's purpose is only to allocate an empty knowledge model.
    // The knowledge model may get filled with data in the "parse" operation,
    // which is called when a "receive" logic operation is found in cybol.

    // Allocate knowledge model details.
    allocate((void*) &kmdc, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
    *kmdc = *NUMBER_0_INTEGER;
    allocate((void*) &kmds, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
    *kmds = *NUMBER_0_INTEGER;
    allocate((void*) &kmd, (void*) kmds, COMPOUND_ABSTRACTION, COMPOUND_ABSTRACTION_COUNT);
    // CAUTION! Do NOT parse knowledge model details here!
    // This function's purpose is only to allocate an empty knowledge model.
    // The knowledge details are left empty.

    // The comparison result.
    int r = *NUMBER_0_INTEGER;

    if (r == *NUMBER_0_INTEGER) {

        compare_arrays(*em, *emc, (void*) CREATE_PART_ELEMENT_MODEL, (void*) CREATE_PART_ELEMENT_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != *NUMBER_0_INTEGER) {

            if (*wm != *NULL_POINTER) {

                log_message_debug("Debug: Add part knowledge model to whole model.");

                // Use the determined whole model, if it exists.
                set_compound_element_by_name(*wm, *wmc, *wms,
                    kmn, (void*) kmnc, (void*) kmns,
                    kma, (void*) kmac, (void*) kmas,
                    kmm, (void*) kmmc, (void*) kmms,
                    kmd, (void*) kmdc, (void*) kmds);

            } else {

                log_message_debug("Debug: Add part knowledge model to knowledge memory root.");

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
                set_compound_element_by_name(p2, p3, p4,
                    kmn, (void*) kmnc, (void*) kmns,
                    kma, (void*) kmac, (void*) kmas,
                    kmm, (void*) kmmc, (void*) kmms,
                    kmd, (void*) kmdc, (void*) kmds);
            }
        }
    }

    if (r == *NUMBER_0_INTEGER) {

        compare_arrays(*em, *emc, (void*) CREATE_META_ELEMENT_MODEL, (void*) CREATE_META_ELEMENT_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != *NUMBER_0_INTEGER) {

/*??
            if (*wd != *NULL_POINTER) {
*/

                log_message_debug("Debug: Add meta knowledge model to whole details.");

                // Use the determined whole model, if it exists.
                set_compound_element_by_name(*wd, *wdc, *wds,
                    kmn, (void*) kmnc, (void*) kmns,
                    kma, (void*) kmac, (void*) kmas,
                    kmm, (void*) kmmc, (void*) kmms,
                    kmd, (void*) kmdc, (void*) kmds);

/*??
            } else {

                log_message_debug("Error: Could not add meta knowledge model to whole details. The whole details is null.");
            }
*/
        }
    }
}

/* CREATE_SOURCE */
#endif
