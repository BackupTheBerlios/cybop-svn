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
import cybop.core.system.chain.*;
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
 * @version $Revision: 1.22 $ $Date: 2003-06-18 09:57:50 $ $Author: christian $
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
    // Actions.
    //

    /** The show system display action. */
    public static final String SHOW_SYSTEM_DISPLAY_ACTION = new String("show_system_display_action");

    /** The hide system display action. */
    public static final String HIDE_SYSTEM_DISPLAY_ACTION = new String("hide_system_display_action");

    /** The show system information display action. */
    public static final String SHOW_SYSTEM_INFORMATION_DISPLAY_ACTION = new String("show_system_information_display_action");

    /** The hide system information display action. */
    public static final String HIDE_SYSTEM_INFORMATION_DISPLAY_ACTION = new String("hide_system_information_display_action");

    /** The focus gained action. */
    public static final String FOCUS_GAINED_ACTION = new String("focus_gained_action");

    /** The focus lost action. */
    public static final String FOCUS_LOST_ACTION = new String("focus_lost_action");

    /** The mouse pressed action. */
    public static final String MOUSE_PRESSED_ACTION = new String("mouse_pressed_action");

    /** The mouse released action. */
    public static final String MOUSE_RELEASED_ACTION = new String("mouse_released_action");

    /** The mouse clicked action. */
    public static final String MOUSE_CLICKED_ACTION = new String("mouse_clicked_action");

    /** The mouse entered action. */
    public static final String MOUSE_ENTERED_ACTION = new String("mouse_entered_action");

    /** The mouse exited action. */
    public static final String MOUSE_EXITED_ACTION = new String("mouse_exited_action");

    /** The mouse dragged action. */
    public static final String MOUSE_DRAGGED_ACTION = new String("mouse_dragged_action");

    /** The mouse moved action. */
    public static final String MOUSE_MOVED_ACTION = new String("mouse_moved_action");

    /** The mouse wheel action. */
    public static final String MOUSE_WHEEL_ACTION = new String("mouse_wheel_action");

    /** The key typed action. */
    public static final String KEY_TYPED_ACTION = new String("key_typed_action");

    /** The key released action. */
    public static final String KEY_RELEASED_ACTION = new String("key_released_action");

    /** The key pressed action. */
    public static final String KEY_PRESSED_ACTION = new String("key_pressed_action");

    /** The component resized action. */
    public static final String COMPONENT_RESIZED_ACTION = new String("component_resized_action");

    /** The component moved action. */
    public static final String COMPONENT_MOVED_ACTION = new String("component_moved_action");

    /** The component shown action. */
    public static final String COMPONENT_SHOWN_ACTION = new String("component_shown_action");

    /** The component hidden action. */
    public static final String COMPONENT_HIDDEN_ACTION = new String("component_hidden_action");

    /** The input method text changed action. */
    public static final String INPUT_METHOD_TEXT_CHANGED_ACTION = new String("input_method_text_changed_action");

    /** The caret position changed action. */
    public static final String CARET_POSITION_CHANGED_ACTION = new String("caret_position_changed_action");

    /** The hierarchy changed action. */
    public static final String HIERARCHY_CHANGED_ACTION = new String("hierarchy_changed_action");

    /** The ancestor resized action. */
    public static final String ANCESTOR_RESIZED_ACTION = new String("ancestor_resized_action");

    /** The ancestor moved action. */
    public static final String ANCESTOR_MOVED_ACTION = new String("ancestor_moved_action");

//?? ------------------------------

    /** The create system signal id. */
    public static final String CREATE_SYSTEM_SIGNAL_ID = new String("create_system");

    /** The destroy system signal id. */
    public static final String DESTROY_SYSTEM_SIGNAL_ID = new String("destroy_system");

    /** The cut signal id. */
    public static final String CUT_SIGNAL_ID = new String("cut");

    /** The copy signal id. */
    public static final String COPY_SIGNAL_ID = new String("copy");

    /** The paste signal id. */
    public static final String PASTE_SIGNAL_ID = new String("paste");

    /** The show tool bar signal id. */
    public static final String SHOW_TOOL_BAR_SIGNAL_ID = new String("show_tool_bar");

    /** The show status bar signal id. */
    public static final String SHOW_STATUS_BAR_SIGNAL_ID = new String("show_status_bar");

    /** The configure menu bar signal id. */
    public static final String CONFIGURE_MENU_BAR_SIGNAL_ID = new String("configure_menu_bar");

    /** The configure tool bar signal id. */
    public static final String CONFIGURE_TOOL_BAR_SIGNAL_ID = new String("configure_tool_bar");

    /** The configure status bar signal id. */
    public static final String CONFIGURE_STATUS_BAR_SIGNAL_ID = new String("configure_status_bar");

    /** The configure key bindings signal id. */
    public static final String CONFIGURE_KEY_BINDINGS_SIGNAL_ID = new String("configure_key_bindings");

    /** The show help contents signal id. */
    public static final String SHOW_HELP_CONTENTS_SIGNAL_ID = new String("show_help_contents");

    /** The report bug signal id. */
    public static final String REPORT_BUG_SIGNAL_ID = new String("report_bug");

    /** The link to website signal id. */
    public static final String LINK_TO_WEBSITE_SIGNAL_ID = new String("link_to_website");

    //
    // Portal system actions.
    //

    /** The show systems tree signal id. */
    public static final String SHOW_SYSTEMS_TREE_SIGNAL_ID = new String("show_systems_tree");

    /** The configure systems tree signal id. */
    public static final String CONFIGURE_SYSTEMS_TREE_SIGNAL_ID = new String("configure_systems_tree");

    /** The configure res medicinae signal id. */
    public static final String CONFIGURE_RES_MEDICINAE_SIGNAL_ID = new String("configure_res_medicinae");

    /** The iconify all signal id. */
    public static final String ICONIFY_ALL_SIGNAL_ID = new String("iconify_all");

    /** The close signal id. */
    public static final String CLOSE_SIGNAL_ID = new String("close");

    /** The close all signal id. */
    public static final String CLOSE_ALL_SIGNAL_ID = new String("close_all");

    /** The cascade signal id. */
    public static final String CASCADE_SIGNAL_ID = new String("cascade");

    /** The tile vertically signal id. */
    public static final String TILE_VERTICALLY_SIGNAL_ID = new String("tile_vertically");

    /** The tile horizontally signal id. */
    public static final String TILE_HORIZONTALLY_SIGNAL_ID = new String("tile_horizontally");

    /** The set frame display signal id. */
    public static final String SET_FRAME_DISPLAY_SIGNAL_ID = new String("set_frame_display");

    /** The set internal frame display signal id. */
    public static final String SET_INTERNAL_FRAME_DISPLAY_SIGNAL_ID = new String("set_internal_frame_display");

    /** The set tab page display signal id. */
    public static final String SET_TAB_PAGE_DISPLAY_SIGNAL_ID = new String("set_tab_page_display");

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

    //
    // Controlling.
    //

    /**
     * Controls the signal.
     *
     * @param s the signal
     * @exception Exception if the signal is null
     */
    public void control(Signal s) throws Exception {

        if (s != null) {

            String a = (String) s.getChild(Signal.PREDICATE);

            if (a != null) {

                if (a.isEqualTo(Controller.SHOW_SYSTEM_DISPLAY_ACTION)) {

                    showSystemDisplay(s);
    
                } else if (a.isEqualTo(Controller.HIDE_SYSTEM_DISPLAY_ACTION)) {
    
                    hideSystemDisplay(s);

                } else if (a.isEqualTo(Controller.SHOW_SYSTEM_INFORMATION_DISPLAY_ACTION)) {

                    showSystemInformationDisplay(s);
    
                } else if (a.isEqualTo(Controller.HIDE_SYSTEM_INFORMATION_DISPLAY_ACTION)) {

                    hideSystemInformationDisplay(s);
    
                } else if (a.isEqualTo(Controller.MOUSE_CLICKED_ACTION)) {

                    mouseClicked(s);
                }

            } else {

                throw new Exception("Could not process action. The action is null.");
            }

        } else {

            throw new Exception("Could not control signal. The signal is null.");
        }
    }

    /**
     * Shows the system display.
     *
     * @param s the signal
     * @exception Exception if the signal is null
     */
    protected void showSystemDisplay(Signal s) throws Exception {

        if (s != null) {

            s.setChild(Signal.PRIORITY, Signal.NORMAL_PRIORITY);
            s.setChild(Signal.LANGUAGE, Signal.GUI_LANGUAGE);
            s.setChild(Signal.OBJECT, getChild(Controller.SYSTEM_DISPLAY));

        } else {

            throw new Exception("Could not show system display. The signal is null.");
        }
    }

    /**
     * Hides the system display.
     *
     * @param s the signal
     * @exception Exception if the signal is null
     */
    protected void hideSystemDisplay(Signal s) throws Exception {

        if (s != null) {

            s.setChild(Signal.LANGUAGE, Signal.GUI_LANGUAGE);
            s.setChild(Signal.OBJECT, getChild(Controller.SYSTEM_DISPLAY));

        } else {

            throw new Exception("Could not hide system display. The signal is null.");
        }
    }

    /**
     * Shows the system information display.
     *
     * @param s the signal
     * @exception Exception if the signal is null
     */
    protected void showSystemInformationDisplay(Signal s) throws Exception {

        if (s != null) {

            //??
            //?? SystemInformation does not belong into the knowledge model!!
            //?? Create an own model for meta information about systems!
            //??

            SystemInformationDisplayTranslator t = (SystemInformationDisplayTranslator) getChild(Controller.SYSTEM_INFORMATION_DISPLAY_TRANSLATOR);

            if (t != null) {

                // Write system information into user interface.
                t.encode((KnowledgeModel) getChild(Controller.KNOWLEDGE_MODEL), (Model) getChild(Controller.SYSTEM_INFORMATION_DISPLAY));

            } else {

                throw new Exception("Could not show system information display. The translator is null.");
            }

            s.setChild(Signal.LANGUAGE, Signal.GUI_LANGUAGE);
            s.setChild(Signal.OBJECT, getChild(Controller.SYSTEM_INFORMATION_DISPLAY));

        } else {

            throw new Exception("Could not show system information display. The signal is null.");
        }
    }

    /**
     * Hides the system information display.
     *
     * @param s the signal
     * @exception Exception if the signal is null
     */
    protected void hideSystemInformationDisplay(Signal s) throws Exception {

        if (s != null) {

            s.setChild(Signal.LANGUAGE, Signal.GUI_LANGUAGE);
            s.setChild(Signal.OBJECT, getChild(Controller.SYSTEM_INFORMATION_DISPLAY));

        } else {

            throw new Exception("Could not hide system information display. The signal is null.");
        }
    }

    /**
     * Reacts on mouse clicked action.
     *
     * @param s the signal
     * @exception Exception if the signal is null
     */
    protected void mouseClicked(Signal s) throws Exception {

        java.lang.System.out.println("\n\n\n\n\n mouseClicked \n\n\n\n\n");

        if (s != null) {

            MouseModel m = (MouseModel) s.getChild(Signal.OBJECT);

            if (m != null) {

                // Language.
                s.setChild(Signal.LANGUAGE, Signal.NEURO_LANGUAGE);

/*??
                DisplayItem i = getItem((Space) m.getChild(MouseModel.POINTER_POSITION));

                if (i != null) {

                    // Subject.
                    // Determine the system which belongs to the clicked window.
                    //?? s.setChild(Signal.SUBJECT, system belonging to the clicked window);
    
                    // Predicate.
                    String a = (String) i.getChild(DisplayItem.ACTION);

                    s.setChild(Signal.PREDICATE, a);

                    // Sender object.
                    // Determine the active console to identify the user.
                    //?? s.setChild(Signal.SENDER_OBJECT, USER);

                } else {

                    throw new Exception("Could not react on mouse clicked action. The graphic item is null.");
                }
*/

            } else {
    
                throw new Exception("Could not react on mouse clicked action. The mouse model is null.");
            }

        } else {

            throw new Exception("Could not react on mouse clicked action. The signal is null.");
        }
    }

    /**
     * Returns the item at the given position.
     *
     * @param p the position
     * @return the item
     * @exception Exception if the display is null
     */
    protected Item getItem(Space p) throws Exception {

        Item i = null;
        Display c = (Display) getChild(Controller.SYSTEM_DISPLAY);

        if (c != null) {

            i = c.getChild(p);

        } else {

            throw new Exception("Could not get item. The display is null.");
        }

        return i;
    }

    /**
     * Controls the signal as server dummy.
     *
     * @param s the signal
     * @exception Exception if the signal is null
     */
    public void controlAsServerDummy(Signal s) throws Exception {

        if (s != null) {

/*??
            encode((String) s.getChild(Signal.LANGUAGE), (KnowledgeModel) getChild(Controller.KNOWLEDGE_MODEL), (Model) s.getChild(Signal.OBJECT));
            process((String) s.getChild(Signal.PREDICATE), (Model) s.getChild(Signal.OBJECT));
            decode((String) s.getChild(Signal.LANGUAGE), (Model) s.getChild(Signal.OBJECT), (KnowledgeModel) getChild(Controller.KNOWLEDGE_MODEL));
*/

//??            process((String) s.getChild(Signal.PREDICATE), (KnowledgeModel) getChild(Controller.KNOWLEDGE_MODEL));
//??            encode((String) s.getChild(Signal.LANGUAGE), (KnowledgeModel) getChild(Controller.KNOWLEDGE_MODEL), (Model) s.getChild(Signal.OBJECT));

        } else {

            throw new Exception("Could not control signal. The signal is null.");
        }
    }

    /**
     * Processes a signal.
     *
     * @param a the action
     * @param dm the knowledge model
     * @exception Exception if the processor is null
     */
    private void process(String a, KnowledgeModel dm) throws Exception {

        Processor p = (Processor) getChild(Controller.PROCESSOR);

        if (p != null) {

            p.process(a, dm);

        } else {

            throw new Exception("Could not process model. The processor is null.");
        }
    }
}

