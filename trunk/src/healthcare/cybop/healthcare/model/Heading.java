/*
 * $RCSfile: Heading.java,v $
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

package org.resmedicinae.domain.healthcare;

import org.resmedicinae.resmedlib.*;

/**
 * This class represents a heading.<br><br>
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
 * A heading corresponds to a paragraph.
 *
 * The OpenEHR specification describes heading as:<br>
 * "Structural information concepts whose purpose is to organise information
 * according to norms of practice, in the same way as headings in a paper document."
 *
 * @version $Revision: 1.1 $ $Date: 2003-02-18 14:47:46 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 * @see http://www.openehr.org http://www.gehr.org
 */
public class Heading extends Item {
}

