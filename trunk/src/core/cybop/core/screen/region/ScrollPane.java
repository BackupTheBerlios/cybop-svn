/*
 * $RCSfile: ScrollPane.java,v $
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
 * This class represents a scroll pane.
 *
 * @version $Revision: 1.5 $ $Date: 2003-06-17 08:21:03 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class ScrollPane extends DisplayRegion {

    //
    // Static attribute ids.
    //

    /** The viewport id. */
    public static final String VIEWPORT = new String("viewport");

    /** The horizontal scroll bar id. */
    public static final String HORIZONTAL_SCROLL_BAR = new String("horizontal_scroll_bar");

    /** The vertical scroll bar id. */
    public static final String VERTICAL_SCROLL_BAR = new String("vertical_scroll_bar");

    /** The row header id. */
    public static final String ROW_HEADER = new String("row_header");

    /** The column header id. */
    public static final String COLUMN_HEADER = new String("column_header");

    /** The left top corner id. */
    public static final String LEFT_TOP_CORNER = new String("left_top_corner");

    /** The left bottom corner id. */
    public static final String LEFT_BOTTOM_CORNER = new String("left_bottom_corner");

    /** The right top corner id. */
    public static final String RIGHT_TOP_CORNER = new String("right_top_corner");

    /** The right bottom corner id. */
    public static final String RIGHT_BOTTOM_CORNER = new String("right_bottom_corner");

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

            if (n.isEqualTo(ScrollPane.VIEWPORT)) {

                setViewport((Viewport) i);

            } else if (n.isEqualTo(ScrollPane.HORIZONTAL_SCROLL_BAR)) {

                setHorizontalScrollBar((ScrollBar) i);

            } else if (n.isEqualTo(ScrollPane.VERTICAL_SCROLL_BAR)) {

                setVerticalScrollBar((ScrollBar) i);

            } else if (n.isEqualTo(ScrollPane.ROW_HEADER)) {

                setRowHeader((Viewport) i);

            } else if (n.isEqualTo(ScrollPane.COLUMN_HEADER)) {

                setColumnHeader((Viewport) i);

            } else if (n.isEqualTo(ScrollPane.LEFT_TOP_CORNER)) {

                setLeftTopCorner((Organizer) i);

            } else if (n.isEqualTo(ScrollPane.LEFT_BOTTOM_CORNER)) {

                setLeftBottomCorner((Organizer) i);

            } else if (n.isEqualTo(ScrollPane.RIGHT_TOP_CORNER)) {

                setRightTopCorner((Organizer) i);

            } else if (n.isEqualTo(ScrollPane.RIGHT_BOTTOM_CORNER)) {

                setRightBottomCorner((Organizer) i);
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

            if (n.isEqualTo(ScrollPane.VIEWPORT)) {

                setViewport(null);

            } else if (n.isEqualTo(ScrollPane.HORIZONTAL_SCROLL_BAR)) {

                setHorizontalScrollBar(null);

            } else if (n.isEqualTo(ScrollPane.VERTICAL_SCROLL_BAR)) {

                setVerticalScrollBar(null);

            } else if (n.isEqualTo(ScrollPane.ROW_HEADER)) {

                setRowHeader(null);

            } else if (n.isEqualTo(ScrollPane.COLUMN_HEADER)) {

                setColumnHeader(null);

            } else if (n.isEqualTo(ScrollPane.LEFT_TOP_CORNER)) {

                setLeftTopCorner(null);

            } else if (n.isEqualTo(ScrollPane.LEFT_BOTTOM_CORNER)) {

                setLeftBottomCorner(null);

            } else if (n.isEqualTo(ScrollPane.RIGHT_TOP_CORNER)) {

                setRightTopCorner(null);

            } else if (n.isEqualTo(ScrollPane.RIGHT_BOTTOM_CORNER)) {

                setRightBottomCorner(null);
            }

        } else {

            throw new Exception("Could not remove item. The name is null.");
        }

        super.removeChild(n);
    }

    //
    // Encapsulated java swing scroll pane.
    //

    /**
     * Creates an encapsulated java swing scroll pane.
     *
     * @return the encapsulated java swing scroll pane
     * @exception Exception if the encapsulated java swing scroll pane is null
     */
    public java.lang.Object createJavaObject() throws Exception {

        javax.swing.JScrollPane sp = new javax.swing.JScrollPane();

        if (sp != null) {

        } else {

            throw new Exception("Could not create encapsulated java swing scroll pane. The encapsulated java swing scroll pane is null.");
        }

        return sp;
    }

    //
    // Default children.
    //

    /**
     * Returns the default viewport.
     *
     * @return the default viewport
     */
    public String getDefaultViewport() {

        return new String("cybop.core.model.organizer.Viewport");
    }

    /**
     * Returns the default horizontal scroll bar.
     *
     * @return the default horizontal scroll bar
     */
    public String getDefaultHorizontalScrollBar() {

        return new String("cybop.core.model.organizer.ScrollBar");
    }

    /**
     * Returns the default vertical scroll bar.
     *
     * @return the default vertical scroll bar
     */
    public String getDefaultVerticalScrollBar() {

        return new String("cybop.core.model.organizer.ScrollBar");
    }

    /**
     * Returns the default row header.
     *
     * @return the default row header
     */
    public String getDefaultRowHeader() {

        return null;
    }

    /**
     * Returns the default column header.
     *
     * @return the default column header
     */
    public String getDefaultColumnHeader() {

        return null;
    }

    /**
     * Returns the default left top corner.
     *
     * @return the default left top corner
     */
    public String getDefaultLeftTopCorner() {

        return null;
    }

    /**
     * Returns the default left bottom corner.
     *
     * @return the default left bottom corner
     */
    public String getDefaultLeftBottomCorner() {

        return null;
    }

    /**
     * Returns the default right top corner.
     *
     * @return the default right top corner
     */
    public String getDefaultRightTopCorner() {

        return null;
    }

    /**
     * Returns the default right bottom corner.
     *
     * @return the default right bottom corner
     */
    public String getDefaultRightBottomCorner() {

        return null;
    }

    //
    // Viewport.
    //

    /**
     * Sets the viewport.
     *
     * @param vp the viewport
     * @exception Exception if the java scroll pane is null
     * @exception Exception if the viewport is null
     */
    public void setViewport(Viewport vp) throws Exception {

        javax.swing.JScrollPane sp = (javax.swing.JScrollPane) getJavaObject();

        if (sp != null) {

            if (vp != null) {

                sp.setViewport((javax.swing.JViewport) vp.getJavaObject());

            } else {
    
                throw new Exception("Could not set viewport. The viewport is null.");
            }

        } else {

            throw new Exception("Could not set viewport. The java scroll pane is null.");
        }
    }

    //
    // Horizontal scroll bar.
    //

    /**
     * Sets the horizontal scroll bar.
     *
     * @param sb the horizontal scroll bar
     * @exception Exception if the java scroll pane is null
     * @exception Exception if the horizontal scroll bar is null
     */
    public void setHorizontalScrollBar(ScrollBar sb) throws Exception {

        javax.swing.JScrollPane sp = (javax.swing.JScrollPane) getJavaObject();

        if (sp != null) {

            if (sb != null) {

                sp.setHorizontalScrollBar((javax.swing.JScrollBar) sb.getJavaObject());

            } else {
    
                throw new Exception("Could not set horizontal scroll bar. The horizontal scroll bar is null.");
            }

        } else {

            throw new Exception("Could not set horizontal scroll bar. The java scroll pane is null.");
        }
    }

    //
    // Vertical scroll bar.
    //

    /**
     * Sets the vertical scroll bar.
     *
     * @param sb the vertical scroll bar
     * @exception Exception if the java scroll pane is null
     * @exception Exception if the vertical scroll bar is null
     */
    public void setVerticalScrollBar(ScrollBar sb) throws Exception {

        javax.swing.JScrollPane sp = (javax.swing.JScrollPane) getJavaObject();

        if (sp != null) {

            if (sb != null) {

                sp.setVerticalScrollBar((javax.swing.JScrollBar) sb.getJavaObject());

            } else {
    
                throw new Exception("Could not set vertical scroll bar. The vertical scroll bar is null.");
            }

        } else {

            throw new Exception("Could not set vertical scroll bar. The java scroll pane is null.");
        }
    }

    //
    // Row header.
    //

    /**
     * Sets the row header.
     *
     * @param rh the row header
     * @exception Exception if the java scroll pane is null
     * @exception Exception if the row header is null
     */
    public void setRowHeader(Viewport rh) throws Exception {

        javax.swing.JScrollPane sp = (javax.swing.JScrollPane) getJavaObject();

        if (sp != null) {

            if (rh != null) {

                sp.setRowHeader((javax.swing.JViewport) rh.getJavaObject());

            } else {
    
                throw new Exception("Could not set row header. The row header is null.");
            }

        } else {

            throw new Exception("Could not set row header. The java scroll pane is null.");
        }
    }

    //
    // Column header.
    //

    /**
     * Sets the column header.
     *
     * @param ch the column header
     * @exception Exception if the java scroll pane is null
     * @exception Exception if the column header is null
     */
    public void setColumnHeader(Viewport ch) throws Exception {

        javax.swing.JScrollPane sp = (javax.swing.JScrollPane) getJavaObject();

        if (sp != null) {

            if (ch != null) {

                sp.setColumnHeader((javax.swing.JViewport) ch.getJavaObject());

            } else {
    
                throw new Exception("Could not set column header. The column header is null.");
            }

        } else {

            throw new Exception("Could not set column header. The java scroll pane is null.");
        }
    }

    //
    // Left top corner.
    //

    /**
     * Sets the left top corner.
     *
     * @param c the left top corner
     * @exception Exception if the java scroll pane is null
     * @exception Exception if the left top corner is null
     */
    public void setLeftTopCorner(Organizer c) throws Exception {

        javax.swing.JScrollPane sp = (javax.swing.JScrollPane) getJavaObject();

        if (sp != null) {

            if (c != null) {

                sp.setCorner(javax.swing.JScrollPane.UPPER_LEFT_CORNER, (java.awt.Component) c.getJavaObject());

            } else {
    
                throw new Exception("Could not set left top corner. The left top corner is null.");
            }

        } else {

            throw new Exception("Could not set left top corner. The java scroll pane is null.");
        }
    }

    //
    // Left bottom corner.
    //

    /**
     * Sets the left bottom corner.
     *
     * @param c the left bottom corner
     * @exception Exception if the java scroll pane is null
     * @exception Exception if the left bottom corner is null
     */
    public void setLeftBottomCorner(Organizer c) throws Exception {

        javax.swing.JScrollPane sp = (javax.swing.JScrollPane) getJavaObject();

        if (sp != null) {

            if (c != null) {

                sp.setCorner(javax.swing.JScrollPane.LOWER_LEFT_CORNER, (java.awt.Component) c.getJavaObject());

            } else {
    
                throw new Exception("Could not set left bottom corner. The left bottom corner is null.");
            }

        } else {

            throw new Exception("Could not set left bottom corner. The java scroll pane is null.");
        }
    }

    //
    // Right top corner.
    //

    /**
     * Sets the right top corner.
     *
     * @param c the right top corner
     * @exception Exception if the java scroll pane is null
     * @exception Exception if the right top corner is null
     */
    public void setRightTopCorner(Organizer c) throws Exception {

        javax.swing.JScrollPane sp = (javax.swing.JScrollPane) getJavaObject();

        if (sp != null) {

            if (c != null) {

                sp.setCorner(javax.swing.JScrollPane.UPPER_RIGHT_CORNER, (java.awt.Component) c.getJavaObject());

            } else {
    
                throw new Exception("Could not set right top corner. The right top corner is null.");
            }

        } else {

            throw new Exception("Could not set right top corner. The java scroll pane is null.");
        }
    }

    //
    // Right bottom corner.
    //

    /**
     * Sets the right bottom corner.
     *
     * @param c the right bottom corner
     * @exception Exception if the java scroll pane is null
     * @exception Exception if the right bottom corner is null
     */
    public void setRightBottomCorner(Organizer c) throws Exception {

        javax.swing.JScrollPane sp = (javax.swing.JScrollPane) getJavaObject();

        if (sp != null) {

            if (c != null) {

                sp.setCorner(javax.swing.JScrollPane.LOWER_RIGHT_CORNER, (java.awt.Component) c.getJavaObject());

            } else {
    
                throw new Exception("Could not set right bottom corner. The right bottom corner is null.");
            }

        } else {

            throw new Exception("Could not set right bottom corner. The java scroll pane is null.");
        }
    }
}

