/*
 * $RCSfile: Item.java,v $
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

package cyboi;

/**
 * This is an item.<br><br>
 *
 * An item can be created by instantiating (cloning) an existing category.
 * Instantiating means allocating some place in the computer's memory.
 * Basically, every item can become a category if copies of this item are created.
 * The meta-level classes that form a category follow this order:<br><br>
 *
 * Item is the super class of all other classes in the framework.
 *
 * @version $Revision: 1.1 $ $Date: 2003-07-15 09:44:20 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class Item {

    /** The children. */
    static final Map children;

    /** The categories. */
    static final Map categories;

    /** The abstractions. */
    static final Map abstractions;

    /** The positions. */
    static final Map positions;
}

