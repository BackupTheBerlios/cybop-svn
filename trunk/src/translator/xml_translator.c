/*
 * $RCSfile: xml_translator.c,v $
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
 * This file contains the functionality to:
 * - encode a cyboi knowledge tree (compound) into an xml (dom) tree
 * - decode an xml (dom) tree into a cyboi knowledge tree (compound)
 *
 * @version $Revision: 1.2 $ $Date: 2004-08-13 22:37:50 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef XML_TRANSLATOR_SOURCE
#define XML_TRANSLATOR_SOURCE

#include <libxml/tree.h>
#include "../array/array.c"
#include "../global/character_constants.c"
#include "../global/log_constants.c"
#include "../logger/logger.c"
#include "../state/compound.c"
#include "../state/xml_attribute.c"
#include "../state/xml_tag.c"

//
// Xml property.
//

/**
 * Encodes the cyboi model into an xml property.
 *
 * @param p0 the destination
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source
 * @param p4 the source count
 */
void encode_xml_property(void* p0, void* p1, void* p2, const void* p3, const void* p4) {
}

/**
 * Decodes the xml property into a cyboi model.
 *
 * @param p0 the destination
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source
 * @param p4 the source count
 */
void decode_xml_property(void* p0, void* p1, void* p2, const void* p3, const void* p4) {
}

//
// Xml node.
//

/**
 * Encodes the cyboi model into an xml node.
 *
 * @param p0 the destination
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source
 * @param p4 the source count
 */
void encode_xml_node(void* p0, void* p1, void* p2, const void* p3, const void* p4) {
}

/**
 * Decodes the xml node into a cyboi model.
 *
 * @param p0 the destination
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source
 * @param p4 the source count
 */
void decode_xml_node(void* p0, void* p1, void* p2, const void* p3, const void* p4) {

    if (p4 != NULL_POINTER) {

        int* sc = (int*) p4;

        if (p3 != NULL_POINTER) {

            xmlNode** s = (xmlNode**) p3;

            //
            // Compare node name ("compound property" or "compound constraint")
            // using: (*s)->name
            //

            //
            // Properties.
            //

            // Determine first property.
            xmlAttr* p = (*s)->properties;

            while (1) {

                if (p == NULL_POINTER) {

                    break;
                }

                // Decode property.
                decode_xml_property(p0, p1, p2, (void*) &p, p4);

                p = p->next;
            }

/*??
            xmlAttr* cur_attr = NULL_POINTER;

            for (cur_attr = n->properties; cur_attr; cur_attr = cur_attr->next) {

                printf("  Attributname: %s\n", cur_attr->name);
                printf("  Attributwert: %s\n", cur_attr->children->content);
            }
*/

            //
            // Children.
            //

            // Determine first child node.
            xmlNode* c = (*s)->children;

            while (1) {

                if (c == NULL_POINTER) {

                    break;
                }

                if (c->type == XML_ELEMENT_NODE) {

                    // Decode children.
                    decode_xml_node(p0, p1, p2, (void*) &c, p4);
                }

                c = c->next;
            }

        } else {

//??            log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not translate xml node. The source is null.");
        }

    } else {

//??        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not translate xml node. The source count is null.");
    }
}

//
// Xml model.
//

/**
 * Encodes the cyboi model into an xml model.
 *
 * @param p0 the destination
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source
 * @param p4 the source count
 */
void encode_xml(void* p0, void* p1, void* p2, const void* p3, const void* p4) {
}

/**
 * Decodes the xml model into a cyboi model.
 *
 * @param p0 the destination
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source
 * @param p4 the source count
 */
void decode_xml(void* p0, void* p1, void* p2, const void* p3, const void* p4) {

    //??
    //?? BEGIN of temporary workaround for using the libxml2 parser.
    //?? The strings contained in the xml tree are terminated by a null character
    //?? which must be deleted for the cyboi model,
    //?? or neglected in the "count" number!
    //??

    if (p4 != NULL_POINTER) {

        int* sc = (int*) p4;

        if (p3 != NULL_POINTER) {

            void** s = (void**) p3;

            if (p0 != NULL_POINTER) {

                void** d = (void**) p0;

                // Get root element node.
                xmlNode* r = xmlDocGetRootElement((xmlDoc*) *s);

                decode_xml_node(p0, p1, p2, (void*) &r, p4);

            } else {

//??                log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not translate xml. The destination is null.");
            }

        } else {

//??            log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not translate xml. The source is null.");
        }

    } else {

//??        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not translate xml. The source count is null.");
    }

    //??
    //?? END of temporary workaround for using the libxml2 parser.
    //??
}

/* XML_TRANSLATOR_SOURCE */
#endif
