/*
 * $RCSfile: CategoryJavaObjectHandler.java,v $
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
 * This is a category java object handler.
 *
 * @version $Revision: 1.1 $ $Date: 2003-07-31 11:09:45 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
class CategoryJavaObjectHandler {

    //
    // Category java object.
    //

    /**
     * Initializes the category java object.
     *
     * @param p0 the category java object
     */
    static void initialize_category_java_object(java.lang.Object p0) {

        CategoryJavaObject o = (CategoryJavaObject) p0;

        if (o != null) {

            java.lang.System.out.println("INFO: Initialize category java object.");

            o.attributes = new Map();
            MapHandler.initialize_map(o.attributes);

        } else {

            java.lang.System.out.println("ERROR: Could not initialize category java object. The category java object is null.");
        }
    }

    /**
     * Finalizes the category java object.
     *
     * @param p0 the category java object
     */
    static void finalize_category_java_object(java.lang.Object p0) {

        CategoryJavaObject o = (CategoryJavaObject) p0;
        
        if (o != null) {

            java.lang.System.out.println("INFO: Finalize category java object.");

            MapHandler.finalize_map(o.attributes);
            o.attributes = null;

        } else {

            java.lang.System.out.println("ERROR: Could not finalize category java object. The category java object is null.");
        }
    }
}

