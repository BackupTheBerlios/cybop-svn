/*
 * $RCSfile: Layout.java,v $
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
 * This class represents a layout.
 *
 * It specifies the form in which components of a region are ordered.
 *
 * @version $Revision: 1.2 $ $Date: 2003-02-19 17:15:17 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class Layout extends Organizer {

    //
    // Encapsulated java awt layout manager.
    //
    
    /**
     * Creates an encapsulated java awt layout manager.
     *
     * @return the encapsulated java awt layout manager
     */
    public java.lang.Object createJavaObject() throws NullPointerException {

        return new java.awt.BorderLayout();
    }
}

