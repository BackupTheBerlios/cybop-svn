/*
 * $RCSfile: Inheritance.java,v $
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

/**
 * This class represents an inheritance.
 *
 * An inheritance allows a (sub) category to inherit properties from another
 * (super) category. The super category can be specified using the ancestor
 * attribute.
 *
 * @version $Revision: 1.1 $ $Date: 2003-05-17 22:30:11 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class Inheritance extends Category {

    //
    // Meta attributes.
    //

    /** The ancestor. */
    private Inheritance ancestor;

    //
    // Ancestor.
    //

    /**
     * Creates an ancestor.
     *
     * @return the ancestor
     */
    public Inheritance createAncestor() {

        return null;
    }

    /**
     * Destroys the ancestor.
     *
     * @param a the ancestor
     */
    public void destroyAncestor(Inheritance a) {
    }

    /**
     * Sets the ancestor.
     *
     * @param a the ancestor
     */
    public void setAncestor(Inheritance a) {

        this.ancestor = a;
    }

    /**
     * Returns the ancestor.
     *
     * @return the ancestor
     */
    public Inheritance getAncestor() {

        return this.ancestor;
    }

    //
    // Abstraction.
    //

    /**
     * Abstracts this inheritance.
     */
    public void abstracc() throws Exception {

        super.abstracc();

        setAncestor(createAncestor());
    }

    /**
     * Deabstracts this inheritance.
     */
    public void deabstract() throws Exception {

        Inheritance ancestor = getAncestor();
        setAncestor(null);
        destroyAncestor(ancestor);

        super.deabstract();
    }

    //
    // Inheritance.
    //

    /**
     * Inherits this inheritance.
     */
    public void inherit() throws Exception {
    }

    /**
     * Uninherits this inheritance.
     */
    public void uninherit() throws Exception {
    }
}

