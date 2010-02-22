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
 * @version $RCSfile: array.c,v $ $Revision: 1.23 $ $Date: 2009-10-06 21:25:26 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef ARRAY_GETTER_SOURCE
#define ARRAY_GETTER_SOURCE

#include <stdlib.h>
#include <string.h>
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../constant/model/log/message_log_model.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../logger/logger.c"
#include "../../variable/primitive_type_size.c"

/**
 * Gets the destination array elements from the source array starting at index.
 *
 * @param p0 the destination (Hand over as array reference!)
 * @param p1 the source
 * @param p2 the index
 * @param p3 the abstraction
 */
void get_array_elements(void* p0, void* p1, void* p2, void* p3) {

    if (p1 != *NULL_POINTER_MEMORY_MODEL) {

        if (p0 != *NULL_POINTER_MEMORY_MODEL) {

            void** d = (void**) p0;

            log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Get array elements.");

            // The offset.
            int o = *NUMBER_0_INTEGER_MEMORY_MODEL;

            // Calculate offset depending on given array type.
            calculate_area((void*) &o, p2, p3);

            // The destination elements.
            // CAUTION! It HAS TO BE initialised with p1,
            // since an offset is added to it below.
            *d = p1;

            // Add offset to destination elements.
            // The destination is set to source pointer plus offset.
            // That's all.
            add_integer(p0, (void*) &o, (void*) POINTER_MEMORY_ABSTRACTION);

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not get array elements. The destination elements is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not get array elements. The source array is null.");
    }
}

/**
 * Gets the array elements index.
 *
 * Returns the index if the array elements could be found;
 * leaves the given index parameter unchanged, otherwise.
 * Only the first occurence of the elements is considered.
 *
 * @param p0 the index (Hand over as reference!)
 * @param p1 the array
 * @param p2 the array count
 * @param p3 the elements
 * @param p4 the elements count
 * @param p5 the abstraction
 */
void get_array_elements_index(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    if (p4 != *NULL_POINTER_MEMORY_MODEL) {

        int* ec = (int*) p4;

        if (p2 != *NULL_POINTER_MEMORY_MODEL) {

            int* ac = (int*) p2;

            if (p1 != *NULL_POINTER_MEMORY_MODEL) {

                if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                    int* i = (int*) p0;

                    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Get array elements index.");

                    // The iteration limit.
                    int l = *ac - *ec + *NUMBER_1_INTEGER_MEMORY_MODEL;
                    // The element.
                    void* e = *NULL_POINTER_MEMORY_MODEL;
                    // The loop variable.
                    int j = *NUMBER_0_INTEGER_MEMORY_MODEL;
                    // The comparison result.
                    int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

                    while (*NUMBER_1_INTEGER_MEMORY_MODEL) {

                        if (j >= l) {

                            // The element has not been found.
                            break;
                        }

                        get_array_elements((void*) &e, p1, (void*) &j, p5);
                        compare_array_elements((void*) &r, e, p3, p4, p5);

                        if (r == *NUMBER_1_INTEGER_MEMORY_MODEL) {

                            // The element has been found.
                            *i = j;

                            break;
                        }

                        j++;
                    }

                } else {

                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not get array elements index. The index is null.");
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not get array elements index. The array is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not get array elements index. The array count is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not get array elements index. The elements count is null.");
    }
}

/* ARRAY_GETTER_SOURCE */
#endif
