/*
 * $RCSfile: send.c,v $
 *
 * Copyright (c) 1999-2004. Christian Heller. All rights reserved.
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
 * @version $Revision: 1.6 $ $Date: 2004-11-30 15:34:00 $ $Author: rholzmueller $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef SEND_SOURCE
#define SEND_SOURCE

#include "../communicator/tui_communicator.c"
#include "../global/abstraction_constants.c"
#include "../global/channel_constants.c"
#include "../global/name_constants.c"
#include "../global/structure_constants.c"
#include "../logger/logger.c"
#include "../socket/unix_socket.c"

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
 * @param pp_internal the internals
 */
void send_message(const void* p0, const void* p1,
    const void* p2, const void* p3, const void* p4,
    void** pp_internal ) {

    // The language abstraction.
    void* la = NULL_POINTER;
    int lac = 0;
    int las = 0;
    // The language model.
    void* lm = NULL_POINTER;
    int lmc = 0;
    int lms = 0;
    // The language details.
    void* ld = NULL_POINTER;
    int ldc = 0;
    int lds = 0;

    // The sender abstraction.
    void* sa = NULL_POINTER;
    int sac = 0;
    int sas = 0;
    // The sender model.
    void* sm = NULL_POINTER;
    int smc = 0;
    int sms = 0;
    // The sender details.
    void* sd = NULL_POINTER;
    int sdc = 0;
    int sds = 0;

    // The receiver abstraction.
    void* ra = NULL_POINTER;
    int rac = 0;
    int ras = 0;
    // The receiver model.
    void* rm = NULL_POINTER;
    int rmc = 0;
    int rms = 0;
    // The receiver details.
    void* rd = NULL_POINTER;
    int rdc = 0;
    int rds = 0;

    // The message abstraction.
    void* ma = NULL_POINTER;
    int mac = 0;
    int mas = 0;
    // The message model.
    void* mm = NULL_POINTER;
    int mmc = 0;
    int mms = 0;
    // The message details.
    void* md = NULL_POINTER;
    int mdc = 0;
    int mds = 0;

    //
    // The language name is taken directly.
    // All other parameters are hierarchical names and used to
    // determine the actual item from the knowledge tree.
    //

/*??
    // Get language.
    get_compound_element_by_encapsulated_name(p0, p1,
        (void*) &LANGUAGE_NAME_ABSTRACTION, (void*) &LANGUAGE_NAME_ABSTRACTION_COUNT,
        (void*) &la, (void*) &lac, (void*) &las,
        (void*) &lm, (void*) &lmc, (void*) &lms,
        (void*) &ld, (void*) &ldc, (void*) &lds,
        p2, p3);
*/

    // Get language.
    get_compound_element_by_name(p0, p1,
        (void*) &LANGUAGE_NAME_ABSTRACTION, (void*) &LANGUAGE_NAME_ABSTRACTION_COUNT,
        (void*) &la, (void*) &lac, (void*) &las,
        (void*) &lm, (void*) &lmc, (void*) &lms,
        (void*) &ld, (void*) &ldc, (void*) &lds);

    // Get sender.
    get_compound_element_by_encapsulated_name(p0, p1,
        (void*) &SENDER_NAME_ABSTRACTION, (void*) &SENDER_NAME_ABSTRACTION_COUNT,
        (void*) &sa, (void*) &sac, (void*) &sas,
        (void*) &sm, (void*) &smc, (void*) &sms,
        (void*) &sd, (void*) &sdc, (void*) &sds,
        p2, p3);

    // Get receiver.
    get_compound_element_by_encapsulated_name(p0, p1,
        (void*) &RECEIVER_NAME_ABSTRACTION, (void*) &RECEIVER_NAME_ABSTRACTION_COUNT,
        (void*) &ra, (void*) &rac, (void*) &ras,
        (void*) &rm, (void*) &rmc, (void*) &rms,
        (void*) &rd, (void*) &rdc, (void*) &rds,
        p2, p3);

    // Get message.
    get_compound_element_by_encapsulated_name(p0, p1,
        (void*) &MESSAGE_NAME_ABSTRACTION, (void*) &MESSAGE_NAME_ABSTRACTION_COUNT,
        (void*) &ma, (void*) &mac, (void*) &mas,
        (void*) &mm, (void*) &mmc, (void*) &mms,
        (void*) &md, (void*) &mdc, (void*) &mds,
        p2, p3);

    // The done flag.
    int d = 0;
    // The comparison result.
    int r = 0;

    if (d == 0) {

        compare_arrays((void*) &lm, (void*) &lmc, (void*) &TUI_LANGUAGE, (void*) &TUI_LANGUAGE_COUNT, (void*) &r, (void*) &CHARACTER_ARRAY);

        if (r == 1) {

            //?? The temporary standard console output as destination.
            //?? Possibly use "sender" information instead, later.
            void* tmpd = (void*) stdout;
            int tmpdc = 0;
            int tmpds = 0;

            send_tui((void*) &tmpd, (void*) &tmpdc, (void*) &tmpds, (void*) &mm, (void*) &mmc);

            d = 1;
        }
    }

    if (d == 0) {

        compare_arrays((void*) &lm, (void*) &lmc, (void*) &UNIX_SOCKET_CHANNEL, (void*) &UNIX_SOCKET_CHANNEL_COUNT, (void*) &r, (void*) &CHARACTER_ARRAY);

        if (r == 1) {

/*??
            send_unix_socket((void*) &dn, (void*) &dnc, (void*) &dns,
                (void*) &snm, (void*) &snmc,
                (void*) &sna, (void*) &snac,
                (void*) &INLINE_CHANNEL, (void*) &INLINE_CHANNEL_COUNT);
*/

            d = 1;
        }
    }
    
    if (d == 0) {

        compare_arrays((void*) &lm, (void*) &lmc, (void*) &TCP_SOCKET_CHANNEL, (void*) &TCP_SOCKET_CHANNEL_COUNT, (void*) &r, (void*) &CHARACTER_ARRAY);

        if (r == 1) {

/*??
            send_tcp_socket      
 
            send_unix_socket((void*) &dn, (void*) &dnc, (void*) &dns,
                (void*) &snm, (void*) &snmc,
                (void*) &sna, (void*) &snac,
                (void*) &INLINE_CHANNEL, (void*) &INLINE_CHANNEL_COUNT);
*/

            d = 1;
        }
    }
    
}

/* SEND_SOURCE */
#endif
