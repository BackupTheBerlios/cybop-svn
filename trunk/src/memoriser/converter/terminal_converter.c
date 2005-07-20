/*
 * $RCSfile: terminal_converter.c,v $
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
 * @version $Revision: 1.1 $ $Date: 2005-07-20 15:50:37 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef TERMINAL_CONVERTER_SOURCE
#define TERMINAL_CONVERTER_SOURCE

#include "../../globals/constants/log_constants.c"
#include "../../globals/constants/structure_constants.c"
#include "../../globals/logger/logger.c"

/**
 * Parses the byte stream and creates a terminal model from it.
 *
 * @param p0 the destination (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source
 * @param p4 the source count
 */
void parse_terminal(void* p0, void* p1, void* p2, const void* p3, const void* p4) {
}

/**
 * Serialises the terminal model and creates a byte stream from it.
 *
 * @param p0 the destination (Hand over as reference!) (the array with escape control sequences)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source (the compound model)
 * @param p4 the source count (the compound model parts count)
 */
void serialise_terminal(void* p0, void* p1, void* p2, const void* p3, const void* p4) {

    if (p4 != NULL_POINTER) {

        int* sc = (int*) p4;

        if (*dc >= 0) {

            log_message_debug("Serialise terminal.");

            // The loop count.
            int j = 0;

            while (1) {

                if (j >= *c) {

                    break;
                }

                // The part abstraction, model, details.
                void** a = POINTER_NULL_POINTER;
                void** ac = POINTER_NULL_POINTER;
                void** as = POINTER_NULL_POINTER;
                void** m = POINTER_NULL_POINTER;
                void** mc = POINTER_NULL_POINTER;
                void** ms = POINTER_NULL_POINTER;
                void** d = POINTER_NULL_POINTER;
                void** dc = POINTER_NULL_POINTER;
                void** ds = POINTER_NULL_POINTER;

                // Get part at index j.
                get_compound_element_by_index(p3, p4, (void*) &j,
                    (void*) a, (void*) ac, (void*) as
                    (void*) m, (void*) mc, (void*) ms
                    (void*) d, (void*) dc, (void*) ds);

                // The part position.
                void** pa = POINTER_NULL_POINTER;
                void** pac = POINTER_NULL_POINTER;
                void** pas = POINTER_NULL_POINTER;
                void** pm = POINTER_NULL_POINTER;
                void** pmc = POINTER_NULL_POINTER;
                void** pms = POINTER_NULL_POINTER;
                void** pd = POINTER_NULL_POINTER;
                void** pdc = POINTER_NULL_POINTER;
                void** pds = POINTER_NULL_POINTER;

                // Get part position from details.
                get_compound_element_by_index(*d, *dc, (void*) TUI_POSITION,
                    (void*) pa, (void*) pac, (void*) pas
                    (void*) pm, (void*) pmc, (void*) pms
                    (void*) pd, (void*) pdc, (void*) pds);

                // The part colour.
                void** ca = POINTER_NULL_POINTER;
                void** cac = POINTER_NULL_POINTER;
                void** cas = POINTER_NULL_POINTER;
                void** cm = POINTER_NULL_POINTER;
                void** cmc = POINTER_NULL_POINTER;
                void** cms = POINTER_NULL_POINTER;
                void** cd = POINTER_NULL_POINTER;
                void** cdc = POINTER_NULL_POINTER;
                void** cds = POINTER_NULL_POINTER;

                // Get part colour from details.
                get_compound_element_by_index(*d, *dc, (void*) TUI_COLOUR,
                    (void*) ca, (void*) cac, (void*) cas
                    (void*) cm, (void*) cmc, (void*) cms
                    (void*) cd, (void*) cdc, (void*) cds);

                // Check if destination array size is large enough.


                // Add corresponding escape control sequences.
                for all size length + height fill with colour

                if model's abstraction a equals string, then
                set foreground colour and print string into array

                // Recursively call this procedure for part model.
                serialise_terminal(p0, p1, p2, *m, *mc);

                j++;
            }

            // The new destination string size.
            // (Not exactly the size, but the destination string index
            // increased by the source array count.)
            *ds = *dc + *sc;

            // Resize destination string.
            resize_array(p0, p2, (void*) CHARACTER_ARRAY);

            if (*dc <= (*ds - *sc)) {

                // Set source into destination string.
                set_array_elements(*d, p1, p3, p4, (void*) CHARACTER_ARRAY);

                // Increment count.
                // Example:
                // d = "helloworld"
                // dc (as index) = 5
                // s = "universe"
                // sc = 8
                // d (after set) = "hellouniverse"
                // dc = dc + sc = 13
                *dc = *dc + *sc;

            } else {

                log_message_debug("Could not serialise terminal. The destination count exceeds the size.");
            }

        } else {

            log_message_debug("Could not serialise terminal. The destination count is negative.");
        }

    } else {

        log_message_debug("Could not serialise terminal. The source count is null.");
    }
}

/* TERMINAL_CONVERTER_SOURCE */
#endif
