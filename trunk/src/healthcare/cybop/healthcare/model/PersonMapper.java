/*
 * $RCSfile: PersonMapper.java,v $
 *
 * Copyright (c) 1999-2002. Christian Heller. All rights reserved.
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

import java.lang.*;
import java.sql.*;
import java.util.*;

/**
 * Temporary!! Only an EXAMPLE class. "Domain Object Mapper"
 *
 * @version $Revision: 1.1 $ $Date: 2003-02-18 14:47:46 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class PersonMapper {

    /**
     * Loads data from the result set into the domain object.
     *
     * @param o the domain object
     * @param rs the result set
     * @exception NullPointerException if the domain object is null
     * @exception NullPointerException if the result set is null
     */
/*??
    public void load(DomainObject o, ResultSet rs) throws NullPointerException {

        super.load();

        Person p = (PersonImpl) o;

        if (p != null) {

            if (rs != null) {

                p.setName(rs.getString("name"));
                p.setFirstName(rs.getString("first_name"));
                p.setBirthDate(rs.getString(3));
                p.setAge(rs.getInt(4));

            } else {

                throw new NullPointerException("Could not load domain object. The result set is null.");
            }

        } else {

            throw new NullPointerException("Could not load domain object. The domain object is null.");
        }
    }
*/

    /**
     * Updates the database with the given domain object data.
     *
     * @param o the domain object
     * @param s the prepared statement
     * @exception NullPointerException if the update statement is null
     * @exception NullPointerException if the domain object is null
     */
/*??
    public void update(DomainObject o, PreparedStatement s) throws NullPointerException {

        super.update();

        if (s != null) {

            Person p = (PersonImpl) o;

            if (p != null) {

                s.setString(1, p.getLastName());
                s.setString(2, p.getFirstName());

            } else {

                throw new NullPointerException("Could not update database. The domain object is null.");
            }

        } else {

            throw new NullPointerException("Could not update database. The update statement is null.");
        }
    }
*/

    /**
     * Inserts the domain object into the database.
     *
     * @param o the domain object
     * @param s the update statement
     * @exception NullPointerException if the insert statement is null
     * @exception NullPointerException if the domain object is null
     */
/*??
    public void insert(DomainObject o, PreparedStatement s) throws NullPointerException {

        super.insert();

        if (s != null) {

            Person p = (PersonImpl) o;

            if (p != null) {

                s.setString(2, p.getLastName());
                s.setString(3, p.getFirstName());
                s.setInt(4, p.getNumberOfDependents());

            } else {

                throw new NullPointerException("Could not update database. The domain object is null.");
            }

        } else {

            throw new NullPointerException("Could not update database. The insert statement is null.");
        }
    }
*/
}

