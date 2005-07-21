/*
 * $RCSfile: control_sequence_constants.c,v $
 *
 * Copyright (c) 1999-2005. Christian Heller and the CYBOP developers.
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
 * @version $Revision: 1.1 $ $Date: 2005-07-21 08:02:08 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef ESCAPE_CODE_CONSTANTS_SOURCE
#define ESCAPE_CODE_CONSTANTS_SOURCE

/**
 * The cursor position control sequence.
 *
 * ESC[P;PH
 *
 * Mnemonic:
 * CUP (Cursor position)
 * HVP (Horizontal and vertical position)
 */
static const char CURSOR_POSITION_CONTROL_SEQUENCE_ARRAY[] = {'\033', '[', 'x', 'H'};
static const char* CURSOR_POSITION_CONTROL_SEQUENCE = CURSOR_POSITION_CONTROL_SEQUENCE_ARRAY;
static const int CURSOR_POSITION_CONTROL_SEQUENCE_COUNT_ARRAY[] = {1};
static const int* CURSOR_POSITION_CONTROL_SEQUENCE_COUNT = CURSOR_POSITION_CONTROL_SEQUENCE_COUNT_ARRAY;

/* ESCAPE_CODE_CONSTANTS_SOURCE */
#endif

CAUTION! control sequence kann nicht def. werden, da sie x + y Laufzeit-Koordinaten enthaelt!
--> also kann nur ESC character als Konstante verwendet werden ??
