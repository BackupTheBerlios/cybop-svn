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
 * @version $Revision: 1.14 $ $Date: 2003-06-12 21:16:11 $ $Author: christian $
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

    /** The sender object (signal sender). */
    public static final String SENDER_OBJECT = new String("object");

    /** The object (passive data model). */
    public static final String OBJECT = new String("object");

    /** The adverbial (temporal, local, causal). */
    public static final String ADVERBIAL = new String("adverbial");

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
    // Default children.
    //

    /**
     * Returns the default priority.
     *
     * @return the default priority
     */
    public Integer getDefaultPriority() {

        return null;
    }

    /**
     * Returns the default language.
     *
     * @return the default language
     */
    public String getDefaultLanguage() {

        return null;
    }

    /**
     * Returns the default subject.
     *
     * @return the default subject
     */
    public String getDefaultSubject() {

        return null;
    }

    /**
     * Returns the default predicate.
     *
     * @return the default predicate
     */
    public String getDefaultPredicate() {

        return null;
    }

    /**
     * Returns the default sender object.
     *
     * @return the default sender object
     */
    public String getDefaultSenderObject() {

        return null;
    }

    /**
     * Returns the default object.
     *
     * @return the default object
     */
    public String getDefaultObject() {

        return null;
    }

    /**
     * Returns the default adverbial.
     *
     * @return the default adverbial
     */
    public String getDefaultAdverbial() {

        return null;
    }

    //
    // Initialization.
    //

    /**
     * Initializes this signal.
     */
    public void initialize() throws Exception {

        super.initialize();

        setChild(Signal.PRIORITY, getDefaultPriority());
        setChild(Signal.LANGUAGE, getDefaultLanguage());
        setChild(Signal.SUBJECT, getDefaultSubject());
        setChild(Signal.PREDICATE, getDefaultPredicate());
        setChild(Signal.SENDER_OBJECT, getDefaultSenderObject());
        setChild(Signal.OBJECT, getDefaultObject());
        setChild(Signal.ADVERBIAL, getDefaultAdverbial());
    }

    /**
     * Finalizes this signal.
     */
    public void finalizz() throws Exception {

        // Do not destroy children here!
        // There were created by external items and also have to be
        // destroyed by them.

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

