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
 * @version $Revision: 1.6 $ $Date: 2004-09-09 09:07:47 $ $Author: christian $
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
#include "../global/abstraction_constants.c"
#include "../global/channel_constants.c"
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
            // Source variables (persistent).
            //

            // Determine first child node.
            xmlNode* c = (*s)->children;
            // The child node property.
            xmlAttr* p = NULL_POINTER;
            // The property name.
            char* n = NULL_POINTER;
            int nc = 0;
            // The source name.
            void* sn = NULL_POINTER;
            int snc = 0;
            int sns = 0;
            // The source channel.
            void* sc = NULL_POINTER;
            int scc = 0;
            int scs = 0;
            // The source abstraction.
            void* sa = NULL_POINTER;
            int sac = 0;
            int sas = 0;
            // The source model.
            void* sm = NULL_POINTER;
            int smc = 0;
            int sms = 0;

            //
            // Destination variables (transient).
            //

            // The destination name.
            void* dn = NULL_POINTER;
            int dnc = 0;
            int dns = 0;
            // The destination abstraction.
            void* da = NULL_POINTER;
            int dac = 0;
            int das = 0;
            // The destination model.
            void* dm = NULL_POINTER;
            int dmc = 0;
            int dms = 0;

            // The done flag.
            int d = 0;
            // The comparison result.
            int r = 0;

            while (1) {

                if (c == NULL_POINTER) {

                    break;
                }

                if (c->type == XML_ELEMENT_NODE) {

                    //
                    // Child node properties.
                    //

                    // Determine first child node property.
                    p = c->properties;

                    while (1) {

                        if (p == NULL_POINTER) {

                            break;
                        }

                        // Get property name.
                        n = (char*) p->name;
                        nc = strlen(n) - 1;

//?? ---
                        // Reset done flag.
                        d = 0;
                        // Reset comparison result.
                        r = 0;

                        if (d == 0) {

                            compare_arrays((void*) &n, (void*) &nc, (void*) &NAME_ATTRIBUTE, (void*) &NAME_ATTRIBUTE_COUNT, (void*) &r, (void*) &CHARACTER_ARRAY);

                            if (r == 1) {

                                // Create a (transient) name.

                                d = 1;
                            }
                        }

                        if (d == 0) {

                            compare_arrays((void*) &n, (void*) &nc, (void*) &CHANNEL_ATTRIBUTE, (void*) &CHANNEL_ATTRIBUTE_COUNT, (void*) &r, (void*) &CHARACTER_ARRAY);

                            if (r == 1) {

                                // Create a (transient) channel.
                                // TEMPORARY only, for receiving (reading) data!?

                                d = 1;
                            }
                        }

                        if (d == 0) {

                            compare_arrays((void*) &n, (void*) &nc, (void*) &ABSTRACTION_ATTRIBUTE, (void*) &ABSTRACTION_ATTRIBUTE_COUNT, (void*) &r, (void*) &CHARACTER_ARRAY);

                            if (r == 1) {

                                // Create a (transient) abstraction.

                                d = 1;
                            }
                        }

                        if (d == 0) {

                            compare_arrays((void*) &n, (void*) &nc, (void*) &MODEL_ATTRIBUTE, (void*) &MODEL_ATTRIBUTE_COUNT, (void*) &r, (void*) &CHARACTER_ARRAY);

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
                        n = NULL_POINTER;
                        nc = 0;

                        p = p->next;
                    }

                    // Get node name (part | property | constraint):
                    // c->name

                    // Create name.
                    create_model((void*) &dn, (void*) &dnc, (void*) &dns,
                        (void*) &sn, (void*) &snc,
                        (void*) &STRING_ABSTRACTION, (void*) &STRING_ABSTRACTION_COUNT,
                        (void*) &INLINE_CHANNEL, (void*) &INLINE_CHANNEL_COUNT);

                    // Create abstraction.
                    create_model((void*) &da, (void*) &dac, (void*) &das,
                        (void*) &sa, (void*) &sac,
                        (void*) &STRING_ABSTRACTION, (void*) &STRING_ABSTRACTION_COUNT,
                        (void*) &INLINE_CHANNEL, (void*) &INLINE_CHANNEL_COUNT);

                    // Create model.
                    create_model((void*) &dm, (void*) &dmc, (void*) &dms,
                        (void*) &sm, (void*) &smc,
                        (void*) &sa, (void*) &sac,
                        (void*) &sc, (void*) &scc);

                    // Add child node to destination.
                    //?? ...

                    // If child has children, then create details model for it.

                    // Read details.
                    // Filter out all tags with name attribute value "super" and
                    // hand over model to create parts of super model.
                    // Add all details to details model.
                    // Do NOT add super tags to details model!

                    // Decode children.
                    //?? decode_xml_node(p0, p1, p2, (void*) &c, p4);
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
