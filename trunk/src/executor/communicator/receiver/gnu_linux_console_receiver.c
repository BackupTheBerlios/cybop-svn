/*
 * Copyright (C) 1999-2010. Christian Heller.
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
 * @version $RCSfile: gnu_linux_console_communicator.c,v $ $Revision: 1.31 $ $Date: 2009-10-06 21:25:26 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef GNU_LINUX_CONSOLE_RECEIVER_SOURCE
#define GNU_LINUX_CONSOLE_RECEIVER_SOURCE

#include <errno.h>
#include <wchar.h>
#include "../../../constant/abstraction/cybol/text_cybol_abstraction.c"
#include "../../../constant/abstraction/memory/memory_abstraction.c"
#include "../../../constant/abstraction/memory/memory_abstraction.c"
#include "../../../constant/model/character_code/ascii/ascii_character_code_model.c"
#include "../../../constant/model/character_code/unicode/unicode_character_code_model.c"
#include "../../../constant/model/log/message_log_model.c"
#include "../../../constant/model/memory/integer_memory_model.c"
#include "../../../constant/model/memory/pointer_memory_model.c"
#include "../../../executor/memoriser/allocator/model_allocator.c"
#include "../../../executor/converter/character/utf_8_unicode_character_converter.c"
#include "../../../executor/comparator/array_equality_comparator.c"
#include "../../../logger/logger.c"

/**
 * Receives a gnu/linux console character.
 *
 * @param p0 the destination wide character array (Hand over as reference!)
 * @param p1 the destination wide character array count
 * @param p2 the destination wide character array size
 * @param p3 the loop break flag
 * @param p4 the input character
 * @param p5 the escape character mode
 * @param p6 the escape control sequence mode
 * @param p7 the source input stream
 * @param p8 the mutex
 */
void receives_gnu_linux_console_character(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8) {

    if (p7 != *NULL_POINTER_MEMORY_MODEL) {

        FILE* s = (FILE*) p7;

        if (p6 != *NULL_POINTER_MEMORY_MODEL) {

            int* csi = (int*) p6;

            if (p5 != *NULL_POINTER_MEMORY_MODEL) {

                int* esc = (int*) p5;

                if (p4 != *NULL_POINTER_MEMORY_MODEL) {

                    wint_t* c = (wint_t*) p4;

                    if (p3 != *NULL_POINTER_MEMORY_MODEL) {

                        int* b = (int*) p3;

                        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Receive gnu/linux console character.");

                        // Initialise error number.
                        // It is a global variable/ function and other operations
                        // may have set some value that is not wanted here.
                        //
                        // CAUTION! Initialise the error number BEFORE calling
                        // the function that might cause an error.
                        errno = *NUMBER_0_INTEGER_MEMORY_MODEL;

                        // Lock gnu/linux console mutex.
                        pthread_mutex_lock(p8);

                        // Receive character from source input stream of gnu/linux console.
                        //
                        // CAUTION! The multibyte- is converted to a wide character internally,
                        // so that the return value of type "wint_t" may be casted to "wchar_t".
                        // Function calls to "decode_utf_8_unicode_character_vector" are therefore NOT necessary here!
                        *c = fgetwc(s);

                        // Unlock gnu/linux console mutex.
                        pthread_mutex_unlock(p8);

                        if (errno != EILSEQ) {

                            if (*csi == *NUMBER_1_INTEGER_MEMORY_MODEL) {

                                // Reset escape control sequence flag.
                                *csi = *NUMBER_0_INTEGER_MEMORY_MODEL;

                                // Copy source character to destination character array.
                                append_wide_character_vector(p0, p1, p2, p4, (void*) PRIMITIVE_MEMORY_MODEL_COUNT);

                                // Set loop break flag.
                                // An escape character followed by a left square bracket character
                                // were received before. So this is an escape control sequence.
                                // Since all values have been received, the loop can be left now.
                                *b = *NUMBER_1_INTEGER_MEMORY_MODEL;

                            } else if (*esc == *NUMBER_1_INTEGER_MEMORY_MODEL) {

                                // Reset escape character flag.
                                *esc = *NUMBER_0_INTEGER_MEMORY_MODEL;

                                // An escape character was received before.

                                if (*c == *((wint_t*) LEFT_SQUARE_BRACKET_UNICODE_CHARACTER_CODE_MODEL)) {

                                    // The escape character received before is followed by an opening square bracket,
                                    // which means that this is the start of an escape control sequence.

                                    // Set escape control sequence flag.
                                    *csi = *NUMBER_1_INTEGER_MEMORY_MODEL;

                                    // Copy source character to destination character array.
                                    append_wide_character_vector(p0, p1, p2, p4, (void*) PRIMITIVE_MEMORY_MODEL_COUNT);

                                } else {

                                    // This is NOT going to be an escape control sequence.
                                    // An escape- followed by another, second character
                                    // (which is not an opening square bracket) has been detected.

                                    // Lock gnu/linux console mutex.
                                    pthread_mutex_lock(p8);

                                    // Unget this character so that it may be processed once more later on.
                                    ungetwc(*c, p7);

                                    // Unlock gnu/linux console mutex.
                                    pthread_mutex_unlock(p8);

                                    // Set loop break flag.
                                    *b = *NUMBER_1_INTEGER_MEMORY_MODEL;
                                }

                            } else if (*c == *((wint_t*) ESCAPE_CONTROL_UNICODE_CHARACTER_CODE_MODEL)) {

                                // Set escape character flag.
                                *esc = *NUMBER_1_INTEGER_MEMORY_MODEL;

                                // Copy source character to destination character array.
                                append_wide_character_vector(p0, p1, p2, p4, (void*) PRIMITIVE_MEMORY_MODEL_COUNT);

                            } else if (*c == WEOF) {

                                // The function "communicate_sensing_gnu_linux_console_message" filters out
                                // invalid (non-existing) characters recognised by the return value WEOF (-1).
                                // However, to be on the safe side, they are filtered out here once more.

                                // Set loop break flag.
                                *b = *NUMBER_1_INTEGER_MEMORY_MODEL;

                            } else {

                                // Copy source character to destination character array.
                                append_wide_character_vector(p0, p1, p2, p4, (void*) PRIMITIVE_MEMORY_MODEL_COUNT);

                                // Set loop break flag.
                                *b = *NUMBER_1_INTEGER_MEMORY_MODEL;
                            }

                        } else {

                            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not receive from gnu/linux console. The character reading failed.");

                            // Set loop break flag.
                            *b = *NUMBER_1_INTEGER_MEMORY_MODEL;
                        }

                    } else {

                        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not receive gnu/linux console character. The loop break flag is null.");
                    }

                } else {

                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not receive gnu/linux console character. The input character is null.");
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not receive gnu/linux console character. The escape character mode is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not receive gnu/linux console character. The escape control sequence is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not receive gnu/linux console character. The source input stream is null.");
    }
}

/**
 * Receives from gnu/linux console.
 *
 * @param p0 the destination wide character array (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source input stream
 * @param p4 the mutex
 */
void receive_gnu_linux_console(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Receive gnu/linux console.");

    // The loop break flag.
    int b = *NUMBER_0_INTEGER_MEMORY_MODEL;
    // The input character.
    wint_t c = *((wint_t*) NULL_CONTROL_UNICODE_CHARACTER_CODE_MODEL);
    // The escape character mode.
    int esc = *NUMBER_0_INTEGER_MEMORY_MODEL;
    // The escape control sequence mode.
    int csi = *NUMBER_0_INTEGER_MEMORY_MODEL;

    while (*NUMBER_1_INTEGER_MEMORY_MODEL) {

        if (b != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            break;
        }

        receive_gnu_linux_console_character(p0, p1, p2, (void*) &b, (void*) &c, (void*) &esc, (void*) &csi, p3, p4);
    }
}

/* GNU_LINUX_CONSOLE_RECEIVER_SOURCE */
#endif
