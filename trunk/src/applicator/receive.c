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
 * @version $Revision: 1.29 $ $Date: 2007-05-16 19:29:01 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef RECEIVE_SOURCE
#define RECEIVE_SOURCE

#include "../applicator/receive/receive_file_system.c"
#include "../applicator/receive/receive_latex.c"
#include "../applicator/receive/receive_linux_console.c"
#include "../applicator/receive/receive_socket.c"
#include "../applicator/receive/receive_x_window_system.c"
#include "../globals/constants/cybol/cybol_abstraction_constants.c"
#include "../globals/constants/cybol/cybol_channel_constants.c"
#include "../globals/constants/cybol/cybol_model_constants.c"
#include "../globals/constants/cybol/cybol_name_constants.c"
#include "../globals/constants/memory_structure/memory_structure_constants.c"
#include "../globals/constants/pointer/pointer_constants.c"
#include "../globals/logger/logger.c"
#include "../memoriser/accessor/compound_accessor.c"

/**
 * Receives a message in a special language.
 *
 * CAUTION! Do NOT rename this procedure to "receive",
 * as that name is already used by socket functionality.
 *
 * The signal waiting loop only catches cyboi internal signals.
 * In order to also catch signals of various devices,
 * special mechanisms for signal reception have to be started.
 * To the mechanisms belong:
 * - linux console
 * - x window system
 * - socket
 *
 * These have their own internal signal/ action/ event/ interrupt waiting loops
 * which get activated here, running as parallel services in separate threads.
 * Whenever an event occurs in one of these threads, it gets transformed into a
 * cyboi signal and is finally placed in cyboi's signal memory.
 *
 * TODO: Since many internal waiting loops run in parallel,
 * the adding of signals to the signal memory must be synchronized!
 * How to do this properly in C?
 *
 * Expected parameters:
 * - channel: linux_console, tcp_socket, unix_socket, x_window_system
 * - root: dot-separated name to the root window knowledge model of the graphical user interface (gui)
 * - commands: dot-separated name of commands knowledge model
 * - blocking: true, false
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
 */
void receive_message(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5,
    void* p6, void* p7, void* p8) {

    log_message_debug("Receive message.");

    // The name name, abstraction, model, details.
    void** nn = NULL_POINTER;
    void** nnc = NULL_POINTER;
    void** nns = NULL_POINTER;
    void** na = NULL_POINTER;
    void** nac = NULL_POINTER;
    void** nas = NULL_POINTER;
    void** nm = NULL_POINTER;
    void** nmc = NULL_POINTER;
    void** nms = NULL_POINTER;
    void** nd = NULL_POINTER;
    void** ndc = NULL_POINTER;
    void** nds = NULL_POINTER;
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
    // The abstraction name, abstraction, model, details.
    void** an = NULL_POINTER;
    void** anc = NULL_POINTER;
    void** ans = NULL_POINTER;
    void** aa = NULL_POINTER;
    void** aac = NULL_POINTER;
    void** aas = NULL_POINTER;
    void** am = NULL_POINTER;
    void** amc = NULL_POINTER;
    void** ams = NULL_POINTER;
    void** ad = NULL_POINTER;
    void** adc = NULL_POINTER;
    void** ads = NULL_POINTER;
    // The model name, abstraction, model, details.
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
    // The element name, abstraction, model, details.
    void** en = NULL_POINTER;
    void** enc = NULL_POINTER;
    void** ens = NULL_POINTER;
    void** ea = NULL_POINTER;
    void** eac = NULL_POINTER;
    void** eas = NULL_POINTER;
    void** em = NULL_POINTER;
    void** emc = NULL_POINTER;
    void** ems = NULL_POINTER;
    void** ed = NULL_POINTER;
    void** edc = NULL_POINTER;
    void** eds = NULL_POINTER;
    // The whole name, abstraction, model, details.
    void** wn = NULL_POINTER;
    void** wnc = NULL_POINTER;
    void** wns = NULL_POINTER;
    void** wa = NULL_POINTER;
    void** wac = NULL_POINTER;
    void** was = NULL_POINTER;
    void** wm = NULL_POINTER;
    void** wmc = NULL_POINTER;
    void** wms = NULL_POINTER;
    void** wd = NULL_POINTER;
    void** wdc = NULL_POINTER;
    void** wds = NULL_POINTER;
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

    // Get name.
    get_universal_compound_element_by_name(p0, p1,
        (void*) CREATE_NAME_NAME, (void*) CREATE_NAME_NAME_COUNT,
        (void*) &nn, (void*) &nnc, (void*) &nns,
        (void*) &na, (void*) &nac, (void*) &nas,
        (void*) &nm, (void*) &nmc, (void*) &nms,
        (void*) &nd, (void*) &ndc, (void*) &nds,
        p3, p4);

    // Get channel.
    get_universal_compound_element_by_name(p0, p1,
        (void*) CREATE_CHANNEL_NAME, (void*) CREATE_CHANNEL_NAME_COUNT,
        (void*) &cn, (void*) &cnc, (void*) &cns,
        (void*) &ca, (void*) &cac, (void*) &cas,
        (void*) &cm, (void*) &cmc, (void*) &cms,
        (void*) &cd, (void*) &cdc, (void*) &cds,
        p3, p4);

    // Get abstraction.
    get_universal_compound_element_by_name(p0, p1,
        (void*) CREATE_ABSTRACTION_NAME, (void*) CREATE_ABSTRACTION_NAME_COUNT,
        (void*) &an, (void*) &anc, (void*) &ans,
        (void*) &aa, (void*) &aac, (void*) &aas,
        (void*) &am, (void*) &amc, (void*) &ams,
        (void*) &ad, (void*) &adc, (void*) &ads,
        p3, p4);

    // Get model.
    get_universal_compound_element_by_name(p0, p1,
        (void*) CREATE_MODEL_NAME, (void*) CREATE_MODEL_NAME_COUNT,
        (void*) &mn, (void*) &mnc, (void*) &mns,
        (void*) &ma, (void*) &mac, (void*) &mas,
        (void*) &mm, (void*) &mmc, (void*) &mms,
        (void*) &md, (void*) &mdc, (void*) &mds,
        p3, p4);

    // Get element.
    get_universal_compound_element_by_name(p0, p1,
        (void*) CREATE_ELEMENT_NAME, (void*) CREATE_ELEMENT_NAME_COUNT,
        (void*) &en, (void*) &enc, (void*) &ens,
        (void*) &ea, (void*) &eac, (void*) &eas,
        (void*) &em, (void*) &emc, (void*) &ems,
        (void*) &ed, (void*) &edc, (void*) &eds,
        p3, p4);

    // Get whole.
    get_universal_compound_element_by_name(p0, p1,
        (void*) CREATE_WHOLE_NAME, (void*) CREATE_WHOLE_NAME_COUNT,
        (void*) &wn, (void*) &wnc, (void*) &wns,
        (void*) &wa, (void*) &wac, (void*) &was,
        (void*) &wm, (void*) &wmc, (void*) &wms,
        (void*) &wd, (void*) &wdc, (void*) &wds,
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

    // The comparison result.
    int r = 0;

    if (r == 0) {

        compare_arrays((void*) *cm, (void*) *cmc, (void*) FILE_SYSTEM_MODEL, (void*) FILE_SYSTEM_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            receive_file_system(p3, p4, p5, *wm, *wmc, *wms, *wd, *wdc, *wds,
                *nm, *nmc, *na, *nac, *am, *amc, *aa, *aac, *cm, *cmc, *mm, *mmc, *em, *emc);
        }
    }

    if (r == 0) {

        compare_arrays((void*) *cm, (void*) *cmc, (void*) LINUX_CONSOLE_MODEL, (void*) LINUX_CONSOLE_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            receive_linux_console(p2, *com, *comc, *coms);
        }
    }

    if (r == 0) {

        compare_arrays((void*) *cm, (void*) *cmc, (void*) X_WINDOW_SYSTEM_MODEL, (void*) X_WINDOW_SYSTEM_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            receive_x_window_system(p2, *rm, *rmc, *rms, *com, *comc, *coms);
        }
    }

    if (r == 0) {

        compare_arrays((void*) *cm, (void*) *cmc, (void*) WWW_SERVICE_MODEL, (void*) WWW_SERVICE_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            receive_socket(p2, *com, *comc, *stm, *stmc, (void*) WWW_BASE_INTERNAL, (void*) &receive_socket_thread_www, (void*) WWW_SERVICE_THREAD);
        }
    }

    if (r == 0) {

        compare_arrays((void*) *cm, (void*) *cmc, (void*) CYBOI_SERVICE_MODEL, (void*) CYBOI_SERVICE_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            receive_socket(p2, *com, *comc, *stm, *stmc, (void*) CYBOI_BASE_INTERNAL, (void*) &receive_socket_thread_cyboi, (void*) CYBOI_SERVICE_THREAD);
        }
    }

    if (r == 0) {

        compare_arrays((void*) *cm, (void*) *cmc, (void*) LATEX_MODEL, (void*) LATEX_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

//??            receive_latex(p2, *mm, *mmc);
        }
    }
}

/* RECEIVE_SOURCE */
#endif
