/*
 * $RCSfile: Descent.java,v $
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

package cybop.core.basic;

/**
 * This class represents a <i>Descent</i>.
 *
 * A <i>descent</i> contains all mechanisms that are necessary to let children
 * <i>inherit</i> properties of parents. This class follows the biological example
 * of <i>cell separation</i> where a <i>DNA</i> which contains genetical information
 * is passed from the parent cell to the new born cell.
 * In our case, the DNA is called <i>Configuration</i>
 *
 * This descent has nothing to do with the inheritance in object oriented programming.
 * It is rather some kind of forwarding (not extending) the same properties from
 * parents to children.
 *
 * @version $Revision: 1.1 $ $Date: 2003-04-30 14:37:17 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class Descent extends Hierarchy {

    //
    // Meta attributes.
    //

    /** The name. */
    private String name;

    //
    // Name.
    //

    /**
     * Creates a name.
     *
     * @return the name
     */
    public String createName() {

        return null;
    }

    /**
     * Destroys the name.
     *
     * @param n the name
     */
    public void destroyName(String n) {
    }

    /**
     * Sets the name.
     *
     * @param n the name
     */
    public void setName(String n) {

        this.name = n;
    }

    /**
     * Returns the name.
     *
     * @return the name
     */
    public String getName() {

        return this.name;
    }

    //
    // Initialization.
    //

    /**
     * Initializes this category.
     */
    public void initialize() throws Exception {

        setName(createName());
    }

    /**
     * Finalizes this category.
     */
    public void finalizz() throws Exception {

        char[] name = getName();
        setName(null);
        destroyName(name);
    }
}

