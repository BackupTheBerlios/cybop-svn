/*
 * $RCSfile: send.c,v $
 *
 * Copyright (c) 1999-2005. Christian Heller. All rights reserved.
 *
 * This software is published under the GPL GNU General Public License.
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
 * @version $Revision: 1.12 $ $Date: 2005-01-18 15:07:01 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 * @author Rolf Holzmueller <rolf.holzmueller@gmx.de>
 */

#ifndef SEND_SOURCE
#define SEND_SOURCE

#include "../communicator/tui_communicator.c"
#include "../communicator/tcp_socket_communicator.c"
#include "../creator/integer_creator.c"
#include "../global/abstraction_constants.c"
#include "../global/channel_constants.c"
#include "../global/name_constants.c"
#include "../global/structure_constants.c"
#include "../logger/logger.c"
#include "../socket/unix_socket.c"
#include "../web/socket_number_accessor.c"

/**
 * Sends a message in a special language.
 *
 * CAUTION! Do NOT rename this procedure to "send",
 * as that name is already used by socket functionality.
 *
 * Expected parameters:
 * - language (channel): internal, tui, gui, socket, http
 * - sender (who): ip address, socket port
 * - receiver (whom): ip address, socket port
 * - message (what): knowledge model to be sent in serialized form
 *
 * (OLD!!) CYBOL Examples:
 *
 * <!-- Operation parameters (as value of part_model tag):
 *      logic name,language,sender,receiver,message /-->
 *
 * <part name="send_to_socket" part_abstraction="operation" part_location="inline"
 *      part_model="send,application.language,application.sender,application.receiver,application.message"/>
 *
 * @param p0 the parameters
 * @param p1 the parameters count
 * @param p2 the knowledge
 * @param p3 the knowledge count
 * @param p4 the knowledge size
 * @param p5 the signal id
 * @param p6 the internals
 */
void send_message(const void* p0, const void* p1,
    const void* p2, const void* p3, const void* p4, const void* p5, void* p6) {

    // The language abstraction.
    void* la = NULL_POINTER;
    void* lac = NULL_POINTER;
    void* las = NULL_POINTER;
    // The language model.
    void* lm = NULL_POINTER;
    void* lmc = NULL_POINTER;
    void* lms = NULL_POINTER;
    // The language details.
    void* ld = NULL_POINTER;
    void* ldc = NULL_POINTER;
    void* lds = NULL_POINTER;

    // The sender abstraction.
    void* sa = NULL_POINTER;
    void* sac = NULL_POINTER;
    void* sas = NULL_POINTER;
    // The sender model.
    void* sm = NULL_POINTER;
    void* smc = NULL_POINTER;
    void* sms = NULL_POINTER;
    // The sender details.
    void* sd = NULL_POINTER;
    void* sdc = NULL_POINTER;
    void* sds = NULL_POINTER;

    // The receiver abstraction.
    void* ra = NULL_POINTER;
    void* rac = NULL_POINTER;
    void* ras = NULL_POINTER;
    // The receiver model.
    void* rm = NULL_POINTER;
    void* rmc = NULL_POINTER;
    void* rms = NULL_POINTER;
    // The receiver details.
    void* rd = NULL_POINTER;
    void* rdc = NULL_POINTER;
    void* rds = NULL_POINTER;

    // The message abstraction.
    void* ma = NULL_POINTER;
    void* mac = NULL_POINTER;
    void* mas = NULL_POINTER;
    // The message model.
    void* mm = NULL_POINTER;
    void* mmc = NULL_POINTER;
    void* mms = NULL_POINTER;
    // The message details.
    void* md = NULL_POINTER;
    void* mdc = NULL_POINTER;
    void* mds = NULL_POINTER;

    //
    // The language name is taken directly.
    // All other parameters are hierarchical names and used to
    // determine the actual item from the knowledge tree.
    //

    // Get language.
    get_compound_element_by_name(p0, p1,
        (void*) LANGUAGE_NAME_ABSTRACTION, (void*) LANGUAGE_NAME_ABSTRACTION_COUNT,
        (void*) &la, (void*) &lac, (void*) &las,
        (void*) &lm, (void*) &lmc, (void*) &lms,
        (void*) &ld, (void*) &ldc, (void*) &lds);

    // Get sender.
    get_compound_element_by_encapsulated_name(p0, p1,
        (void*) SENDER_NAME_ABSTRACTION, (void*) SENDER_NAME_ABSTRACTION_COUNT,
        (void*) &sa, (void*) &sac, (void*) &sas,
        (void*) &sm, (void*) &smc, (void*) &sms,
        (void*) &sd, (void*) &sdc, (void*) &sds,
        p2, p3);

    // Get receiver.
    get_compound_element_by_encapsulated_name(p0, p1,
        (void*) RECEIVER_NAME_ABSTRACTION, (void*) RECEIVER_NAME_ABSTRACTION_COUNT,
        (void*) &ra, (void*) &rac, (void*) &ras,
        (void*) &rm, (void*) &rmc, (void*) &rms,
        (void*) &rd, (void*) &rdc, (void*) &rds,
        p2, p3);

    // Get message.
    get_compound_element_by_encapsulated_name(p0, p1,
        (void*) MESSAGE_NAME_ABSTRACTION, (void*) MESSAGE_NAME_ABSTRACTION_COUNT,
        (void*) &ma, (void*) &mac, (void*) &mas,
        (void*) &mm, (void*) &mmc, (void*) &mms,
        (void*) &md, (void*) &mdc, (void*) &mds,
        p2, p3);

    // The comparison result.
    int r = 0;

    if (r != 1) {

        compare_arrays((void*) lm, (void*) lmc, (void*) TUI_LANGUAGE, (void*) TUI_LANGUAGE_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

            //?? The temporary standard console output as destination.
            //?? Possibly use "sender" information instead, later.
            void* tmpd = (void*) stdout;
            void* tmpdc = NULL_POINTER;
            void* tmpds = NULL_POINTER;

            send_tui((void*) tmpd, (void*) tmpdc, (void*) tmpds, (void*) mm, (void*) mmc);
        }
    }

    if (r != 1) {

        compare_arrays((void*) lm, (void*) lmc, (void*) UNIX_SOCKET_CHANNEL, (void*) UNIX_SOCKET_CHANNEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

/*??
            send_unix_socket((void*) &dn, (void*) &dnc, (void*) &dns,
                (void*) &snm, (void*) &snmc,
                (void*) &sna, (void*) &snac,
                (void*) &INLINE_CHANNEL, (void*) &INLINE_CHANNEL_COUNT);
*/
        }
    }

    if (r != 1) {

        compare_arrays((void*) lm, (void*) lmc, (void*) TCP_SOCKET_CHANNEL, (void*) TCP_SOCKET_CHANNEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

            // The socket number for the signal id.
            // The index for the signal id in the array is the same index
            // in the client socket number array.
            int i = -1;

            get_index_for_signal_id(p6, p5, (void*) &i);

            if (i >= 0) {

                // The client socket.
                int cs = -1;

                get_client_socket_number_for_index(p6, (void*) &i, (void*) &cs);

                if (cs >= 0) {

                    // The temporary count, size.
                    int tc = 0;
                    int ts = 0;

                    send_tcp_socket((void*) &cs, (void*) &tc, (void*) &ts, (void*) &mm, (void*) &mmc);

                    // Remove client socket number and main signal id from internals.
                    remove_relation_clientsocketnumber_mainsignalid(p6, (void*) &i);

                    // Close socket.
                    close(cs);

                } else {

                    log_message_debug("Could not send tcp socket message. The client socket number was not found.");
                }

            } else {

                log_message_debug("Could not send tcp socket message. The signal id index is invalid.");
            }
        }
    }
}

/* SEND_SOURCE */
#endif
