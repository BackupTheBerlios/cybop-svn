/*
 * $RCSfile: Medication.java,v $
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

package org.resmedicinae.domain.healthcare.unit;

import org.resmedicinae.domain.healthcare.*;
import org.resmedicinae.domain.healthcare.description.Dose;
import java.util.Vector;

/**
 * This class represents a medication.<br><br> A medication is ...
 * @version $Revision: 1.1 $ $Date: 2003-02-18 14:47:46 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class Medication extends Unit {
    private org.resmedicinae.resmedlib.term.String name;

    public String toString() {
        return "Medication";
    }

    //?? Insert attributes here!
    //?? Don't forget "create", "destroy", "set" and "get" methods!
    public org.resmedicinae.resmedlib.term.String getName() {
        return name;
    }

    public void setName(org.resmedicinae.resmedlib.term.String name) {
        this.name = name;
    }

    public Object[] getDose() {
        Object[] childrenArray = getChildren().values().toArray();
        Vector tempVector = new Vector();
        for (int i = 0; i < childrenArray.length; i++) {
            if (childrenArray[i].getClass().equals(Dose.class)) {
                tempVector.add(childrenArray[i]);
            }
        }
        return tempVector.toArray();
    }
}
