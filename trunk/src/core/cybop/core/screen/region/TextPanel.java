/*
 * $RCSfile: TextPanel.java,v $
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

package cybop.core.model.organizer;

import cybop.core.model.*;
import cybop.core.model.String;
import cybop.core.model.*;

/**
 * This class represents a text panel.
 *
 * @version $Revision: 1.2 $ $Date: 2003-05-20 06:21:59 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class TextPanel extends Panel {

    //
    // Children names.
    //

    /** The text. */
    public static final String TEXT = new String("text");

    //
    // Encapsulated java swing panel.
    //

    /**
     * Creates the encapsulated java swing panel.
     *
     * @return the encapsulated java swing panel
     * @exception Exception if the java swing panel is null
     */
    public java.lang.Object createJavaObject() throws Exception {

        javax.swing.JLabel p = new javax.swing.JLabel();

        if (p != null) {
            
            p.setBorder(javax.swing.BorderFactory.createEmptyBorder(10, 10, 10, 10));

        } else {

            throw new Exception("Could not create java swing panel. The java swing panel is null.");
        }

        return p; 
    }

    /**
     * Destroys the encapsulated java swing panel.
     *
     * @param o the encapsulated java swing panel
     */
    public void destroyJavaObject(java.lang.Object o) {

        javax.swing.JLabel p = (javax.swing.JLabel) o;

        if (p != null) {
            
            p.setBorder(null);

        } else {

            throw new Exception("Could not destroy java swing panel. The java swing panel is null.");
        }
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
    public void setChildItem(String n, Item i) throws Exception {

        super.setChildItem(n, i);

        if (n != null) {

            if (n.isEqualTo(TextPanel.TEXT)) {

                setText((String) i);
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
    public void removeChildItem(String n) throws Exception {

        if (n != null) {

            if (n.isEqualTo(TextPanel.TEXT)) {

                removeText((String) getChildItem(n));
            }

        } else {

            throw new Exception("Could not remove item. The name is null.");
        }
        
        super.removeChildItem(n);
    }

    //
    // Default children.
    //

    /**
     * Returns the default text.
     *
     * @return the default text
     */
    public String getDefaultText() {

        return null;
    }

    //
    // Text.
    //

    /**
     * Sets the text.
     *
     * @param t the text
     * @exception Exception if the java panel is null
     * @exception Exception if the text is null
     */
    public void setText(String t) throws Exception {

        javax.swing.JLabel p = (javax.swing.JLabel) getJavaObject();

        if (p != null) {

            if (t != null) {

                p.setText((java.lang.String) t.getJavaObject());

            } else {

                java.lang.System.out.println("DEBUG: Could not set text. The text is null.");
            }

        } else {

            throw new Exception("Could not set text. The java panel is null.");
        }
    }

    /**
     * Removes the text.
     *
     * @param t the text
     * @exception Exception if the java panel is null
     * @exception Exception if the text is null
     */
    public void removeText(String t) throws Exception {

        javax.swing.JLabel p = (javax.swing.JLabel) getJavaObject();

        if (p != null) {

            if (t != null) {

                p.setText(null);

            } else {

                java.lang.System.out.println("DEBUG: Could not remove text. The text is null.");
            }

        } else {

            throw new Exception("Could not remove text. The java panel is null.");
        }
    }

    //
    // Initialization.
    //

    /**
     * Initializes this image panel.
     */
    public void initialize() throws Exception {

        super.initialize();

        setChildItem(TextPanel.TEXT, getDefaultText());
    }

    /**
     * Finalizes this image panel.
     */
    public void finalizz() throws Exception {

//??        TextPanel textPanel = (TextPanel) getChildItem(ImagePanel.TEXT);
        removeChildItem(TextPanel.TEXT);
//??        destroyChildItem(textPanel);

        super.finalizz();
    }
}

