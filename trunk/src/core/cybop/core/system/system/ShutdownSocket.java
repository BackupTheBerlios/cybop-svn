/*
 * $RCSfile: ShutdownSocket.java,v $
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

import cybop.core.model.Boolean;
import cybop.core.model.String;
import cybop.core.signal.*;
import cybop.core.system.chain.*;

/**
 * This class represents a shutdown socket.<br><br>
 *
 * It is the communication partner that can be asked by another system
 * to shutdown a system.
 *
 * @version $Revision: 1.8 $ $Date: 2003-06-12 21:16:11 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class ShutdownSocket extends Socket {

    //
    // Actions.
    //

    /** The shutdown system action. */
    public static final String SHUTDOWN_SYSTEM_ACTION = new String("shutdown_system_action");

    //
    // Default children.
    //

    /**
     * Returns the default socket address.
     *
     * @return the default socket address
     */
    public String getDefaultSocketAddress() {

        return new String("cybop.core.system.chain.SocketAddress");
    }

    //
    // Signal handling.
    //

    /**
     * Handles the signal.
     *
     * @param s the signal
     * @param d the dummy flag indicating whether this system is a:
     * <ul>
     *     <li>false: normal system (client or server) that handles messages</li>
     *     <li>true: local server dummy which represents a remote system and
     *     needs to forward messages to the actual server</li>
     * </ul>
     * @exception Exception if the signal is null
     * @exception Exception if the action is null
     */
    public void handle(Signal s, Boolean b) throws Exception {

        super.handle(s, b);

        if (s != null) {

            String a = (String) s.getChild(Signal.PREDICATE);

            if (a != null) {

                if (a.isEqualTo(ShutdownSocket.SHUTDOWN_SYSTEM_ACTION)) {

                    shutdownSystem();
                }

            } else {

                throw new Exception("Could not handle signal. The action is null.");
            }

        } else {

            throw new Exception("Could not handle signal. The signal is null.");
        }
    }

    /**
     * Shuts down the system.
     *
     * @exception Exception if the output stream is null
     * @exception Exception if the shutdown system action is null
     */
    public void shutdownSystem() throws Exception {

/*??
        String s = ShutdownSocket.SHUTDOWN_SYSTEM_ACTION;

        if (s != null) {

            java.io.OutputStream stream = (OutputStream) getChild(ShutdownSocket.OUTPUT_STREAM);

            if (stream != null) {
                
                int i = 0;

                while (i < s.length()) {

                    stream.write(s.charAt(i));

                    i++;
                }

                stream.flush();
                stream.close();

            } else {

                throw new Exception("Could not shutdown system. The output stream is null.");
            }

        } else {

            throw new Exception("Could not shutdown system. The shutdown system action is null.");
        }
*/
    }
}

