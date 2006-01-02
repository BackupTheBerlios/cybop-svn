/*
 * $RCSfile: receive.c,v $
 *
 * Copyright (c) 1999-2005. Christian Heller and the CYBOP developers.
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
 * @version $Revision: 1.12 $ $Date: 2006-01-02 11:56:01 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef RECEIVE_SOURCE
#define RECEIVE_SOURCE

#include "../applicator/receive/receive_latex.c"
#include "../applicator/receive/receive_linux_console.c"
#include "../applicator/receive/receive_tcp_socket.c"
#include "../applicator/receive/receive_unix_socket.c"
#include "../applicator/receive/receive_x_window_system.c"
#include "../globals/constants/abstraction_constants.c"
#include "../globals/constants/channel_constants.c"
#include "../globals/constants/model_constants.c"
#include "../globals/constants/name_constants.c"
#include "../globals/constants/structure_constants.c"
#include "../globals/logger/logger.c"

/**
 * Receives a message in a special language.
 *
 * CAUTION! Do NOT rename this procedure to "receive",
 * as that name is already used by socket functionality.
 *
 * The signal waiting loop only catches cyboi internal signals.
 * In order to also catch signals of various devices,
 * special mechanisms for signal reception have to be started.
 * To the mechanisms belong:
 * - linux console
 * - tcp socket
 * - unix socket
 * - x window system
 *
 * These have their own internal signal/ action/ event/ interrupt waiting loops
 * which get activated here, running as parallel services in separate threads.
 * Whenever an event occurs in one of these threads, it gets transformed into a
 * cyboi signal and is finally placed in cyboi's signal memory.
 *
 * TODO: Since many internal waiting loops run in parallel,
 * the adding of signals to the signal memory must be synchronized!
 * How to do this properly in C?
 *
 * Expected parameters:
 * - channel: linux_console, tcp_socket, unix_socket, x_window_system
 * - root: dot-separated name to the root window knowledge model of the graphical user interface (gui)
 * - commands: dot-separated name of commands knowledge model
 * - blocking: true, false
 *
 * @param p0 the parameters
 * @param p1 the parameters count
 * @param p2 the internal memory
 * @param p3 the knowledge memory
 * @param p4 the knowledge memory count
 * @param p5 the knowledge memory size
 * @param p6 the signal memory
 * @param p7 the signal memory count
 * @param p8 the signal memory size
 */
void receive_message(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5,
    void* p6, void* p7, void* p8) {

    log_message_debug("Receive message.");

    // The channel abstraction.
    void** ca = &NULL_POINTER;
    void** cac = &NULL_POINTER;
    void** cas = &NULL_POINTER;
    // The channel model.
    void** cm = &NULL_POINTER;
    void** cmc = &NULL_POINTER;
    void** cms = &NULL_POINTER;
    // The channel details.
    void** cd = &NULL_POINTER;
    void** cdc = &NULL_POINTER;
    void** cds = &NULL_POINTER;

    // The root abstraction.
    void** ra = &NULL_POINTER;
    void** rac = &NULL_POINTER;
    void** ras = &NULL_POINTER;
    // The root model.
    void** rm = &NULL_POINTER;
    void** rmc = &NULL_POINTER;
    void** rms = &NULL_POINTER;
    // The root details.
    void** rd = &NULL_POINTER;
    void** rdc = &NULL_POINTER;
    void** rds = &NULL_POINTER;

    // The commands abstraction.
    void** coa = &NULL_POINTER;
    void** coac = &NULL_POINTER;
    void** coas = &NULL_POINTER;
    // The commands model.
    void** com = &NULL_POINTER;
    void** comc = &NULL_POINTER;
    void** coms = &NULL_POINTER;
    // The commands details.
    void** cod = &NULL_POINTER;
    void** codc = &NULL_POINTER;
    void** cods = &NULL_POINTER;

    // The blocking abstraction.
    void** ba = &NULL_POINTER;
    void** bac = &NULL_POINTER;
    void** bas = &NULL_POINTER;
    // The blocking model.
    void** bm = &NULL_POINTER;
    void** bmc = &NULL_POINTER;
    void** bms = &NULL_POINTER;
    // The blocking details.
    void** bd = &NULL_POINTER;
    void** bdc = &NULL_POINTER;
    void** bds = &NULL_POINTER;

    // Get channel.
    get_real_compound_element_by_name(p0, p1,
        (void*) CHANNEL_NAME, (void*) CHANNEL_NAME_COUNT,
        (void*) &ca, (void*) &cac, (void*) &cas,
        (void*) &cm, (void*) &cmc, (void*) &cms,
        (void*) &cd, (void*) &cdc, (void*) &cds,
        p3, p4);

    // Get root.
    get_real_compound_element_by_name(p0, p1,
        (void*) ROOT_NAME, (void*) ROOT_NAME_COUNT,
        (void*) &ra, (void*) &rac, (void*) &ras,
        (void*) &rm, (void*) &rmc, (void*) &rms,
        (void*) &rd, (void*) &rdc, (void*) &rds,
        p3, p4);

    // Get commands.
    get_real_compound_element_by_name(p0, p1,
        (void*) COMMANDS_NAME, (void*) COMMANDS_NAME_COUNT,
        (void*) &coa, (void*) &coac, (void*) &coas,
        (void*) &com, (void*) &comc, (void*) &coms,
        (void*) &cod, (void*) &codc, (void*) &cods,
        p3, p4);

    // Get blocking.
    get_real_compound_element_by_name(p0, p1,
        (void*) BLOCKING_NAME, (void*) BLOCKING_NAME_COUNT,
        (void*) &ba, (void*) &bac, (void*) &bas,
        (void*) &bm, (void*) &bmc, (void*) &bms,
        (void*) &bd, (void*) &bdc, (void*) &bds,
        p3, p4);

    // The comparison result.
    int r = 0;

    if (r == 0) {

        compare_arrays((void*) *cm, (void*) *cmc, (void*) LATEX_MODEL, (void*) LATEX_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

//??            receive_latex(p2, *mm, *mmc);
        }
    }

    if (r == 0) {

        compare_arrays((void*) *cm, (void*) *cmc, (void*) LINUX_CONSOLE_MODEL, (void*) LINUX_CONSOLE_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            receive_linux_console(p2, p3, p4, p5, p6, p7, p8, *com, *comc);
        }
    }

    if (r == 0) {

        compare_arrays((void*) *cm, (void*) *cmc, (void*) TCP_SOCKET_MODEL, (void*) TCP_SOCKET_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            receive_tcp_socket(p2, p3, p4, p5, *ba, *bac, *bm, *bmc);
        }
    }

    if (r == 0) {

        compare_arrays((void*) *cm, (void*) *cmc, (void*) UNIX_SOCKET_MODEL, (void*) UNIX_SOCKET_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            receive_unix_socket(p2, p3, p4);
        }
    }

    if (r == 0) {

        compare_arrays((void*) *cm, (void*) *cmc, (void*) X_WINDOW_SYSTEM_MODEL, (void*) X_WINDOW_SYSTEM_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            receive_x_window_system(p2, *rm, *rmc, *rms, *com, *comc, *coms);
        }
    }
}

/* RECEIVE_SOURCE */
#endif
