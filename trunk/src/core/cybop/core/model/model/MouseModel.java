/*
 * $RCSfile: MouseModel.java,v $
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

package cybop.core.model.model;

import cybop.core.basic.String;
import cybop.core.model.*;
import cybop.core.model.principle.*;
import cybop.core.model.unit.*;
import cybop.core.system.chain.*;

/**
 * This class represents a mouse model.
 *
 * It contains meta information about a mouse, its pointer and position etc.
 *
 * @version $Revision: 1.1 $ $Date: 2003-03-15 23:40:31 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class MouseModel extends Model {

    //
    // Children names.
    //

    /** The pointer position. */
    public static final String POINTER_POSITION = new String("pointer_position");

    //
    // Default children.
    //

    /**
     * Returns the default pointer position.
     *
     * @return the default pointer position
     */
    public String getDefaultPointerPosition() {

        return new String("cybop.core.model.principle.Space");
    }

    //
    // Initialization.
    //

    /**
     * Initializes this mouse model.
     */
    public void initialize() throws Exception {

        super.initialize();

        set(MouseModel.POINTER_POSITION, createItem(getDefaultPointerPosition()));
    }

    /**
     * Finalizes this mouse model.
     */
    public void finalizz() throws Exception {

        Space pointerPosition = (Space) get(MouseModel.POINTER_POSITION);
        remove(MouseModel.POINTER_POSITION);
        destroyItem(pointerPosition);

        super.finalizz();
    }
}

