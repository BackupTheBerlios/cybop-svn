/*
 * Copyright (C) 1999-2011. Christian Heller.
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

#ifndef GNU_LINUX_CONSOLE_SENDER_SOURCE
#define GNU_LINUX_CONSOLE_SENDER_SOURCE

#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <wchar.h>

#include "../../../constant/abstraction/cybol/text_cybol_abstraction.c"
#include "../../../constant/abstraction/memory/memory_abstraction.c"
#include "../../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../../constant/model/character_code/ascii/ascii_character_code_model.c"
#include "../../../constant/model/character_code/unicode/unicode_character_code_model.c"
#include "../../../constant/model/log/message_log_model.c"
#include "../../../constant/model/memory/integer_memory_model.c"
#include "../../../constant/model/memory/pointer_memory_model.c"
#include "../../../executor/comparator/all/array_all_comparator.c"
#include "../../../executor/converter/decoder/utf_8_unicode_character_decoder.c"
#include "../../../executor/memoriser/allocator/model_allocator.c"
#include "../../../executor/modifier/overwriter/array_overwriter.c"
#include "../../../logger/logger.c"

/**
 * Sends the terminal control sequences into a gnu/linux console.
 *
 * @param p0 the destination gnu/linux console (Hand over as reference!)
 * @param p1 the destination gnu/linux console count
 * @param p2 the destination gnu/linux console size
 * @param p3 the source terminal control sequences as utf-8 encoded multibyte characters
 * @param p4 the source terminal control sequences as utf-8 encoded multibyte characters count
 */
void send_gnu_linux_console(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p0 != *NULL_POINTER_MEMORY_MODEL) {

        FILE** d = (FILE**) p0;

        log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Send to gnu/linux console.");

        // The terminated control sequences.
        void* ts = *NULL_POINTER_MEMORY_MODEL;
        void* tsc = *NULL_POINTER_MEMORY_MODEL;
        void* tss = *NULL_POINTER_MEMORY_MODEL;

        // Allocate terminated control sequences.
        //
        // CAUTION! Use a standard (non-wide) character vector here,
        // because the source is handed over as utf-8 encoded multibyte characters
        // and will be forwarded as such to the gnu linux console!
        allocate_model((void*) &ts, (void*) &tsc, (void*) &tss, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) CHARACTER_MEMORY_ABSTRACTION, (void*) CHARACTER_MEMORY_ABSTRACTION_COUNT);

        // Append control sequences and null termination character.
        overwrite_array((void*) &ts, p3, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p4, tsc, (void*) VALUE_PRIMITIVE_MEMORY_NAME, tsc, tss);
        overwrite_array((void*) &ts, (void*) NULL_CONTROL_ASCII_CHARACTER_CODE_MODEL, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, tsc, (void*) VALUE_PRIMITIVE_MEMORY_NAME, tsc, tss);

        if (*d != *NULL_POINTER_MEMORY_MODEL) {

            // Send to terminal.
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

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not send to gnu/linux console. The destination terminal file is null.");
        }

        // Deallocate terminated control sequences.
        deallocate_model((void*) &ts, (void*) &tsc, (void*) &tss, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) CHARACTER_MEMORY_ABSTRACTION, (void*) CHARACTER_MEMORY_ABSTRACTION_COUNT);

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not send to gnu/linux console. The destination terminal file parameter is null.");
    }
}

/**
 * Sends a textual user interface (tui) via gnu/linux console.
 *
 * @param p0 the internal memory
 * @param p1 the source root abstraction
 * @param p2 the source root abstraction count
 * @param p3 the source root model (root window compound model)
 * @param p4 the source root model count
 * @param p5 the source root details (meta properties of root window compound model)
 * @param p6 the source root details count
 * @param p7 the source area to be repainted part name
 * @param p8 the source area to be repainted part name count
 * @param p9 the source clean flag
 * @param p10 the source clean flag count
 * @param p11 the knowledge memory
 * @param p12 the knowledge memory count
 */
void apply_send_gnu_linux_console(void* p0, void* p1, void* p2, void* p3, void* p4,
    void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Apply send gnu/linux console.");

    // The serialised wide character array.
    void* s = *NULL_POINTER_MEMORY_MODEL;
    void* sc = *NULL_POINTER_MEMORY_MODEL;
    void* ss = *NULL_POINTER_MEMORY_MODEL;

    // Allocate serialised wide character array.
    allocate_model((void*) &s, (void*) &sc, (void*) &ss, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT);

    if (p9 != *NULL_POINTER_MEMORY_MODEL) {

        int* f = (int*) p9;

        if (*f != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            overwrite_array((void*) &s, (void*) ESCAPE_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) ESCAPE_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_COUNT, sc, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, sc, ss);
            overwrite_array((void*) &s, (void*) ERASE_DISPLAY_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) ERASE_DISPLAY_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_COUNT, sc, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, sc, ss);
        }
    }

    // Encode textual user interface (tui) into array.
    encode_gnu_linux_console((void*) &s, sc, ss, p1, p2, p3, p4, p5, p6, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, p7, p8, p11, p12);

    // The encoded character array.
    void* e = *NULL_POINTER_MEMORY_MODEL;
    void* ec = *NULL_POINTER_MEMORY_MODEL;
    void* es = *NULL_POINTER_MEMORY_MODEL;

    // Allocate encoded character array.
    //
    // CAUTION! Use a standard (non-wide) character vector here,
    // because the source is handed over as utf-8 encoded multibyte characters
    // and will be forwarded as such to the gnu linux console!
    allocate_model((void*) &e, (void*) &ec, (void*) &es, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) CHARACTER_MEMORY_ABSTRACTION, (void*) CHARACTER_MEMORY_ABSTRACTION_COUNT);

    // Encode serialised wide character array into encoded character array.
    encode_utf_8_unicode_character_vector((void*) &e, ec, es, s, sc);

    // Deallocate serialised wide character array.
    deallocate_model((void*) &s, (void*) &sc, (void*) &ss, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT);

    // The gnu/linux console output stream.
    void** op = NULL_POINTER_MEMORY_MODEL;

    // Get gnu/linux console output stream.
    get_array_elements((void*) &op, p0, (void*) GNU_LINUX_CONSOLE_OUTPUT_FILE_DESCRIPTOR_INTERNAL_MEMORY_MEMORY_NAME, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);

    // Send encoded array as message to shell standard output.
    send_data((void*) op, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, e, ec, (void*) GNU_LINUX_CONSOLE_CYBOL_CHANNEL, (void*) GNU_LINUX_CONSOLE_CYBOL_CHANNEL_COUNT);

    // Deallocate encoded character array.
    deallocate_model((void*) &e, (void*) &ec, (void*) &es, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) CHARACTER_MEMORY_ABSTRACTION, (void*) CHARACTER_MEMORY_ABSTRACTION_COUNT);
}

/* GNU_LINUX_CONSOLE_SENDER_SOURCE */
#endif
