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
 * @version $RCSfile: directory_contents_listing_filer.c,v $ $Revision: 1.3 $ $Date: 2009-10-06 21:25:26 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef DIRECTORY_CONTENTS_LISTING_FILER_SOURCE
#define DIRECTORY_CONTENTS_LISTING_FILER_SOURCE

#include <unistd.h>
#include "../../applicator/runner/executing_runner.c"
#include "../../constant/abstraction/cybol/text_cybol_abstraction.c"
#include "../../constant/abstraction/memory/memory_abstraction.c"
#include "../../constant/model/log/message_log_model.c"
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../constant/name/cybol/operation/file/list_file_operation_cybol_name.c"
#include "../../constant/name/command_option/unix/list_unix_command_option_name.c"
#include "../../logger/logger.c"
#include "../../memoriser/allocator/character_vector_allocator.c"
#include "../../variable/reallocation_factor.c"

/**
 * Lists the directory contents.
 *
 * @param p0 the parameters
 * @param p1 the parameters count
 * @param p2 the knowledge memory
 * @param p3 the knowledge memory count
 */
void file_directory_contents_listing(void* p0, void* p1, void* p2, void* p3) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"List directory contents.");

    // The all name, abstraction, model, details.
    void** alln = NULL_POINTER_MEMORY_MODEL;
    void** allnc = NULL_POINTER_MEMORY_MODEL;
    void** allns = NULL_POINTER_MEMORY_MODEL;
    void** alla = NULL_POINTER_MEMORY_MODEL;
    void** allac = NULL_POINTER_MEMORY_MODEL;
    void** allas = NULL_POINTER_MEMORY_MODEL;
    int** allm = (int**) NULL_POINTER_MEMORY_MODEL;
    void** allmc = NULL_POINTER_MEMORY_MODEL;
    void** allms = NULL_POINTER_MEMORY_MODEL;
    void** alld = NULL_POINTER_MEMORY_MODEL;
    void** alldc = NULL_POINTER_MEMORY_MODEL;
    void** allds = NULL_POINTER_MEMORY_MODEL;

    // The long listing name, abstraction, model, details.
    void** longlistingn = NULL_POINTER_MEMORY_MODEL;
    void** longlistingnc = NULL_POINTER_MEMORY_MODEL;
    void** longlistingns = NULL_POINTER_MEMORY_MODEL;
    void** longlistinga = NULL_POINTER_MEMORY_MODEL;
    void** longlistingac = NULL_POINTER_MEMORY_MODEL;
    void** longlistingas = NULL_POINTER_MEMORY_MODEL;
    int** longlistingm = (int**) NULL_POINTER_MEMORY_MODEL;
    void** longlistingmc = NULL_POINTER_MEMORY_MODEL;
    void** longlistingms = NULL_POINTER_MEMORY_MODEL;
    void** longlistingd = NULL_POINTER_MEMORY_MODEL;
    void** longlistingdc = NULL_POINTER_MEMORY_MODEL;
    void** longlistingds = NULL_POINTER_MEMORY_MODEL;

    // Get all option.
    get_universal_compound_element_by_name(p0, p1,
        (void*) ALL_LIST_FILE_OPERATION_CYBOL_NAME, (void*) ALL_LIST_FILE_OPERATION_CYBOL_NAME_COUNT,
        (void*) &alln, (void*) &allnc, (void*) &allns,
        (void*) &alla, (void*) &allac, (void*) &allas,
        (void*) &allm, (void*) &allmc, (void*) &allms,
        (void*) &alld, (void*) &alldc, (void*) &allds,
        p2, p3);

    // Get long listing option.
    get_universal_compound_element_by_name(p0, p1,
        (void*) LONG_LISTING_LIST_FILE_OPERATION_CYBOL_NAME, (void*) LONG_LISTING_LIST_FILE_OPERATION_CYBOL_NAME_COUNT,
        (void*) &longlistingn, (void*) &longlistingnc, (void*) &longlistingns,
        (void*) &longlistinga, (void*) &longlistingac, (void*) &longlistingas,
        (void*) &longlistingm, (void*) &longlistingmc, (void*) &longlistingms,
        (void*) &longlistingd, (void*) &longlistingdc, (void*) &longlistingds,
        p2, p3);

    // The arguments vector.
    void* arg = *NULL_POINTER_MEMORY_MODEL;
    int argc = *NUMBER_0_INTEGER_MEMORY_MODEL;
    int args = *NUMBER_0_INTEGER_MEMORY_MODEL;

    // Allocate arguments vector.
    allocate((void*) &arg, (void*) &args, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION);

    // Append command.
    append((void*) &arg, (void*) &argc, (void*) &args, (void*) LIST_DIRECTORY_CONTENTS_UNIX_COMMAND_MODEL, (void*) LIST_DIRECTORY_CONTENTS_UNIX_COMMAND_MODEL_COUNT, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION);

    if (*allm != *NULL_POINTER_MEMORY_MODEL) {

        if (**allm == *TRUE_BOOLEAN_MEMORY_MODEL) {

            // Append all option.
            append((void*) &arg, (void*) &argc, (void*) &args, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION);
            append((void*) &arg, (void*) &argc, (void*) &args, (void*) ALL_LIST_UNIX_COMMAND_OPTION_NAME, (void*) ALL_LIST_UNIX_COMMAND_OPTION_NAME_COUNT, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION);
        }
    }

    if (*longlistingm != *NULL_POINTER_MEMORY_MODEL) {

        if (**longlistingm == *TRUE_BOOLEAN_MEMORY_MODEL) {

            // Append long listing option.
            append((void*) &arg, (void*) &argc, (void*) &args, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION);
            append((void*) &arg, (void*) &argc, (void*) &args, (void*) LONG_LISTING_LIST_UNIX_COMMAND_OPTION_NAME, (void*) LONG_LISTING_LIST_UNIX_COMMAND_OPTION_NAME_COUNT, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION);
        }
    }

    // Execute command line in shell.
    run_executing(arg, (void*) &argc);

    // Deallocate arguments vector.
    deallocate((void*) &arg, (void*) &args, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION);
}

/* DIRECTORY_CONTENTS_LISTING_FILER_SOURCE */
#endif
