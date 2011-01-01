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
 * @version $RCSfile: globaliser.c,v $ $Revision: 1.13 $ $Date: 2009-01-31 16:06:30 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef SOCKET_UNGLOBALISER_SOURCE
#define SOCKET_UNGLOBALISER_SOURCE

#include <stdlib.h>

/**
 * Deallocates socket global variables.
 */
void unglobalise_socket() {

    // Free in_addr socket type size.
    free((void*) INTERNET_PROTOCOL_4_HOST_ADDRESS_SOCKET_TYPE_SIZE);

    // Free sockaddr_in socket type size.
    free((void*) INTERNET_PROTOCOL_4_SOCKET_ADDRESS_SOCKET_TYPE_SIZE);

    // Free in6_addr socket type size.
    free((void*) INTERNET_PROTOCOL_6_HOST_ADDRESS_SOCKET_TYPE_SIZE);

    // Free sockaddr_in6 socket type size.
    free((void*) INTERNET_PROTOCOL_6_SOCKET_ADDRESS_SOCKET_TYPE_SIZE);

    // Free sockaddr_un socket type size.
    free((void*) LOCAL_SOCKET_ADDRESS_SOCKET_TYPE_SIZE);

    // Free sockaddr socket type size.
    free((void*) SOCKET_ADDRESS_SOCKET_TYPE_SIZE);
}

/* SOCKET_UNGLOBALISER_SOURCE */
#endif
