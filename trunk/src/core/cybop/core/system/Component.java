/*
 * $RCSfile: Component.java,v $
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
import cybop.core.model.*;
import cybop.core.model.Boolean;
import cybop.core.model.Integer;
import cybop.core.model.String;
import cybop.core.system.*;
import cybop.core.system.chain.*;

/**
 * This class represents a component.
 *
 * It is a super class and forms an own level in the framework's ontology:
 *  <ul>
 *      <li>Network</li>
 *      <li>Family</li>
 *      <li>System</li>
 *      <li>Block</li>
 *      <li>Region</li>
 *      <li>Component</li>
 *      <li>Part</li>
 *      <li>Chain</li>
 *  </ul>
 *
 * A component corresponds to a cell in biology.
 *
 * A component has the following lifecycle:
 *  <ul>
 *      <li>constructor(): called without any parameters on keyword <code>new</code></li>
 *      <li>globalize(Structure globals): hands over global items for reuse to save time and memory</li>
 *      <li>configure(): adapts the properties of an item to the preferences of a user; read from a source</li>
 *      <li>initialize(): creates items (attributes) that are specific to this item; allocates necessary memory</li>
 *      <li>finalize(): destroys items (attributes) that are specific to this item; deallocates memory</li>
 *      <li>deconfigure(): writes system settings to configuration and makes it persistent</li>
 *      <li>deglobalize(Structure globals)</li>
 *      <li>destructor(): called without any parameters; not available for Java where a garbage collector destroys objects incidentally!</li>
 *  </ul>
 *
 * The <code>globalize</code> method must be called before <code>initialize</code>
 * because some global parameters (such as the configuration) need to be forwarded
 * to children. 
 *
 * @version $Revision: 1.20 $ $Date: 2003-06-12 21:16:11 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class Component extends SystemItem {

    //
    // Children names.
    //

    /** The logger output. */
    public static final String LOGGER_OUTPUT = new String("logger_output");

    //
    // Children category names.
    //

    /** The logger output category. */
    public static final String LOGGER_OUTPUT_CATEGORY = new String("logger_output_category");

    //
    // Default children categories.
    //

    /**
     * Returns the default logger output category.
     *
     * @return the default logger output category
     */
    public Item getDefaultLoggerOutputCategory() {

        return null;
    }

    //
    // Configuration.
    //

    /**
     * Configures this component.
     *
     * @exception Exception if the configuration is null
     */
    public void configure() throws Exception {
        
        super.configure();

        Configuration c = (Configuration) getChild(Component.CONFIGURATION);

        if (c != null) {

            setCategory(Component.LOGGER_OUTPUT_CATEGORY, c.getChild(Component.LOGGER_OUTPUT_CATEGORY, getDefaultLoggerOutputCategory()));

        } else {

            throw new Exception("Could not configure component. The configuration is null.");
        }
    }

    /**
     * Deconfigures this component.
     *
     * @exception Exception if the configuration is null
     */
    public void deconfigure() throws Exception {

        Configuration c = (Configuration) getChild(Component.CONFIGURATION);

        if (c != null) {

            c.setChild(Component.LOGGER_OUTPUT_CATEGORY, getCategory(Component.LOGGER_OUTPUT_CATEGORY));
            removeCategory(Component.LOGGER_OUTPUT_CATEGORY);

        } else {

            throw new Exception("Could not deconfigure component. The configuration is null.");
        }

        super.deconfigure();
    }

    //
    // Initialization.
    //

    /**
     * Initializes this component.
     */
    public void initialize() throws Exception {

        super.initialize();

        setChild(Component.LOGGER_OUTPUT, getCategory(Component.LOGGER_OUTPUT_CATEGORY));
    }

    /**
     * Finalizes this component.
     */
    public void finalizz() throws Exception {

        Item loggerOutput = getChild(Component.LOGGER_OUTPUT);
        removeChild(Component.LOGGER_OUTPUT);
        destroyChild((String) loggerOutput);

        super.finalizz();
    }
}

