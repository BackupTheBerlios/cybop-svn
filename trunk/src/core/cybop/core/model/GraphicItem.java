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
 * @version $Revision: 1.2 $ $Date: 2003-03-14 00:04:51 $ $Author: christian $
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
Re: [jdistro-devel] Catching ALL Events
From: Christian Heller <christian.heller@tuxtax.de>
 To: Guillaume Desnoix <guillaume@desnoix.com>
 Cc: jdistro-devel@lists.sourceforge.net, jos-general@lists.sourceforge.net, kissme-general@lists.sourceforge.net
 Date: Thu, 13 Mar 2003 15:57:33 +0100

Hi Guillaume,

>?> But how does for example a mouse event come into the EventQueue?
>
>?I'm not sure but I think it comes from the Toolkit
>?(sun.awt.motif.MToolkit) using native code.

the source code of sun.awt.motif.* is not published somewhere, by chance?

>?Anyway the EventQueue is a central point for all AWT events. So you can
>?create your eventqueue (or if it not enough your toolkit) and get
>?control on these events.

O.k. Seems that for now I only have the choice to go this way ...

>?> All I want and need is ONE SINGLE method that catches ALL events.
>
>?You mean all events comming from outside. Because there is no way to
>?catch user-defined events.

What exactly do you mean? Here I probably need more explanation from you.
My thoughts are:
- identify signals (events) by a string id
- concerning work with a gui: give a button a special id (similar to
the ActionCommand in Swing's AbstractButton); no interfaces etc. needed
- when a mouse click (or any other signal) occurs, I just catch it in
the only responsible method for this, in only one root class/object
- this method also analyses to which gui component (currently on top
of all windows on the screen) the mouse click belongs and gets the
string id (signal action) of that component
- once the signal is catched, it is broadcastet through the whole
application tree of instances
- special controller objects can catch the signal, filter it (compare
strings) and react by calling some method(s)
- advantage: I am not interested whether some signal comes from a mouse,
keyboard, remote server or whatsoever - the action_id of the signal is
what counts

(Comparison with Biology: It doesn't matter whether a Human Being gets
an optical signal, e.g. by reading some command, or an acoustical one -
if the signals contain the same message, the brain can react the same.)

>?Yes, right now, we want JDistro to run on all OS (having Sun JRE 1.4 or
>?compliant). Because right now, people are more interested in a shared
>?JVM than on a new OS. But in the future...

Yes, I see and agree. I guess you can win more users faster when
going this way. Having more contributors, it should be easier then to
go "into the future". However, may be I can try and prepare that
future way already a bit.

>?CYBOP seems to be an interesting project. I will look at it when I
>?willhave more time.

I will be happy to talk about and explain my ideas or answer questions.
It is not easy to find discussion partners on this. Perhaps I can learn
more and get new ideas from you!

>?Regards, Guillaume
>?http://www.jdistro.com/

I like http://www.jdistro.org more :-)

=================================================================

Re: [jos-general] Re: [jdistro-devel] Catching ALL Events
From: Gilbert Carl Herschberger II <gchii@mindspring.com>
 To: Christian Heller <christian.heller@tuxtax.de>
 Cc: jos-general@lists.sourceforge.net
 Date: Thu, 13 Mar 2003 15:59:11 -0500

It may be helpful to understand that this is JVM-specific. While a JVM is
required to have a user-interface thread, it is up to a JVM designer to
implement it appropriately. The garbage-collection thread, the finalizer
thread and the user-interface thread within a JVM is started before the
main thread. As a JVM is launched, it invokes a JVM-specific user-interface
thread. During its lifetime, this thread reads the events and messages from
the foreign operating system and dispatchs them to the AWT. It probably
invokes a native method to read events. This program is very different from
one platform to another but dispatches events to the AWT framework. This is
how a mouse-click ends up inside the AWT.

The user-interface thread that runs on Linux is very, very different from
the user-interface thread that runs on Microsoft Window. An event in the
foreign operating system may target any process. There is a native event
queue associated with the process. The user-interface thread invokes native
methods to extract these events from the event queue of the process. It is
not sophisticated at all.

You may notice that a user-interface thread can only dispatch one event at
a time. When you press a button, the user-interface thread (eventually)
invokes the handleEvent() method of an AWT component. Typically, this
thread polls the foreign operating system for events.

In order to override the user-interface thread, you must modify the source
code of a JVM /or/ write your own dispatch classes within the AWT. And I
believe it is possible to handle non-mouse events without creating an
AWT-based frame. You can write your own native methods to read events from
the OS. But, a program must have some kind of GUI component in order for an
operating system to dispatch keyboard and mouse events to it. It does not
need to be an GUI component from the AWT.

Thanks,

=========================================================

Re: [jos-general] Catching ALL Events
From: Christian Heller <christian.heller@tuxtax.de>
 To: Gilbert Carl Herschberger II <gchii@mindspring.com>
 Cc: jos-general@lists.sourceforge.net, kissme-general@lists.sourceforge.net, jdistro-devel@lists.sourceforge.net
 Date: Fri, 14 Mar 2003 00:27:59 +0100

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

In this processEvent method, I will transform all events into unique
signal action id strings. In case of a mouse click, I will have to find
out which component the click belongs to and then take the signal string
of that component to broadcast it further.

>?In order to override the user-interface thread, you must modify the source
>?code of a JVM /or/ write your own dispatch classes within the AWT. And I
>?believe it is possible to handle non-mouse events without creating an
>?AWT-based frame. You can write your own native methods to read events from
>?the OS. But, a program must have some kind of GUI component in order for an
>?operating system to dispatch keyboard and mouse events to it. It does not
>?need to be an GUI component from the AWT.

Hm, but how about console programs? Or those with a textual user interface
(sometimes called "curses", I believe). Are they not able to catch events?
Perhaps such things cannot be realized with Java. For now, the approach
above seems to work out for me.

Thanks again,
Christian
*/
}

