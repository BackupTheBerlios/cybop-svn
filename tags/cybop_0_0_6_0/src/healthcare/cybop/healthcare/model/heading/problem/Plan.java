/*
 * $RCSfile: Plan.java,v $
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

package cybop.healthcare.model.heading.problem;

import cybop.core.basic.String;
import cybop.healthcare.model.heading.*;
import cybop.healthcare.model.unit.*;

/**
 * This class represents a plan problem heading.<br><br>
 *
 * A plan problem heading is ...
 *
 * @version $Revision: 1.3 $ $Date: 2003-02-20 15:35:15 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class Plan extends ProblemHeading {

    /**
     *Gets the medicaments.
     * @return vector containing medicaments
     */
    public Object[] getMedication() {

        Object[] childrenArray = getChildren().values().toArray();
        java.util.Vector tempVector = new java.util.Vector();

        for (int i = 0; i < childrenArray.length; i++) {

            if (childrenArray[i].getClass().equals(Medication.class)) {

                tempVector.add(childrenArray[i]);
            }
        }

        return tempVector.toArray();
    }

    /**
     *Tests whether this problem has episodes.
     * @return true if the problem has episodes, false if not
     */
    public boolean hasMedication() {
        Object[] childrenArray = getChildren().values().toArray();
        for (int i = 0; i < childrenArray.length; i++) {
            if (childrenArray[i].getClass().equals(Medication.class)) {
                return true;
            }
        }
        return false;
    }

    public int getMedicationCount() {
        Object[] childrenArray = getChildren().values().toArray();
        int count = 0;
        for (int i = 0; i < childrenArray.length; i++) {
            if (childrenArray[i].getClass().equals(Medication.class)) {
                count++;
            }
        }

        return count;
    }
}

