/*
 * $RCSfile: Objective.java,v $
 *
 * Copyright (c) 1999-2002. The Res Medicinae developers. All rights reserved.
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

package org.resmedicinae.domain.healthcare.heading.problem;

import org.resmedicinae.domain.healthcare.heading.*;
import java.util.Vector;

/**
 * This class represents an objective problem heading.<br><br> An objective problem heading is ...
 * @version $Revision: 1.1 $ $Date: 2003-02-18 14:47:46 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class Objective extends ProblemHeading {
    //?? Insert attributes here!
    //?? Don't forget "create", "destroy", "set" and "get" methods!

    private org.resmedicinae.resmedlib.term.String timestamp;

    /** The name of the overlay related to the SOAP object. */
    private String overlayName;

    /** The x coordinates of point which are markers in the image of the episode. */
    private Vector markerXCoordinates;

    /** The y coordinates of point which are markers in the image of the episode. */
    private Vector markerYCoordinates;

    /** The text of the object. */
    private org.resmedicinae.resmedlib.term.String text;

    /** The default constructor. */
    public Objective() {
        this.markerXCoordinates = new Vector();
        this.markerYCoordinates = new Vector();
    }

    /**
     *The constructor.
     * @param text the text the object contains
     */
    public Objective(String text) {
        setText(new org.resmedicinae.resmedlib.term.String(text));
        this.markerXCoordinates = new Vector();
        this.markerYCoordinates = new Vector();
    }

    /**
     *Converts the object to String. This is needed because of the tree table. The tree table nodes are named as
     * the object their represents. So the node will be called like the object.
     * @return object converted to String
     */
    public String toString() {
        return "Objective";
    }

    /**
     *Gets the name of the overlay related to the SOAP object
     * @return the name of the overlay
     */
    public String getOverlayName() {
        return overlayName;
    }

    /**
     *Sets the name of the overlay related to the SOAP object
     * @param overlayName the name of the overlay
     */
    public void setOverlayName(String overlayName) {
        this.overlayName = overlayName;
    }

    /**
     *Adds a marker for the episode. A marker is a point consiting of x and y coordinate
     * @param x a x coordinate
     * @param y a y coordinate
     */
    public void addMarker(int x, int y) {
        getMarkerXCoordinates().addElement(new Integer(x));
        getMarkerYCoordinates().addElement(new Integer(y));
    }

    /**
     *Gets the number of markers in the episode
     * @return the number of markers in the episode
     */
    public int getMarkerCount() {
        return getMarkerXCoordinates().size();
    }

    /**
     *Gets a x marker at the specified index.
     * @param index index of the marker in vector
     * @return marker
     */
    public Integer getXMarker(int index) {
        return (Integer)markerXCoordinates.elementAt(index);
    }

    /**
     *Gets a y marker at the specified index.
     * @param index index of the marker in vector
     * @return marker
     */
    public Integer getYMarker(int index) {
        return (Integer)markerYCoordinates.elementAt(index);
    }

    /**
     *Gets the x coordinates vector of the marker for the episode
     * @param markerXCoordinates
     */
    public Vector getMarkerXCoordinates() {
        return this.markerXCoordinates;
    }

    /**
     *Sets the x coordinates vector of the marker for the episode
     * @param markerXCoordinates
     */
    public void setMarkerXCoordinates(Vector markerXCoordinates) {
        this.markerXCoordinates = markerXCoordinates;
    }

    /**
     *Gets the y coordinates vector of the marker for the episode
     * @return markerYCoordinates
     */
    public Vector getMarkerYCoordinates() {
        return this.markerYCoordinates;
    }

    /**
     *Sets the y coordinates vector of the marker for the episode
     * @param markerYCoordinates
     */
    public void setMarkerYCoordinates(Vector markerYCoordinates) {
        this.markerYCoordinates = markerYCoordinates;
    }

    /**
     *Test whether the episodes has markers or not.
     * @return true if episode has markers, false if not
     */
    public boolean hasMarkers() {
        return !markerYCoordinates.isEmpty();
    }

    /**
     *Gets the text of the object
     * @return the text of the object
     */
    public org.resmedicinae.resmedlib.term.String getText() {
        return this.text;
    }

    /**
     *Sets the text of the object
     *@param text the text of the object
     */
    public void setText(org.resmedicinae.resmedlib.term.String text) {
        this.text = text;
    }

   public org.resmedicinae.resmedlib.term.String getTimestamp() {
        return timestamp;
    }

    public void setTimestamp(org.resmedicinae.resmedlib.term.String timestamp) {
        this.timestamp = timestamp;
    }
}
