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
 * @version $Revision: 1.11 $ $Date: 2005-10-17 22:26:30 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef RECEIVE_SOURCE
#define RECEIVE_SOURCE

#include "../applicator/receive/receive_latex.c"
#include "../applicator/receive/receive_linux_console.c"
#include "../applicator/receive/receive_tcp_socket.c"
#include "../applicator/receive/receive_x_window_system.c"
#include "../globals/constants/abstraction_constants.c"
#include "../globals/constants/channel_constants.c"
#include "../globals/constants/name_constants.c"
#include "../globals/constants/structure_constants.c"
#include "../globals/logger/logger.c"
#include "../socket/unix_socket.c"

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
 * - unix socket
 * - tcp socket
 * - x window system
 *
 * These have their own internal signal/ action/ event/ interrupt
 * waiting loops which get activated here.
 * Whenever such a signal/ action/ event/ interrupt occurs, it gets transformed
 * into a cyboi signal and is finally placed in cyboi's signal memory.
 *
 * TODO: Since many internal waiting loops run in parallel,
 * the adding of signals to the signal memory must be synchronized!
 * How to do this properly in C?
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
void receive_message(void* p0, void* p1,
    void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8) {

    // The service abstraction.
    void** sa = &NULL_POINTER;
    void** sac = &NULL_POINTER;
    void** sas = &NULL_POINTER;
    // The service model.
    void** sm = &NULL_POINTER;
    void** smc = &NULL_POINTER;
    void** sms = &NULL_POINTER;
    // The service details.
    void** sd = &NULL_POINTER;
    void** sdc = &NULL_POINTER;
    void** sds = &NULL_POINTER;

    // The commands abstraction.
    void** ca = &NULL_POINTER;
    void** cac = &NULL_POINTER;
    void** cas = &NULL_POINTER;
    // The commands model.
    void** cm = &NULL_POINTER;
    void** cmc = &NULL_POINTER;
    void** cms = &NULL_POINTER;
    // The commands details.
    void** cd = &NULL_POINTER;
    void** cdc = &NULL_POINTER;
    void** cds = &NULL_POINTER;

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

    // Get service.
    get_real_compound_element_by_name(p0, p1,
        (void*) SERVICE_NAME, (void*) SERVICE_NAME_COUNT,
        (void*) &sa, (void*) &sac, (void*) &sas,
        (void*) &sm, (void*) &smc, (void*) &sms,
        (void*) &sd, (void*) &sdc, (void*) &sds,
        p3, p4);

    // Get commands.
    get_real_compound_element_by_name(p0, p1,
        (void*) COMMANDS_NAME, (void*) COMMANDS_NAME_COUNT,
        (void*) &ca, (void*) &cac, (void*) &cas,
        (void*) &cm, (void*) &cmc, (void*) &cms,
        (void*) &cd, (void*) &cdc, (void*) &cds,
        p3, p4);

    // Get blocking.
    get_real_compound_element_by_name(p0, p1,
        (void*) BLOCKING_NAME, (void*) BLOCKING_NAME_COUNT,
        (void*) &ba, (void*) &bac, (void*) &bas,
        (void*) &bm, (void*) &bmc, (void*) &bms,
        (void*) &bd, (void*) &bdc, (void*) &bds,
        p3, p4);

    log_message_debug("Receive.");

    // The comparison result.
    int r = 0;

    if (r == 0) {

        compare_arrays((void*) *sm, (void*) *smc, (void*) TUI_MODEL, (void*) TUI_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            receive_linux_console(p2, p3, p4, p5, p6, p7, p8, *cm, *cmc);
        }
    }

    if (r == 0) {

        compare_arrays((void*) *sm, (void*) *smc, (void*) X_WINDOW_SYSTEM_MODEL, (void*) X_WINDOW_SYSTEM_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            receive_x_window_system(p2, p3, p4, p5);
        }
    }

    if (r == 0) {

        compare_arrays((void*) *sm, (void*) *smc, (void*) UNIX_SOCKET_MODEL, (void*) UNIX_SOCKET_CHANNEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

/*??
            send_unix_socket((void*) &dn, (void*) &dnc, (void*) &dns,
                (void*) &snm, (void*) &snmc,
                (void*) &sna, (void*) &snac,
                (void*) &INLINE_CHANNEL, (void*) &INLINE_CHANNEL_COUNT);
*/
        }
    }

    if (r == 0) {

        compare_arrays((void*) *sm, (void*) *smc, (void*) TCP_SOCKET_MODEL, (void*) TCP_SOCKET_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            if ((*ba != NULL_POINTER)
                && (*bac != NULL_POINTER)
                && (*bm != NULL_POINTER)
                && (*bmc != NULL_POINTER)) {

                receive_tcp_socket(p2, p3, p4, p5, *ba, *bac, *bm, *bmc);
            }
        }
    }

    if (r == 0) {

        compare_arrays((void*) *sm, (void*) *smc, (void*) LATEX_MODEL, (void*) LATEX_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

//??            receive_latex(p2, *mm, *mmc);
        }
    }
}

/* RECEIVE_SOURCE */
#endif
