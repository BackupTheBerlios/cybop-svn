/*
 * $RCSfile: translator.c,v $
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
 * @version $Revision: 1.17 $ $Date: 2007-04-16 15:50:29 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef TRANSLATOR_SOURCE
#define TRANSLATOR_SOURCE

#include "../globals/constants/cybol/cybol_abstraction_constants.c"
#include "../globals/constants/cybol/cybol_model_constants.c"
#include "../globals/variables/variables.c"
#include "../memoriser/array.c"
#include "../memoriser/translator/xdt_translator.c"
#include "../memoriser/translator/cybol_translator.c"

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
void decode(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    // The comparison result.
    int r = 0;

    if (r == 0) {

        compare_arrays(p5, p6, (void*) COMPOUND_ABSTRACTION, (void*) COMPOUND_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            decode_cybol(p0, p1, p2, p3, p4);
        }
    }

    if (r == 0) {

        compare_arrays(p5, p6, (void*) HXP_ABSTRACTION, (void*) HXP_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

//??            decode_hxp(p0, p1, p2, p3, p4);
        }
    }

    if (r == 0) {

        compare_arrays(p5, p6, (void*) XDT_ABSTRACTION, (void*) XDT_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            decode_xdt(p0, p1, p2, p3, p4);
        }
    }

    if (r == 0) {

        compare_arrays(p5, p6, (void*) HXP_ABSTRACTION, (void*) HXP_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

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
void encode(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    // The comparison result.
    int r = 0;

    if (r == 0) {

        compare_arrays(p5, p6, (void*) COMPOUND_ABSTRACTION, (void*) COMPOUND_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            encode_cybol(p0, p1, p2, p3, p4);
        }
    }

    if (r == 0) {

        compare_arrays(p5, p6, (void*) XDT_ABSTRACTION, (void*) XDT_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            encode_xdt(p0, p1, p2, p3, p4);
        }
    }

    if (r == 0) {

        compare_arrays(p5, p6, (void*) SXW_ABSTRACTION, (void*) SXW_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

//??            encode_sxw(p0, p1, p2, p3, p4);
        }
    }

    if (r == 0) {

        compare_arrays(p5, p6, (void*) HXP_ABSTRACTION, (void*) HXP_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

//??            encode_hxp(p0, p1, p2, p3, p4);
        }
    }
}

/* TRANSLATOR_SOURCE */
#endif
