/*
 * $RCSfile: cybol_model_handler.c,v $
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

#ifndef CYBOL_MODEL_HANDLER_SOURCE
#define CYBOL_MODEL_HANDLER_SOURCE

#include <stdio.h>

/**
 * This is the cybol model handler.
 *
 * It can read and write CYBOL source files.
 *
 * @version $Revision: 1.4 $ $Date: 2003-12-19 12:44:54 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

//
// Constants.
//

/** The cybol path. */
//?? static const char* CYBOL_PATH = "/home/cybop/lib/cybop/";

/** The cybol file suffix. */
//?? static const char* FILE_SUFFIX = ".cybol";

/** The super model. */
//?? static const char* SUPER_MODEL = "super";

/** The null model. */
//?? static const char* NULL_MODEL = "null";

/** The child. */
//?? static const char* CHILD = "child";

/** The name. */
static const char* NAME = "name";

/** The part model. */
static const char* PART_MODEL = "part_model";

/** The part input output names. */
static const char* PART_INPUT_OUTPUT_NAMES = "part_input_output_names";

/** The part input output values. */
static const char* PART_INPUT_OUTPUT_VALUES = "part_input_output_values";

/** The part abstraction. */
static const char* PART_ABSTRACTION = "part_abstraction";

/** The position model. */
static const char* POSITION_MODEL = "position_model";

/** The position abstraction. */
static const char* POSITION_ABSTRACTION = "position_abstraction";

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

    if (m != 0) {

        org.apache.xerces.dom.NodeImpl n = (org.apache.xerces.dom.NodeImpl) m.getNamedItem((char[]) p1);
        
        if (n != 0) {
            
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
    
    if (i != 0) {
    
        org.apache.xerces.dom.NodeImpl n = (org.apache.xerces.dom.NodeImpl) p1;
        
        if (n != 0) {
            
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

    if (l != 0) {
        
        log_message((void*) &INFO_LOG_LEVEL, "Initialize children models.");
        int count = 0;
        int size = l.getLength();
        org.apache.xerces.dom.NodeImpl n = 0;
        item i = 0;
        int name = 0;

        while (count < size) {
        
            n = (org.apache.xerces.dom.NodeImpl) l.item(count);

            if (n != 0) {
                    
                i = new Item();
                initialize_item_containers(i);
                initialize_item(i, n);

                if (i != 0) {
                        
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

    if (l != 0) {
        
        org.apache.xerces.dom.NodeImpl n = (org.apache.xerces.dom.NodeImpl) l.item(0);
        
        if (n != 0) {

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

    if (doc != 0) {
        
        log_message((void*) &INFO_LOG_LEVEL, "Read document.");
        doc.normalize();
        org.apache.xerces.dom.DeepNodeListImpl l = 0;

        if (p0 != 0) {
            
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
    
    char* wort (char*) p0;
    // Normal mode.
    int mode = 0; 
    
    if (strcmp(wort,"name=")==0) mode = 1;
    if (strcmp(wort,"child_ab straction=")==0) mode = 2;
    if (strcmp(wort,"child_model=")==0) mode = 3;
    if (strcmp(wort,"position_abstraction=")==0) mode = 4;
    if (strcmp(wort,"position_model=")==0) mode = 5;
    if (strcmp(wort,"logics_abstraction=")==0) mode = 6;
    if (strcmp(wort,"input_0=")==0) mode = 7;
    if (strcmp(wort,"output_0=")==0) mode = 8;
    if (strcmp(wort,"input_1=")==0) mode = 9;
    if (strcmp(wort,"input_abstraction=")==0) mode = 10;
    if (strcmp(wort,"input_model=")==0) mode = 11;
    if (strcmp(wort,"logics_model=")==0) mode = 12;

    return mode;
}

/**
 * Reads the cybol tags.
 *
 * @param p0 the cybol file
 * @param p1 the cybol hierarchy structure
 */
int read_cybol_tag(void* p0, void* p1) {
    
    char* wort = (char*) p0;
    int mode = 0; //normalmode

    if (strcmp(wort,"<!--")==0) mode = 1; //Kommentaranfang ... innerhalb model berreich mode 4
    if ((strcmp(wort,"!-->")==0) || (strcmp(wort,"/-->")==0)) mode = 2; //Kommentarende ...innerhalb model bereich 5
    if ((strcmp(wort,"<model>")==0) || (strcmp(wort,"/>")==0)) mode = 3;
    if (strcmp(wort,"<child")==0) mode =6;
    if (strcmp(wort,"</model>")==0) mode =7;

    return mode;
}

/**
 * Reads the cybol file.
 *
 * @param p0 the cybol file
 * @param p1 the cybol hierarchy structure
 */
void read_cybol_file(void* p0, void* p1) {
    
    FILE* fp = (FILE*) p0;
    char zeichen;
  char* wort= (char*) malloc(2000);
	int parsemode = 0, childmode = 0,string_open=0;
	while (zeichen != EOF)
	{
		zeichen = fgetc(fp);
		//kommentare ausserhalb model bereich abfangen ... eigentlich unsinnig, aber vermeidung von interpretation auskommentierter model bereiche
		if (parsemode == 1) {if (schluesselwort(wort) == 2) parsemode = 0; }
		else if (parsemode<3) parsemode = schluesselwort(wort);
		//kommentare innerhalb model breich abfangen
		if (parsemode > 2) {
			if ((schluesselwort(wort) == 1) && (parsemode == 3)) parsemode = 4;
			if ((parsemode == 4) && (schluesselwort(wort) == 2)) parsemode = 5;
			if ((parsemode == 6) && (schluesselwort(wort) == 3)) parsemode = 3;
			if (schluesselwort(wort) > 5) parsemode = schluesselwort(wort);

//**************************************der rest genauso**********************************************

                        if (parsemode == 6) {
                                if ((zeichen == 34)&& (string_open)) {
	//++++++++++++++++++CHILD+++++++++++++++++++++++++
if ((parsemode == 6) && (string_open)) printf(wort);  
//	if ((parsemode == 6) && (string_open)) cout << wort << "Childsektion:  " << childmode<< "\n";
	//++++++++++++++++++++++++++++++++++++++++++++++++
				}
				if ((string_open==0) && (child_schluesselwort(wort)>0)) childmode = child_schluesselwort(wort);
			}

//*******************************************************************************************
		}
//cout << wort << "\n";
//cout << string_open << "   " << childmode << "   " <<parsemode;
		if ((zeichen != EOF))
		{
			if ((zeichen == 10) || (zeichen == 13) || (zeichen == 32) || (zeichen == 34)) wort[0]='\0';
			else wort[strlen(wort)] = zeichen;
			if ((zeichen==34) && (parsemode>5)) {
				if (string_open==1) string_open=0;
				else string_open=1;
			}
		}
	}
        
  free(wort);
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

    FILE* f = fopen(PATH + p1 + CYBOL, "r");

    if (f != (void*) 0) {
    
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
