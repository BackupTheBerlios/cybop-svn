/*
 * $RCSfile: MenuItem.java,v $
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

package cybop.core.screen.component;

import cybop.core.category.*;
import cybop.core.model.*;
import cybop.core.model.Boolean;
import cybop.core.model.Integer;
import cybop.core.model.String;

/**
 * This class represents a menu item.
 *
 * @version $Revision: 1.4 $ $Date: 2003-06-20 13:44:24 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class MenuItem extends Button {

    //
    // Encapsulated java swing menu item.
    //

    /**
     * Creates an encapsulated java swing menu item.
     *
     * @return the encapsulated java swing menu item
     * @exception Exception if the encapsulated java swing menu item is null
     */
    public java.lang.Object createJavaObject() throws Exception {

        javax.swing.JMenuItem mi = new javax.swing.JMenuItem();

        if (mi != null) {

            mi.setEnabled(Boolean.TRUE);

        } else {

            throw new Exception("Could not create encapsulated java swing menu item. The encapsulated java swing menu item is null.");
        }

        return mi;
    }

    /**
     * Destroys the encapsulated java swing menu item.
     *
     * @param o the encapsulated java swing menu item
     * @exception Exception if the encapsulated java swing menu item is null
     */
    public void destroyJavaObject(java.lang.Object o) throws Exception {

        javax.swing.JMenuItem mi = (javax.swing.JMenuItem) o;

        if (mi != null) {

            mi.setEnabled(Boolean.FALSE);

        } else {

            throw new Exception("Could not destroy encapsulated java swing menu item. The encapsulated java swing menu item is null.");
        }
    }

    //
    // Default categories.
    //

    /**
     * Returns the default label category.
     *
     * @return the default label category
     */
    public Item getDefaultLabelCategory() {

        return new String("Menu Item");
    }
}

