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
 * This file contains the functionality to:
 * - receive a file stream into a byte array
 * - send a file stream from a byte array
 *
 * @version $Revision: 1.2 $ $Date: 2007-07-23 23:47:58 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef GNU_LINUX_CONSOLE_COMMUNICATOR_SOURCE
#define GNU_LINUX_CONSOLE_COMMUNICATOR_SOURCE

#include <locale.h>
#include <stdio.h>
#include <wchar.h>
#include "../../globals/constants/cybol/cybol_abstraction_constants.c"
#include "../../globals/constants/character/character_constants.c"
#include "../../globals/constants/character/wide_character_constants.c"
#include "../../globals/constants/integer/integer_constants.c"
#include "../../globals/constants/log/log_message_constants.c"
#include "../../globals/constants/memory_structure/array_constants.c"
#include "../../globals/constants/memory_structure/memory_structure_constants.c"
#include "../../globals/constants/pointer/pointer_constants.c"
#include "../../globals/logger/logger.c"
#include "../../globals/variables/variables.c"
#include "../../memoriser/array.c"

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

    log_message_debug("Information: Read from gnu/linux console.");

/*??
    char r = NULL_CONTROL_CHARACTER;
    int j = *NUMBER_0_INTEGER;
    char c = NULL_CONTROL_CHARACTER;

    while (*NUMBER_1_INTEGER) {

        if (j >= **ds) {

            break;
        }

        if (r == EOF) {

            log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not write file. A write error occured.");

            break;
        }

        get_array_element(p0, (void*) &CHARACTER_ARRAY, (void*) &j, (void*) &c);

        r = fputc(c, f);

        j++;
    }
*/

    //?? getc(stdin);
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

            log_message_debug("Information: Write to gnu/linux console.");

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

                log_message_debug("Could not write to gnu/linux console. The destination terminal file is null.");
            }

            // Destroy terminated control sequences.
            deallocate_array((void*) &ts, (void*) &tss, (void*) WIDE_CHARACTER_ARRAY);

        } else {

            log_message_debug("Could not write to gnu/linux console. The destination terminal file parameter is null.");
        }

    } else {

        log_message_debug("Could not write to gnu/linux console. The source terminal control sequences count parameter is null.");
    }
}

/* GNU_LINUX_CONSOLE_COMMUNICATOR_SOURCE */
#endif
