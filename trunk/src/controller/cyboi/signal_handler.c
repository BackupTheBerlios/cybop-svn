/*
 * $RCSfile: signal_handler.c,v $
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
 * @version $Revision: 1.5 $ $Date: 2005-06-29 22:57:38 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 * @author Rolf Holzmueller <rolf.holzmueller@gmx.de>
 */

#ifndef SIGNAL_HANDLER_SOURCE
#define SIGNAL_HANDLER_SOURCE

#include "../../controller/cyboi/compound_signal_handler.c"
#include "../../controller/cyboi/operation_signal_handler.c"
#include "../../globals/constants/abstraction_constants.c"
#include "../../memory/array/array.c"
#include "../../globals/logger/logger.c"

/**
 * Handles the signal.
 *
 * This procedure identifies the signal abstraction and then calls either
 * the compound signal handler, or the operation signal handler procedure.
 *
 * @param p0 the abctraction
 * @param p1 the abstraction count
 * @param p2 the signal (model)
 * @param p3 the signal count
 * @param p4 the parameters (details)
 * @param p5 the parameters count
 * @param p6 the priority
 * @param p7 the signal id
 * @param p8 the shutdown flag
 * @param p9 the internals memory
 * @param p10 the direct execution flag
 */
void handle_signal(const void* p0, const void* p1, const void* p2, const void* p3,
    const void* p4, const void* p5, const  void* p6, const void* p7, void* p8, void* p9, void* p10) {

    // The comparison result.
    int r = 0;

    if (r != 1) {

        compare_arrays(p0, p1, (void*) CYBOL_ABSTRACTION, (void*) CYBOL_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

            handle_compound_signal(p2, p3, p6, p7, p8, p9, p10);
        }
    }

    if (r != 1) {

        compare_arrays(p0, p1, (void*) OPERATION_ABSTRACTION, (void*) OPERATION_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

            handle_operation_signal(p2, p3, p4, p5, p6, p7, p8, p9);
        }
    }

    if (r != 1) {

        log_message((void*) WARNING_LOG_LEVEL, (void*) COULD_NOT_HANDLE_SIGNAL_THE_SIGNAL_ABSTRACTION_IS_UNKNOWN_MESSAGE, (void*) COULD_NOT_HANDLE_SIGNAL_THE_SIGNAL_ABSTRACTION_IS_UNKNOWN_MESSAGE_COUNT);
    }
}

/* SIGNAL_HANDLER_SOURCE */
#endif
