/*
 * $RCSfile: YesButton.java,v $
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
 * but WITHOUT ANY WARRANTY; without even the ied warranty of
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

package cybop.core.model.organizer;

import cybop.core.basic.Integer;
import cybop.core.basic.String;

/**
 * This class represents a yes button.
 *
 * @version $Revision: 1.3 $ $Date: 2003-02-20 15:35:14 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class YesButton extends PanelButton {

    //
    // Actions.
    //

    /** The yes action. */
    public static final String YES_ACTION = new String("yes_action");

    //
    // Default children.
    //

    /**
     * Returns the default label.
     *
     * @return the default label
     */
    public String getDefaultLabel() {

        return new String("Yes");
    }

    /**
     * Returns the default mnemonic.
     *
     * @return the default mnemonic
     */
    public Integer getDefaultMnemonic() {

        return new Integer(java.awt.event.KeyEvent.VK_Y);
    }

    /**
     * Returns the default action.
     *
     * @return the default action
     */
    public String getDefaultAction() {

        return YesButton.YES_ACTION;
    }
}

