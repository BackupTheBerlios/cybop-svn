/*
 * $RCSfile: SocketAddress.java,v $
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

package cybop.core.system.chain;

import cybop.core.model.Integer;
import cybop.core.model.String;

/**
 * This class represents a socket address.<br><br>
 *
 * @version $Revision: 1.6 $ $Date: 2003-05-20 06:21:59 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class SocketAddress extends Address {

    //
    // Children names.
    //

    /** The number. */
    public static final String NUMBER = new String("number");

    /** The port. */
    public static final String PORT = new String("port");

    //
    // Default children.
    //

    /**
     * Returns the default number.
     *
     * @return the default number
     */
    public String getDefaultNumber() {

        return new String("127.0.0.1");
    }

    /**
     * Returns the default port.
     *
     * @return the default port
     */
    public Integer getDefaultPort() {

        return new Integer(8005);
    }

    //
    // Initialization.
    //

    /**
     * Initializes this system.
     */
    public void initialize() throws Exception {

        super.initialize();

        setChildItem(SocketAddress.NUMBER, getDefaultNumber());
        setChildItem(SocketAddress.PORT, getDefaultPort());
    }

    /**
     * Finalizes this system.
     */
    public void finalizz() throws Exception {

        Integer port = (Integer) getChildItem(SocketAddress.PORT);
        removeChildItem(SocketAddress.PORT);
//??        destroyPort(port);

        String number = (String) getChildItem(SocketAddress.NUMBER);
        removeChildItem(SocketAddress.NUMBER);
//??        destroyNumber(number);

        super.finalizz();
    }
}

