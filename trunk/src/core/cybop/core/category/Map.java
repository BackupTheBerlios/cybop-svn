/*
 * $RCSfile: Map.java,v $
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

package cybop.core.category;

/**
 * This class represents a map.
 *
 * A map is like a table. One column (array) contains the element names.
 * A second column (array) contains the actual element references.
 * An element is accessed by first checking for its name -- to determine
 * the index of the wanted element -- and then returning the corresponding
 * reference.
 *
 * @version $Revision: 1.12 $ $Date: 2003-06-20 15:06:25 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class Map {

    //
    // Meta attributes.
    //

    /** The name names. */
    private Array names;

    /** The name references. */
    private Array references;

    //
    // Names.
    //

    /**
     * Creates the names.
     *
     * @return the names
     */
    public Array createNames() throws Exception {

        Array a = new Array();
        
        if (a != null) {

            a.abstracc();

        } else {

            throw new Exception("Could not create names. The names is null.");
        }

        return a;
    }

    /**
     * Destroys the names.
     *
     * @param n the names
     */
    public void destroyNames(Array n) throws Exception {
    }

    /**
     * Sets the names.
     *
     * @param n the names
     */
    public void setNames(Array n) {

        this.names = n;
    }

    /**
     * Returns the names.
     *
     * @return the names
     */
    public Array getNames() {

        return this.names;
    }

    //
    // References.
    //

    /**
     * Creates the references.
     *
     * @return the references
     */
    public Array createReferences() throws Exception {

        Array a = new Array();
        
        if (a != null) {

            a.abstracc();

        } else {

            throw new Exception("Could not create references. The references is null.");
        }

        return a;
    }

    /**
     * Destroys the references.
     *
     * @param r the references
     */
    public void destroyReferences(Array r) throws Exception {
    }

    /**
     * Sets the references.
     *
     * @param r the references
     */
    public void setReferences(Array r) {

        this.references = r;
    }

    /**
     * Returns the references.
     *
     * @return the references
     */
    public Array getReferences() {

        return this.references;
    }

    /**
     * Returns the size.
     *
     * @return the size
     */
    public int getSize() throws Exception {

        int size = 0;
        Array names = getNames();

        if (names != null) {

            size = names.getSize();

        } else {

            throw new Exception("Could not get size. The references is null.");
        }

        return size;
    }

    //
    // Element management.
    //

    /**
     * Sets the element with the name.
     *
     * @param n the name
     * @param e the element
     * @exception Exception if the name is null
     * @exception Exception if the names is null
     * @exception Exception if the references is null
     */
    public void set(Array n, Array e) throws Exception {

        Array refs = getReferences();

        if (refs != null) {

            int i = getNextIndex(n);

            names.set(i, n);
            refs.set(i, e);

        } else {

            throw new Exception("Could not set element. The references is null.");
        }
    }

    /**
     * Adds the element.
     *
     * @param n the name
     * @param e the element
     * @exception Exception if the name is null
     * @exception Exception if the names is null
     * @exception Exception if the references is null
     */
    public void add(Array n, Array e) throws Exception {

        Array refs = getReferences();

        if (refs != null) {

            Array nn = getNewName(n);

            set(nn, e);

        } else {

            throw new Exception("Could not set element. The references is null.");
        }
    }

    /**
     * Removes the element with the index.
     *
     * @param i the index
     * @exception Exception if the references is null
     */
    public void remove(int i) throws Exception {

        Array refs = getReferences();

        if (refs != null) {

            if (i > -1) {

                names.remove(i);
                refs.remove(i);
            }

        } else {

            throw new Exception("Could not remove element. The references is null.");
        }
    }

    /**
     * Removes the element with the name.
     *
     * @param n the name
     * @exception Exception if the references is null
     */
    public void remove(Array n) throws Exception {
    
        int i = getIndex(n);
    
        remove(i);
    }

    /**
     * Returns the element with the index.
     *
     * @param i the index
     * @return the element
     * @exception Exception if the references is null
     */
    public Array get(int i) throws Exception {

        Array e = null;
        Array refs = getReferences();

        if (refs != null) {

            e = refs.get(i);

        } else {

            throw new Exception("Could not get element. The references is null.");
        }

        return e;
    }

    /**
     * Returns the element with the name.
     *
     * @param n the name
     * @return the element
     * @exception Exception if the references is null
     */
    public Array get(Array n) throws Exception {

        int i = getIndex(n);

        return get(i);
    }

    /**
     * Returns the index of the name.
     *
     * @param n the name
     * @return the index
     * @exception Exception if the names is null
     */
    public int getIndex(Array n) throws Exception {

        int index = -1;
        Array names = getNames();

        if (names != null) {

            int i = index + 1;
            Array name = null;

            while (i < names.getSize()) {

                name = names.get(i);

                // If a null name is reached, then the name was not found.
                // In this case, reset index to -1.
                if (name == null) {

                    break;
                
                } else {

                    // If a name equal to the searched one is found,
                    // then its index is the one to be returned.
                    if (name.isEqualTo(n)) {

                        index = i;
                        break;
                    }
                }

                i++;
            }

        } else {

            throw new Exception("Could not get index. The names is null.");
        }

        return index;
    }

    /**
     * Returns the next index that can be used to set an element.
     *
     * If an element with the given name is found, then its index will be returned
     * so that the element can be replaced.
     * If a null element is reached, then the corresponding index marks the next
     * available place and will be returned.
     * If neither an element matches nor a null element is reached, then the
     * map is full and its size will be returned as next available index.
     *
     * @param n the name
     * @return the next index
     * @exception Exception if the names is null
     */
    public int getNextIndex(Array n) throws Exception {

        int index = -1;
        Array names = getNames();

        if (names != null) {

            int i = index + 1;
            Array name = null;

            while (i < names.getSize()) {

                name = names.get(i);

                // If a null name is reached, then the name was not found.
                // In this case, the current value of i is the next free index.
                if (name == null) {

                    index = i;
                    break;

                } else {

                    // If a name equal to the searched one is found,
                    // then its index is the one to be returned since
                    // this element will have to be replaced.
                    if (name.isEqualTo(n)) {

                        index = i;
                        break;
                    }
                }

                i++;
            }

            // Neither element matched, nor was a null element found.
            // The map is full and such its size will be the next index to be used.
            if (index == -1) {

                index = names.getSize();
            }

        } else {

            throw new Exception("Could not get next free index. The names is null.");
        }

        return index;
    }

    /**
     * Returns an extended version of the given name.
     *
     * The given name is used as a word base for the new name.
     * Additionally, the new name will contain a number suffix.
     * It is created by increasing the currently highest number suffix by one.
     *
     * @param n the name
     * @return the new name
     * @exception Exception if the names is null
     */
    public Array getNewName(Array n) throws Exception {

        Array nn = null;
        int i = getHighestIndex(n);

        if (i != null) {

            String no = new String(java.lang.String.valueOf(i.getJavaPrimitive() + 1));

            if (base != null) {

                if (no != null) {

                    nn = new String(base.getJavaObject() + "_" + no.getJavaObject());

                } else {
        
                    throw new Exception("Could not build name. The number string is null.");
                }

            } else {
    
                throw new Exception("Could not build name. The word base of the name is null.");
            }

        } else {

            throw new Exception("Could not build name. The highest name number is null.");
        }
        
        return nn;
    }

    /**
     * Returns the highest index with the given name as word base.
     *
     * @param n the name
     * @return the highest index
     * @exception Exception if the names is null
     */
    public int getHighestIndex(Array n) throws Exception {

        int index = -1;
        Array names = getNames();

        if (names != null) {

            int i = 0;
            int size = names.getSize();
            Array name = null;
            int begin = 0;
            java.lang.String sub = null;
            int number = -1;
            int max = -1;

            while (i < size) {

                name = names.get(i);

                if (name != null) {

                    if (((java.lang.String) name.getJavaObject()).startsWith(((java.lang.String)) n.getJavaObject())) {

                        begin = ((java.lang.String) name.getJavaObject()).indexOf(new String("_"));
                        sub = ((java.lang.String) name.getJavaObject()).substring(begin + 1);
                        number = java.lang.Integer.parseInt(sub);

                        if (number > max) {

                            max = number;
                            index = number;
                        }
                    }

                } else {

                    // Reached last valid name before. Only null entries left.
                    break;
                }

                i++;
            }

        } else {

            throw new Exception("Could not get highest index. The names is null.");
        }

        return index;
    }

    //
    // Abstraction.
    //

    /**
     * Abstracts this abstraction.
     */
    public void abstracc() throws Exception {

        setNames(createNames());
        setReferences(createReferences());
    }

    /**
     * Deabstracts this abstraction.
     */
    public void deabstract() throws Exception {

        Array references = getReferences();
        setReferences(null);
        destroyReferences(references);

        Array names = getNames();
        setNames(null);
        destroyNames(names);
    }
}

