/*
 * Copyright (C) 1999-2008. Christian Heller.
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
 * @version $RCSfile: socket_receiving_communicator.c,v $ $Revision: 1.3 $ $Date: 2008-09-09 21:17:22 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef SOCKET_RECEIVER_SOURCE
#define SOCKET_RECEIVER_SOURCE

#ifdef GNU_LINUX_OPERATING_SYSTEM

#include "../../../constant/model/log/level_log_model.c"
#include "../../../constant/model/log/message_log_model.c"
#include "../../../logger/logger.c"
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
#include "../../../globals/constants/character/character_constants.c"
#include "../../../globals/constants/console/console_escape_code_constants.c"
#include "../../../globals/constants/cyboi/cyboi_signal_priority_constants.c"
#include "../../../constant/abstraction/cybol/text_cybol_abstraction.c"
#include "../../../constant/channel/cybol_channel.c"
#include "../../../globals/constants/cybol/cybol_model_constants.c"
#include "../../../globals/constants/cybol/cybol_name_constants.c"
#include "../../../constant/model/memory/integer_memory_model.c"
#include "../../../constant/abstraction/memory/memory_abstraction.c"
#include "../../../constant/model/memory/pointer_memory_model.c"
#include "../../../memoriser/accessor/compound_accessor.c"
#include "../../../memoriser/accessor/internal_memory_accessor.c"
#include "../../../memoriser/accessor/signal_memory_accessor.c"
#include "../../../memoriser/array.c"
#include "../../../memoriser/allocator.c"
*/

/**
 * Receives message via socket.
 *
 * @param p0 the model (Hand over as reference!)
 * @param p1 the model count
 * @param p2 the model size
 * @param p3 the details (Hand over as reference!)
 * @param p4 the details count
 * @param p5 the details size
 * @param p6 the commands model (Hand over as reference!)
 * @param p7 the commands model count
 * @param p8 the language model (Hand over as reference!)
 * @param p9 the language model count
 * @param p10 the communication style model (Hand over as reference!)
 * @param p11 the communication style model count
 * @param p12 the knowledge memory
 * @param p13 the knowledge memory count
 */
void receive_socket(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7,
    void* p8, void* p9, void* p10, void* p11, void* p12, void* p13) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Receive message via socket.");

    fwprintf(stderr, L"TEST 1 l: %s \n", (wchar_t*) p8);
    fwprintf(stderr, L"TEST 1 lc: %i \n", *((int*) p9));

    read_stream_socket(p0, p1, p2, p3);

    //?? TODO: The model content p8, p9, p10 needs to be RESET every time since
    //?? otherwise, new commands are just added to the "action" part entry, for example.
    //?? Instead, all values should be replaced!

    // Decode http request and write any parameters into the
    // compound model and details being handed over as parameters.
//??    decode(p0, p1, p2, p3, p4, p5, *b, p29, p12, p13, p8, p9);

    fwprintf(stderr, L"TEST 2 l: %s \n", (wchar_t*) p8);
    fwprintf(stderr, L"TEST 2 lc: %i \n", *((int*) p9));

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

    fwprintf(stderr, L"TEST 3 bc: %i \n", *((int*) p29));
    fwprintf(stderr, L"TEST 3 bs: %i \n", *((int*) p30));

    if (*am != *NULL_POINTER_MEMORY_MODEL) {

        // The action parameter is NOT null, so it
        // will be used for generating a signal.

    fwprintf(stderr, L"TEST 4 am: %s \n", (wchar_t*) *am);
    fwprintf(stderr, L"TEST 4 amc: %i \n", **((int**) amc));

        // Receive socket signal.
        receive_socket_signal(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15, *am, *amc, p23, p26);

    } else {

        log_terminated_message((void*) WARNING_LEVEL_LOG_MODEL, (void*) L"Could not receive socket message. The action parameter is null.");
    }

    fwprintf(stderr, L"TEST 5 bc: %i \n", *((int*) p29));
    fwprintf(stderr, L"TEST 5 bs: %i \n", *((int*) p30));
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
    fwprintf(stderr, L"TEST: receive socket signal actual command n: %s \n", (wchar_t*) *n);
    fwprintf(stderr, L"TEST: receive socket signal actual command nc: %i \n", **((int**) nc));
    fwprintf(stderr, L"TEST: receive socket signal actual command a: %s \n", (wchar_t*) *a);
    fwprintf(stderr, L"TEST: receive socket signal actual command ac: %i \n", **((int**) ac));
    fwprintf(stderr, L"TEST: receive socket signal actual command m: %s \n", (wchar_t*) *m);
    fwprintf(stderr, L"TEST: receive socket signal actual command mc: %i \n", **((int**) mc));
    fwprintf(stderr, L"TEST: receive socket signal actual command d: %i \n", *d);
    fwprintf(stderr, L"TEST: receive socket signal actual command dc: %i \n", **((int**) dc));
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

    fwprintf(stderr, L"TEST: receive socket signal p18: %i \n", *((int*) p18));
    fwprintf(stderr, L"TEST: receive socket signal sock: %i \n", **((int**) s));

    // Set signal into signal memory.
    set_signal(p3, p4, p5, a, ac, m, mc, d, dc, (void*) &NORMAL_CYBOI_SIGNAL_PRIORITY, (void*) s);
*/

/*??
    // The url basename.
    wchar_t* url_basename = (wchar_t*) *NULL_POINTER_MEMORY_MODEL;
    int url_basename_count = *NUMBER_0_INTEGER_MEMORY_MODEL;
    // Create url basename.
    allocate_array((void*) &url_basename, (void*) &url_basename_count, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
    // Get url base name.
    receive_socket_url(msg, &msg_count, &url_basename, &url_basename_count);

    // The parameter.
    wchar_t* param = (wchar_t*) *NULL_POINTER_MEMORY_MODEL;
    int param_count = *NUMBER_0_INTEGER_MEMORY_MODEL;
    // Create paramater.
    allocate_array((void*) &param, (void*) &param_count, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
    // Get parameters.
    receive_socket_parameter(msg, &msg_count, &param, &param_count);

    // The firefox web browser makes a second request
    // to determine the favicon.
    char firefox_request[] = "favicon.ico";
    wchar_t* p_firefox_request = &firefox_request[*NUMBER_0_INTEGER_MEMORY_MODEL];
    int firefox_request_count = *NUMBER_11_INTEGER_MEMORY_MODEL;

    // The comparison result.
    int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

    compare_arrays((void*) url_basename, (void*) &url_basename_count, (void*) p_firefox_request, (void*) &firefox_request_count, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

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

/* SOCKET_RECEIVER_SOURCE */
#endif
