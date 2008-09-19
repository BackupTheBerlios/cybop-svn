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
 * @version $RCSfile: cybol_converter.c,v $ $Revision: 1.9 $ $Date: 2008-09-19 14:16:26 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef XML_CONVERTER_SOURCE
#define XML_CONVERTER_SOURCE

#include "../../constant/abstraction/cybol/text_cybol_abstraction.c"
#include "../../constant/channel/cybol_channel.c"
#include "../../constant/model/log/message_log_model.c"
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../src/constant/name/xml_name.c"
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
void set_cybol_element_by_name(void* p0, void* p1, void* p2,
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
void decode_cybol_cybol_nodes(void* p0, void* p1, void* p2, void* p3, void* p4);

/**
 * Allocates the model.
 *
 * @param p0 the model (Hand over as reference!)
 * @param p1 the model size
 * @param p2 the abstraction
 * @param p3 the abstraction count
 */
/*??
void decode_cybol_allocate_model(void* p0, void* p1, void* p2, void* p3) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Allocate model.");

    // The comparison result.
    int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(p2, p3, (void*) KNOWLEDGE_PATH_CYBOL_ABSTRACTION, (void*) KNOWLEDGE_PATH_CYBOL_ABSTRACTION_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            allocate_wide_character_vector(p0, p1);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(p2, p3, (void*) ENCAPSULATED_KNOWLEDGE_PATH_CYBOL_ABSTRACTION, (void*) ENCAPSULATED_KNOWLEDGE_PATH_CYBOL_ABSTRACTION_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            allocate_wide_character_vector(p0, p1);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(p2, p3, (void*) CYBOL_MEMORY_ABSTRACTION, (void*) CYBOL_MEMORY_ABSTRACTION_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            allocate_cybol(p0, p1);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(p2, p3, (void*) PLAIN_OPERATION_CYBOL_ABSTRACTION, (void*) PLAIN_OPERATION_CYBOL_ABSTRACTION_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            allocate_wide_character_vector(p0, p1);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(p2, p3, (void*) CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            allocate_character_vector(p0, p1);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(p2, p3, (void*) BOOLEAN_LOGICVALUE_CYBOL_ABSTRACTION, (void*) BOOLEAN_LOGICVALUE_CYBOL_ABSTRACTION_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            allocate_integer_vector(p0, p1);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(p2, p3, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            allocate_integer_vector(p0, p1);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(p2, p3, (void*) UNSIGNED_LONG_VECTOR_MEMORY_ABSTRACTION, (void*) UNSIGNED_LONG_VECTOR_MEMORY_ABSTRACTION_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            allocate_unsigned_long_vector(p0, p1);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(p2, p3, (void*) DECIMAL_FRACTION_NUMBER_CYBOL_ABSTRACTION, (void*) DECIMAL_FRACTION_NUMBER_CYBOL_ABSTRACTION_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            allocate_double_vector(p0, p1);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(p2, p3, (void*) VULGAR_FRACTION_NUMBER_CYBOL_ABSTRACTION, (void*) VULGAR_FRACTION_NUMBER_CYBOL_ABSTRACTION_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            allocate_fraction(p0, p1);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(p2, p3, (void*) CARTESIAN_COMPLEX_NUMBER_CYBOL_ABSTRACTION, (void*) CARTESIAN_COMPLEX_NUMBER_CYBOL_ABSTRACTION_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            allocate_complex(p0, p1);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(p2, p3, (void*) HXP_ABSTRACTION, (void*) HXP_ABSTRACTION_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            allocate_xml_node(p0, p1);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        log_terminated_message((void*) WARNING_LEVEL_LOG_MODEL, (void*) L"Could not allocate model. The abstraction is unknown.");
    }
}
*/

/**
 * Decodes the xml array until an xml comment end tag is reached.
 *
 * This procedure only counts up the array pointer and
 * changes nothing in the xml model.
 *
 * @param p0 the xml array
 * @param p1 the xml array count
 */
/*??
void decode_cybol_comment_tag(void* p0, void* p1) {

    if (p1 != *NULL_POINTER_MEMORY_MODEL) {

        int* sc = (int*) p1;

        // The leave flag.
        int l = *NUMBER_0_INTEGER_MEMORY_MODEL;
        // The comparison result.
        int r = *NUMBER_0_INTEGER_MEMORY_MODEL;
        // The current byte within the array.
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
 * Decodes the xml array into an xml tag.
 *
 * @param p0 the xml model
 * @param p1 the xml model count
 * @param p2 the xml model size
 * @param p3 the xml array
 * @param p4 the xml array count
 */
/*??
void decode_cybol_tag(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p4 != *NULL_POINTER_MEMORY_MODEL) {

        int* sc = (int*) p4;

        // The leave flag.
        int l = *NUMBER_0_INTEGER_MEMORY_MODEL;
        // The comparison result.
        int r = *NUMBER_0_INTEGER_MEMORY_MODEL;
        // The current byte within the array.
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
void decode_cybol_cybol_property(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5,
    void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14) {

/*??
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
/*??
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
/*??
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
/*??
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
/*??
                }
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode compound cybol property. The CASTED property value is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode compound cybol property. The property value is null.");
    }
*/
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
void decode_cybol_cybol_properties(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12) {

/*??
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
                decode_cybol_cybol_property(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, (void*) p->children, pn, (void*) &pnc);

                // Get next child node property.
                p = p->next;
            }

        } else {

    //??        log_message((void*) &ERROR_LEVEL_LOG_MODEL, (void*) &"Could not translate xml node. The source parameter count is null.");
        }

    } else {

//??        log_message((void*) &ERROR_LEVEL_LOG_MODEL, (void*) &"Could not translate xml node. The source parameter count is null.");
    }
*/
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
void decode_cybol_cybol_node(void* p0, void* p1, void* p2, void* p3, void* p4) {

/*??
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
            decode_cybol_cybol_properties((void*) &sn, (void*) &snc, (void*) &sns, (void*) &sc, (void*) &scc, (void*) &scs,
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
            allocate((void*) &dnc, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION_COUNT);
            *dnc = *NUMBER_0_INTEGER_MEMORY_MODEL;
            allocate((void*) &dns, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION_COUNT);
            *dns = *NUMBER_0_INTEGER_MEMORY_MODEL;
            allocate((void*) &dn, (void*) dns, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT);

            // Decode destination name.
            decode((void*) &dn, (void*) dnc, (void*) dns, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, sn, (void*) &snc, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT);

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
            allocate((void*) &dac, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION_COUNT);
            *dac = *NUMBER_0_INTEGER_MEMORY_MODEL;
            allocate((void*) &das, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION_COUNT);
            *das = *NUMBER_0_INTEGER_MEMORY_MODEL;
            allocate((void*) &da, (void*) das, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT);

            // Decode destination abstraction.
            decode((void*) &da, (void*) dac, (void*) das, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, sa, (void*) &sac, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT);

    fwprintf(stderr, L"TEST decode compound cybol node da: %ls\n", (wchar_t*) da);
    fwprintf(stderr, L"TEST decode compound cybol node dac: %i\n", *dac);

            //
            // Model.
            //

            // The workaround flags for channel- and abstraction comparison.
            // If these are set, the libxml2 parser is used.
            int w1 = *NUMBER_0_INTEGER_MEMORY_MODEL;
            int w2 = *NUMBER_0_INTEGER_MEMORY_MODEL;

            compare_arrays(sc, (void*) &scc, (void*) FILE_CYBOL_CHANNEL, (void*) FILE_CYBOL_CHANNEL_COUNT, (void*) &w1, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
            // CAUTION! Use the original source abstraction and NOT the mapped runtime memory abstraction here!
            // This is necessary because not only the CYBOL abstraction is mapped to COMPOUND,
            // but also other abstractions like XDT are.
            compare_arrays(sa, (void*) &sac, (void*) COMPOUND_MEMORY_ABSTRACTION, (void*) COMPOUND_MEMORY_ABSTRACTION_COUNT, (void*) &w2, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

            if ((w1 != *NUMBER_0_INTEGER_MEMORY_MODEL) && (w2 != *NUMBER_0_INTEGER_MEMORY_MODEL)) {

                // Allocate destination model.
                allocate((void*) &dmc, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION_COUNT);
                *dmc = *NUMBER_0_INTEGER_MEMORY_MODEL;
                allocate((void*) &dms, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION_COUNT);
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
                allocate((void*) &rm, (void*) &rms, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT);

                // Read read model as persistent byte array over channel.
                read_data((void*) &rm, (void*) &rmc, (void*) &rms, sm, (void*) &smc, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, sc, (void*) &scc);

    fwprintf(stderr, L"TEST decode compound cybol node rm: %ls\n", (wchar_t*) rm);
    fwprintf(stderr, L"TEST decode compound cybol node rmc: %i\n", rmc);

                // Allocate destination model.
                allocate((void*) &dmc, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION_COUNT);
                *dmc = *NUMBER_0_INTEGER_MEMORY_MODEL;
                allocate((void*) &dms, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION_COUNT);
                *dms = *NUMBER_0_INTEGER_MEMORY_MODEL;
                allocate((void*) &dm, (void*) dms, ra, (void*) &rac);

                // Decode destination model.
                //
                // CAUTION! Use the original source abstraction and NOT the mapped runtime memory abstraction here!
                // This is necessary so that the correct parsing function is called.
                decode((void*) &dm, (void*) dmc, (void*) dms, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, rm, (void*) &rmc, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, sa, (void*) &sac);

                // Deallocate read model.
                deallocate((void*) &rm, (void*) &rms, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
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
            allocate((void*) &ddc, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION_COUNT);
            *ddc = *NUMBER_0_INTEGER_MEMORY_MODEL;
            allocate((void*) &dds, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION_COUNT);
            *dds = *NUMBER_0_INTEGER_MEMORY_MODEL;
            allocate((void*) &dd, (void*) dds, (void*) COMPOUND_MEMORY_ABSTRACTION, (void*) COMPOUND_MEMORY_ABSTRACTION_COUNT);

            // If child node has children, then decode it for destination details.
            if (s->children != *NULL_POINTER_MEMORY_MODEL) {

                // Decode destination details child node children.
                decode_cybol_cybol_nodes((void*) &dd, (void*) ddc, (void*) dds, p3, p4);

    fwprintf(stderr, L"TEST decode compound cybol node dd: %i\n", dd);
    fwprintf(stderr, L"TEST decode compound cybol node ddc: %i\n", *ddc);
            }

            // Add model to compound.
            set_cybol_element_by_name(*d, p1, p2,
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
*/
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
void decode_cybol_cybol_nodes(void* p0, void* p1, void* p2, void* p3, void* p4) {

/*??
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

                decode_cybol_cybol_node(p0, p1, p2, (void*) c, (void*) &cc);
            }

            c = c->next;
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode compound cybol nodes. The source xml node is null.");
    }
*/
}

/**
 * Decodes the byte array and creates an xml model from it.
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
void decode_cybol_libxml2_parser_workaround(void* p0, void* p1, void* p2, void* p3, void* p4) {

/*??
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
                    set_array_elements(tmp, (void*) &tmpc, (void*) NULL_CONTROL_ASCII_CHARACTER_CODE_MODEL, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) CHARACTER_ARRAY_MEMORY_ABSTRACTION);

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
                    decode_cybol_cybol_nodes(p0, p1, p2, (void*) r, *NULL_POINTER_MEMORY_MODEL);

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
*/
}

/**
 * Processes the cybol declaration content.
 *
 * @param p0 the current byte (Hand over as reference!)
 * @param p1 the remaining bytes count
 */
void decode_cybol_process_declaration_content(void* p0, void* p1) {

/*??
    if (p0 != *NULL_POINTER_MEMORY_MODEL) {

        void** b = (void**) p0;

        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Process cybol declaration content.");

        // The comparison result.
        int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            compare_arrays(*b, p1, (void*) DECLARATION_END_XML_NAME, (void*) DECLARATION_END_XML_NAME_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

            if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                // Set "declaration" mode flag.
                dec = *NUMBER_1_INTEGER_MEMORY_MODEL;
            }
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not process cybol declaration content. The current byte is null.");
    }
*/
}

/**
 * Processes the cybol declaration.
 *
 * @param p0 the current byte (Hand over as reference!)
 * @param p1 the remaining bytes count
 */
void decode_cybol_process_declaration(void* p0, void* p1) {

/*??
    if (p1 != *NULL_POINTER_MEMORY_MODEL) {

        int* rem = (int*) p1;

        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Process cybol declaration.");

        while (*NUMBER_1_INTEGER_MEMORY_MODEL) {

            if (*rem <= *NUMBER_0_INTEGER_MEMORY_MODEL) {

                break;
            }

            decode_cybol_declaration_content(p0, p1);

            // Decrement remaining bytes count.
            rem--;
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not process cybol declaration. The remaining bytes count is null.");
    }
*/
}

/**
 * Detects the xml attribute value end.
 *
 * @param p0 the current position (Hand over as reference!)
 * @param p1 the remaining count
 * @param p2 the comparison result
 */
void decode_xml_detect_attribute_value_end(void* p0, void* p1, void* p2) {

    if (p2 != *NULL_POINTER_MEMORY_MODEL) {

        int* r = (int*) p2;

        if (p1 != *NULL_POINTER_MEMORY_MODEL) {

            int* rem = (int*) p1;

            if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                void** pos = (void**) p0;

                log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Detect xml attribute value end.");

                if (*rem >= *ATTRIBUTE_VALUE_END_XML_NAME_COUNT) {

                    // CAUTION! This comparison is IMPORTANT!
                    // Many "detect" functions may be called in a sequence.
                    // If the result of one detection function was positive (*r == 1),
                    // then that function increments the current position and decrements the remaining count.
                    // In this case, further detection functions following afterwards might detect
                    // further characters and change the current position and remaining count, and so forth,
                    // which would have the effect of "jumping" over some characters and produce WRONG RESULTS!
                    // Therefore, this check avoids another comparison if the result already has a value unequal zero.
                    if (*r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        compare_arrays(*pos, (void*) ATTRIBUTE_VALUE_END_XML_NAME_COUNT, (void*) ATTRIBUTE_VALUE_END_XML_NAME, (void*) ATTRIBUTE_VALUE_END_XML_NAME_COUNT, p2, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

                        if (*r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                            // Increment current position.
                            *pos = *pos + (*ATTRIBUTE_VALUE_END_XML_NAME_COUNT * *POINTER_PRIMITIVE_SIZE);

                            // Decrement remaining count.
                            *rem = *rem - *ATTRIBUTE_VALUE_END_XML_NAME_COUNT;
                        }
                    }

                } else {

                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not detect xml attribute value end. The remaining count is too small.");
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not detect xml attribute value end. The current position is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not detect xml attribute value end. The remaining count is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not detect xml attribute value end. The comparison result is null.");
    }
}

/**
 * Processes the xml attribute value.
 *
 * @param p0 the current position (Hand over as reference!)
 * @param p1 the remaining count
 * @param p2 the attribute value (Hand over as reference!)
 * @param p3 the attribute value count
 */
void decode_xml_process_attribute_value(void* p0, void* p1, void* p2, void* p3) {

    if (p3 != *NULL_POINTER_MEMORY_MODEL) {

        int* avc = (int*) p3;

        if (p2 != *NULL_POINTER_MEMORY_MODEL) {

            void** av = (void**) p2;

            if (p1 != *NULL_POINTER_MEMORY_MODEL) {

                int* rem = (int*) p1;

                if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                    void** pos = (void**) p0;

                    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Process xml attribute value.");

                    // Set attribute value.
                    *av = *pos;

                    // The comparison result.
                    int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

                    while (*NUMBER_1_INTEGER_MEMORY_MODEL) {

                        if (*rem <= *NUMBER_0_INTEGER_MEMORY_MODEL) {

                            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not process attribute value. The remaining count is zero or smaller.");

                            break;
                        }

                        decode_xml_detect_attribute_value_end(p0, p1, (void*) &r);

                        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                            // Increment current position.
                            *pos = *pos + *POINTER_PRIMITIVE_SIZE;

                            // Decrement remaining count.
                            *rem = *rem - *NUMBER_1_INTEGER_MEMORY_MODEL;

                            // Increment attribute value count.
                            (*avc)++;

                        } else {

                            //
                            // The attribute value end was found.
                            //
                            // CAUTION! In this case, the current position and remaining count
                            // were already changed in the called function, to be processed further
                            // in other functions.
                            //
                            // The attribute value and count are left as they are.
                            //

                            break;
                        }
                    }

                } else {

                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not process xml attribute value. The current position is null.");
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not process xml attribute value. The remaining count is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not process xml attribute value. The attribute is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not process xml attribute value. The attribute count is null.");
    }
}

/**
 * Detects the xml attribute name end.
 *
 * @param p0 the current position (Hand over as reference!)
 * @param p1 the remaining count
 * @param p2 the comparison result
 */
void decode_xml_detect_attribute_name_end(void* p0, void* p1, void* p2) {

    if (p2 != *NULL_POINTER_MEMORY_MODEL) {

        int* r = (int*) p2;

        if (p1 != *NULL_POINTER_MEMORY_MODEL) {

            int* rem = (int*) p1;

            if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                void** pos = (void**) p0;

                log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Detect xml attribute name end.");

                if (*rem >= *ATTRIBUTE_NAME_END_XML_NAME_COUNT) {

                    // CAUTION! This comparison is IMPORTANT!
                    // Many "detect" functions may be called in a sequence.
                    // If the result of one detection function was positive (*r == 1),
                    // then that function increments the current position and decrements the remaining count.
                    // In this case, further detection functions following afterwards might detect
                    // further characters and change the current position and remaining count, and so forth,
                    // which would have the effect of "jumping" over some characters and produce WRONG RESULTS!
                    // Therefore, this check avoids another comparison if the result already has a value unequal zero.
                    if (*r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        compare_arrays(*pos, (void*) ATTRIBUTE_NAME_END_XML_NAME_COUNT, (void*) ATTRIBUTE_NAME_END_XML_NAME, (void*) ATTRIBUTE_NAME_END_XML_NAME_COUNT, p2, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

                        if (*r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                            // Increment current position.
                            *pos = *pos + (*ATTRIBUTE_NAME_END_XML_NAME_COUNT * *POINTER_PRIMITIVE_SIZE);

                            // Decrement remaining count.
                            *rem = *rem - *ATTRIBUTE_NAME_END_XML_NAME_COUNT;
                        }
                    }

                } else {

                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not detect xml attribute name end. The remaining count is too small.");
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not detect xml attribute name end. The current position is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not detect xml attribute name end. The remaining count is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not detect xml attribute name end. The comparison result is null.");
    }
}

/**
 * Processes the xml attribute name.
 *
 * @param p0 the current position (Hand over as reference!)
 * @param p1 the remaining count
 * @param p2 the attribute name (Hand over as reference!)
 * @param p3 the attribute name count
 */
void decode_xml_process_attribute_name(void* p0, void* p1, void* p2, void* p3) {

    if (p3 != *NULL_POINTER_MEMORY_MODEL) {

        int* anc = (int*) p3;

        if (p2 != *NULL_POINTER_MEMORY_MODEL) {

            void** an = (void**) p2;

            if (p1 != *NULL_POINTER_MEMORY_MODEL) {

                int* rem = (int*) p1;

                if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                    void** pos = (void**) p0;

                    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Process xml attribute name.");

                    // Set attribute name.
                    *an = *pos;

                    // The comparison result.
                    int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

                    while (*NUMBER_1_INTEGER_MEMORY_MODEL) {

                        if (*rem <= *NUMBER_0_INTEGER_MEMORY_MODEL) {

                            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not process attribute name. The remaining count is zero or smaller.");

                            break;
                        }

                        decode_xml_detect_attribute_name_end(p0, p1, (void*) &r);

                        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                            // Increment current position.
                            *pos = *pos + *POINTER_PRIMITIVE_SIZE;

                            // Decrement remaining count.
                            *rem = *rem - *NUMBER_1_INTEGER_MEMORY_MODEL;

                            // Increment attribute name count.
                            (*anc)++;

                        } else {

                            //
                            // The attribute name end was found.
                            //
                            // CAUTION! In this case, the current position and remaining count
                            // were already changed in the called function, to be processed further
                            // in other functions.
                            //
                            // The attribute name and count are left as they are.
                            //

                            break;
                        }
                    }

                } else {

                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not process xml attribute name. The current position is null.");
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not process xml attribute name. The remaining count is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not process xml attribute name. The attribute is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not process xml attribute name. The attribute count is null.");
    }
}

/**
 * Detects the xml tag name end.
 *
 * @param p0 the current position (Hand over as reference!)
 * @param p1 the remaining count
 * @param p2 the comparison result
 */
void decode_xml_detect_tag_name_end(void* p0, void* p1, void* p2) {

    if (p2 != *NULL_POINTER_MEMORY_MODEL) {

        int* r = (int*) p2;

        if (p1 != *NULL_POINTER_MEMORY_MODEL) {

            int* rem = (int*) p1;

            if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                void** pos = (void**) p0;

                log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Detect xml tag name end.");

                if (*rem >= *TAG_NAME_END_XML_NAME_COUNT) {

                    // CAUTION! This comparison is IMPORTANT!
                    // Many "detect" functions may be called in a sequence.
                    // If the result of one detection function was positive (*r == 1),
                    // then that function increments the current position and decrements the remaining count.
                    // In this case, further detection functions following afterwards might detect
                    // further characters and change the current position and remaining count, and so forth,
                    // which would have the effect of "jumping" over some characters and produce WRONG RESULTS!
                    // Therefore, this check avoids another comparison if the result already has a value unequal zero.
                    if (*r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        compare_arrays(*pos, (void*) TAG_NAME_END_XML_NAME_COUNT, (void*) TAG_NAME_END_XML_NAME, (void*) TAG_NAME_END_XML_NAME_COUNT, p2, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

                        if (*r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                            // Increment current position.
                            *pos = *pos + (*TAG_NAME_END_XML_NAME_COUNT * *POINTER_PRIMITIVE_SIZE);

                            // Decrement remaining count.
                            *rem = *rem - *TAG_NAME_END_XML_NAME_COUNT;
                        }
                    }

                } else {

                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not detect xml tag name end. The remaining count is too small.");
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not detect xml tag name end. The current position is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not detect xml tag name end. The remaining count is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not detect xml tag name end. The comparison result is null.");
    }
}

/**
 * Detects the xml empty tag end.
 *
 * @param p0 the current position (Hand over as reference!)
 * @param p1 the remaining count
 * @param p2 the comparison result
 */
void decode_xml_detect_empty_tag_end(void* p0, void* p1, void* p2) {

    if (p2 != *NULL_POINTER_MEMORY_MODEL) {

        int* r = (int*) p2;

        if (p1 != *NULL_POINTER_MEMORY_MODEL) {

            int* rem = (int*) p1;

            if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                void** pos = (void**) p0;

                log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Detect xml empty tag end.");

                if (*rem >= *EMPTY_TAG_END_XML_NAME_COUNT) {

                    // CAUTION! This comparison is IMPORTANT!
                    // Many "detect" functions may be called in a sequence.
                    // If the result of one detection function was positive (*r == 1),
                    // then that function increments the current position and decrements the remaining count.
                    // In this case, further detection functions following afterwards might detect
                    // further characters and change the current position and remaining count, and so forth,
                    // which would have the effect of "jumping" over some characters and produce WRONG RESULTS!
                    // Therefore, this check avoids another comparison if the result already has a value unequal zero.
                    if (*r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        compare_arrays(*pos, (void*) EMPTY_TAG_END_XML_NAME_COUNT, (void*) EMPTY_TAG_END_XML_NAME, (void*) EMPTY_TAG_END_XML_NAME_COUNT, p2, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

                        if (*r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                            // Increment current position.
                            *pos = *pos + (*EMPTY_TAG_END_XML_NAME_COUNT * *POINTER_PRIMITIVE_SIZE);

                            // Decrement remaining count.
                            *rem = *rem - *EMPTY_TAG_END_XML_NAME_COUNT;
                        }
                    }

                } else {

                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not detect xml empty tag end. The remaining count is too small.");
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not detect xml empty tag end. The current position is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not detect xml empty tag end. The remaining count is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not detect xml empty tag end. The comparison result is null.");
    }
}

/**
 * Detects the xml tag end.
 *
 * @param p0 the current position (Hand over as reference!)
 * @param p1 the remaining count
 * @param p2 the comparison result
 */
void decode_xml_detect_tag_end(void* p0, void* p1, void* p2) {

    if (p2 != *NULL_POINTER_MEMORY_MODEL) {

        int* r = (int*) p2;

        if (p1 != *NULL_POINTER_MEMORY_MODEL) {

            int* rem = (int*) p1;

            if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                void** pos = (void**) p0;

                log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Detect xml tag end.");

                if (*rem >= *TAG_END_XML_NAME_COUNT) {

                    // CAUTION! This comparison is IMPORTANT!
                    // Many "detect" functions may be called in a sequence.
                    // If the result of one detection function was positive (*r == 1),
                    // then that function increments the current position and decrements the remaining count.
                    // In this case, further detection functions following afterwards might detect
                    // further characters and change the current position and remaining count, and so forth,
                    // which would have the effect of "jumping" over some characters and produce WRONG RESULTS!
                    // Therefore, this check avoids another comparison if the result already has a value unequal zero.
                    if (*r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        compare_arrays(*pos, (void*) TAG_END_XML_NAME_COUNT, (void*) TAG_END_XML_NAME, (void*) TAG_END_XML_NAME_COUNT, p2, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

                        if (*r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                            // Increment current position.
                            *pos = *pos + (*TAG_END_XML_NAME_COUNT * *POINTER_PRIMITIVE_SIZE);

                            // Decrement remaining count.
                            *rem = *rem - *TAG_END_XML_NAME_COUNT;
                        }
                    }

                } else {

                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not detect xml tag end. The remaining count is too small.");
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not detect xml tag end. The current position is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not detect xml tag end. The remaining count is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not detect xml tag end. The comparison result is null.");
    }
}

/**
 * Processes the xml tag name.
 *
 * @param p0 the current position (Hand over as reference!)
 * @param p1 the remaining count
 * @param p2 the tag name (Hand over as reference!)
 * @param p3 the tag name count
 * @param p4 the empty tag flag
 */
void decode_xml_process_tag_name(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p3 != *NULL_POINTER_MEMORY_MODEL) {

        int* tnc = (int*) p3;

        if (p2 != *NULL_POINTER_MEMORY_MODEL) {

            void** tn = (void**) p2;

            if (p1 != *NULL_POINTER_MEMORY_MODEL) {

                int* rem = (int*) p1;

                if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                    void** pos = (void**) p0;

                    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Process xml tag name.");

                    // Set tag name.
                    *tn = *pos;

                    // The comparison result.
                    int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

                    while (*NUMBER_1_INTEGER_MEMORY_MODEL) {

                        if (*rem <= *NUMBER_0_INTEGER_MEMORY_MODEL) {

                            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not process tag name. The remaining count is zero or smaller.");

                            break;
                        }

                        // CAUTION! The ORDER of function calls is IMPORTANT!
                        // The empty tag end "/>" has to be searched BEFORE
                        // the simple tag end ">", because of the slash "/" character.
                        decode_xml_detect_tag_name_end(p0, p1, (void*) &r);
                        decode_xml_detect_empty_tag_end(p0, p1, (void*) &r, p4);
                        decode_xml_detect_tag_end(p0, p1, (void*) &r);

                        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                            // Increment current position.
                            *pos = *pos + *POINTER_PRIMITIVE_SIZE;

                            // Decrement remaining count.
                            *rem = *rem - *NUMBER_1_INTEGER_MEMORY_MODEL;

                            // Increment tag name count.
                            (*tnc)++;

                        } else {

                            //
                            // The tag name end was found.
                            //
                            // CAUTION! In this case, the current position and remaining count
                            // were already changed in the called function, to be processed further
                            // in other functions.
                            //
                            // The tag name and count are left as they are.
                            //

                            break;
                        }
                    }

                } else {

                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not process xml tag name. The current position is null.");
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not process xml tag name. The remaining count is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not process xml tag name. The tag is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not process xml tag name. The tag count is null.");
    }
}

/**
 * Processes the xml element.
 *
 * @param p0 the current position (Hand over as reference!)
 * @param p1 the remaining count
 * @param p2 the tag name (Hand over as reference!)
 * @param p3 the tag name count
 * @param p4 the attribute name (Hand over as reference!)
 * @param p5 the attribute name count
 * @param p6 the attribute value (Hand over as reference!)
 * @param p7 the attribute value count
 * @param p8 the empty tag flag
 */
void decode_xml_process_element(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8) {

    if (p3 != *NULL_POINTER_MEMORY_MODEL) {

        int* tnc = (int*) p3;

        if (p2 != *NULL_POINTER_MEMORY_MODEL) {

            void** tn = (void**) p2;

            if (p1 != *NULL_POINTER_MEMORY_MODEL) {

                int* rem = (int*) p1;

                if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                    void** pos = (void**) p0;

                    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Process xml element.");

                    decode_xml_process_tag_name(p0, p1, tn, tnc, p8);

                    // Add tag name to compound.
                    add_compound_element_by_name(c, cc, cs, tn, tnc, ns, TEXT, TEXT_COUNT, TEXT_COUNT, tn, tnc, tnc, NULL_POINTER, NULL_POINTER, NULL_POINTER);

                    //?? CAUTION! If using a DOM tree, it HAS TO BE destroyed afterwards!
                    //?? This should be done in the calling function which created the (compound) tree.

                    // The tag name end found may be one of: " ", "/>", ">".
                    // The position now points to the next character AFTER the tag name end,
                    // i.e. to the FIRST character of the attribute name or element content.

                    // The comparison result.
                    //?? int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

                    while (*NUMBER_1_INTEGER_MEMORY_MODEL) {

                        if (*rem <= *NUMBER_0_INTEGER_MEMORY_MODEL) {

                            break;
                        }

                        decode_xml_process_attribute_name(p0, p1, an, anc);
                        decode_xml_process_attribute_value(p0, p1, av, avc);

                        decode_xml_detect_element_end(p0, p1, (void*) &r);

                        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                            // Increment current position.
                            *pos = *pos + *POINTER_PRIMITIVE_SIZE;

                            // Decrement remaining count.
                            *rem = *rem - *NUMBER_1_INTEGER_MEMORY_MODEL;

                            // Increment tag name count.
                            (*tnc)++;

                        } else {

                            //
                            // The tag name end was found.
                            //
                            // CAUTION! In this case, the current position and remaining count
                            // were already changed in the called function, to be processed further
                            // in other functions.
                            //
                            // The tag name and count are left as they are.
                            //

                            break;
                        }
                    }

                } else {

                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not process xml element. The current position is null.");
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not process xml element. The remaining count is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not process xml element. The tag is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not process xml element. The tag count is null.");
    }
}

/**
 * Processes the xml element.
 *
 * @param p0 the current position (Hand over as reference!)
 * @param p1 the remaining count
 * @param p2 the tag name (Hand over as reference!)
 * @param p3 the tag name count
 * @param p4 the attributes (Hand over as reference!)
 * @param p5 the attributes count
 * @param p6 the content flag (if tag is not empty)
 */
void decode_xml_process_element(void* p0, void* p1) {

    // The part name, abstraction, model, details.
    void* n = *NULL_POINTER_MEMORY_MODEL;
    int* nc = (int*) *NULL_POINTER_MEMORY_MODEL;
    int* ns = (int*) *NULL_POINTER_MEMORY_MODEL;
    void* a = *NULL_POINTER_MEMORY_MODEL;
    int* ac = (int*) *NULL_POINTER_MEMORY_MODEL;
    int* as = (int*) *NULL_POINTER_MEMORY_MODEL;
    void* m = *NULL_POINTER_MEMORY_MODEL;
    int* mc = (int*) *NULL_POINTER_MEMORY_MODEL;
    int* ms = (int*) *NULL_POINTER_MEMORY_MODEL;
    void* d = *NULL_POINTER_MEMORY_MODEL;
    int* dc = (int*) *NULL_POINTER_MEMORY_MODEL;
    int* ds = (int*) *NULL_POINTER_MEMORY_MODEL;

    // Set tag name to current position.
    // The tag name follows right after the start tag begin character "<", e.g.:
    // <part ...
    *t = *pos;

    // The comparison result.
    int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

    while (*NUMBER_1_INTEGER_MEMORY_MODEL) {

        decode_xml_detect_attributes(void* p0, void* p1);

        // Increment current byte position which serves as loop variable.
        pos++;
    }
}

/**
 * Detects the begin pointer and count of the various parts.
 *
 * @param p0 the destination compound (Hand over as reference!)
 * @param p1 the destination compound count
 * @param p2 the destination compound size
 * @param p3 the source byte array
 * @param p4 the source byte array count
 */
void decode_xml_detect(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p4 != *NULL_POINTER_MEMORY_MODEL) {

        int* sc = (int*) p4;

        // The remaining bytes in the source array.
        int rem = *sc;
        // The current byte.
        void* b = *NULL_POINTER_MEMORY_MODEL;

        // The declaration mode flag.
        int cf = *NUMBER_0_INTEGER_MEMORY_MODEL;
        // The definition mode flag.
        int ff = *NUMBER_0_INTEGER_MEMORY_MODEL;
        // The comment mode flag.
        int cf = *NUMBER_0_INTEGER_MEMORY_MODEL;
        // The element mode flag.
        int ef = *NUMBER_0_INTEGER_MEMORY_MODEL;

        // The declaration.
        void* c = *NULL_POINTER_MEMORY_MODEL;
        int cc = *NUMBER_0_INTEGER_MEMORY_MODEL;
        // The definition.
        void* f = *NULL_POINTER_MEMORY_MODEL;
        int fc = *NUMBER_0_INTEGER_MEMORY_MODEL;
        // The comment.
        void* c = *NULL_POINTER_MEMORY_MODEL;
        int cc = *NUMBER_0_INTEGER_MEMORY_MODEL;
        // The element.
        void* e = *NULL_POINTER_MEMORY_MODEL;
        int ec = *NUMBER_0_INTEGER_MEMORY_MODEL;

        // The comparison result.
        int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

        if (dec != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            // The decoder is in "declaration" mode.

            decode_xml_process_declaration((void*) &c, (void*) &cc, (void*) &b, (void*) &rem);

            // Reset "declaration" mode flag.
            dec = *NUMBER_0_INTEGER_MEMORY_MODEL;

        } else if (def != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            // The decoder is in "definition" mode.

            decode_xml_process_definition((void*) &c, b, (void*) &rem);

            // Reset "definition" mode flag.
            def = *NUMBER_0_INTEGER_MEMORY_MODEL;

        } else if (com != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            // The decoder is in "comment" mode.

            decode_xml_process_comment((void*) &c, b, (void*) &rem);

            // Reset "comment" mode flag.
            com = *NUMBER_0_INTEGER_MEMORY_MODEL;

        } else if (ele != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            // The decoder is in "element" mode.

            decode_xml_process_element((void*) &c, b, (void*) &rem);

            // Reset "element" mode flag.
            ele = *NUMBER_0_INTEGER_MEMORY_MODEL;

        } else {

            // The decoder is in no (or neutral) mode.
            // This means, that the next meaningful character sequence may be searched below.

            //
            // CAUTION! The order of the comparisons is IMPORTANT!
            // Do NOT change it easily!
            // The reason is that all elements begin with a "<" character:
            // - declaration: <?
            // - definition: <!
            // - comment: <!--
            // - element: <
            //
            // Before arbitrary elements beginning with just "<" and a term can be identified,
            // all other possibilities (declaration, definition, comment) have to have
            // been processed, in order to be excluded.
            //

            if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                compare_arrays(b, (void*) &rem, (void*) DECLARATION_BEGIN_XML_NAME, (void*) DECLARATION_BEGIN_XML_NAME_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

                if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    decode_xml_process_declaration((void*) &c, (void*) &cc, (void*) &b, (void*) &rem);
                }
            }

            if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                compare_arrays(b, (void*) &rem, (void*) DEFINITION_BEGIN_XML_NAME, (void*) DEFINITION_BEGIN_XML_NAME_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

                if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    decode_xml_process_definition((void*) &c, (void*) &cc, (void*) &b, (void*) &rem);
                }
            }

            if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                compare_arrays(b, (void*) &rem, (void*) COMMENT_BEGIN_XML_NAME, (void*) COMMENT_BEGIN_XML_NAME_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

                if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    decode_xml_process_comment((void*) &c, (void*) &cc, (void*) &b, (void*) &rem);
                }
            }

            if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                compare_arrays(b, (void*) &rem, (void*) START_TAG_BEGIN_XML_NAME, (void*) START_TAG_BEGIN_XML_NAME_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

                if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    decode_xml_process_element((void*) &c, (void*) &cc, (void*) &b, (void*) &rem);
                }
            }
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not detect xml section. The source byte array count is null.");
    }
}

/**
 * Decodes the xml byte array into a compound.
 *
 * @param p0 the destination compound (Hand over as reference!)
 * @param p1 the destination compound count
 * @param p2 the destination compound size
 * @param p3 the source byte array
 * @param p4 the source byte array count
 */
void decode_xml(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Decode xml.");

    decode_xml_detect(p0, p1, p2, p3, p4);
}

/**
 * Encodes the compound into a xml byte array.
 *
 * @param p0 the destination message (Hand over as reference!)
 * @param p1 the destination message count
 * @param p2 the destination message size
 * @param p3 the source compound
 * @param p4 the source compound count
 */
void encode_xml(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Encode xml.");
}

/* XML_CONVERTER_SOURCE */
#endif
