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
 * @version $RCSfile: file_communicator.c,v $ $Revision: 1.37 $ $Date: 2008-09-11 23:02:46 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef FILE_COMMUNICATOR_SOURCE
#define FILE_COMMUNICATOR_SOURCE

#include <stdio.h>
#include "../..//home/cybop/src/constant/model/character_code/unicode/unicode_character_code_model.c"
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../constant/abstraction/memory/array_memory_abstraction.c"
#include "../../constant/abstraction/memory/memory_abstraction.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../globals/constants/system/system_file_name_constants.c"
#include "../../logger/logger.c"
#include "../../variable/reallocation_factor.c"
#include "../../memoriser/converter/character/utf_8_unicode_character_converter.c"
#include "../../memoriser/array.c"

/**
 * Reads a file stream.
 *
 * @param p0 the destination byte array (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source file stream
 */
void read_file_stream(void* p0, void* p1, void* p2, void* p3) {

    if (p3 != *NULL_POINTER_MEMORY_MODEL) {

        if (p2 != *NULL_POINTER_MEMORY_MODEL) {

            int* ds = (int*) p2;

            if (p1 != *NULL_POINTER_MEMORY_MODEL) {

                int* dc = (int*) p1;

                if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                    void** d = (void**) p0;

                    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Read file stream.");

                    // Read first character.
                    char c = fgetc(p3);

                    while (*NUMBER_1_INTEGER_MEMORY_MODEL) {

                        if (c == EOF) {

                            break;
                        }

                        if (*dc == *ds) {

                            // Increase size.
                            *ds = (*ds * *CYBOL_FILE_REALLOCATION_FACTOR) + *NUMBER_1_INTEGER_MEMORY_MODEL;

                            // Reallocate array.
                            reallocate_array(p0, p1, p2, (void*) CHARACTER_ARRAY_MEMORY_ABSTRACTION);
                        }

                        if (*dc < *ds) {

                            // Set character in destination array.
                            // The array count serves as index for setting the character.
                            set_array_elements(*d, p1, (void*) &c, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) CHARACTER_ARRAY_MEMORY_ABSTRACTION);

                            // Increase array count.
                            (*dc)++;

                        } else {

                            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not read file stream. The index exceeds the array size.");
                        }

                        // Read next character.
                        c = fgetc(p3);
                    }

                } else {

                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not read file stream. The destination is null.");
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not read file stream. The destination count is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not read file stream. The destination size is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not read file stream. The file is null.");
    }
}

/**
 * Reads a file and writes it into a byte array.
 *
 * @param p0 the destination byte array (Hand over as reference!)
 * @param p1 the destination byte array count
 * @param p2 the destination byte array size
 * @param p3 the source file name
 * @param p4 the source file name count
 */
void read_file(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p4 != *NULL_POINTER_MEMORY_MODEL) {

        int* sc = (int*) p4;

        log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Read file.");

        // The comparison result.
        int r = *NUMBER_0_INTEGER_MEMORY_MODEL;
        // The file.
        FILE* f = (FILE*) *NULL_POINTER_MEMORY_MODEL;

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            compare_arrays(p3, p4, (void*) INPUT_SYSTEM_FILE_NAME, (void*) INPUT_SYSTEM_FILE_NAME_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

            if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                // The given string is not a file name, but specifies the "standard_input".
                f = stdin;

                read_file_stream(p0, p1, p2, (void*) f);
            }
        }

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            // If the given name does not match the standard input, then interpret it as file name.

            // The terminated file name.
            void* tn = *NULL_POINTER_MEMORY_MODEL;
            int tnc = *NUMBER_0_INTEGER_MEMORY_MODEL;
            int tns = *NUMBER_0_INTEGER_MEMORY_MODEL;

            // Allocate terminated file name.
            allocate_array((void*) &tn, (void*) &tns, (void*) CHARACTER_ARRAY_MEMORY_ABSTRACTION);

            // Encode wide character name into multibyte character array.
            encode_utf_8_unicode_character_vector((void*) &tn, (void*) &tnc, (void*) &tns, p3, p4);

            if (tns <= tnc) {

                // Increase character array size to have place for the termination character.
                tns = tnc + *NUMBER_1_INTEGER_MEMORY_MODEL;

                // Reallocate terminated file name as multibyte character array.
                reallocate_array((void*) &tn, (void*) &tnc, (void*) &tns, (void*) CHARACTER_ARRAY_MEMORY_ABSTRACTION);
            }

            // Add null termination character to terminated file name.
            set_array_elements(tn, (void*) &tnc, (void*) NULL_CONTROL_ASCII_CHARACTER_CODE_MODEL, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) CHARACTER_ARRAY_MEMORY_ABSTRACTION);

            // Open file.
            // CAUTION! The file name cannot be handed over as is.
            // CYBOI strings are NOT terminated with the null character '\0'.
            // Since 'fopen' expects a null terminated string, the termination character
            // must be added to the string before that is used to open the file.
            f = fopen((char*) tn, "r");

            if (f != *NULL_POINTER_MEMORY_MODEL) {

                read_file_stream(p0, p1, p2, (void*) f);

                // Close file.
                // CAUTION! Check file for null pointer to avoid a segmentation fault!
                fclose(f);

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not read file. The file is null.");
            }

            // Deallocate terminated file name.
            deallocate_array((void*) &tn, (void*) &tns, (void*) CHARACTER_ARRAY_MEMORY_ABSTRACTION);
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not read file. The source count is null.");
    }
}

/**
 * Writes a file stream.
 *
 * @param p0 the destination file stream
 * @param p1 the source byte array
 * @param p2 the source byte array count
 */
void write_file_stream(void* p0, void* p1, void* p2) {

    if (p2 != *NULL_POINTER_MEMORY_MODEL) {

        int* sc = (int*) p2;

        if (p0 != *NULL_POINTER_MEMORY_MODEL) {

            log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Write file stream.");

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
                get_array_elements(p1, (void*) &j, (void*) &c, (void*) CHARACTER_ARRAY_MEMORY_ABSTRACTION);

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

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not write file stream. The file is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not write file stream. The source count is null.");
    }
}

/**
 * Writes a file that was read from a byte array.
 *
 * @param p0 the destination file name (Hand over as reference!)
 * @param p1 the destination file name count
 * @param p2 the destination file name size
 * @param p3 the source byte array
 * @param p4 the source byte array count
 */
void write_file(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p1 != *NULL_POINTER_MEMORY_MODEL) {

        int* dc = (int*) p1;

        if (p0 != *NULL_POINTER_MEMORY_MODEL) {

            void** d = (void**) p0;

            log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Write file.");

            // The comparison result.
            int r = *NUMBER_0_INTEGER_MEMORY_MODEL;
            // The file.
            FILE* f = (FILE*) *NULL_POINTER_MEMORY_MODEL;

            if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                compare_arrays(*d, p1, (void*) OUTPUT_SYSTEM_FILE_NAME, (void*) OUTPUT_SYSTEM_FILE_NAME_COUNT, (void*) &r, (void*) CHARACTER_ARRAY_MEMORY_ABSTRACTION);

                if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    // The given string is not a file name, but specifies the "standard_output".
                    f = stdout;

                    write_file_stream((void*) f, p3, p4);

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

                compare_arrays(*d, p1, (void*) ERROR_OUTPUT_SYSTEM_FILE_NAME, (void*) ERROR_OUTPUT_SYSTEM_FILE_NAME_COUNT, (void*) &r, (void*) CHARACTER_ARRAY_MEMORY_ABSTRACTION);

                if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    // The given string is not a file name, but specifies the "standard_error_output".
                    f = stderr;

                    write_file_stream((void*) f, p3, p4);

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
                allocate_array((void*) &tn, (void*) &tns, (void*) CHARACTER_ARRAY_MEMORY_ABSTRACTION);

                // Encode wide character option into multibyte character array.
                encode_utf_8_unicode_character_vector((void*) &tn, (void*) &tnc, (void*) &tns, *d, p1);

                if (tns <= tnc) {

                    // Increase character array size to have place for the termination character.
                    tns = tnc + *NUMBER_1_INTEGER_MEMORY_MODEL;

                    // Reallocate terminated file name as multibyte character array.
                    reallocate_array((void*) &tn, (void*) &tnc, (void*) &tns, (void*) CHARACTER_ARRAY_MEMORY_ABSTRACTION);
                }

                // Add null termination character to terminated file name.
                set_array_elements(tn, (void*) &tnc, (void*) NULL_CONTROL_ASCII_CHARACTER_CODE_MODEL, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) CHARACTER_ARRAY_MEMORY_ABSTRACTION);

                // Open file.
                // CAUTION! The file name cannot be handed over as is.
                // CYBOI strings are NOT terminated with the null character '\0'.
                // Since 'fopen' expects a null terminated string, the termination character
                // must be added to the string before that is used to open the file.
                f = fopen((char*) tn, "w");

                if (f != *NULL_POINTER_MEMORY_MODEL) {

                    write_file_stream((void*) f, p3, p4);

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

                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not write file. The file is null.");
                }

                // Deallocate terminated file name.
                deallocate_array((void*) &tn, (void*) &tns, (void*) CHARACTER_ARRAY_MEMORY_ABSTRACTION);
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not write file. The destination is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not write file. The destination count is null.");
    }
}

/* FILE_COMMUNICATOR_SOURCE */
#endif
