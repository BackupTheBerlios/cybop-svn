/*
 * $RCSfile: Family.java,v $
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
import cybop.core.signal.*;
import cybop.core.system.chain.*;
import cybop.core.system.system.*;

/**
 * This class represents a family.<br><br>
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
 * A family corresponds to a family in biology or human society and can such
 * consist of many systems.<br><br>
 *
 * @version $Revision: 1.9 $ $Date: 2003-04-23 13:08:57 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class Family extends System {

    //
    // Children names.
    //

    /** The available systems. */
    public static final String AVAILABLE_SYSTEMS = new String("available_systems");

    /** The systems count. */
    public static final String SYSTEMS_COUNT = new String("systems_count");

    /** The system class name. */
    public static final String SYSTEM_CLASS_NAME = new String("system_class_name");

    /** The system configuration location. */
    public static final String SYSTEM_CONFIGURATION_LOCATION = new String("system_configuration_location");

    /** The system. */
    public static final String SYSTEM = new String("system");

    /** The external systems count. */
    public static final String EXTERNAL_SYSTEMS_COUNT = new String("external_systems_count");

    /** The external system command. */
    public static final String EXTERNAL_SYSTEM_COMMAND = new String("external_system_command");

    /** The external system. */
    public static final String EXTERNAL_SYSTEM = new String("external_system");

    //
    // Default children.
    //

    /** The default available systems. */
    public Item defaultAvailableSystems;

    /** The default systems count. */
    public Item defaultSystemsCount;

    /** The default system class name. */
    public Item defaultSystemClassName;

    /** The default system configuration location. */
    public Item defaultSystemConfigurationLocation;

    /** The default system. */
    public Item defaultSystem;

    /** The default external systems count. */
    public Item defaultExternalSystemsCount;

    /** The default external system command. */
    public Item defaultExternalSystemCommand;

    /** The default external system. */
    public Item defaultExternalSystem;

    //
    // Default children.
    //

    /**
     * Returns the default available systems.
     *
     * @return the default available systems
     */
    public String getDefaultAvailableSystems() {

        return new String("cybop.core.basic.Item");
    }

    /**
     * Returns the default systems count.
     *
     * @return the default systems count
     */
    public Integer getDefaultSystemsCount() {

        return new Integer(0);
    }

    /**
     * Returns the default system class name.
     *
     * @return the default system class name
     */
    public String getDefaultSystemClassName() {

        return null;
    }

    /**
     * Returns the default system configuration location.
     *
     * @return the default system configuration location
     */
    public String getDefaultSystemConfigurationLocation() {

        return null;
    }

    /**
     * Returns the default external systems count.
     *
     * @return the default external systems count
     */
    public Integer getDefaultExternalSystemsCount() {

        return new Integer(0);
    }

    /**
     * Returns the default external system command.
     *
     * @return the default external system command
     */
    public String getDefaultExternalSystemCommand() {

        return null;
    }

    //
    // System.
    //

    /**
     * Removes the child system from this family.
     *
     * @param n the name
     * @exception NullPointerException if the name is null
     */
    public void removeSystem(String n) throws NullPointerException {

        if (n != null) {

            super.remove(n);

        } else {

            throw new NullPointerException("Could not remove system. The name is null.");
        }
    }

    /**
     * Adds the system to become a child of this family.
     *
     * @param n the name
     * @param s the system
     * @exception NullPointerException if the name is null
     */
    public void setSystem(String n, Item s) throws NullPointerException {

        Integer c = (Integer) get(Family.SYSTEMS_COUNT);

        if (c != null) {

            if (n != null) {

                //?? Delete this line later and use the one below!
                String ext = Family.SYSTEM;
                //?? When more modules are used, use the following line!
                //?? To be implemented yet.
//??                String ext = new String(n.getJavaObject() + "_" + java.lang.String.valueOf(c.getJavaPrimitive()));

                super.set(ext, s);
                set(Family.SYSTEMS_COUNT, new Integer(c.getJavaPrimitive() + 1));

            } else {

                throw new NullPointerException("Could not set system. The name is null.");
            }

        } else {

            throw new NullPointerException("Could not set system. The systems count is null.");
        }
    }

    /**
     * Returns the child system.
     *
     * @param n the name
     * @exception NullPointerException if the name is null
     */
    public System getSystem(String n) throws NullPointerException {

        System s = null;

        if (n != null) {

            s = (System) super.get(n);

        } else {

            throw new NullPointerException("Could not remove system. The name is null.");
        }
        
        return s;
    }

    //
    // Configuration.
    //

    /**
     * Configures this family.
     *
     * @exception NullPointerException if the configuration is null
     */
    public void configure() throws Exception, NullPointerException {

        super.configure();

        Configuration c = (Configuration) get(Family.CONFIGURATION);

        if (c != null) {

            this.defaultAvailableSystems = c.get(Family.AVAILABLE_SYSTEMS, getDefaultAvailableSystems());
            this.defaultSystemsCount = c.get(Family.SYSTEMS_COUNT, getDefaultSystemsCount());
            this.defaultSystemClassName = c.get(Family.SYSTEM_CLASS_NAME, getDefaultSystemClassName());
            this.defaultSystemConfigurationLocation = c.get(Family.SYSTEM_CONFIGURATION_LOCATION, getDefaultSystemConfigurationLocation());
//??            this.defaultSystem = c.get(Family.SYSTEM, getDefaultSystem());
            this.defaultExternalSystemsCount = c.get(Family.EXTERNAL_SYSTEMS_COUNT, getDefaultExternalSystemsCount());
            this.defaultExternalSystemCommand = c.get(Family.EXTERNAL_SYSTEM_COMMAND, getDefaultExternalSystemCommand());
//??            this.defaultExternalSystem = c.get(Family.EXTERNAL_SYSTEM, getDefaultExternalSystem());

        } else {

            java.lang.System.out.println("WARNING: Could not configure family. The configuration is null.");
        }
    }

    /**
     * Deconfigures this family.
     *
     * @exception NullPointerException if the configuration is null
     */
    public void deconfigure() throws Exception, NullPointerException {

        Configuration c = (Configuration) get(Family.CONFIGURATION);

        if (c != null) {

//??            c.set(Family.EXTERNAL_SYSTEM, this.defaultExternalSystem);
            c.set(Family.EXTERNAL_SYSTEM_COMMAND, this.defaultExternalSystemCommand);
            c.set(Family.EXTERNAL_SYSTEMS_COUNT, this.defaultExternalSystemsCount);
//??            c.set(Family.SYSTEM, this.defaultSystem);
            c.set(Family.SYSTEM_CONFIGURATION_LOCATION, this.defaultSystemConfigurationLocation);
            c.set(Family.SYSTEM_CLASS_NAME, this.defaultSystemClassName);
            c.set(Family.SYSTEMS_COUNT, this.defaultSystemsCount);
            c.set(Family.AVAILABLE_SYSTEMS, this.defaultAvailableSystems);

        } else {

            java.lang.System.out.println("WARNING: Could not deconfigure family. The configuration is null.");
        }

        super.deconfigure();
    }

    //
    // Initialization.
    //

    /**
     * Initializes this family.
     */
    public void initialize() throws Exception {

        super.initialize();

        //
        // Available systems.
        //

        set(Family.AVAILABLE_SYSTEMS, createItem((String) this.defaultAvailableSystems));

/*??
        Integer count = getAvailableSystemsCount();
        String[] s = new String[count];

        for (Integer i = 0; i < count; i++) {

            s[i] = getPreferences().get(FamilyConfiguration.AVAILABLE_SYSTEMS + "_" + Integer.toString(i), def);
        }

        return s;
*/

        int i;
        String s = null;

        //
        // Systems.
        //

        set(Family.SYSTEMS_COUNT, this.defaultSystemsCount);

/*??
        if (get(Family.SYSTEMS_COUNT) != null) {

            String cl = null;
            String conf = null;

            // Retrieve the number of systems and create them one by one.
            for (i = 0; i < ((Integer) get(Family.SYSTEMS_COUNT)).getJavaPrimitive(); i++) {

                s = new String(Family.SYSTEM + "_" + java.lang.String.valueOf(i));
                cl = new String(Family.SYSTEM_CLASS_NAME + "_" + java.lang.String.valueOf(i));
                conf = new String(Family.SYSTEM_CONFIGURATION_LOCATION + "_" + java.lang.String.valueOf(i));

//??                set(s, createComponent(c.get(cl, getDefaultSystemClassName())));
            }

        } else {

            throw new NullPointerException("Could not initialize system. The systems count is null.");
        }

        //
        // External systems.
        //

        set(Family.EXTERNAL_SYSTEMS_COUNT, this.defaultExternalSystemsCount);

        if (get(Family.EXTERNAL_SYSTEMS_COUNT) != null) {

            String cmd = null;

            // Retrieve the number of external systems and create them one by one.
            for (i = 0; i < ((Integer) get(Family.EXTERNAL_SYSTEMS_COUNT)).getJavaPrimitive(); i++) {

                s = new String(Family.EXTERNAL_SYSTEM + "_" + java.lang.String.valueOf(i));
                cmd = new String(Family.EXTERNAL_SYSTEM_COMMAND + "_" + java.lang.String.valueOf(i));

//??                set(s, createComponent(c.get(cmd, getDefaultExternalSystemCommand())));
            }

        } else {

            throw new NullPointerException("Could not initialize system. The external systems count is null.");
        }
*/
    }

    /**
     * Finalizes this family.
     */
    public void finalizz() throws Exception {

        int i;
        String s;

/*??
        //
        // External systems.
        //

        if (get(Family.EXTERNAL_SYSTEMS_COUNT) != null) {

            String cmd = null;
            ExternalSystem externalSystem = null;

            for (i = 0; i < ((Integer) get(Family.EXTERNAL_SYSTEMS_COUNT)).getJavaPrimitive(); i++) {

                s = new String(Family.EXTERNAL_SYSTEM + "_" + java.lang.String.valueOf(i));
                cmd = new String(Family.EXTERNAL_SYSTEM_COMMAND + "_" + java.lang.String.valueOf(i));

//??                c.set(cmd, (String) get(cmd));

                externalSystem = (ExternalSystem) get(s);
                remove(s);
                destroyComponent(externalSystem);
            }

            Integer externalSystemsCount = (Integer) get(Family.EXTERNAL_SYSTEMS_COUNT);
//??            c.set(Family.EXTERNAL_SYSTEMS_COUNT, externalSystemsCount);
            remove(Family.EXTERNAL_SYSTEMS_COUNT);
            destroyItem(externalSystemsCount);

        } else {

            throw new NullPointerException("Could not finalize system. The external systems count is null.");
        }

        //
        // Systems.
        //

        if (get(Family.SYSTEMS_COUNT) != null) {

            String cl = null;
            String conf = null; 
            System system = null;

            for (i = 0; i < ((Integer) get(Family.SYSTEMS_COUNT)).getJavaPrimitive(); i++) {

                s = new String(Family.SYSTEM + "_" + java.lang.String.valueOf(i));
                cl = new String(Family.SYSTEM_CLASS_NAME + "_" + java.lang.String.valueOf(i));
                conf = new String(Family.SYSTEM_CONFIGURATION_LOCATION + "_" + java.lang.String.valueOf(i));

//??                c.set(cl, (String) get(cl));
//??                c.set(conf, (String) get(conf));

                system = (System) get(s);
                remove(s);
                destroyComponent(system);
            }

            Integer systemsCount = (Integer) get(Family.SYSTEMS_COUNT);
//??            c.set(Family.SYSTEMS_COUNT, systemsCount);
            remove(Family.SYSTEMS_COUNT);
            destroyItem(systemsCount);

        } else {

            throw new NullPointerException("Could not finalize system. The systems count is null.");
        }
*/

        //
        // Available systems.
        //

        Item availableSystems = get(Family.AVAILABLE_SYSTEMS);
        remove(Family.AVAILABLE_SYSTEMS);
        destroyItem(availableSystems);

/*??
        if (n != null) {

            Enumeration enum = n.depthFirstEnumeration();

            if (enum != null) {

                Object o;
                Integer i = -1;

                while (enum.hasMoreElements() == true) {

                    o = enum.nextElement();
                    i = i + 1;

                    if (o != null) {

                        getPreferences().put(FamilyConfiguration.AVAILABLE_SYSTEMS + "_" + Integer.toString(i), o.toString());
                    }
                }
            }
        }
*/

        super.finalizz();
    }

    //
    // Signal handling.
    //

    /**
     * Handles the signal.
     *
     * This method forwards the signal to all child systems.
     * Design pattern: Chain of Responsibility.
     *
     * @param s the signal
     * @param d the dummy flag indicating whether this system is a:
     * <ul>
     *     <li>false: normal system (client or server) that handles messages</li>
     *     <li>true: local server dummy which represents a remote system and
     *     needs to forward messages to the actual server</li>
     * </ul>
     * @exception NullPointerException if the systems count is null
     * @exception NullPointerException if a system is null
     */
    public void handle(Signal s, Boolean b) throws Exception, NullPointerException {
        
        super.handle(s, b);

        Integer count = (Integer) get(Family.SYSTEMS_COUNT);

        if (count != null) {

            String str = null;
            System sys = null;

//??            for (int i = 0; i < count.getJavaPrimitive(); i++) {

                //?? Delete this line later and use the one below!
                str = Family.SYSTEM;
                //?? When more modules are used, use the following line!
                //?? To be implemented yet.
//??                str = new String(Family.SYSTEM.getJavaObject() + "_" + java.lang.String.valueOf(i));
                sys = (System) getSystem(str);

                if (sys != null) {

                    sys.handle(s, b);

                } else {

//??                    throw new NullPointerException("Could not handle signal. A system is null.");
                }
//??            }

        } else {

            throw new NullPointerException("Could not handle signal. The systems count is null.");
        }
    }
}

