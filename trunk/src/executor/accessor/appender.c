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

#ifndef APPENDER_SOURCE
#define APPENDER_SOURCE

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
 * Appends the source- to the destination vector.
 *
 * This function automatically adjusts the destination's count and size.
 *
 * @param p0 the destination (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source
 * @param p4 the source count
 * @param p5 the abstraction
 */
void append(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    if (p5 != *NULL_POINTER_MEMORY_MODEL) {

        int* a = (int*) p5;

        log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Append.");

        if (*a == *CHARACTER_VECTOR_MEMORY_ABSTRACTION) {

            append_character_vector(p0, p1, p2, p3, p4);

        } else if (*a == *WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION) {

            append_wide_character_vector(p0, p1, p2, p3, p4);

        } else {

            log_terminated_message((void*) WARNING_LEVEL_LOG_MODEL, (void*) L"Could not append value. The abstraction is unknown.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not append value. The abstraction is null.");
    }
}

/* APPENDER_SOURCE */
#endif
