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
 * @version $RCSfile: html_converter.c,v $ $Revision: 1.25 $ $Date: 2009-10-06 21:25:27 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef BEGIN_TAG_HTML_ENCODER_SOURCE
#define BEGIN_TAG_HTML_ENCODER_SOURCE

#include "../../../../constant/abstraction/memory/memory_abstraction.c"
#include "../../../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../../../constant/model/log/message_log_model.c"
#include "../../../../constant/model/memory/integer_memory_model.c"
#include "../../../../constant/model/memory/pointer_memory_model.c"
#include "../../../../executor/accessor/appender/array_appender.c"
#include "../../../../executor/converter/encoder/html/attributes_html_encoder.c"
#include "../../../../executor/converter/encoder/html/indentation_html_encoder.c"
#include "../../../../executor/modifier/appender.c"
#include "../../../../logger/logger.c"

/**
 * Encodes the html begin tag.
 *
 * @param p0 the destination html data (Hand over as reference!)
 * @param p1 the destination html data count
 * @param p2 the destination html data size
 * @param p3 the source part model
 * @param p4 the source part model count
 * @param p5 the source part details
 * @param p6 the source part details count
 * @param p7 the knowledge memory
 * @param p8 the knowledge memory count
 * @param p9 the indentation level (only for beautifying the resulting html code)
 */
void encode_html_begin_tag(void* p0, void* p1, void* p2,
    void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9) {

    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Encode html begin tag.");

    // Encode indentation.
    encode_html_indentation(p0, p1, p2, p9);
    // Encode less than character.
    append(p0, p1, p2, (void*) LESS_THAN_SIGN_UNICODE_CHARACTER_CODE_MODEL, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT);
    // Encode html tag.
    append(p0, p1, p2, p3, p4, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT);
    // Encode html tag properties.
    encode_html_attributes(p0, p1, p2, p5, p6);
    // Encode greater than character.
    append(p0, p1, p2, (void*) GREATER_THAN_SIGN_UNICODE_CHARACTER_CODE_MODEL, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT);
    // Encode line feed character, for better source reading.
    append(p0, p1, p2, (void*) LINE_FEED_CONTROL_UNICODE_CHARACTER_CODE_MODEL, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT);
}

/* BEGIN_TAG_HTML_ENCODER_SOURCE */
#endif
