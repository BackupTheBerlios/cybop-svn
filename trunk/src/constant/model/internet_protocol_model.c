/*
 * Copyright (C) 1999-2011. Christian Heller.
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
 * @author Enrico Gallus <enrico.gallus@googlemail.com>
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

/** The internet control message protocol (icmp)model. */
static int* IP_CONTROL_MESSAGE_PROTOCOL_MODEL = NUMBER_1_INTEGER_MEMORY_MODEL_ARRAY;

/** The internet group management protocol (igmp) model. */
static int* IP_GROUP_MANAGEMENT_PROTOCOL_MODEL = NUMBER_2_INTEGER_MEMORY_MODEL_ARRAY;

/** The gateway-gateway protocol (ggp) model. */
static int* GATEWAY_GATEWAY_PROTOCOL_MODEL = NUMBER_3_INTEGER_MEMORY_MODEL_ARRAY;

/** The IP encapsulated in IP (ip-encap) model. */
static int* IP_ENCAPSULATED_IN_IP_PROTOCOL_MODEL = NUMBER_4_INTEGER_MEMORY_MODEL_ARRAY;

/** The ST datagram mode (st) model. */
static int* ST_DATAGRAM_MODE_PROTOCOL_MODEL = NUMBER_5_INTEGER_MEMORY_ARRAY_MODEL;

/** The transmission control protocol (tcp) model. */
static int* TCP_INTERNET_PROTOCOL_MODEL = NUMBER_6_INTEGER_MEMORY_MODEL_ARRAY;

/** The exterior gateway protocol (egp) model. */
static int* EXTERIOR_GATEWAY_PROTOCOL_MODEL = NUMBER_8_INTEGER_MEMORY_MODEL_ARRAY;

/** The any private interior gateway (igp) model. */
static int* ANY_PRIVATE_INTERIOR_GATEWAY_PROTOCOL_MODEL = NUMBER_9_INTEGER_MEMORY_MODEL_ARRAY;

/** The PARC universal packet protocol (pud) model. */
static int* PARC_UNIVERSAL_PACKET_PROTOCOL_MODEL = NUMBER_12_INTEGER_MEMORY_MODEL_ARRAY;

/** The user datagram protocol (udp) model. */
static int* UDP_INTERNET_PROTOCOL_MODEL = NUMBER_17_INTEGER_MEMORY_MODEL_ARRAY;

/** The internet protocol version 6 (ipv6) model. */
static int* IPV6_INTERNET_PROTOCOL_MODEL = NUMBER_41_INTEGER_MEMORY_MODEL_ARRAY;

/** The routing header for ipv6 model. */
static int* IPV6_ROUTE_INTERNET_PROTOCOL_MODEL = NUMBER_43_INTEGER_MEMORY_MODEL_ARRAY;

/** The fragment header for ipv6 model. */
static int* IPV6_FRAG_INTERNET_PROTOCOL_MODEL = NUMBER_44_INTEGER_MEMORY_MODEL_ARRAY;

/** The inter-domain routing protocol (idrp) model. */
static int* INTER_DOMAIN_INTERNET_PROTOCOL_MODEL = NUMBER_45_INTEGER_MEMORY_MODEL_ARRAY;

/** The icmp for ipv6 model. */
static int* IPV6_ICMP_INTERNET_PROTOCOL_MODEL = NUMBER_58_INTEGER_MEMORY_MODEL_ARRAY;

/** The no next header for ipv6 model. */
static int* IPV6_NONXT_INTERNET_PROTOCOL_MODEL = NUMBER_59_INTEGER_MEMORY_MODEL_ARRAY;

/** The destination options for ipv6 model. */
static int* IPV6_OPTS_INTERNET_PROTOCOL_MODEL = NUMBER_60_INTEGER_MEMORY_MODEL_ARRAY;

/** The radio shortest path first (cphb) model. */
static int* RADIO_SHORTEST_PATH_FIRST_PROTOCOL_MODEL = NUMBER_73_INTEGER_MEMORY_MODEL_ARRAY;

/** The versatile message transport (vmtp) model. */
static int* VERSATILE_MESSAGE_TRANSPORT_PROTOCOL_MODEL = NUMBER_81_INTEGER_MEMORY_MODEL_ARRAY;

/** The enhanced interior routing protocol (eigrp) model. */
static int* ENHANCED_INTERIOR_ROUTING_PROTOCOL_MODEL = NUMBER_88_INTEGER_MEMORY_MODEL_ARRAY;

/** The open shortest path first igp protocol model. */
static int* OSPFIGP_PROTOCOL_MODEL = NUMBER_89_INTEGER_MEMORY_MODEL_ARRAY;

/** The ax.25 frames protocol model. */
static int* AX_25_PROTOCOL_MODEL = NUMBER_93_INTEGER_MEMORY_MODEL_ARRAY;

/** The ip-within-ip encapsulation protocol model. */
static int* IP_IP_PROTOCOL_MODEL = NUMBER_94_INTEGER_MEMORY_MODEL_ARRAY;

/** The ethernet-within-ip encapsulation protocol model. */
static int* ETHERIP_PROTOCOL_MODEL = NUMBER_97_INTEGER_MEMORY_MODEL_ARRAY;

/** The yet another ip encapsulation protocol model. */
static int* ENCAP_PROTOCOL_MODEL = NUMBER_98_INTEGER_MEMORY_MODEL_ARRAY;

/** The any privat encryption scheme protocol model. */
static int* PRIVAT_ENC_PROTOCOL_MODEL = NUMBER_99_INTEGER_MEMORY_MODEL_ARRAY;

/** The protocal independent multicast protocol model. */
static int* PIM_PROTOCOL_MODEL = NUMBER_103_INTEGER_MEMORY_MODEL_ARRAY;

/** The ip payload compression protocol model. */
static int* IPCOMP_PROTOCOL_MODEL = NUMBER_108_INTEGER_MEMORY_MODEL_ARRAY;

/** The virtual router redundancy protocol model. */
static int* VRRP_PROTOCOL_MODEL = NUMBER_112_INTEGER_MEMORY_MODEL_ARRAY;

/** The layer two tunneling protocol model. */
static int* L2TP_PROTOCOL_MODEL = NUMBER_115_INTEGER_MEMORY_MODEL_ARRAY;

/** The is-is over ipv4 protocol model. */
static int* ISIS_PROTOCOL_MODEL = NUMBER_124_INTEGER_MEMORY_MODEL_ARRAY;

/** The stream control transmission protocol model. */
static int* SCTP_PROTOCOL_MODEL = NUMBER_132_INTEGER_MEMORY_MODEL_ARRAY;

/** The fibre channel protocol model. */
static int* FC_PROTOCOL_MODEL = NUMBER_133_INTEGER_MEMORY_MODEL_ARRAY;

/** The udp-lite protocol model. */
static int* UDPLITE_PROTOCOL_MODEL = NUMBER_136_INTEGER_MEMORY_MODEL_ARRAY;

/** The mpls-in-ip protocol model. */
static int* MPLS_IN_IP_PROTOCOL_MODEL = NUMBER_137_INTEGER_MEMORY_MODEL_ARRAY;

/** The manet protocol model. */
static int* MANET_PROTOCOL_MODEL = NUMBER_138_INTEGER_MEMORY_MODEL_ARRAY;

/** The host identity protocol model. */
static int* HIP_PROTOCOL_MODEL = NUMBER_139_INTEGER_MEMORY_MODEL_ARRAY;

/** The shim6 protocol model. */
static int* SHIM6_PROTOCOL_MODEL = NUMBER_140_INTEGER_MEMORY_MODEL_ARRAY;

/** The wrapped encapsulating security payload protocol model. */
static int* WESP_PROTOCOL_MODEL = NUMBER_141_INTEGER_MEMORY_MODEL_ARRAY;

/** The robust header compression protocol model. */
static int* ROHC_PROTOCOL_MODEL = NUMBER_142_INTEGER_MEMORY_MODEL_ARRAY;

/* INTERNET_PROTOCOL_MODEL_SOURCE */
#endif
