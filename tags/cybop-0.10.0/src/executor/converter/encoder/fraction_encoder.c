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
 * @version $RCSfile: fraction_converter.c,v $ $Revision: 1.14 $ $Date: 2009-01-31 16:06:33 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef FRACTION_ENCODER_SOURCE
#define FRACTION_ENCODER_SOURCE

#include "../../../constant/model/memory/integer_memory_model.c"
#include "../../../constant/model/log/message_log_model.c"
#include "../../../constant/model/memory/pointer_memory_model.c"
#include "../../../logger/logger.c"

/**
 * Encodes the fraction model and creates a byte stream from it.
 *
 * @param p0 the destination (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source
 * @param p4 the source count
 */
void encode_fraction(void* p0, void* p1, void* p2, void* p3, void* p4) {

/*??
    //?? log_message((void*) &INFORMATION_LEVEL_LOG_MODEL, (void*) &"Finalise fraction.");

    // Initialise elements.
    int d = *NUMBER_0_INTEGER_MEMORY_MODEL;
    int n = *NUMBER_0_INTEGER_MEMORY_MODEL;

    // Get elements.
    get_array_element(p0, (void*) &INTEGER_ARRAY, (void*) &DENOMINATOR_INDEX, (void*) &d);
    get_array_element(p0, (void*) &INTEGER_ARRAY, (void*) &NUMERATOR_INDEX, (void*) &n);

    // Remove elements.
    remove_array_element(p0, (void*) &INTEGER_ARRAY, (void*) &FRACTION_MEMORY_MODEL_COUNT, (void*) &DENOMINATOR_INDEX);
    remove_array_element(p0, (void*) &INTEGER_ARRAY, (void*) &FRACTION_MEMORY_MODEL_COUNT, (void*) &NUMERATOR_INDEX);

//??    sprintf(p1, %l, (void*) &(m->value));
*/
}

/* FRACTION_ENCODER_SOURCE */
#endif