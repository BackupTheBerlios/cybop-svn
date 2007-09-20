/*
 * $RCSfile: pointer_constants.c,v $
 *
 * Copyright (c) 1999-2007. Christian Heller and the CYBOP developers.
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
 * @version $Revision: 1.3 $ $Date: 2007-09-20 08:00:19 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef POINTER_CONSTANTS_SOURCE
#define POINTER_CONSTANTS_SOURCE

/**
 * The null pointer.
 *
 * CAUTION! Do NOT try to use *NUMBER_0_INTEGER here instead of the value 0!
 * Otherwise, the system would show the following error, as it expects a constant value:
 * "error: initializer element is not constant"
 */
static void* NULL_POINTER_ARRAY[] = {(void*) 0};
static void** NULL_POINTER = NULL_POINTER_ARRAY;

/* POINTER_CONSTANTS_SOURCE */
#endif
