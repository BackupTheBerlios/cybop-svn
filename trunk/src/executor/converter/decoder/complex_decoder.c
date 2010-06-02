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
 * @version $RCSfile: complex_converter.c,v $ $Revision: 1.14 $ $Date: 2009-01-31 16:06:33 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef COMPLEX_DECODER_SOURCE
#define COMPLEX_DECODER_SOURCE

#include "../../../constant/model/memory/integer_memory_model.c"
#include "../../../constant/model/log/message_log_model.c"
#include "../../../constant/model/memory/pointer_memory_model.c"
#include "../../../logger/logger.c"

//
// A complex consists of two floats, a real and an imaginary.
//

/**
 * Decodes the byte stream and creates a complex model from it.
 *
 * @param p0 the destination (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source
 * @param p4 the source count
 */
void decode_complex(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p4 != *NULL_POINTER_MEMORY_MODEL) {

        int* sc = (int*) p4;

        if (p3 != *NULL_POINTER_MEMORY_MODEL) {

            void* s = (void*) p3;

            if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                void* d = (void*) p0;

/*??
            //??    log_message((void*) &INFORMATION_LEVEL_LOG_MODEL, (void*) &"Initialise complex.");

            //??    fscanf(p1, %d, (void*) &(t->real));
            //??    fscanf(p1, %d, (void*) &(t->imaginary));

                // Initialise elements.
                int i = *NUMBER_0_INTEGER_MEMORY_MODEL;
                int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

                // Set elements.
                set_array_element(p0, (void*) &DOUBLE_ARRAY, (void*) &REAL_INDEX, (void*) &r);
                set_array_element(p0, (void*) &DOUBLE_ARRAY, (void*) &IMAGINARY_INDEX, (void*) &i);
*/
            } else {

//??                log_message((void*) &ERROR_LEVEL_LOG_MODEL, (void*) &COULD_NOT_PARSE_INTEGER_THE_DESTINATION_IS_NULL_MESSAGE, (void*) &COULD_NOT_PARSE_INTEGER_THE_DESTINATION_IS_NULL_MESSAGE_COUNT);
            }

        } else {

//??            log_message((void*) &ERROR_LEVEL_LOG_MODEL, (void*) &COULD_NOT_PARSE_INTEGER_THE_SOURCE_IS_NULL_MESSAGE, (void*) &COULD_NOT_PARSE_INTEGER_THE_SOURCE_IS_NULL_MESSAGE_COUNT);
        }

    } else {

//??        log_message((void*) &ERROR_LEVEL_LOG_MODEL, (void*) &COULD_NOT_PARSE_INTEGER_THE_SOURCE_COUNT_IS_NULL_MESSAGE, (void*) &COULD_NOT_PARSE_INTEGER_THE_SOURCE_COUNT_IS_NULL_MESSAGE_COUNT);
    }
}

/* COMPLEX_DECODER_SOURCE */
#endif
