/*
 * $RCSfile: Definition.java,v $
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
 * This class represents a definition.
 *
 * A definition specifies several constraints for its children.
 *
 * @version $Revision: 1.2 $ $Date: 2003-06-12 21:16:11 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class Definition extends Structure {

    //
    // Meta attributes.
    //

    /** The constraints. */
    private Map constraints;

    //
    // Constraints.
    //

    /**
     * Creates the constraints.
     *
     * @return the constraints
     */
    public Map createConstraints() {

        return null;
    }

    /**
     * Destroys the constraints.
     *
     * @param c the constraints
     */
    public void destroyConstraints(Map c) {
    }

    /**
     * Sets the constraints.
     *
     * @param c the constraints
     */
    public void setConstraints(Map c) {

        this.constraints = c;
    }

    /**
     * Returns the constraints.
     *
     * @return the constraints
     */
    public Map getConstraints() {

        return this.constraints;
    }

    //
    // Constraint management.
    //

    /**
     * Sets the constraint.
     *
     * @param n the name
     * @param c the constraint
     * @exception Exception if the constraints is null
     */
    public void setConstraint(String n, Definition c) throws Exception {

        Map m = getConstraints();

        if (m != null) {

            m.set(n, c);

        } else {

            throw new Exception("Could not set constraint. The constraints is null.");
        }
    }

    /**
     * Removes the constraint.
     *
     * @param n the name
     * @exception Exception if the constraints is null
     */
    public void removeConstraint(String n) throws Exception {

        Map m = getConstraints();

        if (m != null) {

            m.remove(n);

        } else {

            throw new Exception("Could not remove constraint. The constraints is null.");
        }
    }

    /**
     * Returns the constraint.
     *
     * @param n the name
     * @return the constraint
     * @exception Exception if the constraints is null
     */
    public Definition getConstraint(String n) throws Exception {

        Definition c = null;
        Map m = getConstraints();

        if (m != null) {

            c = (Definition) m.get(n);

        } else {

            throw new Exception("Could not get constraint. The constraints is null.");
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

        setConstraints(createConstraints());
    }

    /**
     * Deabstracts this abstraction.
     */
    public void deabstract() throws Exception {

        Map constraints = getConstraints();
        setConstraints(null);
        destroyConstraints(constraints);

        super.deabstract();
    }

    //
    // Constraining.
    //

    /**
     * Constrains this definition.
     */
    public void constrain() throws Exception {
    }

    /**
     * Unconstrains this definition.
     */
    public void unconstrain() throws Exception {
    }
}

