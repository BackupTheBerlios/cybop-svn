/*
 * $RCSfile: HelloWorldLauncher.java,v $
 *
 * Copyright (c) 1999-2002. Christian Heller. All rights reserved.
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

package org.resmedicinae.application.sample.helloworld;

import java.lang.*;
import java.util.*;
import org.resmedicinae.resmedlib.component.activity.*;
import org.resmedicinae.resmedlib.component.configuration.*;
import org.resmedicinae.resmedlib.component.context.*;
import org.resmedicinae.resmedlib.component.control.*;
import org.resmedicinae.resmedlib.component.model.*;
import org.resmedicinae.resmedlib.component.view.*;

/**
 * This class launches the Hello World application.
 *
 * @version $Revision: 1.1 $ $Date: 2008-10-17 23:08:32 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class HelloWorldLauncher extends Object {

    /*
     * Launches the Hello World application.
     *
     * @param args the command line arguments for the application
     */
    public static void main(String[] args) {

        try {

            System.out.println("Create Hello World application.");
            HelloWorldControllerImpl c = new HelloWorldControllerImpl();

            if (c != null) {

                if (c instanceof Executable) {

                    System.out.println("Execute the component.");
                    c.execute();
                }

                if (c instanceof Contextualizable) {

                    System.out.println("Contextualize the component.");
                    Context ctxt = c.getDefaultContext();

                    if (ctxt != null) {

                        ctxt.put("system_configuration_location", "");
                        ctxt.put("local_configuration_location", "");
                        ctxt.put("user_configuration_location", "");
                        c.setContext(ctxt);
                        c.contextualize(ctxt);

                    } else {

                        throw new NullPointerException("Could not work on context. The context is null.");
                    }
                }

                if (c instanceof Configurable) {

                    System.out.println("Configure the component.");
                    c.setConfigurationManager(c.getDefaultConfigurationManager());
                    c.configure(c.getConfigurationManager());
                }

                if (c instanceof Initializable) {

                    System.out.println("Initialize the component.");
                    c.initialize();
                }

                if (c instanceof Loadable) {

                    System.out.println("Load the component.");
                    c.setModel(c.getDefaultModel());
                    c.load((Model) c.getModel());
                }

                if (c instanceof Showable) {

                    System.out.println("Show the component.");
                    c.setView(c.getDefaultView());
                    c.show((View) c.getView());
                }

                if (c instanceof Startable) {

                    System.out.println("Start the component.");
                    c.start();
                }

            } else {

                throw new NullPointerException("Could not say 'Hello World!'. The Hello World application is null.");
            }

        } catch (Exception e) {

            System.out.println("Could not launch Hello World application. Undiscovered exception:\n");
            e.printStackTrace();
        }
    }
}

