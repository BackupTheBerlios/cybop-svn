/*
 * $RCSfile: log_handler.c,v $
 *
 * Copyright (c) 1999-2003. Christian Heller. All rights reserved.
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
 */

#ifndef LOG_HANDLER_SOURCE
#define LOG_HANDLER_SOURCE

#include <stdio.h>
#include <string.h>

/**
 * This is a log handler.
 *
 * It writes log entries to an output, such as the screen.
 *
 * @version $Revision: 1.1 $ $Date: 2003-12-01 12:33:58 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

//
// Constants.
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
// Attributes.
//

/** The log level. */    
static void* log_level;

//
// Log entry.
//

/**
 * Returns the log level name.
 *
 * @param p0 the log level name
 * @param p1 the level
 */
static void get_log_level_name(void* p0, void* p1) {

    char* n = (char*) p0;
    int* l = (int*) p1;
    
    if (*l == INFO_LOG_LEVEL) {

        strcat(n, "INFO");
        
    } else if (*l == WARNING_LOG_LEVEL) {

        strcat(n, "WARNING");
    
    } else if (*l == ERROR_LOG_LEVEL) {

        strcat(n, "ERROR");
    }
}

/**
 * Shows the message on screen.
 *
 * @param p0 the message
 */
static void show_message(void* p0) {

    puts((char*) p0);
}

/**
 * Logs the log entry.
 *
 * @param p0 the level
 * @param p1 the message
 */
static void log(void* p0, void* p1) {
    
    int* l = (int*) p0;
    int* ll = (int*) log_level;

    if (*l <= *ll) {

        void* n = malloc(0);

        get_log_level_name(n, p0);
        strcat((char*) n, ": ");
        strcat((char*) n, p1);
        show_message(n);
        
        free(n);
    }
}

/* LOG_HANDLER_SOURCE */
#endif

