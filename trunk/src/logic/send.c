/*
 * $RCSfile: send.c,v $
 *
 * Copyright (c) 1999-2005. Christian Heller. All rights reserved.
 *
 * This software is published under the GPL GNU General Public License.
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
 * @version $Revision: 1.18 $ $Date: 2005-03-20 01:43:34 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 * @author Rolf Holzmueller <rolf.holzmueller@gmx.de>
 */

#ifndef SEND_SOURCE
#define SEND_SOURCE

#include "../communicator/tui_communicator.c"
#include "../communicator/tcp_socket_communicator.c"
#include "../creator/integer_creator.c"
#include "../global/abstraction_constants.c"
#include "../global/channel_constants.c"
#include "../global/name_constants.c"
#include "../global/structure_constants.c"
#include "../logger/logger.c"
#include "../socket/unix_socket.c"
#include "../translator/translator.c"
#include "../web/socket_number_accessor.c"

//?? TEMPORARY TESTING
#include "../x_windows/x_windows.c"
#include "../x_windows/x_windows_handler.c"

/**
 * Sends a message in a special language.
 *
 * CAUTION! Do NOT rename this procedure to "send",
 * as that name is already used by socket functionality.
 *
 * Expected parameters:
 * - language (channel): internal, tui, gui, socket, http
 * - sender (who): ip address, socket port
 * - receiver (whom): ip address, socket port
 * - message (what): knowledge model to be sent in serialized form
 *
 * @param p0 the parameters
 * @param p1 the parameters count
 * @param p2 the knowledge
 * @param p3 the knowledge count
 * @param p4 the knowledge size
 * @param p5 the signal id
 * @param p6 the internals
 */
void send_message(const void* p0, const void* p1,
    const void* p2, const void* p3, const void* p4, const void* p5, void* p6) {

    // The language abstraction.
    void** la = NULL_POINTER;
    void** lac = NULL_POINTER;
    void** las = NULL_POINTER;
    // The language model.
    void** lm = NULL_POINTER;
    void** lmc = NULL_POINTER;
    void** lms = NULL_POINTER;
    // The language details.
    void** ld = NULL_POINTER;
    void** ldc = NULL_POINTER;
    void** lds = NULL_POINTER;

    // The sender abstraction.
    void** sa = NULL_POINTER;
    void** sac = NULL_POINTER;
    void** sas = NULL_POINTER;
    // The sender model.
    void** sm = NULL_POINTER;
    void** smc = NULL_POINTER;
    void** sms = NULL_POINTER;
    // The sender details.
    void** sd = NULL_POINTER;
    void** sdc = NULL_POINTER;
    void** sds = NULL_POINTER;

    // The receiver abstraction.
    void** ra = NULL_POINTER;
    void** rac = NULL_POINTER;
    void** ras = NULL_POINTER;
    // The receiver model.
    void** rm = NULL_POINTER;
    void** rmc = NULL_POINTER;
    void** rms = NULL_POINTER;
    // The receiver details.
    void** rd = NULL_POINTER;
    void** rdc = NULL_POINTER;
    void** rds = NULL_POINTER;

    // The message abstraction.
    void** ma = NULL_POINTER;
    void** mac = NULL_POINTER;
    void** mas = NULL_POINTER;
    // The message model.
    void** mm = NULL_POINTER;
    void** mmc = NULL_POINTER;
    void** mms = NULL_POINTER;
    // The message details.
    void** md = NULL_POINTER;
    void** mdc = NULL_POINTER;
    void** mds = NULL_POINTER;

    //
    // The language name is taken directly.
    // All other parameters are hierarchical names and used to
    // determine the actual item from the knowledge tree.
    //

    // Get language.
    get_compound_element_by_name(p0, p1,
        (void*) LANGUAGE_NAME_ABSTRACTION, (void*) LANGUAGE_NAME_ABSTRACTION_COUNT,
        (void*) &la, (void*) &lac, (void*) &las,
        (void*) &lm, (void*) &lmc, (void*) &lms,
        (void*) &ld, (void*) &ldc, (void*) &lds);

    fprintf(stdout, "TEST la: %s\n", *la);
    fprintf(stdout, "TEST lac: %i\n", **((int**) lac));
    fprintf(stdout, "TEST las: %i\n", **((int**) las));
    fprintf(stdout, "TEST lm: %s\n", *lm);
    fprintf(stdout, "TEST lmc: %i\n", **((int**) lmc));
    fprintf(stdout, "TEST lms: %i\n", **((int**) lms));
    fprintf(stdout, "TEST ld: %i\n", *ld);
//??    fprintf(stdout, "TEST ldc: %i\n", **((int**) ldc));
//??    fprintf(stdout, "TEST lds: %i\n", **((int**) lds));

/*??
    // Get sender.
    get_compound_element_by_encapsulated_name(p0, p1,
        (void*) SENDER_NAME_ABSTRACTION, (void*) SENDER_NAME_ABSTRACTION_COUNT,
        (void*) &sa, (void*) &sac, (void*) &sas,
        (void*) &sm, (void*) &smc, (void*) &sms,
        (void*) &sd, (void*) &sdc, (void*) &sds,
        p2, p3);

    // Get receiver.
    get_compound_element_by_encapsulated_name(p0, p1,
        (void*) RECEIVER_NAME_ABSTRACTION, (void*) RECEIVER_NAME_ABSTRACTION_COUNT,
        (void*) &ra, (void*) &rac, (void*) &ras,
        (void*) &rm, (void*) &rmc, (void*) &rms,
        (void*) &rd, (void*) &rdc, (void*) &rds,
        p2, p3);

    // Get message.
    get_compound_element_by_encapsulated_name(p0, p1,
        (void*) MESSAGE_NAME_ABSTRACTION, (void*) MESSAGE_NAME_ABSTRACTION_COUNT,
        (void*) &ma, (void*) &mac, (void*) &mas,
        (void*) &mm, (void*) &mmc, (void*) &mms,
        (void*) &md, (void*) &mdc, (void*) &mds,
        p2, p3);
*/

    // Get sender.
    get_compound_element_by_name(p0, p1,
        (void*) SENDER_NAME_ABSTRACTION, (void*) SENDER_NAME_ABSTRACTION_COUNT,
        (void*) &sa, (void*) &sac, (void*) &sas,
        (void*) &sm, (void*) &smc, (void*) &sms,
        (void*) &sd, (void*) &sdc, (void*) &sds);

/*??
    fprintf(stdout, "TEST sa: %s\n", *sa);
    fprintf(stdout, "TEST sac: %i\n", **((int**) sac));
    fprintf(stdout, "TEST sas: %i\n", **((int**) sas));
    fprintf(stdout, "TEST sm: %s\n", *sm);
    fprintf(stdout, "TEST smc: %i\n", **((int**) smc));
    fprintf(stdout, "TEST sms: %i\n", **((int**) sms));
    fprintf(stdout, "TEST sd: %i\n", *sd);
//??    fprintf(stdout, "TEST sdc: %i\n", **((int**) sdc));
//??    fprintf(stdout, "TEST sds: %i\n", **((int**) sds));
*/

    // Get receiver.
    get_compound_element_by_name(p0, p1,
        (void*) RECEIVER_NAME_ABSTRACTION, (void*) RECEIVER_NAME_ABSTRACTION_COUNT,
        (void*) &ra, (void*) &rac, (void*) &ras,
        (void*) &rm, (void*) &rmc, (void*) &rms,
        (void*) &rd, (void*) &rdc, (void*) &rds);

    fprintf(stdout, "TEST ra: %s\n", *ra);
    fprintf(stdout, "TEST rac: %i\n", **((int**) rac));
    fprintf(stdout, "TEST ras: %i\n", **((int**) ras));
    fprintf(stdout, "TEST rm: %s\n", *rm);
    fprintf(stdout, "TEST rmc: %i\n", **((int**) rmc));
    fprintf(stdout, "TEST rms: %i\n", **((int**) rms));
    fprintf(stdout, "TEST rd: %i\n", *rd);
//??    fprintf(stdout, "TEST rdc: %i\n", **((int**) rdc));
//??    fprintf(stdout, "TEST rds: %i\n", **((int**) rds));

    // Get message.
    get_compound_element_by_encapsulated_name(p0, p1,
        (void*) MESSAGE_NAME_ABSTRACTION, (void*) MESSAGE_NAME_ABSTRACTION_COUNT,
        (void*) &ma, (void*) &mac, (void*) &mas,
        (void*) &mm, (void*) &mmc, (void*) &mms,
        (void*) &md, (void*) &mdc, (void*) &mds,
        p2, p3);

    fprintf(stdout, "TEST ma: %s\n", *ma);
    fprintf(stdout, "TEST mac: %i\n", **((int**) mac));
    fprintf(stdout, "TEST mas: %i\n", **((int**) mas));
    fprintf(stdout, "TEST mm: %s\n", *mm);
    fprintf(stdout, "TEST mmc: %i\n", **((int**) mmc));
    fprintf(stdout, "TEST mms: %i\n", **((int**) mms));
    fprintf(stdout, "TEST md: %i\n", *md);
//??    fprintf(stdout, "TEST mdc: %i\n", **((int**) mdc));
//??    fprintf(stdout, "TEST mds: %i\n", **((int**) mds));

    // The comparison result.
    int r = 0;

    if (r != 1) {

        compare_arrays((void*) *lm, (void*) *lmc, (void*) TUI_ABSTRACTION, (void*) TUI_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

            //?? The temporary standard console output as destination.
            //?? Possibly use "sender" information instead, later.
            void* tmpd = (void*) stdout;
            void* tmpdc = NULL_POINTER;
            void* tmpds = NULL_POINTER;

            send_tui(tmpd, tmpdc, tmpds, *mm, *mmc);
        }
    }

    if (r != 1) {

        compare_arrays((void*) *lm, (void*) *lmc, (void*) X_WINDOWS_ABSTRACTION, (void*) X_WINDOWS_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

/*??
            translate
            serialise
            send_vga
*/

//??            init_x();

/*??
            // The output screen.
            x->screen = DefaultScreen(x->display);

            // Voreinstellung fuer Pixelwerte
            x->background = WhitePixel(x->display, x->screen);
            x->foreground = BlackPixel(x->display, x->screen);

            // Window-position
            x->hint.x = 100;
            x->hint.y = 100;

            x->hint.width = Anwendung.size_x;
            x->hint.height = Anwendung.size_y;
            x->hint.flags = PPosition | PSize;

            // The parent window.
            // This is mostly the root window of the window manager.
            // For popup menues, it should be the main application window.
            Window parent = DefaultRootWindow(x->display);

            // Create window.
            x->window = XCreateSimpleWindow(
                x->display,
                parent,
                x->hint.x,
                x->hint.y,
                x->hint.width,
                x->hint.height,
                5,
                x->foreground,
                x->background);

            XSetStandardProperties(
                x->display,
                x->window,
                "Application",
                "Icon",
                None,
                NULL,
                0,
                (void*) &(x->hint));

            // Load default colour map.
            x->cmap = DefaultColormap(x->display, x->screen);

            x->gray.red = 49125;
            x->gray.green = 49125;
            x->gray.blue = 49125;
            XAllocColor(x->display, x->cmap, &(x->gray));

            x->light_gray.red = 56000;
            x->light_gray.green = 58000;
            x->light_gray.blue = 60000;
            XAllocColor(x->display, x->cmap, &(x->light_gray));

            x->vlight_gray.red = 60000;
            x->vlight_gray.green = 61000;
            x->vlight_gray.blue = 62000;
            XAllocColor(x->display, x->cmap, &(x->vlight_gray));

            x->dark_gray.red = 32768;
            x->dark_gray.green = 32768;
            x->dark_gray.blue = 32768;
            XAllocColor(x->display, x->cmap, &(x->dark_gray));

            // Create menu graphic context.
            // Each graphic element needs its own graphic context.
            x->gc_menu = XCreateGC(x->display, x->window, 0, 0);
            XSetBackground(x->display, x->gc_menu, x->background);
            XSetForeground(x->display, x->gc_menu, x->light_gray.pixel);

            // Create menu border graphic context.
            // Each graphic element needs its own graphic context.
            x->gc_menu_border_top = XCreateGC(x->display, x->window, 0, 0);
            XSetBackground(x->display, x->gc_menu_border_top, x->background);
            XSetForeground(x->display, x->gc_menu_border_top, x->vlight_gray.pixel);

            // Create menu border bottom graphic context.
            // Each graphic element needs its own graphic context.
            x->gc_menu_border_bottom = XCreateGC(x->display, x->window, 0, 0);
            XSetBackground(x->display, x->gc_menu_border_bottom, x->background);
            XSetForeground(x->display, x->gc_menu_border_bottom, x->dark_gray.pixel);

            // Create menu font graphic context.
            // Each graphic element needs its own graphic context.
            x->gc_menu_font = XCreateGC(x->display, x->window, 0, 0);
            XSetBackground(x->display, x->gc_menu_font, x->light_gray.pixel);
            XSetForeground(x->display, x->gc_menu_font, x->foreground);

            // Create special font.
//??            char* font_name = "Helvetica";
//??            cybol_font = XLoadFont(x->display, font_name);

            // Create graphic context.
            // Each graphic element needs its own graphic context.
            GC gc = XCreateGC(x->display, x->window, 0, 0);
            XSetBackground(x->display, gc, x->background);
            XSetForeground(x->display, gc, x->foreground);
//??            XSetFont(x->display, cybol_gc, cybol_font);

/*??
            char* test = "test string";
            int test_length = strlen(test);
            XDrawString(x->display, x->window, cybol_gc,
                position_x, position_y, test, test_length);
*/

/*??
            // Request input events (signals) to be put into event queue.
            XSelectInput(x->display, x->window, ButtonPressMask | KeyPressMask | ExposureMask);

            // Map the window.
            // This procedure changes the order of all sister windows,
            // so that the given window lies on top.
            // Afterwards, all windows are displayed on the screen.
            XMapRaised(x->display, x->window);

            //?? TODO: From xlib tutorial.
            //?? Remove as soon as event loop (MappingNotify) functions!
            XFlush(x->display);

            sleep(5);

            // Free memory.
            XFreeGC(x->display, gc);
            XDestroyWindow(x->display, x->window);
*/
        }
    }

    if (r != 1) {

        compare_arrays((void*) *lm, (void*) *lmc, (void*) UNIX_SOCKET_CHANNEL, (void*) UNIX_SOCKET_CHANNEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

/*??
            send_unix_socket((void*) &dn, (void*) &dnc, (void*) &dns,
                (void*) &snm, (void*) &snmc,
                (void*) &sna, (void*) &snac,
                (void*) &INLINE_CHANNEL, (void*) &INLINE_CHANNEL_COUNT);
*/
        }
    }

    if (r != 1) {

        compare_arrays((void*) *lm, (void*) *lmc, (void*) TCP_SOCKET_CHANNEL, (void*) TCP_SOCKET_CHANNEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

            // The socket number for the signal id.
            // The index for the signal id in the array is the same index
            // in the client socket number array.
            int i = -1;

            get_index_for_signal_id(p6, p5, (void*) &i);

            if (i >= 0) {

                // The client socket.
                int* cs = INTEGER_NULL_POINTER;

                get_client_socket_number_for_index(p6, (void*) &i, (void*) &cs);

                if (*cs >= 0) {

                    //in abhängigkeit vom empfänger
                    //müssen die Daten verschieden aufbereitet werden
                    //zur Zeit nur TCP socket für webanwednung
                    //darum z.Z. immer html-Aufbereitung
                    //--> das bedeuet, das ermittelte Modell
                    //muss noch für die Ausgabe aufbereuitet (tranlate) werden.

                    //create the destination for the send model
                    void* dest = NULL_POINTER;
                    int* dest_count = INTEGER_NULL_POINTER;
                    int* dest_size = INTEGER_NULL_POINTER;

                    create( &dest_count, INTEGER_COUNT,
                            INTEGER_ABSTRACTION, INTEGER_ABSTRACTION_COUNT );
                    create( &dest_size, INTEGER_COUNT,
                            INTEGER_ABSTRACTION, INTEGER_ABSTRACTION_COUNT );
                    *dest_count = 0;
                    *dest_size  = 0;
                    create( &dest, dest_size,
                            STRING_ABSTRACTION, STRING_ABSTRACTION_COUNT );

                    encode_model( &dest, dest_count, dest_size,
                                  *ma, *mac,
                                  *mm, *mmc,
                                  *md, *mdc,
                                  (void*) HTML_ABSTRACTION,
                                  (void*) HTML_ABSTRACTION_COUNT,
                                  p2, p3 );

                    // The temporary count, size.
                    int tc = 0;
                    int ts = 0;

                    send_tcp_socket( (void*) &cs, (void*) &tc, (void*) &ts,
                                     (void*) dest, (void*) dest_count );

                    // Remove client socket number and main signal id from internals.
                    remove_relation_clientsocketnumber_mainsignalid(p6, (void*) &i);

                    // Close socket.
                    close(*cs);

                    //destroy destination
                    destroy( &dest, dest_size,
                             STRING_ABSTRACTION, STRING_ABSTRACTION_COUNT );
                    destroy( &dest_count, INTEGER_COUNT,
                             INTEGER_ABSTRACTION, INTEGER_ABSTRACTION_COUNT );
                    destroy( &dest_size, INTEGER_COUNT,
                             INTEGER_ABSTRACTION, INTEGER_ABSTRACTION_COUNT );

                } else {

                    log_message_debug("Could not send tcp socket message. The client socket number was not found.");
                }

            } else {

                log_message_debug("Could not send tcp socket message. The signal id index is invalid.");
            }
        }
    }
}

/* SEND_SOURCE */
#endif
