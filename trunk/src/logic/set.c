/*
 * $RCSfile: set.c,v $
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
 * this handel a loop
 *
 * @version $Revision: 1.1 $ $Date: 2005-03-02 07:19:05 $ $Author: rholzmueller $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
 
#ifndef SET_SOURCE
#define SET_SOURCE

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


void set_integer( void* source, int* source_count,
                  void* dest, int* dest_count ) {
 
    //the source and the destinatione are integers

    if ( (source != NULL_POINTER) &&
         (dest   != NULL_POINTER) ) {
  
        *((int*)dest) = *((int*)source);
    }
}


void set_string( void* source, int* source_count,
                 void* dest, int* dest_count ) {
 
    //the source and the destinatione are arrays of string

    if ( (source != NULL_POINTER) &&
         (dest   != NULL_POINTER) ) {
  
        //???
    }
}

/* 
 * @param param the parameters
 * @param param_count the parameters count
 * @param proiority 
 * @param signal_id 
 * @param internal
*/ 
void set( const void* param, const int* param_count, 
          const void* priority, const void* signal_id, 
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
    
    
    log_message_debug("Create part.");

    // The source name abstraction.
    void** sa = POINTER_NULL_POINTER;
    void** sac = POINTER_NULL_POINTER;
    void** sas = POINTER_NULL_POINTER;
    // The source model.
    void** sm = POINTER_NULL_POINTER;
    void** smc = POINTER_NULL_POINTER;
    void** sms = POINTER_NULL_POINTER;
    // The source details.
    void** sd = POINTER_NULL_POINTER;
    void** sdc = POINTER_NULL_POINTER;
    void** sds = POINTER_NULL_POINTER;

    // The destination abstraction.
    void** da = POINTER_NULL_POINTER;
    void** dac = POINTER_NULL_POINTER;
    void** das = POINTER_NULL_POINTER;
    // The destination model.
    void** dm = POINTER_NULL_POINTER;
    void** dmc = POINTER_NULL_POINTER;
    void** dms = POINTER_NULL_POINTER;
    // The destination details.
    void** dd = POINTER_NULL_POINTER;
    void** ddc = POINTER_NULL_POINTER;
    void** dds = POINTER_NULL_POINTER;


    // Get source.
    get_real_compound_element_by_name( param, param_count,
        (void*) SET_SOURCE_NAME_ABSTRACTION, 
        (void*) SET_SOURCE_NAME_ABSTRACTION_COUNT,
        (void*) &sa, (void*) &sac, (void*) &sas,
        (void*) &sm, (void*) &smc, (void*) &sms,
        (void*) &sd, (void*) &sdc, (void*) &sds,
        *km, *kmc );

    // Get destination.
    get_real_compound_element_by_name( param, param_count,
        (void*) SET_DESTINATION_NAME_ABSTRACTION, 
        (void*) SET_DESTINATION_NAME_ABSTRACTION_COUNT,
        (void*) &da, (void*) &dac, (void*) &das,
        (void*) &dm, (void*) &dmc, (void*) &dms,
        (void*) &dd, (void*) &ddc, (void*) &dds,
        *km, *kmc );
        
    // Check source.
    if (   (sa != POINTER_NULL_POINTER)
        && (sac != POINTER_NULL_POINTER)
        && (sas != POINTER_NULL_POINTER)
        && (sm != POINTER_NULL_POINTER)
        && (smc != POINTER_NULL_POINTER)
        && (sms != POINTER_NULL_POINTER)
        && (sd != POINTER_NULL_POINTER)
        && (sdc != POINTER_NULL_POINTER)
        && (sds != POINTER_NULL_POINTER)
        // Check destination.
        && (da != POINTER_NULL_POINTER)
        && (dac != POINTER_NULL_POINTER)
        && (das != POINTER_NULL_POINTER)
        && (dm != POINTER_NULL_POINTER)
        && (dmc != POINTER_NULL_POINTER)
        && (dms != POINTER_NULL_POINTER)
        && (dd != POINTER_NULL_POINTER)
        && (ddc != POINTER_NULL_POINTER)
        && (dds != POINTER_NULL_POINTER)
      )
    {
     
        int r1 = 0;
        int r2 = 0;
     
        //set for integer
        r1 = 0;
        r2 = 0;
        
        compare_arrays( *sa, *sac,
                        (void*) INTEGER_ABSTRACTION, 
                        (void*) INTEGER_ABSTRACTION_COUNT,
                        (void*) &r1, (void*) CHARACTER_ARRAY);
        compare_arrays( *da, *dac,
                        (void*) INTEGER_ABSTRACTION, 
                        (void*) INTEGER_ABSTRACTION_COUNT,
                        (void*) &r2, (void*) CHARACTER_ARRAY);
        
        if ( (r1 == 1) && (r2 == 1) ) {
           
            set_integer( *sm, *smc, *dm, *dmc);
        }
        
        
        //set for string
        r1 = 0;
        r2 = 0;
        
        compare_arrays( *sa, *sac,
                        (void*) STRING_ABSTRACTION, 
                        (void*) STRING_ABSTRACTION_COUNT,
                        (void*) &r1, (void*) CHARACTER_ARRAY);
        compare_arrays( *da, *dac,
                        (void*) STRING_ABSTRACTION, 
                        (void*) STRING_ABSTRACTION_COUNT,
                        (void*) &r2, (void*) CHARACTER_ARRAY);
        
        if ( (r1 == 1) && (r2 == 1) ) {
           
            set_string( *sm, *smc, *dm, *dmc);
        }
        
    }
}           
 
/* SET_SOURCE */
#endif


