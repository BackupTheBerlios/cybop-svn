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
 * @version $RCSfile: accessor.c,v $ $Revision: 1.24 $ $Date: 2009-10-06 21:25:26 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef GETTER_SOURCE
#define GETTER_SOURCE

#include "../../constant/abstraction/memory/memory_abstraction.c"
#include "../../constant/abstraction/memory/memory_abstraction.c"
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../executor/accessor/getter/array_getter.c"
#include "../../executor/accessor/getter/compound_getter.c"
#include "../../executor/accessor/getter/signal_memory_getter.c"
#include "../../executor/comparator/array_equality_comparator.c"

/**
 * Gets the element.
 *
 * @param p0 the destination (Hand over as reference!)
 * @param p1 the source
 * @param p2 the index
 * @param p3 the abstraction
 * @param p4 the abstraction count
 */
void get(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p3 != *NULL_POINTER_MEMORY_MODEL) {

        int* a = (int*) p3;

        log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Get element.");

        if (*a == *CHARACTER_MEMORY_ABSTRACTION) {

            get_array_elements(p0, p1, p2, p3);

        } else if (*a == *COMPLEX_MEMORY_ABSTRACTION) {

//??            get_complex_element(p0, p1, p2);

        } else if (*a == *COMPOUND_MEMORY_ABSTRACTION) {

//??            get_compound_element(p0, p1, p2);

        } else if (*a == *DATETIME_MEMORY_ABSTRACTION) {

//??            get_datetime_element(p0, p1, p2);

        } else if (*a == *DOUBLE_MEMORY_ABSTRACTION) {

            get_array_elements(p0, p1, p2, p3);

        } else if (*a == *FRACTION_MEMORY_ABSTRACTION) {

//??            get_fraction_element(p0, p1, p2);

        } else if (*a == *INTEGER_MEMORY_ABSTRACTION) {

            get_array_elements(p0, p1, p2, p3);

        } else if (*a == *INTERNAL_MEMORY_MEMORY_ABSTRACTION) {

//??            get_internal_memory_element(p0, p1, p2);

        } else if (*a == *POINTER_MEMORY_ABSTRACTION) {

            get_array_elements(p0, p1, p2, p3);

        } else if (*a == *SIGNAL_MEMORY_MEMORY_ABSTRACTION) {

//??            get_signal_memory_element(p0, p1, p2);

        } else if (*a == *UNSIGNED_LONG_MEMORY_ABSTRACTION) {

            get_array_elements(p0, p1, p2, p3);

        } else if (*a == *WIDE_CHARACTER_MEMORY_ABSTRACTION) {

            get_array_elements(p0, p1, p2, p3);

        } else {

            log_terminated_message((void*) WARNING_LEVEL_LOG_MODEL, (void*) L"Could not get element. The abstraction is unknown.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not get element. The abstraction is null.");
    }
}

/* GETTER_SOURCE */
#endif
