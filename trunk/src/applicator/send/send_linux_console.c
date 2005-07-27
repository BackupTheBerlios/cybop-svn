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
 * @version $Revision: 1.16 $ $Date: 2005-07-27 13:30:20 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef SEND_LINUX_CONSOLE_SOURCE
#define SEND_LINUX_CONSOLE_SOURCE

#include <stdio.h>
#include <unistd.h>
#include "../../globals/constants/channel_constants.c"
#include "../../globals/constants/character_constants.c"
#include "../../globals/constants/structure_constants.c"
#include "../../globals/variables/variables.c"
#include "../../memoriser/array.c"

/**
 * Receives a tui source and writes it into a destination byte array.
 *
 * @param p0 the destination byte array (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source
 * @param p4 the source count
 */
void receive_linux_console(void* p0, void* p1, void* p2, void* p3, void* p4) {

/*??
    if (p4 != NULL_POINTER) {

        int* nc = (int*) p4;

        if (p3 != NULL_POINTER) {

            void** n = (void**) p3;

            if (p2 != NULL_POINTER) {

                int* as = (int*) p2;

                if (p1 != NULL_POINTER) {

                    int* ac = (int*) p1;

                    // Initialise terminated file name and its size.
                    char* tn = CHARACTER_NULL_POINTER;
                    int tns = *nc + 1;

                    // Create terminated file name.
                    allocate_array((void*) &tn, (void*) &CHARACTER_ARRAY, (void*) &tns);

                    // Initialise destination array index.
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
                        deallocate_array((void*) &tn, (void*) &CHARACTER_ARRAY, (void*) &tns);

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
 * @param p0 the destination terminal (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source tui compound model
 * @param p4 the source count
 */
void send_linux_console(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message_debug("Send via linux console.");

/*??
    // The tui.
    void* t = NULL_POINTER;
    int* tc = NULL_POINTER;
    int* ts = NULL_POINTER;

    // The tui internal.
    void** ti = NULL_POINTER;
    int** tic = NULL_POINTER;
    int** tis = NULL_POINTER;

    // Get tui internal.
    get_array_elements(p0, (void*) TUI_INTERNAL, (void*) &ti, (void*) POINTER_ARRAY);
    get_array_elements(p0, (void*) TUI_COUNT_INTERNAL, (void*) &tic, (void*) POINTER_ARRAY);
    get_array_elements(p0, (void*) TUI_SIZE_INTERNAL, (void*) &tis, (void*) POINTER_ARRAY);

    // Assign tui internal to real tui.
    t = *ti;
    tc = *tic;
    ts = *tis;

    if (t == NULL_POINTER) {

        // The vector count and size x, y, z elements.
        int* tcx = NULL_POINTER;
        int* tcy = NULL_POINTER;
        int* tcz = NULL_POINTER;
        int* tsx = NULL_POINTER;
        int* tsy = NULL_POINTER;
        int* tsz = NULL_POINTER;

        // Allocate vector count and size x, y, z elements.
        allocate((void*) &tcx, (void*) INTEGER_ABSTRACTION, (void*) INTEGER_ABSTRACTION_COUNT);
        allocate((void*) &tcy, (void*) INTEGER_ABSTRACTION, (void*) INTEGER_ABSTRACTION_COUNT);
        allocate((void*) &tcz, (void*) INTEGER_ABSTRACTION, (void*) INTEGER_ABSTRACTION_COUNT);
        allocate((void*) &tsx, (void*) INTEGER_ABSTRACTION, (void*) INTEGER_ABSTRACTION_COUNT);
        allocate((void*) &tsy, (void*) INTEGER_ABSTRACTION, (void*) INTEGER_ABSTRACTION_COUNT);
        allocate((void*) &tsz, (void*) INTEGER_ABSTRACTION, (void*) INTEGER_ABSTRACTION_COUNT);

        // Initialise vector count and size x, y, z elements.
        *tcx = 0;
        *tcy = 0;
        *tcz = 0;
        *tsx = 0;
        *tsy = 0;
        *tsz = 0;

        // Allocate tui count and size.
        allocate((void*) &tc, (void*) NUMBER_3_INTEGER, (void*) VECTOR_ABSTRACTION, (void*) VECTOR_ABSTRACTION_COUNT);
        allocate((void*) &tS, (void*) NUMBER_3_INTEGER, (void*) VECTOR_ABSTRACTION, (void*) VECTOR_ABSTRACTION_COUNT);

        // Initialise tui count and size.
        set_vector_element((void*) &tc, (void*) NUMBER_0_INTEGER, (void*) tcx);
        set_vector_element((void*) &tc, (void*) NUMBER_1_INTEGER, (void*) tcy);
        set_vector_element((void*) &tc, (void*) NUMBER_2_INTEGER, (void*) tcz);
        set_vector_element((void*) &ts, (void*) NUMBER_0_INTEGER, (void*) tsx);
        set_vector_element((void*) &ts, (void*) NUMBER_1_INTEGER, (void*) tsy);
        set_vector_element((void*) &ts, (void*) NUMBER_2_INTEGER, (void*) tsz);

        // Allocate tui.
        allocate((void*) &t, (void*) ts, (void*) TUI_ABSTRACTION, (void*) TUI_ABSTRACTION_COUNT);

        // Set tui internals.
        set_array_elements(p0, (void*) TUI_INTERNAL, (void*) &t, (void*) NUMBER_1_INTEGER, (void*) POINTER_ARRAY);
        set_array_elements(p0, (void*) TUI_COUNT_INTERNAL, (void*) &tc, (void*) NUMBER_1_INTEGER, (void*) POINTER_ARRAY);
        set_array_elements(p0, (void*) TUI_SIZE_INTERNAL, (void*) &ts, (void*) NUMBER_1_INTEGER, (void*) POINTER_ARRAY);
    }

    // Encode compound model into tui.
    encode((void*) &t, (void*) tc, (void*) ts, p3, p4);

    // The serialised string array to be sent to the terminal.
    void* a = NULL_POINTER;
    int ac = 0;
    int as = 0;

    // Create array.
    allocate((void*) &a, (void*) &as, (void*) STRING_ABSTRACTION, (void*) STRING_ABSTRACTION_COUNT);

    // Serialise multi-dimensional tui into array.
    serialise((void*) &a, (void*) &ac, (void*) &as, t, (void*) tc);

    // Write serialised array as message to terminal.
    write_data(p0, p1, p2, a, (void*) &ac);

    // Destroy array.
    deallocate((void*) &a, (void*) &as, (void*) STRING_ABSTRACTION, (void*) STRING_ABSTRACTION_COUNT);
*/

    //?? TEST.
    write_data(p0, p1, p2, p3, p4, (void*) TERMINAL_CHANNEL, (void*) TERMINAL_CHANNEL_COUNT);
}

/* SEND_LINUX_CONSOLE_SOURCE */
#endif
