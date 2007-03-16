/*
 * $RCSfile: xdt_rule_constants.c,v $
 *
 * Copyright (c) 1999-2007. Christian Heller and the CYBOP developers.
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
 * @version $Revision: 1.1 $ $Date: 2007-03-16 22:05:24 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef XDT_RULE_CONSTANTS_SOURCE
#define XDT_RULE_CONSTANTS_SOURCE

#include "../../globals/constants/integer_constants.c"

//
// Format checking rules.
//

/**
 * The hhmm rule.
 *
 * HH: Stunde
 * MM: Minute
 *
 * Possible values: 0000-2359
 */
static int* HHMM_XDT_RULE = NUMBER_5_INTEGER_ARRAY;

/**
 * The hhmmhhmm rule.
 *
 * HH: Stunde
 * MM: Minute
 */
static int* HHMMHHMM_XDT_RULE = NUMBER_6_INTEGER_ARRAY;

/**
 * The jjmmnnn rule.
 *
 * JJ: Jahr
 * MM: Monat
 * NNN: laufende Nummer
 */
static int* JJMMNNN_XDT_RULE = NUMBER_7_INTEGER_ARRAY;

/**
 * The ttmmjjjj rule.
 *
 * TT: Tag
 * MM: Monat
 * JJJJ: Jahr
 */
static int* TTMMJJJJ_XDT_RULE = NUMBER_8_INTEGER_ARRAY;

/**
 * The mmjj rule.
 *
 * MM: Monat
 * JJ: Jahr
 */
static int* MMJJ_XDT_RULE = NUMBER_14_INTEGER_ARRAY;

/**
 * The arztname zuordnungszeichen rule.
 *
 * Possible values: 0-9, A-Z, #, $, <, >, *
 */
static int* ARZTNAME_ZUORDNUNGSZEICHEN_XDT_RULE = NUMBER_15_INTEGER_ARRAY;

/**
 * The qjjjj rule.
 *
 * Q: Quartal
 * JJJJ: Jahr
 */
static int* QJJJJ_XDT_RULE = NUMBER_16_INTEGER_ARRAY;

/**
 * The vknr rule.
 *
 * Format: nnnnn
 */
static int* VKNR_XDT_RULE = NUMBER_17_INTEGER_ARRAY;

/**
 * The krankenkassennummer rule.
 *
 * Format: nnnnnnn
 */
static int* KRANKENKASSENNUMMER_XDT_RULE = NUMBER_18_INTEGER_ARRAY;

/**
 * The ttmmjjjjttmmjjjj rule.
 *
 * TT: Tag
 * MM: Monat
 * JJJJ: Jahr
 */
static int* TTMMJJJJTTMMJJJJ_XDT_RULE = NUMBER_19_INTEGER_ARRAY;

/**
 * The ttmmjjjj rule.
 *
 * TT: Tag
 * MM: Monat
 * JJJJ: Jahr
 *
 * Possible values:
 * TT=00-31
 * MM=00-12
 * JJJJ=0000-9999
 */
static int* TTMMJJJJ_BESCHRAENKT_XDT_RULE = NUMBER_20_INTEGER_ARRAY;

//
// Content checking rules.
//

/**
 * The feld angekreuzt rule.
 *
 * Possible values: 1
 *
 * Description:
 * 1: Feld angekreuzt/ vorhanden
 */
static int* FELD_ANGEKREUZT_XDT_RULE = NUMBER_101_INTEGER_ARRAY;

//
// Existence checking rules.
//

/**
 * The kassendatei vknr vorhanden rule.
 *
 * VKNR vorhanden und 5-stellig
 */
static int* KASSENDATEI_VKNR_VORHANDEN_XDT_RULE = NUMBER_201_INTEGER_ARRAY;

//
// Context checking rules.
//

/**
 * The datum kleiner oder gleich maschinendatum rule.
 */
static int* DATUM_KLEINER_ODER_GLEICH_MASCHINENDATUM_XDT_RULE = NUMBER_304_INTEGER_ARRAY;

/* XDT_RULE_CONSTANTS_SOURCE */
#endif
