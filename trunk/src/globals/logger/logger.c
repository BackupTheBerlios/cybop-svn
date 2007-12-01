/*
 * $RCSfile: logger.c,v $
 *
 * Copyright (c) 1999-2007. Christian Heller and the CYBOP developers.
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
 * This file handles log messages.
 * It writes log entries to an output, such as the screen.
 *
 * CAUTION! This logger must NOT use the CYBOI array procedures!
 * Otherwise, an ENDLESS LOOP will be created, because cyboi's
 * array procedures call the logger in turn.
 *
 * @version $Revision: 1.23 $ $Date: 2007-12-01 23:57:42 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef LOGGER_SOURCE
#define LOGGER_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "../../globals/constants/character/character_constants.c"
#include "../../globals/constants/integer/integer_constants.c"
#include "../../globals/constants/log/log_level_constants.c"
#include "../../globals/constants/log/log_level_name_constants.c"
#include "../../globals/constants/log/log_message_constants.c"
#include "../../globals/constants/memory_structure/memory_structure_constants.c"
#include "../../globals/constants/pointer/pointer_constants.c"
#include "../../globals/variables/log_variables.c"

/**
 * Gets the log level name.
 *
 * @param p0 the log level name
 * @param p1 the log level name count
 * @param p2 the log level
 */
void log_get_level_name(void* p0, void* p1, void* p2) {

    if (p2 != *NULL_POINTER) {

        int* l = (int*) p2;

        if (p1 != *NULL_POINTER) {

            int* lnc = (int*) p1;

            if (p0 != *NULL_POINTER) {

                void** ln = (void**) p0;

                if (*l == *DEBUG_LOG_LEVEL) {

                    *ln = DEBUG_LOG_LEVEL_NAME;
                    *lnc = *DEBUG_LOG_LEVEL_NAME_COUNT;

                } else if (*l == *INFORMATION_LOG_LEVEL) {

                    *ln = INFORMATION_LOG_LEVEL_NAME;
                    *lnc = *INFORMATION_LOG_LEVEL_NAME_COUNT;

                } else if (*l == *WARNING_LOG_LEVEL) {

                    *ln = WARNING_LOG_LEVEL_NAME;
                    *lnc = *WARNING_LOG_LEVEL_NAME_COUNT;

                } else if (*l == *ERROR_LOG_LEVEL) {

                    *ln = ERROR_LOG_LEVEL_NAME;
                    *lnc = *ERROR_LOG_LEVEL_NAME_COUNT;
                }

            } else {

                // CAUTION! DO NOT use logging functionality here!
                // The logger cannot log itself.
                fputs("Error: Could not get log level name. The log level name is null.\n", stdout);
            }

        } else {

            // CAUTION! DO NOT use logging functionality here!
            // The logger cannot log itself.
            fputs("Error: Could not get log level name. The log level name count is null.\n", stdout);
        }

    } else {

        // CAUTION! DO NOT use logging functionality here!
        // The logger cannot log itself.
        fputs("Error: Could not get log level name. The log level is null.\n", stdout);
    }
}

/**
 * Logs the given message.
 *
 * CAUTION! This function cannot be called "log" as that name
 * is already used somewhere, probably by the glibc library.
 * If using it, the gcc compiler prints an error like the following:
 *
 * ../controller/../controller/manager/../../globals/logger/logger.c:122: error: conflicting types for 'log'
 *
 * @param p0 the log level
 * @param p1 the log message
 * @param p2 the log message count
 */
void log_message(void* p0, void* p1, void* p2) {

    if (p2 != *NULL_POINTER) {

        int* mc = (int*) p2;

        if (p0 != *NULL_POINTER) {

            int* l = (int*) p0;

            //
            // CAUTION! DO NOT use array functionality here!
            // The arrays use the logger which would cause circular references.
            //
            // CAUTION! Do NOT use malloc to allocate memory either!
            // The log functions are not only used by the main process,
            // but also in threads. Threads, however, are not allowed to
            // allocate any memory, as this would result in an error like:
            //
            // *** glibc detected *** malloc(): memory corruption (fast): 0x080e0470 ***
            // Aborted
            //
            // Therefore, the "write" function is called multiple times below,
            // to display the log level, separators, message and line feed.
            //

            // Only log message if log level matches.
            if (*l <= LOG_LEVEL) {

                // The log level name.
                void* ln = *NULL_POINTER;
                int lnc = *NUMBER_0_INTEGER;

                // Add name of the given log level to log entry.
                log_get_level_name((void*) &ln, (void*) &lnc, p0);

                if (LOG_OUTPUT >= *NUMBER_0_INTEGER) {

                    // Send log level, separators, message and line feed to output.
                    write(LOG_OUTPUT, ln, lnc);
                    write(LOG_OUTPUT, (void*) COLON_CHARACTER, *PRIMITIVE_COUNT);
                    write(LOG_OUTPUT, (void*) SPACE_CHARACTER, *PRIMITIVE_COUNT);
                    write(LOG_OUTPUT, p1, *mc);
                    write(LOG_OUTPUT, (void*) LINE_FEED_CONTROL_CHARACTER, *PRIMITIVE_COUNT);

                } else {

                    // The log output value is smaller than zero.
                    // Probably, it still has its default value of -1,
                    // as set in the file "globals/variables/log_variables.c".

                    // CAUTION! DO NOT use logging functionality here!
                    // The logger cannot log itself.
                    fputs("Error: Could not log message. The log output is undefined.\n", stdout);
                }

            } else {

                // CAUTION! Do NOT write an error message here!
                // It is a wanted effect not to write a log message, nor an error,
                // if the given log level is not within the log level tolerance
                // that was set as global variable at cyboi system startup.
            }

        } else {

            // CAUTION! DO NOT use logging functionality here!
            // The logger cannot log itself.
            fputs("Error: Could not log message. The message count is null.\n", stdout);
        }

    } else {

        // CAUTION! DO NOT use logging functionality here!
        // The logger cannot log itself.
        fputs("Error: Could not log message. The log level is null.\n", stdout);
    }
}

/**
 * Logs a null character-terminated message.
 *
 * @param p0 the log level
 * @param p1 the log message as null terminated string
 */
void log_terminated_message(void* p0, void* p1) {

    // The message count.
    int c = strlen(p1);

    log_message(p0, p1, (void*) &c);
}

/* LOGGER_SOURCE */
#endif
