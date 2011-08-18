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
 * @version $RCSfile: optionaliser.c,v $ $Revision: 1.29 $ $Date: 2009-10-06 21:25:26 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef OPTIONALISER_SOURCE
#define OPTIONALISER_SOURCE

#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

#include "../constant/abstraction/cybol/text_cybol_abstraction.c"
#include "../constant/abstraction/memory/memory_abstraction.c"
#include "../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../constant/abstraction/operation/primitive_operation_abstraction.c"
#include "../constant/model/character_code/unicode/unicode_character_code_model.c"
#include "../constant/model/command_argument/cyboi/log_level_cyboi_command_argument_model.c"
#include "../constant/model/cyboi/operation_mode_cyboi_model.c"
#include "../constant/model/log/level_log_model.c"
#include "../constant/model/memory/boolean_memory_model.c"
#include "../constant/model/memory/integer_memory_model.c"
#include "../constant/model/memory/pointer_memory_model.c"
#include "../constant/name/command_option/cyboi_command_option_name.c"
#include "../executor/comparator/all/array_all_comparator.c"
#include "../executor/modifier/copier/integer_copier.c"
#include "../executor/modifier/overwriter/array_overwriter.c"
#include "../executor/modifier/overwriter/item_overwriter.c"
#include "../executor/memoriser/allocator/model_allocator.c"
#include "../executor/memoriser/deallocator/model_deallocator.c"

/**
 * Optionalises the log level option.
 *
 * @param p0 the log level
 * @param p1 the log level name
 * @param p2 the log level name count
 */
void optionalise_log_level(void* p0, void* p1, void* p2) {

    // CAUTION! DO NOT use logging functionality here!
    // The logger will not work before its options are set.
    // Comment out this function call to avoid disturbing messages at system startup!
    // log_write_terminated_message((void*) stdout, L"Debug: Optionalise log level.\n");

    // The comparison result.
    int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, p1, (void*) OFF_LOG_LEVEL_CYBOI_COMMAND_ARGUMENT_MODEL, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p2, (void*) OFF_LOG_LEVEL_CYBOI_COMMAND_ARGUMENT_MODEL_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            // Set log level.
            copy_integer(p0, (void*) OFF_LEVEL_LOG_MODEL);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, p1, (void*) ERROR_LEVEL_LOG_MODEL_CYBOI_COMMAND_ARGUMENT_MODEL, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p2, (void*) ERROR_LEVEL_LOG_MODEL_CYBOI_COMMAND_ARGUMENT_MODEL_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            // Set log level.
            copy_integer(p0, (void*) ERROR_LEVEL_LOG_MODEL);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, p1, (void*) WARNING_LEVEL_LOG_MODEL_CYBOI_COMMAND_ARGUMENT_MODEL, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p2, (void*) WARNING_LEVEL_LOG_MODEL_CYBOI_COMMAND_ARGUMENT_MODEL_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            // Set log level.
            copy_integer(p0, (void*) WARNING_LEVEL_LOG_MODEL);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, p1, (void*) INFORMATION_LEVEL_LOG_MODEL_CYBOI_COMMAND_ARGUMENT_MODEL, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p2, (void*) INFORMATION_LEVEL_LOG_MODEL_CYBOI_COMMAND_ARGUMENT_MODEL_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            // Set log level.
            copy_integer(p0, (void*) INFORMATION_LEVEL_LOG_MODEL);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, p1, (void*) DEBUG_LEVEL_LOG_MODEL_CYBOI_COMMAND_ARGUMENT_MODEL, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p2, (void*) DEBUG_LEVEL_LOG_MODEL_CYBOI_COMMAND_ARGUMENT_MODEL_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            // Set log level.
            copy_integer(p0, (void*) DEBUG_LEVEL_LOG_MODEL);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        // CAUTION! DO NOT use logging functionality here!
        // The logger will not work before its options are set.
        log_write_terminated_message((void*) stdout, L"Warning: Could not optionalise log level. The log level name is unknown.\n");
    }
}

/**
 * Optionalises the log file option.
 *
 * @param p0 the log file (Hand over as reference!)
 * @param p1 the log file name
 * @param p2 the log file name count
 */
void optionalise_log_file(void* p0, void* p1, void* p2) {

    if (p0 != *NULL_POINTER_MEMORY_MODEL) {

        FILE** f = (FILE**) p0;

        // CAUTION! DO NOT use logging functionality here!
        // The logger will not work before its options are set.
        // Comment out this function call to avoid disturbing messages at system startup!
        // log_write_terminated_message((void*) stdout, L"Debug: Optionalise log file.\n");

        // The terminated file name.
        void* t = *NULL_POINTER_MEMORY_MODEL;
        int tc = *NUMBER_0_INTEGER_MEMORY_MODEL;
        int ts = *NUMBER_0_INTEGER_MEMORY_MODEL;

        // Allocate terminated file name as multibyte character array.
        // CAUTION! Do NOT use a wide character array here!
        // The glibc file stream functions below expect standard (multibyte) character arrays.
        allocate_array((void*) &t, (void*) &ts, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

        // Encode wide character option into multibyte character array.
        encode_utf_8_unicode_character_vector((void*) &t, (void*) &tc, (void*) &ts, p1, p2);

        // Add null termination character to terminated file name.
        overwrite_array((void*) &t, (void*) NULL_CONTROL_ASCII_CHARACTER_CODE_MODEL, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) &tc, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) &tc, (void*) &ts);

        // Open log file for writing only.
        // If the file already exists, it is truncated to zero length.
        // Otherwise a new file is created.
        //
        // FILE objects are allocated and managed internally by the input/ output
        // library functions. The library creates objects of type FILE.
        // Programs should deal only with pointers to these objects (FILE* values),
        // rather than the objects themselves.
        *f = fopen((char*) t, "w");

        if (*f != *NULL_POINTER_MEMORY_MODEL) {

            // The file owner.
            int o = *NUMBER_MINUS_1_INTEGER_MEMORY_MODEL;
            // The file group.
            int g = *NUMBER_MINUS_1_INTEGER_MEMORY_MODEL;

            // Set file owner.
            chown((char*) t, o, g);

            // The file access rights.
            //?? TODO: When trying to cross-compile cyboi for windows,
            //?? the two S_IRGRP and S_IWGRP were not recognised by mingw.
            int r = S_IRUSR | S_IWUSR; //?? | S_IRGRP | S_IWGRP;

            // Set file access rights.
            chmod((char*) t, r);

        } else {

            // CAUTION! DO NOT use logging functionality here!
            // The logger will not work before its options are set.
            log_write_terminated_message((void*) stdout, L"Error: Could not optionalise log file. An error occured when trying to open or create the file for writing.\n");
        }

        // Deallocate terminated file name as multibyte character array.
        deallocate_array((void*) &t, (void*) &ts, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

    } else {

        // CAUTION! DO NOT use logging functionality here!
        // The logger will not work before its options are set.
        log_write_terminated_message((void*) stdout, L"Error: Could not optionalise log file. The file descriptor is null.\n");
    }
}

/**
 * Deoptionalises the log file option.
 *
 * @param p0 the log file stream (Hand over as reference!)
 */
void deoptionalise_log_file(void* p0) {

    if (p0 != *NULL_POINTER_MEMORY_MODEL) {

        FILE** f = (FILE**) p0;

        // CAUTION! DO NOT use logging functionality here!
        // The logger will not work before its options are set.
        // Comment out this function call to avoid disturbing messages at system startup!
        // log_write_terminated_message((void*) stdout, L"Debug: Deoptionalise log file.\n");

        // CAUTION! This test is necessary! Do NOT delete it!
        // Checking the file stream argument above is not sufficient,
        // since a segmentation fault will occur here,
        // if no log file is given as command line argument at system startup.
        if (*f != *NULL_POINTER_MEMORY_MODEL) {

            // Close log file.
            fclose(*f);

            // Reset log file pointer.
            // CAUTION! Hand over the log file stream AS REFERENCE!
            // This is necessary, because it is reset to null here.
            // If this was not done, subsequent logger calls would cause segmentation faults,
            // because the null pointer test within the logger would be successful,
            // even though the LOG_OUTPUT pointer would be invalid.
            *f = *NULL_POINTER_MEMORY_MODEL;

        } else {

            // CAUTION! DO NOT use logging functionality here!
            // The logger will not work before its options are set.
            // Do NOT show the following message, as it would only disturb the user!
            // log_write_terminated_message((void*) stdout, L"Warning: Could not deoptionalise log file. No log file was given at system startup.\n");
        }

    } else {

        // CAUTION! DO NOT use logging functionality here!
        // The logger will not work before its options are set.
        // Do NOT show the following message, as it would only disturb the user!
        log_write_terminated_message((void*) stdout, L"Error: Could not deoptionalise log file. The file descriptor is null.\n");
    }
}

/**
 * Optionalises the given command line argument option.
 *
 * This function finds out whether an option is actually a value
 * or vice versa, by just comparing with known cyboi options.
 *
 * @param p0 the operation mode
 * @param p1 the cybol knowledge file path item
 * @param p2 the log level
 * @param p3 the log file stream (Hand over as reference!)
 * @param p4 the value
 * @param p5 the value count
 * @param p6 the option
 * @param p7 the option count
 */
void optionalise_option(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    // CAUTION! DO NOT use logging functionality here!
    // The logger will not work before its options are set.
    // Comment out this function call to avoid disturbing messages at system startup!
    // log_write_terminated_message((void*) stdout, L"Debug: Optionalise option.\n");

    // The comparison result.
    int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, p6, (void*) HELP_CYBOI_COMMAND_OPTION_NAME, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p7, (void*) HELP_CYBOI_COMMAND_OPTION_NAME_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            // Set help operation mode.
            copy_integer(p0, (void*) HELP_OPERATION_MODE_CYBOI_MODEL);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, p6, (void*) KNOWLEDGE_CYBOI_COMMAND_OPTION_NAME, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p7, (void*) KNOWLEDGE_CYBOI_COMMAND_OPTION_NAME_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            // Copy file path from value to cybol knowledge file path.
            overwrite_item_element(p1, p4, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p5, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) DATA_ITEM_MEMORY_NAME);

            // Set knowledge operation mode.
            copy_integer(p0, (void*) KNOWLEDGE_OPERATION_MODE_CYBOI_MODEL);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, p6, (void*) LOG_FILE_CYBOI_COMMAND_OPTION_NAME, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p7, (void*) LOG_FILE_CYBOI_COMMAND_OPTION_NAME_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            // Set log file to store log messages in.
            optionalise_log_file(p3, p4, p5);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, p6, (void*) LOG_LEVEL_CYBOI_COMMAND_OPTION_NAME, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p7, (void*) LOG_LEVEL_CYBOI_COMMAND_OPTION_NAME_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            // Set log level, which is a global variable.
            optionalise_log_level(p2, p4, p5);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, p6, (void*) TEST_CYBOI_COMMAND_OPTION_NAME, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p7, (void*) TEST_CYBOI_COMMAND_OPTION_NAME_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            // Set test operation mode.
            copy_integer(p0, (void*) TEST_OPERATION_MODE_CYBOI_MODEL);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, p6, (void*) VERSION_CYBOI_COMMAND_OPTION_NAME, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p7, (void*) VERSION_CYBOI_COMMAND_OPTION_NAME_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            // Set version operation mode.
            copy_integer(p0, (void*) VERSION_OPERATION_MODE_CYBOI_MODEL);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        // CAUTION! This function call HAS TO BE COMMENTED OUT,
        // in order to avoid disturbing messages at system startup!
        // The last option argument read from command line is
        // always null, so that this warning would ALWAYS appear.
        // log_write_terminated_message((void*) stdout, L"Warning: Could not optionalise option. The command line option is unknown.\n");
    }
}

/**
 * Optionalises the command line argument.
 *
 * It is assumed that the argument is an option followed by a value.
 * Both are determined here and evaluated later in function "optionalise_option".
 *
 * @param p0 the operation mode
 * @param p1 the cybol knowledge file path item
 * @param p2 the log level
 * @param p3 the log file stream (Hand over as reference!)
 * @param p4 the arguments (Hand over as reference!)
 * @param p5 the arguments count
 * @param p6 the index
 */
void optionalise_command_line_argument(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    if (p6 != *NULL_POINTER_MEMORY_MODEL) {

        int* j = (int*) p6;

        if (p5 != *NULL_POINTER_MEMORY_MODEL) {

            int* ac = (int*) p5;

            // CAUTION! DO NOT use logging functionality here!
            // The logger will not work before its options are set.
            // Comment out this function call to avoid disturbing messages at system startup!
            // log_write_terminated_message((void*) stdout, L"Information: Optionalise command line argument.\n");

            // The value index, which is equal to the loop variable increased by one.
            //
            // It is initialised with the options count by default, so that it does
            // NOT get processed, unless set to a valid value lying within the array.
            //
            // CAUTION! Do NOT misuse the index parameter *j handed over to this function!
            // The parameter j is the loop index and must NOT be altered here!
            // Therefore, a new local variable i is introduced.
            int i = *ac;
            // The command line argument option as multibyte character array.
            void** o = NULL_POINTER_MEMORY_MODEL;
            int oc = *NUMBER_0_INTEGER_MEMORY_MODEL;
            // The option as wide character array.
            void* ow = *NULL_POINTER_MEMORY_MODEL;
            int owc = *NUMBER_0_INTEGER_MEMORY_MODEL;
            int ows = *NUMBER_0_INTEGER_MEMORY_MODEL;
            // The command line argument value as multibyte character array.
            void** v = NULL_POINTER_MEMORY_MODEL;
            int vc = *NUMBER_0_INTEGER_MEMORY_MODEL;
            // The value as wide character array.
            void* vw = *NULL_POINTER_MEMORY_MODEL;
            int vwc = *NUMBER_0_INTEGER_MEMORY_MODEL;
            int vws = *NUMBER_0_INTEGER_MEMORY_MODEL;

            // Allocate option as wide character array.
            allocate((void*) &ow, (void*) &ows, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT);
            // Allocate value as wide character array.
            allocate((void*) &vw, (void*) &vws, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT);

            // Get command line argument option.
            // Example: "--loglevel"
            get_array_elements((void*) &o, p4, (void*) j, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);

            if (*o != *NULL_POINTER_MEMORY_MODEL) {

                // Get command line argument option count (number of characters).
                //
                // There are two possibilities to determine it:
                // 1 Force the user to give it as extra command line parameter
                //   (this would be proper, but not very user-friendly)
                // 2 Rely on the null termination character to determine it
                //   (this is a rather dirty workaround, but the "strlen" function can be used)
                //
                // Possibility 2 is applied here.
                oc = strlen((char*) *o);

                // Decode multibyte command line argument option into wide character.
                decode_utf_8_unicode_character_vector((void*) &ow, (void*) &owc, (void*) &ows, *o, (void*) &oc);

            } else {

                // CAUTION! DO NOT use logging functionality here!
                // The logger will not work before its options are set.
                log_write_terminated_message((void*) stdout, L"Error: Could not optionalise command line argument. The command line argument option is null.\n");
            }

            // Calculate value index.
            i = *j + *NUMBER_1_INTEGER_MEMORY_MODEL;

            if (i < *ac) {

                // CAUTION! Only try to access the value following an option,
                // if the array is large enough, to avoid access violation errors!

                // Get command line argument value, standing after the option.
                // Example: "debug"
                get_array_elements((void*) &v, p4, (void*) &i, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);

                if (*v != *NULL_POINTER_MEMORY_MODEL) {

                    // Get command line argument value count (number of characters).
                    //
                    // There are two possibilities to determine it:
                    // 1 Force the user to give it as extra command line parameter
                    //   (this would be proper, but not very user-friendly)
                    // 2 Rely on the null termination character to determine it
                    //   (this is a rather dirty workaround, but the strlen function can be used)
                    //
                    // Possibility 2 is applied here.
                    vc = strlen((char*) *v);

                    // Decode multibyte command line argument value into wide character.
                    decode_utf_8_unicode_character_vector((void*) &vw, (void*) &vwc, (void*) &vws, *v, (void*) &vc);

                } else {

                    // CAUTION! DO NOT use logging functionality here!
                    // The logger will not work before its options are set.
                    log_write_terminated_message((void*) stdout, L"Error: Could not optionalise command line argument. The command line argument value is null.\n");
                }
            }

            // Optionalise the option and its value.
            // CAUTION! The value gets handed over as reference, as it gets
            // copied for the cybol knowledge file name.
            optionalise_option(p0, p1, p2, p3, vw, (void*) &vwc, ow, (void*) &owc);

            // Deallocate option as wide character array.
            deallocate((void*) &ow, (void*) &ows, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT);
            // Deallocate value as wide character array.
            deallocate((void*) &vw, (void*) &vws, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT);

        } else {

            // CAUTION! DO NOT use logging functionality here!
            // The logger will not work before its options are set.
            log_write_terminated_message((void*) stdout, L"Error: Could not optionalise command line argument. The argument count is null.\n");
        }

    } else {

        // CAUTION! DO NOT use logging functionality here!
        // The logger will not work before its options are set.
        log_write_terminated_message(stdout, L"Error: Could not optionalise command line argument. The index is null.\n");
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
 * Optionally, a '--loglevel' and 'logfile' may be given, each followed by a value.
 * In the case of the loglevel, the value may be one of:
 * - off
 * - error
 * - warning
 * - information
 * - debug
 * where 'debug' is the most verbose one.
 * The logfile expects just an arbitrary file name.
 *
 * If none of these options can be found, cyboi displays the help message.
 *
 * @param p0 the operation mode
 * @param p1 the cybol knowledge file path item
 * @param p2 the log level
 * @param p3 the log file stream (Hand over as reference!)
 * @param p4 the arguments (Hand over as reference!)
 * @param p5 the arguments count
 */
void optionalise(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    if (p5 != *NULL_POINTER_MEMORY_MODEL) {

        int* ac = (int*) p5;

        // CAUTION! DO NOT use logging functionality here!
        // The logger will not work before its options are set.
        // Comment out this function call to avoid disturbing messages at system startup!
        // log_write_terminated_message((void*) stdout, L"Information: Optionalise command line arguments.\n");

        // The loop variable.
        //
        // CAUTION! Do NOT initialise it with 0, as the first command line
        // argument is the command itself, and not an option!
        int j = *NUMBER_1_INTEGER_MEMORY_MODEL;

        while (*TRUE_BOOLEAN_MEMORY_MODEL) {

            if (j >= *ac) {

                break;
            }

            optionalise_command_line_argument(p0, p1, p2, p3, p4, p5, (void*) &j);

            // Increment loop variable.
            j++;
        }

    } else {

        // CAUTION! DO NOT use logging functionality here!
        // The logger will not work before its options are set.
        log_write_terminated_message(stdout, L"Error: Could not optionalise command line argument options. The options count is null.\n");
    }
}

/**
 * Deoptionalises the given command line argument options.
 *
 * @param p0 the log file stream
 */
void deoptionalise(void* p0) {

    // CAUTION! DO NOT use logging functionality here!
    // The logger will not work before its options are set.
    // Do NOT show the following message, as it would only disturb the user!
    // log_write_terminated_message((void*) stdout, L"Information: Deoptionalise command line argument options.\n");

    // Deoptionalise log file.
    deoptionalise_log_file(p0);
}

/* OPTIONALISER_SOURCE */
#endif
