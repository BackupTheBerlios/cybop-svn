/*
 * $RCSfile: DesktopDisplay.java,v $
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

package cybop.core.screen.model;

import cybop.core.category.*;
import cybop.core.model.String;
import cybop.core.screen.*;

/**
 * This class represents a desktop model.
 *
 * @version $Revision: 1.4 $ $Date: 2003-06-29 21:31:58 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class DesktopDisplay extends Display {

    //
    // Children names.
    //

    /** The menu. */
    public static final String MENU = new String("menu");

    /** The panel. */
    public static final String PANEL = new String("panel");

    /** The entry. */
    public static final String ENTRY = new String("entry");

    /** The window. */
    public static final String WINDOW = new String("window");

    //
    // Default categories.
    //

    /**
     * Returns the default menu category.
     *
     * @return the default menu category
     */
    public Item getDefaultMenuCategory() {

        return null;
    }

    /**
     * Returns the default panel category.
     *
     * @return the default panel category
     */
    public Item getDefaultPanelCategory() {

        return null;
    }

    //
    // Categorization.
    //

    /**
     * Categorizes this hierarchy.
     */
    public void categorize() throws Exception {

        super.categorize();

        setCategory(DesktopDisplay.MENU, getDefaultMenuCategory());
        setCategory(DesktopDisplay.PANEL, getDefaultPanelCategory());
    }

    /**
     * Decategorizes this hierarchy.
     */
    public void decategorize() throws Exception {

        removeCategory(DesktopDisplay.PANEL);
        removeCategory(DesktopDisplay.MENU);

        super.decategorize();
    }

    //
    // Initialization.
    //

    /**
     * Initializes this item.
     */
    public void initialize() throws Exception {

        super.initialize();

        setChild(DesktopDisplay.MENU, createChild(getCategory(DesktopDisplay.MENU)));
        setChild(DesktopDisplay.PANEL, createChild(getCategory(DesktopDisplay.PANEL)));
    }

    /**
     * Finalizes this item.
     */
    public void finalizz() throws Exception {

        Item panel = getChild(DesktopDisplay.PANEL);
        removeChild(DesktopDisplay.PANEL);
        destroyChild(panel);

        Item menu = getChild(DesktopDisplay.MENU);
        removeChild(DesktopDisplay.MENU);
        destroyChild(menu);

        super.finalizz();
    }
}

