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
 * This is an item.
 *
 * It represents an abstract description of some real world item.
 *
 * An item can be created by instantiating (cloning) an existing category.
 * Instantiating means allocating some place in the computer's memory.
 * Basically, every item can become a category if copies of this item are created.
 *
 * @version $Revision: 1.7 $ $Date: 2003-07-27 22:50:34 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
class Item {

    /** The java object. */
    static java.lang.Object java_object;

    /** The java tree node. */
    static java.lang.Object java_tree_node;

    /** The items. */
    static java.lang.Object items;

    /** The positions. */
    static java.lang.Object positions;

    /** The instances. */
    static java.lang.Object instances;

    /** The interactions. */
    static java.lang.Object interactions;
}

