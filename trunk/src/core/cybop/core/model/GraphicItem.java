/*
 * $RCSfile: GraphicItem.java,v $
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

package cybop.core.model;

import cybop.core.basic.*;
import cybop.core.basic.String;

/**
 * This class represents a graphic item.<br><br>
 *
 * @version $Revision: 1.3 $ $Date: 2003-03-14 14:51:44 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class GraphicItem extends Item {
    
    //
    // Children names.
    //

    /** The expanse. */
    public static final String EXPANSE = new String("expanse");

    /** The minimum expanse. */
    public static final String MINIMUM_EXPANSE = new String("minimum_expanse");

    /** The foreground color. */
    public static final String FOREGROUND_COLOR = new String("foreground_color");

    /** The background color. */
    public static final String BACKGROUND_COLOR = new String("background_color");

    /** The font. */
    public static final String FONT = new String("font");

    /** The cursor. */
    public static final String CURSOR = new String("cursor");

    /** The disabled flag. */
    public static final String DISABLED_FLAG = new String("disabled_flag");

    /** The hidden flag. */
    public static final String HIDDEN_FLAG = new String("hidden_flag");

    /** The focusable flag. */
    public static final String FOCUSABLE_FLAG = new String("focusable_flag");

    /** The orientation. */
    public static final String ORIENTATION = new String("orientation");

    //
    // Orientations.
    //

    /** The 0 degree orientation. */
    public static final String DEGREE_0_ORIENTATION = new String("0_degree_orientation");

    /** The 90 degree orientation. */
    public static final String DEGREE_90_ORIENTATION = new String("90_degree_orientation");

    /** The 180 degree orientation. */
    public static final String DEGREE_180_ORIENTATION = new String("180_degree_orientation");

    /** The 270 degree orientation. */
    public static final String DEGREE_270_ORIENTATION = new String("270_degree_orientation");

    /**
     * This sub class of java awt component is only meant to catch awt events.<br><br>
     *
     * Unfortunately, handling of most events is done via graphical components.
     */
    private class JavaEventCatcher extends java.awt.Component {

//?? Eventuell EventQueue::dispatchEvent(AWTEvent evt) verwenden,
//?? d.h. u.a. auch, von java.awt.EventQueue erben!
//?? Von dort wird erst Component::dispatchEvent aufgerufen, die dann
//?? wiederum Component::processEvent aufruft.

        /**
         * Processes events occurring on this component.
         *
         * @param evt the event
         */
/*??
        protected void processEvent(AWTEvent evt) {

            if (evt instanceof FocusEvent) {

                processFocusEvent((FocusEvent)e);

            } else if (e instanceof MouseEvent) {

                switch(e.getID()) {
                  case MouseEvent.MOUSE_PRESSED:
                  case MouseEvent.MOUSE_RELEASED:
                  case MouseEvent.MOUSE_CLICKED:
                  case MouseEvent.MOUSE_ENTERED:
                  case MouseEvent.MOUSE_EXITED:
                    processMouseEvent((MouseEvent)e);
                    break;
                  case MouseEvent.MOUSE_MOVED:
                  case MouseEvent.MOUSE_DRAGGED:
                    processMouseMotionEvent((MouseEvent)e);
                    break;
                  case MouseEvent.MOUSE_WHEEL:
                    processMouseWheelEvent((MouseWheelEvent)e);
                    break;
                }
    
            } else if (e instanceof KeyEvent) {
                processKeyEvent((KeyEvent)e);
    
            } else if (e instanceof ComponentEvent) {
                processComponentEvent((ComponentEvent)e);
            } else if (e instanceof InputMethodEvent) {
                processInputMethodEvent((InputMethodEvent)e);
            } else if (e instanceof HierarchyEvent) {
                switch (e.getID()) {
                  case HierarchyEvent.HIERARCHY_CHANGED:
                    processHierarchyEvent((HierarchyEvent)e);
                    break;
                  case HierarchyEvent.ANCESTOR_MOVED:
                  case HierarchyEvent.ANCESTOR_RESIZED:
                    processHierarchyBoundsEvent((HierarchyEvent)e);
                    break;
                }
            }
        }
*/
    }

/*??
>?You may notice that a user-interface thread can only dispatch one event at
>?a time. When you press a button, the user-interface thread (eventually)
>?invokes the handleEvent() method of an AWT component. Typically, this
>?thread polls the foreign operating system for events.

Aha! That's where the event comes from. Thank you!
I've checked the java code a bit now. Two old method names have changed:
postEvent(Event e) --> dispatchEvent(AWTEvent)
handleEvent(Event evt) --> processEvent(AWTEvent)

I can neglect the dispatchEvent method since it deals with a lot of old
stuff and finally calls processEvent. So I will let my super class of
all my gui components have an inner class:

private class JavaEventCatcher extends java.awt.Component {

? ? protected void processEvent(AWTEvent evt) {

? ? ? ? ...
? ? }
}
*/
}

