/*
 * $RCSfile: Description.java,v $
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

package cybop.healthcare.model;

import cybop.core.basic.*;

/**
 * This class represents a description.<br><br>
 *
 * It is a super class and forms an own level in the framework's domain ontology:
 *  <ul>
 *      <li>HealthRecord</li>
 *      <li>Unit</li>
 *      <li>Heading</li>
 *      <li>Description</li>
 *      <li>Principle</li>
 *  </ul>
 *
 * A description corresponds to a sentence.
 *
 * The OpenEHR specification describes description as:<br>
 * "The smallest self-contained descriptions of distinct phenomena:
 * concepts which describe observation, analysis or prescription of
 * something in the real world."
 *
 * @version $Revision: 1.2 $ $Date: 2003-02-19 17:15:17 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 * @see http://www.openehr.org http://www.gehr.org
 */
public class Description extends Item {
}

