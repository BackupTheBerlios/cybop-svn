/*
 * $RCSfile: BloodPressure.java,v $
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

package cybop.healthcare.model.description;

import cybop.core.model.String;
import cybop.healthcare.model.*;

/**
 * This class represents a blood pressure.<br><br>
 *
 * A blood pressure is the combination of a systolic and a diastolic value.
 *
 * @version $Revision: 1.7 $ $Date: 2003-06-12 21:16:11 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class BloodPressure extends Description {

    //
    // Children names.
    //
    
    /** The systole. */
    public static final String SYSTOLE = new String("systole");

    /** The diastole. */
    public static final String DIASTOLE = new String("diastole");

    //
    // Default children.
    //

    /**
     * Returns the default systole.
     *
     * @return the default systole
     */
    public String getDefaultSystole() {

        return null;
    }

    /**
     * Returns the default diastole.
     *
     * @return the default diastole
     */
    public String getDefaultDiastole() {

        return null;
    }

    //
    // Initialization.
    //

    /**
     * Initializes this blood pressure.
     */
    public void initialize() throws Exception {

        super.initialize();

        setChild(BloodPressure.SYSTOLE, getDefaultSystole());
        setChild(BloodPressure.DIASTOLE, getDefaultDiastole());
    }

    /**
     * Finalizes this blood pressure.
     */
    public void finalizz() throws Exception {

        removeChild(BloodPressure.DIASTOLE);
        removeChild(BloodPressure.SYSTOLE);

        super.finalizz();
    }
}

