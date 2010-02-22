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
 * @version $RCSfile: file_operation_handler.c,v $ $Revision: 1.3 $ $Date: 2009-01-31 16:06:31 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef FILE_OPERATION_HANDLER_SOURCE
#define FILE_OPERATION_HANDLER_SOURCE

#include "../../../applicator/filer/archiving_filer.c"
#include "../../../applicator/filer/copying_filer.c"
#include "../../../applicator/filer/directory_contents_listing_filer.c"
#include "../../../constant/model/cybol/operation/file_operation_cybol_model.c"
#include "../../../constant/model/memory/integer_memory_model.c"
#include "../../../constant/model/log/message_log_model.c"
#include "../../../logger/logger.c"
#include "../../../executor/comparator/array_equality_comparator.c"

/**
 * Handles the file operation signal.
 *
 * @param p0 the internal memory
 * @param p1 the knowledge memory
 * @param p2 the knowledge memory count
 * @param p3 the knowledge memory size
 * @param p4 the signal memory
 * @param p5 the signal memory count
 * @param p6 the signal memory size
 * @param p7 the shutdown flag
 * @param p8 the signal memory interrupt request flag
 * @param p9 the signal memory mutex
 * @param p10 the model / signal / operation
 * @param p11 the model / signal / operation count
 * @param p12 the details / parameters
 * @param p13 the details / parameters count
 * @param p14 the signal priority (Hand over as reference!)
 * @param p15 the signal identification (Hand over as reference!)
 * @param p16 the comparison result
 */
void handle_file_operation(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6,
    void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14, void* p15, void* p16) {

    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Handle file operation.");

    // The comparison result.
    int* r = (int*) p16;

    if (*r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_arrays((void*) &r, p10, p11, (void*) ARCHIVE_FILE_OPERATION_CYBOL_MODEL, (void*) ARCHIVE_FILE_OPERATION_CYBOL_MODEL_COUNT, p16, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

        if (*r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            file_archiving(p12, p13, p1, p2);
        }
    }

    if (*r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_arrays((void*) &r, p10, p11, (void*) COPY_FILE_OPERATION_CYBOL_MODEL, (void*) COPY_FILE_OPERATION_CYBOL_MODEL_COUNT, p16, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

        if (*r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            file_copying(p12, p13, p1, p2);
        }
    }

    if (*r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_arrays((void*) &r, p10, p11, (void*) LIST_DIRECTORY_CONTENTS_FILE_OPERATION_CYBOL_MODEL, (void*) LIST_DIRECTORY_CONTENTS_FILE_OPERATION_CYBOL_MODEL_COUNT, p16, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

        if (*r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            file_directory_contents_listing(p12, p13, p1, p2);
        }
    }
}

/* FILE_OPERATION_HANDLER_SOURCE */
#endif
