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
 * @version $RCSfile: shell_sending_communicator.c,v $ $Revision: 1.2 $ $Date: 2008-09-04 20:31:29 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef SHELL_SENDER_SOURCE
#define SHELL_SENDER_SOURCE

#include "../../constant/model/character_code/unicode/unicode_character_code_model.c"
#include "../../constant/abstraction/cybol/text_cybol_abstraction.c"
#include "../../constant/channel/cybol_channel.c"
#include "../../globals/constants/cybol/cybol_model_constants.c"
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../constant/model/log/message_log_model.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../logger/logger.c"
#include "../../variable/reallocation_factor.c"
#include "../../memoriser/allocator.c"
#include "../../memoriser/converter.c"
#include "../../memoriser/communicator.c"

/**
 * Sends a knowledge model to the operating system shell's standard output.
 *
 * @param p0 the internal memory
 * @param p1 the source abstraction
 * @param p2 the source abstraction count
 * @param p3 the source model
 * @param p4 the source model count
 * @param p5 the source details
 * @param p6 the source details count
 * @param p7 the knowledge memory
 * @param p8 the knowledge memory count
 * @param p9 the language model
 * @param p10 the language model count
 * @param p11 the source clean flag
 * @param p12 the source clean flag count
 * @param p13 the source new line flag
 * @param p14 the source new line flag count
 */
void send_shell(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Send shell message.");

    // The encoded string array to be sent to the standard output.
    void* a = *NULL_POINTER_MEMORY_MODEL;
    int ac = *NUMBER_0_INTEGER_MEMORY_MODEL;
    int as = *NUMBER_0_INTEGER_MEMORY_MODEL;

    // Allocate array.
    allocate((void*) &a, (void*) &as, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION_COUNT);

    // Encode knowledge model into model diagram (hierarchical text).
    encode((void*) &a, (void*) &ac, (void*) &as, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10);

    if (p13 != *NULL_POINTER_MEMORY_MODEL) {

        int* nl = (int*) p13;

        if (*nl != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            // Resize destination character array for new line character.
            if ((ac + *PRIMITIVE_MEMORY_MODEL_COUNT) >= as) {

                // Set destination character array size.
                // CAUTION! Add constant in case ac is zero!
                as = ac * *CHARACTER_VECTOR_REALLOCATION_FACTOR + *PRIMITIVE_MEMORY_MODEL_COUNT;

                // Reallocate destination character array.
                reallocate_array((void*) &a, (void*) &ac, (void*) &as, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
            }

            // Set new line character.
            set_array_elements(a, (void*) &ac, (void*) LINE_FEED_CONTROL_CHARACTER_CODE, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
            ac = ac + *PRIMITIVE_MEMORY_MODEL_COUNT;
        }
    }

    // Write encoded array as message to shell standard output.
    write_data((void*) &STANDARD_OUTPUT_MODEL, (void*) STANDARD_OUTPUT_MODEL_COUNT, *NULL_POINTER_MEMORY_MODEL, a, (void*) &ac, (void*) FILE_CHANNEL, (void*) FILE_CHANNEL_COUNT);

    // Deallocate array.
    deallocate((void*) &a, (void*) &as, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION_COUNT);
}

/* SHELL_SENDER_SOURCE */
#endif
