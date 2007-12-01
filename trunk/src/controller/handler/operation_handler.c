/*
 * $RCSfile: operation_handler.c,v $
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
 * @version $Revision: 1.39 $ $Date: 2007-12-01 23:57:41 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
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
#include "../../applicator/get.c"
#include "../../applicator/interrupt.c"
#include "../../applicator/loop.c"
#include "../../applicator/receive.c"
#include "../../applicator/run.c"
#include "../../applicator/send.c"
#include "../../applicator/sense.c"
#include "../../applicator/shutdown.c"
#include "../../applicator/startup.c"
#include "../../globals/constants/cybol/cybol_abstraction_constants.c"
#include "../../globals/constants/cybol/cybol_model_constants.c"
#include "../../globals/constants/integer/integer_constants.c"
#include "../../globals/constants/log/log_message_constants.c"
#include "../../globals/logger/logger.c"
#include "../../memoriser/array.c"

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
 * @param p7 the shutdown flag
 * @param p8 the signal memory interrupt request flag
 * @param p9 the signal memory mutex
 * @param p10 the model / signal / operation
 * @param p11 the model / signal / operation count
 * @param p12 the details / parameters
 * @param p13 the details / parameters count
 * @param p14 the signal priority (Hand over as reference!)
 * @param p15 the signal identification (Hand over as reference!)
 */
void handle_operation(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6,
    void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14, void* p15) {

    log_terminated_message((void*) INFORMATION_LOG_LEVEL, (void*) "\n\n");
    log_message((void*) INFORMATION_LOG_LEVEL, (void*) HANDLE_OPERATION_MESSAGE, (void*) HANDLE_OPERATION_MESSAGE_COUNT);

    fprintf(stderr, "TEST handle operation: %s\n", (char*) p10);
    log_terminated_message((void*) DEBUG_LOG_LEVEL, p10);
    log_terminated_message((void*) DEBUG_LOG_LEVEL, (void*) "\n");

    // The comparison result.
    int r = *NUMBER_0_INTEGER;

    //
    // Program flow models.
    //

    if (r == *NUMBER_0_INTEGER) {

        compare_arrays(p10, p11, (void*) COPY_MODEL, (void*) COPY_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != *NUMBER_0_INTEGER) {

            copy(p12, p13, p1, p2, p3);
        }
    }

    if (r == *NUMBER_0_INTEGER) {

        compare_arrays(p10, p11, (void*) BRANCH_MODEL, (void*) BRANCH_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != *NUMBER_0_INTEGER) {

            branch(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p12, p13, p14, p15);
        }
    }

    if (r == *NUMBER_0_INTEGER) {

        compare_arrays(p10, p11, (void*) LOOP_MODEL, (void*) LOOP_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != *NUMBER_0_INTEGER) {

            loop(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p12, p13, p14, p15);
        }
    }

    if (r == *NUMBER_0_INTEGER) {

        compare_arrays(p10, p11, (void*) COUNT_MODEL, (void*) COUNT_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != *NUMBER_0_INTEGER) {

            count(p12, p13, p1, p2, p3);
        }
    }

    if (r == *NUMBER_0_INTEGER) {

        compare_arrays(p10, p11, (void*) BUILD_LISTNAME_MODEL, (void*) BUILD_LISTNAME_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != *NUMBER_0_INTEGER) {

            build_listname(p12, p13, p1, p2, p3);
        }
    }

    if (r == *NUMBER_0_INTEGER) {

        compare_arrays(p10, p11, (void*) GET_MODEL, (void*) GET_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != *NUMBER_0_INTEGER) {

            get(p12, p13, p1, p2, p3);
        }
    }

    //
    // Boolean logic models.
    //

    //
    // Comparison models.
    //

    if (r == *NUMBER_0_INTEGER) {

        compare_arrays(p10, p11, (void*) COMPARE_MODEL, (void*) COMPARE_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != *NUMBER_0_INTEGER) {

            compare(p12, p13, p1, p2, p3);
        }
    }

    //
    // Arithmetic models.
    //

    if (r == *NUMBER_0_INTEGER) {

        compare_arrays(p10, p11, (void*) ADD_MODEL, (void*) ADD_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != *NUMBER_0_INTEGER) {

            add(p12, p13, p1, p2, p3);
        }
    }

    //
    // Memory management models.
    //

    if (r == *NUMBER_0_INTEGER) {

        compare_arrays(p10, p11, (void*) CREATE_MODEL, (void*) CREATE_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != *NUMBER_0_INTEGER) {

            create(p12, p13, p1, p2, p3);
        }
    }

    if (r == *NUMBER_0_INTEGER) {

        compare_arrays(p10, p11, (void*) DESTROY_MODEL, (void*) DESTROY_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != *NUMBER_0_INTEGER) {

            destroy(p12, p13, p1, p2, p3);
        }
    }

    //
    // Lifecycle models.
    //

    if (r == *NUMBER_0_INTEGER) {

        compare_arrays(p10, p11, (void*) STARTUP_MODEL, (void*) STARTUP_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != *NUMBER_0_INTEGER) {

            startup_service(p12, p13, p1, p2, p3, p0);
        }
    }

    if (r == *NUMBER_0_INTEGER) {

        compare_arrays(p10, p11, (void*) SHUTDOWN_MODEL, (void*) SHUTDOWN_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != *NUMBER_0_INTEGER) {

            shutdown_service(p12, p13, p1, p2, p3, p0);
        }
    }

    if (r == *NUMBER_0_INTEGER) {

        compare_arrays(p10, p11, (void*) EXIT_MODEL, (void*) EXIT_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != *NUMBER_0_INTEGER) {

            log_message((void*) INFORMATION_LOG_LEVEL, (void*) SET_SHUTDOWN_FLAG_MESSAGE, (void*) SET_SHUTDOWN_FLAG_MESSAGE_COUNT);

            int* f = (int*) p7;
            *f = *NUMBER_1_INTEGER;
        }
    }

    //
    // Communication models.
    //

    if (r == *NUMBER_0_INTEGER) {

        compare_arrays(p10, p11, (void*) SENSE_MODEL, (void*) SENSE_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != *NUMBER_0_INTEGER) {

            sense(p12, p13, p0, p1, p2, p3, p4, p5, p6);
        }
    }

    if (r == *NUMBER_0_INTEGER) {

        compare_arrays(p10, p11, (void*) INTERRUPT_MODEL, (void*) INTERRUPT_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != *NUMBER_0_INTEGER) {

            interrupt_service(p12, p13, p1, p2, p3);
        }
    }

    if (r == *NUMBER_0_INTEGER) {

        compare_arrays(p10, p11, (void*) RECEIVE_MODEL, (void*) RECEIVE_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != *NUMBER_0_INTEGER) {

            receive_message(p12, p13, p0, p1, p2, p3, p4, p5, p6);
        }
    }

    if (r == *NUMBER_0_INTEGER) {

        compare_arrays(p10, p11, (void*) SEND_MODEL, (void*) SEND_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != *NUMBER_0_INTEGER) {

//??            send_message(p12, p13, p0, p1, p2, p3, p4, p5, p6, p15);

            //?? TEST: For testing reasons, the p15 was replaced with *((int**) p15) here!
            //?? The signal id serves as client socket to which this cyboi system has to reply.
            send_message(p12, p13, p0, p1, p2, p3, p4, p5, p6, *((int**) p15));
        }
    }

    //
    // Shell command models.
    //

    if (r == *NUMBER_0_INTEGER) {

        compare_arrays(p10, p11, (void*) RUN_MODEL, (void*) RUN_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != *NUMBER_0_INTEGER) {

            run(p12, p13, p1, p2);
        }
    }
}

/* OPERATION_HANDLER_SOURCE */
#endif
