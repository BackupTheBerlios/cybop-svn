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

#ifndef ADD_FRACTION_CALCULATOR_SOURCE
#define ADD_FRACTION_CALCULATOR_SOURCE

#include "../../../../constant/model/log/message_log_model.c"
#include "../../../../constant/model/memory/integer_memory_model.c"
#include "../../../../constant/model/memory/pointer_memory_model.c"
#include "../../../../logger/logger.c"

/**
 * Adds the source fraction to the destination fraction.
 *
 * @param p0 the destination fraction
 * @param p1 the source fraction
 */
void calculate_fraction_add(void* p0, void* p1) {

    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Calculate fraction add.");

    // The destination numerator and denominator.
    void* dn = *NULL_POINTER_MEMORY_MODEL;
    void* dd = *NULL_POINTER_MEMORY_MODEL;
    // The source numerator and denominator.
    void* sn = *NULL_POINTER_MEMORY_MODEL;
    void* sd = *NULL_POINTER_MEMORY_MODEL;

    // Get destination numerator and denominator.
    copy_array_forward((void*) &dn, p0, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) NUMERATOR_FRACTION_MEMORY_NAME);
    copy_array_forward((void*) &dd, p0, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) DENOMINATOR_FRACTION_MEMORY_NAME);
    // Get source numerator and denominator.
    copy_array_forward((void*) &sn, p1, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) NUMERATOR_FRACTION_MEMORY_NAME);
    copy_array_forward((void*) &sd, p1, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) DENOMINATOR_FRACTION_MEMORY_NAME);

    // The temporary source numerator value.
    // CAUTION! The original *sn should NOT be altered, since a
    // source should always be left untouched (read-only).
    int tsn = *NUMBER_0_INTEGER_MEMORY_MODEL;
    // Copy temporary source numerator value.
    copy_integer((void*) &tsn, sn);

    // Expand numerators by multiplying them with denominators cross-wise.
    calculate_integer_multiply(dn, sd);
    calculate_integer_multiply((void*) &tsn, dd);

    // Add numerators and multiply denominators.
    calculate_integer_add(*dn, *tsn);
    calculate_integer_multiply(*dd, *sd);

    reduce_fraction(p0);
}

/* ADD_FRACTION_CALCULATOR_SOURCE */
#endif
