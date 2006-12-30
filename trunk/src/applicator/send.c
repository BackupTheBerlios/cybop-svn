/*
 * $RCSfile: send.c,v $
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
 * @version $Revision: 1.37 $ $Date: 2006-12-30 21:55:02 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 * @author Rolf Holzmueller <rolf.holzmueller@gmx.de>
 */

#ifndef SEND_SOURCE
#define SEND_SOURCE

#include <signal.h>
#include "../applicator/send/send_latex.c"
#include "../applicator/send/send_linux_console.c"
#include "../applicator/send/send_socket.c"
#include "../applicator/send/send_x_window_system.c"
#include "../globals/constants/abstraction_constants.c"
#include "../globals/constants/channel_constants.c"
#include "../globals/constants/model_constants.c"
#include "../globals/constants/name_constants.c"
#include "../globals/constants/structure_constants.c"
#include "../globals/logger/logger.c"
#include "../memoriser/accessor/compound_accessor.c"
#include "../memoriser/accessor/internal_memory_accessor.c"
#include "../memoriser/allocator.c"
#include "../memoriser/translator.c"

/**
 * Sends a message in a special language.
 *
 * CAUTION! Do NOT rename this procedure to "send",
 * as that name is already used by socket functionality.
 *
 * Expected parameters (names in parentheses after Lasswell):
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

    // The signal memory mutex.
    pthread_mutex_t** mt = (pthread_mutex_t**) &NULL_POINTER;
    // The interrupt request flag.
    sig_atomic_t** irq = (sig_atomic_t**) &NULL_POINTER;

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

    // The area abstraction.
    void** aa = &NULL_POINTER;
    void** aac = &NULL_POINTER;
    void** aas = &NULL_POINTER;
    // The area model.
    void** am = &NULL_POINTER;
    void** amc = &NULL_POINTER;
    void** ams = &NULL_POINTER;
    // The area details.
    void** ad = &NULL_POINTER;
    void** adc = &NULL_POINTER;
    void** ads = &NULL_POINTER;

    // The clean abstraction.
    void** cla = &NULL_POINTER;
    void** clac = &NULL_POINTER;
    void** clas = &NULL_POINTER;
    // The clean model.
    void** clm = &NULL_POINTER;
    void** clmc = &NULL_POINTER;
    void** clms = &NULL_POINTER;
    // The clean details.
    void** cld = &NULL_POINTER;
    void** cldc = &NULL_POINTER;
    void** clds = &NULL_POINTER;

    // Get signal memory mutex.
    get(p2, (void*) SIGNAL_MEMORY_MUTEX_INTERNAL, (void*) &mt, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    // Get interrupt request internal.
    get(p2, (void*) INTERRUPT_REQUEST_INTERNAL, (void*) &irq, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

    // Get channel.
    get_universal_compound_element_by_name(p0, p1,
        (void*) SEND_CHANNEL_NAME, (void*) SEND_CHANNEL_NAME_COUNT,
        (void*) &ca, (void*) &cac, (void*) &cas,
        (void*) &cm, (void*) &cmc, (void*) &cms,
        (void*) &cd, (void*) &cdc, (void*) &cds,
        p3, p4);

    // Get sender.
    get_universal_compound_element_by_name(p0, p1,
        (void*) SEND_SENDER_NAME, (void*) SEND_SENDER_NAME_COUNT,
        (void*) &sa, (void*) &sac, (void*) &sas,
        (void*) &sm, (void*) &smc, (void*) &sms,
        (void*) &sd, (void*) &sdc, (void*) &sds,
        p3, p4);

    // Get receiver.
    get_universal_compound_element_by_name(p0, p1,
        (void*) SEND_RECEIVER_NAME, (void*) SEND_RECEIVER_NAME_COUNT,
        (void*) &ra, (void*) &rac, (void*) &ras,
        (void*) &rm, (void*) &rmc, (void*) &rms,
        (void*) &rd, (void*) &rdc, (void*) &rds,
        p3, p4);

    // Get message.
    get_universal_compound_element_by_name(p0, p1,
        (void*) SEND_MESSAGE_NAME, (void*) SEND_MESSAGE_NAME_COUNT,
        (void*) &ma, (void*) &mac, (void*) &mas,
        (void*) &mm, (void*) &mmc, (void*) &mms,
        (void*) &md, (void*) &mdc, (void*) &mds,
        p3, p4);

    // Get area.
    get_universal_compound_element_by_name(p0, p1,
        (void*) SEND_AREA_NAME, (void*) SEND_AREA_NAME_COUNT,
        (void*) &aa, (void*) &aac, (void*) &aas,
        (void*) &am, (void*) &amc, (void*) &ams,
        (void*) &ad, (void*) &adc, (void*) &ads,
        p3, p4);

    // Get clean flag.
    get_universal_compound_element_by_name(p0, p1,
        (void*) SEND_CLEAN_NAME, (void*) SEND_CLEAN_NAME_COUNT,
        (void*) &cla, (void*) &clac, (void*) &clas,
        (void*) &clm, (void*) &clmc, (void*) &clms,
        (void*) &cld, (void*) &cldc, (void*) &clds,
        p3, p4);

    // The comparison result.
    int r = 0;

    if (r == 0) {

        compare_arrays((void*) *cm, (void*) *cmc, (void*) SIGNAL_MODEL, (void*) SIGNAL_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            // Lock signal memory mutex.
            pthread_mutex_lock(*mt);

            set_signal(p6, p7, p8, (void*) *ma, (void*) *mac, (void*) *mm, (void*) *mmc, (void*) *md, (void*) *mdc, (void*) NORMAL_PRIORITY, p9);

            // Set interrupt request flag, in order to notify the signal checker
            // that a new signal has been placed in the signal memory.
            **irq = *NUMBER_1_INTEGER;

            // Unlock signal memory mutex.
            pthread_mutex_unlock(*mt);
        }
    }

    if (r == 0) {

        compare_arrays((void*) *cm, (void*) *cmc, (void*) LINUX_CONSOLE_MODEL, (void*) LINUX_CONSOLE_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            send_linux_console(p2, *ma, *mac, *mm, *mmc, *md, *mdc, *am, *amc, *clm, *clmc, p3, p4);
        }
    }

    if (r == 0) {

        compare_arrays((void*) *cm, (void*) *cmc, (void*) X_WINDOW_SYSTEM_MODEL, (void*) X_WINDOW_SYSTEM_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            send_x_window_system(p2, *mm, *mmc, p3, p4);
        }
    }

    if (r == 0) {

        compare_arrays((void*) *cm, (void*) *cmc, (void*) WWW_SERVICE_MODEL, (void*) WWW_SERVICE_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            send_socket(p2, *ra, *rac, *rm, *rmc, *rd, *rdc, *ma, *mac, *mm, *mmc, *md, *mdc, (void*) WWW_BASE_INTERNAL, p3, p4);
        }
    }

    if (r == 0) {

        compare_arrays((void*) *cm, (void*) *cmc, (void*) LATEX_MODEL, (void*) LATEX_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            send_latex(p2, *mm, *mmc, p3, p4);
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

    log_message_debug("Refresh url.");

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
    get_universal_compound_element_by_name(p0, p1,
        (void*) SEND_URL_NAME, (void*) SEND_URL_NAME_COUNT,
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
