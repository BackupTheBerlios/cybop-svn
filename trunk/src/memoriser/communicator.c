/*
 * $RCSfile: communicator.c,v $
 *
 * Copyright (c) 1999-2007. Christian Heller and the CYBOP developers.
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
 * This file contains the functionality to:
 * - read data from a device into a byte array
 * - write data from a byte array to a device
 *
 * @version $Revision: 1.21 $ $Date: 2007-12-01 23:57:42 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef COMMUNICATOR_SOURCE
#define COMMUNICATOR_SOURCE

#include "../globals/constants/cybol/cybol_abstraction_constants.c"
#include "../globals/constants/cybol/cybol_channel_constants.c"
#include "../globals/constants/cybol/cybol_model_constants.c"
#include "../globals/constants/integer/integer_constants.c"
#include "../globals/constants/memory_structure/array_constants.c"
#include "../globals/constants/system/system_file_name_constants.c"
#include "../memoriser/communicator/file_communicator.c"
#include "../memoriser/communicator/ftp_communicator.c"
#include "../memoriser/communicator/gnu_linux_console_communicator.c"
#include "../memoriser/communicator/http_communicator.c"
#include "../memoriser/communicator/inline_communicator.c"
#include "../memoriser/communicator/socket_communicator.c"
#include "../memoriser/communicator/x_window_system_communicator.c"
#include "../memoriser/array.c"

/**
 * Reads a stream according to the given communication channel type
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
 * @param p3 the source or communication partner-connected socket address (the latter for socket communication)
 * @param p4 the source count or communication partner-connected socket address size (the latter for socket communication)
 * @param p5 the communication partner-connected socket of this system (for socket communication)
 * @param p6 the original socket address of this system (for socket communication)
 * @param p7 the original socket address of this system size (for socket communication)
 * @param p8 the original socket of this system (for socket communication)
 * @param p9 the type or style (the latter for socket communication)
 * @param p10 the type count or style count (the latter for socket communication)
 */
void read_data(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10) {

    log_terminated_message((void*) INFORMATION_LOG_LEVEL, (void*) "Read data.");

    // The comparison result.
    int r = *NUMBER_0_INTEGER;

    if (r == *NUMBER_0_INTEGER) {

        compare_arrays(p9, p10, (void*) INLINE_CHANNEL, (void*) INLINE_CHANNEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != *NUMBER_0_INTEGER) {

            read_inline(p0, p1, p2, p3, p4);
        }
    }

    if (r == *NUMBER_0_INTEGER) {

        compare_arrays(p9, p10, (void*) FILE_CHANNEL, (void*) FILE_CHANNEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != *NUMBER_0_INTEGER) {

            read_file(p0, p1, p2, p3, p4);
        }
    }

    if (r == *NUMBER_0_INTEGER) {

        compare_arrays(p9, p10, (void*) SHELL_CHANNEL, (void*) SHELL_CHANNEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != *NUMBER_0_INTEGER) {

            // CAUTION! Instead of a file name, the "stdint" standard intput file stream is handed over here!
            read_file(p0, p1, p2, (void*) INPUT_SYSTEM_FILE_NAME, (void*) INPUT_SYSTEM_FILE_NAME_COUNT);
        }
    }

    if (r == *NUMBER_0_INTEGER) {

        compare_arrays(p9, p10, (void*) FTP_CHANNEL, (void*) FTP_CHANNEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != *NUMBER_0_INTEGER) {

            read_ftp(p0, p1, p2, p3, p4);
        }
    }

    if (r == *NUMBER_0_INTEGER) {

        compare_arrays(p9, p10, (void*) HTTP_CHANNEL, (void*) HTTP_CHANNEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != *NUMBER_0_INTEGER) {

            read_http(p0, p1, p2, p3, p4);
        }
    }

    if (r == *NUMBER_0_INTEGER) {

        compare_arrays(p9, p10, (void*) GNU_LINUX_CONSOLE_MODEL, (void*) GNU_LINUX_CONSOLE_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != *NUMBER_0_INTEGER) {

            read_gnu_linux_console(p0, p1, p2, p3, p4);
        }
    }

    if (r == *NUMBER_0_INTEGER) {

        compare_arrays(p9, p10, (void*) X_WINDOW_SYSTEM_MODEL, (void*) X_WINDOW_SYSTEM_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != *NUMBER_0_INTEGER) {

            read_x_window_system(p0, p1, p2, p3, p4);
        }
    }

    if (r == *NUMBER_0_INTEGER) {

        compare_arrays(p9, p10, (void*) STREAM_COMMUNICATION_STYLE_MODEL, (void*) STREAM_COMMUNICATION_STYLE_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != *NUMBER_0_INTEGER) {

            sense_socket_stream(p0, p1, p2, p3, p4, p5, p6, p9);
        }
    }

    if (r == *NUMBER_0_INTEGER) {

        compare_arrays(p9, p10, (void*) DATAGRAM_COMMUNICATION_STYLE_MODEL, (void*) DATAGRAM_COMMUNICATION_STYLE_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != *NUMBER_0_INTEGER) {

            sense_socket_datagram(p0, p1, p2, p6, p7, p8, p9);
        }
    }

    if (r == *NUMBER_0_INTEGER) {

        compare_arrays(p9, p10, (void*) RAW_COMMUNICATION_STYLE_MODEL, (void*) RAW_COMMUNICATION_STYLE_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != *NUMBER_0_INTEGER) {

            sense_socket_raw(p0, p1, p2);
        }
    }

    if (r == *NUMBER_0_INTEGER) {

        log_terminated_message((void*) WARNING_LOG_LEVEL, (void*) "Could not read data. The communication type is unknown.");
    }
}

/**
 * Writes a stream according to the given communication channel type
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
 * @param p4 the source count
 * @param p5 the type
 * @param p6 the type count
 */
void write_data(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    log_terminated_message((void*) INFORMATION_LOG_LEVEL, (void*) "Write data.");

    // The comparison result.
    int r = *NUMBER_0_INTEGER;

    if (r == *NUMBER_0_INTEGER) {

        compare_arrays(p5, p6, (void*) INLINE_CHANNEL, (void*) INLINE_CHANNEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != *NUMBER_0_INTEGER) {

            write_inline(p0, p1, p2, p3, p4);
        }
    }

    if (r == *NUMBER_0_INTEGER) {

        compare_arrays(p5, p6, (void*) FILE_CHANNEL, (void*) FILE_CHANNEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != *NUMBER_0_INTEGER) {

            write_file(p0, p1, p2, p3, p4);
        }
    }

    if (r == *NUMBER_0_INTEGER) {

        compare_arrays(p5, p6, (void*) SHELL_CHANNEL, (void*) SHELL_CHANNEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != *NUMBER_0_INTEGER) {

            // CAUTION! Instead of a file name, the "stdout" standard output file stream is handed over here!
            write_file((void*) OUTPUT_SYSTEM_FILE_NAME, (void*) OUTPUT_SYSTEM_FILE_NAME_COUNT, p2, p3, p4);
        }
    }

    if (r == *NUMBER_0_INTEGER) {

        compare_arrays(p5, p6, (void*) FTP_CHANNEL, (void*) FTP_CHANNEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != *NUMBER_0_INTEGER) {

            write_ftp(p0, p1, p2, p3, p4);
        }
    }

    if (r == *NUMBER_0_INTEGER) {

        compare_arrays(p5, p6, (void*) HTTP_CHANNEL, (void*) HTTP_CHANNEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != *NUMBER_0_INTEGER) {

            write_http(p0, p1, p2, p3, p4);
        }
    }

    if (r == *NUMBER_0_INTEGER) {

        compare_arrays(p5, p6, (void*) GNU_LINUX_CONSOLE_MODEL, (void*) GNU_LINUX_CONSOLE_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != *NUMBER_0_INTEGER) {

            write_gnu_linux_console(p0, p1, p2, p3, p4);
        }
    }

    if (r == *NUMBER_0_INTEGER) {

        compare_arrays(p5, p6, (void*) X_WINDOW_SYSTEM_MODEL, (void*) X_WINDOW_SYSTEM_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != *NUMBER_0_INTEGER) {

            write_x_window_system(p0, p1, p2, p3, p4);
        }
    }

    if (r == *NUMBER_0_INTEGER) {

        compare_arrays(p9, p10, (void*) STREAM_COMMUNICATION_STYLE_MODEL, (void*) STREAM_COMMUNICATION_STYLE_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != *NUMBER_0_INTEGER) {

            write_stream_socket(p0, p1, p2, p3, p4, p5, p6);
        }
    }

    if (r == *NUMBER_0_INTEGER) {

        compare_arrays(p9, p10, (void*) DATAGRAM_COMMUNICATION_STYLE_MODEL, (void*) DATAGRAM_COMMUNICATION_STYLE_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != *NUMBER_0_INTEGER) {

            sense_socket_datagram(p0, p1, p2, p6, p7, p8, p9);
        }
    }

    if (r == *NUMBER_0_INTEGER) {

        compare_arrays(p9, p10, (void*) RAW_COMMUNICATION_STYLE_MODEL, (void*) RAW_COMMUNICATION_STYLE_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != *NUMBER_0_INTEGER) {

            sense_socket_raw(p0, p1, p2);
        }
    }

    if (r == *NUMBER_0_INTEGER) {

        log_terminated_message((void*) WARNING_LOG_LEVEL, (void*) "Could not write data. The communication type is unknown.");
    }
}

/* COMMUNICATOR_SOURCE */
#endif
