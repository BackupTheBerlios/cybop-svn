/*
 * $RCSfile: HelpMenu.java,v $
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

package cybop.core.screen.region.menu;

import cybop.core.category.*;
import cybop.core.model.*;
import cybop.core.model.String;
import cybop.core.screen.component.*;
import cybop.core.screen.component.menuitem.*;
import cybop.core.screen.region.*;

/**
 * This class represents a help menu.
 *
 * @version $Revision: 1.6 $ $Date: 2003-06-20 13:44:24 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class HelpMenu extends Menu {

    //
    // Children names.
    //

    /** The about menu item. */
    public static final String ABOUT_MENU_ITEM = new String("about_menu_item");

    //
    // Child management.
    //

    /**
     * Adds the item to become a child of this item.
     *
     * @param n the name
     * @param i the item
     * @exception Exception if the name is null
     */
    public void setChild(String n, Item i) throws Exception {

        super.setChild(n, i);

        if (n != null) {

            if (n.isEqualTo(HelpMenu.ABOUT_MENU_ITEM)) {

                setAboutMenuItem((AboutMenuItem) i);
            }

        } else {

            throw new Exception("Could not set item. The name is null.");
        }
    }

    /**
     * Removes the child item from this item.
     *
     * @param n the name
     * @exception Exception if the name is null
     */
    public void removeChild(String n) throws Exception {

        if (n != null) {

            if (n.isEqualTo(HelpMenu.ABOUT_MENU_ITEM)) {

                removeAboutMenuItem((AboutMenuItem) getChild(n));
            }

        } else {

            throw new Exception("Could not remove item. The name is null.");
        }

        super.removeChild(n);
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

        return new String("Help");
    }

    /**
     * Returns the default about menu item category.
     *
     * @return the default about menu item category
     */
    public Item getDefaultAboutMenuItemCategory() {

        return new String("cybop.core.screen.component.menuitem.AboutMenuItem");
    }

    //
    // About menu item.
    //

    /**
     * Sets the about menu item.
     *
     * @param mi the about menu item
     * @exception Exception if the java menu is null
     * @exception Exception if the about menu item is null
     */
    public void setAboutMenuItem(AboutMenuItem mi) throws Exception {

        javax.swing.JMenu m = (javax.swing.JMenu) getJavaObject();

        if (m != null) {

            if (mi != null) {

                m.add((javax.swing.JMenuItem) mi.getJavaObject());

            } else {
    
                throw new Exception("Could not set about menu item. The about menu item is null.");
            }

        } else {

            throw new Exception("Could not set about menu item. The java menu is null.");
        }
    }

    /**
     * Removes the about menu item.
     *
     * @param mi the about menu item
     * @exception Exception if the java menu is null
     * @exception Exception if the about menu item is null
     */
    public void removeAboutMenuItem(AboutMenuItem mi) throws Exception {

        javax.swing.JMenu m = (javax.swing.JMenu) getJavaObject();

        if (m != null) {

            if (mi != null) {

                m.remove((javax.swing.JMenuItem) mi.getJavaObject());

            } else {
    
                throw new Exception("Could not remove about menu item. The about menu item is null.");
            }

        } else {

            throw new Exception("Could not remove about menu item. The java menu is null.");
        }
    }

    //
    // Categorization.
    //

    /**
     * Categorizes this hierarchy.
     */
    public void categorize() throws Exception {

        super.categorize();

        setCategory(HelpMenu.ABOUT_MENU_ITEM, getDefaultAboutMenuItemCategory());
    }

    /**
     * Decategorizes this hierarchy.
     */
    public void decategorize() throws Exception {

        removeCategory(HelpMenu.ABOUT_MENU_ITEM);

        super.decategorize();
    }

    //
    // Initialization.
    //

    /**
     * Initializes this item.
     */
    public void initialize() throws Exception {

        super.initialize();

        setChild(HelpMenu.ABOUT_MENU_ITEM, createChild(getCategory(HelpMenu.ABOUT_MENU_ITEM)));
    }

    /**
     * Finalizes this item.
     */
    public void finalizz() throws Exception {

        Item aboutMenuItem = getChild(HelpMenu.ABOUT_MENU_ITEM);
        removeChild(HelpMenu.ABOUT_MENU_ITEM);
        destroyChild(aboutMenuItem);

        super.finalizz();
    }
}

