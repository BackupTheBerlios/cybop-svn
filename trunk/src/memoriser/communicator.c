/*
 * $RCSfile: communicator.c,v $
 *
 * Copyright (c) 1999-2006. Christian Heller and the CYBOP developers.
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
 * @version $Revision: 1.9 $ $Date: 2006-04-20 22:36:11 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef COMMUNICATOR_SOURCE
#define COMMUNICATOR_SOURCE

#include "../globals/constants/abstraction_constants.c"
#include "../globals/constants/channel_constants.c"
#include "../globals/constants/model_constants.c"
#include "../memoriser/array.c"
#include "../memoriser/communicator/file_communicator.c"
#include "../memoriser/communicator/ftp_communicator.c"
#include "../memoriser/communicator/http_communicator.c"
#include "../memoriser/communicator/inline_communicator.c"
#include "../memoriser/communicator/linux_console_communicator.c"
#include "../memoriser/communicator/x_window_system_communicator.c"

/**
 * Reads a stream according to the given communication channel type
 * and creates a byte array from it.
 *
 * CAUTION! This procedure cannot be called "read"
 * as that name is already used by the input/ output mechanism.
 * CAUTION! This procedure cannot be called "receive"
 * as that name is already used by the socket mechanism.
 *
 * @param p0 the destination byte array (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source
 * @param p4 the source count
 * @param p5 the type
 * @param p6 the type count
 */
void read_data(void* p0, void* p1, void* p2, void* p3, void* p4,
    void* p5, void* p6) {

    // The comparison result.
    int r = 0;

    if (r == 0) {

        compare_arrays(p5, p6, (void*) INLINE_CHANNEL, (void*) INLINE_CHANNEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            read_inline(p0, p1, p2, p3, p4);
        }
    }

    if (r == 0) {

        compare_arrays(p5, p6, (void*) FILE_CHANNEL, (void*) FILE_CHANNEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            read_file(p0, p1, p2, p3, p4);
        }
    }

    if (r == 0) {

        compare_arrays(p5, p6, (void*) FTP_CHANNEL, (void*) FTP_CHANNEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            read_ftp(p0, p1, p2, p3, p4);
        }
    }

    if (r == 0) {

        compare_arrays(p5, p6, (void*) HTTP_CHANNEL, (void*) HTTP_CHANNEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            read_http(p0, p1, p2, p3, p4);
        }
    }

    if (r == 0) {

        compare_arrays(p5, p6, (void*) LINUX_CONSOLE_MODEL, (void*) LINUX_CONSOLE_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            read_linux_console(p0, p1, p2, p3, p4);
        }
    }

    if (r == 0) {

        compare_arrays(p5, p6, (void*) X_WINDOW_SYSTEM_MODEL, (void*) X_WINDOW_SYSTEM_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            read_x_window_system(p0, p1, p2, p3, p4);
        }
    }
}

/**
 * Writes a stream according to the given communication channel type
 * and reads its data from a byte array.
 *
 * CAUTION! This procedure cannot be called "write"
 * as that name is already used by the input/ output mechanism.
 * CAUTION! This procedure cannot be called "send"
 * as that name is already used by the socket mechanism.
 *
 * @param p0 the destination (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source byte array
 * @param p4 the source count
 * @param p5 the type
 * @param p6 the type count
 */
void write_data(void* p0, void* p1, void* p2, void* p3, void* p4,
    void* p5, void* p6) {

    // The comparison result.
    int r = 0;

    if (r == 0) {

        compare_arrays(p5, p6, (void*) INLINE_CHANNEL, (void*) INLINE_CHANNEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            write_inline(p0, p1, p2, p3, p4);
        }
    }

    if (r == 0) {

        compare_arrays(p5, p6, (void*) FILE_CHANNEL, (void*) FILE_CHANNEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            write_file(p0, p1, p2, p3, p4);
        }
    }

    if (r == 0) {

        compare_arrays(p5, p6, (void*) FTP_CHANNEL, (void*) FTP_CHANNEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            write_ftp(p0, p1, p2, p3, p4);
        }
    }

    if (r == 0) {

        compare_arrays(p5, p6, (void*) HTTP_CHANNEL, (void*) HTTP_CHANNEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            write_http(p0, p1, p2, p3, p4);
        }
    }

    if (r == 0) {

        compare_arrays(p5, p6, (void*) LINUX_CONSOLE_MODEL, (void*) LINUX_CONSOLE_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            write_linux_console(p0, p1, p2, p3, p4);
        }
    }

    if (r == 0) {

        compare_arrays(p5, p6, (void*) X_WINDOW_SYSTEM_MODEL, (void*) X_WINDOW_SYSTEM_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            write_x_window_system(p0, p1, p2, p3, p4);
        }
    }
}

/* COMMUNICATOR_SOURCE */
#endif
