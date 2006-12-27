/*
 * $RCSfile: internet_protocol_constants.c,v $
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

#ifndef INTERNET_PROTOCOL_CONSTANTS_SOURCE
#define INTERNET_PROTOCOL_CONSTANTS_SOURCE

#include "../../globals/constants/integer_constants.c"

/** The internet protocol (ip). This is a pseudo protocol number. */
static int IP_PROTOCOL_ARRAY[] = NUMBER_0_INTEGER;
static int* IP_PROTOCOL = IP_PROTOCOL_ARRAY;

/** The transmission control protocol (tcp). */
static int TCP_PROTOCOL_ARRAY[] = NUMBER_6_INTEGER;
static int* TCP_PROTOCOL = TCP_PROTOCOL_ARRAY;

/** The user datagram protocol (udp). */
static int UDP_PROTOCOL_ARRAY[] = NUMBER_17_INTEGER;
static int* UDP_PROTOCOL = UDP_PROTOCOL_ARRAY;

/** The internet protocol version 6 (ipv6). */
static int IPV6_PROTOCOL_ARRAY[] = NUMBER_41_INTEGER;
static int* IPV6_PROTOCOL = IPV6_PROTOCOL_ARRAY;

/** The routing header for ipv6. */
static int IPV6_ROUTE_PROTOCOL_ARRAY[] = NUMBER_43_INTEGER;
static int* IPV6_ROUTE_PROTOCOL = IPV6_ROUTE_PROTOCOL_ARRAY;

/** The fragment header for ipv6. */
static int IPV6_FRAG_PROTOCOL_ARRAY[] = NUMBER_44_INTEGER;
static int* IPV6_FRAG_PROTOCOL = IPV6_FRAG_PROTOCOL_ARRAY;

/** The icmp for ipv6. */
static int IPV6_ICMP_PROTOCOL_ARRAY[] = NUMBER_58_INTEGER;
static int* IPV6_ICMP_PROTOCOL = IPV6_ICMP_PROTOCOL_ARRAY;

/** The no next header for ipv6. */
static int IPV6_NONXT_PROTOCOL_ARRAY[] = NUMBER_59_INTEGER;
static int* IPV6_NONXT_PROTOCOL = IPV6_NONXT_PROTOCOL_ARRAY;

/** The destination options for ipv6. */
static int IPV6_OPTS_PROTOCOL_ARRAY[] = NUMBER_60_INTEGER;
static int* IPV6_OPTS_PROTOCOL = IPV6_OPTS_PROTOCOL_ARRAY;

/* INTERNET_PROTOCOL_CONSTANTS_SOURCE */
#endif
