/*
 * $RCSfile: compound.c,v $
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
 * This file handles a compound model which represents state or logic knowledge.
 *
 * A persistent compound model consists of:
 * - part name
 * - part abstraction
 * - part location
 * - part model (either inline or path to model at location)
 * - part constraint
 * - position abstraction
 * - position location
 * - position model (either inline or path to model at location)
 * - position constraint
 *
 * CYBOL Examples:
 * <part name="example_0" abstraction="compound" location="ftp,address,login,password" model="/test_compound.cybol"/>
 * <part name="example_1" abstraction="string" location="file" model="/test_string.txt"/>
 * <part name="example_2" abstraction="string" location="inline" model="This is a test string."/>
 * <part name="example_3" abstraction="integer" location="inline" model="5" constraint="minimum=1,maximum=10,area=1..10"/>
 *
 * A transient compound model keeps the following meta information about its parts:
 * - part model
 * - part abstraction
 * - part constraint
 * - position model
 * - position abstraction
 * - position constraint
 *
 * CAUTION!
 * The part/position location is not stored as it is not needed at runtime.
 *
 * A compound is like a table, the first column (array) containing the part names
 * and the following columns (arrays) containing the meta information about the parts.
 * Model parts can such be accessed over their index or name.
 * They can also be accessed hierarchically, using a dot-separated name like:
 * "system.frame.menu_bar.exit_menu_item.action"
 *
 * A compound model represents an abstract description of some real world item
 * in one of the physical measurements (dimensions):
 * - space
 * - time
 * - mass
 *
 * A compound model can be created by cloning an existing model template so that
 * some space gets allocated in the computer's memory.
 *
 * @version $Revision: 1.8 $ $Date: 2004-07-22 23:18:22 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef COMPOUND_SOURCE
#define COMPOUND_SOURCE

#include "../array/array.c"
#include "../cybol/cybol.c"
#include "../global/constant.c"
#include "../logger/logger.c"

//
// Compound.
//

/**
 * Creates the compound.
 *
 * @param p0 the transient model
 * @param p1 the transient model size
 */
void create_compound(void* p0, const void* p1) {

//??    log_message((void*) &INFO_LOG_LEVEL, (void*) &CREATE_COMPOUND_MESSAGE, (void*) &CREATE_COMPOUND_MESSAGE_COUNT);

    // Create compound.
    create_array(p0, (void*) &POINTER_ARRAY, (void*) &COMPOUND_COUNT);

    // Initialize part names, abstractions, models, constraints
    // and position abstractions, models, constraints
    // and their counts and sizes.
    void* pn = NULL_POINTER;
    void* pnc = NULL_POINTER;
    void* pns = NULL_POINTER;
    void* pa = NULL_POINTER;
    void* pac = NULL_POINTER;
    void* pas = NULL_POINTER;
    void* pm = NULL_POINTER;
    void* pmc = NULL_POINTER;
    void* pms = NULL_POINTER;
    void* pc = NULL_POINTER;
    void* pcc = NULL_POINTER;
    void* pcs = NULL_POINTER;
    void* poa = NULL_POINTER;
    void* poac = NULL_POINTER;
    void* poas = NULL_POINTER;
    void* pom = NULL_POINTER;
    void* pomc = NULL_POINTER;
    void* poms = NULL_POINTER;
    void* poc = NULL_POINTER;
    void* pocc = NULL_POINTER;
    void* pocs = NULL_POINTER;

    // Create part names, abstractions, models, constraints
    // and position abstractions, models, constraints
    // and their counts and sizes.
    create_array((void*) &pn, (void*) &POINTER_ARRAY, p1);
    create_array((void*) &pnc, (void*) &INTEGER_ARRAY, p1);
    create_array((void*) &pns, (void*) &INTEGER_ARRAY, p1);
    create_array((void*) &pm, (void*) &POINTER_ARRAY, p1);
    create_array((void*) &pmc, (void*) &INTEGER_ARRAY, p1);
    create_array((void*) &pms, (void*) &INTEGER_ARRAY, p1);
    create_array((void*) &pa, (void*) &POINTER_ARRAY, p1);
    create_array((void*) &pac, (void*) &INTEGER_ARRAY, p1);
    create_array((void*) &pas, (void*) &INTEGER_ARRAY, p1);
    create_array((void*) &pc, (void*) &POINTER_ARRAY, p1);
    create_array((void*) &pcc, (void*) &INTEGER_ARRAY, p1);
    create_array((void*) &pcs, (void*) &INTEGER_ARRAY, p1);
    create_array((void*) &pom, (void*) &POINTER_ARRAY, p1);
    create_array((void*) &pomc, (void*) &INTEGER_ARRAY, p1);
    create_array((void*) &poms, (void*) &INTEGER_ARRAY, p1);
    create_array((void*) &poa, (void*) &POINTER_ARRAY, p1);
    create_array((void*) &poac, (void*) &INTEGER_ARRAY, p1);
    create_array((void*) &poas, (void*) &INTEGER_ARRAY, p1);
    create_array((void*) &poc, (void*) &POINTER_ARRAY, p1);
    create_array((void*) &pocc, (void*) &INTEGER_ARRAY, p1);
    create_array((void*) &pocs, (void*) &INTEGER_ARRAY, p1);

    //
    // Use ascending order.
    //

    // Set part names, abstractions, models, constraints
    // and position abstractions, models, constraints
    // and their counts and sizes.
    set_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_NAMES_INDEX, (void*) &pn);
    set_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_NAMES_COUNTS_INDEX, (void*) &pnc);
    set_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_NAMES_SIZES_INDEX, (void*) &pns);
    set_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_ABSTRACTIONS_INDEX, (void*) &pa);
    set_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_ABSTRACTIONS_COUNTS_INDEX, (void*) &pac);
    set_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_ABSTRACTIONS_SIZES_INDEX, (void*) &pas);
    set_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_MODELS_INDEX, (void*) &pm);
    set_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_MODELS_COUNTS_INDEX, (void*) &pmc);
    set_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_MODELS_SIZES_INDEX, (void*) &pms);
    set_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_CONSTRAINTS_INDEX, (void*) &pc);
    set_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_CONSTRAINTS_COUNTS_INDEX, (void*) &pcc);
    set_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_CONSTRAINTS_SIZES_INDEX, (void*) &pcs);
    set_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_ABSTRACTIONS_INDEX, (void*) &poa);
    set_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_ABSTRACTIONS_COUNTS_INDEX, (void*) &poac);
    set_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_ABSTRACTIONS_SIZES_INDEX, (void*) &poas);
    set_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_MODELS_INDEX, (void*) &pom);
    set_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_MODELS_COUNTS_INDEX, (void*) &pomc);
    set_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_MODELS_SIZES_INDEX, (void*) &poms);
    set_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_CONSTRAINTS_INDEX, (void*) &poc);
    set_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_CONSTRAINTS_COUNTS_INDEX, (void*) &pocc);
    set_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_CONSTRAINTS_SIZES_INDEX, (void*) &pocs);
}

/**
 * Destroys the compound.
 *
 * @param p0 the transient model
 * @param p1 the transient model size
 */
void destroy_compound(void* p0, const void* p1) {

//??    log_message((void*) &INFO_LOG_LEVEL, (void*) &DESTROY_COMPOUND_MESSAGE, (void*) &DESTROY_COMPOUND_MESSAGE_COUNT);

    // Initialize part names, abstractions, models, constraints
    // and position abstractions, models, constraints
    // and their counts and sizes.
    void* pn = NULL_POINTER;
    void* pnc = NULL_POINTER;
    void* pns = NULL_POINTER;
    void* pa = NULL_POINTER;
    void* pac = NULL_POINTER;
    void* pas = NULL_POINTER;
    void* pm = NULL_POINTER;
    void* pmc = NULL_POINTER;
    void* pms = NULL_POINTER;
    void* pc = NULL_POINTER;
    void* pcc = NULL_POINTER;
    void* pcs = NULL_POINTER;
    void* poa = NULL_POINTER;
    void* poac = NULL_POINTER;
    void* poas = NULL_POINTER;
    void* pom = NULL_POINTER;
    void* pomc = NULL_POINTER;
    void* poms = NULL_POINTER;
    void* poc = NULL_POINTER;
    void* pocc = NULL_POINTER;
    void* pocs = NULL_POINTER;

    // Get part names, abstractions, models, constraints
    // and position abstractions, models, constraints
    // and their counts and sizes.
    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_NAMES_INDEX, (void*) &pn);
    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_NAMES_COUNTS_INDEX, (void*) &pnc);
    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_NAMES_SIZES_INDEX, (void*) &pns);
    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_ABSTRACTIONS_INDEX, (void*) &pa);
    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_ABSTRACTIONS_COUNTS_INDEX, (void*) &pac);
    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_ABSTRACTIONS_SIZES_INDEX, (void*) &pas);
    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_MODELS_INDEX, (void*) &pm);
    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_MODELS_COUNTS_INDEX, (void*) &pmc);
    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_MODELS_SIZES_INDEX, (void*) &pms);
    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_CONSTRAINTS_INDEX, (void*) &pc);
    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_CONSTRAINTS_COUNTS_INDEX, (void*) &pcc);
    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_CONSTRAINTS_SIZES_INDEX, (void*) &pcs);
    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_ABSTRACTIONS_INDEX, (void*) &poa);
    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_ABSTRACTIONS_COUNTS_INDEX, (void*) &poac);
    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_ABSTRACTIONS_SIZES_INDEX, (void*) &poas);
    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_MODELS_INDEX, (void*) &pom);
    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_MODELS_COUNTS_INDEX, (void*) &pomc);
    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_MODELS_SIZES_INDEX, (void*) &poms);
    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_CONSTRAINTS_INDEX, (void*) &poc);
    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_CONSTRAINTS_COUNTS_INDEX, (void*) &pocc);
    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_CONSTRAINTS_SIZES_INDEX, (void*) &pocs);

    //
    // Use descending order.
    //

    // Remove part names, abstractions, models, constraints
    // and position abstractions, models, constraints
    // and their counts and sizes.
    remove_array_element(p0, (void*) &POINTER_ARRAY, (void*) &COMPOUND_COUNT, (void*) &POSITION_CONSTRAINTS_SIZES_INDEX);
    remove_array_element(p0, (void*) &POINTER_ARRAY, (void*) &COMPOUND_COUNT, (void*) &POSITION_CONSTRAINTS_COUNTS_INDEX);
    remove_array_element(p0, (void*) &POINTER_ARRAY, (void*) &COMPOUND_COUNT, (void*) &POSITION_CONSTRAINTS_INDEX);
    remove_array_element(p0, (void*) &POINTER_ARRAY, (void*) &COMPOUND_COUNT, (void*) &POSITION_MODELS_SIZES_INDEX);
    remove_array_element(p0, (void*) &POINTER_ARRAY, (void*) &COMPOUND_COUNT, (void*) &POSITION_MODELS_COUNTS_INDEX);
    remove_array_element(p0, (void*) &POINTER_ARRAY, (void*) &COMPOUND_COUNT, (void*) &POSITION_MODELS_INDEX);
    remove_array_element(p0, (void*) &POINTER_ARRAY, (void*) &COMPOUND_COUNT, (void*) &POSITION_ABSTRACTIONS_SIZES_INDEX);
    remove_array_element(p0, (void*) &POINTER_ARRAY, (void*) &COMPOUND_COUNT, (void*) &POSITION_ABSTRACTIONS_COUNTS_INDEX);
    remove_array_element(p0, (void*) &POINTER_ARRAY, (void*) &COMPOUND_COUNT, (void*) &POSITION_ABSTRACTIONS_INDEX);
    remove_array_element(p0, (void*) &POINTER_ARRAY, (void*) &COMPOUND_COUNT, (void*) &PART_CONSTRAINTS_SIZES_INDEX);
    remove_array_element(p0, (void*) &POINTER_ARRAY, (void*) &COMPOUND_COUNT, (void*) &PART_CONSTRAINTS_COUNTS_INDEX);
    remove_array_element(p0, (void*) &POINTER_ARRAY, (void*) &COMPOUND_COUNT, (void*) &PART_CONSTRAINTS_INDEX);
    remove_array_element(p0, (void*) &POINTER_ARRAY, (void*) &COMPOUND_COUNT, (void*) &PART_MODELS_SIZES_INDEX);
    remove_array_element(p0, (void*) &POINTER_ARRAY, (void*) &COMPOUND_COUNT, (void*) &PART_MODELS_COUNTS_INDEX);
    remove_array_element(p0, (void*) &POINTER_ARRAY, (void*) &COMPOUND_COUNT, (void*) &PART_MODELS_INDEX);
    remove_array_element(p0, (void*) &POINTER_ARRAY, (void*) &COMPOUND_COUNT, (void*) &PART_ABSTRACTIONS_SIZES_INDEX);
    remove_array_element(p0, (void*) &POINTER_ARRAY, (void*) &COMPOUND_COUNT, (void*) &PART_ABSTRACTIONS_COUNTS_INDEX);
    remove_array_element(p0, (void*) &POINTER_ARRAY, (void*) &COMPOUND_COUNT, (void*) &PART_ABSTRACTIONS_INDEX);
    remove_array_element(p0, (void*) &POINTER_ARRAY, (void*) &COMPOUND_COUNT, (void*) &PART_NAMES_SIZES_INDEX);
    remove_array_element(p0, (void*) &POINTER_ARRAY, (void*) &COMPOUND_COUNT, (void*) &PART_NAMES_COUNTS_INDEX);
    remove_array_element(p0, (void*) &POINTER_ARRAY, (void*) &COMPOUND_COUNT, (void*) &PART_NAMES_INDEX);

    // Destroy part names, abstractions, models, constraints
    // and position abstractions, models, constraints
    // and their counts and sizes.
    destroy_array((void*) &pn, (void*) &POINTER_ARRAY, p1);
    destroy_array((void*) &pnc, (void*) &INTEGER_ARRAY, p1);
    destroy_array((void*) &pns, (void*) &INTEGER_ARRAY, p1);
    destroy_array((void*) &pa, (void*) &POINTER_ARRAY, p1);
    destroy_array((void*) &pac, (void*) &INTEGER_ARRAY, p1);
    destroy_array((void*) &pas, (void*) &INTEGER_ARRAY, p1);
    destroy_array((void*) &pm, (void*) &POINTER_ARRAY, p1);
    destroy_array((void*) &pmc, (void*) &INTEGER_ARRAY, p1);
    destroy_array((void*) &pms, (void*) &INTEGER_ARRAY, p1);
    destroy_array((void*) &pc, (void*) &POINTER_ARRAY, p1);
    destroy_array((void*) &pcc, (void*) &INTEGER_ARRAY, p1);
    destroy_array((void*) &pcs, (void*) &INTEGER_ARRAY, p1);
    destroy_array((void*) &poa, (void*) &POINTER_ARRAY, p1);
    destroy_array((void*) &poac, (void*) &INTEGER_ARRAY, p1);
    destroy_array((void*) &poas, (void*) &INTEGER_ARRAY, p1);
    destroy_array((void*) &pom, (void*) &POINTER_ARRAY, p1);
    destroy_array((void*) &pomc, (void*) &INTEGER_ARRAY, p1);
    destroy_array((void*) &poms, (void*) &INTEGER_ARRAY, p1);
    destroy_array((void*) &poc, (void*) &POINTER_ARRAY, p1);
    destroy_array((void*) &pocc, (void*) &INTEGER_ARRAY, p1);
    destroy_array((void*) &pocs, (void*) &INTEGER_ARRAY, p1);

    // Destroy compound.
    destroy_array(p0, (void*) &POINTER_ARRAY, (void*) &COMPOUND_COUNT);
}

//
// Forward declarations.
//
// These functions are the only forward declarations. They are needed because
// compounds can recursively create/ destroy other models.
//

/**
 * Creates a model.
 *
 * @param p0 the transient model
 * @param p1 the transient model count
 * @param p2 the transient model size
 * @param p3 the persistent abstraction
 * @param p4 the persistent abstraction count
 * @param p5 the persistent location
 * @param p6 the persistent location count
 * @param p7 the persistent model
 * @param p8 the persistent model count
 */
/*??
void create_model(void* p0, void* p1, void* p2,
    const void* p3, const void* p4,
    const void* p5, const void* p6,
    const void* p7, const void* p8);

/**
 * Destroys a model.
 *
 * @param p0 the transient model
 * @param p1 the transient model count
 * @param p2 the transient model size
 * @param p3 the transient position model
 * @param p4 the transient position model count
 * @param p5 the transient position model size
 * @param p6 the persistent part abstraction
 * @param p7 the persistent part abstraction count
 * @param p8 the persistent part location
 * @param p9 the persistent part location count
 * @param p10 the persistent part model
 * @param p11 the persistent part model count
 * @param p12 the persistent position abstraction
 * @param p13 the persistent position abstraction count
 * @param p14 the persistent position location
 * @param p15 the persistent position location count
 * @param p16 the persistent position model
 * @param p17 the persistent position model count
 */
/*??
void destroy_model(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5,
    const void* p6, const void* p7, const void* p8, const void* p9, const void* p10, const void* p11,
    const void* p12, const void* p13, const void* p14, const void* p15, const void* p16, const void* p17);

//
// Values.
//

/**
 * Interprets the name value.
 *
 * @param p0 the persistent value pointer
 * @param p1 the persistent value count
 */
void interpret_name_value(const void* p0, const void* p1) {
}

/**
 * Serializes the name value.
 *
 * @param p0 the persistent value pointer
 * @param p1 the persistent value count
 */
void serialize_name_value(const void* p0, const void* p1) {
}

/**
 * Interprets the abstraction value.
 *
 * @param p0 the persistent value pointer
 * @param p1 the persistent value count
 */
void interpret_abstraction_value(const void* p0, const void* p1) {
}

/**
 * Serializes the abstraction value.
 *
 * @param p0 the persistent value pointer
 * @param p1 the persistent value count
 */
void serialize_abstraction_value(const void* p0, const void* p1) {
}

/**
 * Interprets the location value.
 *
 * @param p0 the persistent value pointer
 * @param p1 the persistent value count
 */
void interpret_location_value(const void* p0, const void* p1) {
}

/**
 * Serializes the location value.
 *
 * @param p0 the persistent value pointer
 * @param p1 the persistent value count
 */
void serialize_location_value(const void* p0, const void* p1) {
}

/**
 * Interprets the model value.
 *
 * @param p0 the persistent value pointer
 * @param p1 the persistent value count
 */
void interpret_model_value(const void* p0, const void* p1) {
}

/**
 * Serializes the model value.
 *
 * @param p0 the persistent value pointer
 * @param p1 the persistent value count
 */
void serialize_model_value(const void* p0, const void* p1) {
}

/**
 * Interprets the constraint value.
 *
 * @param p0 the persistent value pointer
 * @param p1 the persistent value count
 */
void interpret_constraint_value(const void* p0, const void* p1) {
}

/**
 * Serializes the constraint value.
 *
 * @param p0 the persistent value pointer
 * @param p1 the persistent value count
 */
void serialize_constraint_value(const void* p0, const void* p1) {
}

/**
 * Interprets the position abstraction value.
 *
 * @param p0 the persistent value pointer
 * @param p1 the persistent value count
 */
void interpret_position_abstraction_value(const void* p0, const void* p1) {
}

/**
 * Serializes the position abstraction value.
 *
 * @param p0 the persistent value pointer
 * @param p1 the persistent value count
 */
void serialize_position_abstraction_value(const void* p0, const void* p1) {
}

/**
 * Interprets the position location value.
 *
 * @param p0 the persistent value pointer
 * @param p1 the persistent value count
 */
void interpret_position_location_value(const void* p0, const void* p1) {
}

/**
 * Serializes the position location value.
 *
 * @param p0 the persistent value pointer
 * @param p1 the persistent value count
 */
void serialize_position_location_value(const void* p0, const void* p1) {
}

/**
 * Interprets the position model value.
 *
 * @param p0 the persistent value pointer
 * @param p1 the persistent value count
 */
void interpret_position_model_value(const void* p0, const void* p1) {
}

/**
 * Serializes the position model value.
 *
 * @param p0 the persistent value pointer
 * @param p1 the persistent value count
 */
void serialize_position_model_value(const void* p0, const void* p1) {
}

/**
 * Interprets the position constraint value.
 *
 * @param p0 the persistent value pointer
 * @param p1 the persistent value count
 */
void interpret_position_constraint_value(const void* p0, const void* p1) {
}

/**
 * Serializes the position constraint value.
 *
 * @param p0 the persistent value pointer
 * @param p1 the persistent value count
 */
void serialize_position_constraint_value(const void* p0, const void* p1) {
}

//
// Attributes.
//

/**
 * Interprets super attributes.
 *
 * @param p0 the persistent attributes pointer
 * @param p1 the persistent attributes count
 */
void interpret_super_attributes(const void* p0, const void* p1) {

    if (p1 != NULL_POINTER) {

        int* pc = (int*) p1;

        if (p0 != NULL_POINTER) {

            void** p = (void**) p0;

            // The comparison result.
            int r = 0;
            // The current byte within the persistent model.
            void* b = *p;
            // The remaining bytes count.
            int bc = *pc;
            // The parse mode.
            int m = ZERO_PARSE_MODE;
            // The value begin pointer.
            void* v = NULL_POINTER;
            // The value count.
            int vc = 0;
            // The value begin count to be used for calculating the difference.
            int vb = 0;

            while (1) {

                if (bc <= 0) {

                    break;
                }

                //
                // Zero parse mode.
                //

                if (m == ZERO_PARSE_MODE) {

                    if (bc >= NAME_ATTRIBUTE_COUNT) {

                        compare_array_elements((void*) &b, (void*) &NAME_ATTRIBUTE, (void*) &CHARACTER_ARRAY, (void*) &NAME_ATTRIBUTE_COUNT, (void*) &r);

                        if (r == 1) {

                            // Move current byte pointer
                            // and remaining bytes count.
                            b = b + NAME_ATTRIBUTE_COUNT;
                            bc = bc - NAME_ATTRIBUTE_COUNT;

                            // Set value begin pointer and count.
                            v = b;
                            vb = bc;

                            // Set parse mode.
                            m = NAME_ATTRIBUTE_PARSE_MODE;
                        }
                    }
                }

                if (m == ZERO_PARSE_MODE) {

                    if (bc >= ABSTRACTION_ATTRIBUTE_COUNT) {

                        compare_array_elements((void*) &b, (void*) &ABSTRACTION_ATTRIBUTE, (void*) &CHARACTER_ARRAY, (void*) &ABSTRACTION_ATTRIBUTE_COUNT, (void*) &r);

                        if (r == 1) {

                            // Move current byte pointer
                            // and remaining bytes count.
                            b = b + ABSTRACTION_ATTRIBUTE_COUNT;
                            bc = bc - ABSTRACTION_ATTRIBUTE_COUNT;

                            // Set value begin pointer and count.
                            v = b;
                            vb = bc;

                            // Set parse mode.
                            m = ABSTRACTION_ATTRIBUTE_PARSE_MODE;
                        }
                    }
                }

                if (m == ZERO_PARSE_MODE) {

                    if (bc >= LOCATION_ATTRIBUTE_COUNT) {

                        compare_array_elements((void*) &b, (void*) &LOCATION_ATTRIBUTE, (void*) &CHARACTER_ARRAY, (void*) &LOCATION_ATTRIBUTE_COUNT, (void*) &r);

                        if (r == 1) {

                            // Move current byte pointer
                            // and remaining bytes count.
                            b = b + LOCATION_ATTRIBUTE_COUNT;
                            bc = bc - LOCATION_ATTRIBUTE_COUNT;

                            // Set value begin pointer and count.
                            v = b;
                            vb = bc;

                            // Set parse mode.
                            m = LOCATION_ATTRIBUTE_PARSE_MODE;
                        }
                    }
                }

                if (m == ZERO_PARSE_MODE) {

                    if (bc >= MODEL_ATTRIBUTE_COUNT) {

                        compare_array_elements((void*) &b, (void*) &MODEL_ATTRIBUTE, (void*) &CHARACTER_ARRAY, (void*) &MODEL_ATTRIBUTE_COUNT, (void*) &r);

                        if (r == 1) {

                            // Move current byte pointer
                            // and remaining bytes count.
                            b = b + MODEL_ATTRIBUTE_COUNT;
                            bc = bc - MODEL_ATTRIBUTE_COUNT;

                            // Set value begin pointer and count.
                            v = b;
                            vb = bc;

                            // Set parse mode.
                            m = MODEL_ATTRIBUTE_PARSE_MODE;
                        }
                    }
                }

                if (m == ZERO_PARSE_MODE) {

                    if (bc >= CONSTRAINT_ATTRIBUTE_COUNT) {

                        compare_array_elements((void*) &b, (void*) &CONSTRAINT_ATTRIBUTE, (void*) &CHARACTER_ARRAY, (void*) &CONSTRAINT_ATTRIBUTE_COUNT, (void*) &r);

                        if (r == 1) {

                            // Move current byte pointer
                            // and remaining bytes count.
                            b = b + CONSTRAINT_ATTRIBUTE_COUNT;
                            bc = bc - CONSTRAINT_ATTRIBUTE_COUNT;

                            // Set value begin pointer and count.
                            v = b;
                            vb = bc;

                            // Set parse mode.
                            m = CONSTRAINT_ATTRIBUTE_PARSE_MODE;
                        }
                    }
                }

                if (m == ZERO_PARSE_MODE) {

                    if (bc >= POSITION_ABSTRACTION_ATTRIBUTE_COUNT) {

                        compare_array_elements((void*) &b, (void*) &POSITION_ABSTRACTION_ATTRIBUTE, (void*) &CHARACTER_ARRAY, (void*) &POSITION_ABSTRACTION_ATTRIBUTE_COUNT, (void*) &r);

                        if (r == 1) {

                            // Move current byte pointer
                            // and remaining bytes count.
                            b = b + POSITION_ABSTRACTION_ATTRIBUTE_COUNT;
                            bc = bc - POSITION_ABSTRACTION_ATTRIBUTE_COUNT;

                            // Set value begin pointer and count.
                            v = b;
                            vb = bc;

                            // Set parse mode.
                            m = POSITION_ABSTRACTION_ATTRIBUTE_PARSE_MODE;
                        }
                    }
                }

                if (m == ZERO_PARSE_MODE) {

                    if (bc >= POSITION_LOCATION_ATTRIBUTE_COUNT) {

                        compare_array_elements((void*) &b, (void*) &POSITION_LOCATION_ATTRIBUTE, (void*) &CHARACTER_ARRAY, (void*) &POSITION_LOCATION_ATTRIBUTE_COUNT, (void*) &r);

                        if (r == 1) {

                            // Move current byte pointer
                            // and remaining bytes count.
                            b = b + POSITION_LOCATION_ATTRIBUTE_COUNT;
                            bc = bc - POSITION_LOCATION_ATTRIBUTE_COUNT;

                            // Set value begin pointer and count.
                            v = b;
                            vb = bc;

                            // Set parse mode.
                            m = POSITION_LOCATION_ATTRIBUTE_PARSE_MODE;
                        }
                    }
                }

                if (m == ZERO_PARSE_MODE) {

                    if (bc >= POSITION_MODEL_ATTRIBUTE_COUNT) {

                        compare_array_elements((void*) &b, (void*) &POSITION_MODEL_ATTRIBUTE, (void*) &CHARACTER_ARRAY, (void*) &POSITION_MODEL_ATTRIBUTE_COUNT, (void*) &r);

                        if (r == 1) {

                            // Move current byte pointer
                            // and remaining bytes count.
                            b = b + POSITION_MODEL_ATTRIBUTE_COUNT;
                            bc = bc - POSITION_MODEL_ATTRIBUTE_COUNT;

                            // Set value begin pointer and count.
                            v = b;
                            vb = bc;

                            // Set parse mode.
                            m = POSITION_MODEL_ATTRIBUTE_PARSE_MODE;
                        }
                    }
                }

                if (m == ZERO_PARSE_MODE) {

                    if (bc >= POSITION_CONSTRAINT_ATTRIBUTE_COUNT) {

                        compare_array_elements((void*) &b, (void*) &POSITION_CONSTRAINT_ATTRIBUTE, (void*) &CHARACTER_ARRAY, (void*) &POSITION_CONSTRAINT_ATTRIBUTE_COUNT, (void*) &r);

                        if (r == 1) {

                            // Move current byte pointer
                            // and remaining bytes count.
                            b = b + POSITION_CONSTRAINT_ATTRIBUTE_COUNT;
                            bc = bc - POSITION_CONSTRAINT_ATTRIBUTE_COUNT;

                            // Set value begin pointer and count.
                            v = b;
                            vb = bc;

                            // Set parse mode.
                            m = POSITION_CONSTRAINT_ATTRIBUTE_PARSE_MODE;
                        }
                    }
                }

                // If this block is reached, then no known term was found before.
                // The current byte pointer will just be incremented by one so
                // that new characters are read and compared in the next loop cycle.
                if (m == ZERO_PARSE_MODE) {

                    // Increment current byte within persistent model.
                    b++;
                    // Decrement remaining bytes count.
                    bc--;
                }

                //
                // Special parse modes.
                //
                // These conditions are linked with else-if because if one term
                // matches, the parse mode is switched back to ZERO_PARSE_MODE
                // and no further terms have to be compared here.
                //

                // Reset comparison result.
                // CAUTION! Do NOT delete this! One of the comparisons above
                // may have set the result to 1 so that it has to be reset here.
                r = 0;

                if (m == NAME_ATTRIBUTE_PARSE_MODE) {

                    if (bc >= ATTRIBUTE_END_COUNT) {

                        compare_array_elements((void*) &b, (void*) &ATTRIBUTE_END, (void*) &CHARACTER_ARRAY, (void*) &ATTRIBUTE_END_COUNT, (void*) &r);

                        if (r == 1) {

                            // Determine the value length as difference
                            // of the formerly stored value begin count
                            // and the current count.
                            vc = vb - bc;

                            // Interpret values.
                            // Hand over the formerly stored value begin pointer
                            // and its count.
                            interpret_name_value((void*) &v, (void*) &vc);

                            // Move current byte pointer
                            // and remaining bytes count.
                            b = b + ATTRIBUTE_END_COUNT;
                            bc = bc - ATTRIBUTE_END_COUNT;

                            // Reset values.
                            v = NULL_POINTER;
                            vc = 0;
                            vb = 0;

                            // Reset parse mode.
                            m = ZERO_PARSE_MODE;
                        }
                    }

                } else if (m == ABSTRACTION_ATTRIBUTE_PARSE_MODE) {

                    if (bc >= ATTRIBUTE_END_COUNT) {

                        compare_array_elements((void*) &b, (void*) &ATTRIBUTE_END, (void*) &CHARACTER_ARRAY, (void*) &ATTRIBUTE_END_COUNT, (void*) &r);

                        if (r == 1) {

                            // Determine the value length as difference
                            // of the formerly stored value begin count
                            // and the current count.
                            vc = vb - bc;

                            // Interpret values.
                            // Hand over the formerly stored value begin pointer
                            // and its count.
                            interpret_abstraction_value((void*) &v, (void*) &vc);

                            // Move current byte pointer
                            // and remaining bytes count.
                            b = b + ATTRIBUTE_END_COUNT;
                            bc = bc - ATTRIBUTE_END_COUNT;

                            // Reset values.
                            v = NULL_POINTER;
                            vc = 0;
                            vb = 0;

                            // Reset parse mode.
                            m = ZERO_PARSE_MODE;
                        }
                    }

                } else if (m == LOCATION_ATTRIBUTE_PARSE_MODE) {

                    if (bc >= ATTRIBUTE_END_COUNT) {

                        compare_array_elements((void*) &b, (void*) &ATTRIBUTE_END, (void*) &CHARACTER_ARRAY, (void*) &ATTRIBUTE_END_COUNT, (void*) &r);

                        if (r == 1) {

                            // Determine the value length as difference
                            // of the formerly stored value begin count
                            // and the current count.
                            vc = vb - bc;

                            // Interpret values.
                            // Hand over the formerly stored value begin pointer
                            // and its count.
                            interpret_location_value((void*) &v, (void*) &vc);

                            // Move current byte pointer
                            // and remaining bytes count.
                            b = b + ATTRIBUTE_END_COUNT;
                            bc = bc - ATTRIBUTE_END_COUNT;

                            // Reset values.
                            v = NULL_POINTER;
                            vc = 0;
                            vb = 0;

                            // Reset parse mode.
                            m = ZERO_PARSE_MODE;
                        }
                    }

                } else if (m == MODEL_ATTRIBUTE_PARSE_MODE) {

                    if (bc >= ATTRIBUTE_END_COUNT) {

                        compare_array_elements((void*) &b, (void*) &ATTRIBUTE_END, (void*) &CHARACTER_ARRAY, (void*) &ATTRIBUTE_END_COUNT, (void*) &r);

                        if (r == 1) {

                            // Determine the value length as difference
                            // of the formerly stored value begin count
                            // and the current count.
                            vc = vb - bc;

                            // Interpret values.
                            // Hand over the formerly stored value begin pointer
                            // and its count.
                            interpret_model_value((void*) &v, (void*) &vc);

                            // Move current byte pointer
                            // and remaining bytes count.
                            b = b + ATTRIBUTE_END_COUNT;
                            bc = bc - ATTRIBUTE_END_COUNT;

                            // Reset values.
                            v = NULL_POINTER;
                            vc = 0;
                            vb = 0;

                            // Reset parse mode.
                            m = ZERO_PARSE_MODE;
                        }
                    }

                } else if (m == CONSTRAINT_ATTRIBUTE_PARSE_MODE) {

                    if (bc >= ATTRIBUTE_END_COUNT) {

                        compare_array_elements((void*) &b, (void*) &ATTRIBUTE_END, (void*) &CHARACTER_ARRAY, (void*) &ATTRIBUTE_END_COUNT, (void*) &r);

                        if (r == 1) {

                            // Determine the value length as difference
                            // of the formerly stored value begin count
                            // and the current count.
                            vc = vb - bc;

                            // Interpret values.
                            // Hand over the formerly stored value begin pointer
                            // and its count.
                            interpret_constraint_value((void*) &v, (void*) &vc);

                            // Move current byte pointer
                            // and remaining bytes count.
                            b = b + ATTRIBUTE_END_COUNT;
                            bc = bc - ATTRIBUTE_END_COUNT;

                            // Reset values.
                            v = NULL_POINTER;
                            vc = 0;
                            vb = 0;

                            // Reset parse mode.
                            m = ZERO_PARSE_MODE;
                        }
                    }

                } else if (m == POSITION_ABSTRACTION_ATTRIBUTE_PARSE_MODE) {

                    if (bc >= ATTRIBUTE_END_COUNT) {

                        compare_array_elements((void*) &b, (void*) &ATTRIBUTE_END, (void*) &CHARACTER_ARRAY, (void*) &ATTRIBUTE_END_COUNT, (void*) &r);

                        if (r == 1) {

                            // Determine the value length as difference
                            // of the formerly stored value begin count
                            // and the current count.
                            vc = vb - bc;

                            // Interpret values.
                            // Hand over the formerly stored value begin pointer
                            // and its count.
                            interpret_position_abstraction_value((void*) &v, (void*) &vc);

                            // Move current byte pointer
                            // and remaining bytes count.
                            b = b + ATTRIBUTE_END_COUNT;
                            bc = bc - ATTRIBUTE_END_COUNT;

                            // Reset values.
                            v = NULL_POINTER;
                            vc = 0;
                            vb = 0;

                            // Reset parse mode.
                            m = ZERO_PARSE_MODE;
                        }
                    }

                } else if (m == POSITION_LOCATION_ATTRIBUTE_PARSE_MODE) {

                    if (bc >= ATTRIBUTE_END_COUNT) {

                        compare_array_elements((void*) &b, (void*) &ATTRIBUTE_END, (void*) &CHARACTER_ARRAY, (void*) &ATTRIBUTE_END_COUNT, (void*) &r);

                        if (r == 1) {

                            // Determine the value length as difference
                            // of the formerly stored value begin count
                            // and the current count.
                            vc = vb - bc;

                            // Interpret values.
                            // Hand over the formerly stored value begin pointer
                            // and its count.
                            interpret_position_location_value((void*) &v, (void*) &vc);

                            // Move current byte pointer
                            // and remaining bytes count.
                            b = b + ATTRIBUTE_END_COUNT;
                            bc = bc - ATTRIBUTE_END_COUNT;

                            // Reset values.
                            v = NULL_POINTER;
                            vc = 0;
                            vb = 0;

                            // Reset parse mode.
                            m = ZERO_PARSE_MODE;
                        }
                    }

                } else if (m == POSITION_MODEL_ATTRIBUTE_PARSE_MODE) {

                    if (bc >= ATTRIBUTE_END_COUNT) {

                        compare_array_elements((void*) &b, (void*) &ATTRIBUTE_END, (void*) &CHARACTER_ARRAY, (void*) &ATTRIBUTE_END_COUNT, (void*) &r);

                        if (r == 1) {

                            // Determine the value length as difference
                            // of the formerly stored value begin count
                            // and the current count.
                            vc = vb - bc;

                            // Interpret values.
                            // Hand over the formerly stored value begin pointer
                            // and its count.
                            interpret_position_model_value((void*) &v, (void*) &vc);

                            // Move current byte pointer
                            // and remaining bytes count.
                            b = b + ATTRIBUTE_END_COUNT;
                            bc = bc - ATTRIBUTE_END_COUNT;

                            // Reset values.
                            v = NULL_POINTER;
                            vc = 0;
                            vb = 0;

                            // Reset parse mode.
                            m = ZERO_PARSE_MODE;
                        }
                    }

                } else if (m == POSITION_CONSTRAINT_ATTRIBUTE_PARSE_MODE) {

                    if (bc >= ATTRIBUTE_END_COUNT) {

                        compare_array_elements((void*) &b, (void*) &ATTRIBUTE_END, (void*) &CHARACTER_ARRAY, (void*) &ATTRIBUTE_END_COUNT, (void*) &r);

                        if (r == 1) {

                            // Determine the value length as difference
                            // of the formerly stored value begin count
                            // and the current count.
                            vc = vb - bc;

                            // Interpret values.
                            // Hand over the formerly stored value begin pointer
                            // and its count.
                            interpret_position_constraint_value((void*) &v, (void*) &vc);

                            // Move current byte pointer
                            // and remaining bytes count.
                            b = b + ATTRIBUTE_END_COUNT;
                            bc = bc - ATTRIBUTE_END_COUNT;

                            // Reset values.
                            v = NULL_POINTER;
                            vc = 0;
                            vb = 0;

                            // Reset parse mode.
                            m = ZERO_PARSE_MODE;
                        }
                    }
                }

                // Reset comparison result.
                r = 0;
            }

        } else {

//??            log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not interpret super attributes. The persistent attributes is null.");
        }

    } else {

//??        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not interpret super attributes. The persistent attributes count is null.");
    }
}

/**
 * Serializes super attributes.
 *
 * @param p0 the persistent attributes pointer
 * @param p1 the persistent attributes count
 */
void serialize_super_attributes(const void* p0, const void* p1) {
}

/**
 * Interprets part attributes.
 *
 * @param p0 the persistent attributes pointer
 * @param p1 the persistent attributes count
 */
void interpret_part_attributes(const void* p0, const void* p1) {
}

/**
 * Serializes part attributes.
 *
 * @param p0 the persistent attributes pointer
 * @param p1 the persistent attributes count
 */
void serialize_part_attributes(const void* p0, const void* p1) {
}

//
// Model.
//

/**
 * Initializes the compound.
 *
 * @param p0 the transient model
 * @param p1 the transient model count
 * @param p2 the transient model size
 * @param p3 the persistent model
 * @param p4 the persistent model count
 */
void initialize_compound(void* p0, void* p1, void* p2, const void* p3, const void* p4) {

    if (p4 != NULL_POINTER) {

        int* pc = (int*) p4;

        if (p3 != NULL_POINTER) {

            void** p = (void**) p3;

            // The comparison result.
            int r = 0;
            // The current byte within the persistent model.
            void* b = *p;
            // The remaining bytes count.
            int bc = *pc;
            // The parse mode.
            int m = ZERO_PARSE_MODE;
            // The attribute begin pointer.
            void* a = NULL_POINTER;
            // The attribute count.
            int ac = 0;
            // The attribute begin count to be used for calculating the difference.
            int ab = 0;

            //
            // ATTENTION!
            // The <model> tag is NOT considered. It has no meaning (semantics)
            // for CYBOI and was only included in CYBOL models for that these
            // can be viewed and edited using standard XML tools.
            //

            while (1) {

                if (bc <= 0) {

                    break;
                }

                //
                // Zero parse mode.
                //

                if (m == ZERO_PARSE_MODE) {

                    if (bc >= COMMENT_TAG_COUNT) {

                        compare_array_elements((void*) &b, (void*) &COMMENT_TAG, (void*) &CHARACTER_ARRAY, (void*) &COMMENT_TAG_COUNT, (void*) &r);

                        if (r == 1) {

                            // Move current byte pointer
                            // and remaining bytes count.
                            b = b + COMMENT_TAG_COUNT;
                            bc = bc - COMMENT_TAG_COUNT;

                            // Set parse mode.
                            m = COMMENT_TAG_PARSE_MODE;
                        }
                    }
                }

                if (m == ZERO_PARSE_MODE) {

                    if (bc >= SUPER_TAG_COUNT) {

                        compare_array_elements((void*) &b, (void*) &SUPER_TAG, (void*) &CHARACTER_ARRAY, (void*) &SUPER_TAG_COUNT, (void*) &r);

                        if (r == 1) {

                            // Move current byte pointer
                            // and remaining bytes count.
                            b = b + SUPER_TAG_COUNT;
                            bc = bc - SUPER_TAG_COUNT;

                            // Set attribute begin pointer and count.
                            a = b;
                            ab = bc;

                            // Set parse mode.
                            m = SUPER_TAG_PARSE_MODE;
                        }
                    }
                }

                if (m == ZERO_PARSE_MODE) {

                    if (bc >= PART_TAG_COUNT) {

                        compare_array_elements((void*) &b, (void*) &PART_TAG, (void*) &CHARACTER_ARRAY, (void*) &PART_TAG_COUNT, (void*) &r);

                        if (r == 1) {

                            // Move current byte pointer
                            // and remaining bytes count.
                            b = b + PART_TAG_COUNT;
                            bc = bc - PART_TAG_COUNT;

                            // Set attribute values.
                            a = b;
                            ab = bc;

                            // Set parse mode.
                            m = PART_TAG_PARSE_MODE;
                        }
                    }
                }

                // If this block is reached, then no known term was found before.
                // The current byte pointer will just be incremented by one so
                // that new characters are read and compared in the next loop cycle.
                if (m == ZERO_PARSE_MODE) {

                    // Increment current byte within persistent model.
                    b++;
                    // Decrement remaining bytes count.
                    bc--;
                }

                //
                // Special parse modes.
                //
                // These conditions are linked with else-if because if one term
                // matches, the parse mode is switched back to ZERO_PARSE_MODE
                // and no further terms have to be compared here.
                //

                // Reset comparison result.
                // CAUTION! Do NOT delete this! One of the comparisons above
                // may have set the result to 1 so that it has to be reset here.
                r = 0;

                if (m == COMMENT_TAG_PARSE_MODE) {

                    if (bc >= COMMENT_END_COUNT) {

                        compare_array_elements((void*) &b, (void*) &COMMENT_END, (void*) &CHARACTER_ARRAY, (void*) &COMMENT_END_COUNT, (void*) &r);

                        if (r == 1) {

                            // Move current byte pointer
                            // and remaining bytes count.
                            b = b + COMMENT_END_COUNT;
                            bc = bc - COMMENT_END_COUNT;

                            // Reset parse mode.
                            m = ZERO_PARSE_MODE;
                        }
                    }

                } else if (m == SUPER_TAG_PARSE_MODE) {

                    if (bc >= TAG_END_COUNT) {

                        compare_array_elements((void*) &b, (void*) &TAG_END, (void*) &CHARACTER_ARRAY, (void*) &TAG_END_COUNT, (void*) &r);

                        if (r == 1) {

                            // Determine the attributes length as difference
                            // of the formerly stored attribute begin count
                            // and the current count.
                            ac = ab - bc;

                            // Interpret attributes.
                            // Hand over the formerly stored attribute begin pointer
                            // and its count.
                            interpret_super_attributes((void*) &a, (void*) &ac);

                            // Move current byte pointer
                            // and remaining bytes count.
                            b = b + TAG_END_COUNT;
                            bc = bc - TAG_END_COUNT;

                            // Reset values.
                            a = NULL_POINTER;
                            ac = 0;
                            ab = 0;

                            // Reset parse mode.
                            m = ZERO_PARSE_MODE;
                        }
                    }

                } else if (m == PART_TAG_PARSE_MODE) {

                    if (bc >= TAG_END_COUNT) {

                        compare_array_elements((void*) &b, (void*) &TAG_END, (void*) &CHARACTER_ARRAY, (void*) &TAG_END_COUNT, (void*) &r);

                        if (r == 1) {

                            // Determine the attributes length as difference
                            // of the formerly stored attribute begin count
                            // and the current count.
                            ac = ab - bc;

                            // Interpret attributes.
                            // Hand over the formerly stored attribute begin pointer
                            // and its count.
                            interpret_part_attributes((void*) &a, (void*) &ac);

                            // Move current byte pointer
                            // and remaining bytes count.
                            b = b + TAG_END_COUNT;
                            bc = bc - TAG_END_COUNT;

                            // Reset values.
                            a = NULL_POINTER;
                            ac = 0;
                            ab = 0;

                            // Reset parse mode.
                            m = ZERO_PARSE_MODE;
                        }
                    }
                }

                // Reset comparison result.
                r = 0;
            }

        } else {

//??            log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not initialize compound. The persistent model is null.");
        }

    } else {

//??        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not initialize compound. The persistent model count is null.");
    }
}

/**
 * Finalizes the compound.
 *
 * @param p0 the transient model
 * @param p1 the transient model count
 * @param p2 the transient model size
 * @param p3 the persistent model
 * @param p4 the persistent model count
 */
void finalize_compound(const void* p0, const void* p1, const void* p2, void* p3, void* p4) {
}

//
// Compound part.
//

/**
 * Gets the compound part index.
 *
 * @param p0 the compound
 * @param p1 the compound count
 * @param p2 the part name
 * @param p3 the part name count
 * @param p4 the index
 */
void get_compound_part_index(const void* p0, const void* p1, const void* p2, const void* p3, void* p4) {

    if (p4 != NULL_POINTER) {

        int* i = (int*) p4;

        if (p3 != NULL_POINTER) {

            int* nc0 = (int*) p3;

            if (p1 != NULL_POINTER) {

                int* cc = (int*) p1;

//??            log_message((void*) &INFO_LOG_LEVEL, (void*) &GET_COMPOUND_PART_INDEX_MESSAGE, (void*) &GET_COMPOUND_PART_INDEX_MESSAGE_COUNT);

                // Initialize part names and their counts.
                void* n = NULL_POINTER;
                void* nc = NULL_POINTER;

                // Get part names and their counts.
                get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_NAMES_INDEX, (void*) &n);
                get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_NAMES_COUNTS_INDEX, (void*) &nc);

                // The loop variable.
                int j = 0;
                // The name.
                void* n1 = NULL_POINTER;
                // The name count.
                int nc1 = 0;
                // The comparison result.
                int r = 0;

                while (1) {

                    if (j >= *cc) {

                        break;
                    }

                    // Get part name and its count.
                    get_array_element((void*) &n, (void*) &POINTER_ARRAY, (void*) &j, (void*) &n1);
                    get_array_element((void*) &nc, (void*) &POINTER_ARRAY, (void*) &j, (void*) &nc1);

                    if (*nc0 == nc1) {

                        compare_array_elements(p2, (void*) &n1, (void*) &CHARACTER_ARRAY, (void*) &nc1, (void*) &r);

                        if (r == 1) {

                            *i = j;

                            break;
                        }
                    }

                    // Reset name length.
                    nc1 = 0;

                    j++;
                }

            } else {

//??                log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_GET_COMPOUND_PART_INDEX_THE_COMPOUND_COUNT_IS_NULL_MESSAGE, (void*) &COULD_NOT_GET_COMPOUND_PART_INDEX_THE_COMPOUND_COUNT_IS_NULL_MESSAGE_COUNT);
            }

        } else {

//??            log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_GET_COMPOUND_PART_INDEX_THE_NAME_COUNT_IS_NULL_MESSAGE, (void*) &COULD_NOT_GET_COMPOUND_PART_INDEX_THE_NAME_COUNT_IS_NULL_MESSAGE_COUNT);
        }

    } else {

//??        log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_GET_COMPOUND_PART_INDEX_THE_NAME_COUNT_IS_NULL_MESSAGE, (void*) &COULD_NOT_GET_COMPOUND_PART_INDEX_THE_NAME_COUNT_IS_NULL_MESSAGE_COUNT);
    }
}

/**
 * Returns the next index that can be used to set a map element.
 *
 * If an element with the given name is found, then its index will be returned
 * so that the element can be replaced.
 * If a 0 element is reached, then the corresponding index marks the next
 * available place and will be returned.
 * If neither an element matches nor a 0 element is reached, then the
 * map is full and its size will be returned as next available index.
 *
 * @param p0 the names array
 * @param p1 the name
 * @return the next index
 */
/*??
int get_next_map_element_index(const void* p0, const void* p1) {

    int index = INVALID_INDEX;
    int i = 0;
    int count = 0;
    get_array_count(p0, (void*) &count);
    void* name = NULL_POINTER;

    while (i < count) {

        name = get_array_element(p0, (void*) &PART_NAMES_COUNTS_ARRAY_INDEX);

        // If a name equal to the searched one is found,
        // then its index is the one to be returned
        // since this element will have to be replaced.
        if (strcmp((char*) name, (char*) p1) == 0) {

            index = i;

            break;
        }

        i++;
    }

    // Neither element matched. The next index will be the current element count.
    if (index == INVALID_INDEX) {

        index = count;
    }

    return index;
}

/**
 * Returns the number of map elements whose name starts with the given base name.
 *
 * @param p0 the names array
 * @param p1 the base name
 * @return the number of map elements whose name starts with the given base name
 */
/*??
int get_map_element_count(const void* p0, const void* p1) {

    int name_count = 0;
    int i = 0;
    int count = 0;
    get_array_count(p0, (void*) &count);
    void* name = NULL_POINTER;

    while (i < count) {

        name = get_array_element(p0, (void*) &PART_NAMES_COUNTS_ARRAY_INDEX);

        if (name != NULL_POINTER) {

            // Compares the current element's name with the searched base name.
            if (strncmp((char*) name, (char*) p1, strlen((char*) p1)) == 0) {

                char* suffix = strchr((char*) name, SEPARATION);
                char* check = strchr(suffix + 1, SEPARATION);

                // If no second separation is found, the name really matches.
                if (check == NULL_POINTER) {

                    int number = atoi(suffix + 1);

                    if (number > name_count) {

                        name_count = number;
                    }
                }
            }

        } else {

            // Reached last valid name. Only null entries left.
            break;
        }

        i++;
    }

    return name_count;
}

/** The separation. The ASCII code for "_" is 95. */
//??static const int SEPARATION = 95;

/**
 * Builds the next map element name.
 *
 * The given name is used as a word base for the new extended name.
 * Additionally, the new name will receive a number suffix.
 * It is determined by the current number of names containing the given
 * word base and finally increasing the highest index by one.
 *
 * @param p0 the names array
 * @param p1 the base name
 * @param p2 the extended name
 */
/*??
void build_next_map_element_name(const void* p0, const void* p1, void* p2) {

    int count = get_map_element_count(p0, p1);

    //?? It is unclear how to convert the integer into a string!
    //?? A simple cast does not work as it is only for ASCII code
    //?? but here a normal integer number is to be converted into a string.
    char suffix = (char) count;
    p2 = (void*) strcat((char*) p2, (char*) p1);
//??    char separation = (char) SEPARATION;
//?? Use SEPARATION instead of "_"!
    p2 = (void*) strcat((char*) p2, "_");
//??    p2 = (void*) strcat((char*) p2, &suffix);
    //?? Temporary solution adds "0" instead of real suffix.
    p2 = (void*) strcat((char*) p2, "0");
}

/**
 * Sets the compound part by index.
 *
 * @param p0 the compound
 * @param p1 the compound count
 * @param p2 the compound size
 * @param p3 the index
 * @param p4 the part name
 * @param p5 the part name count
 * @param p6 the part name size
 * @param p7 the part model
 * @param p8 the part model count
 * @param p9 the part model size
 * @param p10 the part abstraction
 * @param p11 the part abstraction count
 * @param p12 the part abstraction size
 * @param p13 the part constraint
 * @param p14 the part constraint count
 * @param p15 the part constraint size
 * @param p16 the position model
 * @param p17 the position model count
 * @param p18 the position model size
 * @param p19 the position abstraction
 * @param p20 the position abstraction count
 * @param p21 the position abstraction size
 * @param p22 the position constraint
 * @param p23 the position constraint count
 * @param p24 the position constraint size
 */
void set_compound_part_by_index(void* p0, void* p1, void* p2,
    const void* p3,
    const void* p4, const void* p5, const void* p6,
    const void* p7, const void* p8, const void* p9,
    const void* p10, const void* p11, const void* p12,
    const void* p13, const void* p14, const void* p15,
    const void* p16, const void* p17, const void* p18,
    const void* p19, const void* p20, const void* p21,
    const void* p22, const void* p23, const void* p24) {

    if (p3 != NULL_POINTER) {

        int* i = (int*) p3;

        if (p2 != NULL_POINTER) {

            int* s = (int*) p2;

            if (p1 != NULL_POINTER) {

                int* c = (int*) p1;

                if (*i >= 0) {

//??                    log_message((void*) &INFO_LOG_LEVEL, (void*) &"Set compound part by index.");

                    // Initialize part names, models, abstractions, constraints
                    // and position models, abstractions, constraints
                    // and their counts and sizes.
                    void* pn = NULL_POINTER;
                    void* pnc = NULL_POINTER;
                    void* pns = NULL_POINTER;
                    void* pm = NULL_POINTER;
                    void* pmc = NULL_POINTER;
                    void* pms = NULL_POINTER;
                    void* pa = NULL_POINTER;
                    void* pac = NULL_POINTER;
                    void* pas = NULL_POINTER;
                    void* pc = NULL_POINTER;
                    void* pcc = NULL_POINTER;
                    void* pcs = NULL_POINTER;
                    void* pom = NULL_POINTER;
                    void* pomc = NULL_POINTER;
                    void* poms = NULL_POINTER;
                    void* poa = NULL_POINTER;
                    void* poac = NULL_POINTER;
                    void* poas = NULL_POINTER;
                    void* poc = NULL_POINTER;
                    void* pocc = NULL_POINTER;
                    void* pocs = NULL_POINTER;

                    // Get part names, models, abstractions, constraints
                    // and position models, abstractions, constraints
                    // and their counts and sizes.
                    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_NAMES_INDEX, (void*) &pn);
                    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_NAMES_COUNTS_INDEX, (void*) &pnc);
                    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_NAMES_SIZES_INDEX, (void*) &pns);
                    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_MODELS_INDEX, (void*) &pm);
                    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_MODELS_COUNTS_INDEX, (void*) &pmc);
                    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_MODELS_SIZES_INDEX, (void*) &pms);
                    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_ABSTRACTIONS_INDEX, (void*) &pa);
                    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_ABSTRACTIONS_COUNTS_INDEX, (void*) &pac);
                    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_ABSTRACTIONS_SIZES_INDEX, (void*) &pas);
                    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_CONSTRAINTS_INDEX, (void*) &pc);
                    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_CONSTRAINTS_COUNTS_INDEX, (void*) &pcc);
                    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_CONSTRAINTS_SIZES_INDEX, (void*) &pcs);
                    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_MODELS_INDEX, (void*) &pom);
                    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_MODELS_COUNTS_INDEX, (void*) &pomc);
                    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_MODELS_SIZES_INDEX, (void*) &poms);
                    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_ABSTRACTIONS_INDEX, (void*) &poa);
                    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_ABSTRACTIONS_COUNTS_INDEX, (void*) &poac);
                    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_ABSTRACTIONS_SIZES_INDEX, (void*) &poas);
                    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_CONSTRAINTS_INDEX, (void*) &poc);
                    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_CONSTRAINTS_COUNTS_INDEX, (void*) &pocc);
                    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_CONSTRAINTS_SIZES_INDEX, (void*) &pocs);

                    if (*i == *s) {

                        // Increase size.
                        *s = (*s * COMPOUND_RESIZE_FACTOR) + 1;

                        // Resize part names, models, abstractions, constraints
                        // and position models, abstractions, constraints
                        // and their counts and sizes.
                        resize_array((void*) &pn, (void*) &POINTER_ARRAY, p2);
                        resize_array((void*) &pnc, (void*) &INTEGER_ARRAY, p2);
                        resize_array((void*) &pns, (void*) &INTEGER_ARRAY, p2);
                        resize_array((void*) &pm, (void*) &POINTER_ARRAY, p2);
                        resize_array((void*) &pmc, (void*) &INTEGER_ARRAY, p2);
                        resize_array((void*) &pms, (void*) &INTEGER_ARRAY, p2);
                        resize_array((void*) &pa, (void*) &POINTER_ARRAY, p2);
                        resize_array((void*) &pac, (void*) &INTEGER_ARRAY, p2);
                        resize_array((void*) &pas, (void*) &INTEGER_ARRAY, p2);
                        resize_array((void*) &pc, (void*) &POINTER_ARRAY, p2);
                        resize_array((void*) &pcc, (void*) &INTEGER_ARRAY, p2);
                        resize_array((void*) &pcs, (void*) &INTEGER_ARRAY, p2);
                        resize_array((void*) &pom, (void*) &POINTER_ARRAY, p2);
                        resize_array((void*) &pomc, (void*) &INTEGER_ARRAY, p2);
                        resize_array((void*) &poms, (void*) &INTEGER_ARRAY, p2);
                        resize_array((void*) &poa, (void*) &POINTER_ARRAY, p2);
                        resize_array((void*) &poac, (void*) &INTEGER_ARRAY, p2);
                        resize_array((void*) &poas, (void*) &INTEGER_ARRAY, p2);
                        resize_array((void*) &poc, (void*) &POINTER_ARRAY, p2);
                        resize_array((void*) &pocc, (void*) &INTEGER_ARRAY, p2);
                        resize_array((void*) &pocs, (void*) &INTEGER_ARRAY, p2);
                    }

                    if (*i < *s) {

                        // Set part name, model, abstraction, constraint
                        // and position model, abstraction, constraint
                        // and their count and size.
                        // CAUTION! Only those parameters are set, which are not null.

                        if (p4 != NULL_POINTER) {

                            set_array_element((void*) &pn, (void*) &POINTER_ARRAY, p3, p4);
                        }

                        if (p5 != NULL_POINTER) {

                            set_array_element((void*) &pnc, (void*) &INTEGER_ARRAY, p3, p5);
                        }

                        if (p6 != NULL_POINTER) {

                            set_array_element((void*) &pns, (void*) &INTEGER_ARRAY, p3, p6);
                        }

                        if (p7 != NULL_POINTER) {

                            set_array_element((void*) &pm, (void*) &POINTER_ARRAY, p3, p7);
                        }

                        if (p8 != NULL_POINTER) {

                            set_array_element((void*) &pmc, (void*) &INTEGER_ARRAY, p3, p8);
                        }

                        if (p9 != NULL_POINTER) {

                            set_array_element((void*) &pms, (void*) &INTEGER_ARRAY, p3, p9);
                        }

                        if (p10 != NULL_POINTER) {

                            set_array_element((void*) &pa, (void*) &POINTER_ARRAY, p3, p10);
                        }

                        if (p11 != NULL_POINTER) {

                            set_array_element((void*) &pac, (void*) &INTEGER_ARRAY, p3, p11);
                        }

                        if (p12 != NULL_POINTER) {

                            set_array_element((void*) &pas, (void*) &INTEGER_ARRAY, p3, p12);
                        }

                        if (p13 != NULL_POINTER) {

                            set_array_element((void*) &pc, (void*) &POINTER_ARRAY, p3, p13);
                        }

                        if (p14 != NULL_POINTER) {

                            set_array_element((void*) &pcc, (void*) &INTEGER_ARRAY, p3, p14);
                        }

                        if (p15 != NULL_POINTER) {

                            set_array_element((void*) &pcs, (void*) &INTEGER_ARRAY, p3, p15);
                        }

                        if (p16 != NULL_POINTER) {

                            set_array_element((void*) &pom, (void*) &POINTER_ARRAY, p3, p16);
                        }

                        if (p17 != NULL_POINTER) {

                            set_array_element((void*) &pomc, (void*) &INTEGER_ARRAY, p3, p17);
                        }

                        if (p18 != NULL_POINTER) {

                            set_array_element((void*) &poms, (void*) &INTEGER_ARRAY, p3, p18);
                        }

                        if (p19 != NULL_POINTER) {

                            set_array_element((void*) &poa, (void*) &POINTER_ARRAY, p3, p19);
                        }

                        if (p20 != NULL_POINTER) {

                            set_array_element((void*) &poac, (void*) &INTEGER_ARRAY, p3, p20);
                        }

                        if (p21 != NULL_POINTER) {

                            set_array_element((void*) &poas, (void*) &INTEGER_ARRAY, p3, p21);
                        }

                        if (p22 != NULL_POINTER) {

                            set_array_element((void*) &poc, (void*) &POINTER_ARRAY, p3, p22);
                        }

                        if (p23 != NULL_POINTER) {

                            set_array_element((void*) &pocc, (void*) &INTEGER_ARRAY, p3, p23);
                        }

                        if (p24 != NULL_POINTER) {

                            set_array_element((void*) &pocs, (void*) &INTEGER_ARRAY, p3, p24);
                        }

                        // Increment count.
                        (*c)++;

                    } else {

//??                        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not set compound part by index. The index exceeds the size.");
                    }

                } else {

//??                    log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not set compound part by index. The index is negativ.");
                }

            } else {

//??                log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not set compound part by index. The count is null.");
            }

        } else {

//??            log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not set compound part by index. The size is null.");
        }

    } else {

//??        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not set compound part by index. The index is null.");
    }
}

/**
 * Sets the compound part by name.
 *
 * @param p0 the compound
 * @param p1 the compound count
 * @param p2 the compound size
 * @param p3 the part name
 * @param p4 the part name count
 * @param p5 the part name size
 * @param p6 the part model
 * @param p7 the part model count
 * @param p8 the part model size
 * @param p9 the part abstraction
 * @param p10 the part abstraction count
 * @param p11 the part abstraction size
 * @param p12 the part constraint
 * @param p13 the part constraint count
 * @param p14 the part constraint size
 * @param p15 the position model
 * @param p16 the position model count
 * @param p17 the position model size
 * @param p18 the position abstraction
 * @param p19 the position abstraction count
 * @param p20 the position abstraction size
 * @param p21 the position constraint
 * @param p22 the position constraint count
 * @param p23 the position constraint size
 */
void set_compound_part_by_name(void* p0, void* p1, void* p2,
    const void* p3, const void* p4, const void* p5,
    const void* p6, const void* p7, const void* p8,
    const void* p9, const void* p10, const void* p11,
    const void* p12, const void* p13, const void* p14,
    const void* p15, const void* p16, const void* p17,
    const void* p18, const void* p19, const void* p20,
    const void* p21, const void* p22, const void* p23) {

    // The separator index.
    int i = -1;

    get_array_element_index(p3, (void*) &CHARACTER_ARRAY, p4, (void*) &COMPOUND_PART_SEPARATOR, (void*) &i);

    if (i != -1) {

        // The separator has been found.
        // The full name is hierarchical.
        // The given compound contains parts which are compound models.

        if (p4 != NULL_POINTER) {

            int* nc = (int*) p4;

            if (p3 != NULL_POINTER) {

                void** n = (void**) p3;

                if (i >= 0) {

                    if (i < *nc) {

                        if (i != 0) {

                            if (i != (*nc - 1)) {

                                // The remaining name starts at the index after the separator.
                                // Example: "hello.test"
                                // The index of the separator is 5.
                                // The starting index of the remaining name "test" is 6 = 5 + 1.
                                void* r = (void*) (*n + i + 1);

                                // The remaining name count is the full name count decreased
                                // by the separator index increased by one.
                                // Example: "hello.test"
                                // The full name count is 10.
                                // The separator index is 5.
                                // The count of the remaining name "test" is 4 = 10 - (5 + 1).
                                int rc = *nc - (i + 1);

                                // Initialize part models and their counts and sizes.
                                void* m = NULL_POINTER;
                                int mc = 0;
                                int ms = 0;

                                // Get part models and their counts and sizes.
                                get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_MODELS_INDEX, (void*) &m);
                                get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_MODELS_COUNTS_INDEX, (void*) &mc);
                                get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_MODELS_SIZES_INDEX, (void*) &ms);

                                // Get index of part name.
                                // The separator index i is used as part name count.
                                // Example: "hello.test"
                                // The index i of the separator is 5.
                                // The count of the part name "hello" before the separator is likewise 5.
                                int index = -1;
                                get_compound_part_index(p0, p1, p3, (void*) &i, (void*) &index);

                                if (index != -1) {

                                    // Initialize part model and its count and size.
                                    void* pm = NULL_POINTER;
                                    int pmc = 0;
                                    int pms = 0;

                                    // Get part model and its count and size.
                                    get_array_element((void*) &m, (void*) &POINTER_ARRAY, (void*) &index, (void*) &pm);
                                    get_array_element((void*) &mc, (void*) &INTEGER_ARRAY, (void*) &index, (void*) &pmc);
                                    get_array_element((void*) &ms, (void*) &INTEGER_ARRAY, (void*) &index, (void*) &pms);

                                    //?? TODO:
                                    //?? For now, the remaining name count is also used as
                                    //?? remaining name size and such handed over twice.
                                    //?? Later implementations may use UNICODE names so that
                                    //?? the name count and size differ.

                                    // Recursively continue to process along the hierarchical name.
                                    set_compound_part_by_name((void*) &pm, (void*) &pmc, (void*) &pms,
                                        (void*) &r, (void*) &rc, (void*) &rc,
                                        p6, p7, p8, p9, p10, p11, p12, p13, p14,
                                        p15, p16, p17, p18, p19, p20, p21, p22, p23);

                                } else {

//??                                    log_message((void*) &WARNING_LOG_LEVEL, (void*) &"Could not set compound part by name. A part with that name does not exist.");
                                }

                            } else {

//??                                log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not set compound part by name. The full name ends with a separator.");
                            }

                        } else {

//??                            log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not set compound part by name. The full name starts with a separator.");
                        }

                    } else {

//??                        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not set compound part by name. The separator index exceeds the full name count.");
                    }

                } else {

//??                    log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not set compound part by name. The separator index is negative.");
                }

            } else {

//??                log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not set compound part by name. The name is null.");
            }

        } else {

//??            log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not set compound part by name. The name count is null.");
        }

    } else {

        // The separator could not be found.
        // The full name is not hierarchical and represents the part name.
        // The given compound contains parts which are primitive models.

        // The index of the part name.
        int index = -1;
        get_compound_part_index(p0, p1, p3, p4, (void*) &index);

        if (index != -1) {

//??            log_message((void*) &INFO_LOG_LEVEL, (void*) &SET_COMPOUND_PART_BY_NAME_MESSAGE, (void*) &SET_COMPOUND_PART_BY_NAME_MESSAGE_COUNT);

            //?? TODO:
            //?? - Do NOT just replace existing parts, otherwise the reference to
            //??   them is lost and they can not be destroyed properly.
            //?? - Allow replacement for primitive types (integer, double) that
            //??   do not have to be destroyed!
            //?? - Check the abstraction of the model to be set:
            //??   If it is compound, then do NOT replace; otherwise DO replace!

/*??
            // Use index of the found element.
            set_compound_part_by_index(p0, p1, p2,
                (void*) &index,
                p3, p4, p5,
                p6, p7, p8, p9, p10, p11, p12, p13, p14,
                p15, p16, p17, p18, p19, p20, p21, p22, p23);
*/

        } else {

//??            log_message((void*) &INFO_LOG_LEVEL, (void*) &ADD_COMPOUND_PART_BY_NAME_MESSAGE, (void*) &ADD_COMPOUND_PART_BY_NAME_MESSAGE_COUNT);

            // Use compound count as index.
            set_compound_part_by_index(p0, p1, p2,
                p1,
                p3, p4, p5,
                p6, p7, p8, p9, p10, p11, p12, p13, p14,
                p15, p16, p17, p18, p19, p20, p21, p22, p23);
        }
    }
}

/**
 * Adds the compound part.
 *
 * @param p0 the map
 * @param p1 the name
 * @param p2 the name size
 * @param p3 the reference
 * @param p4 the reference size
 */
void add_compound_part(void* p0, const void* p1, const void* p2, const void* p3, const void* p4) {

/*??
    // This element name will get destroyed (free) in remove_map_element.
    void* n = malloc(0);

    // Extend name with next free index.
    build_next_map_element_name(m->names, p1, n);
    set_map_element_with_name(p0, n, p3);

    int i = -1;

    get_map_size(p0, (void*) &PART_NAMES_COUNTS_ARRAY_INDEX);

    if (i != -1) {

        set_map_element_at_index(p0, (void*) &PART_NAMES_COUNTS_ARRAY_INDEX, p1, p3);
    }
*/
}

/**
 * Removes the compound part by index.
 *
 * @param p0 the compound
 * @param p1 the compound count
 * @param p2 the compound size
 * @param p3 the index
 */
void remove_compound_part_by_index(void* p0, void* p1, void* p2, const void* p3) {

    if (p3 != NULL_POINTER) {

        int* i = (int*) p3;

        if (p2 != NULL_POINTER) {

            int* s = (int*) p2;

            if (p1 != NULL_POINTER) {

                int* c = (int*) p1;

                if (*i >= 0) {

//??                    log_message((void*) &INFO_LOG_LEVEL, (void*) &"Remove compound part by index.");

                    // Initialize part names, models, abstractions, constraints
                    // and position models, abstractions, constraints
                    // and their counts and sizes.
                    void* pn = NULL_POINTER;
                    void* pnc = NULL_POINTER;
                    void* pns = NULL_POINTER;
                    void* pm = NULL_POINTER;
                    void* pmc = NULL_POINTER;
                    void* pms = NULL_POINTER;
                    void* pa = NULL_POINTER;
                    void* pac = NULL_POINTER;
                    void* pas = NULL_POINTER;
                    void* pc = NULL_POINTER;
                    void* pcc = NULL_POINTER;
                    void* pcs = NULL_POINTER;
                    void* pom = NULL_POINTER;
                    void* pomc = NULL_POINTER;
                    void* poms = NULL_POINTER;
                    void* poa = NULL_POINTER;
                    void* poac = NULL_POINTER;
                    void* poas = NULL_POINTER;
                    void* poc = NULL_POINTER;
                    void* pocc = NULL_POINTER;
                    void* pocs = NULL_POINTER;

                    // Get part names, models, abstractions, constraints
                    // and position models, abstractions, constraints
                    // and their counts and sizes.
                    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_NAMES_INDEX, (void*) &pn);
                    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_NAMES_COUNTS_INDEX, (void*) &pnc);
                    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_NAMES_SIZES_INDEX, (void*) &pns);
                    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_MODELS_INDEX, (void*) &pm);
                    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_MODELS_COUNTS_INDEX, (void*) &pmc);
                    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_MODELS_SIZES_INDEX, (void*) &pms);
                    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_ABSTRACTIONS_INDEX, (void*) &pa);
                    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_ABSTRACTIONS_COUNTS_INDEX, (void*) &pac);
                    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_ABSTRACTIONS_SIZES_INDEX, (void*) &pas);
                    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_CONSTRAINTS_INDEX, (void*) &pc);
                    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_CONSTRAINTS_COUNTS_INDEX, (void*) &pcc);
                    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_CONSTRAINTS_SIZES_INDEX, (void*) &pcs);
                    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_MODELS_INDEX, (void*) &pom);
                    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_MODELS_COUNTS_INDEX, (void*) &pomc);
                    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_MODELS_SIZES_INDEX, (void*) &poms);
                    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_ABSTRACTIONS_INDEX, (void*) &poa);
                    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_ABSTRACTIONS_COUNTS_INDEX, (void*) &poac);
                    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_ABSTRACTIONS_SIZES_INDEX, (void*) &poas);
                    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_CONSTRAINTS_INDEX, (void*) &poc);
                    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_CONSTRAINTS_COUNTS_INDEX, (void*) &pocc);
                    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_CONSTRAINTS_SIZES_INDEX, (void*) &pocs);

                    if (*i < *c) {

                        // Remove part name, model, abstraction, constraint
                        // and position model, abstraction, constraint
                        // and their count and size.
                        remove_array_element((void*) &pn, (void*) &POINTER_ARRAY, p1, p3);
                        remove_array_element((void*) &pnc, (void*) &INTEGER_ARRAY, p1, p3);
                        remove_array_element((void*) &pns, (void*) &INTEGER_ARRAY, p1, p3);
                        remove_array_element((void*) &pm, (void*) &POINTER_ARRAY, p1, p3);
                        remove_array_element((void*) &pmc, (void*) &INTEGER_ARRAY, p1, p3);
                        remove_array_element((void*) &pms, (void*) &INTEGER_ARRAY, p1, p3);
                        remove_array_element((void*) &pa, (void*) &POINTER_ARRAY, p1, p3);
                        remove_array_element((void*) &pac, (void*) &INTEGER_ARRAY, p1, p3);
                        remove_array_element((void*) &pas, (void*) &INTEGER_ARRAY, p1, p3);
                        remove_array_element((void*) &pc, (void*) &POINTER_ARRAY, p1, p3);
                        remove_array_element((void*) &pcc, (void*) &INTEGER_ARRAY, p1, p3);
                        remove_array_element((void*) &pcs, (void*) &INTEGER_ARRAY, p1, p3);
                        remove_array_element((void*) &pom, (void*) &POINTER_ARRAY, p1, p3);
                        remove_array_element((void*) &pomc, (void*) &INTEGER_ARRAY, p1, p3);
                        remove_array_element((void*) &poms, (void*) &INTEGER_ARRAY, p1, p3);
                        remove_array_element((void*) &poa, (void*) &POINTER_ARRAY, p1, p3);
                        remove_array_element((void*) &poac, (void*) &INTEGER_ARRAY, p1, p3);
                        remove_array_element((void*) &poas, (void*) &INTEGER_ARRAY, p1, p3);
                        remove_array_element((void*) &poc, (void*) &POINTER_ARRAY, p1, p3);
                        remove_array_element((void*) &pocc, (void*) &INTEGER_ARRAY, p1, p3);
                        remove_array_element((void*) &pocs, (void*) &INTEGER_ARRAY, p1, p3);

                        // Decrement count.
                        (*c)--;

                    } else {

//??                        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not remove compound part by index. The index exceeds the count.");
                    }

                } else {

//??                    log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not remove compound part by index. The index is negativ.");
                }

            } else {

//??                log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not remove compound part by index. The count is null.");
            }

        } else {

//??            log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not remove compound part by index. The size is null.");
        }

    } else {

//??        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not remove compound part by index. The index is null.");
    }
}

/**
 * Removes the compound part by name.
 *
 * @param p0 the compound
 * @param p1 the compound count
 * @param p2 the compound size
 * @param p3 the part name
 * @param p4 the part name count
 * @param p5 the part name size
 */
void remove_compound_part_by_name(void* p0, void* p1, void* p2,
    const void* p3, const void* p4, const void* p5) {

    // The separator index.
    int i = -1;

    get_array_element_index(p3, (void*) &CHARACTER_ARRAY, p4, (void*) &COMPOUND_PART_SEPARATOR, (void*) &i);

    if (i != -1) {

        // The separator has been found.
        // The full name is hierarchical.
        // The given compound contains parts which are compound models.

        if (p4 != NULL_POINTER) {

            int* nc = (int*) p4;

            if (p3 != NULL_POINTER) {

                void** n = (void**) p3;

                if (i >= 0) {

                    if (i < *nc) {

                        if (i != 0) {

                            if (i != (*nc - 1)) {

                                // The remaining name starts at the index after the separator.
                                // Example: "hello.test"
                                // The index of the separator is 5.
                                // The starting index of the remaining name "test" is 6 = 5 + 1.
                                void* r = (void*) (*n + i + 1);

                                // The remaining name count is the full name count decreased
                                // by the separator index increased by one.
                                // Example: "hello.test"
                                // The full name count is 10.
                                // The separator index is 5.
                                // The count of the remaining name "test" is 4 = 10 - (5 + 1).
                                int rc = *nc - (i + 1);

                                // Initialize part models and their counts and sizes.
                                void* m = NULL_POINTER;
                                int mc = 0;
                                int ms = 0;

                                // Get part models and their counts and sizes.
                                get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_MODELS_INDEX, (void*) &m);
                                get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_MODELS_COUNTS_INDEX, (void*) &mc);
                                get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_MODELS_SIZES_INDEX, (void*) &ms);

                                // Get index of part name.
                                // The separator index i is used as part name count.
                                // Example: "hello.test"
                                // The index i of the separator is 5.
                                // The count of the part name "hello" before the separator is likewise 5.
                                int index = -1;
                                get_compound_part_index(p0, p1, p3, (void*) &i, (void*) &index);

                                if (index != -1) {

                                    // Initialize part model and its count and size.
                                    void* pm = NULL_POINTER;
                                    int pmc = 0;
                                    int pms = 0;

                                    // Get part model and its count and size.
                                    get_array_element((void*) &m, (void*) &POINTER_ARRAY, (void*) &index, (void*) &pm);
                                    get_array_element((void*) &mc, (void*) &INTEGER_ARRAY, (void*) &index, (void*) &pmc);
                                    get_array_element((void*) &ms, (void*) &INTEGER_ARRAY, (void*) &index, (void*) &pms);

                                    //?? TODO:
                                    //?? For now, the remaining name count is also used as
                                    //?? remaining name size and such handed over twice.
                                    //?? Later implementations may use UNICODE names so that
                                    //?? the name count and size differ.

                                    // Recursively continue to process along the hierarchical name.
                                    remove_compound_part_by_name((void*) &pm, (void*) &pmc, (void*) &pms,
                                        (void*) &r, (void*) &rc, (void*) &rc);

                                } else {

//??                                    log_message((void*) &WARNING_LOG_LEVEL, (void*) &"Could not remove compound part by name. A part with that name does not exist.");
                                }

                            } else {

//??                                log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not remove compound part by name. The full name ends with a separator.");
                            }

                        } else {

//??                            log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not remove compound part by name. The full name starts with a separator.");
                        }

                    } else {

//??                        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not remove compound part by name. The separator index exceeds the full name size.");
                    }

                } else {

//??                    log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not remove compound part by name. The separator index is negative.");
                }

            } else {

//??                log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not remove compound part by name. The name is null.");
            }

        } else {

//??            log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not remove compound part by name. The name size is null.");
        }

    } else {

        // The separator could not be found.
        // The full name is not hierarchical and represents the part name.
        // The given compound contains parts which are primitive models.

        // The index of the part name.
        int index = -1;
        get_compound_part_index(p0, p1, p3, p4, (void*) &index);

        if (index != -1) {

//??            log_message((void*) &INFO_LOG_LEVEL, (void*) &REMOVE_COMPOUND_PART_BY_NAME_MESSAGE, (void*) &REMOVE_COMPOUND_PART_BY_NAME_MESSAGE_COUNT);

            remove_compound_part_by_index(p0, p1, p2, (void*) &index);

        } else {

//??            log_message((void*) &WARNING_LOG_LEVEL, (void*) &COULD_NOT_REMOVE_COMPOUND_PART_BY_NAME_A_PART_WITH_THAT_NAME_DOES_NOT_EXIST_MESSAGE, (void*) &COULD_NOT_REMOVE_COMPOUND_PART_BY_NAME_A_PART_WITH_THAT_NAME_DOES_NOT_EXIST_MESSAGE_COUNT);
        }
    }
}

/**
 * Gets the compound part by index.
 *
 * @param p0 the compound
 * @param p1 the compound count
 * @param p2 the compound size
 * @param p3 the index
 * @param p4 the part name
 * @param p5 the part name count
 * @param p6 the part name size
 * @param p7 the part model
 * @param p8 the part model count
 * @param p9 the part model size
 * @param p10 the part abstraction
 * @param p11 the part abstraction count
 * @param p12 the part abstraction size
 * @param p13 the part constraint
 * @param p14 the part constraint count
 * @param p15 the part constraint size
 * @param p16 the position model
 * @param p17 the position model count
 * @param p18 the position model size
 * @param p19 the position abstraction
 * @param p20 the position abstraction count
 * @param p21 the position abstraction size
 * @param p22 the position constraint
 * @param p23 the position constraint count
 * @param p24 the position constraint size
 */
void get_compound_part_by_index(const void* p0, const void* p1, const void* p2,
    const void* p3,
    void* p4, void* p5, void* p6,
    void* p7, void* p8, void* p9,
    void* p10, void* p11, void* p12,
    void* p13, void* p14, void* p15,
    void* p16, void* p17, void* p18,
    void* p19, void* p20, void* p21,
    void* p22, void* p23, void* p24) {

    if (p3 != NULL_POINTER) {

        int* i = (int*) p3;

        if (p1 != NULL_POINTER) {

            int* c = (int*) p1;

            if (*i >= 0) {

//??                log_message((void*) &INFO_LOG_LEVEL, (void*) &"Get compound part by index.");

                // Initialize part names, models, abstractions, constraints
                // and position models, abstractions, constraints
                // and their counts and sizes.
                void* pn = NULL_POINTER;
                void* pnc = NULL_POINTER;
                void* pns = NULL_POINTER;
                void* pm = NULL_POINTER;
                void* pmc = NULL_POINTER;
                void* pms = NULL_POINTER;
                void* pa = NULL_POINTER;
                void* pac = NULL_POINTER;
                void* pas = NULL_POINTER;
                void* pc = NULL_POINTER;
                void* pcc = NULL_POINTER;
                void* pcs = NULL_POINTER;
                void* pom = NULL_POINTER;
                void* pomc = NULL_POINTER;
                void* poms = NULL_POINTER;
                void* poa = NULL_POINTER;
                void* poac = NULL_POINTER;
                void* poas = NULL_POINTER;
                void* poc = NULL_POINTER;
                void* pocc = NULL_POINTER;
                void* pocs = NULL_POINTER;

                // Get part names, models, abstractions, constraints
                // and position models, abstractions, constraints
                // and their counts and sizes.
                get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_NAMES_INDEX, (void*) &pn);
                get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_NAMES_COUNTS_INDEX, (void*) &pnc);
                get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_NAMES_SIZES_INDEX, (void*) &pns);
                get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_MODELS_INDEX, (void*) &pm);
                get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_MODELS_COUNTS_INDEX, (void*) &pmc);
                get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_MODELS_SIZES_INDEX, (void*) &pms);
                get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_ABSTRACTIONS_INDEX, (void*) &pa);
                get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_ABSTRACTIONS_COUNTS_INDEX, (void*) &pac);
                get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_ABSTRACTIONS_SIZES_INDEX, (void*) &pas);
                get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_CONSTRAINTS_INDEX, (void*) &pc);
                get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_CONSTRAINTS_COUNTS_INDEX, (void*) &pcc);
                get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_CONSTRAINTS_SIZES_INDEX, (void*) &pcs);
                get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_MODELS_INDEX, (void*) &pom);
                get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_MODELS_COUNTS_INDEX, (void*) &pomc);
                get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_MODELS_SIZES_INDEX, (void*) &poms);
                get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_ABSTRACTIONS_INDEX, (void*) &poa);
                get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_ABSTRACTIONS_COUNTS_INDEX, (void*) &poac);
                get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_ABSTRACTIONS_SIZES_INDEX, (void*) &poas);
                get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_CONSTRAINTS_INDEX, (void*) &poc);
                get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_CONSTRAINTS_COUNTS_INDEX, (void*) &pocc);
                get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_CONSTRAINTS_SIZES_INDEX, (void*) &pocs);

                if (*i < *c) {

                    // Get part name, model, abstraction, constraint
                    // and position model, abstraction, constraint
                    // and their count and size.
                    // CAUTION! Only those parameters are got, which are not null.

                    if (p4 != NULL_POINTER) {

                        get_array_element((void*) &pn, (void*) &POINTER_ARRAY, p3, p4);
                    }

                    if (p5 != NULL_POINTER) {

                        get_array_element((void*) &pnc, (void*) &INTEGER_ARRAY, p3, p5);
                    }

                    if (p6 != NULL_POINTER) {

                        get_array_element((void*) &pns, (void*) &INTEGER_ARRAY, p3, p6);
                    }

                    if (p7 != NULL_POINTER) {

                        get_array_element((void*) &pm, (void*) &POINTER_ARRAY, p3, p7);
                    }

                    if (p8 != NULL_POINTER) {

                        get_array_element((void*) &pmc, (void*) &INTEGER_ARRAY, p3, p8);
                    }

                    if (p9 != NULL_POINTER) {

                        get_array_element((void*) &pms, (void*) &INTEGER_ARRAY, p3, p9);
                    }

                    if (p10 != NULL_POINTER) {

                        get_array_element((void*) &pa, (void*) &POINTER_ARRAY, p3, p10);
                    }

                    if (p11 != NULL_POINTER) {

                        get_array_element((void*) &pac, (void*) &INTEGER_ARRAY, p3, p11);
                    }

                    if (p12 != NULL_POINTER) {

                        get_array_element((void*) &pas, (void*) &INTEGER_ARRAY, p3, p12);
                    }

                    if (p13 != NULL_POINTER) {

                        get_array_element((void*) &pc, (void*) &POINTER_ARRAY, p3, p13);
                    }

                    if (p14 != NULL_POINTER) {

                        get_array_element((void*) &pcc, (void*) &INTEGER_ARRAY, p3, p14);
                    }

                    if (p15 != NULL_POINTER) {

                        get_array_element((void*) &pcs, (void*) &INTEGER_ARRAY, p3, p15);
                    }

                    if (p16 != NULL_POINTER) {

                        get_array_element((void*) &pom, (void*) &POINTER_ARRAY, p3, p16);
                    }

                    if (p17 != NULL_POINTER) {

                        get_array_element((void*) &pomc, (void*) &INTEGER_ARRAY, p3, p17);
                    }

                    if (p18 != NULL_POINTER) {

                        get_array_element((void*) &poms, (void*) &INTEGER_ARRAY, p3, p18);
                    }

                    if (p19 != NULL_POINTER) {

                        get_array_element((void*) &poa, (void*) &POINTER_ARRAY, p3, p19);
                    }

                    if (p20 != NULL_POINTER) {

                        get_array_element((void*) &poac, (void*) &INTEGER_ARRAY, p3, p20);
                    }

                    if (p21 != NULL_POINTER) {

                        get_array_element((void*) &poas, (void*) &INTEGER_ARRAY, p3, p21);
                    }

                    if (p22 != NULL_POINTER) {

                        get_array_element((void*) &poc, (void*) &POINTER_ARRAY, p3, p22);
                    }

                    if (p23 != NULL_POINTER) {

                        get_array_element((void*) &pocc, (void*) &INTEGER_ARRAY, p3, p23);
                    }

                    if (p24 != NULL_POINTER) {

                        get_array_element((void*) &pocs, (void*) &INTEGER_ARRAY, p3, p24);
                    }

                } else {

//??                    log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not get compound part by index. The index exceeds the count.");
                }

            } else {

//??                log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not get compound part by index. The index is negativ.");
            }

        } else {

//??            log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not get compound part by index. The count is null.");
        }

    } else {

//??        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not get compound part by index. The index is null.");
    }
}

/**
 * Gets the compound part by name.
 *
 * @param p0 the compound
 * @param p1 the compound count
 * @param p2 the compound size
 * @param p3 the part name
 * @param p4 the part name count
 * @param p5 the part name size
 * @param p6 the part model
 * @param p7 the part model count
 * @param p8 the part model size
 * @param p9 the part abstraction
 * @param p10 the part abstraction count
 * @param p11 the part abstraction size
 * @param p12 the part constraint
 * @param p13 the part constraint count
 * @param p14 the part constraint size
 * @param p15 the position model
 * @param p16 the position model count
 * @param p17 the position model size
 * @param p18 the position abstraction
 * @param p19 the position abstraction count
 * @param p20 the position abstraction size
 * @param p21 the position constraint
 * @param p22 the position constraint count
 * @param p23 the position constraint size
 */
void get_compound_part_by_name(const void* p0, const void* p1, const void* p2,
    void* p3, void* p4, void* p5,
    void* p6, void* p7, void* p8,
    void* p9, void* p10, void* p11,
    void* p12, void* p13, void* p14,
    void* p15, void* p16, void* p17,
    void* p18, void* p19, void* p20,
    void* p21, void* p22, void* p23) {

    // The separator index.
    int i = -1;

    get_array_element_index(p3, (void*) &CHARACTER_ARRAY, p4, (void*) &COMPOUND_PART_SEPARATOR, (void*) &i);

    if (i != -1) {

        // The separator has been found.
        // The full name is hierarchical.
        // The given compound contains parts which are compound models.

        if (p4 != NULL_POINTER) {

            int* nc = (int*) p4;

            if (p3 != NULL_POINTER) {

                void** n = (void**) p3;

                if (i >= 0) {

                    if (i < *nc) {

                        if (i != 0) {

                            if (i != (*nc - 1)) {

                                // The remaining name starts at the index after the separator.
                                // Example: "hello.test"
                                // The index of the separator is 5.
                                // The starting index of the remaining name "test" is 6 = 5 + 1.
                                void* r = (void*) (*n + i + 1);

                                // The remaining name count is the full name count decreased
                                // by the separator index increased by one.
                                // Example: "hello.test"
                                // The full name count is 10.
                                // The separator index is 5.
                                // The count of the remaining name "test" is 4 = 10 - (5 + 1).
                                int rc = *nc - (i + 1);

                                // Initialize part models and their counts and sizes.
                                void* m = NULL_POINTER;
                                int mc = 0;
                                int ms = 0;

                                // Get part models and their counts and sizes.
                                get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_MODELS_INDEX, (void*) &m);
                                get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_MODELS_COUNTS_INDEX, (void*) &mc);
                                get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_MODELS_SIZES_INDEX, (void*) &ms);

                                // Get index of part name.
                                // The separator index i is used as part name count.
                                // Example: "hello.test"
                                // The index i of the separator is 5.
                                // The count of the part name "hello" before the separator is likewise 5.
                                int index = -1;
                                get_compound_part_index(p0, p1, p3, (void*) &i, (void*) &index);

                                if (index != -1) {

                                    // Initialize part model and its count and size.
                                    void* pm = NULL_POINTER;
                                    int pmc = 0;
                                    int pms = 0;

                                    // Get part model and its count and size.
                                    get_array_element((void*) &m, (void*) &POINTER_ARRAY, (void*) &index, (void*) &pm);
                                    get_array_element((void*) &mc, (void*) &INTEGER_ARRAY, (void*) &index, (void*) &pmc);
                                    get_array_element((void*) &ms, (void*) &INTEGER_ARRAY, (void*) &index, (void*) &pms);

                                    //?? TODO:
                                    //?? For now, the remaining name count is also used as
                                    //?? remaining name size and such handed over twice.
                                    //?? Later implementations may use UNICODE names so that
                                    //?? the name count and size differ.

                                    // Recursively continue to process along the hierarchical name.
                                    get_compound_part_by_name((void*) &pm, (void*) &pmc, (void*) &pms,
                                        (void*) &r, (void*) &rc, (void*) &rc,
                                        p6, p7, p8, p9, p10, p11, p12, p13, p14,
                                        p15, p16, p17, p18, p19, p20, p21, p22, p23);

                                } else {

//??                                    log_message((void*) &WARNING_LOG_LEVEL, (void*) &"Could not get compound part by name. A part with that name does not exist.");
                                }

                            } else {

//??                                log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not get compound part by name. The full name ends with a separator.");
                            }

                        } else {

//??                            log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not get compound part by name. The full name starts with a separator.");
                        }

                    } else {

//??                        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not get compound part by name. The separator index exceeds the full name size.");
                    }

                } else {

//??                    log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not get compound part by name. The separator index is negative.");
                }

            } else {

//??                log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not get compound part by name. The name is null.");
            }

        } else {

//??            log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not get compound part by name. The name size is null.");
        }

    } else {

        // The separator could not be found.
        // The full name is not hierarchical and represents the part name.
        // The given compound contains parts which are primitive models.

        // The index of the part name.
        int index = -1;
        get_compound_part_index(p0, p1, p3, p4, (void*) &index);

        if (index != -1) {

//??            log_message((void*) &INFO_LOG_LEVEL, (void*) &GET_COMPOUND_PART_BY_NAME_MESSAGE, (void*) &GET_COMPOUND_PART_BY_NAME_MESSAGE_COUNT);

            get_compound_part_by_index(p0, p1, p2,
                (void*) &index,
                p3, p4, p5,
                p6, p7, p8, p9, p10, p11, p12, p13, p14,
                p15, p16, p17, p18, p19, p20, p21, p22, p23);

        } else {

//??            log_message((void*) &WARNING_LOG_LEVEL, (void*) &COULD_NOT_GET_COMPOUND_PART_BY_NAME_A_PART_WITH_THAT_NAME_DOES_NOT_EXIST_MESSAGE, (void*) &COULD_NOT_GET_COMPOUND_PART_BY_NAME_A_PART_WITH_THAT_NAME_DOES_NOT_EXIST_MESSAGE_COUNT);
        }
    }
}

/* COMPOUND_SOURCE */
#endif
