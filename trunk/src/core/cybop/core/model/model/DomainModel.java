/*
 * $RCSfile: DomainModel.java,v $
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
import cybop.core.model.unit.*;
import cybop.core.system.chain.*;

/**
 * This class represents a domain model.
 *
 * @version $Revision: 1.5 $ $Date: 2003-04-24 15:58:46 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 * @author Torsten Kunze <zone3@gmx.de>
 */
public class DomainModel extends Model {

    //
    // Children names.
    //

    /** The system information. */
    public static final String SYSTEM_INFORMATION = new String("system_information");

    //
    // Default children.
    //

    /**
     * Returns the default system information.
     *
     * @return the default system information
     */
    public String getDefaultSystemInformation() {

        return new String("cybop.core.model.unit.SystemInformation");
    }

    //
    // Initialization.
    //

    /**
     * Initializes this domain model.
     *
     * @exception NullPointerException if the configuration is null
     */
    public void initialize() throws Exception, NullPointerException {

        super.initialize();

        Configuration c = (Configuration) getChildItem(DomainModel.CONFIGURATION);

        if (c != null) {

            setChildItem(DomainModel.SYSTEM_INFORMATION, createComponent(getDefaultSystemInformation()));

        } else {

            throw new NullPointerException("Could not initialize domain model. The configuration is null.");
        }
    }

    /**
     * Finalizes this domain model.
     *
     * @exception NullPointerException if the configuration is null
     */
    public void finalizz() throws Exception, NullPointerException {

        Configuration c = (Configuration) getChildItem(DomainModel.CONFIGURATION);

        if (c != null) {

            SystemInformation systemInformation = (SystemInformation) getChildItem(DomainModel.SYSTEM_INFORMATION);
            removeChildItem(DomainModel.SYSTEM_INFORMATION);
            destroyComponent(systemInformation);

        } else {

            throw new NullPointerException("Could not finalize domain model. The configuration is null.");
        }

        super.finalizz();
    }
}

