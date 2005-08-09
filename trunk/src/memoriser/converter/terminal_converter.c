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
 * @version $Revision: 1.19 $ $Date: 2005-08-09 13:04:27 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef TERMINAL_CONVERTER_SOURCE
#define TERMINAL_CONVERTER_SOURCE

#include "../../globals/constants/abstraction_constants.c"
#include "../../globals/constants/boolean_constants.c"
#include "../../globals/constants/character_constants.c"
#include "../../globals/constants/control_sequence_constants.c"
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

                if (p13 != NULL_POINTER) {

                    if ((*dc + 100) >= *ds) {

                        // Set destination string size.
                        //?? TODO: Use different size here!
                        //?? Count ALL properties and add corresponding size!
                        *ds = *dc /*??* *STRING_REALLOCATE_FACTOR*/ + 100;

                        // Reallocate destination string.
                        reallocate_array(p0, p1, p2, (void*) CHARACTER_ARRAY);

                        //?? CAUTION! The reallocate procedure returns a different pointer!
                        //?? Assign it here again to *d??
                    }

/*??
    void* test = "\033[2JOn cleared screen,\
        print in \033[32mgreen colour\033[0m and then\
        \033[33myellow on \033[44mblue background\033[0m and try to\
        position \033[10;15H and finally write in \
        \033[1mbold and switch all \033[0m off.";
    int testc = strlen(test);
*/

                    // Position cursor.
                    // CAUTION! The top-left terminal corner is 1:1, but the given positions
                    // start counting from 0, so that 1 has to be added to all positions!
                    // Print to destination string d.
/*??
                    set_array_elements(*d, dc, (void*) ESCAPE_CONTROL_SEQUENCE, (void*) ESCAPE_CONTROL_SEQUENCE_COUNT, (void*) CHARACTER_ARRAY);
                    *dc = *dc + *ESCAPE_CONTROL_SEQUENCE_COUNT;
                    set_array_elements(*d, dc, (void*) ESCAPE_CONTROL_SEQUENCE, (void*) ESCAPE_CONTROL_SEQUENCE_COUNT, (void*) CHARACTER_ARRAY);
                    *dc = *dc + *ESCAPE_CONTROL_SEQUENCE_COUNT;
                    set_array_elements(*d, dc, (void*) SEMICOLON_CHARACTER, (void*) CHARACTER_COUNT, (void*) CHARACTER_ARRAY);
                    *dc = *dc + *CHARACTER_COUNT;
                    set_array_elements(*d, dc, (void*) ESCAPE_CONTROL_SEQUENCE, (void*) ESCAPE_CONTROL_SEQUENCE_COUNT, (void*) CHARACTER_ARRAY);
                    *dc = *dc + *ESCAPE_CONTROL_SEQUENCE_COUNT;
                    set_array_elements(*d, dc, (void*) LATIN_CAPITAL_LETTER_H_CHARACTER, (void*) CHARACTER_COUNT, (void*) CHARACTER_ARRAY);
                    *dc = *dc + *CHARACTER_COUNT;
                    %d;%dH", py + 1, px + 1
*/

                    // Add attribute off control sequence.
                    set_array_elements(*d, dc, (void*) ESCAPE_CONTROL_SEQUENCE, (void*) ESCAPE_CONTROL_SEQUENCE_COUNT, (void*) CHARACTER_ARRAY);
                    *dc = *dc + *ESCAPE_CONTROL_SEQUENCE_COUNT;
                    set_array_elements(*d, dc, (void*) ATTRIBUTE_OFF_CONTROL_SEQUENCE, (void*) ATTRIBUTE_OFF_CONTROL_SEQUENCE_COUNT, (void*) CHARACTER_ARRAY);
                    *dc = *dc + *ATTRIBUTE_OFF_CONTROL_SEQUENCE_COUNT;

/*??
                    // Add background property.
                    set_array_elements(*d, dc, (void*) ESCAPE_CONTROL_SEQUENCE, (void*) ESCAPE_CONTROL_SEQUENCE_COUNT, (void*) CHARACTER_ARRAY);
                    *dc = *dc + *ESCAPE_CONTROL_SEQUENCE_COUNT;
                    set_array_elements(*d, dc, p6, (void*) ATTRIBUTE_OFF_CONTROL_SEQUENCE_COUNT, (void*) CHARACTER_ARRAY);
                    *dc = *dc + *ATTRIBUTE_OFF_CONTROL_SEQUENCE_COUNT;

                    // Add foreground property.
                    set_array_elements(*d, dc, (void*) ESCAPE_CONTROL_SEQUENCE, (void*) ESCAPE_CONTROL_SEQUENCE_COUNT, (void*) CHARACTER_ARRAY);
                    *dc = *dc + *ESCAPE_CONTROL_SEQUENCE_COUNT;
                    set_array_elements(*d, dc, p7, (void*) ATTRIBUTE_OFF_CONTROL_SEQUENCE_COUNT, (void*) CHARACTER_ARRAY);
                    *dc = *dc + *ATTRIBUTE_OFF_CONTROL_SEQUENCE_COUNT;
*/

                    // The comparison result.
                    int r = 0;

                    // Compare hidden property.
                    compare_arrays(p8, (void*) PRIMITIVE_COUNT, (void*) TRUE_BOOLEAN, (void*) PRIMITIVE_COUNT, (void*) &r, (void*) INTEGER_ARRAY);

                    if (r != 0) {

                        // Set hidden property.
                        set_array_elements(*d, dc, (void*) ESCAPE_CONTROL_SEQUENCE, (void*) ESCAPE_CONTROL_SEQUENCE_COUNT, (void*) CHARACTER_ARRAY);
                        *dc = *dc + *ESCAPE_CONTROL_SEQUENCE_COUNT;
                        set_array_elements(*d, dc, (void*) HIDDEN_CONTROL_SEQUENCE, (void*) HIDDEN_CONTROL_SEQUENCE_COUNT, (void*) CHARACTER_ARRAY);
                        *dc = *dc + *HIDDEN_CONTROL_SEQUENCE_COUNT;
                    }

                    // Reset comparison result.
                    r = 0;

                    // Compare inverse property.
                    compare_arrays(p9, (void*) PRIMITIVE_COUNT, (void*) TRUE_BOOLEAN, (void*) PRIMITIVE_COUNT, (void*) &r, (void*) INTEGER_ARRAY);

                    if (r != 0) {

                        // Set inverse property.
                        set_array_elements(*d, dc, (void*) ESCAPE_CONTROL_SEQUENCE, (void*) ESCAPE_CONTROL_SEQUENCE_COUNT, (void*) CHARACTER_ARRAY);
                        *dc = *dc + *ESCAPE_CONTROL_SEQUENCE_COUNT;
                        set_array_elements(*d, dc, (void*) INVERSE_CONTROL_SEQUENCE, (void*) INVERSE_CONTROL_SEQUENCE_COUNT, (void*) CHARACTER_ARRAY);
                        *dc = *dc + *INVERSE_CONTROL_SEQUENCE_COUNT;
                    }

                    // Reset comparison result.
                    r = 0;

                    // Compare blink property.
                    compare_arrays(p10, (void*) PRIMITIVE_COUNT, (void*) TRUE_BOOLEAN, (void*) PRIMITIVE_COUNT, (void*) &r, (void*) INTEGER_ARRAY);

                    if (r != 0) {

                        // Set blink property.
                        set_array_elements(*d, dc, (void*) ESCAPE_CONTROL_SEQUENCE, (void*) ESCAPE_CONTROL_SEQUENCE_COUNT, (void*) CHARACTER_ARRAY);
                        *dc = *dc + *ESCAPE_CONTROL_SEQUENCE_COUNT;
                        set_array_elements(*d, dc, (void*) BLINK_CONTROL_SEQUENCE, (void*) BLINK_CONTROL_SEQUENCE_COUNT, (void*) CHARACTER_ARRAY);
                        *dc = *dc + *BLINK_CONTROL_SEQUENCE_COUNT;
                    }

                    // Reset comparison result.
                    r = 0;

                    // Compare underline property.
                    compare_arrays(p11, (void*) PRIMITIVE_COUNT, (void*) TRUE_BOOLEAN, (void*) PRIMITIVE_COUNT, (void*) &r, (void*) INTEGER_ARRAY);

                    if (r != 0) {

                        // Set underline property.
                        set_array_elements(*d, dc, (void*) ESCAPE_CONTROL_SEQUENCE, (void*) ESCAPE_CONTROL_SEQUENCE_COUNT, (void*) CHARACTER_ARRAY);
                        *dc = *dc + *ESCAPE_CONTROL_SEQUENCE_COUNT;
                        set_array_elements(*d, dc, (void*) UNDERLINE_CONTROL_SEQUENCE, (void*) UNDERLINE_CONTROL_SEQUENCE_COUNT, (void*) CHARACTER_ARRAY);
                        *dc = *dc + *UNDERLINE_CONTROL_SEQUENCE_COUNT;
                    }

                    // Reset comparison result.
                    r = 0;

                    // Compare bold property.
                    compare_arrays(p12, (void*) PRIMITIVE_COUNT, (void*) TRUE_BOOLEAN, (void*) PRIMITIVE_COUNT, (void*) &r, (void*) INTEGER_ARRAY);

                    if (r != 0) {

                        // Set bold property.
                        set_array_elements(*d, dc, (void*) ESCAPE_CONTROL_SEQUENCE, (void*) ESCAPE_CONTROL_SEQUENCE_COUNT, (void*) CHARACTER_ARRAY);
                        *dc = *dc + *ESCAPE_CONTROL_SEQUENCE_COUNT;
                        set_array_elements(*d, dc, (void*) BOLD_CONTROL_SEQUENCE, (void*) BOLD_CONTROL_SEQUENCE_COUNT, (void*) CHARACTER_ARRAY);
                        *dc = *dc + *BOLD_CONTROL_SEQUENCE_COUNT;
                    }

                    // Set character.
                    set_array_elements(*d, dc, p13, (void*) CHARACTER_COUNT, (void*) CHARACTER_ARRAY);
                    *dc = *dc + *CHARACTER_COUNT;

    printf("TEST properties p13: %i\n", p13);
    printf("TEST properties p13: %s\n", (char*) p13);
    printf("TEST properties *dc: %i\n", *dc);

                } else {

                    log_message_debug("WARNING: Could not serialise terminal properties. The character is null.");
                }

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

    log_message_debug("Serialise textual user interface into terminal control sequences.");

    // The source count z, y, x coordinates.
    int** scz = (int**) &NULL_POINTER;
    int** scy = (int**) &NULL_POINTER;
    int** scx = (int**) &NULL_POINTER;

    // Get source count z, y, x coordinates.
    get(p4, (void*) TUI_Z_DIMENSION_INDEX, (void*) &scz, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    get(p4, (void*) TUI_Y_DIMENSION_INDEX, (void*) &scy, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    get(p4, (void*) TUI_X_DIMENSION_INDEX, (void*) &scx, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

    // The loop counts.
    int z = 0;
    int y = 0;
    int x = 0;

    // The z, y, x models.
    void** zm = &NULL_POINTER;
    void** ym = &NULL_POINTER;
    void** xm = &NULL_POINTER;

    // The background property.
    void** bg = &NULL_POINTER;
    // The background property.
    void** fg = &NULL_POINTER;
    // The hidden property.
    void** h = &NULL_POINTER;
    // The inverse property.
    void** i = &NULL_POINTER;
    // The blink property.
    void** bl = &NULL_POINTER;
    // The underline property.
    void** u = &NULL_POINTER;
    // The bold property.
    void** b = &NULL_POINTER;
    // The character.
    void** c = &NULL_POINTER;

    // Reset z loop count.
    z = 0;

    while (1) {

    printf("TEST serialise z: %i\n", z);

        if (z >= **scz) {

            break;
        }

        // Reset z model.
        zm = &NULL_POINTER;

        // Get z dimension layer.
        get(p3, (void*) &z, (void*) &zm, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

        // Not existing layers are skipped.
        if (*zm != NULL_POINTER) {

            // Reset y loop count.
            y = 0;

            while (1) {

    printf("TEST serialise y: %i\n", y);

                if (y >= **scy) {

                    break;
                }

                // Reset y model.
                ym = &NULL_POINTER;

                // Get y dimension row.
                get(*zm, (void*) &y, (void*) &ym, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

                // Not existing rows are skipped.
                if (*ym != NULL_POINTER) {

                    // Reset x loop count.
                    x = 0;

                    while (1) {

    printf("TEST serialise x: %i\n", x);

                        if (x >= **scx) {

                            break;
                        }

                        // Reset x model.
                        xm = &NULL_POINTER;

                        // Get x dimension column.
                        get(*ym, (void*) &x, (void*) &xm, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

                        // Not existing columns (characters) are skipped.
                        if (*xm != NULL_POINTER) {

                            // Get properties and the character itself.
                            get(*xm, (void*) TUI_PROPERTIES_BACKGROUND_INDEX, (void*) &bg, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
                            get(*xm, (void*) TUI_PROPERTIES_FOREGROUND_INDEX, (void*) &fg, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
                            get(*xm, (void*) TUI_PROPERTIES_HIDDEN_INDEX, (void*) &h, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
                            get(*xm, (void*) TUI_PROPERTIES_INVERSE_INDEX, (void*) &i, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
                            get(*xm, (void*) TUI_PROPERTIES_BLINK_INDEX, (void*) &bl, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
                            get(*xm, (void*) TUI_PROPERTIES_UNDERLINE_INDEX, (void*) &u, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
                            get(*xm, (void*) TUI_PROPERTIES_BOLD_INDEX, (void*) &b, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
                            get(*xm, (void*) TUI_PROPERTIES_CHARACTER_INDEX, (void*) &c, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

                            serialise_terminal_properties(p0, p1, p2,
                                (void*) &z, (void*) &y, (void*) &x,
                                *bg, *fg, *h, *i, *bl, *u, *b, *c);

                        } else {

                            log_message_debug("WARNING: Could not serialise terminal. The x column (character) is null.");
                        }

                        x++;
                    }

                } else {

                    log_message_debug("WARNING: Could not serialise terminal. The y row is null.");
                }

                y++;
            }

        } else {

            log_message_debug("WARNING: Could not serialise terminal. The z layer is null.");
        }

        z++;
    }
}

/* TERMINAL_CONVERTER_SOURCE */
#endif
