/*
 * $RCSfile: xhtml_converter.c,v $
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
 * @version $Revision: 1.1 $ $Date: 2007-01-30 01:11:06 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef XHTML_CONVERTER_SOURCE
#define XHTML_CONVERTER_SOURCE

#include "../../globals/constants/abstraction_constants.c"
#include "../../globals/constants/channel_constants.c"
#include "../../globals/constants/ascii_character_constants.c"
#include "../../globals/constants/log_constants.c"
#include "../../globals/constants/name_constants.c"
#include "../../globals/constants/structure_constants.c"
#include "../../globals/logger/logger.c"
#include "../../memoriser/accessor.c"
#include "../../memoriser/accessor/compound_accessor.c"
#include "../../memoriser/array.c"

/**
 * Parses an xhtml format into a compound model.
 *
 * @param p0 the destination part (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source xhtml byte array
 * @param p4 the source count
 */
void parse_xhtml(void* p0, void* p1, void* p2, void* p3, void* p4) {
}

/**
 * Serialises the xhtml attributes.
 *
 * @param p0 the destination xhtml byte array (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source part details
 * @param p4 the source part details count
 * @param p5 the knowledge memory
 * @param p6 the knowledge memory count
 */
void serialise_xhtml_attributes(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    // The source part href attribute.
    void** ta = &NULL_POINTER;
    void** tac = &NULL_POINTER;
    void** tas = &NULL_POINTER;
    void** tm = &NULL_POINTER;
    void** tmc = &NULL_POINTER;
    void** tms = &NULL_POINTER;
    void** td = &NULL_POINTER;
    void** tdc = &NULL_POINTER;
    void** tds = &NULL_POINTER;

    // Get source part href attribute from details.
    get_universal_compound_element_by_name(p3, p4,
        (void*) WUI_TAG_NAME, (void*) WUI_TAG_NAME_COUNT,
        (void*) &ta, (void*) &tac, (void*) &tas,
        (void*) &tm, (void*) &tmc, (void*) &tms,
        (void*) &td, (void*) &tdc, (void*) &tds,
        p5, p6);
}

/**
 * Serialises the xhtml begin tag.
 *
 * @param p0 the destination html byte array (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source part model
 * @param p4 the source part model count
 * @param p5 the source part details
 * @param p6 the source part details count
 * @param p7 the knowledge memory
 * @param p8 the knowledge memory count
 */
void serialise_xhtml_begin_tag(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8) {

    // Serialise less than character.
    serialise_character_vector(p0, p1, p2, (void*) LESS_THAN_SIGN_ASCII_CHARACTER, (void*) PRIMITIVE_COUNT);
    // Serialise xhtml tag.
    serialise_character_vector(p0, p1, p2, p3, p4);
    // Serialise space character.
    serialise_character_vector(p0, p1, p2, (void*) SPACE_ASCII_CHARACTER, (void*) PRIMITIVE_COUNT);
    // Serialise html tag properties.
    serialise_xhtml_attributes(p0, p1, p2, p5, p6, p7, p8);
    // Serialise greater than character.
    serialise_character_vector(p0, p1, p2, (void*) GREATER_THAN_SIGN_ASCII_CHARACTER, (void*) PRIMITIVE_COUNT);
    // Serialise line feed character, for better source reading.
    serialise_character_vector(p0, p1, p2, (void*) LINE_FEED_CONTROL_ASCII_CHARACTER, (void*) PRIMITIVE_COUNT);
}

/**
 * Serialises a compound model into xhtml format.
 *
 * @param p0 the destination html byte array (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source part abstraction
 * @param p4 the source part abstraction count
 * @param p5 the source part model
 * @param p6 the source part model count
 * @param p7 the source part details
 * @param p8 the source part details count
 * @param p9 the knowledge memory
 * @param p10 the knowledge memory count
 */
void serialise_xhtml(void* p0, void* p1, void* p2, void* p3, void* p4,
    void* p5, void* p6, void* p7, void* p8, void* p9, void* p10) {

    if (p6 != NULL_POINTER) {

        int* sc = (int*) p6;

        log_message_debug("Serialise compound model into xhtml format.");

        // The source part abstraction, model, details.
        void** a = &NULL_POINTER;
        void** ac = &NULL_POINTER;
        void** as = &NULL_POINTER;
        void** m = &NULL_POINTER;
        void** mc = &NULL_POINTER;
        void** ms = &NULL_POINTER;
        void** d = &NULL_POINTER;
        void** dc = &NULL_POINTER;
        void** ds = &NULL_POINTER;

        // The source part tag.
        void** ta = &NULL_POINTER;
        void** tac = &NULL_POINTER;
        void** tas = &NULL_POINTER;
        void** tm = &NULL_POINTER;
        void** tmc = &NULL_POINTER;
        void** tms = &NULL_POINTER;
        void** td = &NULL_POINTER;
        void** tdc = &NULL_POINTER;
        void** tds = &NULL_POINTER;

        // Get source part tag from details.
        get_universal_compound_element_by_name(p7, p8,
            (void*) WUI_TAG_NAME, (void*) WUI_TAG_NAME_COUNT,
            (void*) &ta, (void*) &tac, (void*) &tas,
            (void*) &tm, (void*) &tmc, (void*) &tms,
            (void*) &td, (void*) &tdc, (void*) &tds,
            p9, p10);

        // Serialise xhtml begin tag.
        serialise_xhtml_begin_tag(p0, p1, p2, *tm, *tmc, p7, p8, p9, p10);

        // The comparison result.
        int r = *NUMBER_0_INTEGER;

        compare_arrays(p3, p4, (void*) COMPOUND_ABSTRACTION, (void*) COMPOUND_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            // The part model is a compound.

            // The loop variable.
            int j = *NUMBER_0_INTEGER;

            // Iterate through compound parts.
            while (1) {

                if (j >= *sc) {

                    break;
                }

                // Get part at index j.
                get_compound_element_by_index(p5, p6, (void*) &j,
                    (void*) &a, (void*) &ac, (void*) &as,
                    (void*) &m, (void*) &mc, (void*) &ms,
                    (void*) &d, (void*) &dc, (void*) &ds);

                // Recursively call this operation for the part model.
                serialise_xhtml(p0, p1, p2, *a, *ac, *m, *mc, *d, *dc, p9, p10);

                // Reset source part abstraction, model, details.
                a = &NULL_POINTER;
                ac = &NULL_POINTER;
                as = &NULL_POINTER;
                m = &NULL_POINTER;
                mc = &NULL_POINTER;
                ms = &NULL_POINTER;
                d = &NULL_POINTER;
                dc = &NULL_POINTER;
                ds = &NULL_POINTER;

                // Increment loop count.
                j++;
            }
        }

        // Serialise line feed character, for better source reading.
        serialise_character_vector(p0, p1, p2, (void*) LINE_FEED_CONTROL_ASCII_CHARACTER, (void*) PRIMITIVE_COUNT);
        // Serialise less than character.
        serialise_character_vector(p0, p1, p2, (void*) LESS_THAN_SIGN_ASCII_CHARACTER, (void*) PRIMITIVE_COUNT);
        // Serialise solidus character.
        serialise_character_vector(p0, p1, p2, (void*) SOLIDUS_ASCII_CHARACTER, (void*) PRIMITIVE_COUNT);
        // Serialise xhtml tag.
        serialise_character_vector(p0, p1, p2, *tm, *tmc);
        // Serialise greater than character.
        serialise_character_vector(p0, p1, p2, (void*) GREATER_THAN_SIGN_ASCII_CHARACTER, (void*) PRIMITIVE_COUNT);
        // Serialise line feed character, for better source reading.
        serialise_character_vector(p0, p1, p2, (void*) LINE_FEED_CONTROL_ASCII_CHARACTER, (void*) PRIMITIVE_COUNT);

    } else {

        log_message_debug("Error: Could not serialise compound model into xhtml format. The source count parameter is null.");
    }
}

/* XHTML_CONVERTER_SOURCE */
#endif
