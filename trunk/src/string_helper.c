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

#include <string.h>
#include "logger/log_handler.c"

/**
 * This is the string helper.
 *
 * @version $Revision: 1.3 $ $Date: 2004-03-01 17:08:58 $ $Author: christian $
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
 * Returns the string length.
 *
 * It counts the number of characters within the string,
 * until the string termination character "\0" is reached.
 *
 * @param p0 the string
 * @param p1 the length
 */
void get_string_length(const void* p0, void* p1) {

    if (p0 != (void*) 0) {

        // Pointer to the first character of the string.
        char* c = (char*) p0;

        if (p1 != (void*) 0) {

            // Pointer to the length integer.
            int* i = (int*) p1;

            if (*i == 0) {

                // Since the string pointer is constant, it cannot be incremented
                // itself. The i variable is incremented instead, until the string
                // termination character is reached.
                while (*(c + *i) != TERMINATION_CHARACTER) {

                    (*i)++;
                }

            } else {

                log_message((void*) &WARNING_LOG_LEVEL, "The initial string length should be zero.");
            }

        } else {

            log_message((void*) &ERROR_LOG_LEVEL, "Could not get string length. The length is null.");
        }

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, "Could not get string length. The string is null.");
    }
}

/**
 * Returns the first sub string in the given string.
 *
 * It is the most left sub string before the first separation.
 * If there is no separation, then it is the given string itself.
 *
 * @param p0 the string
 * @param p1 the separation
 * @param p2 the sub string
 */
void get_sub_string(void* p0, void* p1) {

    void* ss = (void*) 0;
    char* s = (char*) p0;
    char* sep = (void*) 0;

/*??
    int l = 0;
    get_string_length(p0, (void*) &l);
    int i = 0;

    while (i < l) {

    }
*/

    if (s != (void*) 0) {

        sep = strchr(s, *p1);
        diff = sep - s;

/*??
        int i = s->indexOf(p1);

        if (i != -1) {

            ss = s->substring(0, i);

        } else {

            ss = s;
        }
*/

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, "Could not get sub string. The string is null.");
    }
}

/**
 * Returns the remaining string after the first separation.
 *
 * @param p0 the string
 * @param p1 the separation
 * @param p2 the remaining string
 */
void get_remaining_string(void* p0, void* p1) {

    void* rs = (void*) 0;
    char* s = (char*) p0;
    char* sep = (void*) 0;

    if (s != (void*) 0) {

/*??
        sep = strchr(s, *p1);
        rs = sep + 1;
*/

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, "Could not get remaining string. The string is null.");
    }
}

/**
 * Returns the string element index.
 *
 * @param p0 the string
 * @param p1 the element
 * @param p2 the index
 */
/*??
void get_string_element_index(void* p0, void* p1, void* p2) {

    char* s = (char*) p0;
    int l = strlen(s);
    int i = 0;

    while (i < l) {

        if (strcmp() == 0) {

        }
    }
}

/**
 * Returns the string suffix.
 *
 * @param p0 the string
 * @param p1 the start index
 * @param p2 the remaining suffix
 */
/*??
void get_string_suffix(void* p0, void* p1, void* p2) {

}

/**
 * Returns the string value.
 *
 * @param p0 the string
 * @param p1 the numerical value
 */
/*??
void get_string_value(void* p0, void* p1) {

}

/**
 * Returns the value as string.
 *
 * @param p0 the numerical value
 * @param p1 the string
 */
/*??
void get_value_string(void* p0, void* p1) {

}

/* STRING_HELPER_SOURCE */
#endif
