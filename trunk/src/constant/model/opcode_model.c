/*
 * Copyright (C) 1999-2008. Christian Heller.
 *
 * This file is part of the Cybernetics Oriented Interpreter (CYBOI).
 *
 * CYBOI is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * CYBOI is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with CYBOI.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Cybernetics Oriented Programming (CYBOP) <http://www.cybop.org>
 * Christian Heller <christian.heller@tuxtax.de>
 *
 * @version $RCSfile: opcode_model.c,v $ $Revision: 1.1 $ $Date: 2008-09-03 22:04:00 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef OPCODE_MODEL_SOURCE
#define OPCODE_MODEL_SOURCE

#include "../../constant/model/memory/integer_model.c"

//
// Opcodes.
//

/** The nop abstraction array. */
//??static char NOP_MODEL_ARRAY[] = {L'n', L'o', L'p'};

/** The nop model. */
//??static char* NOP_MODEL = NOP_MODEL_ARRAY;

/** The nop abstraction count. */
//??static int NOP_MODEL_COUNT = 3;

/*??
//
// Pushing constants.
//

static char _MODEL[] = {L'aconst_null'};
static char _MODEL[] = {L'iconst_m1'};
static char _MODEL[] = {L'iconst_0'};
static char _MODEL[] = {L'iconst_1'};
static char _MODEL[] = {L'iconst_2'};
static char _MODEL[] = {L'iconst_3'};
static char _MODEL[] = {L'iconst_4'};
static char _MODEL[] = {L'iconst_5'};
static char _MODEL[] = {L'lconst_0'};
static char _MODEL[] = {L'lconst_1'}; // 10
static char _MODEL[] = {L'fconst_0'};
static char _MODEL[] = {L'fconst_1'};
static char _MODEL[] = {L'fconst_2'};
static char _MODEL[] = {L'dconst_0'};
static char _MODEL[] = {L'dconst_1'};
static char _MODEL[] = {L'bipush'};
static char _MODEL[] = {L'sipush'};
static char _MODEL[] = {L'ldc'}; //or ldc
static char _MODEL[] = {L'ldc_w'}; //or ldc_w was ldc2
static char _MODEL[] = {L'ldc2_w'};//or ldc2_w was ldc2w // 20

//
// Loading local variables.
//

static char _MODEL[] = {L'iload'};
static char _MODEL[] = {L'lload'};
static char _MODEL[] = {L'fload'};
static char _MODEL[] = {L'dload'};
static char _MODEL[] = {L'aload'};
static char _MODEL[] = {L'iload_0'};
static char _MODEL[] = {L'iload_1'};
static char _MODEL[] = {L'iload_2'};
static char _MODEL[] = {L'iload_3'};
static char _MODEL[] = {L'lload_0'}; // 30
static char _MODEL[] = {L'lload_1'};
static char _MODEL[] = {L'lload_2'};
static char _MODEL[] = {L'lload_3'};
static char _MODEL[] = {L'fload_0'};
static char _MODEL[] = {L'fload_1'};
static char _MODEL[] = {L'fload_2'};
static char _MODEL[] = {L'fload_3'};
static char _MODEL[] = {L'dload_0'};
static char _MODEL[] = {L'dload_1'};
static char _MODEL[] = {L'dload_2'}; // 40
static char _MODEL[] = {L'dload_3'};
static char _MODEL[] = {L'aload_0'};
static char _MODEL[] = {L'aload_1'};
static char _MODEL[] = {L'aload_2'};
static char _MODEL[] = {L'aload_3'};

//
// Loading array elements.
//

static char _MODEL[] = {L'iaload'};
static char _MODEL[] = {L'laload'};
static char _MODEL[] = {L'faload'};
static char _MODEL[] = {L'daload'};
static char _MODEL[] = {L'aaload'}; // 50
static char _MODEL[] = {L'baload'};
static char _MODEL[] = {L'caload'};
static char _MODEL[] = {L'saload'};

//
// Storing to local variables.
//

static char _MODEL[] = {L'istore'};
static char _MODEL[] = {L'lstore'};
static char _MODEL[] = {L'fstore'};
static char _MODEL[] = {L'dstore'};
static char _MODEL[] = {L'astore'};
static char _MODEL[] = {L'istore_0'};
static char _MODEL[] = {L'istore_1'}; // 60
static char _MODEL[] = {L'istore_2'};
static char _MODEL[] = {L'istore_3'};
static char _MODEL[] = {L'lstore_0'};
static char _MODEL[] = {L'lstore_1'};
static char _MODEL[] = {L'lstore_2'};
static char _MODEL[] = {L'lstore_3'};
static char _MODEL[] = {L'fstore_0'};
static char _MODEL[] = {L'fstore_1'};
static char _MODEL[] = {L'fstore_2'};
static char _MODEL[] = {L'fstore_3'}; // 70
static char _MODEL[] = {L'dstore_0'};
static char _MODEL[] = {L'dstore_1'};
static char _MODEL[] = {L'dstore_2'};
static char _MODEL[] = {L'dstore_3'};
static char _MODEL[] = {L'astore_0'};
static char _MODEL[] = {L'astore_1'};
static char _MODEL[] = {L'astore_2'};
static char _MODEL[] = {L'astore_3'};

//
// Storing to array elements.
//

static char _MODEL[] = {L'iastore'};
static char _MODEL[] = {L'lastore'}; // 80
static char _MODEL[] = {L'fastore'};
static char _MODEL[] = {L'dastore'};
static char _MODEL[] = {L'aastore'};
static char _MODEL[] = {L'bastore'};
static char _MODEL[] = {L'castore'};
static char _MODEL[] = {L'sastore'};

//
// Stack instructions.
//

static char _MODEL[] = {L'pop'};
static char _MODEL[] = {L'pop2'};
static char _MODEL[] = {L'dup_'};
static char _MODEL[] = {L'dup_x1'}; // 90
static char _MODEL[] = {L'dup_x2'};
static char _MODEL[] = {L'dup2_'};
static char _MODEL[] = {L'dup2_x1'};
static char _MODEL[] = {L'dup2_x2'};
static char _MODEL[] = {L'swap'};

//
// Arithmetic instructions.
//

static char _MODEL[] = {L'iadd'};
static char _MODEL[] = {L'ladd'};
static char _MODEL[] = {L'fadd'};
static char _MODEL[] = {L'dadd'};
static char _MODEL[] = {L'isub'}; // 100
static char _MODEL[] = {L'lsub'};
static char _MODEL[] = {L'fsub'};
static char _MODEL[] = {L'dsub'};
static char _MODEL[] = {L'imul'};
static char _MODEL[] = {L'lmul'};
static char _MODEL[] = {L'fmul'};
static char _MODEL[] = {L'dmul'};
static char _MODEL[] = {L'idiv'};
static char _MODEL[] = {L'ldiv_'};
static char _MODEL[] = {L'fdiv'}; // 110
static char _MODEL[] = {L'ddiv'};
static char _MODEL[] = {L'imod'};
static char _MODEL[] = {L'lmod'};
static char _MODEL[] = {L'fmod_'};
static char _MODEL[] = {L'dmod'};
static char _MODEL[] = {L'ineg'};
static char _MODEL[] = {L'lneg'};
static char _MODEL[] = {L'fneg'};
static char _MODEL[] = {L'dneg'};

//
// Logical instructions.
//

static char _MODEL[] = {L'ishl'}; // 120
static char _MODEL[] = {L'lshl'};
static char _MODEL[] = {L'ishr'};
static char _MODEL[] = {L'lshr'};
static char _MODEL[] = {L'iushr'};
static char _MODEL[] = {L'lushr'};
static char _MODEL[] = {L'iand'};
static char _MODEL[] = {L'land'};
static char _MODEL[] = {L'ior'};
static char _MODEL[] = {L'lor'};
static char _MODEL[] = {L'ixor'}; // 130
static char _MODEL[] = {L'lxor'};

//
// Increment.
//

static char _MODEL[] = {L'iinc'};

//
// Conversion operations.
//

static char _MODEL[] = {L'i2l'}; // 133 here ... was 132 in spec
static char _MODEL[] = {L'i2f'}; // 134 here... was 133 in spec
static char _MODEL[] = {L'i2d'}; // 135 here... was 134 in spec
static char _MODEL[] = {L'l2i'};
static char _MODEL[] = {L'l2f'};
static char _MODEL[] = {L'l2d'};
static char _MODEL[] = {L'f2i'};
static char _MODEL[] = {L'f2l'}; // 140
static char _MODEL[] = {L'f2d'};
static char _MODEL[] = {L'd2i'};
static char _MODEL[] = {L'd2l'};
static char _MODEL[] = {L'd2f'};
static char _MODEL[] = {L'int2byte'};
static char _MODEL[] = {L'int2char'};
static char _MODEL[] = {L'int2short'};

//
// Comparison instructions.
//

static char _MODEL[] = {L'lcmp'};
static char _MODEL[] = {L'fcmpl'};
static char _MODEL[] = {L'fcmpg'}; // 150
static char _MODEL[] = {L'dcmpl'};
static char _MODEL[] = {L'dcmpg'};

//
// Branch instructions.
//

static char _MODEL[] = {L'ifeq'};
static char _MODEL[] = {L'ifne'};
static char _MODEL[] = {L'iflt'};
static char _MODEL[] = {L'ifge'};
static char _MODEL[] = {L'ifgt'};
static char _MODEL[] = {L'ifle'};
static char _MODEL[] = {L'if_icmpeq'};
static char _MODEL[] = {L'if_icmpne'}; // 160
static char _MODEL[] = {L'if_icmplt'};
static char _MODEL[] = {L'if_icmpge'};
static char _MODEL[] = {L'if_icmpgt'};
static char _MODEL[] = {L'if_icmple'};
static char _MODEL[] = {L'if_acmpeq'};
static char _MODEL[] = {L'if_acmpne'};
static char _MODEL[] = {L'goto_'};
static char _MODEL[] = {L'jsr'};
static char _MODEL[] = {L'ret'};

//
// Table jumping.
//

static char _MODEL[] = {L'tableswitch'}; // 170
static char _MODEL[] = {L'lookupswitch'};

//
// Function return.
//

static char _MODEL[] = {L'ireturn'};
static char _MODEL[] = {L'lreturn'};
static char _MODEL[] = {L'freturn'};
static char _MODEL[] = {L'dreturn'};
static char _MODEL[] = {L'areturn'};
static char _MODEL[] = {L'return_'};

//
// Manipulating object fields.
//

static char _MODEL[] = {L'getstatic'};
static char _MODEL[] = {L'putstatic'};
static char _MODEL[] = {L'getfield'}; // 180
static char _MODEL[] = {L'putfield'};

//
// Method invocation.
//

static char _MODEL[] = {L'invokevirtual'};
static char _MODEL[] = {L'invokespecial'}; // was nonvirtual
static char _MODEL[] = {L'invokestatic'};
static char _MODEL[] = {L'invokeinterface'};

//
// Miscellaneous object operations.
//

static char _MODEL[] = {L'newfromname'};
static char _MODEL[] = {L'new_'};
static char _MODEL[] = {L'newarray'};
static char _MODEL[] = {L'anewarray'};
static char _MODEL[] = {L'arraylength'}; // 190
static char _MODEL[] = {L'athrow'};
static char _MODEL[] = {L'checkcast'};
static char _MODEL[] = {L'instanceof'};

//
// Monitors.
//

static char _MODEL[] = {L'monitorenter'};
static char _MODEL[] = {L'monitorexit'};

//
// Debugging.
//

static char _MODEL[] = {L'verifystack'};
// breakpoint;
// breakpoint is in the documentation; but the compiler does not use it
// ... multianewarray moves up one place to take breakpoint's place

//
// More arrays.
//

static char _MODEL[] = {L'multianewarray'};

//
// Undocumented java class stuff.
//

static char _MODEL[] = {L'ifnull'};
static char _MODEL[] = {L'ifnonnull'};

//
// Optimisations.
//

static char _MODEL[] = {L'ldc1_quick'}; // 200
static char _MODEL[] = {L'ldc2_quick'};
static char _MODEL[] = {L'ldc2w_quick'};

static char _MODEL[] = {L'getfield_quick'};
static char _MODEL[] = {L'putfield_quick'};
static char _MODEL[] = {L'getfield2_quick'};
static char _MODEL[] = {L'putfield2_quick'};

//
// Short-cuts for when the current class is not the same as the static field's class.
//

static char _MODEL[] = {L'getstatic_quick'};
static char _MODEL[] = {L'putstatic_quick'};
static char _MODEL[] = {L'getstatic2_quick'};
static char _MODEL[] = {L'putstatic2_quick'}; // 210

static char _MODEL[] = {L'invokevirtual_quick'};
static char _MODEL[] = {L'invokespecial_quick'}; // was nonvirtual
static char _MODEL[] = {L'invokestatic_quick'};
static char _MODEL[] = {L'invokeinterface_quick'};
static char _MODEL[] = {L'invokevirtualobject_quick'}; //?? I can't understand this!

static char _MODEL[] = {L'new_quick'};
static char _MODEL[] = {L'anewarray_quick'};
static char _MODEL[] = {L'checkcast_quick'};
static char _MODEL[] = {L'instanceof_quick'};

//
// Shortcuts for when the current class is the same as the static field's class.
//

static char _MODEL[] = {L'putstaticcurrclass_quick'}; // 220
static char _MODEL[] = {L'putstatic2currclass_quick'};
static char _MODEL[] = {L'getstaticcurrclass_quick'};
static char _MODEL[] = {L'getstatic2currclass_quick'};

static char _MODEL[] = {L'invokenonvirtualcurrclass_quick'};
static char _MODEL[] = {L'invokestaticcurrclass_quick'};

//
// Used for preloaded classes in ROM because we can't overwrite the operand with a guess.
//

static char _MODEL[] = {L'invokeinterface_noguess'}; // +- 226

//
// Special instructions to invoke optimised methods.
//

static char _MODEL[] = {L'invokevirtual_quick_optimised'};
*/

/* OPCODE_MODEL_SOURCE */
#endif
