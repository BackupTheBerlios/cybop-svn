/*
 * $RCSfile: primitive_handler.c,v $
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

#include <string.h>

/**
 * This is a primitive handler.
 *
 * It contains procedures to create items of primitive type.
 *
 * @version $Revision: 1.3 $ $Date: 2003-09-27 00:22:23 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

//
// Boolean primitive.
//

/**
 * Creates a boolean primitive.
 *
 * @param s the boolean primitive as string
 * @return the boolean primitive
 */
void* create_boolean_primitive(void* s) {

    void* p = 0;

    if (strcmp(s, "") == 0) {
        
        log(INFO_LOG_LEVEL, "Create boolean primitive.");
        p = java.lang.Boolean.valueOf(s);
        
    } else {
        
        log(INFO_LOG_LEVEL, "Could not create boolean primitive. The string is empty.");
    }
    
    return p;
}

/**
 * Destroys the boolean primitive.
 *
 * @param p the boolean primitive
 */
void destroy_boolean_primitive(void* p) {

    log(INFO_LOG_LEVEL, "Destroy boolean primitive.");
}

//
// Integer primitive.
//

/**
 * Creates an integer primitive.
 *
 * @param s the integer primitive as string
 * @return the integer primitive
 */
void* create_integer_primitive(void* s) {

    void* p = 0;

    if (strcmp(s, "") == 0) {
        
        log(INFO_LOG_LEVEL, "Create integer primitive.");
        p = java.lang.Integer.valueOf(s);
        
    } else {
        
        log(INFO_LOG_LEVEL, "Could not create integer primitive. The string is empty.");
    }

    return p;
}

/**
 * Destroys the integer primitive.
 *
 * @param p the integer primitive
 */
void destroy_integer_primitive(void* p) {

    log(INFO_LOG_LEVEL, "Destroy integer primitive.");
}

//
// Float primitive.
//

/**
 * Creates a float primitive.
 *
 * @param s the float primitive as string
 * @return the float primitive
 */
void* create_float_primitive(void* s) {

    void* p = 0;

    if (strcmp(s, "") == 0) {
        
        log(INFO_LOG_LEVEL, "Create float primitive.");
        p = java.lang.Double.valueOf((char[]) s);
        
    } else {
        
        log(INFO_LOG_LEVEL, "Could not create float primitive. The string is empty.");
    }
    
    return p;
}

/**
 * Destroys the float primitive.
 *
 * @param p the float primitive
 */
void destroy_float_primitive(void* p) {

    log(INFO_LOG_LEVEL, "Destroy float primitive.");
}

//
// Vector primitive.
//

/**
 * Creates a vector primitive.
 *
 * @param s the vector primitive as string
 * @return the vector primitive
 */
void* create_vector_primitive(void* s) {

    vector* p = (vector*) malloc(sizeof(vector));
    
    if (p != 0) {

        if (strcmp(s, "") == 0) {
            
            log(INFO_LOG_LEVEL, "Create vector primitive.");
            int i1 = s.indexOf(",");
            
            if (i1 != -1) {
                
                char[] x = s.substring(0, i1);
                char[] yz = s.substring(i1 + 1);
                int i2 = yz.indexOf(",");

                if (i2 != -1) {
                
                    char[] y = yz.substring(0, i2);
                    char[] z = yz.substring(i2 + 1);

                    p.x = java.lang.Integer.parseInt(x);
                    p.y = java.lang.Integer.parseInt(y);
                    p.z = java.lang.Integer.parseInt(z);

                } else {
                
                    log(ERROR_LOG_LEVEL, "Could not create vector primitive. The vector does not contain a z coordinate.");
                }
                
            } else {
            
                log(ERROR_LOG_LEVEL, "Could not create vector primitive. The vector does not contain an y coordinate.");
            }
        
        } else {
            
            log(INFO_LOG_LEVEL, "Could not create vector primitive. The string is empty.");
        }
    
    } else {
        
        log(ERROR_LOG_LEVEL, "Could not create vector primitive. The vector is null.");
    }
    
    return p;
}

/**
 * Destroys the vector primitive.
 *
 * @param p the vector primitive
 */
void destroy_vector_primitive(void* p) {

    log(INFO_LOG_LEVEL, "Destroy vector primitive.");
}

//
// Character primitive.
//

/**
 * Creates a character primitive.
 *
 * @param s the character primitive as string
 * @return the character primitive
 */
void* create_character_primitive(void* s) {

    int p = 0;

    if (strcmp(s, "") == 0) {
        
        log(INFO_LOG_LEVEL, "Create character primitive.");
        char[] a = s.toCharArray();
        
        if (a != 0) {

            if (a.length > 0) {
                
                p = new Character(a[0]);
        
            } else {
                
                log(INFO_LOG_LEVEL, "Could not create character primitive. The character array is empty.");
            }
        
        } else {
            
            log(INFO_LOG_LEVEL, "Could not create character primitive. The character array is null.");
        }

    } else {
        
        log(INFO_LOG_LEVEL, "Could not create character primitive. The string is empty.");
    }
    
    return p;
}

/**
 * Destroys the character primitive.
 *
 * @param p the character primitive
 */
void destroy_character_primitive(void* p) {

    log(INFO_LOG_LEVEL, "Destroy character primitive.");
}

//
// String primitive.
//

/**
 * Creates a string primitive.
 *
 * @param s the string primitive as string
 * @return the string primitive
 */
void* create_string_primitive(void* s) {

    void* p = 0;

    if (strcmp(s, "") == 0) {
        
        log(INFO_LOG_LEVEL, "Create string primitive.");
        p = s;
        
    } else {
        
        log(INFO_LOG_LEVEL, "Could not create string primitive. The string is empty.");
    }
    
    return p;
}

/**
 * Destroys the string primitive.
 *
 * @param p the string primitive
 */
void destroy_string_primitive(void* p) {

    log(INFO_LOG_LEVEL, "Destroy string primitive.");
}

//
// Time primitive.
//

/**
 * Creates a time primitive.
 *
 * @param s the time primitive as string
 * @return the time primitive
 */
void* create_time_primitive(void* s) {

    return 0;
}

/**
 * Destroys the time primitive.
 *
 * @param p the time primitive
 */
void destroy_time_primitive(void* p) {

    log(INFO_LOG_LEVEL, "Destroy time primitive.");
}

