/*
 * $RCSfile: logger.c,v $
 *
 * Copyright (c) 1999-2005. Christian Heller. All rights reserved.
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
 * CAUTION! This logger must NOT use the CYBOI array procedures!
 * Otherwise, an ENDLESS LOOP will be created, because cyboi's
 * array procedures call the logger in turn.
 *
 * @version $Revision: 1.17 $ $Date: 2005-01-17 23:46:30 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 * @author Rolf Holzmueller <rolf.holzmueller@gmx.de>
 */

#ifndef LOGGER_SOURCE
#define LOGGER_SOURCE

#include "../global/character_constants.c"
#include "../global/log_constants.c"
#include "../global/variables.c"

/**
 * Adds the log details.
 *
 * @param p0 the log entry
 * @param p1 the log entry index
 * @param p2 the log details
 * @param p3 the log details count
 */
void add_log_details(void* p0, const void* p1, const void* p2, const void* p3) {

    // CAUTION! DO NOT use array functionality here!
    // The arrays use the logger which would cause circular references.
    // Instead, use malloc and similar functions directly!

    if (p3 != NULL_POINTER) {

        int* dc = (int*) p3;

        if (p2 != NULL_POINTER) {

            if (p1 != NULL_POINTER) {

                int* ei = (int*) p1;

                if (p0 != NULL_POINTER) {

                    // The loop index.
                    int j = 0;
                    // The destination character.
                    char* dest = CHARACTER_NULL_POINTER;
                    // The source character.
                    char* src = CHARACTER_NULL_POINTER;

                    while (1) {

                        if (j >= *dc) {

                            break;
                        }

                        // Determine log entry pointer as destination.
                        dest = (char*) (p0 + *ei + j);
                        // Determine log details pointer as source.
                        src = (char*) (p2 + j);

                        // Copy log details elements to log entry.
                        *dest = *src;

                        j++;
                    }

                } else {

                    // CAUTION! DO NOT use logging functionality here!
                    // The logger cannot log itself.
                    fputs("Error: Could not add log details. The log entry index is null.\n", LOG_OUTPUT);
                }

            } else {

                // CAUTION! DO NOT use logging functionality here!
                // The logger cannot log itself.
                fputs("Error: Could not add log details. The log entry index is null.\n", LOG_OUTPUT);
            }

        } else {

            // CAUTION! DO NOT use logging functionality here!
            // The logger cannot log itself.
            fputs("Error: Could not add log details. The log entry index is null.\n", LOG_OUTPUT);
        }

    } else {

        // CAUTION! DO NOT use logging functionality here!
        // The logger cannot log itself.
        fputs("Error: Could not add log details. The log details count is null.\n", LOG_OUTPUT);
    }
}

/**
 * Adds the log level name.
 *
 * @param p0 the log level
 * @param p1 the log entry
 * @param p2 the log entry count
 * @param p3 the log entry index
 */
void add_log_level_name(const void* p0, void* p1, const void* p2, void* p3) {

    // CAUTION! DO NOT use array functionality here!
    // The arrays use the logger which would cause circular references.
    // Instead, use malloc and similar functions directly!

    if (p3 != NULL_POINTER) {

        int* ei = (int*) p3;

        if (p2 != NULL_POINTER) {

            int* ec = (int*) p2;

            if (p0 != NULL_POINTER) {

                int* l = (int*) p0;

                if (*l == *DEBUG_LOG_LEVEL) {

                    if ((*ei + *DEBUG_LOG_LEVEL_NAME_COUNT) < *ec) {

                        add_log_details(p1, p3, (void*) DEBUG_LOG_LEVEL_NAME, (void*) DEBUG_LOG_LEVEL_NAME_COUNT);
                        *ei = *ei + *DEBUG_LOG_LEVEL_NAME_COUNT;

                    } else {

                        // CAUTION! DO NOT use logging functionality here!
                        // The logger cannot log itself.
                        fputs("Warning: Could not add log level name. The log entry count is exceeded.\n", LOG_OUTPUT);
                    }

                } else if (*l == *INFO_LOG_LEVEL) {

                    if ((*ei + *INFO_LOG_LEVEL_NAME_COUNT) < *ec) {

                        add_log_details(p1, p3, (void*) INFO_LOG_LEVEL_NAME, (void*) INFO_LOG_LEVEL_NAME_COUNT);
                        *ei = *ei + *INFO_LOG_LEVEL_NAME_COUNT;

                    } else {

                        // CAUTION! DO NOT use logging functionality here!
                        // The logger cannot log itself.
                        fputs("Warning: Could not add log level name. The log entry count is exceeded.\n", LOG_OUTPUT);
                    }

                } else if (*l == *WARNING_LOG_LEVEL) {

                    if ((*ei + *WARNING_LOG_LEVEL_NAME_COUNT) < *ec) {

                        add_log_details(p1, p3, (void*) WARNING_LOG_LEVEL_NAME, (void*) WARNING_LOG_LEVEL_NAME_COUNT);
                        *ei = *ei + *WARNING_LOG_LEVEL_NAME_COUNT;

                    } else {

                        // CAUTION! DO NOT use logging functionality here!
                        // The logger cannot log itself.
                        fputs("Warning: Could not add log level name. The log entry count is exceeded.\n", LOG_OUTPUT);
                    }

                } else if (*l == *ERROR_LOG_LEVEL) {

                    if ((*ei + *ERROR_LOG_LEVEL_NAME_COUNT) < *ec) {

                        add_log_details(p1, p3, (void*) ERROR_LOG_LEVEL_NAME, (void*) ERROR_LOG_LEVEL_NAME_COUNT);
                        *ei = *ei + *ERROR_LOG_LEVEL_NAME_COUNT;

                    } else {

                        // CAUTION! DO NOT use logging functionality here!
                        // The logger cannot log itself.
                        fputs("Warning: Could not add log level name. The log entry count is exceeded.\n", LOG_OUTPUT);
                    }
                }

            } else {

                // CAUTION! DO NOT use logging functionality here!
                // The logger cannot log itself.
                fputs("Error: Could not add log level name. The log level is null.\n", LOG_OUTPUT);
            }

        } else {

            // CAUTION! DO NOT use logging functionality here!
            // The logger cannot log itself.
            fputs("Error: Could not add log level name. The log entry count is null.\n", LOG_OUTPUT);
        }

    } else {

        // CAUTION! DO NOT use logging functionality here!
        // The logger cannot log itself.
        fputs("Error: Could not add log level name. The log entry index is null.\n", LOG_OUTPUT);
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

    // CAUTION! DO NOT use array functionality here!
    // The arrays use the logger which would cause circular references.
    // Instead, use malloc and similar functions directly!

    if (p2 != NULL_POINTER) {

        int* mc = (int*) p2;

        if (p0 != NULL_POINTER) {

            int* l = (int*) p0;

            // Only log message if log level matches.
            if (*l <= *LOG_LEVEL) {

                // The log entry.
                void* e = NULL_POINTER;
                // The log entry count.
                const int* ec = MAXIMUM_LOG_MESSAGE_COUNT;
                // The log entry index for adding characters.
                int ei = 0;

                // Create log entry.
                e = (void*) malloc(*ec);

                // Add name of the given log level to log entry.
                add_log_level_name(p0, e, (void*) ec, (void*) &ei);

                // Add colon to log entry.
                if ((ei + 1) < *ec) {

                    add_log_details((void*) e, (void*) &ei, (void*) COLON_CHARACTER, (void*) COLON_CHARACTER_COUNT);
                    ei = ei + 1;

                } else {

                    // CAUTION! DO NOT use logging functionality here!
                    // The logger cannot log itself.
                    fputs("Warning: Could not add colon to log entry. The log entry count is exceeded.\n", LOG_OUTPUT);
                }

                // Add space to log entry.
                if ((ei + 1) < *ec) {

                    add_log_details((void*) e, (void*) &ei, (void*) SPACE_CHARACTER, (void*) SPACE_CHARACTER_COUNT);
                    ei = ei + 1;

                } else {

                    // CAUTION! DO NOT use logging functionality here!
                    // The logger cannot log itself.
                    fputs("Warning: Could not add space to log entry. The log entry count is exceeded.\n", LOG_OUTPUT);
                }

                // Add message to log entry.
                if ((ei + *mc) < *ec) {

                    add_log_details((void*) e, (void*) &ei, p1, p2);
                    ei = ei + *mc;

                } else {

                    // CAUTION! DO NOT use logging functionality here!
                    // The logger cannot log itself.
                    fputs("Warning: Could not add message to log entry. The log entry count is exceeded.\n", LOG_OUTPUT);
                }

                // Add new line to log entry.
                if ((ei + 1) < *ec) {

                    add_log_details((void*) e, (void*) &ei, (void*) LINE_FEED_CONTROL_CHARACTER, (void*) LINE_FEED_CONTROL_CHARACTER_COUNT);
                    ei = ei + 1;

                } else {

                    // CAUTION! DO NOT use logging functionality here!
                    // The logger cannot log itself.
                    fputs("Warning: Could not add new line to log entry. The log entry count is exceeded.\n", LOG_OUTPUT);
                }

                // Add string termination to log entry.
                if ((ei + 1) < *ec) {

                    add_log_details((void*) e, (void*) &ei, (void*) NULL_CONTROL_CHARACTER, (void*) NULL_CONTROL_CHARACTER_COUNT);
                    ei = ei + 1;

                } else {

                    // CAUTION! DO NOT use logging functionality here!
                    // The logger cannot log itself.
                    fputs("Warning: Could not add string termination to log entry. The log entry count is exceeded.\n", LOG_OUTPUT);
                }

                // Log entry to output.
                fputs((char*) e, LOG_OUTPUT);

                // Destroy log entry.
                free(e);
            }

        } else {

            // CAUTION! DO NOT use logging functionality here!
            // The logger cannot log itself.
            fputs("Error: Could not log message. The message count is null.\n", LOG_OUTPUT);
        }

    } else {

        // CAUTION! DO NOT use logging functionality here!
        // The logger cannot log itself.
        fputs("Error: Could not log message. The log level is null.\n", LOG_OUTPUT);
    }
}

/**
 * Logs the message for debugging.
 *
 * @param m the log message as null terminated string
 */
void log_message_debug(const char* m) {

    // CAUTION! DO NOT use array functionality here!
    // The arrays use the logger which would cause circular references.
    // Instead, use malloc and similar functions directly!

    // The message count.
    int* c = (int*) malloc(*INTEGER_PRIMITIVE_SIZE);
    *c = strlen(m);

    log_message((void*) DEBUG_LOG_LEVEL, (void*) m, (void*) c);

    free(c);
}

/* LOGGER_SOURCE */
#endif
