/*
 * $RCSfile: SystemInformationUserInterface.java,v $
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

package cybop.core.model.model.user;

import cybop.core.basic.Boolean;
import cybop.core.basic.Integer;
import cybop.core.basic.String;
import cybop.core.model.model.*;
import cybop.core.model.organizer.*;

/**
 * This class represents a system information user interface.
 *
 * It shows the following information about the system:
 * - name
 * - logo
 * - version
 * - license
 * - authors
 * - helpers
 *
 * @version $Revision: 1.3 $ $Date: 2003-02-20 15:35:14 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class SystemInformationUserInterface extends UserInterface {

    //
    // Default children.
    //

    /**
     * Returns the default user interface mode.
     *
     * The default is: System.INTERNAL_FRAME_MODE
     *
     * @return the default user interface mode
     */
    public Integer getDefaultUserInterfaceMode() {

        return SystemInformationUserInterface.MODAL_DIALOG_MODE;
    }

    /**
     * Returns the default title.
     *
     * @return the default title
     */
    public String getDefaultTitle() {

        return new String("About CYBOP");
    }

    /**
     * Returns the default icon.
     *
     * @return the default icon
     */
/*??
    public String getDefaultIcon() {

        return null;
    }

    /**
     * Returns the default contents panel.
     *
     * @return the default contents panel
     */
    public String getDefaultContentsPanel() {

        return new String("cybop.core.model.organizer.SystemInformationContentsPanel");
    }

    /**
     * Returns the default rectangle storing the bounds.
     *
     * @return the default rectangle storing the bounds
     */
    public java.awt.Rectangle getDefaultBounds() {

        // Determine width.
        int screenWidth = (int) java.lang.Math.floor(java.awt.Toolkit.getDefaultToolkit().getScreenSize().getWidth());
        int w = 640;

        if (w > screenWidth) {

            w = screenWidth;
        }

        // Use centered x position by default.
        int x = (screenWidth - w) / 2;

        // Determine height.
        int screenHeight = (int) java.lang.Math.floor(java.awt.Toolkit.getDefaultToolkit().getScreenSize().getHeight());
        int h = 480;

        if (h > screenHeight) {

            h = screenHeight;
        }

        // Use centered y position by default.
        int y = (screenHeight - h) / 2;

        return new java.awt.Rectangle(x, y, w, h);
    }

    /**
     * Returns the default resizable flag.
     *
     * @return the default resizable flag
     */
    public Boolean getDefaultResizableFlag() {

        return new Boolean(Boolean.TRUE);
    }
}

