/*
 * $RCSfile: StatusBar.java,v $
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

package cybop.core.screen.region;

import cybop.core.model.*;
import cybop.core.screen.*;

/**
 * This class represents a status bar.
 *
 * @version $Revision: 1.2 $ $Date: 2003-05-23 11:57:29 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class StatusBar extends ScreenRegion {

    //
    // Encapsulated java swing label.
    //
    
    /**
     * Creates an encapsulated java swing label.
     *
     * @return the encapsulated java swing label
     */
    public java.lang.Object createJavaObject() throws Exception {
        
        return new javax.swing.JLabel();
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

