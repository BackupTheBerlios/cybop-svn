/*
 * $RCSfile: KnowledgeModel.java,v $
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

package cybop.core.knowledge;

import cybop.core.model.*;
import cybop.core.model.String;

/**
 * This class represents a knowledge model.
 *
 * It is able to store general knowledge, that is hierarchical information.
 *
 * @version $Revision: 1.3 $ $Date: 2003-06-12 21:16:11 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 * @author Torsten Kunze <zone3@gmx.de>
 */
public class KnowledgeModel extends KnowledgeItem {

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
     * @exception Exception if the configuration is null
     */
    public void initialize() throws Exception {

        super.initialize();

        Configuration c = (Configuration) getChild(KnowledgeModel.CONFIGURATION);

        if (c != null) {

            setChild(KnowledgeModel.SYSTEM_INFORMATION, createChild(getDefaultSystemInformation()));

        } else {

            throw new Exception("Could not initialize domain model. The configuration is null.");
        }
    }

    /**
     * Finalizes this domain model.
     *
     * @exception Exception if the configuration is null
     */
    public void finalizz() throws Exception {

        Configuration c = (Configuration) getChild(KnowledgeModel.CONFIGURATION);

        if (c != null) {

            SystemInformation systemInformation = (SystemInformation) getChild(KnowledgeModel.SYSTEM_INFORMATION);
            removeChild(KnowledgeModel.SYSTEM_INFORMATION);
            destroyChild(systemInformation);

        } else {

            throw new Exception("Could not finalize domain model. The configuration is null.");
        }

        super.finalizz();
    }
}
