/*
 * $RCSfile: ToolBar.java,v $
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

package cybop.core.model.organizer;

import cybop.core.model.*;

/**
 * This class represents a tool bar.
 *
 * @version $Revision: 1.2 $ $Date: 2003-02-19 17:15:17 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class ToolBar extends Organizer {

    //
    // Encapsulated java swing tool bar.
    //
    
    /**
     * Creates an encapsulated java swing tool bar.
     *
     * @return the encapsulated java swing tool bar
     */
    public java.lang.Object createJavaObject() throws NullPointerException {
        
        return new javax.swing.JToolBar();
    }

    //
    // Initializable.
    //

    /**
     * Initializes this tool bar.
     */
    public void initialize() throws Exception {

        super.initialize();
    }

    /**
     * Finalizes this tool bar.
     */
    public void finalizz() throws Exception {

        super.finalizz();
    }
}

