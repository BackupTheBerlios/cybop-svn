/*
 * $RCSfile: Mouse.java,v $
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

package cybop.core.system.block;

import cybop.core.model.Boolean;
import cybop.core.model.model.*;
import cybop.core.system.*;

/**
 * This class represents a mouse.<br><br>
 *
 * A mouse is an input device with several buttons that can be clicked. 
 *
 * @version $Revision: 1.2 $ $Date: 2003-05-20 06:21:59 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class Mouse extends Block {

    //
    // Sensing mouse actions.
    //

    /**
     * Senses mouse actions.
     */
    public void sense() {
        
        //?? Another waiting loop? Or catch interrupt requests somehow?

        //?? Currently not needed. Mouse actions are caught by the operating
        //?? system and then forwarded by the Java Virtual Machine (JVM).
        //?? For now, mouse events are caught directly from the JVM event queue
        //?? which is done by overloading the dispatchEvent method in class
        //?? cybop.system.family.Launcher.
    }
}

