/*
 * $RCSfile: count.c,v $
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
 * @version $Revision: 1.1 $ $Date: 2005-06-04 22:35:10 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
 
#ifndef COUNT_SOURCE
#define COUNT_SOURCE

#include "../array/array.c"
#include "../creator/creator.c"
#include "../communicator/communicator.c"
#include "../global/abstraction_constants.c"
#include "../global/log_constants.c"
#include "../global/name_constants.c"
#include "../logger/logger.c"
#include "../parser/parser.c"
#include "../translator/translator.c"
#include "../test/test.c"

/* 
 * @param param the parameters
 * @param param_count the parameters count
 * @param internal
*/ 
void count_part( const void* param, const int* param_count, 
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
    
    
    log_message_debug("operation count_part");

    // The basisname abstraction.
    void** bna = POINTER_NULL_POINTER;
    void** bnac = POINTER_NULL_POINTER;
    void** bnas = POINTER_NULL_POINTER;
    // The basisname model.
    void** bnm = POINTER_NULL_POINTER;
    void** bnmc = POINTER_NULL_POINTER;
    void** bnms = POINTER_NULL_POINTER;
    // The basisname details.
    void** bnd = POINTER_NULL_POINTER;
    void** bndc = POINTER_NULL_POINTER;
    void** bnds = POINTER_NULL_POINTER;

    // The index abstraction.
    void** mdla = POINTER_NULL_POINTER;
    void** mdlac = POINTER_NULL_POINTER;
    void** mdlas = POINTER_NULL_POINTER;
    // The index model.
    void** mdlm = POINTER_NULL_POINTER;
    void** mdlmc = POINTER_NULL_POINTER;
    void** mdlms = POINTER_NULL_POINTER;
    // The index details.
    void** mdld = POINTER_NULL_POINTER;
    void** mdldc = POINTER_NULL_POINTER;
    void** mdlds = POINTER_NULL_POINTER;

    // The result abstraction.
    void** resa = POINTER_NULL_POINTER;
    void** resac = POINTER_NULL_POINTER;
    void** resas = POINTER_NULL_POINTER;
    // The result mxodel.
    void** resm = POINTER_NULL_POINTER;
    void** resmc = POINTER_NULL_POINTER;
    void** resms = POINTER_NULL_POINTER;
    // The result details.
    void** resd = POINTER_NULL_POINTER;
    void** resdc = POINTER_NULL_POINTER;
    void** resds = POINTER_NULL_POINTER;

    // get the basisname
    get_real_compound_element_by_name( param, param_count,
        (void*) COUNT_PART_BASISNAME_NAME_ABSTRACTION, 
        (void*) COUNT_PART_BASISNAME_NAME_ABSTRACTION_COUNT,
        (void*) &bna, (void*) &bnac, (void*) &bnas,
        (void*) &bnm, (void*) &bnmc, (void*) &bnms,
        (void*) &bnd, (void*) &bndc, (void*) &bnds,
        *km, *kmc );

    // get the model     
    get_real_compound_element_by_name( param, param_count,
        (void*) COUNT_PART_MODEL_NAME_ABSTRACTION, 
        (void*) COUNT_PART_MODEL_NAME_ABSTRACTION_COUNT,
        (void*) &mdla, (void*) &mdlac, (void*) &mdlas,
        (void*) &mdlm, (void*) &mdlmc, (void*) &mdlms,
        (void*) &mdld, (void*) &mdldc, (void*) &mdlds,
        *km, *kmc );

    // get the result
    get_real_compound_element_by_name( param, param_count,
        (void*) COUNT_PART_RESULT_NAME_ABSTRACTION, 
        (void*) COUNT_PART_RESULT_NAME_ABSTRACTION_COUNT,
        (void*) &resa, (void*) &resac, (void*) &resas,
        (void*) &resm, (void*) &resmc, (void*) &resms,
        (void*) &resd, (void*) &resdc, (void*) &resds,
        *km, *kmc );

    // Check basisname.
    if (   (bna != POINTER_NULL_POINTER)
        && (bnac != POINTER_NULL_POINTER)
        && (bnas != POINTER_NULL_POINTER)
        && (bnm != POINTER_NULL_POINTER)
        && (bnmc != POINTER_NULL_POINTER)
        && (bnms != POINTER_NULL_POINTER)
        && (bnd != POINTER_NULL_POINTER)
        && (bndc != POINTER_NULL_POINTER)
        && (bnds != POINTER_NULL_POINTER)
        // Check index.
        && (mdla != POINTER_NULL_POINTER)
        && (mdlac != POINTER_NULL_POINTER)
        && (mdlas != POINTER_NULL_POINTER)
        && (mdlm != POINTER_NULL_POINTER)
        && (mdlmc != POINTER_NULL_POINTER)
        && (mdlms != POINTER_NULL_POINTER)
        && (mdld != POINTER_NULL_POINTER)
        && (mdldc != POINTER_NULL_POINTER)
        && (mdlds != POINTER_NULL_POINTER) 
        // Check result.
        && (resa != POINTER_NULL_POINTER)
        && (resac != POINTER_NULL_POINTER)
        && (resas != POINTER_NULL_POINTER)
        && (resm != POINTER_NULL_POINTER)
        && (resmc != POINTER_NULL_POINTER)
        && (resms != POINTER_NULL_POINTER)
        && (resd != POINTER_NULL_POINTER)
        && (resdc != POINTER_NULL_POINTER)
        && (resds != POINTER_NULL_POINTER) )
    {

        //check the abstraction for the operation element
        int comp_res1 = 0;
        int comp_res2 = 0;
        int comp_res3 = 0;
        
        compare_arrays( *bna, *bnac, 
                        (void*) STRING_ABSTRACTION, 
                        (void*) STRING_ABSTRACTION_COUNT,
                        (void*) &comp_res1, (void*) CHARACTER_ARRAY);
        compare_arrays( *mdla, *mdlac, 
                        (void*) COMPOUND_ABSTRACTION, 
                        (void*) COMPOUND_ABSTRACTION_COUNT,
                        (void*) &comp_res2, (void*) CHARACTER_ARRAY);
        compare_arrays( *mdla, *mdlac, 
                        (void*) CYBOL_ABSTRACTION, 
                        (void*) CYBOL_ABSTRACTION_COUNT,
                        (void*) &comp_res2, (void*) CHARACTER_ARRAY);
        compare_arrays( *resa, *resac, 
                        (void*) INTEGER_ABSTRACTION, 
                        (void*) INTEGER_ABSTRACTION_COUNT,
                        (void*) &comp_res3, (void*) CHARACTER_ARRAY);
                        
        if ( (comp_res1 == 1) && (comp_res2 == 1) && (comp_res3 == 1) ) {

            //Vorgehen, 
            //-alle Elemente des Compound durchgehen
            //-Namen testen basisname_#
            //-Z?lvariable hochz?hlen
            //am Ende die Z?hlvariable ins result schreiben

            //compound element 
            // The compund element name.
            void** cen = POINTER_NULL_POINTER;
            void** cenc = POINTER_NULL_POINTER;
            void** cens = POINTER_NULL_POINTER;
            
            //init the counter
            int* list_counter = (int*)*resm;
            *list_counter=0;
            
            // Create compare string.
            char* compstring = NULL_POINTER;
            int compstring_count = *((int*)*bnmc) + *LIST_SEPARATOR_COUNT;
            
            create_array( (void*) &compstring, (void*) &compstring_count, 
                          (void*) CHARACTER_ARRAY);

            // Set the compare string
            //this is the basisname and the list separat 
            set_array_elements( compstring, (void*) ZERO_NUMBER, 
                                *bnm, *bnmc,  (void*) CHARACTER_ARRAY);
            set_array_elements( compstring, *bnmc, 
                                LIST_SEPARATOR, LIST_SEPARATOR_COUNT,  
                                (void*) CHARACTER_ARRAY);
                                
            int compare_result = 0;                    
            int loop_counter = 0;
            while (1) {
               
                if ( loop_counter >= *((int*)*mdlmc ) ) {
                    break;    
                }
               
                get_compound_element_name_by_index(
                    *mdlm, *mdlmc, 
                    &loop_counter, 
                    &cen, &cenc, &cens );

                if (   (cen != POINTER_NULL_POINTER)
                    && (cenc != POINTER_NULL_POINTER)
                    && (cens != POINTER_NULL_POINTER) )
                {
                    
                    if (   (*cen != NULL_POINTER)
                        && (*cenc != NULL_POINTER)
                        && (*cens != NULL_POINTER) )
                    {

                        //check the count for the compare arrays
                        // the compound element must greater als the compare string
                        if ( *((int*)*cenc) > compstring_count ) {
                             
                            //
                            compare_result = 0;
                            compare_arrays( compstring, &compstring_count,
                                            *cen, &compstring_count,
                                            &compare_result,
                                            CHARACTER_ARRAY );
                                           
                            //if teh begiining of the two arrays ident, then 
                            //the compound element is a part of the list
                            if ( compare_result == 1 ) {
                             
                                *list_counter = *list_counter+1;
                            }
                        }
                    }
                }
                
                //
                loop_counter++;
            }
        
            // destroy compare string.
            destroy_array( (void*) &compstring, (void*) &compstring_count, 
                          (void*) CHARACTER_ARRAY);
        }
        else {
         
            log_message_debug("operation count_part: the abstraction for the operands are not correct");   
        }
        
    }
    
}           
 
/* COUNT_SOURCE */
#endif


