/*
 * $RCSfile: internet_protocol_constants.c,v $
 *
 * Copyright (c) 1999-2008. Christian Heller and the CYBOP developers.
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
 * @version $Revision: 1.5 $ $Date: 2008-05-04 00:18:12 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef INTERNET_PROTOCOL_CONSTANTS_SOURCE
#define INTERNET_PROTOCOL_CONSTANTS_SOURCE

#include "../../globals/constants/integer/integer_constants.c"

/** The internet protocol (ip). This is a pseudo protocol number. */
static int* IP_PROTOCOL = NUMBER_0_INTEGER_ARRAY;

/** The transmission control protocol (tcp). */
static int* TCP_PROTOCOL = NUMBER_6_INTEGER_ARRAY;

/** The user datagram protocol (udp). */
static int* UDP_PROTOCOL = NUMBER_17_INTEGER_ARRAY;

/** The internet protocol version 6 (ipv6). */
static int* IPV6_PROTOCOL = NUMBER_41_INTEGER_ARRAY;

/** The routing header for ipv6. */
static int* IPV6_ROUTE_PROTOCOL = NUMBER_43_INTEGER_ARRAY;

/** The fragment header for ipv6. */
static int* IPV6_FRAG_PROTOCOL = NUMBER_44_INTEGER_ARRAY;

/** The icmp for ipv6. */
static int* IPV6_ICMP_PROTOCOL = NUMBER_58_INTEGER_ARRAY;

/** The no next header for ipv6. */
static int* IPV6_NONXT_PROTOCOL = NUMBER_59_INTEGER_ARRAY;

/** The destination options for ipv6. */
static int* IPV6_OPTS_PROTOCOL = NUMBER_60_INTEGER_ARRAY;

/* INTERNET_PROTOCOL_CONSTANTS_SOURCE */
#endif
