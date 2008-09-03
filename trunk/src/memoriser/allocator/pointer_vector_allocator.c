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
 * @version $RCSfile: pointer_vector_allocator.c,v $ $Revision: 1.11 $ $Date: 2008-09-03 22:04:02 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef POINTER_VECTOR_ALLOCATOR_SOURCE
#define POINTER_VECTOR_ALLOCATOR_SOURCE

#include "../../globals/constants/cybol/cybol_abstraction_constants.c"
#include "../../constant/model/log/message_log_model.c"
#include "../../constant/abstraction/memory/array_memory_abstraction.c"
#include "../../logger/logger.c"
#include "../../memoriser/array.c"

/**
 * Allocates the pointer vector.
 *
 * @param p0 the vector (Hand over as reference!)
 * @param p1 the vector size
 */
void allocate_pointer_vector(void* p0, void* p1) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Allocate pointer vector.");

    allocate_array(p0, p1, (void*) POINTER_ARRAY);
}

/**
 * Deallocates the pointer vector.
 *
 * @param p0 the vector (Hand over as reference!)
 * @param p1 the vector size
 */
void deallocate_pointer_vector(void* p0, void* p1) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Deallocate pointer vector.");

    deallocate_array(p0, p1, (void*) POINTER_ARRAY);
}

/**
 * Reallocates the pointer vector.
 *
 * @param p0 the vector (Hand over as reference!)
 * @param p1 the vector count
 * @param p2 the vector size
 */
void reallocate_pointer_vector(void* p0, void* p1, void* p2) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Reallocate pointer vector.");

    reallocate_array(p0, p1, p2, (void*) POINTER_ARRAY);
}

/* POINTER_VECTOR_ALLOCATOR_SOURCE */
#endif
