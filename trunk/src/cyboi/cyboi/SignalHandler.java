/*
 * $RCSfile: SignalHandler.java,v $
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

package cyboi;

/**
 * This is a signal handler.
 *
 * It offers signal processing procedures which should be called in the following order:
 *
 * receive
 * handle
 * send
 * reset
 *
 * @version $Revision: 1.3 $ $Date: 2003-07-27 17:55:11 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
class SignalHandler {

    //
    // Constants.
    //

    /** The priority. */
    static java.lang.String PRIORITY = "priority";

    /** The language. */
    static java.lang.String LANGUAGE = "language";

    /** The subject (signal receiver). */
    static java.lang.String SUBJECT = "subject";

    /** The predicate (action). */
    static java.lang.String PREDICATE = "predicate";

    /** The (genitiv) object (object owner). */
//??    static java.lang.String SENDER_OBJECT = "object";

    /** The (dativ) object (signal sender). */
    static java.lang.String SENDER_OBJECT = "sender_object";

    /** The (akussativ) object (passive data model). */
    static java.lang.String OBJECT = "object";

    /** The adverbial (temporal, local, causal). */
    static java.lang.String ADVERBIAL = "adverbial";

    /** The pre/post condition (conditional clause). */
    static java.lang.String CONDITION = "condition";

    //
    // Priorities.
    //

    /** The normal priority. */
    static java.lang.String NORMAL_PRIORITY = "1";

    //
    // Languages.
    //

    /** The system internal (neuro) language. */
    static java.lang.String NEURO_LANGUAGE = "neuro_language";

    /** The textual user interface (tui) language. */
    static java.lang.String TUI_LANGUAGE = "tui_language";

    /** The mouse language. */
    static java.lang.String MOUSE_LANGUAGE = "mouse_language";

    /** The graphical user interface (gui) language. */
    static java.lang.String GUI_LANGUAGE = "gui_language";

    /** The socket language. */
    static java.lang.String SOCKET_LANGUAGE = "socket_language";

    /** The structured query language (sql). */
    static java.lang.String SQ_LANGUAGE = "sq_language";

    /** The java messaging service (jms) language. */
    static java.lang.String JMS_LANGUAGE = "jms_language";

    /** The remote method invocation (rmi) language. */
    static java.lang.String RMI_LANGUAGE = "rmi_language";

    /** The common object request broker architecture (corba) language. */
    static java.lang.String CORBA_LANGUAGE = "corba_language";

    /** The extensible markup language (xml). */
    static java.lang.String XM_LANGUAGE = "xm_language";

    /** The simple object access protocol (soap) language. */
    static java.lang.String SOAP_LANGUAGE = "soap_language";

    //
    // Signal management.
    //
    
    /**
     * Receives the signal.
     *
     * @param s the signal
     */
    static void receive(java.lang.Object s) {
        
        if (s != null) {

        } else {

            java.lang.System.out.println("ERROR: Could not receive signal. The signal is null.");
        }
    }

    /**
     * Handles the signal.
     *
     * @param o the signal
     * @param r the remote flag
     * @return the shutdown flag
     */
    static int handle(java.lang.Object o, int r) {
        
        int sf = 0;
        Item s = (Item) o;
                
        if (s != null) {

            java.lang.String p = (java.lang.String) MapHandler.get_map_element(s.items, "predicate_0");

            if (p != null) {

                if (p.equals("shutdown")) {
                    
                    sf = 1;
                }
                
            } else {
    
//??                java.lang.System.out.println("ERROR: Could not handle signal. The predicate is null.");
            }
    
        } else {

            java.lang.System.out.println("ERROR: Could not handle signal. The signal is null.");
        }
        
        return sf;
    }

    /**
     * Sends the signal.
     *
     * @param s the signal
     */
    static void send(java.lang.Object s) {
        
        if (s != null) {

        } else {

            java.lang.System.out.println("ERROR: Could not send signal. The signal is null.");
        }
    }

    /**
     * Resets the signal.
     *
     * @param s the signal
     */
    static void reset(java.lang.Object s) {
        
        if (s != null) {

        } else {

            java.lang.System.out.println("ERROR: Could not reset signal. The signal is null.");
        }
    }
}

