/*
 * Copyright (C) 1999-2008. Christian Heller.
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
 * @version $RCSfile: double_vector_accessor.c,v $ $Revision: 1.12 $ $Date: 2008-09-04 20:31:31 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef DOUBLE_VECTOR_ACCESSOR_SOURCE
#define DOUBLE_VECTOR_ACCESSOR_SOURCE

#include "../../constant/abstraction/cybol/text_cybol_abstraction.c"
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../constant/model/log/message_log_model.c"
#include "../../constant/abstraction/memory/array_memory_abstraction.c"
#include "../../logger/logger.c"
#include "../../memoriser/array.c"

/**
 * Sets the double vector element.
 *
 * @param p0 the double vector
 * @param p1 the index
 * @param p2 the element (Hand over as reference!)
 */
void set_double_vector_element(void* p0, void* p1, void* p2) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Set double vector element.");

    set_array_elements(p0, p1, p2, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) DOUBLE_ARRAY_MEMORY_ABSTRACTION);
}

/**
 * Removes the double vector element.
 *
 * @param p0 the double vector
 * @param p1 the size
 * @param p2 the index
 */
void remove_double_vector_element(void* p0, void* p1, void* p2) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Remove double vector element.");

    remove_array_elements(p0, p1, p2, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) DOUBLE_ARRAY_MEMORY_ABSTRACTION);
}

/**
 * Gets the double vector element.
 *
 * @param p0 the double vector
 * @param p1 the index
 * @param p2 the vector element (Hand over as reference!)
 */
void get_double_vector_element(void* p0, void* p1, void* p2) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Get double vector element.");

    get_array_elements(p0, p1, p2, (void*) DOUBLE_ARRAY_MEMORY_ABSTRACTION);
}

/* DOUBLE_VECTOR_ACCESSOR_SOURCE */
#endif
