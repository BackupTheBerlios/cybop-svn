/*
 * $RCSfile: gnu_linux_console_communicator.c,v $
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
 * @version $Revision: 1.6 $ $Date: 2007-12-28 19:25:55 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef GNU_LINUX_CONSOLE_COMMUNICATOR_SOURCE
#define GNU_LINUX_CONSOLE_COMMUNICATOR_SOURCE

#include <locale.h>
#include <stdio.h>
#include <wchar.h>
#include "../../globals/constants/character/character_constants.c"
#include "../../globals/constants/character/wide_character_constants.c"
#include "../../globals/constants/cybol/cybol_abstraction_constants.c"
#include "../../globals/constants/integer/integer_constants.c"
#include "../../globals/constants/log/log_message_constants.c"
#include "../../globals/constants/memory_structure/array_constants.c"
#include "../../globals/constants/memory_structure/memory_structure_constants.c"
#include "../../globals/constants/pointer/pointer_constants.c"
#include "../../globals/logger/logger.c"
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
 * Reads the gnu/linux console into terminal control sequences.
 *
 * @param p0 the destination terminal control sequences (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source terminal
 * @param p4 the source count
 */
void read_gnu_linux_console(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_terminated_message((void*) INFORMATION_LOG_LEVEL, (void*) "Read from gnu/linux console.");

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
    //?? wint_t e = *NULL_CONTROL_CHARACTER;
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

/**
 * Writes the terminal control sequences into a gnu/linux console.
 *
 * @param p0 the destination gnu/linux console (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source terminal control sequences
 * @param p4 the source count
 */
void write_gnu_linux_console(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p4 != *NULL_POINTER) {

        int* sc = (int*) p4;

        if (p0 != *NULL_POINTER) {

            FILE** d = (FILE**) p0;

            log_terminated_message((void*) INFORMATION_LOG_LEVEL, (void*) "Write to gnu/linux console.");

            // Possible locales are: LANG, LC_CTYPE, LC_ALL.
            // CAUTION! This setting is necessary for UTF-8 Unicode characters to work.
            char* loc = setlocale(LC_ALL, "");

            // The terminated control sequences string.
            wchar_t* ts = (wchar_t*) *NULL_POINTER;
            // Increase control sequences count by one, for termination character.
            int tss = *sc + *NUMBER_1_INTEGER;

            // Create terminated control sequences string.
            allocate_array((void*) &ts, (void*) &tss, (void*) WIDE_CHARACTER_ARRAY);

            // Set terminated control sequences string by first copying the actual
            // control sequences and then adding the null termination character.
            set_array_elements((void*) ts, (void*) NUMBER_0_INTEGER, p3, p4, (void*) WIDE_CHARACTER_ARRAY);
            set_array_elements((void*) ts, p4, (void*) NULL_CONTROL_WIDE_CHARACTER, (void*) PRIMITIVE_COUNT, (void*) WIDE_CHARACTER_ARRAY);

            if (*d != *NULL_POINTER) {

                // Write to terminal.
    //??            fputs((char*) ts, *d);
    //??            fputws((wchar_t*) ts, *d);
                fprintf(*d, "%ls", ts);

                // Flush any buffered output on the stream to the file.
                //
                // If this was not done here, the buffered output on the
                // stream would only get flushed automatically when either:
                // - one tried to do output and the output buffer is full
                // - the stream was closed
                // - the program terminated by calling exit
                // - a newline was written with the stream being line buffered
                // - an input operation on any stream actually read data from its file
                fflush(*d);

            } else {

                log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) "Could not write to gnu/linux console. The destination terminal file is null.");
            }

            // Destroy terminated control sequences.
            deallocate_array((void*) &ts, (void*) &tss, (void*) WIDE_CHARACTER_ARRAY);

        } else {

            log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) "Could not write to gnu/linux console. The destination terminal file parameter is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) "Could not write to gnu/linux console. The source terminal control sequences count parameter is null.");
    }
}

/* GNU_LINUX_CONSOLE_COMMUNICATOR_SOURCE */
#endif
