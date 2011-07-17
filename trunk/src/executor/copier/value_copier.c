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
 * @version $RCSfile: assigner.c,v $ $Revision: 1.1 $ $Date: 2009-10-06 21:25:26 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef VALUE_COPIER_SOURCE
#define VALUE_COPIER_SOURCE

#include <stdlib.h>
#include <string.h>
#include "../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../constant/abstraction/operation/primitive_operation_abstraction.c"
#include "../../constant/model/log/message_log_model.c"
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../executor/copier/character_copier.c"
#include "../../executor/copier/double_copier.c"
#include "../../executor/copier/fraction_copier.c"
#include "../../executor/copier/integer_copier.c"
#include "../../executor/copier/part_copier.c"
#include "../../executor/copier/pointer_copier.c"
#include "../../executor/copier/unsigned_long_copier.c"
#include "../../executor/copier/wide_character_copier.c"
#include "../../executor/arithmetiser/integer_multiplier.c"
#include "../../executor/memoriser/offset_adder.c"
#include "../../executor/memoriser/size_determiner.c"
#include "../../logger/logger.c"

/**
 * Copies the value.
 *
 * @param p0 the destination value
 * @param p1 the source value
 * @param p2 the abstraction
 */
void copy_value(void* p0, void* p1, void* p2) {

    if (p2 != *NULL_POINTER_MEMORY_MODEL) {

        int* a = (int*) p2;

        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Copy value.");

        // The comparison result.
        // CAUTION! It is used instead of if-else statements.
        // May be one day, this is useful when using assembler or implementing cyboi as hardware chip.
        int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            if (*a == *CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION) {

                r = *NUMBER_1_INTEGER_MEMORY_MODEL;

                copy_character(p0, p1);
            }
        }

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            if (*a == *DOUBLE_PRIMITIVE_MEMORY_ABSTRACTION) {

                r = *NUMBER_1_INTEGER_MEMORY_MODEL;

                copy_double(p0, p1);
            }
        }

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            if (*a == *FRACTION_PRIMITIVE_MEMORY_ABSTRACTION) {

                r = *NUMBER_1_INTEGER_MEMORY_MODEL;

                copy_fraction(p0, p1);
            }
        }

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            if (*a == *INTEGER_PRIMITIVE_MEMORY_ABSTRACTION) {

                r = *NUMBER_1_INTEGER_MEMORY_MODEL;

                copy_integer(p0, p1);
            }
        }

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            if (*a == *PART_PRIMITIVE_MEMORY_ABSTRACTION) {

                r = *NUMBER_1_INTEGER_MEMORY_MODEL;

                copy_part(p0, p1);
            }
        }

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            if (*a == *POINTER_PRIMITIVE_MEMORY_ABSTRACTION) {

                r = *NUMBER_1_INTEGER_MEMORY_MODEL;

                copy_pointer(p0, p1);
            }
        }

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            if (*a == *UNSIGNED_LONG_PRIMITIVE_MEMORY_ABSTRACTION) {

                r = *NUMBER_1_INTEGER_MEMORY_MODEL;

                copy_unsigned_long(p0, p1);
            }
        }

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            if (*a == *WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION) {

                r = *NUMBER_1_INTEGER_MEMORY_MODEL;

                copy_wide_character(p0, p1);
            }
        }

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            log_terminated_message((void*) WARNING_LEVEL_LOG_MODEL, (void*) L"Could not copy value. The operand abstraction is unknown.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not copy value. The operand abstraction is null.");
    }
}

/**
 * Copies the source- to the destination value
 * using the given index to calculate an offset.
 *
 * @param p0 the destination value
 * @param p1 the source value
 * @param p2 the abstraction
 * @param p3 the index
 */
void copy_value_offset(void* p0, void* p1, void* p2, void* p3) {

    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Copy value offset.");

    // The destination value, source value.
    // CAUTION! They HAVE TO BE initialised with p0 and p1,
    // since an offset is added below.
    void* d = p0;
    void* s = p1;

    // Add offset.
    add_offset((void*) &d, p2, p3);
    add_offset((void*) &s, p2, p3);

    // Set source value to destination value.
    copy_value(d, s, p2);
}

/* VALUE_COPIER_SOURCE */
#endif
