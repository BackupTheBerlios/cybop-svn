/*
 * $RCSfile: PortalController.java,v $
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
import cybop.core.model.String;
import cybop.core.system.block.*;
import cybop.core.system.region.controller.*;
import cybop.core.system.region.controller.processor.*;
import cybop.core.system.region.controller.translator.*;

/**
 * This class represents a portal controller.
 *
 * @version $Revision: 1.9 $ $Date: 2003-06-17 08:21:03 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class PortalController extends Controller {

    //
    // Default children categories.
    //

    /**
     * Returns the default portal processor category.
     *
     * @return the default portal processor category
     */
    public Item getDefaultProcessorCategory() {

        return new String("cybop.core.system.region.controller.processor.PortalProcessor");
    }

    /**
     * Returns the default domain model category.
     *
     * @return the default domain model category
     */
    public Item getDefaultKnowledgeModelCategory() {

        return new String("cybop.core.model.model.KnowledgeModel");
    }

    /**
     * Returns the default system user interface category.
     *
     * @return the default system user interface category
     */
    public Item getDefaultDisplayCategory() {

        return new String("cybop.core.model.model.user.system.PortalUserInterface");
    }

    /**
     * Returns the default mouse model category.
     *
     * @return the default mouse model category
     */
    public Item getDefaultMouseModelCategory() {

        return new String("cybop.core.model.model.MouseModel");
    }

    /**
     * Returns the default system information user interface category.
     *
     * @return the default system information user interface category
     */
    public Item getDefaultSystemInformationUserInterfaceCategory() {

        return new String("cybop.core.model.model.user.SystemInformationUserInterface");
    }

    /**
     * Returns the default system information user interface translator category.
     *
     * @return the default system information user interface translator category
     */
    public Item getDefaultSystemInformationUserInterfaceTranslatorCategory() {

        return new String("cybop.core.system.region.controller.translator.SystemInformationUserInterfaceTranslator");
    }
}

