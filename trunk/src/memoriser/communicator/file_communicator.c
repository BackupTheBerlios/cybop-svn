/*
 * $RCSfile: file_communicator.c,v $
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
 * @version $Revision: 1.19 $ $Date: 2007-04-07 12:15:28 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef FILE_COMMUNICATOR_SOURCE
#define FILE_COMMUNICATOR_SOURCE

#include <stdio.h>
#include "../../globals/constants/ascii_character_constants.c"
#include "../../globals/constants/cyboi_constants.c"
#include "../../globals/constants/integer_constants.c"
#include "../../globals/constants/structure_constants.c"
#include "../../globals/constants/system_constants.c"
#include "../../globals/logger/logger.c"
#include "../../globals/variables/variables.c"
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

    if (p3 != NULL_POINTER) {

        if (p2 != NULL_POINTER) {

            int* ds = (int*) p2;

            if (p1 != NULL_POINTER) {

                int* dc = (int*) p1;

                if (p0 != NULL_POINTER) {

                    void** d = (void**) p0;

                    // Read first character.
                    char c = fgetc(p3);

                    while (*NUMBER_1_INTEGER) {

                        if (c == EOF) {

                            break;
                        }

                        if (*dc == *ds) {

                            // Increase size.
                            *ds = (*ds * *FILE_REALLOCATE_FACTOR) + *NUMBER_1_INTEGER;

                            // Reallocate array.
                            reallocate_array(p0, p1, p2, (void*) CHARACTER_ARRAY);
                        }

                        if (*dc < *ds) {

                            // Set character in destination array.
                            // The array count serves as index for setting the character.
                            set_array_elements(*d, p1, (void*) &c, (void*) NUMBER_1_INTEGER, (void*) CHARACTER_ARRAY);

                            // Increase array count.
                            (*dc)++;

                        } else {

                            log_message_debug("Could not read file stream. The index exceeds the array size.");
                        }

                        // Read next character.
                        c = fgetc(p3);
                    }

                } else {

                    log_message_debug("Could not read file stream. The destination is null.");
                }

            } else {

                log_message_debug("Could not read file stream. The destination count is null.");
            }

        } else {

            log_message_debug("Could not read file stream. The destination size is null.");
        }

    } else {

        log_message_debug("Could not read file stream. The file is null.");
    }
}

/**
 * Reads a file stream and writes it into a byte array.
 *
 * @param p0 the destination byte array (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source file name
 * @param p4 the source count
 */
void read_file(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p4 != NULL_POINTER) {

        int* sc = (int*) p4;

        // The comparison result.
        int r = *NUMBER_0_INTEGER;
        // The terminated file name.
        void* tn = NULL_POINTER;
        int tns = *sc + *NUMBER_1_INTEGER;
        // The file.
        FILE* f = NULL_POINTER;

        if (r == *NUMBER_0_INTEGER) {

            compare_arrays(p3, p4, (void*) STANDARD_INPUT_FILE_NAME, (void*) STANDARD_INPUT_FILE_NAME_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

            if (r != *NUMBER_0_INTEGER) {

                // The given string is not a file name, but specifies the "standard_input".
                f = stdin;

                read_file_stream(p0, p1, p2, (void*) f);
            }
        }

        if (r == *NUMBER_0_INTEGER) {

            // If the given name does not match the standard input, then interpret it as file name.

            // Allocate terminated file name.
            allocate_array((void*) &tn, (void*) &tns, (void*) CHARACTER_ARRAY);

            // Set terminated file name by first copying the actual name
            // and then adding the null termination character.
            set_array_elements(tn, (void*) NUMBER_0_INTEGER, p3, p4, (void*) CHARACTER_ARRAY);
            set_array_elements(tn, p4, (void*) NULL_CONTROL_ASCII_CHARACTER, (void*) PRIMITIVE_COUNT, (void*) CHARACTER_ARRAY);

            // Open file.
            // CAUTION! The file name cannot be handed over as is.
            // CYBOI strings are NOT terminated with the null character '\0'.
            // Since 'fopen' expects a null terminated string, the termination character
            // must be added to the string before that is used to open the file.
            f = fopen((char*) tn, "r");

            read_file_stream(p0, p1, p2, (void*) f);

            // Close file.
            fclose(f);

            // Deallocate terminated file name.
            deallocate_array((void*) &tn, (void*) &tns, (void*) CHARACTER_ARRAY);
        }

    } else {

        log_message_debug("Could not read file. The source count is null.");
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

    if (p2 != NULL_POINTER) {

        int* sc = (int*) p2;

        if (p0 != NULL_POINTER) {

            // The loop variable.
            int j = *NUMBER_0_INTEGER;
            // The character.
            char* c = NULL_POINTER;
            // The error value.
            char e = EOF;

            while (*NUMBER_1_INTEGER) {

                if (j >= *sc) {

                    break;
                }

                // Read character from source array.
                get_array_elements(p1, (void*) &j, (void*) &c, (void*) CHARACTER_ARRAY);

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

            log_message_debug("Could not write file stream. The file is null.");
        }

    } else {

        log_message_debug("Could not write file stream. The source count is null.");
    }
}

/**
 * Write a file stream that was read from a byte array.
 *
 * @param p0 the destination file name (Hand over as reference!)
 * @param p1 the destination file name count
 * @param p2 the destination file name size
 * @param p3 the source byte array
 * @param p4 the source byte array count
 */
void write_file(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p1 != NULL_POINTER) {

        int* dc = (int*) p1;

        // The comparison result.
        int r = *NUMBER_0_INTEGER;
        // The terminated file name.
        void* tn = NULL_POINTER;
        int tns = *dc + *NUMBER_1_INTEGER;
        // The file.
        FILE* f = NULL_POINTER;

        if (r == *NUMBER_0_INTEGER) {

            compare_arrays(p0, p1, (void*) STANDARD_OUTPUT_FILE_NAME, (void*) STANDARD_OUTPUT_FILE_NAME_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

            if (r != *NUMBER_0_INTEGER) {

                // The given string is not a file name, but specifies the "standard_output".
                f = stdout;

                write_file_stream((void*) f, p3, p4);
            }
        }

        if (r == *NUMBER_0_INTEGER) {

            compare_arrays(p0, p1, (void*) STANDARD_ERROR_OUTPUT_FILE_NAME, (void*) STANDARD_ERROR_OUTPUT_FILE_NAME_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

            if (r != *NUMBER_0_INTEGER) {

                // The given string is not a file name, but specifies the "standard_error_output".
                f = stderr;

                write_file_stream((void*) f, p3, p4);
            }
        }

        if (r == *NUMBER_0_INTEGER) {

            // If the given name does not match the standard input, then interpret it as file name.

            // Allocate terminated file name.
            allocate_array((void*) &tn, (void*) &tns, (void*) CHARACTER_ARRAY);

            // Set terminated file name by first copying the actual name
            // and then adding the null termination character.
            set_array_elements(tn, (void*) NUMBER_0_INTEGER, p0, p1, (void*) CHARACTER_ARRAY);
            set_array_elements(tn, p1, (void*) NULL_CONTROL_ASCII_CHARACTER, (void*) PRIMITIVE_COUNT, (void*) CHARACTER_ARRAY);

            // Open file.
            // CAUTION! The file name cannot be handed over as is.
            // CYBOI strings are NOT terminated with the null character '\0'.
            // Since 'fopen' expects a null terminated string, the termination character
            // must be added to the string before that is used to open the file.
            f = fopen((char*) tn, "r");

            write_file_stream((void*) f, p3, p4);

            // Close file.
            fclose(f);

            // Deallocate terminated file name.
            deallocate_array((void*) &tn, (void*) &tns, (void*) CHARACTER_ARRAY);
        }

    } else {

        log_message_debug("Could not write file. The destination count is null.");
    }
}

/* FILE_COMMUNICATOR_SOURCE */
#endif
