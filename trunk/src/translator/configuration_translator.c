/*
 * $RCSfile: configuration_translator.c,v $
 *
 * Copyright (c) 1999-2005. Christian Heller. All rights reserved.
 *
 * This software is published under the GPL GNU General Public License.
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
 * @version $Revision: 1.15 $ $Date: 2005-03-21 01:26:59 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 * @author Rolf Holzmueller <rolf.holzmueller@gmx.de>
 */

#ifndef CONFIGURATION_TRANSLATOR_SOURCE
#define CONFIGURATION_TRANSLATOR_SOURCE

#include <libxml/tree.h>
#include "../array/array.c"
#include "../creator/integer_creator.c"
#include "../logger/logger.c"
#include "../translator/cybol_translator.c"

//
// Forward declarations.
//

/**
 * Creates a model.
 *
 * @param p0 the destination
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source model
 * @param p4 the source model count
 * @param p5 the source abstraction
 * @param p6 the source abstraction count
 * @param p7 the source channel
 * @param p8 the source channel count
 */
void create_model(void* p0, void* p1, void* p2, const void* p3, const void* p4,
    const void* p5, const void* p6, const void* p7, const void* p8);

//
// Configuration node.
//

/**
 * Decodes the configuration node into a compound.
 *
 * @param p0 the destination (internals memory) (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source (libxml2 xml node)
 * @param p4 the source count
 */
void decode_configuration_node(void* p0, void* p1, void* p2, const void* p3, const void* p4) {

    if (p3 != NULL_POINTER) {

        xmlNode* s = (xmlNode*) p3;

        if (p0 != NULL_POINTER) {

            void** d = (void**) p0;

            if (s != NULL_POINTER) {

                log_message_debug("Decode configuration node.");

                // Determine first child node.
                xmlNode* c = s->children;
                // The source name.
                void* sn = NULL_POINTER;
                int snc = 0;
                // The source channel.
                void* sc = NULL_POINTER;
                int scc = 0;
                // The source abstraction.
                void* sa = NULL_POINTER;
                int sac = 0;
                // The source model.
                void* sm = NULL_POINTER;
                int smc = 0;
                // The destination model.
                void* dm = NULL_POINTER;
                int* dmc = INTEGER_NULL_POINTER;
                int* dms = INTEGER_NULL_POINTER;
                // The comparison result.
                int r = 0;

                while (1) {

                    if (c == NULL_POINTER) {

                        break;
                    }

                    if (c->type == XML_ELEMENT_NODE) {

                        // Decode child node properties.
                        decode_cybol_property(
                            (void*) &sn, (void*) &snc, (void*) &sc, (void*) &scc,
                            (void*) &sa, (void*) &sac, (void*) &sm, (void*) &smc,
                            (void*) c);

        fprintf(stderr, "sn: %s\n", (char*) sn);
        fprintf(stderr, "snc: %i\n", snc);
        fprintf(stderr, "sc: %s\n", (char*) sc);
        fprintf(stderr, "scc: %i\n", scc);
        fprintf(stderr, "sa: %s\n", (char*) sa);
        fprintf(stderr, "sac: %i\n", sac);
        fprintf(stderr, "sm: %s\n", (char*) sm);
        fprintf(stderr, "smc: %i\n", smc);

                        if (r != 1) {

                            compare_arrays(sn, (void*) &snc, (void*) STARTUP_CHANNEL_CONFIGURATION_NAME, (void*) STARTUP_CHANNEL_CONFIGURATION_NAME_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                            if (r == 1) {

                                log_message_debug("Found startup channel configuration name.");

                                // Create destination model.
                                create_integer((void*) &dmc);
                                *dmc = 0;
                                create_integer((void*) &dms);
                                *dms = 0;
                                create_model((void*) &dm, (void*) dmc, (void*) dms,
                                    sm, (void*) &smc,
                                    sa, (void*) &sac,
                                    sc, (void*) &scc);

                                // Set configuration parameter in internals memory.
                                set_array_elements(*d, (void*) STARTUP_CHANNEL_INTERNAL, (void*) &dm, (void*) ONE_NUMBER, (void*) POINTER_ARRAY);
                                set_array_elements(*d, (void*) STARTUP_CHANNEL_COUNT_INTERNAL, (void*) &dmc, (void*) ONE_NUMBER, (void*) POINTER_ARRAY);
                                set_array_elements(*d, (void*) STARTUP_CHANNEL_SIZE_INTERNAL, (void*) &dms, (void*) ONE_NUMBER, (void*) POINTER_ARRAY);
                            }
                        }

                        if (r != 1) {

                            compare_arrays(sn, (void*) &snc, (void*) STARTUP_ABSTRACTION_CONFIGURATION_NAME, (void*) STARTUP_ABSTRACTION_CONFIGURATION_NAME_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                            if (r == 1) {

                                log_message_debug("Found startup abstraction configuration name.");

                                // Create destination model.
                                create_integer((void*) &dmc);
                                *dmc = 0;
                                create_integer((void*) &dms);
                                *dms = 0;
                                create_model((void*) &dm, (void*) dmc, (void*) dms,
                                    sm, (void*) &smc,
                                    sa, (void*) &sac,
                                    sc, (void*) &scc);

                                // Set configuration parameter in internals memory.
                                set_array_elements(*d, (void*) STARTUP_ABSTRACTION_INTERNAL, (void*) &dm, (void*) ONE_NUMBER, (void*) POINTER_ARRAY);
                                set_array_elements(*d, (void*) STARTUP_ABSTRACTION_COUNT_INTERNAL, (void*) &dmc, (void*) ONE_NUMBER, (void*) POINTER_ARRAY);
                                set_array_elements(*d, (void*) STARTUP_ABSTRACTION_SIZE_INTERNAL, (void*) &dms, (void*) ONE_NUMBER, (void*) POINTER_ARRAY);
                            }
                        }

                        if (r != 1) {

                            compare_arrays(sn, (void*) &snc, (void*) STARTUP_MODEL_CONFIGURATION_NAME, (void*) STARTUP_MODEL_CONFIGURATION_NAME_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                            if (r == 1) {

                                log_message_debug("Found startup model configuration name.");

                                // Create destination model.
                                create_integer((void*) &dmc);
                                *dmc = 0;
                                create_integer((void*) &dms);
                                *dms = 0;
                                create_model((void*) &dm, (void*) dmc, (void*) dms,
                                    sm, (void*) &smc,
                                    sa, (void*) &sac,
                                    sc, (void*) &scc);

                                // Set configuration parameter in internals memory.
                                set_array_elements(*d, (void*) STARTUP_MODEL_INTERNAL, (void*) &dm, (void*) ONE_NUMBER, (void*) POINTER_ARRAY);
                                set_array_elements(*d, (void*) STARTUP_MODEL_COUNT_INTERNAL, (void*) &dmc, (void*) ONE_NUMBER, (void*) POINTER_ARRAY);
                                set_array_elements(*d, (void*) STARTUP_MODEL_SIZE_INTERNAL, (void*) &dms, (void*) ONE_NUMBER, (void*) POINTER_ARRAY);
                            }
                        }

                        if (r != 1) {

                            compare_arrays(sn, (void*) &snc, (void*) UNIX_SERVER_SOCKET_ACTIVE_CONFIGURATION_NAME, (void*) UNIX_SERVER_SOCKET_ACTIVE_CONFIGURATION_NAME_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                            if (r == 1) {

                                log_message_debug("Found unix server socket active configuration name.");

                                // Create destination model.
                                create_model((void*) &dm, (void*) ONE_NUMBER, (void*) ONE_NUMBER,
                                    sm, (void*) &smc,
                                    sa, (void*) &sac,
                                    sc, (void*) &scc);

                                // Set configuration parameter in internals memory.
                                set_array_elements(*d, (void*) UNIX_SERVER_SOCKET_ACTIVE_INTERNAL, (void*) &dm, (void*) ONE_NUMBER, (void*) POINTER_ARRAY);
                            }
                        }

                        if (r != 1) {

                            compare_arrays(sn, (void*) &snc, (void*) UNIX_SERVER_SOCKET_FILENAME_CONFIGURATION_NAME, (void*) UNIX_SERVER_SOCKET_FILENAME_CONFIGURATION_NAME_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                            if (r == 1) {

                                log_message_debug("Found unix server socket filename configuration name.");

                                // Create destination model.
                                create_model((void*) &dm, (void*) ONE_NUMBER, (void*) ONE_NUMBER,
                                    sm, (void*) &smc,
                                    sa, (void*) &sac,
                                    sc, (void*) &scc);

                                // Set configuration parameter in internals memory.
                                set_array_elements(*d, (void*) UNIX_SERVER_SOCKET_FILENAME_INTERNAL, (void*) &dm, (void*) ONE_NUMBER, (void*) POINTER_ARRAY);
                            }
                        }

                        if (r != 1) {

                            compare_arrays(sn, (void*) &snc, (void*) TCP_SERVER_SOCKET_ACTIVE_CONFIGURATION_NAME, (void*) TCP_SERVER_SOCKET_ACTIVE_CONFIGURATION_NAME_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                            if (r == 1) {

                                log_message_debug("Found tcp server socket active configuration name.");

                                // Create destination model.
                                create_model((void*) &dm, (void*) ONE_NUMBER, (void*) ONE_NUMBER,
                                    sm, (void*) &smc,
                                    sa, (void*) &sac,
                                    sc, (void*) &scc);

                                // Set configuration parameter in internals memory.
                                set_array_elements(*d, (void*) TCP_SERVER_SOCKET_ACTIVE_INTERNAL, (void*) &dm, (void*) ONE_NUMBER, (void*) POINTER_ARRAY);
                            }
                        }

                        if (r != 1) {

                            compare_arrays(sn, (void*) &snc, (void*) TCP_SERVER_SOCKET_PORT_CONFIGURATION_NAME, (void*) TCP_SERVER_SOCKET_PORT_CONFIGURATION_NAME_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                            if (r == 1) {

                                log_message_debug("Found tcp server socket port configuration name.");

                                // Create destination model.
                                create_model((void*) &dm, (void*) ONE_NUMBER, (void*) ONE_NUMBER,
                                    sm, (void*) &smc,
                                    sa, (void*) &sac,
                                    sc, (void*) &scc);

                                // Set configuration parameter in internals memory.
                                set_array_elements(*d, (void*) TCP_SERVER_SOCKET_PORT_INTERNAL, (void*) &dm, (void*) ONE_NUMBER, (void*) POINTER_ARRAY);
                            }
                        }

                        // Reset source name.
                        sn = NULL_POINTER;
                        snc = 0;
                        // Reset source channel.
                        sc = NULL_POINTER;
                        scc = 0;
                        // Reset source abstraction.
                        sa = NULL_POINTER;
                        sac = 0;
                        // Reset source model.
                        sm = NULL_POINTER;
                        smc = 0;
                        // Reset destination model.
                        dm = NULL_POINTER;
                        dmc = INTEGER_NULL_POINTER;
                        dms = INTEGER_NULL_POINTER;
                        // Reset comparison result.
                        r = 0;
                    }

                    c = c->next;
                }

            } else {

//??                log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not translate xml node. The source is null.");
            }

        } else {

//??            log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not translate xml node. The source is null.");
        }

    } else {

//??        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not translate xml node. The source parameter is null.");
    }
}

/**
 * Encodes the internals memory into a configuration node.
 *
 * @param p0 the destination (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source
 * @param p4 the source count
 */
void encode_configuration_node(void* p0, void* p1, void* p2, const void* p3, const void* p4) {

    //
    // CONFIGURATION_ABSTRACTION
    //
    // CAUTION! Parameters of the internals memory MUST NOT be written
    // to the configuration file which was given at command line!
    // The CYBOI configuration file can only be edited MANUALLY.
    //
}

//
// Configuration model.
//

/**
 * Decodes the configuration model into an internals memory.
 *
 * @param p0 the destination (internals memory) (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source (parsed cybol/xml model)
 * @param p4 the source count
 */
void decode_configuration(void* p0, void* p1, void* p2, const void* p3, const void* p4) {

    //??
    //?? BEGIN of temporary workaround for using the libxml2 parser.
    //?? The strings contained in the xml tree are terminated by a null character
    //?? which must be deleted for the cyboi model,
    //?? or neglected in the "count" number!
    //??

    if (p4 != NULL_POINTER) {

        int* sc = (int*) p4;

        if (p0 != NULL_POINTER) {

            void** d = (void**) p0;

            log_message_debug("Decode configuration.");

            // Get root element node.
            xmlNode* r = xmlDocGetRootElement((xmlDoc*) p3);

            decode_configuration_node(p0, p1, p2, (void*) r, p4);

        } else {

//??            log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not translate xml. The destination is null.");
        }

    } else {

//??        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not translate xml. The source count is null.");
    }

    //??
    //?? END of temporary workaround for using the libxml2 parser.
    //??
}

/**
 * Encodes the internals memory into a configuration model.
 *
 * @param p0 the destination (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source
 * @param p4 the source count
 */
void encode_configuration(void* p0, void* p1, void* p2, const void* p3, const void* p4) {

    //
    // CONFIGURATION_ABSTRACTION
    //
    // CAUTION! Parameters of the internals memory MUST NOT be written
    // to the configuration file which was given at command line!
    // The CYBOI configuration file can only be edited MANUALLY.
    //
}

/* CONFIGURATION_TRANSLATOR_SOURCE */
#endif
