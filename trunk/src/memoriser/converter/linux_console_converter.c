/*
 * $RCSfile: linux_console_converter.c,v $
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
 * @version $Revision: 1.8 $ $Date: 2006-02-09 02:22:59 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef LINUX_CONSOLE_CONVERTER_SOURCE
#define LINUX_CONSOLE_CONVERTER_SOURCE

#include "../../globals/constants/abstraction_constants.c"
#include "../../globals/constants/boolean_constants.c"
#include "../../globals/constants/character_constants.c"
#include "../../globals/constants/control_sequence_constants.c"
#include "../../globals/constants/log_constants.c"
#include "../../globals/constants/model_constants.c"
#include "../../globals/constants/name_constants.c"
#include "../../globals/constants/structure_constants.c"
#include "../../globals/logger/logger.c"
#include "../../globals/variables/variables.c"
#include "../../memoriser/accessor.c"
#include "../../memoriser/mapper.c"

/**
 * Serialises a linux console character.
 *
 * @param p0 the destination terminal control sequences (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the x coordinate
 * @param p4 the y coordinate
 * @param p5 the z coordinate
 * @param p6 the background property
 * @param p7 the background property count
 * @param p8 the foreground property
 * @param p9 the foreground property count
 * @param p10 the hidden property
 * @param p11 the inverse property
 * @param p12 the blink property
 * @param p13 the underline property
 * @param p14 the bold property
 * @param p15 the character property
 */
void serialise_linux_console_character(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5,
    void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14, void* p15) {

    if (p9 != NULL_POINTER) {

        int* fc = (int*) p9;

        if (p7 != NULL_POINTER) {

            int* bc = (int*) p7;

            if (p4 != NULL_POINTER) {

                int* sy = (int*) p4;

                if (p3 != NULL_POINTER) {

                    int* sx = (int*) p3;

                    if (p2 != NULL_POINTER) {

                        int* ds = (int*) p2;

                        if (p1 != NULL_POINTER) {

                            int* dc = (int*) p1;

                            if (p0 != NULL_POINTER) {

                                void** d = (void**) p0;

                                if (p15 != NULL_POINTER) {

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
//??                                    void* b = NULL_POINTER;
//??                                    int bc = 0;
//??                                    int bs = 0;
                                    // The foreground colour.
//??                                    void* f = NULL_POINTER;
//??                                    int fc = 0;
//??                                    int fs = 0;

                                    //
                                    // Position cursor.
                                    //
                                    // Example:
                                    // printf("\033[%d;%dH", y_row, x_column)
                                    //

                                    serialise_integer_wide((void*) &y, (void*) &yc, (void*) &ys, (void*) &cy, (void*) PRIMITIVE_COUNT);
                                    serialise_integer_wide((void*) &x, (void*) &xc, (void*) &xs, (void*) &cx, (void*) PRIMITIVE_COUNT);

                                    if ((*dc + *ESCAPE_CONTROL_SEQUENCE_COUNT
                                        + yc + *PRIMITIVE_COUNT
                                        + xc + *PRIMITIVE_COUNT) >= *ds) {

                                        // Set destination character array size.
                                        // CAUTION! Add constant in case *dc is zero!
                                        *ds = *dc * *WIDE_CHARACTER_VECTOR_REALLOCATE_FACTOR
                                            + *ESCAPE_CONTROL_SEQUENCE_COUNT
                                            + yc + *PRIMITIVE_COUNT
                                            + xc + *PRIMITIVE_COUNT;

                                        // Reallocate destination character array.
                                        reallocate_array(p0, p1, p2, (void*) WIDE_CHARACTER_ARRAY);
                                    }

                                    set_array_elements(*d, p1, (void*) ESCAPE_CONTROL_SEQUENCE, (void*) ESCAPE_CONTROL_SEQUENCE_COUNT, (void*) WIDE_CHARACTER_ARRAY);
                                    *dc = *dc + *ESCAPE_CONTROL_SEQUENCE_COUNT;
                                    set_array_elements(*d, p1, y, (void*) &yc, (void*) WIDE_CHARACTER_ARRAY);
                                    *dc = *dc + yc;
                                    set_array_elements(*d, p1, (void*) SEMICOLON_CHARACTER, (void*) PRIMITIVE_COUNT, (void*) WIDE_CHARACTER_ARRAY);
                                    *dc = *dc + *PRIMITIVE_COUNT;
                                    set_array_elements(*d, p1, x, (void*) &xc, (void*) WIDE_CHARACTER_ARRAY);
                                    *dc = *dc + xc;
                                    set_array_elements(*d, p1, (void*) LATIN_CAPITAL_LETTER_H_CHARACTER, (void*) PRIMITIVE_COUNT, (void*) WIDE_CHARACTER_ARRAY);
                                    *dc = *dc + *PRIMITIVE_COUNT;

                                    // Add attribute off control sequence.
                                    if ((*dc + *ESCAPE_CONTROL_SEQUENCE_COUNT + *ATTRIBUTE_OFF_CONTROL_SEQUENCE_COUNT) >= *ds) {

                                        // Set destination character array size.
                                        // CAUTION! Add constant in case *dc is zero!
                                        *ds = *dc * *WIDE_CHARACTER_VECTOR_REALLOCATE_FACTOR + *ESCAPE_CONTROL_SEQUENCE_COUNT + *ATTRIBUTE_OFF_CONTROL_SEQUENCE_COUNT;

                                        // Reallocate destination character array.
                                        reallocate_array(p0, p1, p2, (void*) WIDE_CHARACTER_ARRAY);
                                    }

                                    set_array_elements(*d, p1, (void*) ESCAPE_CONTROL_SEQUENCE, (void*) ESCAPE_CONTROL_SEQUENCE_COUNT, (void*) WIDE_CHARACTER_ARRAY);
                                    *dc = *dc + *ESCAPE_CONTROL_SEQUENCE_COUNT;
                                    set_array_elements(*d, p1, (void*) ATTRIBUTE_OFF_CONTROL_SEQUENCE, (void*) ATTRIBUTE_OFF_CONTROL_SEQUENCE_COUNT, (void*) WIDE_CHARACTER_ARRAY);
                                    *dc = *dc + *ATTRIBUTE_OFF_CONTROL_SEQUENCE_COUNT;

                                    //
                                    // Add background and foreground properties.
                                    //
                                    // Example:
                                    // printf("\033[32mgreen colour\033[0mswitched off.")
                                    //

                                    // Serialise background colour integer into character array.
        //??                            serialise_integer_wide((void*) &b, (void*) &bc, (void*) &bs, p6, (void*) PRIMITIVE_COUNT);
                                    // Serialise foreground colour integer into character array.
        //??                            serialise_integer_wide((void*) &f, (void*) &fc, (void*) &fs, p7, (void*) PRIMITIVE_COUNT);

                                    if ((*dc
                                        + *ESCAPE_CONTROL_SEQUENCE_COUNT + *bc + *ATTRIBUTE_SUFFIX_CONTROL_SEQUENCE_COUNT
                                        + *ESCAPE_CONTROL_SEQUENCE_COUNT + *fc + *ATTRIBUTE_SUFFIX_CONTROL_SEQUENCE_COUNT) >= *ds) {

                                        // Set destination character array size.
                                        // CAUTION! Add constant in case *dc is zero!
                                        *ds = *dc * *WIDE_CHARACTER_VECTOR_REALLOCATE_FACTOR
                                            + *ESCAPE_CONTROL_SEQUENCE_COUNT + *bc + *ATTRIBUTE_SUFFIX_CONTROL_SEQUENCE_COUNT
                                            + *ESCAPE_CONTROL_SEQUENCE_COUNT + *fc + *ATTRIBUTE_SUFFIX_CONTROL_SEQUENCE_COUNT;

                                        // Reallocate destination character array.
                                        reallocate_array(p0, p1, p2, (void*) WIDE_CHARACTER_ARRAY);
                                    }

                                    set_array_elements(*d, p1, (void*) ESCAPE_CONTROL_SEQUENCE, (void*) ESCAPE_CONTROL_SEQUENCE_COUNT, (void*) WIDE_CHARACTER_ARRAY);
                                    *dc = *dc + *ESCAPE_CONTROL_SEQUENCE_COUNT;
                                    set_array_elements(*d, p1, p6, p7, (void*) WIDE_CHARACTER_ARRAY);
                                    *dc = *dc + *bc;
                                    set_array_elements(*d, p1, (void*) ATTRIBUTE_SUFFIX_CONTROL_SEQUENCE, (void*) ATTRIBUTE_SUFFIX_CONTROL_SEQUENCE_COUNT, (void*) WIDE_CHARACTER_ARRAY);
                                    *dc = *dc + *ATTRIBUTE_SUFFIX_CONTROL_SEQUENCE_COUNT;
                                    set_array_elements(*d, p1, (void*) ESCAPE_CONTROL_SEQUENCE, (void*) ESCAPE_CONTROL_SEQUENCE_COUNT, (void*) WIDE_CHARACTER_ARRAY);
                                    *dc = *dc + *ESCAPE_CONTROL_SEQUENCE_COUNT;
                                    set_array_elements(*d, p1, p8, p9, (void*) WIDE_CHARACTER_ARRAY);
                                    *dc = *dc + *fc;
                                    set_array_elements(*d, p1, (void*) ATTRIBUTE_SUFFIX_CONTROL_SEQUENCE, (void*) ATTRIBUTE_SUFFIX_CONTROL_SEQUENCE_COUNT, (void*) WIDE_CHARACTER_ARRAY);
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
                                        + *PRIMITIVE_COUNT) >= *ds) {

                                        // Set destination character array size.
                                        // CAUTION! Add constant in case *dc is zero!
                                        *ds = *dc * *WIDE_CHARACTER_VECTOR_REALLOCATE_FACTOR
                                            + *ESCAPE_CONTROL_SEQUENCE_COUNT + *HIDDEN_CONTROL_SEQUENCE_COUNT
                                            + *ESCAPE_CONTROL_SEQUENCE_COUNT + *INVERSE_CONTROL_SEQUENCE_COUNT
                                            + *ESCAPE_CONTROL_SEQUENCE_COUNT + *BLINK_CONTROL_SEQUENCE_COUNT
                                            + *ESCAPE_CONTROL_SEQUENCE_COUNT + *UNDERLINE_CONTROL_SEQUENCE_COUNT
                                            + *ESCAPE_CONTROL_SEQUENCE_COUNT + *BOLD_CONTROL_SEQUENCE_COUNT
                                            + *PRIMITIVE_COUNT;

                                        // Reallocate destination character array.
                                        reallocate_array(p0, p1, p2, (void*) WIDE_CHARACTER_ARRAY);
                                    }

                                    // The comparison result.
                                    int r = 0;

                                    // Compare hidden property.
                                    compare_arrays(p10, (void*) PRIMITIVE_COUNT, (void*) TRUE_BOOLEAN, (void*) PRIMITIVE_COUNT, (void*) &r, (void*) INTEGER_ARRAY);

                                    if (r != 0) {

                                        // Set hidden property.
                                        set_array_elements(*d, p1, (void*) ESCAPE_CONTROL_SEQUENCE, (void*) ESCAPE_CONTROL_SEQUENCE_COUNT, (void*) WIDE_CHARACTER_ARRAY);
                                        *dc = *dc + *ESCAPE_CONTROL_SEQUENCE_COUNT;
                                        set_array_elements(*d, p1, (void*) HIDDEN_CONTROL_SEQUENCE, (void*) HIDDEN_CONTROL_SEQUENCE_COUNT, (void*) WIDE_CHARACTER_ARRAY);
                                        *dc = *dc + *HIDDEN_CONTROL_SEQUENCE_COUNT;
                                    }

                                    // Reset comparison result.
                                    r = 0;

                                    // Compare inverse property.
                                    compare_arrays(p11, (void*) PRIMITIVE_COUNT, (void*) TRUE_BOOLEAN, (void*) PRIMITIVE_COUNT, (void*) &r, (void*) INTEGER_ARRAY);

                                    if (r != 0) {

                                        // Set inverse property.
                                        set_array_elements(*d, p1, (void*) ESCAPE_CONTROL_SEQUENCE, (void*) ESCAPE_CONTROL_SEQUENCE_COUNT, (void*) WIDE_CHARACTER_ARRAY);
                                        *dc = *dc + *ESCAPE_CONTROL_SEQUENCE_COUNT;
                                        set_array_elements(*d, p1, (void*) INVERSE_CONTROL_SEQUENCE, (void*) INVERSE_CONTROL_SEQUENCE_COUNT, (void*) WIDE_CHARACTER_ARRAY);
                                        *dc = *dc + *INVERSE_CONTROL_SEQUENCE_COUNT;
                                    }

                                    // Reset comparison result.
                                    r = 0;

                                    // Compare blink property.
                                    compare_arrays(p12, (void*) PRIMITIVE_COUNT, (void*) TRUE_BOOLEAN, (void*) PRIMITIVE_COUNT, (void*) &r, (void*) INTEGER_ARRAY);

                                    if (r != 0) {

                                        // Set blink property.
                                        set_array_elements(*d, p1, (void*) ESCAPE_CONTROL_SEQUENCE, (void*) ESCAPE_CONTROL_SEQUENCE_COUNT, (void*) WIDE_CHARACTER_ARRAY);
                                        *dc = *dc + *ESCAPE_CONTROL_SEQUENCE_COUNT;
                                        set_array_elements(*d, p1, (void*) BLINK_CONTROL_SEQUENCE, (void*) BLINK_CONTROL_SEQUENCE_COUNT, (void*) WIDE_CHARACTER_ARRAY);
                                        *dc = *dc + *BLINK_CONTROL_SEQUENCE_COUNT;
                                    }

                                    // Reset comparison result.
                                    r = 0;

                                    // Compare underline property.
                                    compare_arrays(p13, (void*) PRIMITIVE_COUNT, (void*) TRUE_BOOLEAN, (void*) PRIMITIVE_COUNT, (void*) &r, (void*) INTEGER_ARRAY);

                                    if (r != 0) {

                                        // Set underline property.
                                        set_array_elements(*d, p1, (void*) ESCAPE_CONTROL_SEQUENCE, (void*) ESCAPE_CONTROL_SEQUENCE_COUNT, (void*) WIDE_CHARACTER_ARRAY);
                                        *dc = *dc + *ESCAPE_CONTROL_SEQUENCE_COUNT;
                                        set_array_elements(*d, p1, (void*) UNDERLINE_CONTROL_SEQUENCE, (void*) UNDERLINE_CONTROL_SEQUENCE_COUNT, (void*) WIDE_CHARACTER_ARRAY);
                                        *dc = *dc + *UNDERLINE_CONTROL_SEQUENCE_COUNT;
                                    }

                                    // Reset comparison result.
                                    r = 0;

                                    // Compare bold property.
                                    compare_arrays(p14, (void*) PRIMITIVE_COUNT, (void*) TRUE_BOOLEAN, (void*) PRIMITIVE_COUNT, (void*) &r, (void*) INTEGER_ARRAY);

                                    if (r != 0) {

                                        // Set bold property.
                                        set_array_elements(*d, p1, (void*) ESCAPE_CONTROL_SEQUENCE, (void*) ESCAPE_CONTROL_SEQUENCE_COUNT, (void*) WIDE_CHARACTER_ARRAY);
                                        *dc = *dc + *ESCAPE_CONTROL_SEQUENCE_COUNT;
                                        set_array_elements(*d, p1, (void*) BOLD_CONTROL_SEQUENCE, (void*) BOLD_CONTROL_SEQUENCE_COUNT, (void*) WIDE_CHARACTER_ARRAY);
                                        *dc = *dc + *BOLD_CONTROL_SEQUENCE_COUNT;
                                    }

                                    // Set character.
                                    set_array_elements(*d, p1, p15, (void*) PRIMITIVE_COUNT, (void*) WIDE_CHARACTER_ARRAY);
                                    *dc = *dc + *PRIMITIVE_COUNT;

                                } else {

                                    log_message_debug("WARNING: Could not serialise linux console properties. The character is null.");
                                }

                            } else {

                                log_message_debug("Could not serialise linux console properties. The destination is null.");
                            }

                        } else {

                            log_message_debug("Could not serialise linux console properties. The destination count is null.");
                        }

                    } else {

                        log_message_debug("Could not serialise linux console properties. The destination size is null.");
                    }

                } else {

                    log_message_debug("Could not serialise linux console properties. The source y is null.");
                }

            } else {

                log_message_debug("Could not serialise linux console properties. The source x is null.");
            }

        } else {

            log_message_debug("Could not serialise linux console properties. The background count is null.");
        }

    } else {

        log_message_debug("Could not serialise linux console properties. The foreground count is null.");
    }
}

/**
 * Serialises a linux console rectangle border.
 *
 * @param p0 the horizontal character
 * @param p1 the vertical character
 * @param p2 the left top
 * @param p3 the right top
 * @param p4 the left bottom
 * @param p5 the right bottom
 * @param p6 the border
 * @param p7 the border count
 */
void serialise_linux_console_rectangle_border(void* p0, void* p1,
    void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    if (p5 != NULL_POINTER) {

        wchar_t* rbc = (wchar_t*) p5;

        if (p4 != NULL_POINTER) {

            wchar_t* lbc = (wchar_t*) p4;

            if (p3 != NULL_POINTER) {

                wchar_t* rtc = (wchar_t*) p3;

                if (p2 != NULL_POINTER) {

                    wchar_t* ltc = (wchar_t*) p2;

                    if (p1 != NULL_POINTER) {

                        wchar_t* vc = (wchar_t*) p1;

                        if (p0 != NULL_POINTER) {

                            wchar_t* hc = (wchar_t*) p0;

                            // The comparison result.
                            int r = 0;

                            if (r == 0) {

                                compare_arrays(p6, p7, (void*) TUI_LINE_BORDER_MODEL, (void*) TUI_LINE_BORDER_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                                if (r != 0) {

                                    *hc = *BOX_DRAWINGS_LIGHT_HORIZONTAL_CHARACTER;
                                    *vc = *BOX_DRAWINGS_LIGHT_VERTICAL_CHARACTER;
                                    *ltc = *BOX_DRAWINGS_LIGHT_UP_AND_RIGHT_CHARACTER;
                                    *rtc = *BOX_DRAWINGS_LIGHT_UP_AND_LEFT_CHARACTER;
                                    *lbc = *BOX_DRAWINGS_LIGHT_DOWN_AND_RIGHT_CHARACTER;
                                    *rbc = *BOX_DRAWINGS_LIGHT_DOWN_AND_LEFT_CHARACTER;
                                }
                            }

                            if (r == 0) {

                                compare_arrays(p6, p7, (void*) TUI_ROUND_LINE_BORDER_MODEL, (void*) TUI_ROUND_LINE_BORDER_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                                if (r != 0) {

                                    *hc = *BOX_DRAWINGS_LIGHT_HORIZONTAL_CHARACTER;
                                    *vc = *BOX_DRAWINGS_LIGHT_VERTICAL_CHARACTER;
                                    *ltc = *BOX_DRAWINGS_LIGHT_ARC_UP_AND_RIGHT_CHARACTER;
                                    *rtc = *BOX_DRAWINGS_LIGHT_ARC_UP_AND_LEFT_CHARACTER;
                                    *lbc = *BOX_DRAWINGS_LIGHT_ARC_DOWN_AND_RIGHT_CHARACTER;
                                    *rbc = *BOX_DRAWINGS_LIGHT_ARC_DOWN_AND_LEFT_CHARACTER;
                                }
                            }

                            if (r == 0) {

                                compare_arrays(p6, p7, (void*) TUI_DOUBLE_LINE_BORDER_MODEL, (void*) TUI_DOUBLE_LINE_BORDER_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                                if (r != 0) {

                                    *hc = *BOX_DRAWINGS_DOUBLE_HORIZONTAL_CHARACTER;
                                    *vc = *BOX_DRAWINGS_DOUBLE_VERTICAL_CHARACTER;
                                    *ltc = *BOX_DRAWINGS_DOUBLE_UP_AND_RIGHT_CHARACTER;
                                    *rtc = *BOX_DRAWINGS_DOUBLE_UP_AND_LEFT_CHARACTER;
                                    *lbc = *BOX_DRAWINGS_DOUBLE_DOWN_AND_RIGHT_CHARACTER;
                                    *rbc = *BOX_DRAWINGS_DOUBLE_DOWN_AND_LEFT_CHARACTER;
                                }
                            }

                        } else {

                            log_message_debug("Could not serialise linux console rectangle border. The horizontal character is null.");
                        }

                    } else {

                        log_message_debug("Could not serialise linux console rectangle border. The vertical character is null.");
                    }

                } else {

                    log_message_debug("Could not serialise linux console rectangle border. The left top character is null.");
                }

            } else {

                log_message_debug("Could not serialise linux console rectangle border. The right top character is null.");
            }

        } else {

            log_message_debug("Could not serialise linux console rectangle border. The left bottom character is null.");
        }

    } else {

        log_message_debug("Could not serialise linux console rectangle border. The right bottom character is null.");
    }
}

/**
 * Serialises a linux console rectangle.
 *
 * @param p0 the destination terminal control sequences (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the character
 * @param p4 the character count
 * @param p5 the hidden property
 * @param p6 the inverse property
 * @param p7 the blink property
 * @param p8 the underline property
 * @param p9 the bold property
 * @param p10 the background
 * @param p11 the background count
 * @param p12 the foreground
 * @param p13 the foreground count
 * @param p14 the position x coordinate
 * @param p15 the position y coordinate
 * @param p16 the position z coordinate
 * @param p17 the size x coordinate
 * @param p18 the size y coordinate
 * @param p19 the size z coordinate
 * @param p20 the border
 * @param p21 the border count
 */
void serialise_linux_console_rectangle(void* p0, void* p1, void* p2, void* p3, void* p4,
    void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13,
    void* p14, void* p15, void* p16, void* p17, void* p18, void* p19, void* p20, void* p21) {

    if (p19 != NULL_POINTER) {

        int* sz = (int*) p19;

        if (p18 != NULL_POINTER) {

            int* sy = (int*) p18;

            if (p17 != NULL_POINTER) {

                int* sx = (int*) p17;

                if (p16 != NULL_POINTER) {

                    int* pz = (int*) p16;

                    if (p15 != NULL_POINTER) {

                        int* py = (int*) p15;

                        if (p14 != NULL_POINTER) {

                            int* px = (int*) p14;

                            int* cc = (int*) p4;

                            // The horizontal character.
                            wchar_t hc = *SPACE_CHARACTER;
                            // The vertical character.
                            wchar_t vc = *SPACE_CHARACTER;
                            // The left top character.
                            wchar_t ltc = *SPACE_CHARACTER;
                            // The right top character.
                            wchar_t rtc = *SPACE_CHARACTER;
                            // The left bottom character.
                            wchar_t lbc = *SPACE_CHARACTER;
                            // The right bottom character.
                            wchar_t rbc = *SPACE_CHARACTER;

                            // Determine border characters.
                            serialise_linux_console_rectangle_border((void*) &hc, (void*) &vc,
                                (void*) &ltc, (void*) &rtc, (void*) &lbc, (void*) &rbc, p20, p21);

                            // The z loop count.
                            int z = *pz;
                            // The y loop count.
                            int y = *py;
                            // The x loop count.
                            int x = *px;
                            // The z loop limit as sum of position and size.
                            int zl = *pz + *sz;
                            // The y loop limit as sum of position and size.
                            int yl = *py + *sy;
                            // The x loop limit as sum of position and size.
                            int xl = *px + *sx;

                            // The character index.
                            int ci = 0;
                            // The character.
                            wchar_t* c = SPACE_CHARACTER;

                            while (1) {

                                if (z >= zl) {

                                    break;
                                }

                                while (1) {

                                    if (y >= yl) {

                                        break;
                                    }

                                    while (1) {

                                        if (x >= xl) {

                                            break;
                                        }

                                        if (p20 == NULL_POINTER) {

                                            // A border is NOT given.

                                            if (cc != NULL_POINTER) {

                                                // Calculate character index.
                                                ci = x - *px;

                                                if (ci < *cc) {

                                                    // Get character value at position x.
                                                    get(p3, (void*) &ci, (void*) &c, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION_COUNT);
                                                }

                                                // Serialise character using escape codes.
                                                serialise_linux_console_character(p0, p1, p2, &x, &y, &z,
                                                    p10, p11, p12, p13, p5, p6, p7, p8, p9, c);

                                            } else {

                                                log_message_debug("Could not serialise linux console rectangle. The character count is null.");
                                            }

                                        } else {

                                            // A border IS given.

                                            if (y == *py) {

                                                if (x == *px) {

                                                    // Serialise left top border character using escape codes.
                                                    serialise_linux_console_character(p0, p1, p2, &x, &y, &z,
                                                        p10, p11, p12, p13, p5, p6, p7, p8, p9, &ltc);

                                                } else if (x == (xl - 1)) {

                                                    // Serialise right top border character using escape codes.
                                                    serialise_linux_console_character(p0, p1, p2, &x, &y, &z,
                                                        p10, p11, p12, p13, p5, p6, p7, p8, p9, &rtc);

                                                } else {

                                                    // Serialise horizontal border character using escape codes.
                                                    serialise_linux_console_character(p0, p1, p2, &x, &y, &z,
                                                        p10, p11, p12, p13, p5, p6, p7, p8, p9, &hc);
                                                }

                                            } else if (y == (yl - 1)) {

                                                if (x == *px) {

                                                    // Serialise left bottom border character using escape codes.
                                                    serialise_linux_console_character(p0, p1, p2, &x, &y, &z,
                                                        p10, p11, p12, p13, p5, p6, p7, p8, p9, &lbc);

                                                } else if (x == (xl - 1)) {

                                                    // Serialise right bottom border character using escape codes.
                                                    serialise_linux_console_character(p0, p1, p2, &x, &y, &z,
                                                        p10, p11, p12, p13, p5, p6, p7, p8, p9, &rbc);

                                                } else {

                                                    // Serialise horizontal border character using escape codes.
                                                    serialise_linux_console_character(p0, p1, p2, &x, &y, &z,
                                                        p10, p11, p12, p13, p5, p6, p7, p8, p9, &hc);
                                                }

                                            } else {

                                                if (x == *px) {

                                                    // Serialise left bottom border character using escape codes.
                                                    serialise_linux_console_character(p0, p1, p2, &x, &y, &z,
                                                        p10, p11, p12, p13, p5, p6, p7, p8, p9, &vc);

                                                } else if (x == (xl - 1)) {

                                                    // Serialise right bottom border character using escape codes.
                                                    serialise_linux_console_character(p0, p1, p2, &x, &y, &z,
                                                        p10, p11, p12, p13, p5, p6, p7, p8, p9, &vc);

                                                } else {

                                                    if (cc != NULL_POINTER) {

                                                        // Calculate character index.
                                                        // CAUTION! Subtract one because of the border.
                                                        ci = x - *px - 1;

                                                        if (ci < *cc) {

                                                            // Get character value at position x.
                                                            get(p3, (void*) &ci, (void*) &c, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION_COUNT);
                                                        }

                                                    } else {

                                                        log_message_debug("Could not serialise linux console rectangle. The character count is null.");
                                                    }

                                                    // Serialise character using escape codes.
                                                    serialise_linux_console_character(p0, p1, p2, &x, &y, &z,
                                                        p10, p11, p12, p13, p5, p6, p7, p8, p9, c);
                                                }
                                            }
                                        }

                                        // The character index ci does not have to be reset,
                                        // as it is always calculated before getting a character.

                                        // Reset character.
                                        c = SPACE_CHARACTER;

                                        x++;
                                    }

                                    // Reset x loop count.
                                    x = *px;

                                    y++;
                                }

                                // Reset y loop count.
                                y = *py;

                                z++;
                            }

                        } else {

                            log_message_debug("Could not serialise user interface rectangle. The character count is null.");
                        }

                    } else {

                        log_message_debug("Could not serialise user interface rectangle. The character count is null.");
                    }

                } else {

                    log_message_debug("Could not serialise user interface rectangle. The character count is null.");
                }

            } else {

                log_message_debug("Could not serialise user interface rectangle. The character count is null.");
            }

        } else {

            log_message_debug("Could not serialise user interface rectangle. The character count is null.");
        }

    } else {

        log_message_debug("Could not serialise user interface rectangle. The character count is null.");
    }
}

/**
 * Serialises a linux console rectangle coordinates layout.
 *
 * @param p0 the cell position x (of the part)
 * @param p1 the cell position y
 * @param p2 the cell position z
 * @param p3 the cell size x (of the part)
 * @param p4 the cell size y
 * @param p5 the cell size z
 * @param p6 the original area position x (of the whole)
 * @param p7 the original area position y
 * @param p8 the original area position z
 * @param p9 the original area size x (of the whole)
 * @param p10 the original area size y
 * @param p11 the original area size z
 */
void serialise_linux_console_rectangle_coordinates_layout(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5,
    void* p6, void* p7, void* p8, void* p9, void* p10, void* p11) {

    int* cpx = (int*) p0;
    int* cpy = (int*) p1;
    int* cpz = (int*) p2;
    int* oapx = (int*) p6;
    int* oapy = (int*) p7;
    int* oapz = (int*) p8;

    // Set cell coordinates.
    *cpx = *oapx + *cpx;
    *cpy = *oapy + *cpy;
    *cpz = *oapz + *cpz;
}

/**
 * Serialises a linux console rectangle compass layout.
 *
 * @param p0 the cell position x (of the part)
 * @param p1 the cell position y
 * @param p2 the cell position z
 * @param p3 the cell size x (of the part)
 * @param p4 the cell size y
 * @param p5 the cell size z
 * @param p6 the free area position x (remaining space within the whole)
 * @param p7 the free area position y
 * @param p8 the free area position z
 * @param p9 the free area size x (remaining space within the whole)
 * @param p10 the free area size y
 * @param p11 the free area size z
 * @param p12 the layout cell
 * @param p13 the layout cell count
 */
void serialise_linux_console_rectangle_compass_layout(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5,
    void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13) {

    int* cpx = (int*) p0;
    int* cpy = (int*) p1;
    int* cpz = (int*) p2;
    int* csx = (int*) p3;
    int* csy = (int*) p4;
    int* csz = (int*) p5;
    int* fapx = (int*) p6;
    int* fapy = (int*) p7;
    int* fapz = (int*) p8;
    int* fasx = (int*) p9;
    int* fasy = (int*) p10;
    int* fasz = (int*) p11;

    // The comparison result.
    int r = 0;

    if (r == 0) {

        compare_arrays(p12, p13, (void*) UI_NORTH_CELL_MODEL, (void*) UI_NORTH_CELL_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            // Set cell coordinates.
            *cpx = *fapx;
            *cpy = *fapy;
            *cpz = *fapz;
            *csx = *fasx;
//??            *csy = 20;
            *csz = *fasz;
            // Set free area coordinates.
            *fapy = *fapy + *csy;
            *fasy = *fasy - *csy;
        }
    }

    if (r == 0) {

        compare_arrays(p12, p13, (void*) UI_SOUTH_CELL_MODEL, (void*) UI_SOUTH_CELL_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            // Set cell coordinates.
            *cpx = *fapx;
            *cpy = *fapy + (*fasy - *csy);
            *cpz = *fapz;
            *csx = *fasx;
//??            *csy = 20;
            *csz = *fasz;
            // Set free area coordinates.
            *fasy = *fasy - *csy;
        }
    }

    if (r == 0) {

        compare_arrays(p12, p13, (void*) UI_WEST_CELL_MODEL, (void*) UI_WEST_CELL_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            // Set cell coordinates.
            *cpx = *fapx;
            *cpy = *fapy;
            *cpz = *fapz;
//??            *csx = 20;
            *csy = *fasy;
            *csz = *fasz;
            // Set free area coordinates.
            *fapx = *fapx + *csx;
            *fasx = *fasx - *csx;
        }
    }

    if (r == 0) {

        compare_arrays(p12, p13, (void*) UI_EAST_CELL_MODEL, (void*) UI_EAST_CELL_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            // Set cell coordinates.
            *cpx = *fapx + (*fasx - *csx);
            *cpy = *fapy;
            *cpz = *fapz;
//??            *csx = 20;
            *csy = *fasy;
            *csz = *fasz;
            // Set free area coordinates.
            *fasx = *fasx - *csx;
        }
    }

    if (r == 0) {

        compare_arrays(p12, p13, (void*) UI_CENTRE_CELL_MODEL, (void*) UI_CENTRE_CELL_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            // Set cell coordinates.
            *cpx = *fapx;
            *cpy = *fapy;
            *cpz = *fapz;
            *csx = *fasx;
            *csy = *fasy;
            *csz = *fasz;
            // Set free area coordinates.
            *fasx = *fasx - *fasx;
            *fasy = *fasy - *fasy;
            *fasz = *fasz - *fasz;
        }
    }
}

/**
 * Serialises a linux console rectangle layout.
 *
 * @param p0 the cell position x (of the part)
 * @param p1 the cell position y
 * @param p2 the cell position z
 * @param p3 the cell size x (of the part)
 * @param p4 the cell size y
 * @param p5 the cell size z
 * @param p6 the free area position x (remaining space within the whole)
 * @param p7 the free area position y
 * @param p8 the free area position z
 * @param p9 the free area size x (remaining space within the whole)
 * @param p10 the free area size y
 * @param p11 the free area size z
 * @param p12 the original area position x (of the whole)
 * @param p13 the original area position y
 * @param p14 the original area position z
 * @param p15 the original area size x (of the whole)
 * @param p16 the original area size y
 * @param p17 the original area size z
 * @param p18 the layout cell
 * @param p19 the layout cell count
 * @param p20 the layout
 * @param p21 the layout count
 */
void serialise_linux_console_rectangle_layout(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5,
    void* p6, void* p7, void* p8, void* p9, void* p10, void* p11,
    void* p12, void* p13, void* p14, void* p15, void* p16, void* p17,
    void* p18, void* p19, void* p20, void* p21) {

    // The comparison result.
    int r = 0;

    if (r == 0) {

        compare_arrays(p20, p21, (void*) UI_COORDINATES_LAYOUT_MODEL, (void*) UI_COORDINATES_LAYOUT_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            // Determine new position and size coordinates for part.
            serialise_linux_console_rectangle_coordinates_layout(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11);
        }
    }

    if (r == 0) {

        compare_arrays(p20, p21, (void*) UI_COMPASS_LAYOUT_MODEL, (void*) UI_COMPASS_LAYOUT_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            // Determine new position and size coordinates for part.
            serialise_linux_console_rectangle_compass_layout(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p18, p19);
        }
    }

    //?? The original area position and size are necessary to calculate
    //?? coordinates of further layout models.
}

/**
 * Serialises the linux console coordinates.
 *
 * @param p0 the destination terminal control sequences (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the character
 * @param p4 the character count
 * @param p5 the hidden property
 * @param p6 the inverse property
 * @param p7 the blink property
 * @param p8 the underline property
 * @param p9 the bold property
 * @param p10 the background
 * @param p11 the background count
 * @param p12 the foreground
 * @param p13 the foreground count
 * @param p14 the position
 * @param p15 the position count
 * @param p16 the size
 * @param p17 the size count
 * @param p18 the whole model position
 * @param p19 the whole model position count
 * @param p20 the whole model size
 * @param p21 the whole model size count
 * @param p22 the border
 * @param p23 the border count
 * @param p24 the layout cell
 * @param p25 the layout cell count
 * @param p26 the layout
 * @param p27 the layout count
 */
void serialise_linux_console_coordinates(void* p0, void* p1, void* p2, void* p3, void* p4,
    void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13,
    void* p14, void* p15, void* p16, void* p17, void* p18, void* p19, void* p20, void* p21,
    void* p22, void* p23, void* p24, void* p25, void* p26, void* p27) {

    // The source part position x, y, z.
    int** px = (int**) &NULL_POINTER;
    int** py = (int**) &NULL_POINTER;
    int** pz = (int**) &NULL_POINTER;
    // The source part size x, y, z.
    int** sx = (int**) &NULL_POINTER;
    int** sy = (int**) &NULL_POINTER;
    int** sz = (int**) &NULL_POINTER;
    // The source whole position coordinates.
    int** wpmx = (int**) &NULL_POINTER;
    int** wpmy = (int**) &NULL_POINTER;
    int** wpmz = (int**) &NULL_POINTER;
    // The source whole size coordinates.
    int** wsmx = (int**) &NULL_POINTER;
    int** wsmy = (int**) &NULL_POINTER;
    int** wsmz = (int**) &NULL_POINTER;
    // The original area position coordinates, set to the zero origo.
    int oapx = *NUMBER_0_INTEGER;
    int oapy = *NUMBER_0_INTEGER;
    int oapz = *NUMBER_0_INTEGER;
    // The original area size coordinates, initialised with whole coordinates.
    int oasx = *NUMBER_0_INTEGER;
    int oasy = *NUMBER_0_INTEGER;
    int oasz = *NUMBER_0_INTEGER;
    // The free area position coordinates, initialised with original area position coordinates.
    int fapx = oapx;
    int fapy = oapy;
    int fapz = oapz;
    // The free area size coordinates, initialised with original area position coordinates.
    int fasx = oasx;
    int fasy = oasy;
    int fasz = oasz;

    // Get part position x, y, z.
    get(p14, (void*) UI_POSITION_X_INDEX, (void*) &px, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    get(p14, (void*) UI_POSITION_Y_INDEX, (void*) &py, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    get(p14, (void*) UI_POSITION_Z_INDEX, (void*) &pz, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    // Get part size x, y, z.
    get(p16, (void*) UI_SIZE_X_INDEX, (void*) &sx, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    get(p16, (void*) UI_SIZE_Y_INDEX, (void*) &sy, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    get(p16, (void*) UI_SIZE_Z_INDEX, (void*) &sz, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

    if (p20 != NULL_POINTER) {

        // Determine source whole position coordinates.
        get(p18, (void*) UI_POSITION_X_INDEX, (void*) &wpmx, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        get(p18, (void*) UI_POSITION_Y_INDEX, (void*) &wpmy, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        get(p18, (void*) UI_POSITION_Z_INDEX, (void*) &wpmz, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        // Determine source whole size coordinates.
        get(p20, (void*) UI_SIZE_X_INDEX, (void*) &wsmx, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        get(p20, (void*) UI_SIZE_Y_INDEX, (void*) &wsmy, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        get(p20, (void*) UI_SIZE_Z_INDEX, (void*) &wsmz, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

        // Set original area position coordinates, initialised with whole position.
        oapx = **wpmx;
        oapy = **wpmy;
        oapz = **wpmz;
        // Set original area size coordinates, initialised with whole size.
        oasx = **wsmx;
        oasy = **wsmy;
        oasz = **wsmz;

        // Set free area position coordinates, initialised with original area position coordinates.
        fapx = oapx;
        fapy = oapy;
        fapz = oapz;
        // Set free area size coordinates, initialised with original area position coordinates.
        fasx = oasx;
        fasy = oasy;
        fasz = oasz;
    }

    // Calculate coordinates according to given layout.
    serialise_linux_console_rectangle_layout(*px, *py, *pz, *sx, *sy, *sz,
        &fapx, &fapy, &fapz, &fasx, &fasy, &fasz,
        &oapx, &oapy, &oapz, &oasx, &oasy, &oasz,
        p24, p25, p26, p27);

    serialise_linux_console_rectangle(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9,
        p10, p11, p12, p13, *px, *py, *pz, *sx, *sy, *sz, p22, p23);
}

/**
 * Serialises a linux console shape.
 *
 * @param p0 the destination terminal control sequences (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the character
 * @param p4 the character count
 * @param p5 the character abstraction
 * @param p6 the character abstraction count
 * @param p7 the hidden property
 * @param p8 the hidden property count
 * @param p9 the inverse property
 * @param p10 the inverse property count
 * @param p11 the blink property
 * @param p12 the blink property count
 * @param p13 the underline property
 * @param p14 the underline property count
 * @param p15 the bold property
 * @param p16 the bold property count
 * @param p17 the background
 * @param p18 the background count
 * @param p19 the foreground
 * @param p20 the foreground count
 * @param p21 the position
 * @param p22 the position count
 * @param p23 the size
 * @param p24 the size count
 * @param p25 the whole model position
 * @param p26 the whole model position count
 * @param p27 the whole model size
 * @param p28 the whole model size count
 * @param p29 the border
 * @param p30 the border count
 * @param p31 the layout cell
 * @param p32 the layout cell count
 * @param p33 the layout
 * @param p34 the layout count
 * @param p35 the shape
 * @param p36 the shape count
 */
void serialise_linux_console_shape(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6,
    void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14, void* p15, void* p16,
    void* p17, void* p18, void* p19, void* p20, void* p21, void* p22, void* p23, void* p24, void* p25, void* p26,
    void* p27, void* p28, void* p29, void* p30, void* p31, void* p32, void* p33, void* p34, void* p35, void* p36) {

    // The character.
    void* c = NULL_POINTER;
    // The character count.
    void* cc = NULL_POINTER;
    // The hidden property.
    int h = 0;
    // The inverse property.
    int i = 0;
    // The blink property.
    int bl = 0;
    // The underline property.
    int u = 0;
    // The bold property.
    int b = 0;
    // The background colour.
    void* bg = NULL_POINTER;
    int bgc = 0;
    // The foreground colour.
    void* fg = NULL_POINTER;
    int fgc = 0;

    //?? TODO: These values should later be given as boolean "true" or "false".
    //?? Currently, they have to be given as "0" or "1" in CYBOL.
    //?? Change this later by transforming boolean into integer values!
    set(&h, (void*) PRIMITIVE_VALUE_INDEX, p7, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
    set(&i, (void*) PRIMITIVE_VALUE_INDEX, p9, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
    set(&bl, (void*) PRIMITIVE_VALUE_INDEX, p11, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
    set(&u, (void*) PRIMITIVE_VALUE_INDEX, p13, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
    set(&b, (void*) PRIMITIVE_VALUE_INDEX, p15, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
    // Map colour names to control sequences.
    mapto((void*) &bg, (void*) &bgc, NULL_POINTER, p17, p18, (void*) TERMINAL_BACKGROUND_ABSTRACTION, (void*) TERMINAL_BACKGROUND_ABSTRACTION_COUNT);
    mapto((void*) &fg, (void*) &fgc, NULL_POINTER, p19, p20, (void*) TERMINAL_FOREGROUND_ABSTRACTION, (void*) TERMINAL_FOREGROUND_ABSTRACTION_COUNT);

    // The comparison result.
    int r = 0;

    compare_arrays(p5, p6, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

    if (r != 0) {

        // Set character parameter to be handed over.
        // If the part model is NOT of abstraction "character" (e.g. a "compound"),
        // the parameter to be handed over remains a NULL_POINTER.
        c = p3;
        cc = p4;
    }

    // Reset comparison result.
    r = 0;

    if (r == 0) {

        compare_arrays(p35, p36, (void*) UI_RECTANGLE_SHAPE_MODEL, (void*) UI_RECTANGLE_SHAPE_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            serialise_linux_console_coordinates(p0, p1, p2, c, cc, &h, &i, &bl, &u, &b,
                bg, (void*) &bgc, fg, (void*) &fgc, p21, p22, p23, p24,
                p25, p26, p27, p28, p29, p30, p31, p32, p33, p34);
        }
    }

    if (r == 0) {

        compare_arrays(p35, p36, (void*) UI_CIRCLE_SHAPE_MODEL, (void*) UI_CIRCLE_SHAPE_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

/*??
            serialise_linux_console_coordinates(p0, p1, p2, c, cc, &h, &i, &bl, &u, &b,
                bg, (void*) &bgc, fg, (void*) &fgc, p21, p22, p23, p24,
                p25, p26, p27, p28, p29, p30, p31, p32, p33, p34);
*/
        }
    }

    if (r == 0) {

        compare_arrays(p35, p36, (void*) UI_POLYGON_SHAPE_MODEL, (void*) UI_POLYGON_SHAPE_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

/*??
            serialise_linux_console_coordinates(p0, p1, p2, c, cc, &h, &i, &bl, &u, &b,
                bg, (void*) &bgc, fg, (void*) &fgc, p21, p22, p23, p24,
                p25, p26, p27, p28, p29, p30, p31, p32, p33, p34);
*/
        }
    }
}

/**
 * Parses a linux console into a compound model.
 *
 * @param p0 the destination linux console model (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source control sequences
 * @param p4 the source count
 */
void parse_linux_console(void* p0, void* p1, void* p2, void* p3, void* p4) {
}

/**
 * Serialises a compound model into linux console control sequences.
 *
 * @param p0 the destination control sequences (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source compound model
 * @param p4 the source compound model count
 * @param p5 the source compound details
 * @param p6 the source compound details count
 * @param p7 the knowledge memory
 * @param p8 the knowledge memory count
 */
void serialise_linux_console(void* p0, void* p1, void* p2, void* p3, void* p4,
    void* p5, void* p6, void* p7, void* p8) {

    if (p4 != NULL_POINTER) {

        int* sc = (int*) p4;

        log_message_debug("Serialise compound model into linux console control sequences.");

        // The source whole position.
        void** wpa = &NULL_POINTER;
        void** wpac = &NULL_POINTER;
        void** wpas = &NULL_POINTER;
        void** wpm = &NULL_POINTER;
        void** wpmc = &NULL_POINTER;
        void** wpms = &NULL_POINTER;
        void** wpd = &NULL_POINTER;
        void** wpdc = &NULL_POINTER;
        void** wpds = &NULL_POINTER;
        // The source whole size.
        void** wsa = &NULL_POINTER;
        void** wsac = &NULL_POINTER;
        void** wsas = &NULL_POINTER;
        void** wsm = &NULL_POINTER;
        void** wsmc = &NULL_POINTER;
        void** wsms = &NULL_POINTER;
        void** wsd = &NULL_POINTER;
        void** wsdc = &NULL_POINTER;
        void** wsds = &NULL_POINTER;
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
        // The source part super properties.
        void** supera = &NULL_POINTER;
        void** superac = &NULL_POINTER;
        void** superas = &NULL_POINTER;
        void** superm = &NULL_POINTER;
        void** supermc = &NULL_POINTER;
        void** superms = &NULL_POINTER;
        void** superd = &NULL_POINTER;
        void** superdc = &NULL_POINTER;
        void** superds = &NULL_POINTER;
        // The source part shape.
        void** sha = &NULL_POINTER;
        void** shac = &NULL_POINTER;
        void** shas = &NULL_POINTER;
        void** shm = &NULL_POINTER;
        void** shmc = &NULL_POINTER;
        void** shms = &NULL_POINTER;
        void** shd = &NULL_POINTER;
        void** shdc = &NULL_POINTER;
        void** shds = &NULL_POINTER;
        // The source part layout.
        void** la = &NULL_POINTER;
        void** lac = &NULL_POINTER;
        void** las = &NULL_POINTER;
        void** lm = &NULL_POINTER;
        void** lmc = &NULL_POINTER;
        void** lms = &NULL_POINTER;
        void** ld = &NULL_POINTER;
        void** ldc = &NULL_POINTER;
        void** lds = &NULL_POINTER;
        // The source part cell.
        void** ca = &NULL_POINTER;
        void** cac = &NULL_POINTER;
        void** cas = &NULL_POINTER;
        void** cm = &NULL_POINTER;
        void** cmc = &NULL_POINTER;
        void** cms = &NULL_POINTER;
        void** cd = &NULL_POINTER;
        void** cdc = &NULL_POINTER;
        void** cds = &NULL_POINTER;
        // The source part position.
        void** pa = &NULL_POINTER;
        void** pac = &NULL_POINTER;
        void** pas = &NULL_POINTER;
        void** pm = &NULL_POINTER;
        void** pmc = &NULL_POINTER;
        void** pms = &NULL_POINTER;
        void** pd = &NULL_POINTER;
        void** pdc = &NULL_POINTER;
        void** pds = &NULL_POINTER;
        // The source part size.
        void** sa = &NULL_POINTER;
        void** sac = &NULL_POINTER;
        void** sas = &NULL_POINTER;
        void** sm = &NULL_POINTER;
        void** smc = &NULL_POINTER;
        void** sms = &NULL_POINTER;
        void** sd = &NULL_POINTER;
        void** sdc = &NULL_POINTER;
        void** sds = &NULL_POINTER;
        // The source part background colour.
        void** bga = &NULL_POINTER;
        void** bgac = &NULL_POINTER;
        void** bgas = &NULL_POINTER;
        void** bgm = &NULL_POINTER;
        void** bgmc = &NULL_POINTER;
        void** bgms = &NULL_POINTER;
        void** bgd = &NULL_POINTER;
        void** bgdc = &NULL_POINTER;
        void** bgds = &NULL_POINTER;
        // The source part foreground colour.
        void** fga = &NULL_POINTER;
        void** fgac = &NULL_POINTER;
        void** fgas = &NULL_POINTER;
        void** fgm = &NULL_POINTER;
        void** fgmc = &NULL_POINTER;
        void** fgms = &NULL_POINTER;
        void** fgd = &NULL_POINTER;
        void** fgdc = &NULL_POINTER;
        void** fgds = &NULL_POINTER;
        // The source part border.
        void** boa = &NULL_POINTER;
        void** boac = &NULL_POINTER;
        void** boas = &NULL_POINTER;
        void** bom = &NULL_POINTER;
        void** bomc = &NULL_POINTER;
        void** boms = &NULL_POINTER;
        void** bod = &NULL_POINTER;
        void** bodc = &NULL_POINTER;
        void** bods = &NULL_POINTER;
        // The source part hidden property.
        void** ha = &NULL_POINTER;
        void** hac = &NULL_POINTER;
        void** has = &NULL_POINTER;
        void** hm = &NULL_POINTER;
        void** hmc = &NULL_POINTER;
        void** hms = &NULL_POINTER;
        void** hd = &NULL_POINTER;
        void** hdc = &NULL_POINTER;
        void** hds = &NULL_POINTER;
        // The source part inverse property.
        void** ia = &NULL_POINTER;
        void** iac = &NULL_POINTER;
        void** ias = &NULL_POINTER;
        void** im = &NULL_POINTER;
        void** imc = &NULL_POINTER;
        void** ims = &NULL_POINTER;
        void** id = &NULL_POINTER;
        void** idc = &NULL_POINTER;
        void** ids = &NULL_POINTER;
        // The source part blink property.
        void** bla = &NULL_POINTER;
        void** blac = &NULL_POINTER;
        void** blas = &NULL_POINTER;
        void** blm = &NULL_POINTER;
        void** blmc = &NULL_POINTER;
        void** blms = &NULL_POINTER;
        void** bld = &NULL_POINTER;
        void** bldc = &NULL_POINTER;
        void** blds = &NULL_POINTER;
        // The source part underline property.
        void** ua = &NULL_POINTER;
        void** uac = &NULL_POINTER;
        void** uas = &NULL_POINTER;
        void** um = &NULL_POINTER;
        void** umc = &NULL_POINTER;
        void** ums = &NULL_POINTER;
        void** ud = &NULL_POINTER;
        void** udc = &NULL_POINTER;
        void** uds = &NULL_POINTER;
        // The source part bold property.
        void** ba = &NULL_POINTER;
        void** bac = &NULL_POINTER;
        void** bas = &NULL_POINTER;
        void** bm = &NULL_POINTER;
        void** bmc = &NULL_POINTER;
        void** bms = &NULL_POINTER;
        void** bd = &NULL_POINTER;
        void** bdc = &NULL_POINTER;
        void** bds = &NULL_POINTER;

        // The comparison result.
        int r = 0;
        // The loop count.
        int j = 0;

        // Iterate through compound parts.
        while (1) {

            if (j >= *sc) {

                break;
            }

            // Get source whole position from details.
            get_compound_element_by_name(p5, p6,
                (void*) UI_POSITION_NAME, (void*) UI_POSITION_NAME_COUNT,
                (void*) &wpa, (void*) &wpac, (void*) &wpas,
                (void*) &wpm, (void*) &wpmc, (void*) &wpms,
                (void*) &wpd, (void*) &wpdc, (void*) &wpds);
            // Get source whole size from details.
            get_compound_element_by_name(p5, p6,
                (void*) UI_SIZE_NAME, (void*) UI_SIZE_NAME_COUNT,
                (void*) &wsa, (void*) &wsac, (void*) &wsas,
                (void*) &wsm, (void*) &wsmc, (void*) &wsms,
                (void*) &wsd, (void*) &wsdc, (void*) &wsds);
            // Get part at index j.
            get_compound_element_by_index(p3, p4, (void*) &j,
                (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms,
                (void*) &d, (void*) &dc, (void*) &ds);
            // Get part super properties from details.
            get_real_compound_element_by_name(*d, *dc,
                (void*) SUPER_PROPERTIES_NAME, (void*) SUPER_PROPERTIES_NAME_COUNT,
                (void*) &supera, (void*) &superac, (void*) &superas,
                (void*) &superm, (void*) &supermc, (void*) &superms,
                (void*) &superd, (void*) &superdc, (void*) &superds,
                p7, p8);

            //
            // Get default property values from super part.
            //

            // Get part shape from super part.
            get_compound_element_by_name(*superm, *supermc,
                (void*) UI_SHAPE_NAME, (void*) UI_SHAPE_NAME_COUNT,
                (void*) &sha, (void*) &shac, (void*) &shas,
                (void*) &shm, (void*) &shmc, (void*) &shms,
                (void*) &shd, (void*) &shdc, (void*) &shds);
            // Get source part layout from details.
            get_compound_element_by_name(*superm, *supermc,
                (void*) UI_LAYOUT_NAME, (void*) UI_LAYOUT_NAME_COUNT,
                (void*) &la, (void*) &lac, (void*) &las,
                (void*) &lm, (void*) &lmc, (void*) &lms,
                (void*) &ld, (void*) &ldc, (void*) &lds);
            // Get source part cell from details.
            get_compound_element_by_name(*superm, *supermc,
                (void*) UI_CELL_NAME, (void*) UI_CELL_NAME_COUNT,
                (void*) &ca, (void*) &cac, (void*) &cas,
                (void*) &cm, (void*) &cmc, (void*) &cms,
                (void*) &cd, (void*) &cdc, (void*) &cds);
            // Get part position from super part.
            get_compound_element_by_name(*superm, *supermc,
                (void*) UI_POSITION_NAME, (void*) UI_POSITION_NAME_COUNT,
                (void*) &pa, (void*) &pac, (void*) &pas,
                (void*) &pm, (void*) &pmc, (void*) &pms,
                (void*) &pd, (void*) &pdc, (void*) &pds);
            // Get part size from super part.
            get_compound_element_by_name(*superm, *supermc,
                (void*) UI_SIZE_NAME, (void*) UI_SIZE_NAME_COUNT,
                (void*) &sa, (void*) &sac, (void*) &sas,
                (void*) &sm, (void*) &smc, (void*) &sms,
                (void*) &sd, (void*) &sdc, (void*) &sds);
            // Get part background colour from super part.
            get_compound_element_by_name(*superm, *supermc,
                (void*) UI_BACKGROUND_NAME, (void*) UI_BACKGROUND_NAME_COUNT,
                (void*) &bga, (void*) &bgac, (void*) &bgas,
                (void*) &bgm, (void*) &bgmc, (void*) &bgms,
                (void*) &bgd, (void*) &bgdc, (void*) &bgds);
            // Get part foreground colour from super part.
            get_compound_element_by_name(*superm, *supermc,
                (void*) UI_FOREGROUND_NAME, (void*) UI_FOREGROUND_NAME_COUNT,
                (void*) &fga, (void*) &fgac, (void*) &fgas,
                (void*) &fgm, (void*) &fgmc, (void*) &fgms,
                (void*) &fgd, (void*) &fgdc, (void*) &fgds);
            // Get part border from super part.
            get_compound_element_by_name(*superm, *supermc,
                (void*) TUI_BORDER_NAME, (void*) TUI_BORDER_NAME_COUNT,
                (void*) &boa, (void*) &boac, (void*) &boas,
                (void*) &bom, (void*) &bomc, (void*) &boms,
                (void*) &bod, (void*) &bodc, (void*) &bods);
            // Get part hidden property from super part.
            get_compound_element_by_name(*superm, *supermc,
                (void*) TUI_HIDDEN_NAME, (void*) TUI_HIDDEN_NAME_COUNT,
                (void*) &ha, (void*) &hac, (void*) &has,
                (void*) &hm, (void*) &hmc, (void*) &hms,
                (void*) &hd, (void*) &hdc, (void*) &hds);
            // Get part inverse property from super part.
            get_compound_element_by_name(*superm, *supermc,
                (void*) TUI_INVERSE_NAME, (void*) TUI_INVERSE_NAME_COUNT,
                (void*) &ia, (void*) &iac, (void*) &ias,
                (void*) &im, (void*) &imc, (void*) &ims,
                (void*) &id, (void*) &idc, (void*) &ids);
            // Get part blink property from super part.
            get_compound_element_by_name(*superm, *supermc,
                (void*) TUI_BLINK_NAME, (void*) TUI_BLINK_NAME_COUNT,
                (void*) &bla, (void*) &blac, (void*) &blas,
                (void*) &blm, (void*) &blmc, (void*) &blms,
                (void*) &bld, (void*) &bldc, (void*) &blds);
            // Get part underline property from super part.
            get_compound_element_by_name(*superm, *supermc,
                (void*) TUI_UNDERLINE_NAME, (void*) TUI_UNDERLINE_NAME_COUNT,
                (void*) &ua, (void*) &uac, (void*) &uas,
                (void*) &um, (void*) &umc, (void*) &ums,
                (void*) &ud, (void*) &udc, (void*) &uds);
            // Get part bold property from super part.
            get_compound_element_by_name(*superm, *supermc,
                (void*) TUI_BOLD_NAME, (void*) TUI_BOLD_NAME_COUNT,
                (void*) &ba, (void*) &bac, (void*) &bas,
                (void*) &bm, (void*) &bmc, (void*) &bms,
                (void*) &bd, (void*) &bdc, (void*) &bds);

            //
            // Get standard property values from part.
            // If a standard property value DOES exist, previously gotten
            // default property values (from super part) are overwritten.
            // If a standard property value does NOT exist, the default
            // property value remains untouched.
            //

            // Get part shape from details.
            get_compound_element_by_name(*d, *dc,
                (void*) UI_SHAPE_NAME, (void*) UI_SHAPE_NAME_COUNT,
                (void*) &sha, (void*) &shac, (void*) &shas,
                (void*) &shm, (void*) &shmc, (void*) &shms,
                (void*) &shd, (void*) &shdc, (void*) &shds);
            // Get source part layout from details.
            get_compound_element_by_name(*d, *dc,
                (void*) UI_LAYOUT_NAME, (void*) UI_LAYOUT_NAME_COUNT,
                (void*) &la, (void*) &lac, (void*) &las,
                (void*) &lm, (void*) &lmc, (void*) &lms,
                (void*) &ld, (void*) &ldc, (void*) &lds);
            // Get source part cell from details.
            get_compound_element_by_name(*d, *dc,
                (void*) UI_CELL_NAME, (void*) UI_CELL_NAME_COUNT,
                (void*) &ca, (void*) &cac, (void*) &cas,
                (void*) &cm, (void*) &cmc, (void*) &cms,
                (void*) &cd, (void*) &cdc, (void*) &cds);
            // Get part position from details.
            get_compound_element_by_name(*d, *dc,
                (void*) UI_POSITION_NAME, (void*) UI_POSITION_NAME_COUNT,
                (void*) &pa, (void*) &pac, (void*) &pas,
                (void*) &pm, (void*) &pmc, (void*) &pms,
                (void*) &pd, (void*) &pdc, (void*) &pds);
            // Get part size from details.
            get_compound_element_by_name(*d, *dc,
                (void*) UI_SIZE_NAME, (void*) UI_SIZE_NAME_COUNT,
                (void*) &sa, (void*) &sac, (void*) &sas,
                (void*) &sm, (void*) &smc, (void*) &sms,
                (void*) &sd, (void*) &sdc, (void*) &sds);
            // Get part background colour from details.
            get_compound_element_by_name(*d, *dc,
                (void*) UI_BACKGROUND_NAME, (void*) UI_BACKGROUND_NAME_COUNT,
                (void*) &bga, (void*) &bgac, (void*) &bgas,
                (void*) &bgm, (void*) &bgmc, (void*) &bgms,
                (void*) &bgd, (void*) &bgdc, (void*) &bgds);
            // Get part foreground colour from details.
            get_compound_element_by_name(*d, *dc,
                (void*) UI_FOREGROUND_NAME, (void*) UI_FOREGROUND_NAME_COUNT,
                (void*) &fga, (void*) &fgac, (void*) &fgas,
                (void*) &fgm, (void*) &fgmc, (void*) &fgms,
                (void*) &fgd, (void*) &fgdc, (void*) &fgds);
            // Get part border from details.
            get_compound_element_by_name(*d, *dc,
                (void*) TUI_BORDER_NAME, (void*) TUI_BORDER_NAME_COUNT,
                (void*) &boa, (void*) &boac, (void*) &boas,
                (void*) &bom, (void*) &bomc, (void*) &boms,
                (void*) &bod, (void*) &bodc, (void*) &bods);
            // Get part hidden property from details.
            get_compound_element_by_name(*d, *dc,
                (void*) TUI_HIDDEN_NAME, (void*) TUI_HIDDEN_NAME_COUNT,
                (void*) &ha, (void*) &hac, (void*) &has,
                (void*) &hm, (void*) &hmc, (void*) &hms,
                (void*) &hd, (void*) &hdc, (void*) &hds);
            // Get part inverse property from details.
            get_compound_element_by_name(*d, *dc,
                (void*) TUI_INVERSE_NAME, (void*) TUI_INVERSE_NAME_COUNT,
                (void*) &ia, (void*) &iac, (void*) &ias,
                (void*) &im, (void*) &imc, (void*) &ims,
                (void*) &id, (void*) &idc, (void*) &ids);
            // Get part blink property from details.
            get_compound_element_by_name(*d, *dc,
                (void*) TUI_BLINK_NAME, (void*) TUI_BLINK_NAME_COUNT,
                (void*) &bla, (void*) &blac, (void*) &blas,
                (void*) &blm, (void*) &blmc, (void*) &blms,
                (void*) &bld, (void*) &bldc, (void*) &blds);
            // Get part underline property from details.
            get_compound_element_by_name(*d, *dc,
                (void*) TUI_UNDERLINE_NAME, (void*) TUI_UNDERLINE_NAME_COUNT,
                (void*) &ua, (void*) &uac, (void*) &uas,
                (void*) &um, (void*) &umc, (void*) &ums,
                (void*) &ud, (void*) &udc, (void*) &uds);
            // Get part bold property from details.
            get_compound_element_by_name(*d, *dc,
                (void*) TUI_BOLD_NAME, (void*) TUI_BOLD_NAME_COUNT,
                (void*) &ba, (void*) &bac, (void*) &bas,
                (void*) &bm, (void*) &bmc, (void*) &bms,
                (void*) &bd, (void*) &bdc, (void*) &bds);

            // Serialise shape.
            serialise_linux_console_shape(p0, p1, p2, *m, *mc, *a, *ac,
                *hm, *hmc, *im, *imc, *blm, *blmc, *um, *umc, *bm, *bmc,
                *bgm, *bgmc, *fgm, *fgmc, *pm, *pmc, *sm, *smc,
                *wpm, *wpmc, *wsm, *wsmc, *bom, *bomc,
                *cm, *cmc, *lm, *lmc, *shm, *shmc);

            compare_arrays(*a, *ac, (void*) CYBOL_ABSTRACTION, (void*) CYBOL_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

            if (r != 0) {

                // The part model is a compound.

                // Recursively call this procedure for compound part model.
                serialise_linux_console(p0, p1, p2, *m, *mc, *d, *dc, p7, p8);
            }

            // Reset source whole position.
            wpa = &NULL_POINTER;
            wpac = &NULL_POINTER;
            wpas = &NULL_POINTER;
            wpm = &NULL_POINTER;
            wpmc = &NULL_POINTER;
            wpms = &NULL_POINTER;
            wpd = &NULL_POINTER;
            wpdc = &NULL_POINTER;
            wpds = &NULL_POINTER;
            // Reset source whole size.
            wsa = &NULL_POINTER;
            wsac = &NULL_POINTER;
            wsas = &NULL_POINTER;
            wsm = &NULL_POINTER;
            wsmc = &NULL_POINTER;
            wsms = &NULL_POINTER;
            wsd = &NULL_POINTER;
            wsdc = &NULL_POINTER;
            wsds = &NULL_POINTER;
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
            // Reset source part super properties.
            supera = &NULL_POINTER;
            superac = &NULL_POINTER;
            superas = &NULL_POINTER;
            superm = &NULL_POINTER;
            supermc = &NULL_POINTER;
            superms = &NULL_POINTER;
            superd = &NULL_POINTER;
            superdc = &NULL_POINTER;
            superds = &NULL_POINTER;
            // Reset source part shape.
            sha = &NULL_POINTER;
            shac = &NULL_POINTER;
            shas = &NULL_POINTER;
            shm = &NULL_POINTER;
            shmc = &NULL_POINTER;
            shms = &NULL_POINTER;
            shd = &NULL_POINTER;
            shdc = &NULL_POINTER;
            shds = &NULL_POINTER;
            // Reset source part layout.
            la = &NULL_POINTER;
            lac = &NULL_POINTER;
            las = &NULL_POINTER;
            lm = &NULL_POINTER;
            lmc = &NULL_POINTER;
            lms = &NULL_POINTER;
            ld = &NULL_POINTER;
            ldc = &NULL_POINTER;
            lds = &NULL_POINTER;
            // Reset source part cell.
            ca = &NULL_POINTER;
            cac = &NULL_POINTER;
            cas = &NULL_POINTER;
            cm = &NULL_POINTER;
            cmc = &NULL_POINTER;
            cms = &NULL_POINTER;
            cd = &NULL_POINTER;
            cdc = &NULL_POINTER;
            cds = &NULL_POINTER;
            // Reset source part position.
            pa = &NULL_POINTER;
            pac = &NULL_POINTER;
            pas = &NULL_POINTER;
            pm = &NULL_POINTER;
            pmc = &NULL_POINTER;
            pms = &NULL_POINTER;
            pd = &NULL_POINTER;
            pdc = &NULL_POINTER;
            pds = &NULL_POINTER;
            // Reset source part size.
            sa = &NULL_POINTER;
            sac = &NULL_POINTER;
            sas = &NULL_POINTER;
            sm = &NULL_POINTER;
            smc = &NULL_POINTER;
            sms = &NULL_POINTER;
            sd = &NULL_POINTER;
            sdc = &NULL_POINTER;
            sds = &NULL_POINTER;
            // Reset source part background colour.
            bga = &NULL_POINTER;
            bgac = &NULL_POINTER;
            bgas = &NULL_POINTER;
            bgm = &NULL_POINTER;
            bgmc = &NULL_POINTER;
            bgms = &NULL_POINTER;
            bgd = &NULL_POINTER;
            bgdc = &NULL_POINTER;
            bgds = &NULL_POINTER;
            // Reset source part foreground colour.
            fga = &NULL_POINTER;
            fgac = &NULL_POINTER;
            fgas = &NULL_POINTER;
            fgm = &NULL_POINTER;
            fgmc = &NULL_POINTER;
            fgms = &NULL_POINTER;
            fgd = &NULL_POINTER;
            fgdc = &NULL_POINTER;
            fgds = &NULL_POINTER;
            // Reset source part border.
            boa = &NULL_POINTER;
            boac = &NULL_POINTER;
            boas = &NULL_POINTER;
            bom = &NULL_POINTER;
            bomc = &NULL_POINTER;
            boms = &NULL_POINTER;
            bod = &NULL_POINTER;
            bodc = &NULL_POINTER;
            bods = &NULL_POINTER;
            // Reset source part hidden property.
            ha = &NULL_POINTER;
            hac = &NULL_POINTER;
            has = &NULL_POINTER;
            hm = &NULL_POINTER;
            hmc = &NULL_POINTER;
            hms = &NULL_POINTER;
            hd = &NULL_POINTER;
            hdc = &NULL_POINTER;
            hds = &NULL_POINTER;
            // Reset source part inverse property.
            ia = &NULL_POINTER;
            iac = &NULL_POINTER;
            ias = &NULL_POINTER;
            im = &NULL_POINTER;
            imc = &NULL_POINTER;
            ims = &NULL_POINTER;
            id = &NULL_POINTER;
            idc = &NULL_POINTER;
            ids = &NULL_POINTER;
            // Reset source part blink property.
            bla = &NULL_POINTER;
            blac = &NULL_POINTER;
            blas = &NULL_POINTER;
            blm = &NULL_POINTER;
            blmc = &NULL_POINTER;
            blms = &NULL_POINTER;
            bld = &NULL_POINTER;
            bldc = &NULL_POINTER;
            blds = &NULL_POINTER;
            // Reset source part underline property.
            ua = &NULL_POINTER;
            uac = &NULL_POINTER;
            uas = &NULL_POINTER;
            um = &NULL_POINTER;
            umc = &NULL_POINTER;
            ums = &NULL_POINTER;
            ud = &NULL_POINTER;
            udc = &NULL_POINTER;
            uds = &NULL_POINTER;
            // Reset source part bold property.
            ba = &NULL_POINTER;
            bac = &NULL_POINTER;
            bas = &NULL_POINTER;
            bm = &NULL_POINTER;
            bmc = &NULL_POINTER;
            bms = &NULL_POINTER;
            bd = &NULL_POINTER;
            bdc = &NULL_POINTER;
            bds = &NULL_POINTER;

            // Reset comparison result.
            r = 0;

            // Increment loop count.
            j++;
        }

    } else {

        log_message_debug("Could not serialise compound model into linux console control sequences. The source count parameter is null.");
    }
}

/* LINUX_CONSOLE_CONVERTER_SOURCE */
#endif
