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
 * @version $Revision: 1.5 $ $Date: 2004-09-08 23:34:12 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef XML_TRANSLATOR_SOURCE
#define XML_TRANSLATOR_SOURCE

#include <libxml/tree.h>
#include <string.h>
#include "../array/array.c"
#include "../creator/compound_creator.c"
#include "../creator/xml_node_creator.c"
#include "../creator/xml_property_creator.c"
#include "../global/character_constants.c"
#include "../global/cybol_constants.c"
#include "../global/log_constants.c"
#include "../logger/logger.c"

//
// Xml property.
//

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

//
// Xml node.
//

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
            // Child nodes.
            //

            // The name.
            void* n = NULL_POINTER;
            int nc = 0;
            int ns = 0;
            // The channel.
            void* c = NULL_POINTER;
            int cc = 0;
            int cs = 0;
            // The abstraction.
            void* a = NULL_POINTER;
            int ac = 0;
            int as = 0;
            // The model.
            void* m = NULL_POINTER;
            int mc = 0;
            int ms = 0;

            // Determine first child node.
            xmlNode* cn = (*s)->children;
            // The child node property.
            xmlAttr* p = NULL_POINTER;

            // The property name.
            char* pn = NULL_POINTER;
            int pnc = 0;

            // The done flag.
            int d = 0;
            // The comparison result.
            int r = 0;

            while (1) {

                if (cn == NULL_POINTER) {

                    break;
                }

                if (cn->type == XML_ELEMENT_NODE) {

                    // Get node name (part | property | constraint):
                    // cn->name

                    //
                    // Child node properties.
                    //

                    // Determine first child node property.
                    p = cn->properties;

                    while (1) {

                        if (p == NULL_POINTER) {

                            break;
                        }

                        // Get property name.
                        pn = (char*) p->name;
                        pnc = strlen(pn) - 1;

//?? ---
                        // Reset done flag.
                        d = 0;
                        // Reset comparison result.
                        r = 0;

                        if (d == 0) {

                            compare_arrays((void*) &pn, (void*) &pnc, (void*) &NAME_ATTRIBUTE, (void*) &NAME_ATTRIBUTE_COUNT, (void*) &r, (void*) &CHARACTER_ARRAY);

                            if (r == 1) {

                                // Create a (transient) name.

                                d = 1;
                            }
                        }

                        if (d == 0) {

                            compare_arrays((void*) &pn, (void*) &pnc, (void*) &CHANNEL_ATTRIBUTE, (void*) &CHANNEL_ATTRIBUTE_COUNT, (void*) &r, (void*) &CHARACTER_ARRAY);

                            if (r == 1) {

                                // Create a (transient) channel.
                                // TEMPORARY only, for receiving (reading) data!?

                                d = 1;
                            }
                        }

                        if (d == 0) {

                            compare_arrays((void*) &pn, (void*) &pnc, (void*) &ABSTRACTION_ATTRIBUTE, (void*) &ABSTRACTION_ATTRIBUTE_COUNT, (void*) &r, (void*) &CHARACTER_ARRAY);

                            if (r == 1) {

                                // Create a (transient) abstraction.

                                d = 1;
                            }
                        }

                        if (d == 0) {

                            compare_arrays((void*) &pn, (void*) &pnc, (void*) &MODEL_ATTRIBUTE, (void*) &MODEL_ATTRIBUTE_COUNT, (void*) &r, (void*) &CHARACTER_ARRAY);

                            if (r == 1) {

                                // Create a (transient) model.

                                d = 1;
                            }
                        }
//?? ---

                        // p->children->content

                        // Decode child node property.
                        //?? decode_xml_property(p0, p1, p2, (void*) &p, p4);

                        // Reset property name.
                        pn = NULL_POINTER;
                        pnc = 0;

                        p = p->next;
                    }

                    // If child has children, then create details model for it.

                    // Read details.
                    // Filter out all tags with name attribute value "super" and
                    // hand over model to create parts of super model.
                    // Add all details to details model.
                    // Do NOT add super tags to details model!

                    // Hand over model.
                    // Receive across channel.
                    // Read abstraction.
                    // Initialize it with the actual persistent model.

                    // Decode children.
                    //?? decode_xml_node(p0, p1, p2, (void*) &c, p4);
                }

                cn = cn->next;
            }

        } else {

//??            log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not translate xml node. The source is null.");
        }

    } else {

//??        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not translate xml node. The source count is null.");
    }
}

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

//
// Xml model.
//

/**
 * Decodes the xml model and creates a cyboi compound from it.
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

/**
 * Encodes the cyboi compound and creates an xml model from it.
 *
 * @param p0 the destination
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source
 * @param p4 the source count
 */
void encode_xml(void* p0, void* p1, void* p2, const void* p3, const void* p4) {
}

/* XML_TRANSLATOR_SOURCE */
#endif
