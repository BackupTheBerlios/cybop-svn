/*
 * $RCSfile: vector_parser.c,v $
 *
 * Copyright (c) 1999-2004. Christian Heller. All rights reserved.
 *
 * This software is published under the GPL GNU General Public License.
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
 * @version $Revision: 1.2 $ $Date: 2004-08-23 07:18:33 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef VECTOR_PARSER_SOURCE
#define VECTOR_PARSER_SOURCE

#include "../global/log_constants.c"
#include "../logger/logger.c"

//
// A vector contains the three coordinates: x, y, z.
//

/**
 * Parses the byte stream and creates a vector model from it.
 *
 * @param p0 the destination
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source
 * @param p4 the source count
 */
void parse_vector(void* p0, void* p1, void* p2, const void* p3, const void* p4) {

    if (p4 != NULL_POINTER) {

        int* sc = (int*) p4;

        if (p3 != NULL_POINTER) {

            void** s = (void**) p3;

            if (p0 != NULL_POINTER) {

                void** d = (void**) p0;

/*??
            //??    log_message((void*) &INFO_LOG_LEVEL, (void*) &"Initialize vector.");

                // Read input stream and transform to vector.
            //??    fscanf(p1, %d, &(m->x));
            //??    fscanf(p1, %d, &(m->y));
            //??    fscanf(p1, %d, &(m->z));

                // Initialize elements.
                int z = 0;
                int y = 0;
                int x = 0;

                // Set elements.
                set_array_element(p0, (void*) &INTEGER_ARRAY, (void*) &X_INDEX, (void*) &x);
                set_array_element(p0, (void*) &INTEGER_ARRAY, (void*) &Y_INDEX, (void*) &y);
                set_array_element(p0, (void*) &INTEGER_ARRAY, (void*) &Z_INDEX, (void*) &z);

/*??
                int i1 = s.indexOf(",");

                if (i1 != -1) {

                    char[] x = s.substring(0, i1);
                    char[] yz = s.substring(i1 + 1);
                    int i2 = yz.indexOf(",");

                    if (i2 != -1) {

                        char[] y = yz.substring(0, i2);
                        char[] z = yz.substring(i2 + 1);

                        p.x = java.lang.Integer.parseInt(x);
                        p.y = java.lang.Integer.parseInt(y);
                        p.z = java.lang.Integer.parseInt(z);

                    } else {

            //??            log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not create vector. The vector does not contain a z coordinate.");
                    }

                } else {

            //??        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not create vector. The vector does not contain an y coordinate.");
                }
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
 * Serializes the vector model and creates a byte stream from it.
 *
 * @param p0 the destination
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source
 * @param p4 the source count
 */
void serialize_vector(void* p0, void* p1, void* p2, const void* p3, const void* p4) {

/*??
            //??    log_message((void*) &INFO_LOG_LEVEL, (void*) &"Finalize vector.");

                // Write output stream and transform from vector.

                // Initialize elements.
                int z = 0;
                int y = 0;
                int x = 0;

                // Get elements.
                get_array_element(p0, (void*) &INTEGER_ARRAY, (void*) &Z_INDEX, (void*) &z);
                get_array_element(p0, (void*) &INTEGER_ARRAY, (void*) &Y_INDEX, (void*) &y);
                get_array_element(p0, (void*) &INTEGER_ARRAY, (void*) &X_INDEX, (void*) &x);

                // Remove elements.
                remove_array_element(p0, (void*) &INTEGER_ARRAY, (void*) &VECTOR_COUNT, (void*) &Z_INDEX);
                remove_array_element(p0, (void*) &INTEGER_ARRAY, (void*) &VECTOR_COUNT, (void*) &Y_INDEX);
                remove_array_element(p0, (void*) &INTEGER_ARRAY, (void*) &VECTOR_COUNT, (void*) &X_INDEX);

            //??    fprintf(p1, %d, &(m->x));
            //??    fprintf(p1, %d, &(m->y));
            //??    fprintf(p1, %d, &(m->z));
*/
}

/* VECTOR_PARSER_SOURCE */
#endif
