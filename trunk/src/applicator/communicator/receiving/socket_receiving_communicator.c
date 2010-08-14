/*
 * Copyright (C) 1999-2010. Christian Heller.
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
 * @version $RCSfile: socket_receiving_communicator.c,v $ $Revision: 1.12 $ $Date: 2009-02-08 22:34:57 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef SOCKET_RECEIVING_COMMUNICATOR_SOURCE
#define SOCKET_RECEIVING_COMMUNICATOR_SOURCE

#ifdef GNU_LINUX_OPERATING_SYSTEM

#include "../../../constant/model/log/level_log_model.c"
#include "../../../constant/model/log/message_log_model.c"
#include "../../../logger/logger.c"
#include "../../../executor/communicator/receiver/stream_socket_receiver.c"
/*??
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <errno.h>
#include <pthread.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include "../../../constant/abstraction/cybol/text_cybol_abstraction.c"
#include "../../../constant/channel/cybol_channel.c"
#include "../../../constant/model/cybol/http_request_cybol_model.c"
#include "../../../constant/name/cybol/web_user_interface/tag_web_user_interface_cybol_name.c"
#include "../../../constant/model/memory/integer_memory_model.c"
#include "../../../constant/abstraction/memory/memory_abstraction.c"
#include "../../../constant/model/memory/pointer_memory_model.c"
#include "../../../executor/accessor/getter/compound_getter.c"
#include "../../../executor/accessor/getter/array_getter.c"
#include "../../../executor/accessor/getter/signal_memory_getter.c"
#include "../../../executor/comparator/array_equality_comparator.c"
#include "../../../executor/memoriser/allocator.c"
*/

/**
 * Receives message via socket.
 *
 * @param p0 the destination message model (Hand over as reference!)
 * @param p1 the destination message model count
 * @param p2 the destination message model size
 * @param p3 the destination message details (Hand over as reference!)
 * @param p4 the destination message details count
 * @param p5 the destination message details size
 * @param p6 the source communication partner-connected socket of this system
 * @param p7 the socket communication style model
 * @param p8 the socket communication style model count
 * @param p9 the language model
 * @param p10 the language model count
 * @param p11 the knowledge memory
 * @param p12 the knowledge memory count
 */
void communicate_receiving_socket(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7,
    void* p8, void* p9, void* p10, void* p11, void* p12) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Receive socket message.");

    fwprintf(stdout, L"TEST 1 l: %s \n", (wchar_t*) p9);
    fwprintf(stdout, L"TEST 1 lc: %i \n", *((int*) p10));

    // The encoded character array.
    // CAUTION! Its size has to be GREATER than zero, e.g. 1024!
    // Otherwise, there will be no place for the data to be received.
    void* e = *NULL_POINTER_MEMORY_MODEL;
    int ec = *NUMBER_0_INTEGER_MEMORY_MODEL;
    int es = *NUMBER_1024_INTEGER_MEMORY_MODEL;

    // Allocate encoded character array.
    allocate((void*) &e, (void*) &es, (void*) CHARACTER_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT);

    // Receive message from stream.
    receive_stream_socket((void*) &e, (void*) &ec, (void*) &es, p6);

    fwprintf(stdout, L"TEST receive socket e: %s \n", (char*) e);
    fwprintf(stdout, L"TEST receive socket ec: %i \n", ec);
    fwprintf(stdout, L"TEST receive socket es: %i \n", es);

    // The serialised wide character array.
    void* s = *NULL_POINTER_MEMORY_MODEL;
    int sc = *NUMBER_0_INTEGER_MEMORY_MODEL;
    int ss = *NUMBER_0_INTEGER_MEMORY_MODEL;

    // Allocate serialised wide character array.
    allocate((void*) &s, (void*) &ss, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT);

    // Decode encoded character array into serialised wide character array.
    decode_utf_8_unicode_character_vector((void*) &s, (void*) &sc, (void*) &ss, e, (void*) &ec);

    fwprintf(stdout, L"TEST receive socket s: %ls \n", (wchar_t*) s);
    fwprintf(stdout, L"TEST receive socket sc: %i \n", sc);
    fwprintf(stdout, L"TEST receive socket ss: %i \n", ss);

    // Deallocate encoded character array.
    deallocate((void*) &e, (void*) &es, (void*) CHARACTER_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT);

    // Deserialise serialised wide character array into destination knowledge model.
    // The http request's parameters are written into the destination compound model.
    decode(p0, p1, p2, p3, p4, p5, s, (void*) &sc, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, p9, p10);

    //?? TODO: The destination compound model content needs to be RESET every time since
    //?? otherwise, new commands are just added to the "action" part entry, for example.
    //?? Instead, all values should be replaced!

    fwprintf(stdout, L"TEST 2 l: %s \n", (wchar_t*) p9);
    fwprintf(stdout, L"TEST 2 lc: %i \n", *((int*) p10));

    // Deallocate serialised wide character array.
    deallocate((void*) &s, (void*) &ss, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT);

/*??
    // The action name, abstraction, model, details.
    void** an = NULL_POINTER_MEMORY_MODEL;
    void** anc = NULL_POINTER_MEMORY_MODEL;
    void** ans = NULL_POINTER_MEMORY_MODEL;
    void** aa = NULL_POINTER_MEMORY_MODEL;
    void** aac = NULL_POINTER_MEMORY_MODEL;
    void** aas = NULL_POINTER_MEMORY_MODEL;
    void** am = NULL_POINTER_MEMORY_MODEL;
    void** amc = NULL_POINTER_MEMORY_MODEL;
    void** ams = NULL_POINTER_MEMORY_MODEL;
    void** ad = NULL_POINTER_MEMORY_MODEL;
    void** adc = NULL_POINTER_MEMORY_MODEL;
    void** ads = NULL_POINTER_MEMORY_MODEL;
*/

/*??
    // Get action.
    // It is just one of many possibly parameters that were sensed as
    // http request and added to the compound model above.
    get_universal_compound_element_by_name(*m, p9,
        (void*) SENSE_MODEL_ACTION_NAME, (void*) SENSE_MODEL_ACTION_NAME_COUNT,
        (void*) &an, (void*) &anc, (void*) &ans,
        (void*) &aa, (void*) &aac, (void*) &aas,
        (void*) &am, (void*) &amc, (void*) &ams,
        (void*) &ad, (void*) &adc, (void*) &ads,
        p0, p1);

    fwprintf(stdout, L"TEST 3 bc: %i \n", *((int*) p29));
    fwprintf(stdout, L"TEST 3 bs: %i \n", *((int*) p30));

    if (*am != *NULL_POINTER_MEMORY_MODEL) {

        // The action parameter is NOT null, so it
        // will be used for generating a signal.

    fwprintf(stdout, L"TEST 4 am: %s \n", (wchar_t*) *am);
    fwprintf(stdout, L"TEST 4 amc: %i \n", **((int**) amc));

        // Receive socket signal.
        receive_socket_signal(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15, *am, *amc, p23, p26);

    } else {

        log_terminated_message((void*) WARNING_LEVEL_LOG_MODEL, (void*) L"Could not receive socket message. The action parameter is null.");
    }

    fwprintf(stdout, L"TEST 5 bc: %i \n", *((int*) p29));
    fwprintf(stdout, L"TEST 5 bs: %i \n", *((int*) p30));
*/

    /** The index parameter. */
    static wchar_t INDEX_PARAMETER_ARRAY[] = {L'i', L'n', L'd', L'e', L'x'};
    static wchar_t* INDEX_PARAMETER = INDEX_PARAMETER_ARRAY;
    static int* INDEX_PARAMETER_COUNT = NUMBER_5_INTEGER_MEMORY_MODEL_ARRAY;

    // The command name, abstraction, model, details.
    void** n = NULL_POINTER_MEMORY_MODEL;
    void** nc = NULL_POINTER_MEMORY_MODEL;
    void** ns = NULL_POINTER_MEMORY_MODEL;
    void** a = NULL_POINTER_MEMORY_MODEL;
    void** ac = NULL_POINTER_MEMORY_MODEL;
    void** as = NULL_POINTER_MEMORY_MODEL;
    void** m = NULL_POINTER_MEMORY_MODEL;
    void** mc = NULL_POINTER_MEMORY_MODEL;
    void** ms = NULL_POINTER_MEMORY_MODEL;
    void** d = NULL_POINTER_MEMORY_MODEL;
    void** dc = NULL_POINTER_MEMORY_MODEL;
    void** ds = NULL_POINTER_MEMORY_MODEL;

/*??
    if (p16 != *NULL_POINTER_MEMORY_MODEL) {

        // Get actual command belonging to the command name.
        // If the name is not known, the command parameter is left untouched.
        get_universal_compound_element_by_name(p14, p15,
            p16, p17,
            (void*) &n, (void*) &nc, (void*) &ns,
            (void*) &a, (void*) &ac, (void*) &as,
            (void*) &m, (void*) &mc, (void*) &ms,
            (void*) &d, (void*) &dc, (void*) &ds,
            p0, p1);

    } else {

        // Get default index command, since the given command is null.
        get_universal_compound_element_by_name(p14, p15,
            INDEX_PARAMETER, INDEX_PARAMETER_COUNT,
            (void*) &n, (void*) &nc, (void*) &ns,
            (void*) &a, (void*) &ac, (void*) &as,
            (void*) &m, (void*) &mc, (void*) &ms,
            (void*) &d, (void*) &dc, (void*) &ds,
            p0, p1);
    }
*/

/*??
    fwprintf(stdout, L"TEST: receive socket signal actual command n: %s \n", (wchar_t*) *n);
    fwprintf(stdout, L"TEST: receive socket signal actual command nc: %i \n", **((int**) nc));
    fwprintf(stdout, L"TEST: receive socket signal actual command a: %s \n", (wchar_t*) *a);
    fwprintf(stdout, L"TEST: receive socket signal actual command ac: %i \n", **((int**) ac));
    fwprintf(stdout, L"TEST: receive socket signal actual command m: %s \n", (wchar_t*) *m);
    fwprintf(stdout, L"TEST: receive socket signal actual command mc: %i \n", **((int**) mc));
    fwprintf(stdout, L"TEST: receive socket signal actual command d: %i \n", *d);
    fwprintf(stdout, L"TEST: receive socket signal actual command dc: %i \n", **((int**) dc));
*/

/*??
    // The communication partner-connected socket of this system
    // (the client socket to accept, receive data from and attach as parameter to the
    // cyboi signal generated later, so that this server may reply to the correct client)
    void** s = NULL_POINTER_MEMORY_MODEL;

    // Get integer number reference for client socket.
    //
    //?? TODO: Rename this function to a more neutral name later and
    //?? possibly move it away from "signal_memory_accessor.c" into another file.
    set_new_signal_identification((void*) &s, p18);

    fwprintf(stdout, L"TEST: receive socket signal p18: %i \n", *((int*) p18));
    fwprintf(stdout, L"TEST: receive socket signal sock: %i \n", **((int**) s));

    // Set signal into signal memory.
    set_signal(p3, p4, p5, a, ac, m, mc, d, dc, (void*) &NORMAL_SIGNAL_PRIORITY_MODEL, (void*) s);
*/

/*??
    // The url basename.
    wchar_t* url_basename = (wchar_t*) *NULL_POINTER_MEMORY_MODEL;
    int url_basename_count = *NUMBER_0_INTEGER_MEMORY_MODEL;
    // Create url basename.
    allocate_array((void*) &url_basename, (void*) &url_basename_count, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT);
    // Get url base name.
    receive_socket_url(msg, &msg_count, &url_basename, &url_basename_count);

    // The parameter.
    wchar_t* param = (wchar_t*) *NULL_POINTER_MEMORY_MODEL;
    int param_count = *NUMBER_0_INTEGER_MEMORY_MODEL;
    // Create paramater.
    allocate_array((void*) &param, (void*) &param_count, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT);
    // Get parameters.
    receive_socket_parameter(msg, &msg_count, &param, &param_count);

    // The firefox web browser makes a second request
    // to determine the favicon.
    char firefox_request[] = "favicon.ico";
    wchar_t* p_firefox_request = &firefox_request[*NUMBER_0_INTEGER_MEMORY_MODEL];
    int firefox_request_count = *NUMBER_11_INTEGER_MEMORY_MODEL;

    // The comparison result.
    int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

    compare_equal_arrays((void*) &r, (void*) url_basename, (void*) &url_basename_count, (void*) p_firefox_request, (void*) &firefox_request_count, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT);

    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

        // Close partner socket, since the request was just intended to retrieve the icon.
        close(*ps);

    } else {

        // query string handling
        set_signals_for_all_parameters((void*) param, (void*) &param_count, p0);

        //?? The OLD solution created a signal here from a cybol knowledge template.
        //?? This is NOW easier, since the commands already exist in the knowledge tree
        //?? and only have to be referenced from here.
    }
*/

    //?? TODO: Also store the communication partner-connected socket of this system in internal memory!
    //?? (It is the client socket to accept, receive data from and attach as parameter to the
    //?? cyboi signal generated later, so that this server may reply to the correct client.)
}

/* GNU_LINUX_OPERATING_SYSTEM */
#endif

/* SOCKET_RECEIVING_COMMUNICATOR_SOURCE */
#endif
