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

/**
 * This class represents a system item.<br><br>
 *
 * A system item has special properties like configuration or log record and
 * is able to create and send signals.
 *
 * @version $Revision: 1.6 $ $Date: 2003-06-12 21:16:11 $ $Author: christian $
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

            java.lang.System.out.println("INFO: Connect child to signal memory.");
            i.set(SystemItem.SIGNAL_MEMORY);
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

            java.lang.System.out.println("INFO: Unconnect child from signal memory.");
            i.remove(SystemItem.SIGNAL_MEMORY);
        }

        super.destroyChild();
    }

    //
    // Categorization.
    //

    /**
     * Categorizes this hierarchy.
     */
    public void categorize() throws Exception {

        super.categorize();

        setCategory(SystemItem.SIGNAL, getDefaultSignalCategory());
    }

    /**
     * Decategorizes this hierarchy.
     */
    public void decategorize() throws Exception {

        Hierarchy signal = getCategory(SystemItem.SIGNAL);
        removeCategory(SystemItem.SIGNAL);
        destroyCategory(signal);

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

        setChild(Item.SIGNAL_MEMORY, m);
    }

    /**
     * Deglobalizes this item.
     */
    public void deglobalize() throws Exception {

        removeChild(Item.SIGNAL_MEMORY);

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

        setChild(Item.ACTION, (String) getDefaultActionCategory());
    }

    /**
     * Finalizes this item.
     */
    public void finalizz() throws Exception {

        String action = (String) getChild(Item.ACTION);
        removeChild(Item.ACTION);
        destroyChild(action);

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

        SignalMemory mem = (SignalMemory) getChild(Item.SIGNAL_MEMORY);

        if (mem != null) {

            String n = mem.buildName(Item.SIGNAL);

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
     * @exception Exception if a child is null
     * @exception Exception if the priority is null
     */
    public Signal fetchSignal() throws Exception {

        Signal s = null;
        SignalMemory mem = (SignalMemory) getChild(Item.SIGNAL_MEMORY);

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

                                priority = (Integer) child.getChild(Signal.PRIORITY);

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

                    mem.removeChild(s.getName());
                }

            } else {
    
                throw new Exception("Could not place signal. The signal memory is null.");
            }

        } else {

            throw new Exception("Could not place signal. The signal memory is null.");
        }

        return s;
    }

    //
    // Logging.
    //

    /**
     * Logs a message with no arguments.
     *
     * @param l the log level
     * @param m the message
     */
    public void log(Integer l, java.lang.String m) throws Exception {

        log(l, m, null);
    }

    /**
     * Logs a message with associated throwable information.
     *
     * @param l the log level
     * @param m the message
     * @param t the throwable
     * @exception Exception if the log level is null
     * @exception Exception if the log record is null
     */
    public void log(Integer l, java.lang.String m, java.lang.Throwable t) throws Exception {

        if (l != null) {

            if (l.isSmallerThanOrEqualTo((Integer) getChild(Item.LOG_LEVEL))) {

                LogRecord r = (LogRecord) getChild(Item.LOG_RECORD);

                if (r != null) {

                    r.setChild(LogRecord.MESSAGE, new String(m));
                    r.setThrowable(t);

                } else {
                    
                    throw new Exception("Could not log message. The log record is null.");
                }
    
                log(r);
            }

        } else {
            
            throw new Exception("Could not log message. The log level is null.");
        }
    }

    /**
     * Logs a log record.
     *
     * @param r the log record
     * @exception Exception if the log record is null
     */
/*??
    public void log(LogRecord r) throws Exception {

        cybop.core.system.region.controller.Encoder e = (cybop.core.system.region.controller.Encoder) getChild(Item.ENCODER);

        if (e != null) {

            e.drive(r);
            
        } else {

            /*??
             * Temporary replacement for logging.
             * The motor (output mechanism) has to be assigned here later.
             * For now, the system console is used for message output.
             */
/*??
            if (r.getThrowable() != null) {

                java.lang.System.out.println(this + " log\n" + "INFO" + ": " + ((String) r.getChild(LogRecord.MESSAGE)).getJavaObject() + "\n" + r.getThrowable());
                r.getThrowable().printStackTrace();

            } else {

                java.lang.System.out.println(this + " log\n" + "INFO" + ": " + ((String) r.getChild(LogRecord.MESSAGE)).getJavaObject());
            }

/*??
            throw new Exception("Could not log record. The motor is null.");
        }
    }

    /**
     * Logs a message with associated throwable information.
     *
     * Displays a graphical message dialog, in addition to the pure logging
     * being done in the parent class's log method.
     *
     * @param lev the level
     * @param msg the message
     * @param t the throwable
     */
/*??
    public void log(Level lev, String msg, Throwable t) throws Exception {

        super.log(lev, msg, t);

        DisplayManager dm = getDisplayManager();

        if (dm != null) {

//??            dm.showMessage(lev, msg, t);

            //?? Example for localization!
            //?? showError(e.getLocalizedSourceControlName(), e.getLocalizedMessage());

        } else {

            // Don't throw exception here cause not all controllers/applications
            // use a graphical display, i.e. not all have a display manager.
        }
    }

    /**
     * Shows a message dialog.
     *
     * @param lev the level
     * @param msg the message
     * @param t the throwable
     */
/*??
    public void showMessage(Level lev, String msg, Throwable t) throws Exception {
    }
*/
}

