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

#include "logger/log_handler.c"

/**
 * This is the string helper.
 *
 * @version $Revision: 1.1 $ $Date: 2004-02-29 16:26:28 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

//
// Constants.
//

/** The empty string. */
static const char* EMPTY_STRING = "";

/** The slash separator. */
static const char* SLASH_SEPARATOR = "/";

/** The dot separator. */
static const char* DOT_SEPARATOR = ".";

/** The comma separator. */
static const char* COMMA_SEPARATOR = ",";

//
// Helper functions.
//

/**
 * Returns the first sub string in the given string.
 *
 * It is the most left sub string before the first separation.
 * If there is no separation, then it is the given string itself.
 *
 * @param p0 the string
 * @param p1 the separation
 * @return the sub string
 */
void* get_sub_string(void* p0, void* p1) {

    void* ss = (void*) 0;
    char* s = (char*) p0;

    if (s != (void*) 0) {

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

    return ss;
}

/**
 * Returns the remaining string after the first separation.
 *
 * @param p0 the string
 * @param p1 the separation
 * @return the remaining string
 */
void* get_remaining_string(void* p0, void* p1) {

    void* rs = (void*) 0;
    char* s = (char*) p0;

    if (s != (void*) 0) {

/*??
        int i = s->indexOf(p1);

        if (i != -1) {

            rs = s->substring(i + 1);
        }
*/

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, "Could not get remaining string. The string is null.");
    }

    return rs;
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
