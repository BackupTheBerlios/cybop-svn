/*
 * $RCSfile: ExternalSystem.java,v $
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

import cybop.core.model.String;
import cybop.core.system.System;

/**
 * This class represents an external system.<br><br> 
 *
 * An external system is one that isn't built on the ResMedLib framework.
 * Such a system runs as process of the surrounding operating system.
 *
 * @version $Revision: 1.7 $ $Date: 2003-06-12 21:16:11 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class ExternalSystem extends System {

    //
    // Static attribute ids.
    //

    /** The command. */
    public static final String COMMAND = new String("command");

    //
    // Encapsulated java process.
    //

    /**
     * Creates an encapsulated java process.
     *
     * @return the encapsulated java process
     * @exception Exception if the java runtime is null
     */
    public java.lang.Object createJavaObject() throws Exception {

        java.lang.Process p = null;
        java.lang.Runtime r = java.lang.Runtime.getRuntime();

        if (r != null) {

            // Executes the specified command and its arguments in a separate
            // process with the specified environment and working directory.
//??            p = r.exec((String) getChild(ExternalSystem.LOCATION)/*?? + " " + getArguments()*/);

        } else {

            throw new Exception("Could not create encapsulated java process. The java runtime is null.");
        }

        return p;
    }

    /**
     * Destroys the encapsulated java process.
     *
     * @param o the encapsulated java process
     * @exception Exception if the encapsulated java process is null
     */
    public void destroyJavaObject(java.lang.Object o) throws Exception {
        
        java.lang.Process p = (java.lang.Process) o;

        if (p != null) {

            // Kill subprocess. Java processes don't have a lifecycle.
            p.destroy();

        } else {

            throw new Exception("Could not destroy encapsulated java process. The encapsulated java process is null.");
        }
    }
}

