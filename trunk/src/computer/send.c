/*
 * $RCSfile: send.c,v $
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
 * @version $Revision: 1.6 $ $Date: 2005-06-29 22:57:32 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 * @author Rolf Holzmueller <rolf.holzmueller@gmx.de>
 */

#ifndef SEND_SOURCE
#define SEND_SOURCE

#include "../computer/send/send_linux_console.c"
//?? #include "../computer/send/send_tcp_socket.c"
#include "../computer/send/send_x_window_system.c"
#include "../controller/communicator/tcp_socket_communicator.c"
#include "../controller/translator/translator.c"
#include "../globals/constants/abstraction_constants.c"
#include "../globals/constants/channel_constants.c"
#include "../globals/constants/model_constants.c"
#include "../globals/constants/name_constants.c"
#include "../globals/constants/structure_constants.c"
#include "../globals/logger/logger.c"
#include "../memory/accessor/internals_memory_accessor.c"
#include "../memory/creator/integer_creator.c"
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
 * - waiting (blocking): whether the system shall wait until message is sent
 *
 * @param p0 the parameters
 * @param p1 the parameters count
 * @param p2 the knowledge memory
 * @param p3 the knowledge memory count
 * @param p4 the knowledge memory size
 * @param p5 the signal id
 * @param p6 the internals memory
 */
void send_message(const void* p0, const void* p1,
    const void* p2, const void* p3, const void* p4, const void* p5, void* p6) {

    // The language abstraction.
    void** la = NULL_POINTER;
    void** lac = NULL_POINTER;
    void** las = NULL_POINTER;
    // The language model.
    void** lm = NULL_POINTER;
    void** lmc = NULL_POINTER;
    void** lms = NULL_POINTER;
    // The language details.
    void** ld = NULL_POINTER;
    void** ldc = NULL_POINTER;
    void** lds = NULL_POINTER;

    // The sender abstraction.
    void** sa = NULL_POINTER;
    void** sac = NULL_POINTER;
    void** sas = NULL_POINTER;
    // The sender model.
    void** sm = NULL_POINTER;
    void** smc = NULL_POINTER;
    void** sms = NULL_POINTER;
    // The sender details.
    void** sd = NULL_POINTER;
    void** sdc = NULL_POINTER;
    void** sds = NULL_POINTER;

    // The receiver abstraction.
    void** ra = NULL_POINTER;
    void** rac = NULL_POINTER;
    void** ras = NULL_POINTER;
    // The receiver model.
    void** rm = NULL_POINTER;
    void** rmc = NULL_POINTER;
    void** rms = NULL_POINTER;
    // The receiver details.
    void** rd = NULL_POINTER;
    void** rdc = NULL_POINTER;
    void** rds = NULL_POINTER;

    // The message abstraction.
    void** ma = NULL_POINTER;
    void** mac = NULL_POINTER;
    void** mas = NULL_POINTER;
    // The message model.
    void** mm = NULL_POINTER;
    void** mmc = NULL_POINTER;
    void** mms = NULL_POINTER;
    // The message details.
    void** md = NULL_POINTER;
    void** mdc = NULL_POINTER;
    void** mds = NULL_POINTER;

    //
    // The language name is taken directly.
    // All other parameters are hierarchical names and used to
    // determine the actual item from the knowledge tree.
    //

    // Get language.
    get_compound_element_by_name(p0, p1,
        (void*) LANGUAGE_NAME, (void*) LANGUAGE_NAME_COUNT,
        (void*) &la, (void*) &lac, (void*) &las,
        (void*) &lm, (void*) &lmc, (void*) &lms,
        (void*) &ld, (void*) &ldc, (void*) &lds);

    // Get sender.
    get_compound_element_by_name(p0, p1,
        (void*) SENDER_NAME, (void*) SENDER_NAME_COUNT,
        (void*) &sa, (void*) &sac, (void*) &sas,
        (void*) &sm, (void*) &smc, (void*) &sms,
        (void*) &sd, (void*) &sdc, (void*) &sds);

    // Get receiver.
    get_compound_element_by_name(p0, p1,
        (void*) RECEIVER_NAME, (void*) RECEIVER_NAME_COUNT,
        (void*) &ra, (void*) &rac, (void*) &ras,
        (void*) &rm, (void*) &rmc, (void*) &rms,
        (void*) &rd, (void*) &rdc, (void*) &rds);

    // Get message.
    get_real_compound_element_by_name(p0, p1,
        (void*) MESSAGE_NAME, (void*) MESSAGE_NAME_COUNT,
        (void*) &ma, (void*) &mac, (void*) &mas,
        (void*) &mm, (void*) &mmc, (void*) &mms,
        (void*) &md, (void*) &mdc, (void*) &mds,
        p2, p3);

    // The comparison result.
    int r = 0;

    if (r != 1) {

        compare_arrays((void*) *lm, (void*) *lmc, (void*) TUI_MODEL, (void*) TUI_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

            //?? The temporary standard console output as destination.
            //?? Possibly use "sender" information instead, later.
            void* tmpd = (void*) stdout;
            void* tmpdc = NULL_POINTER;
            void* tmpds = NULL_POINTER;

            send_linux_console(tmpd, tmpdc, tmpds, *mm, *mmc);
        }
    }

    if (r != 1) {

        compare_arrays((void*) *lm, (void*) *lmc, (void*) X_WINDOW_SYSTEM_MODEL, (void*) X_WINDOW_SYSTEM_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

            send_x_window_system(p6, p2, p3, p4);
        }
    }

    if (r != 1) {

        compare_arrays( (void*) *lm, (void*) *lmc,
                        (void*) SIGNAL_MODEL,
                        (void*) SIGNAL_MODEL_COUNT,
                        (void*) &r, (void*) CHARACTER_ARRAY );

        if (r == 1) {

            //set_signal
            log_message_debug("Set signal.");

            // The signal memory.
            void** sm = NULL_POINTER;
            void** smc = NULL_POINTER;
            void** sms = NULL_POINTER;

            // Get signal memory.
            get_array_elements(p6, (void*) SIGNAL_MEMORY_INTERNAL, (void*) &sm, (void*) POINTER_ARRAY);
            get_array_elements(p6, (void*) SIGNAL_MEMORY_COUNT_INTERNAL, (void*) &smc, (void*) POINTER_ARRAY);
            get_array_elements(p6, (void*) SIGNAL_MEMORY_SIZE_INTERNAL, (void*) &sms, (void*) POINTER_ARRAY);

            // Set signal.
            set_signal(*sm, *smc, *sms,
                (void*) *ma, (void*) *mac,
                (void*) *mm, (void*) *mmc,
                (void*) *md, (void*) *mdc,
                (void*) NORMAL_PRIORITY, p5);

        }
    }

    if (r != 1) {

        compare_arrays((void*) *lm, (void*) *lmc, (void*) TCP_SOCKET_MODEL, (void*) TCP_SOCKET_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

            // The socket number for the signal id.
            // The index for the signal id in the array is the same index
            // in the client socket number array.
            int i = -1;

            get_index_for_signal_id(p6, p5, (void*) &i);

            if (i >= 0) {

                // The client socket.
                int* cs = INTEGER_NULL_POINTER;

                get_client_socket_number_for_index(p6, (void*) &i, (void*) &cs);

                if (*cs >= 0) {

                    //in abh?ngigkeit vom empf?nger
                    //m?ssen die Daten verschieden aufbereitet werden
                    //zur Zeit nur TCP socket f?r webanwednung
                    //darum z.Z. immer html-Aufbereitung
                    //--> das bedeuet, das ermittelte Modell
                    //muss noch f?r die Ausgabe aufbereuitet (tranlate) werden.

                    //create the destination for the send model
                    void* dest = NULL_POINTER;
                    int* dest_count = INTEGER_NULL_POINTER;
                    int* dest_size = INTEGER_NULL_POINTER;

                    create( &dest_count, INTEGER_COUNT,
                            INTEGER_ABSTRACTION, INTEGER_ABSTRACTION_COUNT );
                    create( &dest_size, INTEGER_COUNT,
                            INTEGER_ABSTRACTION, INTEGER_ABSTRACTION_COUNT );
                    *dest_count = 0;
                    *dest_size  = 0;
                    create( &dest, dest_size,
                            STRING_ABSTRACTION, STRING_ABSTRACTION_COUNT );

                    encode_model( &dest, dest_count, dest_size,
                                  *ma, *mac,
                                  *mm, *mmc,
                                  *md, *mdc,
                                  (void*) HTML_ABSTRACTION,
                                  (void*) HTML_ABSTRACTION_COUNT,
                                  p2, p3 );

                    // The temporary count, size.
                    int tc = 0;
                    int ts = 0;

                    send_tcp_socket( (void*) &cs, (void*) &tc, (void*) &ts,
                                     (void*) dest, (void*) dest_count );

                    // Remove client socket number and main signal id from internals.
                    remove_relation_clientsocketnumber_mainsignalid(p6, (void*) &i);

                    // Close socket.
                    close(*cs);

                    //destroy destination
                    destroy( &dest, dest_size,
                             STRING_ABSTRACTION, STRING_ABSTRACTION_COUNT );
                    destroy( &dest_count, INTEGER_COUNT,
                             INTEGER_ABSTRACTION, INTEGER_ABSTRACTION_COUNT );
                    destroy( &dest_size, INTEGER_COUNT,
                             INTEGER_ABSTRACTION, INTEGER_ABSTRACTION_COUNT );

                } else {

                    log_message_debug("Could not send tcp socket message. The client socket number was not found.");
                }

            } else {

                log_message_debug("Could not send tcp socket message. The signal id index is invalid.");
            }
        }
    }
}

/**
 * @param p0 the parameters
 * @param p1 the parameters count
 * @param p2 the knowledge
 * @param p3 the knowledge count
 * @param p4 the knowledge size
 * @param p5 the signal id
 * @param p6 the internals
 */
void send_url_refresh( const void* p0, const void* p1,
    const void* p2, const void* p3, const void* p4, const void* p5, void* p6) {

    // The message abstraction.
    void** urla = NULL_POINTER;
    void** urlac = NULL_POINTER;
    void** urlas = NULL_POINTER;
    // The message model.
    void** urlm = NULL_POINTER;
    void** urlmc = NULL_POINTER;
    void** urlms = NULL_POINTER;
    // The message details.
    void** urld = NULL_POINTER;
    void** urldc = NULL_POINTER;
    void** urlds = NULL_POINTER;

    // Get language.
    get_real_compound_element_by_name(p0, p1,
        (void*) URL_NAME, (void*) URL_NAME_COUNT,
        (void*) &urla, (void*) &urlac, (void*) &urlas,
        (void*) &urlm, (void*) &urlmc, (void*) &urlms,
        (void*) &urld, (void*) &urldc, (void*) &urlds,
        p2, p3 );

    if (    (urla != NULL_POINTER)
         && (urlac != NULL_POINTER)
         && (urlas != NULL_POINTER)
         && (urlm != NULL_POINTER)
         && (urlmc != NULL_POINTER)
         && (urlms != NULL_POINTER)
         && (urld != NULL_POINTER)
         && (urldc != NULL_POINTER)
         && (urlds != NULL_POINTER)
       )
    {

        // The socket number for the signal id.
        // The index for the signal id in the array is the same index
        // in the client socket number array.
        int i = -1;

        get_index_for_signal_id(p6, p5, (void*) &i);

        if (i >= 0) {

            // The client socket.
            int* cs = INTEGER_NULL_POINTER;

            get_client_socket_number_for_index(p6, (void*) &i, (void*) &cs);

            if (*cs >= 0) {

                    char msg_refresh_part_1[] = "<head> <meta http-equiv='expires' content='0'>  <meta http-equiv='refresh' content='0; URL=";
                    char msg_refresh_part_3[] = "'></head><body></body>";
                    int msg_part_1_count = strlen( msg_refresh_part_1 );
                    int msg_part_3_count = strlen( msg_refresh_part_3 );

                    //create the destination for the send model
                    void* dest = NULL_POINTER;
                    int* dest_count = INTEGER_NULL_POINTER;
                    int* dest_size = INTEGER_NULL_POINTER;

                    create( &dest_count, INTEGER_COUNT,
                            INTEGER_ABSTRACTION, INTEGER_ABSTRACTION_COUNT );
                    create( &dest_size, INTEGER_COUNT,
                            INTEGER_ABSTRACTION, INTEGER_ABSTRACTION_COUNT );
                    *dest_count = 0;
                    *dest_size  = 0;
                    create( &dest, dest_size,
                            STRING_ABSTRACTION, STRING_ABSTRACTION_COUNT );

                    parse( &dest, dest_count, dest_size,
                           &msg_refresh_part_1[0], &msg_part_1_count,
                           STRING_ABSTRACTION, STRING_ABSTRACTION_COUNT);

                    parse( &dest, dest_count, dest_size,
                           *urlm, *urlmc,
                           STRING_ABSTRACTION, STRING_ABSTRACTION_COUNT);

                    parse( &dest, dest_count, dest_size,
                           &msg_refresh_part_3[0], &msg_part_3_count,
                           STRING_ABSTRACTION, STRING_ABSTRACTION_COUNT);

                    // The temporary count, size.
                    int tc = 0;
                    int ts = 0;

                    send_tcp_socket( (void*) &cs, (void*) &tc, (void*) &ts,
                                     (void*) dest, (void*) dest_count );

                    // Remove client socket number and main signal id from internals.
                    remove_relation_clientsocketnumber_mainsignalid(p6, (void*) &i);

                    // Close socket.
                    close(*cs);

                    //destroy destination
                    destroy( &dest, dest_size,
                             STRING_ABSTRACTION, STRING_ABSTRACTION_COUNT );
                    destroy( &dest_count, INTEGER_COUNT,
                             INTEGER_ABSTRACTION, INTEGER_ABSTRACTION_COUNT );
                    destroy( &dest_size, INTEGER_COUNT,
                             INTEGER_ABSTRACTION, INTEGER_ABSTRACTION_COUNT );

            }
        }
    }
}
/* SEND_SOURCE */
#endif
