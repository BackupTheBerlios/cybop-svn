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
 * http://www.resmedicinae.org
 * - Information in Medicine -
 */

package cybop.core.system.family;

import cybop.core.basic.*;
import cybop.core.basic.Boolean;
import cybop.core.basic.Integer;
import cybop.core.basic.String;
import cybop.core.model.model.*;
import cybop.core.signal.*;
import cybop.core.system.*;
import cybop.core.system.System;
import cybop.core.system.block.*;
import cybop.core.system.system.*;

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
 * @version $Revision: 1.2 $ $Date: 2003-02-19 17:15:17 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class Launcher extends Family implements
    java.awt.event.ActionListener,
    java.awt.event.FocusListener,
    java.awt.event.ItemListener,
    java.awt.event.KeyListener,
    java.awt.event.MouseListener,
    java.awt.event.MouseMotionListener,
    java.awt.event.WindowFocusListener,
    java.awt.event.WindowListener,
    java.awt.event.WindowStateListener,
    javax.swing.event.DocumentListener,
    javax.swing.event.InternalFrameListener,
    javax.swing.event.ListSelectionListener,
    javax.swing.event.TreeSelectionListener {

    //
    // Command line arguments.
    //

    /** The system class name argument. */
    public static final String SYSTEM_CLASS_NAME_ARGUMENT = new String("-system");

    /** The system configuration location argument. */
    public static final String SYSTEM_CONFIGURATION_LOCATION_ARGUMENT = new String("-configuration");

    /** The lifecycle action argument. */
    public static final String LIFECYCLE_ACTION_ARGUMENT = new String("-action");

    /** The help argument. */
    public static final String HELP_ARGUMENT = new String("-help");

    //
    // Children.
    //

    /** The screen. */
    public static final String SCREEN = new String("screen");

    /** The command line arguments container. */
    private java.lang.String[] arguments;

    /** The lifecycle action. */
    public static final String LIFECYCLE_ACTION = new String("lifecycle_action");

    /** The shutdown hook. */
    public static final String SHUTDOWN_HOOK = new String("shutdown_hook");

    /** The shutdown flag. */
    public static final String SHUTDOWN_FLAG = new String("shutdown_flag");

    //
    // Actions.
    //

    /** The startup system action. */
    public static final String STARTUP_SYSTEM_ACTION = new String("startup_system_action");

    /** The shutdown system action. */
    public static final String SHUTDOWN_SYSTEM_ACTION = new String("shutdown_system_action");

    /** The shutdown system across socket action. */
    public static final String SHUTDOWN_SYSTEM_ACROSS_SOCKET_ACTION = new String("shutdown_system_across_socket_action");

    /** The start system action. */
    public static final String START_SYSTEM_ACTION = new String("start_system_action");

    /** The stop system action. */
    public static final String STOP_SYSTEM_ACTION = new String("stop_system_action");

    /** The restart system action. */
    public static final String RESTART_SYSTEM_ACTION = new String("restart_system_action");

    /** The show help action. */
    public static final String SHOW_HELP_ACTION = new String("show_help_action");

    //
    // Meta methods.
    //

    /*
     * Launches the system whose class name is given as argument.
     *
     * @param args the command line arguments
     */
    public static void main(java.lang.String[] args) {

        try {

            Launcher l = new Launcher();

            if (l != null) {

                l.setArguments(args);
                l.initialize();
                l.launch();
                l.await();
                l.finalizz();
                l.setArguments(null);

                //
                // Runtime.getRuntime().exit(0);
                // and
                // System.exit(0);
                // do the same thing.
                // The program exits normally, when the last non-daemon thread exits.
                //
                java.lang.System.out.println("INFO: Exit system normally.");
                java.lang.System.exit(0);

            } else {

                throw new NullPointerException("Could not launch system. The launcher is null.");
            }

        } catch (Exception e) {

            //
            // Runtime.getRuntime().exit(0);
            // and
            // System.exit(0);
            // do the same thing.
            // The system exits normally, when the last non-daemon thread exits.
            // Since an exception was caught here, the system exits unnormally.
            //
            java.lang.System.out.println("ERROR: Exit system unnormally. Undiscovered exception:\n");
            e.printStackTrace();
            java.lang.System.exit(1);
        }
    }

    //
    // Child management.
    //

    /**
     * Adds the item to become a child of this item.
     *
     * @param n the name
     * @param i the item
     * @exception NullPointerException if the name is null
     */
    public void set(String n, Item i) throws NullPointerException {

        super.set(n, i);

        if (n != null) {

            if (n.isEqualTo(Launcher.COMMUNICATION_PARTNER)) {

                setShutdownHook((ShutdownHook) i);
            }

        } else {

            throw new NullPointerException("Could not set item. The name is null.");
        }
    }

    /**
     * Removes the child item from this item.
     *
     * @param n the name
     * @exception NullPointerException if the name is null
     */
    public void remove(String n) throws NullPointerException {

        if (n != null) {

            if (n.isEqualTo(Launcher.COMMUNICATION_PARTNER)) {

                removeShutdownHook((ShutdownHook) get(n));
            }

        } else {

            throw new NullPointerException("Could not set item. The name is null.");
        }

        super.remove(n);
    }

    //
    // Default children.
    //

    /**
     * Returns the default screen.
     *
     * @return the default screen
     */
    public String getDefaultScreen() {

        return new String("cybop.core.system.block.Screen");
    }

    /**
     * Returns the default shutdown socket.
     *
     * @return the default shutdown socket
     */
    public String getDefaultShutdownSocket() {

        return new String("cybop.core.system.system.ShutdownSocket");
    }

    /**
     * Returns the default lifecycle action.
     *
     * @return the default lifecycle action
     */
    public String getDefaultLifecycleAction() {

        return Launcher.STARTUP_SYSTEM_ACTION;
    }

    /**
     * Returns the default shutdown flag.
     *
     * @return the default shutdown flag
     */
    public Boolean getDefaultShutdownFlag() {

        return new Boolean(Boolean.FALSE);
    }

    /**
     * Returns the default signal.
     *
     * @return the default signal
     */
    public String getDefaultSignal() {

        return new String("cybop.core.signal.Signal");
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
     * @exception NullPointerException if the arguments container is null
     * @exception NullPointerException if an argument is null
     */
    public String getArgument(String key, String def) throws NullPointerException {

        String a = def;
        java.lang.String[] args = getArguments();

        if (args != null) {

            String s = null;

            for (int i = 0; i < args.length; i++) {

                s = new String(args[i]);
                
                if (s != null) {

                    if (s.isEqualTo(key)) {

                        a = new String(args[i + 1]);
                    }

                } else {

                    throw new NullPointerException("Could not get argument. An argument is null.");
                }
            }

        } else {

            throw new NullPointerException("Could not get argument. The arguments container is null.");
        }
        
        return a;
    }

    //
    // Shutdown hook.
    //

    /**
     * Creates the shutdown hook.
     *
     * @return the shutdown hook
     * @exception NullPointerException if the shutdown hook is null
     */
    public ShutdownHook createShutdownHook() throws Exception, NullPointerException {

        ShutdownHook sh = new ShutdownHook();

        if (sh != null) {
            
            sh.initialize();

            // This is an exceptional setting.
            // Normally, child items should not know about the parent item.
            // However, this shutdown hook as thread running in parallel to this launcher,
            // needs to know this launcher so that it can eventually send a shutdown signal. 
            sh.setSystem(this);

        } else {
    
            throw new NullPointerException("Could not create shutdown hook. The shutdown hook is null.");
        }

        return sh;
    }

    /*
     * Destroys the shutdown hook.
     *
     * @param sh the shutdown hook
     * @exception NullPointerException if the shutdown hook is null
     */
    public void destroyShutdownHook(ShutdownHook sh) throws Exception, NullPointerException {

        if (sh != null) {

            sh.setSystem(null);
            sh.finalizz();

        } else {
    
            throw new NullPointerException("Could not destroy shutdown hook. The shutdown hook is null.");
        }
    }

    /**
     * Sets the shutdown hook.
     *
     * @param sh the shutdown hook
     * @exception NullPointerException if the java runtime is null
     * @exception NullPointerException if the shutdown hook is null
     */
    private void setShutdownHook(ShutdownHook sh) throws NullPointerException {

        java.lang.Runtime r = java.lang.Runtime.getRuntime();

        if (r != null) {

            if (sh != null) {

                r.addShutdownHook((java.lang.Thread) sh.getJavaObject());

            } else {
    
                throw new NullPointerException("Could not set shutdown hook. The shutdown hook is null.");
            }
    
        } else {
    
            throw new NullPointerException("Could not set shutdown hook. The java runtime is null.");
        }
    }

    /**
     * Removes the shutdown hook.
     *
     * @param sh the shutdown hook
     * @exception NullPointerException if the java runtime is null
     * @exception NullPointerException if the shutdown hook is null
     */
    private void removeShutdownHook(ShutdownHook sh) throws NullPointerException {

        java.lang.Runtime r = java.lang.Runtime.getRuntime();
        
        if (r != null) {
    
            if (sh != null) {

                r.removeShutdownHook((java.lang.Thread) sh.getJavaObject());

            } else {
    
                throw new NullPointerException("Could not remove shutdown hook. The shutdown hook is null.");
            }

        } else {
    
            throw new NullPointerException("Could not remove shutdown hook. The java runtime is null.");
        }
    }

    //
    // Initialization.
    //

    /**
     * Initializes this launcher.
     */
    public void initialize() throws Exception {

        super.initialize();

        if (getArgument(Launcher.HELP_ARGUMENT, null) != null) {

            set(Launcher.LIFECYCLE_ACTION, Launcher.SHOW_HELP_ACTION);

        } else {

            set(Launcher.SYSTEM_CLASS_NAME, getArgument(Launcher.SYSTEM_CLASS_NAME_ARGUMENT, getDefaultSystemClassName()));
            set(Launcher.SYSTEM_CONFIGURATION_LOCATION, getArgument(Launcher.SYSTEM_CONFIGURATION_LOCATION_ARGUMENT, getDefaultSystemConfigurationLocation()));
            set(Launcher.SCREEN, createComponent(getDefaultScreen()));
            set(Launcher.LIFECYCLE_ACTION, getArgument(Launcher.LIFECYCLE_ACTION_ARGUMENT, getDefaultLifecycleAction()));
            set(Launcher.SHUTDOWN_HOOK, createShutdownHook());
            set(Launcher.SHUTDOWN_FLAG, getDefaultShutdownFlag());
        }
    }

    /**
     * Finalizes this launcher.
     */
    public void finalizz() throws Exception {

        remove(Launcher.SHUTDOWN_FLAG);

        // Remove shutdown hook first to avoid another shutdown call
        // from the java virtual machine to this system.
        ShutdownHook shutdownHook = (ShutdownHook) get(Launcher.SHUTDOWN_HOOK);
        remove(Launcher.SHUTDOWN_HOOK);
        destroyComponent(shutdownHook);

        String lifecycleAction = (String) get(Launcher.LIFECYCLE_ACTION);
        remove(Launcher.LIFECYCLE_ACTION);
        destroyItem(lifecycleAction);

        Screen screen = (Screen) get(Launcher.SCREEN);
        remove(Launcher.SCREEN);
        destroyItem(screen);

        String systemConfigurationLocation = (String) get(Launcher.SYSTEM_CONFIGURATION_LOCATION);
        remove(Launcher.SYSTEM_CONFIGURATION_LOCATION);
        destroyItem(systemConfigurationLocation);

        String systemClassName = (String) get(Launcher.SYSTEM_CLASS_NAME);
        remove(Launcher.SYSTEM_CLASS_NAME);
        destroyItem(systemClassName);

        super.finalizz();
    }

    //
    // Launching.
    //

    /**
     * Launches the system.
     */
    public void launch() throws Exception {

        Signal s = (Signal) createItem(getDefaultSignal());

        receive(s, Signal.TUI_LANGUAGE, get(Launcher.USER), (String) get(Launcher.LIFECYCLE_ACTION));
        handle(s, new Boolean(Boolean.FALSE));
        send(s);
        destroyItem(s);
    }

    //
    // Signal processing.
    //

    /**
     * Waits for signals.<br><br>
     *
     * Once the CYBOP framework contains an <code>OperatingSystem</code> class,
     * the <code>await</code> method needs to be moved there, since it is the
     * task of an operating system to run an endless loop waiting for interrupts.<br><br>
     *
     * Remark: The method's name cannot be <code>wait</code> since that name
     * is already used by java's <code>Object</code> class.
     */
    public void await() throws Exception {

        Signal s = (Signal) createItem(getDefaultSignal());
        Boolean b = null;

        while (true) {

            // Check shutdown flag.
            b = (Boolean) get(Launcher.SHUTDOWN_FLAG);

            if (b != null) {

                if (b.isEqualTo(Boolean.TRUE)) {

                    break;
                }

            } else {

                throw new NullPointerException("Could not wait for signals. The shutdown flag is null.");
            }

            // Check for changed flags on computer (currently done by operating system),
            // e.g. to receive a keyboard or mouse event and then create a CYBOP signal of it.
            // After having handled the signal in this system, its answer will be sent -
            // again by changing flags on the computer (done by operating system),
            // e.g. a gui drawn onto the screen, a printout or a network message.
/*??
            receive(s);
            handle(s, new Boolean(Boolean.FALSE));
            send(s);
            reset(s);

/*??
            // Run garbage collector. Since java has no destructor methods,
            // all unreferenced objects are hanging in memory until the gc is run.
            // Because a signal is created in every cycle of the waiting loop,
            // it has to be garbage collected here. Otherwise, too many objects
            // would be hanging in memory.
            // This garbage collector run is also useful to destruct all objects
            // which were created during handling of the signal.
            java.lang.System.gc();
*/
        }

        destroyItem(s);

/*??
        String port = (String) get(System.SHUTDOWN_PORT);

        if (port != null) {

            java.net.ServerSocket serverSocket = new java.net.ServerSocket(port.getJavaObject(), 1, java.net.InetAddress.getByName("127.0.0.1"));

        } else {

            throw new NullPointerException("Could not wait for shutdown signal. The shutdown port is null.");
        }

        java.net.Socket socket = null;
        java.io.InputStream stream = null;
        String signal = System.SHUTDOWN_SIGNAL;
        java.lang.StringBuffer buff = null;
        int ch = 0;

        while (true) {

            // Listens for a socket connection to be made to the server socket and accepts it.
            socket = serverSocket.accept();

            if (socket != null) {

                // Set timeout to 10 s.
                socket.setSoTimeout(10 * 1000);
                stream = socket.getInputStream();

                if (stream != null) {

                    if (signal != null) {
    
                        // Cut off to avoid DoS attack.
                        int expected = 1024;
                        // Read a set of characters from the socket.
                        buff = new java.lang.StringBuffer();

                        while (expected < shutdown.length()) {
    
                            if (random == null) {
        
                                random = new Random(System.currentTimeMillis());
                            }
        
                            expected += (random.nextInt() % 1024);
                        }

                        while (expected > 0) {
        
                            ch = stream.read();
        
                            // Control character or EOF terminates loop.
                            if (ch < 32) {
        
                                break;
                            }
    
                            buff.append((char) ch);
                            expected--;
                        }

                        socket.close();

                        // Match against our command string
                        if (buff.toString().equals(shutdown)) {

                            break;
                        }

                    } else {
        
                        throw new NullPointerException("Could not shutdown system using socket. The shutdown signal is null.");
                    }

                } else {

                    throw new NullPointerException("Could not wait for shutdown signal. The output stream is null.");
                }

            } else {

                throw new NullPointerException("Could not handle client socket connection made to the server socket. The client socket is null.");
            }
        }

        serverSocket.close();
*/
    }

    /**
     * Receives the signal.<br><br>
     *
     * This method analyzes the state of the system environment. If a change
     * is detected on an input device such as the keyboard or mouse, the
     * corresponding information will be added to the signal.
     *
     * Device drivers are needed in order to properly identify state changes
     * on any input devices.
     *
     * @param s the signal
     */
    public void receive(Signal s) {

        // As long as this CYBOP framework has no OperatingSystem class yet,
        // other methods are used to catch signals, e.g. the actionPerformed method
        // which informs about events of the java AWT/Swing framework.
    }

    /**
     * Receives the signal.<br><br>
     *
     * @param s the signal
     * @param l the language
     * @param subj the subject
     * @param p the predicate
     * @exception NullPointerException if the signal is null
     */
    public void receive(Signal s, String l, Item subj, Item p) throws NullPointerException {

        if (s != null) {

            s.set(Signal.LANGUAGE, l);
            s.set(Signal.SUBJECT, subj);
            s.set(Signal.PREDICATE, p);

        } else {

            throw new NullPointerException("Could not receive signal. The signal is null.");
        }
    }

    /**
     * Sends the signal.<br><br>
     *
     * This method reads the parameters of the given signal and translates them
     * into state changes in the system environment so that the corresponding
     * information will be sent as electrical signal to an output device, such
     * as the screen, printer or over network card to another computer.<br><br>
     *
     * Device drivers are needed in order to properly generate state changes.
     * on any output devices.
     *
     * @param s the signal
     * @exception NullPointerException if the signal is null
     * @exception NullPointerException if the language is null
     * @exception NullPointerException if the screen is null
     */
    public void send(Signal s) throws NullPointerException {

        String l = null;

        if (s != null) {

            l = (String) s.get(Signal.LANGUAGE);
            
            if (l != null) {

                if (l.isEqualTo(Signal.GUI_LANGUAGE)) {

                    Screen scr = (Screen) get(Launcher.SCREEN);

                    if (scr != null) {

                        scr.show((UserInterface) s.get(Signal.OBJECT));

                    } else {

                        throw new NullPointerException("Could not send signal. The screen is null.");
                    }
                }

            } else {

                throw new NullPointerException("Could not send signal. The language is null.");
            }

        } else {

            throw new NullPointerException("Could not send signal. The signal is null.");
        }
    }

    /**
     * Handles the signal.
     *
     * @param s the signal
     * @param d the dummy flag indicating whether this system is a:
     * <ul>
     *     <li>false: normal system (client or server) that handles messages</li>
     *     <li>true: local server dummy which represents a remote system and
     *     needs to forward messages to the actual server</li>
     * </ul>
     * @exception NullPointerException if the signal is null
     * @exception NullPointerException if the action is null
     */
    public void handle(Signal s, Boolean b) throws Exception, NullPointerException {

        super.handle(s, b);

        if (s != null) {

            String a = (String) s.get(Signal.PREDICATE);

            if (a != null) {

                if (a.isEqualTo(Launcher.STARTUP_SYSTEM_ACTION)) {

                    log(Launcher.INFO_LOG_LEVEL, "Startup system.");
                    startupSystem((String) get(Launcher.SYSTEM_CLASS_NAME), (String) get(Launcher.SYSTEM_CONFIGURATION_LOCATION));

                } else if (a.isEqualTo(Launcher.SHUTDOWN_SYSTEM_ACTION)) {

                    log(Launcher.INFO_LOG_LEVEL, "Shutdown system.");
                    shutdownSystem();

                } else if (a.isEqualTo(Launcher.SHUTDOWN_SYSTEM_ACROSS_SOCKET_ACTION)) {
            
                    log(Launcher.INFO_LOG_LEVEL, "Shutdown system across socket.");
                    shutdownSystemAcrossSocket();
    
                } else if (a.isEqualTo(Launcher.START_SYSTEM_ACTION)) {
            
                    log(Launcher.INFO_LOG_LEVEL, "Start system.");
                    startSystem();
    
                } else if (a.isEqualTo(Launcher.STOP_SYSTEM_ACTION)) {
        
                    log(Launcher.INFO_LOG_LEVEL, "Stop system.");
                    stopSystem();
    
                } else if (a.isEqualTo(Launcher.RESTART_SYSTEM_ACTION)) {

                    log(Launcher.INFO_LOG_LEVEL, "Restart system.");
                    restartSystem();

                } else if (a.isEqualTo(Launcher.SHOW_HELP_ACTION)) {
    
                    showHelp();
                }

            } else {

                throw new NullPointerException("Could not handle signal. The action is null.");
            }

        } else {

            throw new NullPointerException("Could not handle signal. The signal is null.");
        }
    }

    /**
     * Starts up the system.
     *
     * @param s the system class name
     * @param c the configuration location
     * @exception NullPointerException if the system is null
     */
    public void startupSystem(String s, String c) throws Exception {

        setSystem(Launcher.SYSTEM, createComponent(s/*??, c*/));

        Signal sig = (Signal) createItem(getDefaultSignal());

        receive(sig, Signal.TUI_LANGUAGE, get(Launcher.USER), Controller.SHOW_SYSTEM_USER_INTERFACE_ACTION);
        handle(sig, new Boolean(Boolean.FALSE));
        send(sig);
        destroyItem(sig);
    }

    /**
     * Shuts down the system.
     */
    public void shutdownSystem() throws Exception {

        //?? The system where the signal is coming from needs to be found
        //?? (e.g. check on which gui the mouse click occured).
        //?? This system reference will be sent as subject of the signal.
        String ext = new String(Launcher.SYSTEM.getJavaObject() + "_" + java.lang.String.valueOf("0"));
        System system = (System) get(ext);

        // The system can be null if another launcher was used to create it.        
        if (system != null) {

            // Remove and destroy the system the signal is coming from.
            removeSystem(ext);
            destroyComponent(system);

            // If this launcher system has sent the exit signal, then set the
            // shutdown flag causing the waiting loop to break and by this to
            // finally exit the whole java virtual machine.
            set(Launcher.SHUTDOWN_FLAG, new Boolean(Boolean.TRUE));

        } else {

            // The system is null which means that it was created by another launcher
            // and now has to be shut down using a socket connection.
            // (This launcher has probably been started in an extra process,
            // by another shell/batch script, e.g. a special shutdown script.)
//??            handle(new String(""), Launcher.SHUTDOWN_SYSTEM_ACROSS_SOCKET_ACTION, new Boolean(Boolean.TRUE));
            shutdownSystemAcrossSocket();
        }
    }

    /**
     * Shuts down the system across a socket connection.
     *
     * @exception NullPointerException if the shutdown socket is null
     */
    public void shutdownSystemAcrossSocket() throws Exception, NullPointerException {

        Signal s = (Signal) createItem(getDefaultSignal());
        ShutdownSocket socket = (ShutdownSocket) createComponent(getDefaultShutdownSocket());

        receive(s, Signal.GUI_LANGUAGE, get(Launcher.USER), (String) get(Launcher.SHUTDOWN_SYSTEM_ACTION));

        if (socket != null) {

            socket.handle(s, new Boolean(Boolean.TRUE));

        } else {

            throw new NullPointerException("Could not shutdown system using socket. The shutdown socket is null.");
        }

        // These methods will probably not be reached anymore, as the previous
        // command already causes the whole java virtual machine to exit.
        // But, to be proper, the methods were added here anyway.
        send(s);
        destroyItem(s);
        destroyComponent(socket);
    }

    /**
     * Starts the system.
     */
    public void startSystem() {
    }

    /**
     * Stops the system.
     */
    public void stopSystem() {
    }

    /**
     * Restarts the system.
     */
    public void restartSystem() {
    }

    /**
     * Displays the help information.
     */
    private void showHelp() {

        java.lang.System.out.println("Usage:\n"
            + "java -classpath $CLASSPATH cybop.core.system.family.Launcher"
            + " -system {location}"
            + " [-configuration {location}]"
            + " [-action {startup | shutdown | start | stop | restart}]"
            + " [-help]");
    }

    //
    // Splash window.
    //

    /**
     * Shows the component splash window.
     *
     * @param c the component splash window
     * @exception NullPointerException if the component is null
     */
/*??
    private void showComponentSplashWindow(BasicApplication c) throws Exception, NullPointerException {

        if (c != null) {

//??            if (c instanceof Splashable) {

            log(Level.INFO, "Show the component splash window.");
//??            c.setSplashWindowController(c.getDefaultSplashWindowController());
//??            c.showSplashWindowController(c.getSplashWindowController());
//??            }

        } else {

            throw new NullPointerException("Could not show component splash window. The component is null.");
        }
    }

    /**
     * Disposes the component splash window.
     *
     * @param c the component splash window
     * @exception NullPointerException if the component is null
     */
/*??
    private void hideComponentSplashWindow(BasicApplication c) throws Exception, NullPointerException {

        if (c != null) {

//??            if (c instanceof Splashable) {

            log(Level.INFO, "Hide the component splash window.");
//??            c.hideSplashWindowController(c.getSplashWindowController());
//??            c.destroySplashWindowController(c.getSplashWindowController());
//??            c.setSplashWindowController(null);
//??            }

        } else {

            throw new NullPointerException("Could not hide component splash window. The component is null.");
        }
    }
*/

    /**
     * Resets the signal.<br><br>
     *
     * All children of the signal will be removed.
     *
     * @param s the signal
     * @exception NullPointerException if the signal is null
     */
    public void reset(Signal s) throws NullPointerException {

        if (s != null) {
            
            s.reset();

        } else {

            throw new NullPointerException("Could not reset signal. The signal is null.");
        }
    }

    //
    // Temporary methods to:
    // - catch ALL events of the java AWT/Swing framework
    // - create, handle and destroy the signal
    //
    // These methods are to be removed as soon as this framework
    // has an OperatingSystem class with input device drivers etc.
    //

    /**
     * Catches action events.
     *
     * @param evt the event
     */
    public void actionPerformed(java.awt.event.ActionEvent evt) {

        try {

            if (evt != null) {

                Signal s = (Signal) createItem(getDefaultSignal());

                receive(s, Signal.GUI_LANGUAGE, get(Launcher.USER), new String(evt.getActionCommand()));
                handle(s, new Boolean(Boolean.FALSE));
                send(s);
                destroyItem(s);

            } else {

                throw new NullPointerException("Could not catch action event. The action event is null.");
            }

        } catch (Exception e) {

            java.lang.System.out.println("ERROR: Could not catch action event. An exception occured:\n" + e);
        }
    }

    /**
     * Evaluates the event if some attribute has changed
     *
     * @param evt the event
     */
    public void changedUpdate(javax.swing.event.DocumentEvent evt) {
    }

    /**
     * Invoked when a component gains the keyboard focus.
     *
     * @param evt the event
     */
    public void focusGained(java.awt.event.FocusEvent evt) {
    }

    /**
     * Invoked when a component loses the keyboard focus.
     *
     * @param evt the event
     */
    public void focusLost(java.awt.event.FocusEvent evt) {
    }

    /**
     * Evaluates the event if something was inserted into the text area
     *
     * @param evt the event
     */
    public void insertUpdate(javax.swing.event.DocumentEvent evt) {
    }

    /**
     * Invoked when an internal frame is activated.
     *
     * @param evt the internal frame event
     */
    public void internalFrameActivated(javax.swing.event.InternalFrameEvent evt) {
    }

    /**
     * Invoked when an internal frame has been closed.
     *
     * @param evt the internal frame event
     */
    public void internalFrameClosed(javax.swing.event.InternalFrameEvent evt) {
    }

    /**
     * Invoked when an internal frame is in the process of being closed.
     * The close operation can be overridden at this point.
     *
     * @param evt the internal frame event
     */
    public void internalFrameClosing(javax.swing.event.InternalFrameEvent evt) {

//??        getView().issueControl(getView().getCloseControl());
    }

    /**
     * Invoked when an internal frame is de-activated.
     *
     * @param evt the internal frame event
     */
    public void internalFrameDeactivated(javax.swing.event.InternalFrameEvent evt) {
    }

    /**
     * Invoked when an internal frame is de-iconified.
     *
     * @param evt the internal frame event
     */
    public void internalFrameDeiconified(javax.swing.event.InternalFrameEvent evt) {
    }

    /**
     * Invoked when an internal frame is iconified.
     *
     * @param evt the internal frame event
     */
    public void internalFrameIconified(javax.swing.event.InternalFrameEvent evt) {
    }

    /**
     * Invoked when an internal frame has been opened.
     *
     * @param evt the internal frame event
     */
    public void internalFrameOpened(javax.swing.event.InternalFrameEvent evt) {
    }

    /**
     * Handles all item events of the whole application.
     *
     * @param evt the event
     */                
    public void itemStateChanged(java.awt.event.ItemEvent evt) {
    }

    /**
     * Handles all keyPressed events of the whole application.
     *
     * @param evt the event
     */                
    public void keyPressed(java.awt.event.KeyEvent evt) {        
    }

    /**
     * Handles all keyTyped events of the whole application.
     *
     * @param evt the event
     */                
    public void keyTyped(java.awt.event.KeyEvent evt) {        
    }

   /**
    * Handles all keyReleased events of the whole application.
     *
     * @param evt the event
    */            
    public void keyReleased(java.awt.event.KeyEvent evt) {
    }

    /**
     * Handles all mouseClicked events of the whole application.
     *
     * @param evt the event
     */                
    public void mouseClicked(java.awt.event.MouseEvent evt) {
    }

    /**
     * Not implemented.
     *
     * @param evt the event
     */
    public void mouseDragged(java.awt.event.MouseEvent evt) { 
    }

    /**
     * Not implemented.
     *
     * @param evt the event
     */
    public void mouseEntered(java.awt.event.MouseEvent evt) {
    }
   
    /**
     * Not implemented.
     *
     * @param evt the event
     */
    public void mouseExited(java.awt.event.MouseEvent evt) {
    }

    /**
     * Mouse moves are registered. If the mouse moved over a polygon area, the polygon is
     * drawn. The polygon info panel is also updated. If one polygon is already painted, and
     * the mouse is still on it, it will no be painted again (see isPainted()). If mouse moves
     * out of a polygon the whole panel is repainted and also overidden the painted polygons
     * Of course in this case the info panel is also updated.
     *
     * @param evt the event
     */
    public void mouseMoved(java.awt.event.MouseEvent evt) {
    }

    /**
     * Not implemented.
     *
     * @param evt the event
     */
    public void mousePressed(java.awt.event.MouseEvent evt) { 
    }

    /**
     * Not implemented.
     *
     * @param evt the event
     */
    public void mouseReleased(java.awt.event.MouseEvent evt) { 
    }

    /**
     * Evaluates the event if something was removed from the text area
     *
     * @param evt the event
     */
    public void removeUpdate(javax.swing.event.DocumentEvent evt) {
    }

    /**
     * Here are all valueChanged events of the whole application handled. These 
     * are events from tables, or lists.
     *
     * @param evt the event
     */                
    public void valueChanged(javax.swing.event.ListSelectionEvent evt) {
    }

    /**
     * Listens and reacts to tree selection events.
     *
     * @param evt the event
     */
    public void valueChanged(javax.swing.event.TreeSelectionEvent evt) {

/*??
        // Determine application tree view as the event's source.
        ResTree tv = (ResTree) evt.getSource();

        if (tv != null) {

            // Determine selected application tree node.
            ApplicationTreeNode n = (ApplicationTreeNode) tv.getLastSelectedPathComponent();

            if (n != null) {

                if (n.isLeaf()) {

                    if (n.isExternal() == false) {

                        try {

                            // Create the application corresponding to the clicked tree node.
                            createApplication(n.getLocation(), n.getArguments(), n.getWorkPath());

                        } catch (Exception e) {

//??                            log(Level.SEVERE, "Error while creating application.", e);
                            java.lang.System.out.println("Error while creating application." + e);
                        }

                    } else {

                        try {

                            // Create the external application corresponding to the clicked tree node.
                            createExternalApplication(n.getLocation()/*??getCommand()*//*??, n.getArguments(), n.getWorkPath());

                        } catch (Exception e) {

//??                            log(Level.SEVERE, "Error while creating external application.", e);
                            java.lang.System.out.println("Error while creating external application." + e);
                        }
                    }
                }
            }
        }
*/
    }

    /**
     * Invoked when a window is activated.
     *
     * @param evt the window event
     */
    public void windowActivated(java.awt.event.WindowEvent evt) {
    }

    /**
     * Invoked when a window has been closed.
     *
     * @param evt the window event
     */
    public void windowClosed(java.awt.event.WindowEvent evt) {
    }

    /**
     * Invoked when a window is in the process of being closed.
     * The close operation can be overridden at this point.
     *
     * @param evt the window event
     * @exception NullPointerException if the view is null
     */
    public void windowClosing(java.awt.event.WindowEvent evt) throws NullPointerException {

/*??
        SwingView v = getView();

        if (v != null) {

//??            v.issueControl(v.getCloseControl());

        } else {

            throw new NullPointerException("Could not issue control. The view is null.");
        }
*/
    }

    /**
     * Invoked when a window is de-activated.
     *
     * @param evt the window event
     */
    public void windowDeactivated(java.awt.event.WindowEvent evt) {
    }

    /**
     * Invoked when a window is de-iconified.
     *
     * @param evt the window event
     */
    public void windowDeiconified(java.awt.event.WindowEvent evt) {
    }

    /**
     * Invoked when the Window is set to be the focused Window, which means
     * that the Window, or one of its subcomponents, will receive keyboard
     * events.
     *
     * @param evt the window event
     */
    public void windowGainedFocus(java.awt.event.WindowEvent evt) {
    }

    /**
     * Invoked when a window is iconified.
     *
     * @param evt the window event
     */
    public void windowIconified(java.awt.event.WindowEvent evt) {
    }

    /**
     * Invoked when the Window is no longer the focused Window, which means
     * that keyboard events will no longer be delivered to the Window or any of
     * its subcomponents.
     *
     * @param evt the window event
     */
    public void windowLostFocus(java.awt.event.WindowEvent evt) {
    }

    /**
     * Invoked when a window has been opened.
     *
     * @param evt the window event
     */
    public void windowOpened(java.awt.event.WindowEvent evt) {
    }

    /**
     * Invoked when a window state is changed.
     *
     * @param evt the window event
     */
    public void windowStateChanged(java.awt.event.WindowEvent evt) {
    }
}

