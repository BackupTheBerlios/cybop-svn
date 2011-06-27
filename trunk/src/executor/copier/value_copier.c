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
#include "../../executor/copier/value/character_value_copier.c"
#include "../../executor/copier/value/compound_value_copier.c"
#include "../../executor/copier/value/double_value_copier.c"
#include "../../executor/copier/value/fraction_value_copier.c"
#include "../../executor/copier/value/integer_value_copier.c"
#include "../../executor/copier/value/pointer_value_copier.c"
#include "../../executor/copier/value/unsigned_long_value_copier.c"
#include "../../executor/copier/value/wide_character_value_copier.c"
#include "../../executor/arithmetiser/integer_multiplier.c"
#include "../../executor/comparator/count_array_comparator.c"
#include "../../executor/memoriser/size_determiner.c"
#include "../../logger/logger.c"

/**
 * Copies the value.
 *
 * @param p0 the destination value
 * @param p1 the source value
 * @param p2 the operand abstraction
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

                copy_value_character(p0, p1);
            }
        }

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            if (*a == *COMPOUND_PRIMITIVE_MEMORY_ABSTRACTION) {

                r = *NUMBER_1_INTEGER_MEMORY_MODEL;

//??                copy_value_compound(p0, p1, COUNT);
            }
        }

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            if (*a == *DOUBLE_PRIMITIVE_MEMORY_ABSTRACTION) {

                r = *NUMBER_1_INTEGER_MEMORY_MODEL;

                copy_value_double(p0, p1);
            }
        }

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            if (*a == *FRACTION_PRIMITIVE_MEMORY_ABSTRACTION) {

                r = *NUMBER_1_INTEGER_MEMORY_MODEL;

                copy_value_fraction(p0, p1);
            }
        }

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            if (*a == *INTEGER_PRIMITIVE_MEMORY_ABSTRACTION) {

                r = *NUMBER_1_INTEGER_MEMORY_MODEL;

                copy_value_integer(p0, p1);
            }
        }

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            if (*a == *POINTER_PRIMITIVE_MEMORY_ABSTRACTION) {

                r = *NUMBER_1_INTEGER_MEMORY_MODEL;

                copy_value_pointer(p0, p1);
            }
        }

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            if (*a == *UNSIGNED_LONG_PRIMITIVE_MEMORY_ABSTRACTION) {

                r = *NUMBER_1_INTEGER_MEMORY_MODEL;

                copy_value_unsigned_long(p0, p1);
            }
        }

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            if (*a == *WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION) {

                r = *NUMBER_1_INTEGER_MEMORY_MODEL;

                copy_value_wide_character(p0, p1);
            }
        }

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            log_terminated_message((void*) WARNING_LEVEL_LOG_MODEL, (void*) L"Could not copy value. The operand abstraction is unknown.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not copy value. The operand abstraction is null.");
    }
}

/* VALUE_COPIER_SOURCE */
#endif
