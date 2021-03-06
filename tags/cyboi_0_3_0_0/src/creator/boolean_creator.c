/*
 * $RCSfile: boolean_creator.c,v $
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
 * @version $Revision: 1.1 $ $Date: 2004-08-21 10:09:38 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef BOOLEAN_CREATOR_SOURCE
#define BOOLEAN_CREATOR_SOURCE

#include "../global/log_constants.c"
#include "../logger/logger.c"

/**
 * Creates the boolean.
 *
 * @param p0 the model
 * @param p1 the model size
 */
void create_boolean(void* p0, const void* p1) {

    if (p0 != NULL_POINTER) {

        int* m = (int*) p0;

//??        log_message((void*) &INFO_LOG_LEVEL, (void*) &CREATE_INTEGER_MESSAGE, (void*) &CREATE_INTEGER_MESSAGE_COUNT);

        *m = 0;

    } else {

//??        log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_CREATE_INTEGER_THE_MODEL_IS_NULL_MESSAGE, (void*) &COULD_NOT_CREATE_INTEGER_THE_MODEL_IS_NULL_MESSAGE_COUNT);
    }
}

/**
 * Destroys the boolean.
 *
 * @param p0 the model
 * @param p1 the model size
 */
void destroy_boolean(void* p0, const void* p1) {

    if (p0 != NULL_POINTER) {

        int* m = (int*) p0;

//??        log_message((void*) &INFO_LOG_LEVEL, (void*) &DESTROY_INTEGER_MESSAGE, (void*) &DESTROY_INTEGER_MESSAGE_COUNT);

    } else {

//??        log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_DESTROY_INTEGER_THE_MODEL_IS_NULL_MESSAGE, (void*) &COULD_NOT_DESTROY_INTEGER_THE_MODEL_IS_NULL_MESSAGE_COUNT);
    }
}

/* BOOLEAN_CREATOR_SOURCE */
#endif
