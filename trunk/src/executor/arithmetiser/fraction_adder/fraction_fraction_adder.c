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
 * @version $RCSfile: integer_adder.c,v $ $Revision: 1.1 $ $Date: 2009-10-06 21:25:26 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef FRACTION_FRACTION_ADDER_SOURCE
#define FRACTION_FRACTION_ADDER_SOURCE

#include "../../../constant/model/log/message_log_model.c"
#include "../../../constant/model/memory/pointer_memory_model.c"
#include "../../../logger/logger.c"

/**
 * Adds the source fraction to the destination fraction.
 *
 * @param p0 the destination fraction
 * @param p1 the source fraction
 */
void add_fraction_to_fraction(void* p0, void* p1) {

    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Add fraction to fraction.");

    // The destination numerator and denominator.
    void** dn = POINTER_MEMORY_ABSTRACTION;
    void** dd = POINTER_MEMORY_ABSTRACTION;
    // The source numerator and denominator.
    void** sn = POINTER_MEMORY_ABSTRACTION;
    void** sd = POINTER_MEMORY_ABSTRACTION;

    // Get destination numerator and denominator.
    get((void*) &dn, p0, (void*) NUMERATOR_FRACTION_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);
    get((void*) &dd, p0, (void*) DENOMINATOR_FRACTION_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);
    // Get source numerator and denominator.
    get((void*) &sn, p1, (void*) NUMERATOR_FRACTION_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);
    get((void*) &sd, p1, (void*) DENOMINATOR_FRACTION_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);

    // Expand numerators by multiplying them with denominators cross-wise.
    multiply_integer(*dn, *sd, (void*) INTEGER_PRIMITIVE_MEMORY_ABSTRACTION);
    //?? CAUTION! The *sn should NOT be altered!
    //?? Solve this with a temporary allocated integer variable?
    multiply_integer(*sn, *dd, (void*) INTEGER_PRIMITIVE_MEMORY_ABSTRACTION);

    // Add numerators and multiply denominators.
    add_integer(*dn, *sn, (void*) INTEGER_PRIMITIVE_MEMORY_ABSTRACTION);
    multiply_integer(*dd, *sd, (void*) INTEGER_PRIMITIVE_MEMORY_ABSTRACTION);

    reduce_fraction(p0);
}

/* FRACTION_FRACTION_ADDER_SOURCE */
#endif
