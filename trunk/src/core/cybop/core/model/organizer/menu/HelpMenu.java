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

package cybop.core.model.organizer.menu;

import cybop.core.basic.*;
import cybop.core.basic.String;
import cybop.core.model.organizer.*;
import cybop.core.model.organizer.menuitem.*;

/**
 * This class represents a help menu.
 *
 * @version $Revision: 1.6 $ $Date: 2003-04-29 15:12:13 $ $Author: christian $
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
     * @exception NullPointerException if the name is null
     */
    public void setChildItem(String n, Item i) throws NullPointerException {

        super.setChildItem(n, i);

        if (n != null) {

            if (n.isEqualTo(HelpMenu.ABOUT_MENU_ITEM)) {

                setAboutMenuItem((AboutMenuItem) i);
            }

        } else {

            throw new NullPointerException("Could not set item. The name is null.");
        }
    }

    /**
     * Removes the child item from this item.
     *
     * @param n the name
     * @exception NullPointerException if the name is null
     */
    public void removeChildItem(String n) throws NullPointerException {

        if (n != null) {

            if (n.isEqualTo(HelpMenu.ABOUT_MENU_ITEM)) {

                removeAboutMenuItem((AboutMenuItem) getChildItem(n));
            }

        } else {

            throw new NullPointerException("Could not remove item. The name is null.");
        }

        super.removeChildItem(n);
    }

    //
    // Default children.
    //

    /**
     * Returns the default label.
     *
     * @return the default label
     */
    public String getDefaultLabel() {

        return new String("Help");
    }

    /**
     * Returns the default about menu item.
     *
     * @return the default about menu item
     */
    public String getDefaultAboutMenuItem() {

        return new String("cybop.core.model.organizer.menuitem.AboutMenuItem");
    }

    //
    // About menu item.
    //

    /**
     * Sets the about menu item.
     *
     * @param mi the about menu item
     * @exception NullPointerException if the java menu is null
     * @exception NullPointerException if the about menu item is null
     */
    public void setAboutMenuItem(AboutMenuItem mi) throws NullPointerException {

        javax.swing.JMenu m = (javax.swing.JMenu) getJavaObject();

        if (m != null) {

            if (mi != null) {

                m.add((javax.swing.JMenuItem) mi.getJavaObject());

            } else {
    
                throw new NullPointerException("Could not set about menu item. The about menu item is null.");
            }

        } else {

            throw new NullPointerException("Could not set about menu item. The java menu is null.");
        }
    }

    /**
     * Removes the about menu item.
     *
     * @param mi the about menu item
     * @exception NullPointerException if the java menu is null
     * @exception NullPointerException if the about menu item is null
     */
    public void removeAboutMenuItem(AboutMenuItem mi) throws NullPointerException {

        javax.swing.JMenu m = (javax.swing.JMenu) getJavaObject();

        if (m != null) {

            if (mi != null) {

                m.remove((javax.swing.JMenuItem) mi.getJavaObject());

            } else {
    
                throw new NullPointerException("Could not remove about menu item. The about menu item is null.");
            }

        } else {

            throw new NullPointerException("Could not remove about menu item. The java menu is null.");
        }
    }

    //
    // Initializable.
    //

    /**
     * Initializes this help menu.
     */
    public void initialize() throws Exception {

        super.initialize();

        setChildItem(HelpMenu.ABOUT_MENU_ITEM, createChildItem(getDefaultAboutMenuItem()));
    }

    /**
     * Finalizes this help menu.
     */
    public void finalizz() throws Exception {

        AboutMenuItem aboutMenuItem = (AboutMenuItem) getChildItem(HelpMenu.ABOUT_MENU_ITEM);
        removeChildItem(HelpMenu.ABOUT_MENU_ITEM);
        destroyChildItem(aboutMenuItem);

        super.finalizz();
    }
}

