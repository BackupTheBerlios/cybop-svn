/*
 * $RCSfile: tui_communicator.c,v $
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
 * @version $Revision: 1.1 $ $Date: 2005-06-05 00:08:32 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef TUI_COMMUNICATOR_SOURCE
#define TUI_COMMUNICATOR_SOURCE

#include <stdio.h>
#include <unistd.h>
#include "../array/array.c"
#include "../global/character_constants.c"
#include "../global/structure_constants.c"
#include "../global/variables.c"

/**
 * Receives a tui source and writes it into a destination byte array.
 *
 * @param p0 the destination (byte array) (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source
 * @param p4 the source count
 */
void receive_tui(void* p0, void* p1, void* p2, const void* p3, const void* p4) {

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
void send_tui(void* p0, void* p1, void* p2, const void* p3, const void* p4) {

    if (p4 != NULL_POINTER) {

        int* sc = (int*) p4;

        if (p3 != NULL_POINTER) {

            void* s = (void*) p3;

            if (p0 != NULL_POINTER) {

                void** d = (void**) p0;

//??                if (strcmp("linux", getenv("TERM")) == 0) {

                    fputs("TEST: This is a linux console.\n", (FILE*) d);

                    //?? TEST: for "Hello, World!"
                    fprintf(stdout, "\n\n%s\n\n\n", (char*) p3);

/*??
                    // Determine device name of controlling terminal.
                    int n = ttyname();
                    fprintf((FILE*) *d, "TEST: The terminal device name is: %i\n", n);

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

/*??
                } else {

                    fputs("TEST: This is a normal serial terminal.\n", (FILE*) *d);
                }
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

/*??
    char r = NULL_CONTROL_CHARACTER;
    int j = 0;
    char c = NULL_CONTROL_CHARACTER;

    while (1) {

        if (j >= *as) {

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

/*?? ==================================== OLD

//
// Character screen.
//

struct textual_screen {

    void* button;
};

struct button {

    void* size;
    void* label;
};

/*??
void create_test(void* p0) {

    struct textual_screen* s = (struct textual_screen*) p0;
    s->button = (void*) malloc(sizeof(struct button));

    struct button* b = (struct button*) s->button;
    b->size = (void*) malloc(sizeof(struct vector));

    struct vector* v = (struct vector*) b->size;
    v->x = 10;
    v->y = 3;
    v->z = 1;

    b->label = (void*) "Exit";
}
*/

/*??
void destroy_test(void* p0) {

    struct textual_screen* s = (struct textual_screen*) p0;
    struct button* b = (struct button*) s->button;
    struct vector* v = (struct vector*) b->size;

    free(v);
    free(b);
}
*/

/*??
void write_button_label(void* p0, void* p1) {

    char* c = (char*) p0;
    FILE* f = (FILE*) p1;

    fputs(c, f);
    fputc(10, stdout);
    fputc(10, stdout);
    fflush(stdout);
}

/*??
void paint_button(void* p0, void* p1) {

    struct vector* s = (struct vector*) p0;
    FILE* f = (FILE*) p1;
    int w = s->x;
    int h = s->y;
    int d = s->z;
    int x_pos = 8;
    int y_pos = 10;
    int z_pos = 0;
    int x = x_pos;
    int y = y_pos;
    int z = z_pos;

    while (z < (z_pos + d)) {

        while (y < (y_pos + h)) {

            while (x < (x_pos + w)) {

                fputc(95, f);

                x++;
            }

            y++;
        }

        z++;
    }

    fputc(10, stdout);
    fputc(10, stdout);
    fflush(stdout);
}
*/

/*??
void send_button(void* p0) {

    struct button* b = (struct button*) p0;
    paint_button(b->size, stdout);
    write_button_label(b->label, stdout);
}
*/

/**
 * Send character screen signal to communication partner (probably the human user).
 *
 * @param p0 the textual screen
 */
/*??
void send_textual_screen(void* p0) {

    struct textual_screen* s = (struct textual_screen*) p0;
    send_button(s->button);
}
*/

/**
 * Tests the textual screen.
 *
 * ?? Probably temporary; CYBOI should read hierarchy from CYBOL files later.
 */
/*??
void test_textual_screen() {

    void* s = (void*) malloc(sizeof(struct textual_screen));
    create_test(s);

    send_textual_screen(s);

    destroy_test(s);
    free(s);
}
*/

/* TUI_COMMUNICATOR_SOURCE */
#endif
