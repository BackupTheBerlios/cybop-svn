/*
 * $RCSfile: dynamics_handler.c,v $
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

#ifndef DYNAMICS_HANDLER_SOURCE
#define DYNAMICS_HANDLER_SOURCE

#include "log_handler.c"

/**
 * This is the dynamics.
 *
 * It contains all dynamic operation sequences.
 *
 * @version $Revision: 1.3 $ $Date: 2003-10-06 00:06:55 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

//
// Complex model.
//

/** The complex model. */
//?? Already defined in statics_handler.c
//?? Do not define it again here!
//?? static const void* COMPLEX_MODEL = "complex";

//
// Boolean operations.
//

/**
 * Logical AND.
 *
 * @param p0 the first parameter
 * @param p1 the second parameter
 * @return the boolean result
 */
static int and(const void* p0, const void* p1) {

    int result = 0;
    int i0 = *((int*) p0);
    int i1 = *((int*) p1);

    result = i0 && i1;
    
    return result;
}

/**
 * Logical OR.
 *
 * @param p0 the first parameter
 * @param p1 the second parameter
 * @return the boolean result
 */
static int or(const void* p0, const void* p1) {

    int result = 0;
    int i0 = *((int*) p0);
    int i1 = *((int*) p1);

    result = i0 || i1;
    
    return result;
}

//
// Comparison.
//

/**
 * Compares if the first parameter is equal to the second parameter.
 *
 * @param p0 the first parameter
 * @param p1 the second parameter
 * @return true if equal; false otherwise
 */
static int equal(const void* p0, const void* p1) {

    int result = 0;
    int i0 = *((int*) p0);
    int i1 = *((int*) p1);

    if (i0 == i1) {

        result = 1;
    }

    return result;        
}

/**
 * Compares if the first parameter is smaller than the second parameter.
 *
 * @param p0 the first parameter
 * @param p1 the second parameter
 * @return true if smaller; false otherwise
 */
static int smaller(const void* p0, const void* p1) {

    int result = 0;
    int i0 = *((int*) p0);
    int i1 = *((int*) p1);

    if (i0 < i1) {

        result = 1;
    }

    return result;        
}

/**
 * Compares if the first parameter is greater than the second parameter.
 *
 * @param p0 the first parameter
 * @param p1 the second parameter
 * @return true if greater; false otherwise
 */
static int greater(const void* p0, const void* p1) {

    int result = 0;
    int i0 = *((int*) p0);
    int i1 = *((int*) p1);

    if (i0 > i1) {

        result = 1;
    }

    return result;        
}

/**
 * Compares if the first parameter is smaller than or equal to the second parameter.
 *
 * @param p0 the first parameter
 * @param p1 the second parameter
 * @return true if smaller or equal; false otherwise
 */
static int smaller_or_equal(const void* p0, const void* p1) {

    int result = 0;
    int i0 = *((int*) p0);
    int i1 = *((int*) p1);

    if (i0 <= i1) {

        result = 1;
    }

    return result;        
}

/**
 * Compares if the first parameter is greater than or equal to the second parameter.
 *
 * @param p0 the first parameter
 * @param p1 the second parameter
 * @return true if greater or equal; false otherwise
 */
static int greater_or_equal(const void* p0, const void* p1) {

    int result = 0;
    int i0 = *((int*) p0);
    int i1 = *((int*) p1);

    if (i0 >= i1) {

        result = 1;
    }

    return result;        
}

//
// Algebra.
//

/**
 * Adds the parameters.
 *
 * @param p0 the first parameter
 * @param p1 the second parameter
 * @return the sum
 */
static int add(const void* p0, const void* p1) {

    int sum = 0;
    int i0 = *((int*) p0);
    int i1 = *((int*) p1);
    
    sum = i0 + i1;
    
    return sum;
}

/**
 * Subtracts the parameters.
 *
 * @param p0 the first parameter
 * @param p1 the second parameter
 * @return the difference
 */
static int subtract(const void* p0, const void* p1) {

    int difference = 0;
    int i0 = *((int*) p0);
    int i1 = *((int*) p1);
    
    difference = i0 - i1;
    
    return difference;
}

/**
 * Multiplies the parameters.
 *
 * @param p0 the first parameter
 * @param p1 the second parameter
 * @return the product
 */
static int multiply(const void* p0, const void* p1) {

    int product = 0;
    int i0 = *((int*) p0);
    int i1 = *((int*) p1);
    
    product = i0 * i1;
    
    return product;
}

/**
 * Divides the parameters.
 *
 * @param p0 the first parameter
 * @param p1 the second parameter
 * @return the integer quotient (without rest)
 */
static int divide(const void* p0, const void* p1) {

    int quotient = 0;
    int i0 = *((int*) p0);
    int i1 = *((int*) p1);
    
    quotient = i0 / i1;
    //?? Rest of integer division is determined with:
    //?? rest = i0 % i1;

    return quotient;
}

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
*/

//
// Signal handling.
//

/**
 * Handles the mouse clicked action.
 *
 * @param p0 the screen item
 * @param p1 the x coordinate
 * @param p2 the y coordinate
 * @param p3 the z coordinate
 * @param p4 the action
 */
static void mouse_clicked_action(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p0 != 0) {

/*??
        // Determine the action of the clicked child screen item.
        int count = 0;
        int size = get_map_size(p0->items);
        void* child = 0;
        struct vector* position = 0;
        struct vector* expansion = 0;
        int x = -1;
        int y = -1;
        int z = -1;
        int width = -1;
        int height = -1;
        int depth = -1;
        int contains = 0;
        void* action = 0;
        
        while (count < size) {

            // Determine child, its position and expansion within the given screen item.
            child = get_map_element(p0->items, count);
            position = (vector*) get_map_element(p0->positions, count);
            
            if (child instanceof item) {
                    
                expansion = (vector) get_item_element(child, "expansion");
                
                if (position != 0) {
                        
                    // Translate the given coordinates according to the child's position.
                    x = p1 - position->x;
                    y = p2 - position->y;
                    z = p3 - position->z;

                    if (expansion != 0) {

                        // Determine child's expansion.
                        width = expansion->x;
                        height = expansion->y;
                        depth = expansion->z;
        
                        // Check if the given coordinates are in the child's screen area.
                        // The "if" conditions had to be inserted because in classical
                        // graphical user interfaces, the depth is normally 0 and
                        // such the boolean comparison would deliver "false".
                        // Using the conditions, the coordinates that are set to "0"
                        // are not considered for comparison.
                        contains = (x >= 0);
                        contains = contains && (x < width);
                        contains = contains && (y >= 0);
                        contains = contains && (y < height);
                        contains = contains && (z >= 0);
                        contains = contains && (z < depth);
        
                        if (contains == 1) {
        
                            // The given coordinates are in the child's screen area.
                            // Therefore, use the child's action.
                            action = mouse_clicked_action(child, x, y, z, p4);
                
                            break;
                        }

                    } else {
                        
                        log((void*) &ERROR_LOG_LEVEL, "Could not handle mouse clicked action. An expansion is null.");
                    }

                } else {
                    
                    log((void*) &ERROR_LOG_LEVEL, "Could not handle mouse clicked action. A position is null.");
                }

            } else {
                
                log((void*) &INFO_LOG_LEVEL, "Could not handle mouse clicked action. A child is not of type Item.");
            }
            
            count++;
        }
        
        // Only use child screen item's action if it exists.
        // Otherwise, use the parent screen item's action.
        if (action != 0) {
            
            p4 = action;

        } else {
            
            // Determine the action of the given screen item.
            get_map_element(i->items, "mouse_clicked_action", p4);
        }
*/

    } else {
        
        puts("ERROR: Could not handle mouse clicked action. The item is null.");
    }
}

/* DYNAMICS_HANDLER_SOURCE */
#endif

