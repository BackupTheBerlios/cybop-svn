/*
 * $RCSfile: Item.java,v $
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
 * This class represents an item.<br><br>
 *
 * An item can be created by instantiating (cloning) an existing category.
 * Basically, every item can become a category if copies of this item are created.
 * The meta-level classes that form a category follow this order:<br><br>
 *
 *  <ul>
 *      <li>Array</li>
 *      <li>Map</li>
 *      <li>Category</li>
 *      <li>Inheritance</li>
 *      <li>Hierarchy</li>
 *      <li>Structure</li>
 *      <li>Definition</li>
 *      <li>Behaviour</li>
 *  </ul>
 *
 * Item is the super class of all other classes in the framework.<br><br>
 *
 * An item has well-defined public methods useable by outside entities. An outside
 * entity which contains items is called their container. Containers have a contract
 * with the items they contain, in that public methods are called in a specific order,
 * called a lifecycle.<br><br>
 *
 * By calling the lifecycle methods, a container ensures the proper startup and
 * shutdown of each item, to work correctly. One or more methods can be called
 * by the container, but the order must be the same.<br>
 *
 * An item has the following lifecycle:
 *  <ul>
 *      <li>constructor(): called without any parameters on keyword <code>new</code></li>
 *      <li>abstract()</li>
 *      <li>name()</li>
 *      <li>inherit()</li>
 *      <li>categorize()</li>
 *      <li>position()</li>
 *      <li>constrain()</li>
 *      <li>behave()</li>
 *      <li>globalize()</li>
 *      <li>initialize()</li>
 *      <li>finalize(): destroys items (attributes) that are specific to this item; deallocates memory</li>
 *      <li>deglobalize()</li>
 *      <li>unbehave()</li>
 *      <li>unconstrain()</li>
 *      <li>unposition()</li>
 *      <li>decategorize()</li>
 *      <li>uninherit()</li>
 *      <li>unname()</li>
 *      <li>deabstract()</li>
 *      <li>destructor(): called without any parameters; not available for Java where a garbage collector destroys objects incidentally!</li>
 *  </ul>
 *
 * Only globalize and initialize relate to the dynamic instance creation.
 * All other methods are for specifying the static category.
 *
 * @version $Revision: 1.1 $ $Date: 2003-05-17 22:30:11 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class Item extends Behaviour {

    //
    // Attributes.
    //

    /** The children. */
    private Map children;

    //
    // Children names.
    //

    /** The log level. */
    public static final String LOG_LEVEL = new String("log_level");

    //
    // Children category names.
    //

    /** The log level category. */
    public static final String LOG_LEVEL_CATEGORY = new String("log_level_category");

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
    public static final Integer SIGNAL_LOG_LEVEL = new Integer(5);

    //
    // Default categories.
    //

    /**
     * Returns the default log level category.
     *
     * @return the default log level category
     */
    public Item getDefaultLogLevelCategory() {

        return Item.SIGNAL_LOG_LEVEL;
    }

    //
    // Children.
    //

    /**
     * Creates the children.
     *
     * @return the children
     */
    public Map createChildren() {

        return new Map();
    }

    /**
     * Destroys the children.
     *
     * @param c the children
     */
    public void destroyChildren(Map c) {
    }

    /**
     * Sets the children.
     *
     * @param c the children
     */
    public void setChildren(Map c) {

        this.children = c;
    }

    /**
     * Returns the children.
     *
     * @return the children
     */
    public Map getChildren() {

        return this.children;
    }

    //
    // Child management.
    //

    /**
     * Creates a child.
     *
     * @param n the category (class) name
     * @return the child
     * @exception Exception if the category is null
     * @exception Exception if the child is null
     */
    public Item createChildItem(String n) throws Exception {

        Item i = null;

        // If a category name is set to null, then don't try to create the child.
        if (n != null) {

            // Find class by name.
            Class cl = Class.forName((java.lang.String) n.getJavaObject());

            if (cl != null) {

                // Create item from given class.
                i = (Item) cl.newInstance();

                if (i != null) {

                    java.lang.System.out.println("INFO: Globalize child.");
                    i.globalize(
                        getChildItem(Item.CONFIGURATION),
                        getChildItem(Item.LOG_RECORD),
                        getChildItem(Item.SIGNAL_MEMORY)
                    );

                    java.lang.System.out.println("INFO: Configure child.");
                    i.configure();

                    java.lang.System.out.println("INFO: Initialize child.");
                    i.initialize();

                    java.lang.System.out.println("INFO: Position child.");
                    i.position();

                } else {

                    throw new Exception("Could not create child. The child is null.");
                }

            } else {

                throw new Exception("Could not create child. The category is null.");
            }

        } else {

            java.lang.System.out.println("DEBUG: Could not create child. The category name is null.");
        }

        return i;
    }

    /**
     * Destroys the child.
     *
     * @param i the child
     * @exception Exception if the child is null
     */
    public void destroyChildItem(Item i) throws Exception {

        if (i != null) {

            java.lang.System.out.println("INFO: Deposition child.");
            i.deposition();

            java.lang.System.out.println("INFO: Finalize child.");
            i.finalizz();

            java.lang.System.out.println("INFO: Deconfigure child.");
            i.deconfigure();

            java.lang.System.out.println("INFO: Deglobalize child.");
            i.deglobalize();

        } else {

            java.lang.System.out.println("DEBUG: Could not destroy child. The child is null.");
        }
    }

    /**
     * Sets the child.
     *
     * @param n the name
     * @param c the child
     * @exception Exception if the children is null
     */
    public void setChild(String n, Item c) throws Exception {

        Map m = getChildren();

        if (m != null) {

            m.set(n, c);

        } else {

            throw new Exception("Could not set child. The children is null.");
        }
    }

    /**
     * Removes the child.
     *
     * @param n the name
     * @exception Exception if the children is null
     */
    public void removeChild(String n) throws Exception {

        Map m = getChildren();

        if (m != null) {

            m.remove(n);

        } else {

            throw new Exception("Could not remove child. The children is null.");
        }
    }

    /**
     * Returns the child.
     *
     * @param n the name
     * @return the child
     * @exception Exception if the children is null
     */
    public Item getChild(String n) throws Exception {

        Item c = null;
        Map m = getChildren();

        if (m != null) {

            c = m.get(n);

        } else {

            throw new Exception("Could not get child. The children is null.");
        }

        return c;
    }

    /**
     * Returns the child.
     *
     * @param n the name
     * @param d the default child
     * @return the child
     * @exception Exception if the children is null
     */
    public Item getChild(String n, Item d) throws Exception {

        Item c = getChild(n);

        if (c == null) {

            c = d;
        }

        return c;
    }

    //
    // Categorization.
    //

    /**
     * Categorizes this item.
     */
    public void categorize() throws Exception {

        super.categorize();

        setChildCategory(Item.LOG_LEVEL_CATEGORY, c.getChildItem(Item.LOG_LEVEL_CATEGORY, getDefaultLogLevelCategory()));
    }

    /**
     * Decategorizes this item.
     */
    public void decategorize() throws Exception {

        //?? Write changes to local user configuration file.
//??        c.setChildItem(Item.LOG_LEVEL_CATEGORY, getChildCategory(Item.LOG_LEVEL_CATEGORY));
//??        removeChildCategory(Item.LOG_LEVEL_CATEGORY);

        super.decategorize();
    }

    //
    // Globalization.
    //

    /**
     * Globalizes this item.
     *
     * @param r the log record
     * @param m the signal memory
     */
    public void globalize(Item r, Item m) throws Exception {

        setChildItem(Item.LOG_RECORD, r);
    }

    /**
     * Deglobalizes this item.
     */
    public void deglobalize() throws Exception {

        removeChildItem(Item.LOG_RECORD);
    }

    //
    // Initialization.
    //

    /**
     * Initializes this item.
     */
    public void initialize() throws Exception {

        setChildren(createChildren());
        setChildItem(Item.LOG_LEVEL, getChildCategory(Item.LOG_LEVEL_CATEGORY));
    }

    /**
     * Finalizes this item.
     *
     * This method's name is <code>finalizz</code> and not <code>finalize</code>
     * because the java computer language already uses <code>finalize</code> in
     * its <code>java.lang.Object</code> class.
     *
     * This method will be renamed to <code>finalize</code> as soon as the new
     * and simplified CYBOL computer language is used.
     */
    public void finalizz() throws Exception {

        Item logLevel = getChildItem(Item.LOG_LEVEL);
        removeChildItem(Item.LOG_LEVEL);
        destroyChildItem((Integer) logLevel);

        Abstraction children = getChildren();
        setChildren(null);
        destroyChildren((Hierarchy) children);
    }

    //
    // Logging.
    //

    /**
     * Logs a message with no arguments.
     *
     * @param l the log level
     * @param m the message
     */
    public void log(Integer l, java.lang.String m) throws Exception {

        log(l, m, null);
    }

    /**
     * Logs a message with associated throwable information.
     *
     * @param l the log level
     * @param m the message
     * @param t the throwable
     * @exception Exception if the log level is null
     * @exception Exception if the log record is null
     */
    public void log(Integer l, java.lang.String m, java.lang.Throwable t) throws Exception {

        if (l != null) {

            if (l.isSmallerThanOrEqualTo((Integer) getChildItem(Item.LOG_LEVEL))) {

                LogRecord r = (LogRecord) getChildItem(Item.LOG_RECORD);

                if (r != null) {

                    r.setChildItem(LogRecord.MESSAGE, new String(m));
                    r.setThrowable(t);

                } else {
                    
                    throw new Exception("Could not log message. The log record is null.");
                }
    
                log(r);
            }

        } else {
            
            throw new Exception("Could not log message. The log level is null.");
        }
    }

    /**
     * Logs a log record.
     *
     * @param r the log record
     * @exception Exception if the log record is null
     */
    public void log(LogRecord r) throws Exception {

/*??
        cybop.core.system.region.controller.Encoder e = (cybop.core.system.region.controller.Encoder) getChildItem(Item.ENCODER);

        if (e != null) {

            e.drive(r);
            
        } else {

            /*??
             * Temporary replacement for logging.
             * The motor (output mechanism) has to be assigned here later.
             * For now, the system console is used for message output.
             */
            if (r.getThrowable() != null) {

                java.lang.System.out.println(this + " log\n" + "INFO" + ": " + ((String) r.getChildItem(LogRecord.MESSAGE)).getJavaObject() + "\n" + r.getThrowable());
                r.getThrowable().printStackTrace();

            } else {

                java.lang.System.out.println(this + " log\n" + "INFO" + ": " + ((String) r.getChildItem(LogRecord.MESSAGE)).getJavaObject());
            }

/*??
            throw new Exception("Could not log record. The motor is null.");
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
    // Name management.
    //

    /**
     * Builds a name.
     *
     * @param base the word base of the name
     * @return the name
     * @exception Exception if the highest name number is null
     * @exception Exception if the word base of the name is null
     * @exception Exception if the number string is null
     */
    public String buildName(String base) throws Exception {

        String n = null;
        Integer i = getHighestNameNumber(base);
        
        if (i != null) {

            String no = new String(java.lang.String.valueOf(i.getJavaPrimitive() + 1));

            if (base != null) {

                if (no != null) {

                    n = new String(base.getJavaObject() + "_" + no.getJavaObject());

                } else {
        
                    throw new Exception("Could not build name. The number string is null.");
                }

            } else {
    
                throw new Exception("Could not build name. The word base of the name is null.");
            }

        } else {

            throw new Exception("Could not build name. The highest name number is null.");
        }

        return n;        
    }

    /**
     * Returns the highest name number.
     *
     * @param base the word base of the name
     * @return the highest name number
     * @exception Exception if the children array is null
     * @exception Exception if a child is null
     * @exception Exception if the name is null
     * @exception Exception if the number is null
     */
    public Integer getHighestNameNumber(String base) throws Exception {

        Integer i = new Integer(-1);
        Item[] c = getChildren();

        if (c != null) {

            int index = 0;
            int no = getChildrenNumber();
            Item child = null;
            String n = null;
            int begin = 0;
            String sub = null;
            Integer number = null;

            while (index < no) {

                child = (Item) c[index];

                if (child != null) {

                    n = child.getName();

                    if (n != null) {

                        if (n.startsWith(base)) {

                            begin = n.indexOf(new String("_"));
                            sub = n.subString(begin + 1);
                            number = Integer.toInteger(sub);

                            if (number != null) {

                                if (number.isGreaterThan(i)) {

                                    i = number;
                                }

                            } else {
                
                                throw new Exception("Could not get highest name number. The number is null.");
                            }
                        }

                    } else {
        
                        throw new Exception("Could not get highest name number. The name is null.");
                    }
    
                } else {

                    throw new Exception("Could not get highest name number. A child is null.");
                }

                index++;
            }

        } else {

            throw new Exception("Could not get highest name number. The children array is null.");
        }

        return i;
    }

    //
    // Functionality.
    //

    /**
     * Returns the child item at the given position.
     *
     * @param p the position relative to this container item
     * @return the child item
     * @exception Exception if the children array is null
     * @exception Exception if the child item is null
     */
    public Item getChildItem(Space p) throws Exception {

        Item child = null;
/*??
        Item[] c = getChildren();

        if (c != null) {

            int no = getChildrenNumber();
            Item item = null;
            Space rp = null;
            Integer n = null;
            int i = 0;

            while (i < no) {

                item = c[i];

                // Transform position into a position relative to (within) the child item.
                rp = new Space(); //?? p.subtract(originPositionDesChildItems);

                if (item != null) {

                    if (item.contains(rp)) {

                        // Set resulting child item to the current item by default.
                        // If the current item does not have children or none of the
                        // child items contains the position, then the child item is
                        // returned itself.
                        // For example, a mouse may be clicked on a panel, in the gap between
                        // two buttons. Then, none of the buttons contains the given position
                        // but the panel as parent container of the buttons does.
                        child = item;
                        n = item.getChildrenNumber();
    
                        if (n != null) {
                            
                            if (n.isGreaterThan(0)) {
    
                                // The child item has children, so call this method
                                // recursively on child item, to get the child item's
                                // child item which is located at the given position.
                                child = item.getChildItem(rp);
                            }
                        }
                    }
    
                } else {
        
                    throw new Exception("Could not get child item. An item is null.");
                }
                
                i++;
            }

        } else {

            throw new Exception("Could not get child item. The children array is null.");
        }
*/

        return child;
    }

    /**
     * Checks whether or not this item contains the given position.
     *
     * @param p the position relative to this item
     * @return true if this item contains the given position;
     * false otherwise
     * @exception Exception if the space is null
     */
    public boolean contains(Space p) throws Exception {

        boolean b = false;
        Space s = null; //?? getChildItem(Item.SPACE);

        if (s != null) {

            b = s.contains(p);

        } else {

            throw new Exception("Could not check position. The space is null.");
        }

        return b;
    }
}

