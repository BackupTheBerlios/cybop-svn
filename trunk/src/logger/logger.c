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
 * @version $Revision: 1.4 $ $Date: 2004-05-26 22:37:39 $ $Author: christian $
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
 * Adds the log level name.
 *
 * @param p0 the log level
 * @param p1 the log entry
 * @param p2 the log entry count
 */
void add_log_level_name(const void* p0, void* p1, void* p2) {

    if (p2 != NULL_POINTER) {

        int* ec = (int*) p2;

        if (p0 != NULL_POINTER) {

            int* l = (int*) p0;

            // The message index.
            int i = 0;

            if (*l == INFO_LOG_LEVEL) {

                *ec = INFO_LOG_LEVEL_NAME_COUNT;
                resize_array(p1, (void*) ec);
                set_array_elements(p1, (void*) &CHARACTER_ARRAY, (void*) &i, (void*) &INFO_LOG_LEVEL_NAME, (void*) ec);

            } else if (*l == WARNING_LOG_LEVEL) {

                *ec = WARNING_LOG_LEVEL_NAME_COUNT;
                resize_array(p1, (void*) ec);
                set_array_elements(p1, (void*) &CHARACTER_ARRAY, (void*) &i, (void*) &WARNING_LOG_LEVEL_NAME, (void*) ec);

            } else if (*l == ERROR_LOG_LEVEL) {

                *ec = ERROR_LOG_LEVEL_NAME_COUNT;
                resize_array(p1, (void*) ec);
                set_array_elements(p1, (void*) &CHARACTER_ARRAY, (void*) &i, (void*) &ERROR_LOG_LEVEL_NAME, (void*) ec);
            }

        } else {

            fputs("Error: Could not add log level name. The log level is null.\n", stderr);
        }

    } else {

        fputs("Error: Could not add log level name. The log entry count is null.\n", stderr);
    }
}

/**
 * Logs the message.
 *
 * @param p0 the log level
 * @param p1 the log message
 * @param p2 the log message count
 */
void log_message(const void* p0, const void* p1, const void* p2) {

    if (p2 != NULL_POINTER) {

        int* mc = (int*) p2;

        if (p0 != NULL_POINTER) {

            int* l = (int*) p0;

            // Only log message if log level matches.
            if (*l <= log_level) {

                // The log entry.
                void* e = NULL_POINTER;
                // The log entry count.
                int ec = 0;
                // The index for adding characters.
                int i = 0;

                // Create log entry.
                create_array((void*) &e, (void*) &ec);

                // Add name of the given log level to entry.
                add_log_level_name(p0, (void*) &e, (void*) &ec);

                // Add colon to message.
                i = ec;
                ec++;
                resize_array((void*) &e, (void*) &ec);
                set_array_element((void*) &e, (void*) &CHARACTER_ARRAY, (void*) &i, (void*) &COLON_CHARACTER);

                // Add space to message.
                i = ec;
                ec++;
                resize_array((void*) &e, (void*) &ec);
                set_array_element((void*) &e, (void*) &CHARACTER_ARRAY, (void*) &i, (void*) &SPACE_CHARACTER);

                // Add message to message.
                i = ec;
                ec = ec + *mc;
                resize_array((void*) &e, (void*) &ec);
                set_array_elements((void*) &e, (void*) &CHARACTER_ARRAY, (void*) &i, p1, p2);

                // Add new line to message.
                i = ec;
                ec++;
                resize_array((void*) &e, (void*) &ec);
                set_array_element((void*) &e, (void*) &CHARACTER_ARRAY, (void*) &i, (void*) &NEW_LINE_CHARACTER);

                // Add string termination to message.
                i = ec;
                ec++;
                resize_array((void*) &e, (void*) &ec);
                set_array_element((void*) &e, (void*) &CHARACTER_ARRAY, (void*) &i, (void*) &STRING_TERMINATION_CHARACTER);

                // Log entry to output.
                fputs((char*) e, stdout);

                // Destroy log entry.
                destroy_array((void*) &e, (void*) &ec);
            }

        } else {

            show_message((void*) &"Error: Could not log message. The message count is null.\n");
        }

    } else {

        show_message((void*) &"Error: Could not log message. The log level is null.\n");
    }
}

/* LOGGER_SOURCE */
#endif
