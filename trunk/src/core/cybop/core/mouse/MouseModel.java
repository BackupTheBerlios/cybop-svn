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

package cybop.core.mouse;

import cybop.core.category.*;
import cybop.core.model.*;
import cybop.core.model.String;

/**
 * This class represents a mouse model.
 *
 * It contains information about how to talk to a mouse, that is its pointer and
 * position etc.
 *
 * @version $Revision: 1.6 $ $Date: 2003-06-29 21:31:58 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class MouseModel extends Item {

    //
    // Children names.
    //

    /** The pointer position. */
    public static final String POINTER_POSITION = new String("pointer_position");

    //
    // Default categories.
    //

    /**
     * Returns the default pointer position category.
     *
     * @return the default pointer position category
     */
    public String getDefaultPointerPositionCategory() {

        return new String("cybop.core.model.Space");
    }

    //
    // Categorization.
    //

    /**
     * Categorizes this hierarchy.
     */
    public void categorize() throws Exception {

        super.categorize();

        setCategory(MouseModel.POINTER_POSITION, getDefaultPointerPositionCategory());
    }

    /**
     * Decategorizes this hierarchy.
     */
    public void decategorize() throws Exception {

        removeCategory(MouseModel.POINTER_POSITION);

        super.decategorize();
    }

    //
    // Initialization.
    //

    /**
     * Initializes this item.
     */
    public void initialize() throws Exception {

        super.initialize();

        setChild(MouseModel.POINTER_POSITION, createChild(getCategory(MouseModel.POINTER_POSITION)));
    }

    /**
     * Finalizes this item.
     */
    public void finalizz() throws Exception {

        Item pointerPosition = getChild(MouseModel.POINTER_POSITION);
        removeChild(MouseModel.POINTER_POSITION);
        destroyChild(pointerPosition);

        super.finalizz();
    }
}

