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
 * @version $Revision: 1.3 $ $Date: 2003-07-17 09:03:04 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
class Main {

    //?? See for example:
    //?? java.io.ObjectOutputStream::writeArray
    //?? for how to transfer a Object into a byte[]

    //
    // Complex constant.
    //
    
    /** The complex constant. */
    static final String COMPLEX = new String("complex");

    //
    // Primitive constants.
    //
    
    /** The integer primitive constant. */
    static final String INTEGER_PRIMITIVE = new String("integer_primitive");

    /** The float primitive constant. */
    static final String FLOAT_PRIMITIVE = new String("float_primitive");

    /** The char primitive constant. */
    static final String CHAR_PRIMITIVE = new String("char_primitive");

    /** The string primitive constant. */
    static final String STRING_PRIMITIVE = new String("string_primitive");

    //
    // Application constants.
    //
    
    /** The koffice kword application constant. */
    static final String KWORD_APPLICATION = new String("kword_application");

    /** The open office writer application constant. */
    static final String SXW_APPLICATION = new String("sxw_application");

    //
    // Audio constants.
    //
    
    /** The mp3 audio constant. */
    static final String MP3_AUDIO = new String("mp3_audio");

    //
    // Image constants.
    //
    
    /** The jpeg image constant. */
    static final String JPEG_IMAGE = new String("jpeg_image");

    /** The gif image constant. */
    static final String GIF_IMAGE = new String("gif_image");

    /** The bmp image constant. */
    static final String BMP_IMAGE = new String("bmp_image");

    //
    // Text constants.
    //
    
    /** The sgml text constant. */
    static final String SGML_TEXT = new String("sgml_text");

    /** The xml text constant. */
    static final String XML_TEXT = new String("xml_text");

    /** The html text constant. */
    static final String HTML_TEXT = new String("html_text");

    /** The rtf text constant. */
    static final String RTF_TEXT = new String("rtf_text");

    /** The tex text constant. */
    static final String TEX_TEXT = new String("tex_text");

    //
    // Video constants.
    //
    
    /** The mpeg video constant. */
    static final String MPEG_VIDEO = new String("mpeg_video");

    /** The quicktime video constant. */
    static final String QUICKTIME_VIDEO = new String("quicktime_video");

    /*
     * The main method.
     *
     * @param args the arguments
     */
    public static void main(String[] args) {

        try {

            if (args != null) {

                // Setup XML processing environment (SAX).
                
                // Take initial system .cybol file, given as argument.

                // Create system.
                Item i = ItemHandler.createItem();

/*??
                initialize(i, args[0]);

                // Setup Java Event Handler.
                // All Java events get transformed into CYBOP signals and
                // are then sent through the whole system.

                // Alternative to Java Event Handler
                // (if it gets replaced one day, once CYBOI is implemented in C):
                // Enter waiting loop and read events (IRQs) from devices.

                // The system is now started up and complete so that a loop
                // can be entered, waiting for signals (events).
//??                l.await();

                // The loop above is left as soon as the shutdown flag is set.

                finalizz(i);
*/

                // Destroy system.
                ItemHandler.destroyItem(i);

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
     * Initializes the item.
     *
     * @param i the item
     * @param c the category
     */
/*??
    static void initialize(Item i, Object c) {

        File f = new File(c);
        XmlItem xml = null;

        while (f != eof) {

            xml = readNextItem(f);

            initialize(i, xml);
        }
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

        String name = null;
        String abstraction = null;
        String category = null;

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
    }
*/
}

