/*
 * $RCSfile: Problem.java,v $
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

package org.resmedicinae.domain.healthcare.unit;

import org.resmedicinae.domain.healthcare.*;
import java.util.Vector;

/**
 * This class represents a problem.<br><br> A problem is some artifact in the health of a patient.
 * @version $Revision: 1.1 $ $Date: 2003-02-18 14:47:46 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class Problem extends Unit {

    /** Name of the problem. */
    private org.resmedicinae.resmedlib.term.String name;

    /** Anamnese of the problem. */
    private org.resmedicinae.resmedlib.term.String anamnese;

    private org.resmedicinae.resmedlib.term.String timestamp;

    /** Constructor. */
    public Problem() {
    }

    /**
     *Sets the problem name.
     * @param name the name of the problem
     */
    public void setName(org.resmedicinae.resmedlib.term.String name) {
        this.name = name;
    }

    /**
     *Gets the problem name.
     * @return the name of the problem
     */
    public org.resmedicinae.resmedlib.term.String getName() {
        return this.name;
    }

    /**
     *Sets the problem anamnese.
     * @param anamnese the anamnese of the problem
     */
    public void setAnamnese(org.resmedicinae.resmedlib.term.String anamnese) {
        System.out.println("++++++++++++++++++++++++++++++Anamnese set!!!!");
        this.anamnese = anamnese;
    }

    /**
     *Gets the problem anamnese.
     * @return the anamnese of the problem
     */
    public org.resmedicinae.resmedlib.term.String getAnamnese() {
        return this.anamnese;
    }


    /**
     *Gets the problem episodes.
     * @return vector containing episodes of the problem
     */
    public Object[] getEpisodes() {
        Object[] childrenArray = getChildren().values().toArray();
        Vector tempVector = new Vector();
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
     *Converts the object to String. This is needed because of the tree table. The tree table nodes are named as
     * the object their represents. So the node will be called like the object.
     */
    public String toString() {
        return "Problem";
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

    public org.resmedicinae.resmedlib.term.String getTimestamp() {
        return timestamp;
    }

    public void setTimestamp(org.resmedicinae.resmedlib.term.String timestamp) {
        this.timestamp = timestamp;
    }

}
