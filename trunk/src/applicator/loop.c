/*
 * $RCSfile: loop.c,v $
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
 * this handel a loop
 *
 * @version $Revision: 1.13 $ $Date: 2006-04-20 22:36:09 $ $Author: christian $
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
#include "../memoriser/accessor/compound_accessor.c"
#include "../memoriser/array.c"

//
// Forward declarations.
//

void handle(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6,
    void* p7, void* p8, void* p9, void* p10, void* p11,
    void* p12, void* p13,  void* p14, void* p15, void* p16, void* p17, void* p18);

/**
 * Loops the program flow, depending on a flag.
 *
 * Expected parameters:
 * - break: the break flag
 * - model: the model to be executed repeatadly
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
 * @param p10 the parameters
 * @param p11 the parameters count
 * @param p12 the priority
 * @param p13 the signal id
 */
void loop(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6,
    void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13) {

    log_message_debug("\n\n");
    log_message_debug("Loop program flow.");

    // The break flag abstraction.
    void** bfa = &NULL_POINTER;
    void** bfac = &NULL_POINTER;
    void** bfas = &NULL_POINTER;
    // The break flag model.
    void** bfm = &NULL_POINTER;
    void** bfmc = &NULL_POINTER;
    void** bfms = &NULL_POINTER;
    // The break flag details.
    void** bfd = &NULL_POINTER;
    void** bfdc = &NULL_POINTER;
    void** bfds = &NULL_POINTER;

    // The model abstraction.
    void** ma = &NULL_POINTER;
    void** mac = &NULL_POINTER;
    void** mas = &NULL_POINTER;
    // The model model.
    void** mm = &NULL_POINTER;
    void** mmc = &NULL_POINTER;
    void** mms = &NULL_POINTER;
    // The model details.
    void** md = &NULL_POINTER;
    void** mdc = &NULL_POINTER;
    void** mds = &NULL_POINTER;

    // Get break flag.
    get_real_compound_element_by_name(p10, p11,
        (void*) BREAK_FLAG_NAME, (void*) BREAK_FLAG_NAME_COUNT,
        (void*) &bfa, (void*) &bfac, (void*) &bfas,
        (void*) &bfm, (void*) &bfmc, (void*) &bfms,
        (void*) &bfd, (void*) &bfdc, (void*) &bfds,
        p1, p2);

    // Get model.
    get_real_compound_element_by_name(p10, p11,
        (void*) LOOP_MODEL_NAME, (void*) LOOP_MODEL_NAME_COUNT,
        (void*) &ma, (void*) &mac, (void*) &mas,
        (void*) &mm, (void*) &mmc, (void*) &mms,
        (void*) &md, (void*) &mdc, (void*) &mds,
        p1, p2);

    // Check break flag.
    if ((*bfa != NULL_POINTER)
        && (*bfac != NULL_POINTER)
        && (*bfas != NULL_POINTER)
        && (*bfm != NULL_POINTER)
        && (*bfmc != NULL_POINTER)
        && (*bfms != NULL_POINTER)
        && (*bfd != NULL_POINTER)
        && (*bfdc != NULL_POINTER)
        && (*bfds != NULL_POINTER)
        // Check model.
        && (*ma != NULL_POINTER)
        && (*mac != NULL_POINTER)
        && (*mas != NULL_POINTER)
        && (*mm != NULL_POINTER)
        && (*mmc != NULL_POINTER)
        && (*mms != NULL_POINTER)
        && (*md != NULL_POINTER)
        && (*mdc != NULL_POINTER)
        && (*mds != NULL_POINTER)) {

        // The comparison result.
        int r = 0;

        compare_arrays(*bfa, *bfac, (void*) BOOLEAN_ABSTRACTION, (void*) BOOLEAN_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

            while (1) {

                // The break flag.
                void* b = NULL_POINTER;

                // Get break flag.
                get_array_elements(*bfm, (void*) PRIMITIVE_VALUE_INDEX, (void*) &b, (void*) INTEGER_ARRAY);

                // Reset comparison flag.
                r = 0;

                compare_arrays(b, PRIMITIVE_COUNT, (void*) TRUE_BOOLEAN, (void*) NUMBER_1_INTEGER, &r, (void*) INTEGER_ARRAY);

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
                    handle(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9,
                        *ma, *mac, *mm, *mmc, *md, *mdc, p12, p13, (void*) &x);
                }
            }
        }
    }
}

/* LOOP_SOURCE */
#endif
