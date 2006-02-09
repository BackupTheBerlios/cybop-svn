/*
 * $RCSfile: receive_linux_console.c,v $
 *
 * Copyright (c) 1999-2005. Christian Heller and the CYBOP developers.
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
 * @version $Revision: 1.6 $ $Date: 2006-02-09 02:22:57 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef RECEIVE_LINUX_CONSOLE_SOURCE
#define RECEIVE_LINUX_CONSOLE_SOURCE

#include <pthread.h>
#include <stdio.h>
#include "../../globals/constants/abstraction_constants.c"
#include "../../globals/constants/ascii_character_constants.c"
#include "../../globals/constants/integer_constants.c"
#include "../../globals/constants/name_constants.c"
#include "../../globals/constants/structure_constants.c"
#include "../../globals/variables/variables.c"
#include "../../memoriser/accessor/compound_accessor.c"
#include "../../memoriser/accessor/signal_memory_accessor.c"
#include "../../memoriser/accessor.c"
#include "../../memoriser/allocator.c"
#include "../../memoriser/array.c"

/**
 * Receives linux console messages (events) in an own thread.
 *
 * @param p0 the internal memory
 */
void receive_linux_console_thread(void* p0) {

    // The knowledge memory.
    void** k = (void**) &NULL_POINTER;
    void** kc = (void**) &NULL_POINTER;
    void** ks = (void**) &NULL_POINTER;
    // The signal memory.
    void** s = (void**) &NULL_POINTER;
    void** sc = (void**) &NULL_POINTER;
    void** ss = (void**) &NULL_POINTER;
    // The user interface commands.
    void** c = (void**) &NULL_POINTER;
    void** cc = (void**) &NULL_POINTER;
    void** cs = (void**) &NULL_POINTER;
    // The terminal (device name).
    void** t = &NULL_POINTER;

    // Get knowledge memory internal.
    get(p0, (void*) KNOWLEDGE_MEMORY_INTERNAL, (void*) &k, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    get(p0, (void*) KNOWLEDGE_MEMORY_COUNT_INTERNAL, (void*) &kc, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    get(p0, (void*) KNOWLEDGE_MEMORY_SIZE_INTERNAL, (void*) &ks, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    // Get signal memory internal.
    get(p0, (void*) SIGNAL_MEMORY_INTERNAL, (void*) &s, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    get(p0, (void*) SIGNAL_MEMORY_COUNT_INTERNAL, (void*) &sc, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    get(p0, (void*) SIGNAL_MEMORY_SIZE_INTERNAL, (void*) &ss, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    // Get user interface commands internal.
    get(p0, (void*) TEMPORARY_USER_INTERFACE_COMMANDS_INTERNAL, (void*) &c, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    get(p0, (void*) TEMPORARY_USER_INTERFACE_COMMANDS_COUNT_INTERNAL, (void*) &cc, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    get(p0, (void*) TEMPORARY_USER_INTERFACE_COMMANDS_SIZE_INTERNAL, (void*) &cs, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    // Get terminal.
    get_array_elements(p0, (void*) TERMINAL_FILE_DESCRIPTOR_INTERNAL, (void*) &t, (void*) POINTER_ARRAY);

    // The command abstraction.
    void** ca = &NULL_POINTER;
    void** cac = &NULL_POINTER;
    void** cas = &NULL_POINTER;
    // The command model.
    void** cm = &NULL_POINTER;
    void** cmc = &NULL_POINTER;
    void** cms = &NULL_POINTER;
    // The command details.
    void** cd = &NULL_POINTER;
    void** cdc = &NULL_POINTER;
    void** cds = &NULL_POINTER;

    // The event character.
    // CAUTION! For the narrow stream functions it is important to store the
    // result of these functions in a variable of type int instead of char,
    // even if you plan to use it only as a character. Storing EOF in a char
    // variable truncates its value to the size of a character, so that it
    // is no longer distinguishable from the valid character (char) -1.
    // So always use an int for the result of getc and friends, and check
    // for EOF after the call; once you've verified that the result is NOT
    // EOF, you can be sure that it will fit in a char variable without loss
    // of information.
    // NEVERTHELESS, a char is used here since EOF is not of importance below,
    // in the "get_compound_element_by_encapsulated_name" procedure.
    int e = *NULL_CONTROL_ASCII_CHARACTER;
    // The signal id.
    int* id = NULL_POINTER;
    // The activation flag.
//??    int** f = (int**) &NULL_POINTER;

    while (1) {

/*??
        // Get activation flag.
        get(p0, (void*) LINUX_CONSOLE_ACTIVE_INTERNAL, (void*) &f, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

        if (**f == *NUMBER_1_INTEGER) {

            break;
        }
*/

        // Get character from terminal.
        // CAUTION! Use 'wint_t' instead of 'int' as return type for
        // 'getwchar()', since that returns 'WEOF' instead of 'EOF'.
        e = fgetc(stdin);

        // Get actual command belonging to the character.
        // If the character is not known as name, the returned command is left
        // untouched, that is at its initial default value NULL.
        get_compound_element_by_encapsulated_name(*c, *cc,
            (void*) &e, (void*) PRIMITIVE_COUNT,
            (void*) &ca, (void*) &cac, (void*) &cas,
            (void*) &cm, (void*) &cmc, (void*) &cms,
            (void*) &cd, (void*) &cdc, (void*) &cds,
            *k, *kc);

        // Allocate signal id.
        allocate((void*) &id, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
        *id = 0;
        get_new_signal_id(*s, *sc, (void*) id);

        // Add signal to signal memory.
        set_signal(*s, *sc, *ss, *ca, *cac, *cm, *cmc, *cd, *cdc, (void*) NORMAL_PRIORITY, (void*) id);

        // Reset command abstraction.
        ca = &NULL_POINTER;
        cac = &NULL_POINTER;
        cas = &NULL_POINTER;
        // Reset command model.
        cm = &NULL_POINTER;
        cmc = &NULL_POINTER;
        cms = &NULL_POINTER;
        // Reset command details.
        cd = &NULL_POINTER;
        cdc = &NULL_POINTER;
        cds = &NULL_POINTER;

        // Reset signal id.
        id = NULL_POINTER;
    }

    // An implicit call to pthread_exit() is made when this thread
    // (other than the thread in which main() was first invoked)
    // returns from the routine that was used to create it.
    // The pthread_exit() function does therefore not have to be called here.
}

/**
 * Receives textual user interface (tui) messages via linux console.
 *
 * @param p0 the internal memory
 * @param p1 the temporary user interface commands internal
 * @param p2 the temporary user interface commands count internal
 * @param p3 the temporary user interface commands size internal
 */
void receive_linux_console(void* p0, void* p1, void* p2, void* p3) {

    log_message_debug("Receive linux console message.");

    // Set temporary user interface commands internal.
    set(p0, (void*) TEMPORARY_USER_INTERFACE_COMMANDS_INTERNAL, (void*) &p1, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    set(p0, (void*) TEMPORARY_USER_INTERFACE_COMMANDS_COUNT_INTERNAL, (void*) &p2, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    set(p0, (void*) TEMPORARY_USER_INTERFACE_COMMANDS_SIZE_INTERNAL, (void*) &p3, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

    // The thread.
    pthread_t t;

    // Create thread.
    pthread_create(&t, (pthread_attr_t*) NULL_POINTER, (void*) &receive_linux_console_thread, p0);
}

/* RECEIVE_LINUX_CONSOLE_SOURCE */
#endif
