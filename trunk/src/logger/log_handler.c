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

/**
 * This is a log handler.
 *
 * It writes log entries to an output, such as the screen.
 *
 * @version $Revision: 1.4 $ $Date: 2003-12-12 16:39:43 $ $Author: christian $
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

/** The error log level name. */
static const char* ERROR_LOG_LEVEL_NAME = "ERROR";

/** The warning log level name. */
static const char* WARNING_LOG_LEVEL_NAME = "WARNING";

/** The info log level name. */
static const char* INFO_LOG_LEVEL_NAME = "INFO";

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
 * @return the log level name
 */
void* get_log_level_name(void* p0) {

    void* n = (void*) 0;
    int* l = (int*) p0;
    
    if (*l == INFO_LOG_LEVEL) {

        n = (void*) INFO_LOG_LEVEL_NAME;
        
    } else if (*l == WARNING_LOG_LEVEL) {

        n = (void*) WARNING_LOG_LEVEL_NAME;
    
    } else if (*l == ERROR_LOG_LEVEL) {

        n = (void*) ERROR_LOG_LEVEL_NAME;
    }
    
    return n;
}

/**
 * Shows the message on screen.
 *
 * @param p0 the message
 */
void show_message(void* p0) {

//??    fputs((char*) p0, stdout);
    fputs((char*) p0, stderr);
}

/**
 * Logs the log entry.
 *
 * @param p0 the level
 * @param p1 the message
 */
void log_message(void* p0, void* p1) {
    
    int* l = (int*) p0;

    if (*l <= *log_level) {

        void* n = get_log_level_name(p0);

        show_message(n);
        show_message((void*) ": ");
        show_message(p1);
        show_message((void*) "\n");
    }
}

/* LOG_HANDLER_SOURCE */
#endif

