/*
 * $RCSfile: AboutMenuItem.java,v $
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

package cybop.core.model.organizer.menuitem;

import cybop.core.basic.Integer;
import cybop.core.basic.String;
import cybop.core.model.organizer.*;

/**
 * This class represents an about menu item.
 *
 * @version $Revision: 1.1 $ $Date: 2003-05-18 17:58:15 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class AboutMenuItem extends MenuItem {

    //
    // Actions.
    //

    /** The show system information user interface action. */
    public static final String SHOW_SYSTEM_INFORMATION_ACTION = new String("show_system_information_user_interface_action");

    //
    // Default children.
    //

    /**
     * Returns the default label.
     *
     * @return the default label
     */
    public String getDefaultLabel() {

        return new String("About");
    }

    /**
     * Returns the default mnemonic.
     *
     * @return the default mnemonic
     */
    public Integer getDefaultMnemonic() {

        return new Integer(java.awt.event.KeyEvent.VK_A);
    }

    /**
     * Returns the default action.
     *
     * @return the default action
     */
    public String getDefaultAction() {

        return AboutMenuItem.SHOW_SYSTEM_INFORMATION_ACTION;
    }
}

