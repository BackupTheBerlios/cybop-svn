/*
 * $RCSfile: PanelButton.java,v $
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

package cybop.core.screen.component;

import cybop.core.model.Boolean;

/**
 * This class represents a panel button.
 *
 * @version $Revision: 1.2 $ $Date: 2003-05-20 06:21:59 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class PanelButton extends Button {

    //
    // Encapsulated java swing button.
    //

    /**
     * Creates an encapsulated java swing button.
     *
     * @return the encapsulated java swing button
     * @exception Exception if the encapsulated java swing button is null
     */
    public java.lang.Object createJavaObject() throws Exception {

        javax.swing.JButton b = new javax.swing.JButton();

        if (b != null) {

            b.setEnabled(Boolean.TRUE);

        } else {

            throw new Exception("Could not create encapsulated java swing button. The encapsulated java swing button is null.");
        }

        return b;
    }

    /**
     * Destroys the encapsulated java swing button.
     *
     * @param o the encapsulated java swing button
     * @exception Exception if the encapsulated java swing button is null
     */
    public void destroyJavaObject(java.lang.Object o) throws Exception {

        javax.swing.JButton b = (javax.swing.JButton) o;

        if (b != null) {

            b.setEnabled(Boolean.FALSE);

        } else {

            throw new Exception("Could not destroy encapsulated java swing button. The encapsulated java swing button is null.");
        }
    }
}

