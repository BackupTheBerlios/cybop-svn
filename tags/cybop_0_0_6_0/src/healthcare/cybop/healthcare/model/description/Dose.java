/*
 * $RCSfile: Dose.java,v $
 *
 * Copyright (c) 1999-2002. Jens Bohl. All rights reserved.
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

import cybop.core.basic.String;
import cybop.healthcare.model.*;

/**
 * This class represents a dose.<br><br>
 *
 * @version $Revision: 1.5 $ $Date: 2003-04-24 15:58:47 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class Dose extends Description {
    
    //
    // Children names.
    //

    /** The value. */
    public static final String VALUE = new String("value");

    //
    // Default children.
    //

    /**
     * Returns the default value.
     *
     * @return the default value
     */
    public String getDefaultValue() {

        return null;
    }

    //
    // Initialization.
    //

    /**
     * Initializes this dose.
     */
    public void initialize() throws Exception {

        super.initialize();

        setChildItem(Dose.VALUE, getDefaultValue());
    }

    /**
     * Finalizes this dose.
     */
    public void finalizz() throws Exception {

        removeChildItem(Dose.VALUE);

        super.finalizz();
    }
}
