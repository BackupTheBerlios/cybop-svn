/*
 * $RCSfile: HelloWorldView.java,v $
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

import java.awt.*;
import org.resmedicinae.resmedlib.component.view.swing.*;

/**
 * This class represents the HelloWorld view.
 *
 * @version $Revision: 1.1 $ $Date: 2003-04-16 10:59:44 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class HelloWorldView extends SwingView {

    /**
     * Creates a HelloWorld panel.
     *
     * @exception NullPointerException if the HelloWorld label is null
     */
/*??
    public HelloWorldView() throws NullPointerException {

        setDisplayMode(3);

        ResLabel l = new ResLabel();

        if (l != null) {

            l.setText("Hello World!");
            l.setMinimumSize(new Dimension(600, 400));

        } else {

            throw new NullPointerException("Could not create Hello World view. The Hello World label is null.");
        }

        // Set panel properties and add child components.
        setLayout(new BorderLayout());
        add(l, BorderLayout.CENTER);
    }
*/
}

