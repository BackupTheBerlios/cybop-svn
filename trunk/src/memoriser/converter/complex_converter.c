/*
 * $RCSfile: complex_converter.c,v $
 *
 * Copyright (c) 1999-2007. Christian Heller and the CYBOP developers.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 *
 * http://www.cybop.net
 * - Cybernetics Oriented Programming -
 *
 * @version $Revision: 1.5 $ $Date: 2007-01-14 22:06:49 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef COMPLEX_CONVERTER_SOURCE
#define COMPLEX_CONVERTER_SOURCE

#include "../../globals/constants/log_constants.c"
#include "../../globals/logger/logger.c"

//
// A complex consists of two floats, a real and an imaginary.
//

/**
 * Parses the byte stream and creates a complex model from it.
 *
 * @param p0 the destination (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source
 * @param p4 the source count
 */
void parse_complex(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p4 != NULL_POINTER) {

        int* sc = (int*) p4;

        if (p3 != NULL_POINTER) {

            void* s = (void*) p3;

            if (p0 != NULL_POINTER) {

                void* d = (void*) p0;

/*??
            //??    log_message((void*) &INFO_LOG_LEVEL, (void*) &"Initialise complex.");

            //??    fscanf(p1, %d, (void*) &(t->real));
            //??    fscanf(p1, %d, (void*) &(t->imaginary));

                // Initialise elements.
                int i = 0;
                int r = 0;

                // Set elements.
                set_array_element(p0, (void*) &DOUBLE_ARRAY, (void*) &REAL_INDEX, (void*) &r);
                set_array_element(p0, (void*) &DOUBLE_ARRAY, (void*) &IMAGINARY_INDEX, (void*) &i);
*/
            } else {

//??                log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_PARSE_INTEGER_THE_DESTINATION_IS_NULL_MESSAGE, (void*) &COULD_NOT_PARSE_INTEGER_THE_DESTINATION_IS_NULL_MESSAGE_COUNT);
            }

        } else {

//??            log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_PARSE_INTEGER_THE_SOURCE_IS_NULL_MESSAGE, (void*) &COULD_NOT_PARSE_INTEGER_THE_SOURCE_IS_NULL_MESSAGE_COUNT);
        }

    } else {

//??        log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_PARSE_INTEGER_THE_SOURCE_COUNT_IS_NULL_MESSAGE, (void*) &COULD_NOT_PARSE_INTEGER_THE_SOURCE_COUNT_IS_NULL_MESSAGE_COUNT);
    }
}

/**
 * Serialises the complex model and creates a byte stream from it.
 *
 * @param p0 the destination (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source
 * @param p4 the source count
 */
void serialise_complex(void* p0, void* p1, void* p2, void* p3, void* p4) {

/*??
            //??    log_message((void*) &INFO_LOG_LEVEL, (void*) &"Finalise complex.");

                // Initialise elements.
                int i = 0;
                int r = 0;

                // Get elements.
                get_array_element(p0, (void*) &DOUBLE_ARRAY, (void*) &IMAGINARY_INDEX, (void*) &i);
                get_array_element(p0, (void*) &DOUBLE_ARRAY, (void*) &REAL_INDEX, (void*) &r);

                // Remove elements.
                remove_array_element(p0, (void*) &DOUBLE_ARRAY, (void*) &COMPLEX_COUNT, (void*) &IMAGINARY_INDEX);
                remove_array_element(p0, (void*) &DOUBLE_ARRAY, (void*) &COMPLEX_COUNT, (void*) &REAL_INDEX);

            //??    fprintf(p1, %d, (void*) &(t->real));
            //??    fprintf(p1, %d, (void*) &(t->imaginary));
*/
}

/* COMPLEX_CONVERTER_SOURCE */
#endif
