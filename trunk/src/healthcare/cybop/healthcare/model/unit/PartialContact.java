/*
 * $RCSfile: PartialContact.java,v $
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
import org.resmedicinae.domain.healthcare.heading.problem.Subjective;
import org.resmedicinae.domain.healthcare.heading.problem.Assessment;
import org.resmedicinae.domain.healthcare.heading.problem.Plan;
import org.resmedicinae.domain.healthcare.heading.problem.Objective;
import java.util.Vector;

/**
 * This class represents a partial contact.<br><br> A partial contact is a time extract of an episode.
 * It consists of problem headings.
 * @version $Revision: 1.1 $ $Date: 2003-02-18 14:47:46 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 * @author Jens Bohl <jens.bohl@stud.tu-ilmenau.de>
 * @author Torsten Kunze <zone3@gmx.de>
 */
public class PartialContact extends Unit {
    //?? Insert attributes here!
    //?? Don't forget "create", "destroy" methods!

    /** The number of the episode within the problem the episode belongs to. */
    private int partialContactNumber;

    /** The date of the partial contact. */
    private org.resmedicinae.resmedlib.term.String date;

    private org.resmedicinae.resmedlib.term.String timestamp;

    /** Constructor. */
    public PartialContact() {
    }

    /**
     *Sets the date of the partial contact
     * @param date the date of the partial contact
     */
    public void setPartialContactDate(org.resmedicinae.resmedlib.term.String  date) {
        this.date = date;
    }

    /**
     *Gets the date of the partial contact
     * @return the date of the partial contact
     */
    public org.resmedicinae.resmedlib.term.String  getPartialContactDate() {
        return this.date;
    }


    /**
     *Adds a object to an partial contact.
     * @param object the object to be added to the partial contact
     */
    public void addObjective(Objective objective) {
        String tempObjectiveId = (new Integer(getObjectiveCount())).toString();
        set(new org.resmedicinae.resmedlib.term.String(tempObjectiveId), objective);
    }

    /**
     *Sets the indes of the partial contact
     * @param partial contactNumber index of the partial contact
     */
    public void setPartialContactNumber(int number) {
        this.partialContactNumber = number;
    }

    /** Gets the index of the partial contact qreturn the index of the partial contact */
    public int getPartialContactNumber() {
        return this.partialContactNumber;
    }

    /**
     *Converts the object to String. This is needed because of the tree table. The tree table nodes are named as
     * the object their represents. So the node will be called like the object.
     */
    public String toString() {
        return "Partial Contact";
    }

    public int getObjectiveCount() {
        Object[] ob = getObjectives();
        if (ob!=null)
            return ob.length;
        else
            return 0;
    }

    public boolean hasObjectives() {
        return !(getObjectiveCount() == 0);
    }

    public int getSubjectiveCount() {
        return getSubjectives().length;
    }

    public boolean hasSubjectives() {
        return !(getSubjectiveCount() == 0);
    }

    public int getAssessmentCount() {
        return getAssessments().length;
    }

    public boolean hasAssessments() {
        return !(getAssessmentCount() == 0);
    }

    public int getPlanCount() {
        return getPlans().length;
    }

    public boolean hasPlans() {
        return !(getPlanCount() == 0);
    }

    /**
     *Gets the objects of the partial contact
     * @return the objects of the partial contact
     */
    public Object[] getObjectives() {
        Object[] childrenArray = getChildren().values().toArray();
        Vector tempVector = new Vector();
        for (int i = 0; i < childrenArray.length; i++) {
            if (childrenArray[i].getClass().equals(Objective.class)) {
                tempVector.add(childrenArray[i]);
            }
        }
        return tempVector.toArray();
    }

    public Object[] getSubjectives() {
        Object[] childrenArray = getChildren().values().toArray();
        Vector tempVector = new Vector();
        for (int i = 0; i < childrenArray.length; i++) {
            if (childrenArray[i].getClass().equals(Subjective.class)) {
                tempVector.add(childrenArray[i]);
            }
        }
        return tempVector.toArray();
    }

    public Object[] getAssessments() {
        Object[] childrenArray = getChildren().values().toArray();
        Vector tempVector = new Vector();
        for (int i = 0; i < childrenArray.length; i++) {
            if (childrenArray[i].getClass().equals(Assessment.class)) {
                tempVector.add(childrenArray[i]);
            }
        }
        return tempVector.toArray();
    }

    public Object[] getPlans() {
        Object[] childrenArray = getChildren().values().toArray();
        int count = 0;
        Vector tempVector = new Vector();
        for (int i = 0; i < childrenArray.length; i++) {
            if (childrenArray[i].getClass().equals(Plan.class)) {
                tempVector.add(childrenArray[i]);
            }
        }
        return tempVector.toArray();
    }

    public void removeObjective(Objective objective) {
        Object[] objectives = getObjectives();
        for (int i = 0; i < objectives.length; i++) {
            if (objectives[i].equals(objective)) {
                remove(objective.getIdentifier());
            }
        }
    }

    public org.resmedicinae.resmedlib.term.String getTimestamp() {
        return timestamp;
    }

    public void setTimestamp(org.resmedicinae.resmedlib.term.String timestamp) {
        this.timestamp = timestamp;
    }

}
