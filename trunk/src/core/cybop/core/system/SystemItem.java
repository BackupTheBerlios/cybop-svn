/*
 * $RCSfile: SystemItem.java,v $
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

package cybop.core.system;

import cybop.core.category.*;
import cybop.core.model.*;
import cybop.core.model.Integer;
import cybop.core.model.String;
import cybop.core.signal.*;
import cybop.core.system.chain.*;

/**
 * This class represents a system item.<br><br>
 *
 * A system item has special properties like configuration or log record and
 * is able to create and send signals.
 *
 * @version $Revision: 1.12 $ $Date: 2003-06-20 11:32:32 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class SystemItem extends Item {

    //
    // Children names.
    //

    /** The signal memory. */
    public static final String SIGNAL_MEMORY = new String("signal_memory");

    /** The signal. */
    public static final String SIGNAL = new String("signal");

    //
    // Default categories.
    //

    /**
     * Returns the default signal memory category.
     *
     * @return the default signal memory category
     */
    public Item getDefaultSignalMemoryCategory() {

        return new String("cybop.core.category.Item");
    }

    /**
     * Returns the default signal category.
     *
     * @return the default signal category
     */
    public Item getDefaultSignalCategory() {

        return new String("cybop.core.signal.Signal");
    }

    //
    // Child management.
    //

    /**
     * Creates a child.
     *
     * @param n the category name
     * @return the child
     * @exception Exception if the category is null
     * @exception Exception if the child is null
     */
    public Item createChild(String n) throws Exception {

        Item i = super.createChild(n);

        if (i != null) {

            // It is bad programming style to use instanceof.
            // This is only temporary to ease coding until switching to new language.
            if (i instanceof SystemItem) {

                java.lang.System.out.println("INFO: Connect child to signal memory.");
                i.setChild(SystemItem.SIGNAL_MEMORY, getChild(SystemItem.SIGNAL_MEMORY));
            }
        }

        return i;
    }

    /**
     * Destroys the child.
     *
     * @param i the child
     * @exception Exception if the child is null
     */
    public void destroyChild(Item i) throws Exception {

        if (i != null) {

            // It is bad programming style to use instanceof.
            // This is only temporary to ease coding until switching to new language.
            if (i instanceof SystemItem) {

                java.lang.System.out.println("INFO: Disconnect child from signal memory.");
                i.removeChild(SystemItem.SIGNAL_MEMORY);
            }
        }

        super.destroyChild(i);
    }

    //
    // Categorization.
    //

    /**
     * Categorizes this hierarchy.
     */
    public void categorize() throws Exception {

        super.categorize();

        setCategory(SystemItem.SIGNAL_MEMORY, getDefaultSignalMemoryCategory());
        setCategory(SystemItem.SIGNAL, getDefaultSignalCategory());
    }

    /**
     * Decategorizes this hierarchy.
     */
    public void decategorize() throws Exception {

        removeCategory(SystemItem.SIGNAL);
        removeCategory(SystemItem.SIGNAL_MEMORY);

        super.decategorize();
    }

    //
    // Signal storage.
    //

    /**
     * Store the signal by keeping it in the signal memory.
     *
     * @param s the signal
     * @exception Exception if the signal memory is null
     */
    public void storeSignal(Signal s) throws Exception {

        Item mem = getChild(SystemItem.SIGNAL_MEMORY);

        if (mem != null) {

            Array n = mem.buildName(SystemItem.SIGNAL);

            mem.setChild(n, s);

        } else {

            throw new Exception("Could not store signal. The signal memory is null.");
        }
    }

    /**
     * Fetch the next signal to be handled from the signal memory.
     *
     * The signal is determined by comparing the priority levels of all signals.
     * Of these highest priority signals, the one which was first queued will
     * be returned.
     *
     * @return the signal
     * @exception Exception if the signal memory is null
     * @exception Exception if the children map is null
     * @exception Exception if a child is null
     * @exception Exception if the priority is null
     */
    public Signal fetchSignal() throws Exception {

        Signal s = null;
        Item mem = getChild(SystemItem.SIGNAL_MEMORY);

        if (mem != null) {

            int i = 0;
            int size = mem.getChildrenSize();
            Signal child = null;
            Integer priority = null;
            Integer max = new Integer(0);
            int index = -1;

            while (i < size) {

                child = (Signal) mem.getChild(i);

                if (child != null) {

                    priority = (Integer) child.getChild(Signal.PRIORITY);

                    if (priority != null) {

                        if (priority.isGreaterThan(max)) {

                            max = priority;
                            s = child;
                            index = i;
                        }

                    } else {

                        throw new Exception("Could not fetch signal. The priority is null.");
                    }

                } else {

                    break;
                }

                i++;
            }

            // If a signal was found, then remove it from the memory.
            if (index > -1) {

                mem.removeChild(index);
            }

        } else {

            throw new Exception("Could not fetch signal. The signal memory is null.");
        }

        return s;
    }
}

