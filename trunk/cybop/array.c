/*
 * $RCSfile: array.c,v $
 *
 * Copyright (c) 1999-2003. Christian Heller. All rights reserved.
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

#ifndef ARRAY_SOURCE
#define ARRAY_SOURCE

/**
 * This is an array.
 *
 * An array represents an allocated area in the computer's memory,
 * that can contain a number of abstract elements.
 * An abstraction simplifies and represents a real world item.
 * In the case of computer science, everything gets abstracted to 0 and 1.
 * But that also means that every abstraction has a bytecode representation.
 *
 * @version $Revision: 1.2 $ $Date: 2003-10-12 14:25:27 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
struct array {

    /** The internal array of pointers (memory addresses). */
    void** internal_array;

    /**
     * The array size.
     * The sizeof operation can only be used for real arrays, expressed with [].
     * Since CYBOI allocates arrays dynamically and stores them as *,
     * the array size needs to be stored extra here because sizeof will not work.
     * See: http://pegasus.rutgers.edu/~elflord/cpp/gotchas/index.shtml
     */
    int size;
};

/* ARRAY_SOURCE */
#endif

