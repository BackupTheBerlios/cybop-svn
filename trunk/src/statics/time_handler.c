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
 * @version $Revision: 1.17 $ $Date: 2004-04-22 08:54:56 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef TIME_HANDLER_SOURCE
#define TIME_HANDLER_SOURCE

#include "../constants.c"
#include "../logger/log_handler.c"
#include "../model/array_handler.c"

//
// Time.
//

/**
 * Creates the time.
 *
 * @param p0 the transient model
 */
void create_time(void* p0) {

    log_message((void*) &INFO_LOG_LEVEL, (void*) &"Create time.");

    // The time.
    create_array(p0, (void*) &TIME_SIZE);
}

/**
 * Destroys the time.
 *
 * @param p0 the transient model
 */
void destroy_time(void* p0) {

    log_message((void*) &INFO_LOG_LEVEL, (void*) &"Destroy time.");

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

    log_message((void*) &INFO_LOG_LEVEL, (void*) &"Initialize time.");

//??    fscanf(p1, %d, &(m->value));

    // Initialize elements.
    int s = 0;
    int min = 0;
    int h = 0;
    int d = 0;
    int m = 0;
    int y = 0;

    // Set elements.
    set_array_element(p0, (void*) &INTEGER_ARRAY, (void*) &YEAR_INDEX, (void*) &y);
    set_array_element(p0, (void*) &INTEGER_ARRAY, (void*) &MONTH_INDEX, (void*) &m);
    set_array_element(p0, (void*) &INTEGER_ARRAY, (void*) &DAY_INDEX, (void*) &d);
    set_array_element(p0, (void*) &INTEGER_ARRAY, (void*) &HOUR_INDEX, (void*) &h);
    set_array_element(p0, (void*) &INTEGER_ARRAY, (void*) &MINUTE_INDEX, (void*) &min);
    set_array_element(p0, (void*) &INTEGER_ARRAY, (void*) &SECOND_INDEX, (void*) &s);
}

/**
 * Finalizes the time.
 *
 * @param p0 the transient model
 * @param p1 the persistent model
 * @param p2 the persistent model size
 */
void finalize_time(void* p0, void* p1, void* p2) {

    log_message((void*) &INFO_LOG_LEVEL, (void*) &"Finalize time.");

    // Initialize elements.
    int s = 0;
    int min = 0;
    int h = 0;
    int d = 0;
    int m = 0;
    int y = 0;

    // Get elements.
    get_array_element(p0, (void*) &INTEGER_ARRAY, (void*) &SECOND_INDEX, (void*) &s);
    get_array_element(p0, (void*) &INTEGER_ARRAY, (void*) &MINUTE_INDEX, (void*) &min);
    get_array_element(p0, (void*) &INTEGER_ARRAY, (void*) &HOUR_INDEX, (void*) &h);
    get_array_element(p0, (void*) &INTEGER_ARRAY, (void*) &DAY_INDEX, (void*) &d);
    get_array_element(p0, (void*) &INTEGER_ARRAY, (void*) &MONTH_INDEX, (void*) &m);
    get_array_element(p0, (void*) &INTEGER_ARRAY, (void*) &YEAR_INDEX, (void*) &y);

    // Remove elements in descending order.
    remove_array_element(p0, (void*) &INTEGER_ARRAY, (void*) &TIME_SIZE, (void*) &SECOND_INDEX);
    remove_array_element(p0, (void*) &INTEGER_ARRAY, (void*) &TIME_SIZE, (void*) &MINUTE_INDEX);
    remove_array_element(p0, (void*) &INTEGER_ARRAY, (void*) &TIME_SIZE, (void*) &HOUR_INDEX);
    remove_array_element(p0, (void*) &INTEGER_ARRAY, (void*) &TIME_SIZE, (void*) &DAY_INDEX);
    remove_array_element(p0, (void*) &INTEGER_ARRAY, (void*) &TIME_SIZE, (void*) &MONTH_INDEX);
    remove_array_element(p0, (void*) &INTEGER_ARRAY, (void*) &TIME_SIZE, (void*) &YEAR_INDEX);

//??    fprintf(p1, %d, &(m->value));
}

/* TIME_HANDLER_SOURCE */
#endif
