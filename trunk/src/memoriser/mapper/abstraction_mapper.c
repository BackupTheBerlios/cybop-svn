/*
 * $RCSfile: abstraction_mapper.c,v $
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
 * @version $Revision: 1.2 $ $Date: 2007-07-29 01:53:30 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef ABSTRACTION_MAPPER_SOURCE
#define ABSTRACTION_MAPPER_SOURCE

#include "../../globals/constants/cybol/cybol_abstraction_constants.c"
#include "../../globals/constants/log/log_message_constants.c"
#include "../../globals/constants/memory_structure/memory_abstraction_constants.c"
#include "../../globals/constants/pointer/pointer_constants.c"
#include "../../globals/logger/logger.c"
#include "../../memoriser/array.c"

/**
 * Maps the serialised cybol abstraction into a runtime cyboi abstraction.
 *
 * @param p0 the destination runtime cyboi abstraction
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source serialised cybol abstraction
 * @param p4 the source count
 */
void map_to_memory_abstraction(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p1 != *NULL_POINTER) {

        int* dc = (int*) p1;

        if (p0 != *NULL_POINTER) {

            void** d = (void**) p0;

            // The comparison result.
            int r = *NUMBER_0_INTEGER;

            if (r == *NUMBER_0_INTEGER) {

                compare_arrays(p3, p4, COMPOUND_ABSTRACTION, COMPOUND_ABSTRACTION_COUNT, &r, (void*) CHARACTER_ARRAY);

                if (r != *NUMBER_0_INTEGER) {

                    *d = COMPOUND_ABSTRACTION_ARRAY;
                    *dc = *COMPOUND_ABSTRACTION_COUNT;
                }
            }

            if (r == *NUMBER_0_INTEGER) {

                compare_arrays(p3, p4, KNOWLEDGE_ABSTRACTION, KNOWLEDGE_ABSTRACTION_COUNT, &r, (void*) CHARACTER_ARRAY);

                if (r != *NUMBER_0_INTEGER) {

                    *d = CHARACTER_VECTOR_ABSTRACTION_ARRAY;
                    *dc = *CHARACTER_VECTOR_ABSTRACTION_COUNT;
                }
            }

            if (r == *NUMBER_0_INTEGER) {

                compare_arrays(p3, p4, ENCAPSULATED_KNOWLEDGE_ABSTRACTION, ENCAPSULATED_KNOWLEDGE_ABSTRACTION_COUNT, &r, (void*) CHARACTER_ARRAY);

                if (r != *NUMBER_0_INTEGER) {

                    *d = CHARACTER_VECTOR_ABSTRACTION_ARRAY;
                    *dc = *CHARACTER_VECTOR_ABSTRACTION_COUNT;
                }
            }

            if (r == *NUMBER_0_INTEGER) {

                compare_arrays(p3, p4, OPERATION_ABSTRACTION, OPERATION_ABSTRACTION_COUNT, &r, (void*) CHARACTER_ARRAY);

                if (r != *NUMBER_0_INTEGER) {

                    *d = CHARACTER_VECTOR_ABSTRACTION_ARRAY;
                    *dc = *CHARACTER_VECTOR_ABSTRACTION_COUNT;
                }
            }

            if (r == *NUMBER_0_INTEGER) {

                compare_arrays(p3, p4, BOOLEAN_ABSTRACTION, BOOLEAN_ABSTRACTION_COUNT, &r, (void*) CHARACTER_ARRAY);

                if (r != *NUMBER_0_INTEGER) {

                    *d = INTEGER_VECTOR_ABSTRACTION_ARRAY;
                    *dc = *INTEGER_VECTOR_ABSTRACTION_COUNT;
                }
            }

            if (r == *NUMBER_0_INTEGER) {

                compare_arrays(p3, p4, CHARACTER_VECTOR_ABSTRACTION, CHARACTER_VECTOR_ABSTRACTION_COUNT, &r, (void*) CHARACTER_ARRAY);

                if (r != *NUMBER_0_INTEGER) {

                    *d = CHARACTER_VECTOR_ABSTRACTION;
                    *dc = *CHARACTER_VECTOR_ABSTRACTION_COUNT;
                }
            }

            if (r == *NUMBER_0_INTEGER) {

                compare_arrays(p3, p4, COMPLEX_ABSTRACTION, COMPLEX_ABSTRACTION_COUNT, &r, (void*) CHARACTER_ARRAY);

                if (r != *NUMBER_0_INTEGER) {

                    *d = COMPLEX_ABSTRACTION_ARRAY;
                    *dc = *COMPLEX_ABSTRACTION_COUNT;
                }
            }

            if (r == *NUMBER_0_INTEGER) {

                compare_arrays(p3, p4, DOUBLE_VECTOR_ABSTRACTION, DOUBLE_VECTOR_ABSTRACTION_COUNT, &r, (void*) CHARACTER_ARRAY);

                if (r != *NUMBER_0_INTEGER) {

                    *d = DOUBLE_VECTOR_ABSTRACTION_ARRAY;
                    *dc = *DOUBLE_VECTOR_ABSTRACTION_COUNT;
                }
            }

            if (r == *NUMBER_0_INTEGER) {

                compare_arrays(p3, p4, FRACTION_ABSTRACTION, FRACTION_ABSTRACTION_COUNT, &r, (void*) CHARACTER_ARRAY);

                if (r != *NUMBER_0_INTEGER) {

                    *d = FRACTION_ABSTRACTION_ARRAY;
                    *dc = *FRACTION_ABSTRACTION_COUNT;
                }
            }

            if (r == *NUMBER_0_INTEGER) {

                compare_arrays(p3, p4, INTEGER_VECTOR_ABSTRACTION, INTEGER_VECTOR_ABSTRACTION_COUNT, &r, (void*) CHARACTER_ARRAY);

                if (r != *NUMBER_0_INTEGER) {

                    *d = INTEGER_VECTOR_ABSTRACTION_ARRAY;
                    *dc = *INTEGER_VECTOR_ABSTRACTION_COUNT;
                }
            }

            if (r == *NUMBER_0_INTEGER) {

                compare_arrays(p3, p4, POINTER_VECTOR_ABSTRACTION, POINTER_VECTOR_ABSTRACTION_COUNT, &r, (void*) CHARACTER_ARRAY);

                if (r != *NUMBER_0_INTEGER) {

                    *d = POINTER_VECTOR_ABSTRACTION_ARRAY;
                    *dc = *POINTER_VECTOR_ABSTRACTION_COUNT;
                }
            }

            if (r == *NUMBER_0_INTEGER) {

                compare_arrays(p3, p4, DATE_TIME_ABSTRACTION, DATE_TIME_ABSTRACTION_COUNT, &r, (void*) CHARACTER_ARRAY);

                if (r != *NUMBER_0_INTEGER) {

                    *d = DATE_TIME_ABSTRACTION_ARRAY;
                    *dc = *DATE_TIME_ABSTRACTION_COUNT;
                }
            }

            if (r == *NUMBER_0_INTEGER) {

                compare_arrays(p3, p4, DDMMYYYY_DATE_TIME_ABSTRACTION, DDMMYYYY_DATE_TIME_ABSTRACTION_COUNT, &r, (void*) CHARACTER_ARRAY);

                if (r != *NUMBER_0_INTEGER) {

                    *d = DATE_TIME_ABSTRACTION_ARRAY;
                    *dc = *DATE_TIME_ABSTRACTION_COUNT;
                }
            }

            if (r == *NUMBER_0_INTEGER) {

                compare_arrays(p3, p4, UNSIGNED_LONG_VECTOR_ABSTRACTION, UNSIGNED_LONG_VECTOR_ABSTRACTION_COUNT, &r, (void*) CHARACTER_ARRAY);

                if (r != *NUMBER_0_INTEGER) {

                    *d = UNSIGNED_LONG_VECTOR_ABSTRACTION_ARRAY;
                    *dc = *UNSIGNED_LONG_VECTOR_ABSTRACTION_COUNT;
                }
            }

            if (r == *NUMBER_0_INTEGER) {

                compare_arrays(p3, p4, WIDE_CHARACTER_VECTOR_ABSTRACTION, WIDE_CHARACTER_VECTOR_ABSTRACTION_COUNT, &r, (void*) CHARACTER_ARRAY);

                if (r != *NUMBER_0_INTEGER) {

                    *d = WIDE_CHARACTER_VECTOR_ABSTRACTION_ARRAY;
                    *dc = *WIDE_CHARACTER_VECTOR_ABSTRACTION_COUNT;
                }
            }

            if (r == *NUMBER_0_INTEGER) {

                compare_arrays(p3, p4, XDT_ABSTRACTION, XDT_ABSTRACTION_COUNT, &r, (void*) CHARACTER_ARRAY);

                if (r != *NUMBER_0_INTEGER) {

                    *d = COMPOUND_ABSTRACTION_ARRAY;
                    *dc = *COMPOUND_ABSTRACTION_COUNT;
                }
            }

        } else {

            log_message_debug("Could not map serialised cybol abstraction to runtime cyboi abstraction. The destination is null.");
        }

    } else {

        log_message_debug("Could not map serialised cybol abstraction to runtime cyboi abstraction. The destination count is null.");
    }
}

/* ABSTRACTION_MAPPER_SOURCE */
#endif
