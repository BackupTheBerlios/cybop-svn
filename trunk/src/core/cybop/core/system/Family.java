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

import cybop.core.category.*;
import cybop.core.model.*;
import cybop.core.model.Boolean;
import cybop.core.model.Integer;
import cybop.core.model.String;
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
 * @version $Revision: 1.21 $ $Date: 2003-06-19 16:20:03 $ $Author: christian $
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

    /** The system. */
    public static final String SYSTEM = new String("system");

    /** The external systems count. */
    public static final String EXTERNAL_SYSTEMS_COUNT = new String("external_systems_count");

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
     * Returns the default systems count category.
     *
     * @return the default systems count category
     */
    public Item getDefaultSystemsCountCategory() {

        return new Integer(0);
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
     * Returns the default external systems count category.
     *
     * @return the default external systems count category
     */
    public Item getDefaultExternalSystemsCountCategory() {

        return new Integer(0);
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
    // System.
    //

    /**
     * Adds the system to become a child of this family.
     *
     * @param n the name
     * @param s the system
     * @exception Exception if the name is null
     */
    public void setSystem(String n, Item s) throws Exception {

        Integer c = (Integer) getChild(Family.SYSTEMS_COUNT);

        if (c != null) {

            if (n != null) {

                //?? Delete this line later and use the one below!
                String ext = Family.SYSTEM;
                //?? When more modules are used, use the following line!
                //?? To be implemented yet.
//??                String ext = new String(n.getJavaObject() + "_" + java.lang.String.valueOf(c.getJavaPrimitive()));

                super.setChild(ext, s);
                setChild(Family.SYSTEMS_COUNT, new Integer(c.getJavaPrimitive() + 1));

            } else {

                throw new Exception("Could not set system. The name is null.");
            }

        } else {

            throw new Exception("Could not set system. The systems count is null.");
        }
    }

    /**
     * Removes the child system from this family.
     *
     * @param n the name
     * @exception Exception if the name is null
     */
    public void removeSystem(String n) throws Exception {

        if (n != null) {

            super.removeChild(n);

        } else {

            throw new Exception("Could not remove system. The name is null.");
        }
    }

    /**
     * Returns the child system.
     *
     * @param n the name
     * @exception Exception if the name is null
     */
    public System getSystem(String n) throws Exception {

        System s = null;

        if (n != null) {

            s = (System) super.getChild(n);

        } else {

            throw new Exception("Could not remove system. The name is null.");
        }
        
        return s;
    }

    //
    // Categorization.
    //

    /**
     * Categorizes this hierarchy.
     */
    public void categorize() throws Exception {

        super.categorize();

        setCategory(Family.AVAILABLE_SYSTEMS, getDefaultAvailableSystemsCategory());
        setCategory(Family.SYSTEMS_COUNT, getDefaultAvailableSystemsCategory());
        setCategory(Family.SYSTEM, getDefaultAvailableSystemsCategory());
        setCategory(Family.EXTERNAL_SYSTEMS_COUNT, getDefaultAvailableSystemsCategory());
        setCategory(Family.EXTERNAL_SYSTEM_COMMAND, getDefaultAvailableSystemsCategory());
        setCategory(Family.EXTERNAL_SYSTEM, getDefaultAvailableSystemsCategory());
    }

    /**
     * Decategorizes this hierarchy.
     */
    public void decategorize() throws Exception {

        removeCategory(Family.EXTERNAL_SYSTEM);
        removeCategory(Family.EXTERNAL_SYSTEM_COMMAND);
        removeCategory(Family.EXTERNAL_SYSTEMS_COUNT);
        removeCategory(Family.SYSTEM);
        removeCategory(Family.SYSTEMS_COUNT);
        removeCategory(Family.AVAILABLE_SYSTEMS);

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

        setChild(Family.AVAILABLE_SYSTEMS, createChild(getCategory(Family.AVAILABLE_SYSTEMS)));

/*??
        Integer count = getAvailableSystemsCount();
        String[] s = new String[count];
        Integer i = 0;

        while (i < count) {

            s[i] = getPreferences().getChild(FamilyConfiguration.AVAILABLE_SYSTEMS + "_" + Integer.toString(i), def);

            i++;
        }

        return s;
*/

        int i;
        String s = null;

        //
        // Systems.
        //

        setChild(Family.SYSTEMS_COUNT, getCategory(Family.SYSTEMS_COUNT));

/*??
        if (getChild(Family.SYSTEMS_COUNT) != null) {

            String cl = null;
            String conf = null;

            // Retrieve the number of systems and create them one by one.
            i = 0;

            while (i < ((Integer) getChild(Family.SYSTEMS_COUNT)).getJavaPrimitive()) {

                s = new String(Family.SYSTEM + "_" + java.lang.String.valueOf(i));
                cl = new String(Family.SYSTEM_CLASS_NAME + "_" + java.lang.String.valueOf(i));
                conf = new String(Family.SYSTEM_CONFIGURATION_LOCATION + "_" + java.lang.String.valueOf(i));

//??                setChild(s, createChild(c.getChild(cl, getDefaultSystemClassName())));

                i++;
            }

        } else {

            throw new Exception("Could not initialize system. The systems count is null.");
        }

        //
        // External systems.
        //

        setChild(Family.EXTERNAL_SYSTEMS_COUNT, this.defaultExternalSystemsCount);

        if (getChild(Family.EXTERNAL_SYSTEMS_COUNT) != null) {

            String cmd = null;

            // Retrieve the number of external systems and create them one by one.
            i = 0;
            
            while (i < ((Integer) getChild(Family.EXTERNAL_SYSTEMS_COUNT)).getJavaPrimitive()) {

                s = new String(Family.EXTERNAL_SYSTEM + "_" + java.lang.String.valueOf(i));
                cmd = new String(Family.EXTERNAL_SYSTEM_COMMAND + "_" + java.lang.String.valueOf(i));

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

        if (getChild(Family.EXTERNAL_SYSTEMS_COUNT) != null) {

            String cmd = null;
            ExternalSystem externalSystem = null;
            i = 0;

            while (i < ((Integer) getChild(Family.EXTERNAL_SYSTEMS_COUNT)).getJavaPrimitive()) {

                s = new String(Family.EXTERNAL_SYSTEM + "_" + java.lang.String.valueOf(i));
                cmd = new String(Family.EXTERNAL_SYSTEM_COMMAND + "_" + java.lang.String.valueOf(i));

//??                c.setChild(cmd, (String) getChild(cmd));

                externalSystem = (ExternalSystem) getChild(s);
                removeChild(s);
                destroyChild(externalSystem);
                
                i++;
            }

            Integer externalSystemsCount = (Integer) getChild(Family.EXTERNAL_SYSTEMS_COUNT);
//??            c.setChild(Family.EXTERNAL_SYSTEMS_COUNT, externalSystemsCount);
            removeChild(Family.EXTERNAL_SYSTEMS_COUNT);
            destroyChild(externalSystemsCount);

        } else {

            throw new Exception("Could not finalize system. The external systems count is null.");
        }

        //
        // Systems.
        //

        if (getChild(Family.SYSTEMS_COUNT) != null) {

            String cl = null;
            String conf = null; 
            System system = null;
            i = 0;

            while (i < ((Integer) getChild(Family.SYSTEMS_COUNT)).getJavaPrimitive()) {

                s = new String(Family.SYSTEM + "_" + java.lang.String.valueOf(i));
                cl = new String(Family.SYSTEM_CLASS_NAME + "_" + java.lang.String.valueOf(i));
                conf = new String(Family.SYSTEM_CONFIGURATION_LOCATION + "_" + java.lang.String.valueOf(i));

//??                c.setChild(cl, (String) getChild(cl));
//??                c.setChild(conf, (String) getChild(conf));

                system = (System) getChild(s);
                removeChild(s);
                destroyChild(system);

                i++;
            }

            Integer systemsCount = (Integer) getChild(Family.SYSTEMS_COUNT);
//??            c.setChild(Family.SYSTEMS_COUNT, systemsCount);
            removeChild(Family.SYSTEMS_COUNT);
            destroyChild(systemsCount);

        } else {

            throw new Exception("Could not finalize system. The systems count is null.");
        }
*/

        //
        // Available systems.
        //

        Item availableSystems = getChild(Family.AVAILABLE_SYSTEMS);
        removeChild(Family.AVAILABLE_SYSTEMS);
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

                if (sub.isEqualTo(getName())) {

                    java.lang.System.out.println("DEBUG: Handle signal in super class.");
                    super.handle(s, b);

                } else {

                    Integer count = (Integer) getChild(Family.SYSTEMS_COUNT);

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

                                    java.lang.System.out.println("DEBUG: Handle signal in system " + sys);
                                    sys.handle(s, b);
                
                                } else {

                                    throw new Exception("Could not handle signal. A system is null.");
                                }
                                
//??                                break;
                            }

                            i++;
//??                        }

                    } else {

                        throw new Exception("Could not handle signal. The systems count is null.");
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

