/*
 * $RCSfile: double_vector_converter.c,v $
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
 * @version $Revision: 1.14 $ $Date: 2007-10-03 23:40:06 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef DOUBLE_VECTOR_CONVERTER_SOURCE
#define DOUBLE_VECTOR_CONVERTER_SOURCE

#include <string.h>
#include "../../globals/constants/character/character_constants.c"
#include "../../globals/constants/integer/integer_constants.c"
#include "../../globals/constants/log/log_message_constants.c"
#include "../../globals/constants/memory_structure/memory_structure_constants.c"
#include "../../globals/constants/pointer/pointer_constants.c"
#include "../../globals/logger/logger.c"
#include "../../memoriser/array.c"

/**
 * Decodes the byte stream and creates a double model from it.
 *
 * @param p0 the destination (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source
 * @param p4 the source count
 */
void decode_double(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p4 != *NULL_POINTER) {

        int* sc = (int*) p4;

        if (p0 != *NULL_POINTER ) {

            void** d = (void**) p0;

            log_terminated_message((void*) INFORMATION_LOG_LEVEL, (void*) "Decode double.");

            // The temporary null-terminated string.
            char* tmp = (char*) *NULL_POINTER;
            int tmps = *sc + *NUMBER_1_INTEGER;

            // Create temporary null-terminated string.
            allocate_array((void*) &tmp, (void*) &tmps, (void*) CHARACTER_ARRAY);

            // The index.
            int i = *NUMBER_0_INTEGER;

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
            char* tail = (char*) *NULL_POINTER;

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

            log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) "Could not decode double. The destination is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) "Could not decode double. The source count is null.");
    }
}

/**
 * Encodes the double model and creates a byte stream from it.
 *
 * @param p0 the destination (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source
 * @param p4 the source count
 */
void encode_double(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p2 != *NULL_POINTER) {

        int* ds = (int*) p2;

        if (p1 != *NULL_POINTER) {

            int* dc = (int*) p1;

            if (p0 != *NULL_POINTER) {

                char** d = (char**) p0;

                log_terminated_message((void*) INFORMATION_LOG_LEVEL, (void*) "Encode double.");

                // The double value.
                double* v = (double*) *NULL_POINTER;

                // Get double value.
                get_array_elements(p3, (void*) PRIMITIVE_VALUE_INDEX, (void*) &v, (void*) DOUBLE_ARRAY);

                //?? TODO: set_array_elements is missing!
                //?? The get_array_elements procedure does NOT copy values;
                //?? it returns just a reference to the corresponding value!

                // Transform source double to destination string.
                *dc = snprintf(*d, *ds, "%d", *v);

                // Set destination string size one greater than the count
                // to have space for the terminating null character.
                *ds = *dc + *NUMBER_1_INTEGER;

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
 * Decodes the byte stream and creates a double vector model from it.
 *
 * @param p0 the destination vector model (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source byte stream
 * @param p4 the source count
 */
void decode_double_vector(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p4 != *NULL_POINTER) {

        int* sc = (int*) p4;

        if (p3 != *NULL_POINTER) {

            void** s = (void**) p3;

            if (p0 != *NULL_POINTER) {

                void** d = (void**) p0;

                log_terminated_message((void*) INFORMATION_LOG_LEVEL, (void*) "Decode double vector.");

/*??
                // The loop count.
                int j = *NUMBER_0_INTEGER;
                // The comma index.
                int i = *NUMBER_MINUS_1_INTEGER;
                // The double vector element count.
                void* c = *NULL_POINTER;
                // The double number.
                int n = *NUMBER_0_INTEGER;

                while (*NUMBER_1_INTEGER) {

                    if (j >= *sc) {

                        break;
                    }

                    get_character_array_elements_index(p3, p4, (void*) COMMA_CHARACTER, (void*) PRIMITIVE_COUNT, (void*) &i);

                    if (i > *NUMBER_0_INTEGER) {

                        // Determine double vector element count.
                        c = *s + i;

                        // Example:
                        // Vector elements: "200,300,400"
                        // The number 200 character array length is 3.
                        // Index of first comma: 3
                        // Handed over as vector element (source) count: index i
                        // (which is 3, as needed for the length)
                        decode_double(d, dc, ds, p3, &i);

                        // Recursively call this procedure for the remaining double vector elements.
                        decode_double_vector(d, dc, ds, new_start_vector, sc);

                    } else {

                        log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) "Could not decode double vector. The source string starts with a comma character.");
                    }

                    j++;
                }

                // Read input stream and transform to double vector.
                //??    fscanf(p1, %d, &(m->x));
                //??    fscanf(p1, %d, &(m->y));
                //??    fscanf(p1, %d, &(m->z));

                // Initialise elements.
                int z = *NUMBER_0_INTEGER;
                int y = *NUMBER_0_INTEGER;
                int x = *NUMBER_0_INTEGER;

                // Set elements.
                set_array_elements(p0, (void*) INTEGER_ARRAY, (void*) &X_INDEX, (void*) &x);
                set_array_elements(p0, (void*) INTEGER_ARRAY, (void*) &Y_INDEX, (void*) &y);
                set_array_elements(p0, (void*) INTEGER_ARRAY, (void*) &Z_INDEX, (void*) &z);
*/

/*??
                int i1 = s.indexOf(",");

                if (i1 != *NUMBER_MINUS_1_INTEGER) {

                    char[] x = s.substring(*NUMBER_0_INTEGER, i1);
                    char[] yz = s.substring(i1 + *NUMBER_1_INTEGER);
                    int i2 = yz.indexOf(",");

                    if (i2 != *NUMBER_MINUS_1_INTEGER) {

                        char[] y = yz.substring(*NUMBER_0_INTEGER, i2);
                        char[] z = yz.substring(i2 + *NUMBER_1_INTEGER);

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
 * Encodes the double vector model and creates a byte stream from it.
 *
 * @param p0 the destination byte stream (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source vector model
 * @param p4 the source count
 */
void encode_double_vector(void* p0, void* p1, void* p2, void* p3, void* p4) {

/*??
//??    log_message((void*) &INFORMATION_LOG_LEVEL, (void*) &"Finalise double vector.");

    // Write output stream and transform from double vector.

    // Initialise elements.
    int z = *NUMBER_0_INTEGER;
    int y = *NUMBER_0_INTEGER;
    int x = *NUMBER_0_INTEGER;

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
