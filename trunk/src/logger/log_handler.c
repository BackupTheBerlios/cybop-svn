/*
 * $RCSfile: log_handler.c,v $
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
 * @version $Revision: 1.11 $ $Date: 2004-04-21 11:02:33 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef LOG_HANDLER_SOURCE
#define LOG_HANDLER_SOURCE

#include <stdio.h>
#include <string.h>
#include "../constants.c"

//
// Log level constants.
//

/** The off log level. */
static const int OFF_LOG_LEVEL = 0;

/** The error log level. */
static const int ERROR_LOG_LEVEL = 1;

/** The warning log level. */
static const int WARNING_LOG_LEVEL = 2;

/** The info log level. */
static const int INFO_LOG_LEVEL = 3;

//
// Log level name constants.
//

/** The error log level name. */
static const char* ERROR_LOG_LEVEL_NAME = "Error";

/** The warning log level name. */
static const char* WARNING_LOG_LEVEL_NAME = "Warning";

/** The info log level name. */
static const char* INFO_LOG_LEVEL_NAME = "Info";

//
// Attributes.
//

/** The log level. */
static int* log_level;

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

    if (p1 != NULL_POINTER) {

        char** n = (char**) p1;

        if (p0 != NULL_POINTER) {

            int* l = (int*) p0;

            if (*l == INFO_LOG_LEVEL) {

                strcat(*n, INFO_LOG_LEVEL_NAME);

            } else if (*l == WARNING_LOG_LEVEL) {

                strcat(*n, WARNING_LOG_LEVEL_NAME);

            } else if (*l == ERROR_LOG_LEVEL) {

                strcat(*n, ERROR_LOG_LEVEL_NAME);
            }

        } else {

            show_message((void*) "Error: Could not get log level name. The level is null.\n");
        }

    } else {

        show_message((void*) "Error: Could not get log level name. The level name is null.\n");
    }
}

/**
 * Shows the message on screen.
 *
 * @param p0 the message
 */
void show_message(const void* p0) {

    if (p0 != NULL_POINTER) {

        char* m = (char*) p0;

//??        fputs(m, stdout);
        fputs(m, stderr);

    } else {

        fputs("Error: Could not show message. The message is null.\n", stderr);
    }
}

/**
 * Logs the log entry.
 *
 * @param p0 the level
 * @param p1 the message
 */
void log_message(const void* p0, const void* p1) {

    if (p0 != NULL_POINTER) {

        int* l = (int*) p0;

        if (*l <= *log_level) {

            char* n = "";

            get_log_level_name(p0, (void*) &n);
            strcat(n, ": ");
            strcat(n, (char*) p1);
            strcat(n, "\n");

            show_message((void*) n);
        }

    } else {

        show_message((void*) "Error: Could not log message. The level is null.\n");
    }
}

/* LOG_HANDLER_SOURCE */
#endif
