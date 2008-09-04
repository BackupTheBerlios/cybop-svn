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
 * @version $RCSfile: compound_converter.c,v $ $Revision: 1.25 $ $Date: 2008-09-04 20:31:32 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef COMPOUND_CONVERTER_SOURCE
#define COMPOUND_CONVERTER_SOURCE

//?? Use libxml2 parser as temporary workaround. Later, self-written parsing functions should be used.
#include <libxml/parser.h>
#include <libxml/tree.h>
#include <string.h>
#include "../../globals/constants/character/code/character_code_constants.c"
#include "../../constant/abstraction/cybol/text_cybol_abstraction.c"
#include "../../constant/channel/cybol_channel.c"
#include "../../globals/constants/cybol/cybol_constants.c"
#include "../../globals/constants/cybol/cybol_name_constants.c"
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../constant/model/log/message_log_model.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../logger/logger.c"
#include "../../memoriser/allocator/xml_node_allocator.c"
#include "../../memoriser/allocator/xml_property_allocator.c"
#include "../../memoriser/converter/abstraction_converter.c"
#include "../../memoriser/array.c"
#include "../../memoriser/allocator.c"
#include "../../memoriser/communicator.c"

//
// The type "xmlChar" used by the libxml2 parser is a null-terminated sequence
// of utf-8 characters, in other words: a multibyte character array.
// And only utf-8! One needs to convert strings encoded in different ways
// to utf-8 before passing them to the libxml2 API.
//
// In order to use a null-terminated sequence of utf-8 characters (xmlChar),
// which represents a multi-byte character string, within CYBOI,
// it needs to be converted into a wide character array.
//

//
// Forward declarations.
//

/**
 * Decodes the source into the destination, according to the given language.
 *
 * @param p0 the destination model (Hand over as reference!)
 * @param p1 the destination model count
 * @param p2 the destination model size
 * @param p3 the destination details (Hand over as reference!)
 * @param p4 the destination details count
 * @param p5 the destination details size
 * @param p6 the source
 * @param p7 the source count
 * @param p8 the knowledge memory
 * @param p9 the knowledge memory count
 * @param p10 the language
 * @param p11 the language count
 */
void decode(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11);

/**
 * Sets the compound element by name.
 *
 * @param p0 the compound
 * @param p1 the compound count
 * @param p2 the compound size
 * @param p3 the name
 * @param p4 the name count
 * @param p5 the name size
 * @param p6 the abstraction
 * @param p7 the abstraction count
 * @param p8 the abstraction size
 * @param p9 the model
 * @param p10 the model count
 * @param p11 the model size
 * @param p12 the details
 * @param p13 the details count
 * @param p14 the details size
 */
void set_compound_element_by_name(void* p0, void* p1, void* p2,
    void* p3, void* p4, void* p5, void* p6, void* p7, void* p8,
    void* p9, void* p10, void* p11, void* p12, void* p13, void* p14);

/**
 * Decodes the compound cybol node.
 *
 * @param p0 the destination (a compound model void**)
 * @param p1 the destination count (the count for coumpound model void*)
 * @param p2 the destination size (the size for compound model void*)
 * @param p3 the source (xmlNode*)
 * @param p4 the source count (for this function not relevant void*)
 */
void decode_compound_cybol_nodes(void* p0, void* p1, void* p2, void* p3, void* p4);

/**
 * Decodes the xml stream until an xml comment end tag is reached.
 *
 * This procedure only counts up the stream pointer and
 * changes nothing in the xml model.
 *
 * @param p0 the xml stream
 * @param p1 the xml stream count
 */
/*??
void decode_compound_comment_tag(void* p0, void* p1) {

    if (p1 != *NULL_POINTER_MEMORY_MODEL) {

        int* sc = (int*) p1;

        // The leave flag.
        int l = *NUMBER_0_INTEGER_MEMORY_MODEL;
        // The comparison result.
        int r = *NUMBER_0_INTEGER_MEMORY_MODEL;
        // The current byte within the stream.
        void* b = p0;
        // The remaining bytes count.
        int bc = *sc;

        while (*NUMBER_1_INTEGER_MEMORY_MODEL) {

            if ((l == *NUMBER_1_INTEGER_MEMORY_MODEL) || (bc <= *NUMBER_0_INTEGER_MEMORY_MODEL)) {

                break;
            }

            if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                if (bc >= *END_COMMENT_TAG_COUNT) {

                    compare_array_elements((void*) b, (void*) END_COMMENT_TAG, (void*) END_COMMENT_TAG_COUNT, (void*) &r, (void*) CHARACTER_ARRAY_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        // Move current byte pointer
                        // and remaining bytes count.
                        b = b + *END_COMMENT_TAG_COUNT;
                        bc = bc - *END_COMMENT_TAG_COUNT;

                        // Set leave flag.
                        l = *NUMBER_1_INTEGER_MEMORY_MODEL;
                    }
                }
            }

            if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                if (bc >= *SHORT_END_COMMENT_TAG_COUNT) {

                    compare_array_elements((void*) b, (void*) SHORT_END_COMMENT_TAG, (void*) SHORT_END_COMMENT_TAG_COUNT, (void*) &r, (void*) CHARACTER_ARRAY_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        // Move current byte pointer
                        // and remaining bytes count.
                        b = b + *SHORT_END_COMMENT_TAG_COUNT;
                        bc = bc - *SHORT_END_COMMENT_TAG_COUNT;

                        // Set leave flag.
                        l = *NUMBER_1_INTEGER_MEMORY_MODEL;
                    }
                }
            }

            // If this block is reached, then no known term was found before.
            // The current byte pointer will just be incremented by one so
            // that new characters are read and compared in the next loop cycle.
            if (r != *NUMBER_1_INTEGER_MEMORY_MODEL) {

                // Increment current byte within persistent model.
                b++;
                // Decrement remaining bytes count.
                bc--;
            }

            // Reset comparison result.
            r = *NUMBER_0_INTEGER_MEMORY_MODEL;
        }

    } else {

//??        log_message((void*) &ERROR_LEVEL_LOG_MODEL, (void*) &"Could not initialise compound. The persistent model count is null.");
    }
}
*/

/**
 * Decodes the xml stream into an xml tag.
 *
 * @param p0 the xml model
 * @param p1 the xml model count
 * @param p2 the xml model size
 * @param p3 the xml stream
 * @param p4 the xml stream count
 */
/*??
void decode_compound_tag(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p4 != *NULL_POINTER_MEMORY_MODEL) {

        int* sc = (int*) p4;

        // The leave flag.
        int l = *NUMBER_0_INTEGER_MEMORY_MODEL;
        // The comparison result.
        int r = *NUMBER_0_INTEGER_MEMORY_MODEL;
        // The current byte within the stream.
        void* b = (void*) p3;
        // The remaining bytes count.
        int bc = *sc;

        while (*NUMBER_1_INTEGER_MEMORY_MODEL) {

            if ((l == *NUMBER_1_INTEGER_MEMORY_MODEL) || (bc <= *NUMBER_0_INTEGER_MEMORY_MODEL)) {

                break;
            }

            if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                if (bc >= *EMPTY_TAG_END_COUNT) {

                    compare_array_elements((void*) b, (void*) EMPTY_TAG_END, (void*) EMPTY_TAG_END_COUNT, (void*) &r, (void*) CHARACTER_ARRAY_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        // Move current byte pointer
                        // and remaining bytes count.
                        b = b + *EMPTY_TAG_END_COUNT;
                        bc = bc - *EMPTY_TAG_END_COUNT;

                        // Set leave flag.
                        l = *NUMBER_1_INTEGER_MEMORY_MODEL;
                    }
                }
            }

            if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                if (bc >= *TAG_END_COUNT) {

                    compare_array_elements((void*) b, (void*) TAG_END, (void*) TAG_END_COUNT, (void*) &r, (void*) CHARACTER_ARRAY_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        // Move current byte pointer
                        // and remaining bytes count.
                        b = b + *TAG_END_COUNT;
                        bc = bc - *TAG_END_COUNT;

                        // Decode xml value.
//??                        decode_xml_value((void*) &b, (void*) &bc);
                    }
                }
            }

            // Reset comparison result.
            r = *NUMBER_0_INTEGER_MEMORY_MODEL;
        }

    } else {

//??        log_message((void*) &ERROR_LEVEL_LOG_MODEL, (void*) &"Could not initialise compound. The persistent model count is null.");
    }
}
*/

/**
 * Decodes a cybol property.
 *
 * @param p0 the name (Hand over as reference!)
 * @param p1 the name count
 * @param p2 the name size
 * @param p3 the channel (Hand over as reference!)
 * @param p4 the channel count
 * @param p5 the channel size
 * @param p6 the abstraction (Hand over as reference!)
 * @param p7 the abstraction count
 * @param p8 the abstraction size
 * @param p9 the model (Hand over as reference!)
 * @param p10 the model count
 * @param p11 the model size
 * @param p12 the property value
 * @param p13 the name
 * @param p14 the name count
 */
void decode_compound_cybol_property(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5,
    void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14) {

    if (p12 != *NULL_POINTER_MEMORY_MODEL) {

        xmlNode* pv = (xmlNode*) p12;

        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Decode compound cybol property.");

        // The comparison result.
        int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

        if (pv != *NULL_POINTER_MEMORY_MODEL) {

    fwprintf(stderr, L"TEST decode compound cybol property p12: %i\n", pv);
    fwprintf(stderr, L"TEST decode compound cybol property p13: %s\n", (char*) p13);
    fwprintf(stderr, L"TEST decode compound cybol property p14: %i\n", *((int*) p14));

            if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

    fwprintf(stderr, L"TEST decode compound cybol property NAME_ATTRIBUTE_AS_CHAR: %s\n", NAME_ATTRIBUTE_AS_CHAR);
    fwprintf(stderr, L"TEST decode compound cybol property NAME_ATTRIBUTE_AS_CHAR_COUNT: %i\n", *((int*) NAME_ATTRIBUTE_AS_CHAR_COUNT));

    fwprintf(stderr, L"TEST decode compound cybol property 0: %i\n", r);

                compare_arrays(p13, p14, (void*) NAME_ATTRIBUTE_AS_CHAR, (void*) NAME_ATTRIBUTE_AS_CHAR_COUNT, (void*) &r, (void*) CHARACTER_ARRAY_MEMORY_ABSTRACTION);

    fwprintf(stderr, L"TEST decode compound cybol property 1: %i\n", r);

                if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

    fwprintf(stderr, L"TEST decode compound cybol property 2: %i\n", r);

                    // Determine temporary character array count.
                    int tmpc = strlen((char*) pv->content);

    fwprintf(stderr, L"TEST decode compound cybol property 3 tmpc: %i\n", tmpc);

                    // Get source name.
                    decode_utf_8_unicode_character_vector(p0, p1, p2, (void*) pv->content, (void*) &tmpc);

    fwprintf(stderr, L"TEST decode compound cybol property name: %ls\n", *((wchar_t**) p0));
    fwprintf(stderr, L"TEST decode compound cybol property name count: %i\n", *((int*) p1));

                    /*?? OLD solution. Delete later:
                    *n = pv->content;
                    *nc = strlen((char*) *n);
                    */
                }
            }

            if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                compare_arrays(p13, p14, (void*) CHANNEL_ATTRIBUTE_AS_CHAR, (void*) CHANNEL_ATTRIBUTE_AS_CHAR_COUNT, (void*) &r, (void*) CHARACTER_ARRAY_MEMORY_ABSTRACTION);

                if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    // Determine temporary character array count.
                    int tmpc = strlen((char*) pv->content);

                    // Get source channel.
                    decode_utf_8_unicode_character_vector(p3, p4, p5, (void*) pv->content, (void*) &tmpc);

                    /*?? OLD solution. Delete later:
                    *c = pv->content;
                    *cc = strlen((char*) *c);
                    */
                }
            }

            if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                compare_arrays(p13, p14, (void*) ABSTRACTION_ATTRIBUTE_AS_CHAR, (void*) ABSTRACTION_ATTRIBUTE_AS_CHAR_COUNT, (void*) &r, (void*) CHARACTER_ARRAY_MEMORY_ABSTRACTION);

                if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    // Determine temporary character array count.
                    int tmpc = strlen((char*) pv->content);

                    // Get source abstraction.
                    decode_utf_8_unicode_character_vector(p6, p7, p8, (void*) pv->content, (void*) &tmpc);

                    /*?? OLD solution. Delete later:
                    *a = pv->content;
                    *ac = strlen((char*) *a);
                    */
                }
            }

            if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                compare_arrays(p13, p14, (void*) MODEL_ATTRIBUTE_AS_CHAR, (void*) MODEL_ATTRIBUTE_AS_CHAR_COUNT, (void*) &r, (void*) CHARACTER_ARRAY_MEMORY_ABSTRACTION);

                if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    // Determine temporary character array count.
                    int tmpc = strlen((char*) pv->content);

                    // Get source model.
                    decode_utf_8_unicode_character_vector(p9, p10, p11, (void*) pv->content, (void*) &tmpc);

                    /*?? OLD solution. Delete later:
                    *m = pv->content;
                    *mc = strlen((char*) *m);
                    */
                }
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode compound cybol property. The CASTED property value is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode compound cybol property. The property value is null.");
    }
}

/**
 * Decodes the cybol properties.
 *
 * @param p0 the name (Hand over as reference!)
 * @param p1 the name count
 * @param p2 the name size
 * @param p3 the channel (Hand over as reference!)
 * @param p4 the channel count
 * @param p5 the channel size
 * @param p6 the abstraction (Hand over as reference!)
 * @param p7 the abstraction count
 * @param p8 the abstraction size
 * @param p9 the model (Hand over as reference!)
 * @param p10 the model count
 * @param p11 the model size
 * @param p12 the child node
 */
void decode_compound_cybol_properties(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12) {

    if (p12 != *NULL_POINTER_MEMORY_MODEL) {

        xmlNode* cn = (xmlNode*) p12;

        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Decode compound cybol properties.");

        if (cn != *NULL_POINTER_MEMORY_MODEL) {

            // Determine first child node property.
            xmlAttr* p = cn->properties;
            // The property name.
            void* pn = *NULL_POINTER_MEMORY_MODEL;
            int pnc = *NUMBER_0_INTEGER_MEMORY_MODEL;

            while (*NUMBER_1_INTEGER_MEMORY_MODEL) {

                if (p == *NULL_POINTER_MEMORY_MODEL) {

                    break;
                }

                // Get property name.
                pn = (void*) p->name;
                pnc = strlen(pn);

                // Decode property.
                decode_compound_cybol_property(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, (void*) p->children, pn, (void*) &pnc);

                // Get next child node property.
                p = p->next;
            }

        } else {

    //??        log_message((void*) &ERROR_LEVEL_LOG_MODEL, (void*) &"Could not translate xml node. The source parameter count is null.");
        }

    } else {

//??        log_message((void*) &ERROR_LEVEL_LOG_MODEL, (void*) &"Could not translate xml node. The source parameter count is null.");
    }
}

/**
 * Decodes the compound cybol node.
 *
 * @param p0 the destination (a compound model void**)
 * @param p1 the destination count (the count for coumpound model void*)
 * @param p2 the destination size (the size for compound model void*)
 * @param p3 the source (xmlNode*)
 * @param p4 the source count (for this function not relevant void*)
 */
void decode_compound_cybol_node(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p3 != *NULL_POINTER_MEMORY_MODEL) {

        xmlNode* s = (xmlNode*) p3;

        if (p0 != *NULL_POINTER_MEMORY_MODEL) {

            void** d = (void**) p0;

            log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Decode compound cybol node.");

    fwprintf(stderr, L"TEST decode compound cybol node p3: %i\n", p3);

            // The source name, channel, abstraction, model.
            void* sn = *NULL_POINTER_MEMORY_MODEL;
            int snc = *NUMBER_0_INTEGER_MEMORY_MODEL;
            int sns = *NUMBER_0_INTEGER_MEMORY_MODEL;
            void* sc = *NULL_POINTER_MEMORY_MODEL;
            int scc = *NUMBER_0_INTEGER_MEMORY_MODEL;
            int scs = *NUMBER_0_INTEGER_MEMORY_MODEL;
            void* sa = *NULL_POINTER_MEMORY_MODEL;
            int sac = *NUMBER_0_INTEGER_MEMORY_MODEL;
            int sas = *NUMBER_0_INTEGER_MEMORY_MODEL;
            void* sm = *NULL_POINTER_MEMORY_MODEL;
            int smc = *NUMBER_0_INTEGER_MEMORY_MODEL;
            int sms = *NUMBER_0_INTEGER_MEMORY_MODEL;
            // The destination name, abstraction, model, details.
            void* dn = *NULL_POINTER_MEMORY_MODEL;
            int* dnc = (int*) *NULL_POINTER_MEMORY_MODEL;
            int* dns = (int*) *NULL_POINTER_MEMORY_MODEL;
            void* da = *NULL_POINTER_MEMORY_MODEL;
            int* dac = (int*) *NULL_POINTER_MEMORY_MODEL;
            int* das = (int*) *NULL_POINTER_MEMORY_MODEL;
            void* dm = *NULL_POINTER_MEMORY_MODEL;
            int* dmc = (int*) *NULL_POINTER_MEMORY_MODEL;
            int* dms = (int*) *NULL_POINTER_MEMORY_MODEL;
            void* dd = *NULL_POINTER_MEMORY_MODEL;
            int* ddc = (int*) *NULL_POINTER_MEMORY_MODEL;
            int* dds = (int*) *NULL_POINTER_MEMORY_MODEL;

            // Decode child node properties.
            decode_compound_cybol_properties((void*) &sn, (void*) &snc, (void*) &sns, (void*) &sc, (void*) &scc, (void*) &scs,
                (void*) &sa, (void*) &sac, (void*) &sas, (void*) &sm, (void*) &smc, (void*) &sms, p3);

    fwprintf(stderr, L"TEST decode compound cybol node sn: %ls\n", (wchar_t*) sn);
    fwprintf(stderr, L"TEST decode compound cybol node snc: %i\n", snc);
    fwprintf(stderr, L"TEST decode compound cybol node sc: %ls\n", (wchar_t*) sc);
    fwprintf(stderr, L"TEST decode compound cybol node scc: %i\n", scc);
    fwprintf(stderr, L"TEST decode compound cybol node sa: %ls\n", (wchar_t*) sa);
    fwprintf(stderr, L"TEST decode compound cybol node sac: %i\n", sac);
    fwprintf(stderr, L"TEST decode compound cybol node sm: %ls\n", (wchar_t*) sm);
    fwprintf(stderr, L"TEST decode compound cybol node smc: %i\n", smc);

            //
            // Name.
            //

            // Allocate destination name.
            allocate((void*) &dnc, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
            *dnc = *NUMBER_0_INTEGER_MEMORY_MODEL;
            allocate((void*) &dns, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
            *dns = *NUMBER_0_INTEGER_MEMORY_MODEL;
            allocate((void*) &dn, (void*) dns, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION_COUNT);

            // Decode destination name.
            decode((void*) &dn, (void*) dnc, (void*) dns, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, sn, (void*) &snc, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION_COUNT);

    fwprintf(stderr, L"TEST decode compound cybol node dn: %ls\n", (wchar_t*) dn);
    fwprintf(stderr, L"TEST decode compound cybol node dnc: %i\n", *dnc);

            //
            // Channel.
            //
            // CAUTION! A (transient) destination channel is not created,
            // since that is only needed temporarily for model loading.
            //

            //
            // Abstraction.
            //

            // Allocate destination abstraction.
            allocate((void*) &dac, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
            *dac = *NUMBER_0_INTEGER_MEMORY_MODEL;
            allocate((void*) &das, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
            *das = *NUMBER_0_INTEGER_MEMORY_MODEL;
            allocate((void*) &da, (void*) das, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION_COUNT);

            // Decode destination abstraction.
            decode((void*) &da, (void*) dac, (void*) das, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, sa, (void*) &sac, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION_COUNT);

    fwprintf(stderr, L"TEST decode compound cybol node da: %ls\n", (wchar_t*) da);
    fwprintf(stderr, L"TEST decode compound cybol node dac: %i\n", *dac);

            //
            // Model.
            //

            // The workaround flags for channel- and abstraction comparison.
            // If these are set, the libxml2 parser is used.
            int w1 = *NUMBER_0_INTEGER_MEMORY_MODEL;
            int w2 = *NUMBER_0_INTEGER_MEMORY_MODEL;

            compare_arrays(sc, (void*) &scc, (void*) FILE_CHANNEL, (void*) FILE_CHANNEL_COUNT, (void*) &w1, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
            // CAUTION! Use the original source abstraction and NOT the mapped runtime memory abstraction here!
            // This is necessary because not only the CYBOL abstraction is mapped to COMPOUND,
            // but also other abstractions like XDT are.
            compare_arrays(sa, (void*) &sac, (void*) COMPOUND_ABSTRACTION, (void*) COMPOUND_ABSTRACTION_COUNT, (void*) &w2, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

            if ((w1 != *NUMBER_0_INTEGER_MEMORY_MODEL) && (w2 != *NUMBER_0_INTEGER_MEMORY_MODEL)) {

                // Allocate destination model.
                allocate((void*) &dmc, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
                *dmc = *NUMBER_0_INTEGER_MEMORY_MODEL;
                allocate((void*) &dms, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
                *dms = *NUMBER_0_INTEGER_MEMORY_MODEL;
                allocate((void*) &dm, (void*) dms, sa, (void*) &sac);

                // CAUTION! If a cybol file is to be read, then the libxml2 parser is used.
                // This is just a workaround, until cyboi posesses its own cybol parsing functions.
                // This source code block can then be deleted completely.
                decode((void*) &dm, (void*) dmc, (void*) dms, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, sm, (void*) &smc, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, sa, (void*) &sac);

            } else {

                // The runtime abstraction.
                void* ra = *NULL_POINTER_MEMORY_MODEL;
                int rac = *NUMBER_0_INTEGER_MEMORY_MODEL;

                // Decode source abstraction into runtime abstraction, since a decoded
                // message does not always have the same runtime abstraction.
                // For example, an "xdt" file is converted into a compound.
                decode_abstraction((void*) &ra, (void*) &rac, *NULL_POINTER_MEMORY_MODEL, sa, (void*) &sac);

    fwprintf(stderr, L"TEST decode compound cybol node ra: %ls\n", (wchar_t*) ra);
    fwprintf(stderr, L"TEST decode compound cybol node rac: %i\n", rac);

                // The read model.
                void* rm = *NULL_POINTER_MEMORY_MODEL;
                int rmc = *NUMBER_0_INTEGER_MEMORY_MODEL;
                int rms = *NUMBER_0_INTEGER_MEMORY_MODEL;

                // Allocate read model of type character, to read single bytes.
                allocate((void*) &rm, (void*) &rms, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION_COUNT);

                // Read read model as persistent byte stream over channel.
                read_data((void*) &rm, (void*) &rmc, (void*) &rms, sm, (void*) &smc, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, sc, (void*) &scc);

    fwprintf(stderr, L"TEST decode compound cybol node rm: %ls\n", (wchar_t*) rm);
    fwprintf(stderr, L"TEST decode compound cybol node rmc: %i\n", rmc);

                // Allocate destination model.
                allocate((void*) &dmc, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
                *dmc = *NUMBER_0_INTEGER_MEMORY_MODEL;
                allocate((void*) &dms, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
                *dms = *NUMBER_0_INTEGER_MEMORY_MODEL;
                allocate((void*) &dm, (void*) dms, ra, (void*) &rac);

                // Decode destination model.
                //
                // CAUTION! Use the original source abstraction and NOT the mapped runtime memory abstraction here!
                // This is necessary so that the correct parsing function is called.
                decode((void*) &dm, (void*) dmc, (void*) dms, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, rm, (void*) &rmc, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, sa, (void*) &sac);

                // Deallocate read model.
                deallocate((void*) &rm, (void*) &rms, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION_COUNT);
            }

    fwprintf(stderr, L"TEST decode compound cybol node dm: %i\n", dm);
    fwprintf(stderr, L"TEST decode compound cybol node dmc: %i\n", *dmc);

            //
            // Details.
            //

            // Allocate and decode destination details.
            //
            // CAUTION! Do ALWAYS allocate the details, even if it has no entries!
            // This is because at runtime, properties may be assigned to the details.
            // So, it MUST NOT be null.
            allocate((void*) &ddc, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
            *ddc = *NUMBER_0_INTEGER_MEMORY_MODEL;
            allocate((void*) &dds, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
            *dds = *NUMBER_0_INTEGER_MEMORY_MODEL;
            allocate((void*) &dd, (void*) dds, (void*) COMPOUND_ABSTRACTION, (void*) COMPOUND_ABSTRACTION_COUNT);

            // If child node has children, then decode it for destination details.
            if (s->children != *NULL_POINTER_MEMORY_MODEL) {

                // Decode destination details child node children.
                decode_compound_cybol_nodes((void*) &dd, (void*) ddc, (void*) dds, p3, p4);

    fwprintf(stderr, L"TEST decode compound cybol node dd: %i\n", dd);
    fwprintf(stderr, L"TEST decode compound cybol node ddc: %i\n", *ddc);
            }

            // Add model to compound.
            set_compound_element_by_name(*d, p1, p2,
                dn, (void*) dnc, (void*) dns,
                da, (void*) dac, (void*) das,
                dm, (void*) dmc, (void*) dms,
                dd, (void*) ddc, (void*) dds);

            //?? CAUTION! TODO:
            //?? If "add", then first check if name exists in whole;
            //?? if yes, add "_0" or "_1" or "_2" etc.
            //?? to name, taking first non-existing suffix!
            //?? If "set", then just replace the model
            //?? with equal name.
            //?? PROBLEM: Where to destroy the model if
            //?? no whole keeps a reference to it anymore?

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode compound cybol node. The destination compound is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode compound cybol node. The source xml node is null.");
    }
}

/**
 * Decodes the compound cybol node.
 *
 * @param p0 the destination (a compound model void**)
 * @param p1 the destination count (the count for coumpound model void*)
 * @param p2 the destination size (the size for compound model void*)
 * @param p3 the source (xmlNode*)
 * @param p4 the source count (for this function not relevant void*)
 */
void decode_compound_cybol_nodes(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p3 != *NULL_POINTER_MEMORY_MODEL) {

        xmlNode* s = (xmlNode*) p3;

        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Decode compound cybol nodes.");

        // Determine first child node.
        xmlNode* c = s->children;
        // The child count.
        int cc = *NUMBER_0_INTEGER_MEMORY_MODEL;

        while (*NUMBER_1_INTEGER_MEMORY_MODEL) {

            if (c == *NULL_POINTER_MEMORY_MODEL) {

                break;
            }

    fwprintf(stderr, L"TEST decode compound cybol nodes cc: %i\n", cc);

            if (c->type == XML_ELEMENT_NODE) {

                decode_compound_cybol_node(p0, p1, p2, (void*) c, (void*) &cc);
            }

            c = c->next;
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode compound cybol nodes. The source xml node is null.");
    }
}

/**
 * Decodes the byte stream and creates an xml model from it.
 *
 * CAUTION! This function is a temporary WORKAROUND, to be used until CYBOL-specific
 * parsing functions are written! CYBOL is completely XML-conform, with one exception:
 * XML attributes will not just be demarcated by "", but some special characters which
 * identify the beginning and end of an attribute value. It is not decided yet which
 * character sequence to use, but it might be something like e.g.:
 * attribute="@CYBOLBEGIN@here_comes_the_actual_value@CYBOLEND@"
 *
 * @param p0 the destination (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source xml file name
 * @param p4 the source count
 */
void decode_compound_libxml2_parser_workaround(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p4 != *NULL_POINTER_MEMORY_MODEL) {

        int* sc = (int*) p4;

        if (p3 != *NULL_POINTER_MEMORY_MODEL) {

            void* s = (void*) p3;

            if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                void** d = (void**) p0;

                // Following is a special check to avoid:
                // I/O warning : failed to load external entity ""
                // messages of the xml parser.
                if (*sc > *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Decode compound libxml2 parser workaround.");

                    // The temporary null-terminated file name.
                    void* tmp = *NULL_POINTER_MEMORY_MODEL;
                    int tmpc = *NUMBER_0_INTEGER_MEMORY_MODEL;
                    int tmps = *NUMBER_0_INTEGER_MEMORY_MODEL;

                    // Create temporary null-terminated file name.
                    allocate_array((void*) &tmp, (void*) &tmps, (void*) CHARACTER_ARRAY_MEMORY_ABSTRACTION);

                    // Encode wide character name into multibyte character array.
                    encode_utf_8_unicode_character_vector((void*) &tmp, (void*) &tmpc, (void*) &tmps, p3, p4);

                    if (tmps <= tmpc) {

                        // Increase character array size to have place for the termination character.
                        tmps = tmpc + *NUMBER_1_INTEGER_MEMORY_MODEL;

                        // Reallocate terminated file name as multibyte character array.
                        reallocate_array((void*) &tmp, (void*) &tmpc, (void*) &tmps, (void*) CHARACTER_ARRAY_MEMORY_ABSTRACTION);
                    }

                    // Add null termination character to terminated file name.
                    set_array_elements(tmp, (void*) &tmpc, (void*) NULL_CONTROL_CHARACTER_CODE, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) CHARACTER_ARRAY_MEMORY_ABSTRACTION);

    fwprintf(stderr, L"TEST decode tmp: %s\n", (char*) tmp);
    fwprintf(stderr, L"TEST decode tmpc: %i\n", tmpc);

                    // Initialise the library.
                    // Check potential ABI mismatches between the version
                    // it was compiled for and the actual shared library used.
                    LIBXML_TEST_VERSION

                    // Decode file and get xml document.
                    // This function returns a pointer to type: xmlDoc*
                    xmlDoc* doc = (void*) xmlParseFile((char*) tmp);

                    // Destroy temporary null-terminated file name.
                    deallocate_array((void*) &tmp, (void*) &tmps, (void*) CHARACTER_ARRAY_MEMORY_ABSTRACTION);

                    // Free global variables that may have been allocated by the parser.
                    xmlCleanupParser();

                    // Get root element node.
                    xmlNode* r = xmlDocGetRootElement(doc);

                    // Decode cybol.
                    decode_compound_cybol_nodes(p0, p1, p2, (void*) r, *NULL_POINTER_MEMORY_MODEL);

                    if (doc != *NULL_POINTER_MEMORY_MODEL) {

                        // Deallocate xml dom document.
                        //
                        // CAUTION! This has to be done only AFTER parsing the document nodes!
                        // Otherwise, the document would not exist anymore, so that no nodes could be found.
//??                        xmlFreeDoc((xmlDoc*) *((void**) *d));
                        xmlFreeDoc(doc);

                    } else {

                        log_terminated_message((void*) WARNING_LEVEL_LOG_MODEL, (void*) L"Could not deallocate xml document. Probably, the given cybol file name was empty.");
                    }

                } else {

                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode xml. The file name count is null.");
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode xml. The destination is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode xml. The source is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode xml. The source count is null.");
    }
}

/**
 * Decodes the byte stream message and creates a compound from it.
 *
 * @param p0 the destination compound (Hand over as reference!)
 * @param p1 the destination compound count
 * @param p2 the destination compound size
 * @param p3 the source message
 * @param p4 the source message count
 */
void decode_compound(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Decode compound.");

    decode_compound_libxml2_parser_workaround(p0, p1, p2, p3, p4);

/*??
    // The comparison result.
    int* r = (int*) *NULL_POINTER_MEMORY_MODEL;
    allocate((void*) &r, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
    *r = *NUMBER_0_INTEGER_MEMORY_MODEL;
    // The current byte within the stream.
    void* b = *s;
    // The remaining bytes count.
    int bc = *sc;

    while (*NUMBER_1_INTEGER_MEMORY_MODEL) {

        if (bc <= *NUMBER_0_INTEGER_MEMORY_MODEL) {

            break;
        }

        //
        // Zero decode/parse mode.
        //
        // CAUTION!
        // The order of comparisons is important.
        // Comment tags have to be found before other tags.
        // Otherwise, a comment tag is treated wrongly as normal tag.
        //

        if (d == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            if (bc >= BEGIN_COMMENT_TAG_COUNT) {

                compare_array_elements((void*) &b, (void*) &BEGIN_COMMENT_TAG, (void*) &CHARACTER_ARRAY, (void*) &BEGIN_COMMENT_TAG_COUNT, (void*) &r);

                if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    // Move current byte pointer
                    // and remaining bytes count.
                    b = b + BEGIN_COMMENT_TAG_COUNT;
                    bc = bc - BEGIN_COMMENT_TAG_COUNT;

                    // Decode xml comment tag.
                    decode_xml_comment_tag((void*) &b, (void*) &bc);
                }
            }
        }

        if (d == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            if (bc >= BEGIN_TAG_BEGIN_COUNT) {

                compare_array_elements((void*) &b, (void*) &BEGIN_TAG_BEGIN, (void*) &CHARACTER_ARRAY, (void*) &BEGIN_TAG_BEGIN_COUNT, (void*) &r);

                if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    // Move current byte pointer
                    // and remaining bytes count.
                    b = b + BEGIN_TAG_BEGIN_COUNT;
                    bc = bc - BEGIN_TAG_BEGIN_COUNT;

                    // Initialise xml tag.
                    void* t = *NULL_POINTER_MEMORY_MODEL;
                    int tc = *NUMBER_0_INTEGER_MEMORY_MODEL;
                    int ts = *NUMBER_0_INTEGER_MEMORY_MODEL;

                    // Exceptionally do NOT create and add a new xml tag.
                    // The first tag of an xml file is the root tag.
                    // The corresponding transient xml root tag model
                    // to be used was already handed over to this procedure.
                    // So, use this model instead of creating a new one!
                    // For any other part tags of root, however,
                    // new transient xml tag models have to be created!

                    // Create xml tag.
//??                    allocate_xml_tag((void*) &t, (void*) &ts);

                    // Decode xml tag.
                    decode_xml_tag((void*) &t, (void*) &tc, (void*) &ts,
                        (void*) &b, (void*) &bc);

                    //?? Exit sub procedure above when end tag is reached!

                    // Add xml tag.
//??                    add_xml_tag();
                }
            }
        }

        // If this block is reached, then no known term was found before.
        // The current byte pointer will just be incremented by one so
        // that new characters are read and compared in the next loop cycle.
        if (d == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            // Increment current byte within persistent model.
            b++;
            // Decrement remaining bytes count.
            bc--;
        }

        // Reset comparison result.
        *r = *NUMBER_0_INTEGER_MEMORY_MODEL;
    }
*/
}

/**
 * Encodes the compound into a byte stream message.
 *
 * @param p0 the destination message (Hand over as reference!)
 * @param p1 the destination message count
 * @param p2 the destination message size
 * @param p3 the source compound
 * @param p4 the source compound count
 */
void encode_compound(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Encode compound.");
}

/* COMPOUND_CONVERTER_SOURCE */
#endif
