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
 * @version $Revision: 1.3 $ $Date: 2007-04-09 08:48:44 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef SEND_SHELL_SOURCE
#define SEND_SHELL_SOURCE

#include "../../globals/constants/abstraction_constants.c"
#include "../../globals/constants/channel_constants.c"
#include "../../globals/constants/integer_constants.c"
#include "../../globals/constants/log_constants.c"
#include "../../globals/constants/model_constants.c"
#include "../../globals/logger/logger.c"
#include "../../globals/variables/variables.c"

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
 * @param p7 the source clean flag
 * @param p8 the source clean flag count
 * @param p9 the language model
 * @param p10 the language model count
 * @param p11 the knowledge memory
 * @param p12 the knowledge memory count
 */
void send_shell(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12) {

    log_message_debug("Information: Send shell message.");

    // The serialised string array to be sent to the standard output.
    void* a = NULL_POINTER;
    int ac = *NUMBER_0_INTEGER;
    int as = *NUMBER_0_INTEGER;

    // Allocate array.
    allocate((void*) &a, (void*) &as, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION_COUNT);

    // Serialise knowledge model into model diagram (hierarchical text).
    serialise((void*) &a, (void*) &ac, (void*) &as, NULL_POINTER, NULL_POINTER, p9, p10, p3, p4, NULL_POINTER, NULL_POINTER, p11, p12);

    // Write serialised array as message to shell standard output.
    write_data((void*) STANDARD_OUTPUT_MODEL, (void*) STANDARD_OUTPUT_MODEL_COUNT, NULL_POINTER, a, (void*) &ac, (void*) FILE_CHANNEL, (void*) FILE_CHANNEL_COUNT);

    // Deallocate array.
    deallocate((void*) &a, (void*) &as, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION_COUNT);
}

/* SEND_SHELL_SOURCE */
#endif
