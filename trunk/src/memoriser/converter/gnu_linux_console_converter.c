/*
 * Copyright (C) 1999-2008. Christian Heller.
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
 * @version $RCSfile: gnu_linux_console_converter.c,v $ $Revision: 1.18 $ $Date: 2008-09-03 22:04:02 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef GNU_LINUX_CONSOLE_CONVERTER_SOURCE
#define GNU_LINUX_CONSOLE_CONVERTER_SOURCE

#ifdef CYGWIN_ENVIRONMENT
#include <windows.h>
/* CYGWIN_ENVIRONMENT */
#endif

#include <stdio.h>
#include <wchar.h>
#include "../../globals/constants/boolean/boolean_constants.c"
#include "../../globals/constants/character/code/wide_character_code_constants.c"
#include "../../globals/constants/console/console_control_sequence_constants.c"
#include "../../globals/constants/cybol/cybol_abstraction_constants.c"
#include "../../globals/constants/cybol/cybol_model_constants.c"
#include "../../globals/constants/cybol/cybol_name_constants.c"
#include "../../globals/constants/integer/integer_constants.c"
#include "../../constant/model/log/message_log_model.c"
#include "../../globals/constants/memory_structure/memory_abstraction_constants.c"
#include "../../globals/constants/memory_structure/memory_structure_constants.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../logger/logger.c"
#include "../../globals/variables/reallocation_factor_variables.c"
#include "../../memoriser/accessor/compound_accessor.c"
#include "../../memoriser/accessor.c"

//
// Forward declarations.
//

/**
 * Encodes the source into the destination, according to the given language.
 *
 * @param p0 the destination (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source name
 * @param p4 the source name count
 * @param p5 the source abstraction
 * @param p6 the source abstraction count
 * @param p7 the source model
 * @param p8 the source model count
 * @param p9 the source details
 * @param p10 the source details count
 * @param p11 the knowledge memory
 * @param p12 the knowledge memory count
 * @param p13 the language
 * @param p14 the language count
 */
void encode(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6,
    void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14);

/**
 * Decodes a gnu/linux console escape control sequence into a command.
 *
 * This function changes the escape control sequences into real names as defined by CYBOL.
 * Example: The ARROW_UP_CONTROL_SEQUENCE (ESC[A sequence) gets converted into the
 * constant UI_ARROW_UP_NAME with the value "arrow_up", which is used so in CYBOL files.
 *
 * @param p0 the destination command (Hand over as reference!)
 * @param p1 the destination command count
 * @param p2 the destination command size
 * @param p3 the source character array
 * @param p4 the source character array count
 */
void decode_gnu_linux_console_escape_control_sequence(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Decode gnu/linux console escape control sequence.");

    // The comparison result.
    int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(p3, p4, (void*) ARROW_UP_CONTROL_SEQUENCE, (void*) ARROW_UP_CONTROL_SEQUENCE_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            set(p0, p1, p2, (void*) UI_ARROW_UP_NAME, (void*) UI_ARROW_UP_NAME_COUNT, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION_COUNT);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(p3, p4, (void*) ARROW_DOWN_CONTROL_SEQUENCE, (void*) ARROW_DOWN_CONTROL_SEQUENCE_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            set(p0, p1, p2, (void*) UI_ARROW_DOWN_NAME, (void*) UI_ARROW_DOWN_NAME_COUNT, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION_COUNT);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(p3, p4, (void*) ARROW_LEFT_CONTROL_SEQUENCE, (void*) ARROW_LEFT_CONTROL_SEQUENCE_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            set(p0, p1, p2, (void*) UI_ARROW_LEFT_NAME, (void*) UI_ARROW_LEFT_NAME_COUNT, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION_COUNT);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(p3, p4, (void*) ARROW_RIGHT_CONTROL_SEQUENCE, (void*) ARROW_RIGHT_CONTROL_SEQUENCE_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            set(p0, p1, p2, (void*) UI_ARROW_RIGHT_NAME, (void*) UI_ARROW_RIGHT_NAME_COUNT, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION_COUNT);
        }
    }

    // Just don't do anything, if none of the escape control sequences above matched.
    // This was to be an escape control sequence, as it started with the corresponding prefix.
    // If the sequence's values are not recognised, they probably do not make sense anyway.
    // So, just ignore this and wait for other, proper sequences and characters to be converted.
}

/**
 * Decodes a gnu/linux console character into a command.
 *
 * This function changes the key codes into real names as defined by CYBOL.
 * Example: The LINE_FEED_CONTROL_CHARACTER_CODE (<enter> key) gets converted into the
 * constant UI_ENTER_NAME with the value "enter", which is used so in CYBOL files.
 *
 * @param p0 the destination command (Hand over as reference!)
 * @param p1 the destination command count
 * @param p2 the destination command size
 * @param p3 the source character array
 * @param p4 the source character array count
 */
void decode_gnu_linux_console_character(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Decode gnu/linux console character.");

    // The comparison result.
    int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(p3, p4, (void*) LINE_FEED_CONTROL_UNICODE_CHARACTER_CODE_MODEL, (void*) PRIMITIVE_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            set(p0, p1, p2, (void*) UI_ENTER_NAME, (void*) UI_ENTER_NAME_COUNT, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION_COUNT);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(p3, p4, (void*) ESCAPE_CONTROL_UNICODE_CHARACTER_CODE_MODEL, (void*) PRIMITIVE_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            set(p0, p1, p2, (void*) UI_ESCAPE_NAME, (void*) UI_ESCAPE_NAME_COUNT, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION_COUNT);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        // None of the control characters above matched.
        // Pass along character without modification.
        set(p0, p1, p2, p3, p4, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION_COUNT);
    }
}

/**
 * Decodes the gnu/linux console character array into a command.
 *
 * @param p0 the destination command (Hand over as reference!)
 * @param p1 the destination command count
 * @param p2 the destination command size
 * @param p3 the source character array
 * @param p4 the source character array count
 */
void decode_gnu_linux_console(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p4 != *NULL_POINTER_MEMORY_MODEL) {

        int* sc = (int*) p4;

        log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Decode gnu/linux console.");

    fwprintf(stderr, L"TEST decode gnu/linux console s: %s\n", (char*) p3);
    fwprintf(stderr, L"TEST decode gnu/linux console sc: %i\n", *((int*) p4));

        // The comparison result.
        int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

    fwprintf(stderr, L"TEST a0: %i\n", p3);

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

    fwprintf(stderr, L"TEST a1: %i\n", p3);

            if (*sc > *ESCAPE_CONTROL_SEQUENCE_COUNT) {

                // Only do the following comparison if the source array
                // is greater than the escape control sequence prefix,
                // since a value has to follow after the escape control sequence prefix.

                // CAUTION! Use the "ESCAPE_CONTROL_SEQUENCE_COUNT" for both comparison values,
                // since they would not be equal if their size differed.
                compare_arrays(p3, (void*) ESCAPE_CONTROL_SEQUENCE_COUNT, (void*) ESCAPE_CONTROL_SEQUENCE, (void*) ESCAPE_CONTROL_SEQUENCE_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

    fwprintf(stderr, L"TEST a2: %i\n", p3);

                if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

    fwprintf(stderr, L"TEST a3: %i\n", p3);

                    // Initialise temporary character sequence with pointer to the
                    // first character AFTER the escape control sequence prefix.
                    void* t = p3 + (*ESCAPE_CONTROL_SEQUENCE_COUNT * *WIDE_CHARACTER_PRIMITIVE_SIZE);
                    int tc = *sc - *ESCAPE_CONTROL_SEQUENCE_COUNT;

    fwprintf(stderr, L"TEST a4: %i\n", p3);

                    decode_gnu_linux_console_escape_control_sequence(p0, p1, p2, t, (void*) &tc);

    fwprintf(stderr, L"TEST a5: %i\n", p3);
                }
            }
        }

    fwprintf(stderr, L"TEST b0: %i\n", p3);

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

    fwprintf(stderr, L"TEST b1: %i\n", p3);

            decode_gnu_linux_console_character(p0, p1, p2, p3, p4);

    fwprintf(stderr, L"TEST b2: %i\n", p3);
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode gnu/linux console. The source character array count is null.");
    }
}

/**
 * Encodes a gnu/linux console character.
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
void encode_gnu_linux_console_character(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5,
    void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14, void* p15) {

    if (p9 != *NULL_POINTER_MEMORY_MODEL) {

        int* fc = (int*) p9;

        if (p7 != *NULL_POINTER_MEMORY_MODEL) {

            int* bc = (int*) p7;

            if (p4 != *NULL_POINTER_MEMORY_MODEL) {

                int* sy = (int*) p4;

                if (p3 != *NULL_POINTER_MEMORY_MODEL) {

                    int* sx = (int*) p3;

                    if (p2 != *NULL_POINTER_MEMORY_MODEL) {

                        int* ds = (int*) p2;

                        if (p1 != *NULL_POINTER_MEMORY_MODEL) {

                            int* dc = (int*) p1;

                            if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                                void** d = (void**) p0;

                                log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Encode gnu/linux console character.");

                                if (p15 != *NULL_POINTER_MEMORY_MODEL) {

                                    //
                                    // The *CHARACTER_VECTOR_REALLOCATION_FACTOR is not necessary
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
                                    void* y = *NULL_POINTER_MEMORY_MODEL;
                                    int yc = *NUMBER_0_INTEGER_MEMORY_MODEL;
                                    int ys = *NUMBER_0_INTEGER_MEMORY_MODEL;
                                    // The x coordinate.
                                    void* x = *NULL_POINTER_MEMORY_MODEL;
                                    int xc = *NUMBER_0_INTEGER_MEMORY_MODEL;
                                    int xs = *NUMBER_0_INTEGER_MEMORY_MODEL;
                                    // The background colour.
//??                                    void* b = *NULL_POINTER_MEMORY_MODEL;
//??                                    int bc = *NUMBER_0_INTEGER_MEMORY_MODEL;
//??                                    int bs = *NUMBER_0_INTEGER_MEMORY_MODEL;
                                    // The foreground colour.
//??                                    void* f = *NULL_POINTER_MEMORY_MODEL;
//??                                    int fc = *NUMBER_0_INTEGER_MEMORY_MODEL;
//??                                    int fs = *NUMBER_0_INTEGER_MEMORY_MODEL;

                                    //
                                    // Position cursor.
                                    //
                                    // Example:
                                    // printf("\033[%d;%dH", y_row, x_column)
                                    //

                                    // Allocate arrays.
                                    allocate((void*) &y, (void*) &ys, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION_COUNT);
                                    allocate((void*) &x, (void*) &xs, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION_COUNT);

                                    encode_integer((void*) &y, (void*) &yc, (void*) &ys, (void*) &cy, (void*) PRIMITIVE_COUNT);
                                    encode_integer((void*) &x, (void*) &xc, (void*) &xs, (void*) &cx, (void*) PRIMITIVE_COUNT);

                                    if ((*dc + *ESCAPE_CONTROL_SEQUENCE_COUNT
                                        + yc + *PRIMITIVE_COUNT
                                        + xc + *PRIMITIVE_MEMORY_MODEL_COUNT) >= *ds) {

                                        // Set destination character array size.
                                        // CAUTION! Add constant in case *dc is zero!
                                        *ds = *dc * *WIDE_CHARACTER_VECTOR_REALLOCATION_FACTOR
                                            + *ESCAPE_CONTROL_SEQUENCE_COUNT
                                            + yc + *PRIMITIVE_COUNT
                                            + xc + *PRIMITIVE_MEMORY_MODEL_COUNT;

                                        // Reallocate destination character array.
                                        reallocate_array(p0, p1, p2, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
                                    }

                                    set_array_elements(*d, p1, (void*) ESCAPE_CONTROL_SEQUENCE, (void*) ESCAPE_CONTROL_SEQUENCE_COUNT, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
                                    *dc = *dc + *ESCAPE_CONTROL_SEQUENCE_COUNT;
                                    set_array_elements(*d, p1, y, (void*) &yc, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
                                    *dc = *dc + yc;
                                    set_array_elements(*d, p1, (void*) SEMICOLON_UNICODE_CHARACTER_CODE_MODEL, (void*) PRIMITIVE_COUNT, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
                                    *dc = *dc + *PRIMITIVE_MEMORY_MODEL_COUNT;
                                    set_array_elements(*d, p1, x, (void*) &xc, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
                                    *dc = *dc + xc;
                                    set_array_elements(*d, p1, (void*) LATIN_CAPITAL_LETTER_H_UNICODE_CHARACTER_CODE_MODEL, (void*) PRIMITIVE_COUNT, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
                                    *dc = *dc + *PRIMITIVE_MEMORY_MODEL_COUNT;

                                    // Add attribute off control sequence.
                                    if ((*dc + *ESCAPE_CONTROL_SEQUENCE_COUNT + *ATTRIBUTE_OFF_CONTROL_SEQUENCE_COUNT) >= *ds) {

                                        // Set destination character array size.
                                        // CAUTION! Add constant in case *dc is zero!
                                        *ds = *dc * *WIDE_CHARACTER_VECTOR_REALLOCATION_FACTOR + *ESCAPE_CONTROL_SEQUENCE_COUNT + *ATTRIBUTE_OFF_CONTROL_SEQUENCE_COUNT;

                                        // Reallocate destination character array.
                                        reallocate_array(p0, p1, p2, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
                                    }

                                    set_array_elements(*d, p1, (void*) ESCAPE_CONTROL_SEQUENCE, (void*) ESCAPE_CONTROL_SEQUENCE_COUNT, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
                                    *dc = *dc + *ESCAPE_CONTROL_SEQUENCE_COUNT;
                                    set_array_elements(*d, p1, (void*) ATTRIBUTE_OFF_CONTROL_SEQUENCE, (void*) ATTRIBUTE_OFF_CONTROL_SEQUENCE_COUNT, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
                                    *dc = *dc + *ATTRIBUTE_OFF_CONTROL_SEQUENCE_COUNT;

                                    // Deallocate arrays.
                                    deallocate((void*) &y, (void*) &ys, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION_COUNT);
                                    deallocate((void*) &x, (void*) &xs, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION_COUNT);

                                    //
                                    // Add background and foreground properties.
                                    //
                                    // Example:
                                    // printf("\033[32mgreen colour\033[0mswitched off.")
                                    //

                                    // Encode background colour integer into character array.
        //??                            encode_integer((void*) &b, (void*) &bc, (void*) &bs, p6, (void*) PRIMITIVE_COUNT);
                                    // Encode foreground colour integer into character array.
        //??                            encode_integer((void*) &f, (void*) &fc, (void*) &fs, p7, (void*) PRIMITIVE_COUNT);

                                    if ((*dc
                                        + *ESCAPE_CONTROL_SEQUENCE_COUNT + *bc + *ATTRIBUTE_SUFFIX_CONTROL_SEQUENCE_COUNT
                                        + *ESCAPE_CONTROL_SEQUENCE_COUNT + *fc + *ATTRIBUTE_SUFFIX_CONTROL_SEQUENCE_COUNT) >= *ds) {

                                        // Set destination character array size.
                                        // CAUTION! Add constant in case *dc is zero!
                                        *ds = *dc * *WIDE_CHARACTER_VECTOR_REALLOCATION_FACTOR
                                            + *ESCAPE_CONTROL_SEQUENCE_COUNT + *bc + *ATTRIBUTE_SUFFIX_CONTROL_SEQUENCE_COUNT
                                            + *ESCAPE_CONTROL_SEQUENCE_COUNT + *fc + *ATTRIBUTE_SUFFIX_CONTROL_SEQUENCE_COUNT;

                                        // Reallocate destination character array.
                                        reallocate_array(p0, p1, p2, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
                                    }

                                    set_array_elements(*d, p1, (void*) ESCAPE_CONTROL_SEQUENCE, (void*) ESCAPE_CONTROL_SEQUENCE_COUNT, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
                                    *dc = *dc + *ESCAPE_CONTROL_SEQUENCE_COUNT;
                                    set_array_elements(*d, p1, p6, p7, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
                                    *dc = *dc + *bc;
                                    set_array_elements(*d, p1, (void*) ATTRIBUTE_SUFFIX_CONTROL_SEQUENCE, (void*) ATTRIBUTE_SUFFIX_CONTROL_SEQUENCE_COUNT, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
                                    *dc = *dc + *ATTRIBUTE_SUFFIX_CONTROL_SEQUENCE_COUNT;
                                    set_array_elements(*d, p1, (void*) ESCAPE_CONTROL_SEQUENCE, (void*) ESCAPE_CONTROL_SEQUENCE_COUNT, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
                                    *dc = *dc + *ESCAPE_CONTROL_SEQUENCE_COUNT;
                                    set_array_elements(*d, p1, p8, p9, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
                                    *dc = *dc + *fc;
                                    set_array_elements(*d, p1, (void*) ATTRIBUTE_SUFFIX_CONTROL_SEQUENCE, (void*) ATTRIBUTE_SUFFIX_CONTROL_SEQUENCE_COUNT, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
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
                                        + *PRIMITIVE_MEMORY_MODEL_COUNT) >= *ds) {

                                        // Set destination character array size.
                                        // CAUTION! Add constant in case *dc is zero!
                                        *ds = *dc * *WIDE_CHARACTER_VECTOR_REALLOCATION_FACTOR
                                            + *ESCAPE_CONTROL_SEQUENCE_COUNT + *HIDDEN_CONTROL_SEQUENCE_COUNT
                                            + *ESCAPE_CONTROL_SEQUENCE_COUNT + *INVERSE_CONTROL_SEQUENCE_COUNT
                                            + *ESCAPE_CONTROL_SEQUENCE_COUNT + *BLINK_CONTROL_SEQUENCE_COUNT
                                            + *ESCAPE_CONTROL_SEQUENCE_COUNT + *UNDERLINE_CONTROL_SEQUENCE_COUNT
                                            + *ESCAPE_CONTROL_SEQUENCE_COUNT + *BOLD_CONTROL_SEQUENCE_COUNT
                                            + *PRIMITIVE_MEMORY_MODEL_COUNT;

                                        // Reallocate destination character array.
                                        reallocate_array(p0, p1, p2, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
                                    }

                                    // The comparison result.
                                    int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

                                    // Compare hidden property.
                                    compare_arrays(p10, (void*) PRIMITIVE_COUNT, (void*) TRUE_BOOLEAN, (void*) PRIMITIVE_COUNT, (void*) &r, (void*) INTEGER_ARRAY);

                                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                                        // Set hidden property.
                                        set_array_elements(*d, p1, (void*) ESCAPE_CONTROL_SEQUENCE, (void*) ESCAPE_CONTROL_SEQUENCE_COUNT, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
                                        *dc = *dc + *ESCAPE_CONTROL_SEQUENCE_COUNT;
                                        set_array_elements(*d, p1, (void*) HIDDEN_CONTROL_SEQUENCE, (void*) HIDDEN_CONTROL_SEQUENCE_COUNT, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
                                        *dc = *dc + *HIDDEN_CONTROL_SEQUENCE_COUNT;
                                    }

                                    // Reset comparison result.
                                    r = *NUMBER_0_INTEGER_MEMORY_MODEL;

                                    // Compare inverse property.
                                    compare_arrays(p11, (void*) PRIMITIVE_COUNT, (void*) TRUE_BOOLEAN, (void*) PRIMITIVE_COUNT, (void*) &r, (void*) INTEGER_ARRAY);

                                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                                        // Set inverse property.
                                        set_array_elements(*d, p1, (void*) ESCAPE_CONTROL_SEQUENCE, (void*) ESCAPE_CONTROL_SEQUENCE_COUNT, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
                                        *dc = *dc + *ESCAPE_CONTROL_SEQUENCE_COUNT;
                                        set_array_elements(*d, p1, (void*) INVERSE_CONTROL_SEQUENCE, (void*) INVERSE_CONTROL_SEQUENCE_COUNT, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
                                        *dc = *dc + *INVERSE_CONTROL_SEQUENCE_COUNT;
                                    }

                                    // Reset comparison result.
                                    r = *NUMBER_0_INTEGER_MEMORY_MODEL;

                                    // Compare blink property.
                                    compare_arrays(p12, (void*) PRIMITIVE_COUNT, (void*) TRUE_BOOLEAN, (void*) PRIMITIVE_COUNT, (void*) &r, (void*) INTEGER_ARRAY);

                                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                                        // Set blink property.
                                        set_array_elements(*d, p1, (void*) ESCAPE_CONTROL_SEQUENCE, (void*) ESCAPE_CONTROL_SEQUENCE_COUNT, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
                                        *dc = *dc + *ESCAPE_CONTROL_SEQUENCE_COUNT;
                                        set_array_elements(*d, p1, (void*) BLINK_CONTROL_SEQUENCE, (void*) BLINK_CONTROL_SEQUENCE_COUNT, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
                                        *dc = *dc + *BLINK_CONTROL_SEQUENCE_COUNT;
                                    }

                                    // Reset comparison result.
                                    r = *NUMBER_0_INTEGER_MEMORY_MODEL;

                                    // Compare underline property.
                                    compare_arrays(p13, (void*) PRIMITIVE_COUNT, (void*) TRUE_BOOLEAN, (void*) PRIMITIVE_COUNT, (void*) &r, (void*) INTEGER_ARRAY);

                                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                                        // Set underline property.
                                        set_array_elements(*d, p1, (void*) ESCAPE_CONTROL_SEQUENCE, (void*) ESCAPE_CONTROL_SEQUENCE_COUNT, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
                                        *dc = *dc + *ESCAPE_CONTROL_SEQUENCE_COUNT;
                                        set_array_elements(*d, p1, (void*) UNDERLINE_CONTROL_SEQUENCE, (void*) UNDERLINE_CONTROL_SEQUENCE_COUNT, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
                                        *dc = *dc + *UNDERLINE_CONTROL_SEQUENCE_COUNT;
                                    }

                                    // Reset comparison result.
                                    r = *NUMBER_0_INTEGER_MEMORY_MODEL;

                                    // Compare bold property.
                                    compare_arrays(p14, (void*) PRIMITIVE_COUNT, (void*) TRUE_BOOLEAN, (void*) PRIMITIVE_COUNT, (void*) &r, (void*) INTEGER_ARRAY);

                                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                                        // Set bold property.
                                        set_array_elements(*d, p1, (void*) ESCAPE_CONTROL_SEQUENCE, (void*) ESCAPE_CONTROL_SEQUENCE_COUNT, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
                                        *dc = *dc + *ESCAPE_CONTROL_SEQUENCE_COUNT;
                                        set_array_elements(*d, p1, (void*) BOLD_CONTROL_SEQUENCE, (void*) BOLD_CONTROL_SEQUENCE_COUNT, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
                                        *dc = *dc + *BOLD_CONTROL_SEQUENCE_COUNT;
                                    }

                                    // Set character.
                                    set_array_elements(*d, p1, p15, (void*) PRIMITIVE_COUNT, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
                                    *dc = *dc + *PRIMITIVE_MEMORY_MODEL_COUNT;

                                } else {

                                    log_terminated_message((void*) WARNING_LEVEL_LOG_MODEL, (void*) L"Could not encode gnu/linux console properties. The character is null.");
                                }

                            } else {

                                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not encode gnu/linux console properties. The destination is null.");
                            }

                        } else {

                            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not encode gnu/linux console properties. The destination count is null.");
                        }

                    } else {

                        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not encode gnu/linux console properties. The destination size is null.");
                    }

                } else {

                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not encode gnu/linux console properties. The source y is null.");
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not encode gnu/linux console properties. The source x is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not encode gnu/linux console properties. The background count is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not encode gnu/linux console properties. The foreground count is null.");
    }
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

                                compare_arrays(p6, p7, (void*) TUI_LINE_BORDER_MODEL, (void*) TUI_LINE_BORDER_MODEL_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

                                if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                                    *hc = *BOX_DRAWINGS_LIGHT_HORIZONTAL_UNICODE_CHARACTER_CODE_MODEL;
                                    *vc = *BOX_DRAWINGS_LIGHT_VERTICAL_UNICODE_CHARACTER_CODE_MODEL;
                                    *ltc = *BOX_DRAWINGS_LIGHT_DOWN_AND_RIGHT_UNICODE_CHARACTER_CODE_MODEL;
                                    *rtc = *BOX_DRAWINGS_LIGHT_DOWN_AND_LEFT_UNICODE_CHARACTER_CODE_MODEL;
                                    *lbc = *BOX_DRAWINGS_LIGHT_UP_AND_RIGHT_UNICODE_CHARACTER_CODE_MODEL;
                                    *rbc = *BOX_DRAWINGS_LIGHT_UP_AND_LEFT_UNICODE_CHARACTER_CODE_MODEL;
                                }
                            }

                            if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                                compare_arrays(p6, p7, (void*) TUI_ROUND_LINE_BORDER_MODEL, (void*) TUI_ROUND_LINE_BORDER_MODEL_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

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

                                compare_arrays(p6, p7, (void*) TUI_DOUBLE_LINE_BORDER_MODEL, (void*) TUI_DOUBLE_LINE_BORDER_MODEL_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

                                if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                                    *hc = *BOX_DRAWINGS_DOUBLE_HORIZONTAL_UNICODE_CHARACTER_CODE_MODEL;
                                    *vc = *BOX_DRAWINGS_DOUBLE_VERTICAL_UNICODE_CHARACTER_CODE_MODEL;
                                    *ltc = *BOX_DRAWINGS_DOUBLE_DOWN_AND_RIGHT_UNICODE_CHARACTER_CODE_MODEL;
                                    *rtc = *BOX_DRAWINGS_DOUBLE_DOWN_AND_LEFT_UNICODE_CHARACTER_CODE_MODEL;
                                    *lbc = *BOX_DRAWINGS_DOUBLE_UP_AND_RIGHT_UNICODE_CHARACTER_CODE_MODEL;
                                    *rbc = *BOX_DRAWINGS_DOUBLE_UP_AND_LEFT_UNICODE_CHARACTER_CODE_MODEL;
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
                            wchar_t* c = SPACE_UNICODE_CHARACTER_CODE_MODEL;

                            while (*NUMBER_1_INTEGER) {

                                if (z >= zl) {

                                    break;
                                }

                                while (*NUMBER_1_INTEGER) {

                                    if (y >= yl) {

                                        break;
                                    }

                                    while (*NUMBER_1_INTEGER) {

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
                                                    get_element(p3, (void*) &ci, (void*) &c, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION_COUNT);
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

                                                } else if (x == (xl - *NUMBER_1_INTEGER)) {

                                                    // Encode right top border character using escape codes.
                                                    encode_gnu_linux_console_character(p0, p1, p2, &x, &y, &z, p10, p11, p12, p13, p5, p6, p7, p8, p9, &rtc);

                                                } else {

                                                    // Encode horizontal border character using escape codes.
                                                    encode_gnu_linux_console_character(p0, p1, p2, &x, &y, &z, p10, p11, p12, p13, p5, p6, p7, p8, p9, &hc);
                                                }

                                            } else if (y == (yl - *NUMBER_1_INTEGER)) {

                                                if (x == *px) {

                                                    // Encode left bottom border character using escape codes.
                                                    encode_gnu_linux_console_character(p0, p1, p2, &x, &y, &z, p10, p11, p12, p13, p5, p6, p7, p8, p9, &lbc);

                                                } else if (x == (xl - *NUMBER_1_INTEGER)) {

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

                                                } else if (x == (xl - *NUMBER_1_INTEGER)) {

                                                    // Encode right bottom border character using escape codes.
                                                    encode_gnu_linux_console_character(p0, p1, p2, &x, &y, &z, p10, p11, p12, p13, p5, p6, p7, p8, p9, &vc);

                                                } else {

                                                    if (cc != *NULL_POINTER_MEMORY_MODEL) {

                                                        // Calculate character index.
                                                        // CAUTION! Subtract one because of the border.
                                                        ci = x - *px - *NUMBER_1_INTEGER;

                                                        if (ci < *cc) {

                                                            // Get character value at position x.
                                                            get_element(p3, (void*) &ci, (void*) &c, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION_COUNT);
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
                                        c = SPACE_UNICODE_CHARACTER_CODE_MODEL;

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

        compare_arrays(p12, p13, (void*) UI_NORTH_CELL_MODEL, (void*) UI_NORTH_CELL_MODEL_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            // Set cell coordinates.
            *cpx = *fapx;
            *cpy = *fapy;
            *cpz = *fapz;
            *csx = *fasx;
//??            *csy = *NUMBER_20_INTEGER;
            *csz = *fasz;
            // Set free area coordinates.
            *fapy = *fapy + *csy;
            *fasy = *fasy - *csy;
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(p12, p13, (void*) UI_SOUTH_CELL_MODEL, (void*) UI_SOUTH_CELL_MODEL_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            // Set cell coordinates.
            *cpx = *fapx;
            *cpy = *fapy + (*fasy - *csy);
            *cpz = *fapz;
            *csx = *fasx;
//??            *csy = *NUMBER_20_INTEGER;
            *csz = *fasz;
            // Set free area coordinates.
            *fasy = *fasy - *csy;
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(p12, p13, (void*) UI_WEST_CELL_MODEL, (void*) UI_WEST_CELL_MODEL_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            // Set cell coordinates.
            *cpx = *fapx;
            *cpy = *fapy;
            *cpz = *fapz;
//??            *csx = *NUMBER_20_INTEGER;
            *csy = *fasy;
            *csz = *fasz;
            // Set free area coordinates.
            *fapx = *fapx + *csx;
            *fasx = *fasx - *csx;
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(p12, p13, (void*) UI_EAST_CELL_MODEL, (void*) UI_EAST_CELL_MODEL_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            // Set cell coordinates.
            *cpx = *fapx + (*fasx - *csx);
            *cpy = *fapy;
            *cpz = *fapz;
//??            *csx = *NUMBER_20_INTEGER;
            *csy = *fasy;
            *csz = *fasz;
            // Set free area coordinates.
            *fasx = *fasx - *csx;
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(p12, p13, (void*) UI_CENTRE_CELL_MODEL, (void*) UI_CENTRE_CELL_MODEL_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

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

        compare_arrays(p20, p21, (void*) UI_COORDINATES_LAYOUT_MODEL, (void*) UI_COORDINATES_LAYOUT_MODEL_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            // Determine new position and size coordinates for part.
            encode_gnu_linux_console_rectangle_coordinates_layout(p0, p1, p2, p3, p4, p5, p12, p13, p14, p15, p16, p17);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(p20, p21, (void*) UI_COMPASS_LAYOUT_MODEL, (void*) UI_COMPASS_LAYOUT_MODEL_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

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
    get_element(p14, (void*) UI_POSITION_X_INDEX, (void*) &px, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
    get_element(p14, (void*) UI_POSITION_Y_INDEX, (void*) &py, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
    get_element(p14, (void*) UI_POSITION_Z_INDEX, (void*) &pz, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
    // Get part size x, y, z.
    get_element(p16, (void*) UI_SIZE_X_INDEX, (void*) &sx, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
    get_element(p16, (void*) UI_SIZE_Y_INDEX, (void*) &sy, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
    get_element(p16, (void*) UI_SIZE_Z_INDEX, (void*) &sz, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);

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
        get_element(p18, (void*) UI_POSITION_X_INDEX, (void*) &wpmx, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
        get_element(p18, (void*) UI_POSITION_Y_INDEX, (void*) &wpmy, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
        get_element(p18, (void*) UI_POSITION_Z_INDEX, (void*) &wpmz, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
        // Determine source whole size coordinates.
        get_element(p20, (void*) UI_SIZE_X_INDEX, (void*) &wsmx, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
        get_element(p20, (void*) UI_SIZE_Y_INDEX, (void*) &wsmy, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
        get_element(p20, (void*) UI_SIZE_Z_INDEX, (void*) &wsmz, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);

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

    if (p4 != *NULL_POINTER_MEMORY_MODEL) {

        int* sc = (int*) p4;

        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Encode gnu/linux console shape.");

        // The character.
        void* c = *NULL_POINTER_MEMORY_MODEL;
        int cc = *NUMBER_0_INTEGER_MEMORY_MODEL;
        size_t cs = *NUMBER_0_INTEGER_MEMORY_MODEL;
        // The hidden property.
        int h = *NUMBER_0_INTEGER_MEMORY_MODEL;
        // The inverse property.
        int i = *NUMBER_0_INTEGER_MEMORY_MODEL;
        // The blink property.
        int bl = *NUMBER_0_INTEGER_MEMORY_MODEL;
        // The underline property.
        int u = *NUMBER_0_INTEGER_MEMORY_MODEL;
        // The bold property.
        int b = *NUMBER_0_INTEGER_MEMORY_MODEL;
        // The background colour.
        void* bg = *NULL_POINTER_MEMORY_MODEL;
        int bgc = *NUMBER_0_INTEGER_MEMORY_MODEL;
        int bgs = *NUMBER_0_INTEGER_MEMORY_MODEL;
        // The foreground colour.
        void* fg = *NULL_POINTER_MEMORY_MODEL;
        int fgc = *NUMBER_0_INTEGER_MEMORY_MODEL;
        int fgs = *NUMBER_0_INTEGER_MEMORY_MODEL;

        //?? TODO: These values should later be given as boolean "true" or "false".
        //?? Currently, they have to be given as "0" or "1" in CYBOL.
        //?? Change this later by transforming boolean into integer values!
        set_element(&h, (void*) PRIMITIVE_VALUE_INDEX, p7, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
        set_element(&i, (void*) PRIMITIVE_VALUE_INDEX, p9, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
        set_element(&bl, (void*) PRIMITIVE_VALUE_INDEX, p11, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
        set_element(&u, (void*) PRIMITIVE_VALUE_INDEX, p13, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
        set_element(&b, (void*) PRIMITIVE_VALUE_INDEX, p15, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
        // Map colour names to control sequences.
        encode((void*) &bg, (void*) &bgc, (void*) &bgs, *NULL_POINTER, *NULL_POINTER, *NULL_POINTER, *NULL_POINTER, p17, p18,
            *NULL_POINTER, *NULL_POINTER, *NULL_POINTER, *NULL_POINTER, (void*) TERMINAL_BACKGROUND_ABSTRACTION, (void*) TERMINAL_BACKGROUND_ABSTRACTION_COUNT);
        encode((void*) &fg, (void*) &fgc, (void*) &fgs, *NULL_POINTER, *NULL_POINTER, *NULL_POINTER, *NULL_POINTER, p19, p20,
            *NULL_POINTER, *NULL_POINTER, *NULL_POINTER, *NULL_POINTER, (void*) TERMINAL_FOREGROUND_ABSTRACTION, (void*) TERMINAL_FOREGROUND_ABSTRACTION_COUNT);

        // The comparison result.
        int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            compare_arrays(p5, p6, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

            if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                // Set character parameter to be handed over.
                c = p3;
                cc = *sc;
            }
        }

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            compare_arrays(p5, p6, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

            if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                // The temporary character array.
                void* tmp = *NULL_POINTER_MEMORY_MODEL;
                int tmps = *sc + *NUMBER_1_INTEGER;

                // Allocate temporary character array.
                allocate((void*) &tmp, (void*) &tmps, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT);

                // Set temporary character array by first copying the
                // given array and then adding the null termination character.
                set_array_elements(tmp, (void*) NUMBER_0_INTEGER, p3, p4, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
                set_array_elements(tmp, p4, (void*) NULL_CONTROL_CHARACTER_CODE, (void*) PRIMITIVE_COUNT, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

                // Initialise temporary wide character string size.
                // CAUTION! One extra place is added for the null termination character.
                cs = *sc + *NUMBER_100_INTEGER;

                // Allocate temporary wide character string.
                allocate((void*) &c, (void*) &cs, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION_COUNT);

                // Set character parameter to be handed over.
                // The temporary wide character string count is returned.
#ifdef CYGWIN_ENVIRONMENT
                cc = wsprintfW((wchar_t*) c, L"%s", (char*) tmp);
/* CYGWIN_ENVIRONMENT */
#else
                cc = swprintf((wchar_t*) c, cs, L"%s", (char*) tmp);
/* CYGWIN_ENVIRONMENT */
#endif

                // Deallocate temporary character array.
                deallocate((void*) &tmp, (void*) &tmps, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT);
            }
        }

        // If the part model is neither of abstraction "wide_character" nor of
        // abstraction "character" (e.g. a "compound"), the parameter to be
        // handed over remains a null pointer.

        // Reset comparison result.
        r = *NUMBER_0_INTEGER_MEMORY_MODEL;

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            compare_arrays(p35, p36, (void*) UI_RECTANGLE_SHAPE_MODEL, (void*) UI_RECTANGLE_SHAPE_MODEL_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

            if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                encode_gnu_linux_console_coordinates(p0, p1, p2, c, (void*) &cc,
                    &h, &i, &bl, &u, &b,
                    bg, (void*) &bgc, fg, (void*) &fgc, p21, p22, p23, p24,
                    p25, p26, p27, p28, p29, p30, p31, p32, p33, p34);
            }
        }

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            compare_arrays(p35, p36, (void*) UI_CIRCLE_SHAPE_MODEL, (void*) UI_CIRCLE_SHAPE_MODEL_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

            if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

    /*??
                encode_gnu_linux_console_coordinates(p0, p1, p2, c, cc, &h, &i, &bl, &u, &b,
                    bg, (void*) &bgc, fg, (void*) &fgc, p21, p22, p23, p24,
                    p25, p26, p27, p28, p29, p30, p31, p32, p33, p34);
    */
            }
        }

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            compare_arrays(p35, p36, (void*) UI_POLYGON_SHAPE_MODEL, (void*) UI_POLYGON_SHAPE_MODEL_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

            if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

    /*??
                encode_gnu_linux_console_coordinates(p0, p1, p2, c, cc, &h, &i, &bl, &u, &b,
                    bg, (void*) &bgc, fg, (void*) &fgc, p21, p22, p23, p24,
                    p25, p26, p27, p28, p29, p30, p31, p32, p33, p34);
    */
            }
        }

        // Reset comparison result.
        r = *NUMBER_0_INTEGER_MEMORY_MODEL;

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            compare_arrays(p5, p6, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

            if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                // Deallocate temporary wide character string.
                deallocate((void*) &c, (void*) &cs, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION_COUNT);
            }
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not encode gnu/linux console shape. The character count is null.");
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
    void** n = NULL_POINTER;
    void** nc = NULL_POINTER;
    void** ns = NULL_POINTER;
    void** a = NULL_POINTER;
    void** ac = NULL_POINTER;
    void** as = NULL_POINTER;
    void** m = NULL_POINTER;
    void** mc = NULL_POINTER;
    void** ms = NULL_POINTER;
    void** d = NULL_POINTER;
    void** dc = NULL_POINTER;
    void** ds = NULL_POINTER;
    // The source part super properties name, abstraction, model, details.
    void** supern = NULL_POINTER;
    void** supernc = NULL_POINTER;
    void** superns = NULL_POINTER;
    void** supera = NULL_POINTER;
    void** superac = NULL_POINTER;
    void** superas = NULL_POINTER;
    void** superm = NULL_POINTER;
    void** supermc = NULL_POINTER;
    void** superms = NULL_POINTER;
    void** superd = NULL_POINTER;
    void** superdc = NULL_POINTER;
    void** superds = NULL_POINTER;
    // The source part shape name, abstraction, model, details.
    void** shn = NULL_POINTER;
    void** shnc = NULL_POINTER;
    void** shns = NULL_POINTER;
    void** sha = NULL_POINTER;
    void** shac = NULL_POINTER;
    void** shas = NULL_POINTER;
    void** shm = NULL_POINTER;
    void** shmc = NULL_POINTER;
    void** shms = NULL_POINTER;
    void** shd = NULL_POINTER;
    void** shdc = NULL_POINTER;
    void** shds = NULL_POINTER;
    // The source part layout name, abstraction, model, details.
    void** ln = NULL_POINTER;
    void** lnc = NULL_POINTER;
    void** lns = NULL_POINTER;
    void** la = NULL_POINTER;
    void** lac = NULL_POINTER;
    void** las = NULL_POINTER;
    void** lm = NULL_POINTER;
    void** lmc = NULL_POINTER;
    void** lms = NULL_POINTER;
    void** ld = NULL_POINTER;
    void** ldc = NULL_POINTER;
    void** lds = NULL_POINTER;
    // The source part cell name, abstraction, model, details.
    void** cn = NULL_POINTER;
    void** cnc = NULL_POINTER;
    void** cns = NULL_POINTER;
    void** ca = NULL_POINTER;
    void** cac = NULL_POINTER;
    void** cas = NULL_POINTER;
    void** cm = NULL_POINTER;
    void** cmc = NULL_POINTER;
    void** cms = NULL_POINTER;
    void** cd = NULL_POINTER;
    void** cdc = NULL_POINTER;
    void** cds = NULL_POINTER;
    // The source part position name, abstraction, model, details.
    void** pn = NULL_POINTER;
    void** pnc = NULL_POINTER;
    void** pns = NULL_POINTER;
    void** pa = NULL_POINTER;
    void** pac = NULL_POINTER;
    void** pas = NULL_POINTER;
    void** pm = NULL_POINTER;
    void** pmc = NULL_POINTER;
    void** pms = NULL_POINTER;
    void** pd = NULL_POINTER;
    void** pdc = NULL_POINTER;
    void** pds = NULL_POINTER;
    // The source part size name, abstraction, model, details.
    void** sn = NULL_POINTER;
    void** snc = NULL_POINTER;
    void** sns = NULL_POINTER;
    void** sa = NULL_POINTER;
    void** sac = NULL_POINTER;
    void** sas = NULL_POINTER;
    void** sm = NULL_POINTER;
    void** smc = NULL_POINTER;
    void** sms = NULL_POINTER;
    void** sd = NULL_POINTER;
    void** sdc = NULL_POINTER;
    void** sds = NULL_POINTER;
    // The source part background colour name, abstraction, model, details.
    void** bgn = NULL_POINTER;
    void** bgnc = NULL_POINTER;
    void** bgns = NULL_POINTER;
    void** bga = NULL_POINTER;
    void** bgac = NULL_POINTER;
    void** bgas = NULL_POINTER;
    void** bgm = NULL_POINTER;
    void** bgmc = NULL_POINTER;
    void** bgms = NULL_POINTER;
    void** bgd = NULL_POINTER;
    void** bgdc = NULL_POINTER;
    void** bgds = NULL_POINTER;
    // The source part foreground colour name, abstraction, model, details.
    void** fgn = NULL_POINTER;
    void** fgnc = NULL_POINTER;
    void** fgns = NULL_POINTER;
    void** fga = NULL_POINTER;
    void** fgac = NULL_POINTER;
    void** fgas = NULL_POINTER;
    void** fgm = NULL_POINTER;
    void** fgmc = NULL_POINTER;
    void** fgms = NULL_POINTER;
    void** fgd = NULL_POINTER;
    void** fgdc = NULL_POINTER;
    void** fgds = NULL_POINTER;
    // The source part border name, abstraction, model, details.
    void** bon = NULL_POINTER;
    void** bonc = NULL_POINTER;
    void** bons = NULL_POINTER;
    void** boa = NULL_POINTER;
    void** boac = NULL_POINTER;
    void** boas = NULL_POINTER;
    void** bom = NULL_POINTER;
    void** bomc = NULL_POINTER;
    void** boms = NULL_POINTER;
    void** bod = NULL_POINTER;
    void** bodc = NULL_POINTER;
    void** bods = NULL_POINTER;
    // The source part hidden property name, abstraction, model, details.
    void** hn = NULL_POINTER;
    void** hnc = NULL_POINTER;
    void** hns = NULL_POINTER;
    void** ha = NULL_POINTER;
    void** hac = NULL_POINTER;
    void** has = NULL_POINTER;
    void** hm = NULL_POINTER;
    void** hmc = NULL_POINTER;
    void** hms = NULL_POINTER;
    void** hd = NULL_POINTER;
    void** hdc = NULL_POINTER;
    void** hds = NULL_POINTER;
    // The source part inverse property name, abstraction, model, details.
    void** in = NULL_POINTER;
    void** inc = NULL_POINTER;
    void** ins = NULL_POINTER;
    void** ia = NULL_POINTER;
    void** iac = NULL_POINTER;
    void** ias = NULL_POINTER;
    void** im = NULL_POINTER;
    void** imc = NULL_POINTER;
    void** ims = NULL_POINTER;
    void** id = NULL_POINTER;
    void** idc = NULL_POINTER;
    void** ids = NULL_POINTER;
    // The source part blink property name, abstraction, model, details.
    void** bln = NULL_POINTER;
    void** blnc = NULL_POINTER;
    void** blns = NULL_POINTER;
    void** bla = NULL_POINTER;
    void** blac = NULL_POINTER;
    void** blas = NULL_POINTER;
    void** blm = NULL_POINTER;
    void** blmc = NULL_POINTER;
    void** blms = NULL_POINTER;
    void** bld = NULL_POINTER;
    void** bldc = NULL_POINTER;
    void** blds = NULL_POINTER;
    // The source part underline property name, abstraction, model, details.
    void** un = NULL_POINTER;
    void** unc = NULL_POINTER;
    void** uns = NULL_POINTER;
    void** ua = NULL_POINTER;
    void** uac = NULL_POINTER;
    void** uas = NULL_POINTER;
    void** um = NULL_POINTER;
    void** umc = NULL_POINTER;
    void** ums = NULL_POINTER;
    void** ud = NULL_POINTER;
    void** udc = NULL_POINTER;
    void** uds = NULL_POINTER;
    // The source part bold property name, abstraction, model, details.
    void** bn = NULL_POINTER;
    void** bnc = NULL_POINTER;
    void** bns = NULL_POINTER;
    void** ba = NULL_POINTER;
    void** bac = NULL_POINTER;
    void** bas = NULL_POINTER;
    void** bm = NULL_POINTER;
    void** bmc = NULL_POINTER;
    void** bms = NULL_POINTER;
    void** bd = NULL_POINTER;
    void** bdc = NULL_POINTER;
    void** bds = NULL_POINTER;
    // The source whole position name, abstraction, model, details.
    void** wpn = NULL_POINTER;
    void** wpnc = NULL_POINTER;
    void** wpns = NULL_POINTER;
    void** wpa = NULL_POINTER;
    void** wpac = NULL_POINTER;
    void** wpas = NULL_POINTER;
    void** wpm = NULL_POINTER;
    void** wpmc = NULL_POINTER;
    void** wpms = NULL_POINTER;
    void** wpd = NULL_POINTER;
    void** wpdc = NULL_POINTER;
    void** wpds = NULL_POINTER;
    // The source whole size name, abstraction, model, details.
    void** wsn = NULL_POINTER;
    void** wsnc = NULL_POINTER;
    void** wsns = NULL_POINTER;
    void** wsa = NULL_POINTER;
    void** wsac = NULL_POINTER;
    void** wsas = NULL_POINTER;
    void** wsm = NULL_POINTER;
    void** wsmc = NULL_POINTER;
    void** wsms = NULL_POINTER;
    void** wsd = NULL_POINTER;
    void** wsdc = NULL_POINTER;
    void** wsds = NULL_POINTER;

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
    int f = *NUMBER_MINUS_1_INTEGER;
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
        get_universal_compound_element_by_name(p7, p8,
            (void*) SUPER_PROPERTIES_NAME, (void*) SUPER_PROPERTIES_NAME_COUNT,
            (void*) &supern, (void*) &supernc, (void*) &superns,
            (void*) &supera, (void*) &superac, (void*) &superas,
            (void*) &superm, (void*) &supermc, (void*) &superms,
            (void*) &superd, (void*) &superdc, (void*) &superds,
            p13, p14);
        // Get part shape from details.
        get_universal_compound_element_by_name(p7, p8,
            (void*) UI_SHAPE_NAME, (void*) UI_SHAPE_NAME_COUNT,
            (void*) &shn, (void*) &shnc, (void*) &shns,
            (void*) &sha, (void*) &shac, (void*) &shas,
            (void*) &shm, (void*) &shmc, (void*) &shms,
            (void*) &shd, (void*) &shdc, (void*) &shds,
            p13, p14);
        // Get source part layout from details.
        get_universal_compound_element_by_name(p7, p8,
            (void*) UI_LAYOUT_NAME, (void*) UI_LAYOUT_NAME_COUNT,
            (void*) &ln, (void*) &lnc, (void*) &lns,
            (void*) &la, (void*) &lac, (void*) &las,
            (void*) &lm, (void*) &lmc, (void*) &lms,
            (void*) &ld, (void*) &ldc, (void*) &lds,
            p13, p14);
        // Get source part cell from details.
        get_universal_compound_element_by_name(p7, p8,
            (void*) UI_CELL_NAME, (void*) UI_CELL_NAME_COUNT,
            (void*) &cn, (void*) &cnc, (void*) &cns,
            (void*) &ca, (void*) &cac, (void*) &cas,
            (void*) &cm, (void*) &cmc, (void*) &cms,
            (void*) &cd, (void*) &cdc, (void*) &cds,
            p13, p14);
        // Get part position from details.
        get_universal_compound_element_by_name(p7, p8,
            (void*) UI_POSITION_NAME, (void*) UI_POSITION_NAME_COUNT,
            (void*) &pn, (void*) &pnc, (void*) &pns,
            (void*) &pa, (void*) &pac, (void*) &pas,
            (void*) &pm, (void*) &pmc, (void*) &pms,
            (void*) &pd, (void*) &pdc, (void*) &pds,
            p13, p14);
        // Get part size from details.
        get_universal_compound_element_by_name(p7, p8,
            (void*) UI_SIZE_NAME, (void*) UI_SIZE_NAME_COUNT,
            (void*) &sn, (void*) &snc, (void*) &sns,
            (void*) &sa, (void*) &sac, (void*) &sas,
            (void*) &sm, (void*) &smc, (void*) &sms,
            (void*) &sd, (void*) &sdc, (void*) &sds,
            p13, p14);
        // Get part background colour from details.
        get_universal_compound_element_by_name(p7, p8,
            (void*) UI_BACKGROUND_NAME, (void*) UI_BACKGROUND_NAME_COUNT,
            (void*) &bgn, (void*) &bgnc, (void*) &bgns,
            (void*) &bga, (void*) &bgac, (void*) &bgas,
            (void*) &bgm, (void*) &bgmc, (void*) &bgms,
            (void*) &bgd, (void*) &bgdc, (void*) &bgds,
            p13, p14);
        // Get part foreground colour from details.
        get_universal_compound_element_by_name(p7, p8,
            (void*) UI_FOREGROUND_NAME, (void*) UI_FOREGROUND_NAME_COUNT,
            (void*) &fgn, (void*) &fgnc, (void*) &fgns,
            (void*) &fga, (void*) &fgac, (void*) &fgas,
            (void*) &fgm, (void*) &fgmc, (void*) &fgms,
            (void*) &fgd, (void*) &fgdc, (void*) &fgds,
            p13, p14);
        // Get part border from details.
        get_universal_compound_element_by_name(p7, p8,
            (void*) TUI_BORDER_NAME, (void*) TUI_BORDER_NAME_COUNT,
            (void*) &bon, (void*) &bonc, (void*) &bons,
            (void*) &boa, (void*) &boac, (void*) &boas,
            (void*) &bom, (void*) &bomc, (void*) &boms,
            (void*) &bod, (void*) &bodc, (void*) &bods,
            p13, p14);
        // Get part hidden property from details.
        get_universal_compound_element_by_name(p7, p8,
            (void*) TUI_HIDDEN_NAME, (void*) TUI_HIDDEN_NAME_COUNT,
            (void*) &hn, (void*) &hnc, (void*) &hns,
            (void*) &ha, (void*) &hac, (void*) &has,
            (void*) &hm, (void*) &hmc, (void*) &hms,
            (void*) &hd, (void*) &hdc, (void*) &hds,
            p13, p14);
        // Get part inverse property from details.
        get_universal_compound_element_by_name(p7, p8,
            (void*) TUI_INVERSE_NAME, (void*) TUI_INVERSE_NAME_COUNT,
            (void*) &in, (void*) &inc, (void*) &ins,
            (void*) &ia, (void*) &iac, (void*) &ias,
            (void*) &im, (void*) &imc, (void*) &ims,
            (void*) &id, (void*) &idc, (void*) &ids,
            p13, p14);
        // Get part blink property from details.
        get_universal_compound_element_by_name(p7, p8,
            (void*) TUI_BLINK_NAME, (void*) TUI_BLINK_NAME_COUNT,
            (void*) &bln, (void*) &blnc, (void*) &blns,
            (void*) &bla, (void*) &blac, (void*) &blas,
            (void*) &blm, (void*) &blmc, (void*) &blms,
            (void*) &bld, (void*) &bldc, (void*) &blds,
            p13, p14);
        // Get part underline property from details.
        get_universal_compound_element_by_name(p7, p8,
            (void*) TUI_UNDERLINE_NAME, (void*) TUI_UNDERLINE_NAME_COUNT,
            (void*) &un, (void*) &unc, (void*) &uns,
            (void*) &ua, (void*) &uac, (void*) &uas,
            (void*) &um, (void*) &umc, (void*) &ums,
            (void*) &ud, (void*) &udc, (void*) &uds,
            p13, p14);
        // Get part bold property from details.
        get_universal_compound_element_by_name(p7, p8,
            (void*) TUI_BOLD_NAME, (void*) TUI_BOLD_NAME_COUNT,
            (void*) &bn, (void*) &bnc, (void*) &bns,
            (void*) &ba, (void*) &bac, (void*) &bas,
            (void*) &bm, (void*) &bmc, (void*) &bms,
            (void*) &bd, (void*) &bdc, (void*) &bds,
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
            get_universal_compound_element_by_name(*superm, *supermc,
                (void*) UI_SHAPE_NAME, (void*) UI_SHAPE_NAME_COUNT,
                (void*) &shn, (void*) &shnc, (void*) &shns,
                (void*) &sha, (void*) &shac, (void*) &shas,
                (void*) &shm, (void*) &shmc, (void*) &shms,
                (void*) &shd, (void*) &shdc, (void*) &shds,
                p13, p14);
        }

        if (*lm == *NULL_POINTER_MEMORY_MODEL) {

            // Get source part layout from details.
            get_universal_compound_element_by_name(*superm, *supermc,
                (void*) UI_LAYOUT_NAME, (void*) UI_LAYOUT_NAME_COUNT,
                (void*) &ln, (void*) &lnc, (void*) &lns,
                (void*) &la, (void*) &lac, (void*) &las,
                (void*) &lm, (void*) &lmc, (void*) &lms,
                (void*) &ld, (void*) &ldc, (void*) &lds,
                p13, p14);
        }

        if (*cm == *NULL_POINTER_MEMORY_MODEL) {

            // Get source part cell from details.
            get_universal_compound_element_by_name(*superm, *supermc,
                (void*) UI_CELL_NAME, (void*) UI_CELL_NAME_COUNT,
                (void*) &cn, (void*) &cnc, (void*) &cns,
                (void*) &ca, (void*) &cac, (void*) &cas,
                (void*) &cm, (void*) &cmc, (void*) &cms,
                (void*) &cd, (void*) &cdc, (void*) &cds,
                p13, p14);
        }

        if (*pm == *NULL_POINTER_MEMORY_MODEL) {

            // Get part position from super part.
            get_universal_compound_element_by_name(*superm, *supermc,
                (void*) UI_POSITION_NAME, (void*) UI_POSITION_NAME_COUNT,
                (void*) &pn, (void*) &pnc, (void*) &pns,
                (void*) &pa, (void*) &pac, (void*) &pas,
                (void*) &pm, (void*) &pmc, (void*) &pms,
                (void*) &pd, (void*) &pdc, (void*) &pds,
                p13, p14);
        }

        if (*sm == *NULL_POINTER_MEMORY_MODEL) {

            // Get part size from super part.
            get_universal_compound_element_by_name(*superm, *supermc,
                (void*) UI_SIZE_NAME, (void*) UI_SIZE_NAME_COUNT,
                (void*) &sn, (void*) &snc, (void*) &sns,
                (void*) &sa, (void*) &sac, (void*) &sas,
                (void*) &sm, (void*) &smc, (void*) &sms,
                (void*) &sd, (void*) &sdc, (void*) &sds,
                p13, p14);
        }

        if (*bgm == *NULL_POINTER_MEMORY_MODEL) {

            // Get part background colour from super part.
            get_universal_compound_element_by_name(*superm, *supermc,
                (void*) UI_BACKGROUND_NAME, (void*) UI_BACKGROUND_NAME_COUNT,
                (void*) &bgn, (void*) &bgnc, (void*) &bgns,
                (void*) &bga, (void*) &bgac, (void*) &bgas,
                (void*) &bgm, (void*) &bgmc, (void*) &bgms,
                (void*) &bgd, (void*) &bgdc, (void*) &bgds,
                p13, p14);
        }

        if (*fgm == *NULL_POINTER_MEMORY_MODEL) {

            // Get part foreground colour from super part.
            get_universal_compound_element_by_name(*superm, *supermc,
                (void*) UI_FOREGROUND_NAME, (void*) UI_FOREGROUND_NAME_COUNT,
                (void*) &fgn, (void*) &fgnc, (void*) &fgns,
                (void*) &fga, (void*) &fgac, (void*) &fgas,
                (void*) &fgm, (void*) &fgmc, (void*) &fgms,
                (void*) &fgd, (void*) &fgdc, (void*) &fgds,
                p13, p14);
        }

        if (*bom == *NULL_POINTER_MEMORY_MODEL) {

            // Get part border from super part.
            get_universal_compound_element_by_name(*superm, *supermc,
                (void*) TUI_BORDER_NAME, (void*) TUI_BORDER_NAME_COUNT,
                (void*) &bon, (void*) &bonc, (void*) &bons,
                (void*) &boa, (void*) &boac, (void*) &boas,
                (void*) &bom, (void*) &bomc, (void*) &boms,
                (void*) &bod, (void*) &bodc, (void*) &bods,
                p13, p14);
        }

        if (*hm == *NULL_POINTER_MEMORY_MODEL) {

            // Get part hidden property from super part.
            get_universal_compound_element_by_name(*superm, *supermc,
                (void*) TUI_HIDDEN_NAME, (void*) TUI_HIDDEN_NAME_COUNT,
                (void*) &hn, (void*) &hnc, (void*) &hns,
                (void*) &ha, (void*) &hac, (void*) &has,
                (void*) &hm, (void*) &hmc, (void*) &hms,
                (void*) &hd, (void*) &hdc, (void*) &hds,
                p13, p14);
        }

        if (*im == *NULL_POINTER_MEMORY_MODEL) {

            // Get part inverse property from super part.
            get_universal_compound_element_by_name(*superm, *supermc,
                (void*) TUI_INVERSE_NAME, (void*) TUI_INVERSE_NAME_COUNT,
                (void*) &in, (void*) &inc, (void*) &ins,
                (void*) &ia, (void*) &iac, (void*) &ias,
                (void*) &im, (void*) &imc, (void*) &ims,
                (void*) &id, (void*) &idc, (void*) &ids,
                p13, p14);
        }

        if (*blm == *NULL_POINTER_MEMORY_MODEL) {

            // Get part blink property from super part.
            get_universal_compound_element_by_name(*superm, *supermc,
                (void*) TUI_BLINK_NAME, (void*) TUI_BLINK_NAME_COUNT,
                (void*) &bln, (void*) &blnc, (void*) &blns,
                (void*) &bla, (void*) &blac, (void*) &blas,
                (void*) &blm, (void*) &blmc, (void*) &blms,
                (void*) &bld, (void*) &bldc, (void*) &blds,
                p13, p14);
        }

        if (*um == *NULL_POINTER_MEMORY_MODEL) {

            // Get part underline property from super part.
            get_universal_compound_element_by_name(*superm, *supermc,
                (void*) TUI_UNDERLINE_NAME, (void*) TUI_UNDERLINE_NAME_COUNT,
                (void*) &un, (void*) &unc, (void*) &uns,
                (void*) &ua, (void*) &uac, (void*) &uas,
                (void*) &um, (void*) &umc, (void*) &ums,
                (void*) &ud, (void*) &udc, (void*) &uds,
                p13, p14);
        }

        if (*bm == *NULL_POINTER_MEMORY_MODEL) {

            // Get part bold property from super part.
            get_universal_compound_element_by_name(*superm, *supermc,
                (void*) TUI_BOLD_NAME, (void*) TUI_BOLD_NAME_COUNT,
                (void*) &bn, (void*) &bnc, (void*) &bns,
                (void*) &ba, (void*) &bac, (void*) &bas,
                (void*) &bm, (void*) &bmc, (void*) &bms,
                (void*) &bd, (void*) &bdc, (void*) &bds,
                p13, p14);
        }

        // Get source whole position from details.
        get_universal_compound_element_by_name(p9, p10,
            (void*) UI_POSITION_NAME, (void*) UI_POSITION_NAME_COUNT,
            (void*) &wpn, (void*) &wpnc, (void*) &wpns,
            (void*) &wpa, (void*) &wpac, (void*) &wpas,
            (void*) &wpm, (void*) &wpmc, (void*) &wpms,
            (void*) &wpd, (void*) &wpdc, (void*) &wpds,
            p13, p14);

        // Get source whole size from details.
        get_universal_compound_element_by_name(p9, p10,
            (void*) UI_SIZE_NAME, (void*) UI_SIZE_NAME_COUNT,
            (void*) &wsn, (void*) &wsnc, (void*) &wsns,
            (void*) &wsa, (void*) &wsac, (void*) &wsas,
            (void*) &wsm, (void*) &wsmc, (void*) &wsms,
            (void*) &wsd, (void*) &wsdc, (void*) &wsds,
            p13, p14);

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

        compare_arrays(p3, p4, (void*) COMPOUND_ABSTRACTION, (void*) COMPOUND_ABSTRACTION_COUNT, (void*) &ar, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (ar != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            // The part model is a compound.

            if (p6 != *NULL_POINTER_MEMORY_MODEL) {

                int* sc = (int*) p6;

                // Iterate through compound parts.
                while (*NUMBER_1_INTEGER) {

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
                    compare_arrays(*n, *nc, en, (void*) &enc, (void*) &nr, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

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
                    n = NULL_POINTER;
                    nc = NULL_POINTER;
                    ns = NULL_POINTER;
                    a = NULL_POINTER;
                    ac = NULL_POINTER;
                    as = NULL_POINTER;
                    m = NULL_POINTER;
                    mc = NULL_POINTER;
                    ms = NULL_POINTER;
                    d = NULL_POINTER;
                    dc = NULL_POINTER;
                    ds = NULL_POINTER;

                    // Reset name comparison result.
                    nr = *NUMBER_0_INTEGER_MEMORY_MODEL;

                    // Increment loop count.
                    j++;
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not encode compound model into gnu/linux console control sequences. The source count parameter is null.");
            }
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not encode compound model into gnu/linux console control sequences. The hierarchical compound element name contains a meta element, while only part elements are permitted.");
    }
}

/* GNU_LINUX_CONSOLE_CONVERTER_SOURCE */
#endif
