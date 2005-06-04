/*
 * $RCSfile: selection.c,v $
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
 * @version $Revision: 1.2 $ $Date: 2005-06-04 23:49:50 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef SELECTION_SOURCE
#define SELECTION_SOURCE

#include "../controller/communicator/communicator.c"
#include "../controller/converter/converter.c"
#include "../controller/translator/translator.c"
#include "../globals/constants/abstraction_constants.c"
#include "../globals/constants/log_constants.c"
#include "../globals/constants/name_constants.c"
#include "../globals/logger/logger.c"
#include "../memory/accessor/compound_accessor.c"
#include "../memory/array/array.c"
#include "../memory/creator/creator.c"
#include "../tester/tester.c"

void handle_signal(const void* p0, const void* p1, const void* p2, const void* p3,
    const void* p4, const void* p5, const void* p6, const void* p7, void* p8, void* p9, void* p10);

/**
 * selection
 *
 * @param param the parameters
 * @param param_count the parameters count
 * @param proiority
 * @param signal_id
 * @param internal
 */
void selection( const void* param, const int* param_count,
           const void* priority, const void* signal_id, void* shutdownflag,
           void* internal )
{

    // The knowledge memory.
    void** km = POINTER_NULL_POINTER;
    void** kmc = POINTER_NULL_POINTER;
    void** kms = POINTER_NULL_POINTER;

    // Get knowledge memory.
    get_array_elements(internal, (void*) KNOWLEDGE_MEMORY_INTERNAL, (void*) &km, (void*) POINTER_ARRAY);
    get_array_elements(internal, (void*) KNOWLEDGE_MEMORY_COUNT_INTERNAL, (void*) &kmc, (void*) POINTER_ARRAY);
    get_array_elements(internal, (void*) KNOWLEDGE_MEMORY_SIZE_INTERNAL, (void*) &kms, (void*) POINTER_ARRAY);

    log_message_debug("operation selection");

    // The comparison abstraction.
    void** compa = POINTER_NULL_POINTER;
    void** compac = POINTER_NULL_POINTER;
    void** compas = POINTER_NULL_POINTER;
    // The comparison model.
    void** compm = POINTER_NULL_POINTER;
    void** compmc = POINTER_NULL_POINTER;
    void** compms = POINTER_NULL_POINTER;
    // The comparison details.
    void** compd = POINTER_NULL_POINTER;
    void** compdc = POINTER_NULL_POINTER;
    void** compds = POINTER_NULL_POINTER;

    // The model true abstraction.
    void** truea = POINTER_NULL_POINTER;
    void** trueac = POINTER_NULL_POINTER;
    void** trueas = POINTER_NULL_POINTER;
    // The model true model.
    void** truem = POINTER_NULL_POINTER;
    void** truemc = POINTER_NULL_POINTER;
    void** truems = POINTER_NULL_POINTER;
    // The model true details.
    void** trued = POINTER_NULL_POINTER;
    void** truedc = POINTER_NULL_POINTER;
    void** trueds = POINTER_NULL_POINTER;

    // The model false abstraction.
    void** falsea = POINTER_NULL_POINTER;
    void** falseac = POINTER_NULL_POINTER;
    void** falseas = POINTER_NULL_POINTER;
    // The model false model.
    void** falsem = POINTER_NULL_POINTER;
    void** falsemc = POINTER_NULL_POINTER;
    void** falsems = POINTER_NULL_POINTER;
    // The model false details.
    void** falsed = POINTER_NULL_POINTER;
    void** falsedc = POINTER_NULL_POINTER;
    void** falseds = POINTER_NULL_POINTER;

    // get the comarison
    get_real_compound_element_by_name( param, param_count,
        (void*) SELECTION_COMPARISON_NAME_ABSTRACTION,
        (void*) SELECTION_COMPARISON_NAME_ABSTRACTION_COUNT,
        (void*) &compa, (void*) &compac, (void*) &compas,
        (void*) &compm, (void*) &compmc, (void*) &compms,
        (void*) &compd, (void*) &compdc, (void*) &compds,
        *km, *kmc );

    // get the operand 2
    get_real_compound_element_by_name( param, param_count,
        (void*) SELECTION_FALSE_MODEL_NAME_ABSTRACTION,
        (void*) SELECTION_FALSE_MODEL_NAME_ABSTRACTION_COUNT,
        (void*) &truea, (void*) &trueac, (void*) &trueas,
        (void*) &truem, (void*) &truemc, (void*) &truems,
        (void*) &trued, (void*) &truedc, (void*) &trueds,
        *km, *kmc );

    // get the result
    get_real_compound_element_by_name( param, param_count,
        (void*) SELECTION_TRUE_MODEL_NAME_ABSTRACTION,
        (void*) SELECTION_TRUE_MODEL_NAME_ABSTRACTION_COUNT,
        (void*) &falsea, (void*) &falseac, (void*) &falseas,
        (void*) &falsem, (void*) &falsemc, (void*) &falsems,
        (void*) &falsed, (void*) &falsedc, (void*) &falseds,
        *km, *kmc );

    // Check comparison
    if (   (compa != POINTER_NULL_POINTER)
        && (compac != POINTER_NULL_POINTER)
        && (compas != POINTER_NULL_POINTER)
        && (compm != POINTER_NULL_POINTER)
        && (compmc != POINTER_NULL_POINTER)
        && (compms != POINTER_NULL_POINTER)
        && (compd != POINTER_NULL_POINTER)
        && (compdc != POINTER_NULL_POINTER)
        && (compds != POINTER_NULL_POINTER)
        // Check true model.
        && (truea != POINTER_NULL_POINTER)
        && (trueac != POINTER_NULL_POINTER)
        && (trueas != POINTER_NULL_POINTER)
        && (truem != POINTER_NULL_POINTER)
        && (truemc != POINTER_NULL_POINTER)
        && (truems != POINTER_NULL_POINTER)
        && (trued != POINTER_NULL_POINTER)
        && (truedc != POINTER_NULL_POINTER)
        && (trueds != POINTER_NULL_POINTER)
        // check false model
        && (falsea != POINTER_NULL_POINTER)
        && (falseac != POINTER_NULL_POINTER)
        && (falseas != POINTER_NULL_POINTER)
        && (falsem != POINTER_NULL_POINTER)
        && (falsemc != POINTER_NULL_POINTER)
        && (falsems != POINTER_NULL_POINTER)
        && (falsed != POINTER_NULL_POINTER)
        && (falsedc != POINTER_NULL_POINTER)
        && (falseds != POINTER_NULL_POINTER)
        )
    {

        int r = 0;

        int direct_execution_flag = 0;

        compare_arrays( *compa, *compac,
                        (void*) BOOLEAN_ABSTRACTION,
                        (void*) BOOLEAN_ABSTRACTION_COUNT,
                        (void*) &r, (void*) CHARACTER_ARRAY);

        if (r==1) {


            //chek, is then value of the brakflag false
            void* comp_dest = NULL_POINTER;
            get_array_elements( *compm, (void*) INTEGER_VALUE_INDEX,
                                (void*) &comp_dest,
                                (void*) INTEGER_ARRAY);
            r = 0;
            compare_arrays( comp_dest, INTEGER_COUNT,
                            (void*) ZERO_NUMBER, (void*) ONE_NUMBER,
                            &r, (void*) INTEGER_ARRAY );

            if (r ==1) {

                //the comparison is false
                handle_signal( *falsea, *falseac,
                               *falsem, *falsemc,
                               *falsed, *falsedc,
                               priority, signal_id,
                               shutdownflag, internal,
                               (void*) &direct_execution_flag );
            }
            else {

                //the comparison is true
                handle_signal( *truea, *trueac,
                               *truem, *truemc,
                               *trued, *truedc,
                               priority, signal_id,
                               shutdownflag, internal,
                               (void*) &direct_execution_flag );
            }
        }

    }
}

/* SELECTION_SOURCE */
#endif
