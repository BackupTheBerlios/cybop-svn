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
 * @version $RCSfile: double_vector_converter.c,v $ $Revision: 1.24 $ $Date: 2009-01-31 16:06:33 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef DOUBLE_VECTOR_DECODER_SOURCE
#define DOUBLE_VECTOR_DECODER_SOURCE

#include "../../../constant/abstraction/memory/memory_abstraction.c"
#include "../../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../../constant/model/character_code/unicode/unicode_character_code_model.c"
#include "../../../constant/model/log/message_log_model.c"
#include "../../../constant/model/memory/boolean_memory_model.c"
#include "../../../constant/model/memory/integer_memory_model.c"
#include "../../../constant/model/memory/pointer_memory_model.c"
#include "../../../executor/comparator/all/array_all_comparator.c"
#include "../../../executor/memoriser/allocator/model_allocator.c"
#include "../../../executor/memoriser/deallocator/model_deallocator.c"
#include "../../../logger/logger.c"

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

    if (p4 != *NULL_POINTER_MEMORY_MODEL) {

        int* sc = (int*) p4;

        if (p0 != *NULL_POINTER_MEMORY_MODEL ) {

            void** d = (void**) p0;

            log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Decode double.");

            // The temporary null-terminated string.
            void* tmp = *NULL_POINTER_MEMORY_MODEL;
            void* tmpc = *NULL_POINTER_MEMORY_MODEL;
            void* tmps = *NULL_POINTER_MEMORY_MODEL;

            int s = *sc + *NUMBER_1_INTEGER_MEMORY_MODEL;

            // Create temporary null-terminated string.
            allocate_model((void*) &tmp, (void*) &tmpc, (void*) &tmps, (void*) &s, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT);

            // The index.
            int i = *NUMBER_0_INTEGER_MEMORY_MODEL;

            // Copy original string to temporary null-terminated string.
            overwrite_array(tmp, p3, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p4, (void*) &i, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, tmpc, tmps);

            // This is used as index to set the termination character.
            i = *sc;

            // Add string termination to temporary null-terminated string.
            overwrite_array(tmp, (void*) NULL_CONTROL_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) &i, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, tmpc, tmps);

            // The tail variable is useless here and only needed for the string
            // transformation function. If the whole string array consists of
            // many sub strings, separated by space characters, then each sub
            // string gets interpreted as integer number.
            // The tail variable in this case points to the remaining sub string.
            wchar_t* tail = (wchar_t*) *NULL_POINTER_MEMORY_MODEL;

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
            double v = wcstod((wchar_t*) tmp, &tail);

            //?? p0 (Hand over as reference!)
            //?? Doesn't p0 need to be reallocated from size 0 to size 1,
            //?? to be able to take the double value?

            // Set double value.
            overwrite_array(p0, (void*) &v, (void*) DOUBLE_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);

            // Destroy temporary null-terminated string.
            deallocate_model((void*) &tmp, (void*) &tmpc, (void*) &tmps, (void*) &s, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT);

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode double. The destination is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode double. The source count is null.");
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

    if (p4 != *NULL_POINTER_MEMORY_MODEL) {

        int* sc = (int*) p4;

        if (p3 != *NULL_POINTER_MEMORY_MODEL) {

            void** s = (void**) p3;

            if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                void** d = (void**) p0;

                log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Decode double vector.");

/*??
                // The loop count.
                int j = *NUMBER_0_INTEGER_MEMORY_MODEL;
                // The comma index.
                int i = *NUMBER_MINUS_1_INTEGER_MEMORY_MODEL;
                // The double vector element count.
                void* c = *NULL_POINTER_MEMORY_MODEL;
                // The double number.
                int n = *NUMBER_0_INTEGER_MEMORY_MODEL;

                while (*TRUE_BOOLEAN_MEMORY_MODEL) {

                    if (j >= *sc) {

                        break;
                    }

                    get_character_array_elements_index(p3, p4, (void*) COMMA_CHARACTER_CODE, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) &i);

                    if (i > *NUMBER_0_INTEGER_MEMORY_MODEL) {

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

                        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode double vector. The source string starts with a comma character.");
                    }

                    j++;
                }

                // Read input stream and transform to double vector.
                //??    fscanf(p1, %d, &(m->x));
                //??    fscanf(p1, %d, &(m->y));
                //??    fscanf(p1, %d, &(m->z));

                // Initialise elements.
                int z = *NUMBER_0_INTEGER_MEMORY_MODEL;
                int y = *NUMBER_0_INTEGER_MEMORY_MODEL;
                int x = *NUMBER_0_INTEGER_MEMORY_MODEL;

                // Set elements.
                overwrite_array(p0, (void*) INTEGER_ARRAY, (void*) &X_INDEX, (void*) &x);
                overwrite_array(p0, (void*) INTEGER_ARRAY, (void*) &Y_INDEX, (void*) &y);
                overwrite_array(p0, (void*) INTEGER_ARRAY, (void*) &Z_INDEX, (void*) &z);
*/

/*??
                int i1 = s.indexOf(",");

                if (i1 != *NUMBER_MINUS_1_INTEGER_MEMORY_MODEL) {

                    char[] x = s.substring(*NUMBER_0_INTEGER_MEMORY_MODEL, i1);
                    char[] yz = s.substring(i1 + *NUMBER_1_INTEGER_MEMORY_MODEL);
                    int i2 = yz.indexOf(",");

                    if (i2 != *NUMBER_MINUS_1_INTEGER_MEMORY_MODEL) {

                        char[] y = yz.substring(*NUMBER_0_INTEGER_MEMORY_MODEL, i2);
                        char[] z = yz.substring(i2 + *NUMBER_1_INTEGER_MEMORY_MODEL);

                        p.x = java.lang.Integer.parseInt(x);
                        p.y = java.lang.Integer.parseInt(y);
                        p.z = java.lang.Integer.parseInt(z);

                    } else {

            //??            log_message((void*) &ERROR_LEVEL_LOG_MODEL, (void*) &"Could not create double vector. The vector does not contain a z coordinate.");
                    }

                } else {

            //??        log_message((void*) &ERROR_LEVEL_LOG_MODEL, (void*) &"Could not create double vector. The vector does not contain an y coordinate.");
                }
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

/* DOUBLE_VECTOR_DECODER_SOURCE */
#endif
