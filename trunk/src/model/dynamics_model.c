/*
 * $RCSfile: dynamics_model.c,v $
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

#ifndef DYNAMICS_MODEL_SOURCE
#define DYNAMICS_MODEL_SOURCE

/**
 * This is the dynamics model.
 *
 * It represents an abstract description of some real world process.
 *
 * A model can be created by instantiating (cloning) an existing model.
 * Instantiating means allocating some place in the computer's memory.
 * Basically, every model can become a template itself,
 * if copies (other instances) of this model are created.
 *
 * @version $Revision: 1.1 $ $Date: 2003-12-01 12:33:58 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
struct dynamics_model {

    /** The parts. */
    void* parts;

    /** The abstractions. */
    void* abstractions;

    /** The positions. */
    void* positions;
};

/* DYNAMICS_MODEL_SOURCE */
#endif

