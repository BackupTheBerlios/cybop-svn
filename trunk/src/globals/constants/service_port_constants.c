/*
 * $RCSfile: service_port_constants.c,v $
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
 * @version $Revision: 1.1 $ $Date: 2006-12-27 09:53:07 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef SERVICE_PORT_CONSTANTS_SOURCE
#define SERVICE_PORT_CONSTANTS_SOURCE

#include "../../globals/constants/integer_constants.c"

//
// IANA assigned ports.
//

/** The tcp service multiplexer port. */
static int TCP_MUX_PORT_ARRAY[] = NUMBER_1_INTEGER;
static int* TCP_MUX_PORT = TCP_MUX_PORT_ARRAY;

/** The file transfer protocol (ftp) data port. */
static int FTP_DATA_PORT_ARRAY[] = NUMBER_20_INTEGER;
static int* FTP_DATA_PORT = FTP_DATA_PORT_ARRAY;

/** The file transfer protocol (ftp) port. */
static int FTP_PORT_ARRAY[] = NUMBER_21_INTEGER;
static int* FTP_PORT = FTP_PORT_ARRAY;

/** The file ?? protocol (fsp) port. */
static int FSP_PORT_ARRAY[] = NUMBER_21_INTEGER;
static int* FSP_PORT = FSP_PORT_ARRAY;

/** The secure shell (ssh) port. */
static int SSH_PORT_ARRAY[] = NUMBER_22_INTEGER;
static int* SSH_PORT = SSH_PORT_ARRAY;

/** The telnet port. */
static int TELNET_PORT_ARRAY[] = NUMBER_23_INTEGER;
static int* TELNET_PORT = TELNET_PORT_ARRAY;

/** The ?? mail transfer protocol (smtp) port. */
static int SMTP_PORT_ARRAY[] = NUMBER_25_INTEGER;
static int* SMTP_PORT = SMTP_PORT_ARRAY;

/** The world wide web (www) hypertext transfer protocol (http) port. */
static int WWW_PORT_ARRAY[] = NUMBER_80_INTEGER;
static int* WWW_PORT = WWW_PORT_ARRAY;

/** The post office protocol version 3 (pop3) port. */
static int POP3_PORT_ARRAY[] = NUMBER_110_INTEGER;
static int* POP3_PORT = POP3_PORT_ARRAY;

/** The hypertext transfer protocol over tls/ ssl (https) port. */
static int HTTPS_PORT_ARRAY[] = NUMBER_443_INTEGER;
static int* HTTPS_PORT = HTTPS_PORT_ARRAY;

/* SERVICE_PORT_CONSTANTS_SOURCE */
#endif
