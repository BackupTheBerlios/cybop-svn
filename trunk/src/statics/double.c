/*
 * $RCSfile: double.c,v $
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
 * This file handles a double.
 *
 * A double is a floating point number.
 *
 * @version $Revision: 1.1 $ $Date: 2004-05-06 18:00:49 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef DOUBLE_HANDLER_SOURCE
#define DOUBLE_HANDLER_SOURCE

#include "../constants.c"
#include "../logger/log_handler.c"

//
// Double.
//

/**
 * Initializes the double.
 *
 * @param p0 the transient model
 * @param p1 the persistent model
 * @param p2 the persistent model size
 */
void initialize_double(void* p0, const void* p1, const void* p2) {

    log_message((void*) &INFO_LOG_LEVEL, (void*) &"Initialize double.");

    // Transform string to double.
//??    sscanf(p1, %d, (void*) &(m->value));
}

/**
 * Finalizes the double.
 *
 * @param p0 the transient model
 * @param p1 the persistent model
 * @param p2 the persistent model size
 */
void finalize_double(const void* p0, void* p1, void* p2) {

    log_message((void*) &INFO_LOG_LEVEL, (void*) &"Finalize double.");

    // Transform double to string.
//??    sprintf(p1, %d, (void*) &(m->value));
}

/* DOUBLE_HANDLER_SOURCE */
#endif
