/*
 * $RCSfile: Dynamics.java,v $
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
 * This is the dynamics.<br><br>
 *
 * It contains all dynamic operation sequences.
 *
 * @version $Revision: 1.3 $ $Date: 2003-07-20 07:49:52 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
class Dynamics extends Item {

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
}

