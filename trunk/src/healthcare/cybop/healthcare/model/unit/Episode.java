/*
 * $RCSfile: Episode.java,v $
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
import java.util.Vector;

/**
 * This class represents an episode.<br><br> An episode is a time extract of a certain problem/illness.
 * It consists of at least one or many partial contacts.
 * @version $Revision: 1.1 $ $Date: 2003-02-18 14:47:46 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 * @author Jens Bohl <jens.bohl@stud.tu-ilmenau.de>
 * @author Torsten Kunze <zone3@gmx.de>
 */
public class Episode extends Unit {

    private org.resmedicinae.resmedlib.term.String timestamp;

    /**
     *Converts the object to String. This is needed because of the tree table. The tree table nodes are named as
     * the object their represents. So the node will be called like the object.
     */
    public String toString() {
        return "Episode";
    }

    public org.resmedicinae.resmedlib.term.String getTimestamp() {
        return timestamp;
    }

    public void setTimestamp(org.resmedicinae.resmedlib.term.String timestamp) {
        this.timestamp = timestamp;
    }

    public int getPartialContactCount() {
        Object[] childrenArray = getChildren().values().toArray();
        int count = 0;
        for (int i = 0; i < childrenArray.length; i++) {
            if (childrenArray[i].getClass().equals(PartialContact.class)) {
                count++;
            }
        }
        return count;
    }

    public boolean hasPartialContacts() {
        Object[] childrenArray = getChildren().values().toArray();
        for (int i = 0; i < childrenArray.length; i++) {
            if (childrenArray[i].getClass().equals(PartialContact.class)) {
                return true;
            }
        }
        return false;
    }

    public Object[] getPartialContacts() {
        Object[] childrenArray = getChildren().values().toArray();
        Vector tempVector = new Vector();
        for (int i = 0; i < childrenArray.length; i++) {
            if (childrenArray[i].getClass().equals(PartialContact.class)) {
                tempVector.add(childrenArray[i]);
            }
        }
        return tempVector.toArray();
    }

    public PartialContact getLastPartialContact() {
        if (hasPartialContacts()) {
            return (PartialContact)getPartialContacts() [getPartialContactCount() - 1];
        }
        return null;
    }

    public PartialContact getFirstPartialContact() {
        if (hasPartialContacts()) {
            return (PartialContact)getPartialContacts() [0];
        }
        return null;
    }

}
