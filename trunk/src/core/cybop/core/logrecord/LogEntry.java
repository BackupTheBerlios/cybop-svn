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
 * @version $Revision: 1.3 $ $Date: 2003-06-17 15:39:22 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class LogEntry extends LogItem {

    //
    // Children categories.
    //

    /** The time category. */
    public static final String TIME_CATEGORY = new String("time_category");

    /** The level category. */
    public static final String LEVEL_CATEGORY = new String("level_category");

    /** The message category. */
    public static final String MESSAGE_CATEGORY = new String("message_category");

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

        return new String("cybop.core.model.String");
    }

    //
    // Categorization.
    //

    /**
     * Categorizes this hierarchy.
     */
    public void categorize() throws Exception {
        
        super.categorize();

        setCategory(LogEntry.TIME_CATEGORY, getDefaultTimeCategory());
        setCategory(LogEntry.LEVEL_CATEGORY, getDefaultLevelCategory());
        setCategory(LogEntry.MESSAGE_CATEGORY, getDefaultMessageCategory());
    }

    /**
     * Decategorizes this hierarchy.
     */
    public void decategorize() throws Exception {

        Hierarchy messageCategory = getCategory(LogEntry.MESSAGE_CATEGORY);
        removeCategory(LogEntry.MESSAGE_CATEGORY);
        destroyCategory(messageCategory);

        Hierarchy levelCategory = getCategory(LogEntry.LEVEL_CATEGORY);
        removeCategory(LogEntry.LEVEL_CATEGORY);
        destroyCategory(levelCategory);

        Hierarchy timeCategory = getCategory(LogEntry.TIME_CATEGORY);
        removeCategory(LogEntry.TIME_CATEGORY);
        destroyCategory(timeCategory);

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

        setChild(LogEntry.TIME, getDefaultTime());
        setChild(LogEntry.LEVEL, getDefaultLevel());
        setChild(LogEntry.MESSAGE, getDefaultMessage());
    }

    /**
     * Finalizes this item.
     */
    public void finalizz() throws Exception {

        Item message = getChild(LogEntry.MESSAGE);
        removeChild(LogEntry.MESSAGE);
        destroyItem(message);

        Item level = getChild(LogEntry.LEVEL);
        removeChild(LogEntry.LEVEL);
        destroyItem(level);

        Item time = getChild(LogEntry.TIME);
        removeChild(LogEntry.TIME);
        destroyItem(time);

        super.finalizz();
    }
}

