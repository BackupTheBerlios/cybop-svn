/*
 * $RCSfile: Add.java,v $
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

/**
 * This is the add action.<br><br>
 *
 * It represents a controller component and corresponds to a human nerve cell.
 *
 * @version $Revision: 1.4 $ $Date: 2003-07-15 09:44:19 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class Add extends Item {

    //
    // Actions.
    //

    /** The show system display action. */
    public static final String SHOW_SYSTEM_DISPLAY_ACTION = new String("show_system_display_action");

    /** The hide system display action. */
    public static final String HIDE_SYSTEM_DISPLAY_ACTION = new String("hide_system_display_action");

    /** The show system information display action. */
    public static final String SHOW_SYSTEM_INFORMATION_DISPLAY_ACTION = new String("show_system_information_display_action");

    /** The hide system information display action. */
    public static final String HIDE_SYSTEM_INFORMATION_DISPLAY_ACTION = new String("hide_system_information_display_action");

    /** The focus gained action. */
    public static final String FOCUS_GAINED_ACTION = new String("focus_gained_action");

    /** The focus lost action. */
    public static final String FOCUS_LOST_ACTION = new String("focus_lost_action");

    /** The mouse pressed action. */
    public static final String MOUSE_PRESSED_ACTION = new String("mouse_pressed_action");

    /** The mouse released action. */
    public static final String MOUSE_RELEASED_ACTION = new String("mouse_released_action");

    /** The mouse clicked action. */
    public static final String MOUSE_CLICKED_ACTION = new String("mouse_clicked_action");

    /** The mouse entered action. */
    public static final String MOUSE_ENTERED_ACTION = new String("mouse_entered_action");

    /** The mouse exited action. */
    public static final String MOUSE_EXITED_ACTION = new String("mouse_exited_action");

    /** The mouse dragged action. */
    public static final String MOUSE_DRAGGED_ACTION = new String("mouse_dragged_action");

    /** The mouse moved action. */
    public static final String MOUSE_MOVED_ACTION = new String("mouse_moved_action");

    /** The mouse wheel action. */
    public static final String MOUSE_WHEEL_ACTION = new String("mouse_wheel_action");

    /** The key typed action. */
    public static final String KEY_TYPED_ACTION = new String("key_typed_action");

    /** The key released action. */
    public static final String KEY_RELEASED_ACTION = new String("key_released_action");

    /** The key pressed action. */
    public static final String KEY_PRESSED_ACTION = new String("key_pressed_action");

    /** The component resized action. */
    public static final String COMPONENT_RESIZED_ACTION = new String("component_resized_action");

    /** The component moved action. */
    public static final String COMPONENT_MOVED_ACTION = new String("component_moved_action");

    /** The component shown action. */
    public static final String COMPONENT_SHOWN_ACTION = new String("component_shown_action");

    /** The component hidden action. */
    public static final String COMPONENT_HIDDEN_ACTION = new String("component_hidden_action");

    /** The input method text changed action. */
    public static final String INPUT_METHOD_TEXT_CHANGED_ACTION = new String("input_method_text_changed_action");

    /** The caret position changed action. */
    public static final String CARET_POSITION_CHANGED_ACTION = new String("caret_position_changed_action");

    /** The hierarchy changed action. */
    public static final String HIERARCHY_CHANGED_ACTION = new String("hierarchy_changed_action");

    /** The ancestor resized action. */
    public static final String ANCESTOR_RESIZED_ACTION = new String("ancestor_resized_action");

    /** The ancestor moved action. */
    public static final String ANCESTOR_MOVED_ACTION = new String("ancestor_moved_action");

//?? ------------------------------

    /** The create system signal id. */
    public static final String CREATE_SYSTEM_SIGNAL_ID = new String("create_system");

    /** The destroy system signal id. */
    public static final String DESTROY_SYSTEM_SIGNAL_ID = new String("destroy_system");

    /** The cut signal id. */
    public static final String CUT_SIGNAL_ID = new String("cut");

    /** The copy signal id. */
    public static final String COPY_SIGNAL_ID = new String("copy");

    /** The paste signal id. */
    public static final String PASTE_SIGNAL_ID = new String("paste");

    /** The show tool bar signal id. */
    public static final String SHOW_TOOL_BAR_SIGNAL_ID = new String("show_tool_bar");

    /** The show status bar signal id. */
    public static final String SHOW_STATUS_BAR_SIGNAL_ID = new String("show_status_bar");

    /** The configure menu bar signal id. */
    public static final String CONFIGURE_MENU_BAR_SIGNAL_ID = new String("configure_menu_bar");

    /** The configure tool bar signal id. */
    public static final String CONFIGURE_TOOL_BAR_SIGNAL_ID = new String("configure_tool_bar");

    /** The configure status bar signal id. */
    public static final String CONFIGURE_STATUS_BAR_SIGNAL_ID = new String("configure_status_bar");

    /** The configure key bindings signal id. */
    public static final String CONFIGURE_KEY_BINDINGS_SIGNAL_ID = new String("configure_key_bindings");

    /** The show help contents signal id. */
    public static final String SHOW_HELP_CONTENTS_SIGNAL_ID = new String("show_help_contents");

    /** The report bug signal id. */
    public static final String REPORT_BUG_SIGNAL_ID = new String("report_bug");

    /** The link to website signal id. */
    public static final String LINK_TO_WEBSITE_SIGNAL_ID = new String("link_to_website");

    //
    // Portal system actions.
    //

    /** The show systems tree signal id. */
    public static final String SHOW_SYSTEMS_TREE_SIGNAL_ID = new String("show_systems_tree");

    /** The configure systems tree signal id. */
    public static final String CONFIGURE_SYSTEMS_TREE_SIGNAL_ID = new String("configure_systems_tree");

    /** The configure res medicinae signal id. */
    public static final String CONFIGURE_RES_MEDICINAE_SIGNAL_ID = new String("configure_res_medicinae");

    /** The iconify all signal id. */
    public static final String ICONIFY_ALL_SIGNAL_ID = new String("iconify_all");

    /** The close signal id. */
    public static final String CLOSE_SIGNAL_ID = new String("close");

    /** The close all signal id. */
    public static final String CLOSE_ALL_SIGNAL_ID = new String("close_all");

    /** The cascade signal id. */
    public static final String CASCADE_SIGNAL_ID = new String("cascade");

    /** The tile vertically signal id. */
    public static final String TILE_VERTICALLY_SIGNAL_ID = new String("tile_vertically");

    /** The tile horizontally signal id. */
    public static final String TILE_HORIZONTALLY_SIGNAL_ID = new String("tile_horizontally");

    /** The set frame display signal id. */
    public static final String SET_FRAME_DISPLAY_SIGNAL_ID = new String("set_frame_display");

    /** The set internal frame display signal id. */
    public static final String SET_INTERNAL_FRAME_DISPLAY_SIGNAL_ID = new String("set_internal_frame_display");

    /** The set tab page display signal id. */
    public static final String SET_TAB_PAGE_DISPLAY_SIGNAL_ID = new String("set_tab_page_display");

    //
    // Launcher actions.
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

                java.lang.System.out.println("INFO: Abstract child to get an abstraction.");
                l.abstracc();

                // Set meta attributes for child.
                // DO NOT use the normal method setChild(name, item);
                // This would lead to an endless loop since for example
                // setChild(Item.NAME, n); would cause to be called repeatedly!
                java.lang.System.out.println("INFO: Name child to get a category.");
                l.name(new String("launcher"));

                java.lang.System.out.println("INFO: Inherit child to get an inheritance.");
                l.inherit();

                java.lang.System.out.println("INFO: Categorize child to get a hierarchy.");
                l.categorize();

                java.lang.System.out.println("INFO: Position child to get a structure.");
                l.position();

                java.lang.System.out.println("INFO: Constrain child to get a definition.");
                l.constrain();

                java.lang.System.out.println("INFO: Behave child to get a behaviour.");
                l.behave();

                java.lang.System.out.println("INFO: Connect child to signal memory.");
                l.setChild(Launcher.SIGNAL_MEMORY, l.createChild(l.getCategory(Launcher.SIGNAL_MEMORY)));

                java.lang.System.out.println("INFO: Initialize child to get an item.");
                l.initialize();

                l.launch();

                // The system is now started up and complete so that a loop
                // can be entered, waiting for signals (events).
                l.await();
                // The loop above is left as soon as the shutdown flag is set
                // so that the system can be shut down now.

                java.lang.System.out.println("INFO: Finalize child.");
                l.finalizz();
    
                java.lang.System.out.println("INFO: Disconnect child from signal memory.");
                Item signalMemory = l.getChild(Launcher.SIGNAL_MEMORY);
                l.removeChild(Launcher.SIGNAL_MEMORY);
                l.destroyChild(signalMemory);

                java.lang.System.out.println("INFO: Unbehave child.");
                l.unbehave();
    
                java.lang.System.out.println("INFO: Unconstrain child.");
                l.unconstrain();
    
                java.lang.System.out.println("INFO: Deposition child.");
                l.deposition();
    
                java.lang.System.out.println("INFO: Decategorize child.");
                l.decategorize();
    
                java.lang.System.out.println("INFO: Uninherit child.");
                l.uninherit();
    
                java.lang.System.out.println("INFO: Unname child.");
                l.unname();

                java.lang.System.out.println("INFO: Deabstract child.");
                l.deabstract();

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

                throw new Exception("Could not launch system. The launcher is null.");
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
    // Launching.
    //

    /**
     * Launches the system.
     *
     * @exception Exception if the signal is null
     */
    public void launch() throws Exception {

        Signal s = (Signal) createChild(getCategory(Launcher.SIGNAL));

        if (s != null) {

            s.setChild(Signal.PRIORITY, Signal.NORMAL_PRIORITY);
            s.setChild(Signal.LANGUAGE, Signal.NEURO_LANGUAGE);
            s.setChild(Signal.SUBJECT, Launcher.SELF);
            s.setChild(Signal.PREDICATE, getChild(Launcher.LIFECYCLE_ACTION));

        } else {

            throw new Exception("Could not launch. The signal is null.");
        }

        storeSignal(s);
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

        Signal s = (Signal) createChild(getCategory(Launcher.SIGNAL));
        //?? Temporary for handling signals which stem from java event queue.
        Signal queued = null;
        Boolean b = null;

        while (true) {

            // Check shutdown flag.
            b = (Boolean) getChild(Launcher.SHUTDOWN_FLAG);

            if (b != null) {

                if (b.isEqualTo(Boolean.TRUE)) {

                    break;
                }

            } else {

                throw new Exception("Could not wait for signals. The shutdown flag is null.");
            }

            queued = fetchSignal();

            if (queued != null) {

                //?? Temporary code block for handling of signals that came from the
                //?? java event queue and were stored in the signal memory.
                //?? These signals were created outside this method but must be
                //?? destroyed here!

                java.lang.System.out.println("DEBUG: Handle signal " + /*??queued.getName().getJavaObject() +*/ " with action: " + ((String) queued.getChild(Signal.PREDICATE)).getJavaObject());
                handle(queued, new Boolean(Boolean.FALSE));

                java.lang.System.out.println("DEBUG: Send signal " + /*??queued.getName().getJavaObject() +*/ " with action: " + ((String) queued.getChild(Signal.PREDICATE)).getJavaObject());
                send(queued);

                destroyChild(queued);

            } else {

/*??
                // Check for changed flags on computer (currently done by operating system),
                // e.g. to receive a keyboard or mouse event and then create a CYBOP signal of it.
                receive(s);
                // Handle the signal by sending it through the whole system.
                handle(s, new Boolean(Boolean.FALSE));
                // After having handled the signal in this system, its answer will be sent -
                // again by changing flags on the computer (done by operating system),
                // e.g. a gui drawn onto the screen, a printout or a network message.
                send(s);

                if (s != null) {
                    
                    s.resetChild();
        
                } else {
        
                    throw new Exception("Could not reset signal. The signal is null.");
                }
*/
            }
        }

        destroyChild(s);

/*??
        String port = (String) getChild(System.SHUTDOWN_PORT);

        if (port != null) {

            java.net.ServerSocket serverSocket = new java.net.ServerSocket(port.getJavaObject(), 1, java.net.InetAddress.getByName("127.0.0.1"));

        } else {

            throw new Exception("Could not wait for shutdown signal. The shutdown port is null.");
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
        
                        throw new Exception("Could not shutdown system using socket. The shutdown signal is null.");
                    }

                } else {

                    throw new Exception("Could not wait for shutdown signal. The output stream is null.");
                }

            } else {

                throw new Exception("Could not handle client socket connection made to the server socket. The client socket is null.");
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
        // java events are catched using the JavaEventCatcher class which
        // inherits from the java.awt.EventQueue class.
        // That's why another receive method has to be used for now,
        // to hand over parameters from java events to the new CYBOP signals.
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
     * @exception Exception if the signal is null
     * @exception Exception if the language is null
     * @exception Exception if the screen is null
     */
    public void send(Signal s) throws Exception {

        String l = null;

        if (s != null) {

            l = (String) s.getChild(Signal.LANGUAGE);
            
            if (l != null) {

                if (l.isEqualTo(Signal.GUI_LANGUAGE)) {

                    Screen scr = (Screen) getChild(Launcher.SCREEN);

                    if (scr != null) {

                        java.lang.System.out.println("DEBUG: Show on screen.");
                        scr.show((Display) s.getChild(Signal.OBJECT));

                    } else {

                        throw new Exception("Could not send signal. The screen is null.");
                    }
                }

            } else {

                throw new Exception("Could not send signal. The language is null.");
            }

        } else {

            throw new Exception("Could not send signal. The signal is null.");
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
     * @exception Exception if the signal is null
     * @exception Exception if the action is null
     */
    public void handle(Signal s, Boolean b) throws Exception {

        super.handle(s, b);

        if (s != null) {

            String a = (String) s.getChild(Signal.PREDICATE);

            if (a != null) {

                if (a.isEqualTo(Launcher.STARTUP_SYSTEM_ACTION)) {

                    java.lang.System.out.println("INFO: Startup system.");
                    startupSystem(getCategory(Launcher.SYSTEM));

                } else if (a.isEqualTo(Launcher.SHUTDOWN_SYSTEM_ACTION)) {

                    java.lang.System.out.println("INFO: Shutdown system.");
                    shutdownSystem();

                } else if (a.isEqualTo(Launcher.SHUTDOWN_SYSTEM_ACROSS_SOCKET_ACTION)) {
            
                    java.lang.System.out.println("INFO: Shutdown system across socket.");
                    shutdownSystemAcrossSocket();
    
                } else if (a.isEqualTo(Launcher.START_SYSTEM_ACTION)) {
            
                    java.lang.System.out.println("INFO: Start system.");
                    startSystem();
    
                } else if (a.isEqualTo(Launcher.STOP_SYSTEM_ACTION)) {
        
                    java.lang.System.out.println("INFO: Stop system.");
                    stopSystem();
    
                } else if (a.isEqualTo(Launcher.RESTART_SYSTEM_ACTION)) {

                    java.lang.System.out.println("INFO: Restart system.");
                    restartSystem();

                } else if (a.isEqualTo(Launcher.SHOW_HELP_ACTION)) {
    
                    showHelp();
                }

            } else {

                throw new Exception("Could not handle signal. The action is null.");
            }

        } else {

            throw new Exception("Could not handle signal. The signal is null.");
        }
    }

    //
    // Controlling.
    //

    /**
     * Controls the signal.
     *
     * @param s the signal
     * @exception Exception if the signal is null
     */
    public void control(Signal s) throws Exception {

        if (s != null) {

            String a = (String) s.getChild(Signal.PREDICATE);

            if (a != null) {

                if (a.isEqualTo(Controller.SHOW_SYSTEM_DISPLAY_ACTION)) {

                    showSystemDisplay(s);
    
                } else if (a.isEqualTo(Controller.HIDE_SYSTEM_DISPLAY_ACTION)) {
    
                    hideSystemDisplay(s);

                } else if (a.isEqualTo(Controller.SHOW_SYSTEM_INFORMATION_DISPLAY_ACTION)) {

                    showSystemInformationDisplay(s);
    
                } else if (a.isEqualTo(Controller.HIDE_SYSTEM_INFORMATION_DISPLAY_ACTION)) {

                    hideSystemInformationDisplay(s);

                } else if (a.isEqualTo(Controller.MOUSE_CLICKED_ACTION)) {

                    mouseClicked(s);
                }

            } else {

                throw new Exception("Could not process action. The action is null.");
            }

        } else {

            throw new Exception("Could not control signal. The signal is null.");
        }
    }

    /**
     * Starts up the system.
     *
     * Create user interface by sending the corresponding signal through the system.
     * The user interface will be displayed by the screen, done in the send method.
     *
     * @param sys the system category
     * @exception Exception if the signal is null
     */
    public void startupSystem(Array sys) throws Exception {

        setupJavaEventHandling();

        String n = (String) addChild(Launcher.SYSTEM, createChild((String) sys));
        Signal s = (Signal) createChild(getCategory(Launcher.SIGNAL));

        if (s != null) {

            s.setChild(Signal.PRIORITY, Signal.NORMAL_PRIORITY);
            s.setChild(Signal.LANGUAGE, Signal.NEURO_LANGUAGE);
            s.setChild(Signal.SUBJECT, n);
            s.setChild(Signal.PREDICATE, Controller.SHOW_SYSTEM_DISPLAY_ACTION);
            s.setChild(Signal.SENDER_OBJECT, Launcher.USER);

        } else {

            throw new Exception("Could not startup system. The signal is null.");
        }

        storeSignal(s);
    }

    /**
     * Sets up the java event handling.
     *
     * @exception Exception if the java awt toolkit is null
     * @exception Exception if the java event queue is null
     */
    private void setupJavaEventHandling() throws Exception {

        // Start the awt event thread by calling getDefaultToolkit().
        // Otherwise, the event thread is started by calling the show method
        // on a java awt frame.
        java.awt.Toolkit t = java.awt.Toolkit.getDefaultToolkit();

        if (t != null) {

            java.awt.EventQueue q = t.getSystemEventQueue();

            if (q != null) {

                // Replace the SystemEventQueue with the JavaEventCatcher.
                q.push(getJavaEventCatcher());

            } else {

                throw new Exception("Could not startup system. The java event queue is null.");
            }

        } else {

            throw new Exception("Could not startup system. The java awt toolkit is null.");
        }
    }

    /**
     * Shuts down the system.
     */
    public void shutdownSystem() throws Exception {

        //?? The system where the signal is coming from needs to be found
        //?? (e.g. check on which gui the mouse click occured).
        //?? This system reference will be sent as subject of the signal.
        String ext = new String(Launcher.SYSTEM.getJavaObject() + "_" + java.lang.String.valueOf("0"));
        System system = (System) getChild(ext);

        // The system can be null if another launcher was used to create it.        
        if (system != null) {

            // Remove and destroy the system the signal is coming from.
            removeChild(ext);
            destroyChild(system);

            // If this launcher system has sent the exit signal, then set the
            // shutdown flag causing the waiting loop to break and by this to
            // finally exit the whole java virtual machine.
            setChild(Launcher.SHUTDOWN_FLAG, new Boolean(Boolean.TRUE));

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
     * @exception Exception if the signal is null
     * @exception Exception if the shutdown socket is null
     */
    public void shutdownSystemAcrossSocket() throws Exception {

        Signal s = (Signal) createChild(getCategory(Launcher.SIGNAL));

        if (s != null) {
            
            s.setChild(Signal.PRIORITY, Signal.NORMAL_PRIORITY);
            s.setChild(Signal.LANGUAGE, Signal.GUI_LANGUAGE);
            s.setChild(Signal.SUBJECT, Launcher.SYSTEM);
            s.setChild(Signal.PREDICATE, Launcher.SHUTDOWN_SYSTEM_ACTION);

        } else {

            throw new Exception("Could not shutdown system across socket. The signal is null.");
        }

        ShutdownSocket socket = (ShutdownSocket) createChild((String) getDefaultShutdownSocketCategory());

        if (socket != null) {

            socket.storeSignal(s);
//??            socket.handle(s, new Boolean(Boolean.TRUE));

        } else {

            throw new Exception("Could not shutdown system using socket. The shutdown socket is null.");
        }

        destroyChild(socket);
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
     * @exception Exception if the component is null
     */
/*??
    private void showComponentSplashWindow(BasicApplication c) throws Exception {

        if (c != null) {

//??            if (c instanceof Splashable) {

            log(Level.INFO, "Show the component splash window.");
//??            c.setSplashWindowController(c.getDefaultSplashWindowController());
//??            c.showSplashWindowController(c.getSplashWindowController());
//??            }

        } else {

            throw new Exception("Could not show component splash window. The component is null.");
        }
    }

    /**
     * Disposes the component splash window.
     *
     * @param c the component splash window
     * @exception Exception if the component is null
     */
/*??
    private void hideComponentSplashWindow(BasicApplication c) throws Exception {

        if (c != null) {

//??            if (c instanceof Splashable) {

            log(Level.INFO, "Hide the component splash window.");
//??            c.hideSplashWindowController(c.getSplashWindowController());
//??            c.destroySplashWindowController(c.getSplashWindowController());
//??            c.setSplashWindowController(null);
//??            }

        } else {

            throw new Exception("Could not hide component splash window. The component is null.");
        }
    }
*/

    /**
     * Shows the system display.
     *
     * @param s the signal
     * @exception Exception if the signal is null
     */
    protected void showSystemDisplay(Signal s) throws Exception {

        if (s != null) {

            s.setChild(Signal.PRIORITY, Signal.NORMAL_PRIORITY);
            s.setChild(Signal.LANGUAGE, Signal.GUI_LANGUAGE);
            s.setChild(Signal.OBJECT, getChild(Controller.SYSTEM_DISPLAY));

        } else {

            throw new Exception("Could not show system display. The signal is null.");
        }
    }

    /**
     * Hides the system display.
     *
     * @param s the signal
     * @exception Exception if the signal is null
     */
    protected void hideSystemDisplay(Signal s) throws Exception {

        if (s != null) {

            s.setChild(Signal.LANGUAGE, Signal.GUI_LANGUAGE);
            s.setChild(Signal.OBJECT, getChild(Controller.SYSTEM_DISPLAY));

        } else {

            throw new Exception("Could not hide system display. The signal is null.");
        }
    }

    /**
     * Shows the system information display.
     *
     * @param s the signal
     * @exception Exception if the signal is null
     */
    protected void showSystemInformationDisplay(Signal s) throws Exception {

        if (s != null) {

            //??
            //?? SystemInformation does not belong into the knowledge model!!
            //?? Create an own model for meta information about systems!
            //??

            SystemInformationDisplayTranslator t = (SystemInformationDisplayTranslator) getChild(Controller.SYSTEM_INFORMATION_DISPLAY_TRANSLATOR);

            if (t != null) {

                // Write system information into user interface.
                t.encode((KnowledgeModel) getChild(Controller.KNOWLEDGE_MODEL), getChild(Controller.SYSTEM_INFORMATION_DISPLAY));

            } else {

                throw new Exception("Could not show system information display. The translator is null.");
            }

            s.setChild(Signal.LANGUAGE, Signal.GUI_LANGUAGE);
            s.setChild(Signal.OBJECT, getChild(Controller.SYSTEM_INFORMATION_DISPLAY));

        } else {

            throw new Exception("Could not show system information display. The signal is null.");
        }
    }

    /**
     * Hides the system information display.
     *
     * @param s the signal
     * @exception Exception if the signal is null
     */
    protected void hideSystemInformationDisplay(Signal s) throws Exception {

        if (s != null) {

            s.setChild(Signal.LANGUAGE, Signal.GUI_LANGUAGE);
            s.setChild(Signal.OBJECT, getChild(Controller.SYSTEM_INFORMATION_DISPLAY));

        } else {

            throw new Exception("Could not hide system information display. The signal is null.");
        }
    }

    /**
     * Reacts on mouse clicked action.
     *
     * @param s the signal
     * @exception Exception if the signal is null
     */
    protected void mouseClicked(Signal s) throws Exception {

        java.lang.System.out.println("\n\n\n\n\n mouseClicked \n\n\n\n\n");

/*??
get screen resolution
identify mouse coordinates
identify clicked window (let Desktop do that?)
identify belonging system (owner as name string)

if (owner != this.getName()) {

    owner.handle(s);
    
} else {
    
    get system's display item that was clicked
    getAction();
}
*/

/*??
        if (s != null) {

            DesktopDisplay d = getChild(Controller.SYSTEM_DISPLAY);

            if (d != null) {

                MouseModel m = (MouseModel) s.getChild(Signal.OBJECT);
    
                if (m != null) {
    
                    // Language.
                    s.setChild(Signal.LANGUAGE, Signal.NEURO_LANGUAGE);
        
                    DisplayItem i = d.getDisplayItem((Space) m.getChild(MouseModel.POINTER_POSITION));

                    if (i != null) {
    
                        // Subject.
                        // Determine the system which belongs to the clicked window.
                        //?? s.setChild(Signal.SUBJECT, name of the system that the clicked window belongs to);
        
                        // Predicate.
                        s.setChild(Signal.PREDICATE, i.getChild(DisplayItem.ACTION));
    
                        // Sender object.
                        // Determine the active console to identify the user.
                        //?? s.setChild(Signal.SENDER_OBJECT, USER);
    
                    } else {
    
                        throw new Exception("Could not react on mouse clicked action. The display item is null.");
                    }

                } else {
        
                    throw new Exception("Could not react on mouse clicked action. The mouse model is null.");
                }

            } else {

                throw new Exception("Could not react on mouse clicked action. The desktop display is null.");
            }

        } else {

            throw new Exception("Could not react on mouse clicked action. The signal is null.");
        }
*/
    }

    /**
     * Returns the display item at the given position.
     *
     * @param p the position
     * @return the item
     * @exception Exception if the display is null
     */
    protected DisplayItem getDisplayItem(Space p) throws Exception {

        DisplayItem i = null;
/*??
        Display c = (Display) getChild(Controller.SYSTEM_DISPLAY);

        if (c != null) {

            i = (DisplayItem) c.getChild(p);

        } else {

            throw new Exception("Could not get item. The display is null.");
        }
*/

        return i;
    }

    /**
     * ?? OLD method !! Only kept here for reference purposes.
     * Remove this method once the signal is handled by controller or processor!
     *
     * Listens and reacts to tree selection events.
     *
     * @param evt the event
     */
/*??
    public void valueChanged(javax.swing.event.TreeSelectionEvent evt) {

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
    }
*/

    /**
     * Controls the signal as server dummy.
     *
     * @param s the signal
     * @exception Exception if the signal is null
     */
    public void controlAsServerDummy(Signal s) throws Exception {

        if (s != null) {

/*??
            encode((String) s.getChild(Signal.LANGUAGE), (KnowledgeModel) getChild(Controller.KNOWLEDGE_MODEL), (Model) s.getChild(Signal.OBJECT));
            process((String) s.getChild(Signal.PREDICATE), (Model) s.getChild(Signal.OBJECT));
            decode((String) s.getChild(Signal.LANGUAGE), (Model) s.getChild(Signal.OBJECT), (KnowledgeModel) getChild(Controller.KNOWLEDGE_MODEL));
*/

//??            process((String) s.getChild(Signal.PREDICATE), (KnowledgeModel) getChild(Controller.KNOWLEDGE_MODEL));
//??            encode((String) s.getChild(Signal.LANGUAGE), (KnowledgeModel) getChild(Controller.KNOWLEDGE_MODEL), (Model) s.getChild(Signal.OBJECT));

        } else {

            throw new Exception("Could not control signal. The signal is null.");
        }
    }

    /**
     * Processes a signal.
     *
     * @param a the action
     * @param dm the knowledge model
     * @exception Exception if the processor is null
     */
    private void process(String a, KnowledgeModel dm) throws Exception {

        Processor p = (Processor) getChild(Controller.PROCESSOR);

        if (p != null) {

            p.process(a, dm);

        } else {

            throw new Exception("Could not process model. The processor is null.");
        }
    }

    /**
     * Processes the data.
     *
     * @param d the data
     */
/*??
    public void process(Data d) {

        if (d != null) {

//??            operation1(d1);            
//??            operation2(d2);            
//??            operation3(d3);            
        }
    }
*/

/*??
public class ShowSystemInformation extends Item {

    /**
     * Processes the data.
     */
/*??
    public void process(Data d) {

        translate
            get system information model
            get system information display
            write model data into display
        send display to output
    }
}
*/

    //
    // Java event handling and transformation into CYBOP signals.
    //

    /**
     * Handles a java event.
     *
     * After the java event has been transformed into a CYBOP signal,
     * the signal is forwarded to the normal signal handling method
     * which finally broadcasts the signal through the whole system
     * and all sub systems.
     *
     * The following java awt methods might be of interest in understanding
     * how events are handled in the JDK and how clicked components are
     * identified:
     * java.awt.EventDispatchThread::pumpOneEventForHierarchy(...);
     * java.awt.Toolkit::getSystemEventQueueImpl();
     * java.awt.Container::dispatchEvent(AWTEvent e);
     * java.awt.Container::getMouseEventTargetImpl();
     *
     * @param evt the java event
     * @exception Exception if the java event is null
     * @exception Exception if the signal is null
     * @exception Exception if the system is null
     * @exception Exception if the controller is null
     * @exception Exception if the mouse model is null
     * @exception Exception if the mouse pointer position is null
     */
    public void handle(java.awt.AWTEvent evt) throws Exception {

        java.lang.System.out.println("SIGNAL: " + evt.toString());

        String l = null;
        String a = null;
        Item m = null;

        if (evt != null) {

            int id = evt.getID();

            if (id == java.awt.event.ComponentEvent.COMPONENT_HIDDEN) {

                a = Controller.COMPONENT_HIDDEN_ACTION;
                l = Signal.NEURO_LANGUAGE;

            } else if (id == java.awt.event.ComponentEvent.COMPONENT_MOVED) {

                a = Controller.COMPONENT_MOVED_ACTION;
                l = Signal.NEURO_LANGUAGE;

            } else if (id == java.awt.event.ComponentEvent.COMPONENT_RESIZED) {

                a = Controller.COMPONENT_RESIZED_ACTION;
                l = Signal.NEURO_LANGUAGE;

            } else if (id == java.awt.event.ComponentEvent.COMPONENT_SHOWN) {

                a = Controller.COMPONENT_SHOWN_ACTION;
                l = Signal.NEURO_LANGUAGE;

            } else if (id == java.awt.event.FocusEvent.FOCUS_GAINED) {

                a = Controller.FOCUS_GAINED_ACTION;
                l = Signal.NEURO_LANGUAGE;

            } else if (id == java.awt.event.FocusEvent.FOCUS_LOST) {

                a = Controller.FOCUS_LOST_ACTION;
                l = Signal.NEURO_LANGUAGE;

            } else if (id == java.awt.event.HierarchyEvent.ANCESTOR_MOVED) {

                a = Controller.ANCESTOR_MOVED_ACTION;
                l = Signal.NEURO_LANGUAGE;

            } else if (id == java.awt.event.HierarchyEvent.ANCESTOR_RESIZED) {

                a = Controller.ANCESTOR_RESIZED_ACTION;
                l = Signal.NEURO_LANGUAGE;

            } else if (id == java.awt.event.HierarchyEvent.HIERARCHY_CHANGED) {

                a = Controller.HIERARCHY_CHANGED_ACTION;
                l = Signal.NEURO_LANGUAGE;

            } else if (id == java.awt.event.InputMethodEvent.CARET_POSITION_CHANGED) {

                a = Controller.CARET_POSITION_CHANGED_ACTION;
                l = Signal.NEURO_LANGUAGE;

            } else if (id == java.awt.event.InputMethodEvent.INPUT_METHOD_TEXT_CHANGED) {

                a = Controller.INPUT_METHOD_TEXT_CHANGED_ACTION;
                l = Signal.NEURO_LANGUAGE;

            } else if (id == java.awt.event.KeyEvent.KEY_PRESSED) {

                a = Controller.KEY_PRESSED_ACTION;
                l = Signal.TUI_LANGUAGE;

            } else if (id == java.awt.event.KeyEvent.KEY_RELEASED) {

                a = Controller.KEY_RELEASED_ACTION;
                l = Signal.TUI_LANGUAGE;

            } else if (id == java.awt.event.KeyEvent.KEY_TYPED) {

                a = Controller.KEY_TYPED_ACTION;
                l = Signal.TUI_LANGUAGE;

            } else if (id == java.awt.event.MouseEvent.MOUSE_CLICKED) {

                a = Controller.MOUSE_CLICKED_ACTION;
                l = Signal.MOUSE_LANGUAGE;

                //?? Find out which child system is active (top window)
                //?? to use its controller here.
                System sys = (System) getChild(Launcher.SYSTEM);

                if (sys != null) {

                    Controller c = (Controller) sys.getChild(System.CONTROLLER);
    
                    if (c != null) {
    
                        m = (MouseModel) c.getChild(Controller.MOUSE_MODEL);
    
                        if (m != null) {

                            Space sp = (Space) m.getChild(MouseModel.POINTER_POSITION);

                            if (sp != null) {

                                sp.setChild(Space.EXPANSE_X_COORDINATE, new Integer(((java.awt.event.MouseEvent) evt).getX()));
                                sp.setChild(Space.EXPANSE_Y_COORDINATE, new Integer(((java.awt.event.MouseEvent) evt).getY()));

                            } else {

                                throw new Exception("Could not handle java event. The pointer position is null.");
                            }
    
                        } else {
                
                            throw new Exception("Could not handle java event. The mouse model is null.");
                        }
    
                    } else {
            
                        throw new Exception("Could not handle java event. The controller is null.");
                    }
    
                } else {
        
                    throw new Exception("Could not handle java event. The system is null.");
                }

            } else if (id == java.awt.event.MouseEvent.MOUSE_DRAGGED) {

                a = Controller.MOUSE_DRAGGED_ACTION;
                l = Signal.MOUSE_LANGUAGE;

                //?? Find out which child system is active (top window)
                //?? to use its controller here.
                System sys = (System) getChild(Launcher.SYSTEM);

                if (sys != null) {

                    Controller c = (Controller) sys.getChild(System.CONTROLLER);
    
                    if (c != null) {
    
                        m = (MouseModel) c.getChild(Controller.MOUSE_MODEL);
    
                        if (m != null) {

                            Space sp = (Space) m.getChild(MouseModel.POINTER_POSITION);

                            if (sp != null) {

                                sp.setChild(Space.EXPANSE_X_COORDINATE, new Integer(((java.awt.event.MouseEvent) evt).getX()));
                                sp.setChild(Space.EXPANSE_Y_COORDINATE, new Integer(((java.awt.event.MouseEvent) evt).getY()));

                            } else {

                                throw new Exception("Could not handle java event. The pointer position is null.");
                            }
    
                        } else {
                
                            throw new Exception("Could not handle java event. The mouse model is null.");
                        }
    
                    } else {
            
                        throw new Exception("Could not handle java event. The controller is null.");
                    }
    
                } else {
        
                    throw new Exception("Could not handle java event. The system is null.");
                }

            } else if (id == java.awt.event.MouseEvent.MOUSE_ENTERED) {

                a = Controller.MOUSE_ENTERED_ACTION;
                l = Signal.MOUSE_LANGUAGE;

                //?? Find out which child system is active (top window)
                //?? to use its controller here.
                System sys = (System) getChild(Launcher.SYSTEM);

                if (sys != null) {

                    Controller c = (Controller) sys.getChild(System.CONTROLLER);
    
                    if (c != null) {
    
                        m = (MouseModel) c.getChild(Controller.MOUSE_MODEL);
    
                        if (m != null) {

                            Space sp = (Space) m.getChild(MouseModel.POINTER_POSITION);

                            if (sp != null) {

                                sp.setChild(Space.EXPANSE_X_COORDINATE, new Integer(((java.awt.event.MouseEvent) evt).getX()));
                                sp.setChild(Space.EXPANSE_Y_COORDINATE, new Integer(((java.awt.event.MouseEvent) evt).getY()));

                            } else {

                                throw new Exception("Could not handle java event. The pointer position is null.");
                            }
    
                        } else {
                
                            throw new Exception("Could not handle java event. The mouse model is null.");
                        }
    
                    } else {
            
                        throw new Exception("Could not handle java event. The controller is null.");
                    }
    
                } else {
        
                    throw new Exception("Could not handle java event. The system is null.");
                }

            } else if (id == java.awt.event.MouseEvent.MOUSE_EXITED) {

                a = Controller.MOUSE_EXITED_ACTION;
                l = Signal.MOUSE_LANGUAGE;

                //?? Find out which child system is active (top window)
                //?? to use its controller here.
                System sys = (System) getChild(Launcher.SYSTEM);

                if (sys != null) {

                    Controller c = (Controller) sys.getChild(System.CONTROLLER);
    
                    if (c != null) {
    
                        m = (MouseModel) c.getChild(Controller.MOUSE_MODEL);
    
                        if (m != null) {

                            Space sp = (Space) m.getChild(MouseModel.POINTER_POSITION);

                            if (sp != null) {

                                sp.setChild(Space.EXPANSE_X_COORDINATE, new Integer(((java.awt.event.MouseEvent) evt).getX()));
                                sp.setChild(Space.EXPANSE_Y_COORDINATE, new Integer(((java.awt.event.MouseEvent) evt).getY()));

                            } else {

                                throw new Exception("Could not handle java event. The pointer position is null.");
                            }
    
                        } else {
                
                            throw new Exception("Could not handle java event. The mouse model is null.");
                        }
    
                    } else {
            
                        throw new Exception("Could not handle java event. The controller is null.");
                    }
    
                } else {
        
                    throw new Exception("Could not handle java event. The system is null.");
                }

            } else if (id == java.awt.event.MouseEvent.MOUSE_MOVED) {

                a = Controller.MOUSE_MOVED_ACTION;
                l = Signal.MOUSE_LANGUAGE;

                //?? Find out which child system is active (top window)
                //?? to use its controller here.
                System sys = (System) getChild(Launcher.SYSTEM);

                if (sys != null) {

                    Controller c = (Controller) sys.getChild(System.CONTROLLER);
    
                    if (c != null) {
    
                        m = (MouseModel) c.getChild(Controller.MOUSE_MODEL);
    
                        if (m != null) {

                            Space sp = (Space) m.getChild(MouseModel.POINTER_POSITION);

                            if (sp != null) {

                                sp.setChild(Space.EXPANSE_X_COORDINATE, new Integer(((java.awt.event.MouseEvent) evt).getX()));
                                sp.setChild(Space.EXPANSE_Y_COORDINATE, new Integer(((java.awt.event.MouseEvent) evt).getY()));

                            } else {

                                throw new Exception("Could not handle java event. The pointer position is null.");
                            }
    
                        } else {
                
                            throw new Exception("Could not handle java event. The mouse model is null.");
                        }
    
                    } else {
            
                        throw new Exception("Could not handle java event. The controller is null.");
                    }
    
                } else {
        
                    throw new Exception("Could not handle java event. The system is null.");
                }

            } else if (id == java.awt.event.MouseEvent.MOUSE_PRESSED) {

                a = Controller.MOUSE_PRESSED_ACTION;
                l = Signal.MOUSE_LANGUAGE;

                //?? Find out which child system is active (top window)
                //?? to use its controller here.
                System sys = (System) getChild(Launcher.SYSTEM);

                if (sys != null) {

                    Controller c = (Controller) sys.getChild(System.CONTROLLER);
    
                    if (c != null) {
    
                        m = (MouseModel) c.getChild(Controller.MOUSE_MODEL);
    
                        if (m != null) {

                            Space sp = (Space) m.getChild(MouseModel.POINTER_POSITION);

                            if (sp != null) {

                                sp.setChild(Space.EXPANSE_X_COORDINATE, new Integer(((java.awt.event.MouseEvent) evt).getX()));
                                sp.setChild(Space.EXPANSE_Y_COORDINATE, new Integer(((java.awt.event.MouseEvent) evt).getY()));

                            } else {

                                throw new Exception("Could not handle java event. The pointer position is null.");
                            }
    
                        } else {
                
                            throw new Exception("Could not handle java event. The mouse model is null.");
                        }
    
                    } else {
            
                        throw new Exception("Could not handle java event. The controller is null.");
                    }
    
                } else {
        
                    throw new Exception("Could not handle java event. The system is null.");
                }

            } else if (id == java.awt.event.MouseEvent.MOUSE_RELEASED) {

                a = Controller.MOUSE_RELEASED_ACTION;
                l = Signal.MOUSE_LANGUAGE;

                //?? Find out which child system is active (top window)
                //?? to use its controller here.
                System sys = (System) getChild(Launcher.SYSTEM);

                if (sys != null) {

                    Controller c = (Controller) sys.getChild(System.CONTROLLER);
    
                    if (c != null) {
    
                        m = (MouseModel) c.getChild(Controller.MOUSE_MODEL);
    
                        if (m != null) {

                            Space sp = (Space) m.getChild(MouseModel.POINTER_POSITION);

                            if (sp != null) {

                                sp.setChild(Space.EXPANSE_X_COORDINATE, new Integer(((java.awt.event.MouseEvent) evt).getX()));
                                sp.setChild(Space.EXPANSE_Y_COORDINATE, new Integer(((java.awt.event.MouseEvent) evt).getY()));

                            } else {

                                throw new Exception("Could not handle java event. The pointer position is null.");
                            }
    
                        } else {
                
                            throw new Exception("Could not handle java event. The mouse model is null.");
                        }
    
                    } else {
            
                        throw new Exception("Could not handle java event. The controller is null.");
                    }
    
                } else {
        
                    throw new Exception("Could not handle java event. The system is null.");
                }

            } else if (id == java.awt.event.MouseWheelEvent.MOUSE_WHEEL) {

                a = Controller.MOUSE_WHEEL_ACTION;
                l = Signal.MOUSE_LANGUAGE;
            }

            // This condition is solely for speeding up the signal (event) handling.
            // If an action is still null here, then the java event was unknown
            // so that in the comparisons above no action string could be assigned.
            // In this case it does NOT make sense to continue the signal handling.
            if (a != null) {

                Signal s = (Signal) createChild(getCategory(Launcher.SIGNAL));

                // Check for changed flags on computer (currently done by operating system),
                // e.g. to receive a keyboard or mouse event and then create a CYBOP signal of it.
                // In our case here we have checked the coming java events and will now
                // transform them into a CYBOP signal.
                if (s != null) {

                    s.setChild(Signal.PRIORITY, Signal.NORMAL_PRIORITY);
                    s.setChild(Signal.LANGUAGE, l);
                    s.setChild(Signal.SUBJECT, Launcher.SELF);
                    s.setChild(Signal.PREDICATE, a);
                    s.setChild(Signal.OBJECT, m);

                } else {
        
                    throw new Exception("Could not handle java event. The signal is null.");
                }

                storeSignal(s);
            }

        } else {

            throw new Exception("Could not handle java event. The java event is null.");
        }
    }

    /**
     * This sub class of java awt component is only meant to catch awt events.<br><br>
     *
     * Unfortunately, handling of most events is done via graphical components in java.
     */
    private class JavaEventCatcher extends java.awt.EventQueue {

        //
        // Children names.
        //

        /**
         * The launcher.
         *
         * Exceptionally, the private internal class JavaEventCatcher has
         * permittance to know about its container (the surrounding launcher).
         * This is necessary to forward java awt events to the launcher.
         */             
        private Launcher launcher;

        //
        // Launcher.
        //

        /*
         * Sets the launcher.
         *
         * @param l the launcher
         */
        public void setLauncher(Launcher l) {
    
            this.launcher = l;
        }
    
        /**
         * Returns the launcher.
         *
         * @return the launcher
         */
        public Launcher getLauncher() {

            return this.launcher;
        }

        /**
         * Dispatches an event.
         *
         * Example:
         * On clicking the mouse or a button, a hardware interrupt occurs.
         * The operating system catches this interrupt and transforms it
         * correctly into some meaningful piece of software code.
         * Device drivers are necessary to do this translation.
         * Now, all running processes are informed by the operating system.
         * In the case of Java processes (applications), the Java Virtual Machine (JVM)
         * (which is an application itself to the operating system) receives the events.
         * Finally, the JVM puts the events into the event queue of the
         * Abstract Windowing Toolkit (AWT).
         *
         * As we don't want to use event listeners and the like in CYBOP
         * (they are improper and unnecessarily complicated in our opinion -
         * as interfaces/ concerns/ aspects are, anyway),
         * we catch all events directly in the event queue, their first point
         * of occurence in the Java Development Kit (JDK) Class Hierarchy.
         *
         * The AWT distinguishes between different types of events and filters
         * them out by comparing with "instanceof" - again improper.
         * As a rule of thumb, one should never use "instanceof" in
         * Object Oriented Programming (OOP) but rather rely on inheritance.
         * However, we have to use these events here but will transform them
         * into CYBOP signals which have a predicate which is a string that
         * identifies the signal's (event's) action.
         *
         * By the way, Java events can be posted using:
         * Toolkit.getEventQueue().postEvent(evt);
         *
         * @param evt the java awt event sent directly from the JVM to here
         */
        protected void dispatchEvent(java.awt.AWTEvent evt) {

            java.lang.System.out.println("\n\n\n\n\n Test dispatch:\n" + evt);

            //?? For now, we also call the AWT event handling.
            //?? Later, we will cut it off by removing this line.
            //?? I tried removing this line:
            //?? - the frame/window still gets created
            //?? - but no contents (menue and other components) is shown
            //?? Checking this out later.
            super.dispatchEvent(evt);

            try {

                Launcher l = getLauncher();

                if (l != null) {

                    l.handle(evt);

                } else {

                    throw new Exception("Could not dispatch java awt event. The launcher is null.");
                }

            } catch (Exception e) {

                java.lang.System.out.println("ERROR: Could not dispatch java awt event. An exception occured:\n" + e);
            }
        }
    }
}

