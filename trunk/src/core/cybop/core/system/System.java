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

import cybop.core.address.*;
import cybop.core.category.*;
import cybop.core.logrecord.*;
import cybop.core.model.*;
import cybop.core.model.Boolean;
import cybop.core.model.Integer;
import cybop.core.model.String;
import cybop.core.signal.*;
import cybop.core.system.block.*;
import cybop.core.system.region.controller.*;
import cybop.core.system.region.controller.translator.*;
import cybop.core.system.system.*;

/**
 * This class represents a system.<br><br>
 *
 * It contains meta information about a system.
 * A system corresponds to an animal or human organism.<br><br>
 *
 * It is important to note that users of systems are treated as system
 * themselves. Taking the metapher of a system being a human person, each
 * system has capabilities to communicate with other systems, may it be alive users
 * (view/user interface) or programs running on the same (local communication)
 * or other machines (remote communication, persistence mechanism).
 *
 * @version $Revision: 1.27 $ $Date: 2003-07-15 09:44:19 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class System extends SystemItem implements java.lang.Runnable {

    //
    // Children names.
    //

    /** The self. It names this system itself. */
    public static final String SELF = new String("self");

    /** The name. */
    public static final String NAME = new String("name");

    /** The version. */
    public static final String VERSION = new String("version");

    /** The date. */
    public static final String DATE = new String("date");

    /** The slogan id. */
    public static final String SLOGAN = new String("slogan");

    /** The logo. */
    public static final String LOGO = new String("logo");

    /** The copyright. */
    public static final String COPYRIGHT = new String("copyright");

    /** The contact. */
    public static final String CONTACT = new String("contact");

    /** The description id. */
    public static final String DESCRIPTION = new String("description");

    /** The authors. */
    public static final String AUTHORS = new String("authors");

    /** The helpers. */
    public static final String HELPERS = new String("helpers");

    /** The inspirations. */
    public static final String INSPIRATIONS = new String("inspirations");

    /** The license. */
    public static final String LICENSE = new String("license");

    /** The controller. */
    public static final String CONTROLLER = new String("controller");

    /** The screen. */
    public static final String SCREEN = new String("screen");

    /** The mouse. */
    public static final String MOUSE = new String("mouse");

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
     * Returns the default name category.
     *
     * @return the default name category
     */
    public Item getDefaultNameCategory() {

        return new String("Res Medicinae");
    }

    /**
     * Returns the default version category.
     *
     * @return the default version category
     */
    public Item getDefaultVersionCategory() {

        return new String("0.0.5.0");
    }

    /**
     * Returns the default date category.
     *
     * @return the default date category
     */
    public Item getDefaultDateCategory() {

        return new String("31.01.2003");
    }

    /**
     * Returns the default slogan category.
     *
     * @return the default slogan category
     */
    public Item getDefaultSloganCategory() {

        return new String("- Cybernetics Oriented Programming -");
    }

    /**
     * Returns the default logo category.
     *
     * @return the default logo category
     */
    public Item getDefaultLogoCategory() {

        return null;
    }

    /**
     * Returns the default copyright category.
     *
     * @return the default copyright category
     */
    public Item getDefaultCopyrightCategory() {

        return new String("Copyright (c) 1999-2003. Christian Heller <christian.heller@tuxtax.de>. All rights reserved.");
    }

    /**
     * Returns the default contact category.
     *
     * @return the default contact category
     */
    public Item getDefaultContactCategory() {

        return new String("http://www.cybop.net");
    }

    /**
     * Returns the default description category.
     *
     * @return the default description category
     */
    public Item getDefaultDescriptionCategory() {

        return new String("Free Medical Information System");
    }

    /**
     * Returns the default authors category.
     *
     * @return the default authors category
     */
    public Item getDefaultAuthorsCategory() {

        return new String("Unspecified Authors.\n"
            + "Try to contact these project administrators:\n\n"
            + "Christian Heller\n<christian.heller@tuxtax.de>\n\n"
            + "Karsten Hilbert\n<karsten.hilbert@gmx.net>");
    }

    /**
     * Returns the default helpers category.
     *
     * @return the default helpers category
     */
    public Item getDefaultHelpersCategory() {

        return new String("Helpers ...");
    }

    /**
     * Returns the default inspirations category.
     *
     * @return the default inspirations category
     */
    public Item getDefaultInspirationsCategory() {

        return new String("Inspirations ...");
    }

    /**
     * Returns the default license category.
     *
     * @return the default license category
     */
    public Item getDefaultLicenseCategory() {

        return new String("This software is published under the GPL GNU General Public License.\n"
            + "This program is free software; you can redistribute it and/or\n"
            + "modify it under the terms of the GNU General Public License\n"
            + "as published by the Free Software Foundation; either version 2\n"
            + "of the License, or (at your option) any later version.\n\n"
            + "This program is distributed in the hope that it will be useful,\n"
            + "but WITHOUT ANY WARRANTY; without even the implied warranty of\n"
            + "MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the\n"
            + "GNU General Public License for more details.\n\n"
            + "You should have received a copy of the GNU General Public License\n"
            + "along with this program; if not, write to the Free Software\n"
            + "Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.\n\n"
            + "Find the GPL license and more information at: http://www.gnu.org");
    }

    /**
     * Returns the default controller category.
     *
     * @return the default controller category
     */
    public Item getDefaultControllerCategory() {

        return null;
    }

    /**
     * Returns the default screen category.
     *
     * @return the default screen category
     */
    public Item getDefaultScreenCategory() {

        return new String("cybop.core.system.block.Screen");
    }

    /**
     * Returns the default mouse category.
     *
     * @return the default mouse category
     */
    public Item getDefaultMouseCategory() {

        return new String("cybop.core.system.block.Mouse");
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

        setCategory(System.NAME, getDefaultNameCategory());
        setCategory(System.VERSION, getDefaultVersionCategory());
        setCategory(System.DATE, getDefaultDateCategory());
        setCategory(System.SLOGAN, getDefaultSloganCategory());
        setCategory(System.LOGO, getDefaultLogoCategory());
        setCategory(System.COPYRIGHT, getDefaultCopyrightCategory());
        setCategory(System.CONTACT, getDefaultContactCategory());
        setCategory(System.DESCRIPTION, getDefaultDescriptionCategory());
        setCategory(System.AUTHORS, getDefaultAuthorsCategory());
        setCategory(System.HELPERS, getDefaultHelpersCategory());
        setCategory(System.INSPIRATIONS, getDefaultInspirationsCategory());
        setCategory(System.LICENSE, getDefaultLicenseCategory());
        setCategory(System.CONTROLLER, getDefaultControllerCategory());
        setCategory(System.SCREEN, getDefaultScreenCategory());
        setCategory(System.MOUSE, getDefaultMouseCategory());
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
        removeCategory(System.MOUSE);
        removeCategory(System.SCREEN);
        removeCategory(System.CONTROLLER);
        removeCategory(System.LICENSE);
        removeCategory(System.INSPIRATIONS);
        removeCategory(System.HELPERS);
        removeCategory(System.AUTHORS);
        removeCategory(System.DESCRIPTION);
        removeCategory(System.CONTACT);
        removeCategory(System.COPYRIGHT);
        removeCategory(System.LOGO);
        removeCategory(System.SLOGAN);
        removeCategory(System.DATE);
        removeCategory(System.VERSION);
        removeCategory(System.NAME);

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

        setChild(System.NAME, (Item) getCategory(System.NAME));
        setChild(System.VERSION, (Item) getCategory(System.VERSION));
        setChild(System.DATE, (Item) getCategory(System.DATE));
        setChild(System.SLOGAN, (Item) getCategory(System.SLOGAN));
        setChild(System.LOGO, (Item) getCategory(System.LOGO));
        setChild(System.COPYRIGHT, (Item) getCategory(System.COPYRIGHT));
        setChild(System.CONTACT, (Item) getCategory(System.CONTACT));
        setChild(System.DESCRIPTION, (Item) getCategory(System.DESCRIPTION));
        setChild(System.AUTHORS, (Item) getCategory(System.AUTHORS));
        setChild(System.HELPERS, (Item) getCategory(System.HELPERS));
        setChild(System.INSPIRATIONS, (Item) getCategory(System.INSPIRATIONS));
        setChild(System.LICENSE, (Item) getCategory(System.LICENSE));
        setChild(System.CONTROLLER, createChild(getCategory(System.CONTROLLER)));
        setChild(System.SCREEN, createChild(getCategory(System.SCREEN)));
        setChild(System.MOUSE, createChild(getCategory(System.MOUSE)));
        setChild(System.LOG_LEVEL, (Item) getCategory(System.LOG_LEVEL));
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

        Item mouse = getChild(System.MOUSE);
        removeChild(System.MOUSE);
        destroyChild(mouse);

        Item screen = getChild(System.SCREEN);
        removeChild(System.SCREEN);
        destroyChild(screen);

        Item controller = getChild(System.CONTROLLER);
        removeChild(System.CONTROLLER);
        destroyChild(controller);

        Item license = getChild(System.LICENSE);
        removeChild(System.LICENSE);
        destroyChild(license);

        Item inspirations = getChild(System.INSPIRATIONS);
        removeChild(System.INSPIRATIONS);
        destroyChild(inspirations);

        Item helpers = getChild(System.HELPERS);
        removeChild(System.HELPERS);
        destroyChild(helpers);

        Item authors = getChild(System.AUTHORS);
        removeChild(System.AUTHORS);
        destroyChild(authors);

        Item description = getChild(System.DESCRIPTION);
        removeChild(System.DESCRIPTION);
        destroyChild(description);

        Item contact = getChild(System.CONTACT);
        removeChild(System.CONTACT);
        destroyChild(contact);

        Item copyright = getChild(System.COPYRIGHT);
        removeChild(System.COPYRIGHT);
        destroyChild(copyright);

        Item logo = getChild(System.LOGO);
        removeChild(System.LOGO);
        destroyChild(logo);

        Item slogan = getChild(System.SLOGAN);
        removeChild(System.SLOGAN);
        destroyChild(slogan);

        Item date = getChild(System.DATE);
        removeChild(System.DATE);
        destroyChild(date);

        Item version = getChild(System.VERSION);
        removeChild(System.VERSION);
        destroyChild(version);

        Item name = getChild(System.NAME);
        removeChild(System.NAME);
        destroyChild(name);

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

/*??
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
*/
    }
}

