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
 * Time format:
 * dd.mm.yyyy hh:mm:ss";
 * Examples:
 * 01.01.2000 00:00:00";
 * 31.12.1999 23:59:59";
 *
 * @version $Revision: 1.10 $ $Date: 2004-04-02 16:13:46 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef TIME_HANDLER_SOURCE
#define TIME_HANDLER_SOURCE

#include "../logger/log_handler.c"

//
// Constants.
//

/** The time size. */
static const int TIME_SIZE = 6;

/** The year index. */
static const int YEAR_INDEX = 0;

/** The month index. */
static const int MONTH_INDEX = 1;

/** The day index. */
static const int DAY_INDEX = 2;

/** The hour index. */
static const int HOUR_INDEX = 3;

/** The minute index. */
static const int MINUTE_INDEX = 4;

/** The second index. */
static const int SECOND_INDEX = 5;

//
// Time.
//

/**
 * Creates the time.
 *
 * @param p0 the transient model
 */
void create_time(void* p0) {

    log_message((void*) &INFO_LOG_LEVEL, "Create time.");

    // The time.
    create_array(p0, (void*) &TIME_SIZE);
}

/**
 * Destroys the time.
 *
 * @param p0 the transient model
 */
void destroy_time(void* p0) {

    log_message((void*) &INFO_LOG_LEVEL, "Destroy time.");

    // The time.
    destroy_array(p0, (void*) &TIME_SIZE);
}

/**
 * Initializes the time.
 *
 * @param p0 the transient model
 * @param p1 the persistent model
 * @param p2 the persistent model size
 */
void initialize_time(void* p0, const void* p1, const void* p2) {

    log_message((void*) &INFO_LOG_LEVEL, "Initialize time.");

    // Read input stream and transform to time.

//??    fscanf(p1, %d, &(m->value));

    // The year.
    int y = 0;
    set_array_element(p0, (void*) &TIME_SIZE, (void*) &INTEGER_ARRAY, (void*) &YEAR_INDEX, (void*) &y);

    // The month.
    int m = 0;
    set_array_element(p0, (void*) &TIME_SIZE, (void*) &INTEGER_ARRAY, (void*) &MONTH_INDEX, (void*) &m);

    // The day.
    int d = 0;
    set_array_element(p0, (void*) &TIME_SIZE, (void*) &INTEGER_ARRAY, (void*) &DAY_INDEX, (void*) &d);

    // The hour.
    int h = 0;
    set_array_element(p0, (void*) &TIME_SIZE, (void*) &INTEGER_ARRAY, (void*) &HOUR_INDEX, (void*) &h);

    // The minute.
    int min = 0;
    set_array_element(p0, (void*) &TIME_SIZE, (void*) &INTEGER_ARRAY, (void*) &MINUTE_INDEX, (void*) &min);

    // The second.
    int s = 0;
    set_array_element(p0, (void*) &TIME_SIZE, (void*) &INTEGER_ARRAY, (void*) &SECOND_INDEX, (void*) &s);
}

/**
 * Finalizes the time.
 *
 * @param p0 the transient model
 * @param p1 the persistent model
 * @param p2 the persistent model size
 */
void finalize_time(const void* p0, void* p1, void* p2) {

    log_message((void*) &INFO_LOG_LEVEL, "Finalize time.");

    // Write output stream and transform from time.

    // The second.
    int s = 0;
    get_array_element(p0, (void*) &TIME_SIZE, (void*) &INTEGER_ARRAY, (void*) &SECOND_INDEX, (void*) &s);
    remove_array_element(p0, (void*) &TIME_SIZE, (void*) &INTEGER_ARRAY, (void*) &SECOND_INDEX);

    // The minute.
    int min = 0;
    get_array_element(p0, (void*) &TIME_SIZE, (void*) &INTEGER_ARRAY, (void*) &MINUTE_INDEX, (void*) &min);
    remove_array_element(p0, (void*) &TIME_SIZE, (void*) &INTEGER_ARRAY, (void*) &MINUTE_INDEX);

    // The hour.
    int h = 0;
    get_array_element(p0, (void*) &TIME_SIZE, (void*) &INTEGER_ARRAY, (void*) &HOUR_INDEX, (void*) &h);
    remove_array_element(p0, (void*) &TIME_SIZE, (void*) &INTEGER_ARRAY, (void*) &HOUR_INDEX);

    // The day.
    int d = 0;
    get_array_element(p0, (void*) &TIME_SIZE, (void*) &INTEGER_ARRAY, (void*) &DAY_INDEX, (void*) &d);
    remove_array_element(p0, (void*) &TIME_SIZE, (void*) &INTEGER_ARRAY, (void*) &DAY_INDEX);

    // The month.
    int m = 0;
    get_array_element(p0, (void*) &TIME_SIZE, (void*) &INTEGER_ARRAY, (void*) &MONTH_INDEX, (void*) &m);
    remove_array_element(p0, (void*) &TIME_SIZE, (void*) &INTEGER_ARRAY, (void*) &MONTH_INDEX);

    // The year.
    int y = 0;
    get_array_element(p0, (void*) &TIME_SIZE, (void*) &INTEGER_ARRAY, (void*) &YEAR_INDEX, (void*) &y);
    remove_array_element(p0, (void*) &TIME_SIZE, (void*) &INTEGER_ARRAY, (void*) &YEAR_INDEX);

//??    fprintf(p1, %d, &(m->value));
}

/* TIME_HANDLER_SOURCE */
#endif
