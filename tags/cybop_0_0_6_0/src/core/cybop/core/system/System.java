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
 * @version $Revision: 1.10 $ $Date: 2003-04-28 12:14:32 $ $Author: christian $
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
                    s.setChildItem(System.CONFIGURATION, createChildItem(new String("cybop.core.system.chain.Configuration")));
                    s.setChildItem(System.LOG_RECORD, createChildItem(new String("cybop.core.system.chain.LogRecord")));
                    s.setChildItem(System.SIGNAL_MEMORY, createChildItem(new String("cybop.core.system.chain.SignalMemory")));

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
            SignalMemory m = (SignalMemory) s.getChildItem(System.SIGNAL_MEMORY);
            s.removeChildItem(System.SIGNAL_MEMORY);
            destroyChildItem(m);

            LogRecord h = (LogRecord) s.getChildItem(System.LOG_RECORD);
            s.removeChildItem(System.LOG_RECORD);
            destroyChildItem(h);

            Configuration c = (Configuration) s.getChildItem(System.CONFIGURATION);
            s.removeChildItem(System.CONFIGURATION);
            destroyChildItem(c);

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
    public Item getDefaultControllerCategory() {

        return null;
    }

    /**
     * Returns the default socket address category.
     *
     * @return the default socket address category
     */
    public Item getDefaultSocketAddressCategory() {

        return null;
    }

    /**
     * Returns the default internet protocol 6 address category.
     *
     * @return the default internet protocol 6 address category
     */
    public Item getDefaultIp6AddressCategory() {

        return null;
    }

    /**
     * Returns the default internet protocol 4 address category.
     *
     * @return the default internet protocol 4 address category
     */
    public Item getDefaultIp4AddressCategory() {

        return null;
    }

    /**
     * Returns the default host name category.
     *
     * @return the default host name category
     */
    public Item getDefaultHostNameCategory() {

        return null;
    }

    /**
     * Returns the default domain name category.
     *
     * @return the default domain name category
     */
    public Item getDefaultDomainNameCategory() {

        return null;
    }

    /**
     * Returns the default communication partners count category.
     *
     * @return the default communication partners count category
     */
    public Item getDefaultCommunicationPartnersCountCategory() {

        return new Integer(0);
    }

    /**
     * Returns the default communication partner category.
     *
     * @return the default communication partner category
     */
    public Item getDefaultCommunicationPartnerCategory() {

        return null;
    }

    /**
     * Returns the default user category.
     *
     * @return the default user category
     */
    public Item getDefaultUserCategory() {

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

        Configuration c = (Configuration) getChildItem(System.CONFIGURATION);

        if (c != null) {

            setChildCategory(System.CONTROLLER_CATEGORY, c.getChildItem(System.CONTROLLER_CATEGORY, getDefaultControllerCategory()));
            setChildCategory(System.SOCKET_ADDRESS_CATEGORY, c.getChildItem(System.SOCKET_ADDRESS_CATEGORY, getDefaultSocketAddressCategory()));
            setChildCategory(System.IP6_ADDRESS_CATEGORY, c.getChildItem(System.IP6_ADDRESS_CATEGORY, getDefaultIp6AddressCategory()));
            setChildCategory(System.IP4_ADDRESS_CATEGORY, c.getChildItem(System.IP4_ADDRESS_CATEGORY, getDefaultIp4AddressCategory()));
            setChildCategory(System.HOST_NAME_CATEGORY, c.getChildItem(System.HOST_NAME_CATEGORY, getDefaultHostNameCategory()));
            setChildCategory(System.DOMAIN_NAME_CATEGORY, c.getChildItem(System.DOMAIN_NAME_CATEGORY, getDefaultDomainNameCategory()));
            setChildCategory(System.COMMUNICATION_PARTNERS_COUNT_CATEGORY, c.getChildItem(System.COMMUNICATION_PARTNERS_COUNT_CATEGORY, getDefaultCommunicationPartnersCountCategory()));
            setChildCategory(System.COMMUNICATION_PARTNER_CATEGORY, c.getChildItem(System.COMMUNICATION_PARTNER_CATEGORY, getDefaultCommunicationPartnerCategory()));
            setChildCategory(System.USER_CATEGORY, c.getChildItem(System.USER_CATEGORY, getDefaultUserCategory()));

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

        Configuration c = (Configuration) getChildItem(System.CONFIGURATION);

        if (c != null) {

            c.setChildItem(System.USER_CATEGORY, getChildCategory(System.USER_CATEGORY));
            removeChildCategory(System.USER_CATEGORY);

            c.setChildItem(System.COMMUNICATION_PARTNER_CATEGORY, getChildCategory(System.COMMUNICATION_PARTNER_CATEGORY));
            removeChildCategory(System.COMMUNICATION_PARTNER_CATEGORY);

            c.setChildItem(System.COMMUNICATION_PARTNERS_COUNT_CATEGORY, getChildCategory(System.COMMUNICATION_PARTNERS_COUNT_CATEGORY));
            removeChildCategory(System.COMMUNICATION_PARTNERS_COUNT_CATEGORY);

            c.setChildItem(System.DOMAIN_NAME_CATEGORY, getChildCategory(System.DOMAIN_NAME_CATEGORY));
            removeChildCategory(System.DOMAIN_NAME_CATEGORY);

            c.setChildItem(System.HOST_NAME_CATEGORY, getChildCategory(System.HOST_NAME_CATEGORY));
            removeChildCategory(System.HOST_NAME_CATEGORY);

            c.setChildItem(System.IP4_ADDRESS_CATEGORY, getChildCategory(System.IP4_ADDRESS_CATEGORY));
            removeChildCategory(System.IP4_ADDRESS_CATEGORY);

            c.setChildItem(System.IP6_ADDRESS_CATEGORY, getChildCategory(System.IP6_ADDRESS_CATEGORY));
            removeChildCategory(System.IP6_ADDRESS_CATEGORY);

            c.setChildItem(System.SOCKET_ADDRESS_CATEGORY, getChildCategory(System.SOCKET_ADDRESS_CATEGORY));
            removeChildCategory(System.SOCKET_ADDRESS_CATEGORY);

            c.setChildItem(System.CONTROLLER_CATEGORY, getChildCategory(System.CONTROLLER_CATEGORY));
            removeChildCategory(System.CONTROLLER_CATEGORY);

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

        setChildItem(System.CONTROLLER, createComponent((String) getChildCategory(System.CONTROLLER_CATEGORY)));
        setChildItem(System.SOCKET_ADDRESS, createComponent((String) getChildCategory(System.SOCKET_ADDRESS_CATEGORY)));
        setChildItem(System.IP6_ADDRESS, createComponent((String) getChildCategory(System.IP6_ADDRESS_CATEGORY)));
        setChildItem(System.IP4_ADDRESS, createComponent((String) getChildCategory(System.IP4_ADDRESS_CATEGORY)));
        setChildItem(System.HOST_NAME, createChildItem((String) getChildCategory(System.HOST_NAME_CATEGORY)));
        setChildItem(System.DOMAIN_NAME, createChildItem((String) getChildCategory(System.DOMAIN_NAME_CATEGORY)));
        setChildItem(System.USER, createComponent((String) getChildCategory(System.USER_CATEGORY)));

        //
        // Communication partners.
        //

/*??
        int i;
        String s = null;

        setChildItem(System.SYSTEMS_COUNT, c.getChildItem(System.SYSTEMS_COUNT, createSystemsCount()));

        if (getChildItem(System.SYSTEMS_COUNT) != null) {

            // Retrieve the number of systems and create them one by one.
            for (i = 0; i < ((Integer) getChildItem(System.SYSTEMS_COUNT)).getJavaPrimitive(); i++) {

                s = new String(System.SYSTEM + "_" + java.lang.String.valueOf(i));

                setChildItem(s, createSystem(c.getChildItem(loc, new String("")), c.getChildItem(args, new String("")), c.getChildItem(wp, new String(""))));

                //?? Testing.
                setChildItem(new String("system_test_user"), createSystem(c.getChildItem(loc, new String("cybop.core.system.system.User")), c.getChildItem(args, new String("")), c.getChildItem(wp, new String(""))));
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
        if (getChildItem(System.SYSTEMS_COUNT) != null) {

            String loc;
            String args; 
            String wp;
            System system = null;

            for (i = 0; i < ((Integer) getChildItem(System.SYSTEMS_COUNT)).getJavaPrimitive(); i++) {

                s = new String(System.SYSTEM + "_" + java.lang.String.valueOf(i));
                loc = new String(System.SYSTEM_LOCATION + "_" + java.lang.String.valueOf(i));
                args = new String(System.SYSTEM_ARGUMENTS + "_" + java.lang.String.valueOf(i));
                wp = new String(System.SYSTEM_WORKPATH + "_" + java.lang.String.valueOf(i));

                system = (System) getChildItem(s);
                removeChildItem(s);
                destroySystem(system);
            }

            Integer systemsCount = (Integer) getChildItem(System.SYSTEMS_COUNT);
            removeChildItem(System.SYSTEMS_COUNT);
            destroySystemsCount(systemsCount);

        } else {

            throw new NullPointerException("Could not finalize system. The systems count is null.");
        }
*/

        Item user = getChildItem(System.USER);
        removeChildItem(System.USER);
        destroyComponent((User) user);

        Item domainName = getChildItem(System.DOMAIN_NAME);
        removeChildItem(System.DOMAIN_NAME);
//??            destroyDomainName((String) domainName);

        Item hostName = getChildItem(System.HOST_NAME);
        removeChildItem(System.HOST_NAME);
//??            destroyHostName((String) hostName);

        Item ip4Address = getChildItem(System.IP4_ADDRESS);
        removeChildItem(System.IP4_ADDRESS);
        destroyChildItem((Ip4Address) ip4Address);

        Item ip6Address = getChildItem(System.IP6_ADDRESS);
        removeChildItem(System.IP6_ADDRESS);
        destroyChildItem((Ip6Address) ip6Address);

        Item socketAddress = getChildItem(System.SOCKET_ADDRESS);
        removeChildItem(System.SOCKET_ADDRESS);
        destroyChildItem((SocketAddress) socketAddress);

        Item controller = getChildItem(System.CONTROLLER);
        removeChildItem(System.CONTROLLER);
        destroyComponent((Controller) controller);

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

        Controller c = (Controller) getChildItem(System.CONTROLLER);

        if (c != null) {

            if (b != null) {

                if (b.isEqualTo(Boolean.FALSE)) {

                    log(System.DEBUG_LOG_LEVEL, "Control signal.");
                    c.control(s);

                } else {

                    log(System.DEBUG_LOG_LEVEL, "Control signal as server dummy.");
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

