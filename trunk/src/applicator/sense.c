/*
 * $RCSfile: sense.c,v $
 *
 * Copyright (c) 1999-2008. Christian Heller and the CYBOP developers.
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
 * @version $Revision: 1.6 $ $Date: 2008-05-28 22:39:58 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef SENSE_SOURCE
#define SENSE_SOURCE

#include "../applicator/sense/sense_gnu_linux_console.c"
#include "../applicator/sense/sense_socket.c"
#include "../applicator/sense/sense_x_window_system.c"
#include "../globals/constants/cybol/cybol_abstraction_constants.c"
#include "../globals/constants/cybol/cybol_model_constants.c"
#include "../globals/constants/cybol/cybol_name_constants.c"
#include "../globals/constants/integer/integer_constants.c"
#include "../globals/constants/log/log_level_constants.c"
#include "../globals/constants/pointer/pointer_constants.c"
#include "../globals/logger/logger.c"
#include "../globals/variables/thread_identification_variables.c"
#include "../memoriser/accessor/compound_accessor.c"

/**
 * Senses message.
 *
 * @param p0 the internal memory
 * @param p1 the service thread
 * @param p2 the thread procedure
 */
void sense_message(void* p0, void* p1, void* p2) {

    if (p1 != *NULL_POINTER) {

        int* t = (int*) p1;

        log_terminated_message((void*) DEBUG_LOG_LEVEL, (void*) L"Sense message.");

        // Only create thread, if not existent.
        // CAUTION! The "pthread_t" type is an integer, so both can be compared.
        if (*t == *NUMBER_MINUS_1_INTEGER) {

            log_terminated_message((void*) DEBUG_LOG_LEVEL, (void*) L"Create sense message thread.");

            // Create thread.
            //
            // CAUTION! Do NOT allocate any resources within the thread procedure!
            // The reason is that this main process thread gets forked when executing
            // external programs. A "fork" duplicates ALL resources of the parent process,
            // including ALL resources of any threads running within the parent process.
            // However, since the created child process does not have those threads running,
            // their duplicated resources will never be deallocated, which eats up memory.
            // See source code file: applicator/run/run_execute.c
            //
            // Any dynamically allocated resources needed within the thread have to be:
            // - allocated at service startup
            // - added to the internal memory
            // - handed over to the thread procedure HERE
            // - deallocated at service shutdown
            //
            // The third parameter is the procedure to be called.
            pthread_create((pthread_t*) p1, *NULL_POINTER, p2, p0);
        }

    } else {

        log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) L"Could not sense message. The service thread is null.");
    }
}

/**
 * Senses an interrupt request happening on the given device channel.
 *
 * In order to sense interrupt requests of various devices, special mechanisms
 * for interrupt detection have to be started. To these mechanisms belong:
 * - gnu/linux console
 * - x window system
 * - socket
 *
 * All of them have their own internal signal/ action/ event/ interrupt waiting loops
 * which get activated here, running as parallel services in separate threads.
 * Whenever an event occurs in one of these threads, it gets transformed into a
 * cyboi-internal interrupt request by setting the corresponding flag.
 * The cyboi signal checker loop then senses the interrupt and receives the
 * corresponding message via the channel the interrupt belongs to.
 *
 * Expected parameters:
 * - channel (required): the channel via which to receive the message (gnu_linux_console, www, x_window_system etc.)
 * - handler (optional): the handler (usually a receive operation) that parses an input and filters out a command that the system is to react to
 * - language (required): the language (abstraction, type, structure) of the data received (http_request, xdt, boolean, character etc.)
 * - message (required): the source (knowledge template) from where to receive data
 * - meta message (optional): the source (knowledge template) from where to receive meta data (details)
 * - model (required): the compound model to be filled with the data received
 * - details (required): the compound details to be filled with the data received
 * - root (required): the knowledge model that will serve as the root
 * - style (optional, only if channel is www, cyboi or similar): the style of socket communication
 * - commands (optional, only if a user interface thread is to react to certain commands):
 *   the knowledge model containing the commands that the user interface should react to
 * - blocking (optional, only if channel is www, cyboi or similar): the flag indicating whether the receive process should be blocking
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
void sense(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8) {

    log_terminated_message((void*) INFORMATION_LOG_LEVEL, (void*) L"Sense interrupt request.");

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
    // The handler name, abstraction, model, details.
    void** hn = NULL_POINTER;
    void** hnc = NULL_POINTER;
    void** hns = NULL_POINTER;
    void** ha = NULL_POINTER;
    void** hac = NULL_POINTER;
    void** has = NULL_POINTER;
    void** hm = NULL_POINTER;
    void** hmc = NULL_POINTER;
    void** hms = NULL_POINTER;
    void** hd = NULL_POINTER;
    void** hdc = NULL_POINTER;
    void** hds = NULL_POINTER;
/*??
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
    // The meta message name, abstraction, model, details.
    void** men = NULL_POINTER;
    void** menc = NULL_POINTER;
    void** mens = NULL_POINTER;
    void** mea = NULL_POINTER;
    void** meac = NULL_POINTER;
    void** meas = NULL_POINTER;
    void** mem = NULL_POINTER;
    void** memc = NULL_POINTER;
    void** mems = NULL_POINTER;
    void** med = NULL_POINTER;
    void** medc = NULL_POINTER;
    void** meds = NULL_POINTER;
    // The model name, abstraction, model, details.
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
    // The root name, abstraction, model, details.
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
    // The socket communication style name, abstraction, model, details.
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
    // The commands name, abstraction, model, details.
    void** con = NULL_POINTER;
    void** conc = NULL_POINTER;
    void** cons = NULL_POINTER;
    void** coa = NULL_POINTER;
    void** coac = NULL_POINTER;
    void** coas = NULL_POINTER;
    void** com = NULL_POINTER;
    void** comc = NULL_POINTER;
    void** coms = NULL_POINTER;
    void** cod = NULL_POINTER;
    void** codc = NULL_POINTER;
    void** cods = NULL_POINTER;
    // The blocking name, abstraction, model, details.
    void** bn = NULL_POINTER;
    void** bnc = NULL_POINTER;
    void** bns = NULL_POINTER;
    void** ba = NULL_POINTER;
    void** bac = NULL_POINTER;
    void** bas = NULL_POINTER;
    void** bm = NULL_POINTER;
    void** bmc = NULL_POINTER;
    void** bms = NULL_POINTER;
    void** bd = NULL_POINTER;
    void** bdc = NULL_POINTER;
    void** bds = NULL_POINTER;
*/

    // Get channel.
    get_universal_compound_element_by_name(p0, p1,
        (void*) RECEIVE_CHANNEL_NAME, (void*) RECEIVE_CHANNEL_NAME_COUNT,
        (void*) &cn, (void*) &cnc, (void*) &cns,
        (void*) &ca, (void*) &cac, (void*) &cas,
        (void*) &cm, (void*) &cmc, (void*) &cms,
        (void*) &cd, (void*) &cdc, (void*) &cds,
        p3, p4);

    // Get handler.
    get_universal_compound_element_by_name(p0, p1,
        (void*) RECEIVE_HANDLER_NAME, (void*) RECEIVE_HANDLER_NAME_COUNT,
        (void*) &hn, (void*) &hnc, (void*) &hns,
        (void*) &ha, (void*) &hac, (void*) &has,
        (void*) &hm, (void*) &hmc, (void*) &hms,
        (void*) &hd, (void*) &hdc, (void*) &hds,
        p3, p4);

/*??
    // Get language.
    get_universal_compound_element_by_name(p0, p1,
        (void*) RECEIVE_LANGUAGE_NAME, (void*) RECEIVE_LANGUAGE_NAME_COUNT,
        (void*) &ln, (void*) &lnc, (void*) &lns,
        (void*) &la, (void*) &lac, (void*) &las,
        (void*) &lm, (void*) &lmc, (void*) &lms,
        (void*) &ld, (void*) &ldc, (void*) &lds,
        p3, p4);

    // Get message.
    get_universal_compound_element_by_name(p0, p1,
        (void*) RECEIVE_MESSAGE_NAME, (void*) RECEIVE_MESSAGE_NAME_COUNT,
        (void*) &mn, (void*) &mnc, (void*) &mns,
        (void*) &ma, (void*) &mac, (void*) &mas,
        (void*) &mm, (void*) &mmc, (void*) &mms,
        (void*) &md, (void*) &mdc, (void*) &mds,
        p3, p4);

    // Get meta message.
    get_universal_compound_element_by_name(p0, p1,
        (void*) RECEIVE_META_NAME, (void*) RECEIVE_META_NAME_COUNT,
        (void*) &men, (void*) &menc, (void*) &mens,
        (void*) &mea, (void*) &meac, (void*) &meas,
        (void*) &mem, (void*) &memc, (void*) &mems,
        (void*) &med, (void*) &medc, (void*) &meds,
        p3, p4);

    // Get model.
    get_universal_compound_element_by_name(p0, p1,
        (void*) RECEIVE_MODEL_NAME, (void*) RECEIVE_MODEL_NAME_COUNT,
        (void*) &mon, (void*) &monc, (void*) &mons,
        (void*) &moa, (void*) &moac, (void*) &moas,
        (void*) &mom, (void*) &momc, (void*) &moms,
        (void*) &mod, (void*) &modc, (void*) &mods,
        p3, p4);

    // Get root.
    get_universal_compound_element_by_name(p0, p1,
        (void*) RECEIVE_ROOT_NAME, (void*) RECEIVE_ROOT_NAME_COUNT,
        (void*) &rn, (void*) &rnc, (void*) &rns,
        (void*) &ra, (void*) &rac, (void*) &ras,
        (void*) &rm, (void*) &rmc, (void*) &rms,
        (void*) &rd, (void*) &rdc, (void*) &rds,
        p3, p4);

    // Get socket communication style.
    get_universal_compound_element_by_name(p0, p1,
        (void*) RECEIVE_STYLE_NAME, (void*) RECEIVE_STYLE_NAME_COUNT,
        (void*) &stn, (void*) &stnc, (void*) &stns,
        (void*) &sta, (void*) &stac, (void*) &stas,
        (void*) &stm, (void*) &stmc, (void*) &stms,
        (void*) &std, (void*) &stdc, (void*) &stds,
        p3, p4);

    // Get commands.
    get_universal_compound_element_by_name(p0, p1,
        (void*) RECEIVE_COMMANDS_NAME, (void*) RECEIVE_COMMANDS_NAME_COUNT,
        (void*) &con, (void*) &conc, (void*) &cons,
        (void*) &coa, (void*) &coac, (void*) &coas,
        (void*) &com, (void*) &comc, (void*) &coms,
        (void*) &cod, (void*) &codc, (void*) &cods,
        p3, p4);

    // Get blocking.
    get_universal_compound_element_by_name(p0, p1,
        (void*) RECEIVE_BLOCKING_NAME, (void*) RECEIVE_BLOCKING_NAME_COUNT,
        (void*) &bn, (void*) &bnc, (void*) &bns,
        (void*) &ba, (void*) &bac, (void*) &bas,
        (void*) &bm, (void*) &bmc, (void*) &bms,
        (void*) &bd, (void*) &bdc, (void*) &bds,
        p3, p4);
*/

    // The comparison result.
    int r = *NUMBER_0_INTEGER;
    // The internal memory index.
    int i = *NUMBER_0_INTEGER;

    if (r == *NUMBER_0_INTEGER) {

        compare_arrays((void*) *cm, (void*) *cmc, (void*) GNU_LINUX_CONSOLE_MODEL, (void*) GNU_LINUX_CONSOLE_MODEL_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY);

        if (r != *NUMBER_0_INTEGER) {

            // Set handler abstraction, model, details.
            set_element(p2, (void*) GNU_LINUX_CONSOLE_HANDLER_ABSTRACTION_INTERNAL, (void*) ha, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
            set_element(p2, (void*) GNU_LINUX_CONSOLE_HANDLER_ABSTRACTION_COUNT_INTERNAL, (void*) hac, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
            set_element(p2, (void*) GNU_LINUX_CONSOLE_HANDLER_MODEL_INTERNAL, (void*) hm, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
            set_element(p2, (void*) GNU_LINUX_CONSOLE_HANDLER_MODEL_COUNT_INTERNAL, (void*) hmc, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
            set_element(p2, (void*) GNU_LINUX_CONSOLE_HANDLER_DETAILS_INTERNAL, (void*) hd, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
            set_element(p2, (void*) GNU_LINUX_CONSOLE_HANDLER_DETAILS_COUNT_INTERNAL, (void*) hdc, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

            // Sense incoming message.
            sense_message(p2, (void*) GNU_LINUX_CONSOLE_THREAD, (void*) &sense_gnu_linux_console);
        }
    }

    if (r == *NUMBER_0_INTEGER) {

        compare_arrays((void*) *cm, (void*) *cmc, (void*) X_WINDOW_SYSTEM_MODEL, (void*) X_WINDOW_SYSTEM_MODEL_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY);

        if (r != *NUMBER_0_INTEGER) {

            // Set handler abstraction, model, details.
            set_element(p2, (void*) X_WINDOW_SYSTEM_HANDLER_ABSTRACTION_INTERNAL, (void*) ha, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
            set_element(p2, (void*) X_WINDOW_SYSTEM_HANDLER_ABSTRACTION_COUNT_INTERNAL, (void*) hac, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
            set_element(p2, (void*) X_WINDOW_SYSTEM_HANDLER_MODEL_INTERNAL, (void*) hm, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
            set_element(p2, (void*) X_WINDOW_SYSTEM_HANDLER_MODEL_COUNT_INTERNAL, (void*) hmc, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
            set_element(p2, (void*) X_WINDOW_SYSTEM_HANDLER_DETAILS_INTERNAL, (void*) hd, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
            set_element(p2, (void*) X_WINDOW_SYSTEM_HANDLER_DETAILS_COUNT_INTERNAL, (void*) hdc, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

            // Sense incoming message.
            sense_message(p2, (void*) X_WINDOW_SYSTEM_THREAD, (void*) &sense_x_window_system);
        }
    }

    if (r == *NUMBER_0_INTEGER) {

        compare_arrays((void*) *cm, (void*) *cmc, (void*) WWW_SERVICE_MODEL, (void*) WWW_SERVICE_MODEL_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY);

        if (r != *NUMBER_0_INTEGER) {

            // Set handler abstraction, model, details.
            i = *WWW_BASE_INTERNAL + *SOCKET_HANDLER_ABSTRACTION_INTERNAL;
            set_element(p2, (void*) &i, (void*) ha, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
            i = *WWW_BASE_INTERNAL + *SOCKET_HANDLER_ABSTRACTION_COUNT_INTERNAL;
            set_element(p2, (void*) &i, (void*) hac, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
            i = *WWW_BASE_INTERNAL + *SOCKET_HANDLER_MODEL_INTERNAL;
            set_element(p2, (void*) &i, (void*) hm, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
            i = *WWW_BASE_INTERNAL + *SOCKET_HANDLER_MODEL_COUNT_INTERNAL;
            set_element(p2, (void*) &i, (void*) hmc, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
            i = *WWW_BASE_INTERNAL + *SOCKET_HANDLER_DETAILS_INTERNAL;
            set_element(p2, (void*) &i, (void*) hd, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
            i = *WWW_BASE_INTERNAL + *SOCKET_HANDLER_DETAILS_COUNT_INTERNAL;
            set_element(p2, (void*) &i, (void*) hdc, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

            // Sense incoming message (http request or response).
            sense_message(p2, (void*) WWW_SERVICE_THREAD, (void*) &sense_www_socket);
        }
    }

    if (r == *NUMBER_0_INTEGER) {

        compare_arrays((void*) *cm, (void*) *cmc, (void*) CYBOI_SERVICE_MODEL, (void*) CYBOI_SERVICE_MODEL_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY);

        if (r != *NUMBER_0_INTEGER) {

            // Set handler abstraction, model, details.
            i = *CYBOI_BASE_INTERNAL + *SOCKET_HANDLER_ABSTRACTION_INTERNAL;
            set_element(p2, (void*) &i, (void*) ha, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
            i = *CYBOI_BASE_INTERNAL + *SOCKET_HANDLER_ABSTRACTION_COUNT_INTERNAL;
            set_element(p2, (void*) &i, (void*) hac, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
            i = *CYBOI_BASE_INTERNAL + *SOCKET_HANDLER_MODEL_INTERNAL;
            set_element(p2, (void*) &i, (void*) hm, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
            i = *CYBOI_BASE_INTERNAL + *SOCKET_HANDLER_MODEL_COUNT_INTERNAL;
            set_element(p2, (void*) &i, (void*) hmc, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
            i = *CYBOI_BASE_INTERNAL + *SOCKET_HANDLER_DETAILS_INTERNAL;
            set_element(p2, (void*) &i, (void*) hd, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
            i = *CYBOI_BASE_INTERNAL + *SOCKET_HANDLER_DETAILS_COUNT_INTERNAL;
            set_element(p2, (void*) &i, (void*) hdc, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

            // Sense incoming message (http request or response).
            sense_message(p2, (void*) CYBOI_SERVICE_THREAD, (void*) &sense_cyboi_socket);
        }
    }

    if (r == *NUMBER_0_INTEGER) {

        log_terminated_message((void*) WARNING_LOG_LEVEL, (void*) L"Could not sense interrupt request. The channel is unknown.");
    }
}

/* SENSE_SOURCE */
#endif
