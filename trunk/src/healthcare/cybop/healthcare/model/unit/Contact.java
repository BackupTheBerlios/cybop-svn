/*
 * $RCSfile: Contact.java,v $
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
 * http://www.resmedicinae.org
 * - Information in Medicine -
 */

package cybop.healthcare.model.unit;

import cybop.core.basic.String;
import cybop.healthcare.model.*;

/**
 * This class represents a contact.<br><br>
 *
 * A contact gives information about how to get in touch with a
 * patient, e.g. his/her address.
 *
 * @version $Revision: 1.2 $ $Date: 2003-02-19 17:15:17 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class Contact extends Unit {

    //
    // Children.
    //

    /** The photo. */
    public static final String PHOTO = new String("photo");

    /** The family name. */
    public static final String FAMILY_NAME = new String("family_name");

    /** The family name at birth. */
    public static final String BIRTH_NAME = new String("birth_name");

    /** The given names. */
    public static final String GIVEN_NAMES = new String("given_names");

    /** The first name. */
    public static final String FIRST_NAME = new String("first_name");

    /** The nick name. */
    public static final String NICK_NAME = new String("nick_name");

    /** The artist or stage name. */
    public static final String ARTIST_NAME = new String("artist_name");

    /** The title. */
    public static final String TITLE = new String("title");

    /** The date of birth. */
    public static final String BIRTH_DATE = new String("birth_date");

    /** The place of birth. */
    public static final String BIRTH_PLACE = new String("birth_place");

    /** The country of origin. */
    public static final String ORIGIN_COUNTRY = new String("origin_country");

    /** The profession. */
    public static final String PROFESSION = new String("profession");

    /** The job. */
    public static final String JOB = new String("job");

    /** The experiences. */
    public static final String EXPERIENCES = new String("experiences");

    /** The languages. */
    public static final String LANGUAGES = new String("languages");

    /** The mother. */
    public static final String MOTHER = new String("mother");

    /** The father. */
    public static final String FATHER = new String("father");

    /** The partner. */
    public static final String PARTNER = new String("partner");

    /** The children. */
    public static final String CHILDREN = new String("children");

    /** The marital status. */
    public static final String MARITAL_STATUS = new String("marital_status");

    /** The institution. */
    public static final String INSTITUTION = new String("institution");

    /** The room. */
    public static final String ROOM = new String("room");

    /** The house. */
    public static final String HOUSE = new String("house");

    /** The street. */
    public static final String STREET = new String("street");

    /** The place. */
    public static final String PLACE = new String("place");

    /** The post code. */
    public static final String POST_CODE = new String("post_code");

    /** The county. */
    public static final String COUNTY = new String("county");

    /** The state. */
    public static final String STATE = new String("state");

    /** The country. */
    public static final String COUNTRY = new String("country");

    /** The mobile. */
    public static final String MOBILE = new String("mobile");

    /** The phone. */
    public static final String PHONE = new String("phone");

    /** The fax. */
    public static final String FAX = new String("fax");

    /** The email. */
    public static final String EMAIL = new String("email");

    /** The web. */
    public static final String WEB = new String("web");

    /** The keywords. */
    public static final String KEYWORDS = new String("keywords");

    //
    // Marital stati.
    //

    /** The single marital status. */
    public static final Integer SINGLE_MARITAL_STATUS = new Integer(0);

    /** The married marital status. */
    public static final Integer MARRIED_MARITAL_STATUS = new Integer(1);

    /** The divorced marital status. */
    public static final Integer DIVORCED_MARITAL_STATUS = new Integer(2);

    /** The widowed marital status. */
    public static final Integer WIDOWED_MARITAL_STATUS = new Integer(3);
}

