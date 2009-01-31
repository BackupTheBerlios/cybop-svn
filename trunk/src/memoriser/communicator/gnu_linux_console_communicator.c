/*
 * Copyright (C) 1999-2009. Christian Heller.
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
 * @version $RCSfile: gnu_linux_console_communicator.c,v $ $Revision: 1.29 $ $Date: 2009-01-31 16:06:33 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef GNU_LINUX_CONSOLE_COMMUNICATOR_SOURCE
#define GNU_LINUX_CONSOLE_COMMUNICATOR_SOURCE

#include <errno.h>
#include <wchar.h>
#include "../../constant/abstraction/cybol/text_cybol_abstraction.c"
#include "../../constant/abstraction/memory/array_memory_abstraction.c"
#include "../../constant/abstraction/memory/memory_abstraction.c"
#include "../../constant/model/character_code/ascii/ascii_character_code_model.c"
#include "../../constant/model/character_code/unicode/unicode_character_code_model.c"
#include "../../constant/model/log/message_log_model.c"
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../logger/logger.c"
#include "../../memoriser/allocator/model_allocator.c"
#include "../../memoriser/converter/character/utf_8_unicode_character_converter.c"
#include "../../memoriser/array.c"

/**
 * Reads a gnu/linux console character.
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
void read_gnu_linux_console_character(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8) {

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

                        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Read gnu/linux console character.");

                        // Initialise error number.
                        // It is a global variable/ function and other operations
                        // may have set some value that is not wanted here.
                        //
                        // CAUTION! Initialise the error number BEFORE calling
                        // the function that might cause an error.
                        errno = *NUMBER_0_INTEGER_MEMORY_MODEL;

                        // Lock gnu/linux console mutex.
                        pthread_mutex_lock(p8);

                        // Read character from source input stream of gnu/linux console.
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
                                // were read before. So this is an escape control sequence.
                                // Since all values have been read, the loop can be left now.
                                *b = *NUMBER_1_INTEGER_MEMORY_MODEL;

                            } else if (*esc == *NUMBER_1_INTEGER_MEMORY_MODEL) {

                                // Reset escape character flag.
                                *esc = *NUMBER_0_INTEGER_MEMORY_MODEL;

                                // An escape character was read before.

                                if (*c == *((wint_t*) LEFT_SQUARE_BRACKET_UNICODE_CHARACTER_CODE_MODEL)) {

                                    // The escape character read before is followed by an opening square bracket,
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

                            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not read from gnu/linux console. The character reading failed.");

                            // Set loop break flag.
                            *b = *NUMBER_1_INTEGER_MEMORY_MODEL;
                        }

                    } else {

                        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not read gnu/linux console character. The loop break flag is null.");
                    }

                } else {

                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not read gnu/linux console character. The input character is null.");
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not read gnu/linux console character. The escape character mode is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not read gnu/linux console character. The escape control sequence is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not read gnu/linux console character. The source input stream is null.");
    }
}

/**
 * Reads from gnu/linux console.
 *
 * @param p0 the destination wide character array (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source input stream
 * @param p4 the mutex
 */
void read_gnu_linux_console(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Read gnu/linux console.");

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

        read_gnu_linux_console_character(p0, p1, p2, (void*) &b, (void*) &c, (void*) &esc, (void*) &csi, p3, p4);
    }
}

/**
 * Writes the terminal control sequences into a gnu/linux console.
 *
 * @param p0 the destination gnu/linux console (Hand over as reference!)
 * @param p1 the destination gnu/linux console count
 * @param p2 the destination gnu/linux console size
 * @param p3 the source terminal control sequences as utf-8 encoded multibyte characters
 * @param p4 the source terminal control sequences as utf-8 encoded multibyte characters count
 */
void write_gnu_linux_console(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p0 != *NULL_POINTER_MEMORY_MODEL) {

        FILE** d = (FILE**) p0;

        log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Write to gnu/linux console.");

        // The terminated control sequences.
        void* ts = *NULL_POINTER_MEMORY_MODEL;
        void* tsc = *NULL_POINTER_MEMORY_MODEL;
        void* tss = *NULL_POINTER_MEMORY_MODEL;

        // Allocate terminated control sequences.
        //
        // CAUTION! Use a standard (non-wide) character vector here,
        // because the source is handed over as utf-8 encoded multibyte characters
        // and will be forwarded as such to the gnu linux console!
        allocate_model((void*) &ts, (void*) &tsc, (void*) &tss, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT);

        // Append control sequences and null termination character.
        append_character_vector((void*) &ts, tsc, tss, p3, p4);
        append_character_vector((void*) &ts, tsc, tss, (void*) NULL_CONTROL_ASCII_CHARACTER_CODE_MODEL, (void*) PRIMITIVE_MEMORY_MODEL_COUNT);

        if (*d != *NULL_POINTER_MEMORY_MODEL) {

            // Write to terminal.
//??            fwprintf(*d, L"%s", (char*) ts);

            //?? This is a TEMPORARY workaround.
            //?? The UTF-8 conversion returns the total number of bytes,
            //?? of all multibyte characters that were converted from wide characters.
            //?? So the size is known, but not the actual number of characters,
            //?? since one character may occupy more than just one byte.
            //?? This may sometimes lead to problems (THIS IS AN ASSUMPTION),
            //?? so that the text user interface is not drawn properly or not at all.
            //?? Therefore, as a workaround, the source is printed on console as is,
            //?? without null termination character.
            fwprintf(*d, L"%s", (char*) p3);

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

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not write to gnu/linux console. The destination terminal file is null.");
        }

        // Deallocate terminated control sequences.
        deallocate_model((void*) &ts, (void*) &tsc, (void*) &tss, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT);

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not write to gnu/linux console. The destination terminal file parameter is null.");
    }
}

/* GNU_LINUX_CONSOLE_COMMUNICATOR_SOURCE */
#endif
