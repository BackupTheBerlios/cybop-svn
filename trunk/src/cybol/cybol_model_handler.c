/*
 * $RCSfile: cybol_model_handler.c,v $
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
 * This file handles a cybol model.
 *
 * It can read and write a cybol source file.
 *
 * @version $Revision: 1.11 $ $Date: 2004-04-05 16:10:30 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CYBOL_MODEL_HANDLER_SOURCE
#define CYBOL_MODEL_HANDLER_SOURCE

#include <stdio.h>

//
// Constants.
//

/** The cybol path. */
//?? static const char CYBOL_PATH[] = {'/home/cybop/lib/cybop/'};

/** The cybol file suffix. */
//?? static const char FILE_SUFFIX[] = {'.cybol'};

/** The super model. */
//?? static const char SUPER_MODEL[] = {'super'};

/** The null model. */
//?? static const char NULL_MODEL[] = {'null'};

/** The name. */
static const char NAME[] = {'n', 'a', 'm', 'e'};

/** The part abstraction. */
static const char PART_ABSTRACTION[] = {'p', 'a', 'r', 't', '_', 'a', 'b', 's', 't', 'r', 'a', 'c', 't', 'i', 'o', 'n'};

/** The part location. */
static const char PART_LOCATION[] = {'p', 'a', 'r', 't', '_', 'l', 'o', 'c', 'a', 't', 'i', 'o', 'n'};

/** The part model. */
static const char PART_MODEL[] = {'p', 'a', 'r', 't', '_', 'm', 'o', 'd', 'e', 'l'};

/** The position abstraction. */
static const char POSITION_ABSTRACTION[] = {'p', 'o', 's', 'i', 't', 'i', 'o', 'n', '_', 'a', 'b', 's', 't', 'r', 'a', 'c', 't', 'i', 'o', 'n'};

/** The position location. */
static const char POSITION_LOCATION[] = {'p', 'o', 's', 'i', 't', 'i', 'o', 'n', '_', 'l', 'o', 'c', 'a', 't', 'i', 'o', 'n'};

/** The position model. */
static const char POSITION_MODEL[] = {'p', 'o', 's', 'i', 't', 'i', 'o', 'n', '_', 'm', 'o', 'd', 'e', 'l'};

/** The constraint abstraction. */
static const char CONSTRAINT_ABSTRACTION[] = {'c', 'o', 'n', 's', 't', 'r', 'a', 'i', 'n', 't', '_', 'a', 'b', 's', 't', 'r', 'a', 'c', 't', 'i', 'o', 'n'};

/** The constraint location. */
static const char CONSTRAINT_LOCATION[] = {'c', 'o', 'n', 's', 't', 'r', 'a', 'i', 'n', 't', '_', 'l', 'o', 'c', 'a', 't', 'i', 'o', 'n'};

/** The constraint model. */
static const char CONSTRAINT_MODEL[] = {'c', 'o', 'n', 's', 't', 'r', 'a', 'i', 'n', 't', '_', 'm', 'o', 'd', 'e', 'l'};

cybol_model
    tags (0..n)
        map = name_attribute
            names array
            references array
        map = part_abstraction_attribute
        map = part_location_attribute
        map = part_model_attribute
        map = position_abstraction_attribute
        (attributes 0..9 = size 10)

//
// Attribute.
//

/**
 * Reads the child attribute.
 *
 * @param p0 the child attributes map
 * @param p1 the child attribute name
 * @param p2 the child attribute
 */
/*??
void read_child_attribute(void* p0, void* p1, void* p2) {

/*??
    org.apache.xerces.dom.NamedNodeMapImpl m = (org.apache.xerces.dom.NamedNodeMapImpl) p0;

    if (m != NULL) {

        org.apache.xerces.dom.NodeImpl n = (org.apache.xerces.dom.NodeImpl) m.getNamedItem((char[]) p1);

        if (n != NULL) {

            log_message((void*) &INFO_LOG_LEVEL, "Read child attribute.");
            p2 = n.getNodeValue();

        } else {

            log_message((void*) &WARNING_LOG_LEVEL, "Could not read child attribute. The child attribute node is null.");
        }

    } else {
        
        log_message((void*) &WARNING_LOG_LEVEL, "Could not read child attribute. The child attributes map is null.");
    }
*/
/*??
}

/**
 * Writes the child attribute.
 *
 * @param p0 the child attributes map
 * @param p1 the child attribute name
 * @param p2 the child attribute
 */
/*??
void write_child_attribute(void* p0, void* p1, void* p2) {
}

//
// Attributes.
//

/**
 * Initializes the child attributes.
 *
 * @param p0 the child attribute items
 * @param p1 the child attributes map
 */
/*??
void initialize_child_attributes(void* p0, void* p1) {

/*??
    log_message((void*) &INFO_LOG_LEVEL, "Initialize child attributes.");
    int a = 0;

    a = read_child_attribute(p1, NAME);
    set_map_element(p0, NAME, a);

    a = read_child_attribute(p1, ITEM_CATEGORY);
    set_map_element(p0, ITEM_CATEGORY, a);

    a = read_child_attribute(p1, ITEM_ABSTRACTION);
    set_map_element(p0, ITEM_ABSTRACTION, a);

    a = read_child_attribute(p1, POSITION_CATEGORY);
    set_map_element(p0, POSITION_CATEGORY, a);

    a = read_child_attribute(p1, POSITION_ABSTRACTION);
    set_map_element(p0, POSITION_ABSTRACTION, a);

    a = read_child_attribute(p1, INSTANCE_CATEGORY);
    set_map_element(p0, INSTANCE_CATEGORY, a);

    a = read_child_attribute(p1, INSTANCE_ABSTRACTION);
    set_map_element(p0, INSTANCE_ABSTRACTION, a);

    a = read_child_attribute(p1, INTERACTION_CATEGORY);
    set_map_element(p0, INTERACTION_CATEGORY, a);

    a = read_child_attribute(p1, INTERACTION_ABSTRACTION);
    set_map_element(p0, INTERACTION_ABSTRACTION, a);
*/
/*??
}

/**
 * Finalizes the child attributes.
 *
 * @param p0 the child attribute items
 * @param p1 the child attributes map
 */
/*??
void finalize_child_attributes(void* p0, void* p1) {
}

//
// Child model.
//

/**
 * Initializes the child model.
 *
 * @param p0 the child model
 * @param p1 the child model node
 */
/*??
void initialize_child_model(void* p0, void* p1) {

/*??
    Item i = (Item) p0;

    if (i != NULL) {

        org.apache.xerces.dom.NodeImpl n = (org.apache.xerces.dom.NodeImpl) p1;

        if (n != NULL) {
            
            log_message((void*) &INFO_LOG_LEVEL, "Initialize child model.");
            initialize_attributes(i.items, (org.apache.xerces.dom.NamedNodeMapImpl) n.getAttributes());
    
        } else {
            
            log_message((void*) &WARNING_LOG_LEVEL, "Could not initialize child model. The child model node is null.");
        }

    } else {
        
        log_message((void*) &WARNING_LOG_LEVEL, "Could not initialize child model. The child model is null.");
    }
*/
/*??
}

/**
 * Finalizes the child model.
 *
 * @param p0 the child model
 * @param p1 the child model node
 */
/*??
void finalize_child_model(void* p0, void* p1) {
}

//
// Children.
//

/**
 * Initializes the children.
 *
 * @param p0 the model children
 * @param p1 the model children list
 */
/*??
void initialize_children_models(void* p0, void* p1) {

/*??
    org.apache.xerces.dom.DeepNodeListImpl l = (org.apache.xerces.dom.DeepNodeListImpl) p1;

    if (l != NULL) {
        
        log_message((void*) &INFO_LOG_LEVEL, "Initialize children models.");
        int count = 0;
        int size = l.getLength();
        org.apache.xerces.dom.NodeImpl n = NULL;
        item i = NULL;
        int name = 0;

        while (count < size) {
        
            n = (org.apache.xerces.dom.NodeImpl) l.item(count);

            if (n != NULL) {
                    
                i = new Item();
                initialize_item_containers(i);
                initialize_item(i, n);

                if (i != NULL) {
                        
                    name = get_map_element(i.items, NAME);
                    set_map_element(p0, name, i);
                    
/*??
                    // Initialize serialized item.
                    i = n.getNodeValue();
*/

/*??
                } else {
                    
                    log_message((void*) &ERROR_LOG_LEVEL, "Could not initialize children models. A model is null.");
                }
        
            } else {
                
                log_message((void*) &INFO_LOG_LEVEL, "Could not initialize children models. The model item node is null.");
            }
                    
            count++;
        }
        
    } else {

        log_message((void*) &ERROR_LOG_LEVEL, "Could not initialize children models. The model items list is null.");
    }
*/
/*??
}

/**
 * Finalizes the children models.
 *
 * @param p0 the children models
 * @param p1 the children models list
 */
/*??
void finalize_items(void* p0, void* p1) {
}

//
// Super model.
//

/**
 * Initializes the super model.
 *
 * @param p0 the model
 * @param p1 the super model list
 */
/*??
void initialize_super_model(void* p0, void* p1) {

/*??
    org.apache.xerces.dom.DeepNodeListImpl l = (org.apache.xerces.dom.DeepNodeListImpl) p1;

    if (l != NULL) {
        
        org.apache.xerces.dom.NodeImpl n = (org.apache.xerces.dom.NodeImpl) l.item(0);
        
        if (n != NULL) {

            log_message((void*) &INFO_LOG_LEVEL, "Initialize super model.");
            int s = read_attribute((org.apache.xerces.dom.NamedNodeMapImpl) n.getAttributes(), CATEGORY);
            initialize_category(p0, s);
            
        } else {
            
            log_message((void*) &WARNING_LOG_LEVEL, "Could not initialize super model. The super model node is null.");
        }
        
    } else {
        
        log_message((void*) &WARNING_LOG_LEVEL, "Could not initialize super model. The super model list is null.");
    }
*/
/*??
}

/**
 * Finalizes the super model.
 *
 * @param p0 the model
 * @param p1 the super model list
 */
/*??
void finalize_super_model(void* p0, void* p1) {
}

//
// Model.
//

/**
 * Reads the cybol hierarchy into the model.
 *
 * @param p0 the model
 * @param p1 the cybol hierarchy
 */
void read_into_model(void* p0, void* p1) {

/*??
    org.apache.xerces.dom.DocumentImpl doc = (org.apache.xerces.dom.DocumentImpl) p1;

    if (doc != NULL) {
        
        log_message((void*) &INFO_LOG_LEVEL, "Read document.");
        doc.normalize();
        org.apache.xerces.dom.DeepNodeListImpl l = NULL;

        if (p0 != NULL) {
            
            l = (org.apache.xerces.dom.DeepNodeListImpl) doc.getElementsByTagName(SUPER_CATEGORY);
            initialize_super_category(p0, l);

            l = (org.apache.xerces.dom.DeepNodeListImpl) doc.getElementsByTagName(ITEM);
            initialize_items(((Item) p0).items, l);

        } else {

            log_message((void*) &ERROR_LOG_LEVEL, "Could not read structure. The model is null.");
        }

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, "Could not read structure. The structure is null.");
    }
*/
}

/**
 * Writes the model into the cybol hierarchy.
 *
 * @param p0 the model
 * @param p1 the cybol hierarchy
 */
void write_from_model(void* p0, void* p1) {
}

/**
 * Reads the cybol attributes.
 *
 * @param p0 the cybol file
 * @param p1 the cybol hierarchy structure
 */
int read_cybol_attribute(void* p0, void* p1) {

    int mode = 0;
    char* s = (char*) p0;
    
    if (strcmp(s, "name=") == 0) {
        
        mode = 1;

    } else if (strcmp(s, "child_ab straction=") == 0) {
        
        mode = 2;
    
    } else if (strcmp(s, "child_model=") == 0) {
        
        mode = 3;
    
    } else if (strcmp(s, "position_abstraction=") == 0) {
        
        mode = 4;
    
    } else if (strcmp(s, "position_model=") == 0) {
        
        mode = 5;
    
    } else if (strcmp(s, "logics_abstraction=") == 0) {
        
        mode = 6;
    
    } else if (strcmp(s, "input_0=") == 0) {
        
        mode = 7;
    
    } else if (strcmp(s, "output_0=") == 0) {
        
        mode = 8;

    } else if (strcmp(s, "input_1=") == 0) {

        mode = 9;

    } else if (strcmp(s, "input_abstraction=") == 0) {

        mode = 10;

    } else if (strcmp(s, "input_model=") == 0) {

        mode = 11;

    } else if (strcmp(s, "logics_model=") == 0) {

        mode = 12;
    }

    return mode;
}

/**
 * Reads the cybol tags.
 *
 * @param p0 the cybol file
 * @param p1 the cybol hierarchy structure
 */
int read_cybol_tag(void* p0, void* p1) {

    int mode = 0;
    char* s = (char*) p0;

    if (strcmp(s, "<!--") == 0) {

        //Kommentaranfang ... innerhalb model berreich mode 4
        mode = 1;

    } else if (strcmp(s, "/-->") == 0) {

        //Kommentarende ...innerhalb model bereich 5
        mode = 2;

    } else if ((strcmp(s, "<model>") == 0) || (strcmp(s, "/>") == 0)) {

        mode = 3;

    } else if (strcmp(s, "<child") == 0) {

        mode = 6;

    } else if (strcmp(s, "</model>") == 0) {

        mode = 7;
    }

    return mode;
}

/**
 * Reads the cybol file.
 *
 * @param p0 the cybol model
 * @param p1 the cybol file
 */
void read_cybol_file(void* p0, const void* p1) {

    FILE* f = (FILE*) p1;
    //?? char* s = (char*) malloc(2000);
    char c = fgetc(f);
    int parsemode = 0;
    int childmode = 0;
    int string_open = 0;

    while (c != EOF) {

        // Kommentare ausserhalb model bereich abfangen ... eigentlich unsinnig,
        // aber vermeidung von interpretation auskommentierter model bereiche
        if (parsemode == 1) {

            if (read_cybol_tag(s) == 2) {

                parsemode = 0;
            }

        } else if (parsemode < 3) {

            parsemode = read_cybol_tag(s);
        }

        // kommentare innerhalb model breich abfangen
        if (parsemode > 2) {

            if ((read_cybol_tag(s) == 1) && (parsemode == 3)) {

                parsemode = 4;

            } else if ((parsemode == 4) && (read_cybol_tag(s) == 2)) {

                parsemode = 5;

            } else if ((parsemode == 6) && (read_cybol_tag(s) == 3)) {

                parsemode = 3;

            } else if (read_cybol_tag(s) > 5) {

                parsemode = read_cybol_tag(s);

            } else if (parsemode == 6) {

                if ((c == 34) && (string_open)) {

                    // Child.
                    if ((parsemode == 6) && (string_open)) {

                        printf(s);
                    }

                    if ((parsemode == 6) && (string_open)) {

                        cout << s << "Childsektion:  " << childmode<< "\n'};
                    }
                }

            } else if ((string_open == 0) && (read_cybol_attribute(s) > 0)) {

                childmode = read_cybol_attribute(s);
            }
        }

        if ((c != EOF)) {

            // 10 == 'LF', 13 == 'CR', 32 == ' ', 34 == '"'
            if ((c == 10) || (c == 13) || (c == 32) || (c == 34)) {

                s[0] = '\0';

            } else {

                s[strlen(s)] = c;
            }

            if ((c == 34) && (parsemode > 5)) {

                if (string_open == 1) {

                    string_open = 0;

                } else {

                    string_open = 1;
                }
            }
        }

        c = fgetc(f);
    }

//??    free(s);
}

//
// Source model.
//

/**
 * Initializes the source model.
 *
 * Reads the file of the given model.
 *
 * @param p0 the model
 * @param p1 the model name
 */
void initialize_source_model(void* p0, void* p1) {

    log_message((void*) &INFO_LOG_LEVEL, "Initialize model.");

    char* n[] = {''};
    n = strcat(n, CYBOL_PATH);
    n = strcat(n, p1);
    n = strcat(n, CYBOL_SUFFIX);
    FILE* f = fopen(n, "r");

    if (f != NULL) {

        read_cybol_file(f);
        fclose(f);
        read_into_model(p0, s);

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, "Could not initialize source model. The file is null.");
    }
}

/**
 * Finalizes the source model.
 *
 * Writes the file of the given model.
 *
 * @param p0 the model
 * @param p1 the model name
 */
void finalize_source_model(void* p0, void* p1) {
}

/* CYBOL_MODEL_HANDLER_SOURCE */
#endif
