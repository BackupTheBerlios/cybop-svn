/*
 * $RCSfile: Component.java,v $
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

import cybop.core.basic.*;
import cybop.core.basic.Boolean;
import cybop.core.basic.Integer;
import cybop.core.basic.String;
import cybop.core.signal.*;
import cybop.core.system.chain.*;

/**
 * This class represents a component.
 *
 * It is a super class and forms an own level in the framework's ontology:
 *  <ul>
 *      <li>Network</li>
 *      <li>Family</li>
 *      <li>System</li>
 *      <li>Block</li>
 *      <li>Region</li>
 *      <li>Component</li>
 *      <li>Part</li>
 *      <li>Chain</li>
 *  </ul>
 *
 * A component corresponds to a cell in biology.
 *
 * A component has the following lifecycle:
 *  <ul>
 *      <li>constructor(): called without any parameters on keyword <code>new</code></li>
 *      <li>globalize(Structure globals): hands over global items for reuse to save time and memory</li>
 *      <li>configure(): adapts the properties of an item to the preferences of a user; read from a source</li>
 *      <li>initialize(): creates items (attributes) that are specific to this item; allocates necessary memory</li>
 *      <li>finalize(): destroys items (attributes) that are specific to this item; deallocates memory</li>
 *      <li>deconfigure(): writes system settings to configuration and makes it persistent</li>
 *      <li>deglobalize(Structure globals)</li>
 *      <li>destructor(): called without any parameters; not available for Java where a garbage collector destroys objects incidentally!</li>
 *  </ul>
 *
 * The <code>globalize</code> method must be called before <code>initialize</code>
 * because some global parameters (such as the configuration) need to be forwarded
 * to children. 
 *
 * @version $Revision: 1.13 $ $Date: 2003-04-24 15:58:46 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class Component extends Chain {

    //
    // Children names.
    //

    /** The configuration. */
    public static final String CONFIGURATION = new String("configuration");

    /** The log record. */
    public static final String LOG_RECORD = new String("log_record");

    /** The signal memory. */
    public static final String SIGNAL_MEMORY = new String("signal_memory");

    /** The signal. */
    public static final String SIGNAL = new String("signal");

    /** The named subsystem. */
    public static final String NAMED_SUBSYSTEM = new String("named_subsystem");

    /** The logger output. */
    public static final String LOGGER_OUTPUT = new String("logger_output");

    /** The log level. */
    public static final String LOG_LEVEL = new String("log_level");

    //
    // Children category names.
    //

    /** The configuration category. */
    public static final String CONFIGURATION_CATEGORY = new String("configuration_category");

    /** The log record category. */
    public static final String LOG_RECORD_CATEGORY = new String("log_record_category");

    /** The signal memory category. */
    public static final String SIGNAL_MEMORY_CATEGORY = new String("signal_memory_category");

    /** The signal category. */
    public static final String SIGNAL_CATEGORY = new String("signal_category");

    /** The named subsystem category. */
    public static final String NAMED_SUBSYSTEM_CATEGORY = new String("named_subsystem_category");

    /** The logger output category. */
    public static final String LOGGER_OUTPUT_CATEGORY = new String("logger_output_category");

    /** The log level category. */
    public static final String LOG_LEVEL_CATEGORY = new String("log_level_category");

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
    public static final Integer EVENT_LOG_LEVEL = new Integer(5);

    //
    // Child management.
    //

    /**
     * Creates a component.
     *
     * @param n the component class name
     * @return the component
     * @exception NullPointerException if the component class is null
     * @exception NullPointerException if the component is null
     */
    public Component createComponent(String n) throws Exception, NullPointerException {

        Component c = null;

        // If a component class name is set to null, then don't try to create the component.
        if (n != null) {

            // Find class by name.
            Class cl = Class.forName((java.lang.String) n.getJavaObject());

            if (cl != null) {

                // Create component from given class.
                c = (Component) cl.newInstance();

                if (c != null) {

                    java.lang.System.out.println("INFO: Set global component items.");
                    c.setChildItem(Component.CONFIGURATION, getChildItem(Component.CONFIGURATION));
                    c.setChildItem(Component.LOG_RECORD, getChildItem(Component.LOG_RECORD));
                    c.setChildItem(Component.SIGNAL_MEMORY, getChildItem(Component.SIGNAL_MEMORY));

                    java.lang.System.out.println("INFO: Configure component.");
                    c.configure();

                    java.lang.System.out.println("INFO: Initialize component.");
                    c.initialize();

                } else {

                    throw new NullPointerException("Could not create component. The component is null.");
                }

            } else {

                throw new NullPointerException("Could not create component. The component class is null.");
            }

        } else {

            java.lang.System.out.println("DEBUG: Could not create component. The component class name is null.");
        }

        return c;
    }

    /**
     * Destroys the component.
     *
     * @param c the component
     */
    public void destroyComponent(Component c) throws Exception {

        if (c != null) {

            java.lang.System.out.println("INFO: Finalize component.");
            c.finalizz();

            java.lang.System.out.println("INFO: Deconfigure component.");
            c.deconfigure();

            java.lang.System.out.println("INFO: Remove global component items.");
            c.removeChildItem(Component.SIGNAL_MEMORY);
            c.removeChildItem(Component.LOG_RECORD);
            c.removeChildItem(Component.CONFIGURATION);

        } else {

            java.lang.System.out.println("DEBUG: Could not destroy component. The component is null.");
        }
    }

    //
    // Default children categories.
    //

    /**
     * Returns the default signal category.
     *
     * @return the default signal category
     */
    public String getDefaultSignalCategory() {

        return new String("cybop.core.signal.Signal");
    }

    /**
     * Returns the default named subsystem category.
     *
     * @return the default named subsystem category
     */
    public String getDefaultNamedSubsystemCategory() {

        return new String(getClass().getName());
    }

    /**
     * Returns the default logger output category.
     *
     * @return the default logger output category
     */
    public String getDefaultLoggerOutputCategory() {

        return new String("console");
    }

    /**
     * Returns the default log level category.
     *
     * @return the default log level category
     */
    public Integer getDefaultLogLevelCategory() {

        return Component.EVENT_LOG_LEVEL;
    }

    //
    // Configuration.
    //

    /**
     * Configures this component.
     *
     * @exception NullPointerException if the configuration is null
     */
    public void configure() throws Exception, NullPointerException {

        Configuration c = (Configuration) getChildItem(Component.CONFIGURATION);

        if (c != null) {

            setChildCategory(Component.SIGNAL_CATEGORY, c.getChildItem(Component.SIGNAL_CATEGORY, getDefaultSignalCategory()));
            setChildCategory(Component.NAMED_SUBSYSTEM_CATEGORY, c.getChildItem(Component.NAMED_SUBSYSTEM_CATEGORY, getDefaultNamedSubsystemCategory()));
            setChildCategory(Component.LOGGER_OUTPUT_CATEGORY, c.getChildItem(Component.LOGGER_OUTPUT_CATEGORY, getDefaultLoggerOutputCategory()));
            setChildCategory(Component.LOG_LEVEL_CATEGORY, c.getChildItem(Component.LOG_LEVEL_CATEGORY, getDefaultLogLevelCategory()));

        } else {

            throw new NullPointerException("Could not configure component. The configuration is null.");
        }
    }

    /**
     * Deconfigures this component.
     *
     * @exception NullPointerException if the configuration is null
     */
    public void deconfigure() throws Exception, NullPointerException {

        Configuration c = (Configuration) getChildItem(Component.CONFIGURATION);

        if (c != null) {

            c.setChildItem(Component.LOG_LEVEL_CATEGORY, getChildCategory(Component.LOG_LEVEL_CATEGORY));
            removeChildCategory(Component.LOG_LEVEL_CATEGORY);

            c.setChildItem(Component.LOGGER_OUTPUT_CATEGORY, getChildCategory(Component.LOGGER_OUTPUT_CATEGORY));
            removeChildCategory(Component.LOGGER_OUTPUT_CATEGORY);

            c.setChildItem(Component.NAMED_SUBSYSTEM_CATEGORY, getChildCategory(Component.NAMED_SUBSYSTEM_CATEGORY));
            removeChildCategory(Component.NAMED_SUBSYSTEM_CATEGORY);

            c.setChildItem(Component.SIGNAL_CATEGORY, getChildCategory(Component.SIGNAL_CATEGORY));
            removeChildCategory(Component.SIGNAL_CATEGORY);

        } else {

            throw new NullPointerException("Could not deconfigure component. The configuration is null.");
        }
    }

    //
    // Initialization.
    //

    /**
     * Initializes this component.
     */
    public void initialize() throws Exception {

        super.initialize();

        setChildItem(Component.NAMED_SUBSYSTEM, getChildCategory(Component.NAMED_SUBSYSTEM_CATEGORY));
        setChildItem(Component.LOGGER_OUTPUT, getChildCategory(Component.LOGGER_OUTPUT_CATEGORY));
        setChildItem(Component.LOG_LEVEL, getChildCategory(Component.LOG_LEVEL_CATEGORY));
    }

    /**
     * Finalizes this component.
     */
    public void finalizz() throws Exception {

        Integer logLevel = (Integer) getChildItem(Component.LOG_LEVEL);
        removeChildItem(Component.LOG_LEVEL);
        destroyChildItem(logLevel);

        String loggerOutput = (String) getChildItem(Component.LOGGER_OUTPUT);
        removeChildItem(Component.LOGGER_OUTPUT);
        destroyChildItem(loggerOutput);

        String namedSubsystem = (String) getChildItem(Component.NAMED_SUBSYSTEM);
        removeChildItem(Component.NAMED_SUBSYSTEM);
        destroyChildItem(namedSubsystem);

        super.finalizz();
    }

    //
    // Logging.
    //

    /**
     * Logs a message with no arguments.
     *
     * @param v the log level value
     * @param m the message
     */
    public void log(Integer v, java.lang.String m) throws Exception {

        log(v, m, null);
    }

    /**
     * Logs a message with associated throwable information.
     *
     * @param v the log level
     * @param m the message
     * @param t the throwable
     * @exception NullPointerException if the log level is null
     * @exception NullPointerException if the log record is null
     */
    public void log(Integer l, java.lang.String m, java.lang.Throwable t) throws Exception, NullPointerException {

        if (l != null) {

            if (l.isSmallerThanOrEqualTo((Integer) getChildItem(Component.LOG_LEVEL))) {

                LogRecord r = (LogRecord) getChildItem(Component.LOG_RECORD);
    
                if (r != null) {

                    r.setChildItem(LogRecord.MESSAGE, new String(m));
                    r.setThrowable(t);

                } else {
                    
                    throw new NullPointerException("Could not log message. The log record is null.");
                }
    
                log(r);
            }

        } else {
            
            throw new NullPointerException("Could not log message. The log level is null.");
        }
    }

    /**
     * Logs a log record.
     *
     * @param r the log record
     * @exception NullPointerException if the log record is null
     */
    public void log(LogRecord r) throws Exception, NullPointerException {

/*??
        cybop.core.system.region.controller.Encoder e = (cybop.core.system.region.controller.Encoder) getChildItem(Component.ENCODER);

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
            throw new NullPointerException("Could not log record. The motor is null.");
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

    //
    // Signal storage.
    //

    /**
     * Store the signal by keeping it in the signal memory.
     *
     * @param s the signal
     * @exception NullPointerException if the signal memory is null
     */
    public void storeSignal(Signal s) throws NullPointerException {

        SignalMemory mem = (SignalMemory) getChildItem(Component.SIGNAL_MEMORY);

        if (mem != null) {

            String n = mem.buildName(Component.SIGNAL);

            mem.setChildItem(n, s);

        } else {

            throw new NullPointerException("Could not store signal. The signal memory is null.");
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
     * @exception NullPointerException if the signal memory is null
     * @exception NullPointerException if a child is null
     * @exception NullPointerException if the priority is null
     */
    public Signal fetchSignal() throws NullPointerException {

        Signal s = null;
        SignalMemory mem = (SignalMemory) getChildItem(Component.SIGNAL_MEMORY);

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
    
                            if (n.startsWith(Component.SIGNAL)) {
    
                                priority = (Integer) child.getChildItem(Signal.PRIORITY);
    
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

                if (s != null) {

                    mem.removeChildItem(s.getName());
                }

            } else {
    
                throw new NullPointerException("Could not place signal. The signal memory is null.");
            }

        } else {

            throw new NullPointerException("Could not place signal. The signal memory is null.");
        }

        return s;
    }
}

