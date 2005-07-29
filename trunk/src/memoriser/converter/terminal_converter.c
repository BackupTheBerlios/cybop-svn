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
 * @version $Revision: 1.9 $ $Date: 2005-07-29 15:48:51 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef TERMINAL_CONVERTER_SOURCE
#define TERMINAL_CONVERTER_SOURCE

#include "../../globals/constants/log_constants.c"
//?? #include "../../globals/constants/structure_constants.c"
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
void parse_terminal(void* p0, void* p1, void* p2, void* p3, void* p4) {
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
void serialise_terminal(void* p0, void* p1, void* p2, void* p3, void* p4) {

/*??
    if (p4 != NULL_POINTER) {

        int* sc = (int*) p4;

        if (p2 != NULL_POINTER) {

            int* des = (int*) p2;

            if (p1 != NULL_POINTER) {

                int* dec = (int*) p1;

                if (p0 != NULL_POINTER) {

                    void** de = (void**) p0;

        log_message_debug("Serialise terminal.");

        // The part abstraction, model, details.
        void** a = NULL_POINTER;
        void** ac = NULL_POINTER;
        void** as = NULL_POINTER;
        void** m = NULL_POINTER;
        void** mc = NULL_POINTER;
        void** ms = NULL_POINTER;
        void** d = NULL_POINTER;
        void** dc = NULL_POINTER;
        void** ds = NULL_POINTER;

        // The part position.
        void** pa = NULL_POINTER;
        void** pac = NULL_POINTER;
        void** pas = NULL_POINTER;
        void** pm = NULL_POINTER;
        void** pmc = NULL_POINTER;
        void** pms = NULL_POINTER;
        void** pd = NULL_POINTER;
        void** pdc = NULL_POINTER;
        void** pds = NULL_POINTER;

        // The part size.
        void** sa = NULL_POINTER;
        void** sac = NULL_POINTER;
        void** sas = NULL_POINTER;
        void** sm = NULL_POINTER;
        void** smc = NULL_POINTER;
        void** sms = NULL_POINTER;
        void** sd = NULL_POINTER;
        void** sdc = NULL_POINTER;
        void** sds = NULL_POINTER;

        // The part colour.
        void** ca = NULL_POINTER;
        void** cac = NULL_POINTER;
        void** cas = NULL_POINTER;
        void** cm = NULL_POINTER;
        void** cmc = NULL_POINTER;
        void** cms = NULL_POINTER;
        void** cd = NULL_POINTER;
        void** cdc = NULL_POINTER;
        void** cds = NULL_POINTER;

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

        // The comparison result.
        int r = 0;

        // The x, y, z loop counts.
        int x = 0;
        int y = 0;
        int z = 0;

        // The part colour control sequence.
        char* cs = NULL_POINTER;
        int csc = 0;
        int css = 0;

        // The terminated part colour control sequence.
        char* tcs = NULL_POINTER;
        int tcsc = 0;
        int tcss = 0;

        // The part model string.
        char* s = NULL_POINTER;

        while (1) {

            if (j >= *sc) {

                break;
            }

            // Get part at index j.
            get_compound_element_by_index(p3, p4, (void*) &j,
                (void*) a, (void*) ac, (void*) as,
                (void*) m, (void*) mc, (void*) ms,
                (void*) d, (void*) dc, (void*) ds);

            // Reset comparison result.
            r = 0;

            compare_arrays(*a, *ac, (void*) STRING_ABSTRACTION, (void*) STRING_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

            // Get part position from details.
            get_compound_element_by_index(*d, *dc, (void*) TUI_POSITION,
                (void*) pa, (void*) pac, (void*) pas
                (void*) pm, (void*) pmc, (void*) pms
                (void*) pd, (void*) pdc, (void*) pds);

            // Get part size from details.
            get_compound_element_by_index(*d, *dc, (void*) TUI_SIZE,
                (void*) sa, (void*) sac, (void*) sas
                (void*) sm, (void*) smc, (void*) sms
                (void*) sd, (void*) sdc, (void*) sds);

            // Get part colour from details.
            get_compound_element_by_index(*d, *dc, (void*) TUI_COLOUR,
                (void*) ca, (void*) cac, (void*) cas
                (void*) cm, (void*) cmc, (void*) cms
                (void*) cd, (void*) cdc, (void*) cds);

            // Get part position x, y, z.
            get_integer_array_elements(*pm, (void*) NUMBER_1_INTEGER, (void*) &px);
            get_integer_array_elements(*pm, (void*) NUMBER_2_INTEGER, (void*) &py);
            get_integer_array_elements(*pm, (void*) THREE_INTEGER, (void*) &pz);

            // Get part size x, y, z.
            get_integer_array_elements(*sm, (void*) NUMBER_1_INTEGER, (void*) &sx);
            get_integer_array_elements(*sm, (void*) NUMBER_2_INTEGER, (void*) &sy);
            get_integer_array_elements(*sm, (void*) THREE_INTEGER, (void*) &sz);

            if (r == 0) {

            // Determine part colour control sequence.
            get_control_sequence((void*) &cs, (void*) &csc, (void*) &css, *cm, *cmc);

            // Reset terminated part colour control sequence.
            tcs = NULL_POINTER;
            // Set terminated part colour control sequence size.
            tcss = csc + 1;

            // Create terminated part colour control sequence.
            allocate_array((void*) &tcs, (void*) &tcss, (void*) CHARACTER_ARRAY);

            // Set terminated part colour control sequence by first copying the
            // actual control sequence and then adding the null termination character.
            set_array_elements(tcs, (void*) NUMBER_0_INTEGER, (void*) &cs, (void*) &csc, (void*) CHARACTER_ARRAY);
            set_array_elements(tcs, (void*) &csc, (void*) NULL_CONTROL_CHARACTER, (void*) NULL_CONTROL_CHARACTER_COUNT, (void*) CHARACTER_ARRAY);

            // Position cursor.
            // CAUTION! The top-left terminal corner is 1:1, but the given positions
            // start counting from 0, so that 1 has to be added to all positions.
            printf("\033[%d;%dH", py + 1, px + 1);

            // Print colour.
            sprintf(*d, tcs);

            // Reset z loop index to first position.
            z = 0;

            // Add corresponding escape control sequences.
            while (1) {

                if (z >= sz) {

                    break;
                }

                // Reset y loop index to first position.
                y = 0;

                while (1) {

                    if (y >= sy) {

                        break;
                    }

                    // Reset x loop index to first position.
                    x = 0;

                    while (1) {

                        if (x >= sx) {

                            break;
                        }

                        if (r == 0) {

                            // Print space.
                            sprintf(*d, SPACE_CHARACTER);

                        } else {

                            // Get part string with just one character at position y.
                            get_character_array_elements(string, (void*) &y, (void*) &s);

                            // Print string.
                            sprintf(*d, s);
                        }

                        x++;
                    }

                    y++;
                }

                z++;
            }

            // Destroy terminated part colour control sequence.
            deallocate_array((void*) &tcs, (void*) &tcss, (void*) CHARACTER_ARRAY);

            // Check if destination array size is large enough.

            printf("\033[2J");
            fputs("Set colour to \033[32mgreen\033[0m.\n", (FILE*) *d);

            if model's abstraction a equals string, then
            set foreground colour and print string into array

            // Reset comparison result.
            r = 0;

            compare_arrays(*a, *ac, (void*) COMPOUND_ABSTRACTION, (void*) COMPOUND_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

            if (r != 0) {

                // Recursively call this procedure for compound part model.
                serialise_terminal(p0, p1, p2, *m, *mc);
            }

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
*/
}

/* TERMINAL_CONVERTER_SOURCE */
#endif
