/*
 * $RCSfile: Socket.java,v $
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

import cybop.core.basic.Integer;
import cybop.core.basic.String;
import cybop.core.system.System;
import cybop.core.system.chain.*;

/**
 * This class represents a socket.<br><br>
 *
 * A socket is an endpoint for communication between two machines.
 *
 * @version $Revision: 1.4 $ $Date: 2003-04-23 14:08:24 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class Socket extends System {

    //
    // Encapsulated java socket.
    //

    /**
     * Creates an encapsulated java socket.
     *
     * @return the encapsulated java socket
     */
    public java.lang.Object createJavaObject() {

        java.net.Socket s = new java.net.Socket();
        
        if (s != null) {

//??            s.open();

        } else {

            throw new NullPointerException("Could not create java socket. The java socket is null.");
        }

        return s;
    }

    /**
     * Destroys the encapsulated java socket.
     *
     * @param o the encapsulated java socket
     */
    public void destroyJavaObject(java.lang.Object o) {

        java.net.Socket s = (java.net.Socket) o;

        if (s != null) {

            try {

                s.close();
                
            } catch (Exception e) {
                
                java.lang.System.out.println("ERROR: Could not destroy java socket. An exception occured during socket closing.");
            }

        } else {

            throw new NullPointerException("Could not destroy java socket. The java socket is null.");
        }
    }

    //
    // Initialization.
    //

    /**
     * Initializes this socket.
     *
     * @exception NullPointerException if the configuration is null
     */
    public void initialize() throws Exception, NullPointerException {

        super.initialize();
    }

    /**
     * Finalizes this socket.
     *
     * @exception NullPointerException if the configuration is null
     */
    public void finalizz() throws Exception, NullPointerException {

        super.finalizz();
    }
}

