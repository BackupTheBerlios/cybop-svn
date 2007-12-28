/*
 * $RCSfile: receive_socket.c,v $
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
 * @version $Revision: 1.46 $ $Date: 2007-12-28 19:25:54 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef RECEIVE_SOCKET_SOURCE
#define RECEIVE_SOCKET_SOURCE

#ifdef GNU_LINUX_OPERATING_SYSTEM

#include "../../globals/constants/log/log_level_constants.c"
#include "../../globals/constants/log/log_message_constants.c"
#include "../../globals/logger/logger.c"
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
#include "../../globals/constants/character/character_constants.c"
#include "../../globals/constants/console/console_escape_code_constants.c"
#include "../../globals/constants/cyboi/cyboi_signal_priority_constants.c"
#include "../../globals/constants/cybol/cybol_abstraction_constants.c"
#include "../../globals/constants/cybol/cybol_channel_constants.c"
#include "../../globals/constants/cybol/cybol_model_constants.c"
#include "../../globals/constants/cybol/cybol_name_constants.c"
#include "../../globals/constants/integer/integer_constants.c"
#include "../../globals/constants/memory_structure/memory_structure_constants.c"
#include "../../globals/constants/pointer/pointer_constants.c"
#include "../../memoriser/accessor/compound_accessor.c"
#include "../../memoriser/accessor/internal_memory_accessor.c"
#include "../../memoriser/accessor/signal_memory_accessor.c"
#include "../../memoriser/array.c"
#include "../../memoriser/allocator.c"
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

    log_terminated_message((void*) INFORMATION_LOG_LEVEL, (void*) "Receive message via socket.");

    fprintf(stderr, "TEST 1 l: %s \n", (char*) p8);
    fprintf(stderr, "TEST 1 lc: %i \n", *((int*) p9));

    read_stream_socket(p0, p1, p2, p3);

    //?? TODO: The model content p8, p9, p10 needs to be RESET every time since
    //?? otherwise, new commands are just added to the "action" part entry, for example.
    //?? Instead, all values should be replaced!

    // Decode http request and write any parameters into the
    // compound model and details being handed over as parameters.
    decode(p0, p1, p2, p3, p4, p5, *b, p29, p12, p13, p8, p9);

    fprintf(stderr, "TEST 2 l: %s \n", (char*) p8);
    fprintf(stderr, "TEST 2 lc: %i \n", *((int*) p9));

/*??
    // The action name, abstraction, model, details.
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
*/

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

    fprintf(stderr, "TEST 3 bc: %i \n", *((int*) p29));
    fprintf(stderr, "TEST 3 bs: %i \n", *((int*) p30));

    if (*am != *NULL_POINTER) {

        // The action parameter is NOT null, so it
        // will be used for generating a signal.

    fprintf(stderr, "TEST 4 am: %s \n", (char*) *am);
    fprintf(stderr, "TEST 4 amc: %i \n", **((int**) amc));

        // Receive socket signal.
        receive_socket_signal(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15, *am, *amc, p23, p26);

    } else {

        log_terminated_message((void*) WARNING_LOG_LEVEL, (void*) "Could not receive socket message. The action parameter is null.");
    }

    fprintf(stderr, "TEST 5 bc: %i \n", *((int*) p29));
    fprintf(stderr, "TEST 5 bs: %i \n", *((int*) p30));

    /** The index parameter. */
    static char INDEX_PARAMETER_ARRAY[] = {'i', 'n', 'd', 'e', 'x'};
    static char* INDEX_PARAMETER = INDEX_PARAMETER_ARRAY;
    static int* INDEX_PARAMETER_COUNT = NUMBER_5_INTEGER_ARRAY;

    // The command name, abstraction, model, details.
    void** n = NULL_POINTER;
    void** nc = NULL_POINTER;
    void** ns = NULL_POINTER;
    void** a = NULL_POINTER;
    void** ac = NULL_POINTER;
    void** as = NULL_POINTER;
    void** m = NULL_POINTER;
    void** mc = NULL_POINTER;
    void** ms = NULL_POINTER;
    void** d = NULL_POINTER;
    void** dc = NULL_POINTER;
    void** ds = NULL_POINTER;

    if (p16 != *NULL_POINTER) {

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

/*??
    fprintf(stderr, "TEST: receive socket signal actual command n: %s \n", (char*) *n);
    fprintf(stderr, "TEST: receive socket signal actual command nc: %i \n", **((int**) nc));
    fprintf(stderr, "TEST: receive socket signal actual command a: %s \n", (char*) *a);
    fprintf(stderr, "TEST: receive socket signal actual command ac: %i \n", **((int**) ac));
    fprintf(stderr, "TEST: receive socket signal actual command m: %s \n", (char*) *m);
    fprintf(stderr, "TEST: receive socket signal actual command mc: %i \n", **((int**) mc));
    fprintf(stderr, "TEST: receive socket signal actual command d: %i \n", *d);
    fprintf(stderr, "TEST: receive socket signal actual command dc: %i \n", **((int**) dc));
*/

/*??
    // The communication partner-connected socket of this system
    // (the client socket to accept, receive data from and attach as parameter to the
    // cyboi signal generated later, so that this server may reply to the correct client)
    void** s = NULL_POINTER;

    // Get integer number reference for client socket.
    //
    //?? TODO: Rename this function to a more neutral name later and
    //?? possibly move it away from "signal_memory_accessor.c" into another file.
    set_new_signal_identification((void*) &s, p18);

    fprintf(stderr, "TEST: receive socket signal p18: %i \n", *((int*) p18));
    fprintf(stderr, "TEST: receive socket signal sock: %i \n", **((int**) s));

    // Set signal into signal memory.
    set_signal(p3, p4, p5, a, ac, m, mc, d, dc, (void*) &NORMAL_CYBOI_SIGNAL_PRIORITY, (void*) s);
*/

/*??
    // The url basename.
    char* url_basename = (char*) *NULL_POINTER;
    int url_basename_count = *NUMBER_0_INTEGER;
    // Create url basename.
    allocate_array((void*) &url_basename, (void*) &url_basename_count, (void*) CHARACTER_ARRAY);
    // Get url base name.
    receive_socket_url(msg, &msg_count, &url_basename, &url_basename_count);

    // The parameter.
    char* param = (char*) *NULL_POINTER;
    int param_count = *NUMBER_0_INTEGER;
    // Create paramater.
    allocate_array((void*) &param, (void*) &param_count, (void*) CHARACTER_ARRAY);
    // Get parameters.
    receive_socket_parameter(msg, &msg_count, &param, &param_count);

    // The firefox web browser makes a second request
    // to determine the favicon.
    char firefox_request[] = "favicon.ico";
    char* p_firefox_request = &firefox_request[*NUMBER_0_INTEGER];
    int firefox_request_count = *NUMBER_11_INTEGER;

    // The comparison result.
    int r = *NUMBER_0_INTEGER;

    compare_arrays((void*) url_basename, (void*) &url_basename_count, (void*) p_firefox_request, (void*) &firefox_request_count, (void*) &r, (void*) CHARACTER_ARRAY);

    if (r != *NUMBER_0_INTEGER) {

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

/* RECEIVE_SOCKET_SOURCE */
#endif
