/*
 * $RCSfile: ModelItem.java,v $
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

import cybop.core.category.*;

/**
 * This class represents a model item.
 *
 * A model item can be any arbitrary abstraction of the real world.
 * System items work on model items.
 *
 * @version $Revision: 1.4 $ $Date: 2003-06-11 14:22:23 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class ModelItem extends Item {

    //
    // Children categories.
    //

    /** The log level category. */
    public static final String LOG_LEVEL_CATEGORY = new String("log_level_category");

    //
    // Children names.
    //

    /** The log level. */
    public static final String LOG_LEVEL = new String("log_level");

    //
    // Log levels.
    //

    /** The log level to turn off logging. */
    public static final Integer OFF_LOG_LEVEL = new Integer(0);

    /** The log level indicating a serious failure. */
    public static final Integer ERROR_LOG_LEVEL = new Integer(1);

    /** The log level indicating a potential problem. */
    public static final Integer WARNING_LOG_LEVEL = new Integer(2);

    /** The log level for informational messages. */
    public static final Integer INFO_LOG_LEVEL = new Integer(3);

    /** The log level providing tracing information. */
    public static final Integer DEBUG_LOG_LEVEL = new Integer(4);

    /** The log level printing all messages, including every signal occuring in the system. */
    public static final Integer SIGNAL_LOG_LEVEL = new Integer(5);

    //
    // Default categories.
    //

    /**
     * Returns the default log level category.
     *
     * @return the default log level category
     */
    public Item getDefaultLogLevelCategory() {

        return Item.SIGNAL_LOG_LEVEL;
    }

    //
    // Categorization.
    //

    /**
     * Categorizes this item.
     */
    public void categorize() throws Exception {

        super.categorize();

        setChildCategory(Item.LOG_LEVEL_CATEGORY, c.getChildItem(Item.LOG_LEVEL_CATEGORY, getDefaultLogLevelCategory()));
    }

    /**
     * Decategorizes this item.
     */
    public void decategorize() throws Exception {

        //?? Write changes to local user configuration file.
//??        c.setChildItem(Item.LOG_LEVEL_CATEGORY, getChildCategory(Item.LOG_LEVEL_CATEGORY));
//??        removeChildCategory(Item.LOG_LEVEL_CATEGORY);

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

        setChildItem(Item.LOG_RECORD, r);
    }

    /**
     * Deglobalizes this item.
     */
    public void deglobalize() throws Exception {

        removeChildItem(Item.LOG_RECORD);
    }

    //
    // Initialization.
    //

    /**
     * Initializes this item.
     */
    public void initialize() throws Exception {

        setChildItem(Item.LOG_LEVEL, getChildCategory(Item.LOG_LEVEL_CATEGORY));
    }

    /**
     * Finalizes this item.
     *
     * This method's name is <code>finalizz</code> and not <code>finalize</code>
     * because the java computer language already uses <code>finalize</code> in
     * its <code>java.lang.Object</code> class.
     *
     * This method will be renamed to <code>finalize</code> as soon as the new
     * and simplified CYBOL computer language is used.
     */
    public void finalizz() throws Exception {

        Item logLevel = getChildItem(Item.LOG_LEVEL);
        removeChildItem(Item.LOG_LEVEL);
        destroyChildItem((Integer) logLevel);
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

            if (l.isSmallerThanOrEqualTo((Integer) getChildItem(Item.LOG_LEVEL))) {

                LogRecord r = (LogRecord) getChildItem(Item.LOG_RECORD);

                if (r != null) {

                    r.setChildItem(LogRecord.MESSAGE, new String(m));
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
    public void log(LogRecord r) throws Exception {

/*??
        cybop.core.system.region.controller.Encoder e = (cybop.core.system.region.controller.Encoder) getChildItem(Item.ENCODER);

        if (e != null) {

            e.drive(r);
            
        } else {

            /*??
             * Temporary replacement for logging.
             * The motor (output mechanism) has to be assigned here later.
             * For now, the system console is used for message output.
             */
            if (r.getThrowable() != null) {

                java.lang.System.out.println(this + " log\n" + "INFO" + ": " + ((String) r.getChildItem(LogRecord.MESSAGE)).getJavaObject() + "\n" + r.getThrowable());
                r.getThrowable().printStackTrace();

            } else {

                java.lang.System.out.println(this + " log\n" + "INFO" + ": " + ((String) r.getChildItem(LogRecord.MESSAGE)).getJavaObject());
            }

/*??
            throw new Exception("Could not log record. The motor is null.");
        }
*/
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

