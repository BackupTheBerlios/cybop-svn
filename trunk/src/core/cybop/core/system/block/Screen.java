/*
 * $RCSfile: Screen.java,v $
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

package cybop.core.system.block;

import cybop.core.category.*;
import cybop.core.model.Boolean;
import cybop.core.model.String;
import cybop.core.screen.*;
import cybop.core.system.*;

/**
 * This class represents a screen.<br><br>
 *
 * A screen is an output device that displays optical (graphical) information. 
 *
 * @version $Revision: 1.12 $ $Date: 2003-06-29 21:31:58 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class Screen extends Block {

    //
    // Children names.
    //

    /** The resolution. */
    public static final String RESOLUTION = new String("resolution");

    //
    // Resolutions.
    //
    
    /** The 640x480 resolution. */
    public static final String THE_640_480_RESOLUTION = new String("640_480_resolution");

    /** The 800x600 resolution. */
    public static final String THE_800_600_RESOLUTION = new String("800_600_resolution");

    /** The 1024x768 resolution. */
    public static final String THE_1024_768_RESOLUTION = new String("1024_768_resolution");

    //
    // Default categories.
    //

    /**
     * Returns the default resolution category.
     *
     * @return the default resolution category
     */
    public Item getDefaultResolutionCategory() {

        return null; //?? Screen.THE_640_480_RESOLUTION;
    }

    //
    // Categorization.
    //

    /**
     * Categorizes this hierarchy.
     */
    public void categorize() throws Exception {

        super.categorize();

        setCategory(Screen.RESOLUTION, getDefaultResolutionCategory());
    }

    /**
     * Decategorizes this hierarchy.
     */
    public void decategorize() throws Exception {

        removeCategory(Screen.RESOLUTION);

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

        setChild(Screen.RESOLUTION, createChild(getCategory(Screen.RESOLUTION)));
    }

    /**
     * Finalizes this item.
     */
    public void finalizz() throws Exception {

        Item resolution = getChild(Screen.RESOLUTION);
        removeChild(Screen.RESOLUTION);
        destroyChild(resolution);

        super.finalizz();
    }

    //
    // Showing models.
    //
    
    /**
     * Shows the gui model.
     *
     * @param m the gui model
     * @exception Exception if the model is null
     */
    public void show(Display m) throws Exception {

        if (m != null) {

            //?? Temporary workaround using Java AWT's capabilities.
            //?? Let this screen class paint everything later,
            //?? when AWT gets replaced.
            java.lang.System.out.println("DEBUG: Set java gui visible.");
            ((java.awt.Component) m.getJavaObject()).setVisible(Boolean.TRUE);

        } else {

            throw new Exception("Could not show model. The model is null.");
        }
    }
    
    /**
     * Hides the gui model.
     *
     * @param m the gui model
     * @exception Exception if the model is null
     */
    public void hide(Display m) throws Exception {

        if (m != null) {

            //?? Temporary workaround using Java AWT's capabilities.
            //?? Let this screen class paint everything later,
            //?? when AWT gets replaced.
            java.lang.System.out.println("DEBUG: Set java gui invisible.");
            ((java.awt.Component) m.getJavaObject()).setVisible(Boolean.FALSE);

        } else {

            throw new Exception("Could not hide model. The model is null.");
        }
    }
}

