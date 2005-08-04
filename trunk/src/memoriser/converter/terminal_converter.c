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
 * @version $Revision: 1.15 $ $Date: 2005-08-04 15:20:58 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef TERMINAL_CONVERTER_SOURCE
#define TERMINAL_CONVERTER_SOURCE

#include "../../globals/constants/abstraction_constants.c"
#include "../../globals/constants/log_constants.c"
#include "../../globals/constants/structure_constants.c"
#include "../../globals/logger/logger.c"
#include "../../memoriser/accessor.c"

/**
 * Serialises the tui model properties into a terminal model.
 *
 * @param p0 the destination terminal control sequences (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source tui model z coordinate
 * @param p4 the source tui model y coordinate
 * @param p5 the source tui model x coordinate
 * @param p6 the source tui model background property
 * @param p7 the source tui model foreground property
 * @param p8 the source tui model hidden property
 * @param p9 the source tui model inverse property
 * @param p10 the source tui model blink property
 * @param p11 the source tui model underline property
 * @param p12 the source tui model bold property
 * @param p13 the source tui model character property
 */
void serialise_terminal_properties(void* p0, void* p1, void* p2,
    void* p3, void* p4, void* p5,
    void* p6, void* p7, void* p8, void* p9,
    void* p10, void* p11, void* p12, void* p13) {

    if (p2 != NULL_POINTER) {

        int* ds = (int*) p2;

        if (p1 != NULL_POINTER) {

            int* dc = (int*) p1;

            if (p0 != NULL_POINTER) {

                void** d = (void**) p0;

    sprintf(*d, "TEST serialise 1: %s\n", *d);

                //?? TEST only!
                *dc = 100;
                *ds = 100;

                reallocate_array(p0, p1, p2, (void*) CHARACTER_ARRAY);

                //?? CAUTION! The reallocate procedure returns a different pointer!
                //?? Assign it here again to *d??

    sprintf(*d, "TEST serialise 2: %s\n", *d);

                set(*d, dc, (void*) "Hallo, dies ist ein Test fuer Res Medicinae!", (void*) STRING_ABSTRACTION, (void*) STRING_ABSTRACTION_COUNT);

    sprintf(*d, "TEST serialise 3: %s\n", *d);

/*??
                // Calculate new destination string count.
                *dc = *dc + *ESCAPE_CONTROL_SEQUENCE_COUNT;
                // Calculate new destination string size.
                *ds = *ds + *ESCAPE_CONTROL_SEQUENCE_COUNT;

                reallocate_array((void*) &d, (void*) dc, (void*) ds, (void*) CHARACTER_ARRAY);

                set(*d, dc, (void*) ESCAPE_CONTROL_SEQUENCE, (void*) STRING_ABSTRACTION, (void*) STRING_ABSTRACTION_COUNT);

                // Set terminated part colour control sequence by first copying the
                // actual control sequence and then adding the null termination character.
                set_array_elements(tcs, (void*) NUMBER_0_INTEGER, (void*) &cs, (void*) &csc, (void*) CHARACTER_ARRAY);
                set_array_elements(tcs, (void*) &csc, (void*) NULL_CONTROL_CHARACTER, (void*) NULL_CONTROL_CHARACTER_COUNT, (void*) CHARACTER_ARRAY);

                // Position cursor.
                // CAUTION! The top-left terminal corner is 1:1, but the given positions
                // start counting from 0, so that 1 has to be added to all positions.
                // Print to destination string d.
                sprintf(*d, "\033[%d;%dH", py + 1, px + 1);
                // Clear screen.
                sprintf(*d, "\033[2J");
                sprintf(*d, "Set colour to \033[32mgreen\033[0m.\n");
*/

            } else {

                log_message_debug("Could not serialise terminal properties. The destination is null.");
            }

        } else {

            log_message_debug("Could not serialise terminal properties. The destination count is null.");
        }

    } else {

        log_message_debug("Could not serialise terminal properties. The destination size is null.");
    }
}

/**
 * Parses the terminal model into a tui model.
 *
 * @param p0 the destination tui model (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source terminal control sequences
 * @param p4 the source count
 */
void parse_terminal(void* p0, void* p1, void* p2, void* p3, void* p4) {
}

/**
 * Serialises the tui model into a terminal model.
 *
 * @param p0 the destination terminal control sequences (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source tui model
 * @param p4 the source count
 */
void serialise_terminal(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p4 != NULL_POINTER) {

        void** sc = (void**) p4;

        log_message_debug("Serialise textual user interface into terminal control sequences.");

        // The source count z, y, x coordinates.
        int* scz = NULL_POINTER;
        int* scy = NULL_POINTER;
        int* scx = NULL_POINTER;

        // Get source count z, y, x coordinates.
        get(*sc, (void*) TUI_Z_DIMENSION_INDEX, (void*) &scz, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
        get(*sc, (void*) TUI_Y_DIMENSION_INDEX, (void*) &scy, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
        get(*sc, (void*) TUI_X_DIMENSION_INDEX, (void*) &scx, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);

        // The loop counts.
        int z = 0;
        int y = 0;
        int x = 0;

        // The z, y, x models.
        void* zm = NULL_POINTER;
        void** zmp = &zm;
        void* ym = NULL_POINTER;
        void** ymp = &ym;
        void* xm = NULL_POINTER;
        void** xmp = &xm;

        // The background property.
        int bg = -1;
        // The background property.
        int fg = -1;
        // The hidden property.
        int h = -1;
        // The inverse property.
        int i = -1;
        // The blink property.
        int bl = -1;
        // The underline property.
        int u = -1;
        // The bold property.
        int b = -1;
        // The character.
        int c = -1;

        // Reset z loop count.
        z = 0;

        while (1) {

            if (z >= *scz) {

                break;
            }

            // Get z dimension layer.
            get(p3, (void*) &z, &zmp, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

            // Reset y loop count.
            y = 0;

            while (1) {

                if (y >= *scy) {

                    break;
                }

                // Get y dimension row.
                get(zm, (void*) &y, &ymp, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

                // Reset x loop count.
                x = 0;

                while (1) {

                    if (x >= *scx) {

                        break;
                    }

                    // Get x dimension column.
                    get(ym, (void*) &x, &xmp, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

                    // Get properties and the character itself.
                    get(xm, (void*) TUI_PROPERTIES_BACKGROUND_INDEX, (void*) &bg, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
                    get(xm, (void*) TUI_PROPERTIES_FOREGROUND_INDEX, (void*) &fg, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
                    get(xm, (void*) TUI_PROPERTIES_HIDDEN_INDEX, (void*) &h, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
                    get(xm, (void*) TUI_PROPERTIES_INVERSE_INDEX, (void*) &i, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
                    get(xm, (void*) TUI_PROPERTIES_BLINK_INDEX, (void*) &bl, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
                    get(xm, (void*) TUI_PROPERTIES_UNDERLINE_INDEX, (void*) &u, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
                    get(xm, (void*) TUI_PROPERTIES_BOLD_INDEX, (void*) &b, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
                    get(xm, (void*) TUI_PROPERTIES_CHARACTER_INDEX, (void*) &c, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

                    serialise_terminal_properties(p0, p1, p2,
                        (void*) &z, (void*) &y, (void*) &x,
                        (void*) &bg, (void*) &fg, (void*) &h, (void*) &i,
                        (void*) &bl, (void*) &u, (void*) &b, (void*) &c);

                    x++;
                }

                y++;
            }

            z++;
        }

    } else {

        log_message_debug("Could not serialise terminal. The source count is null.");
    }
}

/* TERMINAL_CONVERTER_SOURCE */
#endif
