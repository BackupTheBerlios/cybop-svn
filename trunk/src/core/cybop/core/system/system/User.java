/*
 * $RCSfile: User.java,v $
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

package cybop.core.system.system;

import cybop.core.model.String;
import cybop.core.system.System;
import cybop.core.system.block.*;

/**
 * This class represents a user.<br><br>
 *
 * A user is nothing else than another system, only that it/he/she is alive.
 * Systems can communicate with each other and it doesn't matter whether
 * the systems are machines or users.
 *
 * @version $Revision: 1.7 $ $Date: 2003-06-12 21:16:11 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class User extends System {

    //
    // Children names.
    //

    /** The login. */
    public static final String LOGIN = new String("login");

    /** The password. */
    public static final String PASSWORD = new String("password");

    //
    // Default children.
    //

    /**
     * Returns the default login.
     *
     * @return the default login
     */
    public String getDefaultLogin() {
     
        return null;
    }

    /**
     * Returns the default password.
     *
     * @return the default password
     */
    public String getDefaultPassword() {

        return null;
    }

    //
    // Initialization.
    //
    
    /**
     * Initializes this user.
     */
    public void initialize() throws Exception {

        super.initialize();

        setChild(User.LOGIN, getDefaultLogin());
        setChild(User.PASSWORD, getDefaultPassword());
    }

    /**
     * Finalizes this user.
     */
    public void finalizz() throws Exception {

        removeChild(User.PASSWORD);

        removeChild(User.LOGIN);

        super.finalizz();
    }
}

