/*
 * $RCSfile: html_character_mapper.c,v $
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
 * @version $Revision: 1.2 $ $Date: 2007-08-13 16:37:12 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef HTML_CHARACTER_MAPPER_SOURCE
#define HTML_CHARACTER_MAPPER_SOURCE

#include "../../globals/constants/character/character_constants.c"
#include "../../globals/constants/character/html_character_constants.c"
#include "../../globals/constants/integer/integer_constants.c"
#include "../../globals/constants/pointer/pointer_constants.c"
#include "../../globals/variables/variables.c"

//?? CAUTION! Add an extra character code set for &quot; and &amp; etc. !!
//?? and use an OR || when parsing HTML !
//??
//?? The following list contains only those characters, for which a name
//?? like "&euro" exists; others have been deleted.

/*??
Symbol
Code
Entity Name
  €     &euro;
  "  &#34;  &quot;
  &  &#38;  &amp;
  <  &#60;  &lt;
  >  &#62;  &gt;
  Non-breaking space  &#160;  &nbsp;
  ¡  &#161;  &iexcl;
  ¢  &#162;  &cent;
  £  &#163;  &pound;
  ¤  &#164;  &curren;
  ¥  &#165;  &yen;
  ¦  &#166;  &brvbar;
  §  &#167;  &sect;
  ¨  &#168;  &uml;
  ©  &#169;  &copy;
  ª  &#170;  &ordf;
  «  &#171;
  ¬  &#172;  &not;
  ­  &#173;  &shy;
  ®  &#174;  &reg;
  ¯  &#175;  &macr;
  °  &#176;  &deg;
  ±  &#177;  &plusmn;
  ²  &#178;  &sup2;
  ³  &#179;  &sup3;
  ´  &#180;  &acute;
  µ  &#181;  &micro;
  ¶  &#182;  &para;
  ·  &#183;  &middot;
  ¸  &#184;  &cedil;
  ¹  &#185;  &sup1;
  º  &#186;  &ordm;
  »  &#187;  &raquo;
  ¼  &#188;  &frac14;
  ½  &#189;  &frac12;
  ¾  &#190;  &frac34;
  ¿  &#191;  &iquest;
  À  &#192;  &Agrave;
  Á  &#193;  &Aacute;
  Â  &#194;  Â
  Ã  &#195;  &Atilde;
  Ä  &#196;  &Auml;
  Å  &#197  &Aring;
  Æ  &#198;  &AElig;
  Ç  &#199;  &Ccedil;
  È  &#200;  &Egrave;
  É  &#201;  &Eacute;
  Ê  &#202;  &Ecirc;
  Ë  &#203;  Ë
  Ì  &#204;  &Igrave;
  Í  &#205;  &Iacute;
  Î  &#206;  &Icirc;
  Ï  &#207;  &Iuml;
  Ð  &#208;  &ETH;
  Ñ  &#209;  &Ntilde;
  Ò  &#210;  &Ograve;
  Ó  &#211;  &Oacute;
  Ô  &#212;  &Ocirc;
  Õ  &#213;  &Otilde;
  Ö  &#214;  &Ouml;
  ×  &#215;  &times;
  Ø  &#216;  &Oslash;
  Ù  &#217;  &Ugrave;
  Ú  &#218;  &Uacute;
  Û  &#219;  &Ucirc;
  Ü  &#220;  &Uuml;
  Ý  &#221;  &Yacute;
  Þ  &#222;  &THORN;
  ß  &#223;  &szlig;
  à  &#224;  &agrave;
  á  &#225;  &aacute;
  â  &#226;  &acirc;
  ã  &#227;  &atilde;
  ä  &#228;  &auml;
  å  &#229;  &aring;
  æ  &#230;  &aelig;
  ç  &#231;  &ccedil;
  è  &#232;  &egrave;
  é  &#233;  &eacute;
  ê  &#234;  &ecirc;
  ë  &#235;  &euml;
  ì  &#236;  &igrave;
  í  &#237  &iacute;
  î  &#238;  &icirc;
  ï  &#239;  &iuml;
  ð  &#240;  &eth;
  ñ  &#241;  &ntilde;
  ò  &#242;  &ograve;
  ó  &#243;  &oacute;
  ô  &#244;  &ocirc;
  õ  &#245;  &otilde;
  ö  &#246;  &ouml;
  ÷  &#247;  &divide;
  ø  &#248;  &oslash;
  ù  &#249;  &ugrave;
  ú  &#250;  &uacute;
  û  &#251;  &ucirc;
  ü  &#252;  &uuml;
  ý  &#253;  &yacute;
  þ  &#254;  &thorn;
  ÿ  &#255;
*/

/**
 * Maps from html character to character.
 *
 * @param p0 the destination character
 * @param p1 the destination character count
 * @param p2 the destination character size
 * @param p3 the source html character
 * @param p4 the source html character count
 */
void map_from_html_character(void* p0, void* p1, void* p2, void* p3, void* p4) {
}

/**
 * Maps from character to html character.
 *
 * @param p0 the destination html character
 * @param p1 the destination html character count
 * @param p2 the destination html character size
 * @param p3 the source character
 * @param p4 the source character count
 */
void map_to_html_character(void* p0, void* p1, void* p2, void* p3, void* p4) {
}

/* HTML_CHARACTER_MAPPER_SOURCE */
#endif
