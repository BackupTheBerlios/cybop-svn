/*
 * $RCSfile: Plan.java,v $
 *
 * Copyright (c) 1999-2002. The Res Medicinae developers. All rights reserved.
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

package org.resmedicinae.domain.healthcare.heading.problem;

import org.resmedicinae.domain.healthcare.heading.*;
import org.resmedicinae.domain.healthcare.unit.Medication;
import java.util.Vector;

/**
 * This class represents a plan problem heading.<br><br> A plan problem heading is ...
 * @version $Revision: 1.1 $ $Date: 2003-02-18 14:47:46 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class Plan extends ProblemHeading {
    //?? Insert attributes here!
    //?? Don't forget "create", "destroy", "set" and "get" methods!

    /** The text of the object. */
    private org.resmedicinae.resmedlib.term.String text;

    /**
     *The constructor.
     * @param text the text the plan contains
     */
    public Plan(String text) {
        setText(new org.resmedicinae.resmedlib.term.String(text));
    }

    /**
     *Converts the object to String. This is needed because of the tree table. The tree table nodes are named as
     * the object their represents. So the node will be called like the object.
     * @return object converted to String
     */
    public String toString() {
        return "Plan";
    }

    /**
     *Gets the text of the object
     * @return the text of the object
     */
    public org.resmedicinae.resmedlib.term.String getText() {
        return this.text;
    }

    /**
     *Sets the text of the object
     *@param text the text of the object
     */
    public void setText(org.resmedicinae.resmedlib.term.String text) {
        this.text = text;
    }

    /**
     *Gets the medicaments.
     * @return vector containing medicaments
     */
    public Object[] getMedication() {
        Object[] childrenArray = getChildren().values().toArray();
        Vector tempVector = new Vector();
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
