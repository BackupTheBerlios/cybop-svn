/*
 * $RCSfile: model_constants.c,v $
 *
 * Copyright (c) 1999-2005. Christian Heller and the CYBOP developers.
 *
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
 *
 * @version $Revision: 1.3 $ $Date: 2005-06-29 23:59:10 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef MODEL_CONSTANTS_SOURCE
#define MODEL_CONSTANTS_SOURCE

//
// Boolean models.
//

/** The false model. */
static const char FALSE_MODEL_ARRAY[] = {'f', 'a', 'l', 's', 'e'};
static const char* FALSE_MODEL = FALSE_MODEL_ARRAY;
static const int FALSE_MODEL_COUNT_ARRAY[] = {5};
static const int* FALSE_MODEL_COUNT = FALSE_MODEL_COUNT_ARRAY;

/** The true model. */
static const char TRUE_MODEL_ARRAY[] = {'t', 'r', 'u', 'e'};
static const char* TRUE_MODEL = TRUE_MODEL_ARRAY;
static const int TRUE_MODEL_COUNT_ARRAY[] = {4};
static const int* TRUE_MODEL_COUNT = TRUE_MODEL_COUNT_ARRAY;

//
// Program flow models.
//

/** The copy (set, assign) model. */
static const char COPY_MODEL_ARRAY[] = {'c', 'o', 'p', 'y'};
static const char* COPY_MODEL = COPY_MODEL_ARRAY;
static const int COPY_MODEL_COUNT_ARRAY[] = {4};
static const int* COPY_MODEL_COUNT = COPY_MODEL_COUNT_ARRAY;

/** The move model. */
static const char MOVE_MODEL_ARRAY[] = {'m', 'o', 'v', 'e'};
static const char* MOVE_MODEL = MOVE_MODEL_ARRAY;
static const int MOVE_MODEL_COUNT_ARRAY[] = {4};
static const int* MOVE_MODEL_COUNT = MOVE_MODEL_COUNT_ARRAY;

/** The copy property model. */
static const char COPY_PROPERTY_MODEL_ARRAY[] = {'c', 'o', 'p', 'y', '_', 'p', 'r', 'o', 'p', 'e', 'r', 't', 'y'};
static const char* COPY_PROPERTY_MODEL = COPY_PROPERTY_MODEL_ARRAY;
static const int COPY_PROPERTY_MODEL_COUNT_ARRAY[] = {13};
static const int* COPY_PROPERTY_MODEL_COUNT = COPY_PROPERTY_MODEL_COUNT_ARRAY;

/** The move property model. */
static const char MOVE_PROPERTY_MODEL_ARRAY[] = {'m', 'o', 'v', 'e', '_', 'p', 'r', 'o', 'p', 'e', 'r', 't', 'y'};
static const char* MOVE_PROPERTY_MODEL = MOVE_PROPERTY_MODEL_ARRAY;
static const int MOVE_PROPERTY_MODEL_COUNT_ARRAY[] = {13};
static const int* MOVE_PROPERTY_MODEL_COUNT = MOVE_PROPERTY_MODEL_COUNT_ARRAY;

/** The branch model. */
static const char BRANCH_MODEL_ARRAY[] = {'b', 'r', 'a', 'n', 'c', 'h'};
static const char* BRANCH_MODEL = BRANCH_MODEL_ARRAY;
static const int BRANCH_MODEL_COUNT_ARRAY[] = {6};
static const int* BRANCH_MODEL_COUNT = BRANCH_MODEL_COUNT_ARRAY;

/** The loop model. */
static const char LOOP_MODEL_ARRAY[] = {'l', 'o', 'o', 'p'};
static const char* LOOP_MODEL = LOOP_MODEL_ARRAY;
static const int LOOP_MODEL_COUNT_ARRAY[] = {4};
static const int* LOOP_MODEL_COUNT = LOOP_MODEL_COUNT_ARRAY;

/** The count parts model. */
static const char COUNT_PARTS_MODEL_ARRAY[] = {'c', 'o', 'u', 'n', 't', '_', 'p', 'a', 'r', 't', 's'};
static const char* COUNT_PARTS_MODEL = COUNT_PARTS_MODEL_ARRAY;
static const int COUNT_PARTS_MODEL_COUNT_ARRAY[] = {11};
static const int* COUNT_PARTS_MODEL_COUNT = COUNT_PARTS_MODEL_COUNT_ARRAY;

/** The build listname model. */
static const char BUILD_LISTNAME_MODEL_ARRAY[] = {'b', 'u', 'i', 'l', 'd', '_', 'l', 'i', 's', 't', 'n', 'a', 'm', 'e'};
static const char* BUILD_LISTNAME_MODEL = BUILD_LISTNAME_MODEL_ARRAY;
static const int BUILD_LISTNAME_MODEL_COUNT_ARRAY[] = {14};
static const int* BUILD_LISTNAME_MODEL_COUNT = BUILD_LISTNAME_MODEL_COUNT_ARRAY;

//
// Boolean logic models.
//

/** The and model. */
static const char AND_MODEL_ARRAY[] = {'a', 'n', 'd'};
static const char* AND_MODEL = AND_MODEL_ARRAY;
static const int AND_MODEL_COUNT_ARRAY[] = {3};
static const int* AND_MODEL_COUNT = AND_MODEL_COUNT_ARRAY;

/** The or model. */
static const char OR_MODEL_ARRAY[] = {'o', 'r'};
static const char* OR_MODEL = OR_MODEL_ARRAY;
static const int OR_MODEL_COUNT_ARRAY[] = {2};
static const int* OR_MODEL_COUNT = OR_MODEL_COUNT_ARRAY;

//
// Comparison models.
//

/** The compare model. */
static const char COMPARE_MODEL_ARRAY[] = {'c', 'o', 'm', 'p', 'a', 'r', 'e'};
static const char* COMPARE_MODEL = COMPARE_MODEL_ARRAY;
static const int COMPARE_MODEL_COUNT_ARRAY[] = {7};
static const int* COMPARE_MODEL_COUNT = COMPARE_MODEL_COUNT_ARRAY;

/** The equal model. */
static const char EQUAL_MODEL_ARRAY[] = {'e', 'q', 'u', 'a', 'l'};
static const char* EQUAL_MODEL = EQUAL_MODEL_ARRAY;
static const int EQUAL_MODEL_COUNT_ARRAY[] = {5};
static const int* EQUAL_MODEL_COUNT = EQUAL_MODEL_COUNT_ARRAY;

/** The smaller model. */
static const char SMALLER_MODEL_ARRAY[] = {'s', 'm', 'a', 'l', 'l', 'e', 'r'};
static const char* SMALLER_MODEL = SMALLER_MODEL_ARRAY;
static const int SMALLER_MODEL_COUNT_ARRAY[] = {7};
static const int* SMALLER_MODEL_COUNT = SMALLER_MODEL_COUNT_ARRAY;

/** The greater model. */
static const char GREATER_MODEL_ARRAY[] = {'g', 'r', 'e', 'a', 't', 'e', 'r'};
static const char* GREATER_MODEL = GREATER_MODEL_ARRAY;
static const int GREATER_MODEL_COUNT_ARRAY[] = {7};
static const int* GREATER_MODEL_COUNT = GREATER_MODEL_COUNT_ARRAY;

/** The smaller or equal model. */
static const char SMALLER_OR_EQUAL_MODEL_ARRAY[] = {'s', 'm', 'a', 'l', 'l', 'e', 'r', '_', 'o', 'r', '_', 'e', 'q', 'u', 'a', 'l'};
static const char* SMALLER_OR_EQUAL_MODEL = SMALLER_OR_EQUAL_MODEL_ARRAY;
static const int SMALLER_OR_EQUAL_MODEL_COUNT_ARRAY[] = {16};
static const int* SMALLER_OR_EQUAL_MODEL_COUNT = SMALLER_OR_EQUAL_MODEL_COUNT_ARRAY;

/** The greater or equal model. */
static const char GREATER_OR_EQUAL_MODEL_ARRAY[] = {'g', 'r', 'e', 'a', 't', 'e', 'r', '_', 'o', 'r', '_', 'e', 'q', 'u', 'a', 'l'};
static const char* GREATER_OR_EQUAL_MODEL = GREATER_OR_EQUAL_MODEL_ARRAY;
static const int GREATER_OR_EQUAL_MODEL_COUNT_ARRAY[] = {16};
static const int* GREATER_OR_EQUAL_MODEL_COUNT = GREATER_OR_EQUAL_MODEL_COUNT_ARRAY;

//
// Arithmetic models.
//

/** The add model. */
static const char ADD_MODEL_ARRAY[] = {'a', 'd', 'd'};
static const char* ADD_MODEL = ADD_MODEL_ARRAY;
static const int ADD_MODEL_COUNT_ARRAY[] = {3};
static const int* ADD_MODEL_COUNT = ADD_MODEL_COUNT_ARRAY;

/** The subtract model. */
static const char SUBTRACT_MODEL_ARRAY[] = {'s', 'u', 'b', 't', 'r', 'a', 'c', 't'};
static const char* SUBTRACT_MODEL = SUBTRACT_MODEL_ARRAY;
static const int SUBTRACT_MODEL_COUNT_ARRAY[] = {8};
static const int* SUBTRACT_MODEL_COUNT = SUBTRACT_MODEL_COUNT_ARRAY;

/** The multiply model. */
static const char MULTIPLY_MODEL_ARRAY[] = {'m', 'u', 'l', 't', 'i', 'p', 'l', 'y'};
static const char* MULTIPLY_MODEL = MULTIPLY_MODEL_ARRAY;
static const int MULTIPLY_MODEL_COUNT_ARRAY[] = {8};
static const int* MULTIPLY_MODEL_COUNT = MULTIPLY_MODEL_COUNT_ARRAY;

/** The divide model. */
static const char DIVIDE_MODEL_ARRAY[] = {'d', 'i', 'v', 'i', 'd', 'e'};
static const char* DIVIDE_MODEL = DIVIDE_MODEL_ARRAY;
static const int DIVIDE_MODEL_COUNT_ARRAY[] = {6};
static const int* DIVIDE_MODEL_COUNT = DIVIDE_MODEL_COUNT_ARRAY;

//
// Memory management models.
//

/** The create part model. */
static const char CREATE_PART_MODEL_ARRAY[] = {'c', 'r', 'e', 'a', 't', 'e', '_', 'p', 'a', 'r', 't'};
static const char* CREATE_PART_MODEL = CREATE_PART_MODEL_ARRAY;
static const int CREATE_PART_MODEL_COUNT_ARRAY[] = {11};
static const int* CREATE_PART_MODEL_COUNT = CREATE_PART_MODEL_COUNT_ARRAY;

/** The destroy part model. */
static const char DESTROY_PART_MODEL_ARRAY[] = {'d', 'e', 's', 't', 'r', 'o', 'y', '_', 'p', 'a', 'r', 't'};
static const char* DESTROY_PART_MODEL = DESTROY_PART_MODEL_ARRAY;
static const int DESTROY_PART_MODEL_COUNT_ARRAY[] = {12};
static const int* DESTROY_PART_MODEL_COUNT = DESTROY_PART_MODEL_COUNT_ARRAY;

//
// Lifecycle models.
//

/** The startup model. */
static const char STARTUP_MODEL_ARRAY[] = {'s', 't', 'a', 'r', 't', 'u', 'p'};
static const char* STARTUP_MODEL = STARTUP_MODEL_ARRAY;
static const int STARTUP_MODEL_COUNT_ARRAY[] = {7};
static const int* STARTUP_MODEL_COUNT = STARTUP_MODEL_COUNT_ARRAY;

/** The shutdown model. */
static const char SHUTDOWN_MODEL_ARRAY[] = {'s', 'h', 'u', 't', 'd', 'o', 'w', 'n'};
static const char* SHUTDOWN_MODEL = SHUTDOWN_MODEL_ARRAY;
static const int SHUTDOWN_MODEL_COUNT_ARRAY[] = {8};
static const int* SHUTDOWN_MODEL_COUNT = SHUTDOWN_MODEL_COUNT_ARRAY;

/** The exit model. */
static const char EXIT_MODEL_ARRAY[] = {'e', 'x', 'i', 't'};
static const char* EXIT_MODEL = EXIT_MODEL_ARRAY;
static const int EXIT_MODEL_COUNT_ARRAY[] = {4};
static const int* EXIT_MODEL_COUNT = EXIT_MODEL_COUNT_ARRAY;

//
// Communication models.
//

/** The send model. */
static const char SEND_MODEL_ARRAY[] = {'s', 'e', 'n', 'd'};
static const char* SEND_MODEL = SEND_MODEL_ARRAY;
static const int SEND_MODEL_COUNT_ARRAY[] = {4};
static const int* SEND_MODEL_COUNT = SEND_MODEL_COUNT_ARRAY;

/** The receive model. */
static const char RECEIVE_MODEL_ARRAY[] = {'r', 'e', 'c', 'e', 'i', 'v', 'e'};
static const char* RECEIVE_MODEL = RECEIVE_MODEL_ARRAY;
static const int RECEIVE_MODEL_COUNT_ARRAY[] = {7};
static const int* RECEIVE_MODEL_COUNT = RECEIVE_MODEL_COUNT_ARRAY;

/** The interrupt model. */
static const char INTERRUPT_MODEL_ARRAY[] = {'i', 'n', 't', 'e', 'r', 'r', 'u', 'p', 't'};
static const char* INTERRUPT_MODEL = INTERRUPT_MODEL_ARRAY;
static const int INTERRUPT_MODEL_COUNT_ARRAY[] = {9};
static const int* INTERRUPT_MODEL_COUNT = INTERRUPT_MODEL_COUNT_ARRAY;

/** The refresh url model. */
static const char REFRESH_URL_MODEL_ARRAY[] = {'r', 'e', 'f', 'r', 'e', 's', 'h', '_', 'u', 'r', 'l'};
static const char* REFRESH_URL_MODEL = REFRESH_URL_MODEL_ARRAY;
static const int REFRESH_URL_MODEL_COUNT_ARRAY[] = {11};
static const int* REFRESH_URL_MODEL_COUNT = REFRESH_URL_MODEL_COUNT_ARRAY;

//
// Language models.
//

/** The textual user interface (tui) model. */
static const char TUI_MODEL_ARRAY[] = {'t', 'u', 'i'};
static const char* TUI_MODEL = TUI_MODEL_ARRAY;
static const int TUI_MODEL_COUNT_ARRAY[] = {3};
static const int* TUI_MODEL_COUNT = TUI_MODEL_COUNT_ARRAY;

/** The graphical user interface (gui) model. */
static const char GUI_MODEL_ARRAY[] = {'g', 'u', 'i'};
static const char* GUI_MODEL = GUI_MODEL_ARRAY;
static const int GUI_MODEL_COUNT_ARRAY[] = {3};
static const int* GUI_MODEL_COUNT = GUI_MODEL_COUNT_ARRAY;

/** The web user interface (wui) model. */
static const char WUI_MODEL_ARRAY[] = {'w', 'u', 'i'};
static const char* WUI_MODEL = WUI_MODEL_ARRAY;
static const int WUI_MODEL_COUNT_ARRAY[] = {3};
static const int* WUI_MODEL_COUNT = WUI_MODEL_COUNT_ARRAY;

/** The x window system model. */
static const char X_WINDOW_SYSTEM_MODEL_ARRAY[] = {'x', '_', 'w', 'i', 'n', 'd', 'o', 'w', '_', 's', 'y', 's', 't', 'e', 'm'};
static const char* X_WINDOW_SYSTEM_MODEL = X_WINDOW_SYSTEM_MODEL_ARRAY;
static const int X_WINDOW_SYSTEM_MODEL_COUNT_ARRAY[] = {15};
static const int* X_WINDOW_SYSTEM_MODEL_COUNT = X_WINDOW_SYSTEM_MODEL_COUNT_ARRAY;

/** The unix socket model. */
static const char UNIX_SOCKET_MODEL_ARRAY[] = {'u', 'n', 'i', 'x', '_', 's', 'o', 'c', 'k', 'e', 't'};
static const char* UNIX_SOCKET_MODEL = UNIX_SOCKET_MODEL_ARRAY;
static const int UNIX_SOCKET_MODEL_COUNT_ARRAY[] = {11};
static const int* UNIX_SOCKET_MODEL_COUNT = UNIX_SOCKET_MODEL_COUNT_ARRAY;

/** The tcp socket model. */
static const char TCP_SOCKET_MODEL_ARRAY[] = {'t', 'c', 'p', '_', 's', 'o', 'c', 'k', 'e', 't'};
static const char* TCP_SOCKET_MODEL = TCP_SOCKET_MODEL_ARRAY;
static const int TCP_SOCKET_MODEL_COUNT_ARRAY[] = {10};
static const int* TCP_SOCKET_MODEL_COUNT = TCP_SOCKET_MODEL_COUNT_ARRAY;

/** The signal model. */
static const char SIGNAL_MODEL_ARRAY[] = {'s', 'i', 'g', 'n', 'a', 'l'};
static const char* SIGNAL_MODEL = SIGNAL_MODEL_ARRAY;
static const int SIGNAL_MODEL_COUNT_ARRAY[] = {6};
static const int* SIGNAL_MODEL_COUNT = SIGNAL_MODEL_COUNT_ARRAY;

/** The mouse model. */
static const char MOUSE_MODEL_ARRAY[] = {'m', 'o', 'u', 's', 'e'};
static const char* MOUSE_MODEL = MOUSE_MODEL_ARRAY;
static const int MOUSE_MODEL_COUNT_ARRAY[] = {5};
static const int* MOUSE_MODEL_COUNT = MOUSE_MODEL_COUNT_ARRAY;

/** The structured query language (sql). */
static const char SQL_MODEL_ARRAY[] = {'s', 'q', 'l'};
static const char* SQL_MODEL = SQL_MODEL_ARRAY;
static const int SQL_MODEL_COUNT_ARRAY[] = {3};
static const int* SQL_MODEL_COUNT = SQL_MODEL_COUNT_ARRAY;

//
//
// Opcodes.
//

/** The nop abstraction array. */
//??static const char NOP_MODEL_ARRAY[] = {'n', 'o', 'p'};

/** The nop model. */
//??static const char* NOP_MODEL = NOP_MODEL_ARRAY;

/** The nop abstraction count. */
//??static const int NOP_MODEL_COUNT = 3;

/*??
//
// Pushing constants.
//

static const char _MODEL[] = {'aconst_null'};
static const char _MODEL[] = {'iconst_m1'};
static const char _MODEL[] = {'iconst_0'};
static const char _MODEL[] = {'iconst_1'};
static const char _MODEL[] = {'iconst_2'};
static const char _MODEL[] = {'iconst_3'};
static const char _MODEL[] = {'iconst_4'};
static const char _MODEL[] = {'iconst_5'};
static const char _MODEL[] = {'lconst_0'};
static const char _MODEL[] = {'lconst_1'}; // 10
static const char _MODEL[] = {'fconst_0'};
static const char _MODEL[] = {'fconst_1'};
static const char _MODEL[] = {'fconst_2'};
static const char _MODEL[] = {'dconst_0'};
static const char _MODEL[] = {'dconst_1'};
static const char _MODEL[] = {'bipush'};
static const char _MODEL[] = {'sipush'};
static const char _MODEL[] = {'ldc'}; //or ldc
static const char _MODEL[] = {'ldc_w'}; //or ldc_w was ldc2
static const char _MODEL[] = {'ldc2_w'};//or ldc2_w was ldc2w // 20

//
// Loading local variables.
//

static const char _MODEL[] = {'iload'};
static const char _MODEL[] = {'lload'};
static const char _MODEL[] = {'fload'};
static const char _MODEL[] = {'dload'};
static const char _MODEL[] = {'aload'};
static const char _MODEL[] = {'iload_0'};
static const char _MODEL[] = {'iload_1'};
static const char _MODEL[] = {'iload_2'};
static const char _MODEL[] = {'iload_3'};
static const char _MODEL[] = {'lload_0'}; // 30
static const char _MODEL[] = {'lload_1'};
static const char _MODEL[] = {'lload_2'};
static const char _MODEL[] = {'lload_3'};
static const char _MODEL[] = {'fload_0'};
static const char _MODEL[] = {'fload_1'};
static const char _MODEL[] = {'fload_2'};
static const char _MODEL[] = {'fload_3'};
static const char _MODEL[] = {'dload_0'};
static const char _MODEL[] = {'dload_1'};
static const char _MODEL[] = {'dload_2'}; // 40
static const char _MODEL[] = {'dload_3'};
static const char _MODEL[] = {'aload_0'};
static const char _MODEL[] = {'aload_1'};
static const char _MODEL[] = {'aload_2'};
static const char _MODEL[] = {'aload_3'};

//
// Loading array elements.
//

static const char _MODEL[] = {'iaload'};
static const char _MODEL[] = {'laload'};
static const char _MODEL[] = {'faload'};
static const char _MODEL[] = {'daload'};
static const char _MODEL[] = {'aaload'}; // 50
static const char _MODEL[] = {'baload'};
static const char _MODEL[] = {'caload'};
static const char _MODEL[] = {'saload'};

//
// Storing to local variables.
//

static const char _MODEL[] = {'istore'};
static const char _MODEL[] = {'lstore'};
static const char _MODEL[] = {'fstore'};
static const char _MODEL[] = {'dstore'};
static const char _MODEL[] = {'astore'};
static const char _MODEL[] = {'istore_0'};
static const char _MODEL[] = {'istore_1'}; // 60
static const char _MODEL[] = {'istore_2'};
static const char _MODEL[] = {'istore_3'};
static const char _MODEL[] = {'lstore_0'};
static const char _MODEL[] = {'lstore_1'};
static const char _MODEL[] = {'lstore_2'};
static const char _MODEL[] = {'lstore_3'};
static const char _MODEL[] = {'fstore_0'};
static const char _MODEL[] = {'fstore_1'};
static const char _MODEL[] = {'fstore_2'};
static const char _MODEL[] = {'fstore_3'}; // 70
static const char _MODEL[] = {'dstore_0'};
static const char _MODEL[] = {'dstore_1'};
static const char _MODEL[] = {'dstore_2'};
static const char _MODEL[] = {'dstore_3'};
static const char _MODEL[] = {'astore_0'};
static const char _MODEL[] = {'astore_1'};
static const char _MODEL[] = {'astore_2'};
static const char _MODEL[] = {'astore_3'};

//
// Storing to array elements.
//

static const char _MODEL[] = {'iastore'};
static const char _MODEL[] = {'lastore'}; // 80
static const char _MODEL[] = {'fastore'};
static const char _MODEL[] = {'dastore'};
static const char _MODEL[] = {'aastore'};
static const char _MODEL[] = {'bastore'};
static const char _MODEL[] = {'castore'};
static const char _MODEL[] = {'sastore'};

//
// Stack instructions.
//

static const char _MODEL[] = {'pop'};
static const char _MODEL[] = {'pop2'};
static const char _MODEL[] = {'dup_'};
static const char _MODEL[] = {'dup_x1'}; // 90
static const char _MODEL[] = {'dup_x2'};
static const char _MODEL[] = {'dup2_'};
static const char _MODEL[] = {'dup2_x1'};
static const char _MODEL[] = {'dup2_x2'};
static const char _MODEL[] = {'swap'};

//
// Arithmetic instructions.
//

static const char _MODEL[] = {'iadd'};
static const char _MODEL[] = {'ladd'};
static const char _MODEL[] = {'fadd'};
static const char _MODEL[] = {'dadd'};
static const char _MODEL[] = {'isub'}; // 100
static const char _MODEL[] = {'lsub'};
static const char _MODEL[] = {'fsub'};
static const char _MODEL[] = {'dsub'};
static const char _MODEL[] = {'imul'};
static const char _MODEL[] = {'lmul'};
static const char _MODEL[] = {'fmul'};
static const char _MODEL[] = {'dmul'};
static const char _MODEL[] = {'idiv'};
static const char _MODEL[] = {'ldiv_'};
static const char _MODEL[] = {'fdiv'}; // 110
static const char _MODEL[] = {'ddiv'};
static const char _MODEL[] = {'imod'};
static const char _MODEL[] = {'lmod'};
static const char _MODEL[] = {'fmod_'};
static const char _MODEL[] = {'dmod'};
static const char _MODEL[] = {'ineg'};
static const char _MODEL[] = {'lneg'};
static const char _MODEL[] = {'fneg'};
static const char _MODEL[] = {'dneg'};

//
// Logical instructions.
//

static const char _MODEL[] = {'ishl'}; // 120
static const char _MODEL[] = {'lshl'};
static const char _MODEL[] = {'ishr'};
static const char _MODEL[] = {'lshr'};
static const char _MODEL[] = {'iushr'};
static const char _MODEL[] = {'lushr'};
static const char _MODEL[] = {'iand'};
static const char _MODEL[] = {'land'};
static const char _MODEL[] = {'ior'};
static const char _MODEL[] = {'lor'};
static const char _MODEL[] = {'ixor'}; // 130
static const char _MODEL[] = {'lxor'};

//
// Increment.
//

static const char _MODEL[] = {'iinc'};

//
// Conversion operations.
//

static const char _MODEL[] = {'i2l'}; // 133 here ... was 132 in spec
static const char _MODEL[] = {'i2f'}; // 134 here... was 133 in spec
static const char _MODEL[] = {'i2d'}; // 135 here... was 134 in spec
static const char _MODEL[] = {'l2i'};
static const char _MODEL[] = {'l2f'};
static const char _MODEL[] = {'l2d'};
static const char _MODEL[] = {'f2i'};
static const char _MODEL[] = {'f2l'}; // 140
static const char _MODEL[] = {'f2d'};
static const char _MODEL[] = {'d2i'};
static const char _MODEL[] = {'d2l'};
static const char _MODEL[] = {'d2f'};
static const char _MODEL[] = {'int2byte'};
static const char _MODEL[] = {'int2char'};
static const char _MODEL[] = {'int2short'};

//
// Comparison instructions.
//

static const char _MODEL[] = {'lcmp'};
static const char _MODEL[] = {'fcmpl'};
static const char _MODEL[] = {'fcmpg'}; // 150
static const char _MODEL[] = {'dcmpl'};
static const char _MODEL[] = {'dcmpg'};

//
// Branch instructions.
//

static const char _MODEL[] = {'ifeq'};
static const char _MODEL[] = {'ifne'};
static const char _MODEL[] = {'iflt'};
static const char _MODEL[] = {'ifge'};
static const char _MODEL[] = {'ifgt'};
static const char _MODEL[] = {'ifle'};
static const char _MODEL[] = {'if_icmpeq'};
static const char _MODEL[] = {'if_icmpne'}; // 160
static const char _MODEL[] = {'if_icmplt'};
static const char _MODEL[] = {'if_icmpge'};
static const char _MODEL[] = {'if_icmpgt'};
static const char _MODEL[] = {'if_icmple'};
static const char _MODEL[] = {'if_acmpeq'};
static const char _MODEL[] = {'if_acmpne'};
static const char _MODEL[] = {'goto_'};
static const char _MODEL[] = {'jsr'};
static const char _MODEL[] = {'ret'};

//
// Table jumping.
//

static const char _MODEL[] = {'tableswitch'}; // 170
static const char _MODEL[] = {'lookupswitch'};

//
// Function return.
//

static const char _MODEL[] = {'ireturn'};
static const char _MODEL[] = {'lreturn'};
static const char _MODEL[] = {'freturn'};
static const char _MODEL[] = {'dreturn'};
static const char _MODEL[] = {'areturn'};
static const char _MODEL[] = {'return_'};

//
// Manipulating object fields.
//

static const char _MODEL[] = {'getstatic'};
static const char _MODEL[] = {'putstatic'};
static const char _MODEL[] = {'getfield'}; // 180
static const char _MODEL[] = {'putfield'};

//
// Method invocation.
//

static const char _MODEL[] = {'invokevirtual'};
static const char _MODEL[] = {'invokespecial'}; // was nonvirtual
static const char _MODEL[] = {'invokestatic'};
static const char _MODEL[] = {'invokeinterface'};

//
// Miscellaneous object operations.
//

static const char _MODEL[] = {'newfromname'};
static const char _MODEL[] = {'new_'};
static const char _MODEL[] = {'newarray'};
static const char _MODEL[] = {'anewarray'};
static const char _MODEL[] = {'arraylength'}; // 190
static const char _MODEL[] = {'athrow'};
static const char _MODEL[] = {'checkcast'};
static const char _MODEL[] = {'instanceof'};

//
// Monitors.
//

static const char _MODEL[] = {'monitorenter'};
static const char _MODEL[] = {'monitorexit'};

//
// Debugging.
//

static const char _MODEL[] = {'verifystack'};
// breakpoint;
// breakpoint is in the documentation; but the compiler does not use it
// ... multianewarray moves up one place to take breakpoint's place

//
// More arrays.
//

static const char _MODEL[] = {'multianewarray'};

//
// Undocumented java class stuff.
//

static const char _MODEL[] = {'ifnull'};
static const char _MODEL[] = {'ifnonnull'};

//
// Optimisations.
//

static const char _MODEL[] = {'ldc1_quick'}; // 200
static const char _MODEL[] = {'ldc2_quick'};
static const char _MODEL[] = {'ldc2w_quick'};

static const char _MODEL[] = {'getfield_quick'};
static const char _MODEL[] = {'putfield_quick'};
static const char _MODEL[] = {'getfield2_quick'};
static const char _MODEL[] = {'putfield2_quick'};

//
// Short-cuts for when the current class is not the same as the static field's class.
//

static const char _MODEL[] = {'getstatic_quick'};
static const char _MODEL[] = {'putstatic_quick'};
static const char _MODEL[] = {'getstatic2_quick'};
static const char _MODEL[] = {'putstatic2_quick'}; // 210

static const char _MODEL[] = {'invokevirtual_quick'};
static const char _MODEL[] = {'invokespecial_quick'}; // was nonvirtual
static const char _MODEL[] = {'invokestatic_quick'};
static const char _MODEL[] = {'invokeinterface_quick'};
static const char _MODEL[] = {'invokevirtualobject_quick'}; //?? I can't understand this!

static const char _MODEL[] = {'new_quick'};
static const char _MODEL[] = {'anewarray_quick'};
static const char _MODEL[] = {'checkcast_quick'};
static const char _MODEL[] = {'instanceof_quick'};

//
// Shortcuts for when the current class is the same as the static field's class.
//

static const char _MODEL[] = {'putstaticcurrclass_quick'}; // 220
static const char _MODEL[] = {'putstatic2currclass_quick'};
static const char _MODEL[] = {'getstaticcurrclass_quick'};
static const char _MODEL[] = {'getstatic2currclass_quick'};

static const char _MODEL[] = {'invokenonvirtualcurrclass_quick'};
static const char _MODEL[] = {'invokestaticcurrclass_quick'};

//
// Used for preloaded classes in ROM because we can't overwrite the operand with a guess.
//

static const char _MODEL[] = {'invokeinterface_noguess'}; // +- 226

//
// Special instructions to invoke optimised methods.
//

static const char _MODEL[] = {'invokevirtual_quick_optimised'};
*/

/* MODEL_CONSTANTS_SOURCE */
#endif
