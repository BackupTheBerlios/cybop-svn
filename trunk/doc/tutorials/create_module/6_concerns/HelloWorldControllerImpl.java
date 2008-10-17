/*
 * $RCSfile: HelloWorldControllerImpl.java,v $
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
import org.resmedicinae.resmedlib.component.activity.*;
import org.resmedicinae.resmedlib.component.configuration.*;
import org.resmedicinae.resmedlib.component.context.*;
import org.resmedicinae.resmedlib.component.control.*;
import org.resmedicinae.resmedlib.component.view.*;

/**
 * This class represents the Hello World controller.
 *
 * @version $Revision: 1.1 $ $Date: 2008-10-17 23:08:32 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class HelloWorldControllerImpl extends ApplicationControllerImpl implements Contextualizable, Configurable, Initializable, Showable {

    /**
     * Says "Hello World!".
     */
    public void sayHelloWorld() {

        System.out.println("\n\n\n");
        System.out.println("Hello World!");
        System.out.println("\n\n\n");
    }
}

