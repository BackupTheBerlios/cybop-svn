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

/**
 * This is the main class of the <i>Cybernetics Oriented Interpreter</i> (CYBOI).<br><br>
 *
 * It contains a static <i>main</i> method to execute the interpreter.
 *
 * CYBOI can interpret <i>Cybernetics Oriented Language</i> (CYBOL) files,
 * which adhere to the <i>Extended Markup Language</i> (XML) format.
 *
 * @version $Revision: 1.2 $ $Date: 2003-07-15 13:21:54 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class Main extends Object {

    //?? See for example:
    //?? java.io.ObjectOutputStream::writeArray
    //?? for how to transfer a Object into a byte[]

    //
    // Complex constant.
    //
    
    /** The complex constant. */
    public static final String COMPLEX = new String("complex");

    //
    // Primitive constants.
    //
    
    /** The integer primitive constant. */
    public static final String INTEGER_PRIMITIVE = new String("integer_primitive");

    /** The float primitive constant. */
    public static final String FLOAT_PRIMITIVE = new String("float_primitive");

    /** The char primitive constant. */
    public static final String CHAR_PRIMITIVE = new String("char_primitive");

    /** The string primitive constant. */
    public static final String STRING_PRIMITIVE = new String("string_primitive");

    //
    // Application constants.
    //
    
    /** The koffice kword application constant. */
    public static final String KWORD_APPLICATION = new String("kword_application");

    /** The open office writer application constant. */
    public static final String SXW_APPLICATION = new String("sxw_application");

    //
    // Audio constants.
    //
    
    /** The mp3 audio constant. */
    public static final String MP3_AUDIO = new String("mp3_audio");

    //
    // Image constants.
    //
    
    /** The jpeg image constant. */
    public static final String JPEG_IMAGE = new String("jpeg_image");

    /** The gif image constant. */
    public static final String GIF_IMAGE = new String("gif_image");

    /** The bmp image constant. */
    public static final String BMP_IMAGE = new String("bmp_image");

    //
    // Text constants.
    //
    
    /** The sgml text constant. */
    public static final String SGML_TEXT = new String("sgml_text");

    /** The xml text constant. */
    public static final String XML_TEXT = new String("xml_text");

    /** The html text constant. */
    public static final String HTML_TEXT = new String("html_text");

    /** The rtf text constant. */
    public static final String RTF_TEXT = new String("rtf_text");

    /** The tex text constant. */
    public static final String TEX_TEXT = new String("tex_text");

    //
    // Video constants.
    //
    
    /** The mpeg video constant. */
    public static final String MPEG_VIDEO = new String("mpeg_video");

    /** The quicktime video constant. */
    public static final String QUICKTIME_VIDEO = new String("quicktime_video");

    /*
     * The main method.
     *
     * @param args the arguments
     */
    public static void main(String[] args) {

        try {

            if (args != null) {

                // Create system.
                Item i = create(args[0]);
                
                // Setup XML processing environment (SAX).
                
                // Take initial system .cybol file, given as argument.
                
                // Setup Java Event Handler.
                // All Java events get transformed into CYBOP signals and
                // are then sent through the whole system.
                
                // Alternative to Java Event Handler (if it gets replaced one day
                // once CYBOI is implemented in C):
                // Enter waiting loop and read events (IRQs) from devices.

                // The system is now started up and complete so that a loop
                // can be entered, waiting for signals (events).
//??                l.await();
    
                // The loop above is left as soon as the shutdown flag is set.
                // Destroy system.
                destroy(i);

                //
                // Runtime.getRuntime().exit(0);
                // and
                // System.exit(0);
                // do the same thing.
                // The program exits normally, when the last non-daemon thread exits.
                //
                System.out.println("INFO: Exit system normally.");
                System.exit(0);

            } else {

                System.out.println("Could not execute cyboi. The argument array is null.");
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
            System.out.println("ERROR: Exit cyboi unnormally. Undiscovered exception:\n");
            e.printStackTrace();
            System.exit(1);
        }
    }

    /**
     * Creates an item.
     *
     * @param c the category
     */
    public static Item createItem(Object c) {

        Item i = null;
        Item tmp = null;
        String name = null;
        String abstraction = null;
        String category = null;

        while (file != eof) {

            tmp = readNextItem();

            if (tmp != null) {

                name = tmp.name;
                abstraction = tmp.abstraction;
                category = tmp.category;
                position = tmp.position;

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

                    System.out.println("DEBUG: Could not read item. The category is null.");
                }

            } else {

                System.out.println("DEBUG: Could not read item. The item is null.");
            }
        }

        create(s);

        return i;
    }

    //
    // Object creation and destruction.
    //

    /**
     * Creates an integer primitive.
     *
     * @param s the integer primitive as string
     * @return the integer primitive
     */
    public static Object createIntegerPrimitive(String s) {

        return Integer.valueOf(s);
    }

    /**
     * Creates a float primitive.
     *
     * @param s the float primitive as string
     * @return the float primitive
     */
    public static Object createFloatPrimitive(String s) {

        return Double.valueOf(s);
    }

    /**
     * Creates a string primitive.
     *
     * @param s the string primitive as string
     * @return the string primitive
     */
    public static Object createStringPrimitive(String s) {

        return s;
    }

    /**
     * Creates an item.
     *
     * @param s the category as string
     * @return the item
     * @exception Exception if the category is null
     * @exception Exception if the item is null
     */
    public static Item createItem(String s) {

        Item i = null;

        // If a category is set to null, then don't try to create the item.
        if (s != null) {

            // Find class by name.
            Class cl = Class.forName(s);

            if (cl != null) {

                // Create item from class.
                i = (Item) cl.newInstance();

                if (i != null) {

                    System.out.println("INFO: Abstract item to get an abstraction.");
                    i.abstracc();

                    System.out.println("INFO: Name item to get a category.");
                    i.name(null);

                    System.out.println("INFO: Inherit item to get an inheritance.");
                    i.inherit();

                    System.out.println("INFO: Categorize item to get a hierarchy.");
                    i.categorize();

                    System.out.println("INFO: Position item to get a structure.");
                    i.position();

                    System.out.println("INFO: Constrain item to get a definition.");
                    i.constrain();

                    System.out.println("INFO: Behave item to get a behaviour.");
                    i.behave();

                    System.out.println("INFO: Initialize item to get an item.");
                    i.initialize();

                } else {

                    System.out.println("Could not create item. The item is null.");
                }

            } else {

                System.out.println("Could not create item. The category is null.");
            }

        } else {

            System.out.println("DEBUG: Could not create item. The category name is null.");
        }

        return i;
    }

    /**
     * Destroys the item.
     *
     * @param i the item
     * @exception Exception if the item is null
     */
    public static void destroyItem(Item i) {

        if (i != null) {

            System.out.println("INFO: Finalize item.");
            i.finalizz();

            System.out.println("INFO: Unbehave item.");
            i.unbehave();

            System.out.println("INFO: Unconstrain item.");
            i.unconstrain();

            System.out.println("INFO: Deposition item.");
            i.deposition();

            System.out.println("INFO: Decategorize item.");
            i.decategorize();

            System.out.println("INFO: Uninherit item.");
            i.uninherit();

            System.out.println("INFO: Unname item.");
            i.unname();

            System.out.println("INFO: Deabstract item.");
            i.deabstract();

        } else {

            System.out.println("DEBUG: Could not destroy item. The item is null.");
        }
    }

/*??
    public static void abstracc() {

        // As long as the CYBOP framework is built on Java, every
        // item needs to be capable of encapsulating a pure Java object.
        setJavaObject(createJavaObject());

        // This java tree node can contain children.
        // It is only used as long as Java objects are used in the CYBOP framework,
        // to build up a system tree using java tree nodes so that such trees can
        // easily be displayed in javax.swing.JTree objects.
        setJavaTreeNode(createJavaTreeNode());
    }

    public static void deabstract() {

        // This java tree node can contain children.
        // It is only used as long as Java objects are used in the CYBOP framework,
        // to build up a system tree using java tree nodes so that such trees can
        // easily be displayed in javax.swing.JTree objects.
        javax.swing.tree.DefaultMutableTreeNode javaTreeNode = getJavaTreeNode();
        setJavaTreeNode(null);
        destroyJavaTreeNode(javaTreeNode);

        // As long as the CYBOP framework is built on Java, every
        // item needs to be capable of encapsulating a pure Java object.
        Object javaObject = getJavaObject();
        setJavaObject(null);
        destroyJavaObject(javaObject);
    }
*/
    //
    // Encapsulated java object.
    //

    /**
     * Creates an encapsulated java object.
     *
     * @return the encapsulated java object
     * @exception Exception if the encapsulated java object is null
     */
/*??
    public static Object createJavaObject() {

        return null;
    }

    /**
     * Destroys the encapsulated java object.
     *
     * @param o the encapsulated java object
     */
/*??
    public static void destroyJavaObject(Object o) {
    }

    /**
     * Sets the encapsulated java object.
     *
     * @param o the encapsulated java object
     */
/*??
    public static void setJavaObject(Object o) {

        this.javaObject = o;
    }

    /**
     * Returns the encapsulated java object.
     *
     * @return the encapsulated java object
     */
/*??
    public static Object getJavaObject() {

        return this.javaObject;
    }

    //
    // Java tree node.
    //

    /**
     * Creates a java tree node.
     *
     * @return the java tree node
     * @exception Exception if the java tree node is null
     */
/*??
    public static javax.swing.tree.DefaultMutableTreeNode createJavaTreeNode() {

        javax.swing.tree.DefaultMutableTreeNode tn = new javax.swing.tree.DefaultMutableTreeNode();

        if (tn != null) {

            tn.setUserObject("Item");

        } else {

            System.out.println("Could not create java tree node. The java tree node is null.");
        }

        return tn;
    }

    /**
     * Destroys the java tree node.
     *
     * @param tn the java tree node
     */
/*??
    public static void destroyJavaTreeNode(javax.swing.tree.DefaultMutableTreeNode tn) {
    }

    /**
     * Sets the java tree node.
     *
     * @param tn the java tree node
     */
/*??
    public static void setJavaTreeNode(javax.swing.tree.DefaultMutableTreeNode tn) {

        this.javaTreeNode = tn;
    }

    /**
     * Returns the java tree node.
     *
     * @return the java tree node
     */
/*??
    public static javax.swing.tree.DefaultMutableTreeNode getJavaTreeNode() {

        return this.javaTreeNode;
    }

    //
    // Java tree node management.
    //

    /**
     * Adds the java tree node of the array.
     *
     * @param a the array
     * @exception Exception if the java tree node is null
     * @exception Exception if the array is null
     */
/*??
    public static void addTreeNode(Array a) {

        javax.swing.tree.DefaultMutableTreeNode tn = getJavaTreeNode();

        if (tn != null) {
    
            if (a != null) {

                //
                // It is bad coding style to use instanceof.
                // However, since this method is a temporary solution anyway,
                // it seems the simplest way to work with instanceof here.
                // This check had to be inserted because signal items have
                // children that are not child tree nodes of that signal.
                // Also, array should not know about Signal because this
                // breaks the dependency between the framework's layers.
                //
                if ((a.getJavaTreeNode() != null) && (a.getJavaTreeNode().isNodeAncestor(tn))) {

                    tn.add(a.getJavaTreeNode());
                }

            } else {

//??                System.out.println("DEBUG: Could not add java tree node. The array is null.");
            }

        } else {

            System.out.println("Could not add java tree node. The java tree node is null.");
        }
    }

    /**
     * Removes the java tree node of the array.
     *
     * @param a the array
     * @exception Exception if the java tree node is null
     * @exception Exception if the array is null
     */
/*??
    public static void removeTreeNode(Array a) {

        javax.swing.tree.DefaultMutableTreeNode tn = getJavaTreeNode();

        if (tn != null) {
    
            if (a != null) {

                //
                // It is bad coding style to use instanceof.
                // However, since this method is a temporary solution anyway,
                // it seems the simplest way to work with instanceof here.
                // This check had to be inserted because signal items have
                // children that are not child tree nodes of that signal.
                // Also, array should not know about Signal because this
                // breaks the dependency between the framework's layers.
                // Alternative:
                // if (tn.isNodeChild(a.getJavaTreeNode())) {
                //
                if ((a.getJavaTreeNode() != null) && (a.getJavaTreeNode().isNodeAncestor(tn))) {

                    tn.remove(a.getJavaTreeNode());
                }

            } else {

//??                System.out.println("DEBUG: Could not remove java tree node. The array is null.");
            }

        } else {

            System.out.println("Could not remove java tree node. The java tree node is null.");
        }
    }
*/
}

