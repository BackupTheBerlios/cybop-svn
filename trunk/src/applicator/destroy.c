/*
 * $RCSfile: destroy.c,v $
 *
 * Copyright (c) 1999-2005. Christian Heller and the CYBOP developers.
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
 * This file destroys a transient model to a persistent model.
 *
 * @version $Revision: 1.8 $ $Date: 2005-07-29 16:46:17 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef DESTROY_SOURCE
#define DESTROY_SOURCE

#include "../globals/constants/abstraction_constants.c"
#include "../globals/constants/log_constants.c"
#include "../globals/constants/name_constants.c"
#include "../globals/logger/logger.c"
#include "../memoriser/array.c"

void destroy(void** model, void* model_count, void* model_size,
    void* model_abstr, void* model_abstr_count);

/**
 * Checks for a compound model.
 *
 * @param p0 the primitive flag (1 if primitive; unchanged otherwise)
 * @param p1 the abstraction
 * @param p2 the abstraction count
 */
void check_compound_model(void* p0, void* p1, void* p2) {

    if (p0 != NULL_POINTER) {

        int* p = (int*) p0;

        if (*p != 1) {

            compare_arrays( p1, p2,
                            (void*) COMPOUND_ABSTRACTION,
                            (void*) COMPOUND_ABSTRACTION_COUNT,
                            p0, (void*) CHARACTER_ARRAY);
        }

        if (*p != 1) {

            compare_arrays( p1, p2,
                            (void*) CYBOL_ABSTRACTION,
                            (void*) CYBOL_ABSTRACTION_COUNT,
                            p0, (void*) CHARACTER_ARRAY);
        }
    }
}

/**
 * destroy a primitive model
 *
 * @param p0 the model
 * @param p1 the model count
 * @param p2 the model size
 * @param p3 the model abstraction
 * @param p4 the model abstraction count
 */
void deallocate_primitive_model( void** model, void* model_count, void* model_size,
    void* model_abstr, void* model_abstr_count) {

    log_message_debug("Destroy primitive model.");

    // Destroy model of type given as abstraction.
    deallocate( model, model_size, model_abstr, model_abstr_count );
}

/**
 * destroy a primitive model
 *
 * @param p0 the model
 * @param p1 the model count
 * @param p2 the model size
 * @param p3 the model abstraction
 * @param p4 the model abstraction count
 */
void deallocate_compound_model( void** model, void* model_count, void* model_size,
    void* model_abstr, void* model_abstr_count) {

    //das gesamte Compound durchgehen und f?r jedes Element im Compound wieder
    //destroy model aufrufen

    if (    (model != NULL_POINTER)
         && (model_count != NULL_POINTER)
         && (model_size != NULL_POINTER)
         && (model_abstr != NULL_POINTER)
         && (model_abstr_count != NULL_POINTER) )
    {

        int compound_counter = 0;

        // The element name.
        void** en = NULL_POINTER;
        void** enc = NULL_POINTER;
        void** ens = NULL_POINTER;
        // The element abstraction.
        void** ea = NULL_POINTER;
        void** eac = NULL_POINTER;
        void** eas = NULL_POINTER;
        // The element model.
        void** em = NULL_POINTER;
        void** emc = NULL_POINTER;
        void** ems = NULL_POINTER;
        // The element details.
        void** ed = NULL_POINTER;
        void** edc = NULL_POINTER;
        void** eds = NULL_POINTER;


        while (1) {

            if ( compound_counter  >= *((int*)model_count) ) {

                break;
            }

            // Get element name.
            get_compound_element_name_by_index(*model, model_count,
                (void*) &compound_counter,
                (void*) &en, (void*) &enc, (void*) &ens);

            // Get element.
            get_compound_element_by_index(*model, model_count,
                (void*) &compound_counter,
                (void*) &ea, (void*) &eac, (void*) &eas,
                (void*) &em, (void*) &emc, (void*) &ems,
                (void*) &ed, (void*) &edc, (void*) &eds);

            destroy( em, *emc, *ems, *ea, *eac);

            compound_counter = compound_counter + 1;

        }
    }
}

/**
 * Deallocates a transient destination model.
 *
 * Primitive models need a different creation than compound models.
 *
 * persistent:
 * - stored permanently
 * - outside CYBOI
 * - longer than CYBOI lives
 *
 * transient:
 * - stored in computer memory (RAM)
 * - only accessible from within CYBOI
 * - created and destroyed by CYBOI
 * - not available anymore after CYBOI has been destroyed
 *
 * @param p0 the model
 * @param p1 the model count
 * @param p2 the model size
 * @param p3 the model abstraction
 * @param p4 the model abstraction count
 */
void destroy(void** model, void* model_count, void* model_size,
    void* model_abstr, void* model_abstr_count) {

    //?The comparison result.
    int r = 0;

    // Check for compound (later better for primitive!!) model.
    check_compound_model((void*) &r, model_abstr, model_abstr_count);

    if (r == 0) {

        deallocate_primitive_model(model, model_count, model_size, model_abstr, model_abstr_count);

    } else {

        deallocate_compound_model(model, model_count, model_size, model_abstr, model_abstr_count);
    }
}

/**
 * Deallocates a part and removes it from the knowledge model.
 *
 * Expected parameters:
 * - name
 * - channel
 * - abstraction
 * - model
 *
 * @param p0 the parameters
 * @param p1 the parameters count
 * @param p2 the knowledge
 * @param p3 the knowledge count
 * @param p4 the knowledge size
 */
void deallocate_part(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message_debug("Destroy part.");

    // The name name abstraction.
    void** na = NULL_POINTER;
    void** nac = NULL_POINTER;
    void** nas = NULL_POINTER;
    // The name name model.
    void** nm = NULL_POINTER;
    void** nmc = NULL_POINTER;
    void** nms = NULL_POINTER;
    // The name name details.
    void** nd = NULL_POINTER;
    void** ndc = NULL_POINTER;
    void** nds = NULL_POINTER;

    // Get name name.
    get_real_compound_element_by_name(p0, p1,
        (void*) NAME_NAME, (void*) NAME_NAME_COUNT,
        (void*) &na, (void*) &nac, (void*) &nas,
        (void*) &nm, (void*) &nmc, (void*) &nms,
        (void*) &nd, (void*) &ndc, (void*) &nds,
        p2, p3);


    // Check name name.
    if ((na != NULL_POINTER)
        && (nac != NULL_POINTER)
        && (nas != NULL_POINTER)
        && (nm != NULL_POINTER)
        && (nmc != NULL_POINTER)
        && (nms != NULL_POINTER)
        && (nd != NULL_POINTER)
        && (ndc != NULL_POINTER)
        && (nds != NULL_POINTER)
        )
    {

        //check the abstraction from the name
        //is must be a string
        int r = 0;
        compare_arrays( *na, *nac,
                        STRING_ABSTRACTION, STRING_ABSTRACTION_COUNT,
                        &r, CHARACTER_ARRAY );

        if ( r==1 ) {

            // The element abstraction.
            void** ea = NULL_POINTER;
            void** eac = NULL_POINTER;
            void** eas = NULL_POINTER;
            // The element model.
            void** em = NULL_POINTER;
            void** emc = NULL_POINTER;
            void** ems = NULL_POINTER;
            // The element details.
            void** ed = NULL_POINTER;
            void** edc = NULL_POINTER;
            void** eds = NULL_POINTER;

            get_real_compound_element_by_name(p2, p3,
                (void*) *nm, (void*) *nmc,
                (void*) &ea, (void*) &eac, (void*) &eas,
                (void*) &em, (void*) &emc, (void*) &ems,
                (void*) &ed, (void*) &edc, (void*) &eds,
                p2, p3);

            if (    (em != NULL_POINTER)
                 && (emc != NULL_POINTER)
                 && (ems != NULL_POINTER)
                 && (ea != NULL_POINTER)
                 && (eac != NULL_POINTER)
                 && (eas != NULL_POINTER) )
            {

                //destroy model
                destroy( em, *emc, *ems , *ea, *eac );
            }

            //remove the part
            //this must after the destroy the model, because
            //some wrong pointer
            remove_compound_element_by_name(p2, p3, p4,
                (void*) *nm, (void*) *nmc );

        }

    } else {

        log_message_debug("Could not destry the part. At least one of the given parameters is null.");
    }

}

/* DESTROY_SOURCE */
#endif
