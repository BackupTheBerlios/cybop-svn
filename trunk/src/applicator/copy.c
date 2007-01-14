/*
 * $RCSfile: copy.c,v $
 *
 * Copyright (c) 1999-2007. Christian Heller and the CYBOP developers.
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
 * @version $Revision: 1.20 $ $Date: 2007-01-14 22:06:47 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef COPY_SOURCE
#define COPY_SOURCE

#include "../applicator/copy/copy_character_vector.c"
#include "../applicator/copy/copy_integer_vector.c"
#include "../globals/constants/abstraction_constants.c"
#include "../globals/constants/log_constants.c"
#include "../globals/constants/name_constants.c"
#include "../globals/logger/logger.c"
#include "../memoriser/accessor/compound_accessor.c"
#include "../memoriser/array.c"

/**
 * Copies a primitive model.
 *
 * @param p0 the parameters
 * @param p1 the parameters count
 * @param p2 the knowledge memory
 * @param p3 the knowledge memory count
 * @param p4 the knowledge memory size
 */
void copy(void* p0, int* p1, void* p2, void* p3, void* p4) {

    log_message_debug("Copy primitive model.");

    // The source abstraction.
    void** sa = &NULL_POINTER;
    void** sac = &NULL_POINTER;
    void** sas = &NULL_POINTER;
    // The source model.
    void** sm = &NULL_POINTER;
    void** smc = &NULL_POINTER;
    void** sms = &NULL_POINTER;
    // The source details.
    void** sd = &NULL_POINTER;
    void** sdc = &NULL_POINTER;
    void** sds = &NULL_POINTER;

    // The destination abstraction.
    void** da = &NULL_POINTER;
    void** dac = &NULL_POINTER;
    void** das = &NULL_POINTER;
    // The destination model.
    void** dm = &NULL_POINTER;
    void** dmc = &NULL_POINTER;
    void** dms = &NULL_POINTER;
    // The destination details.
    void** dd = &NULL_POINTER;
    void** ddc = &NULL_POINTER;
    void** dds = &NULL_POINTER;

    // The abstraction abstraction.
    void** aa = &NULL_POINTER;
    void** aac = &NULL_POINTER;
    void** aas = &NULL_POINTER;
    // The abstraction model.
    void** am = &NULL_POINTER;
    void** amc = &NULL_POINTER;
    void** ams = &NULL_POINTER;
    // The abstraction details.
    void** ad = &NULL_POINTER;
    void** adc = &NULL_POINTER;
    void** ads = &NULL_POINTER;

    // Get source.
    get_universal_compound_element_by_name(p0, p1,
        (void*) COPY_SOURCE_NAME, (void*) COPY_SOURCE_NAME_COUNT,
        (void*) &sa, (void*) &sac, (void*) &sas,
        (void*) &sm, (void*) &smc, (void*) &sms,
        (void*) &sd, (void*) &sdc, (void*) &sds,
        p2, p3);

    // Get destination.
    get_universal_compound_element_by_name(p0, p1,
        (void*) COPY_DESTINATION_NAME, (void*) COPY_DESTINATION_NAME_COUNT,
        (void*) &da, (void*) &dac, (void*) &das,
        (void*) &dm, (void*) &dmc, (void*) &dms,
        (void*) &dd, (void*) &ddc, (void*) &dds,
        p2, p3);

    // Get abstraction.
    get_universal_compound_element_by_name(p0, p1,
        (void*) COPY_ABSTRACTION_NAME, (void*) COPY_ABSTRACTION_NAME_COUNT,
        (void*) &aa, (void*) &aac, (void*) &aas,
        (void*) &am, (void*) &amc, (void*) &ams,
        (void*) &ad, (void*) &adc, (void*) &ads,
        p2, p3);

    // The comparison result.
    int r = 0;

    if (r == 0) {

        compare_arrays(*am, *amc, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            copy_integer_vector(dm, *dmc, *dms, *sm, *smc);
        }
    }

    if (r == 0) {

        compare_arrays(*am, *amc, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            copy_character_vector(dm, *dmc, *dms, *sm, *smc);
        }
    }
}

/* COPY_SOURCE */
#endif
