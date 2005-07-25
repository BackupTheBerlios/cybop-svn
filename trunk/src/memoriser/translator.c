/*
 * $RCSfile: translator.c,v $
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
 * @version $Revision: 1.3 $ $Date: 2005-07-25 21:01:02 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef TRANSLATOR_SOURCE
#define TRANSLATOR_SOURCE

#include "../memoriser/translator/cybol_translator.c"
#include "../memoriser/translator/html_translator.c"
#include "../memoriser/translator/x_window_system_translator.c"

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
void decode(void* p0, void* p1, void* p2, void* p3, void* p4,
    void* p5, void* p6) {

    // The comparison result.
    int r = 0;

    if (r != 1) {

        compare_arrays(p5, p6, (void*) CYBOL_ABSTRACTION, (void*) CYBOL_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

            decode_cybol(p0, p1, p2, p3, p4);
        }
    }

/*??
    if (r != 1) {

        compare_arrays(p5, p6, (void*) X_WINDOW_SYSTEM_ABSTRACTION, (void*) X_WINDOW_SYSTEM_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

            decode_x_window_system(p0, p1, p2, p3, p4);
        }
    }
*/

    if (r != 1) {

        compare_arrays(p5, p6, (void*) HTML_ABSTRACTION, (void*) HTML_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

//??            decode_html(p0, p1, p2, p3, p4);
        }
    }

    if (r != 1) {

        compare_arrays(p5, p6, (void*) SXW_ABSTRACTION, (void*) SXW_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

//??            decode_sxw(p0, p1, p2, p3, p4);
        }
    }

    if (r != 1) {

        compare_arrays(p5, p6, (void*) HXP_ABSTRACTION, (void*) HXP_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

//??            decode_hxp(p0, p1, p2, p3, p4);
        }
    }

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
void encode(void* p0, void* p1, void* p2, void* p3, void* p4,
    void* p5, void* p6) {

    // The comparison result.
    int r = 0;

    if (r != 1) {

        compare_arrays(p5, p6, (void*) CYBOL_ABSTRACTION, (void*) CYBOL_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

            encode_cybol(p0, p1, p2, p3, p4);
        }
    }

/*??
    if (r != 1) {

        compare_arrays(p5, p6, (void*) X_WINDOW_SYSTEM_ABSTRACTION, (void*) X_WINDOW_SYSTEM_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

            encode_x_window_system(p0, p1, p2, p3, p4);
        }
    }
*/

    if (r != 1) {

        compare_arrays(p5, p6, (void*) HTML_ABSTRACTION, (void*) HTML_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

//??            encode_html(p0, p1, p2, p3, p4);
        }
    }

    if (r != 1) {

        compare_arrays(p5, p6, (void*) SXW_ABSTRACTION, (void*) SXW_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

//??            encode_sxw(p0, p1, p2, p3, p4);
        }
    }

    if (r != 1) {

        compare_arrays(p5, p6, (void*) HXP_ABSTRACTION, (void*) HXP_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

//??            encode_hxp(p0, p1, p2, p3, p4);
        }
    }

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
 */
void encode_model(void** dest, int* dest_count, int* dest_size,
                  void* source_abstr, int* source_abstr_count,
                  void* source_model, int* source_model_count,
                  void* source_detail, int* source_detail_count,
                  void* type, int* type_count,
                  void* know, int* know_count) {

    // The comparison result.
    int r = 0;

    if (r != 1) {

        compare_arrays(type, type_count, (void*) HTML_ABSTRACTION, (void*) HTML_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

            encode_html(dest, dest_count, dest_size,
                        source_abstr, source_abstr_count,
                        source_model, source_model_count,
                        source_detail, source_detail_count,
                        know, know_count);
        }
    }
}

/* TRANSLATOR_SOURCE */
#endif
