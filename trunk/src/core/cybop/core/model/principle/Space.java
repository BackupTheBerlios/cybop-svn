/*
 * $RCSfile: Space.java,v $
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

package cybop.core.model.principle;

import cybop.core.basic.String;
import cybop.core.model.*;

/**
 * This class represents a space and point.
 *
 * A space specifies the room which is spanned up by an item.
 * A point is just a minimal space and always relative to the referenced object.
 * The absolute point does not exist as any point can consist of yet smaller points.
 *
 * @version $Revision: 1.4 $ $Date: 2003-03-12 18:12:20 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class Space extends Principle {

    //
    // Children names.
    //

    /** The origin x coordinate. */
    public static final String ORIGIN_X_COORDINATE = new String("origin_x_coordinate");

    /** The origin y coordinate. */
    public static final String ORIGIN_Y_COORDINATE = new String("origin_y_coordinate");

    /** The origin z coordinate. */
    public static final String ORIGIN_Z_COORDINATE = new String("origin_z_coordinate");

    /** The expanse x coordinate. */
    public static final String EXPANSE_X_COORDINATE = new String("expanse_x_coordinate");

    /** The expanse y coordinate. */
    public static final String EXPANSE_Y_COORDINATE = new String("expanse_y_coordinate");

    /** The expanse z coordinate. */
    public static final String EXPANSE_Z_COORDINATE = new String("expanse_z_coordinate");
}

