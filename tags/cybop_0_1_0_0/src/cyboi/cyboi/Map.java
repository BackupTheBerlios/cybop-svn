/*
 * $RCSfile: Map.java,v $
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
 * This is a map.
 *
 * A map is like a table. One column (array) contains the element names.
 * A second column (array) contains the actual element references.
 *
 * @version $Revision: 1.6 $ $Date: 2003-08-09 15:34:58 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
class Map {

    // Do not use static keyword!
    // If you do, the elements will always be overwritten
    // whenever some instance sets them.
    
    /** The names. */
    java.lang.Object[] names;

    /** The references. */
    java.lang.Object[] references;
}

