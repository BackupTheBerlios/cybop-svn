/*
 * $RCSfile: Launcher.java,v $
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

package cybop.core.system.system;

import cybop.core.category.*;
import cybop.core.model.*;
import cybop.core.model.Boolean;
import cybop.core.model.Integer;
import cybop.core.model.String;
import cybop.core.mouse.*;
import cybop.core.signal.*;
import cybop.core.screen.*;
import cybop.core.system.*;
import cybop.core.system.System;
import cybop.core.system.block.*;

/**
 * This class represents a launcher.<br><br>
 *
 * Its task is to startup and shutdown a child system as well as to provide
 * further lifecycle methods (start, stop, restart, help) for the system.<br><br>
 *
 * The launcher is the only class in the whole CYBOP framework that owns a
 * static method <code>main</code>. This method provides an interface to
 * the outside and can be called by shell scripts/batch files.<br><br>
 *
 * The main method initializes the launcher. The launch method then calls the
 * lifecycle method which was given as command line argument.<br><br>
 *
 * There are three possible ways of how to shutdown a system:<br>
 * <ol>
 *     <li>A signal from inside the system, i.e. actually from another system
 *     such as the user who clicks on "Exit" in some menu or so.
 *     This signal is handled by returning the system shutdown waiting loop
 *     so that the following <code>shutdown</code> method can be called in
 *     <code>startup</code>.</li>
 *     <li>Invocation of a shutdown script from outside the system, just like
 *     a startup script has been called before to startup the system.
 *     A socket needs to be created in the <code>shutdown</code> method.
 *     It handles the shutdown of the running system process.</li>
 *     <li>An external event that causes the whole java virtual machine (JVM)
 *     to shutdown. Such a termination event may be a user interrupt (like typing ^C)
 *     or a system-wide event (like user logoff or operating system shutdown).
 *     A special shutdown hook item, running in an own thread, will be called
 *     by the java virtual machine before it shuts down. However, shutdown time
 *     is mostly limited so the shutdown method shouldn't take too much of it.</li>
 * </ol>
 *
 * @version $Revision: 1.2 $ $Date: 2003-07-15 09:44:19 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class Launcher extends System {

    //
    // Children names.
    //

    /** The command line arguments container. */
    private java.lang.String[] arguments;

    /** The lifecycle action. */
    public static final String LIFECYCLE_ACTION = new String("lifecycle_action");

    /** The java event catcher. */
    private JavaEventCatcher javaEventCatcher;

    /** The shutdown flag. */
    public static final String SHUTDOWN_FLAG = new String("shutdown_flag");

    /** The shutdown hook. */
    public static final String SHUTDOWN_HOOK = new String("shutdown_hook");

    //
    // Command line arguments.
    //

    /** The system category argument. */
    public static final String SYSTEM_ARGUMENT = new String("-system");

    /** The lifecycle action argument. */
    public static final String LIFECYCLE_ACTION_ARGUMENT = new String("-action");

    /** The help argument. */
    public static final String HELP_ARGUMENT = new String("-help");

    //
    // Child management.
    //

    /**
     * Adds the item to become a child of this item.
     *
     * @param n the name
     * @param i the item
     * @exception Exception if the name is null
     */
/*??
    public void setChild(String n, Item i) throws Exception {

        super.setChild(n, i);

        if (n != null) {

            if (n.isEqualTo(Launcher.COMMUNICATION_PARTNER)) {

                setShutdownHook((ShutdownHook) i);
            }

        } else {

            throw new Exception("Could not set item. The name is null.");
        }
    }

    /**
     * Removes the child item from this item.
     *
     * @param n the name
     * @exception Exception if the name is null
     */
/*??
    public void removeChild(String n) throws Exception {

        if (n != null) {

            if (n.isEqualTo(Launcher.COMMUNICATION_PARTNER)) {

                removeShutdownHook((ShutdownHook) getChild(n));
            }

        } else {

            throw new Exception("Could not set item. The name is null.");
        }

        super.removeChild(n);
    }

    //
    // Default categories.
    //

    /**
     * Returns the default controller category.
     *
     * @return the default controller category
     */
    public Item getDefaultControllerCategory() {

        return new String("cybop.core.system.block.controller.OperatingSystemController");
    }

    /**
     * Returns the default lifecycle action category.
     *
     * @return the default lifecycle action category
     */
    public Item getDefaultLifecycleActionCategory() {

        return Launcher.STARTUP_SYSTEM_ACTION;
    }

    /**
     * Returns the default shutdown flag category.
     *
     * @return the default shutdown flag category
     */
    public Item getDefaultShutdownFlagCategory() {

        return new Boolean(Boolean.FALSE);
    }

    /**
     * Returns the default shutdown hook category.
     *
     * @return the default shutdown hook category
     */
    public Item getDefaultShutdownHookCategory() {

        return new String("cybop.core.system.system.ShutdownHook");
    }

    /**
     * Returns the default shutdown socket category.
     *
     * @return the default shutdown socket category
     */
    public Item getDefaultShutdownSocketCategory() {

        return new String("cybop.core.system.system.ShutdownSocket");
    }

    //
    // Arguments.
    //

    /*
     * Sets the arguments.
     *
     * @param a the arguments
     */
    public void setArguments(java.lang.String[] a) {

        this.arguments = a;
    }

    /**
     * Returns the arguments.
     *
     * @return the arguments
     */
    public java.lang.String[] getArguments() {

        return this.arguments;
    }

    /**
     * Returns an argument.
     *
     * @param key the argument key
     * @param def the default argument
     * @return the argument
     * @exception Exception if the arguments container is null
     * @exception Exception if an argument is null
     */
    public Item getArgument(String key, Item def) throws Exception {

        Item a = def;
        java.lang.String[] args = getArguments();

        if (args != null) {

            String s = null;
            int i = 0;

            while (i < args.length) {

                s = new String(args[i]);
                
                if (s != null) {

                    if (s.isEqualTo(key)) {

                        a = new String(args[i + 1]);
                    }

                } else {

                    throw new Exception("Could not get argument. An argument is null.");
                }
                
                i++;
            }

        } else {

            throw new Exception("Could not get argument. The arguments container is null.");
        }
        
        return a;
    }

    //
    // Java event catcher.
    //

    /**
     * Creates a java event catcher.
     *
     * @return the java event catcher
     * @exception Exception if the java event catcher is null
     */
    public JavaEventCatcher createJavaEventCatcher() throws Exception {

        JavaEventCatcher jec = new JavaEventCatcher();
        
        if (jec != null) {

            // Exceptionally, the private internal class JavaEventCatcher has
            // permittance to know about its container (this launcher).
            // This is necessary to forward java awt events to this launcher.             
            jec.setLauncher(this);

        } else {
    
            throw new Exception("Could not create java event catcher. The java event catcher is null.");
        }
        
        return jec;
    }

    /*
     * Destroys the java event catcher.
     *
     * @param jec the java event catcher
     * @exception Exception if the java event catcher is null
     */
    public void destroyJavaEventCatcher(JavaEventCatcher jec) throws Exception {

        if (jec != null) {

            jec.setLauncher(null);

        } else {

            throw new Exception("Could not destroy java event catcher. The java event catcher is null.");
        }
    }

    /*
     * Sets the java event catcher.
     *
     * @param jec the java event catcher
     */
    public void setJavaEventCatcher(JavaEventCatcher jec) {

        this.javaEventCatcher = jec;
    }

    /**
     * Returns the java event catcher.
     *
     * @return the java event catcher
     */
    public JavaEventCatcher getJavaEventCatcher() {

        return this.javaEventCatcher;
    }

    //
    // Shutdown hook.
    //

    /**
     * Creates the shutdown hook.
     *
     * @param n the category name
     * @return the shutdown hook
     * @exception Exception if the shutdown hook is null
     */
    public ShutdownHook createShutdownHook(Array n) throws Exception {

        ShutdownHook s = (ShutdownHook) createChild(n);

        if (s != null) {

            // This is an exceptional setting.
            // Normally, child items should not know about the parent item.
            // However, this shutdown hook as thread running in parallel to this launcher,
            // needs to know this launcher so that it can eventually send a shutdown signal. 
            s.setSystem(this);

        } else {
    
            throw new Exception("Could not create shutdown hook. The shutdown hook is null.");
        }

        return s;
    }

    /*
     * Destroys the shutdown hook.
     *
     * @param i the child
     * @exception Exception if the child is null
     */
    public void destroyShutdownHook(ShutdownHook s) throws Exception {

        if (s != null) {

            s.setSystem(null);

            destroyChild(s);

        } else {
    
            throw new Exception("Could not destroy shutdown hook. The shutdown hook is null.");
        }
    }

    /**
     * Sets the shutdown hook.
     *
     * @param s the shutdown hook
     * @exception Exception if the java runtime is null
     * @exception Exception if the shutdown hook is null
     */
    private void setShutdownHook(ShutdownHook s) throws Exception {

        java.lang.Runtime r = java.lang.Runtime.getRuntime();

        if (r != null) {

            if (s != null) {

                r.addShutdownHook((java.lang.Thread) s.getJavaObject());

            } else {
    
                throw new Exception("Could not set shutdown hook. The shutdown hook is null.");
            }
    
        } else {
    
            throw new Exception("Could not set shutdown hook. The java runtime is null.");
        }
    }

    /**
     * Removes the shutdown hook.
     *
     * @param s the shutdown hook
     * @exception Exception if the java runtime is null
     * @exception Exception if the shutdown hook is null
     */
    private void removeShutdownHook(ShutdownHook s) throws Exception {

        java.lang.Runtime r = java.lang.Runtime.getRuntime();
        
        if (r != null) {
    
            if (s != null) {

                r.removeShutdownHook((java.lang.Thread) s.getJavaObject());

            } else {
    
                throw new Exception("Could not remove shutdown hook. The shutdown hook is null.");
            }

        } else {
    
            throw new Exception("Could not remove shutdown hook. The java runtime is null.");
        }
    }

    //
    // Categorization.
    //

    /**
     * Categorizes this hierarchy.
     */
    public void categorize() throws Exception {

        super.categorize();

        setCategory(Launcher.LIFECYCLE_ACTION, getArgument(Launcher.LIFECYCLE_ACTION_ARGUMENT, getDefaultLifecycleActionCategory()));
        setCategory(Launcher.SHUTDOWN_FLAG, getDefaultShutdownFlagCategory());
        setCategory(Launcher.SHUTDOWN_HOOK, getDefaultShutdownHookCategory());
        // This system category is normally set and removed in the Family class.
        // It is here overwritten with the command line argument.
        setCategory(Launcher.SYSTEM, getArgument(Launcher.SYSTEM_ARGUMENT, getDefaultSystemCategory()));
    }

    /**
     * Decategorizes this hierarchy.
     */
    public void decategorize() throws Exception {

        removeCategory(Launcher.SHUTDOWN_HOOK);
        removeCategory(Launcher.SHUTDOWN_FLAG);
        removeCategory(Launcher.LIFECYCLE_ACTION);

        super.decategorize();
    }

    //
    // Initialization.
    //

    /**
     * Initializes this item.
     */
    public void initialize() throws Exception {

        super.initialize();

        if (getArgument(Launcher.HELP_ARGUMENT, null) != null) {

            setChild(Launcher.LIFECYCLE_ACTION, Launcher.SHOW_HELP_ACTION);

        } else {

            setChild(Launcher.LIFECYCLE_ACTION, (Item) getCategory(Launcher.LIFECYCLE_ACTION));
            //?? Temporary until event handling doesn't need java awt EventQueue anymore.
            setJavaEventCatcher(createJavaEventCatcher());
            setChild(Launcher.SHUTDOWN_FLAG, (Item) getCategory(Launcher.SHUTDOWN_FLAG));
            setChild(Launcher.SHUTDOWN_HOOK, createShutdownHook(getCategory(Launcher.SHUTDOWN_HOOK)));
        }
    }

    /**
     * Finalizes this item.
     */
    public void finalizz() throws Exception {

        // Remove shutdown hook first to avoid another shutdown call
        // from the java virtual machine to this system.
        Item shutdownHook = getChild(Launcher.SHUTDOWN_HOOK);
        removeChild(Launcher.SHUTDOWN_HOOK);
        destroyShutdownHook((ShutdownHook) shutdownHook);

        Item shutdownFlag = getChild(Launcher.SHUTDOWN_FLAG);
        removeChild(Launcher.SHUTDOWN_FLAG);
        destroyChild(shutdownFlag);

        //?? Temporary until event handling doesn't need java awt EventQueue anymore.
        destroyJavaEventCatcher(getJavaEventCatcher());
        setJavaEventCatcher(null);

        Item lifecycleAction = getChild(Launcher.LIFECYCLE_ACTION);
        removeChild(Launcher.LIFECYCLE_ACTION);
        destroyChild(lifecycleAction);

        super.finalizz();
    }
}

