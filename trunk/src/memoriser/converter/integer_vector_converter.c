/*
 * $RCSfile: integer_vector_converter.c,v $
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
 * @version $Revision: 1.2 $ $Date: 2005-08-01 09:09:07 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef INTEGER_VECTOR_CONVERTER_SOURCE
#define INTEGER_VECTOR_CONVERTER_SOURCE

#include "../../globals/constants/character_constants.c"
#include "../../globals/constants/log_constants.c"
#include "../../globals/logger/logger.c"
#include "../../memoriser/converter/integer_converter.c"

/**
 * Parses the byte stream and creates an integer vector model from it.
 *
 * @param p0 the destination vector model (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source byte stream
 * @param p4 the source count
 */
void parse_integer_vector(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p4 != NULL_POINTER) {

        int* sc = (int*) p4;

        if (p3 != NULL_POINTER) {

            void** s = (void**) p3;

            if (p0 != NULL_POINTER) {

                void** d = (void**) p0;

                log_message_debug("Parse integer vector.");

                // The loop count.
                int j = 0;
                // The comma index.
                int i = -1;
                // The integer number.
                void* n = NULL_POINTER;
                int nc = NULL_POINTER;
                int ns = NULL_POINTER;
                // The integer vector element count.
                void* c = NULL_POINTER;
                // The integer number.
                int n = 0;

                // Loop through source string containing comma-separated integers.
                while (1) {

                    if (j >= *sc) {

                        break;
                    }

                    // Find comma character index.
                    get_array_elements_index(p3, p4, (void*) COMMA_CHARACTER, (void*) COMMA_CHARACTER_COUNT, (void*) &i, (void*) CHARACTER_ARRAY);

                    if (i > 0) {

                        // Determine integer vector element count.
                        c = *s + i;

                        // Parse integer.
                        // Example:
                        // Vector elements: "200,300,400"
                        // The number 200 character array length is 3.
                        // Index of first comma: 3
                        // Handed over as vector element (source) count: index i
                        // (which is 3, as needed for the length)
                        parse_integer((void*) &n, (void*) INTEGER_COUNT, (void*) INTEGER_COUNT, p3, (void*) &i);

                        // Add integer to integer vector.

                        // Assign part string with new, shorter count to local variables.

                        // Recursively call this procedure for the remaining integer vector elements.
                        parse_integer_vector(d, dc, ds, new_start_vector, sc);
                        // Recursively process further integers found in the vector.
                        // Hand over increased pointer, pointing to next integer element,
                        // and its remaining size, cut shorter.
                        parse_integer_vector();

                    } else {

                        log_message_debug("Could not parse integer vector. The source string starts with a comma character.");
                    }

                    j++;
                }

/*??
                // Read input stream and transform to integer vector.
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

            //??            log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not create integer vector. The vector does not contain a z coordinate.");
                    }

                } else {

            //??        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not create integer vector. The vector does not contain an y coordinate.");
                }
*/

            } else {

                log_message_debug("Could not parse integer vector. The destination is null.");
            }

        } else {

            log_message_debug("Could not parse integer vector. The source is null.");
        }

    } else {

        log_message_debug("Could not parse integer vector. The source count is null.");
    }
}

/**
 * Serialises the integer vector model and creates a byte stream from it.
 *
 * @param p0 the destination byte stream (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source vector model
 * @param p4 the source count
 */
void serialise_integer_vector(void* p0, void* p1, void* p2, void* p3, void* p4) {

/*??
//??    log_message((void*) &INFO_LOG_LEVEL, (void*) &"Finalise integer vector.");

    // Write output stream and transform from integer vector.

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

/* INTEGER_VECTOR_CONVERTER_SOURCE */
#endif
