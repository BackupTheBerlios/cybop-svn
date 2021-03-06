/*
 * $RCSfile: Panel.java,v $
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

import cybop.core.category.*;
import cybop.core.model.*;
import cybop.core.model.String;
import cybop.core.screen.*;
import cybop.core.screen.component.*;

/**
 * This class represents a screen region.
 *
 * @version $Revision: 1.2 $ $Date: 2003-06-20 13:44:24 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class Panel extends DisplayRegion {

    //
    // Children names.
    //

    /** The layout. */
    public static final String LAYOUT = new String("layout");

    //
    // Encapsulated java swing panel.
    //
    
    /**
     * Creates an encapsulated java swing panel.
     *
     * @return the encapsulated java swing panel
     */
    public java.lang.Object createJavaObject() throws Exception {
        
        return new javax.swing.JPanel();
    }

    //
    // Child management.
    //

    /**
     * Adds the item to become a child of this item.
     *
     * @param n the name
     * @param i the item
     * @exception Exception if the name is null
     */
    public void setChild(String n, Item i) throws Exception {

        super.setChild(n, i);

        if (n != null) {

            if (n.isEqualTo(Panel.LAYOUT)) {

                setLayout((Layout) i);
            }

        } else {

            throw new Exception("Could not set item. The name is null.");
        }
    }

    /**
     * Removes the child item from this item.
     *
     * @param n the name
     * @exception Exception if the name is null
     */
    public void removeChild(String n) throws Exception {

        if (n != null) {

            if (n.isEqualTo(Panel.LAYOUT)) {
                
                removeLayout((Layout) getChild(n));
            }

        } else {

            throw new Exception("Could not set item. The name is null.");
        }

        super.removeChild(n);
    }

    //
    // Default categories.
    //

    /**
     * Returns the default layout category.
     *
     * @return the default layout category
     */
    public Item getDefaultLayoutCategory() {

        return new String("cybop.core.screen.component.Layout");
    }

    //
    // Layout.
    //

    /**
     * Sets the layout.
     *
     * @param l the layout
     * @exception Exception if the java panel is null
     * @exception Exception if the layout is null
     */
    public void setLayout(Layout l) throws Exception {

        javax.swing.JPanel p = (javax.swing.JPanel) getJavaObject();

        if (p != null) {

            if (l != null) {

                p.setLayout((java.awt.LayoutManager) l.getJavaObject());

            } else {
    
                throw new Exception("Could not set layout. The layout is null.");
            }

        } else {

            throw new Exception("Could not set layout. The java panel is null.");
        }
    }

    /**
     * Removes the layout.
     *
     * @param l the layout
     * @exception Exception if the java panel is null
     * @exception Exception if the layout is null
     */
    public void removeLayout(Layout l) throws Exception {

        javax.swing.JPanel p = (javax.swing.JPanel) getJavaObject();

        if (p != null) {

            if (l != null) {

                p.setLayout(null);

            } else {

                throw new Exception("Could not remove layout. The layout is null.");
            }

        } else {

            throw new Exception("Could not remove layout. The java panel is null.");
        }
    }

    //
    // Categorization.
    //

    /**
     * Categorizes this hierarchy.
     */
    public void categorize() throws Exception {

        super.categorize();

        setCategory(Panel.LAYOUT, getDefaultLayoutCategory());
    }

    /**
     * Decategorizes this hierarchy.
     */
    public void decategorize() throws Exception {

        removeCategory(Panel.LAYOUT);

        super.decategorize();
    }

    //
    // Initialization.
    //

    /**
     * Initializes this item.
     */
    public void initialize() throws Exception {

        super.initialize();

        setChild(Panel.LAYOUT, createChild(getCategory(Panel.LAYOUT)));
    }

    /**
     * Finalizes this item.
     */
    public void finalizz() throws Exception {

        Item layout = getChild(Panel.LAYOUT);
        removeChild(Panel.LAYOUT);
        destroyChild(layout);

        super.finalizz();
    }
}

