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
 * @version $Revision: 1.19 $ $Date: 2003-06-17 08:17:00 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class Controller extends Block {

    //
    // Children names.
    //

    /** The processor id. */
    public static final String PROCESSOR = new String("processor");

    /** The domain model. */
    public static final String DOMAIN_MODEL = new String("domain_model");

    /** The system user interface. */
    public static final String SYSTEM_USER_INTERFACE = new String("system_user_interface");

    /** The mouse model. */
    public static final String MOUSE_MODEL = new String("mouse_model");

    /** The system information user interface. */
    public static final String SYSTEM_INFORMATION_USER_INTERFACE = new String("system_information_user_interface");

    /** The system information user interface translator. */
    public static final String SYSTEM_INFORMATION_USER_INTERFACE_TRANSLATOR = new String("system_information_user_interface_translator");

//?? --- Move the following translators into some i/o class, to handle i/o devices (receive/send signal)!

    /** The textual user interface (tui) translator. */
    public static final String TUI_TRANSLATOR = new String("tui_translator");

    /** The graphical user interface (gui) translator. */
    public static final String GUI_TRANSLATOR = new String("gui_translator");

    /** The socket translator. */
    public static final String SOCKET_TRANSLATOR = new String("socket_translator");

    //
    // Children category names.
    //

    /** The processor category. */
    public static final String PROCESSOR_CATEGORY = new String("processor_category");

    /** The domain model category. */
    public static final String DOMAIN_MODEL_CATEGORY = new String("domain_model_category");

    /** The system user interface category. */
    public static final String SYSTEM_USER_INTERFACE_CATEGORY = new String("system_user_interface_category");

    /** The mouse model category. */
    public static final String MOUSE_MODEL_CATEGORY = new String("mouse_model_category");

    /** The system information user interface category. */
    public static final String SYSTEM_INFORMATION_USER_INTERFACE_CATEGORY = new String("system_information_user_interface_category");

    /** The system information user interface translator category. */
    public static final String SYSTEM_INFORMATION_USER_INTERFACE_TRANSLATOR_CATEGORY = new String("system_information_user_interface_translator_category");

    /** The tui translator category. */
    public static final String TUI_TRANSLATOR_CATEGORY = new String("tui_translator_category");

    /** The gui translator category. */
    public static final String GUI_TRANSLATOR_CATEGORY = new String("gui_translator_category");

    /** The socket translator category. */
    public static final String SOCKET_TRANSLATOR_CATEGORY = new String("socket_translator_category");

    //
    // Actions.
    //

    /** The show system user interface action. */
    public static final String SHOW_SYSTEM_USER_INTERFACE_ACTION = new String("show_system_user_interface_action");

    /** The hide system user interface action. */
    public static final String HIDE_SYSTEM_USER_INTERFACE_ACTION = new String("hide_system_user_interface_action");

    /** The show system information user interface action. */
    public static final String SHOW_SYSTEM_INFORMATION_USER_INTERFACE_ACTION = new String("show_system_information_user_interface_action");

    /** The hide system information user interface action. */
    public static final String HIDE_SYSTEM_INFORMATION_USER_INTERFACE_ACTION = new String("hide_system_information_user_interface_action");

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
     * Returns the default domain model category.
     *
     * @return the default domain model category
     */
    public Item getDefaultKnowledgeModelCategory() {

        return null;
    }

    /**
     * Returns the default system user interface category.
     *
     * @return the default system user interface category
     */
    public Item getDefaultScreenModelCategory() {

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
     * Returns the default system information user interface category.
     *
     * @return the default system information user interface category
     */
    public Item getDefaultSystemInformationUserInterfaceCategory() {

        return null;
    }

    /**
     * Returns the default system information user interface translator category.
     *
     * @return the default system information user interface translator category
     */
    public Item getDefaultSystemInformationUserInterfaceTranslatorCategory() {

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

        setCategory(Controller.PROCESSOR_CATEGORY, getDefaultProcessorCategory());
        setCategory(Controller.DOMAIN_MODEL_CATEGORY, getDefaultKnowledgeModelCategory());
        setCategory(Controller.SYSTEM_USER_INTERFACE_CATEGORY, getDefaultScreenModelCategory());
        setCategory(Controller.MOUSE_MODEL_CATEGORY, getDefaultMouseModelCategory());
        setCategory(Controller.SYSTEM_INFORMATION_USER_INTERFACE_CATEGORY, getDefaultSystemInformationUserInterfaceCategory());
        setCategory(Controller.SYSTEM_INFORMATION_USER_INTERFACE_TRANSLATOR_CATEGORY, getDefaultSystemInformationUserInterfaceTranslatorCategory());
        setCategory(Controller.TUI_TRANSLATOR_CATEGORY, getDefaultTuiTranslatorCategory());
        setCategory(Controller.GUI_TRANSLATOR_CATEGORY, getDefaultGuiTranslatorCategory());
        setCategory(Controller.SOCKET_TRANSLATOR_CATEGORY, getDefaultSocketTranslatorCategory());
    }

    /**
     * Decategorizes this hierarchy.
     */
    public void decategorize() throws Exception {

        removeCategory(Controller.SOCKET_TRANSLATOR_CATEGORY);
        removeCategory(Controller.GUI_TRANSLATOR_CATEGORY);
        removeCategory(Controller.TUI_TRANSLATOR_CATEGORY);
        removeCategory(Controller.SYSTEM_INFORMATION_USER_INTERFACE_TRANSLATOR_CATEGORY);
        removeCategory(Controller.SYSTEM_INFORMATION_USER_INTERFACE_CATEGORY);
        removeCategory(Controller.MOUSE_MODEL_CATEGORY);
        removeCategory(Controller.SYSTEM_USER_INTERFACE_CATEGORY);
        removeCategory(Controller.DOMAIN_MODEL_CATEGORY);
        removeCategory(Controller.PROCESSOR_CATEGORY);

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

        setChild(Controller.PROCESSOR, createChild(getCategory(Controller.PROCESSOR_CATEGORY)));
        setChild(Controller.DOMAIN_MODEL, createChild(getCategory(Controller.DOMAIN_MODEL_CATEGORY)));
        setChild(Controller.SYSTEM_USER_INTERFACE, createChild(getCategory(Controller.SYSTEM_USER_INTERFACE_CATEGORY)));
        setChild(Controller.MOUSE_MODEL, createChild(getCategory(Controller.MOUSE_MODEL_CATEGORY)));
        setChild(Controller.SYSTEM_INFORMATION_USER_INTERFACE, createChild(getCategory(Controller.SYSTEM_INFORMATION_USER_INTERFACE_CATEGORY)));
        setChild(Controller.SYSTEM_INFORMATION_USER_INTERFACE_TRANSLATOR, createChild(getCategory(Controller.SYSTEM_INFORMATION_USER_INTERFACE_TRANSLATOR_CATEGORY)));
        setChild(Controller.TUI_TRANSLATOR, createChild(getCategory(Controller.TUI_TRANSLATOR_CATEGORY)));
        setChild(Controller.GUI_TRANSLATOR, createChild(getCategory(Controller.GUI_TRANSLATOR_CATEGORY)));
        setChild(Controller.SOCKET_TRANSLATOR, createChild(getCategory(Controller.SOCKET_TRANSLATOR_CATEGORY)));
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

        Item systemInformationUserInterfaceTranslator = getChild(Controller.SYSTEM_INFORMATION_USER_INTERFACE_TRANSLATOR);
        removeChild(Controller.SYSTEM_INFORMATION_USER_INTERFACE_TRANSLATOR);
        destroyChild(systemInformationUserInterfaceTranslator);

        Item systemInformationUserInterface = getChild(Controller.SYSTEM_INFORMATION_USER_INTERFACE);
        removeChild(Controller.SYSTEM_INFORMATION_USER_INTERFACE);
        destroyChild(systemInformationUserInterface);

        Item mouseModel = getChild(Controller.MOUSE_MODEL);
        removeChild(Controller.MOUSE_MODEL);
        destroyChild(mouseModel);

        Item systemUserInterface = getChild(Controller.SYSTEM_USER_INTERFACE);
        removeChild(Controller.SYSTEM_USER_INTERFACE);
        destroyChild(systemUserInterface);

        Item domainModel = getChild(Controller.DOMAIN_MODEL);
        removeChild(Controller.DOMAIN_MODEL);
        destroyChild(domainModel);

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

                if (a.isEqualTo(Controller.SHOW_SYSTEM_USER_INTERFACE_ACTION)) {

                    showScreenModel(s);
    
                } else if (a.isEqualTo(Controller.HIDE_SYSTEM_USER_INTERFACE_ACTION)) {
    
                    hideScreenModel(s);

                } else if (a.isEqualTo(Controller.SHOW_SYSTEM_INFORMATION_USER_INTERFACE_ACTION)) {

                    showSystemInformationUserInterface(s);
    
                } else if (a.isEqualTo(Controller.HIDE_SYSTEM_INFORMATION_USER_INTERFACE_ACTION)) {

                    hideSystemInformationUserInterface(s);
    
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
     * Shows the system user interface.
     *
     * @param s the signal
     * @exception Exception if the signal is null
     */
    protected void showScreenModel(Signal s) throws Exception {

        if (s != null) {

            s.setChild(Signal.PRIORITY, Signal.NORMAL_PRIORITY);
            s.setChild(Signal.LANGUAGE, Signal.GUI_LANGUAGE);
            s.setChild(Signal.OBJECT, getChild(Controller.SYSTEM_USER_INTERFACE));

        } else {

            throw new Exception("Could not show system user interface. The signal is null.");
        }
    }

    /**
     * Hides the system user interface.
     *
     * @param s the signal
     * @exception Exception if the signal is null
     */
    protected void hideScreenModel(Signal s) throws Exception {

        if (s != null) {

            s.setChild(Signal.LANGUAGE, Signal.GUI_LANGUAGE);
            s.setChild(Signal.OBJECT, getChild(Controller.SYSTEM_USER_INTERFACE));

        } else {

            throw new Exception("Could not hide system user interface. The signal is null.");
        }
    }

    /**
     * Shows the system information user interface.
     *
     * @param s the signal
     * @exception Exception if the signal is null
     */
    protected void showSystemInformationUserInterface(Signal s) throws Exception {

        if (s != null) {

            //??
            //?? SystemInformation does not belong into the domain model!!
            //?? Create an own model for meta information about systems!
            //??

            SystemInformationUserInterfaceTranslator t = (SystemInformationUserInterfaceTranslator) getChild(Controller.SYSTEM_INFORMATION_USER_INTERFACE_TRANSLATOR);

            if (t != null) {

                // Write system information into user interface.
                t.encode((KnowledgeModel) getChild(Controller.DOMAIN_MODEL), (Model) getChild(Controller.SYSTEM_INFORMATION_USER_INTERFACE));

            } else {

                throw new Exception("Could not show system information user interface. The translator is null.");
            }

            s.setChild(Signal.LANGUAGE, Signal.GUI_LANGUAGE);
            s.setChild(Signal.OBJECT, getChild(Controller.SYSTEM_INFORMATION_USER_INTERFACE));

        } else {

            throw new Exception("Could not show system information user interface. The signal is null.");
        }
    }

    /**
     * Hides the system information user interface.
     *
     * @param s the signal
     * @exception Exception if the signal is null
     */
    protected void hideSystemInformationUserInterface(Signal s) throws Exception {

        if (s != null) {

            s.setChild(Signal.LANGUAGE, Signal.GUI_LANGUAGE);
            s.setChild(Signal.OBJECT, getChild(Controller.SYSTEM_INFORMATION_USER_INTERFACE));

        } else {

            throw new Exception("Could not hide system information user interface. The signal is null.");
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
                ScreenItem i = getItem((Space) m.getChild(MouseModel.POINTER_POSITION));

                if (i != null) {

                    // Subject.
                    // Determine the system which belongs to the clicked window.
                    //?? s.setChild(Signal.SUBJECT, system belonging to the clicked window);
    
                    // Predicate.
                    String a = (String) i.getChild(ScreenItem.ACTION);

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
     * @exception Exception if the system user interface is null
     */
    protected Item getItem(Space p) throws Exception {

        Item i = null;
        ScreenModel c = (ScreenModel) getChild(Controller.SYSTEM_USER_INTERFACE);

        if (c != null) {

            i = c.getChild(p);

        } else {

            throw new Exception("Could not get item. The system user interface is null.");
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
            encode((String) s.getChild(Signal.LANGUAGE), (KnowledgeModel) getChild(Controller.DOMAIN_MODEL), (Model) s.getChild(Signal.OBJECT));
            process((String) s.getChild(Signal.PREDICATE), (Model) s.getChild(Signal.OBJECT));
            decode((String) s.getChild(Signal.LANGUAGE), (Model) s.getChild(Signal.OBJECT), (KnowledgeModel) getChild(Controller.DOMAIN_MODEL));
*/

//??            process((String) s.getChild(Signal.PREDICATE), (KnowledgeModel) getChild(Controller.DOMAIN_MODEL));
//??            encode((String) s.getChild(Signal.LANGUAGE), (KnowledgeModel) getChild(Controller.DOMAIN_MODEL), (Model) s.getChild(Signal.OBJECT));

        } else {

            throw new Exception("Could not control signal. The signal is null.");
        }
    }

    /**
     * Processes a signal.
     *
     * @param a the action
     * @param dm the domain model
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

