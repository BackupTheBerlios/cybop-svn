/*
 * Copyright (C) 1999-2009. Christian Heller.
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
 * @version $RCSfile: xml_cybol_name.c,v $ $Revision: 1.4 $ $Date: 2009-01-31 16:06:30 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef XML_CYBOL_NAME_SOURCE
#define XML_CYBOL_NAME_SOURCE

#include <stddef.h>
#include "../../../constant/model/memory/integer_memory_model.c"

/** The node xml cybol name. */
static wchar_t NODE_XML_CYBOL_NAME_ARRAY[] = {L'n', L'o', L'd', L'e'};
static wchar_t* NODE_XML_CYBOL_NAME = NODE_XML_CYBOL_NAME_ARRAY;
static int* NODE_XML_CYBOL_NAME_COUNT = NUMBER_4_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The node name xml cybol name.
 *
 * CAUTION! The node name is intentionally left empty.
 * The cyboi xml parser adds the xml tag name and xml attribute names
 * to a node's details, all on the same level.
 * But because xml attributes may have arbitrary names,
 * an ambiguous situation could be caused when fixing a node's name.
 *
 * Example:
 *
 * <catalogue>
 *     <article number="01234">
 *         <colour name="red" value="255,0,0" model="rgb"/>
 *         <size width="10" length="5" height="2"/>
 *     </article>
 * </catalogue>
 *
 * The "colour" tag has an attribute "name" with the value "red".
 * After having parsed the xml file, the resulting cyboi model might look as follows:
 *
 *  | compound
 * +-node_$0 | compound
 * | +-node_$0 | compound
 * | | +-node_$0 | compound
 * | | | #-name | wide_character_vector | colour
 * | | | #-name | wide_character_vector | red
 * | | | #-value | wide_character_vector | 255,0,0
 * | | | #-model | wide_character_vector | rgb
 * | | +-node_$1 | compound
 * | | | #-name | wide_character_vector | size
 * | | | #-width | wide_character_vector | 10
 * | | | #-length | wide_character_vector | 5
 * | | | #-height | wide_character_vector | 2
 * | | #-name | wide_character_vector | article
 * | | #-number | wide_character_vector | 01234
 * | #-name | wide_character_vector | catalogue
 *
 * One of the nodes has two sub nodes (for the tag name and attribute name)
 * with identical name:
 *
 * | | | #-name | wide_character_vector | colour
 * | | | #-name | wide_character_vector | red
 *
 * In order to avoid an ambiguous situation of this kind,
 * the node name representing the tag name does NOT receive ANY name.
 * In other words, it is just left empty.
 * For the example above, this would result in the following cyboi model:
 *
 *  | compound
 * +-node_$0 | compound
 * | +-node_$0 | compound
 * | | +-node_$0 | compound
 * | | | #- | wide_character_vector | colour
 * | | | #-name | wide_character_vector | red
 * | | | #-value | wide_character_vector | 255,0,0
 * | | | #-model | wide_character_vector | rgb
 * | | +-node_$1 | compound
 * | | | #- | wide_character_vector | size
 * | | | #-width | wide_character_vector | 10
 * | | | #-length | wide_character_vector | 5
 * | | | #-height | wide_character_vector | 2
 * | | #- | wide_character_vector | article
 * | | #-number | wide_character_vector | 01234
 * | #- | wide_character_vector | catalogue
 */
static wchar_t NODE_NAME_XML_CYBOL_NAME_ARRAY[] = {};
static wchar_t* NODE_NAME_XML_CYBOL_NAME = NODE_NAME_XML_CYBOL_NAME_ARRAY;
static int* NODE_NAME_XML_CYBOL_NAME_COUNT = NUMBER_0_INTEGER_MEMORY_MODEL_ARRAY;

/* XML_CYBOL_NAME_SOURCE */
#endif
