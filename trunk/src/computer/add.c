/*
 * $RCSfile: add.c,v $
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
 * @version $Revision: 1.3 $ $Date: 2005-06-29 18:48:45 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef ADD_SOURCE
#define ADD_SOURCE

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

/**
 * Adds two integer summands resulting in the integer sum.
 *
 * @param p0 the sum
 * @param p1 the summand 1
 * @param p2 the summand 2
 */
void add_integers(void* p0, const void* p1, const void* p2) {

    if (p2 != NULL_POINTER) {

        int* summand2 = (int*) p2;

        if (p1 != NULL_POINTER) {

            int* summand1 = (int*) p1;

            if (p0 != NULL_POINTER) {

                int* sum = (int*) p0;

                *sum = *summand1 + *summand2;

            } else {

//??                log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_HANDLE_CREATE_MODEL_SIGNAL_THE_SIGNAL_PARAMETERS_COUNT_IS_NULL_MESSAGE, (void*) &COULD_NOT_HANDLE_CREATE_MODEL_SIGNAL_THE_SIGNAL_PARAMETERS_COUNT_IS_NULL_MESSAGE_COUNT);
            }

        } else {

//??            log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_HANDLE_CREATE_MODEL_SIGNAL_THE_SIGNAL_PARAMETERS_COUNT_IS_NULL_MESSAGE, (void*) &COULD_NOT_HANDLE_CREATE_MODEL_SIGNAL_THE_SIGNAL_PARAMETERS_COUNT_IS_NULL_MESSAGE_COUNT);
        }

    } else {

//??        log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_HANDLE_CREATE_MODEL_SIGNAL_THE_SIGNAL_PARAMETERS_COUNT_IS_NULL_MESSAGE, (void*) &COULD_NOT_HANDLE_CREATE_MODEL_SIGNAL_THE_SIGNAL_PARAMETERS_COUNT_IS_NULL_MESSAGE_COUNT);
    }
}


/**
 * Adds two strings (concate)
 *
 * @param res the result (Hand over as reference)
 * @param res_count the result count
 * @param res_size the result size
 * @param op1 the operand 1
 * @param op1_count the operand 1 count
 * @param op1_size the operand 1 size
 * @param op2 the operand 2
 * @param op2_count the operand 2 count
 * @param op2_size the operand 2 size
 */
void add_strings( void** res, int* res_count, int* res_size,
                  void* op1, int* op1_count, int* op1_size,
                  void* op2, int* op2_count, int* op2_size )
{

    //check operanden
    if ( (op1 != NULL_POINTER) &&
         (op1_count != NULL_POINTER) &&
         (op1_size != NULL_POINTER) &&
         (op2 != NULL_POINTER) &&
         (op2_count != NULL_POINTER) &&
         (op2_size != NULL_POINTER) )
    {

        //check result
        if ( (res != NULL_POINTER) &&
             (res_count != NULL_POINTER) &&
             (res_size != NULL_POINTER) )
        {

            //resize the result array
            //if source and the destination the same, then
            //must the coutn in a temp variable
            int start_count = *op1_count;
            *res_size = *op1_count + *op2_count;
            *res_count = *op1_count + *op2_count;
            resize_array( res, res_size, CHARACTER_ARRAY );

            //set the result array
            set_array_elements( *res, (void*) ZERO_NUMBER,
                                op1, op1_count,  (void*) CHARACTER_ARRAY);

            set_array_elements( *res, &start_count,
                                op2, op2_count,  (void*) CHARACTER_ARRAY);
        }  //check result

    } //check operanden
}

///**
// * Adds two primitive summands resulting in the primitive sum.
// *
// * @param p0 the sum
// * @param p1 the summand 1
// * @param p2 the summand 2
// * @param p3 the abstraction
// * @param p4 the abstraction count
// */
//void add_primitives(void* p0, const void* p1, const void* p2, const void* p3, const void* p4) {
//
//    if (p4 != NULL_POINTER) {
//
//        int* ac = (int*) p4;
//
//        // The comparison result.
//        int r = 0;
//
//        if (r != 1) {
//
//            if (*ac == *INTEGER_ABSTRACTION_COUNT) {
//
//                compare_array_elements(p3, (void*) INTEGER_ABSTRACTION, (void*) INTEGER_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);
//
//                if (r == 1) {
//
//                    add_integers(p0, p1, p2);
//                }
//            }
//        }
//
//    } else {
//
////??        log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_HANDLE_CREATE_MODEL_SIGNAL_THE_SIGNAL_PARAMETERS_COUNT_IS_NULL_MESSAGE, (void*) &COULD_NOT_HANDLE_CREATE_MODEL_SIGNAL_THE_SIGNAL_PARAMETERS_COUNT_IS_NULL_MESSAGE_COUNT);
//    }
//}

/**
 * Adds two summands resulting in the sum.
 *
 * CYBOL Examples:
 *
 * <!-- Operation parameters (as value of part_model tag):
 *      logic name,summand 1,summand 2,sum /-->
 *
 * <part name="add_two_numbers" part_abstraction="operation" part_location="inline"
 *      part_model="add,application.summand1,application.summand2,application.sum"/>
 *
 * @param p0 the parameters
 * @param p1 the parameters count
 * @param p2 the knowledge
 * @param p3 the knowledge count
 * @param p4 the knowledge size
 */
void add(const void* p0, const void* p1, void* p2, void* p3, void* p4) {

/*??
    // The opernad 1 abstraction.
    void** op1a = POINTER_NULL_POINTER;
    void** op1ac = POINTER_NULL_POINTER;
    void** op1as = POINTER_NULL_POINTER;
    // The opmmand 1 model.
    void** op1m = POINTER_NULL_POINTER;
    void** op1mc = POINTER_NULL_POINTER;
    void** op1ms = POINTER_NULL_POINTER;
    // The opmmand 1 details.
    void** op1d = POINTER_NULL_POINTER;
    void** op1dc = POINTER_NULL_POINTER;
    void** op1ds = POINTER_NULL_POINTER;

    // The summand 2 abstraction.
    void** op2a = POINTER_NULL_POINTER;
    void** op2ac = POINTER_NULL_POINTER;
    void** op2as = POINTER_NULL_POINTER;
    // The opmmand 2 model.
    void** op2m = POINTER_NULL_POINTER;
    void** op2mc = POINTER_NULL_POINTER;
    void** op2ms = POINTER_NULL_POINTER;
    // The opmmand 2 details.
    void** op2d = POINTER_NULL_POINTER;
    void** op2dc = POINTER_NULL_POINTER;
    void** op2ds = POINTER_NULL_POINTER;

    // The result abstraction.
    void** ra = POINTER_NULL_POINTER;
    void** rac = POINTER_NULL_POINTER;
    void** ras = POINTER_NULL_POINTER;
    // The result index model.
    void** rm = POINTER_NULL_POINTER;
    void** rmc = POINTER_NULL_POINTER;
    void** rms = POINTER_NULL_POINTER;
    // The result index details.
    void** rd = POINTER_NULL_POINTER;
    void** rdc = POINTER_NULL_POINTER;
    void** rds = POINTER_NULL_POINTER;

    // get the operand 1
    get_real_compound_element_by_name( p0, p1,
        (void*) ADD_OPERAND_1_NAME_ABSTRACTION,
        (void*) ADD_OPERAND_1_NAME_ABSTRACTION_COUNT,
        (void*) &op1a, (void*) &op1ac, (void*) &op1as,
        (void*) &op1m, (void*) &op1mc, (void*) &op1ms,
        (void*) &op1d, (void*) &op1dc, (void*) &op1ds,
        p2, p3 );

    // get the operand 2
    get_real_compound_element_by_name( p0, p1,
        (void*) ADD_OPERAND_2_NAME_ABSTRACTION,
        (void*) ADD_OPERAND_2_NAME_ABSTRACTION_COUNT,
        (void*) &op2a, (void*) &op2ac, (void*) &op2as,
        (void*) &op2m, (void*) &op2mc, (void*) &op2ms,
        (void*) &op2d, (void*) &op2dc, (void*) &op2ds,
        p2, p3 );

    // get the result
    get_real_compound_element_by_name( p0, p1,
        (void*) ADD_RESULT_NAME_ABSTRACTION,
        (void*) ADD_RESULT_NAME_ABSTRACTION_COUNT,
        (void*) &ra, (void*) &rac, (void*) &ras,
        (void*) &rm, (void*) &rmc, (void*) &rms,
        (void*) &rd, (void*) &rdc, (void*) &rds,
        p2, p3 );

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

        int r1 = 0;
        int r2 = 0;
        int r3 = 0;
        //check the abstracton from operand_1 and operand_2
        //the abstrcation msut be the same
        compare_arrays( *op1a, *op1ac,
                        (void*) INTEGER_ABSTRACTION,
                        (void*) INTEGER_ABSTRACTION_COUNT,
                        (void*) &r1, (void*) CHARACTER_ARRAY);
        compare_arrays( *op2a, *op2ac,
                        (void*) INTEGER_ABSTRACTION,
                        (void*) INTEGER_ABSTRACTION_COUNT,
                        (void*) &r2, (void*) CHARACTER_ARRAY);
        compare_arrays( *ra, *rac,
                        (void*) INTEGER_ABSTRACTION,
                        (void*) INTEGER_ABSTRACTION_COUNT,
                        (void*) &r3, (void*) CHARACTER_ARRAY);

        if ( (r1==1) && (r2==1) && (r3==1) ) {

            add_integers( *rm, *op1m, *op2m );
        }

        r1 = 0;
        r2 = 0;
        r3 = 0;
        //check the abstracton from operand_1 and operand_2
        //the abstrcation msut be the same
        compare_arrays( *op1a, *op1ac,
                        (void*) STRING_ABSTRACTION,
                        (void*) STRING_ABSTRACTION_COUNT,
                        (void*) &r1, (void*) CHARACTER_ARRAY);
        compare_arrays( *op2a, *op2ac,
                        (void*) STRING_ABSTRACTION,
                        (void*) STRING_ABSTRACTION_COUNT,
                        (void*) &r2, (void*) CHARACTER_ARRAY);
        compare_arrays( *ra, *rac,
                        (void*) STRING_ABSTRACTION,
                        (void*) STRING_ABSTRACTION_COUNT,
                        (void*) &r3, (void*) CHARACTER_ARRAY);

        if ( (r1==1) && (r2==1) && (r3==1) ) {

            add_strings( rm, *rmc, *rms,
                         *op1m, *op1mc, *op1ms,
                         *op2m, *op2mc, *op2ms );
        }

    }

/*??
            //
            // CAUTION! Only addition of primitives with equal type is allowed!
            //

            // The comparison result.
            int r = 0;

            // Compare summand 1- and sum abstraction.
            if (tsumac == ts1ac) {

                compare_array_elements((void*) &tsuma, (void*) &ts1a, (void*) &CHARACTER_ARRAY, (void*) &tsumac, (void*) &r);

                if (r == 1) {

                    r = 0;

                    // Compare summand 2- and sum abstraction.
                    if (tsumac == ts2ac) {

                        compare_array_elements((void*) &tsuma, (void*) &ts2a, (void*) &CHARACTER_ARRAY, (void*) &tsumac, (void*) &r);

                        if (r == 1) {

                            // Add summand 1 and summand 2 resulting in the sum.
                            add_primitives((void*) &ts1m, (void*) &ts2m, (void*) &tsumm, (void*) &tsuma, (void*) &tsumac);
                        }
                    }

                } else {

//??                    log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_HANDLE_CREATE_MODEL_SIGNAL_THE_SIGNAL_PARAMETERS_COUNT_DOES_NOT_MATCH_MESSAGE, (void*) &COULD_NOT_HANDLE_CREATE_MODEL_SIGNAL_THE_SIGNAL_PARAMETERS_COUNT_DOES_NOT_MATCH_MESSAGE_COUNT);
                }

            } else {

//??                log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_HANDLE_CREATE_MODEL_SIGNAL_THE_SIGNAL_PARAMETERS_COUNT_DOES_NOT_MATCH_MESSAGE, (void*) &COULD_NOT_HANDLE_CREATE_MODEL_SIGNAL_THE_SIGNAL_PARAMETERS_COUNT_DOES_NOT_MATCH_MESSAGE_COUNT);
            }

        } else {

//??            log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_HANDLE_CREATE_MODEL_SIGNAL_THE_SIGNAL_PARAMETERS_COUNT_DOES_NOT_MATCH_MESSAGE, (void*) &COULD_NOT_HANDLE_CREATE_MODEL_SIGNAL_THE_SIGNAL_PARAMETERS_COUNT_DOES_NOT_MATCH_MESSAGE_COUNT);
        }

    } else {

//??        log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_HANDLE_CREATE_MODEL_SIGNAL_THE_SIGNAL_PARAMETERS_COUNT_IS_NULL_MESSAGE, (void*) &COULD_NOT_HANDLE_CREATE_MODEL_SIGNAL_THE_SIGNAL_PARAMETERS_COUNT_IS_NULL_MESSAGE_COUNT);
    }
*/
}

/* ADD_SOURCE */
#endif
