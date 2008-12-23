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
 * @version $RCSfile: cybol_selector.c,v $ $Revision: 1.1 $ $Date: 2008-12-23 22:37:05 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CYBOL_SELECTOR_SOURCE
#define CYBOL_SELECTOR_SOURCE

#include "../../constant/model/log/message_log_model.c"
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../constant/name/cybol/xml_cybol_name.c"
#include "../../logger/logger.c"
#include "../../memoriser/detector/xml_detector.c"

//
// Forward declarations.
//

//?? void process_xml_declaration(void* p0, void* p1, void* p2, void* p3, void* p4);

/**
 * Selects the channel.
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
void select_cybol_channel(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8) {

    if (p8 != *NULL_POINTER_MEMORY_MODEL) {

        int* rem = (int*) p8;

        if (p7 != *NULL_POINTER_MEMORY_MODEL) {

            void** pos = (void**) p7;

            if (p6 != *NULL_POINTER_MEMORY_MODEL) {

                int* b = (int*) p6;

                log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Select cybol channel.");

                // The comparison result.
                int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    detect_xml_end_tag_begin((void*) &r, p7, p8);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        process_xml_end_tag(p7, p8);

                        // Set break flag, because this xml element's end tag
                        // has been reached and its content fully been processed.
                        *b = *NUMBER_1_INTEGER_MEMORY_MODEL;
                    }
                }

                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    // None of the comparisons above delivered a positive (r != 0) result.
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not select cybol channel. The break flag is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not select cybol channel. The current position is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not select cybol channel. The remaining count is null.");
    }
}

/**
 * Selects the abstraction.
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
void select_cybol_abstraction(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8) {

    if (p8 != *NULL_POINTER_MEMORY_MODEL) {

        int* rem = (int*) p8;

        if (p7 != *NULL_POINTER_MEMORY_MODEL) {

            void** pos = (void**) p7;

            if (p6 != *NULL_POINTER_MEMORY_MODEL) {

                int* b = (int*) p6;

                log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Select cybol abstraction.");

                // The comparison result.
                int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    detect_xml_end_tag_begin((void*) &r, p7, p8);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        process_xml_end_tag(p7, p8);

                        // Set break flag, because this xml element's end tag
                        // has been reached and its content fully been processed.
                        *b = *NUMBER_1_INTEGER_MEMORY_MODEL;
                    }
                }

                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    // None of the comparisons above delivered a positive (r != 0) result.
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not select cybol abstraction. The break flag is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not select cybol abstraction. The current position is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not select cybol abstraction. The remaining count is null.");
    }
}

/**
 * Selects the node type.
 *
 * @param p0 the model flag
 * @param p1 the part flag
 * @param p2 the property flag
 * @param p3 the node details
 * @param p4 the node details count
 */
void select_cybol_node_type(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p4 != *NULL_POINTER_MEMORY_MODEL) {

        int* rem = (int*) p4;

        if (p3 != *NULL_POINTER_MEMORY_MODEL) {

            void** pos = (void**) p3;

            if (p2 != *NULL_POINTER_MEMORY_MODEL) {

                int* pr = (int*) p2;

                if (p1 != *NULL_POINTER_MEMORY_MODEL) {

                    int* p = (int*) p1;

                    if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                        int* m = (int*) p0;

                        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Select cybol node type.");

                        //
                        // CAUTION! The comparison result HAS TO BE ZERO, if a detection is to be taking place!
                        // Many "detect" functions are called in a sequence, below.
                        //

                        // The comparison result.
                        int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

                        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                            detect_cybol_tag((void*) &r, p3, p4);

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

                        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not select cybol node type. The has attribute flag is null.");
                    }

                } else {

                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not select cybol node type. The has content flag is null.");
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not select cybol node type. The is empty flag is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not select cybol node type. The current position is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not select cybol node type. The remaining count is null.");
    }
}

/* CYBOL_SELECTOR_SOURCE */
#endif
