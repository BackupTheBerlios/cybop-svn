/*
 * $RCSfile: Principle.java,v $
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

package cybop.healthcare.model;

import cybop.core.basic.*;

/**
 * This class represents a principle.<br><br>
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
 * A principle corresponds to a word.
 *
 * Principles are basic terms of healthcare. They are mostly specified
 * in a collection of words, called terminology.<br><br>
 *
 * The OpenEHR specification describes principles as:<br>
 * "Vocabulary and quantitative semantics of domain; facts true for all
 * instances and all use contexts"
 *
 * @version $Revision: 1.3 $ $Date: 2003-02-20 15:35:14 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 * @see http://www.openehr.org http://www.gehr.org
 */
public class Principle extends Item {
}
