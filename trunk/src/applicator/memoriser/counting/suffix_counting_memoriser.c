/*
 * Copyright (C) 1999-2011. Christian Heller.
 *
 * This file is part of the Cybernetics Oriented Interpreter (CYBOI).
 *
 * CYBOI is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * CYBOI is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with CYBOI.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Cybernetics Oriented Programming (CYBOP) <http://www.cybop.org>
 * Christian Heller <christian.heller@tuxtax.de>
 *
 * @version $RCSfile: suffix_counting_memoriser.c,v $ $Revision: 1.9 $ $Date: 2009-01-31 16:06:29 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef SUFFIX_COUNTING_MEMORISER_SOURCE
#define SUFFIX_COUNTING_MEMORISER_SOURCE

#include "../../../constant/abstraction/cybol/text_cybol_abstraction.c"
#include "../../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../../constant/model/log/message_log_model.c"
#include "../../../constant/model/memory/integer_memory_model.c"
#include "../../../constant/model/memory/pointer_memory_model.c"
#include "../../../constant/name/cybol/web_user_interface/tag_web_user_interface_cybol_name.c"
#include "../../../executor/accessor/getter/compound_getter.c"
#include "../../../executor/communicator/receiver.c"
#include "../../../executor/comparator/array_equality_comparator.c"
#include "../../../executor/converter/decoder.c"
#include "../../../executor/memoriser/allocator.c"
#include "../../../logger/logger.c"

/**
 * Counts those compound parts whose name ends with the given suffix.
 *
 * @param p0 the result
 * @param p1 the result count
 * @param p2 the result size
 * @param p3 the compound
 * @param p4 the compound count
 * @param p5 the filter (suffix)
 * @param p6 the filter count
 */
void memorise_counting_suffix(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

/*??
    if (p4 != *NULL_POINTER_MEMORY_MODEL) {

        int* cc = (int*) p4;

        if (p0 != *NULL_POINTER_MEMORY_MODEL) {

            void** r = (void**) p0;

            log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Count all compound parts.");

            // Set result to compound count value.
            // A loop is not needed here, since the compound count already contains
            // the number of parts within that compound.
            replace(*r, NUMBER_0_INTEGER_MEMORY_MODEL, (void*) &p4, INTEGER_ABSTRACTION, INTEGER_ABSTRACTION_COUNT);

    fwprintf(stdout, L"TEST r: %i\n", **r);
    fwprintf(stdout, L"TEST rc: %i\n", *((int*) rc));
    fwprintf(stdout, L"TEST cc: %i\n", *cc);

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not count all compound parts. The result is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not count all compound parts. The compound count is null.");
    }
*/

/*??
            // The compund element name.
            void** cen = NULL_POINTER_MEMORY_MODEL;
            void** cenc = NULL_POINTER_MEMORY_MODEL;
            void** cens = NULL_POINTER_MEMORY_MODEL;

            //init the counter
            int* list_counter = (int*) *resm;
            *list_counter = *NUMBER_0_INTEGER_MEMORY_MODEL;

            // Create compare string.
            wchar_t* compstring = *NULL_POINTER_MEMORY_MODEL;
            int compstring_count = *((int*) *bnmc) + *LIST_SEPARATOR_CYBOL_NAME_COUNT;

            allocate_array((void*) &compstring, (void*) &compstring_count, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

            // Set the compare string
            // this is the basisname and the list separat
            replace_array(compstring, *bnm, *bnmc, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);
            replace_array(compstring, LIST_SEPARATOR_CYBOL_NAME, LIST_SEPARATOR_CYBOL_NAME_COUNT, *bnmc, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

            // The loop count.
            int j = *NUMBER_0_INTEGER_MEMORY_MODEL;
            // The comparison result.
            int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

            while (*NUMBER_1_INTEGER_MEMORY_MODEL) {

                if (j >= *((int*) *mdlmc)) {

                    break;
                }

                get_compound_element_name_by_index(*mdlm, *mdlmc, &j, &cen, &cenc, &cens);

//??                if ((cen != NULL_POINTER_MEMORY_MODEL) && (cenc != NULL_POINTER_MEMORY_MODEL) && (cens != NULL_POINTER_MEMORY_MODEL)) {

                    if ((*cen != *NULL_POINTER_MEMORY_MODEL) && (*cenc != *NULL_POINTER_MEMORY_MODEL) && (*cens != *NULL_POINTER_MEMORY_MODEL)) {

                        //check the count for the compare arrays
                        // the compound element must greater als the compare string
                        if (*((int*) *cenc) > compstring_count) {

                            r = *NUMBER_0_INTEGER_MEMORY_MODEL;

                            compare_equal_arrays(&r, compstring, &compstring_count, *cen, &compstring_count, WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                            //if teh begiining of the two arrays ident, then
                            //the compound element is a part of the list
                            if (r == *NUMBER_1_INTEGER_MEMORY_MODEL) {

                                *list_counter = *list_counter + *NUMBER_1_INTEGER_MEMORY_MODEL;
                            }
                        }
                    }
//??                }

                j++;
            }

            // destroy compare string.
            deallocate_array((void*) &compstring, (void*) &compstring_count, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);
*/

/*??
    // The basisname name, abstraction, model, details.
    void** bnn = NULL_POINTER_MEMORY_MODEL;
    void** bnnc = NULL_POINTER_MEMORY_MODEL;
    void** bnns = NULL_POINTER_MEMORY_MODEL;
    void** bna = NULL_POINTER_MEMORY_MODEL;
    void** bnac = NULL_POINTER_MEMORY_MODEL;
    void** bnas = NULL_POINTER_MEMORY_MODEL;
    void** bnm = NULL_POINTER_MEMORY_MODEL;
    void** bnmc = NULL_POINTER_MEMORY_MODEL;
    void** bnms = NULL_POINTER_MEMORY_MODEL;
    void** bnd = NULL_POINTER_MEMORY_MODEL;
    void** bndc = NULL_POINTER_MEMORY_MODEL;
    void** bnds = NULL_POINTER_MEMORY_MODEL;
    // The index name, abstraction, model, details.
    void** mdln = NULL_POINTER_MEMORY_MODEL;
    void** mdlnc = NULL_POINTER_MEMORY_MODEL;
    void** mdlns = NULL_POINTER_MEMORY_MODEL;
    void** mdla = NULL_POINTER_MEMORY_MODEL;
    void** mdlac = NULL_POINTER_MEMORY_MODEL;
    void** mdlas = NULL_POINTER_MEMORY_MODEL;
    void** mdlm = NULL_POINTER_MEMORY_MODEL;
    void** mdlmc = NULL_POINTER_MEMORY_MODEL;
    void** mdlms = NULL_POINTER_MEMORY_MODEL;
    void** mdld = NULL_POINTER_MEMORY_MODEL;
    void** mdldc = NULL_POINTER_MEMORY_MODEL;
    void** mdlds = NULL_POINTER_MEMORY_MODEL;
    // The result name, abstraction, model, details.
    void** resn = NULL_POINTER_MEMORY_MODEL;
    void** resnc = NULL_POINTER_MEMORY_MODEL;
    void** resns = NULL_POINTER_MEMORY_MODEL;
    void** resa = NULL_POINTER_MEMORY_MODEL;
    void** resac = NULL_POINTER_MEMORY_MODEL;
    void** resas = NULL_POINTER_MEMORY_MODEL;
    void** resm = NULL_POINTER_MEMORY_MODEL;
    void** resmc = NULL_POINTER_MEMORY_MODEL;
    void** resms = NULL_POINTER_MEMORY_MODEL;
    void** resd = NULL_POINTER_MEMORY_MODEL;
    void** resdc = NULL_POINTER_MEMORY_MODEL;
    void** resds = NULL_POINTER_MEMORY_MODEL;
*/
}

/* SUFFIX_COUNTING_MEMORISER_SOURCE */
#endif
