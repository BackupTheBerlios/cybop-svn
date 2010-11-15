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
 * @version $RCSfile: globaliser.c,v $ $Revision: 1.13 $ $Date: 2009-01-31 16:06:30 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef REALLOCATION_FACTOR_GLOBALISER_SOURCE
#define REALLOCATION_FACTOR_GLOBALISER_SOURCE

#include "../../constant/model/memory/integer_memory_model.c"
#include "../../variable/type_size/integral_type_size.c"
#include "../../variable/reallocation_factor.c"

/**
 * Allocates and initialises reallocation factor global variables.
 */
void globalise_reallocation_factor() {

    //
    // If a source model is to be copied to a destination model, the size of
    // the destination has to be large enough to take on the source's elements.
    // If the destination is too small, its size has to be extended.
    // The reallocation factors determine how fast the destination is to grow.
    //
    // The reallocation factors have the following meaning:
    // 0 - neglect number of destination elements and count only source elements
    //     CAUTION! This may delete existing content of the destination, since
    //     its size may shrink, depending on the number of source elements.
    //     The usage of this zero reallocation factor is NOT recommended!
    // 1 - extend destination by adding the exact number of source elements
    //     This is the most memory-efficient solution. The memory structures
    //     using this reallocation factor are only as big as necessary, that is
    //     their size and count (number of elements) are IDENTICAL.
    //     If elements get removed from the memory structure, its size is
    //     shrinked by the exact number of removed elements.
    //     However, this variant is not very effective.
    // 2 - extend destination by twice its count and add number of source elements
    //     This is a more effective solution to what concerns runtime speed.
    //     Whenever the destination gets reallocated, its element count gets
    //     doubled. Therefore, it does not have to get reallocated so often.
    //     However, this variant uses more memory.
    // 3 - extend destination by thrice its count and add number of source elements
    //     This solution is similar to a reallocation factor of two, only that
    //     it is yet more effective, but also uses yet more memory.
    // x - and so on
    //

    // Allocate and initialise array reallocation factor.
    ARRAY_REALLOCATION_FACTOR = (signed char*) malloc(*SIGNED_CHARACTER_INTEGRAL_TYPE_SIZE);
    *ARRAY_REALLOCATION_FACTOR = *NUMBER_2_INTEGER_MEMORY_MODEL;

    // Allocate and initialise compound reallocation factor.
    COMPOUND_REALLOCATION_FACTOR = (signed char*) malloc(*SIGNED_CHARACTER_INTEGRAL_TYPE_SIZE);
    *COMPOUND_REALLOCATION_FACTOR = *NUMBER_2_INTEGER_MEMORY_MODEL;

    // Allocate and initialise cybol file reallocation factor.
    CYBOL_FILE_REALLOCATION_FACTOR = (signed char*) malloc(*SIGNED_CHARACTER_INTEGRAL_TYPE_SIZE);
    *CYBOL_FILE_REALLOCATION_FACTOR = *NUMBER_2_INTEGER_MEMORY_MODEL;
}

/* REALLOCATION_FACTOR_GLOBALISER_SOURCE */
#endif
