/*
 * Copyright (C) 1999-2010. Christian Heller.
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
 * @version $RCSfile: globaliser.c,v $ $Revision: 1.13 $ $Date: 2009-01-31 16:06:30 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef SOCKET_GLOBALISER_SOURCE
#define SOCKET_GLOBALISER_SOURCE

#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/stat.h>
#include <sys/un.h>
#include "../../variable/type_size/integral_type_size.c"
#include "../../variable/type_size/socket_type_size.c"

/**
 * Allocates and initialises socket global variables.
 */
void globalise_socket() {

    // Allocate and initialise struct in_addr socket type size.
    INTERNET_PROTOCOL_4_HOST_ADDRESS_SOCKET_TYPE_SIZE = (signed int*) malloc(*SIGNED_INTEGER_INTEGRAL_TYPE_SIZE);
    *INTERNET_PROTOCOL_4_HOST_ADDRESS_SOCKET_TYPE_SIZE = sizeof(struct in_addr);

    // Allocate and initialise struct sockaddr_in socket type size.
    INTERNET_PROTOCOL_4_SOCKET_ADDRESS_SOCKET_TYPE_SIZE = (signed int*) malloc(*SIGNED_INTEGER_INTEGRAL_TYPE_SIZE);
    *INTERNET_PROTOCOL_4_SOCKET_ADDRESS_SOCKET_TYPE_SIZE = sizeof(struct sockaddr_in);

    // Allocate and initialise struct in6_addr socket type size.
    INTERNET_PROTOCOL_6_HOST_ADDRESS_SOCKET_TYPE_SIZE = (signed int*) malloc(*SIGNED_INTEGER_INTEGRAL_TYPE_SIZE);
    *INTERNET_PROTOCOL_6_HOST_ADDRESS_SOCKET_TYPE_SIZE = sizeof(struct in6_addr);

    // Allocate and initialise struct sockaddr_in6 socket type size.
    INTERNET_PROTOCOL_6_SOCKET_ADDRESS_SOCKET_TYPE_SIZE = (signed int*) malloc(*SIGNED_INTEGER_INTEGRAL_TYPE_SIZE);
    *INTERNET_PROTOCOL_6_SOCKET_ADDRESS_SOCKET_TYPE_SIZE = sizeof(struct sockaddr_in6);

    // Allocate and initialise struct sockaddr_un socket type size.
    LOCAL_SOCKET_ADDRESS_SOCKET_TYPE_SIZE = (signed int*) malloc(*SIGNED_INTEGER_INTEGRAL_TYPE_SIZE);
    *LOCAL_SOCKET_ADDRESS_SOCKET_TYPE_SIZE = sizeof(struct sockaddr_un);

    // Allocate and initialise struct sockaddr socket type size.
    SOCKET_ADDRESS_SOCKET_TYPE_SIZE = (signed int*) malloc(*SIGNED_INTEGER_INTEGRAL_TYPE_SIZE);
    *SOCKET_ADDRESS_SOCKET_TYPE_SIZE = sizeof(struct sockaddr);
}

/* SOCKET_GLOBALISER_SOURCE */
#endif