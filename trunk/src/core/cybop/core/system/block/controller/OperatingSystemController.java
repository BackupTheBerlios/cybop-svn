/*
 * $RCSfile: OperatingSystemController.java,v $
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

package cybop.core.system.block.controller;

import cybop.core.category.*;
import cybop.core.model.*;
import cybop.core.model.Boolean;
import cybop.core.model.String;
import cybop.core.mouse.*;
import cybop.core.screen.*;
import cybop.core.screen.model.*;
import cybop.core.signal.*;
import cybop.core.system.block.*;

/**
 * This class represents an operating system controller.
 *
 * @version $Revision: 1.1 $ $Date: 2003-06-29 21:31:58 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class OperatingSystemController extends Controller {

    //
    // Default children categories.
    //

    /**
     * Returns the default system display category.
     *
     * @return the default system display category
     */
    public Item getDefaultSystemDisplayCategory() {

        return new String("cybop.core.screen.model.DesktopDisplay");
    }

    /**
     * Returns the default mouse model category.
     *
     * @return the default mouse model category
     */
    public Item getDefaultMouseModelCategory() {

        return new String("cybop.core.mouse.MouseModel");
    }

    //
    // Controlling.
    //

    /**
     * Controls the signal.
     *
     * @param s the signal
     * @exception Exception if the signal is null
     */
    public void control(Signal s) throws Exception {

        if (s != null) {

            String a = (String) s.getChild(Signal.PREDICATE);

            if (a != null) {

                if (a.isEqualTo(Controller.MOUSE_CLICKED_ACTION)) {

                    mouseClicked(s);
                }

            } else {

                throw new Exception("Could not process action. The action is null.");
            }

        } else {

            throw new Exception("Could not control signal. The signal is null.");
        }
    }

    /**
     * Reacts on mouse clicked action.
     *
     * @param s the signal
     * @exception Exception if the signal is null
     */
    protected void mouseClicked(Signal s) throws Exception {

        java.lang.System.out.println("\n\n\n\n\n mouseClicked \n\n\n\n\n");

/*??
get screen resolution
identify mouse coordinates
identify clicked window (let Desktop do that?)
identify belonging system (owner as name string)

if (owner != this.getName()) {

    owner.handle(s);
    
} else {
    
    get system's display item that was clicked
    getAction();
}
*/

/*??
        if (s != null) {

            DesktopDisplay d = getChild(Controller.SYSTEM_DISPLAY);

            if (d != null) {

                MouseModel m = (MouseModel) s.getChild(Signal.OBJECT);
    
                if (m != null) {
    
                    // Language.
                    s.setChild(Signal.LANGUAGE, Signal.NEURO_LANGUAGE);
        
                    DisplayItem i = d.getDisplayItem((Space) m.getChild(MouseModel.POINTER_POSITION));

                    if (i != null) {
    
                        // Subject.
                        // Determine the system which belongs to the clicked window.
                        //?? s.setChild(Signal.SUBJECT, name of the system that the clicked window belongs to);
        
                        // Predicate.
                        s.setChild(Signal.PREDICATE, i.getChild(DisplayItem.ACTION));
    
                        // Sender object.
                        // Determine the active console to identify the user.
                        //?? s.setChild(Signal.SENDER_OBJECT, USER);
    
                    } else {
    
                        throw new Exception("Could not react on mouse clicked action. The display item is null.");
                    }

                } else {
        
                    throw new Exception("Could not react on mouse clicked action. The mouse model is null.");
                }

            } else {

                throw new Exception("Could not react on mouse clicked action. The desktop display is null.");
            }

        } else {

            throw new Exception("Could not react on mouse clicked action. The signal is null.");
        }
*/
    }

    /**
     * Returns the display item at the given position.
     *
     * @param p the position
     * @return the item
     * @exception Exception if the display is null
     */
    protected DisplayItem getDisplayItem(Space p) throws Exception {

        DisplayItem i = null;
/*??
        Display c = (Display) getChild(Controller.SYSTEM_DISPLAY);

        if (c != null) {

            i = (DisplayItem) c.getChild(p);

        } else {

            throw new Exception("Could not get item. The display is null.");
        }
*/

        return i;
    }
}

