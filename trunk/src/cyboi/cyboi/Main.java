/*
 * $RCSfile: Main.java,v $
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

package cyboi;

//?? import java.io.*;
//?? import org.apache.xerces.dom.*;
//?? import org.apache.xerces.parsers.*;
//?? import org.apache.xml.serialize.*;
//?? import org.w3c.dom.*;

/**
 * This is the main class of the <i>Cybernetics Oriented Interpreter</i> (CYBOI).<br><br>
 *
 * It contains a static <i>main</i> method to execute the interpreter.
 *
 * CYBOI can interpret <i>Cybernetics Oriented Language</i> (CYBOL) files,
 * which adhere to the <i>Extended Markup Language</i> (XML) format.
 *
 * @version $Revision: 1.5 $ $Date: 2003-07-18 11:24:32 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
class Main {

    //?? See for example:
    //?? java.io.ObjectOutputStream::writeArray
    //?? for how to transfer a Object into a byte[]

    /** The xml dom parser. */
    static org.apache.xerces.parsers.DOMParser parser;

    /** The java event handler. */
    static JavaEventHandler java_event_handler;

    /** The signal memory. */
    static Map signal_memory;

    /*
     * The main method.
     *
     * @param args the arguments
     */
    public static void main(String[] args) {

        try {

            if (args != null) {

                Main.java_event_handler = create_java_event_handling();
                create_signal_memory();
                create_statics();
                create_dynamics();

                // Alternative to Java Event Handler
                // (if it gets replaced one day, once CYBOI is implemented in C):
                // Enter waiting loop and read events (IRQs) from devices (IVT?).

                // The system is now started up and complete so that a loop
                // can be entered, waiting for signals (events).
                Main.await();

                Item i = ItemHandler.create_item();

                Main.initialize(i, args[0]); //?? dynamics
//??                Main.initialize(i, args[1]); //?? statics

                // The loop above is left as soon as the shutdown flag is set.

//??                Main.finalizz(i);

                ItemHandler.destroy_item(i);

                destroy_dynamics();
                destroy_statics();
                destroy_signal_memory();
                destroy_java_event_handling();
                destroy_xml_environment();

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

                java.lang.System.out.println("Could not execute cyboi. The argument array is null.");
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
            java.lang.System.out.println("ERROR: Exit cyboi unnormally. Undiscovered exception:\n");
            e.printStackTrace();
            java.lang.System.exit(1);
        }
    }

    /**
     * Initializes the signal memory.
     */
    static void initialize_signal_memory() throws Exception {

        Main.signal_memory = MapHandler.create_map();
    }

    /**
     * Initializes the xml environment.
     */
    static void initialize_xml_environment() throws Exception {

        Main.parser = new org.apache.xerces.parsers.DOMParser();
    }

    /**
     * Creates the java event handler.
     *
     * @return the java event handler
     */
    static JavaEventHandler create_java_event_handler() throws Exception {

        JavaEventHandler h = new JavaEventHandler();
        
        // Start the awt event thread by calling getDefaultToolkit().
        // Otherwise, the event thread is started by calling the show method
        // on a java awt frame.
        java.awt.Toolkit t = java.awt.Toolkit.getDefaultToolkit();

        if (t != null) {

            java.awt.EventQueue q = t.getSystemEventQueue();

            if (q != null) {

                // Replace the system event queue with the java event handler.
                q.push(h);

            } else {

                java.lang.System.out.println("Could not create java event handler. The java event queue is null.");
            }

        } else {

            java.lang.System.out.println("Could not startup system. The java awt toolkit is null.");
        }
        
        return h;
    }

    /**
     * Destroys the java event handler.
     *
     * @param h the java event handler
     */
    static void destroy_java_event_handler(JavaEventHandler h) {

        Main.java_event_handler = null;
    }

    //
    // Initialization.
    //
    
    /**
     * Initializes the item.
     *
     * @param item the item
     * @param c the category
     */
    static void initialize(Item item, Object c) throws Exception {

        java.lang.String f = c + ".cybol";
        org.w3c.dom.Document doc = new org.apache.xerces.dom.DocumentImpl();

        if (Main.parser != null) {
            
            Main.parser.setFeature("http://xml.org/sax/features/validation", true);
            Main.parser.parse(f);
            java.lang.System.out.println("INFO: Parsed file: " + f);
            
            doc = Main.parser.getDocument();
            
            if (doc != null) {
                
                doc.normalize();
        
                org.w3c.dom.NodeList l = null;
                org.w3c.dom.Node n = null;

/*??
                l = doc.getElementsByTagName("name");
                
                if (l != null) {
                    
                    n = l.item(0);
                    
                    if (n != null) {
                        
                        String name = n.getNodeValue();
                        java.lang.System.out.println("INFO: Read name: " + name);
                        
                    } else {
                        
                        java.lang.System.out.println("ERROR: The node is null.");
                    }
                    
                } else {
                    
                    java.lang.System.out.println("ERROR: The node list is null.");
                }
                    
                l = doc.getElementsByTagName("super");
                
                if (l != null) {
                    
                    n = l.item(0);
                    
                    if (n != null) {
                        
                        String superCategory = n.getNodeValue();
                        java.lang.System.out.println("INFO: Read super: " + superCategory);
                        
                    } else {
                        
                        java.lang.System.out.println("ERROR: The node is null.");
                    }
                    
                } else {
                    
                    java.lang.System.out.println("ERROR: The node list is null.");
                }
*/
                    
                l = doc.getElementsByTagName("item");

                if (l != null) {
                    
                    int size = l.getLength();
                    int i = 0;
                    org.w3c.dom.NamedNodeMap m = null;
                    int msize = 0;
                    int j = 0;
                    org.w3c.dom.Node a = null;
                    java.lang.String name = null;
                    java.lang.String abstraction = null;
                    java.lang.String category = null;
       
                    while (i < size) {
                    
                        n = l.item(i);

                        if (n != null) {
                                
/*??
                            item = n.getNodeValue();
                            java.lang.System.out.println("INFO: Read item: " + item);
*/
                        
                            m = n.getAttributes();
        
                            if (m != null) {
                
                                a = m.getNamedItem("name");
                                name = a.getNodeValue();
                                java.lang.System.out.println(name);
            
                                a = m.getNamedItem("abstraction");
                                abstraction = a.getNodeValue();
                                java.lang.System.out.println(abstraction);
            
                                a = m.getNamedItem("category");
                                category = a.getNodeValue();
                                java.lang.System.out.println(category);

                            } else {
                                
                                java.lang.System.out.println("ERROR: The named node map is null.");
                            }

                        } else {
                            
                            java.lang.System.out.println("ERROR: The node is null.");
                        }
                        
                        i++;
                    }
                    
                    java.lang.Object child = null;
                    
                    if (abstraction != null) {
            
                        if (abstraction.equals(Statics.INTEGER_PRIMITIVE)) {
            
                            child = PrimitiveHandler.create_integer_primitive(category);
            
                        } else if (abstraction.equals(Statics.FLOAT_PRIMITIVE)) {
            
                            child = PrimitiveHandler.create_float_primitive(category);
            
                        } else if (abstraction.equals(Statics.CHAR_PRIMITIVE)) {
            
                            child = PrimitiveHandler.create_character_primitive(category);
            
                        } else if (abstraction.equals(Statics.STRING_PRIMITIVE)) {
            
                            child = PrimitiveHandler.create_string_primitive(category);
            
                        } else if (abstraction.equals(Statics.COMPLEX)) {
            
//??                            child = ItemHandler.create_item(category);
                        }
                    
                    } else {
                        
                        java.lang.System.out.println("ERROR: The abstraction is null.");
                    }
                    
                } else {
                    
                    java.lang.System.out.println("ERROR: The node list is null.");
                }

            } else {
                
                java.lang.System.out.println("ERROR: The document is null.");
            }
            
        } else {
            
            java.lang.System.out.println("ERROR: The parser is null.");
        }
            
/*??
        File f = new File(c);
        XmlItem xml = null;

        while (f != eof) {

            xml = readNextItem(f);

            initialize(i, xml);
        }
*/

/*??
        File f = new File("/home/cybop/src/cybol/cybol/test.xml");
        FileReader r = new FileReader(f);
        int ci;
        
        while (true) {
        
            ci = r.read();
            
            if (ci != -1) {
            
               System.out.println(ci);
            
            } else {
                
                break;
            }
        }
        
        r.close();
*/
    }

    /**
     * Reads a sub array as a sequence of bytes.
     *
     * @param b the byte array into which the data are written
     * @param o the offset in the data
     * @param n the number of bytes to be written
     */
/*??
    static void readbytes(byte[] b, int o, int n) {

        // Code.
        
        // See: Aelfred XMLParser!
    }

    /**
     * Initializes the item.
     *
     * @param i the item
     * @param c the category
     */
/*??
    static void initialize(Item i, Object c) {

        String name = tmp.name;
        String abstraction = tmp.abstraction;
        String category = tmp.category;
        String position = tmp.position;

        if (abstraction != null) {

            if (abstraction.equals(Main.INTEGER_PRIMITIVE)) {

                i = createIntegerPrimitive(category);

            } else if (abstraction.equals(Main.FLOAT_PRIMITIVE)) {

                i = createFloatPrimitive(category);

            } else if (abstraction.equals(Main.CHAR_PRIMITIVE)) {

                i = createCharPrimitive(category);

            } else if (abstraction.equals(Main.STRING_PRIMITIVE)) {

                i = createStringPrimitive(category);

            } else if (abstraction.equals(Main.COMPLEX)) {

                i = createItem(category);
            }
            
            add(i);

        } else {

            java.lang.System.out.println("DEBUG: Could not read item. The abstraction is null.");
        }
    }
*/

    /**
     * Waits for signals.
     */
    static void await() {

/*??
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

                java.lang.System.out.println("Could not wait for signals. The shutdown flag is null.");
            }

            queued = fetchSignal();

            if (queued != null) {

                //?? Temporary code block for handling of signals that came from the
                //?? java event queue and were stored in the signal memory.
                //?? These signals were created outside this method but must be
                //?? destroyed here!

                java.lang.java.lang.System.out.println("DEBUG: Handle signal " + queued.getName().getJavaObject() + " with action: " + ((String) queued.getChild(Signal.PREDICATE)).getJavaObject());
                handle(queued, new Boolean(Boolean.FALSE));

                java.lang.java.lang.System.out.println("DEBUG: Send signal " + queued.getName().getJavaObject() + " with action: " + ((String) queued.getChild(Signal.PREDICATE)).getJavaObject());
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
        
                    java.lang.System.out.println("Could not reset signal. The signal is null.");
                }
*/
/*??
            }
        }

        destroyChild(s);
*/
    }
}

