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
 * @version $RCSfile: complex_converter.c,v $ $Revision: 1.14 $ $Date: 2009-01-31 16:06:33 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef COMPLEX_ENCODER_SOURCE
#define COMPLEX_ENCODER_SOURCE

#include "../../../constant/model/memory/integer_memory_model.c"
#include "../../../constant/model/log/message_log_model.c"
#include "../../../constant/model/memory/pointer_memory_model.c"
#include "../../../logger/logger.c"

/**
 * Encodes the complex model and creates a byte stream from it.
 *
 * @param p0 the destination (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source
 * @param p4 the source count
 */
void encode_complex(void* p0, void* p1, void* p2, void* p3, void* p4) {

/*??
    //??    log_message((void*) &INFORMATION_LEVEL_LOG_MODEL, (void*) &"Finalise complex.");

    // Initialise elements.
    int i = *NUMBER_0_INTEGER_MEMORY_MODEL;
    int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

    // Get elements.
    get_array_element(p0, (void*) &DOUBLE_ARRAY, (void*) &IMAGINARY_INDEX, (void*) &i);
    get_array_element(p0, (void*) &DOUBLE_ARRAY, (void*) &REAL_INDEX, (void*) &r);

    // Remove elements.
    remove_array_element(p0, (void*) &DOUBLE_ARRAY, (void*) &COMPLEX_MEMORY_MODEL_COUNT, (void*) &IMAGINARY_INDEX);
    remove_array_element(p0, (void*) &DOUBLE_ARRAY, (void*) &COMPLEX_MEMORY_MODEL_COUNT, (void*) &REAL_INDEX);

    //??    fwprintf(p1, %d, (void*) &(t->real));
    //??    fwprintf(p1, %d, (void*) &(t->imaginary));
*/
}

/* COMPLEX_ENCODER_SOURCE */
#endif
