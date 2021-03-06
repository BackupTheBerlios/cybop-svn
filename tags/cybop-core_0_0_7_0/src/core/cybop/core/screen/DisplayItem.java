/*
 * $RCSfile: DisplayItem.java,v $
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

package cybop.core.screen;

import cybop.core.category.*;
import cybop.core.model.*;
import cybop.core.model.String;

/**
 * This class represents a screen item.<br><br>
 *
 * @version $Revision: 1.3 $ $Date: 2003-06-17 15:39:22 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class DisplayItem extends Item {

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
}

