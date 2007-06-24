/*
 * $RCSfile: count_prefix.c,v $
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
 * @version $Revision: 1.2 $ $Date: 2007-06-24 15:02:21 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef COUNT_PREFIX_SOURCE
#define COUNT_PREFIX_SOURCE

#include "../../globals/constants/cybol/cybol_abstraction_constants.c"
#include "../../globals/constants/cybol/cybol_name_constants.c"
#include "../../globals/constants/log/log_message_constants.c"
#include "../../globals/constants/pointer/pointer_constants.c"
#include "../../globals/logger/logger.c"
#include "../../memoriser/accessor/compound_accessor.c"
#include "../../memoriser/allocator.c"
#include "../../memoriser/array.c"
#include "../../memoriser/communicator.c"
#include "../../memoriser/converter.c"
#include "../../memoriser/translator.c"

/**
 * Counts those compound parts whose name starts with the given prefix.
 *
 * @param p0 the result
 * @param p1 the result count
 * @param p2 the result size
 * @param p3 the compound
 * @param p4 the compound count
 * @param p5 the filter (prefix)
 * @param p6 the filter count
 */
void count_prefix(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

/*??
    if (p4 != *NULL_POINTER) {

        int* cc = (int*) p4;

        if (p0 != *NULL_POINTER) {

            void** r = (void**) p0;

            log_message_debug("Count all compound parts.");

            // Set result to compound count value.
            // A loop is not needed here, since the compound count already contains
            // the number of parts within that compound.
            set_element(*r, NUMBER_0_INTEGER, (void*) &p4, INTEGER_ABSTRACTION, INTEGER_ABSTRACTION_COUNT);

    fprintf(stderr, "TEST r: %i\n", **r);
    fprintf(stderr, "TEST rc: %i\n", *((int*) rc));
    fprintf(stderr, "TEST cc: %i\n", *cc);

        } else {

            log_message_debug("Error: Could not count all compound parts. The result is null.");
        }

    } else {

        log_message_debug("Error: Could not count all compound parts. The compound count is null.");
    }
*/

/*??
            // The compund element name.
            void** cen = NULL_POINTER;
            void** cenc = NULL_POINTER;
            void** cens = NULL_POINTER;

            //init the counter
            int* list_counter = (int*) *resm;
            *list_counter = 0;

            // Create compare string.
            char* compstring = *NULL_POINTER;
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

                    if ((*cen != *NULL_POINTER) && (*cenc != *NULL_POINTER) && (*cens != *NULL_POINTER)) {

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
*/

/*??
    // The basisname name, abstraction, model, details.
    void** bnn = NULL_POINTER;
    void** bnnc = NULL_POINTER;
    void** bnns = NULL_POINTER;
    void** bna = NULL_POINTER;
    void** bnac = NULL_POINTER;
    void** bnas = NULL_POINTER;
    void** bnm = NULL_POINTER;
    void** bnmc = NULL_POINTER;
    void** bnms = NULL_POINTER;
    void** bnd = NULL_POINTER;
    void** bndc = NULL_POINTER;
    void** bnds = NULL_POINTER;
    // The index name, abstraction, model, details.
    void** mdln = NULL_POINTER;
    void** mdlnc = NULL_POINTER;
    void** mdlns = NULL_POINTER;
    void** mdla = NULL_POINTER;
    void** mdlac = NULL_POINTER;
    void** mdlas = NULL_POINTER;
    void** mdlm = NULL_POINTER;
    void** mdlmc = NULL_POINTER;
    void** mdlms = NULL_POINTER;
    void** mdld = NULL_POINTER;
    void** mdldc = NULL_POINTER;
    void** mdlds = NULL_POINTER;
    // The result name, abstraction, model, details.
    void** resn = NULL_POINTER;
    void** resnc = NULL_POINTER;
    void** resns = NULL_POINTER;
    void** resa = NULL_POINTER;
    void** resac = NULL_POINTER;
    void** resas = NULL_POINTER;
    void** resm = NULL_POINTER;
    void** resmc = NULL_POINTER;
    void** resms = NULL_POINTER;
    void** resd = NULL_POINTER;
    void** resdc = NULL_POINTER;
    void** resds = NULL_POINTER;
*/
}

/* COUNT_PREFIX_SOURCE */
#endif
