/*
 * $RCSfile: integer.c,v $
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
 * This file handles an integer.
 *
 * @version $Revision: 1.7 $ $Date: 2004-06-11 18:50:17 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef INTEGER_SOURCE
#define INTEGER_SOURCE

#include "../constants/constants.c"
#include "../logger/logger.c"

//
// Integer.
//

/**
 * Initializes the integer.
 *
 * @param p0 the transient model
 * @param p1 the transient model count
 * @param p2 the transient model size
 * @param p3 the persistent model
 * @param p4 the persistent model count
 */
void initialize_integer(void* p0, void* p1, void* p2, const void* p3, const void* p4) {

//??    log_message((void*) &INFO_LOG_LEVEL, (void*) &"Initialize integer.");

    // Transform string to integer.
//??    sscanf(p1, %d, (void*) &(m->value));
}

/**
 * Finalizes the integer.
 *
 * @param p0 the transient model
 * @param p1 the transient model count
 * @param p2 the transient model size
 * @param p3 the persistent model
 * @param p4 the persistent model count
 */
void finalize_integer(void* p0, void* p1, void* p2, const void* p3, const void* p4) {

//??    log_message((void*) &INFO_LOG_LEVEL, (void*) &"Finalize integer.");

    // Transform integer to string.
//??    sprintf(p1, %d, (void*) &(m->value));
}

/* INTEGER_SOURCE */
#endif
