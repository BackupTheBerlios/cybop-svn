/*
 * $RCSfile: Hierarchy.java,v $
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
 * This class represents a hierarchy.
 *
 * A hierarchy is a parent that contains a number of (child) categories.
 * It can also be a child itself, belonging to a parent.<br><br>
 *
 * Since humans don't know where this hierarchy stops in the real world,
 * to microcosm as well as towards macrocosm, a black box has to be assumed
 * at some point towards microcosm. In the case of programming, this is mostly
 * the basic items of programming language, namely Boolean, Number and Character.
 * They are coded in binaries within the machine and that is the final abstraction.
 * Towards macrocosm, it depends on the modeller how far he/she wants to go.<br><br>
 *
 * @version $Revision: 1.3 $ $Date: 2003-06-13 16:56:43 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class Hierarchy extends Inheritance {

    //
    // Meta attributes.
    //

    /** The categories. */
    private Map categories;

    //
    // Categories.
    //

    /**
     * Creates the categories.
     *
     * @return the categories
     */
    public Map createCategories() {

        return null;
    }

    /**
     * Destroys the categories.
     *
     * @param c the categories
     */
    public void destroyCategories(Map c) {
    }

    /**
     * Sets the categories.
     *
     * @param c the categories
     */
    public void setCategories(Map c) {

        this.categories = c;
    }

    /**
     * Returns the categories.
     *
     * @return the categories
     */
    public Map getCategories() {

        return this.categories;
    }

    //
    // Category management.
    //

    /**
     * Sets the category.
     *
     * @param n the name
     * @param c the category
     * @exception Exception if the categories is null
     */
    public void setCategory(Array n, Hierarchy c) throws Exception {

        Map m = getCategories();

        if (m != null) {

            m.set(n, c);

        } else {

            throw new Exception("Could not set category. The categories is null.");
        }
    }

    /**
     * Removes the category.
     *
     * @param n the name
     * @exception Exception if the categories is null
     */
    public void removeCategory(Array n) throws Exception {

        Map m = getCategories();

        if (m != null) {

            m.remove(n);

        } else {

            throw new Exception("Could not remove category. The categories is null.");
        }
    }

    /**
     * Returns the category.
     *
     * @param n the name
     * @return the category
     * @exception Exception if the categories is null
     */
    public Hierarchy getCategory(Array n) throws Exception {

        Hierarchy c = null;
        Map m = getCategories();

        if (m != null) {

            c = (Hierarchy) m.get(n);

        } else {

            throw new Exception("Could not get category. The categories is null.");
        }
        
        return c;
    }

    //
    // Abstraction.
    //

    /**
     * Abstracts this abstraction.
     */
    public void abstracc() throws Exception {

        super.abstracc();

        setCategories(createCategories());
    }

    /**
     * Deabstracts this abstraction.
     */
    public void deabstract() throws Exception {

        Map categories = getCategories();
        setCategories(null);
        destroyCategories(categories);

        super.deabstract();
    }

    //
    // Categorization.
    //

    /**
     * Categorizes this hierarchy.
     */
    public void categorize() throws Exception {
    }

    /**
     * Decategorizes this hierarchy.
     */
    public void decategorize() throws Exception {
    }
}

