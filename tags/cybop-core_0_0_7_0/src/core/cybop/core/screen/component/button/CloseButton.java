/*
 * $RCSfile: CloseButton.java,v $
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

package cybop.core.screen.component.button;

import cybop.core.model.Integer;
import cybop.core.model.String;

/**
 * This class represents a close button.
 *
 * @version $Revision: 1.3 $ $Date: 2003-05-23 11:57:29 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class CloseButton extends PanelButton {

    //
    // Actions.
    //

    /** The close action. */
    public static final String CLOSE_ACTION = new String("close_action");

    //
    // Default children.
    //

    /**
     * Returns the default label.
     *
     * @return the default label
     */
    public String getDefaultLabel() {

        return new String("Close");
    }

    /**
     * Returns the default mnemonic.
     *
     * @return the default mnemonic
     */
    public Integer getDefaultMnemonic() {

        return new Integer(java.awt.event.KeyEvent.VK_C);
    }

    /**
     * Returns the default action.
     *
     * @return the default action
     */
    public String getDefaultAction() {

        return CloseButton.CLOSE_ACTION;
    }
}

