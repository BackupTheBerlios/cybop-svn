/*
 * $RCSfile: Unit.java,v $
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

package cybop.model;

import cybop.basic.*;

/**
 * This class represents a unit.<br><br>
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
 * A unit corresponds to a chapter.
 * Also graphical view components that can contain other components are units.
 *
 * The OpenEHR specification describes unit as:<br>
 * "Unit of information capture, committal, review, modification and
 * communication (Unit of Work)."
 *
 * @version $Revision: 1.1 $ $Date: 2003-02-19 07:46:09 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 * @see http://www.openehr.org http://www.gehr.org
 */
public class Unit extends cybop.system.Component {

    //?? Only temporary inheritance from Component!
    //?? The gui components need a signal handler which is set in the
    //?? globalize method of Component.
    //?? Remove this inheritance (replace with Item parent class),
    //?? as soon as no signal handler has to be forwarded anymore
    //?? (when CYBOP provides mouse/keyboard input handling itselfs.
}

