/*
 * $RCSfile: Rectangle.java,v $
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

package cybop.core.model.description;

import cybop.core.model.*;

/**
 * This class represents a rectangle.
 *
 * A rectangle corresponds to a cell border in biology.
 *
 * @version $Revision: 1.3 $ $Date: 2003-02-20 15:35:14 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class Rectangle extends Description {

    //
    // Encapsulated java awt rectangle.
    //
    
    /**
     * Creates an encapsulated java awt rectangle.
     *
     * @return the encapsulated java awt rectangle
     */
    public java.lang.Object createJavaObject() throws NullPointerException {

        return new java.awt.Rectangle();
    }

    //
    // Children.
    //

    /** The control id. */
/*??
    private String controlId;

    /** The control parameter. */
/*??
    private Object controlParameter;

    /**
     * The view that owns this menu at any time.
     * When selected, the menu causes its owner to issue a control.
     */
/*??
    private SwingView owner;

    //
    // Control id.
    //

    /**
     * Returns the control id.
     *
     * @return the control id
     */
/*??
    public String getControlId() {

        return this.controlId;
    }

    /**
     * Sets the control id.
     *
     * @param controlId the control id
     */
/*??
    public void setControlId(String controlId) {

        this.controlId = controlId;
    }

    //
    // Control parameter.
    //

    /**
     * Returns the control parameter.
     *
     * @return the control parameter
     */
/*??
    public Object getControlParameter() {

        return this.controlParameter;
    }

    /**
     * Sets the control parameter.
     *
     * @param controlParameter the control parameter
     */
/*??
    public void setControlParameter(Object controlParameter) {

        this.controlParameter = controlParameter;
    }

    //
    // Fire action.
    //

    /**
     * Fires an action.
     *
     * @param evt the action event
     * @exception NullPointerException if the owner view is null
     */
/*??
    protected void fireActionPerformed(ActionEvent evt) throws NullPointerException {

        SwingView v = getOwner();

        if (v != null) {

//??            v.issueControl(createControl());

        } else {

            throw new NullPointerException("Could not fire action performed. The owner view is null.");
        }
    }

    //
    // Create control.
    //

    /**
     * Creates a control.
     *
     * @return the control issued when the button is pressed
     * @exception NullPointerException if the control is null
     */
/*??
    protected Control createControl() throws NullPointerException {

        Control c = new Control();

        if (c != null) {

            c.setId(getControlId());
//??            c.setParameter(getControlParameter());

        } else {

            throw new NullPointerException("Could not create control. The control is null.");
        }

        return c;
    }
*/
}

