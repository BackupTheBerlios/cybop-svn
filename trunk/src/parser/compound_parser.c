/*
 * $RCSfile: compound_parser.c,v $
 *
 * Copyright (c) 1999-2004. Christian Heller. All rights reserved.
 *
 * This software is published under the GPL GNU General Public License.
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
 * @version $Revision: 1.2 $ $Date: 2004-08-23 07:18:33 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef COMPOUND_PARSER_SOURCE
#define COMPOUND_PARSER_SOURCE

#include "../global/log_constants.c"
#include "../logger/logger.c"

//
// This file handles a compound model which represents state or logic knowledge.
//
// A persistent compound model consists of:
// - part name
// - part abstraction
// - part location
// - part model (either inline or path to model at location)
// - part constraint
// - position abstraction
// - position location
// - position model (either inline or path to model at location)
// - position constraint
//
// CYBOL Examples:
// <part name="example_0" abstraction="compound" location="ftp,address,login,password" model="/test_compound.cybol"/>
// <part name="example_1" abstraction="string" location="file" model="/test_string.txt"/>
// <part name="example_2" abstraction="string" location="inline" model="This is a test string."/>
// <part name="example_3" abstraction="integer" location="inline" model="5" constraint="minimum=1,maximum=10,area=1..10"/>
//
// A transient compound model keeps the following meta information about its parts:
// - part model
// - part abstraction
// - part constraint
// - position model
// - position abstraction
// - position constraint
//
// CAUTION!
// The part/position location is not stored as it is not needed at runtime.
//
// A compound is like a table, the first column (array) containing the part names
// and the following columns (arrays) containing the meta information about the parts.
// Model parts can such be accessed over their index or name.
// They can also be accessed hierarchically, using a dot-separated name like:
// "system.frame.menu_bar.exit_menu_item.action"
//
// A compound model represents an abstract description of some real world item
// in one of the physical measurements (dimensions):
// - space
// - time
// - mass
//
// A compound model can be created by cloning an existing model template so that
// some space gets allocated in the computer's memory.
//

/**
 * Parses the byte stream and creates a compound model from it.
 *
 * @param p0 the destination
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source
 * @param p4 the source count
 */
void parse_compound(void* p0, void* p1, void* p2, const void* p3, const void* p4) {

    if (p4 != NULL_POINTER) {

        int* sc = (int*) p4;

        if (p3 != NULL_POINTER) {

            void** s = (void**) p3;

            if (p0 != NULL_POINTER) {

                void** d = (void**) p0;

            } else {

//??                log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_PARSE_INTEGER_THE_DESTINATION_IS_NULL_MESSAGE, (void*) &COULD_NOT_PARSE_INTEGER_THE_DESTINATION_IS_NULL_MESSAGE_COUNT);
            }

        } else {

//??            log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_PARSE_INTEGER_THE_SOURCE_IS_NULL_MESSAGE, (void*) &COULD_NOT_PARSE_INTEGER_THE_SOURCE_IS_NULL_MESSAGE_COUNT);
        }

    } else {

//??        log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_PARSE_INTEGER_THE_SOURCE_COUNT_IS_NULL_MESSAGE, (void*) &COULD_NOT_PARSE_INTEGER_THE_SOURCE_COUNT_IS_NULL_MESSAGE_COUNT);
    }
}

/**
 * Serializes the compound model and creates a byte stream from it.
 *
 * @param p0 the destination
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source
 * @param p4 the source count
 */
void serialize_compound(void* p0, void* p1, void* p2, const void* p3, const void* p4) {
}

/* COMPOUND_PARSER_SOURCE */
#endif
