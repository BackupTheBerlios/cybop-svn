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
 * @version $RCSfile: gnu_linux_console_sending_communicator.c,v $ $Revision: 1.1 $ $Date: 2008-09-03 22:03:59 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef GNU_LINUX_CONSOLE_SENDER_SOURCE
#define GNU_LINUX_CONSOLE_SENDER_SOURCE

#include <stdio.h>
#include <unistd.h>
#include "../../globals/constants/boolean/boolean_constants.c"
#include "../../globals/constants/console/console_control_sequence_constants.c"
#include "../../globals/constants/cybol/cybol_abstraction_constants.c"
#include "../../globals/constants/cybol/cybol_channel_constants.c"
#include "../../globals/constants/integer/integer_constants.c"
#include "../../globals/constants/memory_structure/memory_structure_constants.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../globals/variables/reallocation_factor_variables.c"
#include "../../memoriser/accessor.c"
#include "../../memoriser/allocator.c"
#include "../../memoriser/array.c"
#include "../../memoriser/communicator.c"
#include "../../memoriser/converter.c"

/**
 * Sends a textual user interface (tui) via gnu/linux console.
 *
 * @param p0 the internal memory
 * @param p1 the source root abstraction
 * @param p2 the source root abstraction count
 * @param p3 the source root model (root window compound model)
 * @param p4 the source root model count
 * @param p5 the source root details (meta properties of root window compound model)
 * @param p6 the source root details count
 * @param p7 the source part name (area to be repainted)
 * @param p8 the source part name count
 * @param p9 the source clean flag
 * @param p10 the source clean flag count
 * @param p11 the knowledge memory
 * @param p12 the knowledge memory count
 */
void send_gnu_linux_console(void* p0, void* p1, void* p2, void* p3, void* p4,
    void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Send gnu/linux console message.");

    // The encoded string array to be sent to the gnu/linux console (terminal).
    void* a = *NULL_POINTER_MEMORY_MODEL;
    int ac = *NUMBER_0_INTEGER_MEMORY_MODEL;
    int as = *NUMBER_0_INTEGER_MEMORY_MODEL;

    // Allocate array.
    allocate((void*) &a, (void*) &as, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION_COUNT);

    if (p9 != *NULL_POINTER_MEMORY_MODEL) {

        int* f = (int*) p9;

        if (*f != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            // Resize destination character array for erase display control sequence.
            if ((ac + *ESCAPE_CONTROL_SEQUENCE_COUNT + *ERASE_DISPLAY_CONTROL_SEQUENCE_COUNT) >= as) {

                // Set destination character array size.
                // CAUTION! Add constant in case ac is zero!
                as = ac * *WIDE_CHARACTER_VECTOR_REALLOCATION_FACTOR
                    + *ESCAPE_CONTROL_SEQUENCE_COUNT
                    + *ERASE_DISPLAY_CONTROL_SEQUENCE_COUNT;

                // Reallocate destination character array.
                reallocate_array((void*) &a, (void*) &ac, (void*) &as, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
            }

            // Set erase display control sequence.
            set_array_elements(a, (void*) &ac, (void*) ESCAPE_CONTROL_SEQUENCE, (void*) ESCAPE_CONTROL_SEQUENCE_COUNT, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
            ac = ac + *ESCAPE_CONTROL_SEQUENCE_COUNT;
            set_array_elements(a, (void*) &ac, (void*) ERASE_DISPLAY_CONTROL_SEQUENCE, (void*) ERASE_DISPLAY_CONTROL_SEQUENCE_COUNT, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
            ac = ac + *ERASE_DISPLAY_CONTROL_SEQUENCE_COUNT;
        }
    }

    // Encode textual user interface (tui) into array.
    encode_gnu_linux_console((void*) &a, (void*) &ac, (void*) &as, p1, p2, p3, p4, p5, p6, *NULL_POINTER, *NULL_POINTER, p7, p8, p11, p12);

    // The gnu/linux console output stream.
    void** op = NULL_POINTER;

    // Get gnu/linux console output stream.
    get_array_elements(p0, (void*) GNU_LINUX_CONSOLE_OUTPUT_FILE_DESCRIPTOR_INTERNAL, (void*) &op, (void*) POINTER_ARRAY);

    // Write encoded array as message to gnu/linux console.
    write_data((void*) op, *NULL_POINTER, *NULL_POINTER, a, (void*) &ac, (void*) GNU_LINUX_CONSOLE_MODEL, (void*) GNU_LINUX_CONSOLE_MODEL_COUNT);

    // Deallocate array.
    deallocate((void*) &a, (void*) &as, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION_COUNT);
}

/* GNU_LINUX_CONSOLE_SENDER_SOURCE */
#endif
