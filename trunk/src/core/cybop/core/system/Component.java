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
 * @version $Revision: 1.7 $ $Date: 2003-04-17 14:50:02 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class Component extends Chain {

    //
    // Children names.
    //

    /** The globals. */
    public static final String GLOBALS = new String("globals");

    /** The finalize globals flag. */
    public static final String FINALIZE_GLOBALS_FLAG = new String("finalize_globals_flag");

    /** The configuration. */
    public static final String CONFIGURATION = new String("configuration");

    /** The finalize configuration flag. */
    public static final String FINALIZE_CONFIGURATION_FLAG = new String("finalize_configuration_flag");

    /** The log record. */
    public static final String LOG_RECORD = new String("log_record");

    /** The finalize log record flag. */
    public static final String FINALIZE_LOG_RECORD_FLAG = new String("finalize_log_record_flag");

    /** The signal memory. */
    public static final String SIGNAL_MEMORY = new String("signal_memory");

    /** The finalize signal memory flag. */
    public static final String FINALIZE_SIGNAL_MEMORY_FLAG = new String("finalize_signal_memory_flag");

    /** The named subsystem. */
    public static final String NAMED_SUBSYSTEM = new String("named_subsystem");

    /** The logger output. */
    public static final String LOGGER_OUTPUT = new String("logger_output");

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
    public Component createComponent(String n) throws Exception {

        Component c = null;

        // If a component class name is set to null, then don't try to create the component.
        if (n != null) {

            // Find class by name.
            Class cl = Class.forName((java.lang.String) n.getJavaObject());

            if (cl != null) {

                // Create component from given class.
                c = (Component) cl.newInstance();

                if (c != null) {

                    java.lang.System.out.println("INFO: Globalize component.");
                    c.globalize(get(Component.GLOBALS));

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

            java.lang.System.out.println("INFO: Deglobalize component.");
            c.deglobalize(get(Component.GLOBALS));

        } else {

            java.lang.System.out.println("DEBUG: Could not destroy component. The component is null.");
        }
    }

    //
    // Default children.
    //

    /**
     * Returns the default globals.
     *
     * @return the default globals
     */
    public String getDefaultGlobals() {

        return new String("cybop.core.basic.Item");
    }

    /**
     * Returns the default finalize globals flag.
     *
     * @return the default finalize globals flag
     */
    public Boolean getDefaultFinalizeGlobalsFlag() {

        return new Boolean(Boolean.FALSE);
    }

    /**
     * Returns the default configuration.
     *
     * @return the default configuration
     */
    public String getDefaultConfiguration() {

        return new String("cybop.core.system.chain.Configuration");
    }

    /**
     * Returns the default finalize configuration flag.
     *
     * @return the default finalize configuration flag
     */
    public Boolean getDefaultFinalizeConfigurationFlag() {

        return new Boolean(Boolean.FALSE);
    }

    /**
     * Returns the default log record.
     *
     * @return the default log record
     */
    public String getDefaultLogRecord() {

        return new String("cybop.core.system.chain.LogRecord");
    }

    /**
     * Returns the default finalize log record flag.
     *
     * @return the default finalize log record flag
     */
    public Boolean getDefaultFinalizeLogRecordFlag() {

        return new Boolean(Boolean.FALSE);
    }

    /**
     * Returns the default signal memory.
     *
     * @return the default signal memory
     */
    public String getDefaultSignalMemory() {

        return new String("cybop.core.system.chain.SignalMemory");
    }

    /**
     * Returns the default finalize signal memory flag.
     *
     * @return the default finalize signal memory flag
     */
    public Boolean getDefaultFinalizeSignalMemoryFlag() {

        return new Boolean(Boolean.FALSE);
    }

    /**
     * Returns the default named subsystem.
     *
     * @return the default named subsystem
     */
    public String getDefaultNamedSubsystem() {

        return new String(getClass().getName());
    }

    /**
     * Returns the default logger output.
     *
     * @return the default logger output
     */
    public String getDefaultLoggerOutput() {

        return new String("console");
    }

    /**
     * Returns the default log level.
     *
     * @return the default log level
     */
    public Integer getDefaultLogLevel() {

        return Component.EVENT_LOG_LEVEL;
    }

    //
    // Globalization.
    //

    /**
     * Globalizes this component.
     *
     * @param g the globals item
     * @exception NullPointerException if the globals item is null
     */
    public void globalize(Item g) throws Exception, NullPointerException {

        if (g != null) {

            set(Component.GLOBALS, g);
            set(Component.CONFIGURATION, g.get(Component.CONFIGURATION));
            set(Component.LOG_RECORD, g.get(Component.LOG_RECORD));
            set(Component.SIGNAL_MEMORY, g.get(Component.SIGNAL_MEMORY));

        } else {

            log(Component.WARNING_LOG_LEVEL, "Could not globalize component. The globals item is null.");
        }
    }

    /**
     * Deglobalizes this component.
     *
     * @param g the globals item
     * @exception NullPointerException if the globals item is null
     */
    public void deglobalize(Item g) throws Exception, NullPointerException {

        if (g != null) {

            remove(Component.SIGNAL_MEMORY);
            remove(Component.LOG_RECORD);
            remove(Component.CONFIGURATION);
            remove(Component.GLOBALS);

        } else {
            
            log(Component.WARNING_LOG_LEVEL, "Could not deglobalize component. The globals item is null.");
        }
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

        Configuration c = (Configuration) get(System.CONFIGURATION);

        if (c != null) {

        } else {

            throw new NullPointerException("Could not configure system. The configuration is null.");
        }
    }

    /**
     * Deconfigures this component.
     *
     * @exception NullPointerException if the configuration is null
     */
    public void deconfigure() throws Exception, NullPointerException {

        Configuration c = (Configuration) get(System.CONFIGURATION);

        if (c != null) {

        } else {

            throw new NullPointerException("Could not deconfigure system. The configuration is null.");
        }
    }

    //
    // Initialization.
    //

    /**
     * Initializes this component.
     *
     * @exception NullPointerException if the globals item is null
     * @exception NullPointerException if the configuration is null
     */
    public void initialize() throws Exception, NullPointerException {

        super.initialize();

        set(Component.FINALIZE_GLOBALS_FLAG, getDefaultFinalizeGlobalsFlag());
        set(Component.FINALIZE_CONFIGURATION_FLAG, getDefaultFinalizeConfigurationFlag());
        set(Component.FINALIZE_LOG_RECORD_FLAG, getDefaultFinalizeLogRecordFlag());
        set(Component.FINALIZE_SIGNAL_MEMORY_FLAG, getDefaultFinalizeSignalMemoryFlag());

        // If no globals item was set in the globalize method,
        // then create a globals item here.
        if (get(Component.GLOBALS) == null) {

            set(Component.GLOBALS, createItem(getDefaultGlobals()));
            set(Component.FINALIZE_GLOBALS_FLAG, new Boolean(Boolean.TRUE));
        }

        Item g = (Item) get(Component.GLOBALS);

        if (g != null) {

            // If no global configuration was set in the globalize method,
            // then create a configuration here.            
            if (get(Component.CONFIGURATION) == null) {

                set(Component.CONFIGURATION, createItem(getDefaultConfiguration()));
                set(Component.FINALIZE_CONFIGURATION_FLAG, new Boolean(Boolean.TRUE));
                g.set(Component.CONFIGURATION, get(Component.CONFIGURATION));
            }

            // If no global log record was set in the globalize method,
            // then create a log record here.
            if (get(Component.LOG_RECORD) == null) {

                set(Component.LOG_RECORD, createItem(getDefaultLogRecord()));
                set(Component.FINALIZE_LOG_RECORD_FLAG, new Boolean(Boolean.TRUE));
                g.set(Component.LOG_RECORD, get(Component.LOG_RECORD));
            }

            // If no global signal memory was set in the globalize method,
            // then create a signal memory here.
            if (get(Component.SIGNAL_MEMORY) == null) {

                set(Component.SIGNAL_MEMORY, createItem(getDefaultSignalMemory()));
                set(Component.FINALIZE_SIGNAL_MEMORY_FLAG, new Boolean(Boolean.TRUE));
                g.set(Component.SIGNAL_MEMORY, get(Component.SIGNAL_MEMORY));
            }

        } else {

            throw new NullPointerException("Could not initialize component. The globals item is null.");
        }

        Configuration c = (Configuration) get(Component.CONFIGURATION);

        if (c != null) {

            set(Component.NAMED_SUBSYSTEM, c.get(Component.NAMED_SUBSYSTEM, getDefaultNamedSubsystem()));
            set(Component.LOGGER_OUTPUT, c.get(Component.LOGGER_OUTPUT, getDefaultLoggerOutput()));
            set(Component.LOG_LEVEL, c.get(Component.LOG_LEVEL, getDefaultLogLevel()));

        } else {

            throw new NullPointerException("Could not initialize component. The configuration is null.");
        }
    }

    /**
     * Finalizes this component.
     *
     * @exception NullPointerException if the configuration is null
     * @exception NullPointerException if the globals item is null
     * @exception NullPointerException if the finalize log record item is null
     * @exception NullPointerException if the finalize configuration item is null
     * @exception NullPointerException if the finalize globals item is null
     */
    public void finalizz() throws Exception, NullPointerException {

        Configuration c = (Configuration) get(Component.CONFIGURATION);

        if (c != null) {

            Integer logLevel = (Integer) get(Component.LOG_LEVEL);
            c.set(Component.LOG_LEVEL, logLevel);
            remove(Component.LOG_LEVEL);
            destroyItem(logLevel);

            String loggerOutput = (String) get(Component.LOGGER_OUTPUT);
            c.set(Component.LOGGER_OUTPUT, loggerOutput);
            remove(Component.LOGGER_OUTPUT);
            destroyItem(loggerOutput);

            String namedSubsystem = (String) get(Component.NAMED_SUBSYSTEM);
            c.set(Component.NAMED_SUBSYSTEM, namedSubsystem);
            remove(Component.NAMED_SUBSYSTEM);
            destroyItem(namedSubsystem);

            Item g = (Item) get(Component.GLOBALS);
            
            if (g != null) {

                // Only destroy signal memory, if it was also created
                // in this component, which can be seen on the flag.
                if (get(Component.FINALIZE_SIGNAL_MEMORY_FLAG) != null) {

                    if (((Boolean) get(Component.FINALIZE_SIGNAL_MEMORY_FLAG)).isEqualTo(Boolean.TRUE)) {

                        Item signalMemory = (Item) get(Component.SIGNAL_MEMORY);
                        g.remove(Component.SIGNAL_MEMORY);
                        remove(Component.SIGNAL_MEMORY);
                        destroyItem(signalMemory);
                    }

                } else {
                    
                    throw new NullPointerException("Could not finalize component. The finalize configuration item is null.");
                }

                // Only destroy log record, if it was also created
                // in this component, which can be seen on the flag.            
                if (get(Component.FINALIZE_LOG_RECORD_FLAG) != null) {

                    if (((Boolean) get(Component.FINALIZE_LOG_RECORD_FLAG)).isEqualTo(Boolean.TRUE)) {

                        LogRecord logRecord = (LogRecord) get(Component.LOG_RECORD);
                        g.remove(Component.LOG_RECORD);
                        remove(Component.LOG_RECORD);
                        destroyItem(logRecord);
                    }

                } else {
                    
                    throw new NullPointerException("Could not finalize component. The finalize log record item is null.");
                }

                // Only destroy configuration, if it was also created
                // in this component, which can be seen on the flag.            
                if (get(Component.FINALIZE_CONFIGURATION_FLAG) != null) {

                    if (((Boolean) get(Component.FINALIZE_CONFIGURATION_FLAG)).isEqualTo(Boolean.TRUE)) {

                        Configuration configuration = (Configuration) get(Component.CONFIGURATION);
                        g.remove(Component.CONFIGURATION);
                        remove(Component.CONFIGURATION);
                        destroyItem(configuration);
                    }

                } else {
                    
                    throw new NullPointerException("Could not finalize component. The finalize configuration item is null.");
                }

            } else {
                
                throw new NullPointerException("Could not finalize component. The globals item is null.");
            }

            // Only destroy globals item, if it was also created
            // in this component, which can be seen on the flag.            
            if (get(Component.FINALIZE_GLOBALS_FLAG) != null) {

                if (((Boolean) get(Component.FINALIZE_GLOBALS_FLAG)).isEqualTo(Boolean.TRUE)) {

                    Item globals = (Item) get(Component.GLOBALS);
                    remove(Component.GLOBALS);
                    destroyItem(globals);
                }

            } else {

                throw new NullPointerException("Could not finalize component. The finalize globals item is null.");
            }

            Boolean finalizeSignalMemoryFlag = (Boolean) get(Component.FINALIZE_SIGNAL_MEMORY_FLAG);
            remove(Component.FINALIZE_SIGNAL_MEMORY_FLAG);
            destroyItem(finalizeSignalMemoryFlag);

            Boolean finalizeLogRecordFlag = (Boolean) get(Component.FINALIZE_LOG_RECORD_FLAG);
            remove(Component.FINALIZE_LOG_RECORD_FLAG);
            destroyItem(finalizeLogRecordFlag);

            Boolean finalizeConfigurationFlag = (Boolean) get(Component.FINALIZE_CONFIGURATION_FLAG);
            remove(Component.FINALIZE_CONFIGURATION_FLAG);
            destroyItem(finalizeConfigurationFlag);

            Boolean finalizeGlobalsFlag = (Boolean) get(Component.FINALIZE_GLOBALS_FLAG);
            remove(Component.FINALIZE_GLOBALS_FLAG);
            destroyItem(finalizeGlobalsFlag);

        } else {

            throw new NullPointerException("Could not finalize component. The configuration is null.");
        }

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

            if (l.isSmallerThanOrEqualTo((Integer) get(Component.LOG_LEVEL))) {

                LogRecord r = (LogRecord) get(Component.LOG_RECORD);
    
                if (r != null) {

                    r.set(LogRecord.MESSAGE, new String(m));
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
        cybop.core.system.region.controller.Encoder e = (cybop.core.system.region.controller.Encoder) get(Component.ENCODER);

        if (e != null) {

            e.drive(r);
            
        } else {

            /*??
             * Temporary replacement for logging.
             * The motor (output mechanism) has to be assigned here later.
             * For now, the system console is used for message output.
             */
            if (r.getThrowable() != null) {

                java.lang.System.out.println(this + " log\n" + "INFO" + ": " + ((String) r.get(LogRecord.MESSAGE)).getJavaObject() + "\n" + r.getThrowable());
                r.getThrowable().printStackTrace();

            } else {

                java.lang.System.out.println(this + " log\n" + "INFO" + ": " + ((String) r.get(LogRecord.MESSAGE)).getJavaObject());
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

        SignalMemory mem = (SignalMemory) get(Component.SIGNAL_MEMORY);

        if (mem != null) {

            mem.storeSignal(s);

        } else {

            throw new NullPointerException("Could not remember signal. The signal memory is null.");
        }
    }

    /**
     * Fetch the next signal to be handled from the signal memory.
     *
     * @return the signal
     * @exception NullPointerException if the signal memory is null
     */
    public Signal fetchSignal() throws NullPointerException {

        Signal s = null;
        SignalMemory mem = (SignalMemory) get(Component.SIGNAL_MEMORY);

        if (mem != null) {

            s = mem.fetchSignal();

        } else {

            throw new NullPointerException("Could not place signal. The signal memory is null.");
        }
        
        return s;
    }
}

