/*
 * $RCSfile: Controller.java,v $
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

package cybop.core.system.block;

import cybop.core.category.*;
import cybop.core.knowledge.*;
import cybop.core.model.*;
import cybop.core.model.Boolean;
import cybop.core.model.String;
import cybop.core.mouse.*;
import cybop.core.screen.*;
import cybop.core.signal.*;
import cybop.core.system.*;
import cybop.core.system.region.controller.*;
import cybop.core.system.region.controller.translator.*;

/**
 * This class represents a controller.<br><br>
 *
 * A controller corresponds to the brain in an animal's or human's body.
 * Its main task is to receive input signals, process information and finally
 * send output signals.<br><br>
 *
 * Following this order of actions, the controller consists of three types of regions:
 *  <ul>
 *      <li><code>Translator (receiving signals)</code></li>
 *      <li><code>Processor (processing signals)</code></li>
 *      <li><code>Translator (sending signals)</code></li>
 *  </ul>
 *
 * @version $Revision: 1.26 $ $Date: 2003-07-15 09:44:19 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class Controller extends Block {

    //
    // Children names.
    //

    /** The processor id. */
    public static final String PROCESSOR = new String("processor");

    /** The system display. */
    public static final String SYSTEM_DISPLAY = new String("system_display");

    /** The system information. */
    public static final String SYSTEM_INFORMATION = new String("system_information");

    /** The system information display. */
    public static final String SYSTEM_INFORMATION_DISPLAY = new String("system_information_display");

    /** The system information display translator. */
    public static final String SYSTEM_INFORMATION_DISPLAY_TRANSLATOR = new String("system_information_display_translator");

    /** The mouse model. */
    public static final String MOUSE_MODEL = new String("mouse_model");

    /** The knowledge model. */
    public static final String KNOWLEDGE_MODEL = new String("knowledge_model");

//?? --- Move the following translators into some i/o class, to handle i/o devices (receive/send signal)!

    /** The textual user interface (tui) translator. */
    public static final String TUI_TRANSLATOR = new String("tui_translator");

    /** The graphical user interface (gui) translator. */
    public static final String GUI_TRANSLATOR = new String("gui_translator");

    /** The socket translator. */
    public static final String SOCKET_TRANSLATOR = new String("socket_translator");

    //
    // Default categories.
    //

    /**
     * Returns the default processor category.
     *
     * @return the default processor category
     */
    public Item getDefaultProcessorCategory() {

        return null;
    }

    /**
     * Returns the default system display category.
     *
     * @return the default system display category
     */
    public Item getDefaultSystemDisplayCategory() {

        return null;
    }

    /**
     * Returns the default system information category.
     *
     * @return the default system information category
     */
    public String getDefaultSystemInformationCategory() {

        return new String("cybop.core.systeminformation.SystemInformation");
    }

    /**
     * Returns the default system information display category.
     *
     * @return the default system information display category
     */
    public Item getDefaultSystemInformationDisplayCategory() {

        return null;
    }

    /**
     * Returns the default system information display translator category.
     *
     * @return the default system information display translator category
     */
    public Item getDefaultSystemInformationDisplayTranslatorCategory() {

        return null;
    }

    /**
     * Returns the default mouse model category.
     *
     * @return the default mouse model category
     */
    public Item getDefaultMouseModelCategory() {

        return null;
    }

    /**
     * Returns the default knowledge model category.
     *
     * @return the default knowledge model category
     */
    public Item getDefaultKnowledgeModelCategory() {

        return null;
    }

    /**
     * Returns the default tui translator category.
     *
     * @return the default tui translator category
     */
    public Item getDefaultTuiTranslatorCategory() {

        return null;
    }

    /**
     * Returns the default gui translator category.
     *
     * @return the default gui translator category
     */
    public Item getDefaultGuiTranslatorCategory() {

        return null;
    }

    /**
     * Returns the default socket translator category.
     *
     * @return the default socket translator category
     */
    public Item getDefaultSocketTranslatorCategory() {

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

        setCategory(Controller.PROCESSOR, getDefaultProcessorCategory());
        setCategory(Controller.SYSTEM_DISPLAY, getDefaultSystemDisplayCategory());
        setCategory(Controller.SYSTEM_INFORMATION, getDefaultSystemInformationCategory());
        setCategory(Controller.SYSTEM_INFORMATION_DISPLAY, getDefaultSystemInformationDisplayCategory());
        setCategory(Controller.SYSTEM_INFORMATION_DISPLAY_TRANSLATOR, getDefaultSystemInformationDisplayTranslatorCategory());
        setCategory(Controller.MOUSE_MODEL, getDefaultMouseModelCategory());
        setCategory(Controller.KNOWLEDGE_MODEL, getDefaultKnowledgeModelCategory());
        setCategory(Controller.TUI_TRANSLATOR, getDefaultTuiTranslatorCategory());
        setCategory(Controller.GUI_TRANSLATOR, getDefaultGuiTranslatorCategory());
        setCategory(Controller.SOCKET_TRANSLATOR, getDefaultSocketTranslatorCategory());
    }

    /**
     * Decategorizes this hierarchy.
     */
    public void decategorize() throws Exception {

        removeCategory(Controller.SOCKET_TRANSLATOR);
        removeCategory(Controller.GUI_TRANSLATOR);
        removeCategory(Controller.TUI_TRANSLATOR);
        removeCategory(Controller.MOUSE_MODEL);
        removeCategory(Controller.KNOWLEDGE_MODEL);
        removeCategory(Controller.SYSTEM_INFORMATION_DISPLAY_TRANSLATOR);
        removeCategory(Controller.SYSTEM_INFORMATION_DISPLAY);
        removeCategory(Controller.SYSTEM_INFORMATION);
        removeCategory(Controller.SYSTEM_DISPLAY);
        removeCategory(Controller.PROCESSOR);

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

        setChild(Controller.PROCESSOR, createChild(getCategory(Controller.PROCESSOR)));
        setChild(Controller.SYSTEM_DISPLAY, createChild(getCategory(Controller.SYSTEM_DISPLAY)));
        setChild(Controller.SYSTEM_INFORMATION, createChild(getCategory(Controller.SYSTEM_INFORMATION)));
        setChild(Controller.SYSTEM_INFORMATION_DISPLAY, createChild(getCategory(Controller.SYSTEM_INFORMATION_DISPLAY)));
        setChild(Controller.SYSTEM_INFORMATION_DISPLAY_TRANSLATOR, createChild(getCategory(Controller.SYSTEM_INFORMATION_DISPLAY_TRANSLATOR)));
        setChild(Controller.MOUSE_MODEL, createChild(getCategory(Controller.MOUSE_MODEL)));
        setChild(Controller.KNOWLEDGE_MODEL, createChild(getCategory(Controller.KNOWLEDGE_MODEL)));
        setChild(Controller.TUI_TRANSLATOR, createChild(getCategory(Controller.TUI_TRANSLATOR)));
        setChild(Controller.GUI_TRANSLATOR, createChild(getCategory(Controller.GUI_TRANSLATOR)));
        setChild(Controller.SOCKET_TRANSLATOR, createChild(getCategory(Controller.SOCKET_TRANSLATOR)));
    }

    /**
     * Finalizes this item.
     */
    public void finalizz() throws Exception {

        Item socketTranslator = getChild(Controller.SOCKET_TRANSLATOR);
        removeChild(Controller.SOCKET_TRANSLATOR);
        destroyChild(socketTranslator);

        Item guiTranslator = getChild(Controller.GUI_TRANSLATOR);
        removeChild(Controller.GUI_TRANSLATOR);
        destroyChild(guiTranslator);

        Item tuiTranslator = getChild(Controller.TUI_TRANSLATOR);
        removeChild(Controller.TUI_TRANSLATOR);
        destroyChild(tuiTranslator);

        Item knowledgeModel = getChild(Controller.KNOWLEDGE_MODEL);
        removeChild(Controller.KNOWLEDGE_MODEL);
        destroyChild(knowledgeModel);

        Item mouseModel = getChild(Controller.MOUSE_MODEL);
        removeChild(Controller.MOUSE_MODEL);
        destroyChild(mouseModel);

        Item systemInformationDisplayTranslator = getChild(Controller.SYSTEM_INFORMATION_DISPLAY_TRANSLATOR);
        removeChild(Controller.SYSTEM_INFORMATION_DISPLAY_TRANSLATOR);
        destroyChild(systemInformationDisplayTranslator);

        Item systemInformationDisplay = getChild(Controller.SYSTEM_INFORMATION_DISPLAY);
        removeChild(Controller.SYSTEM_INFORMATION_DISPLAY);
        destroyChild(systemInformationDisplay);

        Item systemInformation = getChild(Controller.SYSTEM_INFORMATION);
        removeChild(Controller.SYSTEM_INFORMATION);
        destroyChild(systemInformation);

        Item systemDisplay = getChild(Controller.SYSTEM_DISPLAY);
        removeChild(Controller.SYSTEM_DISPLAY);
        destroyChild(systemDisplay);

        Item processor = getChild(Controller.PROCESSOR);
        removeChild(Controller.PROCESSOR);
        destroyChild(processor);

        super.finalizz();
    }
}

