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
 * @version $Revision: 1.1 $ $Date: 2004-07-04 09:49:29 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef SEND_SOURCE
#define SEND_SOURCE

#include "../logger/logger.c"

/**
 * Sends a message in a special language.
 *
 * @param p0 the language
 * @param p1 the language count
 * @param p2 the sender address
 * @param p3 the sender address count
 * @param p4 the receiver address
 * @param p5 the receiver address count
 * @param p6 the message
 * @param p7 the message count
 * @param p8 the character internals
 * @param p9 the integer internals
 * @param p10 the pointer internals
 * @param p11 the double internals
 */
void send_in_language(const void* p0, const void* p1, const void* p2, const void* p3,
    const void* p4, const void* p5, const void* p6, const void* p7,
    const void* p8, const void* p9, const void* p10, const void* p11) {

    if (p1 != NULL_POINTER) {

        int* lc = (int*) p1;

        // The done flag.
        int d = 0;
        // The comparison result.
        int r = 0;

        if (d == 0) {

            if (*lc == UNIX_SOCKET_LANGUAGE_COUNT) {

                compare_array_elements(p0, (void*) &UNIX_SOCKET_LANGUAGE, (void*) &CHARACTER_ARRAY, (void*) &UNIX_SOCKET_LANGUAGE_COUNT, (void*) &r);

                if (r == 1) {

                    send_unix_socket(p4, p5, p6, p7);

                    d = 1;
                }
            }
        }

        if (d == 0) {

            if (*lc == INTERNAL_LANGUAGE_COUNT) {

                compare_array_elements(p0, (void*) &INTERNAL_LANGUAGE, (void*) &CHARACTER_ARRAY, (void*) &INTERNAL_LANGUAGE_COUNT, (void*) &r);

                if (r == 1) {

//??                    send_internal(p0, p1, p2);

                    d = 1;
                }
            }
        }

    } else {

//??        log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_HANDLE_CREATE_MODEL_SIGNAL_THE_SIGNAL_PARAMETERS_COUNT_IS_NULL_MESSAGE, (void*) &COULD_NOT_HANDLE_CREATE_MODEL_SIGNAL_THE_SIGNAL_PARAMETERS_COUNT_IS_NULL_MESSAGE_COUNT);
    }
}

/**
 * Sends a message to another system.
 *
 * CAUTION! Do NOT rename this procedure to "send",
 * as that name is already used by socket functionality.
 *
 * The contents of communication is described by the "Laswell Formula".
 * After it, communication consists of the elements:
 * - language (Channel): internal, tui, gui, socket, http
 * - sender (Who): ip address, socket port
 * - receiver (Whom): ip address, socket port
 * - message (What): knowledge model to be sent in serialized form
 * - result (Effect): ignored because not relevant for sender
 *
 * CYBOL Examples:
 *
 * <!-- Operation parameters (as value of part_model tag):
 *      logic name,language,sender,receiver,message /-->
 *
 * <part name="send_to_socket" part_abstraction="operation" part_location="inline"
 *      part_model="send,application.language,application.sender,application.receiver,application.message"/>
 *
 * @param p0 the signal parameters count
 * @param p1 the parameters
 * @param p2 the parameters counts
 * @param p3 the parameters sizes
 * @param p4 the knowledge
 * @param p5 the knowledge count
 * @param p6 the knowledge size
 * @param p7 the character internals
 * @param p8 the integer internals
 * @param p9 the pointer internals
 * @param p10 the double internals
 */
void send_message(const void* p0, const void* p1, const void* p2, const void* p3,
    const void* p4, const void* p5, const void* p6,
    const void* p7, const void* p8, const void* p9, const void* p10) {

    if (p0 != NULL_POINTER) {

        int* sc = (int*) p0;

        if (*sc == 5) {

            // Initialize persistent language-, sender-, receiver-, message name
            // and their counts and sizes.
            void* pl = NULL_POINTER;
            int plc = 0;
            int pls = 0;
            void* ps = NULL_POINTER;
            int psc = 0;
            int pss = 0;
            void* pr = NULL_POINTER;
            int prc = 0;
            int prs = 0;
            void* pm = NULL_POINTER;
            int pmc = 0;
            int pms = 0;

            // CAUTION! The parameter at index 0 is the logic/ operation name.
            // Input and output parameters start with index 1.

            // The loop variable.
            int j = 1;

            while (1) {

                if (j >= *sc) {

                    break;
                }

                // CAUTION! The parameter at index 0 is the logic/ operation name.
                // Input and output parameters start with index 1.

                if (j == 1) {

                    // Get persistent language name and its count and size.
                    get_array_element(p1, (void*) &POINTER_ARRAY, (void*) &j, (void*) &pl);
                    get_array_element(p2, (void*) &INTEGER_ARRAY, (void*) &j, (void*) &plc);
                    get_array_element(p3, (void*) &INTEGER_ARRAY, (void*) &j, (void*) &pls);

                } else if (j == 2) {

                    // Get persistent sender name and its count and size.
                    get_array_element(p1, (void*) &POINTER_ARRAY, (void*) &j, (void*) &ps);
                    get_array_element(p2, (void*) &INTEGER_ARRAY, (void*) &j, (void*) &psc);
                    get_array_element(p3, (void*) &INTEGER_ARRAY, (void*) &j, (void*) &pss);

                } else if (j == 3) {

                    // Get persistent receiver name and its count and size.
                    get_array_element(p1, (void*) &POINTER_ARRAY, (void*) &j, (void*) &pr);
                    get_array_element(p2, (void*) &INTEGER_ARRAY, (void*) &j, (void*) &prc);
                    get_array_element(p3, (void*) &INTEGER_ARRAY, (void*) &j, (void*) &prs);

                } else if (j == 4) {

                    // Get persistent message name and its count and size.
                    get_array_element(p1, (void*) &POINTER_ARRAY, (void*) &j, (void*) &pm);
                    get_array_element(p2, (void*) &INTEGER_ARRAY, (void*) &j, (void*) &pmc);
                    get_array_element(p3, (void*) &INTEGER_ARRAY, (void*) &j, (void*) &pms);
                }

                j++;
            }

            // Initialize transient language, sender, receiver, message
            // and their counts and sizes.
            void* tl = NULL_POINTER;
            int tlc = 0;
            int tls = 0;
            void* ts = NULL_POINTER;
            int tsc = 0;
            int tss = 0;
            void* tr = NULL_POINTER;
            int trc = 0;
            int trs = 0;
            void* tm = NULL_POINTER;
            int tmc = 0;
            int tms = 0;

            // Get transient language, sender, receiver, message
            // and their counts and sizes.
            get_compound_part_by_name(p4, p5, p6,
                (void*) &pl, (void*) &plc, (void*) &pls,
                (void*) &tl, (void*) &tlc, (void*) &tls,
                (void*) &NULL_POINTER, (void*) &NULL_POINTER, (void*) &NULL_POINTER,
                (void*) &NULL_POINTER, (void*) &NULL_POINTER, (void*) &NULL_POINTER,
                (void*) &NULL_POINTER, (void*) &NULL_POINTER, (void*) &NULL_POINTER,
                (void*) &NULL_POINTER, (void*) &NULL_POINTER, (void*) &NULL_POINTER,
                (void*) &NULL_POINTER, (void*) &NULL_POINTER, (void*) &NULL_POINTER);
            get_compound_part_by_name(p4, p5, p6,
                (void*) &ps, (void*) &psc, (void*) &pss,
                (void*) &ts, (void*) &tsc, (void*) &tss,
                (void*) &NULL_POINTER, (void*) &NULL_POINTER, (void*) &NULL_POINTER,
                (void*) &NULL_POINTER, (void*) &NULL_POINTER, (void*) &NULL_POINTER,
                (void*) &NULL_POINTER, (void*) &NULL_POINTER, (void*) &NULL_POINTER,
                (void*) &NULL_POINTER, (void*) &NULL_POINTER, (void*) &NULL_POINTER,
                (void*) &NULL_POINTER, (void*) &NULL_POINTER, (void*) &NULL_POINTER);
            get_compound_part_by_name(p4, p5, p6,
                (void*) &pr, (void*) &prc, (void*) &prs,
                (void*) &tr, (void*) &trc, (void*) &trs,
                (void*) &NULL_POINTER, (void*) &NULL_POINTER, (void*) &NULL_POINTER,
                (void*) &NULL_POINTER, (void*) &NULL_POINTER, (void*) &NULL_POINTER,
                (void*) &NULL_POINTER, (void*) &NULL_POINTER, (void*) &NULL_POINTER,
                (void*) &NULL_POINTER, (void*) &NULL_POINTER, (void*) &NULL_POINTER,
                (void*) &NULL_POINTER, (void*) &NULL_POINTER, (void*) &NULL_POINTER);
            get_compound_part_by_name(p4, p5, p6,
                (void*) &pm, (void*) &pmc, (void*) &pms,
                (void*) &tm, (void*) &tmc, (void*) &tms,
                (void*) &NULL_POINTER, (void*) &NULL_POINTER, (void*) &NULL_POINTER,
                (void*) &NULL_POINTER, (void*) &NULL_POINTER, (void*) &NULL_POINTER,
                (void*) &NULL_POINTER, (void*) &NULL_POINTER, (void*) &NULL_POINTER,
                (void*) &NULL_POINTER, (void*) &NULL_POINTER, (void*) &NULL_POINTER,
                (void*) &NULL_POINTER, (void*) &NULL_POINTER, (void*) &NULL_POINTER);

            // Send message in a special language.
            send_in_language((void*) &tl, (void*) &tlc, (void*) &ts, (void*) &tsc,
                (void*) &tr, (void*) &trc, (void*) &tm, (void*) &tmc, p7, p8, p9, p10);

        } else {

//??            log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_HANDLE_SEND_SIGNAL_THE_SIGNAL_PARAMETERS_COUNT_DOES_NOT_MATCH_MESSAGE, (void*) &COULD_NOT_HANDLE_SEND_SIGNAL_THE_SIGNAL_PARAMETERS_COUNT_DOES_NOT_MATCH_MESSAGE_COUNT);
        }

    } else {

//??        log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_HANDLE_SEND_SIGNAL_THE_SIGNAL_PARAMETERS_COUNT_IS_NULL_MESSAGE, (void*) &COULD_NOT_HANDLE_SEND_SIGNAL_THE_SIGNAL_PARAMETERS_COUNT_IS_NULL_MESSAGE_COUNT);
    }
}

/* SEND_SOURCE */
#endif
