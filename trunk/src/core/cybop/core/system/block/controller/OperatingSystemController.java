/*
 * $RCSfile: OperatingSystemController.java,v $
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

package cybop.core.system.block.controller;

import cybop.core.category.*;
import cybop.core.model.*;
import cybop.core.model.Boolean;
import cybop.core.model.String;
import cybop.core.mouse.*;
import cybop.core.screen.*;
import cybop.core.screen.model.*;
import cybop.core.signal.*;
import cybop.core.system.block.*;

/**
 * This class represents an operating system controller.
 *
 * @version $Revision: 1.2 $ $Date: 2003-07-15 09:44:19 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class OperatingSystemController extends Controller {

    //
    // Default children categories.
    //

    /**
     * Returns the default system display category.
     *
     * @return the default system display category
     */
    public Item getDefaultSystemDisplayCategory() {

        return new String("cybop.core.screen.model.DesktopDisplay");
    }

    /**
     * Returns the default mouse model category.
     *
     * @return the default mouse model category
     */
    public Item getDefaultMouseModelCategory() {

        return new String("cybop.core.mouse.MouseModel");
    }
}

