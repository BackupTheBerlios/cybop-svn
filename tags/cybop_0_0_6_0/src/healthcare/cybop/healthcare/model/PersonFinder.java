/*
 * $RCSfile: PersonFinder.java,v $
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
 * http://www.cybop.net
 * - Cybernetics Oriented Programming -
 */

package cybop.healthcare.model;

import java.lang.*;
import java.sql.*;
import java.util.*;

/**
 * Temporary!! Only an EXAMPLE class. "Domain Object Finder"
 *
 * @version $Revision: 1.3 $ $Date: 2003-02-20 15:35:14 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class PersonFinder {

    /** The constant indicating the columns to select in the database. */
/*??
    public static final String COLUMNS = "id, lastname, firstname, number_of_dependents ";

    /** The find last name statement. */
/*??
    private static final String findLastNameStatement
        = "SELECT "
        + COLUMNS
        + "FROM people "
        + "WHERE UPPER(lastname) like UPPER(?) "
        + "ORDER BY lastname";

    /** The update statement. */
/*??
    private static final String updateStatement
        = "UPDATE people "
        + "SET lastname = ?, firstname = ?, number_of_dependents = ? "
        + "WHERE id = ?";

    /**
     * Returns the find statement.
     *
     * @return the find statement
     */
/*??
    public String getFindStatement() {

        return "SELECT " + COLUMNS + " FROM people WHERE id = ?";
    }

    /**
     * Returns the insert statement.
     *
     * @return the insert statement
     */
/*??
    public String getInsertStatement() {

        return "INSERT INTO people VALUES (?, ?, ?, ?)";
    }

    /**
     * Finds objects by last name.
     *
     * @param name the last name
     * @return the list of found objects
     * @exception NullPointerException if the result object list is null
     * @exception NullPointerException if the find statement is null
     * @exception NullPointerException if the result set is null
     */
/*??
    public List findByLastName(String name) throws NullPointerException {

        List l = new ArrayList();
        PreparedStatement s;
        ResultSet rs = null;

        if (l != null) {

            s = ""; //??DB.prepare(findLastNameStatement);

            if (s != null) {

                s.setString(1, name);

                try {

                    rs = s.executeQuery();

                    if (rs != null) {

                        while (rs.next()) {

                            l.add(load(rs));
                        }

                    } else {

                        throw new NullPointerException("Could not assemble result object list. The result set is null.");
                    }

                } catch (SQLException e) {

                    throw new ApplicationException(e);

                } finally {

                    DB.cleanUp(s, rs);
                }

            } else {

                throw new NullPointerException("Could not execute query. The find statement is null.");
            }

        } else {

            throw new NullPointerException("Could not find object by last name. The result object list is null.");
        }

        return l;
    }
*/

    /**
     * Loads a domain object.
     *
     * @param id the domain object id
     * @param rs the result set
     * @return the domain object
     * @exception NullPointerException if the map of loaded domain objects is null
     * @exception NullPointerException if the result set is null
     * @exception NullPointerException if the mapper is null
     */
/*??
    protected DomainObject load(Long id, ResultSet rs) throws NullPointerException {

        super.load(id, rs);

        if (o == null) {

            o = new PersonImpl();
            Map m = getLoadedObjects();

            if (m != null) {

                if (rs != null) {

                    long l = rs.getLong("id");
                    Long id = new Long(l);

                    // First, put the empty object to the map.
                    m.put(id, o);

                    // Then, load the object data.
                    // This is to avoid cyclic references, if another object
                    // to be set here would have a reference to this object.
                    // The empty object was put to the map above to stop the
                    // recursive loading. If now there is a cycle, the identity
                    // map will return that object and such stop recursion.
                    Mapper mapper = getMapper();

                    if (mapper != null) {

                        mapper.load(o, rs);

                    } else {

                        throw new NullPointerException("Could not load domain object. The mapper is null.");
                    }

                } else {

                    throw new NullPointerException("Could not load domain object. The result set is null.");
                }

            } else {

                throw new NullPointerException("Could not load domain object. The map of loaded domain objects is null.");
            }
        }

        return o;
    }
*/

    /**
     * Updates the database with the given person data.
     *
     * @param o the domain object
     * @param s the prepared statement
     * @exception NullPointerException if the update statement is null
     * @exception NullPointerException if the domain object is null
     */
/*??
    public void update(DomainObject o, PreparedStatement s) throws NullPointerException {

        super.update(o, s);

        try {

            PreparedStatement s = ""; //??DB.prepare(updateStatementString);
            Mapper mapper = getMapper();

            if (mapper != null) {

                mapper.update(o, s);

            } else {

                throw new NullPointerException("Could not load domain object. The mapper is null.");
            }

            if (s != null) {

                s.execute();

            } else {

                throw new NullPointerException("Could not load domain object. The result set is null.");
            }

        } finally {

//??            DB.cleanUp(s);
        }
    }
*/
}

