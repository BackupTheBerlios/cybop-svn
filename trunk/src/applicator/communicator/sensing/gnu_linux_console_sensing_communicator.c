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
 * @version $RCSfile: gnu_linux_console_sensing_communicator.c,v $ $Revision: 1.3 $ $Date: 2008-09-06 23:17:19 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef GNU_LINUX_CONSOLE_SENSOR_SOURCE
#define GNU_LINUX_CONSOLE_SENSOR_SOURCE

#ifdef GNU_LINUX_OPERATING_SYSTEM

#include <pthread.h>
#include <signal.h>
#include <stdio.h>
//?? #include <wchar.h>
#include "../../globals/constants/character/code/character_code_constants.c"
#include "../../constant/model/character_code/unicode/unicode_character_code_model.c"
#include "../../globals/constants/console/console_control_sequence_constants.c"
#include "../../globals/constants/cyboi/cyboi_signal_priority_constants.c"
#include "../../constant/abstraction/cybol/text_cybol_abstraction.c"
#include "../../globals/constants/cybol/cybol_name_constants.c"
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../constant/model/log/level_log_model.c"
#include "../../constant/abstraction/memory/memory_abstraction.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../logger/logger.c"
#include "../../variable/thread_identification.c"
#include "../../memoriser/accessor/compound_accessor.c"
#include "../../memoriser/accessor/signal_memory_accessor.c"
#include "../../memoriser/accessor.c"
#include "../../memoriser/allocator.c"
#include "../../memoriser/array.c"

/**
 * Senses gnu/linux console message.
 *
 * @param p0 the interrupt
 * @param p1 the mutex
 * @param p2 the sleep time
 * @param p3 the input stream
 */
void sense_gnu_linux_console_message(void* p0, void* p1, void* p2, void* p3) {

    if (p3 != *NULL_POINTER_MEMORY_MODEL) {

        FILE* is = (FILE*) p3;

        if (p2 != *NULL_POINTER_MEMORY_MODEL) {

            unsigned int* st = (unsigned int*) p2;

            if (p1 != *NULL_POINTER_MEMORY_MODEL) {

                pthread_mutex_t* mt = (pthread_mutex_t*) p1;

                if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                    int* irq = (int*) p0;

                    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Sense gnu/linux console message.");

                    // Get character from gnu/linux console input stream,
                    // just to detect that some (event) character is available.
                    // This is also called "peeking ahead" at the input.
                    //
                    // CAUTION! For the narrow stream functions it is important to store the
                    // result of these functions in a variable of type int instead of char,
                    // even if one plans to use it only as a character. Storing EOF in a char
                    // variable truncates its value to the size of a character, so that it
                    // is no longer distinguishable from the valid character (char) -1.
                    // So, one should always use an int for the result of getc and friends,
                    // and check for EOF after the call; once it is verified that the result
                    // is NOT EOF, one can be sure that it will fit in a char variable
                    // without loss of information.
                    // int c = fgetc(is);
                    //
                    // CAUTION! Use 'wint_t' instead of 'int' as return type for
                    // 'getwchar()', since that returns 'WEOF' instead of 'EOF'!
                    wint_t c = fgetwc(is);

//??                    fwprintf(stdout, L"TEST character %i\n", e);

                    // Unread character, that is push it back on the stream to
                    // make it available to be input again from the stream, by the
                    // next call to fgetc or another input function on that stream.
                    //
                    // If c is EOF, ungetc does nothing and just returns EOF.
                    // This lets you call ungetc with the return value of getc
                    // without needing to check for an error from getc.
                    //
                    // The character that you push back doesn't have to be the same
                    // as the last character that was actually read from the stream.
                    // In fact, it isn't necessary to actually read any characters
                    // from the stream before unreading them with ungetc!
                    // But that is a strange way to write a program;
                    // usually ungetc is used only to unread a character that was
                    // just read from the same stream.
                    //
                    // The GNU C library only supports one character of pushback.
                    // In other words, it does not work to call ungetc twice without
                    // doing input in between.
                    // Other systems might let you push back multiple characters;
                    // then reading from the stream retrieves the characters in the
                    // reverse order that they were pushed.
                    //
                    // Pushing back characters doesn't alter the file;
                    // only the internal buffering for the stream is affected.
                    // If a file positioning function (such as fseek, fseeko or rewind)
                    // is called, any pending pushed-back characters are discarded.
                    //
                    // Unreading a character on a stream that is at end of file
                    // clears the end-of-file indicator for the stream, because it
                    // makes the character of input available.
                    // After you read that character, trying to read again will
                    // encounter end of file.
                    ungetwc(c, is);

                    // Lock gnu/linux console mutex.
                    pthread_mutex_lock(mt);

                    // Set gnu/linux console interrupt request to indicate
                    // that a message has been received via gnu/linux console,
                    // which may now be processed in the main thread of this system.
                    *irq = *NUMBER_1_INTEGER_MEMORY_MODEL;

    fwprintf(stderr, L"TEST sense gnu/linux console irq value: %i\n", *irq);

                    // Unlock gnu/linux console mutex.
                    pthread_mutex_unlock(mt);

                    while (*irq == *NUMBER_1_INTEGER_MEMORY_MODEL) {

                        // Sleep as long as the gnu/linux console interrupt is not handled and reset yet.
                        // This is to give the central processing unit (cpu) some
                        // time to breathe, that is to be idle or to process other signals.
                        sleep(*st);
                    }

                } else {

                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not sense gnu/linux console message. The interrupt is null.");
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not sense gnu/linux console message. The mutex is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not sense gnu/linux console message. The sleep time is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not sense gnu/linux console message. The input stream is null.");
    }
}

/**
 * Senses gnu/linux console messages.
 *
 * @param p0 the internal memory
 */
void sense_gnu_linux_console(void* p0) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Sense gnu/linux console.");

    // The interrupt.
    void** irq = NULL_POINTER_MEMORY_MODEL;
    // The mutex.
    void** mt = NULL_POINTER_MEMORY_MODEL;
    // The sleep time.
    void** st = NULL_POINTER_MEMORY_MODEL;
    // The input stream.
    void** is = NULL_POINTER_MEMORY_MODEL;

    // Get interrupt.
    get_element(p0, (void*) GNU_LINUX_CONSOLE_INTERRUPT_REQUEST_INTERNAL_MEMORY_MEMORY_NAME, (void*) &irq, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
    // Get mutex.
    get_element(p0, (void*) GNU_LINUX_CONSOLE_MUTEX_INTERNAL_MEMORY_MEMORY_NAME, (void*) &mt, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
    // Get sleep time.
    get_element(p0, (void*) GNU_LINUX_CONSOLE_SLEEP_TIME_INTERNAL_MEMORY_MEMORY_NAME, (void*) &st, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
    // Get input stream.
    get_element(p0, (void*) GNU_LINUX_CONSOLE_INPUT_FILE_DESCRIPTOR_INTERNAL, (void*) &is, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);

    while (*NUMBER_1_INTEGER_MEMORY_MODEL) {

        // A break condition does not exist here because the loop
        // is running neverendingly while sensing messages.
        //
        // The loop and this thread can only be exited by an external signal
        // which is sent in the corresponding interrupt service function
        // (situated in the applicator/interrupt/ directory)
        // and processed in the system signal handler procedure
        // (situated in the controller/checker.c module).

    fwprintf(stderr, L"TEST sense gnu/linux console irq pointer: %i\n", *irq);

        sense_gnu_linux_console_message(*irq, *mt, *st, *is);
    }

    // An implicit call to pthread_exit() is made when this thread
    // (other than the thread in which main() was first invoked)
    // returns from the function that was used to create it (this function).
    // The pthread_exit() function does therefore not have to be called here.
    // However, since this function runs an endless loop waiting for input, it may
    // only be left using an external signal (see comment at "break" condition above).
}

/* GNU_LINUX_OPERATING_SYSTEM */
#endif

/* GNU_LINUX_CONSOLE_SENSOR_SOURCE */
#endif
