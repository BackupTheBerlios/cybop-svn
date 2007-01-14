/*
 * $RCSfile: count.c,v $
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
 * @version $Revision: 1.17 $ $Date: 2007-01-14 22:06:47 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef COUNT_SOURCE
#define COUNT_SOURCE

#include "../globals/constants/abstraction_constants.c"
#include "../globals/constants/log_constants.c"
#include "../globals/constants/name_constants.c"
#include "../globals/logger/logger.c"
#include "../memoriser/accessor/compound_accessor.c"
#include "../memoriser/allocator.c"
#include "../memoriser/array.c"
#include "../memoriser/communicator.c"
#include "../memoriser/converter.c"
#include "../memoriser/translator.c"

/**
 * Counts the parts.
 *
 * @param p0 the parameters
 * @param p1 the parameters count
 * @param p2 the knowledge memory
 * @param p3 the knowledge memory count
 * @param p4 the knowledge memory size
 */
void count_parts(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message_debug("Count parts.");

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
    void** mdla = &NULL_POINTER;
    void** mdlac = &NULL_POINTER;
    void** mdlas = &NULL_POINTER;
    // The index model.
    void** mdlm = &NULL_POINTER;
    void** mdlmc = &NULL_POINTER;
    void** mdlms = &NULL_POINTER;
    // The index details.
    void** mdld = &NULL_POINTER;
    void** mdldc = &NULL_POINTER;
    void** mdlds = &NULL_POINTER;

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
    get_universal_compound_element_by_name(p0, p1,
        (void*) PART_NAME_NAME, (void*) PART_NAME_NAME_COUNT,
        (void*) &bna, (void*) &bnac, (void*) &bnas,
        (void*) &bnm, (void*) &bnmc, (void*) &bnms,
        (void*) &bnd, (void*) &bndc, (void*) &bnds,
        p2, p3);

    // get the model
    get_universal_compound_element_by_name(p0, p1,
        (void*) WHOLE_MODEL_NAME, (void*) WHOLE_MODEL_NAME_COUNT,
        (void*) &mdla, (void*) &mdlac, (void*) &mdlas,
        (void*) &mdlm, (void*) &mdlmc, (void*) &mdlms,
        (void*) &mdld, (void*) &mdldc, (void*) &mdlds,
        p2, p3);

    // get the result
    get_universal_compound_element_by_name(p0, p1,
        (void*) COUNTER_NAME, (void*) COUNTER_NAME_COUNT,
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
        && (*mdla != NULL_POINTER)
        && (*mdlac != NULL_POINTER)
        && (*mdlas != NULL_POINTER)
        && (*mdlm != NULL_POINTER)
        && (*mdlmc != NULL_POINTER)
        && (*mdlms != NULL_POINTER)
        && (*mdld != NULL_POINTER)
        && (*mdldc != NULL_POINTER)
        && (*mdlds != NULL_POINTER)
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
        compare_arrays(*mdla, *mdlac, (void*) COMPOUND_ABSTRACTION, (void*) COMPOUND_ABSTRACTION_COUNT, (void*) &comp_res2, (void*) CHARACTER_ARRAY);
        compare_arrays(*resa, *resac, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT, (void*) &comp_res3, (void*) CHARACTER_ARRAY);

        if ((comp_res1 == 1) && (comp_res2 == 1) && (comp_res3 == 1)) {

            //Vorgehen,
            //-alle Elemente des Compound durchgehen
            //-Namen testen basisname_#
            //-Z?lvariable hochz?hlen
            //am Ende die Z?hlvariable ins result schreiben

            //compound element
            // The compund element name.
            void** cen = &NULL_POINTER;
            void** cenc = &NULL_POINTER;
            void** cens = &NULL_POINTER;

            //init the counter
            int* list_counter = (int*) *resm;
            *list_counter = 0;

            // Create compare string.
            char* compstring = NULL_POINTER;
            int compstring_count = *((int*) *bnmc) + *LIST_SEPARATOR_COUNT;

            allocate_array((void*) &compstring, (void*) &compstring_count, (void*) CHARACTER_ARRAY);

            // Set the compare string
            // this is the basisname and the list separat
            set_array_elements(compstring, (void*) NUMBER_0_INTEGER, *bnm, *bnmc,  (void*) CHARACTER_ARRAY);
            set_array_elements(compstring, *bnmc, LIST_SEPARATOR, LIST_SEPARATOR_COUNT, (void*) CHARACTER_ARRAY);

            // The loop count.
            int j = 0;
            // The comparison result.
            int r = 0;

            while (1) {

                if (j >= *((int*) *mdlmc)) {

                    break;
                }

                get_compound_element_name_by_index(*mdlm, *mdlmc, &j, &cen, &cenc, &cens);

//??                if ((cen != NULL_POINTER) && (cenc != NULL_POINTER) && (cens != NULL_POINTER)) {

                    if ((*cen != NULL_POINTER) && (*cenc != NULL_POINTER) && (*cens != NULL_POINTER)) {

                        //check the count for the compare arrays
                        // the compound element must greater als the compare string
                        if (*((int*) *cenc) > compstring_count) {

                            r = 0;

                            compare_arrays(compstring, &compstring_count, *cen, &compstring_count, &r, CHARACTER_ARRAY);

                            //if teh begiining of the two arrays ident, then
                            //the compound element is a part of the list
                            if (r == 1) {

                                *list_counter = *list_counter + 1;
                            }
                        }
                    }
//??                }

                j++;
            }

            // destroy compare string.
            deallocate_array((void*) &compstring, (void*) &compstring_count, (void*) CHARACTER_ARRAY);

        } else {

            log_message_debug("Could not count part. The abstraction for the operands is not correct.");
        }
    }
}

/* COUNT_SOURCE */
#endif
