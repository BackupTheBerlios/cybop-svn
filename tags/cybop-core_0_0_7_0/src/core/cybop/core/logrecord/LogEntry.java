/*
 * $RCSfile: LogEntry.java,v $
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

package cybop.core.logrecord;

import cybop.core.category.*;
import cybop.core.model.String;

/**
 * This class represents a log entry.
 *
 * A log entry consists of the time this entry was made, a log level and a message.
 *
 * @version $Revision: 1.6 $ $Date: 2003-06-19 19:41:21 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class LogEntry extends LogItem {

    //
    // Children names.
    //

    /** The time. */
    public static final String TIME = new String("time");

    /** The level. */
    public static final String LEVEL = new String("level");

    /** The message. */
    public static final String MESSAGE = new String("message");

    //
    // Default categories.
    //

    /**
     * Returns the default time category.
     *
     * @return the default time category
     */
    public String getDefaultTimeCategory() {

        return null;
    }

    /**
     * Returns the default level category.
     *
     * @return the default level category
     */
    public String getDefaultLevelCategory() {

        return null;
    }

    /**
     * Returns the default message category.
     *
     * @return the default message category
     */
    public String getDefaultMessageCategory() {

        return null;
    }

    //
    // Categorization.
    //

    /**
     * Categorizes this hierarchy.
     */
    public void categorize() throws Exception {
        
        super.categorize();

        setCategory(LogEntry.TIME, getDefaultTimeCategory());
        setCategory(LogEntry.LEVEL, getDefaultLevelCategory());
        setCategory(LogEntry.MESSAGE, getDefaultMessageCategory());
    }

    /**
     * Decategorizes this hierarchy.
     */
    public void decategorize() throws Exception {

        removeCategory(LogEntry.MESSAGE);
        removeCategory(LogEntry.LEVEL);
        removeCategory(LogEntry.TIME);

        super.decategorize();
    }

    //
    // Initialization.
    //

    /**
     * Initializes this item.
     */
    public void initialize() throws Exception {

        super.initialize();

        setChild(LogEntry.TIME, createChild(getCategory(LogEntry.TIME)));
        setChild(LogEntry.LEVEL, createChild(getCategory(LogEntry.LEVEL)));
        setChild(LogEntry.MESSAGE, createChild(getCategory(LogEntry.MESSAGE)));
    }

    /**
     * Finalizes this item.
     */
    public void finalizz() throws Exception {

        Item message = getChild(LogEntry.MESSAGE);
        removeChild(LogEntry.MESSAGE);
        destroyChild(message);

        Item level = getChild(LogEntry.LEVEL);
        removeChild(LogEntry.LEVEL);
        destroyChild(level);

        Item time = getChild(LogEntry.TIME);
        removeChild(LogEntry.TIME);
        destroyChild(time);

        super.finalizz();
    }
}

