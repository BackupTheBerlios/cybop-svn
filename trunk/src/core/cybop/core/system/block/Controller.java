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

import cybop.core.basic.*;
import cybop.core.basic.Boolean;
import cybop.core.basic.String;
import cybop.core.model.*;
import cybop.core.model.model.*;
import cybop.core.model.model.user.*;
import cybop.core.model.principle.*;
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
 * @version $Revision: 1.14 $ $Date: 2003-04-29 15:12:13 $ $Author: christian $
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
    // Default children categories.
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
    public Item getDefaultDomainModelCategory() {

        return null;
    }

    /**
     * Returns the default system user interface category.
     *
     * @return the default system user interface category
     */
    public Item getDefaultSystemUserInterfaceCategory() {

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
    // Configuration.
    //

    /**
     * Configures this controller.
     *
     * @exception NullPointerException if the configuration is null
     */
    public void configure() throws Exception, NullPointerException {

        super.configure();

        Configuration c = (Configuration) getChildItem(Controller.CONFIGURATION);

        if (c != null) {

            setChildCategory(Controller.PROCESSOR_CATEGORY, c.getChildItem(Controller.PROCESSOR_CATEGORY, getDefaultProcessorCategory()));
            setChildCategory(Controller.DOMAIN_MODEL_CATEGORY, c.getChildItem(Controller.DOMAIN_MODEL_CATEGORY, getDefaultDomainModelCategory()));
            setChildCategory(Controller.SYSTEM_USER_INTERFACE_CATEGORY, c.getChildItem(Controller.SYSTEM_USER_INTERFACE_CATEGORY, getDefaultSystemUserInterfaceCategory()));
            setChildCategory(Controller.MOUSE_MODEL_CATEGORY, c.getChildItem(Controller.MOUSE_MODEL_CATEGORY, getDefaultMouseModelCategory()));
            setChildCategory(Controller.SYSTEM_INFORMATION_USER_INTERFACE_CATEGORY, c.getChildItem(Controller.SYSTEM_INFORMATION_USER_INTERFACE_CATEGORY, getDefaultSystemInformationUserInterfaceCategory()));
            setChildCategory(Controller.SYSTEM_INFORMATION_USER_INTERFACE_TRANSLATOR_CATEGORY, c.getChildItem(Controller.SYSTEM_INFORMATION_USER_INTERFACE_TRANSLATOR_CATEGORY, getDefaultSystemInformationUserInterfaceTranslatorCategory()));
            setChildCategory(Controller.TUI_TRANSLATOR_CATEGORY, c.getChildItem(Controller.TUI_TRANSLATOR_CATEGORY, getDefaultTuiTranslatorCategory()));
            setChildCategory(Controller.GUI_TRANSLATOR_CATEGORY, c.getChildItem(Controller.GUI_TRANSLATOR_CATEGORY, getDefaultGuiTranslatorCategory()));
            setChildCategory(Controller.SOCKET_TRANSLATOR_CATEGORY, c.getChildItem(Controller.SOCKET_TRANSLATOR_CATEGORY, getDefaultSocketTranslatorCategory()));

        } else {

            java.lang.System.out.println("WARNING: Could not configure controller. The configuration is null.");
        }
    }

    /**
     * Deconfigures this controller.
     *
     * @exception NullPointerException if the configuration is null
     */
    public void deconfigure() throws Exception, NullPointerException {

        Configuration c = (Configuration) getChildItem(Controller.CONFIGURATION);

        if (c != null) {

            c.setChildItem(Controller.SOCKET_TRANSLATOR_CATEGORY, getChildCategory(Controller.SOCKET_TRANSLATOR_CATEGORY));
            removeChildCategory(Controller.SOCKET_TRANSLATOR_CATEGORY);

            c.setChildItem(Controller.GUI_TRANSLATOR_CATEGORY, getChildCategory(Controller.GUI_TRANSLATOR_CATEGORY));
            removeChildCategory(Controller.GUI_TRANSLATOR_CATEGORY);

            c.setChildItem(Controller.TUI_TRANSLATOR_CATEGORY, getChildCategory(Controller.TUI_TRANSLATOR_CATEGORY));
            removeChildCategory(Controller.TUI_TRANSLATOR_CATEGORY);

            c.setChildItem(Controller.SYSTEM_INFORMATION_USER_INTERFACE_TRANSLATOR_CATEGORY, getChildCategory(Controller.SYSTEM_INFORMATION_USER_INTERFACE_TRANSLATOR_CATEGORY));
            removeChildCategory(Controller.SYSTEM_INFORMATION_USER_INTERFACE_TRANSLATOR_CATEGORY);

            c.setChildItem(Controller.SYSTEM_INFORMATION_USER_INTERFACE_CATEGORY, getChildCategory(Controller.SYSTEM_INFORMATION_USER_INTERFACE_CATEGORY));
            removeChildCategory(Controller.SYSTEM_INFORMATION_USER_INTERFACE_CATEGORY);

            c.setChildItem(Controller.MOUSE_MODEL_CATEGORY, getChildCategory(Controller.MOUSE_MODEL_CATEGORY));
            removeChildCategory(Controller.MOUSE_MODEL_CATEGORY);

            c.setChildItem(Controller.SYSTEM_USER_INTERFACE_CATEGORY, getChildCategory(Controller.SYSTEM_USER_INTERFACE_CATEGORY));
            removeChildCategory(Controller.SYSTEM_USER_INTERFACE_CATEGORY);

            c.setChildItem(Controller.DOMAIN_MODEL_CATEGORY, getChildCategory(Controller.DOMAIN_MODEL_CATEGORY));
            removeChildCategory(Controller.DOMAIN_MODEL_CATEGORY);

            c.setChildItem(Controller.PROCESSOR_CATEGORY, getChildCategory(Controller.PROCESSOR_CATEGORY));
            removeChildCategory(Controller.PROCESSOR_CATEGORY);

        } else {

            java.lang.System.out.println("WARNING: Could not deconfigure controller. The configuration is null.");
        }

        super.deconfigure();
    }

    //
    // Initializable.
    //

    /**
     * Initializes this controller.
     */
    public void initialize() throws Exception {

        super.initialize();

        setChildItem(Controller.PROCESSOR, createChildItem((String) getChildCategory(Controller.PROCESSOR_CATEGORY)));
        setChildItem(Controller.DOMAIN_MODEL, createChildItem((String) getChildCategory(Controller.DOMAIN_MODEL_CATEGORY)));
        setChildItem(Controller.SYSTEM_USER_INTERFACE, createChildItem((String) getChildCategory(Controller.SYSTEM_USER_INTERFACE_CATEGORY)));
        setChildItem(Controller.MOUSE_MODEL, createChildItem((String) getChildCategory(Controller.MOUSE_MODEL_CATEGORY)));
        setChildItem(Controller.SYSTEM_INFORMATION_USER_INTERFACE, createChildItem((String) getChildCategory(Controller.SYSTEM_INFORMATION_USER_INTERFACE_CATEGORY)));
        setChildItem(Controller.SYSTEM_INFORMATION_USER_INTERFACE_TRANSLATOR, createChildItem((String) getChildCategory(Controller.SYSTEM_INFORMATION_USER_INTERFACE_TRANSLATOR_CATEGORY)));
        setChildItem(Controller.TUI_TRANSLATOR, createChildItem((String) getChildCategory(Controller.TUI_TRANSLATOR_CATEGORY)));
        setChildItem(Controller.GUI_TRANSLATOR, createChildItem((String) getChildCategory(Controller.GUI_TRANSLATOR_CATEGORY)));
        setChildItem(Controller.SOCKET_TRANSLATOR, createChildItem((String) getChildCategory(Controller.SOCKET_TRANSLATOR_CATEGORY)));
    }

    /**
     * Finalizes this controller.
     */
    public void finalizz() throws Exception {

        Item socketTranslator = getChildItem(Controller.SOCKET_TRANSLATOR);
        removeChildItem(Controller.SOCKET_TRANSLATOR);
        destroyChildItem((SocketTranslator) socketTranslator);

        Item guiTranslator = getChildItem(Controller.GUI_TRANSLATOR);
        removeChildItem(Controller.GUI_TRANSLATOR);
        destroyChildItem((Component) guiTranslator);

        Item tuiTranslator = (TuiTranslator) getChildItem(Controller.TUI_TRANSLATOR);
        removeChildItem(Controller.TUI_TRANSLATOR);
        destroyChildItem((TuiTranslator) tuiTranslator);

        Item systemInformationUserInterfaceTranslator = getChildItem(Controller.SYSTEM_INFORMATION_USER_INTERFACE_TRANSLATOR);
        removeChildItem(Controller.SYSTEM_INFORMATION_USER_INTERFACE_TRANSLATOR);
        destroyChildItem((SystemInformationUserInterfaceTranslator) systemInformationUserInterfaceTranslator);

        Item systemInformationUserInterface = getChildItem(Controller.SYSTEM_INFORMATION_USER_INTERFACE);
        removeChildItem(Controller.SYSTEM_INFORMATION_USER_INTERFACE);
        destroyChildItem((SystemInformationUserInterface) systemInformationUserInterface);

        Item mouseModel = getChildItem(Controller.MOUSE_MODEL);
        removeChildItem(Controller.MOUSE_MODEL);
        destroyChildItem((MouseModel) mouseModel);

        Item systemUserInterface = getChildItem(Controller.SYSTEM_USER_INTERFACE);
        removeChildItem(Controller.SYSTEM_USER_INTERFACE);
        destroyChildItem((SystemUserInterface) systemUserInterface);

        Item domainModel = getChildItem(Controller.DOMAIN_MODEL);
        removeChildItem(Controller.DOMAIN_MODEL);
        destroyChildItem((DomainModel) domainModel);

        Item processor = getChildItem(Controller.PROCESSOR);
        removeChildItem(Controller.PROCESSOR);
        destroyChildItem((Processor) processor);

        super.finalizz();
    }

    //
    // Controlling.
    //

    /**
     * Controls the signal.
     *
     * @param s the signal
     * @exception NullPointerException if the signal is null
     */
    public void control(Signal s) throws Exception, NullPointerException {

        if (s != null) {

            String a = (String) s.getChildItem(Signal.PREDICATE);

            if (a != null) {

                if (a.isEqualTo(Controller.SHOW_SYSTEM_USER_INTERFACE_ACTION)) {

                    log(Controller.INFO_LOG_LEVEL, "Show system user interface.");
                    showSystemUserInterface(s);
    
                } else if (a.isEqualTo(Controller.HIDE_SYSTEM_USER_INTERFACE_ACTION)) {
    
                    log(Controller.INFO_LOG_LEVEL, "Hide system user interface.");
                    hideSystemUserInterface(s);

                } else if (a.isEqualTo(Controller.SHOW_SYSTEM_INFORMATION_USER_INTERFACE_ACTION)) {

                    log(Controller.INFO_LOG_LEVEL, "Show system information user interface.");
                    showSystemInformationUserInterface(s);
    
                } else if (a.isEqualTo(Controller.HIDE_SYSTEM_INFORMATION_USER_INTERFACE_ACTION)) {

                    log(Controller.INFO_LOG_LEVEL, "Hide system information user interface.");
                    hideSystemInformationUserInterface(s);
    
                } else if (a.isEqualTo(Controller.MOUSE_CLICKED_ACTION)) {

                    log(Controller.INFO_LOG_LEVEL, "Mouse clicked.");
                    mouseClicked(s);
                }

            } else {

                throw new NullPointerException("Could not process action. The action is null.");
            }

        } else {

            throw new NullPointerException("Could not control signal. The signal is null.");
        }
    }

    /**
     * Shows the system user interface.
     *
     * @param s the signal
     * @exception NullPointerException if the signal is null
     */
    protected void showSystemUserInterface(Signal s) throws Exception, NullPointerException {

        if (s != null) {

            s.setChildItem(Signal.PRIORITY, Signal.NORMAL_PRIORITY);
            s.setChildItem(Signal.LANGUAGE, Signal.GUI_LANGUAGE);
            s.setChildItem(Signal.OBJECT, getChildItem(Controller.SYSTEM_USER_INTERFACE));

        } else {

            throw new NullPointerException("Could not show system user interface. The signal is null.");
        }
    }

    /**
     * Hides the system user interface.
     *
     * @param s the signal
     * @exception NullPointerException if the signal is null
     */
    protected void hideSystemUserInterface(Signal s) throws Exception, NullPointerException {

        if (s != null) {

            s.setChildItem(Signal.LANGUAGE, Signal.GUI_LANGUAGE);
            s.setChildItem(Signal.OBJECT, getChildItem(Controller.SYSTEM_USER_INTERFACE));

        } else {

            throw new NullPointerException("Could not hide system user interface. The signal is null.");
        }
    }

    /**
     * Shows the system information user interface.
     *
     * @param s the signal
     * @exception NullPointerException if the signal is null
     */
    protected void showSystemInformationUserInterface(Signal s) throws Exception, NullPointerException {

        if (s != null) {

            //??
            //?? SystemInformation does not belong into the domain model!!
            //?? Create an own model for meta information about systems!
            //??

            SystemInformationUserInterfaceTranslator t = (SystemInformationUserInterfaceTranslator) getChildItem(Controller.SYSTEM_INFORMATION_USER_INTERFACE_TRANSLATOR);

            if (t != null) {

                // Write system information into user interface.
                t.encode((DomainModel) getChildItem(Controller.DOMAIN_MODEL), (Model) getChildItem(Controller.SYSTEM_INFORMATION_USER_INTERFACE));

            } else {

                throw new NullPointerException("Could not show system information user interface. The translator is null.");
            }

            s.setChildItem(Signal.LANGUAGE, Signal.GUI_LANGUAGE);
            s.setChildItem(Signal.OBJECT, getChildItem(Controller.SYSTEM_INFORMATION_USER_INTERFACE));

        } else {

            throw new NullPointerException("Could not show system information user interface. The signal is null.");
        }
    }

    /**
     * Hides the system information user interface.
     *
     * @param s the signal
     * @exception NullPointerException if the signal is null
     */
    protected void hideSystemInformationUserInterface(Signal s) throws Exception, NullPointerException {

        if (s != null) {

            s.setChildItem(Signal.LANGUAGE, Signal.GUI_LANGUAGE);
            s.setChildItem(Signal.OBJECT, getChildItem(Controller.SYSTEM_INFORMATION_USER_INTERFACE));

        } else {

            throw new NullPointerException("Could not hide system information user interface. The signal is null.");
        }
    }

    /**
     * Reacts on mouse clicked action.
     *
     * @param s the signal
     * @exception NullPointerException if the signal is null
     */
    protected void mouseClicked(Signal s) throws Exception, NullPointerException {

        java.lang.System.out.println("\n\n\n\n\n mouseClicked \n\n\n\n\n");

        if (s != null) {

            MouseModel m = (MouseModel) s.getChildItem(Signal.OBJECT);

            if (m != null) {

                // Language.
                s.setChildItem(Signal.LANGUAGE, Signal.NEURO_LANGUAGE);

                Item i = getItem((Space) m.getChildItem(MouseModel.POINTER_POSITION));

                if (i != null) {

                    // Subject.
                    // Determine the system which belongs to the clicked window.
                    //?? s.setChildItem(Signal.SUBJECT, system belonging to the clicked window);
    
                    // Predicate.
                    String a = (String) i.getChildItem(Item.ACTION);

                    s.setChildItem(Signal.PREDICATE, a);

                    // Sender object.
                    // Determine the active console to identify the user.
                    //?? s.setChildItem(Signal.SENDER_OBJECT, USER);

                } else {

                    throw new NullPointerException("Could not react on mouse clicked action. The graphic item is null.");
                }

            } else {
    
                throw new NullPointerException("Could not react on mouse clicked action. The mouse model is null.");
            }

        } else {

            throw new NullPointerException("Could not react on mouse clicked action. The signal is null.");
        }
    }

    /**
     * Returns the item at the given position.
     *
     * @param p the position
     * @return the item
     * @exception NullPointerException if the system user interface is null
     */
    protected Item getItem(Space p) throws Exception, NullPointerException {

        Item i = null;
        SystemUserInterface c = (SystemUserInterface) getChildItem(Controller.SYSTEM_USER_INTERFACE);

        if (c != null) {

            i = c.getChildItem(p);

        } else {

            throw new NullPointerException("Could not get item. The system user interface is null.");
        }

        return i;
    }

    /**
     * Controls the signal as server dummy.
     *
     * @param s the signal
     * @exception NullPointerException if the signal is null
     */
    public void controlAsServerDummy(Signal s) throws Exception, NullPointerException {

        if (s != null) {

/*??
            encode((String) s.getChildItem(Signal.LANGUAGE), (DomainModel) getChildItem(Controller.DOMAIN_MODEL), (Model) s.getChildItem(Signal.OBJECT));
            process((String) s.getChildItem(Signal.PREDICATE), (Model) s.getChildItem(Signal.OBJECT));
            decode((String) s.getChildItem(Signal.LANGUAGE), (Model) s.getChildItem(Signal.OBJECT), (DomainModel) getChildItem(Controller.DOMAIN_MODEL));
*/

//??            process((String) s.getChildItem(Signal.PREDICATE), (DomainModel) getChildItem(Controller.DOMAIN_MODEL));
//??            encode((String) s.getChildItem(Signal.LANGUAGE), (DomainModel) getChildItem(Controller.DOMAIN_MODEL), (Model) s.getChildItem(Signal.OBJECT));

        } else {

            throw new NullPointerException("Could not control signal. The signal is null.");
        }
    }

    /**
     * Processes a signal.
     *
     * @param a the action
     * @param dm the domain model
     * @exception NullPointerException if the processor is null
     */
    private void process(String a, DomainModel dm) throws Exception, NullPointerException {

        Processor p = (Processor) getChildItem(Controller.PROCESSOR);

        if (p != null) {

            p.process(a, dm);

        } else {

            throw new NullPointerException("Could not process model. The processor is null.");
        }
    }
}

