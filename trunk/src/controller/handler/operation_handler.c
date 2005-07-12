/*
 * $RCSfile: operation_handler.c,v $
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
 * @version $Revision: 1.1 $ $Date: 2005-07-12 10:38:54 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 * @author Rolf Holzmueller <rolf.holzmueller@gmx.de>
 */

#ifndef OPERATION_SIGNAL_HANDLER_SOURCE
#define OPERATION_SIGNAL_HANDLER_SOURCE

#include "../../applicator/add.c"
#include "../../applicator/branch.c"
#include "../../applicator/build.c"
#include "../../applicator/compare.c"
#include "../../applicator/count.c"
#include "../../applicator/create.c"
#include "../../applicator/destroy.c"
#include "../../applicator/interrupt.c"
#include "../../applicator/loop.c"
#include "../../applicator/receive.c"
#include "../../applicator/send.c"
#include "../../applicator/set.c"
#include "../../applicator/shutdown.c"
#include "../../applicator/startup.c"
#include "../../globals/constants/model_constants.c"
#include "../../globals/logger/logger.c"
#include "../../memoriser/array/array.c"
/*??
#include "../../globals/constants/abstraction_constants.c"
#include "../../globals/constants/integer_constants.c"
#include "../../globals/constants/structure_constants.c"
*/

/**
 * Handles the operation signal.
 *
 * @param p0 the signal (operation)
 * @param p1 the signal count
 * @param p2 the parameters (details)
 * @param p3 the parameters count
 * @param p4 the signal priority
 * @param p5 the signal id
 * @param p6 the shutdown flag
 * @param p7 the internals
 */
void handle_operation_signal(const void* p0, const void* p1, const void* p2, const void* p3,
    const void* p4, const void* p5, void* p6, void* p7) {

    log_message((void*) INFO_LOG_LEVEL, (void*) HANDLE_OPERATION_SIGNAL_MESSAGE, (void*) HANDLE_OPERATION_SIGNAL_MESSAGE_COUNT);

    // The comparison result.
    int r = 0;

    fprintf(stderr, "TEST operation: %s\n", (char*) p0);
    fprintf(stderr, "TEST operation count: %i\n", *((int*) p1));

    // The knowledge memory.
    void** km = POINTER_NULL_POINTER;
    void** kmc = POINTER_NULL_POINTER;
    void** kms = POINTER_NULL_POINTER;

    // Get knowledge memory.
    get_array_elements(p7, (void*) KNOWLEDGE_MEMORY_INTERNAL, (void*) &km, (void*) POINTER_ARRAY);
    get_array_elements(p7, (void*) KNOWLEDGE_MEMORY_COUNT_INTERNAL, (void*) &kmc, (void*) POINTER_ARRAY);
    get_array_elements(p7, (void*) KNOWLEDGE_MEMORY_SIZE_INTERNAL, (void*) &kms, (void*) POINTER_ARRAY);

    //
    // Program flow models.
    //

    if (r != 1) {

        compare_arrays(p0, p1, (void*) COPY_MODEL, (void*) COPY_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

//??            copy(p2, p3, p4, p5, p7);
        }
    }

    if (r != 1) {

        compare_arrays(p0, p1, (void*) COPY_PROPERTY_MODEL, (void*) COPY_PROPERTY_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

//??            copy_property(p2, p3, p4, p5, p7);
        }
    }

    if (r != 1) {

        compare_arrays(p0, p1, (void*) BRANCH_MODEL, (void*) BRANCH_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

            branch(p2, p3, *km, *kmc, *kms, p4, p5, p6, p7);
        }
    }

    if (r != 1) {

        compare_arrays(p0, p1, (void*) LOOP_MODEL, (void*) LOOP_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

            loop(p2, p3, *km, *kmc, *kms, p4, p5, p6, p7);
        }
    }

    if (r != 1) {

        compare_arrays(p0, p1, (void*) COUNT_PARTS_MODEL, (void*) COUNT_PARTS_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

//??            count_parts(p2, p3, p7);
        }
    }

    if (r != 1) {

        compare_arrays(p0, p1, (void*) BUILD_LISTNAME_MODEL, (void*) BUILD_LISTNAME_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

//??            build_listname(p2, p3, p7);
        }
    }

    //
    // Boolean logic models.
    //

    //
    // Comparison models.
    //

    if (r != 1) {

        compare_arrays(p0, p1, (void*) COMPARE_MODEL, (void*) COMPARE_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

            compare(p2, p3, *km, *kmc, *kms);
        }
    }

    //
    // Arithmetic models.
    //

    if (r != 1) {

        compare_arrays(p0, p1, (void*) ADD_MODEL, (void*) ADD_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

            add(p2, p3, *km, *kmc, *kms);
        }
    }

    //
    // Memory management models.
    //

    if (r != 1) {

        compare_arrays(p0, p1, (void*) CREATE_PART_MODEL, (void*) CREATE_PART_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

            create_part(p2, p3, *km, *kmc, *kms);
        }
    }

    if (r != 1) {

        compare_arrays(p0, p1, (void*) DESTROY_PART_MODEL, (void*) DESTROY_PART_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

            destroy_part(p2, p3, *km, *kmc, *kms);
        }
    }

    //
    // Lifecycle models.
    //

    if (r != 1) {

        compare_arrays(p0, p1, (void*) STARTUP_MODEL, (void*) STARTUP_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

            startup_service(p2, p3, *km, *kmc, *kms, p7);
        }
    }

    if (r != 1) {

        compare_arrays(p0, p1, (void*) SHUTDOWN_MODEL, (void*) SHUTDOWN_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

            shutdown_service(p2, p3, *km, *kmc, *kms, p7);
        }
    }

    if (r != 1) {

        compare_arrays(p0, p1, (void*) EXIT_MODEL, (void*) EXIT_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

            log_message((void*) INFO_LOG_LEVEL, (void*) SET_SHUTDOWN_FLAG_MESSAGE, (void*) SET_SHUTDOWN_FLAG_MESSAGE_COUNT);

            int* f = (int*) p6;
            *f = 1;
        }
    }

    //
    // Communication models.
    //

    if (r != 1) {

        compare_arrays(p0, p1, (void*) SEND_MODEL, (void*) SEND_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

            send_message(p2, p3, *km, *kmc, *kms, p5, p7);
        }
    }

    if (r != 1) {

        compare_arrays(p0, p1, (void*) RECEIVE_MODEL, (void*) RECEIVE_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

            receive_message(p2, p3, *km, *kmc, *kms, p7);
        }
    }

    if (r != 1) {

        compare_arrays(p0, p1, (void*) INTERRUPT_MODEL, (void*) INTERRUPT_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

//??            interrupt_service(p2, p3, *km, *kmc, *kms, p7);
        }
    }

    if (r != 1) {

        compare_arrays(p0, p1, (void*) REFRESH_URL_MODEL, (void*) REFRESH_URL_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

//??            refresh_url(p2, p3, *km, *kmc, *kms, p5, p7);
        }
    }

/*??
    //?? Only for later, when mouse interrupt is handled directly here, and not in JavaEventHandler.
    if (strcmp(l, "mouse_moved") == 0) {

        Model statics = statics;

        set_model_element(statics, "mouse.pointer_position.x_distance.quantity", new java.lang.Integer(((java.awt.event.MouseEvent) evt).getX()));
        set_model_element(statics, "mouse.pointer_position.x_distance.unit", "pixel");
        set_model_element(statics, "mouse.pointer_position.y_distance.quantity", new java.lang.Integer(((java.awt.event.MouseEvent) evt).getY()));
        set_model_element(statics, "mouse.pointer_position.y_distance.unit", "pixel");

    } else if (strcmp(l, "mouse_clicked") == 0) {

        void* main_frame = get_statics_model_part(statics, (void*) "main_frame");
        struct vector* pointer_position = get_statics_model_part(statics, (void*) "mouse.pointer_position");

        reset_signal(s);

        if (pointer_position != NULL_POINTER) {

//??        mouse_clicked_action(main_frame, (void*) pointer_position->x, (void*) pointer_position->y, (void*) pointer_position->z, s->predicate);

        } else {

//??            log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not handle mouse clicked action. The pointer position is null.");
        }
    }
*/
}

/* OPERATION_SIGNAL_HANDLER_SOURCE */
#endif
