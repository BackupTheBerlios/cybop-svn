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
 * http://www.resmedicinae.org
 * - Information in Medicine -
 */

package cybop.core.model.principle;

import cybop.core.basic.Integer;
import cybop.core.model.*;

/**
 * This class represents a space and point.
 *
 * A space specifies the room which is spanned up by an item.
 * A point is just a minimal space and always relative to the referenced object.
 * The absolute point does not exist as any point can consist of yet smaller points.
 *
 * @version $Revision: 1.2 $ $Date: 2003-02-19 17:15:17 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class Space extends Principle {

    //
    // Children.
    //

    /** The x coordinate. */
    private Integer x;
    
    /** The y coordinate. */
    private Integer y;
    
    /** The z coordinate. */
    private Integer z;

    //
    // Encapsulated java awt point.
    //
    
    /**
     * Creates an encapsulated java awt point.
     *
     * @return the encapsulated java awt point
     */
    public java.lang.Object createJavaObject() throws NullPointerException {

        return new java.awt.Point();
    }

    //
    // The x coordinate.
    //
    
    /**
     * Sets the x coordinate.
     *
     * @param x the x coordinate
     */
    public void setX(Integer x) {
        
        this.x = x;
    }
    
    /**
     * Returns the x coordinate.
     *
     * @return the x coordinate
     */
    public Integer getX() {
        
        return this.x;
    }
    
    //
    // The y coordinate.
    //
    
    /**
     * Sets the y coordinate.
     *
     * @param y the y coordinate
     */
    public void setY(Integer y) {
        
        this.y = y;
    }
    
    /**
     * Returns the y coordinate.
     *
     * @return the y coordinate
     */
    public Integer getY() {
        
        return this.y;
    }
    
    //
    // The z coordinate.
    //
    
    /**
     * Sets the z coordinate.
     *
     * @param z the z coordinate
     */
    public void setZ(Integer z) {

        this.z = z;
    }
    
    /**
     * Returns the z coordinate.
     *
     * @return the z coordinate
     */
    public Integer getZ() {
        
        return this.z;
    }
}

