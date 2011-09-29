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
 * @version $RCSfile: abstraction_converter.c,v $ $Revision: 1.17 $ $Date: 2009-10-06 21:25:27 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CHANNEL_DECODER_SOURCE
#define CHANNEL_DECODER_SOURCE

#include "../../../constant/abstraction/cybol/compare_cybol_abstraction.c"
#include "../../../constant/abstraction/cybol/datetime_cybol_abstraction.c"
#include "../../../constant/abstraction/cybol/logicvalue_cybol_abstraction.c"
//?? Delete this later. Superfluous since replaced with compare/equal etc.
#include "../../../constant/abstraction/cybol/operation_cybol_abstraction.c"
#include "../../../constant/abstraction/cybol/text_cybol_abstraction.c"
#include "../../../constant/abstraction/memory/memory_abstraction.c"
#include "../../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../../constant/abstraction/operation/operation_abstraction.c"
#include "../../../constant/abstraction/operation/primitive_operation_abstraction.c"
#include "../../../constant/model/log/message_log_model.c"
#include "../../../constant/model/memory/integer_memory_model.c"
#include "../../../constant/model/memory/pointer_memory_model.c"
#include "../../../executor/comparator/all/array_all_comparator.c"
#include "../../../logger/logger.c"

/**
 * Decodes the cybol channel (wchar_t) into a runtime cyboi channel (int).
 *
 * @param p0 the destination channel
 * @param p1 the source channel
 * @param p2 the source channel count
 */
void decode_channel(void* p0, void* p1, void* p2) {

    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Decode channel.");

    // The comparison result.
    int r = *FALSE_BOOLEAN_MEMORY_MODEL;

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_all_array((void*) &r, p1, (void*) FILE_SYSTEM_CYBOL_CHANNEL, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p2, (void*) FILE_SYSTEM_CYBOL_CHANNEL_COUNT);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            copy_integer(p0, (void*) FILE_SYSTEM_CYBOI_CHANNEL);
        }
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_all_array((void*) &r, p1, (void*) GNU_LINUX_CONSOLE_CYBOL_CHANNEL, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p2, (void*) GNU_LINUX_CONSOLE_CYBOL_CHANNEL_COUNT);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            copy_integer(p0, (void*) GNU_LINUX_CONSOLE_CYBOI_CHANNEL);
        }
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_all_array((void*) &r, p1, (void*) INLINE_CYBOL_CHANNEL, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p2, (void*) INLINE_CYBOL_CHANNEL_COUNT);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            copy_integer(p0, (void*) INLINE_CYBOI_CHANNEL);
        }
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_all_array((void*) &r, p1, (void*) SHELL_CYBOL_CHANNEL, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p2, (void*) SHELL_CYBOL_CHANNEL_COUNT);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            copy_integer(p0, (void*) SHELL_CYBOI_CHANNEL);
        }
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_all_array((void*) &r, p1, (void*) SOCKET_CYBOL_CHANNEL, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p2, (void*) SOCKET_CYBOL_CHANNEL_COUNT);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            copy_integer(p0, (void*) SOCKET_CYBOI_CHANNEL);
        }
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_all_array((void*) &r, p1, (void*) WWW_CYBOL_CHANNEL, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p2, (void*) WWW_CYBOL_CHANNEL_COUNT);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            copy_integer(p0, (void*) WWW_CYBOI_CHANNEL);
        }
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_all_array((void*) &r, p1, (void*) X_WINDOW_SYSTEM_CYBOL_CHANNEL, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p2, (void*) X_WINDOW_SYSTEM_CYBOL_CHANNEL_COUNT);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            copy_integer(p0, (void*) X_WINDOW_SYSTEM_CYBOI_CHANNEL);
        }
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        log_terminated_message((void*) WARNING_LEVEL_LOG_MODEL, (void*) L"Could not decode channel. The source channel is unknown.");
    }
}

/* CHANNEL_DECODER_SOURCE */
#endif
