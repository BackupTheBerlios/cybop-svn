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
 * @version $RCSfile: accessor.c,v $ $Revision: 1.24 $ $Date: 2009-10-06 21:25:26 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef RETRIEVER_SOURCE
#define RETRIEVER_SOURCE

#include "../../constant/abstraction/memory/memory_abstraction.c"
#include "../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../executor/accessor/getter/array_getter.c"
#include "../../executor/accessor/getter/compound_getter.c"
#include "../../executor/accessor/getter/signal_memory_getter.c"
#include "../../executor/comparator/equality/array_equality_comparator.c"

/**
 * Retrieves the element at position index.
 *
 * @param p0 the destination element (Hand over as reference!)
 * @param p1 the destination element count (Hand over as reference!)
 * @param p2 the destination element size (Hand over as reference!)
 * @param p3 the source model
 * @param p4 the source model count
 * @param p5 the source model index
 * @param p6 the source model abstraction
 * @param p7 the source model abstraction count
 */
void retrieve(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    if (p5 != *NULL_POINTER_MEMORY_MODEL) {

        int* i = (int*) p5;

        if (p4 != *NULL_POINTER_MEMORY_MODEL) {

            int* sc = (int*) p4;

            log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Retrieve element.");

            if (*i < *sc) {

                // The comparison result.
                int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_array((void*) &r, p6, p7, (void*) CHARACTER_MEMORY_ABSTRACTION, (void*) CHARACTER_MEMORY_ABSTRACTION_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        get_array_elements(p0, p1, p2, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);
                    }
                }

                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_array((void*) &r, p6, p7, (void*) COMPLEX_MEMORY_ABSTRACTION, (void*) COMPLEX_MEMORY_ABSTRACTION_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            //??            get_complex_element(p0, p1, p2);
                    }
                }

                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_array((void*) &r, p6, p7, (void*) COMPOUND_MEMORY_ABSTRACTION, (void*) COMPOUND_MEMORY_ABSTRACTION_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

//??                        get_array(p0, p3, p5, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
                    }
                }

                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_array((void*) &r, p6, p7, (void*) DATETIME_MEMORY_ABSTRACTION, (void*) DATETIME_MEMORY_ABSTRACTION_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            //??            get_datetime_element(p0, p1, p2);
                    }
                }

                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_array((void*) &r, p6, p7, (void*) DOUBLE_MEMORY_ABSTRACTION, (void*) DOUBLE_MEMORY_ABSTRACTION_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        get_array_elements(p0, p1, p2, (void*) DOUBLE_PRIMITIVE_MEMORY_ABSTRACTION);
                    }
                }

                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_array((void*) &r, p6, p7, (void*) FRACTION_MEMORY_ABSTRACTION, (void*) FRACTION_MEMORY_ABSTRACTION_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            //??            get_fraction_element(p0, p1, p2);
                    }
                }

                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_array((void*) &r, p6, p7, (void*) INTEGER_MEMORY_ABSTRACTION, (void*) INTEGER_MEMORY_ABSTRACTION_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        get_array_elements(p0, p1, p2, (void*) INTEGER_PRIMITIVE_MEMORY_ABSTRACTION);
                    }
                }

                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_array((void*) &r, p6, p7, (void*) INTERNAL_MEMORY_MEMORY_ABSTRACTION, (void*) INTERNAL_MEMORY_MEMORY_ABSTRACTION_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            //??            get_internal_memory_element(p0, p1, p2);
                    }
                }

                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_array((void*) &r, p6, p7, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        get_array_elements(p0, p1, p2, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
                    }
                }

                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_array((void*) &r, p6, p7, (void*) SIGNAL_MEMORY_MEMORY_ABSTRACTION, (void*) SIGNAL_MEMORY_MEMORY_ABSTRACTION_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            //??            get_signal_memory_element(p0, p1, p2);
                    }
                }

                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_array((void*) &r, p6, p7, (void*) UNSIGNED_LONG_MEMORY_ABSTRACTION, (void*) UNSIGNED_LONG_MEMORY_ABSTRACTION_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        get_array_elements(p0, p1, p2, (void*) UNSIGNED_LONG_PRIMITIVE_MEMORY_ABSTRACTION);
                    }
                }

                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_array((void*) &r, p6, p7, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        get_array_elements(p0, p1, p2, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);
                    }
                }

                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    log_terminated_message((void*) WARNING_LEVEL_LOG_MODEL, (void*) L"Could not get element. The source model abstraction is unknown.");
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not get element. The source model index is greater or equal the source model count.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not get element. The source model count is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not get element. The source model index is null.");
    }
}

/* RETRIEVER_SOURCE */
#endif
