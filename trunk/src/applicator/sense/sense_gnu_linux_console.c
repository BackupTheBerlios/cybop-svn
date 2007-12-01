/*
 * $RCSfile: sense_gnu_linux_console.c,v $
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
 * @version $Revision: 1.1 $ $Date: 2007-12-01 23:57:41 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef SENSE_GNU_LINUX_CONSOLE_SOURCE
#define SENSE_GNU_LINUX_CONSOLE_SOURCE

#ifdef GNU_LINUX_OPERATING_SYSTEM

#include <pthread.h>
#include <signal.h>
#include <stdio.h>
//?? #include <wchar.h>
#include "../../globals/constants/cyboi/cyboi_signal_priority_constants.c"
#include "../../globals/constants/cybol/cybol_abstraction_constants.c"
#include "../../globals/constants/character/character_constants.c"
#include "../../globals/constants/character/wide_character_constants.c"
#include "../../globals/constants/console/console_control_sequence_constants.c"
#include "../../globals/constants/cybol/cybol_name_constants.c"
#include "../../globals/constants/integer/integer_constants.c"
#include "../../globals/constants/log/log_level_constants.c"
#include "../../globals/constants/memory_structure/memory_structure_constants.c"
#include "../../globals/constants/pointer/pointer_constants.c"
#include "../../globals/logger/logger.c"
#include "../../globals/variables/thread_identification_variables.c"
#include "../../memoriser/accessor/compound_accessor.c"
#include "../../memoriser/accessor/signal_memory_accessor.c"
#include "../../memoriser/accessor.c"
#include "../../memoriser/allocator.c"
#include "../../memoriser/array.c"

/**
 * Senses gnu/linux console signal.
 *
 * @param p0 the internal memory
 * @param p1 the command name string
 * @param p2 the command name string count
 */
void sense_gnu_linux_console_signal(void* p0, void* p1, void* p2) {

    // The knowledge memory.
    void** k = NULL_POINTER;
    void** kc = NULL_POINTER;
    void** ks = NULL_POINTER;
    // The signal memory.
    void** s = NULL_POINTER;
    void** sc = NULL_POINTER;
    void** ss = NULL_POINTER;
    // The signal memory mutex.
    pthread_mutex_t** smt = (pthread_mutex_t**) NULL_POINTER;
    // The gnu/linux console mutex.
    pthread_mutex_t** lmt = (pthread_mutex_t**) NULL_POINTER;
    // The interrupt request flag.
    sig_atomic_t** irq = (sig_atomic_t**) NULL_POINTER;
    // The user interface commands.
    void** c = NULL_POINTER;
    void** cc = NULL_POINTER;
    void** cs = NULL_POINTER;
    // The command name, abstraction, model, details.
    void** cn = NULL_POINTER;
    void** cnc = NULL_POINTER;
    void** cns = NULL_POINTER;
    void** ca = NULL_POINTER;
    void** cac = NULL_POINTER;
    void** cas = NULL_POINTER;
    void** cm = NULL_POINTER;
    void** cmc = NULL_POINTER;
    void** cms = NULL_POINTER;
    void** cd = NULL_POINTER;
    void** cdc = NULL_POINTER;
    void** cds = NULL_POINTER;
    // The signal identification.
    void** id = NULL_POINTER;

    // Get knowledge memory internal.
    get_element(p0, (void*) KNOWLEDGE_MEMORY_INTERNAL, (void*) &k, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    get_element(p0, (void*) KNOWLEDGE_MEMORY_COUNT_INTERNAL, (void*) &kc, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    get_element(p0, (void*) KNOWLEDGE_MEMORY_SIZE_INTERNAL, (void*) &ks, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    // Get signal memory internal.
    get_element(p0, (void*) SIGNAL_MEMORY_INTERNAL, (void*) &s, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    get_element(p0, (void*) SIGNAL_MEMORY_COUNT_INTERNAL, (void*) &sc, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    get_element(p0, (void*) SIGNAL_MEMORY_SIZE_INTERNAL, (void*) &ss, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    // Get signal memory mutex.
    get_element(p0, (void*) SIGNAL_MEMORY_MUTEX_INTERNAL, (void*) &smt, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    // Get gnu/linux console mutex.
    get_element(p0, (void*) GNU_LINUX_CONSOLE_MUTEX_INTERNAL, (void*) &lmt, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    // Get interrupt request internal.
    get_element(p0, (void*) SIGNAL_MEMORY_INTERRUPT_REQUEST_INTERNAL, (void*) &irq, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

    // Lock gnu/linux console mutex.
    //
    // CAUTION! A mutex is needed here to ensure that the commands internal
    // and its associated count and size are retrieved at once and belong together.
    // Otherwise, a commands internal might be got in this "sense" thread,
    // then the "main" thread of cyboi might set a new commands internal, count
    // and size, and finally this "sense" thread would get a wrong count or size
    // (of the new commands internal), not belonging to the commands internal got before.
    pthread_mutex_lock(*lmt);

    // Get user interface commands internal.
    get_element(p0, (void*) GNU_LINUX_CONSOLE_THREAD_COMMANDS_INTERNAL, (void*) &c, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    get_element(p0, (void*) GNU_LINUX_CONSOLE_THREAD_COMMANDS_COUNT_INTERNAL, (void*) &cc, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    get_element(p0, (void*) GNU_LINUX_CONSOLE_THREAD_COMMANDS_SIZE_INTERNAL, (void*) &cs, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

    // Unlock gnu/linux console mutex.
    pthread_mutex_unlock(*lmt);

    // Get actual command belonging to the command name.
    // If the name is not known, the command parameter is left untouched.
    get_universal_compound_element_by_name(*c, *cc,
        p1, p2,
        (void*) &cn, (void*) &cnc, (void*) &cns,
        (void*) &ca, (void*) &cac, (void*) &cas,
        (void*) &cm, (void*) &cmc, (void*) &cms,
        (void*) &cd, (void*) &cdc, (void*) &cds,
        *k, *kc);

    // Lock signal memory mutex.
    pthread_mutex_lock(*smt);

    // Get new signal identification by incrementing the current maximum signal's one.
    get_new_signal_identification(*s, *sc, (void*) &id);

    // Add signal to signal memory.
    set_signal(*s, *sc, *ss, ca, cac, cm, cmc, cd, cdc, (void*) &NORMAL_CYBOI_SIGNAL_PRIORITY, (void*) id);

    // Set interrupt request flag, in order to notify the signal checker
    // that a new signal has been placed in the signal memory.
    **irq = *NUMBER_1_INTEGER;

    // Unlock signal memory mutex.
    pthread_mutex_unlock(*smt);
}

/**
 * Senses a gnu/linux console escape control sequence and
 * forwards the corresponding command, to be sent as signal.
 *
 * @param p0 the internal memory
 * @param p1 the character buffer
 * @param p2 the character buffer count
 */
void sense_gnu_linux_console_escape_control_sequence(void* p0, void* p1, void* p2) {

    // The comparison result.
    int r = *NUMBER_0_INTEGER;

    // Determine escape control sequence and send a corresponding signal.
    if (r == *NUMBER_0_INTEGER) {

        compare_arrays(p1, p2, (void*) ARROW_UP_CONTROL_SEQUENCE, (void*) ARROW_UP_CONTROL_SEQUENCE_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != *NUMBER_0_INTEGER) {

            sense_gnu_linux_console_signal(p0, (void*) UI_ARROW_UP_NAME, (void*) UI_ARROW_UP_NAME_COUNT);
        }
    }

    if (r == *NUMBER_0_INTEGER) {

        compare_arrays(p1, p2, (void*) ARROW_DOWN_CONTROL_SEQUENCE, (void*) ARROW_DOWN_CONTROL_SEQUENCE_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != *NUMBER_0_INTEGER) {

            sense_gnu_linux_console_signal(p0, (void*) UI_ARROW_DOWN_NAME, (void*) UI_ARROW_DOWN_NAME_COUNT);
        }
    }

    if (r == *NUMBER_0_INTEGER) {

        compare_arrays(p1, p2, (void*) ARROW_LEFT_CONTROL_SEQUENCE, (void*) ARROW_LEFT_CONTROL_SEQUENCE_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != *NUMBER_0_INTEGER) {

            sense_gnu_linux_console_signal(p0, (void*) UI_ARROW_LEFT_NAME, (void*) UI_ARROW_LEFT_NAME_COUNT);
        }
    }

    if (r == *NUMBER_0_INTEGER) {

        compare_arrays(p1, p2, (void*) ARROW_RIGHT_CONTROL_SEQUENCE, (void*) ARROW_RIGHT_CONTROL_SEQUENCE_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != *NUMBER_0_INTEGER) {

            sense_gnu_linux_console_signal(p0, (void*) UI_ARROW_RIGHT_NAME, (void*) UI_ARROW_RIGHT_NAME_COUNT);
        }
    }
}

/**
 * Senses a gnu/linux console character and
 * forwards the corresponding command, to be sent as signal.
 *
 * This procedure changes some key codes into real names as defined by CYBOL.
 * Example: The LINE_FEED_CONTROL_CHARACTER (<enter> key)
 * gets converted into UI_ENTER_NAME ("enter"), which is used in CYBOL files.
 *
 * @param p0 the internal memory
 * @param p1 the character
 */
void sense_gnu_linux_console_character(void* p0, void* p1) {

    if (p1 != *NULL_POINTER) {

        char* e = (char*) p1;

        if (*e == *LINE_FEED_CONTROL_WIDE_CHARACTER) {

            sense_gnu_linux_console_signal(p0, (void*) UI_ENTER_NAME, (void*) UI_ENTER_NAME_COUNT);

        } else if (*e == *ESCAPE_CONTROL_WIDE_CHARACTER) {

            sense_gnu_linux_console_signal(p0, (void*) UI_ESCAPE_NAME, (void*) UI_ESCAPE_NAME_COUNT);

        } else {

            sense_gnu_linux_console_signal(p0, p1, (void*) NUMBER_1_INTEGER);
        }

    } else {

        log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) "Could not sense gnu/linux console character. The character is null.");
    }
}

/**
 * Senses gnu/linux console messages (events) in an own thread.
 *
 * @param p0 the internal memory
 */
void sense_gnu_linux_console_thread(void* p0) {

    // The gnu/linux console input stream.
    void** ip = NULL_POINTER;

    // Get gnu/linux console input stream.
    get_array_elements(p0, (void*) GNU_LINUX_CONSOLE_INPUT_FILE_DESCRIPTOR_INTERNAL, (void*) &ip, (void*) POINTER_ARRAY);

    if (*ip != *NULL_POINTER) {

        // The event character.
        // CAUTION! For the narrow stream functions it is important to store the
        // result of these functions in a variable of type int instead of char,
        // even if one plans to use it only as a character. Storing EOF in a char
        // variable truncates its value to the size of a character, so that it
        // is no longer distinguishable from the valid character (char) -1.
        // So, one should always use an int for the result of getc and friends,
        // and check for EOF after the call; once it is verified that the result
        // is NOT EOF, one can be sure that it will fit in a char variable
        // without loss of information.
        // NEVERTHELESS, a char is used here since EOF is not of importance below,
        // in the "get_universal_compound_element_by_name" procedure.
    //??    wint_t e = *NULL_CONTROL_CHARACTER;
        char e = *NULL_CONTROL_CHARACTER;
        // The escape character mode.
        int esc = *NUMBER_0_INTEGER;
        // The escape control sequence mode.
        int csi = *NUMBER_0_INTEGER;
        // The character buffer.
        void** b = NULL_POINTER;
        int** bc = (int**) NULL_POINTER;
        int** bs = (int**) NULL_POINTER;
        // The interrupt flag.
        int** f = (int**) NULL_POINTER;
        // The loop count.
        int j = *NUMBER_0_INTEGER;

        // Get character buffer.
        get_element(p0, (void*) GNU_LINUX_CONSOLE_THREAD_CHARACTER_BUFFER_INTERNAL, (void*) &b, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        get_element(p0, (void*) GNU_LINUX_CONSOLE_THREAD_CHARACTER_BUFFER_COUNT_INTERNAL, (void*) &bc, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        get_element(p0, (void*) GNU_LINUX_CONSOLE_THREAD_CHARACTER_BUFFER_SIZE_INTERNAL, (void*) &bs, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

        while (*NUMBER_1_INTEGER) {

            // A break condition does not exist here because the loop
            // is blocking neverendingly while waiting for signals.
            // The loop and this thread can only be exited by an external signal
            // which is sent in the corresponding interrupt service procedure
            // (situated in the applicator/interrupt/ directory)
            // and processed in the system signal handler procedure
            // (situated in the controller/checker.c module).

            // Get character from gnu/linux console.
            // CAUTION! Use 'wint_t' instead of 'int' as return type for
            // 'getwchar()', since that returns 'WEOF' instead of 'EOF'.
    //??        e = fgetwc(*ip);
            e = fgetc(*ip);

    //??    fprintf(stdout, "TEST character %i\n", e);

            if (csi == *NUMBER_1_INTEGER) {

                // Reset escape control sequence mode.
                csi = *NUMBER_0_INTEGER;

                // An escape character followed by a left square bracket character
                // were read before. So this is an escape control sequence.

                // Add character to buffer.
                set_element(*b, (void*) *bc, (void*) &e, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT);
                (**bc)++;

                sense_gnu_linux_console_escape_control_sequence(p0, *b, (void*) *bc);

                // Initialise loop count.
                j = **bc - *NUMBER_1_INTEGER;

                // Empty the buffer for future results.
                while (*NUMBER_1_INTEGER) {

                    if (j < *NUMBER_0_INTEGER) {

                        break;
                    }

                    // Remove all characters from buffer.
                    remove_element(*b, (void*) *bs, (void*) &j, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT);

                    // Decrease loop count.
                    j--;
                    // Decrease character buffer count.
                    (**bc)--;
                }

            } else if (esc == *NUMBER_1_INTEGER) {

                // Reset escape character mode.
                esc = *NUMBER_0_INTEGER;

                // An escape character was read before.
                // Find out if it was just that escape character,
                // or if a left square bracket character follows now,
                // in which case this is the start of an escape control sequence.

                if (e == *LEFT_SQUARE_BRACKET_WIDE_CHARACTER) {

                    // This is the start of an escape control sequence.

                    // Set escape control sequence flag.
                    csi = *NUMBER_1_INTEGER;

                    // Add character to buffer.
                    set_element(*b, (void*) *bc, (void*) &e, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT);
                    (**bc)++;

                } else {

                    // This is NOT going to be an escape control sequence.
                    // Send both, the formerly read escape character and the
                    // current character as two independent signals.
                    sense_gnu_linux_console_signal(p0, (void*) UI_ESCAPE_NAME, (void*) UI_ESCAPE_NAME_COUNT);

                    if (e != EOF) {

                        // Forward character if it is not the end of the console stream.
                        sense_gnu_linux_console_character(p0, (void*) &e);
                    }
                }

            } else if (e == *ESCAPE_CONTROL_WIDE_CHARACTER) {

                // Set escape character flag.
                esc = *NUMBER_1_INTEGER;

                // Add character to buffer.
                set_element(*b, (void*) *bc, (void*) &e, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT);
                (**bc)++;

            } else if (e != EOF) {

                // Forward character if it is not the end of the console stream.
                sense_gnu_linux_console_character(p0, (void*) &e);
            }
        }

    } else {

        log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) "Could not sense gnu/linux console thread. The input stream is null.");
    }

    // An implicit call to pthread_exit() is made when this thread
    // (other than the thread in which main() was first invoked)
    // returns from the routine that was used to create it.
    // The pthread_exit() function does therefore not have to be called here.
    //
    // However, since this procedure runs an endless loop waiting for input,
    // and is NEVER left (does not have a "break" condition),
    // the loop and this thread can only be exited by an external signal
    // which is sent in the corresponding interrupt service procedure,
    // situated in the applicator/interrupt/ directory,
    // and processed in the interrupt_service_system_signal_handler procedure:
    // controller/manager/system_signal_handler_manager.c
}

/**
 * Senses textual user interface (tui) interrupt request via gnu/linux console.
 *
 * @param p0 the internal memory
 * @param p1 the temporary user interface commands internal
 * @param p2 the temporary user interface commands count internal
 * @param p3 the temporary user interface commands size internal
 */
void sense_gnu_linux_console(void* p0, void* p1, void* p2, void* p3) {

    log_terminated_message((void*) INFORMATION_LOG_LEVEL, (void*) "Sense gnu/linux console message.");

    // The gnu/linux console mutex.
    pthread_mutex_t** mt = (pthread_mutex_t**) NULL_POINTER;

    // Get gnu/linux console mutex.
    get_element(p0, (void*) GNU_LINUX_CONSOLE_MUTEX_INTERNAL, (void*) &mt, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

    // Lock gnu/linux console mutex.
    pthread_mutex_lock(*mt);

    // Adding the following parameters to the internal memory is necessary,
    // because only one parameter (the internal memory p0) can be forwarded
    // to the thread procedure further below. Thus, p0 must contain any others.

    // Set temporary user interface commands internal.
    //
    // CAUTION! A mutex is ACTUALLY not necessary, since the thread
    // procedures only read, but NOT write internal memory values.
    //
    // However, a mutex IS NECESSARY anyway, since the commands
    // internal and its count and size should be set together, at once.
    // Otherwise, the thread procedures might read a new commands internal
    // with the count or size of the old commands internal,
    // which would lead to a segmentation fault and possibly system crash.
    set_element(p0, (void*) GNU_LINUX_CONSOLE_THREAD_COMMANDS_INTERNAL, (void*) &p1, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    set_element(p0, (void*) GNU_LINUX_CONSOLE_THREAD_COMMANDS_COUNT_INTERNAL, (void*) &p2, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    set_element(p0, (void*) GNU_LINUX_CONSOLE_THREAD_COMMANDS_SIZE_INTERNAL, (void*) &p3, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

    // Unlock gnu/linux console mutex.
    pthread_mutex_unlock(*mt);

    // Only create thread, if not existent.
    if (*GNU_LINUX_CONSOLE_THREAD == *NUMBER_MINUS_1_INTEGER) {

        log_terminated_message((void*) DEBUG_LOG_LEVEL, (void*) "Create new gnu/linux console sense service thread.");

        // Create thread.
        //
        // CAUTION! Do NOT allocate any resources within the thread procedure!
        // The reason is that this main process thread gets forked when executing
        // external programs. A "fork" duplicates ALL resources of the parent process,
        // including ALL resources of any threads running within the parent process.
        // However, since the created child process does not have those threads running,
        // their duplicated resources will never be deallocated, which eats up memory.
        // See source code file: applicator/run/run_execute.c
        //
        // Any dynamically allocated resources needed within the thread have to be:
        // - allocated at service startup
        // - added to the internal memory
        // - handed over to the thread procedure HERE
        // - deallocated at service shutdown
        pthread_create(GNU_LINUX_CONSOLE_THREAD, *NULL_POINTER, (void*) &sense_gnu_linux_console_thread, p0);
    }
}

/* GNU_LINUX_OPERATING_SYSTEM */
#endif

/* SENSE_GNU_LINUX_CONSOLE_SOURCE */
#endif
