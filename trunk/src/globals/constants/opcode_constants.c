/*
 * $RCSfile: opcode_constants.c,v $
 *
 * Copyright (c) 1999-2006. Christian Heller and the CYBOP developers.
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
 * @version $Revision: 1.2 $ $Date: 2006-04-20 22:36:10 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef OPCODE_CONSTANTS_SOURCE
#define OPCODE_CONSTANTS_SOURCE

#include "../../globals/constants/integer_constants.c"

//
// Opcodes.
//

/** The nop abstraction array. */
//??static char NOP_MODEL_ARRAY[] = {'n', 'o', 'p'};

/** The nop model. */
//??static char* NOP_MODEL = NOP_MODEL_ARRAY;

/** The nop abstraction count. */
//??static int NOP_MODEL_COUNT = 3;

/*??
//
// Pushing constants.
//

static char _MODEL[] = {'aconst_null'};
static char _MODEL[] = {'iconst_m1'};
static char _MODEL[] = {'iconst_0'};
static char _MODEL[] = {'iconst_1'};
static char _MODEL[] = {'iconst_2'};
static char _MODEL[] = {'iconst_3'};
static char _MODEL[] = {'iconst_4'};
static char _MODEL[] = {'iconst_5'};
static char _MODEL[] = {'lconst_0'};
static char _MODEL[] = {'lconst_1'}; // 10
static char _MODEL[] = {'fconst_0'};
static char _MODEL[] = {'fconst_1'};
static char _MODEL[] = {'fconst_2'};
static char _MODEL[] = {'dconst_0'};
static char _MODEL[] = {'dconst_1'};
static char _MODEL[] = {'bipush'};
static char _MODEL[] = {'sipush'};
static char _MODEL[] = {'ldc'}; //or ldc
static char _MODEL[] = {'ldc_w'}; //or ldc_w was ldc2
static char _MODEL[] = {'ldc2_w'};//or ldc2_w was ldc2w // 20

//
// Loading local variables.
//

static char _MODEL[] = {'iload'};
static char _MODEL[] = {'lload'};
static char _MODEL[] = {'fload'};
static char _MODEL[] = {'dload'};
static char _MODEL[] = {'aload'};
static char _MODEL[] = {'iload_0'};
static char _MODEL[] = {'iload_1'};
static char _MODEL[] = {'iload_2'};
static char _MODEL[] = {'iload_3'};
static char _MODEL[] = {'lload_0'}; // 30
static char _MODEL[] = {'lload_1'};
static char _MODEL[] = {'lload_2'};
static char _MODEL[] = {'lload_3'};
static char _MODEL[] = {'fload_0'};
static char _MODEL[] = {'fload_1'};
static char _MODEL[] = {'fload_2'};
static char _MODEL[] = {'fload_3'};
static char _MODEL[] = {'dload_0'};
static char _MODEL[] = {'dload_1'};
static char _MODEL[] = {'dload_2'}; // 40
static char _MODEL[] = {'dload_3'};
static char _MODEL[] = {'aload_0'};
static char _MODEL[] = {'aload_1'};
static char _MODEL[] = {'aload_2'};
static char _MODEL[] = {'aload_3'};

//
// Loading array elements.
//

static char _MODEL[] = {'iaload'};
static char _MODEL[] = {'laload'};
static char _MODEL[] = {'faload'};
static char _MODEL[] = {'daload'};
static char _MODEL[] = {'aaload'}; // 50
static char _MODEL[] = {'baload'};
static char _MODEL[] = {'caload'};
static char _MODEL[] = {'saload'};

//
// Storing to local variables.
//

static char _MODEL[] = {'istore'};
static char _MODEL[] = {'lstore'};
static char _MODEL[] = {'fstore'};
static char _MODEL[] = {'dstore'};
static char _MODEL[] = {'astore'};
static char _MODEL[] = {'istore_0'};
static char _MODEL[] = {'istore_1'}; // 60
static char _MODEL[] = {'istore_2'};
static char _MODEL[] = {'istore_3'};
static char _MODEL[] = {'lstore_0'};
static char _MODEL[] = {'lstore_1'};
static char _MODEL[] = {'lstore_2'};
static char _MODEL[] = {'lstore_3'};
static char _MODEL[] = {'fstore_0'};
static char _MODEL[] = {'fstore_1'};
static char _MODEL[] = {'fstore_2'};
static char _MODEL[] = {'fstore_3'}; // 70
static char _MODEL[] = {'dstore_0'};
static char _MODEL[] = {'dstore_1'};
static char _MODEL[] = {'dstore_2'};
static char _MODEL[] = {'dstore_3'};
static char _MODEL[] = {'astore_0'};
static char _MODEL[] = {'astore_1'};
static char _MODEL[] = {'astore_2'};
static char _MODEL[] = {'astore_3'};

//
// Storing to array elements.
//

static char _MODEL[] = {'iastore'};
static char _MODEL[] = {'lastore'}; // 80
static char _MODEL[] = {'fastore'};
static char _MODEL[] = {'dastore'};
static char _MODEL[] = {'aastore'};
static char _MODEL[] = {'bastore'};
static char _MODEL[] = {'castore'};
static char _MODEL[] = {'sastore'};

//
// Stack instructions.
//

static char _MODEL[] = {'pop'};
static char _MODEL[] = {'pop2'};
static char _MODEL[] = {'dup_'};
static char _MODEL[] = {'dup_x1'}; // 90
static char _MODEL[] = {'dup_x2'};
static char _MODEL[] = {'dup2_'};
static char _MODEL[] = {'dup2_x1'};
static char _MODEL[] = {'dup2_x2'};
static char _MODEL[] = {'swap'};

//
// Arithmetic instructions.
//

static char _MODEL[] = {'iadd'};
static char _MODEL[] = {'ladd'};
static char _MODEL[] = {'fadd'};
static char _MODEL[] = {'dadd'};
static char _MODEL[] = {'isub'}; // 100
static char _MODEL[] = {'lsub'};
static char _MODEL[] = {'fsub'};
static char _MODEL[] = {'dsub'};
static char _MODEL[] = {'imul'};
static char _MODEL[] = {'lmul'};
static char _MODEL[] = {'fmul'};
static char _MODEL[] = {'dmul'};
static char _MODEL[] = {'idiv'};
static char _MODEL[] = {'ldiv_'};
static char _MODEL[] = {'fdiv'}; // 110
static char _MODEL[] = {'ddiv'};
static char _MODEL[] = {'imod'};
static char _MODEL[] = {'lmod'};
static char _MODEL[] = {'fmod_'};
static char _MODEL[] = {'dmod'};
static char _MODEL[] = {'ineg'};
static char _MODEL[] = {'lneg'};
static char _MODEL[] = {'fneg'};
static char _MODEL[] = {'dneg'};

//
// Logical instructions.
//

static char _MODEL[] = {'ishl'}; // 120
static char _MODEL[] = {'lshl'};
static char _MODEL[] = {'ishr'};
static char _MODEL[] = {'lshr'};
static char _MODEL[] = {'iushr'};
static char _MODEL[] = {'lushr'};
static char _MODEL[] = {'iand'};
static char _MODEL[] = {'land'};
static char _MODEL[] = {'ior'};
static char _MODEL[] = {'lor'};
static char _MODEL[] = {'ixor'}; // 130
static char _MODEL[] = {'lxor'};

//
// Increment.
//

static char _MODEL[] = {'iinc'};

//
// Conversion operations.
//

static char _MODEL[] = {'i2l'}; // 133 here ... was 132 in spec
static char _MODEL[] = {'i2f'}; // 134 here... was 133 in spec
static char _MODEL[] = {'i2d'}; // 135 here... was 134 in spec
static char _MODEL[] = {'l2i'};
static char _MODEL[] = {'l2f'};
static char _MODEL[] = {'l2d'};
static char _MODEL[] = {'f2i'};
static char _MODEL[] = {'f2l'}; // 140
static char _MODEL[] = {'f2d'};
static char _MODEL[] = {'d2i'};
static char _MODEL[] = {'d2l'};
static char _MODEL[] = {'d2f'};
static char _MODEL[] = {'int2byte'};
static char _MODEL[] = {'int2char'};
static char _MODEL[] = {'int2short'};

//
// Comparison instructions.
//

static char _MODEL[] = {'lcmp'};
static char _MODEL[] = {'fcmpl'};
static char _MODEL[] = {'fcmpg'}; // 150
static char _MODEL[] = {'dcmpl'};
static char _MODEL[] = {'dcmpg'};

//
// Branch instructions.
//

static char _MODEL[] = {'ifeq'};
static char _MODEL[] = {'ifne'};
static char _MODEL[] = {'iflt'};
static char _MODEL[] = {'ifge'};
static char _MODEL[] = {'ifgt'};
static char _MODEL[] = {'ifle'};
static char _MODEL[] = {'if_icmpeq'};
static char _MODEL[] = {'if_icmpne'}; // 160
static char _MODEL[] = {'if_icmplt'};
static char _MODEL[] = {'if_icmpge'};
static char _MODEL[] = {'if_icmpgt'};
static char _MODEL[] = {'if_icmple'};
static char _MODEL[] = {'if_acmpeq'};
static char _MODEL[] = {'if_acmpne'};
static char _MODEL[] = {'goto_'};
static char _MODEL[] = {'jsr'};
static char _MODEL[] = {'ret'};

//
// Table jumping.
//

static char _MODEL[] = {'tableswitch'}; // 170
static char _MODEL[] = {'lookupswitch'};

//
// Function return.
//

static char _MODEL[] = {'ireturn'};
static char _MODEL[] = {'lreturn'};
static char _MODEL[] = {'freturn'};
static char _MODEL[] = {'dreturn'};
static char _MODEL[] = {'areturn'};
static char _MODEL[] = {'return_'};

//
// Manipulating object fields.
//

static char _MODEL[] = {'getstatic'};
static char _MODEL[] = {'putstatic'};
static char _MODEL[] = {'getfield'}; // 180
static char _MODEL[] = {'putfield'};

//
// Method invocation.
//

static char _MODEL[] = {'invokevirtual'};
static char _MODEL[] = {'invokespecial'}; // was nonvirtual
static char _MODEL[] = {'invokestatic'};
static char _MODEL[] = {'invokeinterface'};

//
// Miscellaneous object operations.
//

static char _MODEL[] = {'newfromname'};
static char _MODEL[] = {'new_'};
static char _MODEL[] = {'newarray'};
static char _MODEL[] = {'anewarray'};
static char _MODEL[] = {'arraylength'}; // 190
static char _MODEL[] = {'athrow'};
static char _MODEL[] = {'checkcast'};
static char _MODEL[] = {'instanceof'};

//
// Monitors.
//

static char _MODEL[] = {'monitorenter'};
static char _MODEL[] = {'monitorexit'};

//
// Debugging.
//

static char _MODEL[] = {'verifystack'};
// breakpoint;
// breakpoint is in the documentation; but the compiler does not use it
// ... multianewarray moves up one place to take breakpoint's place

//
// More arrays.
//

static char _MODEL[] = {'multianewarray'};

//
// Undocumented java class stuff.
//

static char _MODEL[] = {'ifnull'};
static char _MODEL[] = {'ifnonnull'};

//
// Optimisations.
//

static char _MODEL[] = {'ldc1_quick'}; // 200
static char _MODEL[] = {'ldc2_quick'};
static char _MODEL[] = {'ldc2w_quick'};

static char _MODEL[] = {'getfield_quick'};
static char _MODEL[] = {'putfield_quick'};
static char _MODEL[] = {'getfield2_quick'};
static char _MODEL[] = {'putfield2_quick'};

//
// Short-cuts for when the current class is not the same as the static field's class.
//

static char _MODEL[] = {'getstatic_quick'};
static char _MODEL[] = {'putstatic_quick'};
static char _MODEL[] = {'getstatic2_quick'};
static char _MODEL[] = {'putstatic2_quick'}; // 210

static char _MODEL[] = {'invokevirtual_quick'};
static char _MODEL[] = {'invokespecial_quick'}; // was nonvirtual
static char _MODEL[] = {'invokestatic_quick'};
static char _MODEL[] = {'invokeinterface_quick'};
static char _MODEL[] = {'invokevirtualobject_quick'}; //?? I can't understand this!

static char _MODEL[] = {'new_quick'};
static char _MODEL[] = {'anewarray_quick'};
static char _MODEL[] = {'checkcast_quick'};
static char _MODEL[] = {'instanceof_quick'};

//
// Shortcuts for when the current class is the same as the static field's class.
//

static char _MODEL[] = {'putstaticcurrclass_quick'}; // 220
static char _MODEL[] = {'putstatic2currclass_quick'};
static char _MODEL[] = {'getstaticcurrclass_quick'};
static char _MODEL[] = {'getstatic2currclass_quick'};

static char _MODEL[] = {'invokenonvirtualcurrclass_quick'};
static char _MODEL[] = {'invokestaticcurrclass_quick'};

//
// Used for preloaded classes in ROM because we can't overwrite the operand with a guess.
//

static char _MODEL[] = {'invokeinterface_noguess'}; // +- 226

//
// Special instructions to invoke optimised methods.
//

static char _MODEL[] = {'invokevirtual_quick_optimised'};
*/

/* OPCODE_CONSTANTS_SOURCE */
#endif
