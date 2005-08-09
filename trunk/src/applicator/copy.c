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
 * @version $Revision: 1.7 $ $Date: 2005-08-09 13:04:25 $ $Author: christian $
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

        reallocate_array(dest, dest_size, dest_size, CHARACTER_ARRAY);
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
    void** sa = NULL_POINTER;
    void** sac = NULL_POINTER;
    void** sas = NULL_POINTER;
    // The source model.
    void** sm = NULL_POINTER;
    void** smc = NULL_POINTER;
    void** sms = NULL_POINTER;
    // The source details.
    void** sd = NULL_POINTER;
    void** sdc = NULL_POINTER;
    void** sds = NULL_POINTER;

    // The destination abstraction.
    void** da = NULL_POINTER;
    void** dac = NULL_POINTER;
    void** das = NULL_POINTER;
    // The destination model.
    void** dm = NULL_POINTER;
    void** dmc = NULL_POINTER;
    void** dms = NULL_POINTER;
    // The destination details.
    void** dd = NULL_POINTER;
    void** ddc = NULL_POINTER;
    void** dds = NULL_POINTER;

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
    if ((sa != NULL_POINTER)
        && (sac != NULL_POINTER)
        && (sas != NULL_POINTER)
        && (sm != NULL_POINTER)
        && (smc != NULL_POINTER)
        && (sms != NULL_POINTER)
        && (sd != NULL_POINTER)
        && (sdc != NULL_POINTER)
        && (sds != NULL_POINTER)
        // Check destination.
        && (da != NULL_POINTER)
        && (dac != NULL_POINTER)
        && (das != NULL_POINTER)
        && (dm != NULL_POINTER)
        && (dmc != NULL_POINTER)
        && (dms != NULL_POINTER)
        && (dd != NULL_POINTER)
        && (ddc != NULL_POINTER)
        && (dds != NULL_POINTER)) {

        int r1 = 0;
        int r2 = 0;

        //set for integer
        r1 = 0;
        r2 = 0;

        compare_arrays(*sa, *sac, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT, (void*) &r1, (void*) CHARACTER_ARRAY);
        compare_arrays(*da, *dac, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT, (void*) &r2, (void*) CHARACTER_ARRAY);

        if ((r1 == 1) && (r2 == 1)) {

            copy_integer(*sm, *smc, *dm, *dmc);
        }

        // Set for string.
        r1 = 0;
        r2 = 0;

        compare_arrays(*sa, *sac, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT, (void*) &r1, (void*) CHARACTER_ARRAY);
        compare_arrays(*da, *dac, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT, (void*) &r2, (void*) CHARACTER_ARRAY);

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
    void** sa = NULL_POINTER;
    void** sac = NULL_POINTER;
    void** sas = NULL_POINTER;
    // The source model.
    void** sm = NULL_POINTER;
    void** smc = NULL_POINTER;
    void** sms = NULL_POINTER;
    // The source details.
    void** sd = NULL_POINTER;
    void** sdc = NULL_POINTER;
    void** sds = NULL_POINTER;

    // The destination abstraction.
    void** da = NULL_POINTER;
    void** dac = NULL_POINTER;
    void** das = NULL_POINTER;
    // The destination model.
    void** dm = NULL_POINTER;
    void** dmc = NULL_POINTER;
    void** dms = NULL_POINTER;
    // The destination details.
    void** dd = NULL_POINTER;
    void** ddc = NULL_POINTER;
    void** dds = NULL_POINTER;

    // The destination property name abstraction.
    void** dpa = NULL_POINTER;
    void** dpac = NULL_POINTER;
    void** dpas = NULL_POINTER;
    // The destination property model.
    void** dpm = NULL_POINTER;
    void** dpmc = NULL_POINTER;
    void** dpms = NULL_POINTER;
    // The destination property details.
    void** dpd = NULL_POINTER;
    void** dpdc = NULL_POINTER;
    void** dpds = NULL_POINTER;

    // The destination property name abstraction.
    void** pa = NULL_POINTER;
    void** pac = NULL_POINTER;
    void** pas = NULL_POINTER;
    // The destination property model.
    void** pm = NULL_POINTER;
    void** pmc = NULL_POINTER;
    void** pms = NULL_POINTER;
    // The destination property details.
    void** pd = NULL_POINTER;
    void** pdc = NULL_POINTER;
    void** pds = NULL_POINTER;

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
    if ((sa != NULL_POINTER)
        && (sac != NULL_POINTER)
        && (sas != NULL_POINTER)
        && (sm != NULL_POINTER)
        && (smc != NULL_POINTER)
        && (sms != NULL_POINTER)
        && (sd != NULL_POINTER)
        && (sdc != NULL_POINTER)
        && (sds != NULL_POINTER)
        // Check destination.
        && (da != NULL_POINTER)
        && (dac != NULL_POINTER)
        && (das != NULL_POINTER)
        && (dm != NULL_POINTER)
        && (dmc != NULL_POINTER)
        && (dms != NULL_POINTER)
        && (dd != NULL_POINTER)
        && (ddc != NULL_POINTER)
        && (dds != NULL_POINTER)
        //check destination property
        && (dpa != NULL_POINTER)
        && (dpac != NULL_POINTER)
        && (dpas != NULL_POINTER)
        && (dpm != NULL_POINTER)
        && (dpmc != NULL_POINTER)
        && (dpms != NULL_POINTER)
        && (dpd != NULL_POINTER)
        && (dpdc != NULL_POINTER)
        && (dpds != NULL_POINTER)) {

        //check the abstraction for the destination property
        //this must be a string
        int r = 0;

        compare_arrays(*dpa, *dpac, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

            // Get the property from the destination
            get_compound_element_by_name(*dd, *ddc,
                (void*) *dpm, (void*) *dpmc,
                (void*) &pa, (void*) &pac, (void*) &pas,
                (void*) &pm, (void*) &pmc, (void*) &pms,
                (void*) &pd, (void*) &pdc, (void*) &pds);

            if ((pa != NULL_POINTER)
                && (pac != NULL_POINTER)
                && (pas != NULL_POINTER)
                && (pm != NULL_POINTER)
                && (pmc != NULL_POINTER)
                && (pms != NULL_POINTER)
                && (pd != NULL_POINTER)
                && (pdc != NULL_POINTER)
                && (pds != NULL_POINTER)) {

                int r1 = 0;
                int r2 = 0;

                //set for integer
                r1 = 0;
                r2 = 0;

                compare_arrays(*sa, *sac, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT, (void*) &r1, (void*) CHARACTER_ARRAY);
                compare_arrays(*pa, *pac, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT, (void*) &r2, (void*) CHARACTER_ARRAY);

                if ((r1 == 1) && (r2 == 1)) {

                    copy_integer(*sm, *smc, *pm, *pmc);
                }

                // Set for string.
                r1 = 0;
                r2 = 0;

                compare_arrays(*sa, *sac, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT, (void*) &r1, (void*) CHARACTER_ARRAY);
                compare_arrays(*pa, *pac, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT, (void*) &r2, (void*) CHARACTER_ARRAY);

                if ((r1 == 1) && (r2 == 1)) {

                    copy_string(*sm, *smc, *sms, pm, *pmc, *pms);
                }
            }
        }
    }
}

/* SET_SOURCE */
#endif
