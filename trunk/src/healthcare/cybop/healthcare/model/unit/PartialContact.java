/*
 * $RCSfile: PartialContact.java,v $
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
import cybop.healthcare.model.heading.problem.Subjective;
import cybop.healthcare.model.heading.problem.Assessment;
import cybop.healthcare.model.heading.problem.Plan;
import cybop.healthcare.model.heading.problem.Objective;

/**
 * This class represents a partial contact.<br><br>
 *
 * A partial contact is a time extract of an episode.
 * It consists of problem headings.
 *
 * @version $Revision: 1.3 $ $Date: 2003-02-20 15:35:15 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 * @author Jens Bohl <jens.bohl@stud.tu-ilmenau.de>
 * @author Torsten Kunze <zone3@gmx.de>
 */
public class PartialContact extends Unit {

    //
    // Children.
    //

    /** The partial contact number. */
    public static final String PARTIAL_CONTACT_NUMBER = new String("partial_contact_number");

    /** The partial contact date. */
    public static final String PARTIAL_CONTACT_DATE = new String("partial_contact_date");

    /**
     * Adds a object to an partial contact.
     *
     * @param o the object to be added to the partial contact
     */
    public void addObjective(Objective o) {

        String id = new String(java.lang.String.valueOf(getObjectiveCount()));

        set(id, o);
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
        java.util.Vector tempVector = new java.util.Vector();

        for (int i = 0; i < childrenArray.length; i++) {

            if (childrenArray[i].getClass().equals(Objective.class)) {

                tempVector.add(childrenArray[i]);
            }
        }

        return tempVector.toArray();
    }

    public Object[] getSubjectives() {

        Object[] childrenArray = getChildren().values().toArray();
        java.util.Vector tempVector = new java.util.Vector();

        for (int i = 0; i < childrenArray.length; i++) {

            if (childrenArray[i].getClass().equals(Subjective.class)) {

                tempVector.add(childrenArray[i]);
            }
        }

        return tempVector.toArray();
    }

    public Object[] getAssessments() {

        Object[] childrenArray = getChildren().values().toArray();
        java.util.Vector tempVector = new java.util.Vector();

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
        java.util.Vector tempVector = new java.util.Vector();

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

//??                remove(objective.get(Objective.IDENTIFIER));
            }
        }
    }
}

