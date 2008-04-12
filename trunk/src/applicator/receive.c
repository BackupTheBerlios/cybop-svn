/*
 * $RCSfile: receive.c,v $
 *
 * Copyright (c) 1999-2007. Christian Heller and the CYBOP developers.
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
 * @version $Revision: 1.47 $ $Date: 2008-04-12 17:03:22 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef RECEIVE_SOURCE
#define RECEIVE_SOURCE

#include "../applicator/receive/receive_file_system.c"
#include "../applicator/receive/receive_latex.c"
#include "../applicator/receive/receive_gnu_linux_console.c"
#include "../applicator/receive/receive_socket.c"
#include "../applicator/receive/receive_x_window_system.c"
#include "../globals/constants/cybol/cybol_abstraction_constants.c"
#include "../globals/constants/cybol/cybol_channel_constants.c"
#include "../globals/constants/cybol/cybol_model_constants.c"
#include "../globals/constants/cybol/cybol_name_constants.c"
#include "../globals/constants/integer/integer_constants.c"
#include "../globals/constants/memory_structure/memory_structure_constants.c"
#include "../globals/constants/pointer/pointer_constants.c"
#include "../globals/logger/logger.c"
#include "../globals/variables/thread_identification_variables.c"
#include "../memoriser/accessor/compound_accessor.c"

/**
 * Receives a message via the given channel.
 *
 * @param p0 the internal memory
 * @param p1 the knowledge memory
 * @param p2 the knowledge memory count
 * @param p3 the model (Hand over as reference!)
 * @param p4 the model count (Hand over as reference!)
 * @param p5 the model size (Hand over as reference!)
 * @param p6 the details (Hand over as reference!)
 * @param p7 the details count (Hand over as reference!)
 * @param p8 the details size (Hand over as reference!)
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
void receive_with_parameters(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6,
    void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14, void* p15, void* p16,
    void* p17, void* p18, void* p19, void* p20, void* p21, void* p22, void* p23) {

    log_terminated_message((void*) DEBUG_LOG_LEVEL, (void*) "Receive message with given parameters.");

    // The comparison result.
    int r = *NUMBER_0_INTEGER;

    if (r == *NUMBER_0_INTEGER) {

        compare_arrays(p22, p23, (void*) FILE_SYSTEM_MODEL, (void*) FILE_SYSTEM_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != *NUMBER_0_INTEGER) {

            // Receive model by reading message data.
            //
            // CAUTION! The details are handed over as well, since sometimes,
            // they are read from the message together with the model, for
            // example when converting from a file in xdt format.
            receive_file_system(p3, p4, p5, p6, p7, p8, p14, p15, p18, p19);

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
            receive_file_system(p6, p7, p8, *NULL_POINTER, *NULL_POINTER, *NULL_POINTER, p16, p17, p18, p19);
        }
    }

    if (r == *NUMBER_0_INTEGER) {

        compare_arrays(p22, p23, (void*) GNU_LINUX_CONSOLE_MODEL, (void*) GNU_LINUX_CONSOLE_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != *NUMBER_0_INTEGER) {

            // The gnu/linux console input stream.
            void** is = NULL_POINTER;

            // Get gnu/linux console input stream.
            get_array_elements(p0, (void*) GNU_LINUX_CONSOLE_INPUT_FILE_DESCRIPTOR_INTERNAL, (void*) &is, (void*) POINTER_ARRAY);

            receive_gnu_linux_console(NULL_POINTER, NULL_POINTER, NULL_POINTER, NULL_POINTER, NULL_POINTER, NULL_POINTER, p3, p4, p5, p6, p7, p8, *is, p12, p13, p1, p2);
        }
    }

    if (r == *NUMBER_0_INTEGER) {

        compare_arrays(p22, p23, (void*) X_WINDOW_SYSTEM_MODEL, (void*) X_WINDOW_SYSTEM_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != *NUMBER_0_INTEGER) {

//??            receive_x_window_system(p0, p7, p8, p9, p10, p11, p12);
        }
    }

    if (r == *NUMBER_0_INTEGER) {

        compare_arrays(p22, p23, (void*) WWW_SERVICE_MODEL, (void*) WWW_SERVICE_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != *NUMBER_0_INTEGER) {

            // Receive model by reading http request or response.
            //
            // CAUTION! The details are handed over as well,
            // since they will store http headers as meta data.
//??            receive_socket(p0, (void*) WWW_BASE_INTERNAL, (void*) WWW_SERVICE_THREAD, (void*) &receive_socket_www, p1, p2, p3, p4, p5, p6, p10, p11, p17, p18, p19, p20);
        }
    }

    if (r == *NUMBER_0_INTEGER) {

        compare_arrays(p22, p23, (void*) CYBOI_SERVICE_MODEL, (void*) CYBOI_SERVICE_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != *NUMBER_0_INTEGER) {

            // Receive model by reading http request or response.
            //
            // CAUTION! The details are handed over as well,
            // since they will store http headers as meta data.
//??            receive_socket(p0, (void*) CYBOI_BASE_INTERNAL, (void*) CYBOI_SERVICE_THREAD, (void*) &receive_socket_cyboi, p1, p2, p3, p4, p5, p6, p10, p11, p17, p18, p19, p20);
        }
    }

    if (r == *NUMBER_0_INTEGER) {

        compare_arrays(p22, p23, (void*) LATEX_MODEL, (void*) LATEX_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != *NUMBER_0_INTEGER) {

//??            receive_latex(p0, p13, p14);
        }
    }

    if (r == *NUMBER_0_INTEGER) {

        log_terminated_message((void*) WARNING_LOG_LEVEL, (void*) "Could not receive message with given parameters. The channel model is unknown.");
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
 * @param p0 the parameters
 * @param p1 the parameters count
 * @param p2 the internal memory
 * @param p3 the knowledge memory
 * @param p4 the knowledge memory count
 * @param p5 the knowledge memory size
 */
void receive_message(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    log_terminated_message((void*) INFORMATION_LOG_LEVEL, (void*) "Receive message.");

    // The channel name, abstraction, model, details.
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
    // The language name, abstraction, model, details.
    void** ln = NULL_POINTER;
    void** lnc = NULL_POINTER;
    void** lns = NULL_POINTER;
    void** la = NULL_POINTER;
    void** lac = NULL_POINTER;
    void** las = NULL_POINTER;
    void** lm = NULL_POINTER;
    void** lmc = NULL_POINTER;
    void** lms = NULL_POINTER;
    void** ld = NULL_POINTER;
    void** ldc = NULL_POINTER;
    void** lds = NULL_POINTER;
    // The message name, abstraction, model, details.
    void** mn = NULL_POINTER;
    void** mnc = NULL_POINTER;
    void** mns = NULL_POINTER;
    void** ma = NULL_POINTER;
    void** mac = NULL_POINTER;
    void** mas = NULL_POINTER;
    void** mm = NULL_POINTER;
    void** mmc = NULL_POINTER;
    void** mms = NULL_POINTER;
    void** md = NULL_POINTER;
    void** mdc = NULL_POINTER;
    void** mds = NULL_POINTER;
    // The meta message name, abstraction, model, details.
    void** men = NULL_POINTER;
    void** menc = NULL_POINTER;
    void** mens = NULL_POINTER;
    void** mea = NULL_POINTER;
    void** meac = NULL_POINTER;
    void** meas = NULL_POINTER;
    void** mem = NULL_POINTER;
    void** memc = NULL_POINTER;
    void** mems = NULL_POINTER;
    void** med = NULL_POINTER;
    void** medc = NULL_POINTER;
    void** meds = NULL_POINTER;
    // The model name, abstraction, model, details.
    void** mon = NULL_POINTER;
    void** monc = NULL_POINTER;
    void** mons = NULL_POINTER;
    void** moa = NULL_POINTER;
    void** moac = NULL_POINTER;
    void** moas = NULL_POINTER;
    void** mom = NULL_POINTER;
    void** momc = NULL_POINTER;
    void** moms = NULL_POINTER;
    void** mod = NULL_POINTER;
    void** modc = NULL_POINTER;
    void** mods = NULL_POINTER;
    // The root name, abstraction, model, details.
    void** rn = NULL_POINTER;
    void** rnc = NULL_POINTER;
    void** rns = NULL_POINTER;
    void** ra = NULL_POINTER;
    void** rac = NULL_POINTER;
    void** ras = NULL_POINTER;
    void** rm = NULL_POINTER;
    void** rmc = NULL_POINTER;
    void** rms = NULL_POINTER;
    void** rd = NULL_POINTER;
    void** rdc = NULL_POINTER;
    void** rds = NULL_POINTER;
    // The socket communication style name, abstraction, model, details.
    void** stn = NULL_POINTER;
    void** stnc = NULL_POINTER;
    void** stns = NULL_POINTER;
    void** sta = NULL_POINTER;
    void** stac = NULL_POINTER;
    void** stas = NULL_POINTER;
    void** stm = NULL_POINTER;
    void** stmc = NULL_POINTER;
    void** stms = NULL_POINTER;
    void** std = NULL_POINTER;
    void** stdc = NULL_POINTER;
    void** stds = NULL_POINTER;
    // The commands name, abstraction, model, details.
    void** con = NULL_POINTER;
    void** conc = NULL_POINTER;
    void** cons = NULL_POINTER;
    void** coa = NULL_POINTER;
    void** coac = NULL_POINTER;
    void** coas = NULL_POINTER;
    void** com = NULL_POINTER;
    void** comc = NULL_POINTER;
    void** coms = NULL_POINTER;
    void** cod = NULL_POINTER;
    void** codc = NULL_POINTER;
    void** cods = NULL_POINTER;
    // The blocking name, abstraction, model, details.
    void** bn = NULL_POINTER;
    void** bnc = NULL_POINTER;
    void** bns = NULL_POINTER;
    void** ba = NULL_POINTER;
    void** bac = NULL_POINTER;
    void** bas = NULL_POINTER;
    void** bm = NULL_POINTER;
    void** bmc = NULL_POINTER;
    void** bms = NULL_POINTER;
    void** bd = NULL_POINTER;
    void** bdc = NULL_POINTER;
    void** bds = NULL_POINTER;

    // Get channel.
    get_universal_compound_element_by_name(p0, p1,
        (void*) RECEIVE_CHANNEL_NAME, (void*) RECEIVE_CHANNEL_NAME_COUNT,
        (void*) &cn, (void*) &cnc, (void*) &cns,
        (void*) &ca, (void*) &cac, (void*) &cas,
        (void*) &cm, (void*) &cmc, (void*) &cms,
        (void*) &cd, (void*) &cdc, (void*) &cds,
        p3, p4);

    // Get language.
    get_universal_compound_element_by_name(p0, p1,
        (void*) RECEIVE_LANGUAGE_NAME, (void*) RECEIVE_LANGUAGE_NAME_COUNT,
        (void*) &ln, (void*) &lnc, (void*) &lns,
        (void*) &la, (void*) &lac, (void*) &las,
        (void*) &lm, (void*) &lmc, (void*) &lms,
        (void*) &ld, (void*) &ldc, (void*) &lds,
        p3, p4);

    // Get message.
    get_universal_compound_element_by_name(p0, p1,
        (void*) RECEIVE_MESSAGE_NAME, (void*) RECEIVE_MESSAGE_NAME_COUNT,
        (void*) &mn, (void*) &mnc, (void*) &mns,
        (void*) &ma, (void*) &mac, (void*) &mas,
        (void*) &mm, (void*) &mmc, (void*) &mms,
        (void*) &md, (void*) &mdc, (void*) &mds,
        p3, p4);

    // Get meta message.
    get_universal_compound_element_by_name(p0, p1,
        (void*) RECEIVE_META_NAME, (void*) RECEIVE_META_NAME_COUNT,
        (void*) &men, (void*) &menc, (void*) &mens,
        (void*) &mea, (void*) &meac, (void*) &meas,
        (void*) &mem, (void*) &memc, (void*) &mems,
        (void*) &med, (void*) &medc, (void*) &meds,
        p3, p4);

    // Get model.
    get_universal_compound_element_by_name(p0, p1,
        (void*) RECEIVE_MODEL_NAME, (void*) RECEIVE_MODEL_NAME_COUNT,
        (void*) &mon, (void*) &monc, (void*) &mons,
        (void*) &moa, (void*) &moac, (void*) &moas,
        (void*) &mom, (void*) &momc, (void*) &moms,
        (void*) &mod, (void*) &modc, (void*) &mods,
        p3, p4);

    // Get root.
    get_universal_compound_element_by_name(p0, p1,
        (void*) RECEIVE_ROOT_NAME, (void*) RECEIVE_ROOT_NAME_COUNT,
        (void*) &rn, (void*) &rnc, (void*) &rns,
        (void*) &ra, (void*) &rac, (void*) &ras,
        (void*) &rm, (void*) &rmc, (void*) &rms,
        (void*) &rd, (void*) &rdc, (void*) &rds,
        p3, p4);

    // Get socket communication style.
    get_universal_compound_element_by_name(p0, p1,
        (void*) RECEIVE_STYLE_NAME, (void*) RECEIVE_STYLE_NAME_COUNT,
        (void*) &stn, (void*) &stnc, (void*) &stns,
        (void*) &sta, (void*) &stac, (void*) &stas,
        (void*) &stm, (void*) &stmc, (void*) &stms,
        (void*) &std, (void*) &stdc, (void*) &stds,
        p3, p4);

    // Get commands.
    get_universal_compound_element_by_name(p0, p1,
        (void*) RECEIVE_COMMANDS_NAME, (void*) RECEIVE_COMMANDS_NAME_COUNT,
        (void*) &con, (void*) &conc, (void*) &cons,
        (void*) &coa, (void*) &coac, (void*) &coas,
        (void*) &com, (void*) &comc, (void*) &coms,
        (void*) &cod, (void*) &codc, (void*) &cods,
        p3, p4);

    // Get blocking.
    get_universal_compound_element_by_name(p0, p1,
        (void*) RECEIVE_BLOCKING_NAME, (void*) RECEIVE_BLOCKING_NAME_COUNT,
        (void*) &bn, (void*) &bnc, (void*) &bns,
        (void*) &ba, (void*) &bac, (void*) &bas,
        (void*) &bm, (void*) &bmc, (void*) &bms,
        (void*) &bd, (void*) &bdc, (void*) &bds,
        p3, p4);

    // Receive data using the parameters determined above.
    receive_with_parameters(p2, p3, p4, (void*) mom, *momc, *moms, (void*) mod, *modc, *mods, *rm, *rmc, *rms,
        *com, *comc, *coms, *mm, *mmc, *mem, *memc, *lm, *lmc, (void*) stm, (void*) stmc, *cm, *cmc);
}

/* RECEIVE_SOURCE */
#endif
