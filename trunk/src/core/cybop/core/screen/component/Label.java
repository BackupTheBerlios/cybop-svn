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
 * http://www.cybop.net
 * - Cybernetics Oriented Programming -
 */

package cybop.core.screen.component;

import cybop.core.category.*;
import cybop.core.model.*;
import cybop.core.model.Integer;
import cybop.core.model.String;
import cybop.core.screen.*;

/**
 * This class represents a label.
 *
 * @version $Revision: 1.5 $ $Date: 2003-06-17 08:21:03 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class Label extends DisplayComponent {

    //
    // Children names.
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
     * @exception Exception if the java swing label is null
     */
    public java.lang.Object createJavaObject() throws Exception {

        javax.swing.JLabel l = new javax.swing.JLabel();

        if (l != null) {
            
            l.setBorder(javax.swing.BorderFactory.createEmptyBorder(10, 10, 10, 10));

        } else {

            throw new Exception("Could not create java swing label. The java swing label is null.");
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

            throw new Exception("Could not destroy java swing label. The java swing label is null.");
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

            if (n.isEqualTo(Label.FONT)) {

                removeFont((Font) getChild(n));

            } else if (n.isEqualTo(Label.TEXT)) {

                removeText((String) getChild(n));

            } else if (n.isEqualTo(Label.HORIZONTAL_TEXT_POSITION)) {

                removeHorizontalTextPosition((Integer) getChild(n));
            
            } else if (n.isEqualTo(Label.VERTICAL_TEXT_POSITION)) {

                removeVerticalTextPosition((Integer) getChild(n));
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
     * @exception Exception if the java label is null
     * @exception Exception if the font is null
     */
    public void setFont(Font f) throws Exception {

        javax.swing.JLabel l = (javax.swing.JLabel) getJavaObject();

        if (l != null) {

            if (f != null) {

                l.setFont((java.awt.Font) f.getJavaObject());

            } else {

                java.lang.System.out.println("DEBUG: Could not set font. The font is null.");
            }

        } else {

            throw new Exception("Could not set font. The java label is null.");
        }
    }

    /**
     * Removes the font.
     *
     * @param f the font
     * @exception Exception if the java label is null
     * @exception Exception if the font is null
     */
    public void removeFont(Font f) throws Exception {

        javax.swing.JLabel l = (javax.swing.JLabel) getJavaObject();

        if (l != null) {

            if (f != null) {

                l.setFont(null);

            } else {

                java.lang.System.out.println("DEBUG: Could not remove font. The font is null.");
            }

        } else {

            throw new Exception("Could not remove font. The java label is null.");
        }
    }

    //
    // Text.
    //

    /**
     * Sets the text.
     *
     * @param t the text
     * @exception Exception if the java label is null
     * @exception Exception if the text is null
     */
    public void setText(String t) throws Exception {

        javax.swing.JLabel l = (javax.swing.JLabel) getJavaObject();

        if (l != null) {

            if (t != null) {

                l.setText((java.lang.String) t.getJavaObject());

            } else {

                java.lang.System.out.println("DEBUG: Could not set text. The text is null.");
            }

        } else {

            throw new Exception("Could not set text. The java label is null.");
        }
    }

    /**
     * Removes the text.
     *
     * @param t the text
     * @exception Exception if the java label is null
     * @exception Exception if the text is null
     */
    public void removeText(String t) throws Exception {

        javax.swing.JLabel l = (javax.swing.JLabel) getJavaObject();

        if (l != null) {

            if (t != null) {

                l.setText(null);

            } else {

                java.lang.System.out.println("DEBUG: Could not remove text. The text is null.");
            }

        } else {

            throw new Exception("Could not remove text. The java label is null.");
        }
    }

    //
    // Horizontal text position.
    //

    /**
     * Sets the horizontal text position.
     *
     * @param a the horizontal text position
     * @exception Exception if the java label is null
     * @exception Exception if the horizontal text position is null
     */
    public void setHorizontalTextPosition(Integer a) throws Exception {

        javax.swing.JLabel l = (javax.swing.JLabel) getJavaObject();

        if (l != null) {

            if (a != null) {

                l.setHorizontalTextPosition(a.getJavaPrimitive());

            } else {

                java.lang.System.out.println("DEBUG: Could not set horizontal text position. The horizontal text position is null.");
            }

        } else {

            throw new Exception("Could not set horizontal text position. The java label is null.");
        }
    }

    /**
     * Removes the horizontal text position.
     *
     * @param a the horizontal text position
     * @exception Exception if the java label is null
     * @exception Exception if the horizontal text position is null
     */
    public void removeHorizontalTextPosition(Integer a) throws Exception {

        javax.swing.JLabel l = (javax.swing.JLabel) getJavaObject();

        if (l != null) {

            if (a != null) {

                l.setHorizontalTextPosition(javax.swing.SwingConstants.CENTER);

            } else {

                java.lang.System.out.println("DEBUG: Could not remove horizontal text position. The horizontal text position is null.");
            }

        } else {

            throw new Exception("Could not remove horizontal text position. The java label is null.");
        }
    }

    //
    // Vertical text position.
    //

    /**
     * Sets the vertical text position.
     *
     * @param a the vertical text position
     * @exception Exception if the java label is null
     * @exception Exception if the vertical text position is null
     */
    public void setVerticalTextPosition(Integer a) throws Exception {

        javax.swing.JLabel l = (javax.swing.JLabel) getJavaObject();

        if (l != null) {

            if (a != null) {

                l.setVerticalTextPosition(a.getJavaPrimitive());

            } else {

                java.lang.System.out.println("DEBUG: Could not set vertical text position. The vertical text position is null.");
            }

        } else {

            throw new Exception("Could not set vertical text position. The java label is null.");
        }
    }

    /**
     * Removes the vertical text position.
     *
     * @param a the vertical text position
     * @exception Exception if the java label is null
     * @exception Exception if the vertical text position is null
     */
    public void removeVerticalTextPosition(Integer a) throws Exception {

        javax.swing.JLabel l = (javax.swing.JLabel) getJavaObject();

        if (l != null) {

            if (a != null) {

                l.setVerticalTextPosition(javax.swing.SwingConstants.CENTER);

            } else {

                java.lang.System.out.println("DEBUG: Could not remove vertical text position. The vertical text position is null.");
            }

        } else {

            throw new Exception("Could not remove vertical text position. The java label is null.");
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

        setChild(Label.FONT, createChild(getDefaultFont()));
        setChild(Label.TEXT, getDefaultText());
        setChild(Label.HORIZONTAL_TEXT_POSITION, getDefaultHorizontalTextPosition());
        setChild(Label.VERTICAL_TEXT_POSITION, getDefaultVerticalTextPosition());
    }

    /**
     * Finalizes this label.
     */
    public void finalizz() throws Exception {

        Integer verticalTextPosition = (Integer) getChild(Label.VERTICAL_TEXT_POSITION);
        removeChild(Label.VERTICAL_TEXT_POSITION);
        destroyChild(verticalTextPosition);

        Integer horizontalTextPosition = (Integer) getChild(Label.HORIZONTAL_TEXT_POSITION);
        removeChild(Label.HORIZONTAL_TEXT_POSITION);
        destroyChild(horizontalTextPosition);

        String text = (String) getChild(Label.TEXT);
        removeChild(Label.TEXT);
        destroyChild(text);

        Font font = (Font) getChild(Label.FONT);
        removeChild(Label.FONT);
        destroyChild(font);

        super.finalizz();
    }
}

