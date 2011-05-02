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
 * @version $RCSfile: terminal_foreground_converter.c,v $ $Revision: 1.10 $ $Date: 2009-01-31 16:06:34 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef TERMINAL_FOREGROUND_ENCODER_SOURCE
#define TERMINAL_FOREGROUND_ENCODER_SOURCE

#include "../../../constant/abstraction/cybol/text_cybol_abstraction.c"
#include "../../../constant/abstraction/memory/memory_abstraction.c"
#include "../../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../../constant/model/cybol/colour/terminal_colour_cybol_model.c"
#include "../../../constant/model/gnu_linux_console/escape_control_sequence_gnu_linux_console_model.c"
#include "../../../constant/model/log/message_log_model.c"
#include "../../../constant/model/memory/integer_memory_model.c"
#include "../../../constant/model/memory/pointer_memory_model.c"
#include "../../../executor/accessor/getter.c"
#include "../../../executor/comparator/wide_character_equal_array_comparator.c"
#include "../../../executor/modifier/appender.c"
#include "../../../logger/logger.c"

/**
 * Encodes the terminal foreground colour name into a control sequence code.
 *
 * @param p0 the destination control sequence code (Hand over as reference!)
 * @param p1 the destination control sequence code count
 * @param p2 the destination control sequence code size
 * @param p3 the source colour name
 * @param p4 the source colour name count
 */
void encode_terminal_foreground(void* p0, void* p1, void* p2, void* p3, void* p4) {

    // The comparison result.
    int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_array_equal_wide_character((void*) &r, p3, p4, (void*) BLACK_TERMINAL_COLOUR_CYBOL_MODEL, (void*) BLACK_TERMINAL_COLOUR_CYBOL_MODEL_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            append(p0, p1, p2, (void*) BLACK_FOREGROUND_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL, (void*) BLACK_FOREGROUND_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_array_equal_wide_character((void*) &r, p3, p4, (void*) RED_TERMINAL_COLOUR_CYBOL_MODEL, (void*) RED_TERMINAL_COLOUR_CYBOL_MODEL_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            append(p0, p1, p2, (void*) RED_FOREGROUND_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL, (void*) RED_FOREGROUND_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_array_equal_wide_character((void*) &r, p3, p4, (void*) GREEN_TERMINAL_COLOUR_CYBOL_MODEL, (void*) GREEN_TERMINAL_COLOUR_CYBOL_MODEL_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            append(p0, p1, p2, (void*) GREEN_FOREGROUND_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL, (void*) GREEN_FOREGROUND_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_array_equal_wide_character((void*) &r, p3, p4, (void*) YELLOW_TERMINAL_COLOUR_CYBOL_MODEL, (void*) YELLOW_TERMINAL_COLOUR_CYBOL_MODEL_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            append(p0, p1, p2, (void*) YELLOW_FOREGROUND_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL, (void*) YELLOW_FOREGROUND_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_array_equal_wide_character((void*) &r, p3, p4, (void*) BLUE_TERMINAL_COLOUR_CYBOL_MODEL, (void*) BLUE_TERMINAL_COLOUR_CYBOL_MODEL_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            append(p0, p1, p2, (void*) BLUE_FOREGROUND_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL, (void*) BLUE_FOREGROUND_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_array_equal_wide_character((void*) &r, p3, p4, (void*) MAGENTA_TERMINAL_COLOUR_CYBOL_MODEL, (void*) MAGENTA_TERMINAL_COLOUR_CYBOL_MODEL_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            append(p0, p1, p2, (void*) MAGENTA_FOREGROUND_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL, (void*) MAGENTA_FOREGROUND_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_array_equal_wide_character((void*) &r, p3, p4, (void*) COBALT_TERMINAL_COLOUR_CYBOL_MODEL, (void*) COBALT_TERMINAL_COLOUR_CYBOL_MODEL_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            append(p0, p1, p2, (void*) COBALT_FOREGROUND_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL, (void*) COBALT_FOREGROUND_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_array_equal_wide_character((void*) &r, p3, p4, (void*) WHITE_TERMINAL_COLOUR_CYBOL_MODEL, (void*) WHITE_TERMINAL_COLOUR_CYBOL_MODEL_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            append(p0, p1, p2, (void*) WHITE_FOREGROUND_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL, (void*) WHITE_FOREGROUND_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT);
        }
    }
}

/* TERMINAL_FOREGROUND_ENCODER_SOURCE */
#endif
