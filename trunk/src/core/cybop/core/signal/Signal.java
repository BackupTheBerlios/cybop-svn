/*
 * $RCSfile: Signal.java,v $
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

package cybop.core.signal;

import cybop.core.category.*;
import cybop.core.model.*;
import cybop.core.model.Integer;
import cybop.core.model.String;

/**
 * This class represents a signal.<br><br>
 *
 * It serves as container transporting information of communication.
 *
 * @version $Revision: 1.16 $ $Date: 2003-06-20 13:44:24 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class Signal extends Item {

    //
    // Children names.
    //

    /** The priority. */
    public static final String PRIORITY = new String("priority");

    /** The language. */
    public static final String LANGUAGE = new String("language");

    /** The subject (signal receiver). */
    public static final String SUBJECT = new String("subject");

    /** The predicate (action). */
    public static final String PREDICATE = new String("predicate");

    /** The (genitiv) object (object owner). */
//??    public static final String SENDER_OBJECT = new String("object");

    /** The (dativ) object (signal sender). */
    public static final String SENDER_OBJECT = new String("sender_object");

    /** The (akussativ) object (passive data model). */
    public static final String OBJECT = new String("object");

    /** The adverbial (temporal, local, causal). */
    public static final String ADVERBIAL = new String("adverbial");

    /** The pre/post condition (conditional clause). */
    public static final String CONDITION = new String("condition");

    //
    // Priorities.
    //

    /** The normal priority. */
    public static final Integer NORMAL_PRIORITY = new Integer(1);

    //
    // Languages.
    //

    /** The system internal (neuro) language. */
    public static final String NEURO_LANGUAGE = new String("neuro_language");

    /** The textual user interface (tui) language. */
    public static final String TUI_LANGUAGE = new String("tui_language");

    /** The mouse language. */
    public static final String MOUSE_LANGUAGE = new String("mouse_language");

    /** The graphical user interface (gui) language. */
    public static final String GUI_LANGUAGE = new String("gui_language");

    /** The socket language. */
    public static final String SOCKET_LANGUAGE = new String("socket_language");

    /** The structured query language (sql). */
    public static final String SQ_LANGUAGE = new String("sq_language");

    /** The java messaging service (jms) language. */
    public static final String JMS_LANGUAGE = new String("jms_language");

    /** The remote method invocation (rmi) language. */
    public static final String RMI_LANGUAGE = new String("rmi_language");

    /** The common object request broker architecture (corba) language. */
    public static final String CORBA_LANGUAGE = new String("corba_language");

    /** The extensible markup language (xml). */
    public static final String XM_LANGUAGE = new String("xm_language");

    /** The simple object access protocol (soap) language. */
    public static final String SOAP_LANGUAGE = new String("soap_language");

    //
    // Default categories.
    //

    /**
     * Returns the default priority category.
     *
     * @return the default priority category
     */
    public Integer getDefaultPriorityCategory() {

        return null;
    }

    /**
     * Returns the default language category.
     *
     * @return the default language category
     */
    public String getDefaultLanguageCategory() {

        return null;
    }

    /**
     * Returns the default subject category.
     *
     * @return the default subject category
     */
    public String getDefaultSubjectCategory() {

        return null;
    }

    /**
     * Returns the default predicate category.
     *
     * @return the default predicate category
     */
    public String getDefaultPredicateCategory() {

        return null;
    }

    /**
     * Returns the default sender object category.
     *
     * @return the default sender object category
     */
    public String getDefaultSenderObjectCategory() {

        return null;
    }

    /**
     * Returns the default object category.
     *
     * @return the default object category
     */
    public String getDefaultObjectCategory() {

        return null;
    }

    /**
     * Returns the default adverbial category.
     *
     * @return the default adverbial category
     */
    public String getDefaultAdverbialCategory() {

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

        setCategory(Signal.PRIORITY, getDefaultPriorityCategory());
        setCategory(Signal.LANGUAGE, getDefaultLanguageCategory());
        setCategory(Signal.SUBJECT, getDefaultSubjectCategory());
        setCategory(Signal.PREDICATE, getDefaultPredicateCategory());
        setCategory(Signal.SENDER_OBJECT, getDefaultSenderObjectCategory());
        setCategory(Signal.OBJECT, getDefaultObjectCategory());
        setCategory(Signal.ADVERBIAL, getDefaultAdverbialCategory());
    }

    /**
     * Decategorizes this hierarchy.
     */
    public void decategorize() throws Exception {

        removeCategory(Signal.ADVERBIAL);
        removeCategory(Signal.OBJECT);
        removeCategory(Signal.SENDER_OBJECT);
        removeCategory(Signal.PREDICATE);
        removeCategory(Signal.SUBJECT);
        removeCategory(Signal.LANGUAGE);
        removeCategory(Signal.PRIORITY);

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

        setChild(Signal.PRIORITY, (Integer) getCategory(Signal.PRIORITY));
        setChild(Signal.LANGUAGE, (String) getCategory(Signal.LANGUAGE));
        setChild(Signal.SUBJECT, (String) getCategory(Signal.SUBJECT));
        setChild(Signal.PREDICATE, (String) getCategory(Signal.PREDICATE));
        setChild(Signal.SENDER_OBJECT, (String) getCategory(Signal.SENDER_OBJECT));
        setChild(Signal.OBJECT, (Item) getCategory(Signal.OBJECT));
        setChild(Signal.ADVERBIAL, (Item) getCategory(Signal.ADVERBIAL));
    }

    /**
     * Finalizes this item.
     */
    public void finalizz() throws Exception {

        // Do not destroy children here!
        // There were created by external items and also have to be
        // destroyed by those.

        removeChild(Signal.ADVERBIAL);
        removeChild(Signal.OBJECT);
        removeChild(Signal.SENDER_OBJECT);
        removeChild(Signal.PREDICATE);
        removeChild(Signal.SUBJECT);
        removeChild(Signal.LANGUAGE);
        removeChild(Signal.PRIORITY);

        super.finalizz();
    }
}

