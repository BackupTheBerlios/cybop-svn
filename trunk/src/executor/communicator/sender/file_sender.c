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
 * @version $RCSfile: file_communicator.c,v $ $Revision: 1.43 $ $Date: 2009-01-31 16:06:33 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef FILE_SENDER_SOURCE
#define FILE_SENDER_SOURCE

#include <stdio.h>
#include "../../../constant/abstraction/memory/memory_abstraction.c"
#include "../../../constant/abstraction/memory/memory_abstraction.c"
#include "../../../constant/model/character_code/ascii/ascii_character_code_model.c"
#include "../../../constant/model/character_code/unicode/unicode_character_code_model.c"
#include "../../../constant/model/memory/integer_memory_model.c"
#include "../../../constant/model/memory/pointer_memory_model.c"
#include "../../../constant/model/stream_model.c"
#include "../../../logger/logger.c"
#include "../../../executor/comparator/array_equality_comparator.c"
#include "../../../executor/converter/encoder/utf_8_unicode_character_encoder.c"
#include "../../../variable/reallocation_factor.c"

/**
 * Sends a file stream.
 *
 * @param p0 the destination file stream
 * @param p1 the source byte array
 * @param p2 the source byte array count
 */
void send_file_stream(void* p0, void* p1, void* p2) {

    if (p2 != *NULL_POINTER_MEMORY_MODEL) {

        int* sc = (int*) p2;

        if (p0 != *NULL_POINTER_MEMORY_MODEL) {

            log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Send file stream.");

            // The loop variable.
            int j = *NUMBER_0_INTEGER_MEMORY_MODEL;
            // The character.
            char* c = (char*) *NULL_POINTER_MEMORY_MODEL;
            // The error value.
            char e = EOF;

            while (*NUMBER_1_INTEGER_MEMORY_MODEL) {

                if (j >= *sc) {

                    break;
                }

                // Read character from source array.
                get_array_elements(p1, (void*) &j, (void*) &c, (void*) CHARACTER_MEMORY_ABSTRACTION);

                // Write character to file.
                e = fputc(*c, (FILE*) p0);

                if (e == EOF) {

                    // Set loop variable to source count, so that the
                    // loop can be left in the next cycle.
                    j = *sc;
                }

                // Increment loop variable.
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

                compare_equal_arrays(*d, p1, (void*) STANDARD_OUTPUT_STREAM_MODEL, (void*) STANDARD_OUTPUT_STREAM_MODEL_COUNT, (void*) &r, (void*) CHARACTER_MEMORY_ABSTRACTION);

                if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    // The given string is not a file name, but specifies the "standard_output".
                    f = stdout;

                    send_file_stream((void*) f, p3, p4);

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

                compare_equal_arrays(*d, p1, (void*) STANDARD_ERROR_OUTPUT_STREAM_MODEL, (void*) STANDARD_ERROR_OUTPUT_STREAM_MODEL_COUNT, (void*) &r, (void*) CHARACTER_MEMORY_ABSTRACTION);

                if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    // The given string is not a file name, but specifies the "standard_error_output".
                    f = stdout;

                    send_file_stream((void*) f, p3, p4);

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
                int tnc = *NUMBER_0_INTEGER_MEMORY_MODEL;
                int tns = *NUMBER_0_INTEGER_MEMORY_MODEL;

                // Allocate terminated file name.
                allocate_array((void*) &tn, (void*) &tns, (void*) CHARACTER_MEMORY_ABSTRACTION);

                // Encode wide character option into multibyte character array.
                encode_utf_8_unicode_character_vector((void*) &tn, (void*) &tnc, (void*) &tns, *d, p1);

                if (tns <= tnc) {

                    // Increase character array size to have place for the termination character.
                    tns = tnc + *NUMBER_1_INTEGER_MEMORY_MODEL;

                    // Reallocate terminated file name as multibyte character array.
                    reallocate_array((void*) &tn, (void*) &tnc, (void*) &tns, (void*) CHARACTER_MEMORY_ABSTRACTION);
                }

                // Add null termination character to terminated file name.
                set_array_elements(tn, (void*) &tnc, (void*) NULL_CONTROL_ASCII_CHARACTER_CODE_MODEL, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) CHARACTER_MEMORY_ABSTRACTION);

                // Open file.
                // CAUTION! The file name cannot be handed over as is.
                // CYBOI strings are NOT terminated with the null character '\0'.
                // Since 'fopen' expects a null terminated string, the termination character
                // must be added to the string before that is used to open the file.
                f = fopen((char*) tn, "w");

                if (f != *NULL_POINTER_MEMORY_MODEL) {

                    send_file_stream((void*) f, p3, p4);

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
                deallocate_array((void*) &tn, (void*) &tns, (void*) CHARACTER_MEMORY_ABSTRACTION);
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not send file. The destination is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not send file. The destination count is null.");
    }
}

/* FILE_SENDER_SOURCE */
#endif
