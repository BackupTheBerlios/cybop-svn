/*
 * Copyright (C) 1999-2011. Christian Heller.
 *
 * This file is part of the Cybernetics Oriented Interpreter (CYBOI).
 *
 * CYBOI is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * CYBOI is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with CYBOI.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Cybernetics Oriented Programming (CYBOP) <http://www.cybop.org>
 * Christian Heller <christian.heller@tuxtax.de>
 *
 * @version $RCSfile: gnu_linux_console_converter.c,v $ $Revision: 1.38 $ $Date: 2009-10-06 21:25:27 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef GNU_LINUX_CONSOLE_ENCODER_SOURCE
#define GNU_LINUX_CONSOLE_ENCODER_SOURCE

#ifdef CYGWIN_ENVIRONMENT
#include <windows.h>
/* CYGWIN_ENVIRONMENT */
#endif

#include <stdio.h>
#include <wchar.h>
#include "../../../constant/abstraction/cybol/text_cybol_abstraction.c"
#include "../../../constant/abstraction/memory/memory_abstraction.c"
#include "../../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../../constant/model/character_code/unicode/unicode_character_code_model.c"
#include "../../../constant/model/cybol/layout/compass_layout_cybol_model.c"
#include "../../../constant/model/cybol/border_cybol_model.c"
#include "../../../constant/model/cybol/http_request_cybol_model.c"
#include "../../../constant/model/cybol/layout_cybol_model.c"
#include "../../../constant/model/cybol/shape_cybol_model.c"
#include "../../../constant/model/gnu_linux_console/escape_control_sequence_gnu_linux_console_model.c"
#include "../../../constant/model/log/message_log_model.c"
#include "../../../constant/model/memory/boolean_memory_model.c"
#include "../../../constant/model/memory/integer_memory_model.c"
#include "../../../constant/model/memory/pointer_memory_model.c"
#include "../../../constant/name/cybol/keyboard_key_cybol_name.c"
#include "../../../constant/name/cybol/super_cybol_name.c"
#include "../../../constant/name/cybol/text_user_interface_cybol_name.c"
#include "../../../constant/name/memory/vector_memory_name.c"
#include "../../../executor/accessor/getter/compound_getter.c"
#include "../../../executor/accessor/getter.c"
#include "../../../executor/accessor/setter.c"
#include "../../../executor/converter/encoder/integer_vector_encoder.c"
#include "../../../executor/converter/encoder/terminal_background_encoder.c"
#include "../../../executor/converter/encoder/terminal_foreground_encoder.c"
#include "../../../logger/logger.c"

/**
 * Encodes a gnu/linux console character.
 *
 * @param p0 the destination terminal control sequences (Hand over as reference!)
 * @param p1 the destination terminal control sequences count
 * @param p2 the destination terminal control sequences size
 * @param p3 the x coordinate
 * @param p4 the y coordinate
 * @param p5 the z coordinate
 * @param p6 the background colour
 * @param p7 the background colour count
 * @param p8 the foreground colour
 * @param p9 the foreground colour count
 * @param p10 the hidden flag
 * @param p11 the inverse flag
 * @param p12 the blink flag
 * @param p13 the underline flag
 * @param p14 the bold flag
 * @param p15 the character
 */
void encode_gnu_linux_console_character(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5,
    void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14, void* p15) {

    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Encode gnu/linux console character.");

    if (p4 != *NULL_POINTER_MEMORY_MODEL) {

        int* sy = (int*) p4;

        if (p3 != *NULL_POINTER_MEMORY_MODEL) {

            int* sx = (int*) p3;

            // CAUTION! The top-left terminal corner is 1:1, but the given positions
            // start counting from 0, so that 1 has to be added to all positions!
            // Therefore, the coordinates handed over need to be corrected.

            // The corrected y.
            int cy = *sy + *NUMBER_1_INTEGER_MEMORY_MODEL;
            // The corrected x.
            int cx = *sx + *NUMBER_1_INTEGER_MEMORY_MODEL;

            //
            // Position cursor.
            //
            // Example:
            // printf("\033[%d;%dH", y_row, x_column)
            //

            append_array_elements(p0, p1, p2, (void*) ESCAPE_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL, (void*) ESCAPE_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);
            encode_integer_vector(p0, p1, p2, (void*) &cy, (void*) PRIMITIVE_MEMORY_MODEL_COUNT);
            append_array_elements(p0, p1, p2, (void*) SEMICOLON_UNICODE_CHARACTER_CODE_MODEL, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);
            encode_integer_vector(p0, p1, p2, (void*) &cx, (void*) PRIMITIVE_MEMORY_MODEL_COUNT);
            append_array_elements(p0, p1, p2, (void*) LATIN_CAPITAL_LETTER_H_UNICODE_CHARACTER_CODE_MODEL, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);
            append_array_elements(p0, p1, p2, (void*) ESCAPE_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL, (void*) ESCAPE_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);
            append_array_elements(p0, p1, p2, (void*) ATTRIBUTE_OFF_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL, (void*) ATTRIBUTE_OFF_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not encode gnu/linux console properties. The x coordinate is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not encode gnu/linux console properties. The y coordinate is null.");
    }

    //
    // Add background and foreground properties.
    //
    // Example:
    // printf("\033[32mgreen colour\033[0mswitched off.")
    //

    append_array_elements(p0, p1, p2, (void*) ESCAPE_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL, (void*) ESCAPE_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);
    encode_terminal_background(p0, p1, p2, p6, p7);
    append_array_elements(p0, p1, p2, (void*) ATTRIBUTE_SUFFIX_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL, (void*) ATTRIBUTE_SUFFIX_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

    append_array_elements(p0, p1, p2, (void*) ESCAPE_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL, (void*) ESCAPE_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);
    encode_terminal_foreground(p0, p1, p2, p8, p9);
    append_array_elements(p0, p1, p2, (void*) ATTRIBUTE_SUFFIX_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL, (void*) ATTRIBUTE_SUFFIX_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

    //
    // Set character properties.
    //
    // Example:
    // printf("\033[1mbold \033[0mswitched off.")
    //

    // The comparison result.
    int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

    // Set hidden property.
    compare_equal_arrays((void*) &r, p10, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) TRUE_BOOLEAN_MEMORY_MODEL, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_MEMORY_ABSTRACTION);

    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

        append_array_elements(p0, p1, p2, (void*) ESCAPE_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL, (void*) ESCAPE_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);
        append_array_elements(p0, p1, p2, (void*) HIDDEN_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL, (void*) HIDDEN_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);
    }

    // Reset comparison result.
    r = *NUMBER_0_INTEGER_MEMORY_MODEL;

    // Set inverse property.
    compare_equal_arrays((void*) &r, p11, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) TRUE_BOOLEAN_MEMORY_MODEL, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

        append_array_elements(p0, p1, p2, (void*) ESCAPE_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL, (void*) ESCAPE_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);
        append_array_elements(p0, p1, p2, (void*) INVERSE_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL, (void*) INVERSE_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);
    }

    // Reset comparison result.
    r = *NUMBER_0_INTEGER_MEMORY_MODEL;

    // Set blink property.
    compare_equal_arrays((void*) &r, p12, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) TRUE_BOOLEAN_MEMORY_MODEL, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

        append_array_elements(p0, p1, p2, (void*) ESCAPE_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL, (void*) ESCAPE_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);
        append_array_elements(p0, p1, p2, (void*) BLINK_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL, (void*) BLINK_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);
    }

    // Reset comparison result.
    r = *NUMBER_0_INTEGER_MEMORY_MODEL;

    // Set underline property.
    compare_equal_arrays((void*) &r, p13, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) TRUE_BOOLEAN_MEMORY_MODEL, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

        append_array_elements(p0, p1, p2, (void*) ESCAPE_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL, (void*) ESCAPE_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);
        append_array_elements(p0, p1, p2, (void*) UNDERLINE_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL, (void*) UNDERLINE_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);
    }

    // Reset comparison result.
    r = *NUMBER_0_INTEGER_MEMORY_MODEL;

    // Set bold property.
    compare_equal_arrays((void*) &r, p14, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) TRUE_BOOLEAN_MEMORY_MODEL, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

        append_array_elements(p0, p1, p2, (void*) ESCAPE_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL, (void*) ESCAPE_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);
        append_array_elements(p0, p1, p2, (void*) BOLD_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL, (void*) BOLD_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);
    }

    // Set character.
    append_array_elements(p0, p1, p2, p15, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);
}

/**
 * Encodes a gnu/linux console rectangle border.
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
void encode_gnu_linux_console_rectangle_border(void* p0, void* p1,
    void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    if (p5 != *NULL_POINTER_MEMORY_MODEL) {

        wchar_t* rbc = (wchar_t*) p5;

        if (p4 != *NULL_POINTER_MEMORY_MODEL) {

            wchar_t* lbc = (wchar_t*) p4;

            if (p3 != *NULL_POINTER_MEMORY_MODEL) {

                wchar_t* rtc = (wchar_t*) p3;

                if (p2 != *NULL_POINTER_MEMORY_MODEL) {

                    wchar_t* ltc = (wchar_t*) p2;

                    if (p1 != *NULL_POINTER_MEMORY_MODEL) {

                        wchar_t* vc = (wchar_t*) p1;

                        if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                            wchar_t* hc = (wchar_t*) p0;

                            log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Encode gnu/linux console rectangle border.");

                            // The comparison result.
                            int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

                            if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                                compare_equal_arrays((void*) &r, p6, p7, (void*) ASCII_LINE_BORDER_CYBOL_MODEL, (void*) ASCII_LINE_BORDER_CYBOL_MODEL_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                                if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                                    *hc = *HYPHEN_MINUS_UNICODE_CHARACTER_CODE_MODEL;
                                    *vc = *VERTICAL_LINE_UNICODE_CHARACTER_CODE_MODEL;
                                    *ltc = *PLUS_SIGN_UNICODE_CHARACTER_CODE_MODEL;
                                    *rtc = *PLUS_SIGN_UNICODE_CHARACTER_CODE_MODEL;
                                    *lbc = *PLUS_SIGN_UNICODE_CHARACTER_CODE_MODEL;
                                    *rbc = *PLUS_SIGN_UNICODE_CHARACTER_CODE_MODEL;
                                }
                            }

                            if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                                compare_equal_arrays((void*) &r, p6, p7, (void*) DOUBLE_LINE_BORDER_CYBOL_MODEL, (void*) DOUBLE_LINE_BORDER_CYBOL_MODEL_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                                if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                                    *hc = *BOX_DRAWINGS_DOUBLE_HORIZONTAL_UNICODE_CHARACTER_CODE_MODEL;
                                    *vc = *BOX_DRAWINGS_DOUBLE_VERTICAL_UNICODE_CHARACTER_CODE_MODEL;
                                    *ltc = *BOX_DRAWINGS_DOUBLE_DOWN_AND_RIGHT_UNICODE_CHARACTER_CODE_MODEL;
                                    *rtc = *BOX_DRAWINGS_DOUBLE_DOWN_AND_LEFT_UNICODE_CHARACTER_CODE_MODEL;
                                    *lbc = *BOX_DRAWINGS_DOUBLE_UP_AND_RIGHT_UNICODE_CHARACTER_CODE_MODEL;
                                    *rbc = *BOX_DRAWINGS_DOUBLE_UP_AND_LEFT_UNICODE_CHARACTER_CODE_MODEL;
                                }
                            }

                            if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                                compare_equal_arrays((void*) &r, p6, p7, (void*) ROUND_LINE_BORDER_CYBOL_MODEL, (void*) ROUND_LINE_BORDER_CYBOL_MODEL_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                                if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                                    *hc = *BOX_DRAWINGS_LIGHT_HORIZONTAL_UNICODE_CHARACTER_CODE_MODEL;
                                    *vc = *BOX_DRAWINGS_LIGHT_VERTICAL_UNICODE_CHARACTER_CODE_MODEL;
                                    *ltc = *BOX_DRAWINGS_LIGHT_ARC_DOWN_AND_RIGHT_UNICODE_CHARACTER_CODE_MODEL;
                                    *rtc = *BOX_DRAWINGS_LIGHT_ARC_DOWN_AND_LEFT_UNICODE_CHARACTER_CODE_MODEL;
                                    *lbc = *BOX_DRAWINGS_LIGHT_ARC_UP_AND_RIGHT_UNICODE_CHARACTER_CODE_MODEL;
                                    *rbc = *BOX_DRAWINGS_LIGHT_ARC_UP_AND_LEFT_UNICODE_CHARACTER_CODE_MODEL;
                                }
                            }

                            if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                                compare_equal_arrays((void*) &r, p6, p7, (void*) SIMPLE_LINE_BORDER_CYBOL_MODEL, (void*) SIMPLE_LINE_BORDER_CYBOL_MODEL_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                                if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                                    *hc = *DIGIT_TWO_UNICODE_CHARACTER_CODE_MODEL;
                                    *vc = *BOX_DRAWINGS_LIGHT_VERTICAL_UNICODE_CHARACTER_CODE_MODEL;
                                    *ltc = *BOX_DRAWINGS_LIGHT_DOWN_AND_RIGHT_UNICODE_CHARACTER_CODE_MODEL;
                                    *rtc = *BOX_DRAWINGS_LIGHT_DOWN_AND_LEFT_UNICODE_CHARACTER_CODE_MODEL;
                                    *lbc = *BOX_DRAWINGS_LIGHT_UP_AND_RIGHT_UNICODE_CHARACTER_CODE_MODEL;
                                    *rbc = *BOX_DRAWINGS_LIGHT_UP_AND_LEFT_UNICODE_CHARACTER_CODE_MODEL;
                                }
                            }

                        } else {

                            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not encode gnu/linux console rectangle border. The horizontal character is null.");
                        }

                    } else {

                        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not encode gnu/linux console rectangle border. The vertical character is null.");
                    }

                } else {

                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not encode gnu/linux console rectangle border. The left top character is null.");
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not encode gnu/linux console rectangle border. The right top character is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not encode gnu/linux console rectangle border. The left bottom character is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not encode gnu/linux console rectangle border. The right bottom character is null.");
    }
}

/**
 * Encodes a gnu/linux console rectangle.
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
void encode_gnu_linux_console_rectangle(void* p0, void* p1, void* p2, void* p3, void* p4,
    void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13,
    void* p14, void* p15, void* p16, void* p17, void* p18, void* p19, void* p20, void* p21) {

    if (p19 != *NULL_POINTER_MEMORY_MODEL) {

        int* sz = (int*) p19;

        if (p18 != *NULL_POINTER_MEMORY_MODEL) {

            int* sy = (int*) p18;

            if (p17 != *NULL_POINTER_MEMORY_MODEL) {

                int* sx = (int*) p17;

                if (p16 != *NULL_POINTER_MEMORY_MODEL) {

                    int* pz = (int*) p16;

                    if (p15 != *NULL_POINTER_MEMORY_MODEL) {

                        int* py = (int*) p15;

                        if (p14 != *NULL_POINTER_MEMORY_MODEL) {

                            int* px = (int*) p14;

                            int* cc = (int*) p4;

                            log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Encode gnu/linux console rectangle.");

                            // The horizontal character.
                            wchar_t hc = *SPACE_UNICODE_CHARACTER_CODE_MODEL;
                            // The vertical character.
                            wchar_t vc = *SPACE_UNICODE_CHARACTER_CODE_MODEL;
                            // The left top character.
                            wchar_t ltc = *SPACE_UNICODE_CHARACTER_CODE_MODEL;
                            // The right top character.
                            wchar_t rtc = *SPACE_UNICODE_CHARACTER_CODE_MODEL;
                            // The left bottom character.
                            wchar_t lbc = *SPACE_UNICODE_CHARACTER_CODE_MODEL;
                            // The right bottom character.
                            wchar_t rbc = *SPACE_UNICODE_CHARACTER_CODE_MODEL;

                            // Determine border characters.
                            encode_gnu_linux_console_rectangle_border((void*) &hc, (void*) &vc,
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
                            int ci = *NUMBER_0_INTEGER_MEMORY_MODEL;
                            // The character.
                            void* c = (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL;

                            while (*NUMBER_1_INTEGER_MEMORY_MODEL) {

                                if (z >= zl) {

                                    break;
                                }

                                while (*NUMBER_1_INTEGER_MEMORY_MODEL) {

                                    if (y >= yl) {

                                        break;
                                    }

                                    while (*NUMBER_1_INTEGER_MEMORY_MODEL) {

                                        if (x >= xl) {

                                            break;
                                        }

                                        if (p20 == *NULL_POINTER_MEMORY_MODEL) {

                                            // A border is NOT given.

                                            if (cc != *NULL_POINTER_MEMORY_MODEL) {

                                                // Calculate character index.
                                                ci = x - *px;

                                                if (ci < *cc) {

                                                    // Get character value at position x.
                                                    get((void*) &c, p3, (void*) &ci, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT);
                                                }

                                                // Encode character using escape codes.
                                                encode_gnu_linux_console_character(p0, p1, p2, &x, &y, &z, p10, p11, p12, p13, p5, p6, p7, p8, p9, c);

                                            } else {

                                                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not encode gnu/linux console rectangle. The character count is null.");
                                            }

                                        } else {

                                            // A border IS given.

                                            if (y == *py) {

                                                if (x == *px) {

                                                    // Encode left top border character using escape codes.
                                                    encode_gnu_linux_console_character(p0, p1, p2, &x, &y, &z, p10, p11, p12, p13, p5, p6, p7, p8, p9, &ltc);

                                                } else if (x == (xl - *NUMBER_1_INTEGER_MEMORY_MODEL)) {

                                                    // Encode right top border character using escape codes.
                                                    encode_gnu_linux_console_character(p0, p1, p2, &x, &y, &z, p10, p11, p12, p13, p5, p6, p7, p8, p9, &rtc);

                                                } else {

                                                    // Encode horizontal border character using escape codes.
                                                    encode_gnu_linux_console_character(p0, p1, p2, &x, &y, &z, p10, p11, p12, p13, p5, p6, p7, p8, p9, &hc);
                                                }

                                            } else if (y == (yl - *NUMBER_1_INTEGER_MEMORY_MODEL)) {

                                                if (x == *px) {

                                                    // Encode left bottom border character using escape codes.
                                                    encode_gnu_linux_console_character(p0, p1, p2, &x, &y, &z, p10, p11, p12, p13, p5, p6, p7, p8, p9, &lbc);

                                                } else if (x == (xl - *NUMBER_1_INTEGER_MEMORY_MODEL)) {

                                                    // Encode right bottom border character using escape codes.
                                                    encode_gnu_linux_console_character(p0, p1, p2, &x, &y, &z, p10, p11, p12, p13, p5, p6, p7, p8, p9, &rbc);

                                                } else {

                                                    // Encode horizontal border character using escape codes.
                                                    encode_gnu_linux_console_character(p0, p1, p2, &x, &y, &z, p10, p11, p12, p13, p5, p6, p7, p8, p9, &hc);
                                                }

                                            } else {

                                                if (x == *px) {

                                                    // Encode left bottom border character using escape codes.
                                                    encode_gnu_linux_console_character(p0, p1, p2, &x, &y, &z, p10, p11, p12, p13, p5, p6, p7, p8, p9, &vc);

                                                } else if (x == (xl - *NUMBER_1_INTEGER_MEMORY_MODEL)) {

                                                    // Encode right bottom border character using escape codes.
                                                    encode_gnu_linux_console_character(p0, p1, p2, &x, &y, &z, p10, p11, p12, p13, p5, p6, p7, p8, p9, &vc);

                                                } else {

                                                    if (cc != *NULL_POINTER_MEMORY_MODEL) {

                                                        // Calculate character index.
                                                        // CAUTION! Subtract one because of the left border.
                                                        ci = x - *px - *NUMBER_1_INTEGER_MEMORY_MODEL;

                                                        if (ci < *cc) {

                                                            // Get character value at position x.
                                                            get(p3, (void*) &ci, (void*) &c, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT);
                                                        }

                                                    } else {

                                                        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not encode gnu/linux console rectangle. The character count is null.");
                                                    }

                                                    // Encode character using escape codes.
                                                    encode_gnu_linux_console_character(p0, p1, p2, &x, &y, &z, p10, p11, p12, p13, p5, p6, p7, p8, p9, c);
                                                }
                                            }
                                        }

                                        // The character index ci does not have to be reset,
                                        // as it is always calculated before getting a character.

                                        // Reset character.
                                        c = (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL;

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

                            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not encode user interface rectangle. The character count is null.");
                        }

                    } else {

                        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not encode user interface rectangle. The character count is null.");
                    }

                } else {

                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not encode user interface rectangle. The character count is null.");
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not encode user interface rectangle. The character count is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not encode user interface rectangle. The character count is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not encode user interface rectangle. The character count is null.");
    }
}

/**
 * Encodes a gnu/linux console rectangle coordinates layout.
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
void encode_gnu_linux_console_rectangle_coordinates_layout(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5,
    void* p6, void* p7, void* p8, void* p9, void* p10, void* p11) {

    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Encode gnu/linux console rectangle coordinates layout.");

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
 * Encodes a gnu/linux console rectangle compass layout.
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
void encode_gnu_linux_console_rectangle_compass_layout(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5,
    void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13) {

    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Encode gnu/linux console rectangle compass layout.");

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
    int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_arrays((void*) &r, p12, p13, (void*) NORTH_COMPASS_LAYOUT_CYBOL_MODEL, (void*) NORTH_COMPASS_LAYOUT_CYBOL_MODEL_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            // Set cell coordinates.
            *cpx = *fapx;
            *cpy = *fapy;
            *cpz = *fapz;
            *csx = *fasx;
//??            *csy = *NUMBER_20_INTEGER_MEMORY_MODEL;
            *csz = *fasz;
            // Set free area coordinates.
            *fapy = *fapy + *csy;
            *fasy = *fasy - *csy;
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_arrays((void*) &r, p12, p13, (void*) SOUTH_COMPASS_LAYOUT_CYBOL_MODEL, (void*) SOUTH_COMPASS_LAYOUT_CYBOL_MODEL_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            // Set cell coordinates.
            *cpx = *fapx;
            *cpy = *fapy + (*fasy - *csy);
            *cpz = *fapz;
            *csx = *fasx;
//??            *csy = *NUMBER_20_INTEGER_MEMORY_MODEL;
            *csz = *fasz;
            // Set free area coordinates.
            *fasy = *fasy - *csy;
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_arrays((void*) &r, p12, p13, (void*) WEST_COMPASS_LAYOUT_CYBOL_MODEL, (void*) WEST_COMPASS_LAYOUT_CYBOL_MODEL_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            // Set cell coordinates.
            *cpx = *fapx;
            *cpy = *fapy;
            *cpz = *fapz;
//??            *csx = *NUMBER_20_INTEGER_MEMORY_MODEL;
            *csy = *fasy;
            *csz = *fasz;
            // Set free area coordinates.
            *fapx = *fapx + *csx;
            *fasx = *fasx - *csx;
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_arrays((void*) &r, p12, p13, (void*) EAST_COMPASS_LAYOUT_CYBOL_MODEL, (void*) EAST_COMPASS_LAYOUT_CYBOL_MODEL_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            // Set cell coordinates.
            *cpx = *fapx + (*fasx - *csx);
            *cpy = *fapy;
            *cpz = *fapz;
//??            *csx = *NUMBER_20_INTEGER_MEMORY_MODEL;
            *csy = *fasy;
            *csz = *fasz;
            // Set free area coordinates.
            *fasx = *fasx - *csx;
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_arrays((void*) &r, p12, p13, (void*) CENTRE_COMPASS_LAYOUT_CYBOL_MODEL, (void*) CENTRE_COMPASS_LAYOUT_CYBOL_MODEL_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

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
 * Encodes a gnu/linux console rectangle layout.
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
void encode_gnu_linux_console_rectangle_layout(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5,
    void* p6, void* p7, void* p8, void* p9, void* p10, void* p11,
    void* p12, void* p13, void* p14, void* p15, void* p16, void* p17,
    void* p18, void* p19, void* p20, void* p21) {

    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Encode gnu/linux console rectangle layout.");

    // The comparison result.
    int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_arrays((void*) &r, p20, p21, (void*) COORDINATES_LAYOUT_CYBOL_MODEL, (void*) COORDINATES_LAYOUT_CYBOL_MODEL_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            // Determine new position and size coordinates for part.
            encode_gnu_linux_console_rectangle_coordinates_layout(p0, p1, p2, p3, p4, p5, p12, p13, p14, p15, p16, p17);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_arrays((void*) &r, p20, p21, (void*) COMPASS_LAYOUT_CYBOL_MODEL, (void*) COMPASS_LAYOUT_CYBOL_MODEL_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            // Determine new position and size coordinates for part.
            encode_gnu_linux_console_rectangle_compass_layout(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p18, p19);
        }
    }

    //?? The original area position and size are necessary to calculate
    //?? coordinates of further layout models.
}

/**
 * Encodes the gnu/linux console coordinates.
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
void encode_gnu_linux_console_coordinates(void* p0, void* p1, void* p2, void* p3, void* p4,
    void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13,
    void* p14, void* p15, void* p16, void* p17, void* p18, void* p19, void* p20, void* p21,
    void* p22, void* p23, void* p24, void* p25, void* p26, void* p27) {

    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Encode gnu/linux console coordinates.");

    // The source part position x, y, z.
    int* px = (int*) *NULL_POINTER_MEMORY_MODEL;
    int* py = (int*) *NULL_POINTER_MEMORY_MODEL;
    int* pz = (int*) *NULL_POINTER_MEMORY_MODEL;
    // The source part size x, y, z.
    int* sx = (int*) *NULL_POINTER_MEMORY_MODEL;
    int* sy = (int*) *NULL_POINTER_MEMORY_MODEL;
    int* sz = (int*) *NULL_POINTER_MEMORY_MODEL;
    // The current position x, y, z.
    int cpx = *NUMBER_0_INTEGER_MEMORY_MODEL;
    int cpy = *NUMBER_0_INTEGER_MEMORY_MODEL;
    int cpz = *NUMBER_0_INTEGER_MEMORY_MODEL;
    // The current size x, y, z.
    int csx = *NUMBER_0_INTEGER_MEMORY_MODEL;
    int csy = *NUMBER_0_INTEGER_MEMORY_MODEL;
    int csz = *NUMBER_0_INTEGER_MEMORY_MODEL;
    // The source whole position coordinates.
    int* wpmx = (int*) *NULL_POINTER_MEMORY_MODEL;
    int* wpmy = (int*) *NULL_POINTER_MEMORY_MODEL;
    int* wpmz = (int*) *NULL_POINTER_MEMORY_MODEL;
    // The source whole size coordinates.
    int* wsmx = (int*) *NULL_POINTER_MEMORY_MODEL;
    int* wsmy = (int*) *NULL_POINTER_MEMORY_MODEL;
    int* wsmz = (int*) *NULL_POINTER_MEMORY_MODEL;
    // The original area position coordinates, set to the zero origo.
    int oapx = *NUMBER_0_INTEGER_MEMORY_MODEL;
    int oapy = *NUMBER_0_INTEGER_MEMORY_MODEL;
    int oapz = *NUMBER_0_INTEGER_MEMORY_MODEL;
    // The original area size coordinates, initialised with whole coordinates.
    int oasx = *NUMBER_0_INTEGER_MEMORY_MODEL;
    int oasy = *NUMBER_0_INTEGER_MEMORY_MODEL;
    int oasz = *NUMBER_0_INTEGER_MEMORY_MODEL;
    // The free area position coordinates, initialised with original area position coordinates.
    int fapx = oapx;
    int fapy = oapy;
    int fapz = oapz;
    // The free area size coordinates, initialised with original area position coordinates.
    int fasx = oasx;
    int fasy = oasy;
    int fasz = oasz;

    // Get part position x, y, z.
    get((void*) &px, p14, (void*) DIMENSION_0_VECTOR_MEMORY_NAME, (void*) INTEGER_MEMORY_ABSTRACTION, (void*) INTEGER_MEMORY_ABSTRACTION_COUNT);
    get((void*) &py, p14, (void*) DIMENSION_1_VECTOR_MEMORY_NAME, (void*) INTEGER_MEMORY_ABSTRACTION, (void*) INTEGER_MEMORY_ABSTRACTION_COUNT);
    get((void*) &pz, p14, (void*) DIMENSION_2_VECTOR_MEMORY_NAME, (void*) INTEGER_MEMORY_ABSTRACTION, (void*) INTEGER_MEMORY_ABSTRACTION_COUNT);
    // Get part size x, y, z.
    get((void*) &sx, p16, (void*) DIMENSION_0_VECTOR_MEMORY_NAME, (void*) INTEGER_MEMORY_ABSTRACTION, (void*) INTEGER_MEMORY_ABSTRACTION_COUNT);
    get((void*) &sy, p16, (void*) DIMENSION_1_VECTOR_MEMORY_NAME, (void*) INTEGER_MEMORY_ABSTRACTION, (void*) INTEGER_MEMORY_ABSTRACTION_COUNT);
    get((void*) &sz, p16, (void*) DIMENSION_2_VECTOR_MEMORY_NAME, (void*) INTEGER_MEMORY_ABSTRACTION, (void*) INTEGER_MEMORY_ABSTRACTION_COUNT);

    // Set current position coordinates, initialised with part position.
    cpx = *px;
    cpy = *py;
    cpz = *pz;
    // Set current size coordinates, initialised with part size.
    csx = *sx;
    csy = *sy;
    csz = *sz;

    if (p20 != *NULL_POINTER_MEMORY_MODEL) {

        // Determine source whole position coordinates.
        get((void*) &wpmx, p18, (void*) DIMENSION_0_VECTOR_MEMORY_NAME, (void*) INTEGER_MEMORY_ABSTRACTION, (void*) INTEGER_MEMORY_ABSTRACTION_COUNT);
        get((void*) &wpmy, p18, (void*) DIMENSION_1_VECTOR_MEMORY_NAME, (void*) INTEGER_MEMORY_ABSTRACTION, (void*) INTEGER_MEMORY_ABSTRACTION_COUNT);
        get((void*) &wpmz, p18, (void*) DIMENSION_2_VECTOR_MEMORY_NAME, (void*) INTEGER_MEMORY_ABSTRACTION, (void*) INTEGER_MEMORY_ABSTRACTION_COUNT);
        // Determine source whole size coordinates.
        get((void*) &wsmx, p20, (void*) DIMENSION_0_VECTOR_MEMORY_NAME, (void*) INTEGER_MEMORY_ABSTRACTION, (void*) INTEGER_MEMORY_ABSTRACTION_COUNT);
        get((void*) &wsmy, p20, (void*) DIMENSION_1_VECTOR_MEMORY_NAME, (void*) INTEGER_MEMORY_ABSTRACTION, (void*) INTEGER_MEMORY_ABSTRACTION_COUNT);
        get((void*) &wsmz, p20, (void*) DIMENSION_2_VECTOR_MEMORY_NAME, (void*) INTEGER_MEMORY_ABSTRACTION, (void*) INTEGER_MEMORY_ABSTRACTION_COUNT);

        // Set original area position coordinates, initialised with whole position.
        oapx = *wpmx;
        oapy = *wpmy;
        oapz = *wpmz;
        // Set original area size coordinates, initialised with whole size.
        oasx = *wsmx;
        oasy = *wsmy;
        oasz = *wsmz;

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
    encode_gnu_linux_console_rectangle_layout((void*) &cpx, (void*) &cpy, (void*) &cpz, (void*) &csx, (void*) &csy, (void*) &csz,
        (void*) &fapx, (void*) &fapy, (void*) &fapz, (void*) &fasx, (void*) &fasy, (void*) &fasz,
        (void*) &oapx, (void*) &oapy, (void*) &oapz, (void*) &oasx, (void*) &oasy, (void*) &oasz,
        p24, p25, p26, p27);

    encode_gnu_linux_console_rectangle(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13,
        (void*) &cpx, (void*) &cpy, (void*) &cpz, (void*) &csx, (void*) &csy, (void*) &csz, p22, p23);
}

/**
 * Encodes a gnu/linux console shape.
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
void encode_gnu_linux_console_shape(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6,
    void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14, void* p15, void* p16,
    void* p17, void* p18, void* p19, void* p20, void* p21, void* p22, void* p23, void* p24, void* p25, void* p26,
    void* p27, void* p28, void* p29, void* p30, void* p31, void* p32, void* p33, void* p34, void* p35, void* p36) {

    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Encode gnu/linux console shape.");

    // The comparison result.
    int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_arrays((void*) &r, p35, p36, (void*) RECTANGLE_SHAPE_CYBOL_MODEL, (void*) RECTANGLE_SHAPE_CYBOL_MODEL_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            encode_gnu_linux_console_coordinates(p0, p1, p2,
                p3, p4,
                p7, p9, p11, p13, p15,
                p17, p18, p19, p20, p21, p22, p23, p24,
                p25, p26, p27, p28, p29, p30, p31, p32, p33, p34);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_arrays((void*) &r, p35, p36, (void*) CIRCLE_SHAPE_CYBOL_MODEL, (void*) CIRCLE_SHAPE_CYBOL_MODEL_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

/*??
            encode_gnu_linux_console_coordinates(p0, p1, p2, c, cc, &h, &i, &bl, &u, &b,
                bg, (void*) &bgc, fg, (void*) &fgc, p21, p22, p23, p24,
                p25, p26, p27, p28, p29, p30, p31, p32, p33, p34);
*/
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_arrays((void*) &r, p35, p36, (void*) POLYGON_SHAPE_CYBOL_MODEL, (void*) POLYGON_SHAPE_CYBOL_MODEL_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

/*??
            encode_gnu_linux_console_coordinates(p0, p1, p2, c, cc, &h, &i, &bl, &u, &b,
                bg, (void*) &bgc, fg, (void*) &fgc, p21, p22, p23, p24,
                p25, p26, p27, p28, p29, p30, p31, p32, p33, p34);
*/
        }
    }
}

/**
 * Encodes a compound model into gnu/linux console control sequences.
 *
 * @param p0 the destination control sequences (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source part abstraction
 * @param p4 the source part abstraction count
 * @param p5 the source part model
 * @param p6 the source part model count
 * @param p7 the source part details
 * @param p8 the source part details count
 * @param p9 the source whole details (the compound containing the source part)
 * @param p10 the source whole details count
 * @param p11 the source part name (area to be repainted)
 * @param p12 the source part name count
 * @param p13 the knowledge memory
 * @param p14 the knowledge memory count
 */
void encode_gnu_linux_console(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6,
    void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Encode gnu/linux console.");

    // The source part name, abstraction, model, details.
    void** n = NULL_POINTER_MEMORY_MODEL;
    void** nc = NULL_POINTER_MEMORY_MODEL;
    void** ns = NULL_POINTER_MEMORY_MODEL;
    void** a = NULL_POINTER_MEMORY_MODEL;
    void** ac = NULL_POINTER_MEMORY_MODEL;
    void** as = NULL_POINTER_MEMORY_MODEL;
    void** m = NULL_POINTER_MEMORY_MODEL;
    void** mc = NULL_POINTER_MEMORY_MODEL;
    void** ms = NULL_POINTER_MEMORY_MODEL;
    void** d = NULL_POINTER_MEMORY_MODEL;
    void** dc = NULL_POINTER_MEMORY_MODEL;
    void** ds = NULL_POINTER_MEMORY_MODEL;
    // The source part super properties name, abstraction, model, details.
    void** supern = NULL_POINTER_MEMORY_MODEL;
    void** supernc = NULL_POINTER_MEMORY_MODEL;
    void** superns = NULL_POINTER_MEMORY_MODEL;
    void** supera = NULL_POINTER_MEMORY_MODEL;
    void** superac = NULL_POINTER_MEMORY_MODEL;
    void** superas = NULL_POINTER_MEMORY_MODEL;
    void** superm = NULL_POINTER_MEMORY_MODEL;
    void** supermc = NULL_POINTER_MEMORY_MODEL;
    void** superms = NULL_POINTER_MEMORY_MODEL;
    void** superd = NULL_POINTER_MEMORY_MODEL;
    void** superdc = NULL_POINTER_MEMORY_MODEL;
    void** superds = NULL_POINTER_MEMORY_MODEL;
    // The source part shape name, abstraction, model, details.
    void** shn = NULL_POINTER_MEMORY_MODEL;
    void** shnc = NULL_POINTER_MEMORY_MODEL;
    void** shns = NULL_POINTER_MEMORY_MODEL;
    void** sha = NULL_POINTER_MEMORY_MODEL;
    void** shac = NULL_POINTER_MEMORY_MODEL;
    void** shas = NULL_POINTER_MEMORY_MODEL;
    void** shm = NULL_POINTER_MEMORY_MODEL;
    void** shmc = NULL_POINTER_MEMORY_MODEL;
    void** shms = NULL_POINTER_MEMORY_MODEL;
    void** shd = NULL_POINTER_MEMORY_MODEL;
    void** shdc = NULL_POINTER_MEMORY_MODEL;
    void** shds = NULL_POINTER_MEMORY_MODEL;
    // The source part layout name, abstraction, model, details.
    void** ln = NULL_POINTER_MEMORY_MODEL;
    void** lnc = NULL_POINTER_MEMORY_MODEL;
    void** lns = NULL_POINTER_MEMORY_MODEL;
    void** la = NULL_POINTER_MEMORY_MODEL;
    void** lac = NULL_POINTER_MEMORY_MODEL;
    void** las = NULL_POINTER_MEMORY_MODEL;
    void** lm = NULL_POINTER_MEMORY_MODEL;
    void** lmc = NULL_POINTER_MEMORY_MODEL;
    void** lms = NULL_POINTER_MEMORY_MODEL;
    void** ld = NULL_POINTER_MEMORY_MODEL;
    void** ldc = NULL_POINTER_MEMORY_MODEL;
    void** lds = NULL_POINTER_MEMORY_MODEL;
    // The source part cell name, abstraction, model, details.
    void** cn = NULL_POINTER_MEMORY_MODEL;
    void** cnc = NULL_POINTER_MEMORY_MODEL;
    void** cns = NULL_POINTER_MEMORY_MODEL;
    void** ca = NULL_POINTER_MEMORY_MODEL;
    void** cac = NULL_POINTER_MEMORY_MODEL;
    void** cas = NULL_POINTER_MEMORY_MODEL;
    void** cm = NULL_POINTER_MEMORY_MODEL;
    void** cmc = NULL_POINTER_MEMORY_MODEL;
    void** cms = NULL_POINTER_MEMORY_MODEL;
    void** cd = NULL_POINTER_MEMORY_MODEL;
    void** cdc = NULL_POINTER_MEMORY_MODEL;
    void** cds = NULL_POINTER_MEMORY_MODEL;
    // The source part position name, abstraction, model, details.
    void** pn = NULL_POINTER_MEMORY_MODEL;
    void** pnc = NULL_POINTER_MEMORY_MODEL;
    void** pns = NULL_POINTER_MEMORY_MODEL;
    void** pa = NULL_POINTER_MEMORY_MODEL;
    void** pac = NULL_POINTER_MEMORY_MODEL;
    void** pas = NULL_POINTER_MEMORY_MODEL;
    void** pm = NULL_POINTER_MEMORY_MODEL;
    void** pmc = NULL_POINTER_MEMORY_MODEL;
    void** pms = NULL_POINTER_MEMORY_MODEL;
    void** pd = NULL_POINTER_MEMORY_MODEL;
    void** pdc = NULL_POINTER_MEMORY_MODEL;
    void** pds = NULL_POINTER_MEMORY_MODEL;
    // The source part size name, abstraction, model, details.
    void** sn = NULL_POINTER_MEMORY_MODEL;
    void** snc = NULL_POINTER_MEMORY_MODEL;
    void** sns = NULL_POINTER_MEMORY_MODEL;
    void** sa = NULL_POINTER_MEMORY_MODEL;
    void** sac = NULL_POINTER_MEMORY_MODEL;
    void** sas = NULL_POINTER_MEMORY_MODEL;
    void** sm = NULL_POINTER_MEMORY_MODEL;
    void** smc = NULL_POINTER_MEMORY_MODEL;
    void** sms = NULL_POINTER_MEMORY_MODEL;
    void** sd = NULL_POINTER_MEMORY_MODEL;
    void** sdc = NULL_POINTER_MEMORY_MODEL;
    void** sds = NULL_POINTER_MEMORY_MODEL;
    // The source part background colour name, abstraction, model, details.
    void** bgn = NULL_POINTER_MEMORY_MODEL;
    void** bgnc = NULL_POINTER_MEMORY_MODEL;
    void** bgns = NULL_POINTER_MEMORY_MODEL;
    void** bga = NULL_POINTER_MEMORY_MODEL;
    void** bgac = NULL_POINTER_MEMORY_MODEL;
    void** bgas = NULL_POINTER_MEMORY_MODEL;
    void** bgm = NULL_POINTER_MEMORY_MODEL;
    void** bgmc = NULL_POINTER_MEMORY_MODEL;
    void** bgms = NULL_POINTER_MEMORY_MODEL;
    void** bgd = NULL_POINTER_MEMORY_MODEL;
    void** bgdc = NULL_POINTER_MEMORY_MODEL;
    void** bgds = NULL_POINTER_MEMORY_MODEL;
    // The source part foreground colour name, abstraction, model, details.
    void** fgn = NULL_POINTER_MEMORY_MODEL;
    void** fgnc = NULL_POINTER_MEMORY_MODEL;
    void** fgns = NULL_POINTER_MEMORY_MODEL;
    void** fga = NULL_POINTER_MEMORY_MODEL;
    void** fgac = NULL_POINTER_MEMORY_MODEL;
    void** fgas = NULL_POINTER_MEMORY_MODEL;
    void** fgm = NULL_POINTER_MEMORY_MODEL;
    void** fgmc = NULL_POINTER_MEMORY_MODEL;
    void** fgms = NULL_POINTER_MEMORY_MODEL;
    void** fgd = NULL_POINTER_MEMORY_MODEL;
    void** fgdc = NULL_POINTER_MEMORY_MODEL;
    void** fgds = NULL_POINTER_MEMORY_MODEL;
    // The source part border name, abstraction, model, details.
    void** bon = NULL_POINTER_MEMORY_MODEL;
    void** bonc = NULL_POINTER_MEMORY_MODEL;
    void** bons = NULL_POINTER_MEMORY_MODEL;
    void** boa = NULL_POINTER_MEMORY_MODEL;
    void** boac = NULL_POINTER_MEMORY_MODEL;
    void** boas = NULL_POINTER_MEMORY_MODEL;
    void** bom = NULL_POINTER_MEMORY_MODEL;
    void** bomc = NULL_POINTER_MEMORY_MODEL;
    void** boms = NULL_POINTER_MEMORY_MODEL;
    void** bod = NULL_POINTER_MEMORY_MODEL;
    void** bodc = NULL_POINTER_MEMORY_MODEL;
    void** bods = NULL_POINTER_MEMORY_MODEL;
    // The source part hidden property name, abstraction, model, details.
    void** hn = NULL_POINTER_MEMORY_MODEL;
    void** hnc = NULL_POINTER_MEMORY_MODEL;
    void** hns = NULL_POINTER_MEMORY_MODEL;
    void** ha = NULL_POINTER_MEMORY_MODEL;
    void** hac = NULL_POINTER_MEMORY_MODEL;
    void** has = NULL_POINTER_MEMORY_MODEL;
    void** hm = NULL_POINTER_MEMORY_MODEL;
    void** hmc = NULL_POINTER_MEMORY_MODEL;
    void** hms = NULL_POINTER_MEMORY_MODEL;
    void** hd = NULL_POINTER_MEMORY_MODEL;
    void** hdc = NULL_POINTER_MEMORY_MODEL;
    void** hds = NULL_POINTER_MEMORY_MODEL;
    // The source part inverse property name, abstraction, model, details.
    void** in = NULL_POINTER_MEMORY_MODEL;
    void** inc = NULL_POINTER_MEMORY_MODEL;
    void** ins = NULL_POINTER_MEMORY_MODEL;
    void** ia = NULL_POINTER_MEMORY_MODEL;
    void** iac = NULL_POINTER_MEMORY_MODEL;
    void** ias = NULL_POINTER_MEMORY_MODEL;
    void** im = NULL_POINTER_MEMORY_MODEL;
    void** imc = NULL_POINTER_MEMORY_MODEL;
    void** ims = NULL_POINTER_MEMORY_MODEL;
    void** id = NULL_POINTER_MEMORY_MODEL;
    void** idc = NULL_POINTER_MEMORY_MODEL;
    void** ids = NULL_POINTER_MEMORY_MODEL;
    // The source part blink property name, abstraction, model, details.
    void** bln = NULL_POINTER_MEMORY_MODEL;
    void** blnc = NULL_POINTER_MEMORY_MODEL;
    void** blns = NULL_POINTER_MEMORY_MODEL;
    void** bla = NULL_POINTER_MEMORY_MODEL;
    void** blac = NULL_POINTER_MEMORY_MODEL;
    void** blas = NULL_POINTER_MEMORY_MODEL;
    void** blm = NULL_POINTER_MEMORY_MODEL;
    void** blmc = NULL_POINTER_MEMORY_MODEL;
    void** blms = NULL_POINTER_MEMORY_MODEL;
    void** bld = NULL_POINTER_MEMORY_MODEL;
    void** bldc = NULL_POINTER_MEMORY_MODEL;
    void** blds = NULL_POINTER_MEMORY_MODEL;
    // The source part underline property name, abstraction, model, details.
    void** un = NULL_POINTER_MEMORY_MODEL;
    void** unc = NULL_POINTER_MEMORY_MODEL;
    void** uns = NULL_POINTER_MEMORY_MODEL;
    void** ua = NULL_POINTER_MEMORY_MODEL;
    void** uac = NULL_POINTER_MEMORY_MODEL;
    void** uas = NULL_POINTER_MEMORY_MODEL;
    void** um = NULL_POINTER_MEMORY_MODEL;
    void** umc = NULL_POINTER_MEMORY_MODEL;
    void** ums = NULL_POINTER_MEMORY_MODEL;
    void** ud = NULL_POINTER_MEMORY_MODEL;
    void** udc = NULL_POINTER_MEMORY_MODEL;
    void** uds = NULL_POINTER_MEMORY_MODEL;
    // The source part bold property name, abstraction, model, details.
    void** bn = NULL_POINTER_MEMORY_MODEL;
    void** bnc = NULL_POINTER_MEMORY_MODEL;
    void** bns = NULL_POINTER_MEMORY_MODEL;
    void** ba = NULL_POINTER_MEMORY_MODEL;
    void** bac = NULL_POINTER_MEMORY_MODEL;
    void** bas = NULL_POINTER_MEMORY_MODEL;
    void** bm = NULL_POINTER_MEMORY_MODEL;
    void** bmc = NULL_POINTER_MEMORY_MODEL;
    void** bms = NULL_POINTER_MEMORY_MODEL;
    void** bd = NULL_POINTER_MEMORY_MODEL;
    void** bdc = NULL_POINTER_MEMORY_MODEL;
    void** bds = NULL_POINTER_MEMORY_MODEL;
    // The source whole position name, abstraction, model, details.
    void** wpn = NULL_POINTER_MEMORY_MODEL;
    void** wpnc = NULL_POINTER_MEMORY_MODEL;
    void** wpns = NULL_POINTER_MEMORY_MODEL;
    void** wpa = NULL_POINTER_MEMORY_MODEL;
    void** wpac = NULL_POINTER_MEMORY_MODEL;
    void** wpas = NULL_POINTER_MEMORY_MODEL;
    void** wpm = NULL_POINTER_MEMORY_MODEL;
    void** wpmc = NULL_POINTER_MEMORY_MODEL;
    void** wpms = NULL_POINTER_MEMORY_MODEL;
    void** wpd = NULL_POINTER_MEMORY_MODEL;
    void** wpdc = NULL_POINTER_MEMORY_MODEL;
    void** wpds = NULL_POINTER_MEMORY_MODEL;
    // The source whole size name, abstraction, model, details.
    void** wsn = NULL_POINTER_MEMORY_MODEL;
    void** wsnc = NULL_POINTER_MEMORY_MODEL;
    void** wsns = NULL_POINTER_MEMORY_MODEL;
    void** wsa = NULL_POINTER_MEMORY_MODEL;
    void** wsac = NULL_POINTER_MEMORY_MODEL;
    void** wsas = NULL_POINTER_MEMORY_MODEL;
    void** wsm = NULL_POINTER_MEMORY_MODEL;
    void** wsmc = NULL_POINTER_MEMORY_MODEL;
    void** wsms = NULL_POINTER_MEMORY_MODEL;
    void** wsd = NULL_POINTER_MEMORY_MODEL;
    void** wsdc = NULL_POINTER_MEMORY_MODEL;
    void** wsds = NULL_POINTER_MEMORY_MODEL;

    // The element name.
    void* en = *NULL_POINTER_MEMORY_MODEL;
    int enc = *NUMBER_0_INTEGER_MEMORY_MODEL;
    // The remaining name.
    void* rn = *NULL_POINTER_MEMORY_MODEL;
    int rnc = *NUMBER_0_INTEGER_MEMORY_MODEL;
    // The meta hierarchy flag with the following meanings:
    // -1: not a compound knowledge hierarchy
    // 0: part hierarchy
    // 1: meta hierarchy
    int f = *NUMBER_MINUS_1_INTEGER_MEMORY_MODEL;
    // The loop count.
    int j = *NUMBER_0_INTEGER_MEMORY_MODEL;
    // The name comparison result.
    int nr = *NUMBER_0_INTEGER_MEMORY_MODEL;
    // The abstraction comparison result.
    int ar = *NUMBER_0_INTEGER_MEMORY_MODEL;

    // Get compound element (area to be repainted) name and remaining name,
    // as well as the flag indicating a part- or meta element.
    get_compound_element_name_and_remaining_name(p11, p12, (void*) &en, (void*) &enc, (void*) &rn, (void*) &rnc, (void*) &f);

    if ((p11 == *NULL_POINTER_MEMORY_MODEL) || (*((int*) p12) == *NUMBER_0_INTEGER_MEMORY_MODEL) || (f == *NUMBER_0_INTEGER_MEMORY_MODEL)) {

        // Either, no hierarchical element name (repaint area) was given
        // (p11 == *NULL_POINTER_MEMORY_MODEL), in which case not just a small area
        // but the whole textual user interface (tui) window is repainted,
        // (CAUTION! (*((int*) p12) == 0) is also necessary!)
        // OR:
        // the expected compound element (area to be repainted) pointed to
        // by the hierarchical name is a "part" element (f == 0), not a "meta" element,
        // which is correct, so that the element can be processed/ repainted.

        // Get part super properties from details.
        get_universal_compound_element_by_name(
            (void*) &supern, (void*) &supernc, (void*) &superns,
            (void*) &supera, (void*) &superac, (void*) &superas,
            (void*) &superm, (void*) &supermc, (void*) &superms,
            (void*) &superd, (void*) &superdc, (void*) &superds,
            p7, p8,
            (void*) SUPER_CYBOL_NAME, (void*) SUPER_CYBOL_NAME_COUNT,
            p13, p14);
        // Get part shape from details.
        get_universal_compound_element_by_name(
            (void*) &shn, (void*) &shnc, (void*) &shns,
            (void*) &sha, (void*) &shac, (void*) &shas,
            (void*) &shm, (void*) &shmc, (void*) &shms,
            (void*) &shd, (void*) &shdc, (void*) &shds,
            p7, p8,
            (void*) SHAPE_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) SHAPE_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT,
            p13, p14);
        // Get source part layout from details.
        get_universal_compound_element_by_name(
            (void*) &ln, (void*) &lnc, (void*) &lns,
            (void*) &la, (void*) &lac, (void*) &las,
            (void*) &lm, (void*) &lmc, (void*) &lms,
            (void*) &ld, (void*) &ldc, (void*) &lds,
            p7, p8,
            (void*) LAYOUT_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) LAYOUT_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT,
            p13, p14);
        // Get source part cell from details.
        get_universal_compound_element_by_name(
            (void*) &cn, (void*) &cnc, (void*) &cns,
            (void*) &ca, (void*) &cac, (void*) &cas,
            (void*) &cm, (void*) &cmc, (void*) &cms,
            (void*) &cd, (void*) &cdc, (void*) &cds,
            p7, p8,
            (void*) CELL_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) CELL_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT,
            p13, p14);
        // Get part position from details.
        get_universal_compound_element_by_name(
            (void*) &pn, (void*) &pnc, (void*) &pns,
            (void*) &pa, (void*) &pac, (void*) &pas,
            (void*) &pm, (void*) &pmc, (void*) &pms,
            (void*) &pd, (void*) &pdc, (void*) &pds,
            p7, p8,
            (void*) POSITION_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) POSITION_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT,
            p13, p14);
        // Get part size from details.
        get_universal_compound_element_by_name(
            (void*) &sn, (void*) &snc, (void*) &sns,
            (void*) &sa, (void*) &sac, (void*) &sas,
            (void*) &sm, (void*) &smc, (void*) &sms,
            (void*) &sd, (void*) &sdc, (void*) &sds,
            p7, p8,
            (void*) SIZE_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) SIZE_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT,
            p13, p14);
        // Get part background colour from details.
        get_universal_compound_element_by_name(
            (void*) &bgn, (void*) &bgnc, (void*) &bgns,
            (void*) &bga, (void*) &bgac, (void*) &bgas,
            (void*) &bgm, (void*) &bgmc, (void*) &bgms,
            (void*) &bgd, (void*) &bgdc, (void*) &bgds,
            p7, p8,
            (void*) BACKGROUND_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) BACKGROUND_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT,
            p13, p14);
        // Get part foreground colour from details.
        get_universal_compound_element_by_name(
            (void*) &fgn, (void*) &fgnc, (void*) &fgns,
            (void*) &fga, (void*) &fgac, (void*) &fgas,
            (void*) &fgm, (void*) &fgmc, (void*) &fgms,
            (void*) &fgd, (void*) &fgdc, (void*) &fgds,
            p7, p8,
            (void*) FOREGROUND_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) FOREGROUND_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT,
            p13, p14);
        // Get part border from details.
        get_universal_compound_element_by_name(
            (void*) &bon, (void*) &bonc, (void*) &bons,
            (void*) &boa, (void*) &boac, (void*) &boas,
            (void*) &bom, (void*) &bomc, (void*) &boms,
            (void*) &bod, (void*) &bodc, (void*) &bods,
            p7, p8,
            (void*) BORDER_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) BORDER_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT,
            p13, p14);
        // Get part hidden property from details.
        get_universal_compound_element_by_name(
            (void*) &hn, (void*) &hnc, (void*) &hns,
            (void*) &ha, (void*) &hac, (void*) &has,
            (void*) &hm, (void*) &hmc, (void*) &hms,
            (void*) &hd, (void*) &hdc, (void*) &hds,
            p7, p8,
            (void*) HIDDEN_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) HIDDEN_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT,
            p13, p14);
        // Get part inverse property from details.
        get_universal_compound_element_by_name(
            (void*) &in, (void*) &inc, (void*) &ins,
            (void*) &ia, (void*) &iac, (void*) &ias,
            (void*) &im, (void*) &imc, (void*) &ims,
            (void*) &id, (void*) &idc, (void*) &ids,
            p7, p8,
            (void*) INVERSE_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) INVERSE_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT,
            p13, p14);
        // Get part blink property from details.
        get_universal_compound_element_by_name(
            (void*) &bln, (void*) &blnc, (void*) &blns,
            (void*) &bla, (void*) &blac, (void*) &blas,
            (void*) &blm, (void*) &blmc, (void*) &blms,
            (void*) &bld, (void*) &bldc, (void*) &blds,
            p7, p8,
            (void*) BLINK_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) BLINK_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT,
            p13, p14);
        // Get part underline property from details.
        get_universal_compound_element_by_name(
            (void*) &un, (void*) &unc, (void*) &uns,
            (void*) &ua, (void*) &uac, (void*) &uas,
            (void*) &um, (void*) &umc, (void*) &ums,
            (void*) &ud, (void*) &udc, (void*) &uds,
            p7, p8,
            (void*) UNDERLINE_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) UNDERLINE_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT,
            p13, p14);
        // Get part bold property from details.
        get_universal_compound_element_by_name(
            (void*) &bn, (void*) &bnc, (void*) &bns,
            (void*) &ba, (void*) &bac, (void*) &bas,
            (void*) &bm, (void*) &bmc, (void*) &bms,
            (void*) &bd, (void*) &bdc, (void*) &bds,
            p7, p8,
            (void*) BOLD_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) BOLD_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT,
            p13, p14);

        //
        // Get default property values from super part.
        //
        // If a standard property value DOES exist, it is NOT
        // overwritten with the default property value of the super part.
        // If a standard property value does NOT exist, the default
        // property value of the super part is used.
        //

        if (*shm == *NULL_POINTER_MEMORY_MODEL) {

            // Get part shape from super part.
            get_universal_compound_element_by_name(
                (void*) &shn, (void*) &shnc, (void*) &shns,
                (void*) &sha, (void*) &shac, (void*) &shas,
                (void*) &shm, (void*) &shmc, (void*) &shms,
                (void*) &shd, (void*) &shdc, (void*) &shds,
                *superm, *supermc,
                (void*) SHAPE_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) SHAPE_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT,
                p13, p14);
        }

        if (*lm == *NULL_POINTER_MEMORY_MODEL) {

            // Get source part layout from details.
            get_universal_compound_element_by_name(
                (void*) &ln, (void*) &lnc, (void*) &lns,
                (void*) &la, (void*) &lac, (void*) &las,
                (void*) &lm, (void*) &lmc, (void*) &lms,
                (void*) &ld, (void*) &ldc, (void*) &lds,
                *superm, *supermc,
                (void*) LAYOUT_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) LAYOUT_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT,
                p13, p14);
        }

        if (*cm == *NULL_POINTER_MEMORY_MODEL) {

            // Get source part cell from details.
            get_universal_compound_element_by_name(
                (void*) &cn, (void*) &cnc, (void*) &cns,
                (void*) &ca, (void*) &cac, (void*) &cas,
                (void*) &cm, (void*) &cmc, (void*) &cms,
                (void*) &cd, (void*) &cdc, (void*) &cds,
                *superm, *supermc,
                (void*) CELL_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) CELL_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT,
                p13, p14);
        }

        if (*pm == *NULL_POINTER_MEMORY_MODEL) {

            // Get part position from super part.
            get_universal_compound_element_by_name(
                (void*) &pn, (void*) &pnc, (void*) &pns,
                (void*) &pa, (void*) &pac, (void*) &pas,
                (void*) &pm, (void*) &pmc, (void*) &pms,
                (void*) &pd, (void*) &pdc, (void*) &pds,
                *superm, *supermc,
                (void*) POSITION_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) POSITION_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT,
                p13, p14);
        }

        if (*sm == *NULL_POINTER_MEMORY_MODEL) {

            // Get part size from super part.
            get_universal_compound_element_by_name(
                (void*) &sn, (void*) &snc, (void*) &sns,
                (void*) &sa, (void*) &sac, (void*) &sas,
                (void*) &sm, (void*) &smc, (void*) &sms,
                (void*) &sd, (void*) &sdc, (void*) &sds,
                *superm, *supermc,
                (void*) SIZE_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) SIZE_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT,
                p13, p14);
        }

        if (*bgm == *NULL_POINTER_MEMORY_MODEL) {

            // Get part background colour from super part.
            get_universal_compound_element_by_name(
                (void*) &bgn, (void*) &bgnc, (void*) &bgns,
                (void*) &bga, (void*) &bgac, (void*) &bgas,
                (void*) &bgm, (void*) &bgmc, (void*) &bgms,
                (void*) &bgd, (void*) &bgdc, (void*) &bgds,
                *superm, *supermc,
                (void*) BACKGROUND_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) BACKGROUND_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT,
                p13, p14);
        }

        if (*fgm == *NULL_POINTER_MEMORY_MODEL) {

            // Get part foreground colour from super part.
            get_universal_compound_element_by_name(
                (void*) &fgn, (void*) &fgnc, (void*) &fgns,
                (void*) &fga, (void*) &fgac, (void*) &fgas,
                (void*) &fgm, (void*) &fgmc, (void*) &fgms,
                (void*) &fgd, (void*) &fgdc, (void*) &fgds,
                *superm, *supermc,
                (void*) FOREGROUND_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) FOREGROUND_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT,
                p13, p14);
        }

        if (*bom == *NULL_POINTER_MEMORY_MODEL) {

            // Get part border from super part.
            get_universal_compound_element_by_name(
                (void*) &bon, (void*) &bonc, (void*) &bons,
                (void*) &boa, (void*) &boac, (void*) &boas,
                (void*) &bom, (void*) &bomc, (void*) &boms,
                (void*) &bod, (void*) &bodc, (void*) &bods,
                *superm, *supermc,
                (void*) BORDER_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) BORDER_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT,
                p13, p14);
        }

        if (*hm == *NULL_POINTER_MEMORY_MODEL) {

            // Get part hidden property from super part.
            get_universal_compound_element_by_name(
                (void*) &hn, (void*) &hnc, (void*) &hns,
                (void*) &ha, (void*) &hac, (void*) &has,
                (void*) &hm, (void*) &hmc, (void*) &hms,
                (void*) &hd, (void*) &hdc, (void*) &hds,
                *superm, *supermc,
                (void*) HIDDEN_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) HIDDEN_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT,
                p13, p14);
        }

        if (*im == *NULL_POINTER_MEMORY_MODEL) {

            // Get part inverse property from super part.
            get_universal_compound_element_by_name(
                (void*) &in, (void*) &inc, (void*) &ins,
                (void*) &ia, (void*) &iac, (void*) &ias,
                (void*) &im, (void*) &imc, (void*) &ims,
                (void*) &id, (void*) &idc, (void*) &ids,
                *superm, *supermc,
                (void*) INVERSE_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) INVERSE_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT,
                p13, p14);
        }

        if (*blm == *NULL_POINTER_MEMORY_MODEL) {

            // Get part blink property from super part.
            get_universal_compound_element_by_name(
                (void*) &bln, (void*) &blnc, (void*) &blns,
                (void*) &bla, (void*) &blac, (void*) &blas,
                (void*) &blm, (void*) &blmc, (void*) &blms,
                (void*) &bld, (void*) &bldc, (void*) &blds,
                *superm, *supermc,
                (void*) BLINK_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) BLINK_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT,
                p13, p14);
        }

        if (*um == *NULL_POINTER_MEMORY_MODEL) {

            // Get part underline property from super part.
            get_universal_compound_element_by_name(
                (void*) &un, (void*) &unc, (void*) &uns,
                (void*) &ua, (void*) &uac, (void*) &uas,
                (void*) &um, (void*) &umc, (void*) &ums,
                (void*) &ud, (void*) &udc, (void*) &uds,
                *superm, *supermc,
                (void*) UNDERLINE_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) UNDERLINE_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT,
                p13, p14);
        }

        if (*bm == *NULL_POINTER_MEMORY_MODEL) {

            // Get part bold property from super part.
            get_universal_compound_element_by_name(
                (void*) &bn, (void*) &bnc, (void*) &bns,
                (void*) &ba, (void*) &bac, (void*) &bas,
                (void*) &bm, (void*) &bmc, (void*) &bms,
                (void*) &bd, (void*) &bdc, (void*) &bds,
                *superm, *supermc,
                (void*) BOLD_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) BOLD_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT,
                p13, p14);
        }

        // Get source whole position from details.
        get_universal_compound_element_by_name(
            (void*) &wpn, (void*) &wpnc, (void*) &wpns,
            (void*) &wpa, (void*) &wpac, (void*) &wpas,
            (void*) &wpm, (void*) &wpmc, (void*) &wpms,
            (void*) &wpd, (void*) &wpdc, (void*) &wpds,
            p9, p10,
            (void*) POSITION_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) POSITION_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT,
            p13, p14);

        // Get source whole size from details.
        get_universal_compound_element_by_name(
            (void*) &wsn, (void*) &wsnc, (void*) &wsns,
            (void*) &wsa, (void*) &wsac, (void*) &wsas,
            (void*) &wsm, (void*) &wsmc, (void*) &wsms,
            (void*) &wsd, (void*) &wsdc, (void*) &wsds,
            p9, p10,
            (void*) SIZE_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) SIZE_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT,
            p13, p14);

        compare_equal_arrays((void*) &ar, p3, p4, (void*) COMPOUND_MEMORY_ABSTRACTION, (void*) COMPOUND_MEMORY_ABSTRACTION_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

        if (ar != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            // The part model IS a compound.

            // CAUTION! Paint the compound's background etc.,
            // but do NOT hand over the model!
            // Since the model is a compound and not a valid character,
            // it will cause wrong characters or question marks to be printed on screen!
            // Therefore, do hand over a null pointer instead of the model!
            if ((p11 == *NULL_POINTER_MEMORY_MODEL) || (*((int*) p12) == *NUMBER_0_INTEGER_MEMORY_MODEL) || (rn == *NULL_POINTER_MEMORY_MODEL)) {

                // Either, no hierarchical element name (repaint area) was given
                // (p11 == *NULL_POINTER_MEMORY_MODEL), in which case not just a small area
                // but the whole textual user interface (tui) window is repainted,
                // (CAUTION! (*((int*) p12) == 0) is also necessary!)
                // OR:
                // the remaining compound element name (area to be repainted)
                // is null, which means the final element in the hierarchical
                // name has been reached and can be repainted.
                // Previous names pointing to surrounding areas higher
                // in the hierarchy are not painted that way, to be more efficient.

                // Encode shape.
                encode_gnu_linux_console_shape(p0, p1, p2,
                    *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL,
                    *hm, *hmc, *im, *imc, *blm, *blmc, *um, *umc, *bm, *bmc,
                    *bgm, *bgmc, *fgm, *fgmc, *pm, *pmc, *sm, *smc,
                    *wpm, *wpmc, *wsm, *wsmc, *bom, *bomc,
                    *cm, *cmc, *lm, *lmc, *shm, *shmc);
            }

            if (p6 != *NULL_POINTER_MEMORY_MODEL) {

                int* sc = (int*) p6;

                // Iterate through compound parts.
                while (*NUMBER_1_INTEGER_MEMORY_MODEL) {

                    if (j >= *sc) {

                        break;
                    }

                    // Get part at index j.
                    get_compound_element_by_index(p5, p6, (void*) &j,
                        (void*) &n, (void*) &nc, (void*) &ns,
                        (void*) &a, (void*) &ac, (void*) &as,
                        (void*) &m, (void*) &mc, (void*) &ms,
                        (void*) &d, (void*) &dc, (void*) &ds);

                    // Compare expected name with that of the current compound part element.
                    compare_equal_arrays((void*) &nr, *n, *nc, en, (void*) &enc, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if ((p11 == *NULL_POINTER_MEMORY_MODEL) || (*((int*) p12) == *NUMBER_0_INTEGER_MEMORY_MODEL) || (nr != *NUMBER_0_INTEGER_MEMORY_MODEL)) {

                        // Either, no hierarchical element name (repaint area) was given
                        // (p11 == *NULL_POINTER_MEMORY_MODEL), in which case not just a small area
                        // but the whole textual user interface (tui) window is repainted,
                        // (CAUTION! (*((int*) p12) == 0) is also necessary!)
                        // OR:
                        // the compound part name matches the next name in the
                        // given cascade of separated names, pointing to a knowledge model.

                        // Recursively call this procedure for compound part model.
                        encode_gnu_linux_console(p0, p1, p2, *a, *ac, *m, *mc, *d, *dc, p7, p8, rn, (void*) &rnc, p13, p14);
                    }

                    // Reset source part name, abstraction, model, details
                    // (parameters of the current compound part element).
                    n = NULL_POINTER_MEMORY_MODEL;
                    nc = NULL_POINTER_MEMORY_MODEL;
                    ns = NULL_POINTER_MEMORY_MODEL;
                    a = NULL_POINTER_MEMORY_MODEL;
                    ac = NULL_POINTER_MEMORY_MODEL;
                    as = NULL_POINTER_MEMORY_MODEL;
                    m = NULL_POINTER_MEMORY_MODEL;
                    mc = NULL_POINTER_MEMORY_MODEL;
                    ms = NULL_POINTER_MEMORY_MODEL;
                    d = NULL_POINTER_MEMORY_MODEL;
                    dc = NULL_POINTER_MEMORY_MODEL;
                    ds = NULL_POINTER_MEMORY_MODEL;

                    // Reset name comparison result.
                    nr = *NUMBER_0_INTEGER_MEMORY_MODEL;

                    // Increment loop count.
                    j++;
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not encode compound model into gnu/linux console control sequences. The source count parameter is null.");
            }

        } else {

            // The part model is NOT a compound.

            if ((p11 == *NULL_POINTER_MEMORY_MODEL) || (*((int*) p12) == *NUMBER_0_INTEGER_MEMORY_MODEL) || (rn == *NULL_POINTER_MEMORY_MODEL)) {
    //??        if ((p11 == *NULL_POINTER_MEMORY_MODEL) || (*((int*) p12) == *NUMBER_0_INTEGER_MEMORY_MODEL)) {

                // Either, no hierarchical element name (repaint area) was given
                // (p11 == *NULL_POINTER_MEMORY_MODEL), in which case not just a small area
                // but the whole textual user interface (tui) window is repainted,
                // (CAUTION! (*((int*) p12) == 0) is also necessary!)
                // OR:
                // the remaining compound element name (area to be repainted)
                // is null, which means the final element in the hierarchical
                // name has been reached and can be repainted.
                // Previous names pointing to surrounding areas higher
                // in the hierarchy are not painted that way, to be more efficient.

                // Encode shape.
                encode_gnu_linux_console_shape(p0, p1, p2, p5, p6, p3, p4,
                    *hm, *hmc, *im, *imc, *blm, *blmc, *um, *umc, *bm, *bmc,
                    *bgm, *bgmc, *fgm, *fgmc, *pm, *pmc, *sm, *smc,
                    *wpm, *wpmc, *wsm, *wsmc, *bom, *bomc,
                    *cm, *cmc, *lm, *lmc, *shm, *shmc);
            }
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not encode compound model into gnu/linux console control sequences. The hierarchical compound element name contains a meta element, while only part elements are permitted.");
    }
}

/* GNU_LINUX_CONSOLE_ENCODER_SOURCE */
#endif
