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
import cybop.core.logrecord.*;
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
 * @version $Revision: 1.20 $ $Date: 2003-06-17 15:39:22 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class System extends SystemItem implements java.lang.Runnable {

    //
    // Children names.
    //

    /** The controller. */
    public static final String CONTROLLER = new String("controller");

    /** The log level. */
    public static final String LOG_LEVEL = new String("log_level");

    /** The log record. */
    public static final String LOG_RECORD = new String("log_record");

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
    public java.lang.Object createJavaObject() throws Exception {

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
     * Returns the default log record category.
     *
     * @return the default log record category
     */
    public Item getDefaultLogRecordCategory() {

        return new String("cybop.core.logrecord.LogRecord");
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
    // Categorization.
    //

    /**
     * Categorizes this hierarchy.
     */
    public void categorize() throws Exception {

        super.categorize();

        setCategory(System.CONTROLLER, getDefaultControllerCategory());
        setCategory(System.LOG_LEVEL, getDefaultLogLevelCategory());
        setCategory(System.LOG_RECORD, getDefaultLogRecordCategory());
        setCategory(System.SOCKET_ADDRESS, getDefaultSocketAddressCategory());
        setCategory(System.IP6_ADDRESS, getDefaultIp6AddressCategory());
        setCategory(System.IP4_ADDRESS, getDefaultIp4AddressCategory());
        setCategory(System.HOST_NAME, getDefaultHostNameCategory());
        setCategory(System.DOMAIN_NAME, getDefaultDomainNameCategory());
        setCategory(System.COMMUNICATION_PARTNERS_COUNT, getDefaultCommunicationPartnersCountCategory());
        setCategory(System.COMMUNICATION_PARTNER, getDefaultCommunicationPartnerCategory());
        setCategory(System.USER, getDefaultUserCategory());
    }

    /**
     * Decategorizes this hierarchy.
     */
    public void decategorize() throws Exception {

        removeCategory(System.USER);
        removeCategory(System.COMMUNICATION_PARTNER);
        removeCategory(System.COMMUNICATION_PARTNERS_COUNT);
        removeCategory(System.DOMAIN_NAME);
        removeCategory(System.HOST_NAME);
        removeCategory(System.IP4_ADDRESS);
        removeCategory(System.IP6_ADDRESS);
        removeCategory(System.SOCKET_ADDRESS);
        removeCategory(System.LOG_RECORD);
        removeCategory(System.LOG_LEVEL);
        removeCategory(System.CONTROLLER);

        super.decategorize();
    }

    //
    // Initialization.
    //

    /**
     * Initializes this item.
     */
    public void initialize() throws Exception {

        super.initialize();

        setChild(System.CONTROLLER, createChild(getCategory(System.CONTROLLER)));
        setChild(System.LOG_LEVEL, createChild(getCategory(System.LOG_LEVEL)));
        setChild(System.LOG_RECORD, createChild(getCategory(System.LOG_RECORD)));
        setChild(System.SOCKET_ADDRESS, createChild(getCategory(System.SOCKET_ADDRESS)));
        setChild(System.IP6_ADDRESS, createChild(getCategory(System.IP6_ADDRESS)));
        setChild(System.IP4_ADDRESS, createChild(getCategory(System.IP4_ADDRESS)));
        setChild(System.HOST_NAME, createChild(getCategory(System.HOST_NAME)));
        setChild(System.DOMAIN_NAME, createChild(getCategory(System.DOMAIN_NAME)));
        setChild(System.USER, createChild(getCategory(System.USER)));

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
     * Finalizes this item.
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
        destroyChild(user);

        Item domainName = getChild(System.DOMAIN_NAME);
        removeChild(System.DOMAIN_NAME);
        destroyChild(domainName);

        Item hostName = getChild(System.HOST_NAME);
        removeChild(System.HOST_NAME);
        destroyChild(hostName);

        Item ip4Address = getChild(System.IP4_ADDRESS);
        removeChild(System.IP4_ADDRESS);
        destroyChild(ip4Address);

        Item ip6Address = getChild(System.IP6_ADDRESS);
        removeChild(System.IP6_ADDRESS);
        destroyChild(ip6Address);

        Item socketAddress = getChild(System.SOCKET_ADDRESS);
        removeChild(System.SOCKET_ADDRESS);
        destroyChild(socketAddress);

        Item logRecord = getChild(System.LOG_RECORD);
        removeChild(System.LOG_RECORD);
        destroyChild(logRecord);

        Item logLevel = getChild(System.LOG_LEVEL);
        removeChild(System.LOG_LEVEL);
        destroyChild(logLevel);

        Item controller = getChild(System.CONTROLLER);
        removeChild(System.CONTROLLER);
        destroyChild(controller);

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

        LogRecord r = (LogRecord) getChild(System.LOG_RECORD);

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

