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
 * @version $Revision: 1.29 $ $Date: 2007-05-09 15:32:40 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CREATE_SOURCE
#define CREATE_SOURCE

#include <libxml/tree.h>
#include "../globals/constants/cybol/cybol_abstraction_constants.c"
#include "../globals/constants/cybol/cybol_channel_constants.c"
#include "../globals/constants/log_message/log_message_constants.c"
#include "../globals/constants/cybol/cybol_name_constants.c"
#include "../globals/logger/logger.c"
#include "../memoriser/accessor/compound_accessor.c"
#include "../memoriser/array.c"
#include "../memoriser/communicator.c"
#include "../memoriser/converter.c"
#include "../memoriser/allocator.c"
#include "../memoriser/translator.c"

/**
 * Creates a primitive model.
 *
 * The creation happens in 2 steps and 3 models are involved.
 *
 * 1 source code: persistent, probably stored in files, for example cybol/xml
 * 2 receive model: transient byte/character stream, as read from channel/location
 * 3 parse model: transient model that cyboi works with, that is cyboi internal model
 *
 * The "received model" and "parsed model" are temporary helper models;
 * they get created and destroyed during creation handling.
 *
 *                read                              parse
 * source code  ----------> received/read model  ----------> parsed model
 * (persistent)             (transient)                      (transient)
 *
 * The counterparts of the creation procedures are:
 * - read <--> write
 * - parse <--> serialise
 *
 * @param p0 the destination (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source model
 * @param p4 the source model count
 * @param p5 the source abstraction
 * @param p6 the source abstraction count
 * @param p7 the source channel
 * @param p8 the source channel count
 */
void create_primitive_model(void* p0, void* p1, void* p2, void* p3, void* p4,
    void* p5, void* p6, void* p7, void* p8) {

    log_message_debug("Create primitive model.");

    //
    // Receive.
    //

    // The receive model.
    void* rm = NULL_POINTER;
    int rmc = 0;
    int rms = 0;

    // Create receive model of type character, to read single bytes.
    allocate((void*) &rm, (void*) &rms, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT);

    // Reads persistent byte stream over channel.
    read_data((void*) &rm, (void*) &rmc, (void*) &rms, p3, p4, p7, p8);

    //
    // Parse.
    //

    // Create parse model of type given as abstraction.
    allocate(p0, p2, p5, p6);

    // Parse byte stream according to given document type.
    parse(p0, p1, p2, NULL_POINTER, NULL_POINTER, NULL_POINTER, rm, (void*) &rmc, p5, p6);

    // Destroy receive model.
    deallocate((void*) &rm, (void*) &rms, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT);
}

/**
 * Creates a compound model.
 *
 * The creation happens in 3 steps and 4 models are involved.
 *
 * 1 source code: persistent, probably stored in files, for example cybol/xml
 * 2 receive model: transient byte/character stream, as read from channel/location
 * 3 parse model: transient model representing the structure of the parsed document,
 *   for example xml dom tree
 * 4 decode model: transient model that cyboi works with, that is cyboi internal model
 *
 * The "received model" and "parsed model" are temporary helper models;
 * they get created and destroyed during creation handling.
 *
 *                read                              parse                   decode
 * source code  ----------> received/read model  ----------> parsed model ----------> decoded model
 * (persistent)             (transient)                      (transient)              (transient)
 *
 * The counterparts of the creation procedures are:
 * - read <--> write
 * - parse <--> serialise
 * - decode <--> encode
 *
 * @param p0 the destination (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source model
 * @param p4 the source model count
 * @param p5 the source abstraction
 * @param p6 the source abstraction count
 * @param p7 the source channel
 * @param p8 the source channel count
 */
void create_compound_model(void* p0, void* p1, void* p2, void* p3, void* p4,
    void* p5, void* p6, void* p7, void* p8) {

    log_message_debug("Create compound model.");

    //?The temporary workaround flag to use the libxml2 parser.
    //?? Later, when an own xml parser is implemented in cyboi,
    //?? delete this flag and change the corresponding blocks below!
    int w = 1;

    //
    // Receive.
    //

    // The receive model.
    void* rm = NULL_POINTER;
    int rmc = 0;
    int rms = 0;

    // Create receive model of type character, to read single bytes.
    allocate((void*) &rm, (void*) &rms, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT);

    // Read persistent byte stream over channel.
    read_data((void*) &rm, (void*) &rmc, (void*) &rms, p3, p4, p7, p8);

    //
    // Parse.
    //

    // The parse model.
    void* pm = NULL_POINTER;
    int pmc = 0;
    int pms = 0;

    if (w == 0) {

        // Create parse model of type given as abstraction.
        allocate((void*) &pm, (void*) &pms, p5, p6);

        // Parse byte stream according to given document type.
        parse((void*) &pm, (void*) &pmc, (void*) &pms, NULL_POINTER, NULL_POINTER, NULL_POINTER, rm, (void*) &rmc, p5, p6);

    } else {

        parse((void*) &pm, (void*) &pmc, (void*) &pms, NULL_POINTER, NULL_POINTER, NULL_POINTER, p3, p4, p5, p6);
    }

    // Destroy receive model.
    deallocate((void*) &rm, (void*) &rms, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT);

    //
    // Decode.
    //

    // Create compound decode model.
    allocate(p0, p2, (void*) COMPOUND_ABSTRACTION, (void*) COMPOUND_ABSTRACTION_COUNT);

    // Decode document model according to given document type.
    decode(p0, p1, p2, pm, (void*) &pmc, p5, p6);

    if (w == 0) {

        // Destroy parse model.
        deallocate((void*) &pm, (void*) &pms, p5, p6);

    } else {

        if (pm != NULL_POINTER) {

            // Free xml dom document.
            xmlFreeDoc((xmlDoc*) *((void**) pm));

        } else {

            log_message_debug("Could not free parse model (xml document). Probably, the given cybol file name was empty.");
        }
    }
}

/**
 * Creates a transient destination model from a persistent source model.
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
 * @param p0 the destination (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source model
 * @param p4 the source model count
 * @param p5 the source abstraction
 * @param p6 the source abstraction count
 * @param p7 the source channel
 * @param p8 the source channel count
 */
void create_model(void* p0, void* p1, void* p2, void* p3, void* p4,
    void* p5, void* p6, void* p7, void* p8) {

    log_message_debug("Create.");

    // The comparison result.
    int r = *NUMBER_0_INTEGER;

    compare_arrays(p5, p6, (void*) COMPOUND_ABSTRACTION, (void*) COMPOUND_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

    if (r != *NUMBER_0_INTEGER) {

        create_compound_model(p0, p1, p2, p3, p4, p5, p6, p7, p8);

    } else {

        create_primitive_model(p0, p1, p2, p3, p4, p5, p6, p7, p8);
    }
}

/**
 * Creates a knowledge model and adds it to the given whole element,
 * or to the knowledge memory root directly, if no whole element is given.
 *
 * Expected parameters:
 * - name
 * - abstraction
 * - element (may be "part" or "meta")
 * - whole
 *
 * @param p0 the parameters
 * @param p1 the parameters count
 * @param p2 the knowledge memory
 * @param p3 the knowledge memory count
 * @param p4 the knowledge memory size
 */
void create(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message_debug("Create knowledge model.");

    // The name name, abstraction, model, details.
    void** nn = &NULL_POINTER;
    void** nnc = &NULL_POINTER;
    void** nns = &NULL_POINTER;
    void** na = &NULL_POINTER;
    void** nac = &NULL_POINTER;
    void** nas = &NULL_POINTER;
    void** nm = &NULL_POINTER;
    void** nmc = &NULL_POINTER;
    void** nms = &NULL_POINTER;
    void** nd = &NULL_POINTER;
    void** ndc = &NULL_POINTER;
    void** nds = &NULL_POINTER;
    // The abstraction name, abstraction, model, details.
    void** an = &NULL_POINTER;
    void** anc = &NULL_POINTER;
    void** ans = &NULL_POINTER;
    void** aa = &NULL_POINTER;
    void** aac = &NULL_POINTER;
    void** aas = &NULL_POINTER;
    void** am = &NULL_POINTER;
    void** amc = &NULL_POINTER;
    void** ams = &NULL_POINTER;
    void** ad = &NULL_POINTER;
    void** adc = &NULL_POINTER;
    void** ads = &NULL_POINTER;
    // The element name, abstraction, model, details.
    void** en = &NULL_POINTER;
    void** enc = &NULL_POINTER;
    void** ens = &NULL_POINTER;
    void** ea = &NULL_POINTER;
    void** eac = &NULL_POINTER;
    void** eas = &NULL_POINTER;
    void** em = &NULL_POINTER;
    void** emc = &NULL_POINTER;
    void** ems = &NULL_POINTER;
    void** ed = &NULL_POINTER;
    void** edc = &NULL_POINTER;
    void** eds = &NULL_POINTER;
    // The whole name, abstraction, model, details.
    void** wn = &NULL_POINTER;
    void** wnc = &NULL_POINTER;
    void** wns = &NULL_POINTER;
    void** wa = &NULL_POINTER;
    void** wac = &NULL_POINTER;
    void** was = &NULL_POINTER;
    void** wm = &NULL_POINTER;
    void** wmc = &NULL_POINTER;
    void** wms = &NULL_POINTER;
    void** wd = &NULL_POINTER;
    void** wdc = &NULL_POINTER;
    void** wds = &NULL_POINTER;

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

    // The knowledge model name.
    void* kmn = NULL_POINTER;
    int* kmnc = NULL_POINTER;
    int* kmns = NULL_POINTER;
    // The knowledge model abstraction.
    void* kma = NULL_POINTER;
    int* kmac = NULL_POINTER;
    int* kmas = NULL_POINTER;
    // The knowledge model model.
    void* kmm = NULL_POINTER;
    int* kmmc = NULL_POINTER;
    int* kmms = NULL_POINTER;
    // The knowledge model details.
    void* kmd = NULL_POINTER;
    int* kmdc = NULL_POINTER;
    int* kmds = NULL_POINTER;

    // Create knowledge model name.
    allocate((void*) &kmnc, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
    *kmnc = 0;
    allocate((void*) &kmns, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
    *kmns = 0;
    create_model((void*) &kmn, (void*) kmnc, (void*) kmns, *nm, *nmc, *na, *nac, (void*) INLINE_CHANNEL, (void*) INLINE_CHANNEL_COUNT);

    // A knowledge model channel is not created,
    // since that is only needed temporarily for model loading.

    // Create knowledge model abstraction.
    allocate((void*) &kmac, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
    *kmac = 0;
    allocate((void*) &kmas, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
    *kmas = 0;
    create_model((void*) &kma, (void*) kmac, (void*) kmas, *am, *amc, *aa, *aac, (void*) INLINE_CHANNEL, (void*) INLINE_CHANNEL_COUNT);

    // Create knowledge model model.
    allocate((void*) &kmmc, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
    *kmmc = 0;
    allocate((void*) &kmms, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
    *kmms = 0;
    create_model((void*) &kmm, (void*) kmmc, (void*) kmms, EMPTY_MODEL, EMPTY_MODEL_COUNT, *am, *amc, INLINE_CHANNEL, INLINE_CHANNEL_COUNT);

    // Create knowledge model details.
    allocate((void*) &kmdc, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
    *kmdc = 0;
    allocate((void*) &kmds, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
    *kmds = 0;
    create_model((void*) &kmd, (void*) kmdc, (void*) kmds, EMPTY_MODEL, EMPTY_MODEL_COUNT, COMPOUND_ABSTRACTION, COMPOUND_ABSTRACTION_COUNT, INLINE_CHANNEL, INLINE_CHANNEL_COUNT);

    // The comparison result.
    int r = *NUMBER_0_INTEGER;

    if (r == *NUMBER_0_INTEGER) {

        compare_arrays(*em, *emc, (void*) CREATE_PART_ELEMENT_MODEL, (void*) CREATE_PART_ELEMENT_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != *NUMBER_0_INTEGER) {

            if (*wm != NULL_POINTER) {

                log_message_debug("Add part knowledge model to whole model.");

                // Use the determined whole model, if it exists.
                set_compound_element_by_name(*wm, *wmc, *wms,
                    kmn, (void*) kmnc, (void*) kmns,
                    kma, (void*) kmac, (void*) kmas,
                    kmm, (void*) kmmc, (void*) kmms,
                    kmd, (void*) kmdc, (void*) kmds);

            } else {

                log_message_debug("Add part knowledge model to knowledge memory root.");

                // Use the knowledge memory root if the determined whole model is null.
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

            if (*wd != NULL_POINTER) {

                log_message_debug("Add meta knowledge model to whole details.");

                // Use the determined whole model, if it exists.
                set_compound_element_by_name(*wd, *wdc, *wds,
                    kmn, (void*) kmnc, (void*) kmns,
                    kma, (void*) kmac, (void*) kmas,
                    kmm, (void*) kmmc, (void*) kmms,
                    kmd, (void*) kmdc, (void*) kmds);

            } else {

                log_message_debug("Could not add meta knowledge model to whole details. The whole details is null.");
            }
        }
    }
}

/* CREATE_SOURCE */
#endif
