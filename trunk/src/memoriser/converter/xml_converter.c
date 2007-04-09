/*
 * $RCSfile: xml_converter.c,v $
 *
 * Copyright (c) 1999-2007. Christian Heller and the CYBOP developers.
 *
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
 * - parse an xml stream into an xml model
 * - serialise an xml model into an xml stream
 *
 * @version $Revision: 1.16 $ $Date: 2007-04-09 08:48:44 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef XML_CONVERTER_SOURCE
#define XML_CONVERTER_SOURCE

#include <libxml/parser.h>
#include "../../globals/constants/character_constants.c"
#include "../../globals/constants/cybol_constants.c"
#include "../../globals/constants/integer_constants.c"
#include "../../globals/constants/log_constants.c"
#include "../../globals/logger/logger.c"
#include "../../memoriser/allocator.c"
#include "../../memoriser/allocator/xml_node_allocator.c"
#include "../../memoriser/allocator/xml_property_allocator.c"

//
// Xml comment tag.
//

/**
 * Parses the xml stream until an xml comment end tag is reached.
 *
 * This procedure only counts up the stream pointer and
 * changes nothing in the xml model.
 *
 * @param p0 the xml stream
 * @param p1 the xml stream count
 */
void parse_xml_comment_tag(void* p0, void* p1) {

    if (p1 != NULL_POINTER) {

        int* sc = (int*) p1;

        // The leave flag.
        int l = 0;
        // The comparison result.
        int r = 0;
        // The current byte within the stream.
        void* b = p0;
        // The remaining bytes count.
        int bc = *sc;

        while (1) {

            if ((l == 1) || (bc <= 0)) {

                break;
            }

            if (r != 1) {

                if (bc >= *END_COMMENT_TAG_COUNT) {

                    compare_array_elements((void*) b, (void*) END_COMMENT_TAG, (void*) END_COMMENT_TAG_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r == 1) {

                        // Move current byte pointer
                        // and remaining bytes count.
                        b = b + *END_COMMENT_TAG_COUNT;
                        bc = bc - *END_COMMENT_TAG_COUNT;

                        // Set leave flag.
                        l = 1;
                    }
                }
            }

            if (r != 1) {

                if (bc >= *SHORT_END_COMMENT_TAG_COUNT) {

                    compare_array_elements((void*) b, (void*) SHORT_END_COMMENT_TAG, (void*) SHORT_END_COMMENT_TAG_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r == 1) {

                        // Move current byte pointer
                        // and remaining bytes count.
                        b = b + *SHORT_END_COMMENT_TAG_COUNT;
                        bc = bc - *SHORT_END_COMMENT_TAG_COUNT;

                        // Set leave flag.
                        l = 1;
                    }
                }
            }

            // If this block is reached, then no known term was found before.
            // The current byte pointer will just be incremented by one so
            // that new characters are read and compared in the next loop cycle.
            if (r != 1) {

                // Increment current byte within persistent model.
                b++;
                // Decrement remaining bytes count.
                bc--;
            }

            // Reset comparison result.
            r = 0;
        }

    } else {

//??        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not initialise compound. The persistent model count is null.");
    }
}

//
// Xml tag.
//

/**
 * Parses the xml stream into an xml tag.
 *
 * @param p0 the xml model
 * @param p1 the xml model count
 * @param p2 the xml model size
 * @param p3 the xml stream
 * @param p4 the xml stream count
 */
void parse_xml_tag(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p4 != NULL_POINTER) {

        int* sc = (int*) p4;

        // The leave flag.
        int l = 0;
        // The comparison result.
        int r = 0;
        // The current byte within the stream.
        void* b = (void*) p3;
        // The remaining bytes count.
        int bc = *sc;

        while (1) {

            if ((l == 1) || (bc <= 0)) {

                break;
            }

            if (r != 1) {

                if (bc >= *EMPTY_TAG_END_COUNT) {

                    compare_array_elements((void*) b, (void*) EMPTY_TAG_END, (void*) EMPTY_TAG_END_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r == 1) {

                        // Move current byte pointer
                        // and remaining bytes count.
                        b = b + *EMPTY_TAG_END_COUNT;
                        bc = bc - *EMPTY_TAG_END_COUNT;

                        // Set leave flag.
                        l = 1;
                    }
                }
            }

            if (r != 1) {

                if (bc >= *TAG_END_COUNT) {

                    compare_array_elements((void*) b, (void*) TAG_END, (void*) TAG_END_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r == 1) {

                        // Move current byte pointer
                        // and remaining bytes count.
                        b = b + *TAG_END_COUNT;
                        bc = bc - *TAG_END_COUNT;

                        // Parse xml value.
//??                        parse_xml_value((void*) &b, (void*) &bc);
                    }
                }
            }

            // Reset comparison result.
            r = 0;
        }

    } else {

//??        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not initialise compound. The persistent model count is null.");
    }
}

//
// Xml model.
//

/**
 * Parses the byte stream and creates an xml model from it.
 *
 * @param p0 the destination (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source
 * @param p4 the source count
 */
void parse_xml(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p4 != NULL_POINTER) {

        int* sc = (int*) p4;

        if (p3 != NULL_POINTER) {

            void* s = (void*) p3;

            if (p0 != NULL_POINTER) {

                void** d = (void**) p0;

                //?? BEGIN of temporary workaround for using the libxml2 parser.
                //?? Parameter p3 represents the xml file name!

                // Following is a special check to avoid:
                // I/O warning : failed to load external entity ""
                // messages of the xml parser.
                if (*sc > 0) {

                    log_message_debug("Information: Parse xml.");

                    // The temporary null-terminated file name.
                    void* tmp = NULL_POINTER;
                    int tmps = *sc + 1;

                    // Create temporary null-terminated file name.
                    allocate_array((void*) &tmp, (void*) &tmps, (void*) CHARACTER_ARRAY);

                    // Set terminated file name by first copying the actual name
                    // and then adding the null termination character.
                    set_array_elements(tmp, (void*) NUMBER_0_INTEGER, p3, p4, (void*) CHARACTER_ARRAY);
                    set_array_elements(tmp, p4, (void*) NULL_CONTROL_CHARACTER, (void*) PRIMITIVE_COUNT, (void*) CHARACTER_ARRAY);

                    // Initialise the library.
                    // Check potential ABI mismatches between the version
                    // it was compiled for and the actual shared library used.
                    LIBXML_TEST_VERSION

                    // Parse file and get xml document.
                    // This function returns a pointer to type: xmlDoc*
                    *d = (void*) xmlParseFile((char*) tmp);

                    // Free global variables that may have been allocated by the parser.
                    xmlCleanupParser();

                    // Destroy temporary null-terminated file name.
                    deallocate_array((void*) &tmp, (void*) &tmps, (void*) CHARACTER_ARRAY);

                } else {

                    log_message_debug("Error: Could not parse xml. The file name count is null.");
                }

                //?? END of temporary workaround for using the libxml2 parser.

/*??
            // The comparison result.
            int* r = NULL_POINTER;
            allocate((void*) &r, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
            *r = 0;
            // The current byte within the stream.
            void* b = *s;
            // The remaining bytes count.
            int bc = *sc;

            while (1) {

                if (bc <= 0) {

                    break;
                }

                //
                // Zero parse mode.
                //
                // CAUTION!
                // The order of comparisons is important.
                // Comment tags have to be found before other tags.
                // Otherwise, a comment tag is treated wrongly as normal tag.
                //

                if (d == 0) {

                    if (bc >= BEGIN_COMMENT_TAG_COUNT) {

                        compare_array_elements((void*) &b, (void*) &BEGIN_COMMENT_TAG, (void*) &CHARACTER_ARRAY, (void*) &BEGIN_COMMENT_TAG_COUNT, (void*) &r);

                        if (r == 1) {

                            // Move current byte pointer
                            // and remaining bytes count.
                            b = b + BEGIN_COMMENT_TAG_COUNT;
                            bc = bc - BEGIN_COMMENT_TAG_COUNT;

                            // Parse xml comment tag.
                            parse_xml_comment_tag((void*) &b, (void*) &bc);
                        }
                    }
                }

                if (d == 0) {

                    if (bc >= BEGIN_TAG_BEGIN_COUNT) {

                        compare_array_elements((void*) &b, (void*) &BEGIN_TAG_BEGIN, (void*) &CHARACTER_ARRAY, (void*) &BEGIN_TAG_BEGIN_COUNT, (void*) &r);

                        if (r == 1) {

                            // Move current byte pointer
                            // and remaining bytes count.
                            b = b + BEGIN_TAG_BEGIN_COUNT;
                            bc = bc - BEGIN_TAG_BEGIN_COUNT;

                            // Initialise xml tag.
                            void* t = NULL_POINTER;
                            int tc = 0;
                            int ts = 0;

                            // Exceptionally do NOT create and add a new xml tag.
                            // The first tag of an xml file is the root tag.
                            // The corresponding transient xml root tag model
                            // to be used was already handed over to this procedure.
                            // So, use this model instead of creating a new one!
                            // For any other part tags of root, however,
                            // new transient xml tag models have to be created!

                            // Create xml tag.
//??                            allocate_xml_tag((void*) &t, (void*) &ts);

                            // Parse xml tag.
                            parse_xml_tag((void*) &t, (void*) &tc, (void*) &ts,
                                (void*) &b, (void*) &bc);

                            //?? Exit sub procedure above when end tag is reached!

                            // Add xml tag.
//??                            add_xml_tag();
                        }
                    }
                }

                // If this block is reached, then no known term was found before.
                // The current byte pointer will just be incremented by one so
                // that new characters are read and compared in the next loop cycle.
                if (d == 0) {

                    // Increment current byte within persistent model.
                    b++;
                    // Decrement remaining bytes count.
                    bc--;
                }

                // Reset comparison result.
                *r = 0;
            }
*/

            } else {

                log_message_debug("Error: Could not parse xml. The destination is null.");
            }

        } else {

            log_message_debug("Error: Could not parse xml. The source is null.");
        }

    } else {

        log_message_debug("Error: Could not parse xml. The source count is null.");
    }
}

/**
 * Serialises the xml model and creates a byte stream from it.
 *
 * @param p0 the destination (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source
 * @param p4 the source count
 */
void serialise_xml(void* p0, void* p1, void* p2, void* p3, void* p4) {
}

/* XML_CONVERTER_SOURCE */
#endif
