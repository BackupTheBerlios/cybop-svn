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
 * This file contains the functionality to:
 * - encode a cyboi knowledge tree (compound) into an xml (dom) tree
 * - decode an xml (dom) tree into a cyboi knowledge tree (compound)
 *
 * @version $Revision: 1.1 $ $Date: 2004-08-13 22:37:50 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef TRANSLATOR_SOURCE
#define TRANSLATOR_SOURCE

#include "../array/array.c"
#include "../global/abstraction_constants.c"
#include "../global/log_constants.c"
#include "../logger/logger.c"

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
}

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

    if (p6 != NULL_POINTER) {

        int* tc = (int*) p6;

        // The done flag.
        int d = 0;
        // The comparison result.
        int r = 0;

        //?? Later, additional formats besides cybol might be read,
        //?? for example html, sxi, hdx.sf.net etc.

        if (d == 0) {

            if (*tc == XML_ABSTRACTION_COUNT) {

                compare_array_elements(p5, (void*) &XML_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &XML_ABSTRACTION_COUNT, (void*) &r);

                if (r == 1) {

                    decode_xml(p0, p1, p2, p3, p4);

                    d = 1;
                }
            }
        }

    } else {

//??        log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_DECODE_MESSAGE, (void*) &COULD_NOT_DECODE_MESSAGE_COUNT);
    }
}

/* TRANSLATOR_SOURCE */
#endif
