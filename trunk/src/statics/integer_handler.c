/*
 * $RCSfile: integer_handler.c,v $
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
 * This file handles integers.
 *
 * @version $Revision: 1.9 $ $Date: 2004-04-01 15:15:30 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef INTEGER_HANDLER_SOURCE
#define INTEGER_HANDLER_SOURCE

#include "../logger/log_handler.c"

//
// Constants.
//

/** The default integer value. */
static const int DEFAULT_INTEGER_VALUE = 0;

//
// Integer model.
//

/**
 * Initializes the integer model.
 *
 * @param p0 the transient model
 * @param p1 the persistent model
 * @param p2 the persistent model size
 */
void initialize_integer_model(void* p0, const void* p1, const void* p2) {

    log_message((void*) &INFO_LOG_LEVEL, "Initialize integer model.");

    // Transform string to integer.
//??    sscanf(p1, %d, (void*) &(m->value));
}

/**
 * Finalizes the integer model.
 *
 * @param p0 the transient model
 * @param p1 the persistent model
 * @param p2 the persistent model size
 */
void finalize_integer_model(const void* p0, void* p1, void* p2) {

    log_message((void*) &INFO_LOG_LEVEL, "Finalize integer model.");

    // Transform integer to string.
//??    sprintf(p1, %d, (void*) &(m->value));
}

/* INTEGER_HANDLER_SOURCE */
#endif
