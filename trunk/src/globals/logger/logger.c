/*
 * $RCSfile: logger.c,v $
 *
 * Copyright (c) 1999-2008. Christian Heller and the CYBOP developers.
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
 * @version $Revision: 1.27 $ $Date: 2008-05-20 22:13:43 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef LOGGER_SOURCE
#define LOGGER_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <wchar.h>
#include "../../globals/constants/character/wide_character_constants.c"
#include "../../globals/constants/integer/integer_constants.c"
#include "../../globals/constants/log/log_level_constants.c"
#include "../../globals/constants/log/log_level_name_constants.c"
#include "../../globals/constants/log/log_message_constants.c"
#include "../../globals/constants/memory_structure/array_constants.c"
#include "../../globals/constants/memory_structure/memory_structure_constants.c"
#include "../../globals/constants/pointer/pointer_constants.c"
#include "../../globals/variables/log_variables.c"

//
// CAUTION! Following some reflexions on logging. There are two possibilities:
//
// 1 New Console
//
// A new console has to be opened whenever a textual user interface is used.
// This way, the original console where the cyboi process was started may use
// standard ASCII characters, as can the log messages, logger and test output.
//
// 2 Logger Adaptation
//
// If using just one textual console (the one where the cyboi process was started),
// then only wide character functions may be used on it, without exception.
// The MIXING of normal characters and wide characters is NOT PERMITTED on
// one-and-the-same stream, as it would lead to unpredictable, untraceable errors,
// as the glibc documentation says.
// But this also means that all log messages have to be converted to wide characters.
//
// Since the glibc "write" function used by the old version of the logger could not
// handle wide characters, the functions "fputws" or "fwprintf" had to be used instead.
// But they in turn require a termination wide character to be added.
// Adding such a termination requires the creation of a new wide character array
// to built together the whole log message, including log level, actual message
// and finally termination wide character.
//
// But: the logger must not allocate any memory area, since it is used by thread functions as well.
// Therefore, a log message array with fixed size, pre-allocated at system startup,
// needs to be forwarded (as global variable) and used by the logger.
// Whenever a log message is copied to this array and written to console,
// a MUTEX has to be set BEFORE, so that log output between the main program flow
// and threads do not conflict.
//

//
// Forward declarations.
//

/**
 * Sets the array elements.
 *
 * @param p0 the array
 * @param p1 the index
 * @param p2 the elements (Hand over as array!)
 * @param p3 the count
 * @param p4 the type
 */
void set_array_elements(void* p0, void* p1, void* p2, void* p3, void* p4);

/**
 * Writes a terminated log message to the given output stream.
 *
 * CAUTION! The "write" function is not used here, because it expects
 * a multibyte character sequence.
 * The log message, however, is handed over with a null termination wide character,
 * so that it may be passed on to either of the "fputws" or "fwprintf" function.
 * Since it seems simpler and presumably is faster, the decision here fell on the "fputws" function.
 *
 * @param p0 the log output stream
 * @param p1 the log message
 */
void log_write_terminated_message(void* p0, void* p1) {

    if (p1 != *NULL_POINTER) {

        wchar_t* m = (wchar_t*) p1;

        if (p0 != *NULL_POINTER) {

            FILE* s = (FILE*) p0;

            fputws(m, s);

        } else {

            // CAUTION! DO NOT use logging functionality here!
            // The logger cannot log itself.
            fputws(L"Error: Could not write terminated log message. The log output stream is null.\n", stdout);
        }

    } else {

        // CAUTION! DO NOT use logging functionality here!
        // The logger cannot log itself.
        fputws(L"Error: Could not write terminated log message. The log message is null.\n", stdout);
    }
}

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
                log_write_terminated_message((void*) stdout, L"Error: Could not get log level name. The log level name is null.\n");
            }

        } else {

            // CAUTION! DO NOT use logging functionality here!
            // The logger cannot log itself.
            log_write_terminated_message((void*) stdout, L"Error: Could not get log level name. The log level name count is null.\n");
        }

    } else {

        // CAUTION! DO NOT use logging functionality here!
        // The logger cannot log itself.
        log_write_terminated_message((void*) stdout, L"Error: Could not get log level name. The log level is null.\n");
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

            // Only log message if log level matches.
            if (*l <= *LOG_LEVEL) {

                // The log level name.
                void* ln = *NULL_POINTER;
                int lnc = *NUMBER_0_INTEGER;

                // Add name of the given log level to log entry.
                log_get_level_name((void*) &ln, (void*) &lnc, p0);

                if (LOG_OUTPUT != *NULL_POINTER) {

                    //
                    // CAUTION! Do NOT allocate/ reallocate/ deallocate an array here, because:
                    //
                    // 1 Thread Safety
                    //
                    // The log functions are not only used by the main process,
                    // but also in threads. Threads, however, are not allowed to
                    // allocate any memory, as this would result in an error like:
                    //
                    // *** glibc detected *** malloc(): memory corruption (fast): 0x080e0470 ***
                    // Aborted
                    //
                    // 2 Circular References
                    //
                    // The arrays use this logger which could cause circular references.
                    //
                    // Therefore, the global variable "LOG_MESSAGE" is used below.
                    // It gets allocated at cyboi system startup.
                    //

                    // The index.
                    int i = *NUMBER_0_INTEGER;
                    // The maximum message count.
                    int mmc = lnc + *PRIMITIVE_COUNT + *PRIMITIVE_COUNT + *mc + *PRIMITIVE_COUNT + *PRIMITIVE_COUNT;

                    if (mmc <= *LOG_MESSAGE_COUNT) {

                        // RESET maximum message count to count of log message that was handed over as parameter.
                        mmc = *mc;

                    } else {

                        // Limit the maximum log message count to the global log message array's count.
                        //
                        // CAUTION! DO NOT FORGET TO SUBTRACT the number of extra characters to be added,
                        // to have place to copy them to the log message array further below!
                        // But do NOT subtract "*mc", as it was the reason for a too big message
                        // and would result in a negative value!
                        mmc = *LOG_MESSAGE_COUNT - (lnc + *PRIMITIVE_COUNT + *PRIMITIVE_COUNT + *PRIMITIVE_COUNT + *PRIMITIVE_COUNT);
                    }

                    // CAUTION! Further checks are not built in here!
                    //
                    // This logger source code assumes that the global variable LOG_MESSAGE_COUNT has
                    // at least a size of about 15, calculated as follows:
                    // lnc + *PRIMITIVE_COUNT + *PRIMITIVE_COUNT + *PRIMITIVE_COUNT + *PRIMITIVE_COUNT
                    // The variable "lnc" may hereby be a value from 5 to 11.
                    // See module "log_level_name_constants.c"!

                    // Copy log level.
                    set_array_elements((void*) LOG_MESSAGE, (void*) &i, ln, (void*) &lnc, (void*) WIDE_CHARACTER_ARRAY);
                    // Increment index.
                    i = i + lnc;
                    // Copy colon.
                    set_array_elements((void*) LOG_MESSAGE, (void*) &i, (void*) COLON_WIDE_CHARACTER, (void*) PRIMITIVE_COUNT, (void*) WIDE_CHARACTER_ARRAY);
                    // Increment index.
                    i = i + *PRIMITIVE_COUNT;
                    // Copy space.
                    set_array_elements((void*) LOG_MESSAGE, (void*) &i, (void*) SPACE_WIDE_CHARACTER, (void*) PRIMITIVE_COUNT, (void*) WIDE_CHARACTER_ARRAY);
                    // Increment index.
                    i = i + *PRIMITIVE_COUNT;
                    // Copy log message.
                    set_array_elements((void*) LOG_MESSAGE, (void*) &i, p1, (void*) &mmc, (void*) WIDE_CHARACTER_ARRAY);
                    // Increment index.
                    i = i + mmc;
                    // Copy line feed control wide character.
                    set_array_elements((void*) LOG_MESSAGE, (void*) &i, (void*) LINE_FEED_CONTROL_WIDE_CHARACTER, (void*) PRIMITIVE_COUNT, (void*) WIDE_CHARACTER_ARRAY);
                    // Increment index.
                    i = i + *PRIMITIVE_COUNT;
                    // Copy null termination wide character.
                    set_array_elements((void*) LOG_MESSAGE, (void*) &i, (void*) NULL_CONTROL_WIDE_CHARACTER, (void*) PRIMITIVE_COUNT, (void*) WIDE_CHARACTER_ARRAY);

                    // Log message.
                    log_write_terminated_message((void*) stdout, (void*) LOG_MESSAGE);

                } else {

                    // The log output value of type FILE is null.
                    // Probably, it was not opened correctly in module "optionaliser.c".

                    // CAUTION! DO NOT use logging functionality here!
                    // The logger cannot log itself.
                    log_write_terminated_message((void*) stdout, L"Error: Could not log message. The log output is undefined.\n");
                }

            } else {

                // CAUTION! Do NOT write an error message here!
                // It is a wanted effect NOT to write a log message, NOR an error,
                // if the given log level is not within the log level tolerance
                // that was set as global variable at cyboi system startup.
            }

        } else {

            // CAUTION! DO NOT use logging functionality here!
            // The logger cannot log itself.
            log_write_terminated_message((void*) stdout, L"Error: Could not log message. The message count is null.\n");
        }

    } else {

        // CAUTION! DO NOT use logging functionality here!
        // The logger cannot log itself.
        log_write_terminated_message((void*) stdout, L"Error: Could not log message. The log level is null.\n");
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
    int c = wcslen((wchar_t*) p1);

    log_message(p0, p1, (void*) &c);
}

/* LOGGER_SOURCE */
#endif
