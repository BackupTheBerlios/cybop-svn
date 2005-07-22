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
 * @version $Revision: 1.4 $ $Date: 2005-07-22 22:42:50 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef COUNT_SOURCE
#define COUNT_SOURCE

#include "../globals/constants/abstraction_constants.c"
#include "../globals/constants/log_constants.c"
#include "../globals/constants/name_constants.c"
#include "../globals/logger/logger.c"
#include "../memoriser/array.c"
#include "../memoriser/communicator.c"
#include "../memoriser/converter.c"
#include "../memoriser/creator.c"
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
void count_parts(const void* p0, const void* p1, void* p2, void* p3, void* p4) {

    log_message_debug("Count parts.");

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
    get_real_compound_element_by_name(p0, p1,
        (void*) PART_NAME_NAME,
        (void*) PART_NAME_NAME_COUNT,
        (void*) &bna, (void*) &bnac, (void*) &bnas,
        (void*) &bnm, (void*) &bnmc, (void*) &bnms,
        (void*) &bnd, (void*) &bndc, (void*) &bnds,
        p2, p3);

    // get the model
    get_real_compound_element_by_name(p0, p1,
        (void*) WHOLE_MODEL_NAME,
        (void*) WHOLE_MODEL_NAME_COUNT,
        (void*) &mdla, (void*) &mdlac, (void*) &mdlas,
        (void*) &mdlm, (void*) &mdlmc, (void*) &mdlms,
        (void*) &mdld, (void*) &mdldc, (void*) &mdlds,
        p2, p3);

    // get the result
    get_real_compound_element_by_name(p0, p1,
        (void*) COUNTER_NAME,
        (void*) COUNTER_NAME_COUNT,
        (void*) &resa, (void*) &resac, (void*) &resas,
        (void*) &resm, (void*) &resmc, (void*) &resms,
        (void*) &resd, (void*) &resdc, (void*) &resds,
        p2, p3);

    // Check basisname.
    if ((bna != POINTER_NULL_POINTER)
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
        && (resds != POINTER_NULL_POINTER)) {

        //check the abstraction for the operation element
        int comp_res1 = 0;
        int comp_res2 = 0;
        int comp_res3 = 0;

        compare_arrays(*bna, *bnac, (void*) STRING_ABSTRACTION, (void*) STRING_ABSTRACTION_COUNT, (void*) &comp_res1, (void*) CHARACTER_ARRAY);
        compare_arrays(*mdla, *mdlac, (void*) COMPOUND_ABSTRACTION, (void*) COMPOUND_ABSTRACTION_COUNT, (void*) &comp_res2, (void*) CHARACTER_ARRAY);
        compare_arrays(*mdla, *mdlac, (void*) CYBOL_ABSTRACTION, (void*) CYBOL_ABSTRACTION_COUNT, (void*) &comp_res2, (void*) CHARACTER_ARRAY);
        compare_arrays(*resa, *resac, (void*) INTEGER_ABSTRACTION, (void*) INTEGER_ABSTRACTION_COUNT, (void*) &comp_res3, (void*) CHARACTER_ARRAY);

        if ((comp_res1 == 1) && (comp_res2 == 1) && (comp_res3 == 1)) {

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
            int* list_counter = (int*) *resm;
            *list_counter = 0;

            // Create compare string.
            char* compstring = NULL_POINTER;
            int compstring_count = *((int*) *bnmc) + *LIST_SEPARATOR_COUNT;

            create_array((void*) &compstring, (void*) &compstring_count, (void*) CHARACTER_ARRAY);

            // Set the compare string
            // this is the basisname and the list separat
            set_array_elements(compstring, (void*) ZERO_INTEGER, *bnm, *bnmc,  (void*) CHARACTER_ARRAY);
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

                if ((cen != POINTER_NULL_POINTER) && (cenc != POINTER_NULL_POINTER) && (cens != POINTER_NULL_POINTER)) {

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
                }

                j++;
            }

            // destroy compare string.
            destroy_array((void*) &compstring, (void*) &compstring_count, (void*) CHARACTER_ARRAY);

        } else {

            log_message_debug("Could not count part. The abstraction for the operands is not correct.");
        }
    }
}

/* COUNT_SOURCE */
#endif
