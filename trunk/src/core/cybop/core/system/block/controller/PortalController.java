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

import cybop.core.basic.*;
import cybop.core.basic.String;
import cybop.core.system.block.*;
import cybop.core.system.region.controller.*;
import cybop.core.system.region.controller.processor.*;
import cybop.core.system.region.controller.translator.*;

/**
 * This class represents a portal controller.
 *
 * @version $Revision: 1.3 $ $Date: 2003-02-20 15:35:14 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class PortalController extends Controller {

    //
    // Default children.
    //

    /**
     * Returns the default portal processor.
     *
     * @return the default portal processor
     */
    public String getDefaultProcessor() {

        return new String("cybop.core.system.region.controller.processor.PortalProcessor");
    }

    /**
     * Returns the default domain model.
     *
     * @return the default domain model
     */
    public String getDefaultDomainModel() {

        return new String("cybop.core.model.model.DomainModel");
    }

    /**
     * Returns the default system user interface.
     *
     * @return the default system user interface
     */
    public String getDefaultSystemUserInterface() {

        return new String("cybop.core.model.model.user.system.PortalUserInterface");
    }

    /**
     * Returns the default system information user interface.
     *
     * @return the default system information user interface
     */
    public String getDefaultSystemInformationUserInterface() {

        return new String("cybop.core.model.model.user.SystemInformationUserInterface");
    }

    /**
     * Returns the default system information user interface translator.
     *
     * @return the default system information user interface translator
     */
    public String getDefaultSystemInformationUserInterfaceTranslator() {

        return new String("cybop.core.system.region.controller.translator.SystemInformationUserInterfaceTranslator");
    }
}

