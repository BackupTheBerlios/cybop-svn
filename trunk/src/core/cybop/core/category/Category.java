/*
 * $RCSfile: Category.java,v $
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

/**
 * This class represents a category.
 *
 * A category classifies items with common properties into one group.
 * The category can be named using the corresponding name attribute.
 *
 * @version $Revision: 1.2 $ $Date: 2003-06-12 21:16:11 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class Category extends Array {

    //
    // Meta attributes.
    //

    /** The name. */
    private Array name;

    //
    // Name.
    //

    /**
     * Creates a name.
     *
     * @return the name
     */
    public Array createName() {

        return null;
    }

    /**
     * Destroys the name.
     *
     * @param n the name
     */
    public void destroyName(Array n) {
    }

    /**
     * Sets the name.
     *
     * @param n the name
     */
    public void setName(Array n) {

        this.name = n;
    }

    /**
     * Returns the name.
     *
     * @return the name
     */
    public Array getName() {

        return this.name;
    }

    //
    // Abstraction.
    //

    /**
     * Abstracts this abstraction.
     */
    public void abstracc() throws Exception {

        super.abstracc();

        setName(createName());
    }

    /**
     * Deabstracts this abstraction.
     */
    public void deabstract() throws Exception {

        Array name = getName();
        setName(null);
        destroyName(name);
        
        super.deabstract();
    }

    //
    // Naming.
    //

    /**
     * Names this category.
     */
    public void name() throws Exception {
    }

    /**
     * Unnames this category.
     */
    public void unname() throws Exception {
    }
}

