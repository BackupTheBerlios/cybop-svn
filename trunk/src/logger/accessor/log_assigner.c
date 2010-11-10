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
 * @version $RCSfile: assigner.c,v $ $Revision: 1.1 $ $Date: 2009-10-06 21:25:26 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef LOG_ASSIGNER_SOURCE
#define LOG_ASSIGNER_SOURCE

#include <stdlib.h>
#include <string.h>
#include "../../constant/model/log/message_log_model.c"
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../logger/accessor/assigner/log_integer_assigner.c"
#include "../../logger/accessor/assigner/log_wide_character_assigner.c"
#include "../../logger/arithmetiser/log_integer_multiplier.c"
#include "../../logger/memoriser/log_size_determiner.c"
#include "../../variable/primitive_type_size.c"

/**
 * Assigns the value.
 *
 * @param p0 the destination base
 * @param p1 the source value
 * @param p2 the offset
 * @param p3 the abstraction
 */
void log_assign(void* p0, void* p1, void* p2, void* p3) {

    if (p3 != *NULL_POINTER_MEMORY_MODEL) {

        int* a = (int*) p3;

        if (p2 != *NULL_POINTER_MEMORY_MODEL) {

            int* o = (int*) p2;

            // Determine destination element.
            void* de = p0 + *o;
            // Determine source element.
            void* se = p1 + *o;

            // CAUTION! DO NOT use logging functionality here!
            // The logger cannot log itself.

            if (*a == *INTEGER_PRIMITIVE_MEMORY_ABSTRACTION) {

                log_assign_integer(de, se);

            } else if (*a == *WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION) {

                log_assign_wide_character(de, se);

            } else {

                // CAUTION! DO NOT use logging functionality here!
                // The logger cannot log itself.
                // "Could not assign value. The abstraction is unknown."
            }

        } else {

            // CAUTION! DO NOT use logging functionality here!
            // The logger cannot log itself.
            // "Could not assign value. The offset is null."
        }

    } else {

        // CAUTION! DO NOT use logging functionality here!
        // The logger cannot log itself.
        // "Could not assign value. The abstraction is null."
    }
}

/**
 * Assigns the value at the given offset.
 *
 * @param p0 the destination
 * @param p1 the source
 * @param p2 the index
 * @param p3 the abstraction
 */
void log_assign_with_offset(void* p0, void* p1, void* p2, void* p3) {

    // The offset.
    int o = *NUMBER_0_INTEGER_MEMORY_MODEL;

    // Determine abstraction (type) size.
    log_determine_size((void*) &o, p3);

    // Calculate memory area (destination offset).
    log_multiply_with_integer((void*) &o, p2, (void*) INTEGER_PRIMITIVE_MEMORY_ABSTRACTION);

    // Assign source- to destination memory area.
    log_assign(p0, p1, (void*) &o, p3);
}

/* LOG_ASSIGNER_SOURCE */
#endif
