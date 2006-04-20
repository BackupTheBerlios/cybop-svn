/*
 * $RCSfile: run.c,v $
 *
 * Copyright (c) 1999-2006. Christian Heller and the CYBOP developers.
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
 * @version $Revision: 1.3 $ $Date: 2006-04-20 22:36:09 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef RUN_SOURCE
#define RUN_SOURCE

#include "../applicator/run/run_archive.c"
#include "../applicator/run/run_copy.c"
#include "../applicator/run/run_list_directory_contents.c"
#include "../applicator/run/run_program.c"
#include "../globals/constants/abstraction_constants.c"
#include "../globals/constants/log_constants.c"
#include "../globals/constants/model_constants.c"
#include "../globals/constants/name_constants.c"
#include "../globals/logger/logger.c"
#include "../globals/variables/variables.c"

/**
 * Runs a command as a shell command.
 *
 * Expected parameters:
 * - command: list_directory_contents, ...
 *
 * @param p0 the parameters
 * @param p1 the parameters count
 * @param p2 the internal memory
 * @param p3 the knowledge memory
 * @param p4 the knowledge memory count
 * @param p5 the knowledge memory size
 * @param p6 the signal memory
 * @param p7 the signal memory count
 * @param p8 the signal memory size
 * @param p9 the signal id
 */
void run(void* p0, void* p1) {

    log_message_debug("Run a command.");

    // The command abstraction.
    void** ca = &NULL_POINTER;
    void** cac = &NULL_POINTER;
    void** cas = &NULL_POINTER;
    // The command model.
    void** cm = &NULL_POINTER;
    void** cmc = &NULL_POINTER;
    void** cms = &NULL_POINTER;
    // The command details.
    void** cd = &NULL_POINTER;
    void** cdc = &NULL_POINTER;
    void** cds = &NULL_POINTER;

    // Get command.
    get_compound_element_by_name(p0, p1,
        (void*) RUN_COMMAND_NAME, (void*) RUN_COMMAND_NAME_COUNT,
        (void*) &ca, (void*) &cac, (void*) &cas,
        (void*) &cm, (void*) &cmc, (void*) &cms,
        (void*) &cd, (void*) &cdc, (void*) &cds);

    // The comparison result.
    int r = 0;

    if (r == 0) {

        compare_arrays(*cm, *cmc, (void*) RUN_PROGRAM_MODEL, (void*) RUN_PROGRAM_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            run_program(p0, p1);
        }
    }

    if (r == 0) {

        compare_arrays(*cm, *cmc, (void*) RUN_LIST_DIRECTORY_CONTENTS_MODEL, (void*) RUN_LIST_DIRECTORY_CONTENTS_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            run_list_directory_contents(p0, p1);
        }
    }

    if (r == 0) {

        compare_arrays(*cm, *cmc, (void*) RUN_COPY_MODEL, (void*) RUN_COPY_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            run_copy(p0, p1);
        }
    }

    if (r == 0) {

        compare_arrays(*cm, *cmc, (void*) RUN_ARCHIVE_MODEL, (void*) RUN_ARCHIVE_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            run_archive(p0, p1);
        }
    }
}

/* RUN_SOURCE */
#endif
