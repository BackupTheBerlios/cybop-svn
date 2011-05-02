/*
 * Copyright (C) 1999-2011. Christian Heller.
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
 * @version $RCSfile: converter.c,v $ $Revision: 1.76 $ $Date: 2009-10-06 21:25:26 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef ENCODER_SOURCE
#define ENCODER_SOURCE

#include "../../constant/abstraction/cybol/application_cybol_abstraction.c"
#include "../../constant/abstraction/cybol/application_x_cybol_abstraction.c"
#include "../../constant/abstraction/cybol/colour_cybol_abstraction.c"
#include "../../constant/abstraction/cybol/datetime_cybol_abstraction.c"
#include "../../constant/abstraction/cybol/interface_cybol_abstraction.c"
#include "../../constant/abstraction/cybol/logicvalue_cybol_abstraction.c"
#include "../../constant/abstraction/cybol/message_cybol_abstraction.c"
#include "../../constant/abstraction/cybol/number_cybol_abstraction.c"
#include "../../constant/abstraction/cybol/operation_cybol_abstraction.c"
#include "../../constant/abstraction/cybol/text_cybol_abstraction.c"
#include "../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../constant/channel/cybol_channel.c"
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../executor/comparator/wide_character_equal_array_comparator.c"
#include "../../executor/converter/decoder/cybol_decoder.c"
#include "../../executor/converter/encoder/boolean_encoder.c"
#include "../../executor/converter/encoder/complex_encoder.c"
#include "../../executor/converter/encoder/cybol_encoder.c"
#include "../../executor/converter/encoder/date_time_encoder.c"
#include "../../executor/converter/encoder/double_vector_encoder.c"
#include "../../executor/converter/encoder/fraction_encoder.c"
#include "../../executor/converter/encoder/gnu_linux_console_encoder.c"
#include "../../executor/converter/encoder/html_encoder.c"
#include "../../executor/converter/encoder/http_request_encoder.c"
#include "../../executor/converter/encoder/http_response_encoder.c"
#include "../../executor/converter/encoder/integer_encoder.c"
#include "../../executor/converter/encoder/integer_vector_encoder.c"
#include "../../executor/converter/encoder/latex_encoder.c"
#include "../../executor/converter/encoder/model_diagram_encoder.c"
#include "../../executor/converter/encoder/terminal_background_encoder.c"
#include "../../executor/converter/encoder/terminal_foreground_encoder.c"
#include "../../executor/converter/encoder/utf_16_unicode_character_encoder.c"
#include "../../executor/converter/encoder/utf_8_unicode_character_encoder.c"
#include "../../executor/converter/encoder/xdt_encoder.c"
#include "../../executor/converter/encoder/xml_encoder.c"
#include "../../executor/converter/encoder/x_window_system_encoder.c"

/**
 * Encodes the source into the destination, according to the given language.
 *
 * @param p0 the destination (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source message name
 * @param p4 the source message name count
 * @param p5 the source message abstraction
 * @param p6 the source message abstraction count
 * @param p7 the source message model
 * @param p8 the source message model count
 * @param p9 the source message details
 * @param p10 the source message details count
 * @param p11 the source metadata name
 * @param p12 the source metadata name count
 * @param p13 the source metadata abstraction
 * @param p14 the source metadata abstraction count
 * @param p15 the source metadata model
 * @param p16 the source metadata model count
 * @param p17 the source metadata details
 * @param p18 the source metadata details count
 * @param p19 the knowledge memory
 * @param p20 the knowledge memory count
 * @param p21 the language
 * @param p22 the language count
 */
void encode(void* p0, void* p1, void* p2,
    void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10,
    void* p11, void* p12, void* p13, void* p14, void* p15, void* p16, void* p17, void* p18,
    void* p19, void* p20, void* p21, void* p22) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Encode.");

    // The comparison result.
    int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_array_equal_wide_character((void*) &r, p21, p22, (void*) BOOLEAN_LOGICVALUE_CYBOL_ABSTRACTION, (void*) BOOLEAN_LOGICVALUE_CYBOL_ABSTRACTION_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            encode_boolean(p0, p1, p2, p7, p8);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_array_equal_wide_character((void*) &r, p21, p22, (void*) CARTESIAN_COMPLEX_NUMBER_CYBOL_ABSTRACTION, (void*) CARTESIAN_COMPLEX_NUMBER_CYBOL_ABSTRACTION_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            encode_complex(p0, p1, p2, p7, p8);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_array_equal_wide_character((void*) &r, p21, p22, (void*) CYBOL_TEXT_CYBOL_ABSTRACTION, (void*) CYBOL_TEXT_CYBOL_ABSTRACTION_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            encode_cybol(p0, p1, p2, p7, p8);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_array_equal_wide_character((void*) &r, p21, p22, (void*) DECIMAL_FRACTION_NUMBER_CYBOL_ABSTRACTION, (void*) DECIMAL_FRACTION_NUMBER_CYBOL_ABSTRACTION_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            encode_double_vector(p0, p1, p2, p7, p8);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_array_equal_wide_character((void*) &r, p21, p22, (void*) ENCAPSULATED_KNOWLEDGE_PATH_CYBOL_ABSTRACTION, (void*) ENCAPSULATED_KNOWLEDGE_PATH_CYBOL_ABSTRACTION_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            append(p0, p1, p2, p7, p8, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_array_equal_wide_character((void*) &r, p21, p22, (void*) GNU_LINUX_CONSOLE_CYBOL_CHANNEL, (void*) GNU_LINUX_CONSOLE_CYBOL_CHANNEL_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

//??            encode_gnu_linux_console(p0, p1, p2, p7, p8, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, p13, p14);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_array_equal_wide_character((void*) &r, p21, p22, (void*) HH_MM_SS_DATETIME_CYBOL_ABSTRACTION, (void*) HH_MM_SS_DATETIME_CYBOL_ABSTRACTION_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            encode_date_time(p0, p1, p2, p7, p8);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_array_equal_wide_character((void*) &r, p21, p22, (void*) HTML_TEXT_CYBOL_ABSTRACTION, (void*) HTML_TEXT_CYBOL_ABSTRACTION_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            encode_html(p0, p1, p2, p5, p6, p7, p8, p9, p10, p19, p20);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_array_equal_wide_character((void*) &r, p21, p22, (void*) HTTP_REQUEST_MESSAGE_CYBOL_ABSTRACTION, (void*) HTTP_REQUEST_MESSAGE_CYBOL_ABSTRACTION_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            //?? encode_http_request();
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_array_equal_wide_character((void*) &r, p21, p22, (void*) HTTP_RESPONSE_MESSAGE_CYBOL_ABSTRACTION, (void*) HTTP_RESPONSE_MESSAGE_CYBOL_ABSTRACTION_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            encode_http_response(p0, p1, p2, p5, p6, p7, p8, p9, p10, p13, p14, p15, p16, p17, p18);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_array_equal_wide_character((void*) &r, p21, p22, (void*) INTEGER_MEMORY_ABSTRACTION, (void*) INTEGER_MEMORY_ABSTRACTION_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            encode_integer_vector(p0, p1, p2, p7, p8);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_array_equal_wide_character((void*) &r, p21, p22, (void*) KNOWLEDGE_PATH_CYBOL_ABSTRACTION, (void*) KNOWLEDGE_PATH_CYBOL_ABSTRACTION_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            append(p0, p1, p2, p7, p8, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_array_equal_wide_character((void*) &r, p21, p22, (void*) LATEX_APPLICATION_X_CYBOL_ABSTRACTION, (void*) LATEX_APPLICATION_X_CYBOL_ABSTRACTION_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            encode_latex(p0, p1, p2, p7, p8);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_array_equal_wide_character((void*) &r, p21, p22, (void*) MODEL_DIAGRAM_TEXT_CYBOL_ABSTRACTION, (void*) MODEL_DIAGRAM_TEXT_CYBOL_ABSTRACTION_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            encode_model_diagram(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_array_equal_wide_character((void*) &r, p21, p22, (void*) PLAIN_OPERATION_CYBOL_ABSTRACTION, (void*) PLAIN_OPERATION_CYBOL_ABSTRACTION_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            append(p0, p1, p2, p7, p8, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_array_equal_wide_character((void*) &r, p21, p22, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            append(p0, p1, p2, p7, p8, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_array_equal_wide_character((void*) &r, p21, p22, (void*) TERMINAL_BACKGROUND_COLOUR_CYBOL_ABSTRACTION, (void*) TERMINAL_BACKGROUND_COLOUR_CYBOL_ABSTRACTION_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            encode_terminal_background(p0, p1, p2, p7, p8);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_array_equal_wide_character((void*) &r, p21, p22, (void*) TERMINAL_FOREGROUND_COLOUR_CYBOL_ABSTRACTION, (void*) TERMINAL_FOREGROUND_COLOUR_CYBOL_ABSTRACTION_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            encode_terminal_foreground(p0, p1, p2, p7, p8);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_array_equal_wide_character((void*) &r, p21, p22, (void*) VULGAR_FRACTION_NUMBER_CYBOL_ABSTRACTION, (void*) VULGAR_FRACTION_NUMBER_CYBOL_ABSTRACTION_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            encode_fraction(p0, p1, p2, p7, p8);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_array_equal_wide_character((void*) &r, p21, p22, (void*) X_WINDOW_SYSTEM_CYBOL_CHANNEL, (void*) X_WINDOW_SYSTEM_CYBOL_CHANNEL_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            encode_x_window_system(p0, p1, p2, p7, p8, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, p19, p20);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_array_equal_wide_character((void*) &r, p21, p22, (void*) XDT_TEXT_CYBOL_ABSTRACTION, (void*) XDT_TEXT_CYBOL_ABSTRACTION_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            encode_xdt(p0, p1, p2, p7, p8);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_array_equal_wide_character((void*) &r, p21, p22, (void*) YYYY_MM_DD_DATETIME_CYBOL_ABSTRACTION, (void*) YYYY_MM_DD_DATETIME_CYBOL_ABSTRACTION_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            encode_ddmmyyyy_date_time(p0, p1, p2, p7, p8);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        log_terminated_message((void*) WARNING_LEVEL_LOG_MODEL, (void*) L"Could not encode. The language is unknown.");
    }
}

/* ENCODER_SOURCE */
#endif
