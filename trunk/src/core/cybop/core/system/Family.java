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
 * @version $Revision: 1.11 $ $Date: 2003-04-25 11:23:56 $ $Author: christian $
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

            super.removeChildItem(n);

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

        Integer c = (Integer) getChildItem(Family.SYSTEMS_COUNT);

        if (c != null) {

            if (n != null) {

                //?? Delete this line later and use the one below!
                String ext = Family.SYSTEM;
                //?? When more modules are used, use the following line!
                //?? To be implemented yet.
//??                String ext = new String(n.getJavaObject() + "_" + java.lang.String.valueOf(c.getJavaPrimitive()));

                super.setChildItem(ext, s);
                setChildItem(Family.SYSTEMS_COUNT, new Integer(c.getJavaPrimitive() + 1));

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

            s = (System) super.getChildItem(n);

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

        Configuration c = (Configuration) getChildItem(Family.CONFIGURATION);

        if (c != null) {

            this.defaultAvailableSystems = c.getChildItem(Family.AVAILABLE_SYSTEMS, getDefaultAvailableSystems());
            this.defaultSystemsCount = c.getChildItem(Family.SYSTEMS_COUNT, getDefaultSystemsCount());
            this.defaultSystemClassName = c.getChildItem(Family.SYSTEM_CLASS_NAME, getDefaultSystemClassName());
            this.defaultSystemConfigurationLocation = c.getChildItem(Family.SYSTEM_CONFIGURATION_LOCATION, getDefaultSystemConfigurationLocation());
//??            this.defaultSystem = c.getChildItem(Family.SYSTEM, getDefaultSystem());
            this.defaultExternalSystemsCount = c.getChildItem(Family.EXTERNAL_SYSTEMS_COUNT, getDefaultExternalSystemsCount());
            this.defaultExternalSystemCommand = c.getChildItem(Family.EXTERNAL_SYSTEM_COMMAND, getDefaultExternalSystemCommand());
//??            this.defaultExternalSystem = c.getChildItem(Family.EXTERNAL_SYSTEM, getDefaultExternalSystem());

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

        Configuration c = (Configuration) getChildItem(Family.CONFIGURATION);

        if (c != null) {

//??            c.setChildItem(Family.EXTERNAL_SYSTEM, this.defaultExternalSystem);
            c.setChildItem(Family.EXTERNAL_SYSTEM_COMMAND, this.defaultExternalSystemCommand);
            c.setChildItem(Family.EXTERNAL_SYSTEMS_COUNT, this.defaultExternalSystemsCount);
//??            c.setChildItem(Family.SYSTEM, this.defaultSystem);
            c.setChildItem(Family.SYSTEM_CONFIGURATION_LOCATION, this.defaultSystemConfigurationLocation);
            c.setChildItem(Family.SYSTEM_CLASS_NAME, this.defaultSystemClassName);
            c.setChildItem(Family.SYSTEMS_COUNT, this.defaultSystemsCount);
            c.setChildItem(Family.AVAILABLE_SYSTEMS, this.defaultAvailableSystems);

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

        setChildItem(Family.AVAILABLE_SYSTEMS, createChildItem((String) this.defaultAvailableSystems));

/*??
        Integer count = getAvailableSystemsCount();
        String[] s = new String[count];

        for (Integer i = 0; i < count; i++) {

            s[i] = getPreferences().getChildItem(FamilyConfiguration.AVAILABLE_SYSTEMS + "_" + Integer.toString(i), def);
        }

        return s;
*/

        int i;
        String s = null;

        //
        // Systems.
        //

        setChildItem(Family.SYSTEMS_COUNT, this.defaultSystemsCount);

/*??
        if (getChildItem(Family.SYSTEMS_COUNT) != null) {

            String cl = null;
            String conf = null;

            // Retrieve the number of systems and create them one by one.
            for (i = 0; i < ((Integer) getChildItem(Family.SYSTEMS_COUNT)).getJavaPrimitive(); i++) {

                s = new String(Family.SYSTEM + "_" + java.lang.String.valueOf(i));
                cl = new String(Family.SYSTEM_CLASS_NAME + "_" + java.lang.String.valueOf(i));
                conf = new String(Family.SYSTEM_CONFIGURATION_LOCATION + "_" + java.lang.String.valueOf(i));

//??                setChildItem(s, createComponent(c.getChildItem(cl, getDefaultSystemClassName())));
            }

        } else {

            throw new NullPointerException("Could not initialize system. The systems count is null.");
        }

        //
        // External systems.
        //

        setChildItem(Family.EXTERNAL_SYSTEMS_COUNT, this.defaultExternalSystemsCount);

        if (getChildItem(Family.EXTERNAL_SYSTEMS_COUNT) != null) {

            String cmd = null;

            // Retrieve the number of external systems and create them one by one.
            for (i = 0; i < ((Integer) getChildItem(Family.EXTERNAL_SYSTEMS_COUNT)).getJavaPrimitive(); i++) {

                s = new String(Family.EXTERNAL_SYSTEM + "_" + java.lang.String.valueOf(i));
                cmd = new String(Family.EXTERNAL_SYSTEM_COMMAND + "_" + java.lang.String.valueOf(i));

//??                setChildItem(s, createComponent(c.getChildItem(cmd, getDefaultExternalSystemCommand())));
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

        if (getChildItem(Family.EXTERNAL_SYSTEMS_COUNT) != null) {

            String cmd = null;
            ExternalSystem externalSystem = null;

            for (i = 0; i < ((Integer) getChildItem(Family.EXTERNAL_SYSTEMS_COUNT)).getJavaPrimitive(); i++) {

                s = new String(Family.EXTERNAL_SYSTEM + "_" + java.lang.String.valueOf(i));
                cmd = new String(Family.EXTERNAL_SYSTEM_COMMAND + "_" + java.lang.String.valueOf(i));

//??                c.setChildItem(cmd, (String) getChildItem(cmd));

                externalSystem = (ExternalSystem) getChildItem(s);
                removeChildItem(s);
                destroyComponent(externalSystem);
            }

            Integer externalSystemsCount = (Integer) getChildItem(Family.EXTERNAL_SYSTEMS_COUNT);
//??            c.setChildItem(Family.EXTERNAL_SYSTEMS_COUNT, externalSystemsCount);
            removeChildItem(Family.EXTERNAL_SYSTEMS_COUNT);
            destroyChildItem(externalSystemsCount);

        } else {

            throw new NullPointerException("Could not finalize system. The external systems count is null.");
        }

        //
        // Systems.
        //

        if (getChildItem(Family.SYSTEMS_COUNT) != null) {

            String cl = null;
            String conf = null; 
            System system = null;

            for (i = 0; i < ((Integer) getChildItem(Family.SYSTEMS_COUNT)).getJavaPrimitive(); i++) {

                s = new String(Family.SYSTEM + "_" + java.lang.String.valueOf(i));
                cl = new String(Family.SYSTEM_CLASS_NAME + "_" + java.lang.String.valueOf(i));
                conf = new String(Family.SYSTEM_CONFIGURATION_LOCATION + "_" + java.lang.String.valueOf(i));

//??                c.setChildItem(cl, (String) getChildItem(cl));
//??                c.setChildItem(conf, (String) getChildItem(conf));

                system = (System) getChildItem(s);
                removeChildItem(s);
                destroyComponent(system);
            }

            Integer systemsCount = (Integer) getChildItem(Family.SYSTEMS_COUNT);
//??            c.setChildItem(Family.SYSTEMS_COUNT, systemsCount);
            removeChildItem(Family.SYSTEMS_COUNT);
            destroyChildItem(systemsCount);

        } else {

            throw new NullPointerException("Could not finalize system. The systems count is null.");
        }
*/

        //
        // Available systems.
        //

        Item availableSystems = getChildItem(Family.AVAILABLE_SYSTEMS);
        removeChildItem(Family.AVAILABLE_SYSTEMS);
        destroyChildItem(availableSystems);

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
     * @exception NullPointerException if the signal is null
     * @exception NullPointerException if the subject is null
     * @exception NullPointerException if the systems count is null
     * @exception NullPointerException if a system is null
     */
    public void handle(Signal s, Boolean b) throws Exception, NullPointerException {

        if (s != null) {
            
            String sub = (String) s.getChildItem(Signal.SUBJECT);

            if (sub != null) {

                if (sub.isEqualTo(getName())) {

                    log(System.DEBUG_LOG_LEVEL, "Handle signal in super class.");
                    super.handle(s, b);

                } else {

                    Integer count = (Integer) getChildItem(Family.SYSTEMS_COUNT);

                    if (count != null) {

                        String str = null;
                        System sys = null;
                        int i = 0;

//??                        while (i < count.getJavaPrimitive()) {

                            //?? Delete this line later and use the one below!
                            str = Family.SYSTEM;
                            //?? When more modules are used, use the following line!
                            //?? To be implemented yet.
//??                            str = new String(Family.SYSTEM.getJavaObject() + "_" + java.lang.String.valueOf(i));
                            if (sub.isEqualTo(str)) {

                                sys = (System) getSystem(str);
    
                                if (sys != null) {

                                    log(System.DEBUG_LOG_LEVEL, "Handle signal in system " + sys);
                                    sys.handle(s, b);
                
                                } else {

                                    throw new NullPointerException("Could not handle signal. A system is null.");
                                }
                                
//??                                break;
                            }

                            i++;
//??                        }

                    } else {

                        throw new NullPointerException("Could not handle signal. The systems count is null.");
                    }
                }

            } else {

                throw new NullPointerException("Could not handle signal. The subject is null.");
            }

        } else {

            throw new NullPointerException("Could not handle signal. The signal is null.");
        }
    }
}

