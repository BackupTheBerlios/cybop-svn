/*
 * Copyright (C) 1999-2009. Christian Heller.
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
 * @version $RCSfile: internet_protocol_model.c,v $ $Revision: 1.4 $ $Date: 2009-07-22 17:18:16 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef INTERNET_PROTOCOL_MODEL_SOURCE
#define INTERNET_PROTOCOL_MODEL_SOURCE

#include "../../constant/model/memory/integer_memory_model.c"

/**
 * The internet protocol (ip) model.
 *
 * This is a pseudo protocol number.
 */
static int* IP_INTERNET_PROTOCOL_MODEL = NUMBER_0_INTEGER_MEMORY_MODEL_ARRAY;

/** The transmission control protocol (tcp) model. */
static int* TCP_INTERNET_PROTOCOL_MODEL = NUMBER_6_INTEGER_MEMORY_MODEL_ARRAY;

/** The user datagram protocol (udp) model. */
static int* UDP_INTERNET_PROTOCOL_MODEL = NUMBER_17_INTEGER_MEMORY_MODEL_ARRAY;

/** The internet protocol version 6 (ipv6) model. */
static int* IPV6_INTERNET_PROTOCOL_MODEL = NUMBER_41_INTEGER_MEMORY_MODEL_ARRAY;

/** The routing header for ipv6 model. */
static int* IPV6_ROUTE_INTERNET_PROTOCOL_MODEL = NUMBER_43_INTEGER_MEMORY_MODEL_ARRAY;

/** The fragment header for ipv6 model. */
static int* IPV6_FRAG_INTERNET_PROTOCOL_MODEL = NUMBER_44_INTEGER_MEMORY_MODEL_ARRAY;

/** The icmp for ipv6 model. */
static int* IPV6_ICMP_INTERNET_PROTOCOL_MODEL = NUMBER_58_INTEGER_MEMORY_MODEL_ARRAY;

/** The no next header for ipv6 model. */
static int* IPV6_NONXT_INTERNET_PROTOCOL_MODEL = NUMBER_59_INTEGER_MEMORY_MODEL_ARRAY;

/** The destination options for ipv6 model. */
static int* IPV6_OPTS_INTERNET_PROTOCOL_MODEL = NUMBER_60_INTEGER_MEMORY_MODEL_ARRAY;

/* INTERNET_PROTOCOL_MODEL_SOURCE */
#endif
