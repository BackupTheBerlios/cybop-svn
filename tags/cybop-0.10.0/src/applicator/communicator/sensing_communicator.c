/*
 * Copyright (C) 1999-2011. Christian Heller.
 *
 * This file is part of the Cybernetics Oriented Interpreter (CYBOI).
 *
 * CYBOI is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * CYBOI is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with CYBOI.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Cybernetics Oriented Programming (CYBOP) <http://www.cybop.org>
 * Christian Heller <christian.heller@tuxtax.de>
 *
 * @version $RCSfile: sensing_communicator.c,v $ $Revision: 1.11 $ $Date: 2009-02-08 13:04:30 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef SENSING_COMMUNICATOR_SOURCE
#define SENSING_COMMUNICATOR_SOURCE

#include "../../applicator/communicator/sensing/gnu_linux_console_sensing_communicator.c"
#include "../../applicator/communicator/sensing/socket_sensing_communicator.c"
#include "../../applicator/communicator/sensing/x_window_system_sensing_communicator.c"
#include "../../constant/abstraction/cybol/text_cybol_abstraction.c"
#include "../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../constant/channel/cybol_channel.c"
#include "../../constant/model/log/level_log_model.c"
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../constant/name/cybol/operation/communication/sense_communication_operation_cybol_name.c"
#include "../../constant/name/memory/internal_memory_memory_name.c"
#include "../../executor/accessor/getter/compound_getter.c"
#include "../../logger/logger.c"
#include "../../variable/thread_identification.c"

//
// Forward declarations.
//
// The following functions HAVE TO BE declared here since
// otherwise, the compiler will report errors like:
//
// error: 'communicate_sensing_gnu_linux_console' undeclared
//
// The reason is (probably) that the functions are forwarded
// as reference (function pointer), for example:
//
// &communicate_sensing_gnu_linux_console
//
// The compiler does not seem to be able to recognise them
// as functions that way. Therefore, the following explicit
// declarations of the functions are necessary.
//

void communicate_sensing_gnu_linux_console(void* p0);
void communicate_sensing_cyboi_socket(void* p0);
void communicate_sensing_www_socket(void* p0);
void communicate_sensing_x_window_system(void* p0);

/**
 * Senses message.
 *
 * @param p0 the internal memory
 * @param p1 the service thread
 * @param p2 the thread procedure
 */
void communicate_sensing_message(void* p0, void* p1, void* p2) {

    if (p1 != *NULL_POINTER_MEMORY_MODEL) {

        int* t = (int*) p1;

        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Sense message.");

        // Only create thread, if not existent.
        // CAUTION! The "pthread_t" type is an integer, so both can be compared.
        if (*t == *NUMBER_MINUS_1_INTEGER_MEMORY_MODEL) {

            log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Create sense message thread.");

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
            pthread_create((pthread_t*) p1, *NULL_POINTER_MEMORY_MODEL, p2, p0);
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not sense message. The service thread is null.");
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
void communicate_sensing(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Sense interrupt request.");

    // The channel name, abstraction, model, details.
    void** cn = NULL_POINTER_MEMORY_MODEL;
    void** cnc = NULL_POINTER_MEMORY_MODEL;
    void** cns = NULL_POINTER_MEMORY_MODEL;
    void** ca = NULL_POINTER_MEMORY_MODEL;
    void** cac = NULL_POINTER_MEMORY_MODEL;
    void** cas = NULL_POINTER_MEMORY_MODEL;
    void** cm = NULL_POINTER_MEMORY_MODEL;
    void** cmc = NULL_POINTER_MEMORY_MODEL;
    void** cms = NULL_POINTER_MEMORY_MODEL;
    void** cd = NULL_POINTER_MEMORY_MODEL;
    void** cdc = NULL_POINTER_MEMORY_MODEL;
    void** cds = NULL_POINTER_MEMORY_MODEL;
    // The handler name, abstraction, model, details.
    void** hn = NULL_POINTER_MEMORY_MODEL;
    void** hnc = NULL_POINTER_MEMORY_MODEL;
    void** hns = NULL_POINTER_MEMORY_MODEL;
    void** ha = NULL_POINTER_MEMORY_MODEL;
    void** hac = NULL_POINTER_MEMORY_MODEL;
    void** has = NULL_POINTER_MEMORY_MODEL;
    void** hm = NULL_POINTER_MEMORY_MODEL;
    void** hmc = NULL_POINTER_MEMORY_MODEL;
    void** hms = NULL_POINTER_MEMORY_MODEL;
    void** hd = NULL_POINTER_MEMORY_MODEL;
    void** hdc = NULL_POINTER_MEMORY_MODEL;
    void** hds = NULL_POINTER_MEMORY_MODEL;
/*??
    // The language name, abstraction, model, details.
    void** ln = NULL_POINTER_MEMORY_MODEL;
    void** lnc = NULL_POINTER_MEMORY_MODEL;
    void** lns = NULL_POINTER_MEMORY_MODEL;
    void** la = NULL_POINTER_MEMORY_MODEL;
    void** lac = NULL_POINTER_MEMORY_MODEL;
    void** las = NULL_POINTER_MEMORY_MODEL;
    void** lm = NULL_POINTER_MEMORY_MODEL;
    void** lmc = NULL_POINTER_MEMORY_MODEL;
    void** lms = NULL_POINTER_MEMORY_MODEL;
    void** ld = NULL_POINTER_MEMORY_MODEL;
    void** ldc = NULL_POINTER_MEMORY_MODEL;
    void** lds = NULL_POINTER_MEMORY_MODEL;
    // The message name, abstraction, model, details.
    void** mn = NULL_POINTER_MEMORY_MODEL;
    void** mnc = NULL_POINTER_MEMORY_MODEL;
    void** mns = NULL_POINTER_MEMORY_MODEL;
    void** ma = NULL_POINTER_MEMORY_MODEL;
    void** mac = NULL_POINTER_MEMORY_MODEL;
    void** mas = NULL_POINTER_MEMORY_MODEL;
    void** mm = NULL_POINTER_MEMORY_MODEL;
    void** mmc = NULL_POINTER_MEMORY_MODEL;
    void** mms = NULL_POINTER_MEMORY_MODEL;
    void** md = NULL_POINTER_MEMORY_MODEL;
    void** mdc = NULL_POINTER_MEMORY_MODEL;
    void** mds = NULL_POINTER_MEMORY_MODEL;
    // The meta message name, abstraction, model, details.
    void** men = NULL_POINTER_MEMORY_MODEL;
    void** menc = NULL_POINTER_MEMORY_MODEL;
    void** mens = NULL_POINTER_MEMORY_MODEL;
    void** mea = NULL_POINTER_MEMORY_MODEL;
    void** meac = NULL_POINTER_MEMORY_MODEL;
    void** meas = NULL_POINTER_MEMORY_MODEL;
    void** mem = NULL_POINTER_MEMORY_MODEL;
    void** memc = NULL_POINTER_MEMORY_MODEL;
    void** mems = NULL_POINTER_MEMORY_MODEL;
    void** med = NULL_POINTER_MEMORY_MODEL;
    void** medc = NULL_POINTER_MEMORY_MODEL;
    void** meds = NULL_POINTER_MEMORY_MODEL;
    // The model name, abstraction, model, details.
    void** mon = NULL_POINTER_MEMORY_MODEL;
    void** monc = NULL_POINTER_MEMORY_MODEL;
    void** mons = NULL_POINTER_MEMORY_MODEL;
    void** moa = NULL_POINTER_MEMORY_MODEL;
    void** moac = NULL_POINTER_MEMORY_MODEL;
    void** moas = NULL_POINTER_MEMORY_MODEL;
    void** mom = NULL_POINTER_MEMORY_MODEL;
    void** momc = NULL_POINTER_MEMORY_MODEL;
    void** moms = NULL_POINTER_MEMORY_MODEL;
    void** mod = NULL_POINTER_MEMORY_MODEL;
    void** modc = NULL_POINTER_MEMORY_MODEL;
    void** mods = NULL_POINTER_MEMORY_MODEL;
    // The root name, abstraction, model, details.
    void** rn = NULL_POINTER_MEMORY_MODEL;
    void** rnc = NULL_POINTER_MEMORY_MODEL;
    void** rns = NULL_POINTER_MEMORY_MODEL;
    void** ra = NULL_POINTER_MEMORY_MODEL;
    void** rac = NULL_POINTER_MEMORY_MODEL;
    void** ras = NULL_POINTER_MEMORY_MODEL;
    void** rm = NULL_POINTER_MEMORY_MODEL;
    void** rmc = NULL_POINTER_MEMORY_MODEL;
    void** rms = NULL_POINTER_MEMORY_MODEL;
    void** rd = NULL_POINTER_MEMORY_MODEL;
    void** rdc = NULL_POINTER_MEMORY_MODEL;
    void** rds = NULL_POINTER_MEMORY_MODEL;
    // The socket communication style name, abstraction, model, details.
    void** stn = NULL_POINTER_MEMORY_MODEL;
    void** stnc = NULL_POINTER_MEMORY_MODEL;
    void** stns = NULL_POINTER_MEMORY_MODEL;
    void** sta = NULL_POINTER_MEMORY_MODEL;
    void** stac = NULL_POINTER_MEMORY_MODEL;
    void** stas = NULL_POINTER_MEMORY_MODEL;
    void** stm = NULL_POINTER_MEMORY_MODEL;
    void** stmc = NULL_POINTER_MEMORY_MODEL;
    void** stms = NULL_POINTER_MEMORY_MODEL;
    void** std = NULL_POINTER_MEMORY_MODEL;
    void** stdc = NULL_POINTER_MEMORY_MODEL;
    void** stds = NULL_POINTER_MEMORY_MODEL;
    // The commands name, abstraction, model, details.
    void** con = NULL_POINTER_MEMORY_MODEL;
    void** conc = NULL_POINTER_MEMORY_MODEL;
    void** cons = NULL_POINTER_MEMORY_MODEL;
    void** coa = NULL_POINTER_MEMORY_MODEL;
    void** coac = NULL_POINTER_MEMORY_MODEL;
    void** coas = NULL_POINTER_MEMORY_MODEL;
    void** com = NULL_POINTER_MEMORY_MODEL;
    void** comc = NULL_POINTER_MEMORY_MODEL;
    void** coms = NULL_POINTER_MEMORY_MODEL;
    void** cod = NULL_POINTER_MEMORY_MODEL;
    void** codc = NULL_POINTER_MEMORY_MODEL;
    void** cods = NULL_POINTER_MEMORY_MODEL;
    // The blocking name, abstraction, model, details.
    void** bn = NULL_POINTER_MEMORY_MODEL;
    void** bnc = NULL_POINTER_MEMORY_MODEL;
    void** bns = NULL_POINTER_MEMORY_MODEL;
    void** ba = NULL_POINTER_MEMORY_MODEL;
    void** bac = NULL_POINTER_MEMORY_MODEL;
    void** bas = NULL_POINTER_MEMORY_MODEL;
    void** bm = NULL_POINTER_MEMORY_MODEL;
    void** bmc = NULL_POINTER_MEMORY_MODEL;
    void** bms = NULL_POINTER_MEMORY_MODEL;
    void** bd = NULL_POINTER_MEMORY_MODEL;
    void** bdc = NULL_POINTER_MEMORY_MODEL;
    void** bds = NULL_POINTER_MEMORY_MODEL;
*/

    // Get channel.
    get_universal_compound_element_by_name(
        (void*) &cn, (void*) &cnc, (void*) &cns,
        (void*) &ca, (void*) &cac, (void*) &cas,
        (void*) &cm, (void*) &cmc, (void*) &cms,
        (void*) &cd, (void*) &cdc, (void*) &cds,
        p0, p1,
        (void*) CHANNEL_SENSE_COMMUNICATION_OPERATION_CYBOL_NAME, (void*) CHANNEL_SENSE_COMMUNICATION_OPERATION_CYBOL_NAME_COUNT,
        p3, p4);

    // Get handler.
    get_universal_compound_element_by_name(
        (void*) &hn, (void*) &hnc, (void*) &hns,
        (void*) &ha, (void*) &hac, (void*) &has,
        (void*) &hm, (void*) &hmc, (void*) &hms,
        (void*) &hd, (void*) &hdc, (void*) &hds,
        p0, p1,
        (void*) HANDLER_SENSE_COMMUNICATION_OPERATION_CYBOL_NAME, (void*) HANDLER_SENSE_COMMUNICATION_OPERATION_CYBOL_NAME_COUNT,
        p3, p4);

/*??
    // Get language.
    get_universal_compound_element_by_name(
        (void*) &ln, (void*) &lnc, (void*) &lns,
        (void*) &la, (void*) &lac, (void*) &las,
        (void*) &lm, (void*) &lmc, (void*) &lms,
        (void*) &ld, (void*) &ldc, (void*) &lds,
        p0, p1,
        (void*) RECEIVE_LANGUAGE_NAME, (void*) RECEIVE_LANGUAGE_NAME_COUNT,
        p3, p4);

    // Get message.
    get_universal_compound_element_by_name(
        (void*) &mn, (void*) &mnc, (void*) &mns,
        (void*) &ma, (void*) &mac, (void*) &mas,
        (void*) &mm, (void*) &mmc, (void*) &mms,
        (void*) &md, (void*) &mdc, (void*) &mds,
        p0, p1,
        (void*) RECEIVE_MESSAGE_NAME, (void*) RECEIVE_MESSAGE_NAME_COUNT,
        p3, p4);

    // Get meta message.
    get_universal_compound_element_by_name(
        (void*) &men, (void*) &menc, (void*) &mens,
        (void*) &mea, (void*) &meac, (void*) &meas,
        (void*) &mem, (void*) &memc, (void*) &mems,
        (void*) &med, (void*) &medc, (void*) &meds,
        p0, p1,
        (void*) RECEIVE_META_NAME, (void*) RECEIVE_META_NAME_COUNT,
        p3, p4);

    // Get model.
    get_universal_compound_element_by_name(
        (void*) &mon, (void*) &monc, (void*) &mons,
        (void*) &moa, (void*) &moac, (void*) &moas,
        (void*) &mom, (void*) &momc, (void*) &moms,
        (void*) &mod, (void*) &modc, (void*) &mods,
        p0, p1,
        (void*) RECEIVE_MODEL_NAME, (void*) RECEIVE_MODEL_NAME_COUNT,
        p3, p4);

    // Get root.
    get_universal_compound_element_by_name(
        (void*) &rn, (void*) &rnc, (void*) &rns,
        (void*) &ra, (void*) &rac, (void*) &ras,
        (void*) &rm, (void*) &rmc, (void*) &rms,
        (void*) &rd, (void*) &rdc, (void*) &rds,
        p0, p1,
        (void*) RECEIVE_ROOT_NAME, (void*) RECEIVE_ROOT_NAME_COUNT,
        p3, p4);

    // Get socket communication style.
    get_universal_compound_element_by_name(
        (void*) &stn, (void*) &stnc, (void*) &stns,
        (void*) &sta, (void*) &stac, (void*) &stas,
        (void*) &stm, (void*) &stmc, (void*) &stms,
        (void*) &std, (void*) &stdc, (void*) &stds,
        p0, p1,
        (void*) RECEIVE_STYLE_NAME, (void*) RECEIVE_STYLE_NAME_COUNT,
        p3, p4);

    // Get commands.
    get_universal_compound_element_by_name(
        (void*) &con, (void*) &conc, (void*) &cons,
        (void*) &coa, (void*) &coac, (void*) &coas,
        (void*) &com, (void*) &comc, (void*) &coms,
        (void*) &cod, (void*) &codc, (void*) &cods,
        p0, p1,
        (void*) RECEIVE_COMMANDS_NAME, (void*) RECEIVE_COMMANDS_NAME_COUNT,
        p3, p4);

    // Get blocking.
    get_universal_compound_element_by_name(
        (void*) &bn, (void*) &bnc, (void*) &bns,
        (void*) &ba, (void*) &bac, (void*) &bas,
        (void*) &bm, (void*) &bmc, (void*) &bms,
        (void*) &bd, (void*) &bdc, (void*) &bds,
        p0, p1,
        (void*) RECEIVE_BLOCKING_NAME, (void*) RECEIVE_BLOCKING_NAME_COUNT,
        p3, p4);
*/

    // The comparison result.
    int r = *NUMBER_0_INTEGER_MEMORY_MODEL;
    // The internal memory index.
    int i = *NUMBER_0_INTEGER_MEMORY_MODEL;

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_arrays((void*) &r, (void*) *cm, (void*) *cmc, (void*) GNU_LINUX_CONSOLE_CYBOL_CHANNEL, (void*) GNU_LINUX_CONSOLE_CYBOL_CHANNEL_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            // Set handler abstraction, model, details.
            replace_array(p2, (void*) ha, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) GNU_LINUX_CONSOLE_HANDLER_ABSTRACTION_INTERNAL_MEMORY_MEMORY_NAME, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
            replace_array(p2, (void*) hac, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) GNU_LINUX_CONSOLE_HANDLER_ABSTRACTION_COUNT_INTERNAL_MEMORY_MEMORY_NAME, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
            replace_array(p2, (void*) hm, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) GNU_LINUX_CONSOLE_HANDLER_MODEL_INTERNAL_MEMORY_MEMORY_NAME, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
            replace_array(p2, (void*) hmc, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) GNU_LINUX_CONSOLE_HANDLER_MODEL_COUNT_INTERNAL_MEMORY_MEMORY_NAME, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
            replace_array(p2, (void*) hd, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) GNU_LINUX_CONSOLE_HANDLER_DETAILS_INTERNAL_MEMORY_MEMORY_NAME, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
            replace_array(p2, (void*) hdc, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) GNU_LINUX_CONSOLE_HANDLER_DETAILS_COUNT_INTERNAL_MEMORY_MEMORY_NAME, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);

            // Sense incoming message.
            communicate_sensing_message(p2, (void*) GNU_LINUX_CONSOLE_THREAD, (void*) &communicate_sensing_gnu_linux_console);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_arrays((void*) &r, (void*) *cm, (void*) *cmc, (void*) X_WINDOW_SYSTEM_CYBOL_CHANNEL, (void*) X_WINDOW_SYSTEM_CYBOL_CHANNEL_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            // Set handler abstraction, model, details.
            replace_array(p2, (void*) ha, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) X_WINDOW_SYSTEM_HANDLER_ABSTRACTION_INTERNAL_MEMORY_MEMORY_NAME, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
            replace_array(p2, (void*) hac, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) X_WINDOW_SYSTEM_HANDLER_ABSTRACTION_COUNT_INTERNAL_MEMORY_MEMORY_NAME, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
            replace_array(p2, (void*) hm, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) X_WINDOW_SYSTEM_HANDLER_MODEL_INTERNAL_MEMORY_MEMORY_NAME, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
            replace_array(p2, (void*) hmc, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) X_WINDOW_SYSTEM_HANDLER_MODEL_COUNT_INTERNAL_MEMORY_MEMORY_NAME, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
            replace_array(p2, (void*) hd, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) X_WINDOW_SYSTEM_HANDLER_DETAILS_INTERNAL_MEMORY_MEMORY_NAME, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
            replace_array(p2, (void*) hdc, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) X_WINDOW_SYSTEM_HANDLER_DETAILS_COUNT_INTERNAL_MEMORY_MEMORY_NAME, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);

            // Sense incoming message.
            communicate_sensing_message(p2, (void*) X_WINDOW_SYSTEM_THREAD, (void*) &communicate_sensing_x_window_system);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_arrays((void*) &r, (void*) *cm, (void*) *cmc, (void*) WWW_CYBOL_CHANNEL, (void*) WWW_CYBOL_CHANNEL_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            // Set handler abstraction, model, details.
            i = *WWW_BASE_INTERNAL_MEMORY_MEMORY_NAME + *SOCKET_HANDLER_ABSTRACTION_INTERNAL_MEMORY_MEMORY_NAME;
            replace_array(p2, (void*) ha, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) &i, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
            i = *WWW_BASE_INTERNAL_MEMORY_MEMORY_NAME + *SOCKET_HANDLER_ABSTRACTION_COUNT_INTERNAL_MEMORY_MEMORY_NAME;
            replace_array(p2, (void*) hac, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) &i, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
            i = *WWW_BASE_INTERNAL_MEMORY_MEMORY_NAME + *SOCKET_HANDLER_MODEL_INTERNAL_MEMORY_MEMORY_NAME;
            replace_array(p2, (void*) hm, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) &i, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
            i = *WWW_BASE_INTERNAL_MEMORY_MEMORY_NAME + *SOCKET_HANDLER_MODEL_COUNT_INTERNAL_MEMORY_MEMORY_NAME;
            replace_array(p2, (void*) hmc, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) &i, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
            i = *WWW_BASE_INTERNAL_MEMORY_MEMORY_NAME + *SOCKET_HANDLER_DETAILS_INTERNAL_MEMORY_MEMORY_NAME;
            replace_array(p2, (void*) hd, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) &i, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
            i = *WWW_BASE_INTERNAL_MEMORY_MEMORY_NAME + *SOCKET_HANDLER_DETAILS_COUNT_INTERNAL_MEMORY_MEMORY_NAME;
            replace_array(p2, (void*) hdc, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) &i, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);

            // Sense incoming message (http request or response).
            communicate_sensing_message(p2, (void*) WWW_SERVICE_THREAD, (void*) &communicate_sensing_www_socket);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_arrays((void*) &r, (void*) *cm, (void*) *cmc, (void*) CYBOI_CYBOL_CHANNEL, (void*) CYBOI_CYBOL_CHANNEL_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

    fwprintf(stdout, L"TEST sense cyboi service hac: %i\n", *hac);
    fwprintf(stdout, L"TEST sense cyboi service ha: %i\n", *ha);

            // Set handler abstraction, model, details.
            i = *CYBOI_BASE_INTERNAL_MEMORY_MEMORY_NAME + *SOCKET_HANDLER_ABSTRACTION_INTERNAL_MEMORY_MEMORY_NAME;
            replace_array(p2, (void*) ha, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) &i, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
            i = *CYBOI_BASE_INTERNAL_MEMORY_MEMORY_NAME + *SOCKET_HANDLER_ABSTRACTION_COUNT_INTERNAL_MEMORY_MEMORY_NAME;
            replace_array(p2, (void*) hac, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) &i, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
            i = *CYBOI_BASE_INTERNAL_MEMORY_MEMORY_NAME + *SOCKET_HANDLER_MODEL_INTERNAL_MEMORY_MEMORY_NAME;
            replace_array(p2, (void*) hm, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) &i, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
            i = *CYBOI_BASE_INTERNAL_MEMORY_MEMORY_NAME + *SOCKET_HANDLER_MODEL_COUNT_INTERNAL_MEMORY_MEMORY_NAME;
            replace_array(p2, (void*) hmc, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) &i, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
            i = *CYBOI_BASE_INTERNAL_MEMORY_MEMORY_NAME + *SOCKET_HANDLER_DETAILS_INTERNAL_MEMORY_MEMORY_NAME;
            replace_array(p2, (void*) hd, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) &i, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
            i = *CYBOI_BASE_INTERNAL_MEMORY_MEMORY_NAME + *SOCKET_HANDLER_DETAILS_COUNT_INTERNAL_MEMORY_MEMORY_NAME;
            replace_array(p2, (void*) hdc, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) &i, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);

            // Sense incoming message (http request or response).
            communicate_sensing_message(p2, (void*) CYBOI_SERVICE_THREAD, (void*) &communicate_sensing_cyboi_socket);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        log_terminated_message((void*) WARNING_LEVEL_LOG_MODEL, (void*) L"Could not sense interrupt request. The channel is unknown.");
    }
}

/* SENSING_COMMUNICATOR_SOURCE */
#endif
