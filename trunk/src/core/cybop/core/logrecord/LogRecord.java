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

package cybop.core.logrecord;

import cybop.core.category.*;
import cybop.core.model.String;

/**
 * This class represents a log record.
 *
 * A log record stores a history, mostly that of a system.
 * It keeps track of signals (events) occuring on the system.
 *
 * The system using a log record is responsible for providing access to it.
 * This may be writing out the record to console or a file or to another medium
 * or location, using mechanisms offered by the framework.
 *
 * @version $Revision: 1.4 $ $Date: 2003-06-18 09:57:50 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class LogRecord extends LogItem {

    //
    // Children names.
    //

    /** The entry. */
    public static final String ENTRY = new String("entry");

    //
    // Default categories.
    //

    /**
     * Returns the default entry category.
     *
     * @return the default entry category
     */
    public String getDefaultEntryCategory() {

        return new String("cybop.core.logrecord.LogEntry");
    }

    //
    // Categorization.
    //

    /**
     * Categorizes this hierarchy.
     */
    public void categorize() throws Exception {
        
        super.categorize();

        setCategory(LogRecord.ENTRY, getDefaultEntryCategory());
    }

    /**
     * Decategorizes this hierarchy.
     */
    public void decategorize() throws Exception {

        removeCategory(LogRecord.ENTRY);

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

        setChild(LogRecord.ENTRY, createChild(getCategory(LogRecord.ENTRY)));
    }

    /**
     * Finalizes this item.
     */
    public void finalizz() throws Exception {

        Item entry = getChild(LogRecord.ENTRY);
        removeChild(LogRecord.ENTRY);
        destroyChild(entry);

        super.finalizz();
    }
}

