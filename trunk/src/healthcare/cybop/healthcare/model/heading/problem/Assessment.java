/*
 * $RCSfile: Assessment.java,v $
 *
 * Copyright (c) 1999-2002. The Res Medicinae developers. All rights reserved.
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

package org.resmedicinae.domain.healthcare.heading.problem;

import org.resmedicinae.domain.healthcare.heading.*;
import org.resmedicinae.domain.healthcare.unit.PartialContact;

/**
 * This class represents an assessment problem heading.<br><br> An assessment problem heading is ...
 * @version $Revision: 1.1 $ $Date: 2003-02-18 14:47:46 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class Assessment extends ProblemHeading {
    /** The text of the object. */
    private org.resmedicinae.resmedlib.term.String text;
    //?? Insert attributes here!
    //?? Don't forget "create", "destroy", "set" and "get" methods!

    /**
     *The constructor.
     * @param text the text the assessment contains
     */
    public Assessment(String text) {
        setText(new org.resmedicinae.resmedlib.term.String(text));
    }

    /**
     *Converts the object to String. This is needed because of the tree table. The tree table nodes are named as
     * the object their represents. So the node will be called like the object.
     * @return object converted to String
     */
    public String toString() {
        return "Assessment ";
    }

    /**
     *Gets the text of the object
     * @return the text of the object
     */
    public org.resmedicinae.resmedlib.term.String getText() {
        return this.text;
    }

    /**
     *Sets the text of the object
     *@param text the text of the object
     */
    public void setText(org.resmedicinae.resmedlib.term.String text) {
        this.text = text;
    }
}
