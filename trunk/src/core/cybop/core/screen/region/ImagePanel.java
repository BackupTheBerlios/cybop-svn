/*
 * $RCSfile: ImagePanel.java,v $
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

/**
 * This class represents a logo panel.
 *
 * @version $Revision: 1.4 $ $Date: 2003-06-12 21:16:11 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class ImagePanel extends ScreenRegion {

    //
    // Children names.
    //

    /** The image. */
    public static final String IMAGE = new String("image");

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

        javax.swing.JPanel p = new javax.swing.JPanel();

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

        javax.swing.JPanel p = (javax.swing.JPanel) o;

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
    public void setChild(String n, Item i) throws Exception {

        super.setChild(n, i);

        if (n != null) {

            if (n.isEqualTo(ImagePanel.IMAGE)) {

                setImage((Image) i);
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

            if (n.isEqualTo(ImagePanel.IMAGE)) {

                removeImage((Image) getChild(n));
            }

        } else {

            throw new Exception("Could not remove item. The name is null.");
        }
        
        super.removeChild(n);
    }

    //
    // Default children.
    //

    /**
     * Returns the default image.
     *
     * @return the default image
     */
    public String getDefaultImage() {

        return null;
    }

    //
    // Image.
    //

    /**
     * Sets the image.
     *
     * @param i the image
     * @exception Exception if the java panel is null
     * @exception Exception if the image is null
     */
    public void setImage(Image i) throws Exception {

        javax.swing.JPanel p = (javax.swing.JPanel) getJavaObject();

        if (p != null) {

            if (i != null) {

//??                p.add((java.awt.image.BufferedImage) i.getJavaObject(), java.awt.BorderLayout.CENTER);

            } else {

                java.lang.System.out.println("DEBUG: Could not set image. The image is null.");
            }

        } else {

            throw new Exception("Could not set image. The java panel is null.");
        }
    }

    /**
     * Removes the image.
     *
     * @param i the image
     * @exception Exception if the java panel is null
     * @exception Exception if the image is null
     */
    public void removeImage(Image i) throws Exception {

        javax.swing.JPanel p = (javax.swing.JPanel) getJavaObject();

        if (p != null) {

            if (i != null) {

//??                p.removeChild((java.awt.image.BufferedImage) i.getJavaObject());

            } else {

                java.lang.System.out.println("DEBUG: Could not remove image. The image is null.");
            }

        } else {

            throw new Exception("Could not remove image. The java panel is null.");
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

        setChild(ImagePanel.IMAGE, createChild(getDefaultImage()));
    }

    /**
     * Finalizes this image panel.
     */
    public void finalizz() throws Exception {

        Image image = (Image) getChild(ImagePanel.IMAGE);
        removeChild(ImagePanel.IMAGE);
        destroyChild(image);

        super.finalizz();
    }
}

