/*
 * $RCSfile: SystemsMenu.java,v $
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
 * This class represents a systems menu.
 *
 * @version $Revision: 1.4 $ $Date: 2003-03-12 18:12:20 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class SystemsMenu extends Menu {

    //
    // Children names.
    //

    /** The exit menu item. */
    public static final String EXIT_MENU_ITEM = new String("exit_menu_item");

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
    public void set(String n, Item i) throws NullPointerException {

        super.set(n, i);

        if (n != null) {

            if (n.isEqualTo(SystemsMenu.EXIT_MENU_ITEM)) {

                setExitMenuItem((ExitMenuItem) i);
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
    public void remove(String n) throws NullPointerException {

        if (n != null) {

            if (n.isEqualTo(SystemsMenu.EXIT_MENU_ITEM)) {

                removeExitMenuItem((ExitMenuItem) get(n));
            }

        } else {

            throw new NullPointerException("Could not remove item. The name is null.");
        }

        super.remove(n);
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

        return new String("Systems");
    }

    /**
     * Returns the default exit menu item.
     *
     * @return the default exit menu item
     */
    public String getDefaultExitMenuItem() {

        return new String("cybop.core.model.organizer.menuitem.ExitMenuItem");
    }

    //
    // Exit menu item.
    //

    /**
     * Sets the exit menu item.
     *
     * @param mi the exit menu item
     * @exception NullPointerException if the java menu is null
     * @exception NullPointerException if the exit menu item is null
     */
    public void setExitMenuItem(ExitMenuItem mi) throws NullPointerException {

        javax.swing.JMenu m = (javax.swing.JMenu) getJavaObject();

        if (m != null) {

            if (mi != null) {

                m.add((javax.swing.JMenuItem) mi.getJavaObject());

            } else {
    
                throw new NullPointerException("Could not set exit menu item. The exit menu item is null.");
            }

        } else {

            throw new NullPointerException("Could not set exit menu item. The java menu is null.");
        }
    }

    /**
     * Removes the exit menu item.
     *
     * @param mi the exit menu item
     * @exception NullPointerException if the java menu is null
     * @exception NullPointerException if the exit menu item is null
     */
    public void removeExitMenuItem(ExitMenuItem mi) throws NullPointerException {

        javax.swing.JMenu m = (javax.swing.JMenu) getJavaObject();

        if (m != null) {

            if (mi != null) {

                m.remove((javax.swing.JMenuItem) mi.getJavaObject());

            } else {
    
                throw new NullPointerException("Could not remove exit menu item. The exit menu item is null.");
            }

        } else {

            throw new NullPointerException("Could not remove exit menu item. The java menu is null.");
        }
    }

    //
    // Initializable.
    //

    /**
     * Initializes this systems menu.
     */
    public void initialize() throws Exception {

        super.initialize();

        set(SystemsMenu.EXIT_MENU_ITEM, createComponent(getDefaultExitMenuItem()));
    }

    /**
     * Finalizes this systems menu.
     */
    public void finalizz() throws Exception {

        ExitMenuItem exitMenuItem = (ExitMenuItem) get(SystemsMenu.EXIT_MENU_ITEM);
        remove(SystemsMenu.EXIT_MENU_ITEM);
        destroyComponent(exitMenuItem);

        super.finalizz();
    }
}

