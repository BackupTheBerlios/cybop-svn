/*
 * Copyright (C) 1999-2010. Christian Heller.
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
 * @version $RCSfile: model_diagram_converter.c,v $ $Revision: 1.29 $ $Date: 2009-10-06 21:25:27 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef MODEL_DIAGRAM_DECODER_SOURCE
#define MODEL_DIAGRAM_DECODER_SOURCE

#include "../../../constant/model/character_code/unicode/unicode_character_code_model.c"
#include "../../../constant/abstraction/cybol/text_cybol_abstraction.c"
#include "../../../constant/model/memory/integer_memory_model.c"
#include "../../../constant/model/log/message_log_model.c"
#include "../../../constant/abstraction/memory/memory_abstraction.c"
#include "../../../constant/abstraction/memory/memory_abstraction.c"
#include "../../../constant/abstraction/memory/memory_abstraction.c"
#include "../../../constant/model/memory/pointer_memory_model.c"
#include "../../../logger/logger.c"

/**
 * Decodes the model diagram and creates a knowledge model from it.
 *
 * A model diagram in this case is a textual representation of a knowledge model,
 * in form of many line feed-separated lines representing a model part each.
 *
 * @param p0 the destination knowledge model (Hand over as reference!)
 * @param p1 the destination knowledge model count
 * @param p2 the destination knowledge model size
 * @param p3 the source model diagram
 * @param p4 the source count
 */
void decode_model_diagram(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Decode model diagram.");
}

/* MODEL_DIAGRAM_DECODER_SOURCE */
#endif
