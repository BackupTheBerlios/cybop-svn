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
 * @version $Revision: 1.2 $ $Date: 2003-07-31 00:52:20 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
class CategoryItemHandler {

    //
    // Category item.
    //

    /**
     * Initializes the category item.
     *
     * @param p0 the category item
     */
    static void initialize_category_item(java.lang.Object p0) {

        CategoryItem i = (CategoryItem) p0;

        if (i != null) {

            java.lang.System.out.println("INFO: Initialize category item.");

            i.item_category = new Map();
            MapHandler.initialize_map(i.item_category);
            i.item_abstraction = new Map();
            MapHandler.initialize_map(i.item_abstraction);
            i.position_category = new Map();
            MapHandler.initialize_map(i.position_category);
            i.position_abstraction = new Map();
            MapHandler.initialize_map(i.position_abstraction);
            i.instance_category = new Map();
            MapHandler.initialize_map(i.instance_category);
            i.instance_abstraction = new Map();
            MapHandler.initialize_map(i.instance_abstraction);
            i.interaction_category = new Map();
            MapHandler.initialize_map(i.interaction_category);
            i.interaction_abstraction = new Map();
            MapHandler.initialize_map(i.interaction_abstraction);

        } else {

            java.lang.System.out.println("ERROR: Could not initialize category item. The category item is null.");
        }
    }

    /**
     * Finalizes the category item.
     *
     * @param p0 the category item
     */
    static void finalize_category_item(java.lang.Object p0) {

        CategoryItem i = (CategoryItem) p0;
        
        if (i != null) {

            java.lang.System.out.println("INFO: Finalize category item.");

            MapHandler.finalize_map(i.interaction_abstraction);
            i.interaction_abstraction = null;

            MapHandler.finalize_map(i.interaction_category);
            i.interaction_category = null;

            MapHandler.finalize_map(i.instance_abstraction);
            i.instance_abstraction = null;

            MapHandler.finalize_map(i.instance_category);
            i.instance_category = null;

            MapHandler.finalize_map(i.position_abstraction);
            i.position_abstraction = null;

            MapHandler.finalize_map(i.position_category);
            i.position_category = null;

            MapHandler.finalize_map(i.item_abstraction);
            i.item_abstraction = null;

            MapHandler.finalize_map(i.item_category);
            i.item_category = null;

        } else {

            java.lang.System.out.println("ERROR: Could not finalize category item. The category item is null.");
        }
    }
}

