/*
 * $RCSfile: Behaviour.java,v $
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
 * This class represents a behaviour.
 *
 * A behaviour is determined by its procedures.
 *
 * @version $Revision: 1.4 $ $Date: 2003-06-18 13:20:38 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class Behaviour extends Definition {

    //
    // Meta attributes.
    //

    /** The procedures. */
    private Map procedures;

    //
    // Procedures.
    //

    /**
     * Creates the procedures.
     *
     * @return the procedures
     */
    public Map createProcedures() throws Exception {

        Map m = new Map();
        
        if (m != null) {

            m.abstracc();

        } else {

            throw new Exception("Could not create procedures. The procedures is null.");
        }

        return m;
    }

    /**
     * Destroys the procedures.
     *
     * @param p the procedures
     */
    public void destroyProcedures(Map p) throws Exception {
    }

    /**
     * Sets the procedures.
     *
     * @param p the procedures
     */
    public void setProcedures(Map p) {

        this.procedures = p;
    }

    /**
     * Returns the procedures.
     *
     * @return the procedures
     */
    public Map getProcedures() {

        return this.procedures;
    }

    //
    // Procedure management.
    //

    /**
     * Sets the procedure.
     *
     * @param n the name
     * @param p the procedure
     * @exception Exception if the procedures is null
     */
    public void setProcedure(Array n, Behaviour p) throws Exception {

        Map m = getProcedures();

        if (m != null) {

            m.set(n, p);

        } else {

            throw new Exception("Could not set procedure. The procedures is null.");
        }
    }

    /**
     * Removes the procedure.
     *
     * @param n the name
     * @exception Exception if the procedures is null
     */
    public void removeProcedure(Array n) throws Exception {

        Map m = getProcedures();

        if (m != null) {

            m.remove(n);

        } else {

            throw new Exception("Could not remove procedure. The procedures is null.");
        }
    }

    /**
     * Returns the procedure.
     *
     * @param n the name
     * @return the procedure
     * @exception Exception if the procedures is null
     */
    public Behaviour getProcedure(Array n) throws Exception {

        Behaviour p = null;
        Map m = getProcedures();

        if (m != null) {

            p = (Behaviour) m.get(n);

        } else {

            throw new Exception("Could not get procedure. The procedures is null.");
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

        setProcedures(createProcedures());
    }

    /**
     * Deabstracts this abstraction.
     */
    public void deabstract() throws Exception {

        Map procedures = getProcedures();
        setProcedures(null);
        destroyProcedures(procedures);

        super.deabstract();
    }

    //
    // Behaviouring.
    //

    /**
     * Behaves this behaviour.
     */
    public void behave() throws Exception {
    }

    /**
     * Unbehaves this behaviour.
     */
    public void unbehave() throws Exception {
    }
}

