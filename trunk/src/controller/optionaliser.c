/*
 * $RCSfile: optionaliser.c,v $
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
 * @version $Revision: 1.10 $ $Date: 2008-05-06 22:36:52 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef OPTIONALISER_SOURCE
#define OPTIONALISER_SOURCE

#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include "../globals/constants/character/character_constants.c"
#include "../globals/constants/command_line/command_line_constants.c"
#include "../globals/constants/cyboi/cyboi_operation_mode_constants.c"
#include "../globals/constants/cybol/cybol_abstraction_constants.c"
#include "../globals/constants/integer/integer_constants.c"
#include "../globals/constants/log/log_level_constants.c"
#include "../globals/constants/memory_structure/array_constants.c"
#include "../globals/constants/memory_structure/memory_structure_constants.c"
#include "../globals/constants/pointer/pointer_constants.c"

/**
 * Optionalises the knowledge option.
 *
 * @param p0 the cybol knowledge file name
 * @param p1 the cybol knowledge file name count
 * @param p2 the file name value
 * @param p3 the file name value count
 */
void optionalise_knowledge(void* p0, void* p1, void* p2, void* p3) {

    if (p3 != *NULL_POINTER) {

        int* fc = (int*) p3;

        if (p2 != *NULL_POINTER) {

            void** f = (void**) p2;

            if (p1 != *NULL_POINTER) {

                int* kc = (int*) p1;

                if (p0 != *NULL_POINTER) {

                    void** k = (void**) p0;

                    // CAUTION! DO NOT use logging functionality here!
                    // The logger will not work before its options are set.
                    // fputws(L"Debug: Optionalise knowledge.\n", stdout);

                    // Set cybol knowledge file name.
                    *k = *f;
                    *kc = *fc;

                } else {

                    // CAUTION! DO NOT use logging functionality here!
                    // The logger will not work before its options are set.
                    fputws(L"Error: Could not optionalise knowledge. The knowledge is null.\n", stdout);
                }

            } else {

                // CAUTION! DO NOT use logging functionality here!
                // The logger will not work before its options are set.
                fputws(L"Error: Could not optionalise knowledge. The knowledge count is null.\n", stdout);
            }

        } else {

            // CAUTION! DO NOT use logging functionality here!
            // The logger will not work before its options are set.
            fputws(L"Error: Could not optionalise knowledge. The cybol file name is null.\n", stdout);
        }

    } else {

        // CAUTION! DO NOT use logging functionality here!
        // The logger will not work before its options are set.
        fputws(L"Error: Could not optionalise knowledge. The cybol file name count is null.\n", stdout);
    }
}

/**
 * Optionalises the log level option.
 *
 * @param p0 the log level
 * @param p1 the log level name
 * @param p2 the log level name count
 */
void optionalise_log_level(void* p0, void* p1, void* p2) {

    if (p0 != *NULL_POINTER) {

        int* l = (int*) p0;

        // CAUTION! DO NOT use logging functionality here!
        // The logger will not work before its options are set.
        // fputws(L"Debug: Optionalise log level.\n", stdout);

        // The comparison result.
        int r = *NUMBER_0_INTEGER;

        if (r == *NUMBER_0_INTEGER) {

            compare_arrays(p1, p2, (void*) OFF_LOG_LEVEL_COMMAND_LINE_VALUE, (void*) OFF_LOG_LEVEL_COMMAND_LINE_VALUE_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY);

            if (r != *NUMBER_0_INTEGER) {

                // Set log level.
                *l = *OFF_LOG_LEVEL;
            }
        }

        if (r == *NUMBER_0_INTEGER) {

            compare_arrays(p1, p2, (void*) ERROR_LOG_LEVEL_COMMAND_LINE_VALUE, (void*) ERROR_LOG_LEVEL_COMMAND_LINE_VALUE_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY);

            if (r != *NUMBER_0_INTEGER) {

                // Set log level.
                *l = *ERROR_LOG_LEVEL;
            }
        }

        if (r == *NUMBER_0_INTEGER) {

            compare_arrays(p1, p2, (void*) WARNING_LOG_LEVEL_COMMAND_LINE_VALUE, (void*) WARNING_LOG_LEVEL_COMMAND_LINE_VALUE_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY);

            if (r != *NUMBER_0_INTEGER) {

                // Set log level.
                *l = *WARNING_LOG_LEVEL;
            }
        }

        if (r == *NUMBER_0_INTEGER) {

            compare_arrays(p1, p2, (void*) INFORMATION_LOG_LEVEL_COMMAND_LINE_VALUE, (void*) INFORMATION_LOG_LEVEL_COMMAND_LINE_VALUE_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY);

            if (r != *NUMBER_0_INTEGER) {

                // Set log level.
                *l = *INFORMATION_LOG_LEVEL;
            }
        }

        if (r == *NUMBER_0_INTEGER) {

            compare_arrays(p1, p2, (void*) DEBUG_LOG_LEVEL_COMMAND_LINE_VALUE, (void*) DEBUG_LOG_LEVEL_COMMAND_LINE_VALUE_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY);

            if (r != *NUMBER_0_INTEGER) {

                // Set log level.
                *l = *DEBUG_LOG_LEVEL;
            }
        }


        if (r == *NUMBER_0_INTEGER) {

            // CAUTION! DO NOT use logging functionality here!
            // The logger will not work before its options are set.
            fputws(L"Warning: Could not optionalise log level. The log level name is unknown.\n", stdout);
        }

    } else {

        // CAUTION! DO NOT use logging functionality here!
        // The logger will not work before its options are set.
        fputws(L"Error: Could not optionalise log level. The log level is null.\n", stdout);
    }
}

/**
 * Optionalises the log file option.
 *
 * @param p0 the log file descriptor
 * @param p1 the log file name
 * @param p2 the log file name count
 */
void optionalise_log_file(void* p0, void* p1, void* p2) {

    if (p2 != *NULL_POINTER) {

        int* nc = (int*) p2;

        if (p0 != *NULL_POINTER) {

            int* f = (int*) p0;

            // CAUTION! DO NOT use logging functionality here!
            // The logger will not work before its options are set.
            // fputws(L"Debug: Optionalise log file.\n", stdout);

            // The terminated file name.
            void* t = *NULL_POINTER;
            int ts = *nc + *NUMBER_1_INTEGER;

            // Allocate terminated file name.
            allocate_array((void*) &t, (void*) &ts, (void*) WIDE_CHARACTER_ARRAY);

            // Set terminated file name by first copying the actual name
            // and then adding the null termination character.
            set_array_elements(t, (void*) NUMBER_0_INTEGER, p1, p2, (void*) WIDE_CHARACTER_ARRAY);
            set_array_elements(t, p2, (void*) NULL_CONTROL_WIDE_CHARACTER, (void*) PRIMITIVE_COUNT, (void*) WIDE_CHARACTER_ARRAY);

            // The log file status flags.
            int s = O_TRUNC | O_CREAT | O_WRONLY;
            // The log file.
            *f = open((wchar_t*) t, s);

            if (*f >= *NUMBER_0_INTEGER) {

                // The file owner.
                int o = *NUMBER_MINUS_1_INTEGER;

                // The file group.
                int g = *NUMBER_MINUS_1_INTEGER;

                // Set file owner.
                chown((wchar_t*) t, o, g);

                // The file access rights.
                //?? TODO: When trying to cross-compile cyboi for windows,
                //?? the two S_IRGRP and S_IWGRP were not recognised by mingw.
                int r = S_IRUSR | S_IWUSR; //?? | S_IRGRP | S_IWGRP;

                // Set file access rights.
                chmod((wchar_t*) t, r);

            } else {

                // CAUTION! DO NOT use logging functionality here!
                // The logger will not work before its options are set.
                fputws(L"Error: Could not optionalise log file. An error occured when trying to open the file.\n", stdout);
            }

            // Deallocate terminated file name.
            deallocate_array((void*) &t, (void*) &ts, (void*) WIDE_CHARACTER_ARRAY);

        } else {

            // CAUTION! DO NOT use logging functionality here!
            // The logger will not work before its options are set.
            fputws(L"Error: Could not optionalise log file. The file descriptor is null.\n", stdout);
        }

    } else {

        // CAUTION! DO NOT use logging functionality here!
        // The logger will not work before its options are set.
        fputws(L"Error: Could not optionalise log file. The file name count is null.\n", stdout);
    }
}

/**
 * Deoptionalises the log file option.
 *
 * @param p0 the log file descriptor
 */
void deoptionalise_log_file(void* p0) {

    if (p0 != *NULL_POINTER) {

        int* f = (int*) p0;

        // CAUTION! DO NOT use logging functionality here!
        // The logger will not work before its options are set.
        // fputws(L"Debug: Deoptionalise log file.\n", stdout);

        if (*f >= *NUMBER_0_INTEGER) {

            // Close log file.
            close(*f);

        } else {

            // CAUTION! DO NOT use logging functionality here!
            // The logger will not work before its options are set.
            // fputws(L"Error: Could not deoptionalise log file. The file descriptor is invalid (smaller than zero).\n", stdout);
        }

    } else {

        // CAUTION! DO NOT use logging functionality here!
        // The logger will not work before its options are set.
        fputws(L"Error: Could not deoptionalise log file. The file descriptor is null.\n", stdout);
    }
}

/**
 * Optionalises the given command line argument option.
 *
 * @param p0 the operation mode
 * @param p1 the cybol knowledge file path
 * @param p2 the cybol knowledge file path count
 * @param p3 the log level
 * @param p4 the log file
 * @param p5 the value
 * @param p6 the value count
 * @param p7 the option
 * @param p8 the option count
 */
void optionalise_option(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8) {

    if (p5 != *NULL_POINTER) {

        void** v = (void**) p5;

        if (p0 != *NULL_POINTER) {

            int* m = (int*) p0;

            // CAUTION! DO NOT use logging functionality here!
            // The logger will not work before its options are set.
            // fputws(L"Debug: Optionalise option.\n", stdout);

            // The comparison result.
            int r = *NUMBER_0_INTEGER;

            if (r == *NUMBER_0_INTEGER) {

                compare_arrays(p7, p8, (void*) VERSION_COMMAND_LINE_OPTION, (void*) VERSION_COMMAND_LINE_OPTION_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY);

                if (r != *NUMBER_0_INTEGER) {

                    // Set version operation mode.
                    *m = *VERSION_CYBOI_OPERATION_MODE;
                }
            }

            if (r == *NUMBER_0_INTEGER) {

                compare_arrays(p7, p8, (void*) HELP_COMMAND_LINE_OPTION, (void*) HELP_COMMAND_LINE_OPTION_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY);

                if (r != *NUMBER_0_INTEGER) {

                    // Set help operation mode.
                    *m = *HELP_CYBOI_OPERATION_MODE;
                }
            }

            if (r == *NUMBER_0_INTEGER) {

                compare_arrays(p7, p8, (void*) TEST_COMMAND_LINE_OPTION, (void*) TEST_COMMAND_LINE_OPTION_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY);

                if (r != *NUMBER_0_INTEGER) {

                    // Set test operation mode.
                    *m = *TEST_CYBOI_OPERATION_MODE;
                }
            }

            if (r == *NUMBER_0_INTEGER) {

                compare_arrays(p7, p8, (void*) KNOWLEDGE_COMMAND_LINE_OPTION, (void*) KNOWLEDGE_COMMAND_LINE_OPTION_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY);

                if (r != *NUMBER_0_INTEGER) {

                    // Set cybol knowledge file path.
                    optionalise_knowledge(p1, p2, p5, p6);

                    // Set knowledge operation mode.
                    *m = *KNOWLEDGE_CYBOI_OPERATION_MODE;
                }
            }

            if (r == *NUMBER_0_INTEGER) {

                compare_arrays(p7, p8, (void*) LOG_LEVEL_COMMAND_LINE_OPTION, (void*) LOG_LEVEL_COMMAND_LINE_OPTION_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY);

                if (r != *NUMBER_0_INTEGER) {

                    // Set log level, which is a global variable.
                    optionalise_log_level(p3, *v, p6);
                }
            }

            if (r == *NUMBER_0_INTEGER) {

                compare_arrays(p7, p8, (void*) LOG_FILE_COMMAND_LINE_OPTION, (void*) LOG_FILE_COMMAND_LINE_OPTION_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY);

                if (r != *NUMBER_0_INTEGER) {

                    // Set log file to store log messages in.
                    optionalise_log_file(p4, *v, p6);
                }
            }

            if (r == *NUMBER_0_INTEGER) {

                // CAUTION! Do NOT show this warning message, since the last
                // option argument read from command line is always null,
                // so that this warning would always appear and only disturb the user.
                // fputws(L"Warning: Could not optionalise option. The command line option is unknown.\n", stdout);
            }

        } else {

            // CAUTION! DO NOT use logging functionality here!
            // The logger will not work before its options are set.
            fputws(L"Error: Could not optionalise option. The operation mode is null.\n", stdout);
        }

    } else {

        // CAUTION! DO NOT use logging functionality here!
        // The logger will not work before its options are set.
        fputws(L"Error: Could not optionalise option. The value is null.\n", stdout);
    }
}

/**
 * Optionalises the given command line argument options.
 *
 * The GNU Standards for Command Line Interfaces to be found at:
 * http://www.gnu.org/prep/standards/html_node/Command_002dLine-Interfaces.html
 * write:
 * "All programs should support two standard options: '--version' and '--help'."
 * Therefore, this function checks for these two command line argument options.
 *
 * A further option that was added is '--test'. It is just to ease cyboi
 * development because that way, programmers can easily call test functions.
 *
 * The standard option used to run cybol applications is '--knowledge'.
 * Behind it, the cybol file name needs to be given as argument.
 * The cyboi interpreter then starts up the system.
 *
 * If none of these options can be found, cyboi displays the help message.
 *
 * @param p0 the operation mode
 * @param p1 the cybol knowledge file path
 * @param p2 the cybol knowledge file path count
 * @param p3 the log level
 * @param p4 the log file
 * @param p5 the options
 * @param p6 the options count
 */
void optionalise(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    if (p6 != *NULL_POINTER) {

        int* c = (int*) p6;

        // CAUTION! DO NOT use logging functionality here!
        // The logger will not work before its options are set.
        // fputws(L"Information: Optionalise command line argument options.\n", stdout);

        // The loop variable.
        //
        // CAUTION! Do NOT initialise it with 0, as the first command line
        // argument is the command itself, and not an option!
        int j = *NUMBER_1_INTEGER;
        // The value index, which is equal to the loop variable increased by one.
        // It is initialised with the options count by default, so that it does
        // NOT get processed, unless set to a valid value lying within the array.
        int i = *c;
        // The command line argument option.
        void** o = NULL_POINTER;
        // The command line argument option count (number of characters).
        int oc = *NUMBER_0_INTEGER;
        // The command line argument value.
        void** v = NULL_POINTER;
        // The command line argument value count (number of characters).
        int vc = *NUMBER_0_INTEGER;

        while (*NUMBER_1_INTEGER) {

            if (j >= *c) {

                break;
            }

            // Get command line argument option.
            // Example: "--loglevel"
            get_array_elements(p5, (void*) &j, (void*) &o, (void*) POINTER_ARRAY);

            if (*o != *NULL_POINTER) {

                // Get command line argument option count (number of characters).
                //
                // There are two possibilities to determine it:
                // 1 Force the user to give it as extra command line parameter
                //   (this would be proper, but not very user-friendly)
                // 2 Rely on the null termination character to determine it
                //   (this is a rather dirty workaround, but the strlen function can be used)
                //
                // Possibility 2 is applied here.
                oc = wcslen((wchar_t*) *o);

            } else {

                // CAUTION! DO NOT use logging functionality here!
                // The logger will not work before its options are set.
                fputws(L"Error: Could not optionalise command line argument options. The command line argument option is null.\n", stdout);
            }

            // Calculate value index.
            i = j + *NUMBER_1_INTEGER;

            if (i < *c) {

                // CAUTION! Only try to access the value following an option,
                // if the array is large enough, to avoid access violation errors!

                // Get command line argument value, standing after the option.
                // Example: "debug"
                get_array_elements(p5, (void*) &i, (void*) &v, (void*) POINTER_ARRAY);

                if (*v != *NULL_POINTER) {

                    // Get command line argument value count (number of characters).
                    //
                    // There are two possibilities to determine it:
                    // 1 Force the user to give it as extra command line parameter
                    //   (this would be proper, but not very user-friendly)
                    // 2 Rely on the null termination character to determine it
                    //   (this is a rather dirty workaround, but the strlen function can be used)
                    //
                    // Possibility 2 is applied here.
                    vc = wcslen((wchar_t*) *v);

                } else {

                    // CAUTION! DO NOT use logging functionality here!
                    // The logger will not work before its options are set.
                    fputws(L"Error: Could not optionalise command line argument options. The command line argument value is null.\n", stdout);
                }
            }

            // Optionalise the option and its value.
            // CAUTION! The value gets handed over as reference, as it gets
            // copied for the cybol knowledge file name.
            optionalise_option(p0, p1, p2, p3, p4, v, (void*) &vc, *o, (void*) &oc);

            // Reset command line argument option.
            o = NULL_POINTER;
            // Reset command line argument option count (number of characters).
            oc = *NUMBER_0_INTEGER;
            // Reset command line argument value.
            v = NULL_POINTER;
            // Reset command line argument value count (number of characters).
            vc = *NUMBER_0_INTEGER;

            // Increment loop variable.
            j++;
        }

    } else {

        // CAUTION! DO NOT use logging functionality here!
        // The logger will not work before its options are set.
        fputws(L"Error: Could not optionalise command line argument options. The options count is null.\n", stdout);
    }
}

/**
 * Deoptionalises the given command line argument options.
 *
 * @param p0 the log file descriptor
 */
void deoptionalise(void* p0) {

    // CAUTION! DO NOT use logging functionality here!
    // The logger will not work before its options are set.
    // fputws(L"Information: Deoptionalise command line argument options.\n", stdout);

    // Deoptionalise log file.
    deoptionalise_log_file(p0);
}

/* OPTIONALISER_SOURCE */
#endif
