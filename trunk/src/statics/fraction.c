/*
 * $RCSfile: fraction.c,v $
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

#ifndef FRACTION_SOURCE
#define FRACTION_SOURCE

#include "../statics/integer.c"

/**
 * This is a fraction.
 *
 * It consists of two integer numbers, a numerator and a denominator.
 *
 * @version $Revision: 1.2 $ $Date: 2004-01-05 16:38:23 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
struct fraction {

    //?? Temporarily, a double (float) is used here to let the
    //?? Algorithmic Logic Unit (ALU) calculate everything.
    
    /** The value. */
    double value;
    
    /** The numerator. */
//??    struct integer numerator;
    
    /** The denominator. */
//??    struct integer denominator;
};

/* FRACTION_SOURCE */
#endif

