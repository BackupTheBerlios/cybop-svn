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
 * @version $Revision: 1.24 $ $Date: 2005-07-30 14:03:50 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef SEND_LINUX_CONSOLE_SOURCE
#define SEND_LINUX_CONSOLE_SOURCE

#include <stdio.h>
#include <unistd.h>
#include "../../globals/constants/abstraction_constants.c"
#include "../../globals/constants/boolean_constants.c"
#include "../../globals/constants/channel_constants.c"
#include "../../globals/constants/character_constants.c"
#include "../../globals/constants/control_sequence_constants.c"
#include "../../globals/constants/structure_constants.c"
#include "../../globals/variables/variables.c"
#include "../../memoriser/accessor.c"
#include "../../memoriser/allocator.c"
#include "../../memoriser/array.c"
#include "../../memoriser/converter.c"
#include "../../memoriser/translator.c"

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
                    char* tn = NULL_POINTER;
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

    // The tui.
    void* t = NULL_POINTER;
    void** tp = &t;
    int* tc = NULL_POINTER;
    int** tcp = &tc;
    int* ts = NULL_POINTER;
    int** tsp = &ts;

    // Get tui internal.
    get(p0, (void*) TUI_INTERNAL, (void*) &tp, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    get(p0, (void*) TUI_COUNT_INTERNAL, (void*) &tcp, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    get(p0, (void*) TUI_SIZE_INTERNAL, (void*) &tsp, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

    if (t == NULL_POINTER) {

        // The count and size z, y, x coordinates.
        int* tcz = NULL_POINTER;
        int* tcy = NULL_POINTER;
        int* tcx = NULL_POINTER;
        int* tsz = NULL_POINTER;
        int* tsy = NULL_POINTER;
        int* tsx = NULL_POINTER;

        // Allocate count and size z, y, x coordinates.
        allocate((void*) &tcz, (void*) INTEGER_COUNT, (void*) INTEGER_ABSTRACTION, (void*) INTEGER_ABSTRACTION_COUNT);
        allocate((void*) &tcy, (void*) INTEGER_COUNT, (void*) INTEGER_ABSTRACTION, (void*) INTEGER_ABSTRACTION_COUNT);
        allocate((void*) &tcx, (void*) INTEGER_COUNT, (void*) INTEGER_ABSTRACTION, (void*) INTEGER_ABSTRACTION_COUNT);
        allocate((void*) &tsz, (void*) INTEGER_COUNT, (void*) INTEGER_ABSTRACTION, (void*) INTEGER_ABSTRACTION_COUNT);
        allocate((void*) &tsy, (void*) INTEGER_COUNT, (void*) INTEGER_ABSTRACTION, (void*) INTEGER_ABSTRACTION_COUNT);
        allocate((void*) &tsx, (void*) INTEGER_COUNT, (void*) INTEGER_ABSTRACTION, (void*) INTEGER_ABSTRACTION_COUNT);

        // Initialise count and size z, y, x coordinates.
        set(tcz, (void*) INTEGER_VALUE_INDEX, (void*) NUMBER_0_INTEGER, (void*) INTEGER_ABSTRACTION, (void*) INTEGER_ABSTRACTION_COUNT);
        set(tcy, (void*) INTEGER_VALUE_INDEX, (void*) NUMBER_0_INTEGER, (void*) INTEGER_ABSTRACTION, (void*) INTEGER_ABSTRACTION_COUNT);
        set(tcx, (void*) INTEGER_VALUE_INDEX, (void*) NUMBER_0_INTEGER, (void*) INTEGER_ABSTRACTION, (void*) INTEGER_ABSTRACTION_COUNT);
        set(tsz, (void*) INTEGER_VALUE_INDEX, (void*) NUMBER_0_INTEGER, (void*) INTEGER_ABSTRACTION, (void*) INTEGER_ABSTRACTION_COUNT);
        set(tsy, (void*) INTEGER_VALUE_INDEX, (void*) NUMBER_0_INTEGER, (void*) INTEGER_ABSTRACTION, (void*) INTEGER_ABSTRACTION_COUNT);
        set(tsx, (void*) INTEGER_VALUE_INDEX, (void*) NUMBER_0_INTEGER, (void*) INTEGER_ABSTRACTION, (void*) INTEGER_ABSTRACTION_COUNT);

        // Allocate tui count and size.
        allocate((void*) &tc, (void*) TUI_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
        allocate((void*) &ts, (void*) TUI_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);

        // Initialise tui count and size.
        set(tc, (void*) TUI_Z_DIMENSION_INDEX, (void*) tcz, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
        set(tc, (void*) TUI_Y_DIMENSION_INDEX, (void*) tcy, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
        set(tc, (void*) TUI_X_DIMENSION_INDEX, (void*) tcx, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
        set(ts, (void*) TUI_Z_DIMENSION_INDEX, (void*) tsz, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
        set(ts, (void*) TUI_Y_DIMENSION_INDEX, (void*) tsy, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
        set(ts, (void*) TUI_X_DIMENSION_INDEX, (void*) tsx, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);

        // Allocate tui.
        allocate((void*) &t, (void*) tsz, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

        // Set tui internals.
        set(p0, (void*) TUI_INTERNAL, (void*) t, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        set(p0, (void*) TUI_COUNT_INTERNAL, (void*) tc, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        set(p0, (void*) TUI_SIZE_INTERNAL, (void*) ts, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    }

    // Encode compound model into tui.
    encode((void*) &t, (void*) tc, (void*) ts, p3, p4, (void*) TUI_ABSTRACTION, (void*) TUI_ABSTRACTION_COUNT);

    // The serialised string array to be sent to the terminal.
    void* a = NULL_POINTER;
    int ac = 0;
    int as = 0;

    // Create array.
    allocate((void*) &a, (void*) &as, (void*) STRING_ABSTRACTION, (void*) STRING_ABSTRACTION_COUNT);

    printf("TEST 0: %s", a);

    // Serialise multi-dimensional tui into array.
    serialise((void*) &a, (void*) &ac, (void*) &as, t, (void*) tc, (void*) TERMINAL_ABSTRACTION, (void*) TERMINAL_ABSTRACTION_COUNT);

    printf("TEST 4: %s", a);

    // CAUTION! The textual user interface (tui) needs to be deallocated at
    // system shutdown.
    //?? For temporary testing, it is destroyed here. DELETE this line later,
    //?? when tui is stored in internal memory for faster access,
    //?? so that it does not have to be created every time again.
    deallocate((void*) &t, (void*) &ts, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

    printf("TEST 5: %s", a);

    // Write serialised array as message to terminal.
    write_data(p0, p1, p2, a, (void*) &ac, (void*) TERMINAL_CHANNEL, (void*) TERMINAL_CHANNEL_COUNT);

    printf("TEST 6: %s", a);

    // Destroy array.
    deallocate((void*) &a, (void*) &as, (void*) STRING_ABSTRACTION, (void*) STRING_ABSTRACTION_COUNT);
}

/* SEND_LINUX_CONSOLE_SOURCE */
#endif
