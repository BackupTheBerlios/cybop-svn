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
 * @version $Revision: 1.6 $ $Date: 2003-03-18 00:18:01 $ $Author: christian $
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

    //
    // Functionality.
    //

    /**
     * Checks whether or not this item contains the given position.
     *
     * @param p the position relative to this item
     * @return true if this item contains the given position;
     * false otherwise
     * @exception NullPointerException if the position is null
     */
    public boolean contains(Space p) throws Exception, NullPointerException {

        boolean b = false;

        if (p != null) {

            boolean xob = xContains((Integer) p.get(Space.ORIGIN_X_COORDINATE));
            boolean xeb = xContains((Integer) p.get(Space.EXPANSE_X_COORDINATE));
            boolean yob = yContains((Integer) p.get(Space.ORIGIN_Y_COORDINATE));
            boolean yeb = yContains((Integer) p.get(Space.EXPANSE_Y_COORDINATE));
            boolean zob = zContains((Integer) p.get(Space.ORIGIN_Z_COORDINATE));
            boolean zeb = zContains((Integer) p.get(Space.EXPANSE_Z_COORDINATE));

            if (xob && xeb && yob && yeb && zob && zeb) {

                b = true;
            }

        } else {

            throw new NullPointerException("Could not check position. The position is null.");
        }

        return b;
    }

    /**
     * Checks whether or not this item's x expanse contains the given x position.
     *
     * @param x the x position relative to this item
     * @return true if this item's x expanse contains the given x position;
     * false otherwise
     * @exception NullPointerException if the x position is null
     */
    public boolean xContains(Integer x) throws Exception, NullPointerException {

        boolean b = false;

        if (x != null) {

            if (x.isGreaterThanOrEqualTo((Integer) get(Space.ORIGIN_X_COORDINATE))
                && x.isSmallerThan((Integer) get(Space.EXPANSE_X_COORDINATE))) {

                b = true;
            }

        } else {

            throw new NullPointerException("Could not check x position. The x position is null.");
        }

        return b;
    }

    /**
     * Checks whether or not this item's y expanse contains the given y position.
     *
     * @param y the y position relative to this item
     * @return true if this item's y expanse contains the given y position;
     * false otherwise
     * @exception NullPointerException if the y position is null
     */
    public boolean yContains(Integer y) throws Exception, NullPointerException {

        boolean b = false;

        if (y != null) {

            if (y.isGreaterThanOrEqualTo((Integer) get(Space.ORIGIN_Y_COORDINATE))
                && y.isSmallerThan((Integer) get(Space.EXPANSE_Y_COORDINATE))) {

                b = true;
            }

        } else {

            throw new NullPointerException("Could not check y position. The y position is null.");
        }

        return b;
    }

    /**
     * Checks whether or not this item's z expanse contains the given z position.
     *
     * @param z the z position relative to this item
     * @return true if this item's z expanse contains the given z position;
     * false otherwise
     * @exception NullPointerException if the z position is null
     */
    public boolean zContains(Integer z) throws Exception, NullPointerException {

        boolean b = false;

        if (z != null) {

            if (z.isGreaterThanOrEqualTo((Integer) get(Space.ORIGIN_Z_COORDINATE))
                && z.isSmallerThan((Integer) get(Space.EXPANSE_Z_COORDINATE))) {

                b = true;
            }

        } else {

            throw new NullPointerException("Could not check z position. The z position is null.");
        }

        return b;
    }
}

