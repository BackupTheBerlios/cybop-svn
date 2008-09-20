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
 * @version $RCSfile: xml_converter.c,v $ $Revision: 1.22 $ $Date: 2008-09-20 08:54:08 $ $Author: christian $
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

/**
 * Detects the xml declaration begin.
 *
 * @param p0 the current position (Hand over as reference!)
 * @param p1 the remaining count
 * @param p2 the comparison result
 */
void decode_xml_detect_declaration_begin(void* p0, void* p1, void* p2) {

    if (p2 != *NULL_POINTER_MEMORY_MODEL) {

        int* r = (int*) p2;

        if (p1 != *NULL_POINTER_MEMORY_MODEL) {

            int* rem = (int*) p1;

            if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                void** pos = (void**) p0;

                log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Detect xml declaration begin.");

                if (*rem >= *DECLARATION_BEGIN_XML_NAME_COUNT) {

                    compare_arrays(*pos, (void*) DECLARATION_BEGIN_XML_NAME_COUNT, (void*) DECLARATION_BEGIN_XML_NAME, (void*) DECLARATION_BEGIN_XML_NAME_COUNT, p2, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

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
 * Detects the xml definition begin.
 *
 * @param p0 the current position (Hand over as reference!)
 * @param p1 the remaining count
 * @param p2 the comparison result
 */
void decode_xml_detect_definition_begin(void* p0, void* p1, void* p2) {

    if (p2 != *NULL_POINTER_MEMORY_MODEL) {

        int* r = (int*) p2;

        if (p1 != *NULL_POINTER_MEMORY_MODEL) {

            int* rem = (int*) p1;

            if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                void** pos = (void**) p0;

                log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Detect xml definition begin.");

                if (*rem >= *DEFINITION_BEGIN_XML_NAME_COUNT) {

                    compare_arrays(*pos, (void*) DEFINITION_BEGIN_XML_NAME_COUNT, (void*) DEFINITION_BEGIN_XML_NAME, (void*) DEFINITION_BEGIN_XML_NAME_COUNT, p2, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

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
 * Detects the xml comment begin.
 *
 * @param p0 the current position (Hand over as reference!)
 * @param p1 the remaining count
 * @param p2 the comparison result
 */
void decode_xml_detect_comment_begin(void* p0, void* p1, void* p2) {

    if (p2 != *NULL_POINTER_MEMORY_MODEL) {

        int* r = (int*) p2;

        if (p1 != *NULL_POINTER_MEMORY_MODEL) {

            int* rem = (int*) p1;

            if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                void** pos = (void**) p0;

                log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Detect xml comment begin.");

                if (*rem >= *COMMENT_BEGIN_XML_NAME_COUNT) {

                    compare_arrays(*pos, (void*) COMMENT_BEGIN_XML_NAME_COUNT, (void*) COMMENT_BEGIN_XML_NAME, (void*) COMMENT_BEGIN_XML_NAME_COUNT, p2, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

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
 * Detects the xml start tag begin.
 *
 * @param p0 the current position (Hand over as reference!)
 * @param p1 the remaining count
 * @param p2 the comparison result
 */
void decode_xml_detect_start_tag_begin(void* p0, void* p1, void* p2) {

    if (p2 != *NULL_POINTER_MEMORY_MODEL) {

        int* r = (int*) p2;

        if (p1 != *NULL_POINTER_MEMORY_MODEL) {

            int* rem = (int*) p1;

            if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                void** pos = (void**) p0;

                log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Detect xml start tag begin.");

                if (*rem >= *START_TAG_BEGIN_XML_NAME_COUNT) {

                    compare_arrays(*pos, (void*) START_TAG_BEGIN_XML_NAME_COUNT, (void*) START_TAG_BEGIN_XML_NAME, (void*) START_TAG_BEGIN_XML_NAME_COUNT, p2, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

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

                    compare_arrays(*pos, (void*) ATTRIBUTE_VALUE_END_XML_NAME_COUNT, (void*) ATTRIBUTE_VALUE_END_XML_NAME, (void*) ATTRIBUTE_VALUE_END_XML_NAME_COUNT, p2, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

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

                    compare_arrays(*pos, (void*) ATTRIBUTE_NAME_END_XML_NAME_COUNT, (void*) ATTRIBUTE_NAME_END_XML_NAME, (void*) ATTRIBUTE_NAME_END_XML_NAME_COUNT, p2, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

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

                    compare_arrays(*pos, (void*) TAG_NAME_END_XML_NAME_COUNT, (void*) TAG_NAME_END_XML_NAME, (void*) TAG_NAME_END_XML_NAME_COUNT, p2, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

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

                    compare_arrays(*pos, (void*) EMPTY_TAG_END_XML_NAME_COUNT, (void*) EMPTY_TAG_END_XML_NAME, (void*) EMPTY_TAG_END_XML_NAME_COUNT, p2, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

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

                    compare_arrays(*pos, (void*) TAG_END_XML_NAME_COUNT, (void*) TAG_END_XML_NAME, (void*) TAG_END_XML_NAME_COUNT, p2, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

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

                        //
                        // CAUTION! The ORDER of the following function calls is IMPORTANT!
                        // The empty tag end "/>" has to be searched BEFORE
                        // the simple tag end ">", because of the slash "/" character.
                        //
                        // CAUTION! The comparison result HAS TO BE ZERO, if a detection is to be taking place!
                        // Many "detect" functions are called in a sequence, below.
                        // If the result of one detection function was positive (*r == 1),
                        // then that function increments the current position and decrements the remaining count.
                        // In this case, further detection functions following afterwards might detect
                        // further characters and CHANGE the current position and remaining count, and so forth,
                        // which would have the effect of "jumping" over some characters and produce WRONG RESULTS!
                        // Therefore, the checks for (r == 0) below avoid another detection,
                        // if the result already has a value unequal zero.
                        //

                        if (*r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                            decode_xml_detect_tag_name_end(p0, p1, (void*) &r);
                        }

                        if (*r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                            decode_xml_detect_empty_tag_end(p0, p1, (void*) &r, p4);
                        }

                        if (*r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                            decode_xml_detect_tag_end(p0, p1, (void*) &r);
                        }

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
 * @param p0 the compound details (Hand over as reference!)
 * @param p1 the compound details count (Hand over as reference!)
 * @param p2 the compound details size (Hand over as reference!)
 * @param p3 the tag name (Hand over as reference!)
 * @param p4 the tag name count
 * @param p5 the empty tag flag
 * @param p6 the current position (Hand over as reference!)
 * @param p7 the remaining count
 */
void decode_xml_process_element(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    if (p5 != *NULL_POINTER_MEMORY_MODEL) {

        int* etf = (int*) p5;

        if (p1 != *NULL_POINTER_MEMORY_MODEL) {

            int* rem = (int*) p1;

            if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                void** pos = (void**) p0;

                log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Process xml element.");

                decode_xml_process_tag_name(p3, p4, p5, p6, p7);

                // The tag name end found may be one of: " ", "/>", ">".
                // The position now points to the next character AFTER the tag name end,
                // i.e. to the FIRST character of the attribute name or element content.

                // The source attribute name.
                void* an = *NULL_POINTER_MEMORY_MODEL;
                int anc = *NUMBER_0_INTEGER_MEMORY_MODEL;
                // The source attribute value.
                void* av = *NULL_POINTER_MEMORY_MODEL;
                int avc = *NUMBER_0_INTEGER_MEMORY_MODEL;

                // The attribute name.
                void* n = *NULL_POINTER_MEMORY_MODEL;
                void* nc = *NULL_POINTER_MEMORY_MODEL;
                void* ns = *NULL_POINTER_MEMORY_MODEL;
                // The attribute abstraction.
                void* a = *NULL_POINTER_MEMORY_MODEL;
                void* ac = *NULL_POINTER_MEMORY_MODEL;
                void* as = *NULL_POINTER_MEMORY_MODEL;
                // The attribute model.
                void* m = *NULL_POINTER_MEMORY_MODEL;
                void* mc = *NULL_POINTER_MEMORY_MODEL;
                void* ms = *NULL_POINTER_MEMORY_MODEL;
                // The attribute details.
                void* d = *NULL_POINTER_MEMORY_MODEL;
                void* dc = *NULL_POINTER_MEMORY_MODEL;
                void* ds = *NULL_POINTER_MEMORY_MODEL;

                // The comparison result.
                int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

                while (*NUMBER_1_INTEGER_MEMORY_MODEL) {

                    if (*rem <= *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not process xml element. The remaining count is zero or smaller.");

                        break;
                    }

                    decode_xml_process_attribute_name((void*) &an, (void*) &anc, p6, p7);
                    decode_xml_process_attribute_value((void*) &av, (void*) &avc, p6, p7);

                    if (anc > *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        // A part is only generated, if an attribute name exists (attribute name count > 0).
                        // The attribute value count, on the other hand, may be zero.

                        allocate_part((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                            (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                            (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT);

                        // Add attribute to compound.
                        // CAUTION! Hand over the name as reference!
                        add_compound_element_by_name(p0, p1, p2,
                            (void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                            (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds);
                    }

                    //
                    // CAUTION! The ORDER of the following function calls is IMPORTANT!
                    // The empty tag end "/>" has to be searched BEFORE
                    // the simple tag end ">", because of the slash "/" character.
                    //
                    // CAUTION! The comparison result HAS TO BE ZERO, if a detection is to be taking place!
                    // Many "detect" functions are called in a sequence, below.
                    // If the result of one detection function was positive (*r == 1),
                    // then that function increments the current position and decrements the remaining count.
                    // In this case, further detection functions following afterwards might detect
                    // further characters and CHANGE the current position and remaining count, and so forth,
                    // which would have the effect of "jumping" over some characters and produce WRONG RESULTS!
                    // Therefore, the checks for (r == 0) below avoid another detection,
                    // if the result already has a value unequal zero.
                    //

                    if (*r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        decode_xml_detect_empty_tag_end(p0, p1, (void*) &r, p5);
                    }

                    if (*r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        decode_xml_detect_tag_end(p0, p1, (void*) &r);
                    }

                    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        // Increment current position.
                        *pos = *pos + *POINTER_PRIMITIVE_SIZE;

                        // Decrement remaining count.
                        *rem = *rem - *NUMBER_1_INTEGER_MEMORY_MODEL;

                    } else {

                        //
                        // The empty tag end or tag end was found.
                        //
                        // CAUTION! In this case, the current position and remaining count
                        // were already changed in the called function, to be processed further
                        // in other functions.
                        //

                        if (etf == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                            // The empty tag flag is zero which means that this xml element
                            // has content and an end tag should close it.
                            // There is also the possibility that the tag does NOT have
                            // any content, in which case an end tag should follow next.

                            decode_xml_process_element_content(p6, p7);

                        } else {

                            // This xml element is empty, so that the loop can be left now.

                            break;
                        }
                    }
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not process xml element. The current position is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not process xml element. The remaining count is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not process xml element. The empty tag flag is null.");
    }
}

/**
 * Processes the xml element content.
 *
 * @param p0 the destination compound (Hand over as reference!)
 * @param p1 the destination compound count
 * @param p2 the destination compound size
 * @param p3 the current position (Hand over as reference!)
 * @param p4 the remaining count
 */
void decode_xml_process_element_content(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p4 != *NULL_POINTER_MEMORY_MODEL) {

        int* rem = (int*) p4;

        if (p3 != *NULL_POINTER_MEMORY_MODEL) {

            void** pos = (void**) p3;

            log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Process xml element content.");

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

            while (*NUMBER_1_INTEGER_MEMORY_MODEL) {

                if (*rem <= *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not process xml element content. The remaining count is zero or smaller.");

                    break;
                }

                //
                // CAUTION! The ORDER of the following function calls is IMPORTANT!
                // The end tag begin "</" has to be searched BEFORE
                // the start tag begin "<", because of the slash "/" character.
                //
                // CAUTION! The comparison result HAS TO BE ZERO, if a detection is to be taking place!
                // Many "detect" functions are called in a sequence, below.
                // If the result of one detection function was positive (*r == 1),
                // then that function increments the current position and decrements the remaining count.
                // In this case, further detection functions following afterwards might detect
                // further characters and CHANGE the current position and remaining count, and so forth,
                // which would have the effect of "jumping" over some characters and produce WRONG RESULTS!
                // Therefore, the checks for (r == 0) below avoid another detection,
                // if the result already has a value unequal zero.
                //

                if (*r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    decode_xml_detect_end_tag_begin((void*) &r, (void*) &etf, p6, p7);
                }

                if (*r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    decode_xml_detect_declaration_begin((void*) &r, p6, p7);
                }

                if (*r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    decode_xml_detect_definition_begin((void*) &r, p6, p7);
                }

                if (*r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    decode_xml_detect_comment_begin((void*) &r, p6, p7);
                }

                if (*r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    decode_xml_detect_start_tag_begin((void*) &r, p6, p7);
                }

                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    // Increment current position.
                    *pos = *pos + *POINTER_PRIMITIVE_SIZE;

                    // Decrement remaining count.
                    *rem = *rem - *NUMBER_1_INTEGER_MEMORY_MODEL;

                } else {

                    //
                    // An end tag- or start tag begin was found.
                    //
                    // CAUTION! In this case, the current position and remaining count
                    // were already changed in the called function, to be processed further
                    // in other functions.
                    //

                    if (etf == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        // An end tag flag was found.

                        decode_xml_process_end_tag((void*) &r, p6, p7);

                    } else {

                        // A start tag was found, which means that a new xml element begins here.

                        break;
                    }
                }
            }

==
            if (dec != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                // The decoder is in "declaration" mode.

                // Reset "declaration" mode flag.
                dec = *NUMBER_0_INTEGER_MEMORY_MODEL;

                decode_xml_process_declaration((void*) &c, (void*) &cc, p3, p4);

            } else if (def != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                // The decoder is in "definition" mode.

                // Reset "definition" mode flag.
                def = *NUMBER_0_INTEGER_MEMORY_MODEL;

                decode_xml_process_definition((void*) &c, p3, p4);

            } else if (com != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                // The decoder is in "comment" mode.

                // Reset "comment" mode flag.
                com = *NUMBER_0_INTEGER_MEMORY_MODEL;

                decode_xml_process_comment((void*) &c, p3, p4);

            } else if (ele != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                // The decoder is in "element" mode.

                // Reset "element" mode flag.
                ele = *NUMBER_0_INTEGER_MEMORY_MODEL;

                decode_xml_process_element((void*) &c, p3, p4);

                // Add part compound with determined tag name to whole compound.
                add_compound_element_by_name(*cd, p1, p2, tn, tnc, tnc, TEXT, TEXT_COUNT, TEXT_COUNT, tn, tnc, tnc, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL);

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

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not process xml element content. The current position is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not process xml element content. The remaining count is null.");
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
