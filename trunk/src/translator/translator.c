/*
 * $RCSfile: translator.c,v $
 *
 * Copyright (c) 1999-2005. Christian Heller. All rights reserved.
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
 * @version $Revision: 1.14 $ $Date: 2005-03-02 07:27:58 $ $Author: rholzmueller $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef TRANSLATOR_SOURCE
#define TRANSLATOR_SOURCE

#include "../array/array.c"
#include "../creator/integer_creator.c"
#include "../global/abstraction_constants.c"
#include "../global/log_constants.c"
#include "../logger/logger.c"
#include "../translator/configuration_translator.c"
#include "../translator/cybol_translator.c"
#include "../translator/html_translator.c"

/**
 * Decodes the document model according to the given document type
 * and creates a cyboi compound model from it.
 *
 * @param p0 the destination (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source
 * @param p4 the source count
 * @param p5 the type
 * @param p6 the type count
 */
void decode(void* p0, void* p1, void* p2, const void* p3, const void* p4,
    const void* p5, const void* p6) {

    // The comparison result.
    int r = 0;

    if (r != 1) {

        compare_arrays(p5, p6, (void*) CYBOL_ABSTRACTION, (void*) CYBOL_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

            decode_cybol(p0, p1, p2, p3, p4);
        }
    }

    if (r != 1) {

        compare_arrays(p5, p6, (void*) CONFIGURATION_ABSTRACTION, (void*) CONFIGURATION_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

            decode_configuration(p0, p1, p2, p3, p4);
        }
    }

    //?? Later, additional formats besides cybol might be read,
    //?? for example html, sxi, hdx.sf.net etc.
}

/**
 * Encodes the cyboi compound model according to the given document type
 * and creates a document model from it.
 *
 * @param p0 the destination (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source
 * @param p4 the source count
 * @param p5 the type
 * @param p6 the type count
 */
void encode(void* p0, void* p1, void* p2, const void* p3, const void* p4,
    const void* p5, const void* p6) {

    // The comparison result.
    int r = 0;

    if (r != 1) {

        compare_arrays(p5, p6, (void*) CYBOL_ABSTRACTION, (void*) CYBOL_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

            encode_cybol(p0, p1, p2, p3, p4);
        }
    }

    if (r != 1) {

        compare_arrays(p5, p6, (void*) CONFIGURATION_ABSTRACTION, (void*) CONFIGURATION_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

            encode_configuration(p0, p1, p2, p3, p4);
        }
    }

    //?? Later, additional formats besides cybol might be read,
    //?? for example html, sxi, hdx.sf.net etc.
}


/**
 * Encodes a cyboi model according to the given document type
 * and creates a document model from it.
 *
 * @param dest the destination (Hand over as reference!)
 * @param dest_count the destination count
 * @param dest_size the destination size
 * @param source_abstr the source abstraction
 * @param source_abstr_count the source abstraction count
 * @param source_model the source model
 * @param source_model_count the source model count
 * @param source_detail the source detail
 * @param source_detail_count the source detail count
 * @param type the type
 * @param type_count the type count
 * @param know the knowledege memeory
 * @param know_count the knowledege memeory count
 * @param know_size the knowledege memeory size
 * 
 */
void encode_model( void** dest, int* dest_count, int* dest_size, 
                   const void* source_abstr, const int* source_abstr_count,
                   const void* source_model, const int* source_model_count,
                   const void* source_detail, const int* source_detail_count,
                   const void* type, const int* type_count,
                   const void* know, const int* know_count) 
{

    // The comparison result.
    int r = 0;

    if (r != 1) {

        compare_arrays(type, type_count, (void*) HTML_ABSTRACTION, (void*) HTML_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

            encode_html( dest, dest_count, dest_size,
                         source_abstr, source_abstr_count,
                         source_model, source_model_count,
                         source_detail, source_detail_count,
                         know, know_count );
        }
    }

    //?? Later, additional formats besides cybol might be read,
    //?? for example html, sxi, hdx.sf.net etc.
}

/* TRANSLATOR_SOURCE */
#endif
