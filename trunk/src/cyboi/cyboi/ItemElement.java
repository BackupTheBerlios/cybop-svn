/*
 * $RCSfile: ItemElement.java,v $
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

package cyboi;

/**
 * This is an item element.<br><br>
 *
 * An item element represents an item node in an XML-based
 * <i>Cybernetics Oriented Language</i> (CYBOL) file.
 *
 * @version $Revision: 1.4 $ $Date: 2003-07-23 20:10:54 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
class ItemElement extends Element {

    //
    // Constants.
    //
    
    /** The name constant. */
    static java.lang.String NAME = "name";

    /** The item abstraction constant. */
    static java.lang.String ITEM_ABSTRACTION = "item_abstraction";

    /** The item category constant. */
    static java.lang.String ITEM_CATEGORY = "item_category";

    /** The space abstraction constant. */
    static java.lang.String SPACE_ABSTRACTION = "space_abstraction";

    /** The space category constant. */
    static java.lang.String SPACE_CATEGORY = "space_category";

    /** The time abstraction constant. */
    static java.lang.String TIME_ABSTRACTION = "time_abstraction";

    /** The time category constant. */
    static java.lang.String TIME_CATEGORY = "time_category";

    //
    // Elements.
    //
    
    /** The name element. */
    static java.lang.Object name;

    /** The abstraction element. */
    static java.lang.Object abstraction;

    /** The category element. */
    static java.lang.Object category;

    /** The position element. */
    static java.lang.Object position;
}

