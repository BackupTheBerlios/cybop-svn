/*
 * $RCSfile: ModelItem.java,v $
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
 * This class represents a model item.
 *
 * A model item can be any arbitrary abstraction of the real world.
 *
 * Because (active) system items must be able to uniquely identify a
 * (passive) model item, model items get assigned an id at the time
 * of their creation. The id consists of:
 * <ul>
 *     <li>network card number (unique in space)</li>
 *     <li>timestamp (unique in time)</li>
 * </ul>
 *
 * System items work on model items.
 *
 * Because a model item can also represent a state, that is a snapshot in time,
 * it knows about its previous state and is such able to build up a timeline.
 *
 * @version $Revision: 1.1 $ $Date: 2003-05-18 17:25:54 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class ModelItem extends Item {

    //
    // Children names.
    //

    /** The identifier. */
    private String identifier;

    /** The predecessor. */
    private ModelItem predecessor;

    //
    // The identifier.
    //
    
    /**
     * Creates the identifier.
     *
     * @return the identifier
     */
    public String createIdentifier() {

        return null;
    }

    /**
     * Destroys the identifier.
     *
     * @param s the identifier
     */
    public void destroyIdentifier(String s) {
    }

    /**
     * Sets the identifier.
     *
     * @param s the identifier
     */
    public void setIdentifier(String s) {

        this.identifier = s;
    }
    
    /**
     * Returns the identifier.
     *
     * @return the identifier
     */
    public String getIdentifier() {

        return this.identifier;
    }

    //
    // The predecessor.
    //

    /**
     * Creates the predecessor.
     *
     * @return the predecessor
     */
    public ModelItem createPredecessor() {

        return null;
    }

    /**
     * Destroys the predecessor.
     *
     * @param p the predecessor
     */
    public void destroyPredecessor(ModelItem p) {
    }

    /**
     * Sets the predecessor.
     *
     * @param p the predecessor
     */
    public void setPredecessor(ModelItem p) {

        this.predecessor = p;
    }
    
    /**
     * Returns the predecessor.
     *
     * @return the predecessor
     */
    public ModelItem getPredecessor() {

        return this.predecessor;
    }

    //
    // Initializable.
    //

    /**
     * Initializes this item.
     */
    public void initialize() throws Exception {

        super.initialize();

        setIdentifier(createIdentifier());
        setPredecessor(createPredecessor());
    }

    /**
     * Finalizes this item.
     */
    public void finalizz() throws Exception {

        ModelItem predecessor = getPredecessor();
        setPredecessor(null);
        destroyPredecessor(predecessor);

        String identifier = getIdentifier();
        setIdentifier(null);
        destroyIdentifier(identifier);

        super.finalizz();
    }
}

