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
 * @version $Revision: 1.2 $ $Date: 2005-07-21 08:02:08 $ $Author: christian $
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
 * @param p0 the destination compound model (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source array with escape control sequences
 * @param p4 the source count
 */
void parse_terminal(void* p0, void* p1, void* p2, const void* p3, const void* p4) {
}

/**
 * Serialises the terminal model and creates a byte stream from it.
 *
 * @param p0 the destination array with escape control sequences (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source compound model
 * @param p4 the source count
 */
void serialise_terminal(void* p0, void* p1, void* p2, const void* p3, const void* p4) {

    if (p4 != NULL_POINTER) {

        int* sc = (int*) p4;

        log_message_debug("Serialise terminal.");

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

        // The part size.
        void** sa = POINTER_NULL_POINTER;
        void** sac = POINTER_NULL_POINTER;
        void** sas = POINTER_NULL_POINTER;
        void** sm = POINTER_NULL_POINTER;
        void** smc = POINTER_NULL_POINTER;
        void** sms = POINTER_NULL_POINTER;
        void** sd = POINTER_NULL_POINTER;
        void** sdc = POINTER_NULL_POINTER;
        void** sds = POINTER_NULL_POINTER;

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

        // The part position x, y, z.
        int px = -1;
        int py = -1;
        int pz = -1;
        // The part size x, y, z.
        int sx = -1;
        int sy = -1;
        int sz = -1;
        // The part colour.
        void* c = NULL_POINTER;

        // The loop count.
        int j = 0;
        // The x loop count.
        int x = 0;
        // The y loop count.
        int y = 0;
        // The z loop count.
        int z = 0;

        while (1) {

            if (j >= *c) {

                break;
            }

            // Get part at index j.
            get_compound_element_by_index(p3, p4, (void*) &j,
                (void*) a, (void*) ac, (void*) as
                (void*) m, (void*) mc, (void*) ms
                (void*) d, (void*) dc, (void*) ds);

            // Get part position from details.
            get_compound_element_by_index(*d, *dc, (void*) TUI_POSITION,
                (void*) pa, (void*) pac, (void*) pas
                (void*) pm, (void*) pmc, (void*) pms
                (void*) pd, (void*) pdc, (void*) pds);

            // Get part size from details.
            get_compound_element_by_index(*d, *dc, (void*) TUI_POSITION,
                (void*) sa, (void*) sac, (void*) sas
                (void*) sm, (void*) smc, (void*) sms
                (void*) sd, (void*) sdc, (void*) sds);

            // Get part colour from details.
            get_compound_element_by_index(*d, *dc, (void*) TUI_COLOUR,
                (void*) ca, (void*) cac, (void*) cas
                (void*) cm, (void*) cmc, (void*) cms
                (void*) cd, (void*) cdc, (void*) cds);

            // Get part position x, y, z.
            get_integer_array_elements(*pm, (void*) ONE_INTEGER, (void*) &px);
            get_integer_array_elements(*pm, (void*) TWO_INTEGER, (void*) &py);
            get_integer_array_elements(*pm, (void*) THREE_INTEGER, (void*) &pz);
            // Get part size x, y, z.
            get_integer_array_elements(*sm, (void*) ONE_INTEGER, (void*) &sx);
            get_integer_array_elements(*sm, (void*) TWO_INTEGER, (void*) &sy);
            get_integer_array_elements(*sm, (void*) THREE_INTEGER, (void*) &sz);

            // Get part colour as escape control sequence.
            get_integer_array_elements(*cm, (void*) ONE_INTEGER, (void*) &c);

            // Position cursor.
            printf("\033[%d;%dH", py, px);

            // Reset z loop index to first position.
            z = 1;

            // Add corresponding escape control sequences.
            while (1) {

                if (z >= sz) {

                    break;
                }

                // Reset y loop index to first position.
                y = 1;

                while (1) {

                    if (y >= sy) {

                        break;
                    }

                    // Reset x loop index to first position.
                    x = 1;

                    while (1) {

                        if (x >= sx) {

                            break;
                        }

                        printf("\033[32m");

                        x++;
                    }

                    y++;
                }

                z++;
            }

            // Check if destination array size is large enough.

            printf("\033[2J");
            fputs("Set colour to \033[32mgreen\033[0m.\n", (FILE*) *d);

            for all size length + height fill with colour

            if model's abstraction a equals string, then
            set foreground colour and print string into array

            // Recursively call this procedure for part model.
            serialise_terminal(p0, p1, p2, *m, *mc);

            j++;
        }

        if (*dc >= 0) {

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
