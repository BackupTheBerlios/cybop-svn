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
 * @version $RCSfile: terminal_foreground_converter.c,v $ $Revision: 1.8 $ $Date: 2008-09-14 21:29:47 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef TERMINAL_FOREGROUND_CONVERTER_SOURCE
#define TERMINAL_FOREGROUND_CONVERTER_SOURCE

#include "../../constant/abstraction/cybol/text_cybol_abstraction.c"
#include "../../constant/abstraction/memory/memory_abstraction.c"
#include "../../constant/model/cybol/colour/terminal_colour_cybol_model.c"
#include "../../constant/model/gnu_linux_console/escape_control_sequence_gnu_linux_console_model.c"
#include "../../constant/model/log/message_log_model.c"
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../logger/logger.c"
#include "../../memoriser/accessor.c"
#include "../../memoriser/array.c"

/**
 * Decodes the control sequence code into a terminal foreground colour name.
 *
 * @param p0 the destination colour name
 * @param p1 the destination colour name count
 * @param p2 the destination colour name size
 * @param p3 the source control sequence code
 * @param p4 the source control sequence code count
 */
void decode_terminal_foreground(void* p0, void* p1, void* p2, void* p3, void* p4) {
}

/**
 * Encodes the terminal foreground colour name into a control sequence code.
 *
 * @param p0 the destination control sequence code
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source colour name
 * @param p4 the source count
 */
void encode_terminal_foreground(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p1 != *NULL_POINTER_MEMORY_MODEL) {

        int* dc = (int*) p1;

        if (p0 != *NULL_POINTER_MEMORY_MODEL) {

            void** d = (void**) p0;

            // The comparison result.
            int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

            if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                compare_arrays(p3, p4, BLACK_TERMINAL_COLOUR_CYBOL_MODEL, BLACK_TERMINAL_COLOUR_CYBOL_MODEL_COUNT, &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

                if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    *d = BLACK_FOREGROUND_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL;
                    *dc = *BLACK_FOREGROUND_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_COUNT;
                }
            }

            if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                compare_arrays(p3, p4, RED_TERMINAL_COLOUR_CYBOL_MODEL, RED_TERMINAL_COLOUR_CYBOL_MODEL_COUNT, &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

                if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    *d = RED_FOREGROUND_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL;
                    *dc = *RED_FOREGROUND_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_COUNT;
                }
            }

            if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                compare_arrays(p3, p4, GREEN_TERMINAL_COLOUR_CYBOL_MODEL, GREEN_TERMINAL_COLOUR_CYBOL_MODEL_COUNT, &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

                if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    *d = GREEN_FOREGROUND_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL;
                    *dc = *GREEN_FOREGROUND_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_COUNT;
                }
            }

            if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                compare_arrays(p3, p4, YELLOW_TERMINAL_COLOUR_CYBOL_MODEL, YELLOW_TERMINAL_COLOUR_CYBOL_MODEL_COUNT, &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

                if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    *d = YELLOW_FOREGROUND_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL;
                    *dc = *YELLOW_FOREGROUND_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_COUNT;
                }
            }

            if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                compare_arrays(p3, p4, BLUE_TERMINAL_COLOUR_CYBOL_MODEL, BLUE_TERMINAL_COLOUR_CYBOL_MODEL_COUNT, &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

                if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    *d = BLUE_FOREGROUND_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL;
                    *dc = *BLUE_FOREGROUND_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_COUNT;
                }
            }

            if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                compare_arrays(p3, p4, MAGENTA_TERMINAL_COLOUR_CYBOL_MODEL, MAGENTA_TERMINAL_COLOUR_CYBOL_MODEL_COUNT, &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

                if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    *d = MAGENTA_FOREGROUND_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL;
                    *dc = *MAGENTA_FOREGROUND_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_COUNT;
                }
            }

            if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                compare_arrays(p3, p4, COBALT_TERMINAL_COLOUR_CYBOL_MODEL, COBALT_TERMINAL_COLOUR_CYBOL_MODEL_COUNT, &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

                if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    *d = COBALT_FOREGROUND_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL;
                    *dc = *COBALT_FOREGROUND_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_COUNT;
                }
            }

            if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                compare_arrays(p3, p4, WHITE_TERMINAL_COLOUR_CYBOL_MODEL, WHITE_TERMINAL_COLOUR_CYBOL_MODEL_COUNT, &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

                if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    *d = WHITE_FOREGROUND_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL;
                    *dc = *WHITE_FOREGROUND_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_COUNT;
                }
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not encode terminal foreground. The destination is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not encode terminal foreground. The destination count is null.");
    }
}

/* TERMINAL_FOREGROUND_CONVERTER_SOURCE */
#endif
