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

#ifndef RECEIVE_SOURCE
#define RECEIVE_SOURCE

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
 * the model AND details are received TOGETHER, in just one operation.
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
 *
 * @param p0 the parametres array (signal/ operation part details with pointers referencing parts)
 * @param p1 the parametres array count
 * @param p2 the knowledge memory part
 * @param p3 the internal memory array
 */
void apply_receive(void* p0, void* p1, void* p2, void* p3) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Apply receive.");

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

    // The channel part model.
    void* cm = *NULL_POINTER_MEMORY_MODEL;
    // The language part model.
    void* lm = *NULL_POINTER_MEMORY_MODEL;
    // The message part model.
    void* mm = *NULL_POINTER_MEMORY_MODEL;
    // The meta message part model.
    void* mem = *NULL_POINTER_MEMORY_MODEL;
    // The model part model, details.
    void* mom = *NULL_POINTER_MEMORY_MODEL;
    void* mod = *NULL_POINTER_MEMORY_MODEL;
    // The root part model.
    void* rm = *NULL_POINTER_MEMORY_MODEL;
    // The socket communication style part model.
    void* stm = *NULL_POINTER_MEMORY_MODEL;

    // The channel part model data, count.
    void* cmd = *NULL_POINTER_MEMORY_MODEL;
    void* cmc = *NULL_POINTER_MEMORY_MODEL;
    // The language part model data, count.
    void* lmd = *NULL_POINTER_MEMORY_MODEL;
    void* lmc = *NULL_POINTER_MEMORY_MODEL;
    // The message part model data, count.
    void* mmd = *NULL_POINTER_MEMORY_MODEL;
    void* mmc = *NULL_POINTER_MEMORY_MODEL;
    // The meta message part model data, count.
    void* memd = *NULL_POINTER_MEMORY_MODEL;
    void* memc = *NULL_POINTER_MEMORY_MODEL;
    // The model part model data, count.
    void* momd = *NULL_POINTER_MEMORY_MODEL;
    void* momc = *NULL_POINTER_MEMORY_MODEL;
    // The model part details data, count.
    void* modd = *NULL_POINTER_MEMORY_MODEL;
    void* modc = *NULL_POINTER_MEMORY_MODEL;
    // The root part model data, count.
    void* rmd = *NULL_POINTER_MEMORY_MODEL;
    void* rmc = *NULL_POINTER_MEMORY_MODEL;
    // The socket communication style part model data, count.
    void* stmd = *NULL_POINTER_MEMORY_MODEL;
    void* stmc = *NULL_POINTER_MEMORY_MODEL;

    // Get channel part.
    get_name_array((void*) &c, p0, (void*) CHANNEL_RECEIVE_COMMUNICATION_OPERATION_CYBOL_NAME, (void*) CHANNEL_RECEIVE_COMMUNICATION_OPERATION_CYBOL_NAME_COUNT, p1);
    // Get language part.
    get_name_array((void*) &l, p0, (void*) LANGUAGE_RECEIVE_COMMUNICATION_OPERATION_CYBOL_NAME, (void*) LANGUAGE_RECEIVE_COMMUNICATION_OPERATION_CYBOL_NAME_COUNT, p1);
    // Get message part.
    get_name_array((void*) &m, p0, (void*) MESSAGE_RECEIVE_COMMUNICATION_OPERATION_CYBOL_NAME, (void*) MESSAGE_RECEIVE_COMMUNICATION_OPERATION_CYBOL_NAME_COUNT, p1);
    // Get meta message part.
    get_name_array((void*) &me, p0, (void*) META_RECEIVE_COMMUNICATION_OPERATION_CYBOL_NAME, (void*) META_RECEIVE_COMMUNICATION_OPERATION_CYBOL_NAME_COUNT, p1);
    // Get model part.
    get_name_array((void*) &mo, p0, (void*) MODEL_RECEIVE_COMMUNICATION_OPERATION_CYBOL_NAME, (void*) MODEL_RECEIVE_COMMUNICATION_OPERATION_CYBOL_NAME_COUNT, p1);
    // Get root part.
    get_name_array((void*) &r, p0, (void*) ROOT_RECEIVE_COMMUNICATION_OPERATION_CYBOL_NAME, (void*) ROOT_RECEIVE_COMMUNICATION_OPERATION_CYBOL_NAME_COUNT, p1);
    // Get socket communication style part.
    get_name_array((void*) &st, p0, (void*) STYLE_RECEIVE_COMMUNICATION_OPERATION_CYBOL_NAME, (void*) STYLE_RECEIVE_COMMUNICATION_OPERATION_CYBOL_NAME_COUNT, p1);

    // Get channel part model.
    copy_array_forward((void*) &cm, c, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) MODEL_PART_MEMORY_NAME);
    // Get language part model.
    copy_array_forward((void*) &lm, l, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) MODEL_PART_MEMORY_NAME);
    // Get message part model.
    copy_array_forward((void*) &mm, m, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) MODEL_PART_MEMORY_NAME);
    // Get meta message part model.
    copy_array_forward((void*) &mem, me, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) MODEL_PART_MEMORY_NAME);
    // Get model part model, details.
    copy_array_forward((void*) &mom, mo, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) MODEL_PART_MEMORY_NAME);
    copy_array_forward((void*) &mod, mo, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) DETAILS_PART_MEMORY_NAME);
    // Get root part model.
    copy_array_forward((void*) &rm, r, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) MODEL_PART_MEMORY_NAME);
    // Get socket communication style part model.
    copy_array_forward((void*) &stm, st, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) MODEL_PART_MEMORY_NAME);

    // Get channel part model data, count.
    copy_array_forward((void*) &cmd, cm, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) DATA_ITEM_MEMORY_NAME);
    copy_array_forward((void*) &cmc, cm, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) COUNT_ITEM_MEMORY_NAME);
    // Get language part model data, count.
    copy_array_forward((void*) &lmd, lm, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) DATA_ITEM_MEMORY_NAME);
    copy_array_forward((void*) &lmc, lm, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) COUNT_ITEM_MEMORY_NAME);
    // Get message part model data, count.
    copy_array_forward((void*) &mmd, mm, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) DATA_ITEM_MEMORY_NAME);
    copy_array_forward((void*) &mmc, mm, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) COUNT_ITEM_MEMORY_NAME);
    // Get meta message part model data, count.
    copy_array_forward((void*) &memd, mem, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) DATA_ITEM_MEMORY_NAME);
    copy_array_forward((void*) &memc, mem, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) COUNT_ITEM_MEMORY_NAME);
    // Get model part model data, count.
    copy_array_forward((void*) &momd, mom, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) DATA_ITEM_MEMORY_NAME);
    copy_array_forward((void*) &momc, mom, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) COUNT_ITEM_MEMORY_NAME);
    // Get model part details data, count.
    copy_array_forward((void*) &modd, mod, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) DATA_ITEM_MEMORY_NAME);
    copy_array_forward((void*) &modc, mod, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) COUNT_ITEM_MEMORY_NAME);
    // Get root part model data, count.
    copy_array_forward((void*) &rmd, rm, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) DATA_ITEM_MEMORY_NAME);
    copy_array_forward((void*) &rmc, rm, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) COUNT_ITEM_MEMORY_NAME);
    // Get socket communication style part model data, count.
    copy_array_forward((void*) &stmd, stm, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) DATA_ITEM_MEMORY_NAME);
    copy_array_forward((void*) &stmc, stm, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) COUNT_ITEM_MEMORY_NAME);

    // The comparison result.
    int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, cmd, (void*) CYBOI_CYBOL_CHANNEL, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, cmc, (void*) CYBOI_CYBOL_CHANNEL_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

/*??
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
            apply_receive_socket((void*) &momd, momc, moms, (void*) &modd, modc, mods, *ps, p20, p21, p18, p19, p1, p2);
*/
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, cmd, (void*) FILE_SYSTEM_CYBOL_CHANNEL, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, cmc, (void*) FILE_SYSTEM_CYBOL_CHANNEL_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {
        
            // Receive model by reading message data.
            //
            // CAUTION! The details are handed over as well, since sometimes,
            // they are read from the message together with the model, for
            // example when converting from a file in xdt format.
            apply_receive_file_system((void*) &momd, momc, moms, (void*) &modd, modc, mods, mmd, mmc, lmd, lmc);

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
//??            apply_receive_file_system((void*) &modd, modc, mods, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, mmd, mmc, lmd, lmc);

            //?? CAUTION! The function call above was commented out ON PURPOSE, since it caused a runtime error!
            //?? TODO: Figure out what happens inside, before uncommenting it again!
            //?? For the "inline" channel, this function call was commented out as well, as it is never needed.
            //?? For the "file" channel, however, it will be needed sometimes, for example for
            //?? xdt or html or http (if remembered correctly). Just figure this out later, when needed.
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, cmd, (void*) GNU_LINUX_CONSOLE_CYBOL_CHANNEL, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, cmc, (void*) GNU_LINUX_CONSOLE_CYBOL_CHANNEL_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

/*??
            // The gnu/linux console mutex.
            void** mt = NULL_POINTER_MEMORY_MODEL;
            // The gnu/linux console input stream.
            void** is = NULL_POINTER_MEMORY_MODEL;

            // Get gnu/linux console mutex.
            get((void*) &mt, p0, (void*) GNU_LINUX_CONSOLE_MUTEX_INTERNAL_MEMORY_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);
            // Get gnu/linux console input stream.
            get((void*) &is, p0, (void*) GNU_LINUX_CONSOLE_INPUT_FILE_DESCRIPTOR_INTERNAL_MEMORY_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);

            apply_receive_gnu_linux_console((void*) &momd, momc, moms, (void*) &modd, modc, mods, *is, p12, p13, p1, p2, *mt);
*/
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, cmd, (void*) INLINE_CYBOL_CHANNEL, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, cmc, (void*) INLINE_CYBOL_CHANNEL_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            // Receive model by reading message data.
            //
            // CAUTION! The details are handed over as well, since sometimes,
            // they are read from the message together with the model, for
            // example when converting from a file in xdt format.
            apply_receive_inline((void*) &momd, momc, moms, (void*) &modd, modc, mods, mmd, mmc, lmd, lmc);

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

        compare_all_array((void*) &r, cmd, (void*) WWW_CYBOL_CHANNEL, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, cmc, (void*) WWW_CYBOL_CHANNEL_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {
        
            // Receive model by reading http request or response.
            //
            // CAUTION! The details are handed over as well,
            // since they will store http headers as meta data.
//??            apply_receive_socket((void*) &momd, momc, moms, (void*) &modd, modc, mods, (void*) WWW_BASE_INTERNAL_MEMORY_MEMORY_NAME, (void*) WWW_SERVICE_THREAD, (void*) &receive_socket_www, p1, p2, p3, p4, p5, p6, p10, p11, p17, p18, p19, p20);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, cmd, (void*) X_WINDOW_SYSTEM_CYBOL_CHANNEL, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, cmc, (void*) X_WINDOW_SYSTEM_CYBOL_CHANNEL_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

//??            apply_receive_x_window_system((void*) &p0, p7, p8, p9, p10, p11, p12);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        log_terminated_message((void*) WARNING_LEVEL_LOG_MODEL, (void*) L"Could not apply receive. The channel model is unknown.");
    }

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

/* RECEIVE_SOURCE */
#endif
