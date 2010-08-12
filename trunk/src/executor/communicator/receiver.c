/*
 * Copyright (C) 1999-2010. Christian Heller.
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

#ifndef RECEIVER_SOURCE
#define RECEIVER_SOURCE

#include "../../constant/abstraction/cybol/text_cybol_abstraction.c"
#include "../../constant/abstraction/memory/memory_abstraction.c"
#include "../../constant/channel/cybol_channel.c"
#include "../../constant/model/cybol/http_request_cybol_model.c"
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../constant/model/stream_model.c"
#include "../../executor/communicator/receiver/datagram_socket_receiver.c"
#include "../../executor/communicator/receiver/file_receiver.c"
#include "../../executor/communicator/receiver/gnu_linux_console_receiver.c"
#include "../../executor/communicator/receiver/inline_receiver.c"
#include "../../executor/communicator/receiver/raw_socket_receiver.c"
#include "../../executor/communicator/receiver/stream_socket_receiver.c"
#include "../../executor/communicator/receiver/x_window_system_receiver.c"
#include "../../executor/comparator/array_equality_comparator.c"

/**
 * Receives a data stream according to the given communication channel type
 * and creates a byte array from it.
 *
 * CAUTION! This procedure cannot be called "read" as that name
 * is already used by the glibc library's input/ output mechanism.
 *
 * CAUTION! This procedure cannot be called "receive" as that name
 * is already used by the glibc library's socket mechanism.
 *
 * @param p0 the destination byte array (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source OR communication partner-connected socket address (the latter for socket communication)
 * @param p4 the source count OR communication partner-connected socket address size (the latter for socket communication)
 * @param p5 the communication partner-connected socket of this system (for socket communication)
 * @param p6 the original socket address of this system (for socket communication)
 * @param p7 the original socket address of this system size (for socket communication)
 * @param p8 the original socket of this system (for socket communication)
 * @param p9 the type OR style (the latter for socket communication)
 * @param p10 the type count OR style count (the latter for socket communication)
 */
void receive_data(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Receive data.");

    // The comparison result.
    int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

/*??
        compare_equal_arrays((void*) &r, p9, p10, (void*) DATAGRAM_COMMUNICATION_STYLE_CYBOL_MODEL, (void*) DATAGRAM_COMMUNICATION_STYLE_CYBOL_MODEL_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            receive_datagram_socket(p0, p1, p2, p6, p7, p8, p9);
        }
*/
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_arrays((void*) &r, p9, p10, (void*) FILE_CYBOL_CHANNEL, (void*) FILE_CYBOL_CHANNEL_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            receive_file(p0, p1, p2, p3, p4);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_arrays((void*) &r, p9, p10, (void*) GNU_LINUX_CONSOLE_CYBOL_CHANNEL, (void*) GNU_LINUX_CONSOLE_CYBOL_CHANNEL_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

//??            receive_gnu_linux_console(p0, p1, p2, p3);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_arrays((void*) &r, p9, p10, (void*) INLINE_CYBOL_CHANNEL, (void*) INLINE_CYBOL_CHANNEL_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            receive_inline(p0, p1, p2, p3, p4);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

/*??
        compare_equal_arrays((void*) &r, p9, p10, (void*) RAW_COMMUNICATION_STYLE_CYBOL_MODEL, (void*) RAW_COMMUNICATION_STYLE_CYBOL_MODEL_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            receive_raw_socket(p0, p1, p2);
        }
*/
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_arrays((void*) &r, p9, p10, (void*) SHELL_CYBOL_CHANNEL, (void*) SHELL_CYBOL_CHANNEL_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            // CAUTION! Instead of a file name, the "stdint" standard intput file stream is handed over here!
            receive_file(p0, p1, p2, (void*) STANDARD_INPUT_STREAM_MODEL, (void*) STANDARD_INPUT_STREAM_MODEL_COUNT);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

/*??
        compare_equal_arrays((void*) &r, p9, p10, (void*) STREAM_COMMUNICATION_STYLE_CYBOL_MODEL, (void*) STREAM_COMMUNICATION_STYLE_CYBOL_MODEL_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            receive_stream_socket(p0, p1, p2, p3, p4, p5, p6, p9);
        }
*/
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_arrays((void*) &r, p9, p10, (void*) X_WINDOW_SYSTEM_CYBOL_CHANNEL, (void*) X_WINDOW_SYSTEM_CYBOL_CHANNEL_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            receive_x_window_system(p0, p1, p2, p3, p4);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        log_terminated_message((void*) WARNING_LEVEL_LOG_MODEL, (void*) L"Could not receive data. The communication type is unknown.");
    }
}

/* RECEIVER_SOURCE */
#endif
