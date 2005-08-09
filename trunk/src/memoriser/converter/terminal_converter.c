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
 * @version $Revision: 1.20 $ $Date: 2005-08-09 21:31:28 $ $Author: christian $
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

    if (p5 != NULL_POINTER) {

        int* sx = (int*) p5;

        if (p4 != NULL_POINTER) {

            int* sy = (int*) p4;

            if (p2 != NULL_POINTER) {

                int* ds = (int*) p2;

                if (p1 != NULL_POINTER) {

                    int* dc = (int*) p1;

                    if (p0 != NULL_POINTER) {

                        void** d = (void**) p0;

                        if (p13 != NULL_POINTER) {

                            //
                            // The *CHARACTER_VECTOR_REALLOCATE_FACTOR is not necessary
                            // to calculate the new character array size.
                            // However, it is useful to faster increase the character
                            // array size, thus avoiding steady reallocation.
                            //

                            // CAUTION! The top-left terminal corner is 1:1, but the given positions
                            // start counting from 0, so that 1 has to be added to all positions!
                            // Therefore, the coordinates handed over need to be corrected.

                            // The corrected y.
                            int cy = *sy + *NUMBER_1_INTEGER;
                            // The corrected x.
                            int cx = *sx + *NUMBER_1_INTEGER;
                            // The y coordinate.
                            void* y = NULL_POINTER;
                            int yc = 0;
                            int ys = 0;
                            // The x coordinate.
                            void* x = NULL_POINTER;
                            int xc = 0;
                            int xs = 0;
                            // The background colour.
                            void* b = NULL_POINTER;
                            int bc = 0;
                            int bs = 0;
                            // The foreground colour.
                            void* f = NULL_POINTER;
                            int fc = 0;
                            int fs = 0;

                            //
                            // Position cursor.
                            //
                            // Example:
                            // printf("\033[%d;%dH", y_row, x_column)
                            //

                            serialise_integer((void*) &y, (void*) &yc, (void*) &ys, (void*) &cy, (void*) PRIMITIVE_COUNT);
                            serialise_integer((void*) &x, (void*) &xc, (void*) &xs, (void*) &cx, (void*) PRIMITIVE_COUNT);

                            if ((*dc + *ESCAPE_CONTROL_SEQUENCE_COUNT
                                + yc + *CHARACTER_COUNT
                                + xc + *CHARACTER_COUNT) >= *ds) {

                                // Set destination character array size.
                                // CAUTION! Add constant in case *dc is zero!
                                *ds = *dc * *CHARACTER_VECTOR_REALLOCATE_FACTOR
                                    + *ESCAPE_CONTROL_SEQUENCE_COUNT
                                    + yc + *CHARACTER_COUNT
                                    + xc + *CHARACTER_COUNT;

                                // Reallocate destination character array.
                                reallocate_array(p0, p1, p2, (void*) CHARACTER_ARRAY);
                            }

                            set_array_elements(*d, p1, (void*) ESCAPE_CONTROL_SEQUENCE, (void*) ESCAPE_CONTROL_SEQUENCE_COUNT, (void*) CHARACTER_ARRAY);
                            *dc = *dc + *ESCAPE_CONTROL_SEQUENCE_COUNT;
                            set_array_elements(*d, p1, y, (void*) &yc, (void*) CHARACTER_ARRAY);
                            *dc = *dc + yc;
                            set_array_elements(*d, p1, (void*) SEMICOLON_CHARACTER, (void*) CHARACTER_COUNT, (void*) CHARACTER_ARRAY);
                            *dc = *dc + *CHARACTER_COUNT;
                            set_array_elements(*d, p1, x, (void*) &xc, (void*) CHARACTER_ARRAY);
                            *dc = *dc + xc;
                            set_array_elements(*d, p1, (void*) LATIN_CAPITAL_LETTER_H_CHARACTER, (void*) CHARACTER_COUNT, (void*) CHARACTER_ARRAY);
                            *dc = *dc + *CHARACTER_COUNT;

                            // Add attribute off control sequence.
                            if ((*dc + *ESCAPE_CONTROL_SEQUENCE_COUNT + *ATTRIBUTE_OFF_CONTROL_SEQUENCE_COUNT) >= *ds) {

                                // Set destination character array size.
                                // CAUTION! Add constant in case *dc is zero!
                                *ds = *dc * *CHARACTER_VECTOR_REALLOCATE_FACTOR + *ESCAPE_CONTROL_SEQUENCE_COUNT + *ATTRIBUTE_OFF_CONTROL_SEQUENCE_COUNT;

                                // Reallocate destination character array.
                                reallocate_array(p0, p1, p2, (void*) CHARACTER_ARRAY);
                            }

                            set_array_elements(*d, p1, (void*) ESCAPE_CONTROL_SEQUENCE, (void*) ESCAPE_CONTROL_SEQUENCE_COUNT, (void*) CHARACTER_ARRAY);
                            *dc = *dc + *ESCAPE_CONTROL_SEQUENCE_COUNT;
                            set_array_elements(*d, p1, (void*) ATTRIBUTE_OFF_CONTROL_SEQUENCE, (void*) ATTRIBUTE_OFF_CONTROL_SEQUENCE_COUNT, (void*) CHARACTER_ARRAY);
                            *dc = *dc + *ATTRIBUTE_OFF_CONTROL_SEQUENCE_COUNT;

                            //
                            // Add background and foreground properties.
                            //
                            // Example:
                            // printf("\033[32mgreen colour\033[0mswitched off.")
                            //

                            // Serialise background colour integer into character array.
                            serialise_integer((void*) &b, (void*) &bc, (void*) &bs, p6, (void*) PRIMITIVE_COUNT);
                            // Serialise foreground colour integer into character array.
                            serialise_integer((void*) &f, (void*) &fc, (void*) &fs, p7, (void*) PRIMITIVE_COUNT);

                            if ((*dc
                                + *ESCAPE_CONTROL_SEQUENCE_COUNT + bc + *ATTRIBUTE_SUFFIX_CONTROL_SEQUENCE_COUNT
                                + *ESCAPE_CONTROL_SEQUENCE_COUNT + fc + *ATTRIBUTE_SUFFIX_CONTROL_SEQUENCE_COUNT) >= *ds) {

                                // Set destination character array size.
                                // CAUTION! Add constant in case *dc is zero!
                                *ds = *dc * *CHARACTER_VECTOR_REALLOCATE_FACTOR
                                    + *ESCAPE_CONTROL_SEQUENCE_COUNT + bc + *ATTRIBUTE_SUFFIX_CONTROL_SEQUENCE_COUNT
                                    + *ESCAPE_CONTROL_SEQUENCE_COUNT + fc + *ATTRIBUTE_SUFFIX_CONTROL_SEQUENCE_COUNT;

                                // Reallocate destination character array.
                                reallocate_array(p0, p1, p2, (void*) CHARACTER_ARRAY);
                            }

                            set_array_elements(*d, p1, (void*) ESCAPE_CONTROL_SEQUENCE, (void*) ESCAPE_CONTROL_SEQUENCE_COUNT, (void*) CHARACTER_ARRAY);
                            *dc = *dc + *ESCAPE_CONTROL_SEQUENCE_COUNT;
                            set_array_elements(*d, p1, b, (void*) &bc, (void*) CHARACTER_ARRAY);
                            *dc = *dc + bc;
                            set_array_elements(*d, p1, (void*) ATTRIBUTE_SUFFIX_CONTROL_SEQUENCE, (void*) ATTRIBUTE_SUFFIX_CONTROL_SEQUENCE_COUNT, (void*) CHARACTER_ARRAY);
                            *dc = *dc + *ATTRIBUTE_SUFFIX_CONTROL_SEQUENCE_COUNT;
                            set_array_elements(*d, p1, (void*) ESCAPE_CONTROL_SEQUENCE, (void*) ESCAPE_CONTROL_SEQUENCE_COUNT, (void*) CHARACTER_ARRAY);
                            *dc = *dc + *ESCAPE_CONTROL_SEQUENCE_COUNT;
                            set_array_elements(*d, p1, f, (void*) &fc, (void*) CHARACTER_ARRAY);
                            *dc = *dc + fc;
                            set_array_elements(*d, p1, (void*) ATTRIBUTE_SUFFIX_CONTROL_SEQUENCE, (void*) ATTRIBUTE_SUFFIX_CONTROL_SEQUENCE_COUNT, (void*) CHARACTER_ARRAY);
                            *dc = *dc + *ATTRIBUTE_SUFFIX_CONTROL_SEQUENCE_COUNT;

                            //
                            // Set character properties.
                            //
                            // Example:
                            // printf("\033[1mbold \033[0mswitched off.")
                            //

                            // Reallocate array to have capacity for all of the
                            // following properties, even if some of them are not used.
                            if ((*dc + *ESCAPE_CONTROL_SEQUENCE_COUNT + *ATTRIBUTE_OFF_CONTROL_SEQUENCE_COUNT
                                + *ESCAPE_CONTROL_SEQUENCE_COUNT + *HIDDEN_CONTROL_SEQUENCE_COUNT
                                + *ESCAPE_CONTROL_SEQUENCE_COUNT + *INVERSE_CONTROL_SEQUENCE_COUNT
                                + *ESCAPE_CONTROL_SEQUENCE_COUNT + *BLINK_CONTROL_SEQUENCE_COUNT
                                + *ESCAPE_CONTROL_SEQUENCE_COUNT + *UNDERLINE_CONTROL_SEQUENCE_COUNT
                                + *ESCAPE_CONTROL_SEQUENCE_COUNT + *BOLD_CONTROL_SEQUENCE_COUNT
                                + *CHARACTER_COUNT) >= *ds) {

                                // Set destination character array size.
                                // CAUTION! Add constant in case *dc is zero!
                                *ds = *dc * *CHARACTER_VECTOR_REALLOCATE_FACTOR
                                    + *ESCAPE_CONTROL_SEQUENCE_COUNT + *HIDDEN_CONTROL_SEQUENCE_COUNT
                                    + *ESCAPE_CONTROL_SEQUENCE_COUNT + *INVERSE_CONTROL_SEQUENCE_COUNT
                                    + *ESCAPE_CONTROL_SEQUENCE_COUNT + *BLINK_CONTROL_SEQUENCE_COUNT
                                    + *ESCAPE_CONTROL_SEQUENCE_COUNT + *UNDERLINE_CONTROL_SEQUENCE_COUNT
                                    + *ESCAPE_CONTROL_SEQUENCE_COUNT + *BOLD_CONTROL_SEQUENCE_COUNT
                                    + *CHARACTER_COUNT;

                                // Reallocate destination character array.
                                reallocate_array(p0, p1, p2, (void*) CHARACTER_ARRAY);
                            }

                            // The comparison result.
                            int r = 0;

                            // Compare hidden property.
                            compare_arrays(p8, (void*) PRIMITIVE_COUNT, (void*) TRUE_BOOLEAN, (void*) PRIMITIVE_COUNT, (void*) &r, (void*) INTEGER_ARRAY);

                            if (r != 0) {

                                // Set hidden property.
                                set_array_elements(*d, p1, (void*) ESCAPE_CONTROL_SEQUENCE, (void*) ESCAPE_CONTROL_SEQUENCE_COUNT, (void*) CHARACTER_ARRAY);
                                *dc = *dc + *ESCAPE_CONTROL_SEQUENCE_COUNT;
                                set_array_elements(*d, p1, (void*) HIDDEN_CONTROL_SEQUENCE, (void*) HIDDEN_CONTROL_SEQUENCE_COUNT, (void*) CHARACTER_ARRAY);
                                *dc = *dc + *HIDDEN_CONTROL_SEQUENCE_COUNT;
                            }

                            // Reset comparison result.
                            r = 0;

                            // Compare inverse property.
                            compare_arrays(p9, (void*) PRIMITIVE_COUNT, (void*) TRUE_BOOLEAN, (void*) PRIMITIVE_COUNT, (void*) &r, (void*) INTEGER_ARRAY);

                            if (r != 0) {

                                // Set inverse property.
                                set_array_elements(*d, p1, (void*) ESCAPE_CONTROL_SEQUENCE, (void*) ESCAPE_CONTROL_SEQUENCE_COUNT, (void*) CHARACTER_ARRAY);
                                *dc = *dc + *ESCAPE_CONTROL_SEQUENCE_COUNT;
                                set_array_elements(*d, p1, (void*) INVERSE_CONTROL_SEQUENCE, (void*) INVERSE_CONTROL_SEQUENCE_COUNT, (void*) CHARACTER_ARRAY);
                                *dc = *dc + *INVERSE_CONTROL_SEQUENCE_COUNT;
                            }

                            // Reset comparison result.
                            r = 0;

                            // Compare blink property.
                            compare_arrays(p10, (void*) PRIMITIVE_COUNT, (void*) TRUE_BOOLEAN, (void*) PRIMITIVE_COUNT, (void*) &r, (void*) INTEGER_ARRAY);

                            if (r != 0) {

                                // Set blink property.
                                set_array_elements(*d, p1, (void*) ESCAPE_CONTROL_SEQUENCE, (void*) ESCAPE_CONTROL_SEQUENCE_COUNT, (void*) CHARACTER_ARRAY);
                                *dc = *dc + *ESCAPE_CONTROL_SEQUENCE_COUNT;
                                set_array_elements(*d, p1, (void*) BLINK_CONTROL_SEQUENCE, (void*) BLINK_CONTROL_SEQUENCE_COUNT, (void*) CHARACTER_ARRAY);
                                *dc = *dc + *BLINK_CONTROL_SEQUENCE_COUNT;
                            }

                            // Reset comparison result.
                            r = 0;

                            // Compare underline property.
                            compare_arrays(p11, (void*) PRIMITIVE_COUNT, (void*) TRUE_BOOLEAN, (void*) PRIMITIVE_COUNT, (void*) &r, (void*) INTEGER_ARRAY);

                            if (r != 0) {

                                // Set underline property.
                                set_array_elements(*d, p1, (void*) ESCAPE_CONTROL_SEQUENCE, (void*) ESCAPE_CONTROL_SEQUENCE_COUNT, (void*) CHARACTER_ARRAY);
                                *dc = *dc + *ESCAPE_CONTROL_SEQUENCE_COUNT;
                                set_array_elements(*d, p1, (void*) UNDERLINE_CONTROL_SEQUENCE, (void*) UNDERLINE_CONTROL_SEQUENCE_COUNT, (void*) CHARACTER_ARRAY);
                                *dc = *dc + *UNDERLINE_CONTROL_SEQUENCE_COUNT;
                            }

                            // Reset comparison result.
                            r = 0;

                            // Compare bold property.
                            compare_arrays(p12, (void*) PRIMITIVE_COUNT, (void*) TRUE_BOOLEAN, (void*) PRIMITIVE_COUNT, (void*) &r, (void*) INTEGER_ARRAY);

                            if (r != 0) {

                                // Set bold property.
                                set_array_elements(*d, p1, (void*) ESCAPE_CONTROL_SEQUENCE, (void*) ESCAPE_CONTROL_SEQUENCE_COUNT, (void*) CHARACTER_ARRAY);
                                *dc = *dc + *ESCAPE_CONTROL_SEQUENCE_COUNT;
                                set_array_elements(*d, p1, (void*) BOLD_CONTROL_SEQUENCE, (void*) BOLD_CONTROL_SEQUENCE_COUNT, (void*) CHARACTER_ARRAY);
                                *dc = *dc + *BOLD_CONTROL_SEQUENCE_COUNT;
                            }

                            // Set character.
                            set_array_elements(*d, p1, p13, (void*) CHARACTER_COUNT, (void*) CHARACTER_ARRAY);
                            *dc = *dc + *CHARACTER_COUNT;

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

        } else {

            log_message_debug("Could not serialise terminal properties. The source y is null.");
        }

    } else {

        log_message_debug("Could not serialise terminal properties. The source x is null.");
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
