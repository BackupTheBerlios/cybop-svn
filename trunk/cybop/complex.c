/*
 * $RCSfile: complex.c,v $
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

#ifndef COMPLEX_SOURCE
#define COMPLEX_SOURCE

/**
 * This is a complex.
 *
 * It represents an abstract description of some real world thing.
 *
 * A complex can be created by instantiating (cloning) an existing model.
 * Instantiating means allocating some place in the computer's memory.
 * Basically, every complex can become a model (template) itself,
 * if copies (other instances) of this complex are created.
 *
 * @version $Revision: 1.10 $ $Date: 2003-10-13 13:55:20 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
struct complex {

    /** The children. */
    void* children;

    /** The positions. */
    void* positions;
};

/* COMPLEX_SOURCE */
#endif

