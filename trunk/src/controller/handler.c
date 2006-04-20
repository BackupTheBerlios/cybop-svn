/*
 * $RCSfile: handler.c,v $
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
 * @version $Revision: 1.8 $ $Date: 2006-04-20 22:36:09 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 * @author Rolf Holzmueller <rolf.holzmueller@gmx.de>
 */

#ifndef HANDLER_SOURCE
#define HANDLER_SOURCE

#include "../controller/handler/compound_handler.c"
#include "../controller/handler/operation_handler.c"
#include "../globals/constants/abstraction_constants.c"
#include "../globals/constants/log_constants.c"
#include "../globals/logger/logger.c"
#include "../memoriser/array.c"

/**
 * Handles the signal.
 *
 * This procedure identifies the signal abstraction and then calls either
 * the compound signal handler, or the operation signal handler procedure.
 *
 * @param p0 the internal memory
 * @param p1 the knowledge memory
 * @param p2 the knowledge memory count
 * @param p3 the knowledge memory size
 * @param p4 the signal memory
 * @param p5 the signal memory count
 * @param p6 the signal memory size
 * @param p7 the signal memory blocked flag
 * @param p8 the interrupt request flag
 * @param p9 the shutdown flag
 * @param p10 the abctraction
 * @param p11 the abstraction count
 * @param p12 the signal (model)
 * @param p13 the signal count
 * @param p14 the parameters (details)
 * @param p15 the parameters count
 * @param p16 the priority
 * @param p17 the signal id
 * @param p18 the direct execution flag
 */
void handle(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6,
    void* p7, void* p8, void* p9, void* p10, void* p11,
    void* p12, void* p13,  void* p14, void* p15, void* p16, void* p17, void* p18) {

    // The comparison result.
    int r = 0;

    if (r == 0) {

        compare_arrays(p10, p11, (void*) CYBOL_ABSTRACTION, (void*) CYBOL_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            handle_compound(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9,
                p12, p13, p16, p17, p18);
        }
    }

    if (r == 0) {

        compare_arrays(p10, p11, (void*) OPERATION_ABSTRACTION, (void*) OPERATION_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            handle_operation(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9,
                p12, p13, p14, p15, p16, p17);
        }
    }

    if (r == 0) {

        log_message((void*) WARNING_LOG_LEVEL, (void*) COULD_NOT_HANDLE_SIGNAL_THE_SIGNAL_ABSTRACTION_IS_UNKNOWN_MESSAGE, (void*) COULD_NOT_HANDLE_SIGNAL_THE_SIGNAL_ABSTRACTION_IS_UNKNOWN_MESSAGE_COUNT);
    }
}

/* HANDLER_SOURCE */
#endif
