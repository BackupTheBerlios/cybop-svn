/*
 * $RCSfile: item.c,v $
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

/**
 * This is an item.
 *
 * It represents an abstract description of some real world thing.
 *
 * An item can be created by instantiating (cloning) an existing category.
 * Instantiating means allocating some place in the computer's memory.
 * Basically, every item can become a category if copies of this item are created.
 *
 * @version $Revision: 1.2 $ $Date: 2003-09-22 06:50:53 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
struct item {

    /** The items. */
    int items;

    /** The positions. */
    int positions;

    /** The instances. */
    int instances;

    /** The interactions. */
    int interactions;
}

