/*
 * $RCSfile: TreeTable.java,v $
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

package cybop.core.screen.region;

/**
 * This class represents a composite tree/table component.
 *
 * It is an extension of <code>JTable</code> in which the first column
 * presents information in a hierarchical form analogous to <code>JTree</code>
 * (but not necessarily implemented as such).
 *
 * Idea of a tree table originally taken from the "Kiwi Toolkit" of Mark A. Lindner:
 * http://www.dystance.net/ping/kiwi/
 *
 * @version $Revision: 1.2 $ $Date: 2003-05-23 11:57:29 $ $Author: christian $
 * @author Mark A. Lindner <frenzy@ix.netcom.com> <mark_a_lindner@yahoo.com>
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class TreeTable extends Table {

    /**
     * Constructs this object.
     *
     * The component is created without a data model.
     * Use <code>setTreeModel()</code> to set the model.
     */
/*??
    public TreeTable() {

        setShowGrid(false);
        setIntercellSpacing(new Dimension(0, 0));
    }
*/
}

