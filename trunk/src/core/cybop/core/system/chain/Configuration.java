/*
 * $RCSfile: Configuration.java,v $
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

package cybop.core.system.chain;

import cybop.core.basic.Boolean;
import cybop.core.basic.Integer;
import cybop.core.basic.String;
import cybop.core.system.*;

/**
 * This class represents a configuration.
 *
 * A configuration corresponds to a dna genetic information in biology.
 *
 * It wraps <code>java.util.prefs.Preferences</code>, which offers a standard
 * mechanism for dealing with preference data in an application.
 *
 * This configuration tries to read (import) its values from a file.
 * If a file can not be found, the default values given in the get method
 * of each parameter will be used.
 *
 * Note the following length limitations:
 * - Maximum length of string allowed as a key (80 characters)
 * - Maximum length of a node name (80 characters)
 * - Maximum length of string allowed as a value (8192 characters)
 * That means, for storing a tree as one property, approximately 100 nodes
 * of the length 80 can be used. If the tree, i.e. length of all tree nodes
 * (absolute paths) added together is larger than that, the tree will have
 * to be split to store its branches in more than just one property.
 *
 * @version $Revision: 1.3 $ $Date: 2003-02-20 15:35:14 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class Configuration extends Chain {

    //
    // Children.
    //

    /**
     * The location which can for example poInteger to a:
     * - file
     * - database
     * - remote service
     */
    private java.lang.String location;

    /** The file to import and export preferences from/to. */
    private java.io.File file;

    //
    // Encapsulated java preferences.
    //

    /**
     * Creates the encapsulated java preferences.
     *
     * @return the encapsulated java preferences
     * @exception NullPointerException if the encapsulated java preferences is null
     */
    public java.lang.Object createJavaObject() throws NullPointerException {

        java.util.prefs.Preferences p = java.util.prefs.Preferences.systemNodeForPackage(getClass());

        if (p != null) {

        } else {

            throw new NullPointerException("Could not create encapsulated java preferences. The encapsulated java preferences is null.");
        }

        return p;
    }

    //
    // Location.
    //

    /*
     * Creates the location.
     *
     * return the location
     */
    public java.lang.String createLocation() {

        return "";
    }

    /*
     * Destroys the location
     *
     * @param l the location
     */
    public void destroyLocation(java.lang.String l) {
    }
    
    /*
     * Sets the location.
     *
     * @param location the location
     */
    public void setLocation(java.lang.String location) {

        this.location = location;
    }

    /*
     * Returns the location.
     *
     * return the location
     */
    public java.lang.String getLocation() {

        return this.location;
    }

    //
    // File.
    //

    /*
     * Creates a file.
     *
     * return the file
     */
    public java.io.File createFile() {

        return new java.io.File(getLocation());
    }

    /*
     * Destroys the file.
     *
     * @param f the file
     */
    public void destroyFile(java.io.File f) {
    }
    
    /*
     * Sets the file.
     *
     * @param f the file
     */
    public void setFile(java.io.File f) {

        this.file = f;
    }

    /*
     * Returns the file.
     *
     * return the file
     */
    public java.io.File getFile() {

        return this.file;
    }

    //
    // String value.
    //

    /*
     * Sets the string value.
     *
     * @param k the key
     * @param v the string value
     * @exception NullPointerException if the encapsulated java preferences object is null
     * @exception NullPointerException if the key is null
     */
    public void set(String k, String v) throws NullPointerException {

        java.util.prefs.Preferences p = (java.util.prefs.Preferences) getJavaObject();
        
        if (p != null) {
            
            if (k != null) {
                
                if (v != null) {
                    
                    p.put((java.lang.String) k.getJavaObject(), (java.lang.String) v.getJavaObject());

                } else {

                    java.lang.System.out.println("DEBUG: Set string value to 'null'. The string value is null.");
//??                    p.put((java.lang.String) k.getJavaObject(), "null");
                }
    
            } else {
                
                throw new NullPointerException("Could not set string value. The key is null.");
            }

        } else {
            
            throw new NullPointerException("Could not set string value. The encapsulated java preferences object is null.");
        }
    }

    /*
     * Returns the string value.
     *
     * @param k the key
     * @param def the default string value
     * @return the string value
     * @exception NullPointerException if the encapsulated java preferences object is null
     * @exception NullPointerException if the key is null
     */
    public String get(String k, String def) throws NullPointerException {

        String v = null;
        java.util.prefs.Preferences p = (java.util.prefs.Preferences) getJavaObject();

        if (p != null) {

            if (k != null) {
                
                if (def != null) {
                    
                    v = new String(p.get((java.lang.String) k.getJavaObject(), (java.lang.String) def.getJavaObject()));

                } else {

                    java.lang.System.out.println("DEBUG: Set default string value to 'null'. The default string value is null.");
//??                    v = new String(p.get((java.lang.String) k.getJavaObject(), "null"));
                }

            } else {
                
                throw new NullPointerException("Could not get string value. The key is null.");
            }

        } else {
            
            throw new NullPointerException("Could not get string value. The encapsulated java preferences object is null.");
        }

        return v;
    }

    //
    // Integer value.
    //

    /*
     * Sets the integer value.
     *
     * @param k the key
     * @param v the integer value
     * @exception NullPointerException if the encapsulated java preferences object is null
     * @exception NullPointerException if the key is null
     */
    public void set(String k, Integer v) throws NullPointerException {

        java.util.prefs.Preferences p = (java.util.prefs.Preferences) getJavaObject();

        if (p != null) {

            if (k != null) {
                
                if (v != null) {
                    
                    p.putInt((java.lang.String) k.getJavaObject(), v.getJavaPrimitive());

                } else {

                    java.lang.System.out.println("DEBUG: Set integer value to -1. The integer value is null.");
//??                    p.putInt((java.lang.String) k.getJavaObject(), -1);
                }
    
            } else {
                
                throw new NullPointerException("Could not set integer value. The key is null.");
            }
            
        } else {
            
            throw new NullPointerException("Could not set integer value. The encapsulated java preferences object is null.");
        }
    }

    /*
     * Returns the integer value.
     *
     * @param k the key
     * @param def the default integer value
     * @return the integer value
     * @exception NullPointerException if the encapsulated java preferences object is null
     * @exception NullPointerException if the key is null
     */
    public Integer get(String k, Integer def) throws NullPointerException {

        Integer v = null;
        java.util.prefs.Preferences p = (java.util.prefs.Preferences) getJavaObject();

        if (p != null) {

            if (k != null) {
                
                if (def != null) {

                    v = new Integer(p.getInt((java.lang.String) k.getJavaObject(), def.getJavaPrimitive()));

                } else {

                    java.lang.System.out.println("DEBUG: Set default integer value to -1. The default integer value is null.");
//??                    v = new Integer(p.getInt((java.lang.String) k.getJavaObject(), -1));
                }

            } else {
                
                throw new NullPointerException("Could not get integer value. The key is null.");
            }

        } else {
            
            throw new NullPointerException("Could not get integer value. The encapsulated java preferences object is null.");
        }

        return v;
    }

    //
    // Boolean value.
    //

    /*
     * Sets the boolean value.
     *
     * @param k the key
     * @param v the boolean value
     * @exception NullPointerException if the encapsulated java preferences object is null
     * @exception NullPointerException if the key is null
     */
    public void set(String k, Boolean v) throws NullPointerException {

        java.util.prefs.Preferences p = (java.util.prefs.Preferences) getJavaObject();
        
        if (p != null) {
            
            if (k != null) {
                
                if (v != null) {
                    
                    p.putBoolean((java.lang.String) k.getJavaObject(), v.getJavaPrimitive());

                } else {

                    java.lang.System.out.println("DEBUG: Set boolean value to false. The boolean value is null.");
//??                    p.putBoolean((java.lang.String) k.getJavaObject(), false);
                }
    
            } else {
                
                throw new NullPointerException("Could not set boolean value. The key is null.");
            }
            
        } else {
            
            throw new NullPointerException("Could not set boolean value. The encapsulated java preferences object is null.");
        }
    }

    /*
     * Returns the boolean value.
     *
     * @param k the key
     * @param def the default boolean value
     * @return the boolean value
     * @exception NullPointerException if the encapsulated java preferences object is null
     * @exception NullPointerException if the key is null
     */
    public Boolean get(String k, Boolean def) throws NullPointerException {

        Boolean v = null;
        java.util.prefs.Preferences p = (java.util.prefs.Preferences) getJavaObject();

        if (p != null) {

            if (k != null) {
                
                if (def != null) {
                    
                    v = new Boolean(p.getBoolean((java.lang.String) k.getJavaObject(), def.getJavaPrimitive()));

                } else {

                    java.lang.System.out.println("DEBUG: Set default boolean value to false. The default boolean value is null.");
//??                    v = new Boolean(p.getBoolean((java.lang.String) k.getJavaObject(), false));
                }

            } else {
                
                throw new NullPointerException("Could not get boolean value. The key is null.");
            }

        } else {
            
            throw new NullPointerException("Could not get boolean value. The encapsulated java preferences object is null.");
        }

        return v;
    }

    //
    // Initializable.
    //

    /**
     * Initializes this configuration.
     */
    public void initialize() throws Exception {

        super.initialize();
        
        setLocation(createLocation());
        setFile(createFile());
    }

    /**
     * Finalizes this configuration.
     */
    public void finalizz() throws Exception {

        java.io.File file = getFile();
        setFile(null);
        destroyFile(file);            

        java.lang.String location = getLocation();
        setLocation(null);
        destroyLocation(location);

        super.finalizz();
    }

    //
    // Load and save data.
    //

    /*
     * Loads configuration data.
     *
     * @exception NullPointerException if the encapsulated java preferences object is null
     */
/*??
    public void load() throws NullPointerException, java.io.FileNotFoundException, java.io.IOException, java.util.prefs.InvalidPreferencesFormatException {

        java.io.InputStream is = new java.io.FileInputStream(getFile());

        java.util.prefs.Preferences p = (java.util.prefs.Preferences) getJavaObject();
        
        if (p != null) {
            
            p.importPreferences(is);
            
        } else {
            
            throw new NullPointerException("Could not load configuration data. The encapsulated java preferences object is null.");
        }
    }

    /*
     * Saves configuration data.
     *
     * @exception NullPointerException if the encapsulated java preferences object is null
     */
/*??
    public void save() throws NullPointerException, java.io.FileNotFoundException, java.io.IOException, java.util.prefs.InvalidPreferencesFormatException, java.util.prefs.BackingStoreException {

        java.io.OutputStream os = new java.io.FileOutputStream(getFile());

        java.util.prefs.Preferences p = (java.util.prefs.Preferences) getJavaObject();
        
        if (p != null) {
            
            p.exportSubtree(os);
            
        } else {
            
            throw new NullPointerException("Could not save configuration data. The encapsulated java preferences object is null.");
        }
    }
*/
}

