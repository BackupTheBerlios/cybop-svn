/*
 * $RCSfile: time_handler.c,v $
 *
 * Copyright (c) 1999-2004. Christian Heller. All rights reserved.
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
 * This file handles a time.
 *
 * A time is used to measure the duration of dynamics or in other words,
 * the difference between two static states/ instants.
 *
 * @version $Revision: 1.9 $ $Date: 2004-04-01 17:35:16 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef TIME_HANDLER_SOURCE
#define TIME_HANDLER_SOURCE

#include <string.h>
#include "../logger/log_handler.c"

//
// Constants.
//

/** The default time value. */
static const char* DEFAULT_TIME_VALUE = "01.01.0000 00:00:00";

/** The years. */
int years;

/** The months. */
int months;

/** The weeks. */
int weeks;

/** The days. */
int days;

/** The hours. */
int hours;

/** The minutes. */
int minutes;

/** The seconds. */
int seconds;

/** The milli seconds. */
int milli_seconds;

/** The micro seconds. */
int micro_seconds;

/** The nano seconds. */
int nano_seconds;

//
// Time model.
//

/**
 * Initializes the time model.
 *
 * @param p0 the time model
 * @param p1 the model source
 */
void initialize_time_model(void* p0, void* p1) {

    struct time* m = (struct time*) p0;

    if (m != (void*) 0) {

        log_message((void*) &INFO_LOG_LEVEL, "Initialize time model.");

        // Read input stream and transform to time.
//??        fscanf(p1, %d, &(m->value));

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, "Could not initialize time model. The time model is null.");
    }
}

/**
 * Finalizes the time model.
 *
 * @param p0 the time model
 * @param p1 the model source
 */
void finalize_time_model(void* p0, void* p1) {

    struct time* m = (struct time*) p0;
    
    if (m != (void*) 0) {
        
        log_message((void*) &INFO_LOG_LEVEL, "Finalize time model.");
        
        // Write output stream and transform from time.
//??        fprintf(p1, %d, &(m->value));

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, "Could not finalize time model. The time model is null.");
    }
}

/* TIME_HANDLER_SOURCE */
#endif
