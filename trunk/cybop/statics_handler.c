/*
 * $RCSfile: statics_handler.c,v $
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
#include "instance.c"
#include "time.c"
#include "vector.c"
#include "xml_handler.c"

/**
 * This is the statics handler.
 *
 * There are complex and primitive static models.
 * Complex models consist of other complex models and primitive models.
 * Primitive models are the final abstraction in software.
 *
 * An instance is retrieved by instantiating a model.
 *
 * @version $Revision: 1.1 $ $Date: 2003-09-27 19:50:33 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

//
// Complex model.
//

/** The complex model. */
static const void* COMPLEX_MODEL = &"complex";

//
// Primitive models.
//

/** The boolean primitive. */
static const void* BOOLEAN_PRIMITIVE = &"boolean";

/** The integer primitive. */
static const void* INTEGER_PRIMITIVE = &"integer";

/** The float primitive. */
static const void* FLOAT_PRIMITIVE = &"float";

/** The vector primitive. */
static const void* VECTOR_PRIMITIVE = &"vector";

/** The string primitive. */
static const void* STRING_PRIMITIVE = &"string";

/** The time primitive. */
static const void* TIME_PRIMITIVE = &"time";

//
// Application models.
//

/** The koffice kword application. */
static const void* KWORD_APPLICATION = &"kword_application";

/** The open office writer application. */
static const void* SXW_APPLICATION = &"sxw_application";

//
// Audio models.
//

/** The mp3 audio. */
static const void* MP3_AUDIO = &"mp3_audio";

//
// Image models.
//

/** The jpeg image. */
static const void* JPEG_IMAGE = &"jpeg_image";

/** The gif image. */
static const void* GIF_IMAGE = &"gif_image";

/** The bmp image. */
static const void* BMP_IMAGE = &"bmp_image";

//
// Text models.
//

/** The sgml text. */
static const void* SGML_TEXT = &"sgml_text";

/** The xml text. */
static const void* XML_TEXT = &"xml_text";

/** The html text. */
static const void* HTML_TEXT = &"html_text";

/** The rtf text. */
static const void* RTF_TEXT = &"rtf_text";

/** The tex text. */
static const void* TEX_TEXT = &"tex_text";

//
// Video models.
//

/** The mpeg video. */
static const void* MPEG_VIDEO = &"mpeg_video";

/** The quicktime video. */
static const void* QUICKTIME_VIDEO = &"quicktime_video";

//
// Instance.
//

/**
 * Creates an instance.
 *
 * @param p0 the instance
 * @param p1 the model
 * @param p2 the abstraction
 */
void create_instance(void* p0, void* p1, void* p2) {

    log(INFO_LOG_LEVEL, strcat("Create instance: ", p1));

    if (strcmp(*p2, *COMPLEX_MODEL) == 0) {

        create_complex_instance(p0, p1);

    } else if (strcmp(*p2, *BOOLEAN_PRIMITIVE) == 0) {

        create_boolean_instance(p0, p1);

    } else if (strcmp(*p2, *INTEGER_PRIMITIVE) == 0) {

        create_integer_instance(p0, p1);

    } else if (strcmp(*p2, *FLOAT_PRIMITIVE) == 0) {

        create_float_instance(p0, p1);

    } else if (strcmp(*p2, *VECTOR_PRIMITIVE) == 0) {

        create_vector_instance(p0, p1);

    } else if (strcmp(*p2, *STRING_PRIMITIVE) == 0) {

        create_string_instance(p0, p1);

    } else if (strcmp(*p2, *TIME_PRIMITIVE) == 0) {

        create_time_instance(p0, p1);
    }
}

/**
 * Destroys the instance.
 *
 * @param p0 the instance
 * @param p1 the model
 * @param p2 the abstraction
 */
void destroy_instance(void* p0, void* p1, void* p2) {

    log(INFO_LOG_LEVEL, strcat("Destroy instance: ", p1));

    if (strcmp(*p2, *COMPLEX_MODEL) == 0) {

        destroy_complex_instance(p0, p1);
        
    } else if (strcmp(*p2, *BOOLEAN_PRIMITIVE) == 0) {

        destroy_boolean_instance(p0, p1);

    } else if (strcmp(*p2, *INTEGER_PRIMITIVE) == 0) {

        destroy_integer_instance(p0, p1);

    } else if (strcmp(*p2, *FLOAT_PRIMITIVE) == 0) {

        destroy_float_instance(p0, p1);

    } else if (strcmp(*p2, *VECTOR_PRIMITIVE) == 0) {

        destroy_vector_instance(p0, p1);

    } else if (strcmp(*p2, *STRING_PRIMITIVE) == 0) {

        destroy_string_instance(p0, p1);

    } else if (strcmp(*p2, *TIME_PRIMITIVE) == 0) {

        destroy_time_instance(p0, p1);
    }
}

//
// Complex instance.
//

/**
 * Creates a complex instance.
 *
 * @param p0 the complex instance
 * @param p1 the complex model
 */
void create_complex_instance(void* p0, void* p1) {

    if (p1 != 0) {
        
        log(INFO_LOG_LEVEL, "Create complex instance.");

        p0 = malloc(sizeof(instance));

        if (strcmp(*p1, "") != 0) {
            
            initialize_instance_containers(p0);
            initialize_instance(p0, p1);
        }
    }
}

/**
 * Destroys the complex instance.
 *
 * @param p0 the complex instance
 * @param p1 the complex model
 */
void destroy_complex_instance(void* p0, void* p1) {

    if (p0 != 0) {
        
        log(INFO_LOG_LEVEL, "Destroy complex instance.");

        if (strcmp(*p1, "") != 0) {
            
            finalize_instance(p0, p1);
            finalize_instance_containers(p0);
        }

        free(p0);
    }
}

/**
 * Initializes the instance.
 *
 * @param p0 the model
 * @param p1 the model name
 */
void initialize_item(void* p0, void* p1) {

    log(INFO_LOG_LEVEL, "Initialize item: " + p1);

    // Create temporary category item.
    struct item* c = (struct item*) malloc(sizeof(item));
    initialize_item_containers(c);

    // Read category from file.
    initialize_category(c, p1);

    // Initialize elements with category.
    if (c != 0) {

        initialize_child_items(p0, c->children);
        
    } else {
        
        log(ERROR_LOG_LEVEL, "Could not initialize item elements. The category is null.");
    }

    // Destroy temporary category item.        
    finalize_item_containers(c);
    free(c);
}

/**
 * Finalizes the item.
 *
 * @param p0 the item
 * @param p1 the category name
 */
void finalize_item(void* p0, void* p1) {

    log(INFO_LOG_LEVEL, "Finalize item: " + p1);
    
    // Create temporary category item.
    struct item* c = (struct item*) malloc(sizeof(item));
    initialize_item_containers(c);

    // Finalize elements with category.
    if (c != 0) {
        
        finalize_child_items(p0, c->children);
        
    } else {
        
        log(ERROR_LOG_LEVEL, "Could not finalize item elements. The category is null.");
    }

    // Write category to file.
    finalize_category(c, p1);

    // Destroy temporary category item.        
    finalize_item_containers(c);
    free(c);
}

/**
 * Initializes the child items.
 *
 * @param p0 the item
 * @param p1 the category items
 */
void initialize_child_items(void* p0, void* p1) {

    struct map* m = (struct map*) p1;
    int count = 0;
    int size = get_map_size(m);
    struct item* ci = 0;
    struct item* o = 0;

    while (count < size) {
    
        ci = (struct item*) get_map_element(m, count);

        if (ci != 0) {
            
            initialize_child_item(p0, ci->items);

        } else {
            
            log(ERROR_LOG_LEVEL, "Could not initialize items. A category item is null.");
        }
        
        count++;
    }
}

/**
 * Finalizes the child items
 *
 * @param p0 the item
 * @param p1 the category items
 */
void finalize_child_items(void* p0, void* p1) {
}

/**
 * Initializes the child item.
 *
 * @param p0 the item
 * @param p1 the category item attributes
 */
void initialize_child_item(void* p0, void* p1) {

    struct item* i = (struct item*) p0;
    
    if (i != 0) {
            
        log(INFO_LOG_LEVEL, "Initialize item element.");
        void* name = get_map_element(p1, NAME);                
        void* category = 0;                
        void* abstraction = 0;                
        void* o = 0;

        // Item.
        category = get_map_element(p1, ITEM_CATEGORY);
        abstraction = get_map_element(p1, ITEM_ABSTRACTION);
        o = create_object(category, abstraction);
        set_map_element(i->children, name, o);

        // Position.
        category = get_map_element(p1, POSITION_CATEGORY);
        abstraction = get_map_element(p1, POSITION_ABSTRACTION);
        o = create_object(category, abstraction);
        set_map_element(i->positions, name, o);

        // Instance.
        category = get_map_element(p1, INSTANCE_CATEGORY);
        abstraction = get_map_element(p1, INSTANCE_ABSTRACTION);
        o = create_object(category, abstraction);
        set_map_element(i->instances, name, o);

        // Interaction.
        category = get_map_element(p1, INTERACTION_CATEGORY);
        abstraction = get_map_element(p1, INTERACTION_ABSTRACTION);
        o = create_object(category, abstraction);
        set_map_element(i->interactions, name, o);

    } else {
        
        log(ERROR_LOG_LEVEL, "Could not initialize item element. The item is null.");
    }
}

/**
 * Finalizes the child item.
 *
 * @param p0 the item
 * @param p1 the category item attributes
 */
void finalize_child_item(void* p0, void* p1) {
}

//
// Boolean instance.
//

/**
 * Creates a boolean instance.
 *
 * @param p0 the boolean instance
 * @param p1 the boolean model
 */
void create_boolean_instance(void* p0, void* p1) {

    if (p1 != 0) {
        
        log(INFO_LOG_LEVEL, "Create boolean instance.");

        if (strcmp(*p1, "true")) {
            
            *p0 = 1;
            
        } else if (strcmp(*p1, "false")) {
            
            *p0 = 0;
        }
    }
}

/**
 * Destroys the boolean instance.
 *
 * @param p0 the boolean instance
 * @param p1 the boolean model
 */
void destroy_boolean_instance(void* p0, void* p1) {

    if (p0 != 0) {
        
        log(INFO_LOG_LEVEL, "Destroy boolean instance.");

        if (*p0 != 0) {
            
            *p1 = "true";
            
        } else {
    
            *p1 = "false";        
        }
        
        free(p0);
    }
}

//
// Integer instance.
//

/**
 * Creates an integer instance.
 *
 * @param p0 the integer instance
 * @param p1 the integer model
 */
void create_integer_instance(void* p0, void* p1) {

    if (p1 != 0) {
        
        log(INFO_LOG_LEVEL, "Create integer instance.");
        
        if (strcmp(*p1, "") != 0) {
            
//??            p0 = java.lang.Integer.valueOf(p1);
        }
    }
}

/**
 * Destroys the integer instance.
 *
 * @param p0 the integer instance
 * @param p1 the integer model
 */
void destroy_integer_instance(void* p0, void* p1) {

    if (p0 != 0) {
        
        log(INFO_LOG_LEVEL, "Destroy integer instance.");

//??        make_string(p0, p1);
        
        free(p0);
    }
}

//
// Float instance.
//

/**
 * Creates a float instance.
 *
 * @param p0 the float instance
 * @param p1 the float model
 */
void create_float_instance(void* p0, void* p1) {

    if (p1 != 0) {
        
        log(INFO_LOG_LEVEL, "Create float instance.");

        if (strcmp(*p1, "") != 0) {
            
//??            p0 = java.lang.Double.valueOf(p1);
        }
    }
}

/**
 * Destroys the float instance.
 *
 * @param p0 the float instance
 * @param p1 the float model
 */
void destroy_float_instance(void* p0, void* p1) {

    if (p0 != 0) {
        
        log(INFO_LOG_LEVEL, "Destroy float instance.");

//??        make_string(p0, p1);
        
        free(p0);
    }
}

//
// Vector instance.
//

/**
 * Creates a vector instance.
 *
 * @param p0 the vector instance
 * @param p1 the vector model
 */
void create_vector_instance(void* p0, void* p1) {

    if (p1 != 0) {
        
        log(INFO_LOG_LEVEL, "Create vector instance.");

        p0 = malloc(sizeof(vector));

        if (strcmp(*p1, "") != 0) {
            
/*??
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
                
                    log(ERROR_LOG_LEVEL, "Could not create vector instance. The vector does not contain a z coordinate.");
                }
                
            } else {
            
                log(ERROR_LOG_LEVEL, "Could not create vector instance. The vector does not contain an y coordinate.");
            }
*/
        }
    }
}

/**
 * Destroys the vector instance.
 *
 * @param p0 the vector instance
 * @param p1 the vector model
 */
void destroy_vector_instance(void* p0, void* p1) {

    if (p0 != 0) {
        
        log(INFO_LOG_LEVEL, "Destroy vector instance.");

//??        make_string(p0, p1);
        
        free(p0);
    }
}

//
// String instance.
//

/**
 * Creates a string instance.
 *
 * @param p0 the string instance
 * @param p1 the string model
 */
void create_string_instance(void* p0, void* p1) {

    if (p1 != 0) {
        
        log(INFO_LOG_LEVEL, "Create string instance.");

        if (strcmp(*p1, "") != 0) {
            
            strcpy(p0, p1);
        }
    }
}

/**
 * Destroys the string instance.
 *
 * @param p0 the string instance
 * @param p1 the string model
 */
void destroy_string_instance(void* p0, void* p1) {

    if (p0 != 0) {
        
        log(INFO_LOG_LEVEL, "Destroy string instance.");

        strcpy(p1, p0);
        
        free(p0);
    }
}

//
// Time instance.
//

/**
 * Creates a time instance.
 *
 * @param p0 the time instance
 * @param p1 the time model
 */
void create_time_instance(void* p0, void* p1) {

    if (p1 != 0) {
        
        log(INFO_LOG_LEVEL, "Create time instance.");

        if (strcmp(*p1, "") != 0) {
            
        }
    }
}

/**
 * Destroys the time instance.
 *
 * @param p0 the time instance
 * @param p1 the time model
 */
void destroy_time_instance(void* p0, void* p1) {

    if (p0 != 0) {
        
        log(INFO_LOG_LEVEL, "Destroy time instance.");

//??        make_string(p0, p1);
        
        free(p0);
    }
}

