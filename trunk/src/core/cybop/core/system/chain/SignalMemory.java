/*
 * $RCSfile: SignalMemory.java,v $
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

package cybop.core.system.chain;

import cybop.core.basic.*;
import cybop.core.basic.Integer;
import cybop.core.basic.String;
import cybop.core.signal.*;
import cybop.core.system.*;

/**
 * This class represents a signal memory.
 *
 * A signal memory corresponds to the region in a human brain which is
 * responsible for short-time storage of signals.<br><br>
 * [German: "Kurzzeitgedaechtnis"]
 *
 * @version $Revision: 1.2 $ $Date: 2003-04-18 16:31:07 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class SignalMemory extends Chain {
    
    //
    // Children names.
    //
    
    /** The signal. */
    public static final String SIGNAL = new String("signal");

    //
    // Initialization.
    //

    /**
     * Initializes this processor.
     */
    public void initialize() throws Exception, NullPointerException {

        super.initialize();
    }

    /**
     * Finalizes this processor.
     */
    public void finalizz() throws Exception, NullPointerException {

        super.finalizz();
    }

    //
    // Signal storage.
    //

    /**
     * Store the signal.
     *
     * @param s the signal
     * @exception NullPointerException if the children array is null
     */
    public void storeSignal(Signal s) throws NullPointerException {

        Item[] c = getChildren();

        if (c != null) {

            String n = buildName(SignalMemory.SIGNAL);

            add(n, s);

        } else {

            throw new NullPointerException("Could not store signal. The children array is null.");
        }
    }

    /**
     * Fetch the next signal to be handled.
     *
     * The signal is determined by comparing the priority levels of all signals.
     * Of these highest priority signals, the one which was first queued will
     * be returned.
     *
     * @return the signal
     * @exception NullPointerException if the children array is null
     * @exception NullPointerException if a child is null
     * @exception NullPointerException if the priority is null
     */
    public Signal fetchSignal() throws NullPointerException {

        Signal s = null;
        Item[] c = getChildren();

        if (c != null) {

            int index = 0;
            int no = getChildrenNumber();
            Signal child = null;
            String n = null;
            Integer priority = null;
            Integer max = new Integer(0);

            while (index < no) {

                child = (Signal) c[index];

                if (child != null) {

                    n = child.getName();
                    
                    if (n != null) {

                        if (n.startsWith(SignalMemory.SIGNAL)) {

                            priority = (Integer) child.get(Signal.PRIORITY);

                            if (priority != null) {

                                if (priority.isGreaterThan(max)) {

                                    max = priority;
                                    s = child;
                                }

                            } else {
            
                                throw new NullPointerException("Could not fetch signal. The priority is null.");
                            }
                        }

                    } else {
        
                        throw new NullPointerException("Could not fetch signal. The name is null.");
                    }
    
                } else {

                    throw new NullPointerException("Could not fetch signal. A child is null.");
                }

                index++;
            }

//??            remove();
//??            move all following children one position to fill the gap!

        } else {

            throw new NullPointerException("Could not fetch signal. The children array is null.");
        }

        return s;
    }
}

