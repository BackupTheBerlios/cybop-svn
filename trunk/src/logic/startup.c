/*
 * $RCSfile: startup.c,v $
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
 * @version $Revision: 1.4 $ $Date: 2005-04-05 16:40:44 $ $Author: rholzmueller $
 * @author Christian Heller <christian.heller@tuxtax.de>
 * @description This module starts up a service.
 */

#ifndef STARTUP_SOURCE
#define STARTUP_SOURCE

#include "../array/array.c"
#include "../global/abstraction_constants.c"
#include "../global/channel_constants.c"
#include "../global/constant.c"
#include "../global/log_constants.c"
#include "../global/name_constants.c"
#include "../logger/logger.c"
#include "../logic/startup/startup_x_window_system.c"

/**
 * Starts up a service.
 *
 * Expected parameters:
 * - service: unix_socket, tcp_socket, x_window_system, ms_windows
 *
 * @param p0 the parameters
 * @param p1 the parameters count
 * @param p2 the knowledge
 * @param p3 the knowledge count
 * @param p4 the knowledge size
 * @param p5 the internals
 */
void startup_service(const void* p0, const void* p1,
    const void* p2, const void* p3, const void* p4, void* p5) {

    log_message_debug("Startup service.");

    // The service abstraction.
    void** sa = NULL_POINTER;
    void** sac = NULL_POINTER;
    void** sas = NULL_POINTER;
    // The service model.
    void** sm = NULL_POINTER;
    void** smc = NULL_POINTER;
    void** sms = NULL_POINTER;
    // The service details.
    void** sd = NULL_POINTER;
    void** sdc = NULL_POINTER;
    void** sds = NULL_POINTER;

    // Get parameters.
    get_compound_element_by_name(p0, p1,
        (void*) SERVICE_NAME, (void*) SERVICE_NAME_COUNT,
        (void*) &sa, (void*) &sac, (void*) &sas,
        (void*) &sm, (void*) &smc, (void*) &sms,
        (void*) &sd, (void*) &sdc, (void*) &sds);

    // The comparison result.
    int r = 0;

    // Get service.
    if (r != 1) {

        compare_arrays((void*) *sa, (void*) *sac, (void*) STRING_ABSTRACTION, (void*) STRING_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

            get_compound_element_by_name(p0, p1,
                (void*) SERVICE_NAME, (void*) SERVICE_NAME_COUNT,
                (void*) &sa, (void*) &sac, (void*) &sas,
                (void*) &sm, (void*) &smc, (void*) &sms,
                (void*) &sd, (void*) &sdc, (void*) &sds);
        }
    }

    if (r != 1) {

        compare_arrays((void*) *sa, (void*) *sac, (void*) KNOWLEDGE_ABSTRACTION, (void*) KNOWLEDGE_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

            get_compound_element_by_encapsulated_name(p0, p1,
                (void*) SERVICE_NAME, (void*) SERVICE_NAME_COUNT,
                (void*) &sa, (void*) &sac, (void*) &sas,
                (void*) &sm, (void*) &smc, (void*) &sms,
                (void*) &sd, (void*) &sdc, (void*) &sds,
                p2, p3);
        }
    }

    // Reset comparison result.
    r = 0;

    if (r != 1) {

        compare_arrays((void*) *sm, (void*) *smc, (void*) X_WINDOW_SYSTEM_ABSTRACTION, (void*) X_WINDOW_SYSTEM_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

            startup_x_window_system(p5, p2, p3, p4);
        }
    }
}


/**
 * Starts up a model.
 * The modell is defined with abstraction channel and model
 * this must be into the signal memeory
 *
 *
 * @param p0 the parameters
 * @param p1 the parameters count
 * @param p2 the knowledge
 * @param p3 the knowledge count
 * @param p4 the knowledge size
 * @param p5 the internals
 * @param p5 the signal id
 */
void startup_model(const void* p0, const void* p1,
    const void* p2, const void* p3, const void* p4, 
    void* p5, const void* p6) {

    log_message_debug("Startup model.");

    // The channel abstraction.
    void** ca = NULL_POINTER;
    void** cac = NULL_POINTER;
    void** cas = NULL_POINTER;
    // The channel model.
    void** cm = NULL_POINTER;
    void** cmc = NULL_POINTER;
    void** cms = NULL_POINTER;
    // The channel details.
    void** cd = NULL_POINTER;
    void** cdc = NULL_POINTER;
    void** cds = NULL_POINTER;

    // The abstraction abstraction.
    void** aa = NULL_POINTER;
    void** aac = NULL_POINTER;
    void** aas = NULL_POINTER;
    // The abstraction model.
    void** am = NULL_POINTER;
    void** amc = NULL_POINTER;
    void** ams = NULL_POINTER;
    // The abstraction details.
    void** ad = NULL_POINTER;
    void** adc = NULL_POINTER;
    void** ads = NULL_POINTER;

    // The model abstraction.
    void** ma = NULL_POINTER;
    void** mac = NULL_POINTER;
    void** mas = NULL_POINTER;
    // The model model.
    void** mm = NULL_POINTER;
    void** mmc = NULL_POINTER;
    void** mms = NULL_POINTER;
    // The model details.
    void** md = NULL_POINTER;
    void** mdc = NULL_POINTER;
    void** mds = NULL_POINTER;

    // Get channel name.
    get_real_compound_element_by_name(p0, p1,
        (void*) CHANNEL_NAME_ABSTRACTION, (void*) CHANNEL_NAME_ABSTRACTION_COUNT,
        (void*) &ca, (void*) &cac, (void*) &cas,
        (void*) &cm, (void*) &cmc, (void*) &cms,
        (void*) &cd, (void*) &cdc, (void*) &cds,
        p2, p3);

    // Get abstraction name.
    get_real_compound_element_by_name(p0, p1,
        (void*) ABSTRACTION_NAME_ABSTRACTION, (void*) ABSTRACTION_NAME_ABSTRACTION_COUNT,
        (void*) &aa, (void*) &aac, (void*) &aas,
        (void*) &am, (void*) &amc, (void*) &ams,
        (void*) &ad, (void*) &adc, (void*) &ads,
        p2, p3);

    // Get model name.
    get_real_compound_element_by_name(p0, p1,
        (void*) MODEL_NAME_ABSTRACTION, (void*) MODEL_NAME_ABSTRACTION_COUNT,
        (void*) &ma, (void*) &mac, (void*) &mas,
        (void*) &mm, (void*) &mmc, (void*) &mms,
        (void*) &md, (void*) &mdc, (void*) &mds,
        p2, p3);

    if ( // Check channel name.
           (ca != POINTER_NULL_POINTER)
        && (cac != POINTER_NULL_POINTER)
        && (cas != POINTER_NULL_POINTER)
        && (cm != POINTER_NULL_POINTER)
        && (cmc != POINTER_NULL_POINTER)
        && (cms != POINTER_NULL_POINTER)
        && (cd != POINTER_NULL_POINTER)
        && (cdc != POINTER_NULL_POINTER)
        && (cds != POINTER_NULL_POINTER)
        // Check abstraction name.
        && (aa != POINTER_NULL_POINTER)
        && (aac != POINTER_NULL_POINTER)
        && (aas != POINTER_NULL_POINTER)
        && (am != POINTER_NULL_POINTER)
        && (amc != POINTER_NULL_POINTER)
        && (ams != POINTER_NULL_POINTER)
        && (ad != POINTER_NULL_POINTER)
        && (adc != POINTER_NULL_POINTER)
        && (ads != POINTER_NULL_POINTER)
        // Check model name.
        && (ma != POINTER_NULL_POINTER)
        && (mac != POINTER_NULL_POINTER)
        && (mas != POINTER_NULL_POINTER)
        && (mm != POINTER_NULL_POINTER)
        && (mmc != POINTER_NULL_POINTER)
        && (mms != POINTER_NULL_POINTER)
        && (md != POINTER_NULL_POINTER)
        && (mdc != POINTER_NULL_POINTER)
        && (mds != POINTER_NULL_POINTER)
       )
    {
     
        // The signal abstraction.
        void* sa = NULL_POINTER;
        int* sac = INTEGER_NULL_POINTER;
        create_integer( &sac );
        *sac = 0;
        int* sas = INTEGER_NULL_POINTER;
        create_integer( &sas );
        *sas = 0;

        // The signal model.
        void* sm = NULL_POINTER;
        int* smc = INTEGER_NULL_POINTER;
        create_integer( &smc );
        *smc = 0;
        int* sms = INTEGER_NULL_POINTER;
        create_integer( &sms );
        *sms = 0;

        // The signal details.
        void* sd = NULL_POINTER;
        int* sdc = INTEGER_NULL_POINTER;
        create_integer( &sdc );
        *sdc = 0;
        int* sds = INTEGER_NULL_POINTER;
        create_integer( &sds );
        *sds = 0;

        // Create signal abstraction.
        create_model((void*) &sa, (void*) sac, (void*) sas,
            (void*) *am, (void*) *amc,
            (void*) STRING_ABSTRACTION, (void*) STRING_ABSTRACTION_COUNT,
            (void*) INLINE_CHANNEL, (void*) INLINE_CHANNEL_COUNT);

        // Create destination model.
        create_model((void*) &sm, (void*) smc, (void*) sms,
            (void*) *mm, (void*) *mmc,
            (void*) *am, (void*) *amc,
            (void*) INLINE_CHANNEL, (void*) INLINE_CHANNEL_COUNT);

        //
        // Signal.
        //

        log_message_debug("Set start signal.");

        // The signal memory.
        void** m = NULL_POINTER;
        void** mc = NULL_POINTER;
        void** ms = NULL_POINTER;

        // Get signal memory.
        get_array_elements(p5, (void*) SIGNAL_MEMORY_INTERNAL, (void*) &m, (void*) POINTER_ARRAY);
        get_array_elements(p5, (void*) SIGNAL_MEMORY_COUNT_INTERNAL, (void*) &mc, (void*) POINTER_ARRAY);
        get_array_elements(p5, (void*) SIGNAL_MEMORY_SIZE_INTERNAL, (void*) &ms, (void*) POINTER_ARRAY);

        // Set signal.
        set_signal(*m, *mc,* ms,
            (void*) sa, (void*) sac,
            (void*) sm, (void*) smc,
            (void*) sd, (void*) sdc,
            (void*) NORMAL_PRIORITY, p6);

    }

}

/* STARTUP_SOURCE */
#endif
