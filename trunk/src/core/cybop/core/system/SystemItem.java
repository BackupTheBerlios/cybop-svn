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

/**
 * This class represents a system item.<br><br>
 *
 * A system item has special properties like configuration or log record and
 * is able to create and send signals.
 *
 * @version $Revision: 1.1 $ $Date: 2003-05-17 22:30:11 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class SystemItem extends Item {

    //
    // Children names.
    //

    /** The signal. */
    public static final String SIGNAL = new String("signal");

    /** The action. */
    public static final String ACTION = new String("action");

    //
    // Children category names.
    //

    /** The signal category. */
    public static final String SIGNAL_CATEGORY = new String("signal_category");

    /** The action category. */
    public static final String ACTION_CATEGORY = new String("action_category");

    //
    // Default categories.
    //

    /**
     * Returns the default signal category.
     *
     * @return the default signal category
     */
    public Item getDefaultSignalCategory() {

        return new String("cybop.core.signal.Signal");
    }

    /**
     * Returns the default action category.
     *
     * @return the default action category
     */
    public Item getDefaultActionCategory() {

        return null;
    }

    //
    // Categorization.
    //

    /**
     * Categorizes this hierarchy.
     */
    public void categorize() throws Exception {

        super.categorize();

        setChildCategory(Item.SIGNAL_CATEGORY, getDefaultSignalCategory());
    }

    /**
     * Decategorizes this hierarchy.
     */
    public void decategorize() throws Exception {

        //?? Write changes to local user configuration file.
//??        c.setChildItem(Item.SIGNAL_CATEGORY, getChildCategory(Item.SIGNAL_CATEGORY));
//??        removeChildCategory(Item.SIGNAL_CATEGORY);

        super.decategorize();
    }

    //
    // Globalization.
    //

    /**
     * Globalizes this item.
     *
     * @param r the log record
     * @param m the signal memory
     */
    public void globalize(Item r, Item m) throws Exception {

        super.globalize();

        setChildItem(Item.SIGNAL_MEMORY, m);
    }

    /**
     * Deglobalizes this item.
     */
    public void deglobalize() throws Exception {

        removeChildItem(Item.SIGNAL_MEMORY);

        super.deglobalize();
    }

    //
    // Initialization.
    //

    /**
     * Initializes this item.
     */
    public void initialize() throws Exception {

        super.initialize();

        setChildItem(Item.ACTION, (String) getDefaultActionCategory());
    }

    /**
     * Finalizes this item.
     */
    public void finalizz() throws Exception {

        String action = (String) getChildItem(Item.ACTION);
        removeChildItem(Item.ACTION);
        destroyChildItem(action);

        super.finalizz();
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

        SignalMemory mem = (SignalMemory) getChildItem(Item.SIGNAL_MEMORY);

        if (mem != null) {

            String n = mem.buildName(Item.SIGNAL);

            mem.setChildItem(n, s);

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
     * @exception Exception if a child is null
     * @exception Exception if the priority is null
     */
    public Signal fetchSignal() throws Exception {

        Signal s = null;
        SignalMemory mem = (SignalMemory) getChildItem(Item.SIGNAL_MEMORY);

        if (mem != null) {

            Item[] c = mem.getChildren();
            
            if (c != null) {

                int index = 0;
                int no = mem.getChildrenNumber();
                Signal child = null;
                String n = null;
                Integer priority = null;
                Integer max = new Integer(0);
    
                while (index < no) {
    
                    child = (Signal) c[index];
    
                    if (child != null) {
    
                        n = child.getName();
                        
                        if (n != null) {
    
                            if (n.startsWith(Item.SIGNAL)) {

                                priority = (Integer) child.getChildItem(Signal.PRIORITY);

                                if (priority != null) {
    
                                    if (priority.isGreaterThan(max)) {
    
                                        max = priority;
                                        s = child;
                                    }

                                } else {

                                    throw new Exception("Could not fetch signal. The priority is null.");
                                }
                            }
    
                        } else {
            
                            throw new Exception("Could not fetch signal. The name is null.");
                        }
        
                    } else {
    
                        throw new Exception("Could not fetch signal. A child is null.");
                    }
    
                    index++;
                }

                if (s != null) {

                    mem.removeChildItem(s.getName());
                }

            } else {
    
                throw new Exception("Could not place signal. The signal memory is null.");
            }

        } else {

            throw new Exception("Could not place signal. The signal memory is null.");
        }

        return s;
    }
}

