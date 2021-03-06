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
 * @version $RCSfile: internal_memory_manager.c,v $ $Revision: 1.24 $ $Date: 2009-01-31 16:06:31 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef INTERNAL_MEMORY_MANAGER_SOURCE
#define INTERNAL_MEMORY_MANAGER_SOURCE

#include "../../constant/abstraction/cybol/text_cybol_abstraction.c"
#include "../../constant/abstraction/memory/memory_abstraction.c"
#include "../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../constant/model/log/message_log_model.c"
#include "../../constant/model/memory/boolean_memory_model.c"
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../constant/name/memory/internal_memory_memory_name.c"
#include "../../executor/modifier/overwriter/array_overwriter.c"
#include "../../logger/logger.c"

/**
 * Starts up the internal memory.
 *
 * CAUTION! The internal memory items have a fixed position,
 * determined by constants. The items HAVE TO be assigned an
 * initial value, since all source code relies on them.
 *
 * Most values are compared against the *NULL_POINTER_MEMORY_MODEL constant
 * to find out whether they are set or not. If now initial values
 * would be arbitrary pointers, the programme would follow a wrong path,
 * because it would guess that an instance was properly allocated,
 * while in reality the value was just an arbitrary initial one.
 * Therefore, such values are initialised with the well-defined
 * *NULL_POINTER_MEMORY_MODEL.
 *
 * CAUTION! ONLY ONE parameter can be handed over to threads!
 * For example, the tcp socket is running in an own thread.
 * In cyboi, this one parameter is the internal memory.
 * Therefore, the knowledge memory and signal memory NEED TO BE ADDED
 * to the internal memory, in order to be forwardable to threads.
 *
 * @param p0 the internal memory array
 * @param p1 the knowledge memory part (Hand over as reference!)
 * @param p2 the signal memory item (Hand over as reference!)
 * @param p3 the signal memory interrupt request flag (Hand over as reference!)
 * @param p4 the signal memory mutex (Hand over as reference!)
 * @param p5 the signal memory sleep time (Hand over as reference!)
 * @param p6 the gnu/linux console interrupt request flag (Hand over as reference!)
 * @param p7 the gnu/linux console mutex (Hand over as reference!)
 * @param p8 the gnu/linux console sleep time (Hand over as reference!)
 * @param p9 the x window system interrupt request flag (Hand over as reference!)
 * @param p10 the x window system mutex (Hand over as reference!)
 * @param p11 the x window system sleep time (Hand over as reference!)
 * @param p12 the www service interrupt request flag (Hand over as reference!)
 * @param p13 the www service mutex (Hand over as reference!)
 * @param p14 the www service sleep time (Hand over as reference!)
 * @param p15 the cyboi service interrupt request flag (Hand over as reference!)
 * @param p16 the cyboi service mutex (Hand over as reference!)
 * @param p17 the cyboi service sleep time (Hand over as reference!)
 */
void startup_internal_memory(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5,
    void* p6, void* p7, void* p8, void* p9, void* p10, void* p11,
    void* p12, void* p13, void* p14, void* p15, void* p16, void* p17) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"\n\n");
    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Startup internal memory.");

    //
    // Initialise all values with null.
    //

    // The loop variable.
    int j = *NUMBER_0_INTEGER_MEMORY_MODEL;

    while (*TRUE_BOOLEAN_MEMORY_MODEL) {

        if (j >= *INTERNAL_MEMORY_MEMORY_MODEL_COUNT) {

            break;
        }

        // Set null pointer at index.
        //
        // CAUTION! The standard "set" procedure could have been used here as well.
        // However, to speed up the program, the "set_array_elements"
        // procedure was used directly, as it does not do so many comparisons
        // (like for example with "POINTER_PRIMITIVE_MEMORY_ABSTRACTION", to find the right procedure).
        copy_array_forward(p0, (void*) NULL_POINTER_MEMORY_MODEL, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) &j, (void*) VALUE_PRIMITIVE_MEMORY_NAME);

        j++;
    }

    //
    // Set special values.
    //

    // The internal memory index.
    int i = *NUMBER_MINUS_1_INTEGER_MEMORY_MODEL;

    // Set knowledge memory internals.
    copy_array_forward(p0, p1, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) KNOWLEDGE_MEMORY_INTERNAL_MEMORY_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
    // Set signal memory internals.
    copy_array_forward(p0, p2, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) SIGNAL_MEMORY_INTERNAL_MEMORY_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME);

    // Set signal memory interrupt request flag.
    copy_array_forward(p0, p3, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) SIGNAL_MEMORY_INTERRUPT_REQUEST_INTERNAL_MEMORY_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
    // Set signal memory mutex.
    copy_array_forward(p0, p4, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) SIGNAL_MEMORY_MUTEX_INTERNAL_MEMORY_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
    // Set signal memory sleep time.
    copy_array_forward(p0, p5, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) SIGNAL_MEMORY_SLEEP_TIME_INTERNAL_MEMORY_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME);

    // Set gnu/linux console interrupt request flag.
    copy_array_forward(p0, p6, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) GNU_LINUX_CONSOLE_INTERRUPT_REQUEST_INTERNAL_MEMORY_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
    // Set gnu/linux console mutex.
    copy_array_forward(p0, p7, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) GNU_LINUX_CONSOLE_MUTEX_INTERNAL_MEMORY_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
    // Set gnu/linux console sleep time.
    copy_array_forward(p0, p8, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) GNU_LINUX_CONSOLE_SLEEP_TIME_INTERNAL_MEMORY_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME);

    // Set x window system interrupt request flag.
    copy_array_forward(p0, p9, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) X_WINDOW_SYSTEM_INTERRUPT_REQUEST_INTERNAL_MEMORY_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
    // Set x window system mutex.
    copy_array_forward(p0, p10, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) X_WINDOW_SYSTEM_MUTEX_INTERNAL_MEMORY_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
    // Set x window system sleep time.
    copy_array_forward(p0, p11, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) X_WINDOW_SYSTEM_SLEEP_TIME_INTERNAL_MEMORY_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME);

    // Set www service interrupt request flag.
    copy_integer((void*) &i, (void*) WWW_BASE_INTERNAL_MEMORY_MEMORY_NAME);
    calculate_integer_add((void*) &i, (void*) SOCKET_INTERRUPT_REQUEST_INTERNAL_MEMORY_MEMORY_NAME);
    copy_array_forward(p0, p12, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) &i, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
    // Set www service mutex.
    copy_integer((void*) &i, (void*) WWW_BASE_INTERNAL_MEMORY_MEMORY_NAME);
    calculate_integer_add((void*) &i, (void*) SOCKET_MUTEX_INTERNAL_MEMORY_MEMORY_NAME);
    copy_array_forward(p0, p13, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) &i, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
    // Set www service sleep time.
    copy_integer((void*) &i, (void*) WWW_BASE_INTERNAL_MEMORY_MEMORY_NAME);
    calculate_integer_add((void*) &i, (void*) SOCKET_SLEEP_TIME_INTERNAL_MEMORY_MEMORY_NAME);
    copy_array_forward(p0, p14, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) &i, (void*) VALUE_PRIMITIVE_MEMORY_NAME);

    // Set cyboi service interrupt request flag.
    copy_integer((void*) &i, (void*) CYBOI_BASE_INTERNAL_MEMORY_MEMORY_NAME);
    calculate_integer_add((void*) &i, (void*) SOCKET_INTERRUPT_REQUEST_INTERNAL_MEMORY_MEMORY_NAME);
    copy_array_forward(p0, p15, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) &i, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
    // Set cyboi service mutex.
    copy_integer((void*) &i, (void*) CYBOI_BASE_INTERNAL_MEMORY_MEMORY_NAME);
    calculate_integer_add((void*) &i, (void*) SOCKET_MUTEX_INTERNAL_MEMORY_MEMORY_NAME);
    copy_array_forward(p0, p16, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) &i, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
    // Set cyboi service sleep time.
    copy_integer((void*) &i, (void*) CYBOI_BASE_INTERNAL_MEMORY_MEMORY_NAME);
    calculate_integer_add((void*) &i, (void*) SOCKET_SLEEP_TIME_INTERNAL_MEMORY_MEMORY_NAME);
    copy_array_forward(p0, p17, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) &i, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
}

/* INTERNAL_MEMORY_MANAGER_SOURCE */
#endif
