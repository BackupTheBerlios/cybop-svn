/*
 * $RCSfile: parser.c,v $
 *
 * Copyright (c) 2002-2004. Christian Heller. All rights reserved.
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
 * - parse an xml stream into an xml model
 * - serialize an xml model into an xml stream
 *
 * @version $Revision: 1.2 $ $Date: 2004-08-14 22:47:54 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef PARSER_SOURCE
#define PARSER_SOURCE

#include "../array/array.c"
#include "../global/abstraction_constants.c"
#include "../global/log_constants.c"
#include "../logger/logger.c"
#include "../parser/xml_parser.c"

/**
 * Parses the byte stream according to the given document type
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
void parse(void* p0, void* p1, void* p2, const void* p3, const void* p4,
    const void* p5, const void* p6) {

    if (p6 != NULL_POINTER) {

        int* tc = (int*) p6;

        // The done flag.
        int d = 0;
        // The comparison result.
        int r = 0;

        //?? Later, distinguish file types according to suffix,
        //?? for example xml, html, sxi, txt, rtf,
        //?? adl (from OpenEHR), KIF, ODL etc.!
        //?? For now, only the cybol file format is considered.

        if (d == 0) {

            if (*tc == XML_ABSTRACTION_COUNT) {

                compare_array_elements(p5, (void*) &XML_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &XML_ABSTRACTION_COUNT, (void*) &r);

                if (r == 1) {

                    parse_xml(p0, p1, p2, p3, p4);

                    d = 1;
                }
            }
        }

    } else {

//??        log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_PARSE_MESSAGE, (void*) &COULD_NOT_PARSE_MESSAGE_COUNT);
    }
}

/**
 * Serializes the document model according to the given document type
 * and creates a byte stream from it.
 *
 * @param p0 the destination
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source
 * @param p4 the source count
 * @param p5 the type
 * @param p6 the type count
 */
void serializes(void* p0, void* p1, void* p2, const void* p3, const void* p4,
    const void* p5, const void* p6) {
}

/* PARSER_SOURCE */
#endif
