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
 * CAUTION! This logger must NOT use the CYBOI array procedures!
 * Otherwise, an ENDLESS LOOP will be created, because cyboi's
 * array procedures call the logger in turn.
 *
 * @version $Revision: 1.8 $ $Date: 2004-06-13 23:13:31 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef LOGGER_SOURCE
#define LOGGER_SOURCE

#include "../global/constant.c"
#include "../global/variable.c"

//
// Log entry.
//

/**
 * Adds the log details.
 *
 * @param p0 the log entry
 * @param p1 the log entry index
 * @param p2 the log details
 * @param p3 the log details count
 */
void add_log_details(void* p0, const void* p1, const void* p2, const void* p3) {

    if (p3 != NULL_POINTER) {

        int* dc = (int*) p3;

        if (p2 != NULL_POINTER) {

            void** d = (void**) p2;

            if (p1 != NULL_POINTER) {

                int* ei = (int*) p1;

                if (p0 != NULL_POINTER) {

                    void** e = (void**) p0;

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
                        dest = (char*) (*e + *ei + j);
                        // Determine log details pointer as source.
                        src = (char*) (*d + j);

                        // Copy log details elements to log entry.
                        *dest = *src;

                        j++;
                    }

                } else {

                    fputs("Error: Could not add log details. The log entry index is null.\n", LOG_OUTPUT);
                }

            } else {

                fputs("Error: Could not add log details. The log entry index is null.\n", LOG_OUTPUT);
            }

        } else {

            fputs("Error: Could not add log details. The log entry index is null.\n", LOG_OUTPUT);
        }

    } else {

        fputs("Error: Could not add log details. The log details count is null.\n", LOG_OUTPUT);
    }
}

/**
 * Adds the log detail.
 *
 * @param p0 the log entry
 * @param p1 the log entry index
 * @param p2 the log details
 */
void add_log_detail(void* p0, const void* p1, const void* p2) {

    // The detail count.
    int dc = 1;

    // The element p2 needs to be handed over as array to add_log_details.
    // Therefore, it has to be transformed into a pointer.
    // Example 1:
    // - array p0: char* handed over as char**
    // - element p2: single char handed over as char*
    // - the element of type char* gets transformed to type char** with &p2
    // Example 2:
    // - array p0: char** handed over as char***
    // - element p2: string char* handed over as char**
    // - the element of type char** gets transformed to type char*** with &p2
    add_log_details(p0, p1, (void*) &p2, (void*) &dc);
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

    //
    // CAUTION! CYBOI's array procedures are NOT used to avoid an endless loop!
    //

    if (p3 != NULL_POINTER) {

        int* ei = (int*) p3;

        if (p2 != NULL_POINTER) {

            int* ec = (int*) p2;

            if (p0 != NULL_POINTER) {

                int* l = (int*) p0;

                if (*l == INFO_LOG_LEVEL) {

                    if ((*ei + INFO_LOG_LEVEL_NAME_COUNT) < *ec) {

                        add_log_details(p1, p3, (void*) &INFO_LOG_LEVEL_NAME, (void*) &INFO_LOG_LEVEL_NAME_COUNT);
                        *ei = *ei + INFO_LOG_LEVEL_NAME_COUNT;

                    } else {

                        fputs("Warning: Could not add log level name. The log entry count is exceeded.\n", LOG_OUTPUT);
                    }

                } else if (*l == WARNING_LOG_LEVEL) {

                    if ((*ei + WARNING_LOG_LEVEL_NAME_COUNT) < *ec) {

                        add_log_details(p1, p3, (void*) &WARNING_LOG_LEVEL_NAME, (void*) &WARNING_LOG_LEVEL_NAME_COUNT);
                        *ei = *ei + WARNING_LOG_LEVEL_NAME_COUNT;

                    } else {

                        fputs("Warning: Could not add log level name. The log entry count is exceeded.\n", LOG_OUTPUT);
                    }

                } else if (*l == ERROR_LOG_LEVEL) {

                    if ((*ei + ERROR_LOG_LEVEL_NAME_COUNT) < *ec) {

                        add_log_details(p1, p3, (void*) &ERROR_LOG_LEVEL_NAME, (void*) &ERROR_LOG_LEVEL_NAME_COUNT);
                        *ei = *ei + ERROR_LOG_LEVEL_NAME_COUNT;

                    } else {

                        fputs("Warning: Could not add log level name. The log entry count is exceeded.\n", LOG_OUTPUT);
                    }
                }

            } else {

                fputs("Error: Could not add log level name. The log level is null.\n", LOG_OUTPUT);
            }

        } else {

            fputs("Error: Could not add log level name. The log entry count is null.\n", LOG_OUTPUT);
        }

    } else {

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

    //
    // CAUTION! CYBOI's array procedures are NOT used to avoid an endless loop!
    //

    if (p2 != NULL_POINTER) {

        int* mc = (int*) p2;

        if (p0 != NULL_POINTER) {

            int* l = (int*) p0;

            // Only log message if log level matches.
            if (*l <= LOG_LEVEL) {

                // The log entry.
                void* e = NULL_POINTER;
                // The log entry count.
                const int ec = MAXIMUM_LOG_MESSAGE_COUNT;
                // The log entry index for adding characters.
                int ei = 0;

                // Create log entry.
                e = (void*) malloc(ec);

                // Add name of the given log level to log entry.
                add_log_level_name(p0, (void*) &e, (void*) &ec, (void*) &ei);

                // Add colon to log entry.
                if ((ei + 1) < ec) {

                    add_log_detail((void*) &e, (void*) &ei, (void*) &COLON_CHARACTER);
                    ei = ei + 1;

                } else {

                    fputs("Warning: Could not add colon to log entry. The log entry count is exceeded.\n", LOG_OUTPUT);
                }

                // Add space to log entry.
                if ((ei + 1) < ec) {

                    add_log_detail((void*) &e, (void*) &ei, (void*) &SPACE_CHARACTER);
                    ei = ei + 1;

                } else {

                    fputs("Warning: Could not add space to log entry. The log entry count is exceeded.\n", LOG_OUTPUT);
                }

                // Add message to log entry.
                if ((ei + *mc) < ec) {

                    add_log_details((void*) &e, (void*) &ei, p1, p2);
                    ei = ei + *mc;

                } else {

                    fputs("Warning: Could not add message to log entry. The log entry count is exceeded.\n", LOG_OUTPUT);
                }

                // Add new line to log entry.
                if ((ei + 1) < ec) {

                    add_log_detail((void*) &e, (void*) &ei, (void*) &NEW_LINE_CHARACTER);
                    ei = ei + 1;

                } else {

                    fputs("Warning: Could not add new line to log entry. The log entry count is exceeded.\n", LOG_OUTPUT);
                }

                // Add string termination to log entry.
                if ((ei + 1) < ec) {

                    add_log_detail((void*) &e, (void*) &ei, (void*) &NULL_CHARACTER);
                    ei = ei + 1;

                } else {

                    fputs("Warning: Could not add string termination to log entry. The log entry count is exceeded.\n", LOG_OUTPUT);
                }

                // Log entry to output.
                fputs((char*) e, LOG_OUTPUT);

                // Destroy log entry.
                free(e);
            }

        } else {

            fputs("Error: Could not log message. The message count is null.\n", LOG_OUTPUT);
        }

    } else {

        fputs("Error: Could not log message. The log level is null.\n", LOG_OUTPUT);
    }
}

/* LOGGER_SOURCE */
#endif
