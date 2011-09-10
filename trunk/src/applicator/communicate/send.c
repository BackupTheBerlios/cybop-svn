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
 * @version $RCSfile: sending_communicator.c,v $ $Revision: 1.10 $ $Date: 2009-01-31 16:06:29 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef SEND_SOURCE
#define SEND_SOURCE

#include "../../applicator/communicator/sending/cyboi_system_sending_communicator.c"
#include "../../applicator/communicator/sending/file_system_sending_communicator.c"
#include "../../applicator/communicator/sending/gnu_linux_console_sending_communicator.c"
#include "../../applicator/communicator/sending/inline_sending_communicator.c"
#include "../../applicator/communicator/sending/latex_sending_communicator.c"
#include "../../applicator/communicator/sending/shell_sending_communicator.c"
#include "../../applicator/communicator/sending/socket_sending_communicator.c"
#include "../../applicator/communicator/sending/x_window_system_sending_communicator.c"
#include "../../constant/abstraction/cybol/text_cybol_abstraction.c"
#include "../../constant/abstraction/memory/memory_abstraction.c"
#include "../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../constant/abstraction/operation/primitive_operation_abstraction.c"
#include "../../constant/channel/cybol_channel.c"
#include "../../constant/model/cybol/service_cybol_model.c"
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../constant/model/service_port_model.c"
#include "../../constant/model/signal_priority_model.c"
#include "../../constant/name/cybol/operation/communication/send_communication_operation_cybol_name.c"
#include "../../executor/accessor/getter/array_getter.c"
#include "../../executor/accessor/getter/compound_getter.c"
#include "../../executor/memoriser/allocator.c"
#include "../../logger/logger.c"

/**
 * Sends a message in a special language.
 *
 * CAUTION! Do NOT rename this procedure to "send",
 * as that name is already used by socket functionality.
 *
 * Expected parametres:
 * - channel (required): the channel via which to send the message (e.g. http)
 * - language (required): the language into which to encode the message before sending it (e.g. html)
 * - mode (optional, only if channel is http): the mode of communication
 * - namespace (optional, only if channel is http): the namespace of the socket
 * - style (optional, only if channel is http): the style of communication
 * - receiver (required): the name of the system receiving the message
 * - message (required): the actual message to be sent to another system
 * - area (optional, only if language is tui or gui): the user interface area to be repainted
 * - clean (optional, only if language is tui): the flag indicating whether or not to clear the screen before painting a user interface
 * - new_line (optional, only if channel is standard_output/ shell): the flag indicating whether or not to add a new line after having printed the message on screen
 *
 * @param p0 the parametres array (signal/ operation part details with pointers referencing parts)
 * @param p1 the parametres array count
 * @param p2 the knowledge memory part
 * @param p3 the internal memory array
 */
void apply_send(void* p0, void* p1, void* p2, void* p3) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Apply send.");

    // The channel part.
    void* c = *NULL_POINTER_MEMORY_MODEL;
    // The language part.
    void* l = *NULL_POINTER_MEMORY_MODEL;
    // The communication mode part.
    void* mo = *NULL_POINTER_MEMORY_MODEL;
    // The socket namespace part.
    void* n = *NULL_POINTER_MEMORY_MODEL;
    // The socket communication style part.
    void* st = *NULL_POINTER_MEMORY_MODEL;
    // The receiver part.
    void* r = *NULL_POINTER_MEMORY_MODEL;
    // The message part.
    void* m = *NULL_POINTER_MEMORY_MODEL;
    // The metadata part.
    void* me = *NULL_POINTER_MEMORY_MODEL;
    // The area part.
    void* a = *NULL_POINTER_MEMORY_MODEL;
    // The clean part.
    void* cl = *NULL_POINTER_MEMORY_MODEL;
    // The new line part.
    void* nl = *NULL_POINTER_MEMORY_MODEL;

    // The channel part model.
    void* cm = *NULL_POINTER_MEMORY_MODEL;

    // The channel part model data.
    void* cmd = *NULL_POINTER_MEMORY_MODEL;

    // Get channel part.
    get_name_array((void*) &c, p0, (void*) CHANNEL_SEND_COMMUNICATION_OPERATION_CYBOL_NAME, (void*) CHANNEL_SEND_COMMUNICATION_OPERATION_CYBOL_NAME_COUNT, p1);
    // Get language part.
    get_name_array((void*) &l, p0, (void*) LANGUAGE_SEND_COMMUNICATION_OPERATION_CYBOL_NAME, (void*) LANGUAGE_SEND_COMMUNICATION_OPERATION_CYBOL_NAME_COUNT, p1);
    // Get communication mode part.
    get_name_array((void*) &mo, p0, (void*) MODE_SEND_COMMUNICATION_OPERATION_CYBOL_NAME, (void*) MODE_SEND_COMMUNICATION_OPERATION_CYBOL_NAME_COUNT, p1);
    // Get socket namespace part.
    get_name_array((void*) &n, p0, (void*) NAMESPACE_SEND_COMMUNICATION_OPERATION_CYBOL_NAME, (void*) NAMESPACE_SEND_COMMUNICATION_OPERATION_CYBOL_NAME_COUNT, p1);
    // Get socket communication style part.
    get_name_array((void*) &st, p0, (void*) STYLE_SEND_COMMUNICATION_OPERATION_CYBOL_NAME, (void*) STYLE_SEND_COMMUNICATION_OPERATION_CYBOL_NAME_COUNT, p1);
    // Get receiver part.
    get_name_array((void*) &r, p0, (void*) RECEIVER_SEND_COMMUNICATION_OPERATION_CYBOL_NAME, (void*) RECEIVER_SEND_COMMUNICATION_OPERATION_CYBOL_NAME_COUNT, p1);
    // Get message part.
    get_name_array((void*) &m, p0, (void*) MESSAGE_SEND_COMMUNICATION_OPERATION_CYBOL_NAME, (void*) MESSAGE_SEND_COMMUNICATION_OPERATION_CYBOL_NAME_COUNT, p1);
    // Get metadata part.
    get_name_array((void*) &me, p0, (void*) METADATA_SEND_COMMUNICATION_OPERATION_CYBOL_NAME, (void*) METADATA_SEND_COMMUNICATION_OPERATION_CYBOL_NAME_COUNT, p1);
    // Get area part.
    get_name_array((void*) &a, p0, (void*) AREA_SEND_COMMUNICATION_OPERATION_CYBOL_NAME, (void*) AREA_SEND_COMMUNICATION_OPERATION_CYBOL_NAME_COUNT, p1);
    // Get clean flag part.
    get_name_array((void*) &cl, p0, (void*) CLEAN_SEND_COMMUNICATION_OPERATION_CYBOL_NAME, (void*) CLEAN_SEND_COMMUNICATION_OPERATION_CYBOL_NAME_COUNT, p1);
    // Get new line part.
    get_name_array((void*) &nl, p0, (void*) NEW_LINE_SEND_COMMUNICATION_OPERATION_CYBOL_NAME, (void*) NEW_LINE_SEND_COMMUNICATION_OPERATION_CYBOL_NAME_COUNT, p1);

    // Get channel part model.
    copy_array_forward((void*) &cm, c, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) MODEL_PART_MEMORY_NAME);

    // Get channel part model data.
    copy_array_forward((void*) &cmd, cm, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) DATA_ITEM_MEMORY_NAME);

    // The comparison result.
    int r = *FALSE_BOOLEAN_MEMORY_MODEL;

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_integer_equal((void*) &r, cmd, (void*) CYBOI_CYBOL_CHANNEL);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            send_socket(p2, (void*) CYBOI_BASE_INTERNAL_MEMORY_MEMORY_NAME, *rm, *rmc, (void*) TCP_CYBOI_SERVICE_PORT_MODEL, *nm, *nmc, *stm, *stmc, *mom, *momc, *ma, *mac, *mm, *mmc, *md, *mdc, p3, p4, *lm, *lmc);
        }
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_integer_equal((void*) &r, cmd, (void*) FILE_SYSTEM_CYBOL_CHANNEL);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            send_file_system(p2, *mn, *mnc, *ma, *mac, *mm, *mmc, *md, *mdc, p3, p4, *lm, *lmc, *clm, *clmc, *rm, *rmc);
        }
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_integer_equal((void*) &r, cmd, (void*) GNU_LINUX_CONSOLE_CYBOL_CHANNEL);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            send_gnu_linux_console(p2, *ma, *mac, *mm, *mmc, *md, *mdc, *am, *amc, *clm, *clmc, p3, p4);
        }
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_integer_equal((void*) &r, cmd, (void*) INLINE_CYBOL_CHANNEL);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            // CAUTION! Hand over first parameter as reference!
            send_inline(rm, *rmc, *rms, *ma, *mac, *mm, *mmc, *md, *mdc, *mda, *mdac, *mdm, *mdmc, *mdd, *mddc, *lm, *lmc);
        }
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_integer_equal((void*) &r, cmd, (void*) LATEX_CYBOL_CHANNEL);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            send_latex(p2, *mm, *mmc, p3, p4);
        }
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_integer_equal((void*) &r, cmd, (void*) SHELL_CYBOL_CHANNEL);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

/*??
    fwprintf(stdout, L"TEST sending mmc: %i\n", *mmc);
    fwprintf(stdout, L"TEST sending *mmc: %i\n", *((int*) *mmc));
    fwprintf(stdout, L"TEST sending mm: %ls\n", (wchar_t*) *mm);
*/

            send_shell(p2, *ma, *mac, *mm, *mmc, *md, *mdc, p3, p4, *lm, *lmc, *clm, *clmc, *nlm, *nlmc);
        }
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_integer_equal((void*) &r, cmd, (void*) SIGNAL_SERVICE_CYBOL_MODEL);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            send_cyboi_system(p2, p6, p7, p8, ma, mac, mm, mmc, md, mdc, (void*) &NORMAL_SIGNAL_PRIORITY_MODEL, p9);
        }
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_integer_equal((void*) &r, cmd, (void*) WWW_CYBOL_CHANNEL);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            send_socket(p2, (void*) WWW_BASE_INTERNAL_MEMORY_MEMORY_NAME, *rm, *rmc, (void*) TCP_WWW_SERVICE_PORT_MODEL, *nm, *nmc, *stm, *stmc, *mom, *momc, *ma, *mac, *mm, *mmc, *md, *mdc, p3, p4, *lm, *lmc);
        }
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_integer_equal((void*) &r, cmd, (void*) X_WINDOW_SYSTEM_CYBOL_CHANNEL);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            send_x_window_system(p2, *mm, *mmc, p3, p4);
        }
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        log_terminated_message((void*) WARNING_LEVEL_LOG_MODEL, (void*) L"Could not apply send. The channel model is unknown.");
    }
}

/* SEND_SOURCE */
#endif
