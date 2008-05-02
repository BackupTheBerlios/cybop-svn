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
 * @version $Revision: 1.11 $ $Date: 2008-05-02 22:52:18 $ $Author: christian $
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
#include "../../memoriser/converter/character_vector_converter.c"
#include "../../memoriser/array.c"

/**
 * Reads the gnu/linux console into a character array.
 *
 * @param p0 the destination character array (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source input stream
 */
void read_gnu_linux_console(void* p0, void* p1, void* p2, void* p3) {

    if (p3 != *NULL_POINTER) {

        FILE* s = (FILE*) p3;

        log_terminated_message((void*) INFORMATION_LOG_LEVEL, (void*) "Read from gnu/linux console.");

        // The loop exit flag.
        int f = *NUMBER_0_INTEGER;
        // The input character.
        wint_t c = *((wint_t*) NULL_CONTROL_CHARACTER);
//??        int c = *((int*) NULL_CONTROL_CHARACTER);
        // The escape character mode.
        int esc = *NUMBER_0_INTEGER;
        // The escape control sequence mode.
        int csi = *NUMBER_0_INTEGER;

        while (*NUMBER_1_INTEGER) {

            if (f == *NUMBER_1_INTEGER) {

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
            c = fwgetc(s);
//??            c = fgetc(s);

    fprintf(stderr, "TEST read gnu/linux console c: %c\n", c);

            if (csi == *NUMBER_1_INTEGER) {

                // Reset escape control sequence flag.
                csi = *NUMBER_0_INTEGER;

                // Copy source character to destination character array.
                decode_character_vector(p0, p1, p2, (void*) &c, (void*) NUMBER_1_INTEGER);

                // An escape character followed by a left square bracket character
                // were read before. So this is an escape control sequence.
                // Since all values have been read, the loop can be left now.
                f = *NUMBER_1_INTEGER;

            } else if (esc == *NUMBER_1_INTEGER) {

                // Reset escape character flag.
                esc = *NUMBER_0_INTEGER;

                // An escape character was read before.
                // Find out if it was just that escape character,
                // or if a left square bracket character follows now,
                // in which case this is the start of an escape control sequence.

                if (c == *LEFT_SQUARE_BRACKET_WIDE_CHARACTER) {

                    // This is the start of an escape control sequence.

                    // Set escape control sequence flag.
                    csi = *NUMBER_1_INTEGER;

                    // Copy source character to destination character array.
                    decode_character_vector(p0, p1, p2, (void*) &c, (void*) NUMBER_1_INTEGER);

                } else {

                    // This is NOT going to be an escape control sequence.
                    // An escape- followed by another, second character has been detected.

                    // Unget this character so that it may be processed later.
                    ungetc(c, s);

                    // Set loop exit flag.
                    f = *NUMBER_1_INTEGER;
                }

            } else if (c == *ESCAPE_CONTROL_WIDE_CHARACTER) {

                // Set escape character flag.
                esc = *NUMBER_1_INTEGER;

                // Copy source character to destination character array.
                decode_character_vector(p0, p1, p2, (void*) &c, (void*) NUMBER_1_INTEGER);

            } else if (c == EOF) {

                // Set loop exit flag.
                f = *NUMBER_1_INTEGER;

            } else {

                // Copy source character to destination character array.
                decode_character_vector(p0, p1, p2, (void*) &c, (void*) NUMBER_1_INTEGER);

                // Set loop exit flag.
                f = *NUMBER_1_INTEGER;
            }
        }

    } else {

        log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) "Could not read gnu/linux console. The source input stream is null.");
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
