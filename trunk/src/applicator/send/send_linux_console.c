/*
 * $RCSfile: send_linux_console.c,v $
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
 * @version $Revision: 1.7 $ $Date: 2005-07-20 08:18:30 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef SEND_LINUX_CONSOLE_SOURCE
#define SEND_LINUX_CONSOLE_SOURCE

#include <stdio.h>
#include <unistd.h>
#include "../../globals/constants/character_constants.c"
#include "../../globals/constants/structure_constants.c"
#include "../../globals/variables/variables.c"
#include "../../memoriser/array.c"

/**
 * Receives a tui source and writes it into a destination byte array.
 *
 * @param p0 the destination (byte array) (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source
 * @param p4 the source count
 */
void receive_linux_console(void* p0, void* p1, void* p2, const void* p3, const void* p4) {

/*??
    if (p4 != NULL_POINTER) {

        int* nc = (int*) p4;

        if (p3 != NULL_POINTER) {

            void** n = (void**) p3;

            if (p2 != NULL_POINTER) {

                int* as = (int*) p2;

                if (p1 != NULL_POINTER) {

                    int* ac = (int*) p1;

                    // Initialize terminated file name and its size.
                    char* tn = CHARACTER_NULL_POINTER;
                    int tns = *nc + 1;

                    // Create terminated file name.
                    create_array((void*) &tn, (void*) &CHARACTER_ARRAY, (void*) &tns);

                    // Initialize destination array index.
                    int i = 0;

                    // Set terminated file name by first copying the actual name and then
                    // adding the null termination character.
                    set_array_elements((void*) &tn, (void*) CHARACTER_ARRAY, (void*) &i, p3, p4);
                    set_array_elements((void*) &tn, (void*) CHARACTER_ARRAY, p4, (void*) &NULL_CONTROL_CHARACTER, (void*) &NULL_CONTROL_CHARACTER_COUNT);

                    // Open file.
                    // CAUTION! The file name cannot be handed over as is.
                    // CYBOI strings are NOT terminated with the null character '\0'.
                    // Since 'fopen' expects a null terminated string, the termination character
                    // must be added to the string before that is used to open the file.
                    FILE* f = fopen(tn, "r");

                    if (f != NULL_POINTER) {

                        // Read first character.
                        char c = fgetc(f);

                        while (1) {

                            if (c == EOF) {

                                break;
                            }

                            if (*ac == *as) {

                                // Increase size.
                                *as = *as * FILE_RESIZE_FACTOR + 1;

                                // Resize array.
                                resize_array(p0, (void*) &CHARACTER_ARRAY, p2);
                            }

                            if (*ac < *as) {

                                // Set character in destination array.
                                // The array count serves as index for setting the character.
                                set_array_elements(p0, (void*) CHARACTER_ARRAY, p1, (void*) &c);

                                // Increase array count.
                                (*ac)++;

                            } else {

//??                                log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not read file. The index exceeds the array size.");
                            }

                            // Read next character.
                            c = fgetc(f);
                        }

                        // Close file.
                        fclose(f);

                        // Destroy terminated file name.
                        destroy_array((void*) &tn, (void*) &CHARACTER_ARRAY, (void*) &tns);

                    } else {

//??                        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not read file. The file is null.");
                    }

                } else {

//??                    log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not read file. The array count is null.");
                }

            } else {

//??                log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not read file. The array size is null.");
            }

        } else {

//??            log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not read file. The file name is null.");
        }

    } else {

//??        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not read file. The file name count is null.");
    }
*/
}

/**
 * Sends a destination tui that was read from a source byte array.
 *
 * @param p0 the destination (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source
 * @param p4 the source count
 */
void send_linux_console(void* p0, void* p1, void* p2, const void* p3, const void* p4) {

    if (p4 != NULL_POINTER) {

        int* sc = (int*) p4;

        if (p3 != NULL_POINTER) {

            void* s = (void*) p3;

            if (p0 != NULL_POINTER) {

                void** d = (void**) p0;

                    log_message_debug("Send linux console.");

                    // Set blue background.
                    printf("\033[44m");
                    // Clear screen.
                    printf("\033[2J");
                    // Position cursor.
                    int column = 10;
                    int row = 5;
                    printf("\033[%d;%dH", column, row);

                    printf("%s", (char*) p3);

                    // Set default background.
//??                    printf("\033[0m");

                    getc(stdin);

/*??
                    // The temporary null-terminated message.
                    char* tmp = NULL_POINTER;
                    int tmps = **sc + 1;

                    // The index.
                    int* i = INTEGER_NULL_POINTER;
                    create_integer((void*) &i);
                    *i = 0;

                    // Create temporary null-terminated message.
                    create_array((void*) &tmp, (void*) &CHARACTER_ARRAY, (void*) &tmps);

                    // Copy original message to temporary null-terminated message.
                    set_array_elements((void*) &tmp, (void*) CHARACTER_ARRAY, (void*) &i, p3, p4);
                    // This is used as index to set the termination character.
                    *i = **sc;
                    // Add string termination to temporary null-terminated message.
                    set_array_elements((void*) &tmp, (void*) CHARACTER_ARRAY, (void*) &i, (void*) &NULL_CONTROL_CHARACTER, (void*) &NULL_CONTROL_CHARACTER_COUNT);

                    destroy_integer((void*) &i);

                    fputs(tmp, (FILE*) *d);
                    fputs("\n", (FILE*) *d);

                    // Beep \007 twice with system loudspeaker.
//??                    fputs("Beep:\n\007", (FILE*) *d);

                    //
                    // Start ESCAPE CSI sequence with: \033[
                    //

                    // Print bold word.
//??                    fputs("This is a \033[1mbold\033[0m word.\n", (FILE*) *d);

                    // Set colours.
                    // CAUTION! The "m" has to stand after the colour number
                    // and it must NOT be a capital letter.
//??                    fputs("Set colour to \033[32mgreen\033[0m.\n", (FILE*) *d);
//??                    fputs("Set colour to \033[32myellow\041[0m.\n", (FILE*) *d);
//??                    fputs("Set colour to \033[32mred\031[0m.\n", (FILE*) *d);

                    // Destroy temporary null-terminated message.
                    destroy_array((void*) &tmp, (void*) &CHARACTER_ARRAY, (void*) &tmps);
*/

            } else {

        //??        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not read file. The file name count is null.");
            }

        } else {

    //??        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not read file. The file name count is null.");
        }

    } else {

//??        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not read file. The file name count is null.");
    }
}

/* SEND_LINUX_CONSOLE_SOURCE */
#endif
