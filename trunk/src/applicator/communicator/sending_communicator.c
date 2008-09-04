/*
 * Copyright (C) 1999-2008. Christian Heller.
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
 * @version $RCSfile: sending_communicator.c,v $ $Revision: 1.2 $ $Date: 2008-09-04 20:31:29 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef SENDER_SOURCE
#define SENDER_SOURCE

#include "../applicator/sender/cyboi_system_sender.c"
#include "../applicator/sender/file_system_sender.c"
#include "../applicator/sender/latex_sender.c"
#include "../applicator/sender/gnu_linux_console_sender.c"
#include "../applicator/sender/shell_sender.c"
#include "../applicator/sender/socket_sender.c"
#include "../applicator/sender/x_window_system_sender.c"
#include "../globals/constants/cyboi/cyboi_signal_priority_constants.c"
#include "../constant/abstraction/cybol/text_cybol_abstraction.c"
#include "../constant/channel/cybol_channel.c"
#include "../globals/constants/cybol/cybol_model_constants.c"
#include "../globals/constants/cybol/cybol_name_constants.c"
#include "../constant/model/memory/integer_memory_model.c"
#include "../constant/abstraction/memory/memory_abstraction.c"
#include "../constant/model/memory/pointer_memory_model.c"
#include "../globals/constants/service_port_constants.c"
#include "../logger/logger.c"
#include "../memoriser/accessor/compound_accessor.c"
#include "../memoriser/accessor/internal_memory_accessor.c"
#include "../memoriser/allocator.c"

/**
 * Sends a message in a special language.
 *
 * CAUTION! Do NOT rename this procedure to "send",
 * as that name is already used by socket functionality.
 *
 * Expected parameters:
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
 * @param p0 the parameters
 * @param p1 the parameters count
 * @param p2 the internal memory
 * @param p3 the knowledge memory
 * @param p4 the knowledge memory count
 * @param p5 the knowledge memory size
 * @param p6 the signal memory
 * @param p7 the signal memory count
 * @param p8 the signal memory size
 * @param p9 the signal identification (Hand over as reference!)
 */
void send_message(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Send message.");

    // The channel name, abstraction, model, details.
    void** cn = NULL_POINTER_MEMORY_MODEL;
    void** cnc = NULL_POINTER_MEMORY_MODEL;
    void** cns = NULL_POINTER_MEMORY_MODEL;
    void** ca = NULL_POINTER_MEMORY_MODEL;
    void** cac = NULL_POINTER_MEMORY_MODEL;
    void** cas = NULL_POINTER_MEMORY_MODEL;
    void** cm = NULL_POINTER_MEMORY_MODEL;
    void** cmc = NULL_POINTER_MEMORY_MODEL;
    void** cms = NULL_POINTER_MEMORY_MODEL;
    void** cd = NULL_POINTER_MEMORY_MODEL;
    void** cdc = NULL_POINTER_MEMORY_MODEL;
    void** cds = NULL_POINTER_MEMORY_MODEL;
    // The language name, abstraction, model, details.
    void** ln = NULL_POINTER_MEMORY_MODEL;
    void** lnc = NULL_POINTER_MEMORY_MODEL;
    void** lns = NULL_POINTER_MEMORY_MODEL;
    void** la = NULL_POINTER_MEMORY_MODEL;
    void** lac = NULL_POINTER_MEMORY_MODEL;
    void** las = NULL_POINTER_MEMORY_MODEL;
    void** lm = NULL_POINTER_MEMORY_MODEL;
    void** lmc = NULL_POINTER_MEMORY_MODEL;
    void** lms = NULL_POINTER_MEMORY_MODEL;
    void** ld = NULL_POINTER_MEMORY_MODEL;
    void** ldc = NULL_POINTER_MEMORY_MODEL;
    void** lds = NULL_POINTER_MEMORY_MODEL;
    // The communication mode name, abstraction, model, details.
    void** mon = NULL_POINTER_MEMORY_MODEL;
    void** monc = NULL_POINTER_MEMORY_MODEL;
    void** mons = NULL_POINTER_MEMORY_MODEL;
    void** moa = NULL_POINTER_MEMORY_MODEL;
    void** moac = NULL_POINTER_MEMORY_MODEL;
    void** moas = NULL_POINTER_MEMORY_MODEL;
    void** mom = NULL_POINTER_MEMORY_MODEL;
    void** momc = NULL_POINTER_MEMORY_MODEL;
    void** moms = NULL_POINTER_MEMORY_MODEL;
    void** mod = NULL_POINTER_MEMORY_MODEL;
    void** modc = NULL_POINTER_MEMORY_MODEL;
    void** mods = NULL_POINTER_MEMORY_MODEL;
    // The socket namespace name, abstraction, model, details.
    void** nn = NULL_POINTER_MEMORY_MODEL;
    void** nnc = NULL_POINTER_MEMORY_MODEL;
    void** nns = NULL_POINTER_MEMORY_MODEL;
    void** na = NULL_POINTER_MEMORY_MODEL;
    void** nac = NULL_POINTER_MEMORY_MODEL;
    void** nas = NULL_POINTER_MEMORY_MODEL;
    void** nm = NULL_POINTER_MEMORY_MODEL;
    void** nmc = NULL_POINTER_MEMORY_MODEL;
    void** nms = NULL_POINTER_MEMORY_MODEL;
    void** nd = NULL_POINTER_MEMORY_MODEL;
    void** ndc = NULL_POINTER_MEMORY_MODEL;
    void** nds = NULL_POINTER_MEMORY_MODEL;
    // The communication style name, abstraction, model, details.
    void** stn = NULL_POINTER_MEMORY_MODEL;
    void** stnc = NULL_POINTER_MEMORY_MODEL;
    void** stns = NULL_POINTER_MEMORY_MODEL;
    void** sta = NULL_POINTER_MEMORY_MODEL;
    void** stac = NULL_POINTER_MEMORY_MODEL;
    void** stas = NULL_POINTER_MEMORY_MODEL;
    void** stm = NULL_POINTER_MEMORY_MODEL;
    void** stmc = NULL_POINTER_MEMORY_MODEL;
    void** stms = NULL_POINTER_MEMORY_MODEL;
    void** std = NULL_POINTER_MEMORY_MODEL;
    void** stdc = NULL_POINTER_MEMORY_MODEL;
    void** stds = NULL_POINTER_MEMORY_MODEL;
    // The sender name, abstraction, model, details.
    void** sn = NULL_POINTER_MEMORY_MODEL;
    void** snc = NULL_POINTER_MEMORY_MODEL;
    void** sns = NULL_POINTER_MEMORY_MODEL;
    void** sa = NULL_POINTER_MEMORY_MODEL;
    void** sac = NULL_POINTER_MEMORY_MODEL;
    void** sas = NULL_POINTER_MEMORY_MODEL;
    void** sm = NULL_POINTER_MEMORY_MODEL;
    void** smc = NULL_POINTER_MEMORY_MODEL;
    void** sms = NULL_POINTER_MEMORY_MODEL;
    void** sd = NULL_POINTER_MEMORY_MODEL;
    void** sdc = NULL_POINTER_MEMORY_MODEL;
    void** sds = NULL_POINTER_MEMORY_MODEL;
    // The receiver name, abstraction, model, details.
    void** rn = NULL_POINTER_MEMORY_MODEL;
    void** rnc = NULL_POINTER_MEMORY_MODEL;
    void** rns = NULL_POINTER_MEMORY_MODEL;
    void** ra = NULL_POINTER_MEMORY_MODEL;
    void** rac = NULL_POINTER_MEMORY_MODEL;
    void** ras = NULL_POINTER_MEMORY_MODEL;
    void** rm = NULL_POINTER_MEMORY_MODEL;
    void** rmc = NULL_POINTER_MEMORY_MODEL;
    void** rms = NULL_POINTER_MEMORY_MODEL;
    void** rd = NULL_POINTER_MEMORY_MODEL;
    void** rdc = NULL_POINTER_MEMORY_MODEL;
    void** rds = NULL_POINTER_MEMORY_MODEL;
    // The message name, abstraction, model, details.
    void** mn = NULL_POINTER_MEMORY_MODEL;
    void** mnc = NULL_POINTER_MEMORY_MODEL;
    void** mns = NULL_POINTER_MEMORY_MODEL;
    void** ma = NULL_POINTER_MEMORY_MODEL;
    void** mac = NULL_POINTER_MEMORY_MODEL;
    void** mas = NULL_POINTER_MEMORY_MODEL;
    void** mm = NULL_POINTER_MEMORY_MODEL;
    void** mmc = NULL_POINTER_MEMORY_MODEL;
    void** mms = NULL_POINTER_MEMORY_MODEL;
    void** md = NULL_POINTER_MEMORY_MODEL;
    void** mdc = NULL_POINTER_MEMORY_MODEL;
    void** mds = NULL_POINTER_MEMORY_MODEL;
    // The area name, abstraction, model, details.
    void** an = NULL_POINTER_MEMORY_MODEL;
    void** anc = NULL_POINTER_MEMORY_MODEL;
    void** ans = NULL_POINTER_MEMORY_MODEL;
    void** aa = NULL_POINTER_MEMORY_MODEL;
    void** aac = NULL_POINTER_MEMORY_MODEL;
    void** aas = NULL_POINTER_MEMORY_MODEL;
    void** am = NULL_POINTER_MEMORY_MODEL;
    void** amc = NULL_POINTER_MEMORY_MODEL;
    void** ams = NULL_POINTER_MEMORY_MODEL;
    void** ad = NULL_POINTER_MEMORY_MODEL;
    void** adc = NULL_POINTER_MEMORY_MODEL;
    void** ads = NULL_POINTER_MEMORY_MODEL;
    // The clean name, abstraction, model, details.
    void** cln = NULL_POINTER_MEMORY_MODEL;
    void** clnc = NULL_POINTER_MEMORY_MODEL;
    void** clns = NULL_POINTER_MEMORY_MODEL;
    void** cla = NULL_POINTER_MEMORY_MODEL;
    void** clac = NULL_POINTER_MEMORY_MODEL;
    void** clas = NULL_POINTER_MEMORY_MODEL;
    void** clm = NULL_POINTER_MEMORY_MODEL;
    void** clmc = NULL_POINTER_MEMORY_MODEL;
    void** clms = NULL_POINTER_MEMORY_MODEL;
    void** cld = NULL_POINTER_MEMORY_MODEL;
    void** cldc = NULL_POINTER_MEMORY_MODEL;
    void** clds = NULL_POINTER_MEMORY_MODEL;
    // The new line name, abstraction, model, details.
    void** nln = NULL_POINTER_MEMORY_MODEL;
    void** nlnc = NULL_POINTER_MEMORY_MODEL;
    void** nlns = NULL_POINTER_MEMORY_MODEL;
    void** nla = NULL_POINTER_MEMORY_MODEL;
    void** nlac = NULL_POINTER_MEMORY_MODEL;
    void** nlas = NULL_POINTER_MEMORY_MODEL;
    void** nlm = NULL_POINTER_MEMORY_MODEL;
    void** nlmc = NULL_POINTER_MEMORY_MODEL;
    void** nlms = NULL_POINTER_MEMORY_MODEL;
    void** nld = NULL_POINTER_MEMORY_MODEL;
    void** nldc = NULL_POINTER_MEMORY_MODEL;
    void** nlds = NULL_POINTER_MEMORY_MODEL;

    // Get channel.
    get_universal_compound_element_by_name(p0, p1,
        (void*) SEND_CHANNEL_NAME, (void*) SEND_CHANNEL_NAME_COUNT,
        (void*) &cn, (void*) &cnc, (void*) &cns,
        (void*) &ca, (void*) &cac, (void*) &cas,
        (void*) &cm, (void*) &cmc, (void*) &cms,
        (void*) &cd, (void*) &cdc, (void*) &cds,
        p3, p4);

    // Get language.
    get_universal_compound_element_by_name(p0, p1,
        (void*) SEND_LANGUAGE_NAME, (void*) SEND_LANGUAGE_NAME_COUNT,
        (void*) &ln, (void*) &lnc, (void*) &lns,
        (void*) &la, (void*) &lac, (void*) &las,
        (void*) &lm, (void*) &lmc, (void*) &lms,
        (void*) &ld, (void*) &ldc, (void*) &lds,
        p3, p4);

    // Get communication mode.
    get_universal_compound_element_by_name(p0, p1,
        (void*) SEND_COMMUNICATION_MODE_NAME, (void*) SEND_COMMUNICATION_MODE_NAME_COUNT,
        (void*) &mon, (void*) &monc, (void*) &mons,
        (void*) &moa, (void*) &moac, (void*) &moas,
        (void*) &mom, (void*) &momc, (void*) &moms,
        (void*) &mod, (void*) &modc, (void*) &mods,
        p3, p4);

    // Get socket namespace.
    get_universal_compound_element_by_name(p0, p1,
        (void*) SEND_NAMESPACE_NAME, (void*) SEND_NAMESPACE_NAME_COUNT,
        (void*) &nn, (void*) &nnc, (void*) &nns,
        (void*) &na, (void*) &nac, (void*) &nas,
        (void*) &nm, (void*) &nmc, (void*) &nms,
        (void*) &nd, (void*) &ndc, (void*) &nds,
        p3, p4);

    // Get communication style.
    get_universal_compound_element_by_name(p0, p1,
        (void*) SEND_STYLE_NAME, (void*) SEND_STYLE_NAME_COUNT,
        (void*) &stn, (void*) &stnc, (void*) &stns,
        (void*) &sta, (void*) &stac, (void*) &stas,
        (void*) &stm, (void*) &stmc, (void*) &stms,
        (void*) &std, (void*) &stdc, (void*) &stds,
        p3, p4);

    // Get sender.
    get_universal_compound_element_by_name(p0, p1,
        (void*) SEND_SENDER_NAME, (void*) SEND_SENDER_NAME_COUNT,
        (void*) &sn, (void*) &snc, (void*) &sns,
        (void*) &sa, (void*) &sac, (void*) &sas,
        (void*) &sm, (void*) &smc, (void*) &sms,
        (void*) &sd, (void*) &sdc, (void*) &sds,
        p3, p4);

    // Get receiver.
    get_universal_compound_element_by_name(p0, p1,
        (void*) SEND_RECEIVER_NAME, (void*) SEND_RECEIVER_NAME_COUNT,
        (void*) &rn, (void*) &rnc, (void*) &rns,
        (void*) &ra, (void*) &rac, (void*) &ras,
        (void*) &rm, (void*) &rmc, (void*) &rms,
        (void*) &rd, (void*) &rdc, (void*) &rds,
        p3, p4);

    // Get message.
    get_universal_compound_element_by_name(p0, p1,
        (void*) SEND_MESSAGE_NAME, (void*) SEND_MESSAGE_NAME_COUNT,
        (void*) &mn, (void*) &mnc, (void*) &mns,
        (void*) &ma, (void*) &mac, (void*) &mas,
        (void*) &mm, (void*) &mmc, (void*) &mms,
        (void*) &md, (void*) &mdc, (void*) &mds,
        p3, p4);

    // Get area.
    get_universal_compound_element_by_name(p0, p1,
        (void*) SEND_AREA_NAME, (void*) SEND_AREA_NAME_COUNT,
        (void*) &an, (void*) &anc, (void*) &ans,
        (void*) &aa, (void*) &aac, (void*) &aas,
        (void*) &am, (void*) &amc, (void*) &ams,
        (void*) &ad, (void*) &adc, (void*) &ads,
        p3, p4);

    // Get clean flag.
    get_universal_compound_element_by_name(p0, p1,
        (void*) SEND_CLEAN_NAME, (void*) SEND_CLEAN_NAME_COUNT,
        (void*) &cln, (void*) &clnc, (void*) &clns,
        (void*) &cla, (void*) &clac, (void*) &clas,
        (void*) &clm, (void*) &clmc, (void*) &clms,
        (void*) &cld, (void*) &cldc, (void*) &clds,
        p3, p4);

    // Get new line flag.
    get_universal_compound_element_by_name(p0, p1,
        (void*) SEND_NEW_LINE_NAME, (void*) SEND_NEW_LINE_NAME_COUNT,
        (void*) &nln, (void*) &nlnc, (void*) &nlns,
        (void*) &nla, (void*) &nlac, (void*) &nlas,
        (void*) &nlm, (void*) &nlmc, (void*) &nlms,
        (void*) &nld, (void*) &nldc, (void*) &nlds,
        p3, p4);

    // The comparison result.
    int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays((void*) *cm, (void*) *cmc, (void*) SIGNAL_MODEL, (void*) SIGNAL_MODEL_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            send_cyboi_system(p2, p6, p7, p8, ma, mac, mm, mmc, md, mdc, (void*) &NORMAL_CYBOI_SIGNAL_PRIORITY, p9);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays((void*) *cm, (void*) *cmc, (void*) FILE_SYSTEM_MODEL, (void*) FILE_SYSTEM_MODEL_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            send_file_system(p2, *mn, *mnc, *ma, *mac, *mm, *mmc, *md, *mdc, p3, p4, *lm, *lmc, *clm, *clmc, *rm, *rmc);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays((void*) *cm, (void*) *cmc, (void*) SHELL_MODEL, (void*) SHELL_MODEL_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            send_shell(p2, *ma, *mac, *mm, *mmc, *md, *mdc, p3, p4, *lm, *lmc, *clm, *clmc, *nlm, *nlmc);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays((void*) *cm, (void*) *cmc, (void*) GNU_LINUX_CONSOLE_MODEL, (void*) GNU_LINUX_CONSOLE_MODEL_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            send_gnu_linux_console(p2, *ma, *mac, *mm, *mmc, *md, *mdc, *am, *amc, *clm, *clmc, p3, p4);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays((void*) *cm, (void*) *cmc, (void*) X_WINDOW_SYSTEM_MODEL, (void*) X_WINDOW_SYSTEM_MODEL_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            send_x_window_system(p2, *mm, *mmc, p3, p4);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays((void*) *cm, (void*) *cmc, (void*) WWW_SERVICE_MODEL, (void*) WWW_SERVICE_MODEL_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            send_socket(p2, (void*) WWW_BASE_INTERNAL, *rm, *rmc, (void*) WWW_PORT, *nm, *nmc, *stm, *stmc, *mom, *momc, *ma, *mac, *mm, *mmc, *md, *mdc, p3, p4, *lm, *lmc);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays((void*) *cm, (void*) *cmc, (void*) CYBOI_SERVICE_MODEL, (void*) CYBOI_SERVICE_MODEL_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

//??            send_socket(p2, (void*) CYBOI_BASE_INTERNAL, *rm, *rmc, (void*) CYBOI_PORT, *nm, *nmc, *stm, *stmc, *mom, *momc, *ma, *mac, *mm, *mmc, *md, *mdc, p3, p4, *lm, *lmc);

            //?? TEST: For testing reasons, the p2 was replaced with p9 here!
            //?? The signal id serves as client socket to which this cyboi system has to reply.
            send_socket(p9, (void*) CYBOI_BASE_INTERNAL, *rm, *rmc, (void*) CYBOI_PORT, *nm, *nmc, *stm, *stmc, *mom, *momc, *ma, *mac, *mm, *mmc, *md, *mdc, p3, p4, *lm, *lmc);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays((void*) *cm, (void*) *cmc, (void*) LATEX_MODEL, (void*) LATEX_MODEL_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            send_latex(p2, *mm, *mmc, p3, p4);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        log_terminated_message((void*) WARNING_LEVEL_LOG_MODEL, (void*) L"Could not send message. The channel model is unknown.");
    }
}

/* SENDER_SOURCE */
#endif
