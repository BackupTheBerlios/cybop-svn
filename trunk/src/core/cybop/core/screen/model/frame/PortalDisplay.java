/*
 * $RCSfile: PortalDisplay.java,v $
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

package cybop.core.screen.model.frame;

import cybop.core.model.String;
import cybop.core.screen.model.*;

/**
 * This class represents a portal model.
 *
 * It is based on a split pane containing a tree menu on the left.
 * The tree offers a hierarchy of categories with available system modules.
 * On the right side of the splitter, there is a container for child system views.
 *
 * @version $Revision: 1.2 $ $Date: 2003-06-17 15:39:22 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class PortalDisplay extends FrameDisplay {

    //
    // Default children.
    //

    /**
     * Returns the default portal menu bar.
     *
     * @return the default portal menu bar
     */
    public String getDefaultMenuBar() {

        return new String("cybop.core.model.organizer.PortalMenuBar");
    }

    /**
     * Returns the default portal tool bar.
     *
     * @return the default portal tool bar
     */
    public String getDefaultToolBar() {

        return new String("cybop.core.model.organizer.PortalToolBar");
    }

    /**
     * Returns the default contents panel.
     *
     * @return the default contents panel
     */
    public String getDefaultContentsPanel() {

        return new String("cybop.core.screen.PortalPanel");
    }
}

