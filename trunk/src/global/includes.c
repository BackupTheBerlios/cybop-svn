/*
 * $RCSfile: includes.c,v $
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
 * @version $Revision: 1.1 $ $Date: 2005-03-18 09:20:56 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef INCLUDES_SOURCE
#define INCLUDES_SOURCE

//
// CAUTION! The ORDER of includes is important!
//
// Standard C libraries and further system libraries are included first.
// Constants and basic sources that do NOT depend on other sources are
// included next. Sources which depend on basic sources are included last.
//

//
// Standard C libraries.
//

// #include <ctype.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

//
// System libraries.
//

#include <arpa/inet.h>
#include <libxml/parser.h>
#include <libxml/tree.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/un.h>
#include <unistd.h>
// #include <X11/X.h>
// #include <X11/Xatom.h>
// #include <X11/Xfuncs.h>
// #include <X11/Xlib.h>
// #include <X11/Xos.h>
// #include <X11/Xproto.h>
// #include <X11/Xresource.h>
// #include <X11/Xutil.h>

//
// Global.
//

// CAUTION! Do NOT include this file itself!
// #include "../global/includes.c"
#include "../global/abstraction_constants.c"
#include "../global/channel_constants.c"
#include "../global/character_constants.c"
#include "../global/cybol_constants.c"
#include "../global/integer_constants.c"
#include "../global/log_constants.c"
#include "../global/name_constants.c"
#include "../global/structure_constants.c"
#include "../global/constant.c"
#include "../global/variables.c"

//
// Logger.
//

#include "../logger/logger.c"

//
// Array.
//

#include "../array/character_array.c"
#include "../array/double_array.c"
#include "../array/integer_array.c"
#include "../array/pointer_array.c"
#include "../array/array.c"

//
// Creator.
//

#include "../creator/character_creator.c"
#include "../creator/complex_creator.c"
#include "../creator/compound_creator.c"
#include "../creator/double_creator.c"
#include "../creator/fraction_creator.c"
#include "../creator/integer_creator.c"
#include "../creator/internals_memory_creator.c"
#include "../creator/pointer_creator.c"
#include "../creator/signal_memory_creator.c"
#include "../creator/string_creator.c"
#include "../creator/time_creator.c"
#include "../creator/vector_creator.c"
#include "../creator/x_windows_creator.c"
#include "../creator/xml_node_creator.c"
#include "../creator/xml_property_creator.c"
#include "../creator/creator.c"

//
// Accessor.
//

#include "../accessor/compound_accessor.c"
#include "../accessor/signal_memory_accessor.c"

//
// Communicator.
//

#include "../communicator/file_communicator.c"
#include "../communicator/ftp_communicator.c"
#include "../communicator/http_communicator.c"
#include "../communicator/inline_communicator.c"
#include "../communicator/tcp_socket_communicator.c"
#include "../communicator/tui_communicator.c"
#include "../communicator/vga_communicator.c"
#include "../communicator/communicator.c"

//
// Parser.
//

#include "../parser/boolean_parser.c"
#include "../parser/complex_parser.c"
#include "../parser/double_parser.c"
#include "../parser/fraction_parser.c"
#include "../parser/integer_parser.c"
#include "../parser/string_parser.c"
#include "../parser/time_parser.c"
#include "../parser/vector_parser.c"
#include "../parser/xml_parser.c"
#include "../parser/parser.c"

//
// Translator.
//

#include "../translator/cybol_translator.c"
#include "../translator/configuration_translator.c"
#include "../translator/html_translator.c"
#include "../translator/x_windows_translator.c"
#include "../translator/translator.c"

//
// Socket.
//

#include "../socket/client_tcp.c"
#include "../socket/client_udp.c"
#include "../socket/server_tcp.c"
#include "../socket/server_udp.c"
#include "../socket/unix_socket.c"

//
// Web.
//

#include "../web/socket_number_accessor.c"
#include "../web/tcp_socket_server.c"

//
// X windows.
//

#include "../x_windows/x_windows.c"
#include "../x_windows/x_windows_handler.c"

//
// Logic.
//

#include "../logic/add.c"
#include "../logic/build.c"
#include "../logic/compare.c"
#include "../logic/count.c"
#include "../logic/create.c"
#include "../logic/destroy.c"
#include "../logic/loop.c"
#include "../logic/receive.c"
#include "../logic/selection.c"
#include "../logic/send.c"
#include "../logic/set.c"

//
// Test.
//

#include "../test/test.c"

//
// Cyboi.
//

#include "../cyboi/signal_handler.c"
#include "../cyboi/input_output_activator.c"
#include "../cyboi/signal_waiter.c"
#include "../cyboi/input_output_handler.c"
#include "../cyboi/signal_memory_handler.c"
#include "../cyboi/knowledge_memory_handler.c"
#include "../cyboi/system_handler.c"
#include "../cyboi/globals_handler.c"
// CAUTION! Do NOT include main file, to avoid circular dependencies!
//#include "../cyboi/cyboi.c"

/* INCLUDES_SOURCE */
#endif
