/*
 * $RCSfile: ImagePanel.java,v $
 *
 * Copyright (c) 1999-2003. The Res Medicinae developers. All rights reserved.
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

package cybop.model.organizer;

import cybop.basic.*;
import cybop.basic.String;

/**
 * This class represents a logo panel.
 *
 * @version $Revision: 1.1 $ $Date: 2003-02-19 07:49:23 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class ImagePanel extends Panel {

    //
    // Children.
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
     * @exception NullPointerException if the java swing panel is null
     */
    public java.lang.Object createJavaObject() throws NullPointerException {

        javax.swing.JPanel p = new javax.swing.JPanel();

        if (p != null) {
            
            p.setBorder(javax.swing.BorderFactory.createEmptyBorder(10, 10, 10, 10));

        } else {

            throw new NullPointerException("Could not create java swing panel. The java swing panel is null.");
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

            throw new NullPointerException("Could not destroy java swing panel. The java swing panel is null.");
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
     * @exception NullPointerException if the name is null
     */
    public void set(String n, Item i) throws NullPointerException {

        super.set(n, i);

        if (n != null) {

            if (n.isEqualTo(ImagePanel.IMAGE)) {

                setImage((Image) i);
            }

        } else {

            throw new NullPointerException("Could not set item. The name is null.");
        }
    }

    /**
     * Removes the child item from this item.
     *
     * @param n the name
     * @exception NullPointerException if the name is null
     */
    public void remove(String n) throws NullPointerException {

        if (n != null) {

            if (n.isEqualTo(ImagePanel.IMAGE)) {

                removeImage((Image) get(n));
            }

        } else {

            throw new NullPointerException("Could not remove item. The name is null.");
        }
        
        super.remove(n);
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
     * @exception NullPointerException if the java panel is null
     * @exception NullPointerException if the image is null
     */
    public void setImage(Image i) throws NullPointerException {

        javax.swing.JPanel p = (javax.swing.JPanel) getJavaObject();

        if (p != null) {

            if (i != null) {

//??                p.add((java.awt.image.BufferedImage) i.getJavaObject(), java.awt.BorderLayout.CENTER);

            } else {

                java.lang.System.out.println("DEBUG: Could not set image. The image is null.");
            }

        } else {

            throw new NullPointerException("Could not set image. The java panel is null.");
        }
    }

    /**
     * Removes the image.
     *
     * @param i the image
     * @exception NullPointerException if the java panel is null
     * @exception NullPointerException if the image is null
     */
    public void removeImage(Image i) throws NullPointerException {

        javax.swing.JPanel p = (javax.swing.JPanel) getJavaObject();

        if (p != null) {

            if (i != null) {

//??                p.remove((java.awt.image.BufferedImage) i.getJavaObject());

            } else {

                java.lang.System.out.println("DEBUG: Could not remove image. The image is null.");
            }

        } else {

            throw new NullPointerException("Could not remove image. The java panel is null.");
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

        set(ImagePanel.IMAGE, createComponent(getDefaultImage()));
    }

    /**
     * Finalizes this image panel.
     */
    public void finalizz() throws Exception {

        Image image = (Image) get(ImagePanel.IMAGE);
        remove(ImagePanel.IMAGE);
        destroyComponent(image);

        super.finalizz();
    }
}

