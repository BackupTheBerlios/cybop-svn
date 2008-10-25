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
 * @version $RCSfile: xml_detector.c,v $ $Revision: 1.1 $ $Date: 2008-10-25 23:20:10 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef XML_DETECTOR_SOURCE
#define XML_DETECTOR_SOURCE

#include "../../constant/model/log/message_log_model.c"
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../logger/logger.c"

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

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not detect xml tag end. The comparison result is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not detect xml tag end. The current position is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not detect xml tag end. The remaining count is null.");
    }
}

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

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not detect xml declaration begin. The comparison result is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not detect xml declaration begin. The current position is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not detect xml declaration begin. The remaining count is null.");
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

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not detect xml declaration end. The comparison result is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not detect xml declaration end. The current position is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not detect xml declaration end. The remaining count is null.");
    }
}

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

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not detect xml definition begin. The comparison result is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not detect xml definition begin. The current position is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not detect xml definition begin. The remaining count is null.");
    }
}

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

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not detect xml comment begin. The comparison result is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not detect xml comment begin. The current position is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not detect xml comment begin. The remaining count is null.");
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

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not detect xml comment end. The comparison result is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not detect xml comment end. The current position is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not detect xml comment end. The remaining count is null.");
    }
}

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

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not detect xml start tag begin. The comparison result is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not detect xml start tag begin. The current position is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not detect xml start tag begin. The remaining count is null.");
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

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not detect xml end tag begin. The comparison result is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not detect xml end tag begin. The current position is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not detect xml end tag begin. The remaining count is null.");
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

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not detect xml empty tag end. The comparison result is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not detect xml empty tag end. The current position is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not detect xml empty tag end. The remaining count is null.");
    }
}

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

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not detect xml tag name end. The comparison result is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not detect xml tag name end. The current position is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not detect xml tag name end. The remaining count is null.");
    }
}

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

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not detect xml attribute name end. The comparison result is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not detect xml attribute name end. The current position is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not detect xml attribute name end. The remaining count is null.");
    }
}

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

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not detect xml attribute value end. The comparison result is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not detect xml attribute value end. The current position is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not detect xml attribute value end. The remaining count is null.");
    }
}

/* XML_DETECTOR_SOURCE */
#endif
