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

#include <stdio.h>

/**
 * This is a log handler.
 *
 * It writes log entries to an output, such as the screen.
 *
 * @version $Revision: 1.1 $ $Date: 2003-09-17 18:45:34 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

//
// Constants.
//

/** The off log level. */
int OFF_LOG_LEVEL = 0;

/** The error log level. */
int ERROR_LOG_LEVEL = 1;

/** The warning log level. */
int WARNING_LOG_LEVEL = 2;

/** The info log level. */
int INFO_LOG_LEVEL = 3;

//
// Attributes.
//

/** The log level. */    
int log_level;

//
// Log entry.
//

/**
 * Logs the log entry.
 *
 * @param p0 the level
 * @param p1 the message
 */
void log(int p0, java.lang.Object p1) {

    if (p0 <= LogHandler.log_level) {

        java.lang.Object l = LogHandler.get_log_level_name(p0);
        
        printf(l + ": " + p1);
    }
}

/**
 * Returns the log level name.
 *
 * @param p0 the level
 * @return the log level name
 */
java.lang.Object get_log_level_name(int p0) {

    java.lang.Object l = null;
    
    if (p0 == LogHandler.INFO_LOG_LEVEL) {

        l = "INFO";
        
    } else if (p0 == LogHandler.WARNING_LOG_LEVEL) {

        l = "WARNING";
        
    } else if (p0 == LogHandler.ERROR_LOG_LEVEL) {

        l = "ERROR";
    }

    return l;
}

