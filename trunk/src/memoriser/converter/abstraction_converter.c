/*
 * Copyright (C) 1999-2008. Christian Heller.
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
 * @version $RCSfile: abstraction_converter.c,v $ $Revision: 1.6 $ $Date: 2008-09-04 20:31:31 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef ABSTRACTION_CONVERTER_SOURCE
#define ABSTRACTION_CONVERTER_SOURCE

#include "../../constant/abstraction/cybol/text_cybol_abstraction.c"
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../constant/model/log/message_log_model.c"
#include "../../constant/abstraction/memory/memory_abstraction.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../logger/logger.c"
#include "../../memoriser/array.c"

/**
 * Decodes the cybol abstraction into a runtime cyboi abstraction.
 *
 * @param p0 the destination runtime cyboi abstraction
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source cybol abstraction
 * @param p4 the source count
 */
void decode_abstraction(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p1 != *NULL_POINTER_MEMORY_MODEL) {

        int* dc = (int*) p1;

        if (p0 != *NULL_POINTER_MEMORY_MODEL) {

            void** d = (void**) p0;

            // The comparison result.
            int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

            if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                compare_arrays(p3, p4, COMPOUND_ABSTRACTION, COMPOUND_ABSTRACTION_COUNT, &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

                if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    *d = COMPOUND_ABSTRACTION_ARRAY;
                    *dc = *COMPOUND_ABSTRACTION_COUNT;
                }
            }

            if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                compare_arrays(p3, p4, KNOWLEDGE_ABSTRACTION, KNOWLEDGE_ABSTRACTION_COUNT, &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

                if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    *d = WIDE_CHARACTER_VECTOR_ABSTRACTION_ARRAY;
                    *dc = *WIDE_CHARACTER_VECTOR_ABSTRACTION_COUNT;
                }
            }

            if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                compare_arrays(p3, p4, ENCAPSULATED_KNOWLEDGE_ABSTRACTION, ENCAPSULATED_KNOWLEDGE_ABSTRACTION_COUNT, &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

                if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    *d = WIDE_CHARACTER_VECTOR_ABSTRACTION_ARRAY;
                    *dc = *WIDE_CHARACTER_VECTOR_ABSTRACTION_COUNT;
                }
            }

            if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                compare_arrays(p3, p4, OPERATION_ABSTRACTION, OPERATION_ABSTRACTION_COUNT, &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

                if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    *d = WIDE_CHARACTER_VECTOR_ABSTRACTION_ARRAY;
                    *dc = *WIDE_CHARACTER_VECTOR_ABSTRACTION_COUNT;
                }
            }

            if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                compare_arrays(p3, p4, BOOLEAN_ABSTRACTION, BOOLEAN_ABSTRACTION_COUNT, &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

                if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    *d = INTEGER_VECTOR_ABSTRACTION_ARRAY;
                    *dc = *INTEGER_VECTOR_ABSTRACTION_COUNT;
                }
            }

            if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                compare_arrays(p3, p4, CHARACTER_VECTOR_ABSTRACTION, CHARACTER_VECTOR_ABSTRACTION_COUNT, &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

                if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    *d = WIDE_CHARACTER_VECTOR_ABSTRACTION;
                    *dc = *WIDE_CHARACTER_VECTOR_ABSTRACTION_COUNT;
                }
            }

            if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                compare_arrays(p3, p4, COMPLEX_ABSTRACTION, COMPLEX_ABSTRACTION_COUNT, &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

                if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    *d = COMPLEX_ABSTRACTION_ARRAY;
                    *dc = *COMPLEX_ABSTRACTION_COUNT;
                }
            }

            if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                compare_arrays(p3, p4, DOUBLE_VECTOR_ABSTRACTION, DOUBLE_VECTOR_ABSTRACTION_COUNT, &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

                if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    *d = DOUBLE_VECTOR_ABSTRACTION_ARRAY;
                    *dc = *DOUBLE_VECTOR_ABSTRACTION_COUNT;
                }
            }

            if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                compare_arrays(p3, p4, FRACTION_ABSTRACTION, FRACTION_ABSTRACTION_COUNT, &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

                if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    *d = FRACTION_ABSTRACTION_ARRAY;
                    *dc = *FRACTION_ABSTRACTION_COUNT;
                }
            }

            if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                compare_arrays(p3, p4, INTEGER_VECTOR_ABSTRACTION, INTEGER_VECTOR_ABSTRACTION_COUNT, &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

                if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    *d = INTEGER_VECTOR_ABSTRACTION_ARRAY;
                    *dc = *INTEGER_VECTOR_ABSTRACTION_COUNT;
                }
            }

            if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                compare_arrays(p3, p4, POINTER_VECTOR_ABSTRACTION, POINTER_VECTOR_ABSTRACTION_COUNT, &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

                if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    *d = POINTER_VECTOR_ABSTRACTION_ARRAY;
                    *dc = *POINTER_VECTOR_ABSTRACTION_COUNT;
                }
            }

            if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                compare_arrays(p3, p4, DATE_TIME_ABSTRACTION, DATE_TIME_ABSTRACTION_COUNT, &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

                if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    *d = DATE_TIME_ABSTRACTION_ARRAY;
                    *dc = *DATE_TIME_ABSTRACTION_COUNT;
                }
            }

            if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                compare_arrays(p3, p4, DDMMYYYY_DATE_TIME_ABSTRACTION, DDMMYYYY_DATE_TIME_ABSTRACTION_COUNT, &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

                if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    *d = DATE_TIME_ABSTRACTION_ARRAY;
                    *dc = *DATE_TIME_ABSTRACTION_COUNT;
                }
            }

            if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                compare_arrays(p3, p4, UNSIGNED_LONG_VECTOR_ABSTRACTION, UNSIGNED_LONG_VECTOR_ABSTRACTION_COUNT, &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

                if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    *d = UNSIGNED_LONG_VECTOR_ABSTRACTION_ARRAY;
                    *dc = *UNSIGNED_LONG_VECTOR_ABSTRACTION_COUNT;
                }
            }

            if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                compare_arrays(p3, p4, WIDE_CHARACTER_VECTOR_ABSTRACTION, WIDE_CHARACTER_VECTOR_ABSTRACTION_COUNT, &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

                if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    *d = WIDE_CHARACTER_VECTOR_ABSTRACTION_ARRAY;
                    *dc = *WIDE_CHARACTER_VECTOR_ABSTRACTION_COUNT;
                }
            }

            if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                compare_arrays(p3, p4, XDT_ABSTRACTION, XDT_ABSTRACTION_COUNT, &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

                if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    *d = COMPOUND_ABSTRACTION_ARRAY;
                    *dc = *COMPOUND_ABSTRACTION_COUNT;
                }
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode abstraction. The destination is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode abstraction. The destination count is null.");
    }
}

/* ABSTRACTION_CONVERTER_SOURCE */
#endif
