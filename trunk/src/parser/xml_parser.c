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
 * @version $Revision: 1.3 $ $Date: 2004-08-02 11:12:16 $ $Author: christian $
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

        if (p0 != NULL_POINTER) {

            void** s = (void**) p0;

            // The leave flag.
            int l = 0;
            // The done flag.
            int d = 0;
            // The comparison result.
            int r = 0;
            // The current byte within the stream.
            void* b = *s;
            // The remaining bytes count.
            int bc = *sc;

            while (1) {

                if ((l == 1) || (bc <= 0)) {

                    break;
                }

                if (d == 0) {

                    if (bc >= END_COMMENT_TAG_COUNT) {

                        compare_array_elements((void*) &b, (void*) &END_COMMENT_TAG, (void*) &CHARACTER_ARRAY, (void*) &END_COMMENT_TAG_COUNT, (void*) &r);

                        if (r == 1) {

                            // Move current byte pointer
                            // and remaining bytes count.
                            b = b + END_COMMENT_TAG_COUNT;
                            bc = bc - END_COMMENT_TAG_COUNT;

                            // Set leave flag.
                            l = 1;

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

                            // Set leave flag.
                            l = 1;

                            d = 1;
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
void parse_xml_tag(void* p0, void* p1, void* p2, const void* p3, const void* p4) {

    if (p4 != NULL_POINTER) {

        int* sc = (int*) p4;

        if (p3 != NULL_POINTER) {

            void** s = (void**) p3;

            // The leave flag.
            int l = 0;
            // The done flag.
            int d = 0;
            // The comparison result.
            int r = 0;
            // The current byte within the stream.
            void* b = *s;
            // The remaining bytes count.
            int bc = *sc;

            while (1) {

                if ((l == 1) || (bc <= 0)) {

                    break;
                }

                if (d == 0) {

                    if (bc >= EMPTY_TAG_END_COUNT) {

                        compare_array_elements((void*) &b, (void*) &EMPTY_TAG_END, (void*) &CHARACTER_ARRAY, (void*) &EMPTY_TAG_END_COUNT, (void*) &r);

                        if (r == 1) {

                            // Move current byte pointer
                            // and remaining bytes count.
                            b = b + EMPTY_TAG_END_COUNT;
                            bc = bc - EMPTY_TAG_END_COUNT;

                            // Set leave flag.
                            l = 1;

                            // Set done flag.
                            d = 1;
                        }
                    }
                }

                if (d == 0) {

                    if (bc >= TAG_END_COUNT) {

                        compare_array_elements((void*) &b, (void*) &TAG_END, (void*) &CHARACTER_ARRAY, (void*) &TAG_END_COUNT, (void*) &r);

                        if (r == 1) {

                            // Move current byte pointer
                            // and remaining bytes count.
                            b = b + TAG_END_COUNT;
                            bc = bc - TAG_END_COUNT;

                            // Parse xml value.
//??                            parse_xml_value((void*) &b, (void*) &bc);
                        }
                    }
                }

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

                            // Initialize xml tag.
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
//??                            create_xml_tag((void*) &t, (void*) &ts);

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
