/*
 * $RCSfile: GraphicItem.java,v $
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

package cybop.core.model;

import cybop.core.basic.*;
import cybop.core.basic.String;

/**
 * This class represents a graphic item.<br><br>
 *
 * @version $Revision: 1.6 $ $Date: 2003-03-18 00:18:01 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class GraphicItem extends cybop.core.system.Component {

    //?? Only temporary inheritance from Component!
    //?? The gui components need a signal handler which is set in the
    //?? globalize method of Component.
    //?? Remove this inheritance (replace with Item parent class),
    //?? as soon as no signal handler has to be forwarded anymore
    //?? (when CYBOP provides mouse/keyboard input handling itselfs.

    //
    // Children names.
    //

    /** The expanse. */
    public static final String EXPANSE = new String("expanse");

    /** The minimum expanse. */
    public static final String MINIMUM_EXPANSE = new String("minimum_expanse");

    /** The foreground color. */
    public static final String FOREGROUND_COLOR = new String("foreground_color");

    /** The background color. */
    public static final String BACKGROUND_COLOR = new String("background_color");

    /** The font. */
    public static final String FONT = new String("font");

    /** The cursor. */
    public static final String CURSOR = new String("cursor");

    /** The disabled flag. */
    public static final String DISABLED_FLAG = new String("disabled_flag");

    /** The hidden flag. */
    public static final String HIDDEN_FLAG = new String("hidden_flag");

    /** The focusable flag. */
    public static final String FOCUSABLE_FLAG = new String("focusable_flag");

    /** The orientation. */
    public static final String ORIENTATION = new String("orientation");

    //
    // Orientations.
    //

    /** The 0 degree orientation. */
    public static final String DEGREE_0_ORIENTATION = new String("0_degree_orientation");

    /** The 90 degree orientation. */
    public static final String DEGREE_90_ORIENTATION = new String("90_degree_orientation");

    /** The 180 degree orientation. */
    public static final String DEGREE_180_ORIENTATION = new String("180_degree_orientation");

    /** The 270 degree orientation. */
    public static final String DEGREE_270_ORIENTATION = new String("270_degree_orientation");

    //
    // Default children.
    //

    //
    // Initialization.
    //

    /**
     * Initializes this button.
     */
    public void initialize() throws Exception {

        super.initialize();
    }

    /**
     * Finalizes this button.
     */
    public void finalizz() throws Exception {

        super.finalizz();
    }
}

