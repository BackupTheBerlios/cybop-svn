/*
 * $RCSfile: Label.java,v $
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
 * http://www.resmedicinae.org
 * - Information in Medicine -
 */

package cybop.core.model.organizer;

import cybop.core.basic.*;
import cybop.core.basic.Integer;
import cybop.core.basic.String;
import cybop.core.model.*;

/**
 * This class represents a label.
 *
 * @version $Revision: 1.2 $ $Date: 2003-02-19 17:15:17 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class Label extends Organizer {

    //
    // Children.
    //

    /** The font. */
    public static final String FONT = new String("font");

    /** The text. */
    public static final String TEXT = new String("text");

    /** The horizontal text position. */
    public static final String HORIZONTAL_TEXT_POSITION = new String("horizontal_text_position");

    /** The vertical text position. */
    public static final String VERTICAL_TEXT_POSITION = new String("vertical_text_position");

    //
    // Encapsulated java swing label.
    //

    /**
     * Creates the encapsulated java swing label.
     *
     * @return the encapsulated java swing label
     * @exception NullPointerException if the java swing label is null
     */
    public java.lang.Object createJavaObject() throws NullPointerException {

        javax.swing.JLabel l = new javax.swing.JLabel();

        if (l != null) {
            
            l.setBorder(javax.swing.BorderFactory.createEmptyBorder(10, 10, 10, 10));

        } else {

            throw new NullPointerException("Could not create java swing label. The java swing label is null.");
        }

        return l;
    }

    /**
     * Destroys the encapsulated java swing label.
     *
     * @param o the encapsulated java swing label
     */
    public void destroyJavaObject(java.lang.Object o) {

        javax.swing.JLabel l = (javax.swing.JLabel) o;

        if (l != null) {
            
            l.setBorder(null);

        } else {

            throw new NullPointerException("Could not destroy java swing label. The java swing label is null.");
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

            if (n.isEqualTo(Label.FONT)) {

                setFont((Font) i);

            } else if (n.isEqualTo(Label.TEXT)) {

                setText((String) i);
            
            } else if (n.isEqualTo(Label.HORIZONTAL_TEXT_POSITION)) {

                setHorizontalTextPosition((Integer) i);
            
            } else if (n.isEqualTo(Label.VERTICAL_TEXT_POSITION)) {

                setVerticalTextPosition((Integer) i);
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

            if (n.isEqualTo(Label.FONT)) {

                removeFont((Font) get(n));

            } else if (n.isEqualTo(Label.TEXT)) {

                removeText((String) get(n));

            } else if (n.isEqualTo(Label.HORIZONTAL_TEXT_POSITION)) {

                removeHorizontalTextPosition((Integer) get(n));
            
            } else if (n.isEqualTo(Label.VERTICAL_TEXT_POSITION)) {

                removeVerticalTextPosition((Integer) get(n));
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
     * Returns the default font.
     *
     * @return the default font
     */
    public String getDefaultFont() {

        return new String("cybop.core.model.organizer.Font");
    }

    /**
     * Returns the default text.
     *
     * @return the default text
     */
    public String getDefaultText() {

        return new String("Label");
    }

    /**
     * Returns the default horizontal text position.
     *
     * @return the default horizontal text position
     */
    public Integer getDefaultHorizontalTextPosition() {

        return new Integer(javax.swing.SwingConstants.CENTER);
    }

    /**
     * Returns the default vertical text position.
     *
     * @return the default vertical text position
     */
    public Integer getDefaultVerticalTextPosition() {

        return new Integer(javax.swing.SwingConstants.CENTER);
    }

    //
    // Font.
    //

    /**
     * Sets the font.
     *
     * @param f the font
     * @exception NullPointerException if the java label is null
     * @exception NullPointerException if the font is null
     */
    public void setFont(Font f) throws NullPointerException {

        javax.swing.JLabel l = (javax.swing.JLabel) getJavaObject();

        if (l != null) {

            if (f != null) {

                l.setFont((java.awt.Font) f.getJavaObject());

            } else {

                java.lang.System.out.println("DEBUG: Could not set font. The font is null.");
            }

        } else {

            throw new NullPointerException("Could not set font. The java label is null.");
        }
    }

    /**
     * Removes the font.
     *
     * @param f the font
     * @exception NullPointerException if the java label is null
     * @exception NullPointerException if the font is null
     */
    public void removeFont(Font f) throws NullPointerException {

        javax.swing.JLabel l = (javax.swing.JLabel) getJavaObject();

        if (l != null) {

            if (f != null) {

                l.setFont(null);

            } else {

                java.lang.System.out.println("DEBUG: Could not remove font. The font is null.");
            }

        } else {

            throw new NullPointerException("Could not remove font. The java label is null.");
        }
    }

    //
    // Text.
    //

    /**
     * Sets the text.
     *
     * @param t the text
     * @exception NullPointerException if the java label is null
     * @exception NullPointerException if the text is null
     */
    public void setText(String t) throws NullPointerException {

        javax.swing.JLabel l = (javax.swing.JLabel) getJavaObject();

        if (l != null) {

            if (t != null) {

                l.setText((java.lang.String) t.getJavaObject());

            } else {

                java.lang.System.out.println("DEBUG: Could not set text. The text is null.");
            }

        } else {

            throw new NullPointerException("Could not set text. The java label is null.");
        }
    }

    /**
     * Removes the text.
     *
     * @param t the text
     * @exception NullPointerException if the java label is null
     * @exception NullPointerException if the text is null
     */
    public void removeText(String t) throws NullPointerException {

        javax.swing.JLabel l = (javax.swing.JLabel) getJavaObject();

        if (l != null) {

            if (t != null) {

                l.setText(null);

            } else {

                java.lang.System.out.println("DEBUG: Could not remove text. The text is null.");
            }

        } else {

            throw new NullPointerException("Could not remove text. The java label is null.");
        }
    }

    //
    // Horizontal text position.
    //

    /**
     * Sets the horizontal text position.
     *
     * @param a the horizontal text position
     * @exception NullPointerException if the java label is null
     * @exception NullPointerException if the horizontal text position is null
     */
    public void setHorizontalTextPosition(Integer a) throws NullPointerException {

        javax.swing.JLabel l = (javax.swing.JLabel) getJavaObject();

        if (l != null) {

            if (a != null) {

                l.setHorizontalTextPosition(a.getJavaPrimitive());

            } else {

                java.lang.System.out.println("DEBUG: Could not set horizontal text position. The horizontal text position is null.");
            }

        } else {

            throw new NullPointerException("Could not set horizontal text position. The java label is null.");
        }
    }

    /**
     * Removes the horizontal text position.
     *
     * @param a the horizontal text position
     * @exception NullPointerException if the java label is null
     * @exception NullPointerException if the horizontal text position is null
     */
    public void removeHorizontalTextPosition(Integer a) throws NullPointerException {

        javax.swing.JLabel l = (javax.swing.JLabel) getJavaObject();

        if (l != null) {

            if (a != null) {

                l.setHorizontalTextPosition(javax.swing.SwingConstants.CENTER);

            } else {

                java.lang.System.out.println("DEBUG: Could not remove horizontal text position. The horizontal text position is null.");
            }

        } else {

            throw new NullPointerException("Could not remove horizontal text position. The java label is null.");
        }
    }

    //
    // Vertical text position.
    //

    /**
     * Sets the vertical text position.
     *
     * @param a the vertical text position
     * @exception NullPointerException if the java label is null
     * @exception NullPointerException if the vertical text position is null
     */
    public void setVerticalTextPosition(Integer a) throws NullPointerException {

        javax.swing.JLabel l = (javax.swing.JLabel) getJavaObject();

        if (l != null) {

            if (a != null) {

                l.setVerticalTextPosition(a.getJavaPrimitive());

            } else {

                java.lang.System.out.println("DEBUG: Could not set vertical text position. The vertical text position is null.");
            }

        } else {

            throw new NullPointerException("Could not set vertical text position. The java label is null.");
        }
    }

    /**
     * Removes the vertical text position.
     *
     * @param a the vertical text position
     * @exception NullPointerException if the java label is null
     * @exception NullPointerException if the vertical text position is null
     */
    public void removeVerticalTextPosition(Integer a) throws NullPointerException {

        javax.swing.JLabel l = (javax.swing.JLabel) getJavaObject();

        if (l != null) {

            if (a != null) {

                l.setVerticalTextPosition(javax.swing.SwingConstants.CENTER);

            } else {

                java.lang.System.out.println("DEBUG: Could not remove vertical text position. The vertical text position is null.");
            }

        } else {

            throw new NullPointerException("Could not remove vertical text position. The java label is null.");
        }
    }

    //
    // Initializable.
    //

    /**
     * Initializes this label.
     */
    public void initialize() throws Exception {

        super.initialize();

        set(Label.FONT, createComponent(getDefaultFont()));
        set(Label.TEXT, getDefaultText());
        set(Label.HORIZONTAL_TEXT_POSITION, getDefaultHorizontalTextPosition());
        set(Label.VERTICAL_TEXT_POSITION, getDefaultVerticalTextPosition());
    }

    /**
     * Finalizes this label.
     */
    public void finalizz() throws Exception {

        Integer verticalTextPosition = (Integer) get(Label.VERTICAL_TEXT_POSITION);
        remove(Label.VERTICAL_TEXT_POSITION);
        destroyItem(verticalTextPosition);

        Integer horizontalTextPosition = (Integer) get(Label.HORIZONTAL_TEXT_POSITION);
        remove(Label.HORIZONTAL_TEXT_POSITION);
        destroyItem(horizontalTextPosition);

        String text = (String) get(Label.TEXT);
        remove(Label.TEXT);
        destroyItem(text);

        Font font = (Font) get(Label.FONT);
        remove(Label.FONT);
        destroyComponent(font);

        super.finalizz();
    }
}

