/*
 * $RCSfile: Objective.java,v $
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

package cybop.healthcare.model.heading.problem;

import cybop.core.model.String;
import cybop.healthcare.model.heading.*;

/**
 * This class represents an objective problem heading.<br><br>
 *
 * An objective problem heading is ...
 *
 * @version $Revision: 1.4 $ $Date: 2003-05-20 06:21:59 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class Objective extends ProblemHeading {

    /** The name of the overlay related to the SOAP object. */
    private String overlayName;

    /** The x coordinates of point which are markers in the image of the episode. */
    private java.util.Vector markerXCoordinates;

    /** The y coordinates of point which are markers in the image of the episode. */
    private java.util.Vector markerYCoordinates;

    /** The default constructor. */
    public Objective() {
        this.markerXCoordinates = new java.util.Vector();
        this.markerYCoordinates = new java.util.Vector();
    }

    /**
     *The constructor.
     * @param text the text the object contains
     */
    public Objective(String text) {

        this.markerXCoordinates = new java.util.Vector();
        this.markerYCoordinates = new java.util.Vector();
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
    public java.util.Vector getMarkerXCoordinates() {
        return this.markerXCoordinates;
    }

    /**
     *Sets the x coordinates vector of the marker for the episode
     * @param markerXCoordinates
     */
    public void setMarkerXCoordinates(java.util.Vector markerXCoordinates) {
        this.markerXCoordinates = markerXCoordinates;
    }

    /**
     *Gets the y coordinates vector of the marker for the episode
     * @return markerYCoordinates
     */
    public java.util.Vector getMarkerYCoordinates() {
        return this.markerYCoordinates;
    }

    /**
     *Sets the y coordinates vector of the marker for the episode
     * @param markerYCoordinates
     */
    public void setMarkerYCoordinates(java.util.Vector markerYCoordinates) {
        this.markerYCoordinates = markerYCoordinates;
    }

    /**
     *Test whether the episodes has markers or not.
     * @return true if episode has markers, false if not
     */
    public boolean hasMarkers() {
        return !markerYCoordinates.isEmpty();
    }
}

