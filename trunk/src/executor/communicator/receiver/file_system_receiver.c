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
 * @version $RCSfile: file_communicator.c,v $ $Revision: 1.43 $ $Date: 2009-01-31 16:06:33 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef FILE_SYSTEM_RECEIVER_SOURCE
#define FILE_SYSTEM_RECEIVER_SOURCE

#ifdef GNU_LINUX_OPERATING_SYSTEM

#include <stdio.h>

#include "../../../constant/abstraction/memory/memory_abstraction.c"
#include "../../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../../constant/abstraction/operation/primitive_operation_abstraction.c"
#include "../../../constant/model/character_code/ascii/ascii_character_code_model.c"
#include "../../../constant/model/character_code/unicode/unicode_character_code_model.c"
#include "../../../constant/model/memory/boolean_memory_model.c"
#include "../../../constant/model/memory/integer_memory_model.c"
#include "../../../constant/model/memory/pointer_memory_model.c"
#include "../../../constant/model/stream_model.c"
#include "../../../executor/comparator/all/array_all_comparator.c"
#include "../../../executor/converter/encoder/utf_8_unicode_character_encoder.c"
#include "../../../executor/memoriser/allocator/model_allocator.c"
#include "../../../executor/memoriser/deallocator/model_deallocator.c"
#include "../../../logger/logger.c"
#include "../../../variable/reallocation_factor.c"

/**
 * Receives a file stream.
 *
 * @param p0 the destination byte array (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source file stream
 */
void receive_file_stream(void* p0, void* p1, void* p2, void* p3) {

    if (p3 != *NULL_POINTER_MEMORY_MODEL) {

        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Receive file stream.");

        // Read first character.
        char c = fgetc(p3);

        while (*TRUE_BOOLEAN_MEMORY_MODEL) {

            if (c == EOF) {

                break;
            }

            // Set character in destination array.
            // The array count serves as index for setting the character.
            overwrite_array(p0, (void*) &c, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);

            // Read next character.
            c = fgetc(p3);
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not receive file stream. The file is null.");
    }
}

/**
 * Receives a file and writes it into a byte array.
 *
 * @param p0 the destination byte array (Hand over as reference!)
 * @param p1 the destination byte array count
 * @param p2 the destination byte array size
 * @param p3 the source file name
 * @param p4 the source file name count
 */
void receive_file(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p4 != *NULL_POINTER_MEMORY_MODEL) {

        int* sc = (int*) p4;

        log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Receive file.");

        // The comparison result.
        int r = *NUMBER_0_INTEGER_MEMORY_MODEL;
        // The file.
        FILE* f = (FILE*) *NULL_POINTER_MEMORY_MODEL;

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            compare_all_array((void*) &r, p3, (void*) STANDARD_INPUT_STREAM_MODEL, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p4, (void*) STANDARD_INPUT_STREAM_MODEL_COUNT);

            if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                // The given string is not a file name, but specifies the "standard_input".
                f = stdin;

                receive_file_stream(p0, p1, p2, (void*) f);
            }
        }

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            // If the given name does not match the standard input, then interpret it as file name.

            // The terminated file name.
            void* tn = *NULL_POINTER_MEMORY_MODEL;
            void* tnc = *NULL_POINTER_MEMORY_MODEL;
            void* tns = *NULL_POINTER_MEMORY_MODEL;

            // Allocate terminated file name.
            allocate_model((void*) &tn, (void*) &tnc, (void*) &tns, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) CHARACTER_MEMORY_ABSTRACTION, (void*) CHARACTER_MEMORY_ABSTRACTION_COUNT);

            // Encode wide character name into multibyte character array.
            encode_utf_8_unicode_character_vector((void*) &tn, tnc, tns, p3, p4);

            // Add null termination character to terminated file name.
            overwrite_array((void*) &tn, (void*) NULL_CONTROL_ASCII_CHARACTER_CODE_MODEL, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, tnc, (void*) VALUE_PRIMITIVE_MEMORY_NAME, tnc, tns);

            // Open file.
            // CAUTION! The file name cannot be handed over as is.
            // CYBOI strings are NOT terminated with the null character '\0'.
            // Since 'fopen' expects a null terminated string, the termination character
            // must be added to the string before that is used to open the file.
            f = fopen((char*) tn, "r");

            if (f != *NULL_POINTER_MEMORY_MODEL) {

                receive_file_stream(p0, p1, p2, (void*) f);

                // Close file.
                // CAUTION! Check file for null pointer to avoid a segmentation fault!
                fclose(f);

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not receive file. The file is null.");
            }

            // Deallocate terminated file name.
            deallocate_model((void*) &tn, (void*) &tnc, (void*) &tns, *NULL_POINTER_MEMORY_MODEL, (void*) CHARACTER_MEMORY_ABSTRACTION, (void*) CHARACTER_MEMORY_ABSTRACTION_COUNT);
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not receive file. The source count is null.");
    }
}

/**
 * Applies the receive file system operation.
 *
 * @param p0 the destination model item (Hand over as item, since size may change!)
 * @param p1 the destination details item (Hand over as item, since size may change!)
 * @param p2 the source data (file name)
 * @param p3 the source count
 * @param p4 the abstraction
 */
void receive_file_system(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Receive file system.");

    // The encoded array, count, size.
    void* ea = *NULL_POINTER_MEMORY_MODEL;
    int ec = *NUMBER_0_INTEGER_MEMORY_MODEL;
    int es = *NUMBER_0_INTEGER_MEMORY_MODEL;

    // Allocate encoded array.
    allocate_array((void*) &ea, (void*) &es, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

    // Write file into encoded array.
    receive_file((void*) &ea, (void*) &ec, (void*) &es, p6, p7);

//??fwprintf(stdout, L"TEST char: %s\n", (char*) ea);

    // The decoded array, count, size.
    void* da = *NULL_POINTER_MEMORY_MODEL;
    int dc = *NUMBER_0_INTEGER_MEMORY_MODEL;
    int ds = *NUMBER_0_INTEGER_MEMORY_MODEL;

    // Allocate decoded array.
    allocate_array((void*) &da, (void*) &ds, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

    // Decode encoded character array into decoded wide character array.
    decode_utf_8_unicode_character_vector((void*) &da, (void*) &dc, (void*) &ds, ea, (void*) ec);

//??fwprintf(stdout, L"TEST w_char: %ls\n", (wchar_t*) da);

    // Deallocate encoded array.
    deallocate_array((void*) &ea, (void*) &es, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

    // Deserialise serialised wide character array into destination knowledge model.
    decode(p0, p1, da, (void*) &dc, p4);

    // Deallocate decoded array.
    deallocate_array((void*) &da, (void*) &ds, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);
}

/* GNU_LINUX_OPERATING_SYSTEM */
#endif

/* FILE_SYSTEM_RECEIVER_SOURCE */
#endif
