/*
 * $RCSfile: file_communicator.c,v $
 *
 * Copyright (c) 1999-2005. Christian Heller and the CYBOP developers.
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
 * @version $Revision: 1.12 $ $Date: 2005-08-09 13:04:27 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef FILE_COMMUNICATOR_SOURCE
#define FILE_COMMUNICATOR_SOURCE

#include <stdio.h>
#include "../../globals/constants/character_constants.c"
#include "../../globals/constants/constant.c"
#include "../../globals/constants/integer_constants.c"
#include "../../globals/constants/structure_constants.c"
#include "../../globals/logger/logger.c"
#include "../../globals/variables/variables.c"
#include "../../memoriser/array.c"

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

        if (p2 != NULL_POINTER) {

            int* ds = (int*) p2;

            if (p1 != NULL_POINTER) {

                int* dc = (int*) p1;

                if (p0 != NULL_POINTER) {

                    void** d = (void**) p0;

                    // The terminated file name.
                    void* tn = NULL_POINTER;
                    int tns = *sc + 1;

                    // Create terminated file name.
                    allocate_array((void*) &tn, (void*) &tns, (void*) CHARACTER_ARRAY);

                    // Set terminated file name by first copying the actual name
                    // and then adding the null termination character.
                    set_array_elements(tn, (void*) NUMBER_0_INTEGER, p3, p4, (void*) CHARACTER_ARRAY);
                    set_array_elements(tn, p4, (void*) NULL_CONTROL_CHARACTER, (void*) CHARACTER_COUNT, (void*) CHARACTER_ARRAY);

                    // Open file.
                    // CAUTION! The file name cannot be handed over as is.
                    // CYBOI strings are NOT terminated with the null character '\0'.
                    // Since 'fopen' expects a null terminated string, the termination character
                    // must be added to the string before that is used to open the file.
                    FILE* f = fopen((char*) tn, "r");

                    if (f != NULL_POINTER) {

                        // Read first character.
                        char c = fgetc(f);

                        while (1) {

                            if (c == EOF) {

                                break;
                            }

                            if (*dc == *ds) {

                                // Increase size.
                                *ds = (*ds * *FILE_REALLOCATE_FACTOR) + 1;

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

                                log_message_debug("Could not read file. The index exceeds the array size.");
                            }

                            // Read next character.
                            c = fgetc(f);
                        }

                        // Close file.
                        fclose(f);

                    } else {

                        log_message_debug("Could not read file. The file is null.");
                    }

                    // Destroy terminated file name.
                    deallocate_array((void*) &tn, (void*) &tns, (void*) CHARACTER_ARRAY);

                } else {

                    log_message_debug("Could not read file. The destination is null.");
                }

            } else {

                log_message_debug("Could not read file. The destination count is null.");
            }

        } else {

            log_message_debug("Could not read file. The destination size is null.");
        }

    } else {

        log_message_debug("Could not read file. The source count is null.");
    }
}

/**
 * Write a file stream that was read from a byte array.
 *
 * @param p0 the destination file name (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source byte array
 * @param p4 the source count
 */
void write_file(void* p0, void* p1, void* p2, void* p3, void* p4) {

/*??
    char r = NULL_CONTROL_CHARACTER;
    int j = 0;
    char c = NULL_CONTROL_CHARACTER;

    while (1) {

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
}

/* FILE_COMMUNICATOR_SOURCE */
#endif
