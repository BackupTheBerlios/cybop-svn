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

#ifndef GNU_LINUX_CONSOLE_DECODER_SOURCE
#define GNU_LINUX_CONSOLE_DECODER_SOURCE

#ifdef CYGWIN_ENVIRONMENT
#include <windows.h>
/* CYGWIN_ENVIRONMENT */
#endif

#include <stdio.h>
#include <wchar.h>
#include "../../../constant/abstraction/cybol/text_cybol_abstraction.c"
#include "../../../constant/abstraction/memory/memory_abstraction.c"
#include "../../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../../constant/abstraction/operation/primitive_operation_abstraction.c"
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
#include "../../../executor/modifier/overwriter/array_overwriter.c"
#include "../../../executor/accessor/getter.c"
#include "../../../executor/converter/decoder/integer_vector_decoder.c"
#include "../../../executor/converter/decoder/terminal_background_decoder.c"
#include "../../../executor/converter/decoder/terminal_foreground_decoder.c"
#include "../../../logger/logger.c"
#include "../../../variable/type_size/integral_type_size.c"

/**
 * Decodes a gnu/linux console escape control sequence into a command.
 *
 * This function changes the escape control sequences into real names as defined by CYBOL.
 * Example: The ARROW_UP_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL (ESC[A sequence) gets converted into the
 * constant ARROW_UP_KEYBOARD_KEY_CYBOL_NAME with the value "arrow_up", which is used so in CYBOL files.
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

        compare_all_array((void*) &r, p3, (void*) ARROW_UP_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p4, (void*) ARROW_UP_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            overwrite_array(p0, (void*) ARROW_UP_KEYBOARD_KEY_CYBOL_NAME, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) ARROW_UP_KEYBOARD_KEY_CYBOL_NAME_COUNT, p1, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, p1, p2);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, p3, (void*) ARROW_DOWN_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p4, (void*) ARROW_DOWN_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            overwrite_array(p0, (void*) ARROW_DOWN_KEYBOARD_KEY_CYBOL_NAME, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) ARROW_DOWN_KEYBOARD_KEY_CYBOL_NAME_COUNT, p1, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, p1, p2);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, p3, (void*) ARROW_LEFT_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p4, (void*) ARROW_LEFT_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            overwrite_array(p0, (void*) ARROW_LEFT_KEYBOARD_KEY_CYBOL_NAME, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) ARROW_LEFT_KEYBOARD_KEY_CYBOL_NAME_COUNT, p1, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, p1, p2);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, p3, (void*) ARROW_RIGHT_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p4, (void*) ARROW_RIGHT_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            overwrite_array(p0, (void*) ARROW_RIGHT_KEYBOARD_KEY_CYBOL_NAME, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) ARROW_RIGHT_KEYBOARD_KEY_CYBOL_NAME_COUNT, p1, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, p1, p2);
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
 * Example: The LINE_FEED_CONTROL_UNICODE_CHARACTER_CODE_MODEL (<enter> key) gets converted into the
 * constant ENTER_KEYBOARD_KEY_CYBOL_NAME with the value "enter", which is used so in CYBOL files.
 *
 * @param p0 the destination command (Hand over as reference!)
 * @param p1 the destination command count
 * @param p2 the destination command size
 * @param p3 the source character array
 * @param p4 the source character array count
 */
void decode_gnu_linux_console_character(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Decode gnu/linux console character.");

/*??
    fwprintf(stdout, L"TEST decode character p2: %i\n", *((int*) p2));
    fwprintf(stdout, L"TEST decode character p1: %i\n", *((int*) p1));
    fwprintf(stdout, L"TEST decode character p0: %ls\n", (wchar_t*) *((void**) p0));
*/

    // The comparison result.
    int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, p3, (void*) LINE_FEED_CONTROL_UNICODE_CHARACTER_CODE_MODEL, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p4, (void*) PRIMITIVE_MEMORY_MODEL_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            overwrite_array(p0, (void*) ENTER_KEYBOARD_KEY_CYBOL_NAME, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) ENTER_KEYBOARD_KEY_CYBOL_NAME_COUNT, p1, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, p1, p2);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, p3, (void*) ESCAPE_CONTROL_UNICODE_CHARACTER_CODE_MODEL, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p4, (void*) PRIMITIVE_MEMORY_MODEL_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            overwrite_array(p0, (void*) ESCAPE_KEYBOARD_KEY_CYBOL_NAME, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) ESCAPE_KEYBOARD_KEY_CYBOL_NAME_COUNT, p1, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, p1, p2);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

/*??
    fwprintf(stdout, L"TEST decode character cc: %i\n", *((int*) p4));
    fwprintf(stdout, L"TEST decode character c: %ls\n", (wchar_t*) p3);
*/

        // None of the control characters above matched.
        // Pass along character without modification.
        overwrite_array(p0, p3, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p4, p1, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, p1, p2);
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

/*??
    fwprintf(stdout, L"TEST decode 0 p4: %i\n", *((int*) p4));
    fwprintf(stdout, L"TEST decode 0 p3: %ls\n", (wchar_t*) p3);
    fwprintf(stdout, L"TEST decode s: %ls\n", (wchar_t*) p3);
*/

        // The comparison result.
        int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            if (*sc > *ESCAPE_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_COUNT) {

                // Only do the following comparison if the source array
                // is greater than the escape control sequence prefix,
                // since a value has to follow after the escape control sequence prefix.

                // CAUTION! Use the "ESCAPE_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_COUNT" for both comparison values,
                // since they would not be equal if their size differed.
                compare_all_array((void*) &r, p3, (void*) ESCAPE_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) ESCAPE_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_COUNT, (void*) ESCAPE_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_COUNT);

                if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    // Initialise temporary character sequence with pointer to the
                    // first character AFTER the escape control sequence prefix.
                    void* t = p3 + (*ESCAPE_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_COUNT * *WIDE_CHARACTER_INTEGRAL_TYPE_SIZE);
                    int tc = *sc - *ESCAPE_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_COUNT;

                    decode_gnu_linux_console_escape_control_sequence(p0, p1, p2, t, (void*) &tc);
                }
            }
        }

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            decode_gnu_linux_console_character(p0, p1, p2, p3, p4);
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode gnu/linux console. The source character array count is null.");
    }
}

/* GNU_LINUX_CONSOLE_DECODER_SOURCE */
#endif
