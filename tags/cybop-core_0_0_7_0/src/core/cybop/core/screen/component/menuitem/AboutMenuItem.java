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

package cybop.core.screen.component.menuitem;

import cybop.core.category.*;
import cybop.core.model.Integer;
import cybop.core.model.String;
import cybop.core.screen.component.*;

/**
 * This class represents an about menu item.
 *
 * @version $Revision: 1.5 $ $Date: 2003-06-20 13:44:24 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class AboutMenuItem extends MenuItem {

    //
    // Actions.
    //

    /** The show system information display action. */
    public static final String SHOW_SYSTEM_INFORMATION_ACTION = new String("show_system_information_display_action");

    //
    // Default categories.
    //

    /**
     * Returns the default label category.
     *
     * @return the default label category
     */
    public Item getDefaultLabelCategory() {

        return new String("About");
    }

    /**
     * Returns the default mnemonic category.
     *
     * @return the default mnemonic category
     */
    public Item getDefaultMnemonicCategory() {

        return new Integer(java.awt.event.KeyEvent.VK_A);
    }

    /**
     * Returns the default action category.
     *
     * @return the default action category
     */
    public Item getDefaultActionCategory() {

        return AboutMenuItem.SHOW_SYSTEM_INFORMATION_ACTION;
    }
}

