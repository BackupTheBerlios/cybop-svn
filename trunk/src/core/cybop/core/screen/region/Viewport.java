/*
 * $RCSfile: Viewport.java,v $
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

package cybop.core.model.organizer;

import cybop.core.basic.String;
import cybop.core.model.*;

/**
 * This class represents a viewport.
 *
 * @version $Revision: 1.1 $ $Date: 2003-05-18 17:58:15 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class Viewport extends Organizer {

    //
    // Static attribute ids.
    //

    /** The view id. */
    public static final String VIEW = new String("view");

    /** The origin id. */
    public static final String ORIGIN = new String("origin");

    //
    // Encapsulated java swing viewport.
    //

    /**
     * Creates an encapsulated java swing viewport.
     *
     * @return the encapsulated java swing viewport
     * @exception Exception if the encapsulated java swing viewport is null
     */
    public java.lang.Object createJavaObject() throws Exception {

        javax.swing.JViewport v = new javax.swing.JViewport();

        if (v != null) {

        } else {

            throw new Exception("Could not create encapsulated java swing viewport. The encapsulated java swing viewport is null.");
        }

        return v;
    }
}

