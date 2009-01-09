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
 * @version $RCSfile: gnu_linux_console_sending_communicator.c,v $ $Revision: 1.8 $ $Date: 2009-01-09 00:36:13 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef GNU_LINUX_CONSOLE_SENDING_COMMUNICATOR_SOURCE
#define GNU_LINUX_CONSOLE_SENDING_COMMUNICATOR_SOURCE

#include <stdio.h>
#include <unistd.h>
#include "../../../constant/abstraction/cybol/text_cybol_abstraction.c"
#include "../../../constant/abstraction/memory/memory_abstraction.c"
#include "../../../constant/channel/cybol_channel.c"
#include "../../../constant/model/gnu_linux_console/escape_control_sequence_gnu_linux_console_model.c"
#include "../../../constant/model/memory/integer_memory_model.c"
#include "../../../constant/model/memory/pointer_memory_model.c"
#include "../../../constant/name/memory/internal_memory_memory_name.c"
#include "../../../memoriser/accessor.c"
#include "../../../memoriser/allocator.c"
#include "../../../memoriser/array.c"
#include "../../../memoriser/communicator.c"
#include "../../../memoriser/converter.c"
#include "../../../variable/reallocation_factor.c"

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
void communicate_sending_gnu_linux_console(void* p0, void* p1, void* p2, void* p3, void* p4,
    void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Send gnu/linux console message.");

    // The serialised wide character array.
    void* s = *NULL_POINTER_MEMORY_MODEL;
    int sc = *NUMBER_0_INTEGER_MEMORY_MODEL;
    int ss = *NUMBER_0_INTEGER_MEMORY_MODEL;

    // Allocate serialised wide character array.
    allocate((void*) &s, (void*) &ss, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT);

    // Serialise source knowledge model into serialised wide character array.
//??    encode((void*) &s, (void*) &sc, (void*) &ss, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10);

    // Encode textual user interface (tui) into array.
    encode_gnu_linux_console((void*) &s, (void*) &sc, (void*) &ss, p1, p2, p3, p4, p5, p6, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, p7, p8, p11, p12);

    if (p9 != *NULL_POINTER_MEMORY_MODEL) {

        int* f = (int*) p9;

        if (*f != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            append((void*) &s, (void*) &sc, (void*) &ss, (void*) ESCAPE_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL, (void*) ESCAPE_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_COUNT, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
            append((void*) &s, (void*) &sc, (void*) &ss, (void*) ERASE_DISPLAY_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL, (void*) ERASE_DISPLAY_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_COUNT, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
        }
    }

    // The encoded character array.
    void* e = *NULL_POINTER_MEMORY_MODEL;
    int ec = *NUMBER_0_INTEGER_MEMORY_MODEL;
    int es = *NUMBER_0_INTEGER_MEMORY_MODEL;

    // Allocate encoded character array.
    allocate((void*) &e, (void*) &es, (void*) CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT);

    // Encode serialised wide character array into encoded character array.
    encode_utf_8_unicode_character_vector((void*) &e, (void*) &ec, (void*) &es, s, (void*) &sc);

    // Deallocate serialised wide character array.
    deallocate((void*) &s, (void*) &ss, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT);

    // The gnu/linux console output stream.
    void** op = NULL_POINTER_MEMORY_MODEL;

    // Get gnu/linux console output stream.
    get_array_elements(p0, (void*) GNU_LINUX_CONSOLE_OUTPUT_FILE_DESCRIPTOR_INTERNAL_MEMORY_MEMORY_NAME, (void*) &op, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);

    // Write encoded array as message to shell standard output.
    write_data((void*) op, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, e, (void*) &ec, (void*) GNU_LINUX_CONSOLE_CYBOL_CHANNEL, (void*) GNU_LINUX_CONSOLE_CYBOL_CHANNEL_COUNT);

    // Deallocate encoded character array.
    deallocate((void*) &e, (void*) &es, (void*) CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
}

/* GNU_LINUX_CONSOLE_SENDING_COMMUNICATOR_SOURCE */
#endif
