/*
 * $RCSfile: System.java,v $
 *
 * Copyright (c) 1999-2003. The Res Medicinae developers. All rights reserved.
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

package cybop.system;

import cybop.basic.*;
import cybop.basic.Boolean;
import cybop.basic.Integer;
import cybop.basic.String;
import cybop.model.*;
import cybop.model.model.*;
import cybop.model.model.user.*;
import cybop.signal.*;
import cybop.system.block.*;
import cybop.system.chain.*;
import cybop.system.region.controller.*;
import cybop.system.region.controller.translator.*;
import cybop.system.system.*;

/**
 * This class represents a system.<br><br>
 *
 * It is a super class and forms an own level in the framework's ontology:
 *  <ul>
 *      <li>Family</li>
 *      <li>System</li>
 *      <li>Block</li>
 *      <li>Region</li>
 *      <li>Component</li>
 *      <li>Part</li>
 *      <li>Chain</li>
 *  </ul>
 *
 * A system corresponds to an animal or human organism.<br><br>
 *
 * It is important to note that users of systems are treated as system
 * themselves. Taking the metapher of a system being a human person, each
 * system has capabilities to communicate with other systems, may it be alive users
 * (view/user interface) or programs running on the same (local communication)
 * or other machines (remote communication, persistence mechanism).
 *
 * @version $Revision: 1.1 $ $Date: 2003-02-19 07:46:09 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class System extends Block implements 
    java.lang.Runnable {

    //
    // Children.
    //

    /** The controller. */
    public static final String CONTROLLER = new String("controller");

    /** The socket address. */
    public static final String SOCKET_ADDRESS = new String("socket_address");

    /** The internet protocol 6 address. */
    public static final String IP6_ADDRESS = new String("ip6_address");

    /** The internet protocol 4 address. */
    public static final String IP4_ADDRESS = new String("ip4_address");

    /** The host name. */
    public static final String HOST_NAME = new String("host_name");

    /** The domain name. */
    public static final String DOMAIN_NAME = new String("domain_name");

    /** The communication partners count. */
    public static final String COMMUNICATION_PARTNERS_COUNT = new String("communication_partners_count");

    /** The communication partner. */
    public static final String COMMUNICATION_PARTNER = new String("communication_partner");

    /** The user. */
    public static final String USER = new String("user");

    //
    // Encapsulated java thread.
    //

    /**
     * Creates an encapsulated java thread.
     *
     * @return the encapsulated java thread
     */
    public java.lang.Object createJavaObject() {

        return new java.lang.Thread(this);
    }

    //
    // Default children.
    //

    /**
     * Returns the default controller.
     *
     * @return the default controller
     */
    public String getDefaultController() {

        return null;
    }

    /**
     * Returns the default socket address.
     *
     * @return the default socket address
     */
    public String getDefaultSocketAddress() {

        return null;
    }

    /**
     * Returns the default internet protocol 6 address.
     *
     * @return the default internet protocol 6 address
     */
    public String getDefaultIp6Address() {

        return null;
    }

    /**
     * Returns the default internet protocol 4 address.
     *
     * @return the default internet protocol 4 address
     */
    public String getDefaultIp4Address() {

        return null;
    }

    /**
     * Returns the default host name.
     *
     * @return the default host name
     */
    public String getDefaultHostName() {

        return null;
    }

    /**
     * Returns the default domain name.
     *
     * @return the default domain name
     */
    public String getDefaultDomainName() {

        return null;
    }

    /**
     * Returns the default communication partners count.
     *
     * @return the default communication partners count
     */
    public Integer getDefaultCommunicationPartnersCount() {

        return new Integer(0);
    }

    /**
     * Returns the default communication partner.
     *
     * @return the default communication partner
     */
    public String getDefaultCommunicationPartner() {

        return null;
    }

    /**
     * Returns the default user.
     *
     * @return the default user
     */
    public String getDefaultUser() {

        return null;
    }

    //
    // Initialization.
    //

    /**
     * Initializes this system.
     *
     * @exception NullPointerException if the configuration is null
     */
    public void initialize() throws Exception, NullPointerException {

        super.initialize();

        Configuration c = (Configuration) get(System.CONFIGURATION);

        if (c != null) {

            set(System.CONTROLLER, createComponent(getDefaultController()));
            set(System.SOCKET_ADDRESS, createComponent(getDefaultSocketAddress()));
            set(System.IP6_ADDRESS, createComponent(getDefaultIp6Address()));
            set(System.IP4_ADDRESS, createComponent(getDefaultIp4Address()));
            set(System.HOST_NAME, getDefaultHostName());
            set(System.DOMAIN_NAME, getDefaultDomainName());
            set(System.USER, createComponent(getDefaultUser()));

            //
            // Communication partners.
            //

/*??
            int i;
            String s = null;

            set(System.SYSTEMS_COUNT, c.get(System.SYSTEMS_COUNT, createSystemsCount()));

            if (get(System.SYSTEMS_COUNT) != null) {

                // Retrieve the number of systems and create them one by one.
                for (i = 0; i < ((Integer) get(System.SYSTEMS_COUNT)).getJavaPrimitive(); i++) {

                    s = new String(System.SYSTEM + "_" + java.lang.String.valueOf(i));

                    set(s, createSystem(c.get(loc, new String("")), c.get(args, new String("")), c.get(wp, new String(""))));

                    //?? Testing.
                    set(new String("system_test_user"), createSystem(c.get(loc, new String("cybop.system.system.User")), c.get(args, new String("")), c.get(wp, new String(""))));
                }
    
            } else {
    
                throw new NullPointerException("Could not initialize system. The systems count is null.");
            }
*/

        } else {

            throw new NullPointerException("Could not initialize system. The configuration is null.");
        }
    }

    /**
     * Finalizes this system.
     *
     * @exception NullPointerException if the configuration is null
     */
    public void finalizz() throws Exception, NullPointerException {

        Configuration c = (Configuration) get(System.CONFIGURATION);

        if (c != null) {

            //
            // Communication partners.
            //

/*??
            if (get(System.SYSTEMS_COUNT) != null) {

                String loc;
                String args; 
                String wp;
                System system = null;

                for (i = 0; i < ((Integer) get(System.SYSTEMS_COUNT)).getJavaPrimitive(); i++) {

                    s = new String(System.SYSTEM + "_" + java.lang.String.valueOf(i));
                    loc = new String(System.SYSTEM_LOCATION + "_" + java.lang.String.valueOf(i));
                    args = new String(System.SYSTEM_ARGUMENTS + "_" + java.lang.String.valueOf(i));
                    wp = new String(System.SYSTEM_WORKPATH + "_" + java.lang.String.valueOf(i));

                    c.set(loc, (String) get(loc));
                    c.set(args, (String) get(args));
                    c.set(wp, (String) get(wp));

                    system = (System) get(s);
                    remove(s);
                    destroySystem(system);
                }

                Integer systemsCount = (Integer) get(System.SYSTEMS_COUNT);
                c.set(System.SYSTEMS_COUNT, systemsCount);
                remove(System.SYSTEMS_COUNT);
                destroySystemsCount(systemsCount);

            } else {
    
                throw new NullPointerException("Could not finalize system. The systems count is null.");
            }
*/

            User user = (User) get(System.USER);
            remove(System.USER);
            destroyComponent(user);

            String domainName = (String) get(System.DOMAIN_NAME);
            remove(System.DOMAIN_NAME);
//??            destroyDomainName(domainName);

            String hostName = (String) get(System.HOST_NAME);
            remove(System.HOST_NAME);
//??            destroyHostName(hostName);

            Ip4Address ip4Address = (Ip4Address) get(System.IP4_ADDRESS);
            remove(System.IP4_ADDRESS);
            destroyItem(ip4Address);

            Ip6Address ip6Address = (Ip6Address) get(System.IP6_ADDRESS);
            remove(System.IP6_ADDRESS);
            destroyItem(ip6Address);

            SocketAddress socketAddress = (SocketAddress) get(System.SOCKET_ADDRESS);
            remove(System.SOCKET_ADDRESS);
            destroyItem(socketAddress);

            Controller controller = (Controller) get(System.CONTROLLER);
            remove(System.CONTROLLER);
            destroyComponent(controller);

        } else {

            throw new NullPointerException("Could not finalize system. The configuration is null.");
        }

        super.finalizz();
    }

    //
    // Running.
    //
    
    /**
     * Runs this system.
     *
     * This method is called only by the encapsulated java thread.
     * Do not use it elsewise!
     */
    public void run() {
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
     * @exception NullPointerException if the controller is null
     * @exception NullPointerException if the dummy flag is null
     */
    public void handle(Signal s, Boolean b) throws Exception, NullPointerException {

        Controller c = (Controller) get(System.CONTROLLER);

        if (c != null) {

            if (b != null) {

                if (b.isEqualTo(Boolean.FALSE)) {

                    c.control(s);

                } else {

                    c.controlAsServerDummy(s);
                }

            } else {

                throw new NullPointerException("Could not handle signal. The dummy flag is null.");
            }

        } else {

            log(System.DEBUG_LOG_LEVEL, "Could not handle signal. The controller is null.");
        }
    }
}

