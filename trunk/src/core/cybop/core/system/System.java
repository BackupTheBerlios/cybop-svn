/*
 * $RCSfile: System.java,v $
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

package cybop.core.system;

import cybop.core.basic.*;
import cybop.core.basic.Boolean;
import cybop.core.basic.Integer;
import cybop.core.basic.String;
import cybop.core.model.*;
import cybop.core.model.model.*;
import cybop.core.model.model.user.*;
import cybop.core.signal.*;
import cybop.core.system.block.*;
import cybop.core.system.chain.*;
import cybop.core.system.region.controller.*;
import cybop.core.system.region.controller.translator.*;
import cybop.core.system.system.*;

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
 * @version $Revision: 1.7 $ $Date: 2003-04-23 16:03:25 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class System extends Block implements 
    java.lang.Runnable {

    //
    // Children names.
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
    // Children category names.
    //

    /** The controller category. */
    public static final String CONTROLLER_CATEGORY = new String("controller_category");

    /** The socket address category. */
    public static final String SOCKET_ADDRESS_CATEGORY = new String("socket_address_category");

    /** The internet protocol 6 address category. */
    public static final String IP6_ADDRESS_CATEGORY = new String("ip6_address_category");

    /** The internet protocol 4 address category. */
    public static final String IP4_ADDRESS_CATEGORY = new String("ip4_address_category");

    /** The host name category. */
    public static final String HOST_NAME_CATEGORY = new String("host_name_category");

    /** The domain name category. */
    public static final String DOMAIN_NAME_CATEGORY = new String("domain_name_category");

    /** The communication partners count category. */
    public static final String COMMUNICATION_PARTNERS_COUNT_CATEGORY = new String("communication_partners_count_category");

    /** The communication partner category. */
    public static final String COMMUNICATION_PARTNER_CATEGORY = new String("communication_partner_category");

    /** The user category. */
    public static final String USER_CATEGORY = new String("user_category");

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
    // Child management.
    //

    /**
     * Creates a system.
     *
     * @param n the system class name
     * @param l the configuration location
     * @return the system
     * @exception NullPointerException if the system class is null
     * @exception NullPointerException if the system is null
     */
    public System createSystem(String n, String l) throws Exception, NullPointerException {

        System s = null;

        // If a system class name is set to null, then don't try to create the system.
        if (n != null) {

            // Find class by name.
            Class cl = Class.forName((java.lang.String) n.getJavaObject());

            if (cl != null) {

                // Create system from given class.
                s = (System) cl.newInstance();

                if (s != null) {

                    java.lang.System.out.println("INFO: Set global system items.");
                    s.set(System.CONFIGURATION, createItem(new String("cybop.core.system.chain.Configuration")));
                    s.set(System.LOG_RECORD, createItem(new String("cybop.core.system.chain.LogRecord")));
                    s.set(System.SIGNAL_MEMORY, createItem(new String("cybop.core.system.chain.SignalMemory")));

                    java.lang.System.out.println("INFO: Configure system.");
                    s.configure();

                    java.lang.System.out.println("INFO: Initialize system.");
                    s.initialize();

                } else {

                    throw new NullPointerException("Could not create system. The system is null.");
                }

            } else {

                throw new NullPointerException("Could not create system. The system class is null.");
            }

        } else {

            java.lang.System.out.println("DEBUG: Could not create system. The system class name is null.");
        }

        return s;
    }

    /**
     * Destroys the system.
     *
     * @param s the system
     */
    public void destroySystem(System s) throws Exception {

        if (s != null) {

            java.lang.System.out.println("INFO: Finalize system.");
            s.finalizz();

            java.lang.System.out.println("INFO: Deconfigure system.");
            s.deconfigure();

            java.lang.System.out.println("INFO: Remove global system items.");
            SignalMemory m = (SignalMemory) s.get(System.SIGNAL_MEMORY);
            s.remove(System.SIGNAL_MEMORY);
            destroyItem(m);

            LogRecord h = (LogRecord) s.get(System.LOG_RECORD);
            s.remove(System.LOG_RECORD);
            destroyItem(h);

            Configuration c = (Configuration) s.get(System.CONFIGURATION);
            s.remove(System.CONFIGURATION);
            destroyItem(c);

        } else {

            java.lang.System.out.println("DEBUG: Could not destroy system. The system is null.");
        }
    }

    //
    // Default children categories.
    //

    /**
     * Returns the default controller category.
     *
     * @return the default controller category
     */
    public String getDefaultControllerCategory() {

        return null;
    }

    /**
     * Returns the default socket address category.
     *
     * @return the default socket address category
     */
    public String getDefaultSocketAddressCategory() {

        return null;
    }

    /**
     * Returns the default internet protocol 6 address category.
     *
     * @return the default internet protocol 6 address category
     */
    public String getDefaultIp6AddressCategory() {

        return null;
    }

    /**
     * Returns the default internet protocol 4 address category.
     *
     * @return the default internet protocol 4 address category
     */
    public String getDefaultIp4AddressCategory() {

        return null;
    }

    /**
     * Returns the default host name category.
     *
     * @return the default host name category
     */
    public String getDefaultHostNameCategory() {

        return null;
    }

    /**
     * Returns the default domain name category.
     *
     * @return the default domain name category
     */
    public String getDefaultDomainNameCategory() {

        return null;
    }

    /**
     * Returns the default communication partners count category.
     *
     * @return the default communication partners count category
     */
    public Integer getDefaultCommunicationPartnersCountCategory() {

        return new Integer(0);
    }

    /**
     * Returns the default communication partner category.
     *
     * @return the default communication partner category
     */
    public String getDefaultCommunicationPartnerCategory() {

        return null;
    }

    /**
     * Returns the default user category.
     *
     * @return the default user category
     */
    public String getDefaultUserCategory() {

        return null;
    }

    //
    // Configuration.
    //

    /**
     * Configures this system.
     *
     * @exception NullPointerException if the configuration is null
     */
    public void configure() throws Exception, NullPointerException {

        super.configure();

        Configuration c = (Configuration) get(System.CONFIGURATION);

        if (c != null) {

            setCategory(System.CONTROLLER_CATEGORY, c.get(System.CONTROLLER_CATEGORY, getDefaultControllerCategory()));
            setCategory(System.SOCKET_ADDRESS_CATEGORY, c.get(System.SOCKET_ADDRESS_CATEGORY, getDefaultSocketAddressCategory()));
            setCategory(System.IP6_ADDRESS_CATEGORY, c.get(System.IP6_ADDRESS_CATEGORY, getDefaultIp6AddressCategory()));
            setCategory(System.IP4_ADDRESS_CATEGORY, c.get(System.IP4_ADDRESS_CATEGORY, getDefaultIp4AddressCategory()));
            setCategory(System.HOST_NAME_CATEGORY, c.get(System.HOST_NAME_CATEGORY, getDefaultHostNameCategory()));
            setCategory(System.DOMAIN_NAME_CATEGORY, c.get(System.DOMAIN_NAME_CATEGORY, getDefaultDomainNameCategory()));
            setCategory(System.COMMUNICATION_PARTNERS_COUNT_CATEGORY, c.get(System.COMMUNICATION_PARTNERS_COUNT_CATEGORY, getDefaultCommunicationPartnersCountCategory()));
            setCategory(System.COMMUNICATION_PARTNER_CATEGORY, c.get(System.COMMUNICATION_PARTNER_CATEGORY, getDefaultCommunicationPartnerCategory()));
            setCategory(System.USER_CATEGORY, c.get(System.USER_CATEGORY, getDefaultUserCategory()));

        } else {

            java.lang.System.out.println("WARNING: Could not configure system. The configuration is null.");
        }
    }

    /**
     * Deconfigures this system.
     *
     * @exception NullPointerException if the configuration is null
     */
    public void deconfigure() throws Exception, NullPointerException {

        Configuration c = (Configuration) get(System.CONFIGURATION);

        if (c != null) {

            c.set(System.USER_CATEGORY, getCategory(System.USER_CATEGORY));
            removeCategory(System.USER_CATEGORY);

            c.set(System.COMMUNICATION_PARTNER_CATEGORY, getCategory(System.COMMUNICATION_PARTNER_CATEGORY));
            removeCategory(System.COMMUNICATION_PARTNER_CATEGORY);

            c.set(System.COMMUNICATION_PARTNERS_COUNT_CATEGORY, getCategory(System.COMMUNICATION_PARTNERS_COUNT_CATEGORY));
            removeCategory(System.COMMUNICATION_PARTNERS_COUNT_CATEGORY);

            c.set(System.DOMAIN_NAME_CATEGORY, getCategory(System.DOMAIN_NAME_CATEGORY));
            removeCategory(System.DOMAIN_NAME_CATEGORY);

            c.set(System.HOST_NAME_CATEGORY, getCategory(System.HOST_NAME_CATEGORY));
            removeCategory(System.HOST_NAME_CATEGORY);

            c.set(System.IP4_ADDRESS_CATEGORY, getCategory(System.IP4_ADDRESS_CATEGORY));
            removeCategory(System.IP4_ADDRESS_CATEGORY);

            c.set(System.IP6_ADDRESS_CATEGORY, getCategory(System.IP6_ADDRESS_CATEGORY));
            removeCategory(System.IP6_ADDRESS_CATEGORY);

            c.set(System.SOCKET_ADDRESS_CATEGORY, getCategory(System.SOCKET_ADDRESS_CATEGORY));
            removeCategory(System.SOCKET_ADDRESS_CATEGORY);

            c.set(System.CONTROLLER_CATEGORY, getCategory(System.CONTROLLER_CATEGORY));
            removeCategory(System.CONTROLLER_CATEGORY);

        } else {

            java.lang.System.out.println("WARNING: Could not deconfigure system. The configuration is null.");
        }

        super.deconfigure();
    }

    //
    // Initialization.
    //

    /**
     * Initializes this system.
     */
    public void initialize() throws Exception {

        super.initialize();

        set(System.CONTROLLER, createComponent(getCategory(System.CONTROLLER_CATEGORY)));
        set(System.SOCKET_ADDRESS, createComponent(getCategory(System.SOCKET_ADDRESS_CATEGORY)));
        set(System.IP6_ADDRESS, createComponent(getCategory(System.IP6_ADDRESS_CATEGORY)));
        set(System.IP4_ADDRESS, createComponent(getCategory(System.IP4_ADDRESS_CATEGORY)));
        set(System.HOST_NAME, createItem(getCategory(System.HOST_NAME_CATEGORY)));
        set(System.DOMAIN_NAME, createItem(getCategory(System.DOMAIN_NAME_CATEGORY)));
        set(System.USER, createComponent(getCategory(System.USER_CATEGORY)));

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
                set(new String("system_test_user"), createSystem(c.get(loc, new String("cybop.core.system.system.User")), c.get(args, new String("")), c.get(wp, new String(""))));
            }

        } else {

            throw new NullPointerException("Could not initialize system. The systems count is null.");
        }
*/
    }

    /**
     * Finalizes this system.
     */
    public void finalizz() throws Exception {

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

                system = (System) get(s);
                remove(s);
                destroySystem(system);
            }

            Integer systemsCount = (Integer) get(System.SYSTEMS_COUNT);
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

