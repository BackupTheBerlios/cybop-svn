/*
 * $RCSfile: create.c,v $
 *
 * Copyright (c) 1999-2005. Christian Heller and the CYBOP developers.
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
 * @version $Revision: 1.33 $ $Date: 2005-03-30 14:15:42 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CREATE_SOURCE
#define CREATE_SOURCE

#include <libxml/tree.h>
#include "../array/array.c"
#include "../creator/creator.c"
#include "../communicator/communicator.c"
#include "../global/abstraction_constants.c"
#include "../global/log_constants.c"
#include "../global/name_constants.c"
#include "../logger/logger.c"
#include "../parser/parser.c"
#include "../translator/translator.c"
#include "../test/test.c"

/**
 * Checks for primitive model.
 *
 * @param p0 the primitive flag (1 if primitive; unchanged otherwise)
 * @param p1 the abstraction
 * @param p2 the abstraction count
 */
void check_primitive_model(void* p0, const void* p1, const void* p2) {

    if (p0 != NULL_POINTER) {

        int* p = (int*) p0;

        if (*p != 1) {

            compare_arrays(p1, p2, (void*) COMPOUND_ABSTRACTION, (void*) COMPOUND_ABSTRACTION_COUNT, p0, (void*) CHARACTER_ARRAY);
        }

        if (*p != 1) {

            compare_arrays(p1, p2, (void*) OPERATION_ABSTRACTION, (void*) OPERATION_ABSTRACTION_COUNT, p0, (void*) CHARACTER_ARRAY);
        }

        if (*p != 1) {

            compare_arrays(p1, p2, (void*) STRING_ABSTRACTION, (void*) STRING_ABSTRACTION_COUNT, p0, (void*) CHARACTER_ARRAY);
        }

        if (*p != 1) {

            compare_arrays(p1, p2, (void*) INTEGER_ABSTRACTION, (void*) INTEGER_ABSTRACTION_COUNT, p0, (void*) CHARACTER_ARRAY);
        }

        if (*p != 1) {

            compare_arrays(p1, p2, (void*) DOUBLE_ABSTRACTION, (void*) DOUBLE_ABSTRACTION_COUNT, p0, (void*) CHARACTER_ARRAY);
        }

        if (*p != 1) {

            compare_arrays(p1, p2, (void*) BOOLEAN_ABSTRACTION, (void*) BOOLEAN_ABSTRACTION_COUNT, p0, (void*) CHARACTER_ARRAY);
        }

        if (*p != 1) {

            compare_arrays(p1, p2, (void*) VECTOR_ABSTRACTION, (void*) VECTOR_ABSTRACTION_COUNT, p0, (void*) CHARACTER_ARRAY);
        }

        if (*p != 1) {

            compare_arrays(p1, p2, (void*) FRACTION_ABSTRACTION, (void*) FRACTION_ABSTRACTION_COUNT, p0, (void*) CHARACTER_ARRAY);
        }

        if (*p != 1) {

            compare_arrays(p1, p2, (void*) TIME_ABSTRACTION, (void*) TIME_ABSTRACTION_COUNT, p0, (void*) CHARACTER_ARRAY);
        }

        if (*p != 1) {

            compare_arrays(p1, p2, (void*) COMPLEX_ABSTRACTION, (void*) COMPLEX_ABSTRACTION_COUNT, p0, (void*) CHARACTER_ARRAY);
        }

        if (*p != 1) {

            compare_arrays(p1, p2, (void*) KNOWLEDGE_ABSTRACTION, (void*) KNOWLEDGE_ABSTRACTION_COUNT, p0, (void*) CHARACTER_ARRAY);
        }

        if (*p != 1) {

            compare_arrays(p1, p2, (void*) ENCAPSULATED_KNOWLEDGE_ABSTRACTION, (void*) ENCAPSULATED_KNOWLEDGE_ABSTRACTION_COUNT, p0, (void*) CHARACTER_ARRAY);
        }

    } else {

//??        log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_HANDLE_CREATE_MODEL_SIGNAL_THE_KNOWLEDGE_SIZE_IS_NULL_MESSAGE, (void*) &COULD_NOT_HANDLE_CREATE_MODEL_SIGNAL_THE_KNOWLEDGE_SIZE_IS_NULL_MESSAGE_COUNT);
    }
}

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
 *                receive                           parse
 * source code  ----------> received/read model  ----------> parsed model
 * (persistent)             (transient)                      (transient)
 *
 * The counterparts of the creation procedures are:
 * - receive <--> send (read <--> write)
 * - parse <--> serialize
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
void create_primitive_model(void* p0, void* p1, void* p2, const void* p3, const void* p4,
    const void* p5, const void* p6, const void* p7, const void* p8) {

    log_message_debug("Create primitive model.");

    //
    // Receive.
    //

    // The receive model.
    void* rm = NULL_POINTER;
    int rmc = 0;
    int rms = 0;

    // Create receive model of type character, to read single bytes.
    create((void*) &rm, (void*) &rms, (void*) STRING_ABSTRACTION, (void*) STRING_ABSTRACTION_COUNT);

    // Receive persistent byte stream over channel.
    receive_general((void*) &rm, (void*) &rmc, (void*) &rms, p3, p4, p7, p8);

    //
    // Parse.
    //

    // Create parse model of type given as abstraction.
    create(p0, p2, p5, p6);

    // Parse byte stream according to given document type.
    parse(p0, p1, p2, rm, (void*) &rmc, p5, p6);

    // Destroy receive model.
    destroy((void*) &rm, (void*) &rms, (void*) STRING_ABSTRACTION, (void*) STRING_ABSTRACTION_COUNT);
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
 *                receive                           parse                   decode
 * source code  ----------> received/read model  ----------> parsed model ----------> decoded model
 * (persistent)             (transient)                      (transient)              (transient)
 *
 * The counterparts of the creation procedures are:
 * - receive <--> send (read <--> write)
 * - parse <--> serialize
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
void create_compound_model(void* p0, void* p1, void* p2, const void* p3, const void* p4,
    const void* p5, const void* p6, const void* p7, const void* p8) {

    log_message_debug("Create compound model.");

    //?The configuration flag.
    int c = 0;

    compare_arrays(p5, p6, (void*) CONFIGURATION_ABSTRACTION, (void*) CONFIGURATION_ABSTRACTION_COUNT, (void*) &c, (void*) CHARACTER_ARRAY);

    //?The temporary workaround flag to use the libxml2 parser.
    //?? Later, when an own xml parser is implemented in cyboi,
    //?? delete this flag and change the corresponding blocks below!
    int w = 0;

    // Comparison can be done one-after-the-other, because results are only set
    // to 1, if true, but they are NOT set to 0, if false.
    // So, later comparisons won't affect the result of earlier ones.
    compare_arrays(p5, p6, (void*) CONFIGURATION_ABSTRACTION, (void*) CONFIGURATION_ABSTRACTION_COUNT, (void*) &w, (void*) CHARACTER_ARRAY);
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
    create((void*) &rm, (void*) &rms, (void*) STRING_ABSTRACTION, (void*) STRING_ABSTRACTION_COUNT);

    // Receive persistent byte stream over channel.
    receive_general((void*) &rm, (void*) &rmc, (void*) &rms, p3, p4, p7, p8);

    //
    // Parse.
    //

    // The parse model.
    void* pm = NULL_POINTER;
    int pmc = 0;
    int pms = 0;

    if (w == 0) {

        // Create parse model of type given as abstraction.
        create((void*) &pm, (void*) &pms, p5, p6);

        // Parse byte stream according to given document type.
        parse((void*) &pm, (void*) &pmc, (void*) &pms, rm, (void*) &rmc, p5, p6);

    } else {

        parse((void*) &pm, (void*) &pmc, (void*) &pms, p3, p4, p5, p6);
    }

    // Destroy receive model.
    destroy((void*) &rm, (void*) &rms, (void*) STRING_ABSTRACTION, (void*) STRING_ABSTRACTION_COUNT);

    //
    // Decode.
    //

    if (c == 0) {

        // Create compound decode model.
        create(p0, p2, (void*) COMPOUND_ABSTRACTION, (void*) COMPOUND_ABSTRACTION_COUNT);

    } else {

        // Create internals memory decode model.
        create(p0, p2, (void*) INTERNALS_MEMORY_ABSTRACTION, (void*) INTERNALS_MEMORY_ABSTRACTION_COUNT);
    }

    // Decode document model according to given document type.
    decode(p0, p1, p2, pm, (void*) &pmc, p5, p6);

//?? Start of TEMPORARY test from Rolf Holzmueller. Delete again later!
//    if (c == 0) {
//
//        int index = 0;
//        test_compound(*((void**) p0), p2, &index);
//    }
//?? End of TEMPORARY test from Rolf Holzmueller.

    if (w == 0) {

        // Destroy parse model.
        destroy((void*) &pm, (void*) &pms, p5, p6);

    } else {

        // Free xml dom document.
        xmlFreeDoc((xmlDoc*) *((void**) pm));
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
void create_model(void* p0, void* p1, void* p2, const void* p3, const void* p4,
    const void* p5, const void* p6, const void* p7, const void* p8) {

    log_message_debug("Create model.");

    //?The comparison result.
    int r = 0;

    // Check for primitive model.
    check_primitive_model((void*) &r, p5, p6);

    if (r == 1) {

        create_primitive_model(p0, p1, p2, p3, p4, p5, p6, p7, p8);

    } else {

        create_compound_model(p0, p1, p2, p3, p4, p5, p6, p7, p8);
    }
}

/**
 * Creates a part and adds it to the knowledge model.
 *
 * Expected parameters:
 * - name
 * - channel
 * - abstraction
 * - model
 *
 * @param p0 the parameters
 * @param p1 the parameters count
 * @param p2 the knowledge
 * @param p3 the knowledge count
 * @param p4 the knowledge size
 */
void create_part(const void* p0, const void* p1, void* p2, void* p3, void* p4) {

    log_message_debug("Create part.");

    // The name name abstraction.
    void** na = POINTER_NULL_POINTER;
    void** nac = POINTER_NULL_POINTER;
    void** nas = POINTER_NULL_POINTER;
    // The name name model.
    void** nm = POINTER_NULL_POINTER;
    void** nmc = POINTER_NULL_POINTER;
    void** nms = POINTER_NULL_POINTER;
    // The name name details.
    void** nd = POINTER_NULL_POINTER;
    void** ndc = POINTER_NULL_POINTER;
    void** nds = POINTER_NULL_POINTER;

    // The channel name abstraction.
    void** ca = POINTER_NULL_POINTER;
    void** cac = POINTER_NULL_POINTER;
    void** cas = POINTER_NULL_POINTER;
    // The channel name model.
    void** cm = POINTER_NULL_POINTER;
    void** cmc = POINTER_NULL_POINTER;
    void** cms = POINTER_NULL_POINTER;
    // The channel name details.
    void** cd = POINTER_NULL_POINTER;
    void** cdc = POINTER_NULL_POINTER;
    void** cds = POINTER_NULL_POINTER;

    // The abstraction name abstraction.
    void** aa = POINTER_NULL_POINTER;
    void** aac = POINTER_NULL_POINTER;
    void** aas = POINTER_NULL_POINTER;
    // The abstraction name model.
    void** am = POINTER_NULL_POINTER;
    void** amc = POINTER_NULL_POINTER;
    void** ams = POINTER_NULL_POINTER;
    // The abstraction name details.
    void** ad = POINTER_NULL_POINTER;
    void** adc = POINTER_NULL_POINTER;
    void** ads = POINTER_NULL_POINTER;

    // The model name abstraction.
    void** ma = POINTER_NULL_POINTER;
    void** mac = POINTER_NULL_POINTER;
    void** mas = POINTER_NULL_POINTER;
    // The model name model.
    void** mm = POINTER_NULL_POINTER;
    void** mmc = POINTER_NULL_POINTER;
    void** mms = POINTER_NULL_POINTER;
    // The model name details.
    void** md = POINTER_NULL_POINTER;
    void** mdc = POINTER_NULL_POINTER;
    void** mds = POINTER_NULL_POINTER;

    // The whole abstraction.
    void** wa = POINTER_NULL_POINTER;
    void** wac = POINTER_NULL_POINTER;
    void** was = POINTER_NULL_POINTER;
    // The whole model.
    void** wm = POINTER_NULL_POINTER;
    void** wmc = POINTER_NULL_POINTER;
    void** wms = POINTER_NULL_POINTER;
    // The whole details.
    void** wd = POINTER_NULL_POINTER;
    void** wdc = POINTER_NULL_POINTER;
    void** wds = POINTER_NULL_POINTER;

    // Get name name.
    get_real_compound_element_by_name(p0, p1,
        (void*) NAME_NAME_ABSTRACTION, (void*) NAME_NAME_ABSTRACTION_COUNT,
        (void*) &na, (void*) &nac, (void*) &nas,
        (void*) &nm, (void*) &nmc, (void*) &nms,
        (void*) &nd, (void*) &ndc, (void*) &nds,
        p2, p3);

    // Get channel name.
    get_real_compound_element_by_name(p0, p1,
        (void*) CHANNEL_NAME_ABSTRACTION, (void*) CHANNEL_NAME_ABSTRACTION_COUNT,
        (void*) &ca, (void*) &cac, (void*) &cas,
        (void*) &cm, (void*) &cmc, (void*) &cms,
        (void*) &cd, (void*) &cdc, (void*) &cds,
        p2, p3);

    // Get abstraction name.
    get_real_compound_element_by_name(p0, p1,
        (void*) ABSTRACTION_NAME_ABSTRACTION, (void*) ABSTRACTION_NAME_ABSTRACTION_COUNT,
        (void*) &aa, (void*) &aac, (void*) &aas,
        (void*) &am, (void*) &amc, (void*) &ams,
        (void*) &ad, (void*) &adc, (void*) &ads,
        p2, p3);

    // Get model name.
    get_real_compound_element_by_name(p0, p1,
        (void*) MODEL_NAME_ABSTRACTION, (void*) MODEL_NAME_ABSTRACTION_COUNT,
        (void*) &ma, (void*) &mac, (void*) &mas,
        (void*) &mm, (void*) &mmc, (void*) &mms,
        (void*) &md, (void*) &mdc, (void*) &mds,
        p2, p3);

    // Get whole.
    get_real_compound_element_by_name(p0, p1,
        (void*) WHOLE_NAME_ABSTRACTION, (void*) WHOLE_NAME_ABSTRACTION_COUNT,
        (void*) &wa, (void*) &wac, (void*) &was,
        (void*) &wm, (void*) &wmc, (void*) &wms,
        (void*) &wd, (void*) &wdc, (void*) &wds,
        p2, p3);

    // Check name name.
    if ((na != POINTER_NULL_POINTER)
        && (nac != POINTER_NULL_POINTER)
        && (nas != POINTER_NULL_POINTER)
        && (nm != POINTER_NULL_POINTER)
        && (nmc != POINTER_NULL_POINTER)
        && (nms != POINTER_NULL_POINTER)
        && (nd != POINTER_NULL_POINTER)
        && (ndc != POINTER_NULL_POINTER)
        && (nds != POINTER_NULL_POINTER)
        // Check channel name.
        && (ca != POINTER_NULL_POINTER)
        && (cac != POINTER_NULL_POINTER)
        && (cas != POINTER_NULL_POINTER)
        && (cm != POINTER_NULL_POINTER)
        && (cmc != POINTER_NULL_POINTER)
        && (cms != POINTER_NULL_POINTER)
        && (cd != POINTER_NULL_POINTER)
        && (cdc != POINTER_NULL_POINTER)
        && (cds != POINTER_NULL_POINTER)
        // Check abstraction name.
        && (aa != POINTER_NULL_POINTER)
        && (aac != POINTER_NULL_POINTER)
        && (aas != POINTER_NULL_POINTER)
        && (am != POINTER_NULL_POINTER)
        && (amc != POINTER_NULL_POINTER)
        && (ams != POINTER_NULL_POINTER)
        && (ad != POINTER_NULL_POINTER)
        && (adc != POINTER_NULL_POINTER)
        && (ads != POINTER_NULL_POINTER)
        // Check model name.
        && (ma != POINTER_NULL_POINTER)
        && (mac != POINTER_NULL_POINTER)
        && (mas != POINTER_NULL_POINTER)
        && (mm != POINTER_NULL_POINTER)
        && (mmc != POINTER_NULL_POINTER)
        && (mms != POINTER_NULL_POINTER)
        && (md != POINTER_NULL_POINTER)
        && (mdc != POINTER_NULL_POINTER)
        && (mds != POINTER_NULL_POINTER)
//        // Check whole name.
//        && (wa != POINTER_NULL_POINTER)
//        && (wac != POINTER_NULL_POINTER)
//        && (was != POINTER_NULL_POINTER)
//        && (wm != POINTER_NULL_POINTER)
//        && (wmc != POINTER_NULL_POINTER)
//        && (wms != POINTER_NULL_POINTER)
//        && (wd != POINTER_NULL_POINTER)
//        && (wdc != POINTER_NULL_POINTER)
//        && (wds != POINTER_NULL_POINTER)
        ) {

        // The part name.
        void* pn = NULL_POINTER;
        int* pnc = INTEGER_NULL_POINTER;
        int* pns = INTEGER_NULL_POINTER;
        // The part abstraction.
        void* pa = NULL_POINTER;
        int* pac = INTEGER_NULL_POINTER;
        int* pas = INTEGER_NULL_POINTER;
        // The part model.
        void* pm = NULL_POINTER;
        int* pmc = INTEGER_NULL_POINTER;
        int* pms = INTEGER_NULL_POINTER;
        // The part details.
        void* pd = NULL_POINTER;
        int* pdc = INTEGER_NULL_POINTER;
        int* pds = INTEGER_NULL_POINTER;

        // Create part name.
        create_integer((void*) &pnc);
        *pnc = 0;
        create_integer((void*) &pns);
        *pns = 0;
        create_model((void*) &pn, (void*) pnc, (void*) pns, *nm, *nmc, *na, *nac,
            (void*) INLINE_CHANNEL, (void*) INLINE_CHANNEL_COUNT);

        // A part channel is not created, since that is only needed temporarily
        // for model loading.

        // Create part abstraction.
        create_integer((void*) &pac);
        *pac = 0;
        create_integer((void*) &pas);
        *pas = 0;
        create_model((void*) &pa, (void*) pac, (void*) pas, *am, *amc, *aa, *aac,
            (void*) INLINE_CHANNEL, (void*) INLINE_CHANNEL_COUNT);

        // Create part model.
        create_integer((void*) &pmc);
        *pmc = 0;
        create_integer((void*) &pms);
        *pms = 0;
        create_model((void*) &pm, (void*) pmc, (void*) pms, *mm, *mmc, *am, *amc,
            *cm, *cmc);

        // Add part to whole.
        if (wm == NULL_POINTER) {

            // Use the knowledge model root if the determined whole model is null.
            set_compound_element_by_name(p2, p3, p4,
                pn, (void*) pnc, (void*) pns,
                pa, (void*) pac, (void*) pas,
                pm, (void*) pmc, (void*) pms,
                pd, (void*) pdc, (void*) pds);

        } else {

            // Use the determined whole model normally, if it exists.
            set_compound_element_by_name(*wm, *wmc, *wms,
                pn, (void*) pnc, (void*) pns,
                pa, (void*) pac, (void*) pas,
                pm, (void*) pmc, (void*) pms,
                pd, (void*) pdc, (void*) pds);
        }

    } else {

        log_message_debug("Could not create part. At least one of the given parameters is null.");
    }
}

/* CREATE_SOURCE */
#endif
