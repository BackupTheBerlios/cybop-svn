/*
 * $RCSfile: CategoryItemHandler.java,v $
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
 * This is a category item handler.
 *
 * @version $Revision: 1.1 $ $Date: 2003-07-27 22:50:34 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
class CategoryItemHandler {

    //
    // Category item management.
    //

    /**
     * Creates a category item.
     *
     * @return the category item
     */
    static java.lang.Object create_category_item() {

        CategoryItem c = new CategoryItem();

        if (c != null) {

            java.lang.System.out.println("INFO: Create category item.");

            c.item_abstraction = MapHandler.create_map();
            c.item_category = MapHandler.create_map();
            c.position_abstraction = MapHandler.create_map();
            c.position_category = MapHandler.create_map();
            c.instance_abstraction = MapHandler.create_map();
            c.instance_category = MapHandler.create_map();
            c.force_abstraction = MapHandler.create_map();
            c.force_category = MapHandler.create_map();

        } else {

            java.lang.System.out.println("ERROR: Could not create item. The item is null.");
        }

        return c;
    }

    /**
     * Destroys the item.
     *
     * @param c the item
     */
    static void destroy_item(java.lang.Object c) {

        Item ic = (Item) c;
        
        if (ic != null) {

            java.lang.System.out.println("INFO: Destroy item.");

            java.lang.Object forces = ic.forces;
            ic.forces = null;
            MapHandler.destroy_map(forces);

            java.lang.Object force_abstractions = ic.force_abstractions;
            ic.force_abstractions = null;
            MapHandler.destroy_map(force_abstractions);

            java.lang.Object times = ic.times;
            ic.times = null;
            MapHandler.destroy_map(times);

            java.lang.Object time_abstractions = ic.time_abstractions;
            ic.time_abstractions = null;
            MapHandler.destroy_map(time_abstractions);

            java.lang.Object spaces = ic.spaces;
            ic.spaces = null;
            MapHandler.destroy_map(spaces);

            java.lang.Object space_abstractions = ic.space_abstractions;
            ic.space_abstractions = null;
            MapHandler.destroy_map(space_abstractions);

            java.lang.Object items = ic.items;
            ic.items = null;
            MapHandler.destroy_map(items);

            java.lang.Object item_abstractions = ic.item_abstractions;
            ic.item_abstractions = null;
            MapHandler.destroy_map(item_abstractions);

        } else {

            java.lang.System.out.println("ERROR: Could not destroy item. The item is null.");
        }
    }
}

