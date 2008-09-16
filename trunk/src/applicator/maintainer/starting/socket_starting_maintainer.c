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
 * @version $RCSfile: socket_starting_maintainer.c,v $ $Revision: 1.8 $ $Date: 2008-09-16 07:13:50 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef SOCKET_STARTER_SOURCE
#define SOCKET_STARTER_SOURCE

#ifdef GNU_LINUX_OPERATING_SYSTEM

#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include "../../../constant/abstraction/cybol/text_cybol_abstraction.c"
#include "../../../constant/abstraction/memory/memory_abstraction.c"
#include "../../../constant/model/character_code/unicode/unicode_character_code_model.c"
#include "../../../constant/model/cybol/address_cybol_model.c"
#include "../../../constant/model/cybol/communication_style_cybol_model.c"
#include "../../../constant/model/cybol/http_request_cybol_model.c"
#include "../../../constant/model/cybol/namespace_cybol_model.c"
#include "../../../constant/model/memory/integer_memory_model.c"
#include "../../../constant/model/memory/pointer_memory_model.c"
#include "../../../constant/name/memory/internal_memory_memory_name.c"
#include "../../../memoriser/accessor.c"
#include "../../../memoriser/array.c"
#include "../../../memoriser/allocator.c"

/**
 * Gets the socket- and address namespace.
 *
 * @param p0 the socket namespace (Hand over as reference!)
 * @param p1 the address namespace (Hand over as reference!)
 * @param p2 the namespace model
 * @param p3 the namespace model count
 */
void startup_socket_get_namespace(void* p0, void* p1, void* p2, void* p3) {

    if (p1 != *NULL_POINTER_MEMORY_MODEL) {

        int* an = (int*) p1;

        if (p0 != *NULL_POINTER_MEMORY_MODEL) {

            int* sn = (int*) p0;

            log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Startup socket get namespace.");

            // The comparison result.
            int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

            if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                compare_arrays(p2, p3, (void*) LOCAL_NAMESPACE_MODEL, (void*) LOCAL_NAMESPACE_MODEL_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

                if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    *sn = PF_LOCAL;
                    *an = AF_LOCAL;
                }
            }

            if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                compare_arrays(p2, p3, (void*) INET_NAMESPACE_MODEL, (void*) INET_NAMESPACE_MODEL_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

                if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    *sn = PF_INET;
                    *an = AF_INET;
                }
            }

            if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                compare_arrays(p2, p3, (void*) INET6_NAMESPACE_MODEL, (void*) INET6_NAMESPACE_MODEL_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

                if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    *sn = PF_INET6;
                    *an = AF_INET6;
                }
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not get startup socket namespace. The socket namespace is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not get startup socket namespace. The address namespace is null.");
    }
}

/**
 * Gets the communication style.
 *
 * @param p0 the communication style (Hand over as reference!)
 * @param p1 the communication style model
 * @param p2 the communication style model count
 */
void startup_socket_get_style(void* p0, void* p1, void* p2) {

    if (p0 != *NULL_POINTER_MEMORY_MODEL) {

        int* s = (int*) p0;

        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Startup socket get style.");

        // The comparison result.
        int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            compare_arrays(p1, p2, (void*) STREAM_COMMUNICATION_STYLE_CYBOL_MODEL, (void*) STREAM_COMMUNICATION_STYLE_CYBOL_MODEL_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

            if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                *s = SOCK_STREAM;
            }
        }

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            compare_arrays(p1, p2, (void*) DATAGRAM_COMMUNICATION_STYLE_CYBOL_MODEL, (void*) DATAGRAM_COMMUNICATION_STYLE_CYBOL_MODEL_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

            if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                *s = SOCK_DGRAM;
            }
        }

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            compare_arrays(p1, p2, (void*) RAW_COMMUNICATION_STYLE_CYBOL_MODEL, (void*) RAW_COMMUNICATION_STYLE_CYBOL_MODEL_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

            if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                *s = SOCK_RAW;
            }
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not get startup socket style. The communication style is null.");
    }
}

/**
 * Gets the host address.
 *
 * @param p0 the ipv4 or ipv6 host address, depending on the address namespace (Hand over as reference!)
 * @param p1 the address model
 * @param p2 the address model count
 * @param p3 the address namespace
 */
void startup_socket_get_host_address(void* p0, void* p1, void* p2, void* p3) {

    if (p3 != *NULL_POINTER_MEMORY_MODEL) {

        int* an = (int*) p3;

        if (p2 != *NULL_POINTER_MEMORY_MODEL) {

            int* amc = (int*) p2;

            if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                struct in_addr* a4 = (struct in_addr*) *NULL_POINTER_MEMORY_MODEL;
                struct in6_addr* a6 = (struct in6_addr*) *NULL_POINTER_MEMORY_MODEL;

                if (*an == AF_INET) {

                    a4 = (struct in_addr*) p0;

                } else if (*an == AF_INET6) {

                    a6 = (struct in6_addr*) p0;
                }

                log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Startup socket get host address.");

                // The comparison result.
                int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_arrays(p1, p2, (void*) LOOPBACK_ADDRESS_CYBOL_MODEL, (void*) LOOPBACK_ADDRESS_CYBOL_MODEL_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        if (*an == AF_INET) {

                            (*a4).s_addr = INADDR_LOOPBACK;

                        } else if (*an == AF_INET6) {

                            *a6 = in6addr_loopback;
                        }
                    }
                }

                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_arrays(p1, p2, (void*) ANY_ADDRESS_CYBOL_MODEL, (void*) ANY_ADDRESS_CYBOL_MODEL_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        if (*an == AF_INET) {

                            (*a4).s_addr = INADDR_ANY;

                        } else if (*an == AF_INET6) {

                            *a6 = in6addr_any;
                        }
                    }
                }

                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    // If none of the above address models was found, then the given
                    // address is supposed to be the host address directly.

                    // The terminated address model.
                    char* s = (char*) *NULL_POINTER_MEMORY_MODEL;
                    int sc = *NUMBER_0_INTEGER_MEMORY_MODEL;
                    int ss = *NUMBER_0_INTEGER_MEMORY_MODEL;

                    // Allocate terminated address model.
                    allocate_array((void*) &s, (void*) &ss, (void*) CHARACTER_ARRAY_MEMORY_ABSTRACTION);

                    // Encode wide character name into multibyte character array.
                    encode_utf_8_unicode_character_vector((void*) &s, (void*) &sc, (void*) &ss, p1, p2);

                    if (ss <= sc) {

                        // Increase character array size to have place for the termination character.
                        ss = sc + *NUMBER_1_INTEGER_MEMORY_MODEL;

                        // Reallocate terminated file name as multibyte character array.
                        reallocate_array((void*) &s, (void*) &sc, (void*) &ss, (void*) CHARACTER_ARRAY_MEMORY_ABSTRACTION);
                    }

                    // Add null termination character to terminated file name.
                    set_array_elements(s, (void*) &sc, (void*) NULL_CONTROL_ASCII_CHARACTER_CODE_MODEL, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) CHARACTER_ARRAY_MEMORY_ABSTRACTION);

                    // Convert uint16_t integer hostshort from host byte order
                    // to network byte order.
                    inet_pton(*an, s, p0);

                    // Deallocate terminated address model.
                    deallocate_array((void*) &s, (void*) &ss, (void*) CHARACTER_ARRAY_MEMORY_ABSTRACTION);
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not get startup socket host address. The host address is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not get startup socket host address. The address model count is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not get startup socket host address. The address namespace is null.");
    }
}

/**
 * Initialises the local socket address.
 *
 * @param p0 the local socket address (Hand over as reference!)
 * @param p1 the file name
 * @param p2 the file name count
 */
void startup_socket_initialise_local_socket_address(void* p0, void* p1, void* p2) {

    if (p2 != *NULL_POINTER_MEMORY_MODEL) {

        int* fc = (int*) p2;

        if (p1 != *NULL_POINTER_MEMORY_MODEL) {

            wchar_t* f = (wchar_t*) p1;

            if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                // CAUTION! The compiler brings an error if the "struct sockaddr_un"
                // type is used, because pointer calculation is done below!
                // Therefore, a cast to void** is done here instead.
                void** a = (void**) p0;

                log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Startup socket initialise local socket address.");

                // Determine position of namespace
                // ("sun_family" field within the "sockaddr_un" structure).
                //
                // Do NOT access the "sun_family" field directly with:
                // (*a)->sun_family = AF_LOCAL;
                // It won't work because the "sockaddr_un" structure, due to
                // the unknown size of its "sun_path" field (a character array),
                // is considered an incomplete type, so that the compiler
                // brings an error.
                short int* family = (short int*) (*a + *NUMBER_0_INTEGER_MEMORY_MODEL);

                // Set namespace (address format/ family).
                //
                // CAUTION! Use the prefix "AF_" here and NOT "PF_"!
                // The latter is to be used for socket creation.
                *family = AF_LOCAL;

                // CAUTION! For some strange reason, the socket file name length
                // is limited to 108 ascii characters in the gnu c library!
                // The documentation called it a "magic number" and does not
                // know why this limit exists.
                if (*fc < *NUMBER_108_INTEGER_MEMORY_MODEL) {

                    // CAUTION! Do NOT reallocate the file name array with:
                    // int nc = *fc + *NUMBER_1_INTEGER_MEMORY_MODEL;
                    // reallocate_array((void*) &((*a)->sun_path), p2, (void*) &nc, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
                    //
                    // The reason is that the size of the "sun_path" field of
                    // the "sockaddr_un" structure had to be fixed (to 108,
                    // for reasons explained above), in order to be able to
                    // calculate the overall size of the "sockaddr_un" structure.
                    //
                    // It is no problem if the "sun_path" array size is greater
                    // than the actual file name size, since the file name is
                    // terminated with a null character.

                    // Determine position of file name
                    // ("sun_path" field within the "sockaddr_un" structure).
                    //
                    // Do NOT access the "sun_path" field directly with:
                    // (*a)->sun_path
                    // It won't work because the "sockaddr_un" structure, due to
                    // the unknown size of its "sun_path" field (a character array),
                    // is considered an incomplete type, so that the compiler
                    // brings an error.
                    void* path = (void*) (*a + sizeof(short int));

                    // Set terminated file name by first copying the actual name
                    // and then adding the null termination character.
                    set_array_elements(path, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, p1, p2, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
                    set_array_elements(path, p2, (void*) NULL_CONTROL_ASCII_CHARACTER_CODE_MODEL, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

                } else {

                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not initialise local socket address. The socket file name is longer than the limit 108, as set by the gnu c library.");
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not initialise local socket address. The socket address is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not initialise local socket address. The file name is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not initialise local socket address. The file name count is null.");
    }
}

/**
 * Initialises the ipv4 socket address.
 *
 * @param p0 the ipv4 socket address (Hand over as reference!)
 * @param p1 the host address (in network byte order)
 * @param p2 the socket port (in host byte order)
 */
void startup_socket_initialise_ipv4_socket_address(void* p0, void* p1, void* p2) {

    if (p2 != *NULL_POINTER_MEMORY_MODEL) {

        int* p = (int*) p2;

        if (p1 != *NULL_POINTER_MEMORY_MODEL) {

            int* h = (int*) p1;

            if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                struct sockaddr_in** a = (struct sockaddr_in**) p0;

                log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Startup socket initialise ipv4 socket address.");

                // Set namespace (address format/ family).
                //
                // CAUTION! Use the prefix "AF_" here and NOT "PF_"!
                // The latter is to be used for socket creation.
                (*a)->sin_family = AF_INET;

                // Set host address.
                //
                // The "a.sin_addr" field is of type "struct in_addr".
                // This data type is used in certain contexts to contain an
                // IPv4 internet host address. It has just one field, named
                // "s_addr", which records the host address number as an "uint32_t".
                //
                // CAUTION! The host address parameter is already given in
                // network byte order, so that it does NOT have to be converted!
                (*a)->sin_addr.s_addr = *h;

                // Set socket port.
                //
                // CAUTION! The port number is given in host byte order and
                // HAS TO BE converted into network byte order!
                (*a)->sin_port = htons(*p);

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not initialise ipv4 socket address. The socket address is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not initialise ipv4 socket address. The host address is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not initialise ipv4 socket address. The socket port is null.");
    }
}

/**
 * Initialises the ipv6 socket address.
 *
 * @param p0 the ipv6 socket address (Hand over as reference!)
 * @param p1 the host address (in network byte order)
 * @param p2 the socket port (in host byte order)
 */
void startup_socket_initialise_ipv6_socket_address(void* p0, void* p1, void* p2) {

    if (p2 != *NULL_POINTER_MEMORY_MODEL) {

        int* p = (int*) p2;

        if (p1 != *NULL_POINTER_MEMORY_MODEL) {

            struct in6_addr* h = (struct in6_addr*) p1;

            if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                struct sockaddr_in6** a = (struct sockaddr_in6**) p0;

                log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Startup socket initialise ipv6 socket address.");

                // Set namespace (address format/ family).
                //
                // CAUTION! Use the prefix "AF_" here and NOT "PF_"!
                // The latter is to be used for socket creation.
                (*a)->sin6_family = AF_INET6;

                // Set host address.
                //
                // The "a.sin_addr" field is of type "struct in_addr".
                // This data type is used in certain contexts to contain an
                // IPv4 internet host address. It has just one field, named
                // "s_addr", which records the host address number as an "uint32_t".
                //
                // CAUTION! The host address parameter is already given in
                // network byte order, so that it does NOT have to be converted!
                (*a)->sin6_addr = *h;

                // Set flow information.
                //
                // CAUTION! This is a currently unimplemented field,
                // as written in the gnu c library documentation.
                // (*a)->sin6_flowinfo = ??

                // Set socket port.
                //
                // CAUTION! The port number is given in host byte order and
                // HAS TO BE converted into network byte order!
                (*a)->sin6_port = htons(*p);

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not initialise ipv6 socket address. The socket address is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not initialise ipv6 socket address. The host address is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not initialise ipv6 socket address. The socket port is null.");
    }
}

/**
 * Starts up socket.
 *
 * @param p0 the internal memory
 * @param p1 the namespace model
 * @param p2 the namespace model count
 * @param p3 the style model
 * @param p4 the style model count
 * @param p5 the socket file name or host address model, depending on the socket type (local, ipv4, ipv6)
 * @param p6 the socket file name or host address model count
 * @param p7 the port model
 * @param p8 the base internal
 * @param p9 the knowledge memory
 * @param p10 the knowledge memory count
 * @param p11 the knowledge memory size
 */
void startup_socket(void* p0, void* p1, void* p2, void* p3, void* p4,
    void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11) {

    if (p8 != *NULL_POINTER_MEMORY_MODEL) {

        int* base = (int*) p8;

        log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Startup socket.");

        // The socket namespace.
        int sn = *NUMBER_MINUS_1_INTEGER_MEMORY_MODEL;
        // The address namespace.
        int an = *NUMBER_MINUS_1_INTEGER_MEMORY_MODEL;
        // The communication style.
        int st = *NUMBER_MINUS_1_INTEGER_MEMORY_MODEL;
        // The ipv4 host address of this system.
        struct in_addr ha4;
        // The ipv6 host address of this system.
        struct in6_addr ha6;
        // CAUTION! Do use pointers for the addresses declared below,
        // and not only the structure as type, so that the different
        // socket addresses can be processed uniformly below!
        // The local socket address of this system.
        struct sockaddr_un* la = (struct sockaddr_un*) *NULL_POINTER_MEMORY_MODEL;
        // The ipv4 internet socket address of this system.
        struct sockaddr_in* ia4 = (struct sockaddr_in*) *NULL_POINTER_MEMORY_MODEL;
        // The ipv6 internet socket address of this system.
        struct sockaddr_in6* ia6 = (struct sockaddr_in6*) *NULL_POINTER_MEMORY_MODEL;
        // The communication partner local socket address.
        struct sockaddr_un* pla = (struct sockaddr_un*) *NULL_POINTER_MEMORY_MODEL;
        // The communication partner ipv4 internet socket address.
        struct sockaddr_in* pia4 = (struct sockaddr_in*) *NULL_POINTER_MEMORY_MODEL;
        // The communication partner ipv6 internet socket address.
        struct sockaddr_in6* pia6 = (struct sockaddr_in6*) *NULL_POINTER_MEMORY_MODEL;
        // The socket address size of this system.
        int* as = (int*) *NULL_POINTER_MEMORY_MODEL;
        // The communication partner socket address size.
        int* pas = (int*) *NULL_POINTER_MEMORY_MODEL;
        // The socket of this system.
        int* s = (int*) *NULL_POINTER_MEMORY_MODEL;
        // The communication partner socket.
        int* ps = (int*) *NULL_POINTER_MEMORY_MODEL;
/*??
        // The signal ids.
        void* id = *NULL_POINTER_MEMORY_MODEL;
        int* idc = (int*) *NULL_POINTER_MEMORY_MODEL;
        int* ids = (int*) *NULL_POINTER_MEMORY_MODEL;
*/
        // The character buffer being used in the thread procedure receiving messages via socket.
        void* b = *NULL_POINTER_MEMORY_MODEL;
        int* bc = (int*) *NULL_POINTER_MEMORY_MODEL;
        int* bs = (int*) *NULL_POINTER_MEMORY_MODEL;
        // The internal memory index.
        int i = *NUMBER_MINUS_1_INTEGER_MEMORY_MODEL;
        // The result.
        int r = *NUMBER_MINUS_1_INTEGER_MEMORY_MODEL;

        // Get socket- and address namespace.
        startup_socket_get_namespace((void*) &sn, (void*) &an, p1, p2);
        // Get socket communication style.
        startup_socket_get_style((void*) &st, p3, p4);

        // Get host address constant.
        if (an == AF_INET) {

            startup_socket_get_host_address((void*) &ha4, p5, p6, (void*) &an);

        } else if (an == AF_INET6) {

            startup_socket_get_host_address((void*) &ha6, p5, p6, (void*) &an);
        }

        // Allocate socket address size of this system.
        allocate((void*) &as, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION_COUNT);
        // Allocate communication partner socket address size.
        allocate((void*) &pas, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION_COUNT);
        // Allocate socket of this system.
        allocate((void*) &s, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION_COUNT);
        // Allocate communication partner socket.
        allocate((void*) &ps, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION_COUNT);
/*??
        // Allocate signal ids.
        allocate((void*) &idc, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION_COUNT);
        allocate((void*) &ids, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION_COUNT);
        allocate_array((void*) &id, (void*) ids, (void*) INTEGER_ARRAY_MEMORY_ABSTRACTION);
*/

        // Initialise socket address size of this system.
        // Initialise communication partner socket address size.
        if (an == AF_LOCAL) {

            // CAUTION! The following line CANNOT be used:
            // *as = sizeof(struct sockaddr_un);
            // because the compiler brings the error
            // "invalid application of 'sizeof' to incomplete type 'struct sockaddr_un'".
            // The reason is the "sun_path" field of the "sockaddr_un" structure,
            // which is a character array whose size is unknown at compilation time.
            //
            // The size of the "sun_path" character array is therefore set
            // to the fixed size of 108.
            // The number "108" is the limit as set by the gnu c library!
            // Its documentation called it a "magic number" and does not
            // know why this limit exists.
            //
            // With the known type "short int" of the "sun_family" field and
            // a fixed size "108" of the "sun_path" field, the overall size of
            // the "sockaddr_un" structure can be calculated as sum.
            *as = sizeof(short int) + *NUMBER_108_INTEGER_MEMORY_MODEL;
            *pas = sizeof(short int) + *NUMBER_108_INTEGER_MEMORY_MODEL;

        } else if (an == AF_INET) {

            *as = sizeof(struct sockaddr_in);
            *pas = sizeof(struct sockaddr_in);

        } else if (an == AF_INET6) {

            *as = sizeof(struct sockaddr_in6);
            *pas = sizeof(struct sockaddr_in6);
        }

        // Allocate socket address of this system.
        // Allocate communication partner socket address.
        if (an == AF_LOCAL) {

            la = (struct sockaddr_un*) malloc(*as);
            pla = (struct sockaddr_un*) malloc(*pas);

        } else if (an == AF_INET) {

            ia4 = (struct sockaddr_in*) malloc(*as);
            pia4 = (struct sockaddr_in*) malloc(*pas);

        } else if (an == AF_INET6) {

            ia6 = (struct sockaddr_in6*) malloc(*as);
            pia6 = (struct sockaddr_in6*) malloc(*pas);
        }

        // Initialise socket address of this system.
        // CAUTION! Do NOT initialise communication partner socket address!
        // It gets initialised only before sending, or at reception of a message.
        if (an == AF_LOCAL) {

            startup_socket_initialise_local_socket_address((void*) &la, p5, p6);

        } else if (an == AF_INET) {

            startup_socket_initialise_ipv4_socket_address((void*) &ia4, (void*) &ha4, p7);

        } else if (an == AF_INET6) {

            startup_socket_initialise_ipv6_socket_address((void*) &ia6, (void*) &ha6, p7);
        }

/*??
        // Initialise signal ids.
        *idc = *NUMBER_0_INTEGER_MEMORY_MODEL;
        *ids = *NUMBER_0_INTEGER_MEMORY_MODEL;
*/

        // Allocate character buffer count and size.
        allocate((void*) &bc, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION_COUNT);
        allocate((void*) &bs, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION_COUNT);

        // Initialise character buffer count, size.
        // A possible initial size is 2048, which should
        // suffice for transferring standard data over tcp/ip.
        // Another possible size could be 8192.
        *bc = *NUMBER_0_INTEGER_MEMORY_MODEL;
        *bs = *NUMBER_8192_INTEGER_MEMORY_MODEL;

        // Allocate character buffer.
        //
        // CAUTION! Allocate character buffer only AFTER
        // the buffer size has been initialised above!
        allocate((void*) &b, (void*) bs, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT);

        // Set socket address of this system.
        // Set communication partner socket address.
        if (an == AF_LOCAL) {

            i = *base + *SOCKET_ADDRESS_INTERNAL_MEMORY_MEMORY_NAME;
            set_element(p0, (void*) &i, (void*) &la, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
            i = *base + *SOCKET_COMMUNICATION_PARTNER_ADDRESS_INTERNAL_MEMORY_MEMORY_NAME;
            set_element(p0, (void*) &i, (void*) &pla, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);

        } else if (an == AF_INET) {

            i = *base + *SOCKET_ADDRESS_INTERNAL_MEMORY_MEMORY_NAME;
            set_element(p0, (void*) &i, (void*) &ia4, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
            i = *base + *SOCKET_COMMUNICATION_PARTNER_ADDRESS_INTERNAL_MEMORY_MEMORY_NAME;
            set_element(p0, (void*) &i, (void*) &pia4, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);

        } else if (an == AF_INET6) {

            i = *base + *SOCKET_ADDRESS_INTERNAL_MEMORY_MEMORY_NAME;
            set_element(p0, (void*) &i, (void*) &ia6, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
            i = *base + *SOCKET_COMMUNICATION_PARTNER_ADDRESS_INTERNAL_MEMORY_MEMORY_NAME;
            set_element(p0, (void*) &i, (void*) &pia6, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
        }

        // Set socket address size of this system.
        i = *base + *SOCKET_ADDRESS_SIZE_INTERNAL;
        set_element(p0, (void*) &i, (void*) &as, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
        // Set communication partner socket address size.
        i = *base + *SOCKET_COMMUNICATION_PARTNER_ADDRESS_SIZE_INTERNAL;
        set_element(p0, (void*) &i, (void*) &pas, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
        // Set socket of this system.
        i = *base + *SOCKET_INTERNAL_MEMORY_MEMORY_NAME;
        set_element(p0, (void*) &i, (void*) &s, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
        // Set communication partner socket.
        i = *base + *SOCKET_COMMUNICATION_PARTNER_INTERNAL_MEMORY_MEMORY_NAME;
        set_element(p0, (void*) &i, (void*) &ps, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
        // Set character buffer.
        i = *base + *SOCKET_CHARACTER_BUFFER_INTERNAL_MEMORY_MEMORY_NAME;
        set_element(p0, (void*) &i, (void*) &b, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
        i = *base + *SOCKET_CHARACTER_BUFFER_COUNT_INTERNAL_MEMORY_MEMORY_NAME;
        set_element(p0, (void*) &i, (void*) &bc, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
        i = *base + *SOCKET_CHARACTER_BUFFER_SIZE_INTERNAL_MEMORY_MEMORY_NAME;
        set_element(p0, (void*) &i, (void*) &bs, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);

/*??
        // Set signal ids.
        set_element(p0, (void*) TCP_CLIENT_SOCKET_SIGNAL_IDS_INTERNAL, (void*) &id, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
        set_element(p0, (void*) TCP_CLIENT_SOCKET_SIGNAL_IDS_COUNT_INTERNAL, (void*) &idc, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
        set_element(p0, (void*) TCP_CLIENT_SOCKET_SIGNAL_IDS_SIZE_INTERNAL, (void*) &ids, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
*/

        // Initialise error number.
        // It is a global variable/ function and other operations
        // may have set some value that is not wanted here.
        //
        // CAUTION! Initialise the error number BEFORE calling the procedure
        // that might cause an error.
        errno = *NUMBER_0_INTEGER_MEMORY_MODEL;

        // Initialise server socket.
        //
        // param 0: namespace
        // param 1: style
        // param 2: protocol
        //
        // CAUTION! Use prefix "PF_" here and NOT "AF_"!
        // The latter is to be used for address family assignment.
        // See further below!
        *s = socket(sn, st, *NUMBER_0_INTEGER_MEMORY_MODEL);

        if (*s >= *NUMBER_0_INTEGER_MEMORY_MODEL) {

            // Set non-blocking mode for the socket file descriptor.
            //
            // If the O_NONBLOCK flag (a bit) is set, read requests on the socket
            // (file) can return immediately with a failure status if there is no
            // input immediately available, instead of blocking. Likewise, write
            // requests can also return immediately with a failure status if the
            // output can't be written immediately.
            //
            // CAUTION! The "select" procedure was NOT used to make this socket
            // non-blocking, because it has some overhead in that other sockets
            // need to be considered and their file descriptors handed over as
            // parameter.
            // A simple "sleep" procedure is considered to be a more simple and
            // clean solution here.

/*??
            // Get file status flags.
            int fl = fcntl(*s, F_GETFL, NUMBER_0_INTEGER);

            if (fl != *NUMBER_MINUS_1_INTEGER_MEMORY_MODEL) {

                // Set non-blocking flag (bit).
                fl |= O_NONBLOCK;

                // Store modified flag word in the file descriptor.
                fcntl(*s, F_SETFL, fl);

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not start up socket / set non-blocking mode. The socket file descriptor flags could not be read.");
            }
*/

            // Initialise error number.
            // It is a global variable/ function and other operations
            // may have set some value that is not wanted here.
            //
            // CAUTION! Initialise the error number BEFORE calling the procedure
            // that might cause an error.
            errno = *NUMBER_0_INTEGER_MEMORY_MODEL;

            // Bind socket number to socket address.
            if (an == AF_LOCAL) {

                r = bind(*s, (struct sockaddr*) la, *((socklen_t*) as));

            } else if (an == AF_INET) {

                r = bind(*s, (struct sockaddr*) ia4, *((socklen_t*) as));

    fwprintf(stderr, L"TEST: startup socket bind s: %i \n", *s);
    sleep(2);

            } else if (an == AF_INET6) {

                r = bind(*s, (struct sockaddr*) ia6, *((socklen_t*) as));
            }

            if (r >= *NUMBER_0_INTEGER_MEMORY_MODEL) {

                if (st == SOCK_STREAM) {

                    // Reset result.
                    r = *NUMBER_MINUS_1_INTEGER_MEMORY_MODEL;

                    // Initialise error number.
                    // It is a global variable/ function and other operations
                    // may have set some value that is not wanted here.
                    //
                    // CAUTION! Initialise the error number BEFORE calling the procedure
                    // that might cause an error.
                    errno = *NUMBER_0_INTEGER_MEMORY_MODEL;

                    // CAUTION! Datagram sockets do NOT have connections,
                    // which is why the "listen" procedure is only called
                    // for stream sockets here.

                    // Enable socket to accept connections, thus making it a server socket.
                    // The second parameter determines the number of possible
                    // pending client connection requests.
                    r = listen(*s, *NUMBER_1_INTEGER_MEMORY_MODEL);

    fwprintf(stderr, L"TEST: startup socket listen s: %i \n", *s);
    sleep(2);

                    if (r < *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        if (errno == EBADF) {

                            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not start up socket. The argument socket is not a valid file descriptor.");

                        } else if (errno == ENOTSOCK) {

                            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not start up socket. The argument socket is not a socket.");

                        } else if (errno == EOPNOTSUPP) {

                            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not start up socket. The socket does not support this operation.");

                        } else {

                            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not start up socket. An unknown error occured while listening at the socket.");
                        }
                    }
                }

            } else {

                if (errno == EBADF) {

                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not start up socket. The socket argument is not a valid file descriptor.");

                } else if (errno == ENOTSOCK) {

                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not start up socket. The descriptor socket is not a socket.");

                } else if (errno == EADDRNOTAVAIL) {

                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not start up socket. The specified address is not available on this machine.");

                } else if (errno == EADDRINUSE) {

                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not start up socket. The specified address is already used by some other socket.");

                } else if (errno == EINVAL) {

                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not start up socket. The socket socket already has an address.");

                } else if (errno == EACCES) {

                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not start up socket. The permission to access the requested address is missing. (In the internet domain, only the super-user is allowed to specify a port number in the range 0 through IPPORT_RESERVED minus one; see the section called 'Internet Ports'.");

                } else {

                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not start up socket. An unknown error occured while binding the socket to the address.");
                }
            }

        } else {

            if (errno == EPROTONOSUPPORT) {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not start up socket. The protocol or style is not supported by the namespace specified.");

            } else if (errno == EMFILE) {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not start up socket. The process already has too many file descriptors open.");

            } else if (errno == ENFILE) {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not start up socket. The system already has too many file descriptors open.");

            } else if (errno == EACCES) {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not start up socket. The process does not have the privilege to create a socket of the specified style or protocol.");

            } else if (errno == ENOBUFS) {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not start up socket. The system ran out of internal buffer space.");

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not start up socket. An unknown error occured while initialising the socket.");
            }
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not start up socket. The base internal is null.");
    }
}

/* GNU_LINUX_OPERATING_SYSTEM */
#endif

/* SOCKET_STARTER_SOURCE */
#endif
