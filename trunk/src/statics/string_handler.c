/*
 * $RCSfile: string_handler.c,v $
 *
 * Copyright (c) 1999-2004. Christian Heller. All rights reserved.
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
 *
 * This file handles a string.
 *
 * A string is a chain of characters.
 *
 * @version $Revision: 1.9 $ $Date: 2004-04-01 17:35:16 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef STRING_HANDLER_SOURCE
#define STRING_HANDLER_SOURCE

#include "../logger/log_handler.c"

//
// Constants.
//

/** The default string value. */
static const char* DEFAULT_STRING_VALUE = "";

//
// String model.
//

/**
 * Creates the string model.
 *
 * @param p0 the string model
 */
void create_string_model(void* p0) {

    log_message((void*) &INFO_LOG_LEVEL, "Create string model.");

    // The string model.
    create_array(p0, (void*) &MODEL_SIZE);

    // The value.
    void* pa = (void*) 0;
    create_map((void*) &pa);
    set_array_element(p0, (void*) &MODEL_SIZE, (void*) &POINTER_ARRAY, (void*) &PART_ABSTRACTIONS_INDEX, (void*) &pa);
}

/**
 * Destroys the string model.
 *
 * @param p0 the string model
 */
void destroy_string_model(void* p0) {

    log_message((void*) &INFO_LOG_LEVEL, "Destroy string model.");

    // The part abstractions.
    void* pa = (void*) 0;
    get_array_element(p0, (void*) &MODEL_SIZE, (void*) &POINTER_ARRAY, (void*) &PART_ABSTRACTIONS_INDEX, (void*) &pa);
    remove_array_element(p0, (void*) &MODEL_SIZE, (void*) &POINTER_ARRAY, (void*) &PART_ABSTRACTIONS_INDEX);
    destroy_map((void*) &pa);

    // The model.
    destroy_array(p0, (void*) &MODEL_SIZE);
}

/**
 * Initializes the string model.
 *
 * @param p0 the string model
 * @param p1 the model source
 */
void initialize_string_model(void* p0, void* p1) {

    struct string* m = (struct string*) p0;

    if (m != (void*) 0) {

        log_message((void*) &INFO_LOG_LEVEL, "Initialize string model.");

        // Read input stream and transform to string.
//??        sscanf(p1, %10c, (void*) m->value);
//??        strcat(m->value, "\n");

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, "Could not initialize string model. The string model is null.");
    }
}

/**
 * Finalizes the string model.
 *
 * @param p0 the string model
 * @param p1 the model source
 */
void finalize_string_model(void* p0, void* p1) {

    struct string* m = (struct string*) p0;
    
    if (m != (void*) 0) {
        
        log_message((void*) &INFO_LOG_LEVEL, "Finalize string model.");
        
        // Write output stream and transform from string.
//??        sprintf(p1, %c, (void*) m->value);

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, "Could not finalize string model. The string model is null.");
    }
}

/**
 * Returns the string element index.
 *
 * @param p0 the string
 * @param p1 the element
 * @param p2 the index
 */
/*??
void get_string_element_index(void* p0, void* p1, void* p2) {

    char* s = (char*) p0;
    int l = strlen(s);
    int i = 0;
    
    while (i < l) {

        if (strcmp() == 0) {
            
        }
    }
}

/**
 * Returns the string suffix.
 *
 * @param p0 the string
 * @param p1 the start index
 * @param p2 the remaining suffix
 */
/*??
void get_string_suffix(void* p0, void* p1, void* p2) {
    
}

/**
 * Returns the string value.
 *
 * @param p0 the string
 * @param p1 the numerical value
 */
/*??
void get_string_value(void* p0, void* p1) {
    
}

/**
 * Returns the value as string.
 *
 * @param p0 the numerical value
 * @param p1 the string
 */
/*??
void get_value_string(void* p0, void* p1) {
    
}

/* STRING_HANDLER_SOURCE */
#endif
