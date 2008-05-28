/*
 * $RCSfile: run.c,v $
 *
 * Copyright (c) 1999-2008. Christian Heller and the CYBOP developers.
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
 * @version $Revision: 1.17 $ $Date: 2008-05-28 22:39:58 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef RUN_SOURCE
#define RUN_SOURCE

#include "../applicator/run/run_archive.c"
#include "../applicator/run/run_copy.c"
#include "../applicator/run/run_list_directory_contents.c"
#include "../applicator/run/run_program.c"
#include "../globals/constants/cybol/cybol_abstraction_constants.c"
#include "../globals/constants/cybol/cybol_model_constants.c"
#include "../globals/constants/cybol/cybol_name_constants.c"
#include "../globals/constants/log/log_message_constants.c"
#include "../globals/constants/pointer/pointer_constants.c"
#include "../globals/logger/logger.c"
#include "../memoriser/accessor/compound_accessor.c"

/**
 * Runs a command as a shell command.
 *
 * Expected parameters:
 * - command (required): the name of the command to be executed (archive, list_directory_contents etc.)
 *
 * @param p0 the parameters
 * @param p1 the parameters count
 * @param p2 the knowledge memory
 * @param p3 the knowledge memory count
 */
void run(void* p0, void* p1, void* p2, void* p3) {

    log_terminated_message((void*) INFORMATION_LOG_LEVEL, (void*) L"Run a command.");

    // The command name, abstraction, model, details.
    void** cn = NULL_POINTER;
    void** cnc = NULL_POINTER;
    void** cns = NULL_POINTER;
    void** ca = NULL_POINTER;
    void** cac = NULL_POINTER;
    void** cas = NULL_POINTER;
    void** cm = NULL_POINTER;
    void** cmc = NULL_POINTER;
    void** cms = NULL_POINTER;
    void** cd = NULL_POINTER;
    void** cdc = NULL_POINTER;
    void** cds = NULL_POINTER;

    // Get command.
    get_universal_compound_element_by_name(p0, p1,
        (void*) RUN_COMMAND_NAME, (void*) RUN_COMMAND_NAME_COUNT,
        (void*) &cn, (void*) &cnc, (void*) &cns,
        (void*) &ca, (void*) &cac, (void*) &cas,
        (void*) &cm, (void*) &cmc, (void*) &cms,
        (void*) &cd, (void*) &cdc, (void*) &cds,
        p2, p3);

    // The comparison result.
    int r = *NUMBER_0_INTEGER;

    if (r == *NUMBER_0_INTEGER) {

        compare_arrays(*cm, *cmc, (void*) RUN_PROGRAM_MODEL, (void*) RUN_PROGRAM_MODEL_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY);

        if (r != *NUMBER_0_INTEGER) {

            run_program(p0, p1, p2, p3);
        }
    }

    if (r == *NUMBER_0_INTEGER) {

        compare_arrays(*cm, *cmc, (void*) RUN_LIST_DIRECTORY_CONTENTS_MODEL, (void*) RUN_LIST_DIRECTORY_CONTENTS_MODEL_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY);

        if (r != *NUMBER_0_INTEGER) {

            run_list_directory_contents(p0, p1, p2, p3);
        }
    }

    if (r == *NUMBER_0_INTEGER) {

        compare_arrays(*cm, *cmc, (void*) RUN_COPY_MODEL, (void*) RUN_COPY_MODEL_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY);

        if (r != *NUMBER_0_INTEGER) {

            run_copy(p0, p1, p2, p3);
        }
    }

    if (r == *NUMBER_0_INTEGER) {

        compare_arrays(*cm, *cmc, (void*) RUN_ARCHIVE_MODEL, (void*) RUN_ARCHIVE_MODEL_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY);

        if (r != *NUMBER_0_INTEGER) {

            run_archive(p0, p1, p2, p3);
        }
    }

    if (r == *NUMBER_0_INTEGER) {

        log_terminated_message((void*) WARNING_LOG_LEVEL, (void*) L"Could not run command. The command model is unknown.");
    }
}

/* RUN_SOURCE */
#endif
