/*
 * $RCSfile: Cave.java,v $
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
 * This class represents a cave.<br><br>
 *
 * A CAVE entry is an important reminder for doctors, indicating
 * allergies, medication, special problems a patient may have.
 *
 * @version $Revision: 1.4 $ $Date: 2003-03-12 18:12:20 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class Cave extends Description {

    //
    // Children names.
    //

    /** The name. */
    public static final String NAME = new String("name");

    /** The description. */
    public static final String DESCRIPTION = new String("description");

    //
    // Default children.
    //

    /**
     * Returns the default name.
     *
     * @return the default name
     */
    public String getDefaultName() {

        return new String("Empty");
    }

    /**
     * Returns the default description.
     *
     * @return the default description
     */
    public String getDefaultDescription() {

        return null;
    }

    //
    // Initialization.
    //

    /**
     * Initializes this cave.
     */
    public void initialize() throws Exception {

        super.initialize();

        set(Cave.NAME, getDefaultName());
        set(Cave.DESCRIPTION, getDefaultDescription());
    }

    /**
     * Finalizes this cave.
     */
    public void finalizz() throws Exception {

        remove(Cave.DESCRIPTION);
        remove(Cave.NAME);

        super.finalizz();
    }
}

