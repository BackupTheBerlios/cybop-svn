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
 * @version $RCSfile: xml_selector.c,v $ $Revision: 1.7 $ $Date: 2008-12-12 00:52:53 $ $Author: christian $
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

void process_xml_declaration(void* p0, void* p1, void* p2, void* p3, void* p4);
void process_xml_definition(void* p0, void* p1, void* p2, void* p3, void* p4);
void process_xml_comment(void* p0, void* p1);
void process_xml_element_content(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7);
void process_xml_end_tag(void* p0, void* p1);
void process_xml_attribute_name(void* p0, void* p1, void* p2, void* p3);
void process_xml_attribute_value(void* p0, void* p1, void* p2, void* p3);
void process_xml_element(void* p0, void* p1, void* p2, void* p3, void* p4);

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
void select_xml_declaration(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    if (p5 != *NULL_POINTER_MEMORY_MODEL) {

        int* rem = (int*) p5;

        if (p4 != *NULL_POINTER_MEMORY_MODEL) {

            void** pos = (void**) p4;

            if (p3 != *NULL_POINTER_MEMORY_MODEL) {

                int* b = (int*) p3;

                log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Select xml declaration.");

                // The comparison result.
                int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    detect_xml_declaration_end((void*) &r, p4, p5);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        // Set break flag.
                        *b = *NUMBER_1_INTEGER_MEMORY_MODEL;
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

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not select xml declaration. The break flag is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not select xml declaration. The current position is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not select xml declaration. The remaining count is null.");
    }
}

/**
 * Selects the xml definition.
 *
 * @param p0 the break flag
 * @param p1 the current position (Hand over as reference!)
 * @param p2 the remaining count
 */
void select_xml_definition(void* p0, void* p1, void* p2) {

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

                    detect_xml_definition_end((void*) &r, p1, p2);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        // Set break flag.
                        *b = *NUMBER_1_INTEGER_MEMORY_MODEL;
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
void select_xml_comment(void* p0, void* p1, void* p2) {

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

                    detect_xml_comment_end((void*) &r, p1, p2);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        // Set break flag.
                        *b = *NUMBER_1_INTEGER_MEMORY_MODEL;
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
void select_xml_element_content(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8) {

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
                // Also, the comment begin <!-- has to be searched BEFORE the definition begin <!.
                // The very first comparison, however, is to search for the end tag begin "</".
                // The reason is that all elements begin with a "<" character:
                // - declaration: <?
                // - comment: <!--
                // - definition: <!
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

    fwprintf(stdout, L"TEST select element content rem: %i\n", *rem);

                // The comparison result.
                int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    detect_xml_end_tag_begin((void*) &r, p7, p8);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

    fwprintf(stdout, L"TEST select element content end tag begin: %i\n", *rem);

                        process_xml_end_tag(p7, p8);

                        // Set break flag, because this xml element's end tag
                        // has been reached and its content fully been processed.
                        *b = *NUMBER_1_INTEGER_MEMORY_MODEL;
                    }
                }

                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    detect_xml_declaration_begin((void*) &r, p7, p8);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

    fwprintf(stdout, L"TEST select element content declaration begin: %i\n", *rem);

                        // The data contained in an XML declaration are added to the destination details.
                        process_xml_declaration(p3, p4, p5, p7, p8);
                    }
                }

                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    detect_xml_comment_begin((void*) &r, p7, p8);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

    fwprintf(stdout, L"TEST select element content comment begin: %i\n", *rem);

                        // The data contained in an XML comment are just ignored.
                        process_xml_comment(p7, p8);
                    }
                }

                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    detect_xml_definition_begin((void*) &r, p7, p8);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

    fwprintf(stdout, L"TEST select element content definition begin: %i\n", *rem);

                        // The data contained in an XML definition are added to the destination details.
                        process_xml_definition(p3, p4, p5, p7, p8);
                    }
                }

                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    detect_xml_start_tag_begin((void*) &r, p7, p8);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

    fwprintf(stdout, L"TEST select element content start tag begin: %i\n", *rem);

                        // The data contained in an XML element are added to the destination model.
                        process_xml_element(p0, p1, p2, p7, p8);
                    }
                }

                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

    fwprintf(stdout, L"TEST select element content nothing detected: %i\n", *rem);

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
void select_xml_end_tag(void* p0, void* p1, void* p2) {

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

                    detect_xml_tag_end((void*) &r, p1, p2);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        //
                        // The tag end was found.
                        //
                        // CAUTION! The current position and remaining count were already
                        // changed in the called function, to be processed further.
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
 * Selects the attribute begin or tag end.
 *
 * @param p0 the has attribute flag
 * @param p1 the has content flag
 * @param p2 the is empty flag
 * @param p3 the current position (Hand over as reference!)
 * @param p4 the remaining count
 */
void select_xml_attribute_begin_or_tag_end(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p4 != *NULL_POINTER_MEMORY_MODEL) {

        int* rem = (int*) p4;

        if (p3 != *NULL_POINTER_MEMORY_MODEL) {

            void** pos = (void**) p3;

            if (p2 != *NULL_POINTER_MEMORY_MODEL) {

                int* ie = (int*) p2;

                if (p1 != *NULL_POINTER_MEMORY_MODEL) {

                    int* hc = (int*) p1;

                    if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                        int* ha = (int*) p0;

                        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Select xml attribute begin or tag end.");

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

                            detect_xml_empty_tag_end((void*) &r, p3, p4);

                            if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                                // The empty tag end was found.
                                // Set is empty flag.
                                *ie = *NUMBER_1_INTEGER_MEMORY_MODEL;
                            }
                        }

                        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                            detect_xml_tag_end((void*) &r, p3, p4);

                            if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                                // The tag end, indicating subsequent element content, was found.
                                // Set has content flag.
                                *hc = *NUMBER_1_INTEGER_MEMORY_MODEL;
                            }
                        }

                        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                            detect_xml_attribute_begin((void*) &r, p3, p4);

                            if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                                // The tag name end, indicating subsequent attributes, was found.
                                // Set has attribute flag.
                                *ha = *NUMBER_1_INTEGER_MEMORY_MODEL;
                            }
                        }

                        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                            // Increment current position.
                            *pos = *pos + *POINTER_PRIMITIVE_SIZE;

                            // Decrement remaining count.
                            *rem = *rem - *NUMBER_1_INTEGER_MEMORY_MODEL;
                        }

                    } else {

                        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not select xml attribute begin or tag end. The has attribute flag is null.");
                    }

                } else {

                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not select xml attribute begin or tag end. The has content flag is null.");
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not select xml attribute begin or tag end. The is empty flag is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not select xml attribute begin or tag end. The current position is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not select xml attribute begin or tag end. The remaining count is null.");
    }
}

/**
 * Selects the attribute name.
 *
 * @param p0 the break flag
 * @param p1 the current position (Hand over as reference!)
 * @param p2 the remaining count
 */
void select_xml_attribute_name(void* p0, void* p1, void* p2) {

    if (p2 != *NULL_POINTER_MEMORY_MODEL) {

        int* rem = (int*) p2;

        if (p1 != *NULL_POINTER_MEMORY_MODEL) {

            void** pos = (void**) p1;

            if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                int* b = (int*) p0;

                log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Select xml attribute name.");

                // The comparison result.
                int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    detect_xml_attribute_name_end((void*) &r, p1, p2);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        // The attribute name end was found.
                        //
                        // CAUTION! The current position and remaining count were already
                        // changed in the called function, to be processed further.
                        //
                        // The attribute count is left as it is.

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
 * @param p0 the break flag
 * @param p1 the current position (Hand over as reference!)
 * @param p2 the remaining count
 */
void select_xml_attribute_value(void* p0, void* p1, void* p2) {

    if (p2 != *NULL_POINTER_MEMORY_MODEL) {

        int* rem = (int*) p2;

        if (p1 != *NULL_POINTER_MEMORY_MODEL) {

            void** pos = (void**) p1;

            if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                int* b = (int*) p0;

                log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Select xml attribute value.");

                // The comparison result.
                int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    detect_xml_attribute_value_end((void*) &r, p1, p2);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        //
                        // The attribute value end was found.
                        //
                        // CAUTION! The current position and remaining count were already
                        // changed in the called function, to be processed further.
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

/* XML_SELECTOR_SOURCE */
#endif
