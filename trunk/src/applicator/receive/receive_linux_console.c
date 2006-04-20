/*
 * $RCSfile: receive_linux_console.c,v $
 *
 * Copyright (c) 1999-2006. Christian Heller and the CYBOP developers.
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
 * @version $Revision: 1.9 $ $Date: 2006-04-20 22:36:09 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef RECEIVE_LINUX_CONSOLE_SOURCE
#define RECEIVE_LINUX_CONSOLE_SOURCE

#ifdef LINUX_OPERATING_SYSTEM

#include <pthread.h>
#include <signal.h>
#include <stdio.h>
//?? #include <wchar.h>
#include "../../globals/constants/abstraction_constants.c"
#include "../../globals/constants/ascii_character_constants.c"
#include "../../globals/constants/character_constants.c"
#include "../../globals/constants/control_sequence_constants.c"
#include "../../globals/constants/cyboi_constants.c"
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
 * Receives linux console signal.
 *
 * @param p0 the internal memory
 * @param p1 the command name string
 * @param p2 the command name string count
 */
void receive_linux_console_signal(void* p0, void* p1, void* p2) {

    // The knowledge memory.
    void** k = (void**) &NULL_POINTER;
    void** kc = (void**) &NULL_POINTER;
    void** ks = (void**) &NULL_POINTER;
    // The signal memory.
    void** s = (void**) &NULL_POINTER;
    void** sc = (void**) &NULL_POINTER;
    void** ss = (void**) &NULL_POINTER;
    // The signal memory mutex.
    pthread_mutex_t** mt = (pthread_mutex_t**) &NULL_POINTER;
    // The interrupt request flag.
    sig_atomic_t** irq = (sig_atomic_t**) &NULL_POINTER;
    // The user interface commands.
    void** c = (void**) &NULL_POINTER;
    void** cc = (void**) &NULL_POINTER;
    void** cs = (void**) &NULL_POINTER;

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

    // The signal id.
    int* id = NULL_POINTER;

    // Get knowledge memory internal.
    get(p0, (void*) KNOWLEDGE_MEMORY_INTERNAL, (void*) &k, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    get(p0, (void*) KNOWLEDGE_MEMORY_COUNT_INTERNAL, (void*) &kc, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    get(p0, (void*) KNOWLEDGE_MEMORY_SIZE_INTERNAL, (void*) &ks, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    // Get signal memory internal.
    get(p0, (void*) SIGNAL_MEMORY_INTERNAL, (void*) &s, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    get(p0, (void*) SIGNAL_MEMORY_COUNT_INTERNAL, (void*) &sc, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    get(p0, (void*) SIGNAL_MEMORY_SIZE_INTERNAL, (void*) &ss, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    // Get signal memory mutex.
    get(p0, (void*) SIGNAL_MEMORY_MUTEX_INTERNAL, (void*) &mt, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    // Get interrupt request internal.
    get(p0, (void*) INTERRUPT_REQUEST_INTERNAL, (void*) &irq, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    // Get user interface commands internal.
    get(p0, (void*) TEMPORARY_USER_INTERFACE_COMMANDS_INTERNAL, (void*) &c, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    get(p0, (void*) TEMPORARY_USER_INTERFACE_COMMANDS_COUNT_INTERNAL, (void*) &cc, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    get(p0, (void*) TEMPORARY_USER_INTERFACE_COMMANDS_SIZE_INTERNAL, (void*) &cs, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

    fprintf(stdout, "TEST signal p1 %ls\n", (char*) p1);

    // Get actual command belonging to the command name.
    // If the name is not known, the command parameter is left untouched.
    get_compound_element_by_encapsulated_name(*c, *cc,
        p1, p2,
        (void*) &ca, (void*) &cac, (void*) &cas,
        (void*) &cm, (void*) &cmc, (void*) &cms,
        (void*) &cd, (void*) &cdc, (void*) &cds,
        *k, *kc);

    fprintf(stdout, "TEST signal cm %s\n", (char*) *cm);

    // Lock signal memory mutex.
    pthread_mutex_lock(*mt);

    // Allocate signal id.
    allocate((void*) &id, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
    *id = 0;
    get_new_signal_id(*s, *sc, (void*) id);

    // Add signal to signal memory.
    set_signal(*s, *sc, *ss, *ca, *cac, *cm, *cmc, *cd, *cdc, (void*) NORMAL_PRIORITY, (void*) id);

    // Set interrupt request flag, in order to notify the signal checker
    // that a new signal has been placed in the signal memory.
    **irq = *NUMBER_1_INTEGER;

    // Unlock signal memory mutex.
    pthread_mutex_unlock(*mt);
}

/**
 * Receives linux console messages (events) in an own thread.
 *
 * @param p0 the internal memory
 */
void receive_linux_console_thread(void* p0) {

    // The terminal (device name).
    void** t = &NULL_POINTER;

    // Get terminal.
//??    get_array_elements(p0, (void*) TERMINAL_FILE_DESCRIPTOR_INTERNAL, (void*) &t, (void*) POINTER_ARRAY);
    //?? For now, the standard stream is used for input. Possibly changed later.
    *t = stdin;

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
//??    wint_t e = *NULL_CONTROL_CHARACTER;
    char e = *NULL_CONTROL_ASCII_CHARACTER;
    // The escape character mode.
    int esc = *NUMBER_0_INTEGER;
    // The escape control sequence mode.
    int csi = *NUMBER_0_INTEGER;
    // The character buffer.
    // Its size is set to three, because no longer escape sequences are known.
    // Example: An up arrow delivers 'ESC' + '[' + 'A'
    void* b = NULL_POINTER;
    int bc = *NUMBER_0_INTEGER;
    int bs = *NUMBER_3_INTEGER;
    // The interrupt flag.
    int** f = (int**) &NULL_POINTER;

    // Allocate character buffer.
    allocate((void*) &b, (void*) &bs, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT);

    while (1) {

        // A break condition does not exist here because the loop
        // is blocking neverendingly while waiting for signals.
        // The loop and this thread can only be exited by an external signal
        // which is sent in the corresponding interrupt service procedure
        // (situated in the applicator/interrupt/ directory)
        // and processed in the system signal handler procedure
        // (situated in the controller/checker.c module).

        // Get character from terminal.
        // CAUTION! Use 'wint_t' instead of 'int' as return type for
        // 'getwchar()', since that returns 'WEOF' instead of 'EOF'.
//??        e = fgetwc(*t);
        e = fgetc(*t);

    fprintf(stdout, "TEST character %i\n", e);

        if (csi == *NUMBER_1_INTEGER) {

            // Reset escape control sequence mode.
            csi = *NUMBER_0_INTEGER;

    fprintf(stdout, "TEST csi mode %i\n", e);

            // An escape character followed by a left square bracket character
            // were read before. So this is an escape control sequence.

            // Add character to buffer.
            set(b, (void*) &bc, (void*) &e, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT);
            bc++;

    fprintf(stdout, "TEST csi b %s\n", (char*) b);
    fprintf(stdout, "TEST csi bc %i\n", bc);
    fprintf(stdout, "TEST csi bs %i\n", bs);

            // The comparison result.
            int r = 0;

            // Determine escape control sequence and send a corresponding signal.
            if (r == 0) {

                compare_arrays(b, (void*) &bc, (void*) ARROW_UP_CONTROL_SEQUENCE, (void*) ARROW_UP_CONTROL_SEQUENCE_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                if (r != 0) {

                    receive_linux_console_signal(p0, (void*) UI_ARROW_UP_NAME, (void*) UI_ARROW_UP_NAME_COUNT);
                }
            }

            if (r == 0) {

                compare_arrays(b, (void*) &bc, (void*) ARROW_DOWN_CONTROL_SEQUENCE, (void*) ARROW_DOWN_CONTROL_SEQUENCE_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                if (r != 0) {

    fprintf(stdout, "TEST csi mode down %i\n", e);

                    receive_linux_console_signal(p0, (void*) UI_ARROW_DOWN_NAME, (void*) UI_ARROW_DOWN_NAME_COUNT);
                }
            }

            if (r == 0) {

                compare_arrays(b, (void*) &bc, (void*) ARROW_LEFT_CONTROL_SEQUENCE, (void*) ARROW_LEFT_CONTROL_SEQUENCE_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                if (r != 0) {

                    receive_linux_console_signal(p0, (void*) UI_ARROW_LEFT_NAME, (void*) UI_ARROW_LEFT_NAME_COUNT);
                }
            }

            if (r == 0) {

                compare_arrays(b, (void*) &bc, (void*) ARROW_RIGHT_CONTROL_SEQUENCE, (void*) ARROW_RIGHT_CONTROL_SEQUENCE_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                if (r != 0) {

                    receive_linux_console_signal(p0, (void*) UI_ARROW_RIGHT_NAME, (void*) UI_ARROW_RIGHT_NAME_COUNT);
                }
            }

            // The loop count.
            int j = bc - 1;

            while (1) {

                if (j < 0) {

                    break;
                }

                // Remove all characters from buffer.
                remove_element(b, (void*) &bs, (void*) &j, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT);

                // Decrease loop count.
                j--;
                // Decrease character buffer count.
                bc--;
            }

        } else if (esc == *NUMBER_1_INTEGER) {

            // Reset escape character mode.
            esc = *NUMBER_0_INTEGER;

    fprintf(stdout, "TEST esc mode %i\n", e);

            // An escape character was read before.
            // Find out if it was just that escape character,
            // or if a left square bracket character follows now,
            // in which case this is the start of an escape control sequence.

            if (e == *LEFT_SQUARE_BRACKET_CHARACTER) {

                // This is the start of an escape control sequence.

                // Set escape control sequence flag.
                csi = *NUMBER_1_INTEGER;

                // Add character to buffer.
                set(b, (void*) &bc, (void*) &e, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT);
                bc++;

            } else {

                // This is not going to be an escape control sequence.
                // Send both, the formerly read escape character and the
                // current character as two independent signals.
                receive_linux_console_signal(p0, (void*) ESCAPE_CONTROL_CHARACTER, (void*) NUMBER_1_INTEGER);
                receive_linux_console_signal(p0, (void*) &e, (void*) NUMBER_1_INTEGER);
            }

        } else if (e == *ESCAPE_CONTROL_CHARACTER) {

    fprintf(stdout, "TEST if esc char %i\n", e);

            // Set escape character flag.
            esc = *NUMBER_1_INTEGER;

            // Add character to buffer.
            set(b, (void*) &bc, (void*) &e, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT);
            bc++;

        } else {

    fprintf(stdout, "TEST rest %i\n", e);

            receive_linux_console_signal(p0, (void*) &e, (void*) NUMBER_1_INTEGER);
        }
    }

    // Deallocate character buffer.
    deallocate((void*) &b, (void*) &bs, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT);

    // An implicit call to pthread_exit() is made when this thread
    // (other than the thread in which main() was first invoked)
    // returns from the routine that was used to create it.
    // The pthread_exit() function does therefore not have to be called here.
    //
    // However, a break condition does not exist here because the loop
    // is blocking neverendingly while waiting for signals.
    // The loop and this thread can only be exited by an external signal
    // which is sent in the corresponding interrupt service procedure
    // (situated in the applicator/interrupt/ directory)
    // and processed in the system signal handler procedure
    // (situated in the controller/checker.c module).
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

    // Create thread.
    pthread_create(LINUX_CONSOLE_THREAD, NULL_POINTER, (void*) &receive_linux_console_thread, p0);
}

/* LINUX_OPERATING_SYSTEM */
#endif

/* RECEIVE_LINUX_CONSOLE_SOURCE */
#endif
