/*
 * $RCSfile: Server.java,v $
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
 * http://www.resmedicinae.org
 * - Information in Medicine -
 */

package cybop.core.system.system;

import cybop.core.system.System;

/**
 * This class represents a server.<br><br>
 *
 * A server system is an application whose main purpose is to serve
 * requests coming from outside Client applications.
 * After startup, the server runs into a waiting loop which gets only
 * interrupted on incoming Client requests. The request is being
 * processed by forwarding different tasks to several other objects,
 * depending on what the single objects are responsible for in the system.<br><br>
 *
 * Following methods are important to use in the server lifecycle:<br>
 * <code>start()</code>: starts the server as last action of the startup process;
 * runs into a loop that is waiting for requests;
 * should call <code>run</code> method of <code>java.lang.Runnable</code><br>
 * <code>suspend()</code>: deactivates the server<br>
 * <code>resume()</code>: reactivates the server<br>
 * <code>stop()</code>: stops the server's waiting loop<br>
 *
 * @version $Revision: 1.2 $ $Date: 2003-02-19 17:15:17 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class Server extends System {

    //
    // Static attribute ids.
    //
    
    //
    // Initialization.
    //

    /**
     * Initializes this item.
     */
    public void initialize() throws Exception {
    }

    /**
     * Finalizes this item.
     */
    public void finalizz() throws Exception {
    }

    //
    // Start.
    //

    /**
     * Starts this server.
     */
    public void start() throws Exception {
    }

    /**
     * Stops this server.
     */
    public void stop() throws Exception {
    }

    //
    // Suspend.
    //

    /**
     * Suspends this server.
     */
    public void suspend() throws Exception {
    }

    /**
     * Resumes this server.
     */
    public void resume() throws Exception {
    }
}

