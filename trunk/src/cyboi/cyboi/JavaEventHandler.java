/*
 * $RCSfile: JavaEventHandler.java,v $
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

package cyboi;

/**
 * This is the java event handler.
 *
 * It dispatches java.awt.AWTEvent events, transforms them into CYBOI signals
 * and finally sends them through the whole system.
 *
 * Unfortunately, handling of most events is done via graphical components in java.
 *
 * @version $Revision: 1.1 $ $Date: 2003-07-18 11:24:32 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
class JavaEventHandler extends java.awt.EventQueue {

    /**
     * Dispatches an event.
     *
     * Example:
     * On clicking the mouse or a button, a hardware interrupt occurs.
     * The operating system catches this interrupt and transforms it
     * correctly into some meaningful piece of software code.
     * Device drivers are necessary to do this translation.
     * Now, all running processes are informed by the operating system.
     * In the case of Java processes (applications), the Java Virtual Machine (JVM)
     * (which is an application itself to the operating system) receives the events.
     * Finally, the JVM puts the events into the event queue of the
     * Abstract Windowing Toolkit (AWT).
     *
     * As we don't want to use event listeners and the like in CYBOP
     * (they are improper and unnecessarily complicated in our opinion -
     * as interfaces/ concerns/ aspects are, anyway),
     * we catch all events directly in the event queue, their first point
     * of occurence in the Java Development Kit (JDK) Class Hierarchy.
     *
     * The AWT distinguishes between different types of events and filters
     * them out by comparing with "instanceof" - again improper.
     * As a rule of thumb, one should never use "instanceof" in
     * Object Oriented Programming (OOP) but rather rely on inheritance.
     * However, we have to use these events here but will transform them
     * into CYBOP signals which have a predicate which is a string that
     * identifies the signal's (event's) action.
     *
     * By the way, Java events can be posted using:
     * Toolkit.getEventQueue().postEvent(evt);
     *
     * @param evt the java awt event sent directly from the JVM to here
     */
    protected void dispatchEvent(java.awt.AWTEvent evt) {

        java.lang.System.out.println("INFO: Dispatch event: " + evt);

        //?? For now, we also call the AWT event handling.
        //?? Later, we will cut it off by removing this line.
        //?? I tried removing this line:
        //?? - the frame/window still gets created
        //?? - but no contents (menue and other components) is shown
        //?? Checking this out later.
        super.dispatchEvent(evt);

        try {

/*??
            if (launcher != null) {

                launcher.handle(evt);

            } else {

                java.lang.System.out.println("ERROR: Could not dispatch java awt event. The launcher is null.");
            }
*/

        } catch (Exception e) {

            java.lang.System.out.println("ERROR: Could not dispatch java awt event. An exception occured:\n" + e);
        }
    }
}

