/*
 * $RCSfile: Contact.java,v $
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

/**
 * This class represents a contact.<br><br> A contact gives information about how to get in touch with a
 * patient, e.g. his/her address.
 * @version $Revision: 1.1 $ $Date: 2003-02-18 14:47:46 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class Contact extends Unit {
    //
    // Attributes.
    //

    /** The photo. */
    private String photo;

    /** The family name. */
    private String familyName;

    /** The family name at birth. */
    private String birthName;

    /** The given names. */
    private String givenNames;

    /** The first name. */
    private String firstName;

    /** The nick name. */
    private String nickName;

    /** The artist or stage name. */
    private String stageName;

    /** The title. */
    private String title;

    /** The date of birth. */
    private String birthDate;

    /** The place of birth. */
    private String birthPlace;

    /** The country of origin. */
    private String originCountry;

    /** The body height. */
    private String bodyHeight;

    /** The body weight. */
    private String bodyWeight;

    /** The eye color. */
    private String eyeColor;

    /** The profession. */
    private String profession;

    /** The job. */
    private String job;

    /** The experiences. */
    private String experiences;

    /** The languages. */
    private String languages;

    /** The father. */
    private String father;

    /** The mother. */
    private String mother;

    /** The partner. */
    private String partner;

    /** The children. */
    private String children;

    /** The flag indicating a single. */
    private String isSingle;

    /** The flag indicating a married person. */
    private String isMarried;

    /** The flag indicating a divorced person. */
    private String isDivorced;

    /** The flag indicating a widowed person. */
    private String isWidowed;

    /** The institution. */
    private String institution;

    /** The room. */
    private String room;

    /** The house. */
    private String house;

    /** The street. */
    private String street;

    /** The place. */
    private String place;

    /** The post code. */
    private String postCode;

    /** The county. */
    private String county;

    /** The state. */
    private String state;

    /** The country. */
    private String country;

    /** The mobile. */
    private String mobile;

    /** The phone. */
    private String phone;

    /** The fax. */
    private String fax;

    /** The email. */
    private String email;

    /** The web. */
    private String web;

    /** The keywords. */
    private String keywords;
    //
    // Photo.
    //

    /**
     * Returns the photo.
     * @return the photo
     */
    public String getPhoto() {
        return this.photo;
    }

    /**
     * Sets the photo.
     * @param photo the photo
     */
    public void setPhoto(String photo) {
        this.photo = photo;
    }
    //
    // Family name.
    //

    /**
     * Returns the family name.
     * @return the family name
     */
    public String getFamilyName() {
        return this.familyName;
    }

    /**
     * Sets the family name.
     * @param familyName the family name
     */
    public void setFamilyName(String familyName) {
        this.familyName = familyName;
    }
    //
    // Birth name.
    //

    /**
     * Returns the family name at birth.
     * @return the family name at birth
     */
    public String getBirthName() {
        return this.birthName;
    }

    /**
     * Sets the family name at birth.
     * @param birthName the family name at birth
     */
    public void setBirthName(String birthName) {
        this.birthName = birthName;
    }
    //
    // Given names.
    //

    /**
     * Returns the given names.
     * @return the given names
     */
    public String getGivenNames() {
        return this.givenNames;
    }

    /**
     * Sets the given names.
     * @param givenNames the given names
     */
    public void setGivenNames(String givenNames) {
        this.givenNames = givenNames;
    }
    //
    // First name.
    //

    /**
     * Returns the first name.
     * @return the first name
     */
    public String getFirstName() {
        return this.firstName;
    }

    /**
     * Sets the first name.
     * @param firstName the first name
     */
    public void setFirstName(String firstName) {
        this.firstName = firstName;
    }
    //
    // Nick name.
    //

    /**
     * Returns the short or nick name.
     * @return the short or nick name
     */
    public String getNickName() {
        return this.nickName;
    }

    /**
     * Sets the short or nick name.
     * @param nickName the short or nick name
     */
    public void setNickName(String nickName) {
        this.nickName = nickName;
    }
    //
    // Stage name.
    //

    /**
     * Returns the artist or stage name.
     * @return the artist or stage name
     */
    public String getStageName() {
        return this.stageName;
    }

    /**
     * Sets the artist or stage name.
     * @param stageName the artist or stage name
     */
    public void setStageName(String stageName) {
        this.stageName = stageName;
    }
    //
    // Title.
    //

    /**
     * Returns the title.
     * @return the title
     */
    public String getTitle() {
        return this.title;
    }

    /**
     * Sets the title.
     * @param title the title
     */
    public void setTitle(String title) {
        this.title = title;
    }
    //
    // Birth date.
    //

    /**
     * Returns the date of birth.
     * @return the date of birth
     */
    public String getBirthDate() {
        return this.birthDate;
    }

    /**
     * Sets the date of birth.
     * @param birthDate the date of birth
     */
    public void setBirthDate(String birthDate) {
        this.birthDate = birthDate;
    }
    //
    // Birth place.
    //

    /**
     * Returns the place of birth.
     * @return the place of birth
     */
    public String getBirthPlace() {
        return this.birthPlace;
    }

    /**
     * Sets the place of birth.
     * @param birthPlace the place of birth
     */
    public void setBirthPlace(String birthPlace) {
        this.birthPlace = birthPlace;
    }
    //
    // Country of Origin.
    //

    /**
     * Returns the country of origin.
     * @return the country of origin
     */
    public String getOriginCountry() {
        return this.originCountry;
    }

    /**
     * Sets the country of origin.
     * @param originCountry the country of origin
     */
    public void setOriginCountry(String originCountry) {
        this.originCountry = originCountry;
    }
    //
    // Body height.
    //

    /**
     * Returns the body height.
     * @return the body height
     */
    public String getBodyHeight() {
        return this.bodyHeight;
    }

    /**
     * Sets the body height.
     * @param bodyHeight the body height
     */
    public void setBodyHeight(String bodyHeight) {
        this.bodyHeight = bodyHeight;
    }
    //
    // Body weight.
    //

    /**
     * Returns the body weight.
     * @return the body weight
     */
    public String getBodyWeight() {
        return this.bodyWeight;
    }

    /**
     * Sets the body weight.
     * @param bodyWeight the body weight
     */
    public void setBodyWeight(String bodyWeight) {
        this.bodyWeight = bodyWeight;
    }
    //
    // Color of eyes.
    //

    /**
     * Returns the color of eyes.
     * @return the color of eyes
     */
    public String getEyeColor() {
        return this.eyeColor;
    }

    /**
     * Sets the color of eyes.
     * @param eyeColor the color of eyes
     */
    public void setEyeColor(String eyeColor) {
        this.eyeColor = eyeColor;
    }
    //
    // Profession.
    //

    /**
     * Returns the profession.
     * @return the profession
     */
    public String getProfession() {
        return this.profession;
    }

    /**
     * Sets the profession.
     * @param profession the profession
     */
    public void setProfession(String profession) {
        this.profession = profession;
    }
    //
    // Job.
    //

    /**
     * Returns the job.
     * @return the job
     */
    public String getJob() {
        return this.job;
    }

    /**
     * Sets the job.
     * @param job the job
     */
    public void setJob(String job) {
        this.job = job;
    }
    //
    // Experiences.
    //

    /**
     * Returns the experiences.
     * @return the experiences
     */
    public String getExperiences() {
        return this.experiences;
    }

    /**
     * Sets the experiences.
     * @param experiences the experiences
     */
    public void setExperiences(String experiences) {
        this.experiences = experiences;
    }
    //
    // Languages.
    //

    /**
     * Returns the languages.
     * @return the languages
     */
    public String getLanguages() {
        return this.languages;
    }

    /**
     * Sets the languages.
     * @param languages the languages
     */
    public void setLanguages(String languages) {
        this.languages = languages;
    }
    //
    // Father.
    //

    /**
     * Returns the father.
     * @return the father
     */
    public String getFather() {
        return this.father;
    }

    /**
     * Sets the father.
     * @param father the father
     */
    public void setFather(String father) {
        this.father = father;
    }
    //
    // Mother.
    //

    /**
     * Returns the mother.
     * @return the mother
     */
    public String getMother() {
        return this.mother;
    }

    /**
     * Sets the mother.
     * @param mother the mother
     */
    public void setMother(String mother) {
        this.mother = mother;
    }
    //
    // Partner.
    //

    /**
     * Returns the partner.
     * @return the partner
     */
    public String getPartner() {
        return this.partner;
    }

    /**
     * Sets the partner
     * @param partner the partner
     */
    public void setPartner(String partner) {
        this.partner = partner;
    }
    //
    // Children.
    //

    /**
     * Returns the children.
     * @return the children
     */

/*??
    public String getChildren() {

        return this.children;
    }

    /**
     * Sets the children.
     *
     * @param children the children
     */

/*??
    public void setChildren(String children) {

        this.children = children;
    }

    //
    // Single flag.
    //

    /**
     * Returns the flag indicating a single.
     *
     * @return the flag indicating a single
     */

    public String getIsSingle() {
        return this.isSingle;
    }

    /**
     * Sets the flag indicating a single.
     * @param isSingle the flag indicating a single
     */
    public void setIsSingle(String isSingle) {
        this.isSingle = isSingle;
    }
    //
    // Married flag.
    //

    /**
     * Returns the flag indicating a married person.
     * @return the flag indicating a married person
     */
    public String getIsMarried() {
        return this.isMarried;
    }

    /**
     * Sets the flag indicating a married person.
     * @param isMarried the flag indicating a married person
     */
    public void setIsMarried(String isMarried) {
        this.isMarried = isMarried;
    }
    //
    // Divorced flag.
    //

    /**
     * Returns the flag indicating a divorced person.
     * @return the flag indicating a divorced person
     */
    public String getIsDivorced() {
        return this.isDivorced;
    }

    /**
     * Sets the flag indicating a divorced person.
     * @param isDivorced the flag indicating a divorced person
     */
    public void setIsDivorced(String isDivorced) {
        this.isDivorced = isDivorced;
    }
    //
    // Widowed flag.
    //

    /**
     * Returns the flag indicating a widowed person.
     * @return the flag indicating a widowed person
     */
    public String getIsWidowed() {
        return this.isWidowed;
    }

    /**
     * Sets the flag indicating a widowed person.
     * @param isWidowed the flag indicating a widowed person
     */
    public void setIsWidowed(String isWidowed) {
        this.isWidowed = isWidowed;
    }
    //
    // Institution.
    //

    /**
     * Returns the institution.
     * @return the institution
     */
    public String getInstitution() {
        return this.institution;
    }

    /**
     * Sets the institution.
     * @param institution the institution
     */
    public void setInstitution(String institution) {
        this.institution = institution;
    }
    //
    // Room.
    //

    /**
     * Returns the room.
     * @return the room
     */
    public String getRoom() {
        return this.room;
    }

    /**
     * Sets the room.
     * @param room the room
     */
    public void setRoom(String room) {
        this.room = room;
    }
    //
    // House.
    //

    /**
     * Returns the house.
     * @return the house
     */
    public String getHouse() {
        return this.house;
    }

    /**
     * Sets the house.
     * @param house the house
     */
    public void setHouse(String house) {
        this.house = house;
    }
    //
    // Street.
    //

    /**
     * Returns the street.
     * @return the street
     */
    public String getStreet() {
        return this.street;
    }

    /**
     * Sets the street.
     * @param street the street
     */
    public void setStreet(String street) {
        this.street = street;
    }
    //
    // Place.
    //

    /**
     * Returns the place.
     * @return the place
     */
    public String getPlace() {
        return this.place;
    }

    /**
     * Sets the place.
     * @param place the place
     */
    public void setPlace(String place) {
        this.place = place;
    }
    //
    // Postcode.
    //

    /**
     * Returns the postcode.
     * @return the postcode
     */
    public String getPostcode() {
        return this.postCode;
    }

    /**
     * Sets the postcode.
     * @param postCode the postcode
     */
    public void setPostcode(String postCode) {
        this.postCode = postCode;
    }
    //
    // County.
    //

    /**
     * Returns the county.
     * @return the county
     */
    public String getCounty() {
        return this.county;
    }

    /**
     * Sets the county.
     * @param county the county
     */
    public void setCounty(String county) {
        this.county = county;
    }
    //
    // State.
    //

    /**
     * Returns the state.
     * @return the state
     */
    public String getState() {
        return this.state;
    }

    /**
     * Sets the state.
     * @param state the state
     */
    public void setState(String state) {
        this.state = state;
    }
    //
    // Country.
    //

    /**
     * Returns the country.
     * @return the country
     */
    public String getCountry() {
        return this.country;
    }

    /**
     * Sets the country.
     * @param country the country
     */
    public void setCountry(String country) {
        this.country = country;
    }
    //
    // Mobile.
    //

    /**
     * Returns the mobile.
     * @return the mobile
     */
    public String getMobile() {
        return this.mobile;
    }

    /**
     * Sets the mobile.
     * @param mobile the mobile
     */
    public void setMobile(String mobile) {
        this.mobile = mobile;
    }
    //
    // Phone.
    //

    /**
     * Returns the phone.
     * @return the phone
     */
    public String getPhone() {
        return this.phone;
    }

    /**
     * Sets the phone.
     * @param phone the phone
     */
    public void setPhone(String phone) {
        this.phone = phone;
    }
    //
    // Fax.
    //

    /**
     * Returns the fax.
     * @return the fax
     */
    public String getFax() {
        return this.fax;
    }

    /**
     * Sets the fax.
     * @param fax the fax
     */
    public void setFax(String fax) {
        this.fax = fax;
    }
    //
    // Email.
    //

    /**
     * Returns the email.
     * @return the email
     */
    public String getEmail() {
        return this.email;
    }

    /**
     * Sets the email.
     * @param email the email
     */
    public void setEmail(String email) {
        this.email = email;
    }
    //
    // Web.
    //

    /**
     * Returns the web.
     * @return the web
     */
    public String getWeb() {
        return this.web;
    }

    /**
     * Sets the web.
     * @param web the web
     */
    public void setWeb(String web) {
        this.web = web;
    }
    //
    // Keywords.
    //

    /**
     * Returns the keywords.
     * @return the keywords
     */
    public String getKeywords() {
        return this.keywords;
    }

    /**
     * Sets the keywords.
     * @param keywords the keywords
     */
    public void setKeywords(String keywords) {
        this.keywords = keywords;
    }
}
