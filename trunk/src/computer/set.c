/*
 * $RCSfile: set.c,v $
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

#ifndef SET_SOURCE
#define SET_SOURCE

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

void set_integer( void* source, int* source_count,
                  void* dest, int* dest_count ) {

    //the source and the destinatione are integers

    if ( (source != NULL_POINTER) &&
         (dest   != NULL_POINTER) ) {

        *((int*)dest) = *((int*)source);
    }
}


void set_string( void* source, int* source_count, int* source_size,
                 void** dest, int* dest_count, int* dest_size ) {

    //the source and the destinatione are arrays of string

    if ( (source != NULL_POINTER) &&
         (source_count != NULL_POINTER) &&
         (source_size != NULL_POINTER) &&
         (dest   != NULL_POINTER)  &&
         (dest_count   != NULL_POINTER)  &&
         (dest_size   != NULL_POINTER)  )
    {

        *dest_count=*source_count;
        *dest_size=*dest_count;

        resize_array( dest, dest_size, CHARACTER_ARRAY );

        set_array_elements( *dest, (void*) ZERO_NUMBER,
                            source, source_count,
                            (void*) CHARACTER_ARRAY);
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


    log_message_debug("operation set");

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

            set_string( *sm, *smc, *sms, dm, *dmc, *dms );
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
void set_property( const void* param, const int* param_count,
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


    log_message_debug("operation set_proerty.");

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

    // The destination property name abstraction.
    void** dpa = POINTER_NULL_POINTER;
    void** dpac = POINTER_NULL_POINTER;
    void** dpas = POINTER_NULL_POINTER;
    // The destination property model.
    void** dpm = POINTER_NULL_POINTER;
    void** dpmc = POINTER_NULL_POINTER;
    void** dpms = POINTER_NULL_POINTER;
    // The destination property details.
    void** dpd = POINTER_NULL_POINTER;
    void** dpdc = POINTER_NULL_POINTER;
    void** dpds = POINTER_NULL_POINTER;

    // The destination property name abstraction.
    void** pa = POINTER_NULL_POINTER;
    void** pac = POINTER_NULL_POINTER;
    void** pas = POINTER_NULL_POINTER;
    // The destination property model.
    void** pm = POINTER_NULL_POINTER;
    void** pmc = POINTER_NULL_POINTER;
    void** pms = POINTER_NULL_POINTER;
    // The destination property details.
    void** pd = POINTER_NULL_POINTER;
    void** pdc = POINTER_NULL_POINTER;
    void** pds = POINTER_NULL_POINTER;

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

    // Get destination property.
    get_real_compound_element_by_name( param, param_count,
        (void*) SET_DESTINATION_PROPERTY_NAME_ABSTRACTION,
        (void*) SET_DESTINATION_PROPERTY_NAME_ABSTRACTION_COUNT,
        (void*) &dpa, (void*) &dpac, (void*) &dpas,
        (void*) &dpm, (void*) &dpmc, (void*) &dpms,
        (void*) &dpd, (void*) &dpdc, (void*) &dpds,
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
        //check destination property
        && (dpa != POINTER_NULL_POINTER)
        && (dpac != POINTER_NULL_POINTER)
        && (dpas != POINTER_NULL_POINTER)
        && (dpm != POINTER_NULL_POINTER)
        && (dpmc != POINTER_NULL_POINTER)
        && (dpms != POINTER_NULL_POINTER)
        && (dpd != POINTER_NULL_POINTER)
        && (dpdc != POINTER_NULL_POINTER)
        && (dpds != POINTER_NULL_POINTER)
      )
    {

        //check the abstraction for the destination property
        //this must be a string
        int r = 0;

        compare_arrays( *dpa, *dpac,
                        (void*) STRING_ABSTRACTION,
                        (void*) STRING_ABSTRACTION_COUNT,
                        (void*) &r, (void*) CHARACTER_ARRAY);

        if ( r == 1 ) {

            //get the property from the destination
            get_compound_element_by_name( *dd, *ddc,
                (void*) *dpm, (void*) *dpmc,
                (void*) &pa, (void*) &pac, (void*) &pas,
                (void*) &pm, (void*) &pmc, (void*) &pms,
                (void*) &pd, (void*) &pdc, (void*) &pds );

            if (   (pa != POINTER_NULL_POINTER)
                && (pac != POINTER_NULL_POINTER)
                && (pas != POINTER_NULL_POINTER)
                && (pm != POINTER_NULL_POINTER)
                && (pmc != POINTER_NULL_POINTER)
                && (pms != POINTER_NULL_POINTER)
                && (pd != POINTER_NULL_POINTER)
                && (pdc != POINTER_NULL_POINTER)
                && (pds != POINTER_NULL_POINTER) )
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
                compare_arrays( *pa, *pac,
                                (void*) INTEGER_ABSTRACTION,
                                (void*) INTEGER_ABSTRACTION_COUNT,
                                (void*) &r2, (void*) CHARACTER_ARRAY);

                if ( (r1 == 1) && (r2 == 1) ) {

                    set_integer( *sm, *smc, *pm, *pmc);
                }


                //set for string
                r1 = 0;
                r2 = 0;

                compare_arrays( *sa, *sac,
                                (void*) STRING_ABSTRACTION,
                                (void*) STRING_ABSTRACTION_COUNT,
                                (void*) &r1, (void*) CHARACTER_ARRAY);
                compare_arrays( *pa, *pac,
                                (void*) STRING_ABSTRACTION,
                                (void*) STRING_ABSTRACTION_COUNT,
                                (void*) &r2, (void*) CHARACTER_ARRAY);

                if ( (r1 == 1) && (r2 == 1) ) {

                    set_string( *sm, *smc, *sms, pm, *pmc, *pms );
                }

            } //check null pointer property

        } //string abstraction for destination property

    }
}


/* SET_SOURCE */
#endif


