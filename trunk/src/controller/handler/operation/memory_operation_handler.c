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
 * @version $RCSfile: memory_operation_handler.c,v $ $Revision: 1.4 $ $Date: 2009-01-07 01:14:05 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef MEMORY_OPERATION_HANDLER_SOURCE
#define MEMORY_OPERATION_HANDLER_SOURCE

#include "../../../applicator/memoriser/building_memoriser.c"
#include "../../../applicator/memoriser/copying_memoriser.c"
#include "../../../applicator/memoriser/counting_memoriser.c"
#include "../../../applicator/memoriser/creating_memoriser.c"
#include "../../../applicator/memoriser/destructing_memoriser.c"
#include "../../../applicator/memoriser/getting_memoriser.c"
#include "../../../constant/model/cybol/operation/memory_operation_cybol_model.c"
#include "../../../constant/model/memory/integer_memory_model.c"
#include "../../../constant/model/log/message_log_model.c"
#include "../../../logger/logger.c"
#include "../../../memoriser/array.c"

/**
 * Handles the memory operation signal.
 *
 * @param p0 the internal memory
 * @param p1 the knowledge memory
 * @param p2 the knowledge memory count
 * @param p3 the knowledge memory size
 * @param p4 the signal memory
 * @param p5 the signal memory count
 * @param p6 the signal memory size
 * @param p7 the shutdown flag
 * @param p8 the signal memory interrupt request flag
 * @param p9 the signal memory mutex
 * @param p10 the model / signal / operation
 * @param p11 the model / signal / operation count
 * @param p12 the details / parameters
 * @param p13 the details / parameters count
 * @param p14 the signal priority (Hand over as reference!)
 * @param p15 the signal identification (Hand over as reference!)
 * @param p16 the comparison result
 */
void handle_memory_operation(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6,
    void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14, void* p15, void* p16) {

    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Handle memory operation.");

    // The comparison result.
    int* r = (int*) p16;

    if (*r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(p10, p11, (void*) BUILD_LISTNAME_MEMORY_OPERATION_CYBOL_MODEL, (void*) BUILD_LISTNAME_MEMORY_OPERATION_CYBOL_MODEL_COUNT, p16, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (*r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            memorise_building(p12, p13, p1, p2, p3);
        }
    }

    if (*r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(p10, p11, (void*) COPY_MEMORY_OPERATION_CYBOL_MODEL, (void*) COPY_MEMORY_OPERATION_CYBOL_MODEL_COUNT, p16, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (*r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            memorise_copying(p12, p13, p1, p2, p3);
        }
    }

    if (*r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(p10, p11, (void*) COUNT_MEMORY_OPERATION_CYBOL_MODEL, (void*) COUNT_MEMORY_OPERATION_CYBOL_MODEL_COUNT, p16, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (*r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            memorise_counting(p12, p13, p1, p2, p3);
        }
    }

    if (*r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(p10, p11, (void*) CREATE_MEMORY_OPERATION_CYBOL_MODEL, (void*) CREATE_MEMORY_OPERATION_CYBOL_MODEL_COUNT, p16, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (*r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            memorise_creating(p12, p13, p1, p2, p3);
        }
    }

    if (*r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(p10, p11, (void*) DESTROY_MEMORY_OPERATION_CYBOL_MODEL, (void*) DESTROY_MEMORY_OPERATION_CYBOL_MODEL_COUNT, p16, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (*r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            memorise_destructing(p12, p13, p1, p2, p3);
        }
    }

    if (*r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(p10, p11, (void*) GET_MEMORY_OPERATION_CYBOL_MODEL, (void*) GET_MEMORY_OPERATION_CYBOL_MODEL_COUNT, p16, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (*r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            memorise_getting(p12, p13, p1, p2, p3);
        }
    }

    if (*r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(p10, p11, (void*) MOVE_MEMORY_OPERATION_CYBOL_MODEL, (void*) MOVE_MEMORY_OPERATION_CYBOL_MODEL_COUNT, p16, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (*r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

//??            memorise_moving(p12, p13, p1, p2, p3);
        }
    }
}

/* MEMORY_OPERATION_HANDLER_SOURCE */
#endif
