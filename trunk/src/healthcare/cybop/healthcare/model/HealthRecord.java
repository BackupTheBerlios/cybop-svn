/*
 * $RCSfile: HealthRecord.java,v $
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

package cybop.healthcare.model;

import cybop.core.basic.*;
import cybop.core.basic.String;
import cybop.healthcare.model.description.*;
import cybop.healthcare.model.heading.problem.*;
import cybop.healthcare.model.unit.*;

/**
 * This class represents a health record.<br><br>
 *
 * It is a super class and forms an own level in the framework's domain ontology:
 * <ul>
 *      <li>HealthRecord</li>
 *      <li>Unit</li>
 *      <li>Heading</li>
 *      <li>Description</li>
 *      <li>Principle</li>
 * </ul>
 *
 * A record corresponds to a book. A record keeps a history of data over time.
 * Records are used in most diverse business fields, e.g. Healthcare, Insurance, Enterprise.
 * A health record is the collection of information about a person who is
 * medically treated as patient. As such, health record is the core of all
 * medical, administrative and other data stored about people. The OpenEHR
 * specification describes record (history) as:<br>
 * "Concepts relating to collections of information over the long term."
 *
 * @version $Revision: 1.3 $ $Date: 2003-02-20 15:35:14 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 * @see http://www.openehr.org http://www.gehr.org
 */
public class HealthRecord extends Item {

    //
    // Children.
    //

    /** The gender. */
    public static final String GENDER = new String("gender");

    /** The body height. */
    public static final String BODY_HEIGHT = new String("body_height");

    /** The body weight. */
    public static final String BODY_WEIGHT = new String("body_weight");

    /** The eye color. */
    public static final String EYE_COLOR = new String("eye_color");

    /** The blood type. */
    public static final String BLOOD_TYPE = new String("blood_type");

    /** The insurance. */
    public static final String INSURANCE = new String("insurance");

    /** The insurance number. */
    public static final String INSURANCE_NUMBER = new String("insurance_number");

    /** The insurant number. */
    public static final String INSURANT_NUMBER = new String("insurant_number");

    /** The insurant status. */
    public static final String INSURANT_STATUS = new String("insurant_status");

    /** The health fund. */
    public static final String HEALTH_FUND = new String("health_fund");

    /** The health fund number. */
    public static final String HEALTH_FUND_NUMBER = new String("health_fund_number");

    /** The vk validity. */
    public static final String VK_VALIDITY = new String("vk_validity");

    /** The doctor number. */
    public static final String DOCTOR_NUMBER = new String("doctor_number");

    /** The script date. */
    public static final String SCRIPT_DATE = new String("script_date");

    /** The adjustment. */
    public static final String ADJUSTMENT = new String("adjustment");

    /** The noctu. */
    public static final String NOCTU = new String("noctu");

    /** The some others. */
    public static final String SOME_OTHERS = new String("some_others");

    /** The accident. */
    public static final String ACCIDENT = new String("accident");

    /** The BVG. */
    public static final String BVG = new String("bvg");

    /** The resources. */
    public static final String RESOURCES = new String("resources");

    /** The serum. */
    public static final String SERUM = new String("serum");

    /** The requirement. */
    public static final String REQUIREMENT = new String("requirement");

    /** The script medicine. */
    public static final String SCRIPT_MEDICINE = new String("script_medicine");

    /**
     *Gets the problems. The problems are held in a hashtable where the name of the problem is the key and the
     * problem itself is the value.
     * @return the problems of the healthRecord
     */
    public Object[] getProblems() {

        Object[] childrenArray = getChildren().values().toArray();
        java.util.Vector tempVector = new java.util.Vector();

        for (int i = 0; i < childrenArray.length; i++) {

            if (childrenArray[i].getClass().equals(Problem.class)) {

                tempVector.add(childrenArray[i]);
            }
        }

        return tempVector.toArray();
    }

    /**
     *Gets a problem by its name.
     * @param problemName the name of the problem
     * @return the problem
     */
    public Problem getProblemByName(String problemName) {

        Object[] problems = getProblems();

        for (int i = 0; i < problems.length; i++) {

            Problem problem = (Problem)problems[i];

            if (((String) problem.get(Problem.NAME)).isEqualTo(problemName)) {

                return problem;
            }
        }

        return null;
    }

    /**
     *Tests whether the healthRecord has problems.
     * @return true if the healthRecord has problems, false if not
     */
    public boolean hasProblems() {
        Object[] childrenArray = getChildren().values().toArray();
        for (int i = 0; i < childrenArray.length; i++) {
            if (childrenArray[i].getClass().equals(Problem.class)) {
                return true;
            }
        }
        return false;
    }

    public int getProblemCount() {
        Object[] childrenArray = getChildren().values().toArray();
        int count = 0;
        for (int i = 0; i < childrenArray.length; i++) {
            if (childrenArray[i].getClass().equals(Problem.class)) {
                count++;
            }
        }
        return count;
    }

    /**
     *Removes a problem.
     * @param problem the problem to be removed
     */
    public void removeProblem(Problem problem) {

        Object[] problems = getProblems();

        for (int i = 0; i < problems.length; i++) {

            if (problems[i].equals(problem)) {

//??                remove(problem.get(Problem.IDENTIFIER));
            }
        }
    }

    /**
     *Gets the CAVE entries
     * @return the problems of the patient
     */
    public Object[] getCaves() {

        Object[] childrenArray = getChildren().values().toArray();
        java.util.Vector tempVector = new java.util.Vector();

        for (int i = 0; i < childrenArray.length; i++) {

            if (childrenArray[i].getClass().equals(Cave.class)) {

                tempVector.add(childrenArray[i]);
            }
        }

        return tempVector.toArray();
    }

    public int getCavesCount() {
        Object[] childrenArray = getChildren().values().toArray();
        int count = 0;
        for (int i = 0; i < childrenArray.length; i++) {
            if (childrenArray[i].getClass().equals(Cave.class)) {
                count++;
            }
        }
        return count;
    }

    /**
     *Tests whether the patient has CAVE entries.
     * @return true if the patient has CAVE entries, false if not
     */
    public boolean hasCaves() {
        if (getCavesCount() > 0) {
            return true;
        } else {
            return false;
        }
    }
}

