/*
 * $RCSfile: State.java,v $
 *
 * Copyright (c) 1999-2002. The Res Medicinae developers. All rights reserved.
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
 * http://www.resmedicinae.org
 * - Information in Medicine -
 */

package cybop.basic;

/**
 * This class represents a state.
 *
 * A state is a snapshot in time.
 * It knows about its previous state and such builds up a timeline.
 *
 * @version $Revision: 1.1 $ $Date: 2003-02-19 07:46:09 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class State extends java.lang.Object {

    //
    // Children.
    //
    
    /** The previous state. */
    private State previousState;

    //
    // The previous state.
    //
    
    /**
     * Creates the previous state.
     *
     * @return the previous state
     */
    public State createPreviousState() {

        return null;
    }

    /**
     * Destroys the previous state.
     *
     * @param s the previous state
     */
    public void destroyPreviousState(State s) {
    }

    /**
     * Sets the previous state.
     *
     * @param s the previous state
     */
    public void setPreviousState(State s) {

        this.previousState = s;
    }
    
    /**
     * Returns the previous state.
     *
     * @return the previous state
     */
    public State getPreviousState() {
        
        return this.previousState;
    }

    //
    // Initializable.
    //

    /**
     * Initializes this state.
     */
    public void initialize() throws Exception {
        
        setPreviousState(createPreviousState());
    }

    /**
     * Finalizes this state.
     *
     * The method's name is <code>finalizz</code> and not
     * <code>finalize</code> because java's top most class
     * <code>Object</code> already uses <code>finalize</code>.
     */
    public void finalizz() throws Exception {

        State previousState = getPreviousState();
        setPreviousState(null);
        destroyPreviousState(previousState);
    }
}

