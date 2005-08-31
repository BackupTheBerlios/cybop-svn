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
 * @version $Revision: 1.3 $ $Date: 2005-08-31 14:50:18 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef DOUBLE_VECTOR_CONVERTER_SOURCE
#define DOUBLE_VECTOR_CONVERTER_SOURCE

#include <string.h>
//?? #include <stdio.h>
//?? #include <stdlib.h>
#include "../../globals/constants/character_constants.c"
//?? #include "../../globals/constants/integer_constants.c"
#include "../../globals/constants/log_constants.c"
#include "../../globals/constants/structure_constants.c"
#include "../../globals/logger/logger.c"
//?? #include "../../memoriser/allocator.c"
#include "../../memoriser/array.c"

/**
 * Parses the byte stream and creates a double model from it.
 *
 * @param p0 the destination (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source
 * @param p4 the source count
 */
void parse_double(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p4 != NULL_POINTER) {

        int* sc = (int*) p4;

        if (p0 != NULL_POINTER ) {

            void** d = (void**) p0;

            log_message_debug("Parse double.");

            // The temporary null-terminated string.
            char* tmp = NULL_POINTER;
            int tmps = *sc + 1;

            // Create temporary null-terminated string.
            allocate_array((void*) &tmp, (void*) &tmps, (void*) CHARACTER_ARRAY);

            // The index.
            int i = 0;

            // Copy original string to temporary null-terminated string.
            set_array_elements((void*) tmp, (void*) &i, p3, p4, (void*) CHARACTER_ARRAY);

            // This is used as index to set the termination character.
            i = *sc;

            // Add string termination to temporary null-terminated string.
            set_array_elements((void*) tmp, (void*) &i, (void*) NULL_CONTROL_CHARACTER, (void*) NUMBER_1_INTEGER, (void*) CHARACTER_ARRAY);

            // The tail variable is useless here and only needed for the string
            // transformation function. If the whole string array consists of
            // many sub strings, separated by space characters, then each sub
            // string gets interpreted as integer number.
            // The tail variable in this case points to the remaining sub string.
            char* tail = NULL_POINTER;

            // Transform string to double value.
            // The strtod function recognizes four special input strings.
            // The strings "inf" and "infinity" are converted to @math{@infinity{}},
            // or to the largest representable value if the floating-point format
            // doesn't support infinities.
            // One can prepend a "+" or "-" to specify the sign.
            // Case is ignored when scanning these strings.
            // The strings "nan" and "nan(chars...)" are converted to NaN.
            // Again, case is ignored.
            // If chars... are provided, they are used in some unspecified fashion
            // to select a particular representation of NaN (there can be several).
            double v = strtod(tmp, &tail);

            //?? p0 (Hand over as reference!)
            //?? Doesn't p0 need to be reallocated from size 0 to size 1,
            //?? to be able to take the double value?

            // Set double value.
            set_array_elements(*d, (void*) PRIMITIVE_VALUE_INDEX, (void*) &v, (void*) NUMBER_1_INTEGER, (void*) DOUBLE_ARRAY);

            // Destroy temporary null-terminated string.
            deallocate_array((void*) &tmp, (void*) &tmps, (void*) CHARACTER_ARRAY);

        } else {

            log_message_debug("Could not parse double. The destination is null.");
        }

    } else {

        log_message_debug("Could not parse double. The source count is null.");
    }
}

/**
 * Serialises the double model and creates a byte stream from it.
 *
 * @param p0 the destination (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source
 * @param p4 the source count
 */
void serialise_double(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p2 != NULL_POINTER) {

        int* ds = (int*) p2;

        if (p1 != NULL_POINTER) {

            int* dc = (int*) p1;

            if (p0 != NULL_POINTER) {

                char** d = (char**) p0;

                log_message_debug("Serialise double.");

                // The double value.
                double* v = NULL_POINTER;

                // Get double value.
                get_array_elements(p3, (void*) PRIMITIVE_VALUE_INDEX, (void*) &v, (void*) DOUBLE_ARRAY);

                //?? TODO: set_array_elements is missing!
                //?? The get_array_elements procedure does NOT copy values;
                //?? it returns just a reference to the corresponding value!

                // Transform source double to destination string.
                *dc = snprintf(*d, *ds, "%d", *v);

                // Set destination string size one greater than the count
                // to have space for the terminating null character.
                *ds = *dc + 1;

                // Reallocate destination string.
                reallocate_array(p0, p1, p2, (void*) CHARACTER_ARRAY);

                // Transform source double to destination string.
                *dc = snprintf(*d, *ds, "%d", *v);

                // CAUTION! Recalculate string count because only in versions
                // of the GNU C library prior to 2.1, the snprintf function
                // returns the number of characters stored, not including the
                // terminating null; unless there was not enough space in the
                // string to store the result in which case -1 is returned.
                // This was CHANGED in order to comply with the ISO C99 standard.
                // As usual, the string count does NOT contain the terminating
                // null character.
                *dc = strlen(*d);

            } else {

//??                log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_PARSE_INTEGER_THE_DESTINATION_IS_NULL_MESSAGE, (void*) &COULD_NOT_PARSE_INTEGER_THE_DESTINATION_IS_NULL_MESSAGE_COUNT);
            }

        } else {

//??            log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_PARSE_INTEGER_THE_DESTINATION_COUNT_IS_NULL_MESSAGE, (void*) &COULD_NOT_PARSE_INTEGER_THE_DESTINATION_COUNT_IS_NULL_MESSAGE_COUNT);
        }

    } else {

//??        log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_PARSE_INTEGER_THE_DESTINATION_SIZE_IS_NULL_MESSAGE, (void*) &COULD_NOT_PARSE_INTEGER_THE_DESTINATION_SIZE_IS_NULL_MESSAGE_COUNT);
    }
}

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

                    get_character_array_elements_index(p3, p4, (void*) COMMA_CHARACTER, (void*) CHARACTER_COUNT, (void*) &i);

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
