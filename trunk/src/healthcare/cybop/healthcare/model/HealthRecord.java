/*
 * $RCSfile: HealthRecord.java,v $
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

package org.resmedicinae.domain.healthcare;

import org.resmedicinae.domain.healthcare.unit.*;
import org.resmedicinae.domain.healthcare.heading.problem.Objective;
import org.resmedicinae.domain.healthcare.description.Cave;
import org.resmedicinae.resmedlib.*;
import java.util.Hashtable;
import java.util.Vector;

/**
 * This class represents a health record.<br><br> It is a super class and forms an own level in the framework's domain ontology:
 * <ul> <li>HealthRecord</li> <li>Unit</li> <li>Heading</li> <li>Description</li> <li>Principle</li> </ul>
 * A record corresponds to a book. A record keeps a history of data over time. Records are used in most
 * diverse business fields, e.g. Healthcare, Insurance, Enterprise.
 * A health record is the collection of information about a person who is
 * medically treated as patient. As such, health record is the core of all
 * medical, administrative and other data stored about people. The OpenEHR specification describes record (history) as:<br>
 * "Concepts relating to collections of information over the long term."
 * @version $Revision: 1.1 $ $Date: 2003-02-18 14:47:46 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 * @see http://www.openehr.org http://www.gehr.org
 */
public class HealthRecord extends Item {

    /** Name of patient */
    private org.resmedicinae.resmedlib.term.String name;

    /** First name of patient */
    private org.resmedicinae.resmedlib.term.String firstName;

    /** Birthday of patient */
    private org.resmedicinae.resmedlib.term.String birthday;

    /** Street of patient */
    private org.resmedicinae.resmedlib.term.String street;

    /** Zip code of patient */
    private org.resmedicinae.resmedlib.term.String zipCode;

    /** Town of patient */
    private org.resmedicinae.resmedlib.term.String town;

    /** Insurance of patient */
    private org.resmedicinae.resmedlib.term.String insurance;

    /** Gender of patient */
    private org.resmedicinae.resmedlib.term.String gender;

    /** Country of patient */
    private org.resmedicinae.resmedlib.term.String country;

    /** Phone number of patient */
    private org.resmedicinae.resmedlib.term.String phoneNumber;

    /** Insurance number of patient */
    private org.resmedicinae.resmedlib.term.String insuranceNumber;

    /** Blood type number of patient */
    private org.resmedicinae.resmedlib.term.String bloodType;

    /** Height number of patient */
    private org.resmedicinae.resmedlib.term.String height;

    /** Weight number of patient */
    private org.resmedicinae.resmedlib.term.String weight;

    private org.resmedicinae.resmedlib.term.String healthFundNumber;
    private org.resmedicinae.resmedlib.term.String insurantNumber;
    private org.resmedicinae.resmedlib.term.String statusOfInsurant;
    private org.resmedicinae.resmedlib.term.String doctorsNumber;
    private org.resmedicinae.resmedlib.term.String vKValidy;
    private org.resmedicinae.resmedlib.term.String dateOfScript;
    private org.resmedicinae.resmedlib.term.String healthFund;
    private org.resmedicinae.resmedlib.term.String adjustment;
    private org.resmedicinae.resmedlib.term.String noctu;
    private org.resmedicinae.resmedlib.term.String someOthers;
    private org.resmedicinae.resmedlib.term.String accident;
    private org.resmedicinae.resmedlib.term.String bVG;
    private org.resmedicinae.resmedlib.term.String resources;
    private org.resmedicinae.resmedlib.term.String serum;
    private org.resmedicinae.resmedlib.term.String requirement;
    private org.resmedicinae.resmedlib.term.String scriptMedicine;

    private org.resmedicinae.resmedlib.term.String timestamp;

    /** Constructor. */
    public HealthRecord() {
    }

    public void typeOutProperties(){
        java.lang.System.out.println("SYSTEM-PROPERTIES---------------------------------------");
        java.lang.System.out.println("Name: "+getName().getValue());
        java.lang.System.out.println("FirstName: "+getFirstName().getValue());
        java.lang.System.out.println("Birthday: "+getBirthday().getValue());
    }

    /**
     *Sets the patient name.
     * @param name the name of the patient
     */
    public void setName(org.resmedicinae.resmedlib.term.String name) {
        this.name = name;
    }

    /**
     *Gets the patient name.
     * @return the name of the patient
     */
    public org.resmedicinae.resmedlib.term.String getName() {
        return this.name;
    }

    /**
     *Sets the patient first name.
     * @param firstName the first name of the patient
     */
    public void setFirstName(org.resmedicinae.resmedlib.term.String firstName) {
        this.firstName = firstName;
    }

    /**
     *Gets the patient first name.
     * @return the first name of the patient
     */
    public org.resmedicinae.resmedlib.term.String getFirstName() {
        return this.firstName;
    }

    /**
     *Sets the patient birthday.
     * @param birthday the birthday of the patient
     */
    public void setBirthday(org.resmedicinae.resmedlib.term.String birthday) {
        this.birthday = birthday;
    }

    /**
     *Gets the patient birthday.
     * @return the birthday of the patient
     */
    public org.resmedicinae.resmedlib.term.String getBirthday() {
        return this.birthday;
    }

    /**
     *Sets the zip code.
     * @param code the zip code of the town of the patient
     */
    public void setZipCode(org.resmedicinae.resmedlib.term.String code) {
        this.zipCode = code;
    }

    /**
     *Gets the zip code.
     * @return the zip code of the town of the patient
     */
    public org.resmedicinae.resmedlib.term.String getZipCode() {
        return this.zipCode;
    }

    /**
     *Sets the town.
     * @param the town of the patient
     */
    public void setTown(org.resmedicinae.resmedlib.term.String town) {
        this.town = town;
    }

    /**
     *Gets the town.
     * @return the town of the patient
     */
    public org.resmedicinae.resmedlib.term.String getTown() {
        return this.town;
    }

    /**
     *Sets the country.
     * @param country the country name where the patient lives
     */
    public void setCountry(org.resmedicinae.resmedlib.term.String country) {
        this.country = country;
    }

    /**
     *Gets the country.
     * @return the country where the patient lives
     */
    public org.resmedicinae.resmedlib.term.String getCountry() {
        return this.country;
    }

    /**
     *Sets the street name.
     * @param street the street name where the patient lives
     */
    public void setStreet(org.resmedicinae.resmedlib.term.String street) {
        this.street = street;
    }

    /**
     *Gets the street name.
     * @return the street name where the patient lives
     */
    public org.resmedicinae.resmedlib.term.String getStreet() {
        return this.street;
    }

    /**
     *Sets the gender.
     * @param the gender of the patient
     */
    public void setGender(org.resmedicinae.resmedlib.term.String gender) {
        this.gender = gender;
    }

    /**
     *Gets the gender.
     * @return the gender of the patient
     */
    public org.resmedicinae.resmedlib.term.String getGender() {
        return this.gender;
    }

    /**
     *Sets the insurance.
     * @param insurance the insurance of the patient
     */
    public void setInsurance(org.resmedicinae.resmedlib.term.String insurance) {
        this.insurance = insurance;
    }

    /**
     *Gets the insurance.
     * @return the insurance of the patient
     */
    public org.resmedicinae.resmedlib.term.String getInsurance() {
        return this.insurance;
    }

    /**
     *Sets the phone number.
     * @param phoneNumber the phoneNumber of the patient
     */
    public void setPhoneNumber(org.resmedicinae.resmedlib.term.String phoneNumber) {
        this.phoneNumber = phoneNumber;
    }

    /**
     *Gets the phone number.
     * @return the phoneNumber of the patient
     */
    public org.resmedicinae.resmedlib.term.String getPhoneNumber() {
        return this.phoneNumber;
    }

    public void setHealthFundNumber(org.resmedicinae.resmedlib.term.String healthFundNumber) {
        this.healthFundNumber = healthFundNumber;
    }

    public org.resmedicinae.resmedlib.term.String getHealthFundNumber() {
        return this.healthFundNumber;
    }

    public void setInsuranceNumber(org.resmedicinae.resmedlib.term.String insuranceNumber) {
        this.insuranceNumber = insuranceNumber;
    }

    public org.resmedicinae.resmedlib.term.String getInsuranceNumber() {
        return this.insuranceNumber;
    }

    public void setInsurantNumber(org.resmedicinae.resmedlib.term.String insurantNumber) {
        this.insurantNumber = insurantNumber;
    }

    public org.resmedicinae.resmedlib.term.String getInsurantNumber() {
        return this.insurantNumber;
    }

    public void setStatusOfInsurant(org.resmedicinae.resmedlib.term.String statusOfInsurant) {
        this.statusOfInsurant = statusOfInsurant;
    }

    public org.resmedicinae.resmedlib.term.String getStatusOfInsurant() {
        return this.statusOfInsurant;
    }

    public void setDoctorsNumber(org.resmedicinae.resmedlib.term.String doctorsNumber) {
        this.doctorsNumber = doctorsNumber;
    }

    public org.resmedicinae.resmedlib.term.String getDoctorsNumber() {
        return this.doctorsNumber;
    }

    public void setVKValidy(org.resmedicinae.resmedlib.term.String vKValidy) {
        this.vKValidy = vKValidy;
    }

    public org.resmedicinae.resmedlib.term.String getVKValidy() {
        return this.vKValidy;
    }

    public void setDateOfScript(org.resmedicinae.resmedlib.term.String dateOfScript) {
        this.dateOfScript = dateOfScript;
    }

    public org.resmedicinae.resmedlib.term.String getDateOfScript() {
        return this.dateOfScript;
    }

    public void setHealthFund(org.resmedicinae.resmedlib.term.String healthFund) {
        this.healthFund = healthFund;
    }

    public org.resmedicinae.resmedlib.term.String getHealthFund() {
        return this.healthFund;
    }

    public void setAdjustment(org.resmedicinae.resmedlib.term.String adjustment) {
        this.adjustment = adjustment;
    }

    public org.resmedicinae.resmedlib.term.String getAdjustment() {
        return this.adjustment;
    }

    public org.resmedicinae.resmedlib.term.String getNoctu() {
        return noctu;
    }

    public void setNoctu(org.resmedicinae.resmedlib.term.String noctu) {
        this.noctu = noctu;
    }

    public void setSomeOthers(org.resmedicinae.resmedlib.term.String someOthers) {
        this.someOthers = someOthers;
    }

    public org.resmedicinae.resmedlib.term.String getSomeOthers() {
        return this.someOthers;
    }

    public void setAccident(org.resmedicinae.resmedlib.term.String accident) {
        this.accident = accident;
    }

    public org.resmedicinae.resmedlib.term.String getAccident() {
        return this.accident;
    }

    public void setBVG(org.resmedicinae.resmedlib.term.String bVG) {
        this.bVG = bVG;
    }

    public org.resmedicinae.resmedlib.term.String getBVG() {
        return this.bVG;
    }

    public void setResources(org.resmedicinae.resmedlib.term.String resources) {
        this.resources = resources;
    }

    public org.resmedicinae.resmedlib.term.String getResources() {
        return this.resources;
    }

    public void setSerum(org.resmedicinae.resmedlib.term.String serum) {
        this.serum = serum;
    }

    public org.resmedicinae.resmedlib.term.String getSerum() {
        return this.serum;
    }

    public void setRequirement(org.resmedicinae.resmedlib.term.String requirement) {
        this.requirement = requirement;
    }

    public org.resmedicinae.resmedlib.term.String getRequirement() {
        return this.requirement;
    }

    public void setScriptMedicine(org.resmedicinae.resmedlib.term.String scriptMedicine) {
        this.scriptMedicine = scriptMedicine;
    }

    public org.resmedicinae.resmedlib.term.String getScriptMedicine() {
        return this.scriptMedicine;
    }

    public org.resmedicinae.resmedlib.term.String getTimestamp() {
        return timestamp;
    }

    public void setTimestamp(org.resmedicinae.resmedlib.term.String timestamp) {
        this.timestamp = timestamp;
    }

    public org.resmedicinae.resmedlib.term.String getBloodType() {
        return bloodType;
    }

    public void setBloodType(org.resmedicinae.resmedlib.term.String bloodType) {
        this.bloodType = bloodType;
    }

    public org.resmedicinae.resmedlib.term.String getHeight() {
        return height;
    }

    public void setHeight(org.resmedicinae.resmedlib.term.String height) {
        this.height = height;
    }

    public org.resmedicinae.resmedlib.term.String getWeight() {
        return weight;
    }

    public void setWeight(org.resmedicinae.resmedlib.term.String weight) {
        this.weight = weight;
    }

    /**
     *Gets the problems. The problems are held in a hashtable where the name of the problem is the key and the
     * problem itself is the value.
     * @return the problems of the healthRecord
     */
    public Object[] getProblems() {
        Object[] childrenArray = getChildren().values().toArray();
        Vector tempVector = new Vector();
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
            if (problem.getName().equals(problemName)) {
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

    /**
     *Converts the object to String. This is needed because of the tree table. The tree table nodes are named as
     * the object their represents. So the node will be called like the object.
     */
    public String toString() {
        return "Electronic Health Record";
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
                remove(problem.getIdentifier());
            }
        }
    }

    /**
     *Gets the CAVE entries
     * @return the problems of the patient
     */
    public Object[] getCaves() {
        Object[] childrenArray = getChildren().values().toArray();
        Vector tempVector = new Vector();
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
