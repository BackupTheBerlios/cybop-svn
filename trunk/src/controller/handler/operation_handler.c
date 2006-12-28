/*
 * $RCSfile: operation_handler.c,v $
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
 * @version $Revision: 1.25 $ $Date: 2006-12-28 01:10:48 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 * @author Rolf Holzmueller <rolf.holzmueller@gmx.de>
 */

#ifndef OPERATION_HANDLER_SOURCE
#define OPERATION_HANDLER_SOURCE

#include "../../applicator/add.c"
#include "../../applicator/branch.c"
#include "../../applicator/build.c"
#include "../../applicator/compare.c"
#include "../../applicator/copy.c"
#include "../../applicator/count.c"
#include "../../applicator/create.c"
#include "../../applicator/destroy.c"
#include "../../applicator/interrupt.c"
#include "../../applicator/loop.c"
#include "../../applicator/receive.c"
#include "../../applicator/run.c"
#include "../../applicator/send.c"
#include "../../applicator/shutdown.c"
#include "../../applicator/startup.c"
#include "../../globals/constants/abstraction_constants.c"
#include "../../globals/constants/log_constants.c"
#include "../../globals/constants/model_constants.c"
#include "../../globals/logger/logger.c"
#include "../../memoriser/array.c"
//?? TEST only
#include "../../tester/tester.c"

/**
 * Handles the operation signal.
 *
 * @param p0 the internal memory
 * @param p1 the knowledge memory
 * @param p2 the knowledge memory count
 * @param p3 the knowledge memory size
 * @param p4 the signal memory
 * @param p5 the signal memory count
 * @param p6 the signal memory size
 * @param p7 the interrupt request flag
 * @param p8 the signal memory mutex
 * @param p9 the shutdown flag
 * @param p10 the signal (operation)
 * @param p11 the signal count
 * @param p12 the parameters (details)
 * @param p13 the parameters count
 * @param p14 the signal priority
 * @param p15 the signal id
 */
void handle_operation(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6,
    void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14, void* p15) {

    log_message_debug("\n\n");
    log_message((void*) INFO_LOG_LEVEL, (void*) HANDLE_OPERATION_MESSAGE, (void*) HANDLE_OPERATION_MESSAGE_COUNT);

    //?? TEST
//??    fprintf(stderr, "TEST: Operation: %s\n", (char*) p10);
//??    fprintf(stderr, "TEST: Operation count: %i\n", *((int*) p11));
//??    fprintf(stderr, "TEST handler p1: %i\n", p1);
//??    test_knowledge_memory(p1, p2, 5);

    // The comparison result.
    int r = 0;

    //
    // Program flow models.
    //

    if (r == 0) {

        compare_arrays(p10, p11, (void*) COPY_MODEL, (void*) COPY_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            copy(p12, p13, p1, p2, p3);
        }
    }

    if (r == 0) {

        compare_arrays(p10, p11, (void*) BRANCH_MODEL, (void*) BRANCH_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            branch(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p12, p13, p14, p15);
        }
    }

    if (r == 0) {

        compare_arrays(p10, p11, (void*) LOOP_MODEL, (void*) LOOP_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            loop(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p12, p13, p14, p15);
        }
    }

    if (r == 0) {

        compare_arrays(p10, p11, (void*) COUNT_PARTS_MODEL, (void*) COUNT_PARTS_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            count_parts(p12, p13, p1, p2, p3);
        }
    }

    if (r == 0) {

        compare_arrays(p10, p11, (void*) BUILD_LISTNAME_MODEL, (void*) BUILD_LISTNAME_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            build_listname(p12, p13, p1, p2, p3);
        }
    }

    //
    // Boolean logic models.
    //

    //
    // Comparison models.
    //

    if (r == 0) {

        compare_arrays(p10, p11, (void*) COMPARE_MODEL, (void*) COMPARE_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            compare(p12, p13, p1, p2, p3);
        }
    }

    //
    // Arithmetic models.
    //

    if (r == 0) {

        compare_arrays(p10, p11, (void*) ADD_MODEL, (void*) ADD_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            add(p12, p13, p1, p2, p3);
        }
    }

    //
    // Memory management models.
    //

    if (r == 0) {

        compare_arrays(p10, p11, (void*) CREATE_MODEL, (void*) CREATE_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            create(p12, p13, p1, p2, p3);
        }
    }

    if (r == 0) {

        compare_arrays(p10, p11, (void*) DESTROY_MODEL, (void*) DESTROY_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            destroy(p12, p13, p1, p2, p3);
        }
    }

    //
    // Lifecycle models.
    //

    if (r == 0) {

        compare_arrays(p10, p11, (void*) STARTUP_MODEL, (void*) STARTUP_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            startup_service(p12, p13, p1, p2, p3, p0);
        }
    }

    if (r == 0) {

        compare_arrays(p10, p11, (void*) SHUTDOWN_MODEL, (void*) SHUTDOWN_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            shutdown_service(p12, p13, p1, p2, p3, p0);
        }
    }

    if (r == 0) {

        compare_arrays(p10, p11, (void*) EXIT_MODEL, (void*) EXIT_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            log_message((void*) INFO_LOG_LEVEL, (void*) SET_SHUTDOWN_FLAG_MESSAGE, (void*) SET_SHUTDOWN_FLAG_MESSAGE_COUNT);

            int* f = (int*) p9;
            *f = 1;
        }
    }

    //
    // Communication models.
    //

    if (r == 0) {

        compare_arrays(p10, p11, (void*) SEND_MODEL, (void*) SEND_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            send_message(p12, p13, p0, p1, p2, p3, p4, p5, p6, p15);
        }
    }

    if (r == 0) {

        compare_arrays(p10, p11, (void*) RECEIVE_MODEL, (void*) RECEIVE_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            receive_message(p12, p13, p0, p1, p2, p3, p4, p5, p6);
        }
    }

    if (r == 0) {

        compare_arrays(p10, p11, (void*) INTERRUPT_MODEL, (void*) INTERRUPT_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            interrupt_service(p12, p13, p1, p2, p3, p0);
        }
    }

    if (r == 0) {

        compare_arrays(p10, p11, (void*) REFRESH_URL_MODEL, (void*) REFRESH_URL_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

//??            refresh_url(p12, p13, p0, p1, p2, p3, p15);
        }
    }

    //
    // Shell command models.
    //

    if (r == 0) {

        compare_arrays(p10, p11, (void*) RUN_MODEL, (void*) RUN_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            run(p12, p13, p1, p2);
        }
    }
}

/* OPERATION_HANDLER_SOURCE */
#endif
