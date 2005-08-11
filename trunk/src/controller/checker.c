/*
 * $RCSfile: checker.c,v $
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
 * @version $Revision: 1.10 $ $Date: 2005-08-11 12:23:49 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 * @author Rolf Holzmueller <rolf.holzmueller@gmx.de>
 */

#ifndef CHECKER_SOURCE
#define CHECKER_SOURCE

#include "../controller/handler.c"
#include "../globals/constants/log_constants.c"
#include "../globals/variables/variables.c"
#include "../globals/logger/logger.c"
#include "../memoriser/accessor/signal_memory_accessor.c"

/**
 * Checks for signals.
 *
 * @param p0 the internal memory
 * @param p1 the knowledge memory
 * @param p2 the knowledge memory count
 * @param p3 the knowledge memory size
 * @param p4 the signal memory
 * @param p5 the signal memory count
 * @param p6 the signal memory size
 */
void check(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    log_message_debug("\n\n");
    log_message((void*) INFO_LOG_LEVEL, (void*) CHECK_FOR_SIGNALS_MESSAGE, (void*) CHECK_FOR_SIGNALS_MESSAGE_COUNT);

    // The shutdown flag.
    int f = 0;
    // The abstraction.
    void** a = &NULL_POINTER;
    void** ac = &NULL_POINTER;
    // The model (signal operation).
    void** m = &NULL_POINTER;
    void** mc = &NULL_POINTER;
    // The details (parameters).
    void** d = &NULL_POINTER;
    void** dc = &NULL_POINTER;
    // The priority.
    void** p = &NULL_POINTER;
    // The signal id.
    void** id = &NULL_POINTER;
    // The direct execution flag.
    int x = 0;
    // The highest priority index.
    int i = -1;
    // The comparison result.
    int r = 0;

    //?? TODO: Delete this testing stuff from Rolf Holzmueller.
    void** sf = &NULL_POINTER;
    void** bf = &NULL_POINTER;

    // Run endless loop checking signal memory for signals.
    while (1) {

        if (f == 1) {

            // Leave loop if shutdown flag was set.
            break;
        }

        // Get index of the top priority signal.
        get_highest_priority_index(p4, p5, (void*) &i);

        //?? Wait for web input, if no signal is in memory.
        //?? TODO: Use a thread for this!
        //?? Testing from Rolf Holzmueller.
        get(p0, (void*) TCP_SERVER_SOCKET_ACTIVE_INTERNAL, (void*) &sf, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        get(p0, (void*) TCP_SERVER_SOCKET_BLOCKING_INTERNAL, (void*) &bf, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

        if ((sf != NULL_POINTER) && (bf != NULL_POINTER)) {

            if ((*sf != NULL_POINTER) && (*bf != NULL_POINTER)) {

                if ((**((int**) sf) == 1) && (i < 0) && (**((int**) bf) == 1)) {

                    run_tcp_socket(p0);
                }
            }
        }

        if (i >= 0) {

            // Get signal.
            get_signal(p4, p5, (void*) &i,
                (void*) &a, (void*) &ac, (void*) &m, (void*) &mc,
                (void*) &d, (void*) &dc, (void*) &p, (void*) &id);

            //?? For testing only. TODO: Delete these lines later!
            fprintf(stderr, "check i: %i\n", i);
            fprintf(stderr, "check a: %s\n", (char*) *a);
            fprintf(stderr, "check ac: %i\n", *((int*) *ac));
            fprintf(stderr, "check m: %s\n", (char*) *m);
            fprintf(stderr, "check mc: %i\n", *((int*) *mc));
            //?? d and dc are NULL. DO NOT try to print their values here!
            fprintf(stderr, "check p: %i\n", *((int*) *p));
            fprintf(stderr, "check id: %i\n", *((int*) *id));
            fprintf(stderr, "check knowledge model: %s\n", "");
            test_knowledge_model(*k, *kc, 0);

            //
            // Handle signal.
            //

            handle(p0, p1, p2, p3, p4, p5, p6,
                (void*) &f, *a, *ac, *m, *mc, *d, *dc, *p, *id, &x);

            // Remove signal from signal memory.
            remove_signal(p4, p5, p6, (void*) &i);

            // CAUTION! Do NOT destroy the signal's abstraction or model here!
            // A signal only encapsulates an abstraction and a logic model,
            // which are stored in the knowledge tree.
            // That knowledge tree and all its models get created at
            // system startup and destroyed at system shutdown.

            // CAUTION! Do NOT destroy the signal priority!
            // It is a FIXED system constant.

            // Destroy signal id.
            // CAUTION! Do NOT hand over as reference!
            // The id was read from signal memory and is of type void**.
            // The expression (&*id) is the same like (id).
//??            fprintf(stderr, "TEST check pre integer destroy i: %i\n", i);
//??            deallocate((void*) id, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
//??            fprintf(stderr, "TEST check post integer destroy i: %i\n", i);

            // Reset abstraction.
            a = NULL_POINTER;
            ac = NULL_POINTER;
            // Reset model (signal operation).
            m = NULL_POINTER;
            mc = NULL_POINTER;
            // Reset details (parameters).
            d = NULL_POINTER;
            dc = NULL_POINTER;
            // Reset priority.
            p = NULL_POINTER;
            // Reset main signal id.
            id = NULL_POINTER;
            // Reset direct execution flag.
            x = 0;
            // Reset highest priority index.
            i = -1;
            // Reset comparison result.
            r = 0;

            //?? Reset. TODO: Delete this testing stuff from Rolf Holzmueller.
            sf = &NULL_POINTER;
            bf = &NULL_POINTER;
        }
    }
}

/* CHECKER_SOURCE */
#endif
