/*
 * $RCSfile: OperatingSystem.java,v $
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
import cybop.core.system.system.*;

/**
 * This class represents an operating system.<br><br>
 *
 * It manages system input and output, memory organization and the
 * parallel execution of programs. The operating system offers a corresponding
 * set of actions which it knows how to handle.
 *
 * An operating system corresponds to a family in human society as it can
 * consist of many sub systems.<br><br>
 *
 * @version $Revision: 1.2 $ $Date: 2003-06-30 11:19:23 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class OperatingSystem extends MicroProgram {

    //
    // Children names.
    //

    /** The available systems. */
    public static final String AVAILABLE_SYSTEMS = new String("available_systems");

    /** The system. */
    public static final String SYSTEM = new String("system");

    /** The external system command. */
    public static final String EXTERNAL_SYSTEM_COMMAND = new String("external_system_command");

    /** The external system. */
    public static final String EXTERNAL_SYSTEM = new String("external_system");

    //
    // Default categories.
    //

    /**
     * Returns the default available systems category.
     *
     * @return the default available systems category
     */
    public Item getDefaultAvailableSystemsCategory() {

        return new String("cybop.core.category.Item");
    }

    /**
     * Returns the default system category.
     *
     * @return the default system category
     */
    public Item getDefaultSystemCategory() {

        return null;
    }

    /**
     * Returns the default external system command category.
     *
     * @return the default external system command category
     */
    public Item getDefaultExternalSystemCommandCategory() {

        return null;
    }

    /**
     * Returns the default external system category.
     *
     * @return the default external system category
     */
    public Item getDefaultExternalSystemCategory() {

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

        setCategory(OperatingSystem.AVAILABLE_SYSTEMS, getDefaultAvailableSystemsCategory());
        setCategory(OperatingSystem.SYSTEM, getDefaultSystemCategory());
        setCategory(OperatingSystem.EXTERNAL_SYSTEM_COMMAND, getDefaultExternalSystemCommandCategory());
        setCategory(OperatingSystem.EXTERNAL_SYSTEM, getDefaultExternalSystemCategory());
    }

    /**
     * Decategorizes this hierarchy.
     */
    public void decategorize() throws Exception {

        removeCategory(OperatingSystem.EXTERNAL_SYSTEM);
        removeCategory(OperatingSystem.EXTERNAL_SYSTEM_COMMAND);
        removeCategory(OperatingSystem.SYSTEM);
        removeCategory(OperatingSystem.AVAILABLE_SYSTEMS);

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

        //
        // Available systems.
        //

        setChild(OperatingSystem.AVAILABLE_SYSTEMS, createChild(getCategory(OperatingSystem.AVAILABLE_SYSTEMS)));

        //
        // Systems.
        //

/*??
        int i;
        String s = null;

        if (getChild(OperatingSystem.SYSTEMS_COUNT) != null) {

            String cl = null;
            String conf = null;

            // Retrieve the number of systems and create them one by one.
            i = 0;

            while (i < ((Integer) getChild(OperatingSystem.SYSTEMS_COUNT)).getJavaPrimitive()) {

                s = new String(OperatingSystem.SYSTEM + "_" + java.lang.String.valueOf(i));
                cl = new String(OperatingSystem.SYSTEM_CLASS_NAME + "_" + java.lang.String.valueOf(i));
                conf = new String(OperatingSystem.SYSTEM_CONFIGURATION_LOCATION + "_" + java.lang.String.valueOf(i));

//??                setChild(s, createChild(c.getChild(cl, getDefaultSystemClassName())));

                i++;
            }

        } else {

            throw new Exception("Could not initialize system. The systems count is null.");
        }

        //
        // External systems.
        //

        setChild(OperatingSystem.EXTERNAL_SYSTEMS_COUNT, this.defaultExternalSystemsCount);

        if (getChild(OperatingSystem.EXTERNAL_SYSTEMS_COUNT) != null) {

            String cmd = null;

            // Retrieve the number of external systems and create them one by one.
            i = 0;
            
            while (i < ((Integer) getChild(OperatingSystem.EXTERNAL_SYSTEMS_COUNT)).getJavaPrimitive()) {

                s = new String(OperatingSystem.EXTERNAL_SYSTEM + "_" + java.lang.String.valueOf(i));
                cmd = new String(OperatingSystem.EXTERNAL_SYSTEM_COMMAND + "_" + java.lang.String.valueOf(i));

//??                setChild(s, createChild(c.getChild(cmd, getDefaultExternalSystemCommand())));

                i++;
            }

        } else {

            throw new Exception("Could not initialize system. The external systems count is null.");
        }
*/
    }

    /**
     * Finalizes this item.
     */
    public void finalizz() throws Exception {

        int i;
        String s;

/*??
        //
        // External systems.
        //

        if (getChild(OperatingSystem.EXTERNAL_SYSTEMS_COUNT) != null) {

            String cmd = null;
            ExternalSystem externalSystem = null;
            i = 0;

            while (i < ((Integer) getChild(OperatingSystem.EXTERNAL_SYSTEMS_COUNT)).getJavaPrimitive()) {

                s = new String(OperatingSystem.EXTERNAL_SYSTEM + "_" + java.lang.String.valueOf(i));
                cmd = new String(OperatingSystem.EXTERNAL_SYSTEM_COMMAND + "_" + java.lang.String.valueOf(i));

//??                c.setChild(cmd, (String) getChild(cmd));

                externalSystem = (ExternalSystem) getChild(s);
                removeChild(s);
                destroyChild(externalSystem);
                
                i++;
            }

            Integer externalSystemsCount = (Integer) getChild(OperatingSystem.EXTERNAL_SYSTEMS_COUNT);
//??            c.setChild(OperatingSystem.EXTERNAL_SYSTEMS_COUNT, externalSystemsCount);
            removeChild(OperatingSystem.EXTERNAL_SYSTEMS_COUNT);
            destroyChild(externalSystemsCount);

        } else {

            throw new Exception("Could not finalize system. The external systems count is null.");
        }

        //
        // Systems.
        //

        if (getChild(OperatingSystem.SYSTEMS_COUNT) != null) {

            String cl = null;
            String conf = null; 
            System system = null;
            i = 0;

            while (i < ((Integer) getChild(OperatingSystem.SYSTEMS_COUNT)).getJavaPrimitive()) {

                s = new String(OperatingSystem.SYSTEM + "_" + java.lang.String.valueOf(i));
                cl = new String(OperatingSystem.SYSTEM_CLASS_NAME + "_" + java.lang.String.valueOf(i));
                conf = new String(OperatingSystem.SYSTEM_CONFIGURATION_LOCATION + "_" + java.lang.String.valueOf(i));

//??                c.setChild(cl, (String) getChild(cl));
//??                c.setChild(conf, (String) getChild(conf));

                system = (System) getChild(s);
                removeChild(s);
                destroyChild(system);

                i++;
            }

            Integer systemsCount = (Integer) getChild(OperatingSystem.SYSTEMS_COUNT);
//??            c.setChild(OperatingSystem.SYSTEMS_COUNT, systemsCount);
            removeChild(OperatingSystem.SYSTEMS_COUNT);
            destroyChild(systemsCount);

        } else {

            throw new Exception("Could not finalize system. The systems count is null.");
        }
*/

        //
        // Available systems.
        //

        Item availableSystems = getChild(OperatingSystem.AVAILABLE_SYSTEMS);
        removeChild(OperatingSystem.AVAILABLE_SYSTEMS);
        destroyChild(availableSystems);

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
     * @exception Exception if the signal is null
     * @exception Exception if the subject is null
     * @exception Exception if the systems count is null
     * @exception Exception if a system is null
     */
    public void handle(Signal s, Boolean b) throws Exception {

        if (s != null) {
            
            String sub = (String) s.getChild(Signal.SUBJECT);

            if (sub != null) {

                if (sub.isEqualTo(OperatingSystem.SELF)) {

                    java.lang.System.out.println("DEBUG: Handle signal in super class.");
                    super.handle(s, b);

                } else {

                    int i = 0;
                    int count = getCount(OperatingSystem.SYSTEM);
                    String str = null;
                    System sys = null;

                    while (i < count) {

                        str = new String(OperatingSystem.SYSTEM.getJavaObject() + "_" + java.lang.String.valueOf(i));

                        if (sub.isEqualTo(str)) {

                            sys = (System) getChild(str);

                            if (sys != null) {

                                java.lang.System.out.println("DEBUG: Handle signal in system " + sys);
                                s.setChild(Signal.SUBJECT, System.SELF);
                                sys.handle(s, b);

                            } else {

                                throw new Exception("Could not handle signal. A system is null.");
                            }

                            break;
                        }

                        i++;
                    }
                }

            } else {

                throw new Exception("Could not handle signal. The subject is null.");
            }

        } else {

            throw new Exception("Could not handle signal. The signal is null.");
        }
    }
}

