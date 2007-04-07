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
 * @version $Revision: 1.1 $ $Date: 2007-04-07 12:15:28 $ $Author: christian $
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
/*??
#include <stdio.h>
#include <unistd.h>
#include "../../globals/constants/boolean_constants.c"
#include "../../globals/constants/control_sequence_constants.c"
#include "../../globals/constants/structure_constants.c"
#include "../../memoriser/accessor.c"
#include "../../memoriser/allocator.c"
#include "../../memoriser/array.c"
#include "../../memoriser/communicator.c"
#include "../../memoriser/converter.c"
*/

/**
 * Sends a knowledge model to the operating system shell's standard output.
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
void send_shell(void* p0, void* p1, void* p2, void* p3, void* p4,
    void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12) {

    log_message_debug("Information: Send shell message.");

    // The serialised string array to be sent to the standard output.
    void* a = NULL_POINTER;
    int ac = *NUMBER_0_INTEGER;
    int as = *NUMBER_0_INTEGER;

    // Allocate array.
    allocate((void*) &a, (void*) &as, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION_COUNT);

    // Serialise knowledge model into hierarchical text.
//??    serialise_hierarchical_text((void*) &a, (void*) &ac, (void*) &as, p1, p2, p3, p4, p5, p6, NULL_POINTER, NULL_POINTER, p7, p8, p11, p12);

    // The shell standard output.
    void** o = &NULL_POINTER;

    // Get shell standard output.
//??    get_array_elements(p0, (void*) STANDARD_OUTPUT_FILE_DESCRIPTOR_INTERNAL, (void*) &o, (void*) POINTER_ARRAY);

    // Write serialised array as message to shell standard output.
//??    write_data(o, NULL_POINTER, NULL_POINTER, a, (void*) &ac, (void*) SHELL_MODEL, (void*) SHELL_MODEL_COUNT);
//??    write_data((void*) &stdout, NULL_POINTER, NULL_POINTER, p3, p4, (void*) LINUX_CONSOLE_MODEL, (void*) LINUX_CONSOLE_MODEL_COUNT);
    write_data((void*) STANDARD_OUTPUT_MODEL, (void*) STANDARD_OUTPUT_MODEL_COUNT, NULL_POINTER, p3, p4, (void*) FILE_CHANNEL, (void*) FILE_CHANNEL_COUNT);

    // Deallocate array.
    deallocate((void*) &a, (void*) &as, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION_COUNT);
}

/* SEND_SHELL_SOURCE */
#endif
