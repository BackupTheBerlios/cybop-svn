/*
 * $RCSfile: double_vector_converter.c,v $
 *
 * Copyright (c) 1999-2005. Christian Heller and the CYBOP developers.
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
 * @version $Revision: 1.1 $ $Date: 2005-07-28 12:52:13 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef DOUBLE_VECTOR_CONVERTER_SOURCE
#define DOUBLE_VECTOR_CONVERTER_SOURCE

#include "../../globals/constants/character_constants.c"
#include "../../globals/constants/log_constants.c"
#include "../../globals/logger/logger.c"

/**
 * Parses the byte stream and creates a double vector model from it.
 *
 * @param p0 the destination vector model (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source byte stream
 * @param p4 the source count
 */
void parse_double_vector(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p4 != NULL_POINTER) {

        int* sc = (int*) p4;

        if (p3 != NULL_POINTER) {

            void** s = (void**) p3;

            if (p0 != NULL_POINTER) {

                void** d = (void**) p0;

                log_message_debug("Parse double vector.");

/*??
                // The loop count.
                int j = 0;
                // The comma index.
                int i = -1;
                // The double vector element count.
                void* c = NULL_POINTER;
                // The double number.
                int n = 0;

                while (1) {

                    if (j >= *sc) {

                        break;
                    }

                    get_character_array_elements_index(p3, p4, (void*) COMMA_CHARACTER, (void*) COMMA_CHARACTER_COUNT, (void*) &i);

                    if (i > 0) {

                        // Determine double vector element count.
                        c = *s + i;

                        // Example:
                        // Vector elements: "200,300,400"
                        // The number 200 character array length is 3.
                        // Index of first comma: 3
                        // Handed over as vector element (source) count: index i
                        // (which is 3, as needed for the length)
                        parse_double(d, dc, ds, p3, &i);

                        // Recursively call this procedure for the remaining double vector elements.
                        parse_double_vector(d, dc, ds, new_start_vector, sc);

                    } else {

                        log_message_debug("ERROR: Could not parse double vector. The source string starts with a comma character.");
                    }

                    j++;
                }

                // Read input stream and transform to double vector.
                //??    fscanf(p1, %d, &(m->x));
                //??    fscanf(p1, %d, &(m->y));
                //??    fscanf(p1, %d, &(m->z));

                // Initialise elements.
                int z = 0;
                int y = 0;
                int x = 0;

                // Set elements.
                set_array_elements(p0, (void*) INTEGER_ARRAY, (void*) &X_INDEX, (void*) &x);
                set_array_elements(p0, (void*) INTEGER_ARRAY, (void*) &Y_INDEX, (void*) &y);
                set_array_elements(p0, (void*) INTEGER_ARRAY, (void*) &Z_INDEX, (void*) &z);
*/

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

            //??            log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not create double vector. The vector does not contain a z coordinate.");
                    }

                } else {

            //??        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not create double vector. The vector does not contain an y coordinate.");
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
 * Serialises the double vector model and creates a byte stream from it.
 *
 * @param p0 the destination byte stream (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source vector model
 * @param p4 the source count
 */
void serialise_double_vector(void* p0, void* p1, void* p2, void* p3, void* p4) {

/*??
//??    log_message((void*) &INFO_LOG_LEVEL, (void*) &"Finalise double vector.");

    // Write output stream and transform from double vector.

    // Initialise elements.
    int z = 0;
    int y = 0;
    int x = 0;

    // Get elements.
    get_array_elements(p0, (void*) INTEGER_ARRAY, (void*) &Z_INDEX, (void*) &z);
    get_array_elements(p0, (void*) INTEGER_ARRAY, (void*) &Y_INDEX, (void*) &y);
    get_array_elements(p0, (void*) INTEGER_ARRAY, (void*) &X_INDEX, (void*) &x);

    // Remove elements.
    remove_array_elements(p0, (void*) INTEGER_ARRAY, (void*) &INTEGER_VECTOR_COUNT, (void*) &Z_INDEX);
    remove_array_elements(p0, (void*) INTEGER_ARRAY, (void*) &INTEGER_VECTOR_COUNT, (void*) &Y_INDEX);
    remove_array_elements(p0, (void*) INTEGER_ARRAY, (void*) &INTEGER_VECTOR_COUNT, (void*) &X_INDEX);

//??    fprintf(p1, %d, &(m->x));
//??    fprintf(p1, %d, &(m->y));
//??    fprintf(p1, %d, &(m->z));
*/
}

/* DOUBLE_VECTOR_CONVERTER_SOURCE */
#endif
