/*
 * $RCSfile: Episode.java,v $
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
 * http://www.resmedicinae.org
 * - Information in Medicine -
 */

package cybop.healthcare.model.unit;

import cybop.core.basic.String;
import cybop.healthcare.model.*;

/**
 * This class represents an episode.<br><br>
 *
 * An episode is a time extract of a certain problem/illness.
 * It consists of at least one or many partial contacts.
 *
 * @version $Revision: 1.2 $ $Date: 2003-02-19 17:15:17 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 * @author Jens Bohl <jens.bohl@stud.tu-ilmenau.de>
 * @author Torsten Kunze <zone3@gmx.de>
 */
public class Episode extends Unit {
    
    //
    // Children.
    //

    /** The value. */
    public static final String VALUE = new String("value");

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
        java.util.Vector tempVector = new java.util.Vector();

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

