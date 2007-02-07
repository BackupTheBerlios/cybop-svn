/*
 * $RCSfile: bdt_converter.c,v $
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
 * @version $Revision: 1.1 $ $Date: 2007-02-07 00:13:35 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef BDT_CONVERTER_SOURCE
#define BDT_CONVERTER_SOURCE

#include "../../globals/constants/abstraction_constants.c"
#include "../../globals/constants/channel_constants.c"
#include "../../globals/constants/ascii_character_constants.c"
#include "../../globals/constants/log_constants.c"
#include "../../globals/constants/model_constants.c"
#include "../../globals/constants/name_constants.c"
#include "../../globals/constants/structure_constants.c"
#include "../../globals/logger/logger.c"
#include "../../memoriser/accessor.c"
#include "../../memoriser/accessor/compound_accessor.c"
#include "../../memoriser/array.c"

/**
 * Parses a bdt format byte array into a compound model.
 *
 * The "x DatenTransfer" (xDT) is the German version of
 * "Electronic Data Interchange" (EDI) for medical practices.
 * Here is an extract from xDT documentation, issued by the
 * "Kassenaerztliche Bundesvereinigung" (KBV) at:
 * http://www.kbv.de/ita/4274.html
 *
 * Aufbau und Struktur des "AbrechnungsDatenTransfer" (ADT)
 *
 * Der ADT ist eine Datenschnittstelle, die aufgrund ihrer fruehen Entstehung,
 * Mitte der achtziger Jahre, wenig Anknuepfungspunkte zu den erst spaeter im
 * Zusammenhang mit der zunehmenden EDI-Etablierung bekannten Standards besitzt.
 * Natuerlich gibt es Parallelen, beispielsweise zu
 * "EDI for Administration, Commerce and Transport" (EDIFACT),
 * die in der artverwandten Zielsetzung begruendet liegen.
 * Die ADT-Syntax ist der von "Abstract Syntax Notation" (ASN) ASN.1 aehnlich.
 *
 * Eine wesentliche Besonderheit des ADT besteht darin, dass jedes Feld im
 * Grunde einen eigenen Satz darstellt. Das heisst, es enthaelt in sich wieder
 * die Elemente Laenge, Feldkennung, Feldinhalt und Feldende.
 *
 * Die einzelnen Felder haben alle einen eindeutigen Namen in Form einer
 * numerischen Feldkennung. Es gibt wenige Felder mit in der Groesse
 * feststehenden Feldinhalten, die meisten sind variabel, was sich mit einer
 * vorlaufenden Feldlaenge leicht bewerkstelligen laesst. Darueber hinaus
 * werden als Endemarkierung eines Feldes die ASCII-Werte 13 und 10,
 * gleichbedeutend mit Carriage return und Linefeed, verlangt.
 *
 * Jedes Feld hat die gleiche Struktur. Alle Informationen sind als
 * ASCII-Zeichen dargestellt. Gemaess der Feldkennung wird der zugehoerige
 * Eintrag der Feldtabelle herangezogen.
 *
 * Fuer die Laengenberechnung eines Feldes gilt die Regel: Feldinhalt + 9
 *
 * Struktur eines Datenfeldes
 *
 * -----------------------------------------------------------------------------
 * Feldteil         Laenge [Byte]       Bedeutung
 * -----------------------------------------------------------------------------
 * Laenge           3                   Feldlaenge in Bytes
 * Kennung          4                   Feldkennung
 * Inhalt           variabel            Abrechnungsinformationen
 * Ende             2                   ASCII-Wert 13 = CR (Wagenruecklauf)
 *                                      ASCII-Wert 10 = LF (Zeilenvorschub)
 * -----------------------------------------------------------------------------
 *
 * Here is an extract from the German "Arztpraxis Wiegand" (APW) documentation,
 * available at:
 * http://www.apw-wiegand.de/
 *
 * Patientennummerkonvertierung:
 * Beim BDT ... werden die Patientennummern nach folgender Formel konvertiert:
 * Stelle 1: immer 1
 * Stelle 2-3: Parallelabrechnungsnummer (meist 01)
 * Stelle 4-5: 1. Stelle der APW-PatNr umgewandelt in Alphabet-Rangfolge (z.B. a->01, z->26)
 * Stelle 6-7: 2. Stelle der APW-PatNr umgewandelt in Alphabet-Rangfolge
 * ab Stelle 8: ab Stelle 3 der APW-PatNr
 *
 * @param p0 the destination compound model (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source bdt byte array
 * @param p4 the source count
 */
void parse_bdt(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p4 != NULL_POINTER) {

        int* sc = (int*) p4;

        log_message_debug("Parse bdt format into compound model.");

        // The loop variable.
        int j = *NUMBER_0_INTEGER;
        // The source bdt byte array index.
        void* i = NULL_POINTER;
        int ic = *sc;
        // The field identification.
        void* id = NULL_POINTER;
        int idc = *NUMBER_0_INTEGER;
        // The field content.
        void* c = NULL_POINTER;
        int cc = *NUMBER_0_INTEGER;
        // The comparison result.
        int r = *NUMBER_0_INTEGER;

        // Iterate through source bdt byte array.
        while (*NUMBER_1_INTEGER) {

            if (j >= *sc) {

                break;
            }

/*??
            // Parse bdt field.
            parse_bdt_field((void*) &id, (void*) &c, (void*) &cc, (void*) &i, (void*) &ic);

            compare_arrays(id, (void*) RECORD_IDENTIFICATION_BDT_FIELD_COUNT, (void*) RECORD_IDENTIFICATION_BDT_FIELD, (void*) RECORD_IDENTIFICATION_BDT_FIELD_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

            if (r != *NUMBER_0_INTEGER) {

                // Recursively call this operation for the part model.
                parse_patient_record(p0, p1, p2, *a, *ac, *m, *mc, *d, *dc, p9, p10, (void*) &nl);
            }

            // Increment source bdt byte array index with counts for:
            // - field count (3 Byte)
            // - field identification (4 Byte)
            // - content count (dynamic)
            // - carriage return character (1 Byte)
            // - line feed character (1 Byte)
            i = i + *BDT_FIELD_COUNT_COUNT + *BDT_FIELD_IDENTIFICATION_COUNT + cc + *PRIMITIVE_COUNT + *PRIMITIVE_COUNT;

            // Reset field identification.
            id = NULL_POINTER;
            idc = *NUMBER_0_INTEGER;
            // Reset field content.
            c = NULL_POINTER;
            cc = *NUMBER_0_INTEGER;
            // Reset comparison result.
            r = *NUMBER_0_INTEGER;
*/

            // Increment loop variable.
            j++;
        }

    } else {

        log_message_debug("Error: Could not parse bdt format into compound model. The source count is null.");
    }
}

/**
 * Serialises a compound model into a bdt format byte array.
 *
 * @param p0 the destination bdt byte array (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source compound model
 * @param p4 the source count
 */
void serialise_bdt(void* p0, void* p1, void* p2, void* p3, void* p4) {
}

/* BDT_CONVERTER_SOURCE */
#endif
