/*
 * $RCSfile: Structure.java,v $
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

package cybop.core.category;

import cybop.core.model.*;
import cybop.core.model.String;

/**
 * This class represents a structure.
 *
 * A structure knows about the positions of its children, relative to each other.
 * That means that this structure also is a special constellation of children.
 *
 * @version $Revision: 1.2 $ $Date: 2003-06-12 21:16:11 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class Structure extends Hierarchy {

    //
    // Positions.
    //

    /** The index positioning. */
    public static final String INDEX_POSITIONING = new String("index_positioning");

    /** The list positioning. */
    public static final String LIST_POSITIONING = new String("list_positioning");

    /** The compass positioning. */
    public static final String COMPASS_POSITIONING = new String("compass_positioning");

    /** The box positioning. */
    public static final String BOX_POSITIONING = new String("box_positioning");

    /** The card positioning. */
    public static final String CARD_POSITIONING = new String("card_positioning");

    /** The grid bag positioning. */
    public static final String GRID_BAG_POSITIONING = new String("grid_bag_positioning");

    //
    // Meta attributes.
    //

    /** The positions. */
    private Map positions;

    //
    // Positions.
    //

    /**
     * Creates the positions.
     *
     * @return the positions
     */
    public Map createPositions() {

        return null;
    }

    /**
     * Destroys the positions.
     *
     * @param p the positions
     */
    public void destroyPositions(Map p) {
    }

    /**
     * Sets the positions.
     *
     * @param p the positions
     */
    public void setPositions(Map p) {

        this.positions = p;
    }

    /**
     * Returns the positions.
     *
     * @return the positions
     */
    public Map getPositions() {

        return this.positions;
    }

    //
    // Position management.
    //

    /**
     * Sets the position.
     *
     * @param n the name
     * @param p the position
     * @exception Exception if the positions is null
     */
    public void setPosition(String n, Structure p) throws Exception {

        Map m = getPositions();

        if (m != null) {

            m.set(n, p);

        } else {

            throw new Exception("Could not set position. The positions is null.");
        }
    }

    /**
     * Removes the position.
     *
     * @param n the name
     * @exception Exception if the positions is null
     */
    public void removePosition(String n) throws Exception {

        Map m = getPositions();

        if (m != null) {

            m.remove(n);

        } else {

            throw new Exception("Could not remove position. The positions is null.");
        }
    }

    /**
     * Returns the position.
     *
     * @param n the name
     * @return the position
     * @exception Exception if the positions is null
     */
    public Structure getPosition(String n) throws Exception {

        Structure p = null;
        Map m = getPositions();

        if (m != null) {

            p = (Structure) m.get(n);

        } else {

            throw new Exception("Could not get position. The positions is null.");
        }

        return p;
    }

    //
    // Abstraction.
    //

    /**
     * Abstracts this abstraction.
     */
    public void abstracc() throws Exception {

        super.abstracc();

        setPositions(createPositions());
    }

    /**
     * Deabstracts this abstraction.
     */
    public void deabstract() throws Exception {

        Map positions = getPositions();
        setPositions(null);
        destroyPositions(positions);

        super.deabstract();
    }

    //
    // Positioning.
    //

    /**
     * Positions this structure.
     */
    public void position() throws Exception {
    }

    /**
     * Depositions this structure.
     */
    public void deposition() throws Exception {
    }
}

