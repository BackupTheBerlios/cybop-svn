/*
 * $RCSfile: build.c,v $
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
 * @version $Revision: 1.12 $ $Date: 2005-08-11 22:33:45 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef BUILD_SOURCE
#define BUILD_SOURCE

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
 * Builds a list name.
 *
 * @param p0 the parameters
 * @param p1 the parameters count
 * @param p2 the knowledge memory
 * @param p3 the knowledge memory count
 * @param p4 the knowledge memory size
 */
void build_listname(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message_debug("Build list name.");

    // The basisname abstraction.
    void** bna = &NULL_POINTER;
    void** bnac = &NULL_POINTER;
    void** bnas = &NULL_POINTER;
    // The basisname model.
    void** bnm = &NULL_POINTER;
    void** bnmc = &NULL_POINTER;
    void** bnms = &NULL_POINTER;
    // The basisname details.
    void** bnd = &NULL_POINTER;
    void** bndc = &NULL_POINTER;
    void** bnds = &NULL_POINTER;

    // The index abstraction.
    void** idxa = &NULL_POINTER;
    void** idxac = &NULL_POINTER;
    void** idxas = &NULL_POINTER;
    // The index model.
    void** idxm = &NULL_POINTER;
    void** idxmc = &NULL_POINTER;
    void** idxms = &NULL_POINTER;
    // The index details.
    void** idxd = &NULL_POINTER;
    void** idxdc = &NULL_POINTER;
    void** idxds = &NULL_POINTER;

    // The result abstraction.
    void** resa = &NULL_POINTER;
    void** resac = &NULL_POINTER;
    void** resas = &NULL_POINTER;
    // The result mxodel.
    void** resm = &NULL_POINTER;
    void** resmc = &NULL_POINTER;
    void** resms = &NULL_POINTER;
    // The result details.
    void** resd = &NULL_POINTER;
    void** resdc = &NULL_POINTER;
    void** resds = &NULL_POINTER;

    // get the basisname
    get_real_compound_element_by_name(p0, p1,
        (void*) BASE_NAME_NAME,
        (void*) BASE_NAME_NAME_COUNT,
        (void*) &bna, (void*) &bnac, (void*) &bnas,
        (void*) &bnm, (void*) &bnmc, (void*) &bnms,
        (void*) &bnd, (void*) &bndc, (void*) &bnds,
        p2, p3);

    // get the index
    get_real_compound_element_by_name(p0, p1,
        (void*) INDEX_NAME_NAME,
        (void*) INDEX_NAME_NAME_COUNT,
        (void*) &idxa, (void*) &idxac, (void*) &idxas,
        (void*) &idxm, (void*) &idxmc, (void*) &idxms,
        (void*) &idxd, (void*) &idxdc, (void*) &idxds,
        p2, p3);

    // get the result
    get_real_compound_element_by_name(p0, p1,
        (void*) COMPOSED_NAME_NAME,
        (void*) COMPOSED_NAME_NAME_COUNT,
        (void*) &resa, (void*) &resac, (void*) &resas,
        (void*) &resm, (void*) &resmc, (void*) &resms,
        (void*) &resd, (void*) &resdc, (void*) &resds,
        p2, p3);

    // Check basisname.
    if ((*bna != NULL_POINTER)
        && (*bnac != NULL_POINTER)
        && (*bnas != NULL_POINTER)
        && (*bnm != NULL_POINTER)
        && (*bnmc != NULL_POINTER)
        && (*bnms != NULL_POINTER)
        && (*bnd != NULL_POINTER)
        && (*bndc != NULL_POINTER)
        && (*bnds != NULL_POINTER)
        // Check index.
        && (*idxa != NULL_POINTER)
        && (*idxac != NULL_POINTER)
        && (*idxas != NULL_POINTER)
        && (*idxm != NULL_POINTER)
        && (*idxmc != NULL_POINTER)
        && (*idxms != NULL_POINTER)
        && (*idxd != NULL_POINTER)
        && (*idxdc != NULL_POINTER)
        && (*idxds != NULL_POINTER)
        // Check result.
        && (*resa != NULL_POINTER)
        && (*resac != NULL_POINTER)
        && (*resas != NULL_POINTER)
        && (*resm != NULL_POINTER)
        && (*resmc != NULL_POINTER)
        && (*resms != NULL_POINTER)
        && (*resd != NULL_POINTER)
        && (*resdc != NULL_POINTER)
        && (*resds != NULL_POINTER)) {

        //check the abstraction for the operation element
        int comp_res1 = 0;
        int comp_res2 = 0;
        int comp_res3 = 0;

        compare_arrays(*bna, *bnac, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT, (void*) &comp_res1, (void*) CHARACTER_ARRAY);
        compare_arrays(*idxa, *idxac, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT, (void*) &comp_res2, (void*) CHARACTER_ARRAY);
        compare_arrays(*resa, *resac, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT, (void*) &comp_res3, (void*) CHARACTER_ARRAY);

        if ((comp_res1 == 1) && (comp_res2 == 1) && (comp_res3 == 1)) {

            // changing the for the index

            // Create compare string.
            char* int_string = NULL_POINTER;
            // todo Konstante noch definieren
            int int_string_count = 0;
            int int_string_size = 10;

            allocate_array((void*) &int_string, (void*) &int_string_size, (void*) CHARACTER_ARRAY);

            int_string_count = snprintf(int_string, int_string_size, "%i", *((int*) *idxm));

            // destination size
            *(int*)*resms = *((int*) *bnmc) + *LIST_SEPARATOR_COUNT + int_string_count;
            *(int*)*resmc = *((int*) *bnmc) + *LIST_SEPARATOR_COUNT + int_string_count;

            // Reallocate result array.
            reallocate_array(resm, *resms, *resms, CHARACTER_ARRAY);

            // set the result array
            set_array_elements(*resm, (void*) NUMBER_0_INTEGER, *bnm, *bnmc, (void*) CHARACTER_ARRAY);
            set_array_elements(*resm, *bnmc, LIST_SEPARATOR, LIST_SEPARATOR_COUNT, (void*) CHARACTER_ARRAY);

            int temp_index = *((int*) *bnmc) + *LIST_SEPARATOR_COUNT;

            set_array_elements(*resm, &temp_index, int_string, &int_string_count, (void*) CHARACTER_ARRAY);

            // Destroy int_string array.
            deallocate_array((void*) &int_string, (void*) &int_string_size, (void*) CHARACTER_ARRAY);

        } else {

            log_message_debug("Could not build list name. The abstraction for the operands is not correct.");
        }
    }
}

/* BUILD_SOURCE */
#endif
