/*
 * $RCSfile: create.c,v $
 *
 * Copyright (c) 1999-2006. Christian Heller and the CYBOP developers.
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
 * @version $Revision: 1.17 $ $Date: 2006-04-20 22:36:09 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CREATE_SOURCE
#define CREATE_SOURCE

#include <libxml/tree.h>
#include "../globals/constants/abstraction_constants.c"
#include "../globals/constants/log_constants.c"
#include "../globals/constants/name_constants.c"
#include "../globals/logger/logger.c"
#include "../memoriser/array.c"
#include "../memoriser/communicator.c"
#include "../memoriser/converter.c"
#include "../memoriser/allocator.c"
#include "../memoriser/translator.c"

/**
 * Checks for primitive model.
 *
 * @param p0 the primitive flag (1 if primitive; unchanged otherwise)
 * @param p1 the abstraction
 * @param p2 the abstraction count
 */
void check_primitive_model(void* p0, void* p1, void* p2) {

    if (p0 != NULL_POINTER) {

        int* p = (int*) p0;

        if (*p == 0) {

            compare_arrays(p1, p2, (void*) COMPOUND_ABSTRACTION, (void*) COMPOUND_ABSTRACTION_COUNT, p0, (void*) CHARACTER_ARRAY);
        }

        if (*p == 0) {

            compare_arrays(p1, p2, (void*) OPERATION_ABSTRACTION, (void*) OPERATION_ABSTRACTION_COUNT, p0, (void*) CHARACTER_ARRAY);
        }

        if (*p == 0) {

            compare_arrays(p1, p2, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT, p0, (void*) CHARACTER_ARRAY);
        }

        if (*p == 0) {

            compare_arrays(p1, p2, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT, p0, (void*) CHARACTER_ARRAY);
        }

        if (*p == 0) {

            compare_arrays(p1, p2, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT, p0, (void*) CHARACTER_ARRAY);
        }

        if (*p == 0) {

            compare_arrays(p1, p2, (void*) DOUBLE_VECTOR_ABSTRACTION, (void*) DOUBLE_VECTOR_ABSTRACTION_COUNT, p0, (void*) CHARACTER_ARRAY);
        }

        if (*p == 0) {

            compare_arrays(p1, p2, (void*) DOUBLE_VECTOR_ABSTRACTION, (void*) DOUBLE_VECTOR_ABSTRACTION_COUNT, p0, (void*) CHARACTER_ARRAY);
        }

        if (*p == 0) {

            compare_arrays(p1, p2, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT, p0, (void*) CHARACTER_ARRAY);
        }

        if (*p == 0) {

            compare_arrays(p1, p2, (void*) BOOLEAN_ABSTRACTION, (void*) BOOLEAN_ABSTRACTION_COUNT, p0, (void*) CHARACTER_ARRAY);
        }

        if (*p == 0) {

            compare_arrays(p1, p2, (void*) FRACTION_ABSTRACTION, (void*) FRACTION_ABSTRACTION_COUNT, p0, (void*) CHARACTER_ARRAY);
        }

        if (*p == 0) {

            compare_arrays(p1, p2, (void*) TIME_ABSTRACTION, (void*) TIME_ABSTRACTION_COUNT, p0, (void*) CHARACTER_ARRAY);
        }

        if (*p == 0) {

            compare_arrays(p1, p2, (void*) COMPLEX_ABSTRACTION, (void*) COMPLEX_ABSTRACTION_COUNT, p0, (void*) CHARACTER_ARRAY);
        }

        if (*p == 0) {

            compare_arrays(p1, p2, (void*) KNOWLEDGE_ABSTRACTION, (void*) KNOWLEDGE_ABSTRACTION_COUNT, p0, (void*) CHARACTER_ARRAY);
        }

        if (*p == 0) {

            compare_arrays(p1, p2, (void*) ENCAPSULATED_KNOWLEDGE_ABSTRACTION, (void*) ENCAPSULATED_KNOWLEDGE_ABSTRACTION_COUNT, p0, (void*) CHARACTER_ARRAY);
        }

    } else {

//??        log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_HANDLE_CREATE_MODEL_SIGNAL_THE_KNOWLEDGE_SIZE_IS_NULL_MESSAGE, (void*) &COULD_NOT_HANDLE_CREATE_MODEL_SIGNAL_THE_KNOWLEDGE_SIZE_IS_NULL_MESSAGE_COUNT);
    }
}

/**
 * Allocates a primitive model.
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
    parse(p0, p1, p2, rm, (void*) &rmc, p5, p6);

    // Destroy receive model.
    deallocate((void*) &rm, (void*) &rms, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT);
}

/**
 * Allocates a compound model.
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
    int w = 0;

    // Comparison can be done one-after-the-other, because results are only set
    // to 1, if true, but they are NOT set to 0, if false.
    // So, later comparisons won't affect the result of earlier ones.
    compare_arrays(p5, p6, (void*) CYBOL_ABSTRACTION, (void*) CYBOL_ABSTRACTION_COUNT, (void*) &w, (void*) CHARACTER_ARRAY);
    compare_arrays(p5, p6, (void*) XML_ABSTRACTION, (void*) XML_ABSTRACTION_COUNT, (void*) &w, (void*) CHARACTER_ARRAY);
    compare_arrays(p5, p6, (void*) HXP_ABSTRACTION, (void*) HXP_ABSTRACTION_COUNT, (void*) &w, (void*) CHARACTER_ARRAY);

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
        parse((void*) &pm, (void*) &pmc, (void*) &pms, rm, (void*) &rmc, p5, p6);

    } else {

        parse((void*) &pm, (void*) &pmc, (void*) &pms, p3, p4, p5, p6);
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

        // Free xml dom document.
        xmlFreeDoc((xmlDoc*) *((void**) pm));
    }
}

/**
 * Allocates a transient destination model from a persistent source model.
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
void create(void* p0, void* p1, void* p2, void* p3, void* p4,
    void* p5, void* p6, void* p7, void* p8) {

    log_message_debug("Create model.");

    //?The comparison result.
    int r = 0;

    // Check for primitive model.
    check_primitive_model((void*) &r, p5, p6);

    if (r != 0) {

        create_primitive_model(p0, p1, p2, p3, p4, p5, p6, p7, p8);

    } else {

        create_compound_model(p0, p1, p2, p3, p4, p5, p6, p7, p8);
    }
}

/**
 * Allocates a part and adds it to the knowledge model.
 *
 * Expected parameters:
 * - name
 * - channel
 * - abstraction
 * - model
 *
 * @param p0 the parameters
 * @param p1 the parameters count
 * @param p2 the knowledge memory
 * @param p3 the knowledge memory count
 * @param p4 the knowledge memory size
 */
void create_part(void* p0, void* p1, void* p2, void* p3, void* p4) {

    // The name name abstraction.
    void** na = &NULL_POINTER;
    void** nac = &NULL_POINTER;
    void** nas = &NULL_POINTER;
    // The name name model.
    void** nm = &NULL_POINTER;
    void** nmc = &NULL_POINTER;
    void** nms = &NULL_POINTER;
    // The name name details.
    void** nd = &NULL_POINTER;
    void** ndc = &NULL_POINTER;
    void** nds = &NULL_POINTER;

    // The channel name abstraction.
    void** ca = &NULL_POINTER;
    void** cac = &NULL_POINTER;
    void** cas = &NULL_POINTER;
    // The channel name model.
    void** cm = &NULL_POINTER;
    void** cmc = &NULL_POINTER;
    void** cms = &NULL_POINTER;
    // The channel name details.
    void** cd = &NULL_POINTER;
    void** cdc = &NULL_POINTER;
    void** cds = &NULL_POINTER;

    // The abstraction name abstraction.
    void** aa = &NULL_POINTER;
    void** aac = &NULL_POINTER;
    void** aas = &NULL_POINTER;
    // The abstraction name model.
    void** am = &NULL_POINTER;
    void** amc = &NULL_POINTER;
    void** ams = &NULL_POINTER;
    // The abstraction name details.
    void** ad = &NULL_POINTER;
    void** adc = &NULL_POINTER;
    void** ads = &NULL_POINTER;

    // The model name abstraction.
    void** ma = &NULL_POINTER;
    void** mac = &NULL_POINTER;
    void** mas = &NULL_POINTER;
    // The model name model.
    void** mm = &NULL_POINTER;
    void** mmc = &NULL_POINTER;
    void** mms = &NULL_POINTER;
    // The model name details.
    void** md = &NULL_POINTER;
    void** mdc = &NULL_POINTER;
    void** mds = &NULL_POINTER;

    // The whole abstraction.
    void** wa = &NULL_POINTER;
    void** wac = &NULL_POINTER;
    void** was = &NULL_POINTER;
    // The whole model.
    void** wm = &NULL_POINTER;
    void** wmc = &NULL_POINTER;
    void** wms = &NULL_POINTER;
    // The whole details.
    void** wd = &NULL_POINTER;
    void** wdc = &NULL_POINTER;
    void** wds = &NULL_POINTER;

    // Get name name.
    get_real_compound_element_by_name(p0, p1,
        (void*) NAME_NAME, (void*) NAME_NAME_COUNT,
        (void*) &na, (void*) &nac, (void*) &nas,
        (void*) &nm, (void*) &nmc, (void*) &nms,
        (void*) &nd, (void*) &ndc, (void*) &nds,
        p2, p3);

    // Get channel name.
    get_real_compound_element_by_name(p0, p1,
        (void*) CHANNEL_NAME, (void*) CHANNEL_NAME_COUNT,
        (void*) &ca, (void*) &cac, (void*) &cas,
        (void*) &cm, (void*) &cmc, (void*) &cms,
        (void*) &cd, (void*) &cdc, (void*) &cds,
        p2, p3);

    // Get abstraction name.
    get_real_compound_element_by_name(p0, p1,
        (void*) ABSTRACTION_NAME, (void*) ABSTRACTION_NAME_COUNT,
        (void*) &aa, (void*) &aac, (void*) &aas,
        (void*) &am, (void*) &amc, (void*) &ams,
        (void*) &ad, (void*) &adc, (void*) &ads,
        p2, p3);

    // Get model name.
    get_real_compound_element_by_name(p0, p1,
        (void*) MODEL_NAME, (void*) MODEL_NAME_COUNT,
        (void*) &ma, (void*) &mac, (void*) &mas,
        (void*) &mm, (void*) &mmc, (void*) &mms,
        (void*) &md, (void*) &mdc, (void*) &mds,
        p2, p3);

    // Get whole.
    get_real_compound_element_by_name(p0, p1,
        (void*) WHOLE_NAME, (void*) WHOLE_NAME_COUNT,
        (void*) &wa, (void*) &wac, (void*) &was,
        (void*) &wm, (void*) &wmc, (void*) &wms,
        (void*) &wd, (void*) &wdc, (void*) &wds,
        p2, p3);

/*??
    // Check name name.
    if ((*na != NULL_POINTER)
        && (*nac != NULL_POINTER)
        && (*nas != NULL_POINTER)
        && (*nm != NULL_POINTER)
        && (*nmc != NULL_POINTER)
        && (*nms != NULL_POINTER)
        && (*nd != NULL_POINTER)
        && (*ndc != NULL_POINTER)
        && (*nds != NULL_POINTER)
        // Check channel name.
        && (*ca != NULL_POINTER)
        && (*cac != NULL_POINTER)
        && (*cas != NULL_POINTER)
        && (*cm != NULL_POINTER)
        && (*cmc != NULL_POINTER)
        && (*cms != NULL_POINTER)
        && (*cd != NULL_POINTER)
        && (*cdc != NULL_POINTER)
        && (*cds != NULL_POINTER)
        // Check abstraction name.
        && (*aa != NULL_POINTER)
        && (*aac != NULL_POINTER)
        && (*aas != NULL_POINTER)
        && (*am != NULL_POINTER)
        && (*amc != NULL_POINTER)
        && (*ams != NULL_POINTER)
        && (*ad != NULL_POINTER)
        && (*adc != NULL_POINTER)
        && (*ads != NULL_POINTER)
        // Check model name.
        && (*ma != NULL_POINTER)
        && (*mac != NULL_POINTER)
        && (*mas != NULL_POINTER)
        && (*mm != NULL_POINTER)
        && (*mmc != NULL_POINTER)
        && (*mms != NULL_POINTER)
        && (*md != NULL_POINTER)
        && (*mdc != NULL_POINTER)
        && (*mds != NULL_POINTER)
//        // Check whole name.
//        && (*wa != NULL_POINTER)
//        && (*wac != NULL_POINTER)
//        && (*was != NULL_POINTER)
//        && (*wm != NULL_POINTER)
//        && (*wmc != NULL_POINTER)
//        && (*wms != NULL_POINTER)
//        && (*wd != NULL_POINTER)
//        && (*wdc != NULL_POINTER)
//        && (*wds != NULL_POINTER)
        ) {
*/

        log_message_debug("Create part.");

        // The part name.
        void* pn = NULL_POINTER;
        int* pnc = NULL_POINTER;
        int* pns = NULL_POINTER;
        // The part abstraction.
        void* pa = NULL_POINTER;
        int* pac = NULL_POINTER;
        int* pas = NULL_POINTER;
        // The part model.
        void* pm = NULL_POINTER;
        int* pmc = NULL_POINTER;
        int* pms = NULL_POINTER;
        // The part details.
        void* pd = NULL_POINTER;
        int* pdc = NULL_POINTER;
        int* pds = NULL_POINTER;

        // Create part name.
        allocate((void*) &pnc, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
        *pnc = 0;
        allocate((void*) &pns, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
        *pns = 0;
        create((void*) &pn, (void*) pnc, (void*) pns, *nm, *nmc, *na, *nac, (void*) INLINE_CHANNEL, (void*) INLINE_CHANNEL_COUNT);

        // A part channel is not created, since that is only needed temporarily
        // for model loading.

        // Create part abstraction.
        allocate((void*) &pac, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
        *pac = 0;
        allocate((void*) &pas, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
        *pas = 0;
        create((void*) &pa, (void*) pac, (void*) pas, *am, *amc, *aa, *aac, (void*) INLINE_CHANNEL, (void*) INLINE_CHANNEL_COUNT);

        // Create part model.
        allocate((void*) &pmc, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
        *pmc = 0;
        allocate((void*) &pms, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
        *pms = 0;
        create((void*) &pm, (void*) pmc, (void*) pms, *mm, *mmc, *am, *amc, *cm, *cmc);

        // Add part to whole.
        if (*wm == NULL_POINTER) {

            log_message_debug("Add part to knowledge model root.");

            // Use the knowledge model root if the determined whole model is null.
            set_compound_element_by_name(p2, p3, p4,
                pn, (void*) pnc, (void*) pns,
                pa, (void*) pac, (void*) pas,
                pm, (void*) pmc, (void*) pms,
                pd, (void*) pdc, (void*) pds);

        } else {

            log_message_debug("Add part to given whole model.");

            // Use the determined whole model normally, if it exists.
            set_compound_element_by_name(*wm, *wmc, *wms,
                pn, (void*) pnc, (void*) pns,
                pa, (void*) pac, (void*) pas,
                pm, (void*) pmc, (void*) pms,
                pd, (void*) pdc, (void*) pds);
        }

/*??
    } else {

        log_message_debug("Could not create part. At least one of the given parameters is null.");
    }
*/
}

/* CREATE_SOURCE */
#endif
