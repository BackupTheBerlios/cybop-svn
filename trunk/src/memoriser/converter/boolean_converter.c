/*
 * $RCSfile: boolean_converter.c,v $
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
 * @version $Revision: 1.15 $ $Date: 2007-08-13 16:37:12 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef BOOLEAN_CONVERTER_SOURCE
#define BOOLEAN_CONVERTER_SOURCE

#include "../../globals/constants/boolean/boolean_constants.c"
#include "../../globals/constants/cybol/cybol_model_constants.c"
#include "../../globals/constants/integer/integer_constants.c"
#include "../../globals/constants/log/log_message_constants.c"
#include "../../globals/constants/memory_structure/memory_structure_constants.c"
#include "../../globals/constants/pointer/pointer_constants.c"
#include "../../globals/logger/logger.c"
#include "../../memoriser/allocator.c"
#include "../../memoriser/array.c"

/**
 * Parses the byte stream and creates a boolean model from it.
 *
 * @param p0 the destination (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source
 * @param p4 the source count
 */
void parse_boolean(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p4 != *NULL_POINTER) {

        int* sc = (int*) p4;

        if (p1 != *NULL_POINTER) {

            int* dc = (int*) p1;

            if (p0 != *NULL_POINTER) {

                int** d = (int**) p0;

                log_message_debug("Information: Parse boolean.");

                // The comparison result.
                int r = *NUMBER_0_INTEGER;

                if (r == *NUMBER_0_INTEGER) {

                    compare_array_elements(p3, (void*) TRUE_MODEL, (void*) TRUE_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        // Set boolean value to "true", in other words the integer value to "one".
                        set_array_elements(*d, (void*) PRIMITIVE_VALUE_INDEX, (void*) TRUE_BOOLEAN, (void*) NUMBER_1_INTEGER, (void*) INTEGER_ARRAY);

                        // Increment destination count.
                        *dc = *dc + *NUMBER_1_INTEGER;
                    }
                }

                if (r == *NUMBER_0_INTEGER) {

                    compare_array_elements(p3, (void*) FALSE_MODEL, (void*) FALSE_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        // Set boolean value to "false", in other words the integer value to "zero".
                        set_array_elements(*d, (void*) PRIMITIVE_VALUE_INDEX, (void*) FALSE_BOOLEAN, (void*) NUMBER_1_INTEGER, (void*) INTEGER_ARRAY);

                        // Increment destination count.
                        *dc = *dc + *NUMBER_1_INTEGER;
                    }
                }

                if (r == *NUMBER_0_INTEGER) {

                    // If neither "true" nor "false" value were found, then set
                    // the boolean (integer) value to "false" here, by default.

                    // Set boolean value to "false", in other words the integer value to "zero".
                    set_array_elements(*d, (void*) PRIMITIVE_VALUE_INDEX, (void*) FALSE_BOOLEAN, (void*) NUMBER_1_INTEGER, (void*) INTEGER_ARRAY);

                    // Increment destination count.
                    *dc = *dc + *NUMBER_1_INTEGER;
                }

            } else {

                log_message_debug("Error: Could not parse boolean. The destination is null.");
            }

        } else {

            log_message_debug("Error: Could not parse boolean. The destination count is null.");
        }

    } else {

        log_message_debug("Error: Could not parse boolean. The source count is null.");
    }
}

/**
 * Serialises the boolean model and creates a byte stream from it.
 *
 * @param p0 the destination (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source
 * @param p4 the source count
 */
void serialise_boolean(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p4 != *NULL_POINTER) {

        int* sc = (int*) p4;

        if (p3 != *NULL_POINTER) {

            int* s = (int*) p3;

            if (p2 != *NULL_POINTER) {

                int* ds = (int*) p2;

                if (p1 != *NULL_POINTER) {

                    int* dc = (int*) p1;

                    if (p0 != *NULL_POINTER) {

                        void** d = (void**) p0;

                        log_message_debug("Information: Serialise boolean.");

                        if (*sc > *NUMBER_0_INTEGER) {

                            if (*s == *NUMBER_1_INTEGER) {

                                // Set destination character vector.
                                *ds = *dc + *TRUE_MODEL_COUNT;

                                // Reallocate destination character vector.
                                reallocate_array(p0, p1, p2, (void*) CHARACTER_ARRAY);

                                // Set source into destination character vector.
                                set_array_elements(*d, p1, TRUE_MODEL, TRUE_MODEL_COUNT, (void*) CHARACTER_ARRAY);

                                // Increment destination count.
                                *dc = *dc + *TRUE_MODEL_COUNT;

                            } else {

                                // Set destination character vector.
                                *ds = *dc + *FALSE_MODEL_COUNT;

                                // Reallocate destination character vector.
                                reallocate_array(p0, p1, p2, (void*) CHARACTER_ARRAY);

                                // Set source into destination character vector.
                                set_array_elements(*d, p1, FALSE_MODEL, FALSE_MODEL_COUNT, (void*) CHARACTER_ARRAY);

                                // Increment destination count.
                                *dc = *dc + *FALSE_MODEL_COUNT;
                            }

                        } else {

                            log_message_debug("Error: Could not serialise boolean. The source count is zero.");
                        }

                    } else {

                        log_message_debug("Error: Could not serialise boolean. The destination is null.");
                    }

                } else {

                    log_message_debug("Error: Could not serialise boolean. The destination count is null.");
                }

            } else {

                log_message_debug("Error: Could not serialise boolean. The destination size is null.");
            }

        } else {

            log_message_debug("Error: Could not serialise boolean. The source is null.");
        }

    } else {

        log_message_debug("Error: Could not serialise boolean. The source count is null.");
    }
}

/* BOOLEAN_CONVERTER_SOURCE */
#endif
