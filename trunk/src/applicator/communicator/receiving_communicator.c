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
 * @version $RCSfile: receiving_communicator.c,v $ $Revision: 1.14 $ $Date: 2009-02-08 13:04:30 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef RECEIVING_COMMUNICATOR_SOURCE
#define RECEIVING_COMMUNICATOR_SOURCE

#include "../../applicator/communicator/receiving/file_system_receiving_communicator.c"
#include "../../applicator/communicator/receiving/gnu_linux_console_receiving_communicator.c"
#include "../../applicator/communicator/receiving/inline_receiving_communicator.c"
#include "../../applicator/communicator/receiving/latex_receiving_communicator.c"
#include "../../applicator/communicator/receiving/socket_receiving_communicator.c"
#include "../../applicator/communicator/receiving/x_window_system_receiving_communicator.c"
#include "../../constant/abstraction/cybol/text_cybol_abstraction.c"
#include "../../constant/abstraction/memory/memory_abstraction.c"
#include "../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../constant/abstraction/operation/primitive_operation_abstraction.c"
#include "../../constant/channel/cybol_channel.c"
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../constant/name/cybol/operation/communication/receive_communication_operation_cybol_name.c"
#include "../../constant/name/memory/internal_memory_memory_name.c"
#include "../../executor/modifier/getter/knowledge_part_getter.c"
#include "../../logger/logger.c"
#include "../../variable/thread_identification.c"

/**
 * Receives a message via the given channel.
 *
 * @param p0 the internal memory
 * @param p1 the knowledge memory
 * @param p2 the knowledge memory count
 * @param p3 the model (Hand over as reference!)
 * @param p4 the model count
 * @param p5 the model size
 * @param p6 the details (Hand over as reference!)
 * @param p7 the details count
 * @param p8 the details size
 * @param p9 the root
 * @param p10 the root count
 * @param p11 the root size
 * @param p12 the commands
 * @param p13 the commands count
 * @param p14 the message
 * @param p15 the message count
 * @param p16 the meta message
 * @param p17 the meta message count
 * @param p18 the language
 * @param p19 the language count
 * @param p20 the socket communication style
 * @param p21 the socket communication style count
 * @param p22 the channel
 * @param p23 the channel count
 */
void communicate_receiving_with_parameters(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6,
    void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14, void* p15, void* p16,
    void* p17, void* p18, void* p19, void* p20, void* p21, void* p22, void* p23) {

    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Receive message with given parameters.");

    // The comparison result.
    int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, p22, (void*) CYBOI_CYBOL_CHANNEL, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p23, (void*) CYBOI_CYBOL_CHANNEL_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            // The base internal.
            int base = *CYBOI_BASE_INTERNAL_MEMORY_MEMORY_NAME;
            // The internal memory index.
            int i = *NUMBER_MINUS_1_INTEGER_MEMORY_MODEL;
            // The communication partner-connected socket of this system.
            void** ps = NULL_POINTER_MEMORY_MODEL;

            // Get communication partner-connected socket of this system.
            i = base + *SOCKET_COMMUNICATION_PARTNER_INTERNAL_MEMORY_MEMORY_NAME;
            get((void*) &ps, p0, (void*) &i, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);

    fwprintf(stdout, L"TEST ps: %i \n", *((int*) *ps));

            // Receive model by reading http request or response.
            //
            // CAUTION! The details are handed over as well,
            // since they will store http headers as meta data.
            communicate_receiving_socket(p3, p4, p5, p6, p7, p8, *ps, p20, p21, p18, p19, p1, p2);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, p22, (void*) FILE_CYBOL_CHANNEL, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p23, (void*) FILE_CYBOL_CHANNEL_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            // Receive model by reading message data.
            //
            // CAUTION! The details are handed over as well, since sometimes,
            // they are read from the message together with the model, for
            // example when converting from a file in xdt format.
            communicate_receiving_file_system(p3, p4, p5, p6, p7, p8, p14, p15, p18, p19);

            // Receive details by reading meta message data.
            //
            // CAUTION! Sometimes, the details are read from a different source than the
            // model, for example the html attributes of an html table when creating a wui.
            //
            // Example:
            // <part name="receive_table_row" channel="inline" abstraction="operation" model="receive">
            //     <property name="channel" channel="inline" abstraction="character" model="file"/>
            //     <property name="language" channel="inline" abstraction="character" model="compound"/>
            //     <property name="message" channel="inline" abstraction="character" model="residenz/wui/address_table_row.cybol"/>
            //     <property name="meta" channel="inline" abstraction="character" model="residenz/wui/address_table_row_properties.cybol"/>
            //     <property name="model" channel="inline" abstraction="encapsulated" model=".residenz.temporary.translation.translate_record_to_wui.wui_patient_row"/>
            // </part>
//??            communicate_receiving_file_system(p6, p7, p8, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, p16, p17, p18, p19);

            //?? CAUTION! The function call above was commented out ON PURPOSE, since it caused a runtime error!
            //?? TODO: Figure out what happens inside, before uncommenting it again!
            //?? For the "inline" channel, this function call was commented out as well, as it is never needed.
            //?? For the "file" channel, however, it will be needed sometimes, for example for
            //?? xdt or html or http (if remembered correctly). Just figure this out later, when needed.
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, p22, (void*) GNU_LINUX_CONSOLE_CYBOL_CHANNEL, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p23, (void*) GNU_LINUX_CONSOLE_CYBOL_CHANNEL_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            // The gnu/linux console mutex.
            void** mt = NULL_POINTER_MEMORY_MODEL;
            // The gnu/linux console input stream.
            void** is = NULL_POINTER_MEMORY_MODEL;

            // Get gnu/linux console mutex.
            get((void*) &mt, p0, (void*) GNU_LINUX_CONSOLE_MUTEX_INTERNAL_MEMORY_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);
            // Get gnu/linux console input stream.
            get((void*) &is, p0, (void*) GNU_LINUX_CONSOLE_INPUT_FILE_DESCRIPTOR_INTERNAL_MEMORY_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);

            communicate_receiving_gnu_linux_console(NULL_POINTER_MEMORY_MODEL, NULL_POINTER_MEMORY_MODEL, NULL_POINTER_MEMORY_MODEL,
                NULL_POINTER_MEMORY_MODEL, NULL_POINTER_MEMORY_MODEL, NULL_POINTER_MEMORY_MODEL,
                p3, p4, p5, p6, p7, p8, *is, p12, p13, p1, p2, *mt);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, p22, (void*) INLINE_CYBOL_CHANNEL, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p23, (void*) INLINE_CYBOL_CHANNEL_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            // Receive model by reading message data.
            //
            // CAUTION! The details are handed over as well, since sometimes,
            // they are read from the message together with the model, for
            // example when converting from a file in xdt format.
            communicate_receiving_inline(p3, p4, p5, p6, p7, p8, p14, p15, p18, p19);

            // CAUTION! Do NOT try to receive meta data here!
            // When calling the following function:
            // communicate_receiving_inline(p6, p7, p8, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, p16, p17, p18, p19);
            // for some unclear reason the destination array is replaced and returned as null,
            // if source data do not exist. The normal behaviour, however, would be that
            // the destination array is left untouched if the source data are empty.
            // This has probably something to do with the function "replace_wide_character_vector",
            // but is this unclear.
            // It has not been investigated further, since inline data receiving does not
            // use meta data anyway, so that this will probably never be needed.
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, p22, (void*) LATEX_CYBOL_CHANNEL, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p23, (void*) LATEX_CYBOL_CHANNEL_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

//??            communicate_receiving_latex(p0, p13, p14);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, p22, (void*) WWW_CYBOL_CHANNEL, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p23, (void*) WWW_CYBOL_CHANNEL_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            // Receive model by reading http request or response.
            //
            // CAUTION! The details are handed over as well,
            // since they will store http headers as meta data.
//??            communicate_receiving_socket(p0, (void*) WWW_BASE_INTERNAL_MEMORY_MEMORY_NAME, (void*) WWW_SERVICE_THREAD, (void*) &receive_socket_www, p1, p2, p3, p4, p5, p6, p10, p11, p17, p18, p19, p20);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, p22, (void*) X_WINDOW_SYSTEM_CYBOL_CHANNEL, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p23, (void*) X_WINDOW_SYSTEM_CYBOL_CHANNEL_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

//??            communicate_receiving_x_window_system(p0, p7, p8, p9, p10, p11, p12);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        log_terminated_message((void*) WARNING_LEVEL_LOG_MODEL, (void*) L"Could not receive message with given parameters. The channel model is unknown.");
    }
}

/**
 * Receives a message via the given channel.
 *
 * CAUTION! Do NOT rename this procedure to "receive",
 * as that name is already used by low-level socket functionality.
 *
 * The persistent message gets converted into a transient model, residing in memory.
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
 * CAUTION! Some file formats (like the German xDT format for medical data exchange)
 * contain both, the model AND the details, in one file. To cover these cases,
 * the model and details are received TOGETHER, in just one operation.
 *
 * Some receive functions do not just read a persistent message, but first wait for
 * an external signal. In order to catch signals of various devices, special mechanisms
 * for signal reception have to be started. To the mechanisms belong:
 * - gnu/linux console
 * - x window system
 * - socket
 *
 * These have their own internal signal/ action/ event/ interrupt waiting loops
 * which get activated here, running as parallel services in separate threads.
 * Whenever an event occurs in one of these threads, it gets transformed into a
 * cyboi-internal signal and is finally placed in cyboi's signal memory.
 * The cyboi signal waiting loop only catches cyboi-internal signals.
 *
 * Expected parameters:
 * - channel (required): the channel via which to receive the message (gnu_linux_console, www, x_window_system etc.)
 * - language (required): the language (abstraction, type, structure) of the data received (http_request, xdt, boolean, character etc.)
 * - message (required): the source (knowledge template) from where to receive data
 * - meta message (optional): the source (knowledge template) from where to receive meta data (details)
 * - model (required): the compound model to be filled with the data received
 * - details (required): the compound details to be filled with the data received
 * - root (required): the knowledge model that will serve as the root
 * - style (optional, only if channel is www, cyboi or similar): the style of socket communication
 * - DELETE LATER (commands are now added directly as signal to signal memory):
 *   commands (optional, only if a user interface thread is to react to certain commands):
 *   the knowledge model containing the commands that the user interface should react to
 * - DELETE LATER (reception is always non-blocking in cyboi; if wished, the service may be interrupted):
 *   blocking (optional, only if channel is www, cyboi or similar): the flag indicating whether the receive process should be blocking
 *
 * @param p0 the parametres
 * @param p1 the parametres count
 * @param p2 the knowledge memory part
 * @param p3 the internal memory array
 */
void communicate_receiving(void* p0, void* p1, void* p2, void* p3) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Receive message.");

    // The channel part.
    void* c = *NULL_POINTER_MEMORY_MODEL;
    // The language part.
    void* l = *NULL_POINTER_MEMORY_MODEL;
    // The message part.
    void* m = *NULL_POINTER_MEMORY_MODEL;
    // The meta message part.
    void* me = *NULL_POINTER_MEMORY_MODEL;
    // The model part.
    void* mo = *NULL_POINTER_MEMORY_MODEL;
    // The root part.
    void* r = *NULL_POINTER_MEMORY_MODEL;
    // The socket communication style part.
    void* st = *NULL_POINTER_MEMORY_MODEL;
    // The commands part.
    void* co = *NULL_POINTER_MEMORY_MODEL;
/*??
    // The blocking part.
    void* b = *NULL_POINTER_MEMORY_MODEL;
*/

    // Get channel part.
    get_part_knowledge((void*) &c, p0, (void*) CHANNEL_RECEIVE_COMMUNICATION_OPERATION_CYBOL_NAME, (void*) CHANNEL_RECEIVE_COMMUNICATION_OPERATION_CYBOL_NAME_COUNT, p2);
    // Get language part.
    get_part_knowledge((void*) &l, p0, (void*) LANGUAGE_RECEIVE_COMMUNICATION_OPERATION_CYBOL_NAME, (void*) LANGUAGE_RECEIVE_COMMUNICATION_OPERATION_CYBOL_NAME_COUNT, p2);
    // Get message part.
    get_part_knowledge((void*) &m, p0, (void*) MESSAGE_RECEIVE_COMMUNICATION_OPERATION_CYBOL_NAME, (void*) MESSAGE_RECEIVE_COMMUNICATION_OPERATION_CYBOL_NAME_COUNT, p2);
    // Get meta message part.
    get_part_knowledge((void*) &me, p0, (void*) META_RECEIVE_COMMUNICATION_OPERATION_CYBOL_NAME, (void*) META_RECEIVE_COMMUNICATION_OPERATION_CYBOL_NAME_COUNT, p2);
    // Get model part.
    get_part_knowledge((void*) &mo, p0, (void*) MODEL_RECEIVE_COMMUNICATION_OPERATION_CYBOL_NAME, (void*) MODEL_RECEIVE_COMMUNICATION_OPERATION_CYBOL_NAME_COUNT, p2);
    // Get root part.
    get_part_knowledge((void*) &r, p0, (void*) ROOT_RECEIVE_COMMUNICATION_OPERATION_CYBOL_NAME, (void*) ROOT_RECEIVE_COMMUNICATION_OPERATION_CYBOL_NAME_COUNT, p2);
    // Get socket communication style part.
    get_part_knowledge((void*) &st, p0, (void*) STYLE_RECEIVE_COMMUNICATION_OPERATION_CYBOL_NAME, (void*) STYLE_RECEIVE_COMMUNICATION_OPERATION_CYBOL_NAME_COUNT, p2);
    // Get commands part.
    get_part_knowledge((void*) &co, p0, (void*) COMMANDS_RECEIVE_COMMUNICATION_OPERATION_CYBOL_NAME, (void*) COMMANDS_RECEIVE_COMMUNICATION_OPERATION_CYBOL_NAME_COUNT, p2);
/*??
    // Get blocking part.
    get_part_knowledge((void*) &b, p0, (void*) BLOCKING_RECEIVE_COMMUNICATION_OPERATION_CYBOL_NAME, (void*) BLOCKING_RECEIVE_COMMUNICATION_OPERATION_CYBOL_NAME_COUNT, p2);
*/

    // Receive data using the parameters determined above.
    communicate_receiving_with_parameters(p2, p3, p4, (void*) mom, *momc, *moms, (void*) mod, *modc, *mods,
        *rm, *rmc, *rms, *com, *comc, *mm, *mmc, *mem, *memc, *lm, *lmc, *stm, *stmc, *cm, *cmc);

/*??
//?? TEST BEGIN
    // The model diagram.
    void* md = *NULL_POINTER_MEMORY_MODEL;
    int mdc = *NUMBER_0_INTEGER_MEMORY_MODEL;
    int mds = *NUMBER_0_INTEGER_MEMORY_MODEL;
    // Allocate model diagram.
    allocate((void*) &md, (void*) &mds, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT);
    // Encode model into model diagram.
    encode_model_diagram((void*) &md, (void*) &mdc, (void*) &mds,
        *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, (void*) COMPOUND_MEMORY_ABSTRACTION, (void*) COMPOUND_MEMORY_ABSTRACTION_COUNT,
        p3, p4, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL);
    // The multibyte character stream.
    void* mb = *NULL_POINTER_MEMORY_MODEL;
    int mbc = *NUMBER_0_INTEGER_MEMORY_MODEL;
    int mbs = *NUMBER_0_INTEGER_MEMORY_MODEL;
    // Allocate multibyte character stream.
    allocate((void*) &mb, (void*) &mbs, (void*) CHARACTER_MEMORY_ABSTRACTION, (void*) CHARACTER_MEMORY_ABSTRACTION_COUNT);
    // Encode model diagram into multibyte character stream.
    encode_utf_8_unicode_character_vector((void*) &mb, (void*) &mbc, (void*) &mbs, md, (void*) &mdc);
    // The file name.
    void* fn = L"TEST_RECEIVING_COMMUNICATOR.txt";
    int fnc = *NUMBER_27_INTEGER_MEMORY_MODEL;
    int fns = *NUMBER_28_INTEGER_MEMORY_MODEL;
    // Write multibyte character stream as message to file system.
    send_file((void*) &fn, (void*) &fnc, (void*) &fns, mb, (void*) &mbc);
    // Deallocate model diagram.
    deallocate((void*) &md, (void*) &mds, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT);
    // Deallocate multibyte character stream.
    deallocate((void*) &mb, (void*) &mbs, (void*) CHARACTER_MEMORY_ABSTRACTION, (void*) CHARACTER_MEMORY_ABSTRACTION_COUNT);
//?? TEST END
*/
}

/* RECEIVING_COMMUNICATOR_SOURCE */
#endif
