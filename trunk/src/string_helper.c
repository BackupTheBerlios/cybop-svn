/*
 * $RCSfile: string_helper.c,v $
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
 */

#ifndef STRING_HELPER_SOURCE
#define STRING_HELPER_SOURCE

#include <stdlib.h>
#include <string.h>
#include "logger/log_handler.c"

/**
 * This is the string helper.
 *
 * @version $Revision: 1.4 $ $Date: 2004-03-02 07:34:59 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

//
// Constants.
//

/** The comma ',' character with ascii code 44. */
static const char COMMA_CHARACTER = ',';

/** The dot '.' character with ascii code 46. */
static const char DOT_CHARACTER = '.';

/** The slash '/' character with ascii code 47. */
static const char SLASH_CHARACTER = '/';

/** The string termination character '\0' with ascii code ??. */
static const char TERMINATION_CHARACTER = '\0';

/** The empty string. */
static const char* EMPTY_STRING = "";

//
// Helper functions.
//

/**
 * Returns the index of the character within the string.
 *
 * @param p0 the string
 * @param p1 the character
 * @param p2 the length
 * @param p3 the index
 */
void get_character_index(const void* p0, const void* p1, const void* p2, void* p3) {

    if (p0 != (void*) 0) {

        char* s = (char*) p0;

        if (p1 != (void*) 0) {

            char* c = (char*) p1;

            if (p3 != (void*) 0) {

                int* i = (int*) p3;

                if (p2 != (void*) 0) {

                    int* l = (int*) p2;

                    while (1) {

                        if (*i >= *l) {

                            break;
                        }

                        // Since the string pointer is constant, it cannot be incremented
                        // itself. The index i is incremented instead, until the searched
                        // character is found.
                        if (*(s + *i) == *c) {

                            break;
                        }

                        (*i)++;
                    }

                } else {

                    while (1) {

                        // Since the string pointer is constant, it cannot be incremented
                        // itself. The index i is incremented instead, until the searched
                        // character is found.
                        if (*(s + *i) == *c) {

                            break;
                        }

                        (*i)++;
                    }
                }

            } else {

                log_message((void*) &ERROR_LOG_LEVEL, "Could not get character index. The index is null.");
            }

        } else {

            log_message((void*) &ERROR_LOG_LEVEL, "Could not get character index. The character is null.");
        }

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, "Could not get character index. The string is null.");
    }
}

/**
 * Returns the string length.
 *
 * It counts the number of characters within the string,
 * until the string termination character '\0' is reached.
 *
 * @param p0 the string
 * @param p1 the length
 */
void get_string_length(const void* p0, void* p1) {

    get_character_index(p0, TERMINATION_CHARACTER, (void*) 0, p1);
}

/**
 * Copies the string characters between start and end index into sub string.
 *
 * @param p0 the string
 * @param p1 the start index
 * @param p2 the end index
 * @param p3 the sub string
 */
void copy_sub_string(const void* p0, const void* p1, const void* p2, void* p3) {

    char* s = (char*) p0;

    if (s != (void*) 0) {

        int* start = (int*) p1;

        if (start != (void*) 0) {

            int* end = (int*) p2;

            if (end != (void*) 0) {

                char* ss = (char*) p3;

                if (ss != (void*) 0) {

                    int i = 0;
                    int max = *end - *start;

                    while (1) {

                        if (i == max) {

                            break;
                        }

                        ss = realloc(ss, length * 2 + 1);

                        *(ss + i) = *(s + *start + i);

                        i++;
                    }

                    // Add string termination character to sub string.
                    *(ss + i) = '\0';

                } else {

                    log_message((void*) &ERROR_LOG_LEVEL, "Could not get sub string. The sub string is null.");
                }

            } else {

                log_message((void*) &ERROR_LOG_LEVEL, "Could not get sub string. The end index is null.");
            }

        } else {

            log_message((void*) &ERROR_LOG_LEVEL, "Could not get sub string. The start index is null.");
        }

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, "Could not get sub string. The string is null.");
    }
}

/* STRING_HELPER_SOURCE */
#endif
