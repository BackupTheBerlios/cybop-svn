/*
 * $RCSfile: LogRecord.java,v $
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

import cybop.core.model.String;
import cybop.core.system.*;

/**
 * This class represents a log record.
 *
 * A log record corresponds to a chromosome in a human cell core which get
 * shorter in the process of cell duplication which causes cells to get old.
 *
 * In that meaning, a log record is something like the history of a component.
 * It keeps track of state changes, caused by events (signals). The log record
 * should be handed over from component to component within the globals structure.
 *
 * A system is responsible for writing out the record to console or file or
 * another location/medium, using mechanisms offered by the framework.
 * 
 * @version $Revision: 1.6 $ $Date: 2003-05-20 06:21:59 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class LogRecord extends Chain {

    //
    // Children names.
    //

    /** The message. */
    public static final String MESSAGE = new String("message");

    /** The throwable. */
    public static final String THROWABLE = new String("throwable");

    /** The java throwable. */
    private java.lang.Throwable throwable;

    //
    // Default children.
    //

    /**
     * Returns the default message.
     *
     * @return the default message
     */
    public String getDefaultMessage() {

        return null;
    }

    /**
     * Returns the default throwable.
     *
     * @return the default throwable
     */
    public java.lang.Throwable getDefaultThrowable() {

        return null;
    }

    //
    // Throwable.
    //
    
    /**
     * Sets the throwable.
     *
     * @param t the throwable
     */
    public void setThrowable(java.lang.Throwable t) {
        
        this.throwable = t;
    }

    /**
     * Returns the throwable.
     *
     * @return the throwable
     */
    public java.lang.Throwable getThrowable() {

        return this.throwable;
    }

    //
    // Initializable.
    //

    /**
     * Initializes this log record.
     */
    public void initialize() throws Exception {

        super.initialize();
        
        setChildItem(LogRecord.MESSAGE, getDefaultMessage());
        setThrowable(getDefaultThrowable());
    }

    /**
     * Finalizes this log record.
     */
    public void finalizz() throws Exception {

        Throwable throwable = getThrowable();
        setThrowable(null);
//??        destroyThrowable(throwable);

        String message = (String) getChildItem(LogRecord.MESSAGE);
        removeChildItem(LogRecord.MESSAGE);
//??        destroyMessage(message);

        super.finalizz();
    }
}

