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
 * @version $Revision: 1.3 $ $Date: 2005-03-30 14:15:42 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
 
#ifndef LOOP_SOURCE
#define LOOP_SOURCE

#include "../array/array.c"
#include "../creator/creator.c"
#include "../cyboi/signal_handler.c"
#include "../communicator/communicator.c"
#include "../global/abstraction_constants.c"
#include "../global/log_constants.c"
#include "../global/name_constants.c"
#include "../logger/logger.c"
#include "../parser/parser.c"
#include "../translator/translator.c"
#include "../test/test.c"

void handle_signal(const void* p0, const void* p1, const void* p2, const void* p3,
    const void* p4, const void* p5, const void* p6, const void* p7, void* p8, void* p9, void* p10);

/* 
 * @param param the parameters
 * @param param_count the parameters count
 * @param proiority 
 * @param signal_id 
 * @param internal
*/ 
void loop( const void* param, const int* param_count, 
           const void* priority, const void* signal_id, void* shutdownflag,
           void* internal )
{
    //Vorgehen
    //alle paramater ausfl?sen
    //Schleife von bis durchlaufen
    //signal virtuell erzeugen
    //und in der Schleifen abarbeiten
    //nicht signal in signal memeory einf?gen, da eventuell
    //diese Operation vor den anderen ausgef?hrt werden m?ssen
    
    // The knowledge memory.
    void** km = POINTER_NULL_POINTER;
    void** kmc = POINTER_NULL_POINTER;
    void** kms = POINTER_NULL_POINTER;

    // Get knowledge memory.
    get_array_elements(internal, (void*) KNOWLEDGE_MEMORY_INTERNAL, (void*) &km, (void*) POINTER_ARRAY);
    get_array_elements(internal, (void*) KNOWLEDGE_MEMORY_COUNT_INTERNAL, (void*) &kmc, (void*) POINTER_ARRAY);
    get_array_elements(internal, (void*) KNOWLEDGE_MEMORY_SIZE_INTERNAL, (void*) &kms, (void*) POINTER_ARRAY);
    
    
    log_message_debug("operation loop");

    // The breakflag abstraction.
    void** bfa = POINTER_NULL_POINTER;
    void** bfac = POINTER_NULL_POINTER;
    void** bfas = POINTER_NULL_POINTER;
    // The breakflag model.
    void** bfm = POINTER_NULL_POINTER;
    void** bfmc = POINTER_NULL_POINTER;
    void** bfms = POINTER_NULL_POINTER;
    // The breakflag details.
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

    // get the breakflag     
    get_real_compound_element_by_name( param, param_count,
        (void*) LOOP_BREAKFLAG_NAME_ABSTRACTION, 
        (void*) LOOP_BREAKFLAG_NAME_ABSTRACTION_COUNT,
        (void*) &bfa, (void*) &bfac, (void*) &bfas,
        (void*) &bfm, (void*) &bfmc, (void*) &bfms,
        (void*) &bfd, (void*) &bfdc, (void*) &bfds,
        *km, *kmc );

    // get the model     
    get_real_compound_element_by_name( param, param_count,
        (void*) LOOP_MODEL_NAME_ABSTRACTION, 
        (void*) LOOP_MODEL_NAME_ABSTRACTION_COUNT,
        (void*) &ma, (void*) &mac, (void*) &mas,
        (void*) &mm, (void*) &mmc, (void*) &mms,
        (void*) &md, (void*) &mdc, (void*) &mds,
        *km, *kmc );

    // Check breakflag.
    if (   (bfa != POINTER_NULL_POINTER)
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
        && (mds != POINTER_NULL_POINTER) )
    {
        int r = 0;
        
        int direct_execution_flag = 1;
        
        compare_arrays( *bfa, *bfac, 
                        (void*) BOOLEAN_ABSTRACTION, 
                        (void*) BOOLEAN_ABSTRACTION_COUNT,
                        (void*) &r, (void*) CHARACTER_ARRAY);
        
        if (r==1) {

            while (1) {

                //chek, is then value of the brakflag false
                void* bf_dest = NULL_POINTER;
                get_array_elements( *bfm, (void*) INTEGER_VALUE_INDEX, 
                                    (void*) &bf_dest,
                                    (void*) INTEGER_ARRAY);
                r = 0;
                compare_arrays( bf_dest, INTEGER_COUNT,
                                (void*) ZERO_NUMBER, (void*) ONE_NUMBER, 
                                &r, (void*) INTEGER_ARRAY );
                                
                if (r ==1) {
                 
                    //the brakflag is false
                    //so can work the model
                    handle_signal( *ma, *mac, *mm, *mmc, *md, *mdc, 
                                   priority, signal_id, 
                                   shutdownflag, internal,
                                   (void*) &direct_execution_flag );
                }
                else {
                    //the loop ending
                    break;   
                }
            }
        }                        
    }
    
}           
 
/* LOOP_SOURCE */
#endif


