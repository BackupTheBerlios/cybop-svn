/*
 * $RCSfile: Medication.java,v $
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

package cybop.healthcare.model.unit;

import cybop.core.basic.String;
import cybop.healthcare.model.*;
import cybop.healthcare.model.description.*;

/**
 * This class represents a medication.<br><br>
 *
 * A medication is ...
 *
 * @version $Revision: 1.3 $ $Date: 2003-02-20 15:35:15 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class Medication extends Unit {

    //
    // Children.
    //
    
    /** The name. */
    public static final String NAME = new String("name");

    //
    // Default children.
    //

    /**
     * Returns the default name.
     *
     * @return the default name
     */
    public String getDefaultName() {

        return null;
    }

    //
    // Initialization.
    //

    /**
     * Initializes this medication.
     */
    public void initialize() throws Exception {

        super.initialize();

        set(Medication.NAME, getDefaultName());
    }

    /**
     * Finalizes this medication.
     */
    public void finalizz() throws Exception {

        remove(Medication.NAME);

        super.finalizz();
    }

    public Object[] getDose() {

        Object[] childrenArray = getChildren().values().toArray();
        java.util.Vector tempVector = new java.util.Vector();

        for (int i = 0; i < childrenArray.length; i++) {

            if (childrenArray[i].getClass().equals(Dose.class)) {

                tempVector.add(childrenArray[i]);
            }
        }

        return tempVector.toArray();
    }
}

