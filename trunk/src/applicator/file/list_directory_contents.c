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
 * @version $RCSfile: directory_contents_listing_filer.c,v $ $Revision: 1.3 $ $Date: 2009-10-06 21:25:26 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef LIST_DIRECTORY_CONTENTS_SOURCE
#define LIST_DIRECTORY_CONTENTS_SOURCE

#include <unistd.h>

#include "../../applicator/runner/executing_runner.c"
#include "../../constant/abstraction/cybol/text_cybol_abstraction.c"
#include "../../constant/abstraction/memory/memory_abstraction.c"
#include "../../constant/model/log/message_log_model.c"
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../constant/name/cybol/operation/file/list_file_operation_cybol_name.c"
#include "../../constant/name/command_option/unix/list_unix_command_option_name.c"
#include "../../executor/memoriser/allocator.c"
#include "../../logger/logger.c"
#include "../../variable/reallocation_factor.c"

/**
 * Lists the directory contents.
 *
 * Expected parametres:
 * - all (optional): the list all option (showing hidden, current . and super .. directory)
 * - long (optional): the long listing option (showing user rights etc.)
 *
 * @param p0 the parametres array (signal/ operation part details with pointers referencing parts)
 * @param p1 the parametres array count
 */
void apply_list_directory_contents(void* p0, void* p1) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Apply list directory contents.");

    // The all part.
    void* a = *NULL_POINTER_MEMORY_MODEL;
    // The long listing part.
    void* l = *NULL_POINTER_MEMORY_MODEL;

    // The all part model.
    void* am = *NULL_POINTER_MEMORY_MODEL;
    // The long listing part model.
    void* lm = *NULL_POINTER_MEMORY_MODEL;

    // The all part model data.
    void* amd = *NULL_POINTER_MEMORY_MODEL;
    // The long listing part model data.
    void* lmd = *NULL_POINTER_MEMORY_MODEL;

    // Get all part.
    get_name_array((void*) &a, p0, (void*) ALL_LIST_FILE_OPERATION_CYBOL_NAME, (void*) ALL_LIST_FILE_OPERATION_CYBOL_NAME_COUNT, p1);
    // Get long listing part.
    get_name_array((void*) &l, p0, (void*) LONG_LISTING_LIST_FILE_OPERATION_CYBOL_NAME, (void*) LONG_LISTING_LIST_FILE_OPERATION_CYBOL_NAME_COUNT, p1);

    // Get all part model.
    copy_array_forward((void*) &am, a, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) MODEL_PART_MEMORY_NAME);
    // Get long listing part model.
    copy_array_forward((void*) &lm, l, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) MODEL_PART_MEMORY_NAME);

    // Get all part model data.
    copy_array_forward((void*) &amd, am, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) DATA_ITEM_MEMORY_NAME);
    // Get long listing part model data.
    copy_array_forward((void*) &lmd, lm, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) DATA_ITEM_MEMORY_NAME);

    // The arguments vector.
    void* arg = *NULL_POINTER_MEMORY_MODEL;
    int argc = *NUMBER_0_INTEGER_MEMORY_MODEL;
    int args = *NUMBER_0_INTEGER_MEMORY_MODEL;

    // Allocate arguments vector.
    allocate((void*) &arg, (void*) &args, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

    // Append command.
    overwrite_array((void*) &arg, (void*) LIST_DIRECTORY_CONTENTS_UNIX_COMMAND_MODEL, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) LIST_DIRECTORY_CONTENTS_UNIX_COMMAND_MODEL_COUNT, (void*) &argc, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) &argc, (void*) &args, (void*) TRUE_BOOLEAN_MEMORY_MODEL);

    // The comparison result.
    int r = *FALSE_BOOLEAN_MEMORY_MODEL;

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_integer_unequal((void*) &r, (void*) *amd, (void*) FALSE_BOOLEAN_MEMORY_MODEL);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            // Append all option.
            overwrite_array((void*) &arg, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) LIST_DIRECTORY_CONTENTS_UNIX_COMMAND_MODEL_COUNT, (void*) &argc, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) &argc, (void*) &args, (void*) TRUE_BOOLEAN_MEMORY_MODEL);
            overwrite_array((void*) &arg, (void*) ALL_LIST_UNIX_COMMAND_OPTION_NAME, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) ALL_LIST_UNIX_COMMAND_OPTION_NAME_COUNT, (void*) &argc, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) &argc, (void*) &args, (void*) TRUE_BOOLEAN_MEMORY_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_integer_unequal((void*) &r, (void*) *lmd, (void*) FALSE_BOOLEAN_MEMORY_MODEL);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            // Append long listing option.
            overwrite_array((void*) &arg, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) LIST_DIRECTORY_CONTENTS_UNIX_COMMAND_MODEL_COUNT, (void*) &argc, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) &argc, (void*) &args, (void*) TRUE_BOOLEAN_MEMORY_MODEL);
            overwrite_array((void*) &arg, (void*) LONG_LISTING_LIST_UNIX_COMMAND_OPTION_NAME, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) LONG_LISTING_LIST_UNIX_COMMAND_OPTION_NAME_COUNT, (void*) &argc, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) &argc, (void*) &args, (void*) TRUE_BOOLEAN_MEMORY_MODEL);
        }
    }

    // Execute command line in shell.
    run_executing(arg, (void*) &argc);

    // Deallocate arguments vector.
    deallocate((void*) &arg, (void*) &args, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);
}

/* LIST_DIRECTORY_CONTENTS_SOURCE */
#endif
