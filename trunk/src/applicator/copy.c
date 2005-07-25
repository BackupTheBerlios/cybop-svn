/*
 * $RCSfile: copy.c,v $
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
 * @version $Revision: 1.4 $ $Date: 2005-07-25 21:01:01 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef SET_SOURCE
#define SET_SOURCE

#include "../globals/constants/abstraction_constants.c"
#include "../globals/constants/log_constants.c"
#include "../globals/constants/name_constants.c"
#include "../globals/logger/logger.c"
#include "../memoriser/array.c"
#include "../memoriser/communicator.c"
#include "../memoriser/converter.c"
#include "../memoriser/allocator.c"
#include "../memoriser/translator.c"

/**
 * Copies an integer model.
 *
 * @param
 */
void copy_integer(void* source, int* source_count, void* dest, int* dest_count) {

    //the source and the destinatione are integers

    if ((source != NULL_POINTER) && (dest != NULL_POINTER)) {

        *((int*) dest) = *((int*) source);
    }
}

/**
 * Copies a string model.
 *
 * @param
 */
void copy_string(void* source, int* source_count, int* source_size, void** dest, int* dest_count, int* dest_size) {

    // the source and the destinatione are arrays of string

    if ((source != NULL_POINTER) &&
        (source_count != NULL_POINTER) &&
        (source_size != NULL_POINTER) &&
        (dest   != NULL_POINTER)  &&
        (dest_count   != NULL_POINTER)  &&
        (dest_size   != NULL_POINTER)) {

        *dest_count = *source_count;
        *dest_size = *dest_count;

        resize_array(dest, dest_size, CHARACTER_ARRAY);
        set_array_elements(*dest, (void*) NUMBER_0_INTEGER, source, source_count, (void*) CHARACTER_ARRAY);
    }
}

/**
 * Copies a primitive model.
 *
 * @param param the parameters
 * @param param_count the parameters count
 * @param p2 the knowledge memory
 * @param p3 the knowledge memory count
 * @param p4 the knowledge memory size
 * @param proiority
 * @param signal_id
 */
void copy(void* param, int* param_count, void* p2, void* p3, void* p4, void* priority, void* signal_id) {

    log_message_debug("Copy primitive model.");

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
    get_real_compound_element_by_name(param, param_count,
        (void*) SOURCE_NAME,
        (void*) SOURCE_NAME_COUNT,
        (void*) &sa, (void*) &sac, (void*) &sas,
        (void*) &sm, (void*) &smc, (void*) &sms,
        (void*) &sd, (void*) &sdc, (void*) &sds,
        p2, p3);

    // Get destination.
    get_real_compound_element_by_name(param, param_count,
        (void*) DESTINATION_NAME,
        (void*) DESTINATION_NAME_COUNT,
        (void*) &da, (void*) &dac, (void*) &das,
        (void*) &dm, (void*) &dmc, (void*) &dms,
        (void*) &dd, (void*) &ddc, (void*) &dds,
        p2, p3);

    // Check source.
    if ((sa != POINTER_NULL_POINTER)
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
        && (dds != POINTER_NULL_POINTER)) {

        int r1 = 0;
        int r2 = 0;

        //set for integer
        r1 = 0;
        r2 = 0;

        compare_arrays(*sa, *sac, (void*) INTEGER_ABSTRACTION, (void*) INTEGER_ABSTRACTION_COUNT, (void*) &r1, (void*) CHARACTER_ARRAY);
        compare_arrays(*da, *dac, (void*) INTEGER_ABSTRACTION, (void*) INTEGER_ABSTRACTION_COUNT, (void*) &r2, (void*) CHARACTER_ARRAY);

        if ((r1 == 1) && (r2 == 1)) {

            copy_integer(*sm, *smc, *dm, *dmc);
        }

        // Set for string.
        r1 = 0;
        r2 = 0;

        compare_arrays(*sa, *sac, (void*) STRING_ABSTRACTION, (void*) STRING_ABSTRACTION_COUNT, (void*) &r1, (void*) CHARACTER_ARRAY);
        compare_arrays(*da, *dac, (void*) STRING_ABSTRACTION, (void*) STRING_ABSTRACTION_COUNT, (void*) &r2, (void*) CHARACTER_ARRAY);

        if ((r1 == 1) && (r2 == 1)) {

            copy_string(*sm, *smc, *sms, dm, *dmc, *dms);
        }
    }
}

/**
 * Copies a model property.
 *
 * @param param the parameters
 * @param param_count the parameters count
 * @param p2 the knowledge memory
 * @param p3 the knowledge memory count
 * @param p4 the knowledge memory size
 * @param proiority
 * @param signal_id
 */
void copy_property(void* param, int* param_count, void* p2, void* p3, void* p4, void* priority, void* signal_id) {

    log_message_debug("Copy property.");

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
    get_real_compound_element_by_name(param, param_count,
        (void*) SOURCE_NAME,
        (void*) SOURCE_NAME_COUNT,
        (void*) &sa, (void*) &sac, (void*) &sas,
        (void*) &sm, (void*) &smc, (void*) &sms,
        (void*) &sd, (void*) &sdc, (void*) &sds,
        p2, p3);

    // Get destination.
    get_real_compound_element_by_name(param, param_count,
        (void*) DESTINATION_NAME,
        (void*) DESTINATION_NAME_COUNT,
        (void*) &da, (void*) &dac, (void*) &das,
        (void*) &dm, (void*) &dmc, (void*) &dms,
        (void*) &dd, (void*) &ddc, (void*) &dds,
        p2, p3);

    // Get destination property.
    get_real_compound_element_by_name(param, param_count,
        (void*) DESTINATION_PROPERTY_NAME,
        (void*) DESTINATION_PROPERTY_NAME_COUNT,
        (void*) &dpa, (void*) &dpac, (void*) &dpas,
        (void*) &dpm, (void*) &dpmc, (void*) &dpms,
        (void*) &dpd, (void*) &dpdc, (void*) &dpds,
        p2, p3);

    // Check source.
    if ((sa != POINTER_NULL_POINTER)
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
        && (dpds != POINTER_NULL_POINTER)) {

        //check the abstraction for the destination property
        //this must be a string
        int r = 0;

        compare_arrays(*dpa, *dpac, (void*) STRING_ABSTRACTION, (void*) STRING_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

            // Get the property from the destination
            get_compound_element_by_name(*dd, *ddc,
                (void*) *dpm, (void*) *dpmc,
                (void*) &pa, (void*) &pac, (void*) &pas,
                (void*) &pm, (void*) &pmc, (void*) &pms,
                (void*) &pd, (void*) &pdc, (void*) &pds);

            if ((pa != POINTER_NULL_POINTER)
                && (pac != POINTER_NULL_POINTER)
                && (pas != POINTER_NULL_POINTER)
                && (pm != POINTER_NULL_POINTER)
                && (pmc != POINTER_NULL_POINTER)
                && (pms != POINTER_NULL_POINTER)
                && (pd != POINTER_NULL_POINTER)
                && (pdc != POINTER_NULL_POINTER)
                && (pds != POINTER_NULL_POINTER)) {

                int r1 = 0;
                int r2 = 0;

                //set for integer
                r1 = 0;
                r2 = 0;

                compare_arrays(*sa, *sac, (void*) INTEGER_ABSTRACTION, (void*) INTEGER_ABSTRACTION_COUNT, (void*) &r1, (void*) CHARACTER_ARRAY);
                compare_arrays(*pa, *pac, (void*) INTEGER_ABSTRACTION, (void*) INTEGER_ABSTRACTION_COUNT, (void*) &r2, (void*) CHARACTER_ARRAY);

                if ((r1 == 1) && (r2 == 1)) {

                    copy_integer(*sm, *smc, *pm, *pmc);
                }

                // Set for string.
                r1 = 0;
                r2 = 0;

                compare_arrays(*sa, *sac, (void*) STRING_ABSTRACTION, (void*) STRING_ABSTRACTION_COUNT, (void*) &r1, (void*) CHARACTER_ARRAY);
                compare_arrays(*pa, *pac, (void*) STRING_ABSTRACTION, (void*) STRING_ABSTRACTION_COUNT, (void*) &r2, (void*) CHARACTER_ARRAY);

                if ((r1 == 1) && (r2 == 1)) {

                    copy_string(*sm, *smc, *sms, pm, *pmc, *pms);
                }
            }
        }
    }
}

/* SET_SOURCE */
#endif
