/*
 * $RCSfile: service_port_constants.c,v $
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
 * @version $Revision: 1.5 $ $Date: 2007-04-16 16:23:41 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef SERVICE_PORT_CONSTANTS_SOURCE
#define SERVICE_PORT_CONSTANTS_SOURCE

#include "../../globals/constants/integer/integer_constants.c"

//
// IANA assigned ports.
//

/** The tcp service multiplexer port. */
static int* TCP_MUX_PORT = NUMBER_1_INTEGER_ARRAY;

/** The file transfer protocol (ftp) data port. */
static int* FTP_DATA_PORT = NUMBER_20_INTEGER_ARRAY;

/** The file transfer protocol (ftp) port. */
static int* FTP_PORT = NUMBER_21_INTEGER_ARRAY;

/** The file ?? protocol (fsp) port. */
static int* FSP_PORT = NUMBER_21_INTEGER_ARRAY;

/** The secure shell (ssh) port. */
static int* SSH_PORT = NUMBER_22_INTEGER_ARRAY;

/** The telnet port. */
static int* TELNET_PORT = NUMBER_23_INTEGER_ARRAY;

/** The ?? mail transfer protocol (smtp) port. */
static int* SMTP_PORT = NUMBER_25_INTEGER_ARRAY;

/** The world wide web (www) hypertext transfer protocol (http) port. */
static int* WWW_PORT = NUMBER_80_INTEGER_ARRAY;

/** The post office protocol version 3 (pop3) port. */
static int* POP3_PORT = NUMBER_110_INTEGER_ARRAY;

/** The hypertext transfer protocol over tls/ ssl (https) port. */
static int* HTTPS_PORT = NUMBER_443_INTEGER_ARRAY;

/** The cybernetics oriented interpreter (cyboi) port. */
static int* CYBOI_PORT = NUMBER_1971_INTEGER_ARRAY;

/* SERVICE_PORT_CONSTANTS_SOURCE */
#endif
