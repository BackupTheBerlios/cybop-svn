/*
 * $RCSfile: Time.java,v $
 *
 * Copyright (c) 1999-2003. Christian Heller. All rights reserved.
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
 */

package cyboi;

/**
 * This is a time.
 *
 * @version $Revision: 1.1 $ $Date: 2003-09-10 14:44:49 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
class Time {

    // Do not use static keyword!
    // If you do, the elements will always be overwritten
    // whenever some instance sets them.
    
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
}

