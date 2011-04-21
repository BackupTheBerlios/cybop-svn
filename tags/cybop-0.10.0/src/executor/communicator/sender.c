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
 * @version $RCSfile: communicator.c,v $ $Revision: 1.36 $ $Date: 2009-01-31 16:06:31 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef SENDER_SOURCE
#define SENDER_SOURCE

#include "../../constant/abstraction/cybol/text_cybol_abstraction.c"
#include "../../constant/abstraction/memory/memory_abstraction.c"
#include "../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../constant/channel/cybol_channel.c"
#include "../../constant/model/cybol/http_request_cybol_model.c"
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../constant/model/stream_model.c"
#include "../../executor/communicator/sender/datagram_socket_sender.c"
#include "../../executor/communicator/sender/file_sender.c"
#include "../../executor/communicator/sender/gnu_linux_console_sender.c"
#include "../../executor/communicator/sender/inline_sender.c"
#include "../../executor/communicator/sender/raw_socket_sender.c"
#include "../../executor/communicator/sender/stream_socket_sender.c"
#include "../../executor/communicator/sender/x_window_system_sender.c"
#include "../../executor/comparator/array_equality_comparator.c"

/**
 * Sends a data stream according to the given communication channel type
 * and reads its data from a byte array.
 *
 * CAUTION! This procedure cannot be called "write" as that name
 * is already used by the glibc library's input/ output mechanism.
 *
 * CAUTION! This procedure cannot be called "send" as that name
 * is already used by the glibc library's socket mechanism.
 *
 * @param p0 the destination (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source byte array
 * @param p4 the source byte array count
 * @param p5 the communication type
 * @param p6 the communication type count
 */
void send_data(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Send data.");

    // The comparison result.
    int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

/*??
        compare_equal_arrays((void*) &r, p5, p6, (void*) DATAGRAM_COMMUNICATION_STYLE_CYBOL_MODEL, (void*) DATAGRAM_COMMUNICATION_STYLE_CYBOL_MODEL_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            send_datagram_socket(p0, p1, p2, p3, p4, p5, p6);
        }
*/
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_arrays((void*) &r, p5, p6, (void*) FILE_CYBOL_CHANNEL, (void*) FILE_CYBOL_CHANNEL_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            send_file(p0, p1, p2, p3, p4);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_arrays((void*) &r, p5, p6, (void*) GNU_LINUX_CONSOLE_CYBOL_CHANNEL, (void*) GNU_LINUX_CONSOLE_CYBOL_CHANNEL_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            send_gnu_linux_console(p0, p1, p2, p3, p4);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_arrays((void*) &r, p5, p6, (void*) INLINE_CYBOL_CHANNEL, (void*) INLINE_CYBOL_CHANNEL_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            send_inline(p0, p1, p2, p3, p4);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

/*??
        compare_equal_arrays((void*) &r, p5, p6, (void*) RAW_COMMUNICATION_STYLE_CYBOL_MODEL, (void*) RAW_COMMUNICATION_STYLE_CYBOL_MODEL_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            send_raw_socket(p0, p1, p2);
        }
*/
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_arrays((void*) &r, p5, p6, (void*) SHELL_CYBOL_CHANNEL, (void*) SHELL_CYBOL_CHANNEL_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            // CAUTION! Instead of a file name, the "stdout" standard output file stream is handed over here!
            send_file((void*) STANDARD_OUTPUT_STREAM_MODEL, (void*) STANDARD_OUTPUT_STREAM_MODEL_COUNT, p2, p3, p4);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

/*??
        compare_equal_arrays((void*) &r, p5, p6, (void*) STREAM_COMMUNICATION_STYLE_CYBOL_MODEL, (void*) STREAM_COMMUNICATION_STYLE_CYBOL_MODEL_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            send_stream_socket(p0, p1, p2, p3, p4, p5, p6);
        }
*/
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_arrays((void*) &r, p5, p6, (void*) X_WINDOW_SYSTEM_CYBOL_CHANNEL, (void*) X_WINDOW_SYSTEM_CYBOL_CHANNEL_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            send_x_window_system(p0, p1, p2, p3, p4);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        log_terminated_message((void*) WARNING_LEVEL_LOG_MODEL, (void*) L"Could not send data. The communication type is unknown.");
    }
}

/* SENDER_SOURCE */
#endif