/*
 * $RCSfile: Dynamics.java,v $
 *
 * Copyright (c) 1999-2003. Christian Heller. All rights reserved.
 *
 * This software is published under the GPL GNU General Public License.
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License; or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful;
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not; write to the Free Software
 * Foundation; Inc.; 59 Temple Place - Suite 330; Boston; MA  02111-1307; USA.
 *
 * http://www.cybop.net
 * - Cybernetics Oriented Programming -
 */

package cyboi;

/**
 * This is the dynamics.
 *
 * It contains all dynamic operation sequences.
 *
 * @version $Revision: 1.6 $ $Date: 2003-08-10 22:34:31 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
class Dynamics {

    //
    // Category.
    //
    
    /** The category. */
    static java.lang.String CATEGORY = "category";

/*??
    //
    // Nop opcode.
    //
    
    static java.lang.String NOP = "nop";
    
    //
    // Pushing constants.
    //
    
    static java.lang.String CATEGORY = "aconst_null";
    static java.lang.String CATEGORY = "iconst_m1";
    static java.lang.String CATEGORY = "iconst_0";
    static java.lang.String CATEGORY = "iconst_1";
    static java.lang.String CATEGORY = "iconst_2";
    static java.lang.String CATEGORY = "iconst_3";
    static java.lang.String CATEGORY = "iconst_4";
    static java.lang.String CATEGORY = "iconst_5";
    static java.lang.String CATEGORY = "lconst_0";
    static java.lang.String CATEGORY = "lconst_1"; // 10
    static java.lang.String CATEGORY = "fconst_0";
    static java.lang.String CATEGORY = "fconst_1";
    static java.lang.String CATEGORY = "fconst_2";
    static java.lang.String CATEGORY = "dconst_0";
    static java.lang.String CATEGORY = "dconst_1";
    static java.lang.String CATEGORY = "bipush";
    static java.lang.String CATEGORY = "sipush";
    static java.lang.String CATEGORY = "ldc"; //or ldc
    static java.lang.String CATEGORY = "ldc_w"; //or ldc_w was ldc2
    static java.lang.String CATEGORY = "ldc2_w";//or ldc2_w was ldc2w // 20
    
    //
    // Loading local variables.
    //
    
    static java.lang.String CATEGORY = "iload";
    static java.lang.String CATEGORY = "lload";
    static java.lang.String CATEGORY = "fload";
    static java.lang.String CATEGORY = "dload";
    static java.lang.String CATEGORY = "aload";
    static java.lang.String CATEGORY = "iload_0";
    static java.lang.String CATEGORY = "iload_1";
    static java.lang.String CATEGORY = "iload_2";
    static java.lang.String CATEGORY = "iload_3";
    static java.lang.String CATEGORY = "lload_0"; // 30
    static java.lang.String CATEGORY = "lload_1";
    static java.lang.String CATEGORY = "lload_2";
    static java.lang.String CATEGORY = "lload_3";
    static java.lang.String CATEGORY = "fload_0";
    static java.lang.String CATEGORY = "fload_1";
    static java.lang.String CATEGORY = "fload_2";
    static java.lang.String CATEGORY = "fload_3";
    static java.lang.String CATEGORY = "dload_0";
    static java.lang.String CATEGORY = "dload_1";
    static java.lang.String CATEGORY = "dload_2"; // 40
    static java.lang.String CATEGORY = "dload_3";
    static java.lang.String CATEGORY = "aload_0";
    static java.lang.String CATEGORY = "aload_1";
    static java.lang.String CATEGORY = "aload_2";
    static java.lang.String CATEGORY = "aload_3";
    
    //
    // Loading array elements.
    //
    
    static java.lang.String CATEGORY = "iaload";
    static java.lang.String CATEGORY = "laload";
    static java.lang.String CATEGORY = "faload";
    static java.lang.String CATEGORY = "daload";
    static java.lang.String CATEGORY = "aaload"; // 50
    static java.lang.String CATEGORY = "baload";
    static java.lang.String CATEGORY = "caload";
    static java.lang.String CATEGORY = "saload";
    
    //
    // Storing to local variables.
    //
    
    static java.lang.String CATEGORY = "istore";
    static java.lang.String CATEGORY = "lstore";
    static java.lang.String CATEGORY = "fstore";
    static java.lang.String CATEGORY = "dstore";
    static java.lang.String CATEGORY = "astore";
    static java.lang.String CATEGORY = "istore_0";
    static java.lang.String CATEGORY = "istore_1"; // 60
    static java.lang.String CATEGORY = "istore_2";
    static java.lang.String CATEGORY = "istore_3";
    static java.lang.String CATEGORY = "lstore_0";
    static java.lang.String CATEGORY = "lstore_1";
    static java.lang.String CATEGORY = "lstore_2";
    static java.lang.String CATEGORY = "lstore_3";
    static java.lang.String CATEGORY = "fstore_0";
    static java.lang.String CATEGORY = "fstore_1";
    static java.lang.String CATEGORY = "fstore_2";
    static java.lang.String CATEGORY = "fstore_3"; // 70
    static java.lang.String CATEGORY = "dstore_0";
    static java.lang.String CATEGORY = "dstore_1";
    static java.lang.String CATEGORY = "dstore_2";
    static java.lang.String CATEGORY = "dstore_3";
    static java.lang.String CATEGORY = "astore_0";
    static java.lang.String CATEGORY = "astore_1";
    static java.lang.String CATEGORY = "astore_2";
    static java.lang.String CATEGORY = "astore_3";
    
    //
    // Storing to array elements.
    //
    
    static java.lang.String CATEGORY = "iastore";
    static java.lang.String CATEGORY = "lastore"; // 80
    static java.lang.String CATEGORY = "fastore";
    static java.lang.String CATEGORY = "dastore";
    static java.lang.String CATEGORY = "aastore";
    static java.lang.String CATEGORY = "bastore";
    static java.lang.String CATEGORY = "castore";
    static java.lang.String CATEGORY = "sastore";
    
    //
    // Stack instructions.
    //
    
    static java.lang.String CATEGORY = "pop";
    static java.lang.String CATEGORY = "pop2";
    static java.lang.String CATEGORY = "dup_";
    static java.lang.String CATEGORY = "dup_x1"; // 90
    static java.lang.String CATEGORY = "dup_x2";
    static java.lang.String CATEGORY = "dup2_";
    static java.lang.String CATEGORY = "dup2_x1";
    static java.lang.String CATEGORY = "dup2_x2";
    static java.lang.String CATEGORY = "swap";
    
    //
    // Arithmetic instructions.
    //
    
    static java.lang.String CATEGORY = "iadd";
    static java.lang.String CATEGORY = "ladd";
    static java.lang.String CATEGORY = "fadd";
    static java.lang.String CATEGORY = "dadd";
    static java.lang.String CATEGORY = "isub"; // 100
    static java.lang.String CATEGORY = "lsub";
    static java.lang.String CATEGORY = "fsub";
    static java.lang.String CATEGORY = "dsub";
    static java.lang.String CATEGORY = "imul";
    static java.lang.String CATEGORY = "lmul";
    static java.lang.String CATEGORY = "fmul";
    static java.lang.String CATEGORY = "dmul";
    static java.lang.String CATEGORY = "idiv";
    static java.lang.String CATEGORY = "ldiv_";
    static java.lang.String CATEGORY = "fdiv"; // 110
    static java.lang.String CATEGORY = "ddiv";
    static java.lang.String CATEGORY = "imod";
    static java.lang.String CATEGORY = "lmod";
    static java.lang.String CATEGORY = "fmod_";
    static java.lang.String CATEGORY = "dmod";
    static java.lang.String CATEGORY = "ineg";
    static java.lang.String CATEGORY = "lneg";
    static java.lang.String CATEGORY = "fneg";
    static java.lang.String CATEGORY = "dneg";
    
    //
    // Logical instructions.
    //
    
    static java.lang.String CATEGORY = "ishl"; // 120
    static java.lang.String CATEGORY = "lshl";
    static java.lang.String CATEGORY = "ishr";
    static java.lang.String CATEGORY = "lshr";
    static java.lang.String CATEGORY = "iushr";
    static java.lang.String CATEGORY = "lushr";
    static java.lang.String CATEGORY = "iand";
    static java.lang.String CATEGORY = "land";
    static java.lang.String CATEGORY = "ior";
    static java.lang.String CATEGORY = "lor";
    static java.lang.String CATEGORY = "ixor"; // 130
    static java.lang.String CATEGORY = "lxor";
    
    //
    // Increment.
    //
    
    static java.lang.String CATEGORY = "iinc";
    
    //
    // Conversion operations.
    //
    
    static java.lang.String CATEGORY = "i2l"; // 133 here ... was 132 in spec
    static java.lang.String CATEGORY = "i2f"; // 134 here... was 133 in spec
    static java.lang.String CATEGORY = "i2d"; // 135 here... was 134 in spec
    static java.lang.String CATEGORY = "l2i";
    static java.lang.String CATEGORY = "l2f";
    static java.lang.String CATEGORY = "l2d";
    static java.lang.String CATEGORY = "f2i";
    static java.lang.String CATEGORY = "f2l"; // 140
    static java.lang.String CATEGORY = "f2d";
    static java.lang.String CATEGORY = "d2i";
    static java.lang.String CATEGORY = "d2l";
    static java.lang.String CATEGORY = "d2f";
    static java.lang.String CATEGORY = "int2byte";
    static java.lang.String CATEGORY = "int2char";
    static java.lang.String CATEGORY = "int2short";
    
    //
    // Comparison instructions.
    //
    
    static java.lang.String CATEGORY = "lcmp";
    static java.lang.String CATEGORY = "fcmpl";
    static java.lang.String CATEGORY = "fcmpg"; // 150
    static java.lang.String CATEGORY = "dcmpl";
    static java.lang.String CATEGORY = "dcmpg";
    
    //
    // Branch instructions.
    //

    static java.lang.String CATEGORY = "ifeq";
    static java.lang.String CATEGORY = "ifne";
    static java.lang.String CATEGORY = "iflt";
    static java.lang.String CATEGORY = "ifge";
    static java.lang.String CATEGORY = "ifgt";
    static java.lang.String CATEGORY = "ifle";
    static java.lang.String CATEGORY = "if_icmpeq";
    static java.lang.String CATEGORY = "if_icmpne"; // 160
    static java.lang.String CATEGORY = "if_icmplt";
    static java.lang.String CATEGORY = "if_icmpge";
    static java.lang.String CATEGORY = "if_icmpgt";
    static java.lang.String CATEGORY = "if_icmple";
    static java.lang.String CATEGORY = "if_acmpeq";
    static java.lang.String CATEGORY = "if_acmpne";
    static java.lang.String CATEGORY = "goto_";
    static java.lang.String CATEGORY = "jsr";
    static java.lang.String CATEGORY = "ret";
    
    //
    // Table jumping.
    //
    
    static java.lang.String CATEGORY = "tableswitch"; // 170
    static java.lang.String CATEGORY = "lookupswitch";
    
    //
    // Function return.
    //
    
    static java.lang.String CATEGORY = "ireturn";
    static java.lang.String CATEGORY = "lreturn";
    static java.lang.String CATEGORY = "freturn";
    static java.lang.String CATEGORY = "dreturn";
    static java.lang.String CATEGORY = "areturn";
    static java.lang.String CATEGORY = "return_";
    
    //
    // Manipulating object fields.
    //
    
    static java.lang.String CATEGORY = "getstatic";
    static java.lang.String CATEGORY = "putstatic";
    static java.lang.String CATEGORY = "getfield"; // 180
    static java.lang.String CATEGORY = "putfield";
    
    //
    // Method invocation.
    //
    
    static java.lang.String CATEGORY = "invokevirtual";
    static java.lang.String CATEGORY = "invokespecial"; // was nonvirtual
    static java.lang.String CATEGORY = "invokestatic";
    static java.lang.String CATEGORY = "invokeinterface";
    
    //
    // Miscellaneous object operations.
    //
    
    static java.lang.String CATEGORY = "newfromname";
    static java.lang.String CATEGORY = "new_";
    static java.lang.String CATEGORY = "newarray";
    static java.lang.String CATEGORY = "anewarray";
    static java.lang.String CATEGORY = "arraylength"; // 190
    static java.lang.String CATEGORY = "athrow";
    static java.lang.String CATEGORY = "checkcast";
    static java.lang.String CATEGORY = "instanceof";
    
    //
    // Monitors.
    //
    
    static java.lang.String CATEGORY = "monitorenter";
    static java.lang.String CATEGORY = "monitorexit";
    
    //
    // Debugging.
    //
    
    static java.lang.String CATEGORY = "verifystack";
    // breakpoint;
    // breakpoint is in the documentation; but the compiler does not use it
    // ... multianewarray moves up one place to take breakpoint's place
    
    //
    // More arrays.
    //
    
    static java.lang.String CATEGORY = "multianewarray";
    
    //
    // Undocumented java class stuff.
    //

    static java.lang.String CATEGORY = "ifnull";
    static java.lang.String CATEGORY = "ifnonnull";
    
    //
    // Optimisations.
    //

    static java.lang.String CATEGORY = "ldc1_quick"; // 200
    static java.lang.String CATEGORY = "ldc2_quick";
    static java.lang.String CATEGORY = "ldc2w_quick";
    
    static java.lang.String CATEGORY = "getfield_quick";
    static java.lang.String CATEGORY = "putfield_quick";
    static java.lang.String CATEGORY = "getfield2_quick";
    static java.lang.String CATEGORY = "putfield2_quick";
    
    //
    // Short-cuts for when the current class is not the same as the static field's class.
    //

    static java.lang.String CATEGORY = "getstatic_quick";
    static java.lang.String CATEGORY = "putstatic_quick";
    static java.lang.String CATEGORY = "getstatic2_quick";
    static java.lang.String CATEGORY = "putstatic2_quick"; // 210
    
    static java.lang.String CATEGORY = "invokevirtual_quick";
    static java.lang.String CATEGORY = "invokespecial_quick"; // was nonvirtual
    static java.lang.String CATEGORY = "invokestatic_quick";
    static java.lang.String CATEGORY = "invokeinterface_quick";
    static java.lang.String CATEGORY = "invokevirtualobject_quick"; //?? I can't understand this!
    
    static java.lang.String CATEGORY = "new_quick";
    static java.lang.String CATEGORY = "anewarray_quick";
    static java.lang.String CATEGORY = "checkcast_quick";
    static java.lang.String CATEGORY = "instanceof_quick";
    
    //
    // Shortcuts for when the current class is the same as the static field's class.
    //

    static java.lang.String CATEGORY = "putstaticcurrclass_quick"; // 220
    static java.lang.String CATEGORY = "putstatic2currclass_quick";
    static java.lang.String CATEGORY = "getstaticcurrclass_quick";
    static java.lang.String CATEGORY = "getstatic2currclass_quick";
    
    static java.lang.String CATEGORY = "invokenonvirtualcurrclass_quick";
    static java.lang.String CATEGORY = "invokestaticcurrclass_quick";
    
    //
    // Used for preloaded classes in ROM because we can't overwrite the operand with a guess.
    //

    static java.lang.String CATEGORY = "invokeinterface_noguess"; // +- 226
    
    //
    // Special instructions to invoke optimised methods.
    //

    static java.lang.String CATEGORY = "invokevirtual_quick_optimised";

    //
    // Actions.
    //

    /** The show system display action. */
    static java.lang.String SHOW_SYSTEM_DISPLAY_ACTION = "show_system_display_action";

    /** The hide system display action. */
    static java.lang.String HIDE_SYSTEM_DISPLAY_ACTION = "hide_system_display_action";

    /** The show system information display action. */
    static java.lang.String SHOW_SYSTEM_INFORMATION_DISPLAY_ACTION = "show_system_information_display_action";

    /** The hide system information display action. */
    static java.lang.String HIDE_SYSTEM_INFORMATION_DISPLAY_ACTION = "hide_system_information_display_action";

    /** The focus gained action. */
    static java.lang.String FOCUS_GAINED_ACTION = "focus_gained_action";

    /** The focus lost action. */
    static java.lang.String FOCUS_LOST_ACTION = "focus_lost_action";

    /** The mouse pressed action. */
    static java.lang.String MOUSE_PRESSED_ACTION = "mouse_pressed_action";

    /** The mouse released action. */
    static java.lang.String MOUSE_RELEASED_ACTION = "mouse_released_action";

    /** The mouse clicked action. */
    static java.lang.String MOUSE_CLICKED_ACTION = "mouse_clicked_action";

    /** The mouse entered action. */
    static java.lang.String MOUSE_ENTERED_ACTION = "mouse_entered_action";

    /** The mouse exited action. */
    static java.lang.String MOUSE_EXITED_ACTION = "mouse_exited_action";

    /** The mouse dragged action. */
    static java.lang.String MOUSE_DRAGGED_ACTION = "mouse_dragged_action";

    /** The mouse moved action. */
    static java.lang.String MOUSE_MOVED_ACTION = "mouse_moved_action";

    /** The mouse wheel action. */
    static java.lang.String MOUSE_WHEEL_ACTION = "mouse_wheel_action";

    /** The key typed action. */
    static java.lang.String KEY_TYPED_ACTION = "key_typed_action";

    /** The key released action. */
    static java.lang.String KEY_RELEASED_ACTION = "key_released_action";

    /** The key pressed action. */
    static java.lang.String KEY_PRESSED_ACTION = "key_pressed_action";

    /** The component resized action. */
    static java.lang.String COMPONENT_RESIZED_ACTION = "component_resized_action";

    /** The component moved action. */
    static java.lang.String COMPONENT_MOVED_ACTION = "component_moved_action";

    /** The component shown action. */
    static java.lang.String COMPONENT_SHOWN_ACTION = "component_shown_action";

    /** The component hidden action. */
    static java.lang.String COMPONENT_HIDDEN_ACTION = "component_hidden_action";

    /** The input method text changed action. */
    static java.lang.String INPUT_METHOD_TEXT_CHANGED_ACTION = "input_method_text_changed_action";

    /** The caret position changed action. */
    static java.lang.String CARET_POSITION_CHANGED_ACTION = "caret_position_changed_action";

    /** The hierarchy changed action. */
    static java.lang.String HIERARCHY_CHANGED_ACTION = "hierarchy_changed_action";

    /** The ancestor resized action. */
    static java.lang.String ANCESTOR_RESIZED_ACTION = "ancestor_resized_action";

    /** The ancestor moved action. */
    static java.lang.String ANCESTOR_MOVED_ACTION = "ancestor_moved_action";

//?? ==========================================

    /** The create system signal id. */
    static java.lang.String CREATE_SYSTEM_SIGNAL_ID = "create_system";

    /** The destroy system signal id. */
    static java.lang.String DESTROY_SYSTEM_SIGNAL_ID = "destroy_system";

    /** The cut signal id. */
    static java.lang.String CUT_SIGNAL_ID = "cut";

    /** The copy signal id. */
    static java.lang.String COPY_SIGNAL_ID = "copy";

    /** The paste signal id. */
    static java.lang.String PASTE_SIGNAL_ID = "paste";

    /** The configure key bindings signal id. */
    static java.lang.String CONFIGURE_KEY_BINDINGS_SIGNAL_ID = "configure_key_bindings";

    //
    // Launcher actions.
    //

    /** The startup system action. */
    static java.lang.String STARTUP_SYSTEM_ACTION = "startup_system_action";

    /** The shutdown system action. */
    static java.lang.String SHUTDOWN_SYSTEM_ACTION = "shutdown_system_action";

    /** The shutdown system across socket action. */
    static java.lang.String SHUTDOWN_SYSTEM_ACROSS_SOCKET_ACTION = "shutdown_system_across_socket_action";

    /** The start system action. */
    static java.lang.String START_SYSTEM_ACTION = "start_system_action";

    /** The stop system action. */
    static java.lang.String STOP_SYSTEM_ACTION = "stop_system_action";

    /** The restart system action. */
    static java.lang.String RESTART_SYSTEM_ACTION = "restart_system_action";

    /** The show help action. */
    static java.lang.String SHOW_HELP_ACTION = "show_help_action";

    //
    // Children names.
    //

    /** The show tool bar signal id. */
    static java.lang.String SHOW_TOOL_BAR_SIGNAL_ID = "show_tool_bar";

    /** The show status bar signal id. */
    static java.lang.String SHOW_STATUS_BAR_SIGNAL_ID = "show_status_bar";

    /** The configure menu bar signal id. */
    static java.lang.String CONFIGURE_MENU_BAR_SIGNAL_ID = "configure_menu_bar";

    /** The configure tool bar signal id. */
    static java.lang.String CONFIGURE_TOOL_BAR_SIGNAL_ID = "configure_tool_bar";

    /** The configure status bar signal id. */
    static java.lang.String CONFIGURE_STATUS_BAR_SIGNAL_ID = "configure_status_bar";

    /** The show help contents signal id. */
    static java.lang.String SHOW_HELP_CONTENTS_SIGNAL_ID = "show_help_contents";

    /** The report bug signal id. */
    static java.lang.String REPORT_BUG_SIGNAL_ID = "report_bug";

    /** The link to website signal id. */
    static java.lang.String LINK_TO_WEBSITE_SIGNAL_ID = "link_to_website";

    //
    // Portal system actions.
    //

    /** The show systems tree signal id. */
    static java.lang.String SHOW_SYSTEMS_TREE_SIGNAL_ID = "show_systems_tree";

    /** The configure systems tree signal id. */
    static java.lang.String CONFIGURE_SYSTEMS_TREE_SIGNAL_ID = "configure_systems_tree";

    /** The configure res medicinae signal id. */
    static java.lang.String CONFIGURE_RES_MEDICINAE_SIGNAL_ID = "configure_res_medicinae";

    /** The iconify all signal id. */
    static java.lang.String ICONIFY_ALL_SIGNAL_ID = "iconify_all";

    /** The close signal id. */
    static java.lang.String CLOSE_SIGNAL_ID = "close";

    /** The close all signal id. */
    static java.lang.String CLOSE_ALL_SIGNAL_ID = "close_all";

    /** The cascade signal id. */
    static java.lang.String CASCADE_SIGNAL_ID = "cascade";

    /** The tile vertically signal id. */
    static java.lang.String TILE_VERTICALLY_SIGNAL_ID = "tile_vertically";

    /** The tile horizontally signal id. */
    static java.lang.String TILE_HORIZONTALLY_SIGNAL_ID = "tile_horizontally";

    /** The set frame display signal id. */
    static java.lang.String SET_FRAME_DISPLAY_SIGNAL_ID = "set_frame_display";

    /** The set internal frame display signal id. */
    static java.lang.String SET_INTERNAL_FRAME_DISPLAY_SIGNAL_ID = "set_internal_frame_display";

    /** The set tab page display signal id. */
    static java.lang.String SET_TAB_PAGE_DISPLAY_SIGNAL_ID = "set_tab_page_display";
}

