/*
 * $RCSfile: xml_parser.c,v $
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
 * - parse an xml stream into an xml model
 * - serialize an xml model into an xml stream
 *
 * @version $Revision: 1.1 $ $Date: 2004-07-28 22:46:28 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef XML_PARSER_SOURCE
#define XML_PARSER_SOURCE

#include "../array/array.c"
#include "../global/constant.c"
#include "../logger/logger.c"
#include "../state/xml_attribute.c"
#include "../state/xml_tag.c"

//
// Xml model.
//

/**
 * Parses the xml stream into an xml model.
 *
 * @param p0 the xml model
 * @param p1 the xml model count
 * @param p2 the xml model size
 * @param p3 the xml stream
 * @param p4 the xml stream count
 */
void parse_xml(void* p0, void* p1, void* p2, const void* p3, const void* p4) {

    if (p4 != NULL_POINTER) {

        int* sc = (int*) p4;

        if (p3 != NULL_POINTER) {

            void** s = (void**) p3;

            // The done flag.
            int d = 0;
            // The comparison result.
            int r = 0;
            // The current byte within the stream.
            void* b = *s;
            // The remaining bytes count.
            int bc = *sc;
            // The parse mode.
            int m = ZERO_PARSE_MODE;
            // The attribute begin pointer.
            void* a = NULL_POINTER;
            // The attribute count.
            int ac = 0;
            // The attribute begin count to be used for calculating the difference.
            int ab = 0;

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

                if (m == ZERO_PARSE_MODE) {

                    if (bc >= BEGIN_COMMENT_TAG_COUNT) {

                        compare_array_elements((void*) &b, (void*) &BEGIN_COMMENT_TAG, (void*) &CHARACTER_ARRAY, (void*) &BEGIN_COMMENT_TAG_COUNT, (void*) &r);

                        if (r == 1) {

                            // Move current byte pointer
                            // and remaining bytes count.
                            b = b + BEGIN_COMMENT_TAG_COUNT;
                            bc = bc - BEGIN_COMMENT_TAG_COUNT;

                            // Set parse mode.
                            m = COMMENT_TAG_PARSE_MODE;
                        }
                    }
                }

                if (m == ZERO_PARSE_MODE) {

                    if (bc >= BEGIN_TAG_BEGIN_COUNT) {

                        compare_array_elements((void*) &b, (void*) &BEGIN_TAG_BEGIN, (void*) &CHARACTER_ARRAY, (void*) &BEGIN_TAG_BEGIN_COUNT, (void*) &r);

                        if (r == 1) {

                            // Move current byte pointer
                            // and remaining bytes count.
                            b = b + BEGIN_TAG_BEGIN_COUNT;
                            bc = bc - BEGIN_TAG_BEGIN_COUNT;

                            // Initialize xml tag.
                            void* t = NULL_POINTER;
                            int tc = 0;
                            int ts = 0;

                            // Exceptionally do not create a new xml tag.
                            // The first tag of an xml file is the root tag.
                            // The corresponding transient xml root tag model
                            // to be used was already handed over to this procedure.
                            // So, use this model instead of creating a new one!
                            // For any other part tags of root, however,
                            // new transient xml tag models have to be created!

                            // Create xml tag.
//??                            create_xml_tag((void*) &t, (void*) &ts);

                            // Parse xml tag.
//??                            parse_xml_tag((void*) &t, (void*) &tc, (void*) &ts,
//??                                (void*) &b, (void*) &bc);

                            //?? Exit sub procedure above when end tag is reached!

                            // Add xml tag.
//??                            add_xml_tag();

                            // Set parse mode.
                            m = BEGIN_TAG_PARSE_MODE;
                        }
                    }
                }

                // If this block is reached, then no known term was found before.
                // The current byte pointer will just be incremented by one so
                // that new characters are read and compared in the next loop cycle.
                if (m == ZERO_PARSE_MODE) {

                    // Increment current byte within persistent model.
                    b++;
                    // Decrement remaining bytes count.
                    bc--;
                }

/*??
    Put the following code to "parse_xml_tag" procedure!
    When end tag is reached, leave the called sub procedure!

                //
                // Special parse modes.
                //
                // These conditions are linked with else-if because if one term
                // matches, the parse mode is switched back to ZERO_PARSE_MODE
                // and no further terms have to be compared here.
                //

                // Reset comparison result.
                // CAUTION! Do NOT delete this! One of the comparisons above
                // may have set the result to 1 so that it has to be reset here.
                r = 0;

                if (m == COMMENT_TAG_PARSE_MODE) {

                    if (d == 0) {

                        if (bc >= END_COMMENT_TAG_COUNT) {

                            compare_array_elements((void*) &b, (void*) &END_COMMENT_TAG, (void*) &CHARACTER_ARRAY, (void*) &END_COMMENT_TAG_COUNT, (void*) &r);

                            if (r == 1) {

                                // Move current byte pointer
                                // and remaining bytes count.
                                b = b + END_COMMENT_TAG_COUNT;
                                bc = bc - END_COMMENT_TAG_COUNT;

                                // Reset parse mode.
                                m = ZERO_PARSE_MODE;

                                d = 1;
                            }
                        }
                    }

                    if (d == 0) {

                        if (bc >= SHORT_END_COMMENT_TAG_COUNT) {

                            compare_array_elements((void*) &b, (void*) &SHORT_END_COMMENT_TAG, (void*) &CHARACTER_ARRAY, (void*) &SHORT_END_COMMENT_TAG_COUNT, (void*) &r);

                            if (r == 1) {

                                // Move current byte pointer
                                // and remaining bytes count.
                                b = b + SHORT_END_COMMENT_TAG_COUNT;
                                bc = bc - SHORT_END_COMMENT_TAG_COUNT;

                                // Reset parse mode.
                                m = ZERO_PARSE_MODE;

                                d = 1;
                            }
                        }
                    }

                } else if (m == BEGIN_TAG_PARSE_MODE) {

                    if (d == 0) {

                        if (bc >= TAG_END_COUNT) {

                            compare_array_elements((void*) &b, (void*) &TAG_END, (void*) &CHARACTER_ARRAY, (void*) &TAG_END_COUNT, (void*) &r);

                            if (r == 1) {

                                // Determine the attributes length as difference
                                // of the formerly stored attribute begin count
                                // and the current count.
                                ac = ab - bc;

                                // Interpret attributes.
                                // Hand over the formerly stored attribute begin pointer
                                // and its count.
                                interpret_super_attributes((void*) &a, (void*) &ac);

                                // Move current byte pointer
                                // and remaining bytes count.
                                b = b + TAG_END_COUNT;
                                bc = bc - TAG_END_COUNT;

                                // Reset values.
                                a = NULL_POINTER;
                                ac = 0;
                                ab = 0;

                                // Reset parse mode.
                                m = ZERO_PARSE_MODE;
                            }
                        }
                    }

                } else if (m == END_TAG_PARSE_MODE) {

                    if (d == 0) {

                    if (bc >= TAG_END_COUNT) {

                        compare_array_elements((void*) &b, (void*) &TAG_END, (void*) &CHARACTER_ARRAY, (void*) &TAG_END_COUNT, (void*) &r);

                        if (r == 1) {

                            // Determine the attributes length as difference
                            // of the formerly stored attribute begin count
                            // and the current count.
                            ac = ab - bc;

                            // Initialize part.
                            // Hand over the formerly stored attribute begin pointer
                            // and its count.
//??                            initialize_part(p0, p1, p2, (void*) &a, (void*) &ac);

//??                            create(whole, name, abstraction, ...);
//??                            set(whole, name, ...);

                            // Move current byte pointer
                            // and remaining bytes count.
                            b = b + TAG_END_COUNT;
                            bc = bc - TAG_END_COUNT;

                            // Reset values.
                            a = NULL_POINTER;
                            ac = 0;
                            ab = 0;

                            // Reset parse mode.
                            m = ZERO_PARSE_MODE;
                        }
                    }
                }
*/

                // Reset done flag.
                d = 0;
                // Reset comparison result.
                r = 0;
            }

        } else {

//??            log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not initialize compound. The persistent model is null.");
        }

    } else {

//??        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not initialize compound. The persistent model count is null.");
    }
}

/**
 * Serializes the xml tree into an xml stream.
 *
 * @param p0 the xml model
 * @param p1 the xml model count
 * @param p2 the xml model size
 * @param p3 the xml stream
 * @param p4 the xml stream count
 */
void serialize_xml(const void* p0, const void* p1, const void* p2, void* p3, void* p4) {
}

/* XML_PARSER_SOURCE */
#endif
