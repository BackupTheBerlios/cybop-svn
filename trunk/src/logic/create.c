/*
 * $RCSfile: create.c,v $
 *
 * Copyright (c) 1999-2004. Christian Heller. All rights reserved.
 *
 * This software is published under the GPL GNU General Public License.
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
 * @version $Revision: 1.17 $ $Date: 2004-12-13 22:47:20 $ $Author: christian $
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

/**
 * Checks for primitive model.
 *
 * @param p0 the primitive flag (1 if primitive; 0 otherwise)
 * @param p1 the abstraction
 * @param p2 the abstraction count
 */
void check_primitive_model(void* p0, const void* p1, const void* p2) {

    if (p0 != NULL_POINTER) {

        int* p = (int*) p0;

        // The done flag.
        int d = 0;

        // The following comparisons could also be done one after the other,
        // without "done" flag. But the done flag avoids unnecessary comparisons.

        if (d == 0) {

            compare_arrays(p1, p2, (void*) &COMPOUND_ABSTRACTION, (void*) &COMPOUND_ABSTRACTION_COUNT, p0, (void*) &CHARACTER_ARRAY);

            if (*p == 1) {

                d = 1;
            }
        }

        if (d == 0) {

            compare_arrays(p1, p2, (void*) &OPERATION_ABSTRACTION, (void*) &OPERATION_ABSTRACTION_COUNT, p0, (void*) &CHARACTER_ARRAY);

            if (*p == 1) {

                d = 1;
            }
        }

        if (d == 0) {

            compare_arrays(p1, p2, (void*) &STRING_ABSTRACTION, (void*) &STRING_ABSTRACTION_COUNT, p0, (void*) &CHARACTER_ARRAY);

            if (*p == 1) {

                d = 1;
            }
        }

        if (d == 0) {

            compare_arrays(p1, p2, (void*) &INTEGER_ABSTRACTION, (void*) &INTEGER_ABSTRACTION_COUNT, p0, (void*) &CHARACTER_ARRAY);

            if (*p == 1) {

                d = 1;
            }
        }

        if (d == 0) {

            compare_arrays(p1, p2, (void*) &DOUBLE_ABSTRACTION, (void*) &DOUBLE_ABSTRACTION_COUNT, p0, (void*) &CHARACTER_ARRAY);

            if (*p == 1) {

                d = 1;
            }
        }

        if (d == 0) {

            compare_arrays(p1, p2, (void*) &BOOLEAN_ABSTRACTION, (void*) &BOOLEAN_ABSTRACTION_COUNT, p0, (void*) &CHARACTER_ARRAY);

            if (*p == 1) {

                d = 1;
            }
        }

        if (d == 0) {

            compare_arrays(p1, p2, (void*) &VECTOR_ABSTRACTION, (void*) &VECTOR_ABSTRACTION_COUNT, p0, (void*) &CHARACTER_ARRAY);

            if (*p == 1) {

                d = 1;
            }
        }

        if (d == 0) {

            compare_arrays(p1, p2, (void*) &FRACTION_ABSTRACTION, (void*) &FRACTION_ABSTRACTION_COUNT, p0, (void*) &CHARACTER_ARRAY);

            if (*p == 1) {

                d = 1;
            }
        }

        if (d == 0) {

            compare_arrays(p1, p2, (void*) &TIME_ABSTRACTION, (void*) &TIME_ABSTRACTION_COUNT, p0, (void*) &CHARACTER_ARRAY);

            if (*p == 1) {

                d = 1;
            }
        }

        if (d == 0) {

            compare_arrays(p1, p2, (void*) &COMPLEX_ABSTRACTION, (void*) &COMPLEX_ABSTRACTION_COUNT, p0, (void*) &CHARACTER_ARRAY);

            if (*p == 1) {

                d = 1;
            }
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
 * @param p0 the destination
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

    fputs("TEST: create primitive model\n", stdout);

    //
    // Receive.
    //

    // The receive model.
    void* rm = NULL_POINTER;
    int rmc = 0;
    int rms = 0;

    // Create receive model of type character, to read single bytes.
    create((void*) &rm, (void*) &rms,
        (void*) &STRING_ABSTRACTION, (void*) &STRING_ABSTRACTION_COUNT);

    // Receive persistent byte stream over channel.
    receive_general((void*) &rm, (void*) &rmc, (void*) &rms, p3, p4, p7, p8);

    //
    // Parse.
    //

    // Create parse model of type given as abstraction.
    create(p0, p2, p5, p6);

    // Parse byte stream according to given document type.
    parse(p0, p1, p2, (void*) &rm, (void*) &rmc, p5, p6);

    // Destroy receive model.
    destroy((void*) &rm, (void*) &rms,
        (void*) &STRING_ABSTRACTION, (void*) &STRING_ABSTRACTION_COUNT);
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
 * @param p0 the destination
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

    fputs("TEST: create compound model\n", stdout);

    // The temporary workaround flag to use the libxml2 parser.
    //?? Later, when an own xml parser is implemented in cyboi,
    //?? delete this flag and change the corresponding blocks below!
    int w = 0;

    compare_arrays(p5, p6, (void*) &CYBOL_ABSTRACTION, (void*) &CYBOL_ABSTRACTION_COUNT,
        (void*) &w, (void*) &CHARACTER_ARRAY);
    compare_arrays(p5, p6, (void*) &XML_ABSTRACTION, (void*) &XML_ABSTRACTION_COUNT,
        (void*) &w, (void*) &CHARACTER_ARRAY);
    compare_arrays(p5, p6, (void*) &HXP_ABSTRACTION, (void*) &HXP_ABSTRACTION_COUNT,
        (void*) &w, (void*) &CHARACTER_ARRAY);

    //
    // Receive.
    //

    // The receive model.
    void* rm = NULL_POINTER;
    int rmc = 0;
    int rms = 0;

    // Create receive model of type character, to read single bytes.
    create((void*) &rm, (void*) &rms,
        (void*) &STRING_ABSTRACTION, (void*) &STRING_ABSTRACTION_COUNT);

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
        parse((void*) &pm, (void*) &pmc, (void*) &pms,
            (void*) &rm, (void*) &rmc, p5, p6);

    } else {

        parse((void*) &pm, (void*) &pmc, (void*) &pms, p3, p4, p5, p6);
    }

    // Destroy receive model.
    destroy((void*) &rm, (void*) &rms,
        (void*) &STRING_ABSTRACTION, (void*) &STRING_ABSTRACTION_COUNT);

    //
    // Decode.
    //
    
    // Create compound decode model.
    create(p0, p2, (void*) &COMPOUND_ABSTRACTION, (void*) &COMPOUND_ABSTRACTION_COUNT);
    
    // Decode document model according to given document type.
    decode(p0, p1, p2, (void*) &pm, (void*) &pmc, p5, p6);

    if (w == 0) {

        // Destroy parsed model.
        destroy((void*) &pm, (void*) &pms, p5, p6);

    } else {

        // Free xml dom document.
        xmlFreeDoc((xmlDoc*) pm);
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
 * @param p0 the destination
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source model
 * @param p4 the source model xy
 * @param p5 the source abstraction
 * @param p6 the source abstraction count
 * @param p7 the source channel
 * @param p8 the source channel count
 */
void create_model(void* p0, void* p1, void* p2, const void* p3, const void* p4,
    const void* p5, const void* p6, const void* p7, const void* p8) {

    // The primitive flag.
    int p = 0;

    // Check for primitive model.
    check_primitive_model((void*) &p, p5, p6);

    if (p == 1) {

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

    // The name name abstraction.
    void* na = NULL_POINTER;
    int nac = 0;
    int nas = 0;
    // The name name model.
    void* nm = NULL_POINTER;
    int nmc = 0;
    int nms = 0;
    // The name name details.
    void* nd = NULL_POINTER;
    int ndc = 0;
    int nds = 0;

    // The channel name abstraction.
    void* ca = NULL_POINTER;
    int cac = 0;
    int cas = 0;
    // The channel name model.
    void* cm = NULL_POINTER;
    int cmc = 0;
    int cms = 0;
    // The channel name details.
    void* cd = NULL_POINTER;
    int cdc = 0;
    int cds = 0;

    // The abstraction name abstraction.
    void* aa = NULL_POINTER;
    int aac = 0;
    int aas = 0;
    // The abstraction name model.
    void* am = NULL_POINTER;
    int amc = 0;
    int ams = 0;
    // The abstraction name details.
    void* ad = NULL_POINTER;
    int adc = 0;
    int ads = 0;

    // The model name abstraction.
    void* ma = NULL_POINTER;
    int mac = 0;
    int mas = 0;
    // The model name model.
    void* mm = NULL_POINTER;
    int mmc = 0;
    int mms = 0;
    // The model name details.
    void* md = NULL_POINTER;
    int mdc = 0;
    int mds = 0;

    // The whole abstraction.
    void* wa = NULL_POINTER;
    int wac = 0;
    int was = 0;
    // The whole model.
    void* wm = NULL_POINTER;
    void* wmc = NULL_POINTER;
    void* wms = NULL_POINTER;
    // The whole details.
    void* wd = NULL_POINTER;
    int wdc = 0;
    int wds = 0;

    // The part name.
    void* pn = NULL_POINTER;
    int pnc = 0;
    int pns = 0;
    // The part abstraction.
    void* pa = NULL_POINTER;
    int pac = 0;
    int pas = 0;
    // The part model.
    void* pm = NULL_POINTER;
    int pmc = 0;
    int pms = 0;
    // The part details.
    void* pd = NULL_POINTER;
    int pdc = 0;
    int pds = 0;

    // Get name name.
    get_compound_element_by_name(p0, p1,
        (void*) &NAME_NAME_ABSTRACTION, (void*) &NAME_NAME_ABSTRACTION_COUNT,
        (void*) &na, (void*) &nac, (void*) &nas,
        (void*) &nm, (void*) &nmc, (void*) &nms,
        (void*) &nd, (void*) &ndc, (void*) &nds);

    // Get channel name.
    get_compound_element_by_name(p0, p1,
        (void*) &CHANNEL_NAME_ABSTRACTION, (void*) &CHANNEL_NAME_ABSTRACTION_COUNT,
        (void*) &ca, (void*) &cac, (void*) &cas,
        (void*) &cm, (void*) &cmc, (void*) &cms,
        (void*) &cd, (void*) &cdc, (void*) &cds);

    // Get abstraction name.
    get_compound_element_by_name(p0, p1,
        (void*) &ABSTRACTION_NAME_ABSTRACTION, (void*) &ABSTRACTION_NAME_ABSTRACTION_COUNT,
        (void*) &aa, (void*) &aac, (void*) &aas,
        (void*) &am, (void*) &amc, (void*) &ams,
        (void*) &ad, (void*) &adc, (void*) &ads);

    // Get model name.
    get_compound_element_by_name(p0, p1,
        (void*) &MODEL_NAME_ABSTRACTION, (void*) &MODEL_NAME_ABSTRACTION_COUNT,
        (void*) &ma, (void*) &mac, (void*) &mas,
        (void*) &mm, (void*) &mmc, (void*) &mms,
        (void*) &md, (void*) &mdc, (void*) &mds);

    // Get whole.
    get_compound_element_by_encapsulated_name(p0, p1,
        (void*) &WHOLE_NAME_ABSTRACTION, (void*) &WHOLE_NAME_ABSTRACTION_COUNT,
        (void*) &wa, (void*) &wac, (void*) &was,
        (void*) &wm, (void*) &wmc, (void*) &wms,
        (void*) &wd, (void*) &wdc, (void*) &wds,
        p2, p3);

    // Create part name.
    create_model((void*) &pn, (void*) &pnc, (void*) &pns,
        (void*) &nm, (void*) &nmc,
        (void*) &na, (void*) &nac,
        (void*) &INLINE_CHANNEL, (void*) &INLINE_CHANNEL_COUNT);

    // A part channel is not created, since that is only needed temporarily for
    // model loading.

    // Create part abstraction.
    create_model((void*) &pa, (void*) &pac, (void*) &pas,
        (void*) &am, (void*) &amc,
        (void*) &aa, (void*) &aac,
        (void*) &INLINE_CHANNEL, (void*) &INLINE_CHANNEL_COUNT);

    // Create part model.
    create_model((void*) &pm, (void*) &pmc, (void*) &pms,
        (void*) &mm, (void*) &mmc,
        (void*) &am, (void*) &amc,
        (void*) &cm, (void*) &cmc);

    // Add part to whole.
    if (wm == NULL_POINTER) {

        // Use the knowledge model root if the determined whole model is null.
        set_compound_element_by_name(p2, p3, p4,
            (void*) &pn, (void*) &pnc, (void*) &pns,
            (void*) &pa, (void*) &pac, (void*) &pas,
            (void*) &pm, (void*) &pmc, (void*) &pms,
            (void*) &pd, (void*) &pdc, (void*) &pds);

    } else {

        // Use the determined whole model normally, if it exists.
        set_compound_element_by_name((void*) &wm, (void*) &wmc, (void*) &wms,
            (void*) &pn, (void*) &pnc, (void*) &pns,
            (void*) &pa, (void*) &pac, (void*) &pas,
            (void*) &pm, (void*) &pmc, (void*) &pms,
            (void*) &pd, (void*) &pdc, (void*) &pds);
    }
}

/* CREATE_SOURCE */
#endif
