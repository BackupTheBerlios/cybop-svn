/*
 * $RCSfile: ApplyButton.java,v $
 *
 * Copyright (c) 1999-2003. The Res Medicinae developers. All rights reserved.
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
 * http://www.resmedicinae.org
 * - Information in Medicine -
 */

package cybop.model.organizer;

import cybop.basic.Integer;
import cybop.basic.String;

/**
 * This class represents an apply button.
 *
 * @version $Revision: 1.1 $ $Date: 2003-02-19 07:49:23 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class ApplyButton extends PanelButton {

    //
    // Actions.
    //

    /** The apply action. */
    public static final String APPLY_ACTION = new String("apply_action");

    //
    // Default children.
    //

    /**
     * Returns the default label.
     *
     * @return the default label
     */
    public String getDefaultLabel() {

        return new String("Apply");
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

        return ApplyButton.APPLY_ACTION;
    }
}

