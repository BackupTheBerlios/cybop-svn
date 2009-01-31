/*
 * Copyright (C) 1999-2009. Christian Heller.
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
 * @version $RCSfile: abstraction_converter.c,v $ $Revision: 1.16 $ $Date: 2009-01-31 16:06:33 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef ABSTRACTION_CONVERTER_SOURCE
#define ABSTRACTION_CONVERTER_SOURCE

#include "../../constant/abstraction/cybol/datetime_cybol_abstraction.c"
#include "../../constant/abstraction/cybol/logicvalue_cybol_abstraction.c"
#include "../../constant/abstraction/cybol/operation_cybol_abstraction.c"
#include "../../constant/abstraction/cybol/text_cybol_abstraction.c"
#include "../../constant/abstraction/memory/memory_abstraction.c"
#include "../../constant/model/log/message_log_model.c"
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../logger/logger.c"
#include "../../memoriser/array.c"

/**
 * Decodes the cybol abstraction into a runtime cyboi abstraction.
 *
 * @param p0 the destination runtime cyboi abstraction (Hand over as reference!)
 * @param p1 the destination runtime cyboi abstraction count
 * @param p2 the destination runtime cyboi abstraction size
 * @param p3 the source cybol abstraction
 * @param p4 the source cybol abstraction count
 */
void decode_abstraction(void* p0, void* p1, void* p2, void* p3, void* p4) {

    // The comparison result.
    int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(p3, p4, (void*) BOOLEAN_LOGICVALUE_CYBOL_ABSTRACTION, (void*) BOOLEAN_LOGICVALUE_CYBOL_ABSTRACTION_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            replace_wide_character_vector(p0, p1, p2, (void*) INTEGER_VECTOR_MEMORY_ABSTRACTION, (void*) INTEGER_VECTOR_MEMORY_ABSTRACTION_COUNT);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(p3, p4, (void*) CARTESIAN_COMPLEX_NUMBER_CYBOL_ABSTRACTION, (void*) CARTESIAN_COMPLEX_NUMBER_CYBOL_ABSTRACTION_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            replace_wide_character_vector(p0, p1, p2, (void*) COMPLEX_MEMORY_ABSTRACTION, (void*) COMPLEX_MEMORY_ABSTRACTION_COUNT);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(p3, p4, (void*) CYBOL_TEXT_CYBOL_ABSTRACTION, (void*) CYBOL_TEXT_CYBOL_ABSTRACTION_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            replace_wide_character_vector(p0, p1, p2, (void*) COMPOUND_MEMORY_ABSTRACTION, (void*) COMPOUND_MEMORY_ABSTRACTION_COUNT);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(p3, p4, (void*) DECIMAL_FRACTION_NUMBER_CYBOL_ABSTRACTION, (void*) DECIMAL_FRACTION_NUMBER_CYBOL_ABSTRACTION_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            replace_wide_character_vector(p0, p1, p2, (void*) FRACTION_MEMORY_ABSTRACTION, (void*) FRACTION_MEMORY_ABSTRACTION_COUNT);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(p3, p4, (void*) ENCAPSULATED_KNOWLEDGE_PATH_CYBOL_ABSTRACTION, (void*) ENCAPSULATED_KNOWLEDGE_PATH_CYBOL_ABSTRACTION_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            replace_wide_character_vector(p0, p1, p2, (void*) ENCAPSULATED_KNOWLEDGE_PATH_MEMORY_ABSTRACTION, (void*) ENCAPSULATED_KNOWLEDGE_PATH_MEMORY_ABSTRACTION_COUNT);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(p3, p4, (void*) HH_MM_SS_DATETIME_CYBOL_ABSTRACTION, (void*) HH_MM_SS_DATETIME_CYBOL_ABSTRACTION_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            replace_wide_character_vector(p0, p1, p2, (void*) DATETIME_MEMORY_ABSTRACTION, (void*) DATETIME_MEMORY_ABSTRACTION_COUNT);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(p3, p4, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            replace_wide_character_vector(p0, p1, p2, (void*) INTEGER_VECTOR_MEMORY_ABSTRACTION, (void*) INTEGER_VECTOR_MEMORY_ABSTRACTION_COUNT);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(p3, p4, (void*) KNOWLEDGE_PATH_CYBOL_ABSTRACTION, (void*) KNOWLEDGE_PATH_CYBOL_ABSTRACTION_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            replace_wide_character_vector(p0, p1, p2, (void*) KNOWLEDGE_PATH_MEMORY_ABSTRACTION, (void*) KNOWLEDGE_PATH_MEMORY_ABSTRACTION_COUNT);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(p3, p4, (void*) PLAIN_OPERATION_CYBOL_ABSTRACTION, (void*) PLAIN_OPERATION_CYBOL_ABSTRACTION_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            replace_wide_character_vector(p0, p1, p2, (void*) OPERATION_MEMORY_ABSTRACTION, (void*) OPERATION_MEMORY_ABSTRACTION_COUNT);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(p3, p4, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            replace_wide_character_vector(p0, p1, p2, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(p3, p4, (void*) POLAR_COMPLEX_NUMBER_CYBOL_ABSTRACTION, (void*) POLAR_COMPLEX_NUMBER_CYBOL_ABSTRACTION_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            replace_wide_character_vector(p0, p1, p2, (void*) COMPLEX_MEMORY_ABSTRACTION, (void*) COMPLEX_MEMORY_ABSTRACTION_COUNT);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(p3, p4, (void*) VULGAR_FRACTION_NUMBER_CYBOL_ABSTRACTION, (void*) VULGAR_FRACTION_NUMBER_CYBOL_ABSTRACTION_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            replace_wide_character_vector(p0, p1, p2, (void*) FRACTION_MEMORY_ABSTRACTION, (void*) FRACTION_MEMORY_ABSTRACTION_COUNT);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(p3, p4, (void*) XDT_TEXT_CYBOL_ABSTRACTION, (void*) XDT_TEXT_CYBOL_ABSTRACTION_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            replace_wide_character_vector(p0, p1, p2, (void*) COMPOUND_MEMORY_ABSTRACTION, (void*) COMPOUND_MEMORY_ABSTRACTION_COUNT);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        log_terminated_message((void*) WARNING_LEVEL_LOG_MODEL, (void*) L"Could not decode abstraction. The abstraction is unknown.");
    }
}

/* ABSTRACTION_CONVERTER_SOURCE */
#endif
