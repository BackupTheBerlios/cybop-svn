/*
 * $RCSfile: send.c,v $
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
 * @version $Revision: 1.53 $ $Date: 2007-07-23 23:47:57 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 * @author Rolf Holzmueller <rolf.holzmueller@gmx.de>
 */

#ifndef SEND_SOURCE
#define SEND_SOURCE

#include "../applicator/send/send_cyboi_system.c"
#include "../applicator/send/send_file_system.c"
#include "../applicator/send/send_latex.c"
#include "../applicator/send/send_gnu_linux_console.c"
#include "../applicator/send/send_shell.c"
#include "../applicator/send/send_socket.c"
#include "../applicator/send/send_x_window_system.c"
#include "../globals/constants/cybol/cybol_abstraction_constants.c"
#include "../globals/constants/cybol/cybol_channel_constants.c"
#include "../globals/constants/integer/integer_constants.c"
#include "../globals/constants/cybol/cybol_model_constants.c"
#include "../globals/constants/cybol/cybol_name_constants.c"
#include "../globals/constants/service_port_constants.c"
#include "../globals/constants/memory_structure/memory_structure_constants.c"
#include "../globals/constants/pointer/pointer_constants.c"
#include "../globals/logger/logger.c"
#include "../memoriser/accessor/compound_accessor.c"
#include "../memoriser/accessor/internal_memory_accessor.c"
#include "../memoriser/allocator.c"

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

/*??
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

        if (i >= *NUMBER_0_INTEGER) {

            // The client socket.
            int* cs = NULL_POINTER;

            get_client_socket_number_for_index(p2, (void*) &i, (void*) &cs);

            if (*cs >= *NUMBER_0_INTEGER) {

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
                *dest_count = *NUMBER_0_INTEGER;
                *dest_size  = *NUMBER_0_INTEGER;
                allocate(&dest, dest_size, CHARACTER_VECTOR_ABSTRACTION, CHARACTER_VECTOR_ABSTRACTION_COUNT);

                parse(&dest, dest_count, dest_size, &msg_refresh_part_1[*NUMBER_0_INTEGER], &msg_part_1_count, CHARACTER_VECTOR_ABSTRACTION, CHARACTER_VECTOR_ABSTRACTION_COUNT);
                parse(&dest, dest_count, dest_size, *urlm, *urlmc, CHARACTER_VECTOR_ABSTRACTION, CHARACTER_VECTOR_ABSTRACTION_COUNT);
                parse(&dest, dest_count, dest_size, &msg_refresh_part_3[*NUMBER_0_INTEGER], &msg_part_3_count, CHARACTER_VECTOR_ABSTRACTION, CHARACTER_VECTOR_ABSTRACTION_COUNT);

                // The temporary count, size.
                int tc = *NUMBER_0_INTEGER;
                int ts = *NUMBER_0_INTEGER;

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

/**
 * Sends a message in a special language.
 *
 * CAUTION! Do NOT rename this procedure to "send",
 * as that name is already used by socket functionality.
 *
 * Expected parameters (names in parentheses after Lasswell):
 * - channel (channel): gnu_linux_console, tcp_socket, unix_socket, x_window_system
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

    // The channel name, abstraction, model, details.
    void** cn = NULL_POINTER;
    void** cnc = NULL_POINTER;
    void** cns = NULL_POINTER;
    void** ca = NULL_POINTER;
    void** cac = NULL_POINTER;
    void** cas = NULL_POINTER;
    void** cm = NULL_POINTER;
    void** cmc = NULL_POINTER;
    void** cms = NULL_POINTER;
    void** cd = NULL_POINTER;
    void** cdc = NULL_POINTER;
    void** cds = NULL_POINTER;
    // The language name, abstraction, model, details.
    void** ln = NULL_POINTER;
    void** lnc = NULL_POINTER;
    void** lns = NULL_POINTER;
    void** la = NULL_POINTER;
    void** lac = NULL_POINTER;
    void** las = NULL_POINTER;
    void** lm = NULL_POINTER;
    void** lmc = NULL_POINTER;
    void** lms = NULL_POINTER;
    void** ld = NULL_POINTER;
    void** ldc = NULL_POINTER;
    void** lds = NULL_POINTER;
    // The communication mode name, abstraction, model, details.
    void** mon = NULL_POINTER;
    void** monc = NULL_POINTER;
    void** mons = NULL_POINTER;
    void** moa = NULL_POINTER;
    void** moac = NULL_POINTER;
    void** moas = NULL_POINTER;
    void** mom = NULL_POINTER;
    void** momc = NULL_POINTER;
    void** moms = NULL_POINTER;
    void** mod = NULL_POINTER;
    void** modc = NULL_POINTER;
    void** mods = NULL_POINTER;
    // The socket namespace name, abstraction, model, details.
    void** nn = NULL_POINTER;
    void** nnc = NULL_POINTER;
    void** nns = NULL_POINTER;
    void** na = NULL_POINTER;
    void** nac = NULL_POINTER;
    void** nas = NULL_POINTER;
    void** nm = NULL_POINTER;
    void** nmc = NULL_POINTER;
    void** nms = NULL_POINTER;
    void** nd = NULL_POINTER;
    void** ndc = NULL_POINTER;
    void** nds = NULL_POINTER;
    // The communication style name, abstraction, model, details.
    void** stn = NULL_POINTER;
    void** stnc = NULL_POINTER;
    void** stns = NULL_POINTER;
    void** sta = NULL_POINTER;
    void** stac = NULL_POINTER;
    void** stas = NULL_POINTER;
    void** stm = NULL_POINTER;
    void** stmc = NULL_POINTER;
    void** stms = NULL_POINTER;
    void** std = NULL_POINTER;
    void** stdc = NULL_POINTER;
    void** stds = NULL_POINTER;
    // The sender name, abstraction, model, details.
    void** sn = NULL_POINTER;
    void** snc = NULL_POINTER;
    void** sns = NULL_POINTER;
    void** sa = NULL_POINTER;
    void** sac = NULL_POINTER;
    void** sas = NULL_POINTER;
    void** sm = NULL_POINTER;
    void** smc = NULL_POINTER;
    void** sms = NULL_POINTER;
    void** sd = NULL_POINTER;
    void** sdc = NULL_POINTER;
    void** sds = NULL_POINTER;
    // The receiver name, abstraction, model, details.
    void** rn = NULL_POINTER;
    void** rnc = NULL_POINTER;
    void** rns = NULL_POINTER;
    void** ra = NULL_POINTER;
    void** rac = NULL_POINTER;
    void** ras = NULL_POINTER;
    void** rm = NULL_POINTER;
    void** rmc = NULL_POINTER;
    void** rms = NULL_POINTER;
    void** rd = NULL_POINTER;
    void** rdc = NULL_POINTER;
    void** rds = NULL_POINTER;
    // The message name, abstraction, model, details.
    void** mn = NULL_POINTER;
    void** mnc = NULL_POINTER;
    void** mns = NULL_POINTER;
    void** ma = NULL_POINTER;
    void** mac = NULL_POINTER;
    void** mas = NULL_POINTER;
    void** mm = NULL_POINTER;
    void** mmc = NULL_POINTER;
    void** mms = NULL_POINTER;
    void** md = NULL_POINTER;
    void** mdc = NULL_POINTER;
    void** mds = NULL_POINTER;
    // The area name, abstraction, model, details.
    void** an = NULL_POINTER;
    void** anc = NULL_POINTER;
    void** ans = NULL_POINTER;
    void** aa = NULL_POINTER;
    void** aac = NULL_POINTER;
    void** aas = NULL_POINTER;
    void** am = NULL_POINTER;
    void** amc = NULL_POINTER;
    void** ams = NULL_POINTER;
    void** ad = NULL_POINTER;
    void** adc = NULL_POINTER;
    void** ads = NULL_POINTER;
    // The clean name, abstraction, model, details.
    void** cln = NULL_POINTER;
    void** clnc = NULL_POINTER;
    void** clns = NULL_POINTER;
    void** cla = NULL_POINTER;
    void** clac = NULL_POINTER;
    void** clas = NULL_POINTER;
    void** clm = NULL_POINTER;
    void** clmc = NULL_POINTER;
    void** clms = NULL_POINTER;
    void** cld = NULL_POINTER;
    void** cldc = NULL_POINTER;
    void** clds = NULL_POINTER;
    // The new line name, abstraction, model, details.
    void** nln = NULL_POINTER;
    void** nlnc = NULL_POINTER;
    void** nlns = NULL_POINTER;
    void** nla = NULL_POINTER;
    void** nlac = NULL_POINTER;
    void** nlas = NULL_POINTER;
    void** nlm = NULL_POINTER;
    void** nlmc = NULL_POINTER;
    void** nlms = NULL_POINTER;
    void** nld = NULL_POINTER;
    void** nldc = NULL_POINTER;
    void** nlds = NULL_POINTER;

    // Get channel.
    get_universal_compound_element_by_name(p0, p1,
        (void*) SEND_CHANNEL_NAME, (void*) SEND_CHANNEL_NAME_COUNT,
        (void*) &cn, (void*) &cnc, (void*) &cns,
        (void*) &ca, (void*) &cac, (void*) &cas,
        (void*) &cm, (void*) &cmc, (void*) &cms,
        (void*) &cd, (void*) &cdc, (void*) &cds,
        p3, p4);

    // Get language.
    get_universal_compound_element_by_name(p0, p1,
        (void*) SEND_LANGUAGE_NAME, (void*) SEND_LANGUAGE_NAME_COUNT,
        (void*) &ln, (void*) &lnc, (void*) &lns,
        (void*) &la, (void*) &lac, (void*) &las,
        (void*) &lm, (void*) &lmc, (void*) &lms,
        (void*) &ld, (void*) &ldc, (void*) &lds,
        p3, p4);

    // Get communication mode.
    get_universal_compound_element_by_name(p0, p1,
        (void*) SEND_COMMUNICATION_MODE_NAME, (void*) SEND_COMMUNICATION_MODE_NAME_COUNT,
        (void*) &mon, (void*) &monc, (void*) &mons,
        (void*) &moa, (void*) &moac, (void*) &moas,
        (void*) &mom, (void*) &momc, (void*) &moms,
        (void*) &mod, (void*) &modc, (void*) &mods,
        p3, p4);

    // Get socket namespace.
    get_universal_compound_element_by_name(p0, p1,
        (void*) SEND_NAMESPACE_NAME, (void*) SEND_NAMESPACE_NAME_COUNT,
        (void*) &nn, (void*) &nnc, (void*) &nns,
        (void*) &na, (void*) &nac, (void*) &nas,
        (void*) &nm, (void*) &nmc, (void*) &nms,
        (void*) &nd, (void*) &ndc, (void*) &nds,
        p3, p4);

    // Get communication style.
    get_universal_compound_element_by_name(p0, p1,
        (void*) SEND_STYLE_NAME, (void*) SEND_STYLE_NAME_COUNT,
        (void*) &stn, (void*) &stnc, (void*) &stns,
        (void*) &sta, (void*) &stac, (void*) &stas,
        (void*) &stm, (void*) &stmc, (void*) &stms,
        (void*) &std, (void*) &stdc, (void*) &stds,
        p3, p4);

    // Get sender.
    get_universal_compound_element_by_name(p0, p1,
        (void*) SEND_SENDER_NAME, (void*) SEND_SENDER_NAME_COUNT,
        (void*) &sn, (void*) &snc, (void*) &sns,
        (void*) &sa, (void*) &sac, (void*) &sas,
        (void*) &sm, (void*) &smc, (void*) &sms,
        (void*) &sd, (void*) &sdc, (void*) &sds,
        p3, p4);

    // Get receiver.
    get_universal_compound_element_by_name(p0, p1,
        (void*) SEND_RECEIVER_NAME, (void*) SEND_RECEIVER_NAME_COUNT,
        (void*) &rn, (void*) &rnc, (void*) &rns,
        (void*) &ra, (void*) &rac, (void*) &ras,
        (void*) &rm, (void*) &rmc, (void*) &rms,
        (void*) &rd, (void*) &rdc, (void*) &rds,
        p3, p4);

    // Get message.
    get_universal_compound_element_by_name(p0, p1,
        (void*) SEND_MESSAGE_NAME, (void*) SEND_MESSAGE_NAME_COUNT,
        (void*) &mn, (void*) &mnc, (void*) &mns,
        (void*) &ma, (void*) &mac, (void*) &mas,
        (void*) &mm, (void*) &mmc, (void*) &mms,
        (void*) &md, (void*) &mdc, (void*) &mds,
        p3, p4);

    // Get area.
    get_universal_compound_element_by_name(p0, p1,
        (void*) SEND_AREA_NAME, (void*) SEND_AREA_NAME_COUNT,
        (void*) &an, (void*) &anc, (void*) &ans,
        (void*) &aa, (void*) &aac, (void*) &aas,
        (void*) &am, (void*) &amc, (void*) &ams,
        (void*) &ad, (void*) &adc, (void*) &ads,
        p3, p4);

    // Get clean flag.
    get_universal_compound_element_by_name(p0, p1,
        (void*) SEND_CLEAN_NAME, (void*) SEND_CLEAN_NAME_COUNT,
        (void*) &cln, (void*) &clnc, (void*) &clns,
        (void*) &cla, (void*) &clac, (void*) &clas,
        (void*) &clm, (void*) &clmc, (void*) &clms,
        (void*) &cld, (void*) &cldc, (void*) &clds,
        p3, p4);

    // Get new line flag.
    get_universal_compound_element_by_name(p0, p1,
        (void*) SEND_NEW_LINE_NAME, (void*) SEND_NEW_LINE_NAME_COUNT,
        (void*) &nln, (void*) &nlnc, (void*) &nlns,
        (void*) &nla, (void*) &nlac, (void*) &nlas,
        (void*) &nlm, (void*) &nlmc, (void*) &nlms,
        (void*) &nld, (void*) &nldc, (void*) &nlds,
        p3, p4);

    // The comparison result.
    int r = *NUMBER_0_INTEGER;

    if (r == *NUMBER_0_INTEGER) {

        compare_arrays((void*) *cm, (void*) *cmc, (void*) SIGNAL_MODEL, (void*) SIGNAL_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != *NUMBER_0_INTEGER) {

            send_cyboi_system(p2, p6, p7, p8, *ma, *mac, *mm, *mmc, *md, *mdc, (void*) NORMAL_PRIORITY, p9);
        }
    }

    if (r == *NUMBER_0_INTEGER) {

        compare_arrays((void*) *cm, (void*) *cmc, (void*) FILE_SYSTEM_MODEL, (void*) FILE_SYSTEM_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != *NUMBER_0_INTEGER) {

            send_file_system(p2, *mn, *mnc, *ma, *mac, *mm, *mmc, *md, *mdc, p3, p4, *lm, *lmc, *clm, *clmc, *rm, *rmc);
        }
    }

    if (r == *NUMBER_0_INTEGER) {

        compare_arrays((void*) *cm, (void*) *cmc, (void*) SHELL_MODEL, (void*) SHELL_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != *NUMBER_0_INTEGER) {

            send_shell(p2, *ma, *mac, *mm, *mmc, *md, *mdc, p3, p4, *lm, *lmc, *clm, *clmc, *nlm, *nlmc);
        }
    }

    if (r == *NUMBER_0_INTEGER) {

        compare_arrays((void*) *cm, (void*) *cmc, (void*) GNU_LINUX_CONSOLE_MODEL, (void*) GNU_LINUX_CONSOLE_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != *NUMBER_0_INTEGER) {

            send_gnu_linux_console(p2, *ma, *mac, *mm, *mmc, *md, *mdc, *am, *amc, *clm, *clmc, p3, p4);
        }
    }

    if (r == *NUMBER_0_INTEGER) {

        compare_arrays((void*) *cm, (void*) *cmc, (void*) X_WINDOW_SYSTEM_MODEL, (void*) X_WINDOW_SYSTEM_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != *NUMBER_0_INTEGER) {

            send_x_window_system(p2, *mm, *mmc, p3, p4);
        }
    }

    if (r == *NUMBER_0_INTEGER) {

        compare_arrays((void*) *cm, (void*) *cmc, (void*) WWW_SERVICE_MODEL, (void*) WWW_SERVICE_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != *NUMBER_0_INTEGER) {

            send_socket(p2, (void*) WWW_BASE_INTERNAL, *rm, *rmc, (void*) WWW_PORT, *nm, *nmc, *stm, *stmc, *mom, *momc, *ma, *mac, *mm, *mmc, *md, *mdc, p3, p4);
        }
    }

    if (r == *NUMBER_0_INTEGER) {

        compare_arrays((void*) *cm, (void*) *cmc, (void*) CYBOI_SERVICE_MODEL, (void*) CYBOI_SERVICE_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != *NUMBER_0_INTEGER) {

            send_socket(p2, (void*) CYBOI_BASE_INTERNAL, *rm, *rmc, (void*) CYBOI_PORT, *nm, *nmc, *stm, *stmc, *mom, *momc, *ma, *mac, *mm, *mmc, *md, *mdc, p3, p4);
        }
    }

    if (r == *NUMBER_0_INTEGER) {

        compare_arrays((void*) *cm, (void*) *cmc, (void*) LATEX_MODEL, (void*) LATEX_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != *NUMBER_0_INTEGER) {

            send_latex(p2, *mm, *mmc, p3, p4);
        }
    }
}

/* SEND_SOURCE */
#endif
