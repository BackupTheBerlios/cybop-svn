/*
 * $RCSfile: translator.c,v $
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
 * @version $Revision: 1.5 $ $Date: 2004-09-11 22:19:43 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef TRANSLATOR_SOURCE
#define TRANSLATOR_SOURCE

#include "../array/array.c"
#include "../global/abstraction_constants.c"
#include "../global/log_constants.c"
#include "../logger/logger.c"
#include "../translator/compound_translator.c"
#include "../translator/xml_translator.c"

/**
 * Decodes the document model according to the given document type
 * and creates a cyboi model from it.
 *
 * @param p0 the destination
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source
 * @param p4 the source count
 * @param p5 the type
 * @param p6 the type count
 */
void decode(void* p0, void* p1, void* p2, const void* p3, const void* p4,
    const void* p5, const void* p6) {

    // The done flag.
    int d = 0;
    // The comparison result.
    int r = 0;

    if (d == 0) {

        compare_arrays(p5, p6, (void*) &XML_ABSTRACTION, (void*) &XML_ABSTRACTION_COUNT, (void*) &r, (void*) &CHARACTER_ARRAY);

        if (r == 1) {

            decode_xml(p0, p1, p2, p3, p4);

            d = 1;
        }
    }

    if (d == 0) {

        compare_arrays(p5, p6, (void*) &COMPOUND_ABSTRACTION, (void*) &COMPOUND_ABSTRACTION_COUNT, (void*) &r, (void*) &CHARACTER_ARRAY);

        if (r == 1) {

            decode_compound(p0, p1, p2, p3, p4);

            d = 1;
        }
    }

    //?? Later, additional formats besides cybol might be read,
    //?? for example html, sxi, hdx.sf.net etc.
}

/**
 * Encodes the cyboi model according to the given document type
 * and creates a document model from it.
 *
 * @param p0 the destination
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source
 * @param p4 the source count
 * @param p5 the type
 * @param p6 the type count
 */
void encode(void* p0, void* p1, void* p2, const void* p3, const void* p4,
    const void* p5, const void* p6) {

    // The done flag.
    int d = 0;
    // The comparison result.
    int r = 0;

    if (d == 0) {

        compare_arrays(p5, p6, (void*) &XML_ABSTRACTION, (void*) &XML_ABSTRACTION_COUNT, (void*) &r, (void*) &CHARACTER_ARRAY);

        if (r == 1) {

            encode_xml(p0, p1, p2, p3, p4);

            d = 1;
        }
    }

    if (d == 0) {

        compare_arrays(p5, p6, (void*) &COMPOUND_ABSTRACTION, (void*) &COMPOUND_ABSTRACTION_COUNT, (void*) &r, (void*) &CHARACTER_ARRAY);

        if (r == 1) {

            encode_compound(p0, p1, p2, p3, p4);

            d = 1;
        }
    }

    //?? Later, additional formats besides cybol might be read,
    //?? for example html, sxi, hdx.sf.net etc.
}

/* TRANSLATOR_SOURCE */
#endif
