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
 * @version $RCSfile: part_allocator.c,v $ $Revision: 1.3 $ $Date: 2008-10-02 22:17:08 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef PART_ALLOCATOR_SOURCE
#define PART_ALLOCATOR_SOURCE

#include "../../constant/model/log/message_log_model.c"
#include "../../logger/logger.c"

/**
 * Allocates the part.
 *
 * @param p0 the destination name (Hand over as reference!)
 * @param p1 the destination name count (Hand over as reference!)
 * @param p2 the destination name size (Hand over as reference!)
 * @param p3 the destination abstraction (Hand over as reference!)
 * @param p4 the destination abstraction count (Hand over as reference!)
 * @param p5 the destination abstraction size (Hand over as reference!)
 * @param p6 the destination model (Hand over as reference!)
 * @param p7 the destination model count (Hand over as reference!)
 * @param p8 the destination model size (Hand over as reference!)
 * @param p9 the destination details (Hand over as reference!)
 * @param p10 the destination details count (Hand over as reference!)
 * @param p11 the destination details size (Hand over as reference!)
 * @param p12 the source size
 * @param p13 the source abstraction
 * @param p14 the source abstraction count
 */
void allocate_part(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5,
    void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14) {

    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Allocate part.");

    // Allocate name.
    allocate_model(p0, p1, p2, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
    // A channel is not allocated, since that is only needed temporarily for model loading.
    // Allocate abstraction.
    allocate_model(p3, p4, p5, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
    // Allocate model.
    allocate_model(p6, p7, p8, p12, p13, p14);
    // Allocate details.
    allocate_model(p9, p10, p11, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) COMPOUND_MEMORY_ABSTRACTION, (void*) COMPOUND_MEMORY_ABSTRACTION_COUNT);
}

/* PART_ALLOCATOR_SOURCE */
#endif
