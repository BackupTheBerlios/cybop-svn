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

import cybop.core.category.*;
import cybop.core.model.*;
import cybop.core.model.Boolean;
import cybop.core.model.Integer;
import cybop.core.model.String;
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
 * @version $Revision: 1.18 $ $Date: 2003-06-16 18:25:35 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class System extends SystemItem implements java.lang.Runnable {

    //
    // Category names.
    //

    /** The controller category. */
    public static final String CONTROLLER_CATEGORY = new String("controller_category");

    /** The log level category. */
    public static final String LOG_LEVEL_CATEGORY = new String("log_level_category");

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
    // Children names.
    //

    /** The controller. */
    public static final String CONTROLLER = new String("controller");

    /** The log level. */
    public static final String LOG_LEVEL = new String("log_level");

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
    // Log levels.
    //

    /** The log level to turn off logging. */
    public static final Integer OFF_LOG_LEVEL = new Integer(0);

    /** The log level indicating a serious failure. */
    public static final Integer ERROR_LOG_LEVEL = new Integer(1);

    /** The log level indicating a potential problem. */
    public static final Integer WARNING_LOG_LEVEL = new Integer(2);

    /** The log level for informational messages. */
    public static final Integer INFO_LOG_LEVEL = new Integer(3);

    /** The log level providing tracing information. */
    public static final Integer DEBUG_LOG_LEVEL = new Integer(4);

    /** The log level printing all messages, including every signal occuring in the system. */
    public static final Integer SIGNAL_LOG_LEVEL = new Integer(5);

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
    // Default categories.
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
     * Returns the default log level category.
     *
     * @return the default log level category
     */
    public Item getDefaultLogLevelCategory() {

        return System.SIGNAL_LOG_LEVEL;
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
    // Globalization.
    //

    /**
     * Globalizes this system.
     *
     * @param c the configuration
     * @param r the log record
     * @param m the signal memory
     */
    public void globalize(Item c, Item r, Item m) throws Exception {

        // Normally, categories are set in the configure method. Since
        // configure is called after globalize, the categories of global
        // items have to be set before. They are needed because globalize
        // creates the global items, if called on a system.
        setCategory(System.CONFIGURATION_CATEGORY, getDefaultConfigurationCategory());
        setCategory(System.LOG_RECORD_CATEGORY, getDefaultLogRecordCategory());
        setCategory(System.SIGNAL_MEMORY_CATEGORY, getDefaultSignalMemoryCategory());

        setChild(System.CONFIGURATION, createSimple((String) getCategory(System.CONFIGURATION_CATEGORY)));
        setChild(System.LOG_RECORD, createSimple((String) getCategory(System.LOG_RECORD_CATEGORY)));
        setChild(System.SIGNAL_MEMORY, createSimple((String) getCategory(System.SIGNAL_MEMORY_CATEGORY)));
    }

    /**
     * Deglobalizes this system.
     */
    public void deglobalize() throws Exception {

        Item signalMemory = getChild(System.SIGNAL_MEMORY);
        removeChild(System.SIGNAL_MEMORY);
        destroySimple(signalMemory);

        Item logRecord = getChild(System.LOG_RECORD);
        removeChild(System.LOG_RECORD);
        destroySimple(logRecord);

        Item configuration = getChild(System.CONFIGURATION);
        removeChild(System.CONFIGURATION);
        destroySimple(configuration);

        removeCategory(System.SIGNAL_MEMORY_CATEGORY);
        removeCategory(System.LOG_RECORD_CATEGORY);
        removeCategory(System.CONFIGURATION_CATEGORY);
    }

    //
    // Categorization.
    //

    /**
     * Categorizes this item.
     */
    public void categorize() throws Exception {

        super.categorize();

        setCategory(Item.LOG_LEVEL_CATEGORY, c.getChild(Item.LOG_LEVEL_CATEGORY, getDefaultLogLevelCategory()));
    }

    /**
     * Decategorizes this item.
     */
    public void decategorize() throws Exception {

        //?? Write changes to local user configuration file.
//??        c.setChild(Item.LOG_LEVEL_CATEGORY, getCategory(Item.LOG_LEVEL_CATEGORY));
//??        removeCategory(Item.LOG_LEVEL_CATEGORY);

        super.decategorize();
    }

    //
    // Configuration.
    //

    /**
     * Configures this system.
     *
     * @exception Exception if the configuration is null
     */
    public void configure() throws Exception {

        super.configure();

        Configuration c = (Configuration) getChild(System.CONFIGURATION);

        if (c != null) {

            setCategory(System.CONTROLLER_CATEGORY, c.getChild(System.CONTROLLER_CATEGORY, getDefaultControllerCategory()));
            setCategory(System.SOCKET_ADDRESS_CATEGORY, c.getChild(System.SOCKET_ADDRESS_CATEGORY, getDefaultSocketAddressCategory()));
            setCategory(System.IP6_ADDRESS_CATEGORY, c.getChild(System.IP6_ADDRESS_CATEGORY, getDefaultIp6AddressCategory()));
            setCategory(System.IP4_ADDRESS_CATEGORY, c.getChild(System.IP4_ADDRESS_CATEGORY, getDefaultIp4AddressCategory()));
            setCategory(System.HOST_NAME_CATEGORY, c.getChild(System.HOST_NAME_CATEGORY, getDefaultHostNameCategory()));
            setCategory(System.DOMAIN_NAME_CATEGORY, c.getChild(System.DOMAIN_NAME_CATEGORY, getDefaultDomainNameCategory()));
            setCategory(System.COMMUNICATION_PARTNERS_COUNT_CATEGORY, c.getChild(System.COMMUNICATION_PARTNERS_COUNT_CATEGORY, getDefaultCommunicationPartnersCountCategory()));
            setCategory(System.COMMUNICATION_PARTNER_CATEGORY, c.getChild(System.COMMUNICATION_PARTNER_CATEGORY, getDefaultCommunicationPartnerCategory()));
            setCategory(System.USER_CATEGORY, c.getChild(System.USER_CATEGORY, getDefaultUserCategory()));

        } else {

            java.lang.System.out.println("WARNING: Could not configure system. The configuration is null.");
        }
    }

    /**
     * Deconfigures this system.
     *
     * @exception Exception if the configuration is null
     */
    public void deconfigure() throws Exception {

        Configuration c = (Configuration) getChild(System.CONFIGURATION);

        if (c != null) {

            c.setChild(System.USER_CATEGORY, getCategory(System.USER_CATEGORY));
            removeCategory(System.USER_CATEGORY);

            c.setChild(System.COMMUNICATION_PARTNER_CATEGORY, getCategory(System.COMMUNICATION_PARTNER_CATEGORY));
            removeCategory(System.COMMUNICATION_PARTNER_CATEGORY);

            c.setChild(System.COMMUNICATION_PARTNERS_COUNT_CATEGORY, getCategory(System.COMMUNICATION_PARTNERS_COUNT_CATEGORY));
            removeCategory(System.COMMUNICATION_PARTNERS_COUNT_CATEGORY);

            c.setChild(System.DOMAIN_NAME_CATEGORY, getCategory(System.DOMAIN_NAME_CATEGORY));
            removeCategory(System.DOMAIN_NAME_CATEGORY);

            c.setChild(System.HOST_NAME_CATEGORY, getCategory(System.HOST_NAME_CATEGORY));
            removeCategory(System.HOST_NAME_CATEGORY);

            c.setChild(System.IP4_ADDRESS_CATEGORY, getCategory(System.IP4_ADDRESS_CATEGORY));
            removeCategory(System.IP4_ADDRESS_CATEGORY);

            c.setChild(System.IP6_ADDRESS_CATEGORY, getCategory(System.IP6_ADDRESS_CATEGORY));
            removeCategory(System.IP6_ADDRESS_CATEGORY);

            c.setChild(System.SOCKET_ADDRESS_CATEGORY, getCategory(System.SOCKET_ADDRESS_CATEGORY));
            removeCategory(System.SOCKET_ADDRESS_CATEGORY);

            c.setChild(System.CONTROLLER_CATEGORY, getCategory(System.CONTROLLER_CATEGORY));
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

        setChild(System.CONTROLLER, createChild((String) getCategory(System.CONTROLLER_CATEGORY)));
        setChild(System.LOG_LEVEL, getCategory(System.LOG_LEVEL_CATEGORY));
        setChild(System.SOCKET_ADDRESS, createChild((String) getCategory(System.SOCKET_ADDRESS_CATEGORY)));
        setChild(System.IP6_ADDRESS, createChild((String) getCategory(System.IP6_ADDRESS_CATEGORY)));
        setChild(System.IP4_ADDRESS, createChild((String) getCategory(System.IP4_ADDRESS_CATEGORY)));
        setChild(System.HOST_NAME, createChild((String) getCategory(System.HOST_NAME_CATEGORY)));
        setChild(System.DOMAIN_NAME, createChild((String) getCategory(System.DOMAIN_NAME_CATEGORY)));
        setChild(System.USER, createChild((String) getCategory(System.USER_CATEGORY)));

        //
        // Communication partners.
        //

/*??
        int i;
        String s = null;

        setChild(System.SYSTEMS_COUNT, c.getChild(System.SYSTEMS_COUNT, createSystemsCount()));

        if (getChild(System.SYSTEMS_COUNT) != null) {

            // Retrieve the number of systems and create them one by one.
            i = 0;

            while (i < ((Integer) getChild(System.SYSTEMS_COUNT)).getJavaPrimitive()) {

                s = new String(System.SYSTEM + "_" + java.lang.String.valueOf(i));

                setChild(s, createChild(c.getChild(loc, new String("")), c.getChild(args, new String("")), c.getChild(wp, new String(""))));

                //?? Testing.
                setChild(new String("system_test_user"), createChild(c.getChild(loc, new String("cybop.core.system.system.User")), c.getChild(args, new String("")), c.getChild(wp, new String(""))));
                
                i++;
            }

        } else {

            throw new Exception("Could not initialize system. The systems count is null.");
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
        if (getChild(System.SYSTEMS_COUNT) != null) {

            String loc;
            String args; 
            String wp;
            System system = null;
            i = 0;

            while (i < ((Integer) getChild(System.SYSTEMS_COUNT)).getJavaPrimitive()) {

                s = new String(System.SYSTEM + "_" + java.lang.String.valueOf(i));
                loc = new String(System.SYSTEM_LOCATION + "_" + java.lang.String.valueOf(i));
                args = new String(System.SYSTEM_ARGUMENTS + "_" + java.lang.String.valueOf(i));
                wp = new String(System.SYSTEM_WORKPATH + "_" + java.lang.String.valueOf(i));

                system = (System) getChild(s);
                removeChild(s);
                destroyChild(system);
                
                i++;
            }

            Integer systemsCount = (Integer) getChild(System.SYSTEMS_COUNT);
            removeChild(System.SYSTEMS_COUNT);
            destroySystemsCount(systemsCount);

        } else {

            throw new Exception("Could not finalize system. The systems count is null.");
        }
*/

        Item user = getChild(System.USER);
        removeChild(System.USER);
        destroyChild((User) user);

        Item domainName = getChild(System.DOMAIN_NAME);
        removeChild(System.DOMAIN_NAME);
//??            destroyDomainName((String) domainName);

        Item hostName = getChild(System.HOST_NAME);
        removeChild(System.HOST_NAME);
//??            destroyHostName((String) hostName);

        Item ip4Address = getChild(System.IP4_ADDRESS);
        removeChild(System.IP4_ADDRESS);
        destroyChild((Ip4Address) ip4Address);

        Item ip6Address = getChild(System.IP6_ADDRESS);
        removeChild(System.IP6_ADDRESS);
        destroyChild((Ip6Address) ip6Address);

        Item socketAddress = getChild(System.SOCKET_ADDRESS);
        removeChild(System.SOCKET_ADDRESS);
        destroyChild((SocketAddress) socketAddress);

        Item logLevel = getChild(System.LOG_LEVEL);
        removeChild(System.LOG_LEVEL);
        destroyChild((Integer) logLevel);

        Item controller = getChild(System.CONTROLLER);
        removeChild(System.CONTROLLER);
        destroyChild((Controller) controller);

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
     * @exception Exception if the controller is null
     * @exception Exception if the dummy flag is null
     */
    public void handle(Signal s, Boolean b) throws Exception {
        
        log(s);

        Controller c = (Controller) getChild(System.CONTROLLER);

        if (c != null) {

            if (b != null) {

                if (b.isEqualTo(Boolean.FALSE)) {

                    java.lang.System.out.println("DEBUG: Control signal.");
                    c.control(s);

                } else {

                    java.lang.System.out.println("DEBUG: Control signal as server dummy.");
                    c.controlAsServerDummy(s);
                }

            } else {

                throw new Exception("Could not handle signal. The dummy flag is null.");
            }

        } else {

            java.lang.System.out.println("DEBUG: Could not handle signal. The controller is null.");
        }
    }

    /**
     * Logs the signal.
     *
     * @param s the signal
     * @exception Exception if the log record is null
     * @exception Exception if the log entry is null
     * @exception Exception if the signal is null
     */
    public void log(Signal s) throws Exception {

        LogRecord r = getChild(Launcher.LOG_RECORD);

        if (r != null) {

            LogEntry e = createItem(LogRecord.ENTRY);
            
            if (e != null) {

                if (s != null) {

//??                    Time time = ??;

//??                    Integer level = ??;

                    e.setChild(LogEntry.MESSAGE, s.getChild(Signal.PREDICATE));

                } else {
        
                    throw new Exception("Could not log signal. The signal is null.");
                }

                r.set(LogRecord.ENTRY, e);

            } else {

                throw new Exception("Could not log signal. The log entry is null.");
            }

        } else {

            throw new Exception("Could not log signal. The log record is null.");
        }
    }
}

