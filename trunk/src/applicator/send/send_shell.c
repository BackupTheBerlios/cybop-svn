/*
 * $RCSfile: send_shell.c,v $
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
 * @version $Revision: 1.9 $ $Date: 2007-06-16 21:53:30 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef SEND_SHELL_SOURCE
#define SEND_SHELL_SOURCE

#include "../../globals/constants/cybol/cybol_abstraction_constants.c"
#include "../../globals/constants/cybol/cybol_channel_constants.c"
#include "../../globals/constants/integer/integer_constants.c"
#include "../../globals/constants/log/log_message_constants.c"
#include "../../globals/constants/cybol/cybol_model_constants.c"
#include "../../globals/constants/pointer/pointer_constants.c"
#include "../../globals/logger/logger.c"
#include "../../globals/variables/variables.c"
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

    log_message_debug("Information: Send shell message.");

    // The serialised string array to be sent to the standard output.
    void* a = *NULL_POINTER;
    int ac = *NUMBER_0_INTEGER;
    int as = *NUMBER_0_INTEGER;

    // Allocate array.
    allocate((void*) &a, (void*) &as, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT);

    // Serialise knowledge model into model diagram (hierarchical text).
    serialise((void*) &a, (void*) &ac, (void*) &as, *NULL_POINTER, *NULL_POINTER, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10);

    if (p13 != *NULL_POINTER) {

        int* nl = (int*) p13;

        if (*nl != *NUMBER_0_INTEGER) {

            // Resize destination character array for new line character.
            if ((ac + *PRIMITIVE_COUNT) >= as) {

                // Set destination character array size.
                // CAUTION! Add constant in case ac is zero!
                as = ac * *CHARACTER_VECTOR_REALLOCATE_FACTOR + *PRIMITIVE_COUNT;

                // Reallocate destination character array.
                reallocate_array((void*) &a, (void*) &ac, (void*) &as, (void*) CHARACTER_ARRAY);
            }

            // Set new line character.
            set_array_elements(a, (void*) &ac, (void*) LINE_FEED_CONTROL_CHARACTER, (void*) PRIMITIVE_COUNT, (void*) CHARACTER_ARRAY);
            ac = ac + *PRIMITIVE_COUNT;
        }
    }

    // Write serialised array as message to shell standard output.
    write_data((void*) &STANDARD_OUTPUT_MODEL, (void*) STANDARD_OUTPUT_MODEL_COUNT, *NULL_POINTER, a, (void*) &ac, (void*) FILE_CHANNEL, (void*) FILE_CHANNEL_COUNT);

    // Deallocate array.
    deallocate((void*) &a, (void*) &as, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT);
}

/* SEND_SHELL_SOURCE */
#endif
