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

import cybop.core.basic.Integer;
import cybop.core.basic.String;
import cybop.core.model.*;

/**
 * This class represents a space and point at the same time.
 *
 * A space specifies the room which is spanned up by an item.
 * A point is just a minimal space and always relative to the referenced object.
 * The absolute point does not exist as any point can consist of yet smaller points.
 *
 * @version $Revision: 1.5 $ $Date: 2003-03-15 23:40:31 $ $Author: christian $
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

    //
    // Default children.
    //

    /**
     * Returns the default origin x coordinate.
     *
     * @return the default origin x coordinate
     */
    public String getDefaultOriginXCoordinate() {

        return new String("cybop.core.basic.Integer");
    }

    /**
     * Returns the default origin y coordinate.
     *
     * @return the default origin y coordinate
     */
    public String getDefaultOriginYCoordinate() {

        return new String("cybop.core.basic.Integer");
    }

    /**
     * Returns the default origin z coordinate.
     *
     * @return the default origin z coordinate
     */
    public String getDefaultOriginZCoordinate() {

        return new String("cybop.core.basic.Integer");
    }

    /**
     * Returns the default expanse x coordinate.
     *
     * @return the default expanse x coordinate
     */
    public String getDefaultExpanseXCoordinate() {

        return new String("cybop.core.basic.Integer");
    }

    /**
     * Returns the default expanse y coordinate.
     *
     * @return the default expanse y coordinate
     */
    public String getDefaultExpanseYCoordinate() {

        return new String("cybop.core.basic.Integer");
    }

    /**
     * Returns the default expanse z coordinate.
     *
     * @return the default expanse z coordinate
     */
    public String getDefaultExpanseZCoordinate() {

        return new String("cybop.core.basic.Integer");
    }

    //
    // Initialization.
    //

    /**
     * Initializes this mouse model.
     */
    public void initialize() throws Exception {

        super.initialize();

        set(Space.ORIGIN_X_COORDINATE, createItem(getDefaultOriginXCoordinate()));
        set(Space.ORIGIN_Y_COORDINATE, createItem(getDefaultOriginYCoordinate()));
        set(Space.ORIGIN_Z_COORDINATE, createItem(getDefaultOriginZCoordinate()));
        set(Space.EXPANSE_X_COORDINATE, createItem(getDefaultExpanseXCoordinate()));
        set(Space.EXPANSE_Y_COORDINATE, createItem(getDefaultExpanseYCoordinate()));
        set(Space.EXPANSE_Z_COORDINATE, createItem(getDefaultExpanseZCoordinate()));
    }

    /**
     * Finalizes this mouse model.
     */
    public void finalizz() throws Exception {

        Integer expanseZCoordinate = (Integer) get(Space.EXPANSE_Z_COORDINATE);
        remove(Space.EXPANSE_Z_COORDINATE);
        destroyItem(expanseZCoordinate);

        Integer expanseYCoordinate = (Integer) get(Space.EXPANSE_Y_COORDINATE);
        remove(Space.EXPANSE_Y_COORDINATE);
        destroyItem(expanseYCoordinate);

        Integer expanseXCoordinate = (Integer) get(Space.EXPANSE_X_COORDINATE);
        remove(Space.EXPANSE_X_COORDINATE);
        destroyItem(expanseXCoordinate);

        Integer originZCoordinate = (Integer) get(Space.ORIGIN_Z_COORDINATE);
        remove(Space.ORIGIN_Z_COORDINATE);
        destroyItem(originZCoordinate);

        Integer originYCoordinate = (Integer) get(Space.ORIGIN_Y_COORDINATE);
        remove(Space.ORIGIN_Y_COORDINATE);
        destroyItem(originYCoordinate);

        Integer originXCoordinate = (Integer) get(Space.ORIGIN_X_COORDINATE);
        remove(Space.ORIGIN_X_COORDINATE);
        destroyItem(originXCoordinate);

        super.finalizz();
    }
}

