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
 * @version $RCSfile: gnu_linux_console_communicator.c,v $ $Revision: 1.23 $ $Date: 2009-01-18 00:22:31 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef GNU_LINUX_CONSOLE_COMMUNICATOR_SOURCE
#define GNU_LINUX_CONSOLE_COMMUNICATOR_SOURCE

#include <locale.h>
#include <stdio.h>
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
 * Reads the gnu/linux console into a character array.
 *
 * @param p0 the destination wide character array (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source input stream
 */
void read_gnu_linux_console(void* p0, void* p1, void* p2, void* p3) {

    if (p3 != *NULL_POINTER_MEMORY_MODEL) {

        FILE* s = (FILE*) p3;

        log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Read from gnu/linux console.");

        // The loop exit flag.
        int f = *NUMBER_0_INTEGER_MEMORY_MODEL;
        // The input character.
        wint_t c = *((wint_t*) NULL_CONTROL_ASCII_CHARACTER_CODE_MODEL);
//??        int c = *((int*) NULL_CONTROL_ASCII_CHARACTER_CODE_MODEL);
        // The escape character mode.
        int esc = *NUMBER_0_INTEGER_MEMORY_MODEL;
        // The escape control sequence mode.
        int csi = *NUMBER_0_INTEGER_MEMORY_MODEL;

        while (*NUMBER_1_INTEGER_MEMORY_MODEL) {

            if (f == *NUMBER_1_INTEGER_MEMORY_MODEL) {

                break;
            }

            // Read character from source input stream, i.e. gnu/linux console.
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
            c = fgetwc(s);
//??            c = fgetc(s);

    fwprintf(stdout, L"TEST read gnu/linux console c: %c\n", c);

            if (csi == *NUMBER_1_INTEGER_MEMORY_MODEL) {

                // Reset escape control sequence flag.
                csi = *NUMBER_0_INTEGER_MEMORY_MODEL;

                // Copy source character to destination character array.
                decode_utf_8_unicode_character_vector(p0, p1, p2, (void*) &c, (void*) NUMBER_1_INTEGER_MEMORY_MODEL);

                // An escape character followed by a left square bracket character
                // were read before. So this is an escape control sequence.
                // Since all values have been read, the loop can be left now.
                f = *NUMBER_1_INTEGER_MEMORY_MODEL;

            } else if (esc == *NUMBER_1_INTEGER_MEMORY_MODEL) {

                // Reset escape character flag.
                esc = *NUMBER_0_INTEGER_MEMORY_MODEL;

                // An escape character was read before.
                // Find out if it was just that escape character,
                // or if a left square bracket character follows now,
                // in which case this is the start of an escape control sequence.

                if (c == *((wint_t*) LEFT_SQUARE_BRACKET_UNICODE_CHARACTER_CODE_MODEL)) {

                    // This is the start of an escape control sequence.

                    // Set escape control sequence flag.
                    csi = *NUMBER_1_INTEGER_MEMORY_MODEL;

                    // Copy source character to destination character array.
                    decode_utf_8_unicode_character_vector(p0, p1, p2, (void*) &c, (void*) NUMBER_1_INTEGER_MEMORY_MODEL);

                } else {

                    // This is NOT going to be an escape control sequence.
                    // An escape- followed by another, second character has been detected.

                    // Unget this character so that it may be processed later.
                    ungetwc(c, s);

                    // Set loop exit flag.
                    f = *NUMBER_1_INTEGER_MEMORY_MODEL;
                }

            } else if (c == *((wint_t*) ESCAPE_CONTROL_UNICODE_CHARACTER_CODE_MODEL)) {

                // Set escape character flag.
                esc = *NUMBER_1_INTEGER_MEMORY_MODEL;

                // Copy source character to destination character array.
                decode_utf_8_unicode_character_vector(p0, p1, p2, (void*) &c, (void*) NUMBER_1_INTEGER_MEMORY_MODEL);

            } else if (c == WEOF) {

                // Set loop exit flag.
                f = *NUMBER_1_INTEGER_MEMORY_MODEL;

            } else {

                // Copy source character to destination character array.
                decode_utf_8_unicode_character_vector(p0, p1, p2, (void*) &c, (void*) NUMBER_1_INTEGER_MEMORY_MODEL);

                // Set loop exit flag.
                f = *NUMBER_1_INTEGER_MEMORY_MODEL;
            }
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not read gnu/linux console. The source input stream is null.");
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

    if (p4 != *NULL_POINTER_MEMORY_MODEL) {

        int* sc = (int*) p4;

        if (p0 != *NULL_POINTER_MEMORY_MODEL) {

            FILE** d = (FILE**) p0;

            log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Write to gnu/linux console.");

/*??
            // Possible locales are: LANG, LC_CTYPE, LC_ALL.
            // CAUTION! This setting is necessary for UTF-8 Unicode characters to work.
            char* loc = setlocale(LC_ALL, "");
*/

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
                fwprintf(*d, L"%s", (char*) ts);

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

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not write to gnu/linux console. The source terminal control sequences count parameter is null.");
    }
}

/* GNU_LINUX_CONSOLE_COMMUNICATOR_SOURCE */
#endif
