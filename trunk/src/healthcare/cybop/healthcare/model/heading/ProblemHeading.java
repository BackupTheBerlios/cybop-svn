/*
 * $RCSfile: ProblemHeading.java,v $
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

package cybop.healthcare.model.heading;

import cybop.core.model.String;
import cybop.healthcare.model.*;

/**
 * This class represents a problem heading.<br><br>
 *
 * A problem heading is ...
 *
 * @version $Revision: 1.7 $ $Date: 2003-06-12 21:16:11 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class ProblemHeading extends Heading {

    //
    // Children names.
    //
    
    /** The text. */
    public static final String TEXT = new String("text");

    //
    // Default children.
    //

    /**
     * Returns the default text.
     *
     * @return the default text
     */
    public String getDefaultText() {

        return new String("Empty");
    }

    //
    // Initialization.
    //

    /**
     * Initializes this problem heading.
     */
    public void initialize() throws Exception {

        super.initialize();

        setChild(ProblemHeading.TEXT, getDefaultText());
    }

    /**
     * Finalizes this problem heading.
     */
    public void finalizz() throws Exception {

        removeChild(ProblemHeading.TEXT);

        super.finalizz();
    }
}

