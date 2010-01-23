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

#ifndef SETTER_SOURCE
#define SETTER_SOURCE

#include "../constant/model/memory/integer_memory_model.c"
#include "../constant/abstraction/memory/array_memory_abstraction.c"
#include "../constant/abstraction/memory/memory_abstraction.c"
#include "../memoriser/accessor/character_vector_accessor.c"
#include "../memoriser/accessor/compound_accessor.c"
#include "../memoriser/accessor/double_vector_accessor.c"
#include "../memoriser/accessor/integer_vector_accessor.c"
#include "../memoriser/accessor/internal_memory_accessor.c"
#include "../memoriser/accessor/pointer_vector_accessor.c"
#include "../memoriser/accessor/signal_memory_accessor.c"
#include "../memoriser/accessor/wide_character_vector_accessor.c"
#include "../memoriser/array.c"

/**
 * Sets the element.
 *
 * @param p0 the model
 * @param p1 the index
 * @param p2 the element (Hand over as reference!)
 * @param p3 the abstraction
 */
void set(void* p0, void* p1, void* p2, void* p3) {

    if (p3 != *NULL_POINTER_MEMORY_MODEL) {

        int* a = (int*) p3;

        log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Set element.");

        if (*a == *CHARACTER_VECTOR_MEMORY_ABSTRACTION) {

            set_character_vector_element(p0, p1, p2);

        } else if (*a == *COMPLEX_MEMORY_ABSTRACTION) {

//??            set_complex_element(p0, p1, p2);

        } else if (*a == *COMPOUND_MEMORY_ABSTRACTION) {

//??            set_compound_element(p0, p1, p2);

        } else if (*a == *DATETIME_MEMORY_ABSTRACTION) {

//??            set_datetime_element(p0, p1, p2);

        } else if (*a == *DOUBLE_VECTOR_MEMORY_ABSTRACTION) {

            set_double_vector_element(p0, p1, p2);

        } else if (*a == *FRACTION_MEMORY_ABSTRACTION) {

//??            set_fraction_element(p0, p1, p2);

        } else if (*a == *INTEGER_VECTOR_MEMORY_ABSTRACTION) {

            set_integer_vector_element(p0, p1, p2);

        } else if (*a == *INTERNAL_MEMORY_MEMORY_ABSTRACTION) {

//??            set_internal_memory_element(p0, p1, p2);

        } else if (*a == *POINTER_VECTOR_MEMORY_ABSTRACTION) {

            set_pointer_vector_element(p0, p1, p2);

        } else if (*a == *SIGNAL_MEMORY_MEMORY_ABSTRACTION) {

//??            set_signal_memory_element(p0, p1, p2);

        } else if (*a == *UNSIGNED_LONG_VECTOR_MEMORY_ABSTRACTION) {

//??            set_unsigned_long_vector_element(p0, p1, p2);

        } else if (*a == *WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION) {

            set_wide_character_vector_element(p0, p1, p2);

        } else {

            log_terminated_message((void*) WARNING_LEVEL_LOG_MODEL, (void*) L"Could not set element. The abstraction is unknown.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not set element. The abstraction is null.");
    }
}

/* SETTER_SOURCE */
#endif
