/*
 * $RCSfile: Problem.java,v $
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

package cybop.healthcare.model.unit;

import cybop.core.basic.String;
import cybop.healthcare.model.*;

/**
 * This class represents a problem.<br><br>
 *
 * A problem is some artifact in the health of a patient.
 *
 * @version $Revision: 1.4 $ $Date: 2003-03-12 18:12:20 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class Problem extends Unit {

    //
    // Children names.
    //

    /** The identifier. */
    public static final String IDENTIFIER = new String("identifier");

    /** The name. */
    public static final String NAME = new String("name");

    /** The anamnese. */
    public static final String ANAMNESE = new String("anamnese");

    /**
     * Gets the problem episodes.
     *
     * @return vector containing episodes of the problem
     */
    public Object[] getEpisodes() {

        Object[] childrenArray = getChildren().values().toArray();
        java.util.Vector tempVector = new java.util.Vector();

        for (int i = 0; i < childrenArray.length; i++) {

            if (childrenArray[i].getClass().equals(Episode.class)) {

                tempVector.add(childrenArray[i]);
            }
        }

        return tempVector.toArray();
    }

    /**
     *Tests whether this problem has episodes.
     * @return true if the problem has episodes, false if not
     */
    public boolean hasEpisodes() {
        Object[] childrenArray = getChildren().values().toArray();
        for (int i = 0; i < childrenArray.length; i++) {
            if (childrenArray[i].getClass().equals(Episode.class)) {
                return true;
            }
        }
        return false;
    }

    /**
     *Gets the first episode of this problem. This is the episode with the lowest index.
     * @return first episode
     */
    public Episode getFirstEpisode() {
        return (Episode)getEpisodes() [0];
    }

    /**
     *Gets the last episode of this problem. This is the episode with the highest index.
     * @return last episode
     */
    public Episode getLastEpisode() {
        return (Episode)getEpisodes() [getEpisodes().length - 1];
    }

    /**
     *Gets number of episodes.
     * @return number of episodes
     */
    public int getEpisodeCount() {
        Object[] childrenArray = getChildren().values().toArray();
        int count = 0;
        for (int i = 0; i < childrenArray.length; i++) {
            if (childrenArray[i].getClass().equals(Episode.class)) {
                count++;
            }
        }
        return count;
    }
}

