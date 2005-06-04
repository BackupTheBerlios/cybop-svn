/*
 * $RCSfile: compare.c,v $
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
 * @version $Revision: 1.2 $ $Date: 2005-06-04 23:49:50 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef COMPARE_SOURCE
#define COMPARE_SOURCE

#include "../controller/communicator/communicator.c"
#include "../controller/converter/converter.c"
#include "../controller/translator/translator.c"
#include "../globals/constants/abstraction_constants.c"
#include "../globals/constants/log_constants.c"
#include "../globals/constants/name_constants.c"
#include "../globals/logger/logger.c"
#include "../memory/array/array.c"
#include "../memory/creator/creator.c"
#include "../tester/tester.c"

/*
 * @param op1_abstr
 * @param op1_abstr_count
 * @param op1_model
 * @param op1_model_count
 * @param op2_abstr
 * @param op2_abstr_count
 * @param op2_model (hand over as redference)
 * @param op2_model_count
 * @param res
*/
void compare_smaller( const void* op1_abstr, const void* op1_abstr_count,
                      const void* op1_model, const void* op1_model_count,
                      const void* op2_abstr, const void* op2_abstr_count,
                      const void* op2_model, const void* op2_model_count,
                      void* res_model, void* res_model_count, void* res_model_size )
{

    int r1 = 0;
    int r2 = 0;
    compare_arrays( op1_abstr, op1_abstr_count,
                    (void*) INTEGER_ABSTRACTION,
                    (void*) INTEGER_ABSTRACTION_COUNT,
                    (void*) &r1, (void*) CHARACTER_ARRAY);
    compare_arrays( op2_abstr, op2_abstr_count,
                    (void*) INTEGER_ABSTRACTION,
                    (void*) INTEGER_ABSTRACTION_COUNT,
                    (void*) &r2, (void*) CHARACTER_ARRAY);

    if ( (r1==1) && (r2==1) ) {

        if  ( *((int*)op1_model) < *((int*)op2_model) ) {

            parse_boolean( res_model, res_model_count, res_model_size,
                           TRUE_BOOLEAN, TRUE_BOOLEAN_COUNT );
        }
        else {

            parse_boolean( res_model, res_model_count, res_model_size,
                           FALSE_BOOLEAN, FALSE_BOOLEAN_COUNT );
        }
    }
}

/*
 * @param op1_abstr
 * @param op1_abstr_count
 * @param op1_model
 * @param op1_model_count
 * @param op2_abstr
 * @param op2_abstr_count
 * @param op2_model (hand over as redference)
 * @param op2_model_count
 * @param res
*/
void compare_greater_or_equal( const void* op1_abstr, const void* op1_abstr_count,
                      const void* op1_model, const void* op1_model_count,
                      const void* op2_abstr, const void* op2_abstr_count,
                      const void* op2_model, const void* op2_model_count,
                      void* res_model, void* res_model_count, void* res_model_size )
{

    int r1 = 0;
    int r2 = 0;
    compare_arrays( op1_abstr, op1_abstr_count,
                    (void*) INTEGER_ABSTRACTION,
                    (void*) INTEGER_ABSTRACTION_COUNT,
                    (void*) &r1, (void*) CHARACTER_ARRAY);
    compare_arrays( op2_abstr, op2_abstr_count,
                    (void*) INTEGER_ABSTRACTION,
                    (void*) INTEGER_ABSTRACTION_COUNT,
                    (void*) &r2, (void*) CHARACTER_ARRAY);

    if ( (r1==1) && (r2==1) ) {

        if  ( *((int*)op1_model) >= *((int*)op2_model) ) {

            parse_boolean( res_model, res_model_count, res_model_size,
                           TRUE_BOOLEAN, TRUE_BOOLEAN_COUNT );
        }
        else {

            parse_boolean( res_model, res_model_count, res_model_size,
                           FALSE_BOOLEAN, FALSE_BOOLEAN_COUNT );
        }
    }
}


/*
 * @param param the parameters
 * @param param_count the parameters count
 * @param proiority
 * @param signal_id
 * @param internal
*/
void compare( const void* param, const int* param_count,
              const void* priority, const void* signal_id,
              void* internal )
{
    //als oparameter sollten ?bergeben werden
    //- operand_1
    //- operand_2
    //- operator
    //- result
    //nat?rlich in Konstanten gekapselt :-) also jederzeit ?nderbar

    // The knowledge memory.
    void** km = POINTER_NULL_POINTER;
    void** kmc = POINTER_NULL_POINTER;
    void** kms = POINTER_NULL_POINTER;

    // Get knowledge memory.
    get_array_elements(internal, (void*) KNOWLEDGE_MEMORY_INTERNAL, (void*) &km, (void*) POINTER_ARRAY);
    get_array_elements(internal, (void*) KNOWLEDGE_MEMORY_COUNT_INTERNAL, (void*) &kmc, (void*) POINTER_ARRAY);
    get_array_elements(internal, (void*) KNOWLEDGE_MEMORY_SIZE_INTERNAL, (void*) &kms, (void*) POINTER_ARRAY);


    log_message_debug("Operation compare");

    // The operand_1 name abstraction.
    void** op1a = POINTER_NULL_POINTER;
    void** op1ac = POINTER_NULL_POINTER;
    void** op1as = POINTER_NULL_POINTER;
    // The operand_1 model.
    void** op1m = POINTER_NULL_POINTER;
    void** op1mc = POINTER_NULL_POINTER;
    void** op1ms = POINTER_NULL_POINTER;
    // The operand_1 details.
    void** op1d = POINTER_NULL_POINTER;
    void** op1dc = POINTER_NULL_POINTER;
    void** op1ds = POINTER_NULL_POINTER;

    // The operand_2 abstraction.
    void** op2a = POINTER_NULL_POINTER;
    void** op2ac = POINTER_NULL_POINTER;
    void** op2as = POINTER_NULL_POINTER;
    // The operand_2 model.
    void** op2m = POINTER_NULL_POINTER;
    void** op2mc = POINTER_NULL_POINTER;
    void** op2ms = POINTER_NULL_POINTER;
    // The operand_2 details.
    void** op2d = POINTER_NULL_POINTER;
    void** op2dc = POINTER_NULL_POINTER;
    void** op2ds = POINTER_NULL_POINTER;

    // The operator abstraction.
    void** opa = POINTER_NULL_POINTER;
    void** opac = POINTER_NULL_POINTER;
    void** opas = POINTER_NULL_POINTER;
    // The operator model.
    void** opm = POINTER_NULL_POINTER;
    void** opmc = POINTER_NULL_POINTER;
    void** opms = POINTER_NULL_POINTER;
    // The operator details.
    void** opd = POINTER_NULL_POINTER;
    void** opdc = POINTER_NULL_POINTER;
    void** opds = POINTER_NULL_POINTER;

    // The result abstraction.
    void** ra = POINTER_NULL_POINTER;
    void** rac = POINTER_NULL_POINTER;
    void** ras = POINTER_NULL_POINTER;
    // The result model.
    void** rm = POINTER_NULL_POINTER;
    void** rmc = POINTER_NULL_POINTER;
    void** rms = POINTER_NULL_POINTER;
    // The result details.
    void** rd = POINTER_NULL_POINTER;
    void** rdc = POINTER_NULL_POINTER;
    void** rds = POINTER_NULL_POINTER;

    // Get operand_1.
    get_real_compound_element_by_name( param, param_count,
        (void*) COMPARE_OPERAND_1_NAME_ABSTRACTION,
        (void*) COMPARE_OPERAND_1_NAME_ABSTRACTION_COUNT,
        (void*) &op1a, (void*) &op1ac, (void*) &op1as,
        (void*) &op1m, (void*) &op1mc, (void*) &op1ms,
        (void*) &op1d, (void*) &op1dc, (void*) &op1ds,
        *km, *kmc );

    // Get opernad_2.
    get_real_compound_element_by_name(param, param_count,
        (void*) COMPARE_OPERAND_2_NAME_ABSTRACTION,
        (void*) COMPARE_OPERAND_2_NAME_ABSTRACTION_COUNT,
        (void*) &op2a, (void*) &op2ac, (void*) &op2as,
        (void*) &op2m, (void*) &op2mc, (void*) &op2ms,
        (void*) &op2d, (void*) &op2dc, (void*) &op2ds,
        *km, *kmc );

    // Get operator.
    get_compound_element_by_name(param, param_count,
        (void*) COMPARE_OPERATOR_NAME_ABSTRACTION,
        (void*) COMPARE_OPERATOR_NAME_ABSTRACTION_COUNT,
        (void*) &opa, (void*) &opac, (void*) &opas,
        (void*) &opm, (void*) &opmc, (void*) &opms,
        (void*) &opd, (void*) &opdc, (void*) &opds);

    // Get result.
    get_real_compound_element_by_name(param, param_count,
        (void*) COMPARE_RESULT_NAME_ABSTRACTION,
        (void*) COMPARE_RESULT_NAME_ABSTRACTION_COUNT,
        (void*) &ra, (void*) &rac, (void*) &ras,
        (void*) &rm, (void*) &rmc, (void*) &rms,
        (void*) &rd, (void*) &rdc, (void*) &rds,
        *km, *kmc );


    // Check operand 1.
    if (   (op1a != POINTER_NULL_POINTER)
        && (op1ac != POINTER_NULL_POINTER)
        && (op1as != POINTER_NULL_POINTER)
        && (op1m != POINTER_NULL_POINTER)
        && (op1mc != POINTER_NULL_POINTER)
        && (op1ms != POINTER_NULL_POINTER)
        && (op1d != POINTER_NULL_POINTER)
        && (op1dc != POINTER_NULL_POINTER)
        && (op1ds != POINTER_NULL_POINTER)
        // Check operand 2.
        && (op2a != POINTER_NULL_POINTER)
        && (op2ac != POINTER_NULL_POINTER)
        && (op2as != POINTER_NULL_POINTER)
        && (op2m != POINTER_NULL_POINTER)
        && (op2mc != POINTER_NULL_POINTER)
        && (op2ms != POINTER_NULL_POINTER)
        && (op2d != POINTER_NULL_POINTER)
        && (op2dc != POINTER_NULL_POINTER)
        && (op2ds != POINTER_NULL_POINTER)
        // Check operrator.
        && (opa != POINTER_NULL_POINTER)
        && (opac != POINTER_NULL_POINTER)
        && (opas != POINTER_NULL_POINTER)
        && (opm != POINTER_NULL_POINTER)
        && (opmc != POINTER_NULL_POINTER)
        && (opms != POINTER_NULL_POINTER)
        && (opd != POINTER_NULL_POINTER)
        && (opdc != POINTER_NULL_POINTER)
        && (opds != POINTER_NULL_POINTER)
        // result.
        && (ra != POINTER_NULL_POINTER)
        && (rac != POINTER_NULL_POINTER)
        && (ras != POINTER_NULL_POINTER)
        && (rm != POINTER_NULL_POINTER)
        && (rmc != POINTER_NULL_POINTER)
        && (rms != POINTER_NULL_POINTER)
        && (rd != POINTER_NULL_POINTER)
        && (rdc != POINTER_NULL_POINTER)
        && (rds != POINTER_NULL_POINTER)
      )
    {
        int r = 0;

        //check the abstracton from operand_1 and operand_2
        //the abstarction msut be the same
        r = 0;
        compare_arrays( *op1a, *op1ac, *op2a, *op2ac,
                        (void*) &r, (void*) CHARACTER_ARRAY);

        //check the abstraction for the result
        //the abstraction must be boolean;
        r = 0;
        compare_arrays( *op1a, *op1ac,
                        (void*) BOOLEAN_ABSTRACTION,
                        (void*) BOOLEAN_ABSTRACTION_COUNT,
                        (void*) &r, (void*) CHARACTER_ARRAY);


        r = 0;
        int comp_res = 0;
        if (r != 1) {

            compare_arrays( *opm, *opmc,
                            (void*) SMALLER_ABSTRACTION,
                            (void*) SMALLER_ABSTRACTION_COUNT,
                            (void*) &r, (void*) CHARACTER_ARRAY);
            if ( r == 1 ) {

                compare_smaller( *op1a, *op1ac, *op1m, op1mc,
                                 *op2a, *op2ac, *op2m, op2mc,
                                 rm, *rmc, *rms );
            }
        }

        if (r != 1) {

            compare_arrays( *opm, *opmc,
                            (void*) SMALLER_OR_EQUAL_ABSTRACTION,
                            (void*) SMALLER_OR_EQUAL_ABSTRACTION_COUNT,
                            (void*) &r, (void*) CHARACTER_ARRAY);
            if ( r == 1 ) {

            }
        }

        if (r != 1) {

            compare_arrays( *opm, *opmc,
                            (void*) EQUAL_ABSTRACTION,
                            (void*) EQUAL_ABSTRACTION_COUNT,
                            (void*) &r, (void*) CHARACTER_ARRAY);
            if ( r == 1 ) {

            }
        }

        if (r != 1) {

            compare_arrays( *opm, *opmc,
                            (void*) GREATER_OR_EQUAL_ABSTRACTION,
                            (void*) GREATER_OR_EQUAL_ABSTRACTION_COUNT,
                            (void*) &r, (void*) CHARACTER_ARRAY);
            if ( r == 1 ) {

                compare_greater_or_equal( *op1a, *op1ac, *op1m, op1mc,
                                 *op2a, *op2ac, *op2m, op2mc,
                                 rm, *rmc, *rms );
            }
        }

        if (r != 1) {

            compare_arrays( *opm, *opmc,
                            (void*) GREATER_ABSTRACTION,
                            (void*) GREATER_ABSTRACTION_COUNT,
                            (void*) &r, (void*) CHARACTER_ARRAY);
            if ( r == 1 ) {

            }
        }
    }
}

/* COMPARE_SOURCE */
#endif


