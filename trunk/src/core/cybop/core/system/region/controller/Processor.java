/*
 * $RCSfile: Processor.java,v $
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
 * http://www.resmedicinae.org
 * - Information in Medicine -
 */

package cybop.core.system.region.controller;

import cybop.core.basic.Boolean;
import cybop.core.basic.String;
import cybop.core.model.model.*;
import cybop.core.system.region.*;

/**
 * This class represents a processor.
 *
 * A processor corresponds to the region in a human brain which is
 * responsible for actually processing signals.<br><br>
 * [German: "Groszhirnrinde"]
 *
 * A processor can be called by sensors if special processings have to be done.
 * Such processings can be algorithms, fuzzy logic or even neural network
 * calculations.
 * The processor is then responsible for forwarding the signal and results
 * to a motor.
 *
 * @version $Revision: 1.2 $ $Date: 2003-02-19 17:15:17 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class Processor extends ControllerRegion {

    //
    // Initialization.
    //

    /**
     * Initializes this processor.
     */
    public void initialize() throws Exception, NullPointerException {

        super.initialize();
    }

    /**
     * Finalizes this processor.
     */
    public void finalizz() throws Exception, NullPointerException {

        super.finalizz();
    }

    //
    // Processing.
    //

    /**
     * Processes the action, possibly working on the domain model.
     *
     * @param a the action
     * @param m the domain model
     * @exception NullPointerException if the action is null
     */
    public void process(String a, DomainModel m) throws Exception, NullPointerException {

        if (a != null) {

        } else {

            throw new NullPointerException("Could not process action. The action is null.");
        }
    }
}

