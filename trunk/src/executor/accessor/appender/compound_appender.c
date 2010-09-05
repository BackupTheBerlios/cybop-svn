/*
 * Copyright (C) 1999-2010. Christian Heller.
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
 * @version $RCSfile: compound_accessor.c,v $ $Revision: 1.64 $ $Date: 2009-10-06 21:25:26 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef COMPOUND_APPENDER_SOURCE
#define COMPOUND_APPENDER_SOURCE

#include "../../../constant/abstraction/cybol/number_cybol_abstraction.c"
#include "../../../constant/abstraction/cybol/path_cybol_abstraction.c"
#include "../../../constant/abstraction/memory/memory_abstraction.c"
#include "../../../constant/abstraction/memory/memory_abstraction.c"
#include "../../../constant/model/log/message_log_model.c"
#include "../../../constant/model/memory/integer_memory_model.c"
#include "../../../constant/model/memory/pointer_memory_model.c"
#include "../../../constant/name/cybol/separator_cybol_name.c"
#include "../../../constant/name/memory/compound_memory_name.c"
#include "../../../logger/logger.c"
#include "../../../variable/reallocation_factor.c"
#include "../../../executor/memoriser/allocator.c"
#include "../../../executor/comparator/array_equality_comparator.c"

/**
 * Appends the compound element by name.
 *
 * @param p0 the compound model
 * @param p1 the compound model count
 * @param p2 the compound model size
 * @param p3 the name (Hand over as reference!)
 * @param p4 the name count
 * @param p5 the name size
 * @param p6 the abstraction
 * @param p7 the abstraction count
 * @param p8 the abstraction size
 * @param p9 the model
 * @param p10 the model count
 * @param p11 the model size
 * @param p12 the details
 * @param p13 the details count
 * @param p14 the details size
 */
void append_compound_element_by_name(void* p0, void* p1, void* p2,
    void* p3, void* p4, void* p5, void* p6, void* p7, void* p8,
    void* p9, void* p10, void* p11, void* p12, void* p13, void* p14) {

    if (p3 != *NULL_POINTER_MEMORY_MODEL) {

        void** n = (void**) p3;

        log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Append compound element by name:");

        // CAUTION! Use compound count as index for appending new elements.
        // CAUTION! Use DEREFERENCED name, as it was handed over as reference!
        set_compound_element_by_index(p0, p1, p2, p1, *n, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14);

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not append compound element by name. The name is null.");
    }
}

/**
 * Appends the compound element by name with suffix.
 *
 * The name suffix starts with "_$", e.g.:
 * part_$0
 * part_$1
 * channel_$2
 * abstraction_$0
 *
 * @param p0 the compound model
 * @param p1 the compound model count
 * @param p2 the compound model size
 * @param p3 the name (Hand over as reference!)
 * @param p4 the name count
 * @param p5 the name size
 * @param p6 the abstraction
 * @param p7 the abstraction count
 * @param p8 the abstraction size
 * @param p9 the model
 * @param p10 the model count
 * @param p11 the model size
 * @param p12 the details
 * @param p13 the details count
 * @param p14 the details size
 */
void append_compound_element_by_name_with_suffix(void* p0, void* p1, void* p2,
    void* p3, void* p4, void* p5, void* p6, void* p7, void* p8,
    void* p9, void* p10, void* p11, void* p12, void* p13, void* p14) {

    if (p5 != *NULL_POINTER_MEMORY_MODEL) {

        int* ns = (int*) p5;

        if (p4 != *NULL_POINTER_MEMORY_MODEL) {

            int* nc = (int*) p4;

            if (p3 != *NULL_POINTER_MEMORY_MODEL) {

                void** n = (void**) p3;

                log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Append compound element by name with suffix.");

                // The name suffix.
                void* s = *NULL_POINTER_MEMORY_MODEL;
                int sc = *NUMBER_0_INTEGER_MEMORY_MODEL;
                int ss = *NUMBER_0_INTEGER_MEMORY_MODEL;

//??    fwprintf(stdout, L"TEST append compound element 0 p1 dc: %i\n", *((int*) p1));

                // Allocate name suffix as wide character array.
                allocate_array((void*) &s, (void*) &ss, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT);

//??    fwprintf(stdout, L"TEST append compound element 1 ss: %i\n", ss);
//??    fwprintf(stdout, L"TEST append compound element 1 sc: %i\n", sc);
//??    fwprintf(stdout, L"TEST append compound element 1 s: %ls\n", (wchar_t*) s);

                // Use compound count as index to create the element name suffix,
                // because the element is appended at the end of the compound container.
                // The suffix integer is encoded into a wide character array.
                encode((void*) &s, (void*) &sc, (void*) &ss, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, p1, (void*) PRIMITIVE_MEMORY_MODEL_COUNT,
                    *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, (void*) INTEGER_MEMORY_ABSTRACTION);

//??    fwprintf(stdout, L"TEST append compound element 2 ss: %i\n", ss);
//??    fwprintf(stdout, L"TEST append compound element 2 sc: %i\n", sc);
//??    fwprintf(stdout, L"TEST append compound element 2 s: %ls\n", (wchar_t*) s);

                // Resize name.
                if ((*nc + *LIST_SEPARATOR_CYBOL_NAME_COUNT + sc) >= *ns) {

                    // The new name character vector size.
                    // CAUTION! Append constant in case *nc is zero!
                    *ns = (*nc * *CHARACTER_VECTOR_REALLOCATION_FACTOR) + *LIST_SEPARATOR_CYBOL_NAME_COUNT + sc;

//??    fwprintf(stdout, L"TEST append compound element 2 ns pre: %i\n", *ns);
                    // Reallocate name character vector.
                    reallocate_array(p3, p4, p5, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT);
//??    fwprintf(stdout, L"TEST append compound element 2 ns post: %i\n", *ns);
                }

//??    fwprintf(stdout, L"TEST append compound element 3 ss: %i\n", ss);
//??    fwprintf(stdout, L"TEST append compound element 3 sc: %i\n", sc);
//??    fwprintf(stdout, L"TEST append compound element 3 s: %ls\n", (wchar_t*) s);

                // The element name already contains the element base name.

                // Append list element separator characters "_$" to element name.
                // Use name count as index to append the new characters.
                set_array_elements(*n, p4, (void*) LIST_SEPARATOR_CYBOL_NAME, (void*) LIST_SEPARATOR_CYBOL_NAME_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT);
                *nc = *nc + *LIST_SEPARATOR_CYBOL_NAME_COUNT;

//??    fwprintf(stdout, L"TEST append compound element 4 ns: %i\n", *ns);
//??    fwprintf(stdout, L"TEST append compound element 4 nc: %i\n", *nc);
//??    fwprintf(stdout, L"TEST append compound element 4 n: %ls\n", (wchar_t*) *n);

                // Set new element name by appending the index determined above.
                // Use name count as index to append the new characters.
                set_array_elements(*n, p4, s, (void*) &sc, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT);
                *nc = *nc + sc;

//??    fwprintf(stdout, L"TEST append compound element 5 ns: %i\n", *ns);
//??    fwprintf(stdout, L"TEST append compound element 5 nc: %i\n", *nc);
//??    fwprintf(stdout, L"TEST append compound element 5 n: %ls\n", (wchar_t*) *n);

                // Deallocate name suffix as wide character array.
                deallocate_array((void*) &s, (void*) &ss, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT);

//??    fwprintf(stdout, L"TEST append compound element 6 ns: %i\n", *ns);
//??    fwprintf(stdout, L"TEST append compound element 6 nc: %i\n", *nc);
//??    fwprintf(stdout, L"TEST append compound element 6 n: %ls\n", (wchar_t*) *n);

//??    fwprintf(stdout, L"TEST append compound element 7 p2: %i\n", p2);
//??    fwprintf(stdout, L"TEST append compound element 7 *p2: %i\n", *((int*) p2));
//??    fwprintf(stdout, L"TEST append compound element 7 p1: %i\n", p1);
//??    fwprintf(stdout, L"TEST append compound element 7 *p1: %i\n", *((int*) p1));
//??    fwprintf(stdout, L"TEST append compound element 7 p0: %i\n", p0);

                append_compound_element_by_name(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14);

//??    fwprintf(stdout, L"TEST append compound element 8 p2: %i\n", *((int*) p2));
//??    fwprintf(stdout, L"TEST append compound element 8 p1: %i\n", *((int*) p1));
//??    fwprintf(stdout, L"TEST append compound element 8 p0: %i\n", p0);

//??    fwprintf(stdout, L"TEST append compound element 9 ns: %i\n", *ns);
//??    fwprintf(stdout, L"TEST append compound element 9 nc: %i\n", *nc);
//??    fwprintf(stdout, L"TEST append compound element 9 n: %ls\n", (wchar_t*) *n);

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not append compound element by name with suffix. The name is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not append compound element by name with suffix. The name count is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not append compound element by name with suffix. The name size is null.");
    }
}

/* COMPOUND_APPENDER_SOURCE */
#endif
