/*
 * $RCSfile: loop.c,v $
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
 * this handel a loop
 *
 * @version $Revision: 1.1 $ $Date: 2005-07-08 13:47:18 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef LOOP_SOURCE
#define LOOP_SOURCE

#include "../globals/constants/abstraction_constants.c"
#include "../globals/constants/boolean_constants.c"
#include "../globals/constants/log_constants.c"
#include "../globals/constants/name_constants.c"
#include "../globals/constants/structure_constants.c"
#include "../globals/logger/logger.c"
#include "../memory/accessor/compound_accessor.c"
#include "../memory/array/array.c"

//
// Forward declarations.
//

void handle_signal(const void* p0, const void* p1, const void* p2, const void* p3,
    const void* p4, const void* p5,const  void* p6, const void* p7, void* p8, void* p9, void* p10);

/**
 * Loops the program flow, depending on a flag.
 *
 * Expected parameters:
 * - break: the break flag
 * - model: the model to be executed repeatadly
 *
 * @param p0 the parameters
 * @param p1 the parameters count
 * @param p2 the knowledge memory
 * @param p3 the knowledge memory count
 * @param p4 the knowledge memory size
 * @param p5 the priority
 * @param p6 the signal id
 * @param p7 the shutdown flag
 * @param p8 the internals memory
 */
void loop(const void* p0, const void* p1, const void* p2, const void* p3, const void* p4,
    const void* p5, const void* p6, void* p7, void* p8) {

    log_message_debug("Loop program flow.");

    // The break flag abstraction.
    void** bfa = POINTER_NULL_POINTER;
    void** bfac = POINTER_NULL_POINTER;
    void** bfas = POINTER_NULL_POINTER;
    // The break flag model.
    void** bfm = POINTER_NULL_POINTER;
    void** bfmc = POINTER_NULL_POINTER;
    void** bfms = POINTER_NULL_POINTER;
    // The break flag details.
    void** bfd = POINTER_NULL_POINTER;
    void** bfdc = POINTER_NULL_POINTER;
    void** bfds = POINTER_NULL_POINTER;

    // The model abstraction.
    void** ma = POINTER_NULL_POINTER;
    void** mac = POINTER_NULL_POINTER;
    void** mas = POINTER_NULL_POINTER;
    // The model model.
    void** mm = POINTER_NULL_POINTER;
    void** mmc = POINTER_NULL_POINTER;
    void** mms = POINTER_NULL_POINTER;
    // The model details.
    void** md = POINTER_NULL_POINTER;
    void** mdc = POINTER_NULL_POINTER;
    void** mds = POINTER_NULL_POINTER;

    // Get break flag.
    get_real_compound_element_by_name(p0, p1,
        (void*) BREAK_FLAG_NAME, (void*) BREAK_FLAG_NAME_COUNT,
        (void*) &bfa, (void*) &bfac, (void*) &bfas,
        (void*) &bfm, (void*) &bfmc, (void*) &bfms,
        (void*) &bfd, (void*) &bfdc, (void*) &bfds,
        p2, p3);

    // Get model.
    get_real_compound_element_by_name(p0, p1,
        (void*) LOOP_MODEL_NAME, (void*) LOOP_MODEL_NAME_COUNT,
        (void*) &ma, (void*) &mac, (void*) &mas,
        (void*) &mm, (void*) &mmc, (void*) &mms,
        (void*) &md, (void*) &mdc, (void*) &mds,
        p2, p3);

    // Check break flag.
    if ((bfa != POINTER_NULL_POINTER)
        && (bfac != POINTER_NULL_POINTER)
        && (bfas != POINTER_NULL_POINTER)
        && (bfm != POINTER_NULL_POINTER)
        && (bfmc != POINTER_NULL_POINTER)
        && (bfms != POINTER_NULL_POINTER)
        && (bfd != POINTER_NULL_POINTER)
        && (bfdc != POINTER_NULL_POINTER)
        && (bfds != POINTER_NULL_POINTER)
        // Check model.
        && (ma != POINTER_NULL_POINTER)
        && (mac != POINTER_NULL_POINTER)
        && (mas != POINTER_NULL_POINTER)
        && (mm != POINTER_NULL_POINTER)
        && (mmc != POINTER_NULL_POINTER)
        && (mms != POINTER_NULL_POINTER)
        && (md != POINTER_NULL_POINTER)
        && (mdc != POINTER_NULL_POINTER)
        && (mds != POINTER_NULL_POINTER)) {

        // The comparison result.
        int r = 0;

        compare_arrays(*bfa, *bfac, (void*) BOOLEAN_ABSTRACTION, (void*) BOOLEAN_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

            while (1) {

                // The break flag.
                void* b = NULL_POINTER;

                // Get break flag.
                get_array_elements(*bfm, (void*) INTEGER_VALUE_INDEX, (void*) &b, (void*) INTEGER_ARRAY);

                // Reset comparison flag.
                r = 0;

                compare_arrays(b, INTEGER_COUNT, (void*) TRUE_BOOLEAN, (void*) ONE_INTEGER, &r, (void*) INTEGER_ARRAY);

                // The direct execution flag.
                // CAUTION! The flag has to be set to true, because otherwise,
                // each loop cycle places a new signal in signal memory so that
                // these would only be processed with a delay.
                // But this is not desirable, since follow-up signals of this
                // loop may rely on its full execution, including all cycles.
                int x = 1;

                if (r == 1) {

                    // Leave the loop if the break flag is true.
                    break;

                } else {

                    // Send the loop model as new signal,
                    // as long as the break flag is false (not set).
                    handle_signal(*ma, *mac, *mm, *mmc, *md, *mdc,
                        p5, p6, p7, p8, (void*) &x);
                }
            }
        }
    }
}

/* LOOP_SOURCE */
#endif
