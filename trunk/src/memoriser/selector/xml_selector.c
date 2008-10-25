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
 * @version $RCSfile: xml_selector.c,v $ $Revision: 1.1 $ $Date: 2008-10-25 23:20:10 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef XML_SELECTOR_SOURCE
#define XML_SELECTOR_SOURCE

#include "../../constant/model/log/message_log_model.c"
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../constant/name/cybol/xml_cybol_name.c"
#include "../../logger/logger.c"
#include "../../memoriser/detector/xml_detector.c"

//
// Forward declarations.
//

void decode_xml_process_declaration(void* p0, void* p1, void* p2, void* p3, void* p4);
void decode_xml_process_definition(void* p0, void* p1, void* p2, void* p3, void* p4);
void decode_xml_process_comment(void* p0, void* p1);
void decode_xml_process_element_content(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7);
void decode_xml_process_end_tag(void* p0, void* p1);
void decode_xml_process_attribute_name(void* p0, void* p1, void* p2, void* p3);
void decode_xml_process_attribute_value(void* p0, void* p1, void* p2, void* p3);
void decode_xml_process_element(void* p0, void* p1, void* p2, void* p3, void* p4);

/**
 * Selects the xml declaration.
 *
 * @param p0 the destination details (Hand over as reference!)
 * @param p1 the destination details count
 * @param p2 the destination details size
 * @param p3 the break flag
 * @param p4 the current position (Hand over as reference!)
 * @param p5 the remaining count
 */
void decode_xml_select_declaration(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    if (p3 != *NULL_POINTER_MEMORY_MODEL) {

        int* b = (int*) p3;

        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Select xml declaration.");

        // The comparison result.
        int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            decode_xml_detect_declaration_end((void*) &r, p4, p5);

            if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                // Set break flag.
                *b = *NUMBER_1_INTEGER_MEMORY_MODEL;
            }
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not select xml declaration. The break flag is null.");
    }
}

/**
 * Selects the xml definition.
 *
 * @param p0 the break flag
 * @param p1 the current position (Hand over as reference!)
 * @param p2 the remaining count
 */
void decode_xml_select_definition(void* p0, void* p1, void* p2) {

    if (p2 != *NULL_POINTER_MEMORY_MODEL) {

        int* rem = (int*) p2;

        if (p1 != *NULL_POINTER_MEMORY_MODEL) {

            void** pos = (void**) p1;

            if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                int* b = (int*) p0;

                log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Select xml definition.");

                // The comparison result.
                int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    if (*rem >= *DEFINITION_END_XML_NAME_COUNT) {

                        compare_arrays(*pos, (void*) DEFINITION_END_XML_NAME_COUNT, (void*) DEFINITION_END_XML_NAME, (void*) DEFINITION_END_XML_NAME_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

                        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                            // Set break flag.
                            *b = *NUMBER_1_INTEGER_MEMORY_MODEL;
                        }

                    } else {

                        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not select xml definition. The remaining count is too small.");
                    }
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not select xml definition. The break flag is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not select xml definition. The current position is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not select xml definition. The remaining count is null.");
    }
}

/**
 * Selects the xml comment.
 *
 * @param p0 the break flag
 * @param p1 the current position (Hand over as reference!)
 * @param p2 the remaining count
 */
void decode_xml_select_comment(void* p0, void* p1, void* p2) {

    if (p2 != *NULL_POINTER_MEMORY_MODEL) {

        int* rem = (int*) p2;

        if (p1 != *NULL_POINTER_MEMORY_MODEL) {

            void** pos = (void**) p1;

            if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                int* b = (int*) p0;

                log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Select xml comment.");

                // The comparison result.
                int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    if (*rem >= *COMMENT_END_XML_NAME_COUNT) {

                        compare_arrays(*pos, (void*) COMMENT_END_XML_NAME_COUNT, (void*) COMMENT_END_XML_NAME, (void*) COMMENT_END_XML_NAME_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

                        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                            // Set break flag.
                            *b = *NUMBER_1_INTEGER_MEMORY_MODEL;
                        }

                    } else {

                        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not select xml comment. The remaining count is too small.");
                    }
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not select xml comment. The break flag is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not select xml comment. The current position is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not select xml comment. The remaining count is null.");
    }
}

/**
 * Selects the xml element content.
 *
 * @param p0 the destination model (Hand over as reference!)
 * @param p1 the destination model count
 * @param p2 the destination model size
 * @param p3 the destination details (Hand over as reference!)
 * @param p4 the destination details count
 * @param p5 the destination details size
 * @param p6 the break flag
 * @param p7 the current position (Hand over as reference!)
 * @param p8 the remaining count
 */
void decode_xml_select_element_content(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8) {

    if (p8 != *NULL_POINTER_MEMORY_MODEL) {

        int* rem = (int*) p8;

        if (p7 != *NULL_POINTER_MEMORY_MODEL) {

            void** pos = (void**) p7;

            if (p6 != *NULL_POINTER_MEMORY_MODEL) {

                int* b = (int*) p6;

                log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Select xml element content.");

                //
                // CAUTION! The order of the comparisons is IMPORTANT! Do NOT change it easily!
                // Before arbitrary elements -- beginning with just "<" and a term -- can be identified,
                // all other possibilities (declaration, definition, comment) have to have
                // been processed, in order to be excluded.
                // The reason is that all elements begin with a "<" character:
                // - declaration: <?
                // - definition: <!
                // - comment: <!--
                // - element: <
                //
                // CAUTION! The comparison result HAS TO BE ZERO (r == 0),
                // if a detection is to be taking place!
                // Many "detect" functions are called in a sequence, below.
                // If the result of one detection function was positive (r == 1),
                // then that function increments the current position and decrements the remaining count.
                // In this case, further detection functions following afterwards might detect
                // further characters and CHANGE the current position and remaining count, and so forth,
                // which would have the effect of "jumping" over some characters and produce WRONG RESULTS!
                // Therefore, the checks for (r == 0) below avoid another detection,
                // if the result already has a value unequal zero.
                //
                // CAUTION! If a detection was successful, then the current position and remaining count
                // were already adapted within the corresponding "detect" function (as called below),
                // so that they now point to the first character following the detected character sequence.
                // Any "process" function called afterwards can rely on this and start processing right away.
                //

    fwprintf(stderr, L"TEST select element content 0 rem: %i\n", *rem);

                // The comparison result.
                int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    decode_xml_detect_end_tag_begin((void*) &r, p7, p8);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        decode_xml_process_end_tag(p7, p8);

                        // Set break flag, because this xml element's end tag
                        // has been reached and its content fully been processed.
                        *b = *NUMBER_1_INTEGER_MEMORY_MODEL;
                    }
                }

                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    decode_xml_detect_declaration_begin((void*) &r, p7, p8);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        // The data contained in an XML declaration are added to the destination details.
                        decode_xml_process_declaration(p3, p4, p5, p7, p8);
                    }
                }

                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    decode_xml_detect_definition_begin((void*) &r, p7, p8);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        // The data contained in an XML definition are added to the destination details.
                        decode_xml_process_definition(p3, p4, p5, p7, p8);
                    }
                }

                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    decode_xml_detect_comment_begin((void*) &r, p7, p8);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        // The data contained in an XML comment are just ignored.
                        decode_xml_process_comment(p6, p7);
                    }
                }

                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

    fwprintf(stderr, L"TEST select element content 1 rem: %i\n", *rem);

                    decode_xml_detect_start_tag_begin((void*) &r, p7, p8);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

    fwprintf(stderr, L"TEST select element content 2 rem: %i\n", *rem);

                        // The data contained in an XML element are added to the destination model.
                        decode_xml_process_element(p0, p1, p2, p7, p8);
                    }
                }

                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    // None of the comparisons above delivered a positive (r != 0) result.
                    // Therefore, increment the current position by one (pointer size).

                    // Increment current position.
                    *pos = *pos + *POINTER_PRIMITIVE_SIZE;

                    // Decrement remaining count.
                    *rem = *rem - *NUMBER_1_INTEGER_MEMORY_MODEL;
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not select xml element content. The break flag is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not select xml element content. The current position is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not select xml element content. The remaining count is null.");
    }
}

/**
 * Selects the end tag.
 *
 * @param p0 the break flag
 * @param p1 the current position (Hand over as reference!)
 * @param p2 the remaining count
 */
void decode_xml_select_end_tag(void* p0, void* p1, void* p2) {

    if (p2 != *NULL_POINTER_MEMORY_MODEL) {

        int* rem = (int*) p2;

        if (p1 != *NULL_POINTER_MEMORY_MODEL) {

            void** pos = (void**) p1;

            if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                int* b = (int*) p0;

                log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Select xml end tag.");

                //
                // CAUTION! The ORDER of the following function calls is IMPORTANT!
                // The empty tag end "/>" has to be searched BEFORE
                // the simple tag end ">", because of the slash "/" character.
                //
                // CAUTION! The comparison result HAS TO BE ZERO, if a detection is to be taking place!
                // Many "detect" functions are called in a sequence, below.
                // If the result of one detection function was positive (r == 1),
                // then that function increments the current position and decrements the remaining count.
                // In this case, further detection functions following afterwards might detect
                // further characters and CHANGE the current position and remaining count, and so forth,
                // which would have the effect of "jumping" over some characters and produce WRONG RESULTS!
                // Therefore, the checks for (r == 0) below avoid another detection,
                // if the result already has a value unequal zero.
                //

                // The comparison result.
                int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    decode_xml_detect_tag_end((void*) &r, p1, p2);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        //
                        // The tag end was found.
                        //
                        // CAUTION! In this case, the current position and remaining count
                        // were already changed in the called function, to be processed further
                        // in other functions.
                        //
                        // The tag name and count are left as they are.
                        //

                        // Set break flag.
                        *b = *NUMBER_1_INTEGER_MEMORY_MODEL;
                    }
                }

                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    // Increment current position.
                    *pos = *pos + *POINTER_PRIMITIVE_SIZE;

                    // Decrement remaining count.
                    *rem = *rem - *NUMBER_1_INTEGER_MEMORY_MODEL;
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not select xml end tag. The break flag is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not select xml end tag. The current position is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not select xml end tag. The remaining count is null.");
    }
}

/**
 * Selects the tag name.
 *
 * @param p0 the tag name count
 * @param p1 the break flag
 * @param p2 the current position (Hand over as reference!)
 * @param p3 the remaining count
 */
void decode_xml_select_tag_name(void* p0, void* p1, void* p2, void* p3) {

    if (p3 != *NULL_POINTER_MEMORY_MODEL) {

        int* rem = (int*) p3;

        if (p2 != *NULL_POINTER_MEMORY_MODEL) {

            void** pos = (void**) p2;

            if (p1 != *NULL_POINTER_MEMORY_MODEL) {

                int* b = (int*) p1;

                if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                    int* tnc = (int*) p0;

                    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Select xml tag name.");

                    //
                    // CAUTION! The ORDER of the following function calls is IMPORTANT!
                    // The empty tag end "/>" has to be searched BEFORE
                    // the simple tag end ">", because of the slash "/" character.
                    //
                    // CAUTION! The comparison result HAS TO BE ZERO, if a detection is to be taking place!
                    // Many "detect" functions are called in a sequence, below.
                    // If the result of one detection function was positive (r == 1),
                    // then that function increments the current position and decrements the remaining count.
                    // In this case, further detection functions following afterwards might detect
                    // further characters and CHANGE the current position and remaining count, and so forth,
                    // which would have the effect of "jumping" over some characters and produce WRONG RESULTS!
                    // Therefore, the checks for (r == 0) below avoid another detection,
                    // if the result already has a value unequal zero.
                    //

                    // The comparison result.
                    int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

                    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        decode_xml_detect_tag_name_end((void*) &r, p2, p3);

                        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                            // The tag name end was found.
                            // Set break flag.
                            *b = *NUMBER_1_INTEGER_MEMORY_MODEL;
                        }
                    }

                    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        decode_xml_detect_empty_tag_end((void*) &r, p2, p3);

                        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                            // The empty tag end was found.
                            // Set break flag.
                            *b = *NUMBER_1_INTEGER_MEMORY_MODEL;
                        }
                    }

                    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        decode_xml_detect_tag_end((void*) &r, p2, p3);

                        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                            // The tag name end was found.
                            // Set break flag.
                            *b = *NUMBER_1_INTEGER_MEMORY_MODEL;
                        }
                    }

                    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        // Increment current position.
                        *pos = *pos + *POINTER_PRIMITIVE_SIZE;

                        // Decrement remaining count.
                        *rem = *rem - *NUMBER_1_INTEGER_MEMORY_MODEL;

                        // Increment tag name count.
                        (*tnc)++;
                    }

                } else {

                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not select xml tag name. The tag name count is null.");
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not select xml tag name. The break flag is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not select xml tag name. The current position is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not select xml tag name. The remaining count is null.");
    }
}

/**
 * Selects the attribute name.
 *
 * @param p0 the attribute name count
 * @param p1 the break flag
 * @param p2 the current position (Hand over as reference!)
 * @param p3 the remaining count
 */
void decode_xml_select_attribute_name(void* p0, void* p1, void* p2, void* p3) {

    if (p3 != *NULL_POINTER_MEMORY_MODEL) {

        int* rem = (int*) p3;

        if (p2 != *NULL_POINTER_MEMORY_MODEL) {

            void** pos = (void**) p2;

            if (p1 != *NULL_POINTER_MEMORY_MODEL) {

                int* b = (int*) p1;

                if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                    int* anc = (int*) p0;

                    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Select xml attribute name.");

                    // The comparison result.
                    int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

                    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        decode_xml_detect_attribute_name_end((void*) &r, p2, p3);

                        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                            //
                            // The attribute name end was found.
                            //
                            // CAUTION! In this case, the current position and remaining count
                            // were already changed in the called function, to be processed further
                            // in other functions.
                            //
                            // The attribute count is left as it is.
                            //

                            // Set break flag.
                            *b = *NUMBER_1_INTEGER_MEMORY_MODEL;
                        }
                    }

                    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        // Increment current position.
                        *pos = *pos + *POINTER_PRIMITIVE_SIZE;

                        // Decrement remaining count.
                        *rem = *rem - *NUMBER_1_INTEGER_MEMORY_MODEL;

                        // Increment attribute name count.
                        (*anc)++;
                    }

                } else {

                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not select xml attribute name. The attribute name count is null.");
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not select xml attribute name. The break flag is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not select xml attribute name. The current position is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not select xml attribute name. The remaining count is null.");
    }
}

/**
 * Selects the attribute value.
 *
 * @param p0 the attribute value count
 * @param p1 the break flag
 * @param p2 the current position (Hand over as reference!)
 * @param p3 the remaining count
 */
void decode_xml_select_attribute_value(void* p0, void* p1, void* p2, void* p3) {

    if (p3 != *NULL_POINTER_MEMORY_MODEL) {

        int* rem = (int*) p3;

        if (p2 != *NULL_POINTER_MEMORY_MODEL) {

            void** pos = (void**) p2;

            if (p1 != *NULL_POINTER_MEMORY_MODEL) {

                int* b = (int*) p1;

                if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                    int* avc = (int*) p0;

                    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Select xml attribute value.");

                    // The comparison result.
                    int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

                    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        decode_xml_detect_attribute_value_end((void*) &r, p2, p3);

                        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                            //
                            // The attribute value end was found.
                            //
                            // CAUTION! In this case, the current position and remaining count
                            // were already changed in the called function, to be processed further
                            // in other functions.
                            //
                            // The attribute value and count are left as they are.
                            //

                            // Set break flag.
                            *b = *NUMBER_1_INTEGER_MEMORY_MODEL;
                        }
                    }

                    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        // Increment current position.
                        *pos = *pos + *POINTER_PRIMITIVE_SIZE;

                        // Decrement remaining count.
                        *rem = *rem - *NUMBER_1_INTEGER_MEMORY_MODEL;

                        // Increment attribute value count.
                        (*avc)++;
                    }

                } else {

                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not select xml attribute value. The attribute value count is null.");
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not select xml attribute value. The break flag is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not select xml attribute value. The current position is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not select xml attribute value. The remaining count is null.");
    }
}

/**
 * Selects the xml element.
 *
 * @param p0 the destination model (Hand over as reference!)
 * @param p1 the destination model count
 * @param p2 the destination model size
 * @param p3 the destination details (Hand over as reference!)
 * @param p4 the destination details count
 * @param p5 the destination details size
 * @param p6 the break flag
 * @param p7 the current position (Hand over as reference!)
 * @param p8 the remaining count
 */
void decode_xml_select_element(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8) {

    if (p8 != *NULL_POINTER_MEMORY_MODEL) {

        int* rem = (int*) p8;

        if (p7 != *NULL_POINTER_MEMORY_MODEL) {

            void** pos = (void**) p7;

            if (p6 != *NULL_POINTER_MEMORY_MODEL) {

                int* b = (int*) p6;

                log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Select xml element.");

                // The source attribute name.
                void* an = *NULL_POINTER_MEMORY_MODEL;
                int anc = *NUMBER_0_INTEGER_MEMORY_MODEL;
                // The source attribute value.
                void* av = *NULL_POINTER_MEMORY_MODEL;
                int avc = *NUMBER_0_INTEGER_MEMORY_MODEL;

                decode_xml_process_attribute_name((void*) &an, (void*) &anc, p7, p8);
                decode_xml_process_attribute_value((void*) &av, (void*) &avc, p7, p8);

                // The destination attribute name.
                void* n = *NULL_POINTER_MEMORY_MODEL;
                void* nc = *NULL_POINTER_MEMORY_MODEL;
                void* ns = *NULL_POINTER_MEMORY_MODEL;
                // The destination attribute abstraction.
                void* a = *NULL_POINTER_MEMORY_MODEL;
                void* ac = *NULL_POINTER_MEMORY_MODEL;
                void* as = *NULL_POINTER_MEMORY_MODEL;
                // The destination attribute model.
                void* m = *NULL_POINTER_MEMORY_MODEL;
                void* mc = *NULL_POINTER_MEMORY_MODEL;
                void* ms = *NULL_POINTER_MEMORY_MODEL;
                // The destination attribute details.
                void* d = *NULL_POINTER_MEMORY_MODEL;
                void* dc = *NULL_POINTER_MEMORY_MODEL;
                void* ds = *NULL_POINTER_MEMORY_MODEL;

                // Allocate destination attribute.
                allocate_part((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                    (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                    (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT);

                // Decode destination attribute name.
                decode((void*) &n, (void*) nc, (void*) ns, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, an, (void*) &anc, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT);

                // Decode destination attribute abstraction.
                decode((void*) &a, (void*) ac, (void*) as, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT);

                // Decode destination attribute model.
                decode((void*) &m, (void*) mc, (void*) ms, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, av, (void*) &avc, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT);

                // The destination attribute details do NOT have to be decoded,
                // since an attribute itself has just name and value, but no meta information.

                //?? Extend compound size etc. before?

                // Add part to whole (compound) model.
                // CAUTION! Hand over the name as reference!
                // Storing many parts with identical tag name is not a problem,
                // since the tag name of a part is added to its details compound.
                add_compound_element_by_name(p3, p4, p5, (void*) &n, (void*) &nc, (void*) &ns, a, ac, as, m, mc, ms, d, dc, ds);

                //
                // CAUTION! The ORDER of the following function calls is IMPORTANT!
                // The empty tag end "/>" has to be searched BEFORE
                // the simple tag end ">", because of the slash "/" character.
                //
                // CAUTION! The comparison result HAS TO BE ZERO, if a detection is to be taking place!
                // Many "detect" functions are called in a sequence, below.
                // If the result of one detection function was positive (r == 1),
                // then that function increments the current position and decrements the remaining count.
                // In this case, further detection functions following afterwards might detect
                // further characters and CHANGE the current position and remaining count, and so forth,
                // which would have the effect of "jumping" over some characters and produce WRONG RESULTS!
                // Therefore, the checks for (r == 0) below avoid another detection,
                // if the result already has a value unequal zero.
                //

                // The comparison result.
                int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    decode_xml_detect_empty_tag_end((void*) &r, p7, p8);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        // This xml element is empty, so that the loop can be left now.

                        // Set break flag.
                        *b = *NUMBER_1_INTEGER_MEMORY_MODEL;
                    }
                }

                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    decode_xml_detect_tag_end((void*) &r, p7, p8);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        // The tag end was found.
                        //
                        // CAUTION! In this case, the current position and remaining count
                        // were already changed in the called function, to be processed further
                        // in other functions.

                        decode_xml_process_element_content(p0, p1, p2, p3, p4, p5, p7, p8);
                    }
                }

                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    // Increment current position.
                    *pos = *pos + *POINTER_PRIMITIVE_SIZE;

                    // Decrement remaining count.
                    *rem = *rem - *NUMBER_1_INTEGER_MEMORY_MODEL;
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not select xml element. The break flag is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not select xml element. The current position is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not select xml element. The remaining count is null.");
    }
}

/* XML_SELECTOR_SOURCE */
#endif
