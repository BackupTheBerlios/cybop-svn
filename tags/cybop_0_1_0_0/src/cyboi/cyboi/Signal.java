/*
 * $RCSfile: Signal.java,v $
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
 * This is a signal.
 *
 * A signal transports an input state throughout a system to an output state.
 * 
 * Signals can be stored in a memory.
 * 
 * @version $Revision: 1.2 $ $Date: 2003-08-15 09:34:25 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
class Signal {

    // Do not use static keyword!
    // If you do, the elements will always be overwritten
    // whenever some instance sets them.
    
    /** The priority. */
    java.lang.Object priority;

    /** The language. */
    java.lang.Object language;

    /** The subject. */
    java.lang.Object subject;

    /** The predicate. */
    java.lang.Object predicate;

    /** The owner. */
    java.lang.Object owner;

    /** The sender. */
    java.lang.Object sender;

    /** The object. */
    java.lang.Object object;

    /** The adverbial. */
    java.lang.Object adverbial;

    /** The condition. */
    java.lang.Object condition;
}

