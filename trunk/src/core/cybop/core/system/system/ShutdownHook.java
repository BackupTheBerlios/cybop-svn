/*
 * $RCSfile: ShutdownHook.java,v $
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

package cybop.core.system.system;

import cybop.core.system.System;

/**
 * This class represents a shutdown hook.<br><br>
 *
 * It usually gets registered as shutdown hook at the java virtual machine (JVM).
 * When the virtual machine receives an external termination event such as a
 * user interrupt (like typing ^C) or a system-wide event (like user logoff or
 * operating system shutdown), it will start any registered shutdown hooks
 * by calling their <code>start</code> method. These threads are blocked until
 * they have completed their shutdown process. However, shutdown of the single
 * systems should not take too long, as the virtual machine has a time limit.
 *
 * Any CYBOP system inherits from the java <code>Runnable</code> interface
 * and any system encapsulates a java thread object where it registers itselfs.
 * That means, that the virtual machine starts the encapsulated thread of this
 * shutdown hook system and that thread again calls the run method of this system.
 *
 * Actually, this shutdown hook system belongs into the <code>cybop.core.system.system</code>
 * package as it does not contain any child systems. But because this system
 * needs to access a launcher which belongs to the next higher ontological level
 * in the frameworks hierarchy, it must also belong to that package
 * <code>cybop.core.system.family</code>
 *
 * @version $Revision: 1.6 $ $Date: 2003-06-17 08:17:00 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class ShutdownHook extends System {

    //
    // Children names.
    //

    /**
     * The launcher.
     *
     * This attribute needs to be kept in extra. The attribute management
     * (set/get methods) of the Item class cannot be used because the
     * shutdown hook is already a child of launcher and launcher cannot be
     * child of shutdown hook at the same time (dependency free of circles).
     */
    private System system;

    //
    // System.
    //

    /**
     * Sets the system.
     *
     * @param s the system
     */
    public void setSystem(System s) {

        this.system = s;
    }

    /**
     * Returns the system.
     *
     * @return the system
     */
    public System getSystem() {

        return this.system;
    }

    //
    // Running.
    //
    
    /**
     * Runs this system.
     *
     * This method is called only by the encapsulated java thread.
     * Do not use it elsewise!
     *
     * @exception NullPointerException if the launcher is null
     */
    public void run() throws NullPointerException {

        super.run();

        System s = getSystem();

        if (s != null) {

            // Unfortunately, exceptions cannot be sent up the hierarchy.
            // The overloaded run method inherited from the java Runnable interface
            // does not throw an exception, so neither can that be done here.
            // That means, the exception has to be catched here.
            try {

//??                s.shutdownSystem();

            } catch (Exception e) {

                java.lang.System.out.println("ERROR: Could not run shutdown hook. The system is null.");
            }

        } else {

            throw new NullPointerException("Could not run this system. The system is null.");
        }
    }
}

