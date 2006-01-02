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
 * @version $Revision: 1.25 $ $Date: 2006-01-02 11:56:01 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 * @author Rolf Holzmueller <rolf.holzmueller@gmx.de>
 */

#ifndef SEND_SOURCE
#define SEND_SOURCE

#include "../applicator/send/send_latex.c"
#include "../applicator/send/send_linux_console.c"
#include "../applicator/send/send_tcp_socket.c"
#include "../applicator/send/send_unix_socket.c"
#include "../applicator/send/send_x_window_system.c"
#include "../globals/constants/abstraction_constants.c"
#include "../globals/constants/channel_constants.c"
#include "../globals/constants/model_constants.c"
#include "../globals/constants/name_constants.c"
#include "../globals/constants/structure_constants.c"
#include "../globals/logger/logger.c"
#include "../memoriser/accessor/internal_memory_accessor.c"
#include "../memoriser/allocator.c"
#include "../memoriser/communicator/tcp_socket_communicator.c"
#include "../memoriser/translator.c"

/**
 * Sends a message in a special language.
 *
 * CAUTION! Do NOT rename this procedure to "send",
 * as that name is already used by socket functionality.
 *
 * Expected parameters (names in parentheses after Laswell):
 * - channel (channel): linux_console, tcp_socket, unix_socket, x_window_system
 * - sender (who): ip address, socket port
 * - receiver (whom): ip address, socket port
 * - message (what): dot-separated name of knowledge model to be sent
 * - waiting (blocking): whether the system shall wait until message is sent
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
 * @param p9 the signal id
 */
void send_message(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5,
    void* p6, void* p7, void* p8, void* p9) {

    log_message_debug("Send message.");

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

    // The sender abstraction.
    void** sa = &NULL_POINTER;
    void** sac = &NULL_POINTER;
    void** sas = &NULL_POINTER;
    // The sender model.
    void** sm = &NULL_POINTER;
    void** smc = &NULL_POINTER;
    void** sms = &NULL_POINTER;
    // The sender details.
    void** sd = &NULL_POINTER;
    void** sdc = &NULL_POINTER;
    void** sds = &NULL_POINTER;

    // The receiver abstraction.
    void** ra = &NULL_POINTER;
    void** rac = &NULL_POINTER;
    void** ras = &NULL_POINTER;
    // The receiver model.
    void** rm = &NULL_POINTER;
    void** rmc = &NULL_POINTER;
    void** rms = &NULL_POINTER;
    // The receiver details.
    void** rd = &NULL_POINTER;
    void** rdc = &NULL_POINTER;
    void** rds = &NULL_POINTER;

    // The message abstraction.
    void** ma = &NULL_POINTER;
    void** mac = &NULL_POINTER;
    void** mas = &NULL_POINTER;
    // The message model.
    void** mm = &NULL_POINTER;
    void** mmc = &NULL_POINTER;
    void** mms = &NULL_POINTER;
    // The message details.
    void** md = &NULL_POINTER;
    void** mdc = &NULL_POINTER;
    void** mds = &NULL_POINTER;

    // Get channel.
    get_compound_element_by_name(p0, p1,
        (void*) CHANNEL_NAME, (void*) CHANNEL_NAME_COUNT,
        (void*) &ca, (void*) &cac, (void*) &cas,
        (void*) &cm, (void*) &cmc, (void*) &cms,
        (void*) &cd, (void*) &cdc, (void*) &cds);

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
        p3, p4);

    // The comparison result.
    int r = 0;

    if (r == 0) {

        compare_arrays((void*) *cm, (void*) *cmc, (void*) LATEX_MODEL, (void*) LATEX_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            send_latex(p2, *mm, *mmc);
        }
    }

    if (r == 0) {

        compare_arrays((void*) *cm, (void*) *cmc, (void*) LINUX_CONSOLE_MODEL, (void*) LINUX_CONSOLE_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            send_linux_console(p2, *mm, *mmc);
        }
    }

    if (r == 0) {

        compare_arrays((void*) *cm, (void*) *cmc, (void*) SIGNAL_MODEL, (void*) SIGNAL_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            set_signal(p6, p7, p8, (void*) *ma, (void*) *mac, (void*) *mm, (void*) *mmc, (void*) *md, (void*) *mdc, (void*) NORMAL_PRIORITY, p9);
        }
    }

    if (r == 0) {

        compare_arrays((void*) *cm, (void*) *cmc, (void*) TCP_SOCKET_MODEL, (void*) TCP_SOCKET_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

/*??
            // The socket number for the signal id.
            // The index for the signal id in the array is the same index
            // in the client socket number array.
            int i = -1;

            get_index_for_signal_id(p2, p9, (void*) &i);

            if (i >= 0) {

                // The client socket.
                int* cs = NULL_POINTER;

                get_client_socket_number_for_index(p2, (void*) &i, (void*) &cs);

                if (*cs >= 0) {

                    //in abh?ngigkeit vom empf?nger
                    //m?ssen die Daten verschieden aufbereitet werden
                    //zur Zeit nur TCP socket f?r webanwednung
                    //darum z.Z. immer html-Aufbereitung
                    //--> das bedeuet, das ermittelte Modell
                    //muss noch f?r die Ausgabe aufbereuitet (tranlate) werden.

                    //create the destination for the send model
                    void* dest = NULL_POINTER;
                    int* dest_count = NULL_POINTER;
                    int* dest_size = NULL_POINTER;

                    allocate(&dest_count, PRIMITIVE_COUNT, INTEGER_VECTOR_ABSTRACTION, INTEGER_VECTOR_ABSTRACTION_COUNT);
                    allocate(&dest_size, PRIMITIVE_COUNT, INTEGER_VECTOR_ABSTRACTION, INTEGER_VECTOR_ABSTRACTION_COUNT);
                    *dest_count = 0;
                    *dest_size  = 0;
                    allocate(&dest, dest_size, CHARACTER_VECTOR_ABSTRACTION, CHARACTER_VECTOR_ABSTRACTION_COUNT);

                    encode_model(&dest, dest_count, dest_size,
                        *ma, *mac, *mm, *mmc, *md, *mdc,
                        (void*) HTML_ABSTRACTION, (void*) HTML_ABSTRACTION_COUNT,
                        p3, p4);

                    // The temporary count, size.
                    int tc = 0;
                    int ts = 0;

                    send_tcp_socket((void*) &cs, (void*) &tc, (void*) &ts, (void*) dest, (void*) dest_count);

                    // Remove client socket number and main signal id from internal memory.
                    remove_relation_clientsocketnumber_mainsignalid(p2, (void*) &i);

                    // Close socket.
                    close(*cs);

                    // Destroy destination.
                    deallocate(&dest, dest_size, CHARACTER_VECTOR_ABSTRACTION, CHARACTER_VECTOR_ABSTRACTION_COUNT);
                    deallocate(&dest_count, PRIMITIVE_COUNT, INTEGER_VECTOR_ABSTRACTION, INTEGER_VECTOR_ABSTRACTION_COUNT);
                    deallocate(&dest_size, PRIMITIVE_COUNT, INTEGER_VECTOR_ABSTRACTION, INTEGER_VECTOR_ABSTRACTION_COUNT);

                } else {

                    log_message_debug("Could not send tcp socket message. The client socket number was not found.");
                }

            } else {

                log_message_debug("Could not send tcp socket message. The signal id index is invalid.");
            }
*/
        }
    }

    if (r == 0) {

        compare_arrays((void*) *cm, (void*) *cmc, (void*) UNIX_SOCKET_MODEL, (void*) UNIX_SOCKET_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            send_unix_socket(p2, *mm, *mmc);
        }
    }

    if (r == 0) {

        compare_arrays((void*) *cm, (void*) *cmc, (void*) X_WINDOW_SYSTEM_MODEL, (void*) X_WINDOW_SYSTEM_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            send_x_window_system(p2, *mm, *mmc);
        }
    }
}

/**
 * Refreshes the url.
 *
 * @param p0 the parameters
 * @param p1 the parameters count
 * @param p2 the internal memory
 * @param p3 the knowledge memory
 * @param p4 the knowledge memory count
 * @param p5 the knowledge memory size
 * @param p6 the signal id
 */
void refresh_url(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    log_message_debug("Refresh URL.");

    // The message abstraction.
    void** urla = &NULL_POINTER;
    void** urlac = &NULL_POINTER;
    void** urlas = &NULL_POINTER;
    // The message model.
    void** urlm = &NULL_POINTER;
    void** urlmc = &NULL_POINTER;
    void** urlms = &NULL_POINTER;
    // The message details.
    void** urld = &NULL_POINTER;
    void** urldc = &NULL_POINTER;
    void** urlds = &NULL_POINTER;

    // Get language.
    get_real_compound_element_by_name(p0, p1,
        (void*) URL_NAME, (void*) URL_NAME_COUNT,
        (void*) &urla, (void*) &urlac, (void*) &urlas,
        (void*) &urlm, (void*) &urlmc, (void*) &urlms,
        (void*) &urld, (void*) &urldc, (void*) &urlds,
        p3, p4);

/*??
    if ((*urla != NULL_POINTER)
         && (*urlac != NULL_POINTER)
         && (*urlas != NULL_POINTER)
         && (*urlm != NULL_POINTER)
         && (*urlmc != NULL_POINTER)
         && (*urlms != NULL_POINTER)
         && (*urld != NULL_POINTER)
         && (*urldc != NULL_POINTER)
         && (*urlds != NULL_POINTER)) {

        // The socket number for the signal id.
        // The index for the signal id in the array is the same index
        // in the client socket number array.
        int i = -1;

        get_index_for_signal_id(p2, p6, (void*) &i);

        if (i >= 0) {

            // The client socket.
            int* cs = NULL_POINTER;

            get_client_socket_number_for_index(p2, (void*) &i, (void*) &cs);

            if (*cs >= 0) {

                char msg_refresh_part_1[] = "<head> <meta http-equiv='expires' content='0'>  <meta http-equiv='refresh' content='0; URL=";
                char msg_refresh_part_3[] = "'></head><body></body>";
                int msg_part_1_count = strlen( msg_refresh_part_1 );
                int msg_part_3_count = strlen( msg_refresh_part_3 );

                //create the destination for the send model
                void* dest = NULL_POINTER;
                int* dest_count = NULL_POINTER;
                int* dest_size = NULL_POINTER;

                allocate(&dest_count, PRIMITIVE_COUNT, INTEGER_VECTOR_ABSTRACTION, INTEGER_VECTOR_ABSTRACTION_COUNT);
                allocate(&dest_size, PRIMITIVE_COUNT, INTEGER_VECTOR_ABSTRACTION, INTEGER_VECTOR_ABSTRACTION_COUNT);
                *dest_count = 0;
                *dest_size  = 0;
                allocate(&dest, dest_size, CHARACTER_VECTOR_ABSTRACTION, CHARACTER_VECTOR_ABSTRACTION_COUNT);

                parse(&dest, dest_count, dest_size, &msg_refresh_part_1[0], &msg_part_1_count, CHARACTER_VECTOR_ABSTRACTION, CHARACTER_VECTOR_ABSTRACTION_COUNT);
                parse(&dest, dest_count, dest_size, *urlm, *urlmc, CHARACTER_VECTOR_ABSTRACTION, CHARACTER_VECTOR_ABSTRACTION_COUNT);
                parse(&dest, dest_count, dest_size, &msg_refresh_part_3[0], &msg_part_3_count, CHARACTER_VECTOR_ABSTRACTION, CHARACTER_VECTOR_ABSTRACTION_COUNT);

                // The temporary count, size.
                int tc = 0;
                int ts = 0;

                send_tcp_socket((void*) &cs, (void*) &tc, (void*) &ts, (void*) dest, (void*) dest_count);

                // Remove client socket number and main signal id from internal memory.
                remove_relation_clientsocketnumber_mainsignalid(p2, (void*) &i);

                // Close socket.
                close(*cs);

                // Destroy destination.
                deallocate(&dest, dest_size, CHARACTER_VECTOR_ABSTRACTION, CHARACTER_VECTOR_ABSTRACTION_COUNT);
                deallocate(&dest_count, PRIMITIVE_COUNT, INTEGER_VECTOR_ABSTRACTION, INTEGER_VECTOR_ABSTRACTION_COUNT);
                deallocate(&dest_size, PRIMITIVE_COUNT, INTEGER_VECTOR_ABSTRACTION, INTEGER_VECTOR_ABSTRACTION_COUNT);
            }
        }
    }
*/
}

/* SEND_SOURCE */
#endif
