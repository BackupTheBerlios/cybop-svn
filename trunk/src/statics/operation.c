/*
 * $RCSfile: operation.c,v $
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

#ifndef OPERATION_SOURCE
#define OPERATION_SOURCE

/**
 * This is an operation (also known as system).
 *
 * It transports an input state through logics to an output state.
 *
 * The logics is kept as function pointer.
 * Many inputs and outputs are possible.
 * Statics models are kept as hierarchical paths.
 *
 * Operations can be stored as signals in a signal memory.
 *
 * @version $Revision: 1.1 $ $Date: 2003-12-16 11:07:24 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
struct operation {

    /** The inputs and outputs. */
    void* inputs_outputs;
};

/* OPERATION_SOURCE */
#endif

