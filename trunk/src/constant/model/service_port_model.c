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
 * @version $RCSfile: service_port_model.c,v $ $Revision: 1.2 $ $Date: 2008-09-04 20:31:30 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef SERVICE_PORT_MODEL_SOURCE
#define SERVICE_PORT_MODEL_SOURCE

#include "../../constant/model/memory/integer_memory_model.c"

//
// IANA assigned ports.
//

/** The tcp service multiplexer port model. */
static int* TCP_MUX_PORT_MODEL = NUMBER_1_INTEGER_MEMORY_MODEL_ARRAY;

/** The file transfer protocol (ftp) data port model. */
static int* FTP_DATA_PORT_MODEL = NUMBER_20_INTEGER_MEMORY_MODEL_ARRAY;

/** The file transfer protocol (ftp) port model. */
static int* FTP_PORT_MODEL = NUMBER_21_INTEGER_MEMORY_MODEL_ARRAY;

/** The file ?? protocol (fsp) port model. */
static int* FSP_PORT_MODEL = NUMBER_21_INTEGER_MEMORY_MODEL_ARRAY;

/** The secure shell (ssh) port model. */
static int* SSH_PORT_MODEL = NUMBER_22_INTEGER_MEMORY_MODEL_ARRAY;

/** The telnet port model. */
static int* TELNET_PORT_MODEL = NUMBER_23_INTEGER_MEMORY_MODEL_ARRAY;

/** The ?? mail transfer protocol (smtp) port model. */
static int* SMTP_PORT_MODEL = NUMBER_25_INTEGER_MEMORY_MODEL_ARRAY;

/** The world wide web (www) hypertext transfer protocol (http) port model. */
static int* WWW_PORT_MODEL = NUMBER_80_INTEGER_MEMORY_MODEL_ARRAY;

/** The post office protocol version 3 (pop3) port model. */
static int* POP3_PORT_MODEL = NUMBER_110_INTEGER_MEMORY_MODEL_ARRAY;

/** The hypertext transfer protocol over tls/ ssl (https) port model. */
static int* HTTPS_PORT_MODEL = NUMBER_443_INTEGER_MEMORY_MODEL_ARRAY;

/** The cybernetics oriented interpreter (cyboi) port model. */
static int* CYBOI_PORT_MODEL = NUMBER_1971_INTEGER_MEMORY_MODEL_ARRAY;

/* SERVICE_PORT_MODEL_SOURCE */
#endif
