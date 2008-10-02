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
 * @version $RCSfile: xml_converter.c,v $ $Revision: 1.27 $ $Date: 2008-10-02 22:17:08 $ $Author: christian $
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
// General.
//

/**
 * Detects the xml tag end.
 *
 * @param p0 the comparison result
 * @param p1 the current position (Hand over as reference!)
 * @param p2 the remaining count
 */
void decode_xml_detect_tag_end(void* p0, void* p1, void* p2) {

    if (p2 != *NULL_POINTER_MEMORY_MODEL) {

        int* rem = (int*) p2;

        if (p1 != *NULL_POINTER_MEMORY_MODEL) {

            void** pos = (void**) p1;

            if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                int* r = (int*) p0;

                log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Detect xml tag end.");

                if (*rem >= *TAG_END_XML_NAME_COUNT) {

                    compare_arrays(*pos, (void*) TAG_END_XML_NAME_COUNT, (void*) TAG_END_XML_NAME, (void*) TAG_END_XML_NAME_COUNT, p0, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

                    if (*r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        // Increment current position.
                        *pos = *pos + (*TAG_END_XML_NAME_COUNT * *POINTER_PRIMITIVE_SIZE);

                        // Decrement remaining count.
                        *rem = *rem - *TAG_END_XML_NAME_COUNT;
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

//
// Declaration.
//

/**
 * Detects the xml declaration begin.
 *
 * @param p0 the comparison result
 * @param p1 the current position (Hand over as reference!)
 * @param p2 the remaining count
 */
void decode_xml_detect_declaration_begin(void* p0, void* p1, void* p2) {

    if (p2 != *NULL_POINTER_MEMORY_MODEL) {

        int* rem = (int*) p2;

        if (p1 != *NULL_POINTER_MEMORY_MODEL) {

            void** pos = (void**) p1;

            if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                int* r = (int*) p0;

                log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Detect xml declaration begin.");

                if (*rem >= *DECLARATION_BEGIN_XML_NAME_COUNT) {

                    compare_arrays(*pos, (void*) DECLARATION_BEGIN_XML_NAME_COUNT, (void*) DECLARATION_BEGIN_XML_NAME, (void*) DECLARATION_BEGIN_XML_NAME_COUNT, p0, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

                    if (*r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        // Increment current position.
                        *pos = *pos + (*DECLARATION_BEGIN_XML_NAME_COUNT * *POINTER_PRIMITIVE_SIZE);

                        // Decrement remaining count.
                        *rem = *rem - *DECLARATION_BEGIN_XML_NAME_COUNT;
                    }

                } else {

                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not detect xml declaration begin. The remaining count is too small.");
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not detect xml declaration begin. The current position is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not detect xml declaration begin. The remaining count is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not detect xml declaration begin. The comparison result is null.");
    }
}

/**
 * Detects the xml declaration end.
 *
 * @param p0 the comparison result
 * @param p1 the current position (Hand over as reference!)
 * @param p2 the remaining count
 */
void decode_xml_detect_declaration_end(void* p0, void* p1, void* p2) {

    if (p2 != *NULL_POINTER_MEMORY_MODEL) {

        int* rem = (int*) p2;

        if (p1 != *NULL_POINTER_MEMORY_MODEL) {

            void** pos = (void**) p1;

            if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                int* r = (int*) p0;

                log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Detect xml declaration end.");

                if (*rem >= *DECLARATION_END_XML_NAME_COUNT) {

                    compare_arrays(*pos, (void*) DECLARATION_END_XML_NAME_COUNT, (void*) DECLARATION_END_XML_NAME, (void*) DECLARATION_END_XML_NAME_COUNT, p0, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

                    if (*r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        // Increment current position.
                        *pos = *pos + (*DECLARATION_END_XML_NAME_COUNT * *POINTER_PRIMITIVE_SIZE);

                        // Decrement remaining count.
                        *rem = *rem - *DECLARATION_END_XML_NAME_COUNT;
                    }

                } else {

                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not detect xml declaration end. The remaining count is too small.");
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not detect xml declaration end. The current position is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not detect xml declaration end. The remaining count is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not detect xml declaration end. The comparison result is null.");
    }
}

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
 * Processes the xml declaration.
 *
 * @param p0 the destination details (Hand over as reference!)
 * @param p1 the destination details count
 * @param p2 the destination details size
 * @param p3 the current position (Hand over as reference!)
 * @param p4 the remaining count
 */
void decode_xml_process_declaration(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p4 != *NULL_POINTER_MEMORY_MODEL) {

        int* rem = (int*) p4;

        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Process xml declaration.");

        // The break flag.
        int b = *NUMBER_0_INTEGER_MEMORY_MODEL;

        while (*NUMBER_1_INTEGER_MEMORY_MODEL) {

            if (*rem <= *NUMBER_0_INTEGER_MEMORY_MODEL) {

                break;
            }

            decode_xml_select_declaration((void*) &b, p3, p4);
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not process xml declaration. The remaining bytes count is null.");
    }
}

//
// Definition.
//

/**
 * Detects the xml definition begin.
 *
 * @param p0 the comparison result
 * @param p1 the current position (Hand over as reference!)
 * @param p2 the remaining count
 */
void decode_xml_detect_definition_begin(void* p0, void* p1, void* p2) {

    if (p2 != *NULL_POINTER_MEMORY_MODEL) {

        int* rem = (int*) p2;

        if (p1 != *NULL_POINTER_MEMORY_MODEL) {

            void** pos = (void**) p1;

            if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                int* r = (int*) p0;

                log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Detect xml definition begin.");

                if (*rem >= *DEFINITION_BEGIN_XML_NAME_COUNT) {

                    compare_arrays(*pos, (void*) DEFINITION_BEGIN_XML_NAME_COUNT, (void*) DEFINITION_BEGIN_XML_NAME, (void*) DEFINITION_BEGIN_XML_NAME_COUNT, p0, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

                    if (*r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        // Increment current position.
                        *pos = *pos + (*DEFINITION_BEGIN_XML_NAME_COUNT * *POINTER_PRIMITIVE_SIZE);

                        // Decrement remaining count.
                        *rem = *rem - *DEFINITION_BEGIN_XML_NAME_COUNT;
                    }

                } else {

                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not detect xml definition begin. The remaining count is too small.");
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not detect xml definition begin. The current position is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not detect xml definition begin. The remaining count is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not detect xml definition begin. The comparison result is null.");
    }
}

/**
 * Selects the xml definition.
 *
 * @param p0 the break flag
 * @param p1 the current byte (Hand over as reference!)
 * @param p2 the remaining bytes count
 */
void decode_xml_select_definition(void* p0, void* p1) {

    if (p0 != *NULL_POINTER_MEMORY_MODEL) {

        int* b = (int*) p0;

        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Select xml definition.");

        // The comparison result.
        int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            compare_arrays(*b, p1, (void*) DEFINITION_END_XML_NAME, (void*) DEFINITION_END_XML_NAME_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

            if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                // Set break flag.
                *b = *NUMBER_1_INTEGER_MEMORY_MODEL;
            }
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not select xml definition. The break flag is null.");
    }
}

/**
 * Processes the xml definition.
 *
 * @param p0 the current byte (Hand over as reference!)
 * @param p1 the remaining bytes count
 */
void decode_xml_process_definition(void* p0, void* p1) {

    if (p1 != *NULL_POINTER_MEMORY_MODEL) {

        int* rem = (int*) p1;

        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Process xml definition.");

        // The break flag.
        int b = *NUMBER_0_INTEGER_MEMORY_MODEL;

        while (*NUMBER_1_INTEGER_MEMORY_MODEL) {

            if (*rem <= *NUMBER_0_INTEGER_MEMORY_MODEL) {

                break;
            }

            decode_xml_select_definition((void*) &b);
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not process xml definition. The remaining bytes count is null.");
    }
}

//
// Comment.
//

/**
 * Detects the xml comment begin.
 *
 * @param p0 the comparison result
 * @param p1 the current position (Hand over as reference!)
 * @param p2 the remaining count
 */
void decode_xml_detect_comment_begin(void* p0, void* p1, void* p2) {

    if (p2 != *NULL_POINTER_MEMORY_MODEL) {

        int* rem = (int*) p2;

        if (p1 != *NULL_POINTER_MEMORY_MODEL) {

            void** pos = (void**) p1;

            if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                int* r = (int*) p0;

                log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Detect xml comment begin.");

                if (*rem >= *COMMENT_BEGIN_XML_NAME_COUNT) {

                    compare_arrays(*pos, (void*) COMMENT_BEGIN_XML_NAME_COUNT, (void*) COMMENT_BEGIN_XML_NAME, (void*) COMMENT_BEGIN_XML_NAME_COUNT, p0, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

                    if (*r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        // Increment current position.
                        *pos = *pos + (*COMMENT_BEGIN_XML_NAME_COUNT * *POINTER_PRIMITIVE_SIZE);

                        // Decrement remaining count.
                        *rem = *rem - *COMMENT_BEGIN_XML_NAME_COUNT;
                    }

                } else {

                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not detect xml comment begin. The remaining count is too small.");
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not detect xml comment begin. The current position is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not detect xml comment begin. The remaining count is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not detect xml comment begin. The comparison result is null.");
    }
}

/**
 * Detects the xml comment end.
 *
 * @param p0 the comparison result
 * @param p1 the current position (Hand over as reference!)
 * @param p2 the remaining count
 */
void decode_xml_detect_comment_end(void* p0, void* p1, void* p2) {

    if (p2 != *NULL_POINTER_MEMORY_MODEL) {

        int* rem = (int*) p2;

        if (p1 != *NULL_POINTER_MEMORY_MODEL) {

            void** pos = (void**) p1;

            if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                int* r = (int*) p0;

                log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Detect xml comment end.");

                if (*rem >= *COMMENT_END_XML_NAME_COUNT) {

                    compare_arrays(*pos, (void*) COMMENT_END_XML_NAME_COUNT, (void*) COMMENT_END_XML_NAME, (void*) COMMENT_END_XML_NAME_COUNT, p0, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

                    if (*r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        // Increment current position.
                        *pos = *pos + (*COMMENT_END_XML_NAME_COUNT * *POINTER_PRIMITIVE_SIZE);

                        // Decrement remaining count.
                        *rem = *rem - *COMMENT_END_XML_NAME_COUNT;
                    }

                } else {

                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not detect xml comment end. The remaining count is too small.");
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not detect xml comment end. The current position is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not detect xml comment end. The remaining count is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not detect xml comment end. The comparison result is null.");
    }
}

/**
 * Selects the xml comment.
 *
 * @param p0 the break flag
 * @param p1 the current byte (Hand over as reference!)
 * @param p2 the remaining bytes count
 */
void decode_xml_select_comment(void* p0, void* p1) {

    if (p0 != *NULL_POINTER_MEMORY_MODEL) {

        int* b = (int*) p0;

        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Select xml comment.");

        // The comparison result.
        int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            compare_arrays(*b, p1, (void*) COMMENT_END_XML_NAME, (void*) COMMENT_END_XML_NAME_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

            if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                // Set break flag.
                *b = *NUMBER_1_INTEGER_MEMORY_MODEL;
            }
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not select xml comment. The break flag is null.");
    }
}

//
// Element content.
//

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

                // The comparison result.
                int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    decode_xml_detect_end_tag_begin((void*) &r, p7, p8);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        decode_xml_process_end_tag((void*) &tn, (void*) &tnc, p7, p8);

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

                    decode_xml_detect_start_tag_begin((void*) &r, p7, p8);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

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
 * Processes the xml element content.
 *
 * @param p0 the destination model (Hand over as reference!)
 * @param p1 the destination model count
 * @param p2 the destination model size
 * @param p3 the destination details (Hand over as reference!)
 * @param p4 the destination details count
 * @param p5 the destination details size
 * @param p6 the current position (Hand over as reference!)
 * @param p7 the remaining count
 */
void decode_xml_process_element_content(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    if (p7 != *NULL_POINTER_MEMORY_MODEL) {

        int* rem = (int*) p7;

        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Process xml element content.");

        // The break flag.
        int b = *NUMBER_0_INTEGER_MEMORY_MODEL;

        while (*NUMBER_1_INTEGER_MEMORY_MODEL) {

            if (*rem <= *NUMBER_0_INTEGER_MEMORY_MODEL) {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not process xml element content. The remaining count is zero or smaller.");

                break;
            }

            if (b != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                break;
            }

            decode_xml_select_element_content(p0, p1, p2, p3, p4, p5, (void*) &b, p6, p7);
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not process xml element content. The remaining count is null.");
    }
}

//
// Element.
//

/**
 * Detects the xml start tag begin.
 *
 * @param p0 the comparison result
 * @param p1 the current position (Hand over as reference!)
 * @param p2 the remaining count
 */
void decode_xml_detect_start_tag_begin(void* p0, void* p1, void* p2) {

    if (p2 != *NULL_POINTER_MEMORY_MODEL) {

        int* rem = (int*) p2;

        if (p1 != *NULL_POINTER_MEMORY_MODEL) {

            void** pos = (void**) p1;

            if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                int* r = (int*) p0;

                log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Detect xml start tag begin.");

                if (*rem >= *START_TAG_BEGIN_XML_NAME_COUNT) {

                    compare_arrays(*pos, (void*) START_TAG_BEGIN_XML_NAME_COUNT, (void*) START_TAG_BEGIN_XML_NAME, (void*) START_TAG_BEGIN_XML_NAME_COUNT, p0, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

                    if (*r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        // Increment current position.
                        *pos = *pos + (*START_TAG_BEGIN_XML_NAME_COUNT * *POINTER_PRIMITIVE_SIZE);

                        // Decrement remaining count.
                        *rem = *rem - *START_TAG_BEGIN_XML_NAME_COUNT;
                    }

                } else {

                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not detect xml start tag begin. The remaining count is too small.");
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not detect xml start tag begin. The current position is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not detect xml start tag begin. The remaining count is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not detect xml start tag begin. The comparison result is null.");
    }
}

/**
 * Detects the xml end tag begin.
 *
 * @param p0 the comparison result
 * @param p1 the current position (Hand over as reference!)
 * @param p2 the remaining count
 */
void decode_xml_detect_end_tag_begin(void* p0, void* p1, void* p2) {

    if (p2 != *NULL_POINTER_MEMORY_MODEL) {

        int* rem = (int*) p2;

        if (p1 != *NULL_POINTER_MEMORY_MODEL) {

            void** pos = (void**) p1;

            if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                int* r = (int*) p0;

                log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Detect xml end tag begin.");

                if (*rem >= *END_TAG_BEGIN_XML_NAME_COUNT) {

                    compare_arrays(*pos, (void*) END_TAG_BEGIN_XML_NAME_COUNT, (void*) END_TAG_BEGIN_XML_NAME, (void*) END_TAG_BEGIN_XML_NAME_COUNT, p0, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

                    if (*r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        // Increment current position.
                        *pos = *pos + (*END_TAG_BEGIN_XML_NAME_COUNT * *POINTER_PRIMITIVE_SIZE);

                        // Decrement remaining count.
                        *rem = *rem - *END_TAG_BEGIN_XML_NAME_COUNT;
                    }

                } else {

                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not detect xml end tag begin. The remaining count is too small.");
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not detect xml end tag begin. The current position is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not detect xml end tag begin. The remaining count is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not detect xml end tag begin. The comparison result is null.");
    }
}

/**
 * Detects the xml empty tag end.
 *
 * @param p0 the comparison result
 * @param p1 the current position (Hand over as reference!)
 * @param p2 the remaining count
 */
void decode_xml_detect_empty_tag_end(void* p0, void* p1, void* p2) {

    if (p2 != *NULL_POINTER_MEMORY_MODEL) {

        int* rem = (int*) p2;

        if (p1 != *NULL_POINTER_MEMORY_MODEL) {

            void** pos = (void**) p1;

            if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                int* r = (int*) p0;

                log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Detect xml empty tag end.");

                if (*rem >= *EMPTY_TAG_END_XML_NAME_COUNT) {

                    compare_arrays(*pos, (void*) EMPTY_TAG_END_XML_NAME_COUNT, (void*) EMPTY_TAG_END_XML_NAME, (void*) EMPTY_TAG_END_XML_NAME_COUNT, p0, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

                    if (*r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        // Increment current position.
                        *pos = *pos + (*EMPTY_TAG_END_XML_NAME_COUNT * *POINTER_PRIMITIVE_SIZE);

                        // Decrement remaining count.
                        *rem = *rem - *EMPTY_TAG_END_XML_NAME_COUNT;
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
 * Selects the end tag.
 *
 * @param p0 the destination model (Hand over as reference!)
 * @param p1 the destination model count
 * @param p2 the destination model size
 * @param p3 the current position (Hand over as reference!)
 * @param p4 the remaining count
 */
void decode_xml_select_end_tag(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p3 != *NULL_POINTER_MEMORY_MODEL) {

        int* rem = (int*) p3;

        if (p2 != *NULL_POINTER_MEMORY_MODEL) {

            void** pos = (void**) p2;

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

                decode_xml_detect_tag_end((void*) &r, p2, p3);

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

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not select xml end tag. The current position is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not select xml end tag. The remaining count is null.");
    }
}

/**
 * Processes the xml end tag.
 *
 * @param p0 the tag name (Hand over as reference!)
 * @param p1 the tag name count
 * @param p2 the current position (Hand over as reference!)
 * @param p3 the remaining count
 */
void decode_xml_process_end_tag(void* p0, void* p1, void* p2, void* p3) {

    if (p3 != *NULL_POINTER_MEMORY_MODEL) {

        int* rem = (int*) p3;

        if (p2 != *NULL_POINTER_MEMORY_MODEL) {

            void** pos = (void**) p2;

            log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Process xml end tag.");

            // The break flag.
            int b = *NUMBER_0_INTEGER_MEMORY_MODEL;

            while (*NUMBER_1_INTEGER_MEMORY_MODEL) {

                if (*rem <= *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not process xml end tag. The remaining count is zero or smaller.");

                    break;
                }

                decode_xml_select_end_tag((void*) &b);
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not process xml end tag. The current position is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not process xml end tag. The remaining count is null.");
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

/**
 * Processes the xml element.
 *
 * @param p0 the destination whole model (Hand over as reference!)
 * @param p1 the destination whole model count
 * @param p2 the destination whole model size
 * @param p3 the current position (Hand over as reference!)
 * @param p4 the remaining count
 */
void decode_xml_process_element(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p4 != *NULL_POINTER_MEMORY_MODEL) {

        int* rem = (int*) p4;

        if (p3 != *NULL_POINTER_MEMORY_MODEL) {

            void** pos = (void**) p3;

            log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Process xml element.");

            // The part name.
            void* n = *NULL_POINTER_MEMORY_MODEL;
            void* nc = *NULL_POINTER_MEMORY_MODEL;
            void* ns = *NULL_POINTER_MEMORY_MODEL;
            // The part abstraction.
            void* a = *NULL_POINTER_MEMORY_MODEL;
            void* ac = *NULL_POINTER_MEMORY_MODEL;
            void* as = *NULL_POINTER_MEMORY_MODEL;
            // The part model.
            void* m = *NULL_POINTER_MEMORY_MODEL;
            void* mc = *NULL_POINTER_MEMORY_MODEL;
            void* ms = *NULL_POINTER_MEMORY_MODEL;
            // The part details.
            void* d = *NULL_POINTER_MEMORY_MODEL;
            void* dc = *NULL_POINTER_MEMORY_MODEL;
            void* ds = *NULL_POINTER_MEMORY_MODEL;

            // Allocate destination name.
            allocate_part((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT);

            // Decode destination part name.
            // CAUTION! The pre-defined constant "part" is used as name here!
            // The "add_compound_element_by_name" function below will automatically
            // add a number as suffix, to make the name unique.
            decode((void*) &n, (void*) nc, (void*) ns, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, (void*) PART_XML_CYBOL_NAME, (void*) PART_XML_CYBOL_NAME_COUNT, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT);

            // Decode destination part abstraction.
            // CAUTION! All xml elements (parts) are of the abstraction "compound",
            // as internally used by the function "allocate_part" above.
            // If an xml element is empty, the compound will just not contain any parts.
            decode((void*) &a, (void*) ac, (void*) as, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, (void*) COMPOUND_MEMORY_ABSTRACTION, (void*) COMPOUND_MEMORY_ABSTRACTION_COUNT, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT);

            // The destination part model and details are decoded further below,
            // depending on the source byte array.

            // Decode tag name.
            decode_xml_process_tag_name((void*) &d, (void*) &dc, (void*) &ds, p3, p4);

            // The tag name end found may be one of: " ", "/>", ">".
            // The position now points to the next character AFTER the tag name end,
            // i.e. to the FIRST character of the attribute name or element content.

            // The break flag.
            int b = *NUMBER_0_INTEGER_MEMORY_MODEL;

            while (*NUMBER_1_INTEGER_MEMORY_MODEL) {

                if (*rem <= *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not process xml element. The remaining count is zero or smaller.");

                    break;
                }

                if (b != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    break;
                }

                // Process the element's attributes.
                decode_xml_select_element((void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds, (void*) &b, p3, p4);
            }

            //?? Extend compound size etc. before?

            // Add part to whole (compound) model.
            // CAUTION! Hand over the name as reference!
            // Storing many parts with identical tag name is not a problem,
            // since the tag name of a part is added to its details compound.
            add_compound_element_by_name(p0, p1, p2, (void*) &n, (void*) &nc, (void*) &ns, a, ac, as, m, mc, ms, d, dc, ds);

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not process xml element. The current position is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not process xml element. The remaining count is null.");
    }
}

//
// Tag name.
//

/**
 * Detects the xml tag name end.
 *
 * @param p0 the comparison result
 * @param p1 the current position (Hand over as reference!)
 * @param p2 the remaining count
 */
void decode_xml_detect_tag_name_end(void* p0, void* p1, void* p2) {

    if (p2 != *NULL_POINTER_MEMORY_MODEL) {

        int* rem = (int*) p2;

        if (p1 != *NULL_POINTER_MEMORY_MODEL) {

            void** pos = (void**) p1;

            if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                int* r = (int*) p0;

                log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Detect xml tag name end.");

                if (*rem >= *TAG_NAME_END_XML_NAME_COUNT) {

                    compare_arrays(*pos, (void*) TAG_NAME_END_XML_NAME_COUNT, (void*) TAG_NAME_END_XML_NAME, (void*) TAG_NAME_END_XML_NAME_COUNT, p0, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

                    if (*r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        // Increment current position.
                        *pos = *pos + (*TAG_NAME_END_XML_NAME_COUNT * *POINTER_PRIMITIVE_SIZE);

                        // Decrement remaining count.
                        *rem = *rem - *TAG_NAME_END_XML_NAME_COUNT;
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

                        decode_xml_detect_tag_name_end((void*) &r, p4, p5);

                        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                            // The tag name end was found.
                            // Set break flag.
                            *b = *NUMBER_1_INTEGER_MEMORY_MODEL;
                        }
                    }

                    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        decode_xml_detect_empty_tag_end((void*) &r, p0, p1, p4);

                        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                            // The tag name end was found.
                            // Set break flag.
                            *b = *NUMBER_1_INTEGER_MEMORY_MODEL;
                        }
                    }

                    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        decode_xml_detect_tag_end((void*) &r, p4, p5);

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
 * Processes the xml tag name.
 *
 * @param p0 the destination element details (Hand over as reference!)
 * @param p1 the destination element details count
 * @param p2 the destination element details size
 * @param p3 the current position (Hand over as reference!)
 * @param p4 the remaining count
 */
void decode_xml_process_tag_name(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p4 != *NULL_POINTER_MEMORY_MODEL) {

        int* rem = (int*) p4;

        if (p3 != *NULL_POINTER_MEMORY_MODEL) {

            void** pos = (void**) p3;

            log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Process xml tag name.");

            // The destination tag name name.
            void* n = *NULL_POINTER_MEMORY_MODEL;
            void* nc = *NULL_POINTER_MEMORY_MODEL;
            void* ns = *NULL_POINTER_MEMORY_MODEL;
            // The destination tag name abstraction.
            void* a = *NULL_POINTER_MEMORY_MODEL;
            void* ac = *NULL_POINTER_MEMORY_MODEL;
            void* as = *NULL_POINTER_MEMORY_MODEL;
            // The destination tag name model.
            void* m = *NULL_POINTER_MEMORY_MODEL;
            void* mc = *NULL_POINTER_MEMORY_MODEL;
            void* ms = *NULL_POINTER_MEMORY_MODEL;
            // The destination tag name details.
            void* d = *NULL_POINTER_MEMORY_MODEL;
            void* dc = *NULL_POINTER_MEMORY_MODEL;
            void* ds = *NULL_POINTER_MEMORY_MODEL;

            // Allocate destination tag name.
            allocate_part((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT);

            // The source tag name.
            void* tn = *pos;
            int tnc = *NUMBER_0_INTEGER_MEMORY_MODEL;

            // The break flag.
            int b = *NUMBER_0_INTEGER_MEMORY_MODEL;

            while (*NUMBER_1_INTEGER_MEMORY_MODEL) {

                if (*rem <= *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not process xml tag name. The remaining count is zero or smaller.");

                    break;
                }

                if (b != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    break;
                }

                decode_xml_select_tag_name((void*) &tnc, (void*) &b, p3, p4);
            }

            // Decode destination tag name name.
            // CAUTION! The pre-defined constant "tag" is used as name here!
            // The "add_compound_element_by_name" function below will automatically
            // add a number as suffix, to make the name unique.
            decode((void*) &n, (void*) nc, (void*) ns, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, (void*) TAG_XML_CYBOL_NAME, (void*) TAG_XML_CYBOL_NAME_COUNT, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT);

            // Decode destination tag name abstraction.
            // CAUTION! All xml element tag names are of the abstraction "wide_character",
            // as handed over as argument in the function "allocate_part" above.
            decode((void*) &a, (void*) ac, (void*) as, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT);

            // Decode destination tag name model.
            decode((void*) &m, (void*) mc, (void*) ms, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, tn, (void*) &tnc, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT);

            // The destination tag name does not contain any details.

            //?? Extend compound size etc. before?

            // Add tag name to destination xml element (compound) details.
            // CAUTION! Hand over the tag name name as reference!
            // CAUTION! The pre-defined constant "tag" is used as name here!
            add_compound_element_by_name(p0, p1, p2, (void*) &n, (void*) &nc, (void*) &ns, a, ac, as, m, mc, ms, d, dc, ds);

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not process xml tag name. The current position is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not process xml tag name. The remaining count is null.");
    }
}

//
// Attribute name.
//

/**
 * Detects the xml attribute name end.
 *
 * @param p0 the comparison result
 * @param p1 the current position (Hand over as reference!)
 * @param p2 the remaining count
 */
void decode_xml_detect_attribute_name_end(void* p0, void* p1, void* p2) {

    if (p2 != *NULL_POINTER_MEMORY_MODEL) {

        int* rem = (int*) p2;

        if (p1 != *NULL_POINTER_MEMORY_MODEL) {

            void** pos = (void**) p1;

            if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                int* r = (int*) p0;

                log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Detect xml attribute name end.");

                if (*rem >= *ATTRIBUTE_NAME_END_XML_NAME_COUNT) {

                    compare_arrays(*pos, (void*) ATTRIBUTE_NAME_END_XML_NAME_COUNT, (void*) ATTRIBUTE_NAME_END_XML_NAME, (void*) ATTRIBUTE_NAME_END_XML_NAME_COUNT, p0, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

                    if (*r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        // Increment current position.
                        *pos = *pos + (*ATTRIBUTE_NAME_END_XML_NAME_COUNT * *POINTER_PRIMITIVE_SIZE);

                        // Decrement remaining count.
                        *rem = *rem - *ATTRIBUTE_NAME_END_XML_NAME_COUNT;
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
 * Processes the xml attribute name.
 *
 * @param p0 the attribute name (Hand over as reference!)
 * @param p1 the attribute name count
 * @param p2 the current position (Hand over as reference!)
 * @param p3 the remaining count
 */
void decode_xml_process_attribute_name(void* p0, void* p1, void* p2, void* p3) {

    if (p3 != *NULL_POINTER_MEMORY_MODEL) {

        int* rem = (int*) p3;

        if (p2 != *NULL_POINTER_MEMORY_MODEL) {

            void** pos = (void**) p2;

            if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                void** an = (void**) p0;

                log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Process xml attribute name.");

                // Set attribute name.
                *an = *pos;

                // The break flag.
                int b = *NUMBER_0_INTEGER_MEMORY_MODEL;

                while (*NUMBER_1_INTEGER_MEMORY_MODEL) {

                    if (*rem <= *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not process xml attribute name. The remaining count is zero or smaller.");

                        break;
                    }

                    decode_xml_select_attribute_name(p1, (void*) &b, p2, p3);
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not process xml attribute name. The attribute name is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not process xml attribute name. The current position is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not process xml attribute name. The remaining count is null.");
    }
}

//
// Attribute value.
//

/**
 * Detects the xml attribute value end.
 *
 * @param p0 the comparison result
 * @param p1 the current position (Hand over as reference!)
 * @param p2 the remaining count
 */
void decode_xml_detect_attribute_value_end(void* p0, void* p1, void* p2) {

    if (p2 != *NULL_POINTER_MEMORY_MODEL) {

        int* rem = (int*) p2;

        if (p1 != *NULL_POINTER_MEMORY_MODEL) {

            void** pos = (void**) p1;

            if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                int* r = (int*) p0;

                log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Detect xml attribute value end.");

                if (*rem >= *ATTRIBUTE_VALUE_END_XML_NAME_COUNT) {

                    compare_arrays(*pos, (void*) ATTRIBUTE_VALUE_END_XML_NAME_COUNT, (void*) ATTRIBUTE_VALUE_END_XML_NAME, (void*) ATTRIBUTE_VALUE_END_XML_NAME_COUNT, p0, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

                    if (*r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        // Increment current position.
                        *pos = *pos + (*ATTRIBUTE_VALUE_END_XML_NAME_COUNT * *POINTER_PRIMITIVE_SIZE);

                        // Decrement remaining count.
                        *rem = *rem - *ATTRIBUTE_VALUE_END_XML_NAME_COUNT;
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
 * Processes the xml attribute value.
 *
 * @param p0 the attribute value (Hand over as reference!)
 * @param p1 the attribute value count
 * @param p2 the current position (Hand over as reference!)
 * @param p3 the remaining count
 */
void decode_xml_process_attribute_value(void* p0, void* p1, void* p2, void* p3) {

    if (p3 != *NULL_POINTER_MEMORY_MODEL) {

        int* rem = (int*) p3;

        if (p2 != *NULL_POINTER_MEMORY_MODEL) {

            void** pos = (void**) p2;

            if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                void** av = (void**) p0;

                log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Process xml attribute value.");

                // Set attribute value.
                *av = *pos;

                // The break flag.
                int b = *NUMBER_0_INTEGER_MEMORY_MODEL;

                while (*NUMBER_1_INTEGER_MEMORY_MODEL) {

                    if (*rem <= *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not process xml attribute value. The remaining count is zero or smaller.");

                        break;
                    }

                    decode_xml_select_attribute_value(p1, (void*) &b, p2, p3);
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not process xml attribute value. The attribute value is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not process xml attribute value. The current position is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not process xml attribute value. The remaining count is null.");
    }
}

//
// Entry functions.
//

/**
 * Decodes the xml byte array into a compound model and -details.
 *
 * @param p0 the destination model (Hand over as reference!)
 * @param p1 the destination model count
 * @param p2 the destination model size
 * @param p3 the destination details (Hand over as reference!)
 * @param p4 the destination details count
 * @param p5 the destination details size
 * @param p6 the source byte array
 * @param p7 the source byte array count
 */
void decode_xml(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Decode xml.");

    decode_xml_process_element_content(p0, p1, p2, p3, p4, p5, (void*) &p6, p7);
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
