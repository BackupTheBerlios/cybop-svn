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
 * @version $RCSfile: compound_accessor.c,v $ $Revision: 1.64 $ $Date: 2009-10-06 21:25:26 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef COMPOUND_VALUE_COPIER_SOURCE
#define COMPOUND_VALUE_COPIER_SOURCE

#include "../../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../../constant/model/log/message_log_model.c"
#include "../../../constant/model/memory/pointer_memory_model.c"
#include "../../../logger/logger.c"

/**
 * Copies the compound.
 *
 * A "compound" is nothing but a simple pointer array.
 * Each entry references a "part".
 *
 * @param p0 the destination value
 * @param p1 the source value
 * @param p2 the count
 */
void copy_value_compound(void* p0, void* p1, void* p2) {

    if (p2 != *NULL_POINTER_MEMORY_MODEL) {

        int* c = (int*) p2;

        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Copy compound.");

        // The destination, source part.
        void* d = *NULL_POINTER_MEMORY_MODEL;
        void* s = *NULL_POINTER_MEMORY_MODEL;

        // The loop variable.
        int j = *NUMBER_0_INTEGER_MEMORY_MODEL;

        while (*NUMBER_1_INTEGER_MEMORY_MODEL) {

            if (j >= *c) {

                break;
            }

            // Get destination, source part.
            copy_array_offset((void*) &d, p0, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) &j);
            copy_array_offset((void*) &s, p1, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) &j);

            // Allocate destination part instead of getting it, if not existent.
            //?? allocate((void*) &dp, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, a, ac);

            //?? TODO: Determine (source?) abstraction and
            //?? (source?) count to use them as p2 and p3 below.

            // Set source- to destination part.
//??            copy_part(d, s, (void*) source-abstraction, source-count or (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME);

            j++;
        }

        // Set source- to destination model (shallow).
        // Use shallow copying for primitive data like:
        // integer, double, wide_character, fraction.

        // Use deep copying for compound data.
        //
        // CAUTION! Do NOT use shallow copying here!
        // The data is just a reference to the actual compound model.
        // If only the source pointer was copied, then the
        // destination would point to the same model as the source.
        // But this kind of shallow copy is not wanted here.
        // The compound model's parts (child nodes) have to be copied, too.
        // Since they do not exist, they have to be allocated first.

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not copy compound. The count is null.");
    }
}

/* COMPOUND_VALUE_COPIER_SOURCE */
#endif
