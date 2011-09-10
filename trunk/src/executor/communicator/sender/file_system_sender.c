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

#ifndef FILE_SYSTEM_SENDER_SOURCE
#define FILE_SYSTEM_SENDER_SOURCE

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
#include "../../../executor/comparator/all/array_all_comparator.c"
#include "../../../executor/converter/encoder/utf_8_unicode_character_encoder.c"
#include "../../../executor/memoriser/allocator/model_allocator.c"
#include "../../../executor/memoriser/deallocator/model_deallocator.c"
#include "../../../logger/logger.c"
#include "../../../variable/reallocation_factor.c"

/**
 * Sends a character to file.
 *
 * @param p0 the destination file stream
 * @param p1 the source array
 * @param p2 the source array index
 * @param p3 the break flag
 */
void send_file_character(void* p0, void* p1, void* p2, void* p3) {

    // The character.
    char* c = (char*) *NULL_POINTER_MEMORY_MODEL;

    // Read character from source array.
    get_array_elements((void*) &c, p1, p2, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

    // Write character to file.
    char e = fputc(*c, (FILE*) p0);

    // Test error value.
    if (e == EOF) {

        // Set break flag, so that the loop can be left in the next cycle.
        copy_integer(p3, (void*) NUMBER_1_INTEGER_MEMORY_MODEL);
    }
}

/**
 * Sends a wide character to file.
 *
 * @param p0 the destination file stream
 * @param p1 the source array
 * @param p2 the source array index
 * @param p3 the break flag
 */
void send_file_wide_character(void* p0, void* p1, void* p2, void* p3) {

    // The character.
    char* c = (char*) *NULL_POINTER_MEMORY_MODEL;

    // Read character from source array.
    get_array_elements((void*) &c, p1, p2, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

    // Write character to file.
    //
    // CAUTION! Do NOT use the "fputwc" function here, but "fwprintf" instead.
    // The input is char, but the stdout output is set to wide character mode at cyboi startup.
    // Therefore, fwprintf is used to convert char to wchar_t output.
    int e = fwprintf((FILE*) p0, L"%s", c);

    // Test error value.
    if (e != *NUMBER_0_INTEGER_MEMORY_MODEL) {

        // Set break flag, so that the loop can be left in the next cycle.
        copy_integer(p3, (void*) NUMBER_1_INTEGER_MEMORY_MODEL);
    }
}

/**
 * Sends an element to file.
 *
 * @param p0 the destination file stream
 * @param p1 the source array
 * @param p2 the source array index
 * @param p3 the break flag
 * @param p4 the wide character flag (0 - char; 1 - wchar_t)
 */
void send_file_element(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p4 != *NULL_POINTER_MEMORY_MODEL) {

        int* w = (int*) p4;

        if (*w == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            send_file_character(p0, p1, p2, p3);

        } else {

            send_file_wide_character(p0, p1, p2, p3);
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not send file element. The wide character flag is null.");
    }
}

/**
 * Sends a file stream.
 *
 * @param p0 the destination file stream
 * @param p1 the source byte array
 * @param p2 the source byte array count
 * @param p3 the wide character flag (0 - char; 1 - wchar_t)
 */
void send_file_stream(void* p0, void* p1, void* p2, void* p3) {

    if (p2 != *NULL_POINTER_MEMORY_MODEL) {

        int* sc = (int*) p2;

        if (p0 != *NULL_POINTER_MEMORY_MODEL) {

            log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Send file stream.");

            // The loop variable.
            int j = *NUMBER_0_INTEGER_MEMORY_MODEL;
            // The break flag.
            int b = *NUMBER_0_INTEGER_MEMORY_MODEL;

            while (*TRUE_BOOLEAN_MEMORY_MODEL) {

                if ((j >= *sc) || (b != *NUMBER_0_INTEGER_MEMORY_MODEL)) {

                    break;
                }

                send_file_element(p0, p1, (void*) &j, (void*) &b, p3);

                j++;
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not send file stream. The file is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not send file stream. The source count is null.");
    }
}

/**
 * Sends a file that was read from a byte array.
 *
 * @param p0 the destination file name (Hand over as reference!)
 * @param p1 the destination file name count
 * @param p2 the destination file name size
 * @param p3 the source byte array
 * @param p4 the source byte array count
 */
void send_file(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p1 != *NULL_POINTER_MEMORY_MODEL) {

        int* dc = (int*) p1;

        if (p0 != *NULL_POINTER_MEMORY_MODEL) {

            void** d = (void**) p0;

            log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Send file.");

            // The comparison result.
            int r = *NUMBER_0_INTEGER_MEMORY_MODEL;
            // The file.
            FILE* f = (FILE*) *NULL_POINTER_MEMORY_MODEL;

            if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                compare_all_array((void*) &r, *d, (void*) STANDARD_OUTPUT_STREAM_MODEL, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p1, (void*) STANDARD_OUTPUT_STREAM_MODEL_COUNT);

                if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    // The given string is not a file name, but specifies the "standard_output".
                    f = stdout;

                    send_file_stream((void*) f, p3, p4, (void*) NUMBER_1_INTEGER_MEMORY_MODEL);

                    // Flush any buffered output on the stream to the file.
                    //
                    // If this was not done here, the buffered output on the
                    // stream would only get flushed automatically when either:
                    // - one tried to do output and the output buffer is full
                    // - the stream was closed
                    // - the program terminated by calling exit
                    // - a newline was written with the stream being line buffered
                    // - an input operation on any stream actually read data from its file
                    fflush(f);
                }
            }

            if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                compare_all_array((void*) &r, *d, (void*) STANDARD_ERROR_OUTPUT_STREAM_MODEL, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p1, (void*) STANDARD_ERROR_OUTPUT_STREAM_MODEL_COUNT);

                if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    // The given string is not a file name, but specifies the "standard_error_output".
                    f = stderr;

                    send_file_stream((void*) f, p3, p4, (void*) NUMBER_1_INTEGER_MEMORY_MODEL);

                    // Flush any buffered output on the stream to the file.
                    //
                    // If this was not done here, the buffered output on the
                    // stream would only get flushed automatically when either:
                    // - one tried to do output and the output buffer is full
                    // - the stream was closed
                    // - the program terminated by calling exit
                    // - a newline was written with the stream being line buffered
                    // - an input operation on any stream actually read data from its file
                    fflush(f);
                }
            }

            if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                // If the given name does neither match the standard output
                // nor the standard error output, then interpret it as file name.

                // The terminated file name.
                void* tn = *NULL_POINTER_MEMORY_MODEL;
                void* tnc = *NULL_POINTER_MEMORY_MODEL;
                void* tns = *NULL_POINTER_MEMORY_MODEL;

                // Allocate terminated file name.
                allocate_model((void*) &tn, (void*) &tnc, (void*) &tns, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) CHARACTER_MEMORY_ABSTRACTION, (void*) CHARACTER_MEMORY_ABSTRACTION_COUNT);

                // Encode wide character option into multibyte character array.
                encode_utf_8_unicode_character_vector((void*) &tn, tnc, tns, *d, p1);

                // Add null termination character to terminated file name.
                overwrite_array((void*) &tn, (void*) NULL_CONTROL_ASCII_CHARACTER_CODE_MODEL, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, tnc, (void*) VALUE_PRIMITIVE_MEMORY_NAME, tnc, tns);

                // Open file.
                // CAUTION! The file name cannot be handed over as is.
                // CYBOI strings are NOT terminated with the null character '\0'.
                // Since 'fopen' expects a null terminated string, the termination character
                // must be added to the string before that is used to open the file.
                f = fopen((char*) tn, "w");

                if (f != *NULL_POINTER_MEMORY_MODEL) {

                    send_file_stream((void*) f, p3, p4, (void*) NUMBER_0_INTEGER_MEMORY_MODEL);

                    // Flush any buffered output on the stream to the file.
                    //
                    // If this was not done here, the buffered output on the
                    // stream would only get flushed automatically when either:
                    // - one tried to do output and the output buffer is full
                    // - the stream was closed
                    // - the program terminated by calling exit
                    // - a newline was written with the stream being line buffered
                    // - an input operation on any stream actually read data from its file
                    fflush(f);

                    // Close file.
                    // CAUTION! Check file for null pointer to avoid a segmentation fault!
                    fclose(f);

                } else {

                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not send file. The file is null.");
                }

                // Deallocate terminated file name.
                deallocate_model((void*) &tn, (void*) &tnc, (void*) &tns, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) CHARACTER_MEMORY_ABSTRACTION, (void*) CHARACTER_MEMORY_ABSTRACTION_COUNT);
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not send file. The destination is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not send file. The destination count is null.");
    }
}

/**
 * Sends a knowledge model as byte stream to the operating system's file system.
 *
 * @param p0 the internal memory
 * @param p1 the source name
 * @param p2 the source name count
 * @param p3 the source abstraction
 * @param p4 the source abstraction count
 * @param p5 the source model
 * @param p6 the source model count
 * @param p7 the source details
 * @param p8 the source details count
 * @param p9 the knowledge memory
 * @param p10 the knowledge memory count
 * @param p11 the language model
 * @param p12 the language model count
 * @param p13 the source clean flag
 * @param p14 the source clean flag count
 * @param p15 the file name
 * @param p16 the file name count
 */
void apply_send_file_system(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8,
    void* p9, void* p10, void* p11, void* p12, void* p13, void* p14, void* p15, void* p16) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Apply send file system.");

    // The serialised wide character array.
    void* s = *NULL_POINTER_MEMORY_MODEL;
    void* sc = *NULL_POINTER_MEMORY_MODEL;
    void* ss = *NULL_POINTER_MEMORY_MODEL;

    // Allocate serialised wide character array.
    allocate_model((void*) &s, (void*) &sc, (void*) &ss, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT);

    // Serialise source knowledge model into serialised wide character array.
    encode((void*) &s, sc, ss,
        p1, p2, p3, p4, p5, p6, p7, p8,
        *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL,
        p9, p10, p11, p12);

    // The encoded character array.
    void* e = *NULL_POINTER_MEMORY_MODEL;
    void* ec = *NULL_POINTER_MEMORY_MODEL;
    void* es = *NULL_POINTER_MEMORY_MODEL;

    // Allocate encoded character array.
    allocate_model((void*) &e, (void*) &ec, (void*) &es, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) CHARACTER_MEMORY_ABSTRACTION, (void*) CHARACTER_MEMORY_ABSTRACTION_COUNT);

    // Encode serialised wide character array into encoded character array.
    encode_utf_8_unicode_character_vector((void*) &e, ec, es, s, sc);

    // Deallocate serialised wide character array.
    deallocate_model((void*) &s, (void*) &sc, (void*) &ss, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT);

    // Write encoded array into file.
    send_data((void*) &p15, p16, *NULL_POINTER_MEMORY_MODEL, e, ec, (void*) FILE_SYSTEM_CYBOL_CHANNEL, (void*) FILE_SYSTEM_CYBOL_CHANNEL_COUNT);

    // Deallocate encoded character array.
    deallocate_model((void*) &e, (void*) &ec, (void*) &es, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) CHARACTER_MEMORY_ABSTRACTION, (void*) CHARACTER_MEMORY_ABSTRACTION_COUNT);
}

/* FILE_SYSTEM_SENDER_SOURCE */
#endif
