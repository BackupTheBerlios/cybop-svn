/*
 * $RCSfile: signal_handler.c,v $
 *
 * Copyright (c) 1999-2005. Christian Heller. All rights reserved.
 *
 * This software is published under the GPL GNU General Public License.
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
 * @version $Revision: 1.12 $ $Date: 2005-01-10 14:46:33 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef SIGNAL_HANDLER_SOURCE
#define SIGNAL_HANDLER_SOURCE

#include "../array/array.c"
#include "../global/abstraction_constants.c"
#include "../global/integer_constants.c"
#include "../global/structure_constants.c"
#include "../logger/logger.c"
#include "../logic/add.c"
#include "../logic/create.c"
#include "../logic/destroy.c"
#include "../logic/receive.c"
#include "../logic/send.c"
#include "../x_windows/x_windows_handler.c"

/**
 * Handles the compound signal.
 *
 * @param p0 the signal
 * @param p1 the signal count
 * @param p2 the signal priority
 * @param p3 the signal id
 * @param p4 the signal memory
 * @param p5 the signal memory count
 * @param p6 the signal memory size
 */
void handle_compound_signal(const void* p0, const void* p1, const void* p2,
    const void* p3, void* p4, void* p5, void* p6) {

    if (p1 != NULL_POINTER) {

        int** sc = (int**) p1;

        log_message((void*) &INFO_LOG_LEVEL, (void*) &HANDLE_COMPOUND_SIGNAL_MESSAGE, (void*) &HANDLE_COMPOUND_SIGNAL_MESSAGE_COUNT);

        // The abstractions.
        void* pa = NULL_POINTER;
        void* pac = NULL_POINTER;
        // The models.
        void* pm = NULL_POINTER;
        void* pmc = NULL_POINTER;
        // The details.
        void* pd = NULL_POINTER;
        void* pdc = NULL_POINTER;

        // Get abstractions, models, details.
        get_array_elements(p0, (void*) &POINTER_ARRAY, (void*) &ABSTRACTIONS_INDEX, (void*) &pa, (void*) &ONE_NUMBER);
        get_array_elements(p0, (void*) &POINTER_ARRAY, (void*) &ABSTRACTIONS_COUNTS_INDEX, (void*) &pac, (void*) &ONE_NUMBER);
        get_array_elements(p0, (void*) &POINTER_ARRAY, (void*) &MODELS_INDEX, (void*) &pm, (void*) &ONE_NUMBER);
        get_array_elements(p0, (void*) &POINTER_ARRAY, (void*) &MODELS_COUNTS_INDEX, (void*) &pmc, (void*) &ONE_NUMBER);
        get_array_elements(p0, (void*) &POINTER_ARRAY, (void*) &DETAILS_INDEX, (void*) &pd, (void*) &ONE_NUMBER);
        get_array_elements(p0, (void*) &POINTER_ARRAY, (void*) &DETAILS_COUNTS_INDEX, (void*) &pdc, (void*) &ONE_NUMBER);

        // The abstraction.
        void* a = NULL_POINTER;
        void* ac = NULL_POINTER;
        // The model.
        void* m = NULL_POINTER;
        void* mc = NULL_POINTER;
        // The details.
        void* d = NULL_POINTER;
        void* dc = NULL_POINTER;

        // The loop variable.
        int* j = INTEGER_NULL_POINTER;
        create_integer((void*) &j);
        *j = 0;

        while (1) {

            if (*j >= **sc) {

                break;
            }

            // Get abstraction, model, details.
            get_array_elements((void*) &pa, (void*) &POINTER_ARRAY, (void*) &j, (void*) &a, (void*) &ONE_NUMBER);
            get_array_elements((void*) &pac, (void*) &INTEGER_ARRAY, (void*) &j, (void*) &ac, (void*) &ONE_NUMBER);
            get_array_elements((void*) &pm, (void*) &POINTER_ARRAY, (void*) &j, (void*) &m, (void*) &ONE_NUMBER);
            get_array_elements((void*) &pmc, (void*) &INTEGER_ARRAY, (void*) &j, (void*) &mc, (void*) &ONE_NUMBER);
            get_array_elements((void*) &pd, (void*) &POINTER_ARRAY, (void*) &j, (void*) &d, (void*) &ONE_NUMBER);
            get_array_elements((void*) &pdc, (void*) &INTEGER_ARRAY, (void*) &j, (void*) &dc, (void*) &ONE_NUMBER);

            // Add part model (signal) to memory, using the whole signal's priority.
            // (Each signal has a priority. A signal may consist of part
            // signals. The part signals cannot have higher / lower priority
            // than their original whole signal.)
            set_signal(p4, p5, p6, (void*) &a, (void*) &ac, (void*) &m, (void*) &mc,
                (void*) &d, (void*) &dc, p2, p3);

            // Reset abstraction.
            a = NULL_POINTER;
            ac = NULL_POINTER;
            // Reset model.
            m = NULL_POINTER;
            mc = NULL_POINTER;
            // Reset details.
            d = NULL_POINTER;
            dc = NULL_POINTER;

            (*j)++;
        }

        destroy_integer((void*) &j);

    } else {

//??        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not handle compound signal. The signal memory count is null.");
    }
}

/**
 * Handles the operation signal.
 *
 * @param p0 the signal (operation)
 * @param p1 the signal count
 * @param p2 the parameters (details)
 * @param p3 the parameters count
 * @param p4 the knowledge
 * @param p5 the knowledge count
 * @param p6 the knowledge size
 * @param p7 the signal id
 * @param p8 the internals
 * @param p9 the shutdown flag
 */
void handle_operation_signal(const void* p0, const void* p1, const void* p2, const void* p3,
    void* p4, void* p5, void* p6, void* p7, void* p8, void* p9) {

    log_message((void*) &INFO_LOG_LEVEL, (void*) &HANDLE_OPERATION_SIGNAL_MESSAGE, (void*) &HANDLE_OPERATION_SIGNAL_MESSAGE_COUNT);

    // The done flag.
    int d = 0;
    // The comparison result.
    int* r = INTEGER_NULL_POINTER;
    create_integer((void*) &r);
    *r = 0;

    fprintf(stderr, "TEST operation: %s\n", *((char**) p0));
    fprintf(stderr, "TEST operation count: %i\n", **((int**) p1));

    if (d == 0) {

        compare_arrays(p0, p1, (void*) &ADD_ABSTRACTION, (void*) &ADD_ABSTRACTION_COUNT, (void*) &r, (void*) &CHARACTER_ARRAY);

        if (*r == 1) {

            add(p2, p3, p4, p5, p6);

            d = 1;
        }
    }

    if (d == 0) {

        compare_arrays(p0, p1, (void*) &CREATE_PART_ABSTRACTION, (void*) &CREATE_PART_ABSTRACTION_COUNT, (void*) &r, (void*) &CHARACTER_ARRAY);

        if (*r == 1) {

            create_part(p2, p3, p4, p5, p6);

            d = 1;
        }
    }

    if (d == 0) {

        compare_arrays(p0, p1, (void*) &DESTROY_PART_ABSTRACTION, (void*) &DESTROY_PART_ABSTRACTION_COUNT, (void*) &r, (void*) &CHARACTER_ARRAY);

        if (*r == 1) {

            destroy_part(p2, p3, p4, p5, p6);

            d = 1;
        }
    }

    if (d == 0) {

        compare_arrays(p0, p1, (void*) &SEND_ABSTRACTION, (void*) &SEND_ABSTRACTION_COUNT, (void*) &r, (void*) &CHARACTER_ARRAY);

        if (*r == 1) {

            send_message(p2, p3, p4, p5, p6, p7, p8);

            d = 1;
        }
    }

    if (d == 0) {

        compare_arrays(p0, p1, (void*) &RECEIVE_ABSTRACTION, (void*) &RECEIVE_ABSTRACTION_COUNT, (void*) &r, (void*) &CHARACTER_ARRAY);

        if (*r == 1) {

            receive_message(p2, p3, p4, p5, p6, p8);

            d = 1;
        }
    }

    if (d == 0) {

        compare_arrays(p0, p1, (void*) &EXIT_ABSTRACTION, (void*) &EXIT_ABSTRACTION_COUNT, (void*) &r, (void*) &CHARACTER_ARRAY);

        if (*r == 1) {

            log_message((void*) &INFO_LOG_LEVEL, (void*) &SET_SHUTDOWN_FLAG_MESSAGE, (void*) &SET_SHUTDOWN_FLAG_MESSAGE_COUNT);

            int** f = (int**) p9;
            **f = 1;

            d = 1;
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

    destroy_integer((void*) &r);
}

/* SIGNAL_HANDLER_SOURCE */
#endif
