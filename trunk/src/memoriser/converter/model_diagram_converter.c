/*
 * $RCSfile: model_diagram_converter.c,v $
 *
 * Copyright (c) 1999-2007. Christian Heller and the CYBOP developers.
 *
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
 * @version $Revision: 1.1 $ $Date: 2007-04-07 22:58:12 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef MODEL_DIAGRAM_CONVERTER_SOURCE
#define MODEL_DIAGRAM_CONVERTER_SOURCE

#include "../../globals/constants/log_constants.c"
#include "../../globals/logger/logger.c"
/*??
#include "../../globals/constants/boolean_constants.c"
#include "../../globals/constants/integer_constants.c"
#include "../../globals/constants/model_constants.c"
#include "../../globals/constants/structure_constants.c"
#include "../../memoriser/allocator.c"
#include "../../memoriser/array.c"
*/

/**
 * Parses the model diagram and creates a knowledge model from it.
 *
 * A model diagram in this case is a textual representation of a knowledge model,
 * in form of many line feed-separated lines representing a model part each.
 *
 * @param p0 the destination knowledge model (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source model diagram
 * @param p4 the source count
 */
void parse_model_diagram(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message_debug("Parse model diagram.");
}

/**
 * Serialises the knowledge model part.
 *
 * @param p0 the destination model diagram (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source knowledge model
 * @param p4 the source count
 */
void serialise_model_diagram_part(void* p0, void* p1, void* p2, void* p3, void* p4) {
}

/**
 * Serialises the knowledge model and creates a model diagram from it.
 *
 * A model diagram in this case is a textual representation of a knowledge model,
 * in form of many line feed-separated lines representing a model part each.
 *
 * @param p0 the destination model diagram (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source knowledge model
 * @param p4 the source count
 */
void serialise_model_diagram(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p3 != NULL_POINTER) {

        int* s = (int*) p3;

        if (p1 != NULL_POINTER) {

            int* dc = (int*) p1;

            log_message_debug("Serialise model diagram.");

            serialise_model_diagram_part(p0, p1, p2, p3, p4);

        } else {

            log_message_debug("Could not serialise model diagram. The ?? is null.");
        }

    } else {

        log_message_debug("Could not serialise model diagram. The ?? is null.");
    }
}

/* MODEL_DIAGRAM_CONVERTER_SOURCE */
#endif
