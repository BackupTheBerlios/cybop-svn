/*
 * $RCSfile: receive_file_system.c,v $
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
 * @version $Revision: 1.11 $ $Date: 2007-05-26 21:19:57 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef RECEIVE_FILE_SYSTEM_SOURCE
#define RECEIVE_FILE_SYSTEM_SOURCE

#ifdef LINUX_OPERATING_SYSTEM

#include "../../globals/constants/cybol/cybol_abstraction_constants.c"
#include "../../globals/constants/log/log_message_constants.c"
#include "../../globals/constants/pointer/pointer_constants.c"
#include "../../globals/logger/logger.c"
#include "../../memoriser/accessor/compound_accessor.c"
#include "../../memoriser/allocator.c"
#include "../../memoriser/array.c"
#include "../../memoriser/communicator.c"
#include "../../memoriser/converter.c"
#include "../../memoriser/translator.c"

/**
 * Receives a primitive model from the file system.
 *
 * The reception happens in 2 steps and 3 models are involved.
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
 * The counterparts of the reception procedures are:
 * - read <--> write
 * - parse <--> serialise
 *
 * @param p0 the destination model (Hand over as reference!)
 * @param p1 the destination model count
 * @param p2 the destination model size
 * @param p3 the destination details (Hand over as reference!)
 * @param p4 the destination details count
 * @param p5 the destination details size
 * @param p6 the source model
 * @param p7 the source model count
 * @param p8 the source abstraction
 * @param p9 the source abstraction count
 * @param p10 the source channel
 * @param p11 the source channel count
 */
void receive_file_system_primitive_model(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5,
    void* p6, void* p7, void* p8, void* p9, void* p10, void* p11) {

    log_message_debug("Receive file system primitive model.");

    //
    // Receive.
    //

    // The receive model.
    void* rm = *NULL_POINTER;
    int rmc = *NUMBER_0_INTEGER;
    int rms = *NUMBER_0_INTEGER;

    // Allocate receive model of type character, to read single bytes.
    allocate((void*) &rm, (void*) &rms, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT);

    // Reads persistent byte stream over channel.
    read_data((void*) &rm, (void*) &rmc, (void*) &rms, p6, p7, p10, p11);

    //
    // Parse.
    //

    //?? --- START of temporary workaround. ---
    int test = 0;
    compare_arrays(p8, p9, (void*) XDT_ABSTRACTION, (void*) XDT_ABSTRACTION_COUNT, (void*) &test, (void*) CHARACTER_ARRAY);
    if (test != 0) {
        allocate(p0, p2, (void*) COMPOUND_ABSTRACTION, (void*) COMPOUND_ABSTRACTION_COUNT);
    } else {
    //?? --- END of temporary workaround. ---

    // Allocate parse model of type given as abstraction.
    allocate(p0, p2, p8, p9);
    }
    // Allocate parse details, which are always of type "compound".
    allocate(p3, p5, (void*) COMPOUND_ABSTRACTION, (void*) COMPOUND_ABSTRACTION_COUNT);

    // Parse byte stream according to given document type.
    parse(p0, p1, p2, p3, p4, p5, rm, (void*) &rmc, p8, p9);

    // Deallocate receive model.
    deallocate((void*) &rm, (void*) &rms, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT);
}

/**
 * Receives a compound model from the file system.
 *
 * The reception happens in 3 steps and 4 models are involved.
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
 * The counterparts of the reception procedures are:
 * - read <--> write
 * - parse <--> serialise
 * - decode <--> encode
 *
 * @param p0 the destination model (Hand over as reference!)
 * @param p1 the destination model count
 * @param p2 the destination model size
 * @param p3 the destination details (Hand over as reference!)
 * @param p4 the destination details count
 * @param p5 the destination details size
 * @param p6 the source model
 * @param p7 the source model count
 * @param p8 the source abstraction
 * @param p9 the source abstraction count
 * @param p10 the source channel
 * @param p11 the source channel count
 */
void receive_file_system_compound_model(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5,
    void* p6, void* p7, void* p8, void* p9, void* p10, void* p11) {

    log_message_debug("Receive file system compound model.");

    //?? The temporary workaround flag to use the libxml2 parser.
    //?? Later, when an own xml parser is implemented in cyboi,
    //?? delete this flag and change the corresponding blocks below!
    int w = *NUMBER_0_INTEGER;
    //?? If the abstraction is "compound", then a cybol (xml) file representing
    //?? a compound model is expected, so that the libxml2 parser is to be used.
    //?? Otherwise, the flag remains zero and the file is parsed/ decoded normally.
    compare_arrays(p8, p9, (void*) COMPOUND_ABSTRACTION, (void*) COMPOUND_ABSTRACTION_COUNT, (void*) &w, (void*) CHARACTER_ARRAY);

    //
    // Receive.
    //

    // The receive model.
    void* rm = *NULL_POINTER;
    int rmc = *NUMBER_0_INTEGER;
    int rms = *NUMBER_0_INTEGER;

    // Allocate receive model of type character, to read single bytes.
    allocate((void*) &rm, (void*) &rms, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT);

    // Read persistent byte stream over channel.
    read_data((void*) &rm, (void*) &rmc, (void*) &rms, p6, p7, p10, p11);

    //
    // Parse.
    //

    // The parse model.
    void* pm = *NULL_POINTER;
    int pmc = *NUMBER_0_INTEGER;
    int pms = *NUMBER_0_INTEGER;
    // The parse details.
    void* pd = *NULL_POINTER;
    int pdc = *NUMBER_0_INTEGER;
    int pds = *NUMBER_0_INTEGER;

    if (w == *NUMBER_0_INTEGER) {

        // Allocate parse model of type given as abstraction.
//??        allocate((void*) &pm, (void*) &pms, p5, p6);
        //?? Possibly ALWAYS use a "compound" model here?
        //?? The external file in whatever format gets parsed and needs to be
        //?? represented in memory with some structure.
        //?? The standard "compound" structure of cyboi seems to be suitable
        //?? best and all operations for its processing already exist.
        //?? What else should be used instead?
        allocate((void*) &pm, (void*) &pms, (void*) COMPOUND_ABSTRACTION, (void*) COMPOUND_ABSTRACTION_COUNT);
        // Allocate parse details, which are always of type "compound".
        allocate((void*) &pd, (void*) &pds, (void*) COMPOUND_ABSTRACTION, (void*) COMPOUND_ABSTRACTION_COUNT);

        // Parse byte stream according to given document type.
        parse((void*) &pm, (void*) &pmc, (void*) &pms, (void*) &pd, (void*) &pdc, (void*) &pds, rm, (void*) &rmc, p8, p9);

    } else {

        parse((void*) &pm, (void*) &pmc, (void*) &pms, (void*) &pd, (void*) &pdc, (void*) &pds, p6, p7, p8, p9);
    }

    // Deallocate receive model.
    deallocate((void*) &rm, (void*) &rms, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT);

    //
    // Decode.
    //

    // Allocate compound decode model.
    allocate(p0, p2, (void*) COMPOUND_ABSTRACTION, (void*) COMPOUND_ABSTRACTION_COUNT);

    // Decode document model according to given document type.
    decode(p0, p1, p2, pm, (void*) &pmc, p8, p9);

    if (w == *NUMBER_0_INTEGER) {

        // Deallocate parse model.
//??        deallocate((void*) &pm, (void*) &pms, p8, p9);
        deallocate((void*) &pm, (void*) &pms, (void*) COMPOUND_ABSTRACTION, (void*) COMPOUND_ABSTRACTION_COUNT);
        // Deallocate parse details, which are always of type "compound".
        deallocate((void*) &pd, (void*) &pds, (void*) COMPOUND_ABSTRACTION, (void*) COMPOUND_ABSTRACTION_COUNT);

    } else {

        if (pm != *NULL_POINTER) {

            // Free xml dom document.
            xmlFreeDoc((xmlDoc*) *((void**) pm));

        } else {

            log_message_debug("Could not free parse model (xml document). Probably, the given cybol file name was empty.");
        }
    }
}

/**
 * Receives and creates a transient destination model
 * from a persistent source model.
 *
 * Primitive models need to be handled differently than compound models.
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
 * @param p0 the destination model (Hand over as reference!)
 * @param p1 the destination model count
 * @param p2 the destination model size
 * @param p3 the destination details (Hand over as reference!)
 * @param p4 the destination details count
 * @param p5 the destination details size
 * @param p6 the source model
 * @param p7 the source model count
 * @param p8 the source abstraction
 * @param p9 the source abstraction count
 * @param p10 the source channel
 * @param p11 the source channel count
 */
void receive_file_system_model(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5,
    void* p6, void* p7, void* p8, void* p9, void* p10, void* p11) {

    log_message_debug("Receive file system model.");

    // The comparison result.
    int r = *NUMBER_0_INTEGER;

    compare_arrays(p8, p9, (void*) COMPOUND_ABSTRACTION, (void*) COMPOUND_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

    if (r != *NUMBER_0_INTEGER) {

        receive_file_system_compound_model(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11);

    } else {

        receive_file_system_primitive_model(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11);
    }
}

/**
 * Receives a message from the file system.
 *
 * This procedure reads the given file, creates a knowledge model and adds it to the given whole element,
 * or to the knowledge memory root directly, if no whole element is given.
 *
 * Expected parameters:
 * - name
 * - channel
 * - abstraction
 * - model
 * - element (may be "part" or "meta")
 * - whole
 *
 * @param p0 the knowledge memory
 * @param p1 the knowledge memory count
 * @param p2 the knowledge memory size
 * @param p3 the whole model
 * @param p4 the whole model count
 * @param p5 the whole model size
 * @param p6 the whole details
 * @param p7 the whole details count
 * @param p8 the whole details size
 * @param p9 the name model
 * @param p10 the name model count
 * @param p11 the name abstraction
 * @param p12 the name abstraction count
 * @param p13 the abstraction model
 * @param p14 the abstraction model count
 * @param p15 the abstraction abstraction
 * @param p16 the abstraction abstraction count
 * @param p17 the channel model
 * @param p18 the channel model count
 * @param p19 the model model
 * @param p20 the model model count
 * @param p21 the element model
 * @param p22 the element model count
 */
void receive_file_system(void* p0, void* p1, void* p2,
    void* p3, void* p4, void* p5, void* p6, void* p7, void* p8,
    void* p9, void* p10, void* p11, void* p12,
    void* p13, void* p14, void* p15, void* p16,
    void* p17, void* p18, void* p19, void* p20, void* p21, void* p22) {

    log_message_debug("Receive file system message.");

    // The knowledge model name.
    void* n = *NULL_POINTER;
    int* nc = (int*) *NULL_POINTER;
    int* ns = (int*) *NULL_POINTER;
    // The knowledge model abstraction.
    void* a = *NULL_POINTER;
    int* ac = (int*) *NULL_POINTER;
    int* as = (int*) *NULL_POINTER;
    // The knowledge model model.
    void* m = *NULL_POINTER;
    int* mc = (int*) *NULL_POINTER;
    int* ms = (int*) *NULL_POINTER;
    // The knowledge model details.
    void* d = *NULL_POINTER;
    int* dc = (int*) *NULL_POINTER;
    int* ds = (int*) *NULL_POINTER;

    // Create knowledge model name.
    allocate((void*) &nc, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
    *nc = *NUMBER_0_INTEGER;
    allocate((void*) &ns, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
    *ns = *NUMBER_0_INTEGER;
    allocate((void*) &n, (void*) ns, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT);

    // A knowledge model channel is not allocated,
    // since that is only needed temporarily for model loading.

    // Create knowledge model abstraction.
    allocate((void*) &ac, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
    *ac = *NUMBER_0_INTEGER;
    allocate((void*) &as, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
    *as = *NUMBER_0_INTEGER;
    allocate((void*) &a, (void*) as, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT);

    // Create knowledge model model.
    allocate((void*) &mc, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
    *mc = *NUMBER_0_INTEGER;
    allocate((void*) &ms, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
    *ms = *NUMBER_0_INTEGER;
    allocate((void*) &m, (void*) ms, p13, p14);

    // Create knowledge model details.
    allocate((void*) &dc, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
    *dc = *NUMBER_0_INTEGER;
    allocate((void*) &ds, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
    *ds = *NUMBER_0_INTEGER;
    allocate((void*) &d, (void*) ds, (void*) COMPOUND_ABSTRACTION, (void*) COMPOUND_ABSTRACTION_COUNT);

    // Receive knowledge model name.
    receive_file_system_model((void*) &n, (void*) nc, (void*) ns, *NULL_POINTER, *NULL_POINTER, *NULL_POINTER, p9, p10, p11, p12, (void*) INLINE_CHANNEL, (void*) INLINE_CHANNEL_COUNT);
    // Receive knowledge model abstraction.
    receive_file_system_model((void*) &a, (void*) ac, (void*) as, *NULL_POINTER, *NULL_POINTER, *NULL_POINTER, p13, p14, p15, p16, (void*) INLINE_CHANNEL, (void*) INLINE_CHANNEL_COUNT);
    // Receive knowledge model model and details.
    // CAUTION! The knowledge model model is received TOGETHER with the
    // knowledge model details, in just one operation.
    receive_file_system_model((void*) &m, (void*) mc, (void*) ms, (void*) &d, (void*) dc, (void*) ds, p19, p20, p13, p14, p17, p18);

    // The comparison result.
    int r = *NUMBER_0_INTEGER;

    if (r == *NUMBER_0_INTEGER) {

        compare_arrays(p21, p22, (void*) CREATE_PART_ELEMENT_MODEL, (void*) CREATE_PART_ELEMENT_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != *NUMBER_0_INTEGER) {

            if (p3 != *NULL_POINTER) {

                log_message_debug("Add part knowledge model to whole model.");

                // Use the determined whole model, if it exists.
                set_compound_element_by_name(p3, p4, p5,
                    n, (void*) nc, (void*) ns,
                    a, (void*) ac, (void*) as,
                    m, (void*) mc, (void*) ms,
                    d, (void*) dc, (void*) ds);

            } else {

                log_message_debug("Add part knowledge model to knowledge memory root.");

                // Use the knowledge memory root if the determined whole model is null.
                set_compound_element_by_name(p0, p1, p2,
                    n, (void*) nc, (void*) ns,
                    a, (void*) ac, (void*) as,
                    m, (void*) mc, (void*) ms,
                    d, (void*) dc, (void*) ds);
            }
        }
    }

    if (r == *NUMBER_0_INTEGER) {

        compare_arrays(p21, p22, (void*) CREATE_META_ELEMENT_MODEL, (void*) CREATE_META_ELEMENT_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != *NUMBER_0_INTEGER) {

            if (p6 != *NULL_POINTER) {

                log_message_debug("Add meta knowledge model to whole details.");

                // Use the determined whole details model, if it exists.
                set_compound_element_by_name(p6, p7, p8,
                    n, (void*) nc, (void*) ns,
                    a, (void*) ac, (void*) as,
                    m, (void*) mc, (void*) ms,
                    d, (void*) dc, (void*) ds);

            } else {

                log_message_debug("Could not add meta knowledge model to whole details. The whole details is null.");
            }
        }
    }
}

/* LINUX_OPERATING_SYSTEM */
#endif

/* RECEIVE_FILE_SYSTEM_SOURCE */
#endif
