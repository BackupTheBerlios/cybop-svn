/*
 * $RCSfile: logger.c,v $
 *
 * Copyright (c) 1999-2004. Christian Heller. All rights reserved.
 *
 * This software is published under the GPL GNU General Public License.
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
 * This file handles log messages.
 * It writes log entries to an output, such as the screen.
 *
 * @version $Revision: 1.3 $ $Date: 2004-05-26 14:13:50 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef LOGGER_SOURCE
#define LOGGER_SOURCE

#include <stdio.h>
#include <string.h>
#include "../constants/constants.c"

//
// Attributes.
//

/** The log level. */
static int log_level;

//
// Forward declarations.
//

/**
 * Creates the array.
 *
 * @param p0 the array
 * @param p1 the size
 */
void create_array(void* p0, const void* p1, const void* p2);

/**
 * Destroys the array.
 *
 * @param p0 the array
 * @param p1 the size
 */
void destroy_array(void* p0, const void* p1, const void* p2);

/**
 * Resizes the array with the given size.
 *
 * @param p0 the array
 * @param p1 the size
 */
void resize_array(void* p0, const void* p1, const void* p2);

/**
 * Sets the array elements.
 *
 * @param p0 the destination array
 * @param p1 the type
 * @param p2 the index
 * @param p3 the source array
 * @param p4 the count
 */
void set_array_elements(void* p0, const void* p1, const void* p2, const void* p3, const void* p4);

/**
 * Sets the array element.
 *
 * @param p0 the array
 * @param p1 the type
 * @param p2 the index
 * @param p3 the element
 */
void set_array_element(void* p0, const void* p1, const void* p2, const void* p3);

//
// Log entry.
//

/**
 * Returns the log level name.
 *
 * @param p0 the level
 * @param p1 the level name
 */
void get_log_level_name(const void* p0, void* p1) {

    fputs("TEST x0\n", stdout);

    if (p1 != NULL_POINTER) {

        char** n = (char**) p1;

        if (p0 != NULL_POINTER) {

            int* l = (int*) p0;

            fputs("TEST x1\n", stderr);

            if (INFO_LOG_LEVEL) {

                fputs("TEST x2\n", stdout);

                strcat(*n, INFO_LOG_LEVEL_NAME);

                fputs("TEST x3\n", stdout);

            } else if (*l == WARNING_LOG_LEVEL) {

                strcat(*n, WARNING_LOG_LEVEL_NAME);

            } else if (*l == ERROR_LOG_LEVEL) {

                strcat(*n, ERROR_LOG_LEVEL_NAME);
            }

        } else {

            fputs("Error: Could not get log level name. The level is null.\n", stderr);
        }

    } else {

        fputs("Error: Could not get log level name. The level name is null.\n", stderr);
    }
}

/**
 * Shows the message on screen.
 *
 * @param p0 the message
 * @param p1 the message size
 */
void show_message(void* p0, void* p1) {

    if (p1 != NULL_POINTER) {

        int* s = (int*) p1;

        // The log message.
        char* m = CHARACTER_NULL_POINTER;
        // The log size, including two places for new line and
        // string termination.
        int ls = *s + 2;

        create_array((void*) &m, (void*) &CHARACTER_ARRAY, (void*) &ls);

        // The destination index to which to copy the source array.
        int i = 0;
        char n = '\n';
        int ni = *s;
        char t = '\0';
        int ti = *s + 1;

        set_array_elements((void*) &m, (void*) &CHARACTER_ARRAY, (void*) &i, p0, p1);
        set_array_element((void*) &m, (void*) &CHARACTER_ARRAY, (void*) &ni, (void*) &n);
        set_array_element((void*) &m, (void*) &CHARACTER_ARRAY, (void*) &ti, (void*) &t);

        fputs(m, stdout);

        destroy_array((void*) &m, (void*) &CHARACTER_ARRAY, (void*) &ls);

    } else {

        fputs("Error: Could not show message. The message size is null.\n", stdout);
    }
}

/**
 * Logs the log entry.
 *
 * @param p0 the level
 * @param p1 the message
 * @param p2 the message count
 */
void log_message(const void* p0, const void* p1, const void* p2) {

    if (p1 != NULL_POINTER) {

        char** m = (char**) p1;

        if (p0 != NULL_POINTER) {

            int* l = (int*) p0;

            // Only log message if log level matches.
            if (*l <= log_level) {

//??                char n[] = {'\0'};
                void* n = NULL_POINTER;
                int ns = 0;
                create_array((void*) &n, (void*) &ns);

                * @param p0 the destination array
                * @param p1 the type
                * @param p2 the index
                * @param p3 the source array
                * @param p4 the count
                */
                set_array_elements((void*) &n, (void*) &CHARACTER_ARRAY, (void*) &ns, (void*) &log_level_name, (void*) &count);

                int test_index = 0;
                int test_size = 4;
                set_character_array_string((void*) &n, (void*) &test_index, p1, (void*) &test_size);

                int termination_index = 4;
                char termination = '\0';
                set_character_array_element((void*) &n, (void*) &termination_index, (void*) &termination);

//??                get_log_level_name(p0, (void*) &n);
//??                strcat(n, ": ");
//??                strcat(n, *m);
//??                strcat(n, "\n");

                show_message((void*) &n);

                destroy_array((void*) &n, (void*) &ns);
            }

        } else {

            show_message((void*) &"Error: Could not log message. The message is null.\n");
        }

    } else {

        show_message((void*) &"Error: Could not log message. The level is null.\n");
    }
}

/* LOGGER_SOURCE */
#endif
