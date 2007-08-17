/*
 * $RCSfile: x_window_system_converter.c,v $
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
 * @version $Revision: 1.18 $ $Date: 2007-08-17 03:15:33 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef X_WINDOW_SYSTEM_CONVERTER_SOURCE
#define X_WINDOW_SYSTEM_CONVERTER_SOURCE

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include "../../globals/constants/character/character_constants.c"
#include "../../globals/constants/cybol/cybol_abstraction_constants.c"
#include "../../globals/constants/cybol/cybol_model_constants.c"
#include "../../globals/constants/cybol/cybol_name_constants.c"
#include "../../globals/constants/integer/integer_constants.c"
#include "../../globals/constants/memory_structure/memory_abstraction_constants.c"
#include "../../globals/constants/memory_structure/memory_structure_constants.c"
#include "../../globals/constants/pointer/pointer_constants.c"
#include "../../globals/variables/variables.c"
#include "../../memoriser/accessor.c"

/**
 * Decodes the x window system model into a compound model.
 *
 * @param p0 the destination compound model (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the internal memory containing all x window system windows
 * @param p4 the source count
 */
void decode_x_window_system(void* p0, void* p1, void* p2, void* p3, void* p4) {
}

/**
 * Encodes the source compound model into an x window system model.
 *
 * @param p0 the internal memory containing all x window system internals
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source compound model
 * @param p4 the source compound model count
 * @param p5 the source compound details
 * @param p6 the source compound details count
 * @param p7 the knowledge memory
 * @param p8 the knowledge memory count
 */
void encode_x_window_system(void* p0, void* p1, void* p2, void* p3, void* p4,
    void* p5, void* p6, void* p7, void* p8) {

    if (p4 != *NULL_POINTER) {

        int* sc = (int*) p4;

        log_message_debug("Encode x window system.");

        // The display, which is a subsumption of
        // xserver, screens, hardware (input devices etc.).
        struct _XDisplay** di = (struct _XDisplay**) NULL_POINTER;
        // The window.
        int** w = (int**) NULL_POINTER;
        // The graphic context.
        struct _XGC** gc = (struct _XGC**) NULL_POINTER;
        // The window attributes.
        XWindowAttributes wa;

        // Get x window system internals.
        get_element(p0, (void*) X_WINDOW_SYSTEM_DISPLAY_INTERNAL, (void*) &di, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        get_element(p0, (void*) X_WINDOW_SYSTEM_WINDOW_INTERNAL, (void*) &w, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        get_element(p0, (void*) X_WINDOW_SYSTEM_GRAPHIC_CONTEXT_INTERNAL, (void*) &gc, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

        // Get window attributes.
        XGetWindowAttributes(*di, **w, &wa);

        // The source whole size.
        void** wsn = NULL_POINTER;
        void** wsnc = NULL_POINTER;
        void** wsns = NULL_POINTER;
        void** wsa = NULL_POINTER;
        void** wsac = NULL_POINTER;
        void** wsas = NULL_POINTER;
        void** wsm = NULL_POINTER;
        void** wsmc = NULL_POINTER;
        void** wsms = NULL_POINTER;
        void** wsd = NULL_POINTER;
        void** wsdc = NULL_POINTER;
        void** wsds = NULL_POINTER;

        // The source whole size coordinates.
        int* wsmx = (int*) *NULL_POINTER;
        int* wsmy = (int*) *NULL_POINTER;
        int* wsmz = (int*) *NULL_POINTER;

        // The original area position coordinates, set to the zero origo.
        int oapx = *NUMBER_0_INTEGER;
        int oapy = *NUMBER_0_INTEGER;
        int oapz = *NUMBER_0_INTEGER;
        // The original area size coordinates, initialised with whole coordinates.
        int oasx = *NUMBER_0_INTEGER;
        int oasy = *NUMBER_0_INTEGER;
        int oasz = *NUMBER_0_INTEGER;

        // The free area position coordinates, initialised with original area position coordinates.
        int fapx = oapx;
        int fapy = oapy;
        int fapz = oapz;
        // The free area size coordinates, initialised with original area position coordinates.
        int fasx = oasx;
        int fasy = oasy;
        int fasz = oasz;

        if (p5 != *NULL_POINTER) {

            // Get source whole size from details.
            get_universal_compound_element_by_name(p5, p6,
                (void*) UI_SIZE_NAME, (void*) UI_SIZE_NAME_COUNT,
                (void*) &wsn, (void*) &wsnc, (void*) &wsns,
                (void*) &wsa, (void*) &wsac, (void*) &wsas,
                (void*) &wsm, (void*) &wsmc, (void*) &wsms,
                (void*) &wsd, (void*) &wsdc, (void*) &wsds,
                p7, p8);

            // Determine source whole size coordinates.
            get_element(*wsm, (void*) NUMBER_0_INTEGER, (void*) &wsmx, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
            get_element(*wsm, (void*) NUMBER_1_INTEGER, (void*) &wsmy, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
            get_element(*wsm, (void*) NUMBER_2_INTEGER, (void*) &wsmz, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);

            // Set original area position coordinates, set to the zero origo.
            oapx = *NUMBER_0_INTEGER;
            oapy = *NUMBER_0_INTEGER;
            oapz = *NUMBER_0_INTEGER;
            // Set original area size coordinates, initialised with whole coordinates.
            oasx = *wsmx;
            oasy = *wsmy;
            oasz = *wsmz;

            // Set free area position coordinates, initialised with original area position coordinates.
            fapx = oapx;
            fapy = oapy;
            fapz = oapz;
            // Set free area size coordinates, initialised with original area position coordinates.
            fasx = oasx;
            fasy = oasy;
            fasz = oasz;
        }

        // The source part name, abstraction, model, details.
        void** n = NULL_POINTER;
        void** nc = NULL_POINTER;
        void** ns = NULL_POINTER;
        void** a = NULL_POINTER;
        void** ac = NULL_POINTER;
        void** as = NULL_POINTER;
        void** m = NULL_POINTER;
        void** mc = NULL_POINTER;
        void** ms = NULL_POINTER;
        void** d = NULL_POINTER;
        void** dc = NULL_POINTER;
        void** ds = NULL_POINTER;
        // The source part layout name, abstraction, model, details.
        void** ln = NULL_POINTER;
        void** lnc = NULL_POINTER;
        void** lns = NULL_POINTER;
        void** la = NULL_POINTER;
        void** lac = NULL_POINTER;
        void** las = NULL_POINTER;
        void** lm = NULL_POINTER;
        void** lmc = NULL_POINTER;
        void** lms = NULL_POINTER;
        void** ld = NULL_POINTER;
        void** ldc = NULL_POINTER;
        void** lds = NULL_POINTER;
        // The source part cell name, abstraction, model, details.
        void** cn = NULL_POINTER;
        void** cnc = NULL_POINTER;
        void** cns = NULL_POINTER;
        void** ca = NULL_POINTER;
        void** cac = NULL_POINTER;
        void** cas = NULL_POINTER;
        void** cm = NULL_POINTER;
        void** cmc = NULL_POINTER;
        void** cms = NULL_POINTER;
        void** cd = NULL_POINTER;
        void** cdc = NULL_POINTER;
        void** cds = NULL_POINTER;
        // The source part position name, abstraction, model, details.
        void** pn = NULL_POINTER;
        void** pnc = NULL_POINTER;
        void** pns = NULL_POINTER;
        void** pa = NULL_POINTER;
        void** pac = NULL_POINTER;
        void** pas = NULL_POINTER;
        void** pm = NULL_POINTER;
        void** pmc = NULL_POINTER;
        void** pms = NULL_POINTER;
        void** pd = NULL_POINTER;
        void** pdc = NULL_POINTER;
        void** pds = NULL_POINTER;
        // The source part shape name, abstraction, model, details.
        void** shn = NULL_POINTER;
        void** shnc = NULL_POINTER;
        void** shns = NULL_POINTER;
        void** sha = NULL_POINTER;
        void** shac = NULL_POINTER;
        void** shas = NULL_POINTER;
        void** shm = NULL_POINTER;
        void** shmc = NULL_POINTER;
        void** shms = NULL_POINTER;
        void** shd = NULL_POINTER;
        void** shdc = NULL_POINTER;
        void** shds = NULL_POINTER;
        // The source part size name, abstraction, model, details.
        void** sn = NULL_POINTER;
        void** snc = NULL_POINTER;
        void** sns = NULL_POINTER;
        void** sa = NULL_POINTER;
        void** sac = NULL_POINTER;
        void** sas = NULL_POINTER;
        void** sm = NULL_POINTER;
        void** smc = NULL_POINTER;
        void** sms = NULL_POINTER;
        void** sd = NULL_POINTER;
        void** sdc = NULL_POINTER;
        void** sds = NULL_POINTER;
        // The source part title name, abstraction, model, details.
        void** tn = NULL_POINTER;
        void** tnc = NULL_POINTER;
        void** tns = NULL_POINTER;
        void** ta = NULL_POINTER;
        void** tac = NULL_POINTER;
        void** tas = NULL_POINTER;
        void** tm = NULL_POINTER;
        void** tmc = NULL_POINTER;
        void** tms = NULL_POINTER;
        void** td = NULL_POINTER;
        void** tdc = NULL_POINTER;
        void** tds = NULL_POINTER;
        // The source part icon name, abstraction, model, details.
        void** in = NULL_POINTER;
        void** inc = NULL_POINTER;
        void** ins = NULL_POINTER;
        void** ia = NULL_POINTER;
        void** iac = NULL_POINTER;
        void** ias = NULL_POINTER;
        void** im = NULL_POINTER;
        void** imc = NULL_POINTER;
        void** ims = NULL_POINTER;
        void** id = NULL_POINTER;
        void** idc = NULL_POINTER;
        void** ids = NULL_POINTER;

        // The terminated title.
        void* tt = *NULL_POINTER;
        int tts = *NUMBER_MINUS_1_INTEGER;
        // The terminated icon name.
        void* ti = *NULL_POINTER;
        int tis = *NUMBER_MINUS_1_INTEGER;

        // The source part position coordinates.
        int* pmx = (int*) *NULL_POINTER;
        int* pmy = (int*) *NULL_POINTER;
        int* pmz = (int*) *NULL_POINTER;
        // The source part size coordinates.
        int* smx = (int*) *NULL_POINTER;
        int* smy = (int*) *NULL_POINTER;
        int* smz = (int*) *NULL_POINTER;

        // The loop count.
        int j = *NUMBER_0_INTEGER;
        // The comparison result.
        int r = *NUMBER_0_INTEGER;

        // Iterate through compound parts.
        while (*NUMBER_1_INTEGER) {

            if (j >= *sc) {

                break;
            }

            // Get source part at index j.
            get_compound_element_by_index(p3, p4, (void*) &j,
                (void*) &n, (void*) &nc, (void*) &ns,
                (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms,
                (void*) &d, (void*) &dc, (void*) &ds);

            // Get source part layout from details.
            get_universal_compound_element_by_name(*d, *dc,
                (void*) UI_LAYOUT_NAME, (void*) UI_LAYOUT_NAME_COUNT,
                (void*) &ln, (void*) &lnc, (void*) &lns,
                (void*) &la, (void*) &lac, (void*) &las,
                (void*) &lm, (void*) &lmc, (void*) &lms,
                (void*) &ld, (void*) &ldc, (void*) &lds,
                p7, p8);
            // Get source part cell from details.
            get_universal_compound_element_by_name(*d, *dc,
                (void*) UI_CELL_NAME, (void*) UI_CELL_NAME_COUNT,
                (void*) &cn, (void*) &cnc, (void*) &cns,
                (void*) &ca, (void*) &cac, (void*) &cas,
                (void*) &cm, (void*) &cmc, (void*) &cms,
                (void*) &cd, (void*) &cdc, (void*) &cds,
                p7, p8);
            // Get source part position from details.
            get_universal_compound_element_by_name(*d, *dc,
                (void*) UI_POSITION_NAME, (void*) UI_POSITION_NAME_COUNT,
                (void*) &pn, (void*) &pnc, (void*) &pns,
                (void*) &pa, (void*) &pac, (void*) &pas,
                (void*) &pm, (void*) &pmc, (void*) &pms,
                (void*) &pd, (void*) &pdc, (void*) &pds,
                p7, p8);
            // Get source part size from details.
            get_universal_compound_element_by_name(*d, *dc,
                (void*) UI_SIZE_NAME, (void*) UI_SIZE_NAME_COUNT,
                (void*) &sn, (void*) &snc, (void*) &sns,
                (void*) &sa, (void*) &sac, (void*) &sas,
                (void*) &sm, (void*) &smc, (void*) &sms,
                (void*) &sd, (void*) &sdc, (void*) &sds,
                p7, p8);

            // Get source part position coordinates.
            get_element(*pm, (void*) NUMBER_0_INTEGER, (void*) &pmx, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
            get_element(*pm, (void*) NUMBER_1_INTEGER, (void*) &pmy, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
            get_element(*pm, (void*) NUMBER_2_INTEGER, (void*) &pmz, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
            // Get source part size coordinates.
            get_element(*sm, (void*) NUMBER_0_INTEGER, (void*) &smx, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
            get_element(*sm, (void*) NUMBER_1_INTEGER, (void*) &smy, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
            get_element(*sm, (void*) NUMBER_2_INTEGER, (void*) &smz, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);

    fprintf(stderr, "layout: %s\n", *lm);
    fprintf(stderr, "layout count: %i\n", *((int*) *lmc));

            compare_arrays(*lm, *lmc, (void*) UI_ROOT_LAYOUT_MODEL, (void*) UI_ROOT_LAYOUT_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

            if (r == *NUMBER_0_INTEGER) {

                // The source part is no root window.
                log_message_debug("Debug: This is not a root window.");

                // Calculate coordinates according to given layout.
/*??
                encode_x_window_system_layout(*pmx, *pmy, *pmz, *smx, *smy, *smz,
                    &fapx, &fapy, &fapz, &fasx, &fasy, &fasz,
                    &oapx, &oapy, &oapz, &oasx, &oasy, &oasz,
                    *cm, *cmc, *lm, *lmc);
*/

                // Draw graphical element using given coordinates.
                XDrawRectangle(*di, **w, *gc, *pmx, *pmy, *smx - *NUMBER_1_INTEGER, *smy - *NUMBER_1_INTEGER);

                // Reset comparison result.
                r = *NUMBER_0_INTEGER;

                compare_arrays(*a, *ac, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                if (r != *NUMBER_0_INTEGER) {

                    // The terminated text.
                    char* text = (char*) *NULL_POINTER;
                    int texts = *((int*) *mc) + *NUMBER_1_INTEGER;

                    // Create terminated text.
                    allocate_array((void*) &text, (void*) &texts, (void*) CHARACTER_ARRAY);

                    // Set terminated text by first copying the actual name
                    // and then adding the null termination character.
                    set_array_elements(text, (void*) NUMBER_0_INTEGER, *m, *mc, (void*) CHARACTER_ARRAY);
                    set_array_elements(text, *mc, (void*) NULL_CONTROL_CHARACTER, (void*) PRIMITIVE_COUNT, (void*) CHARACTER_ARRAY);

                    // Draw the text (character vector / string).
                    XDrawString(*di, **w, *gc, *pmx, *pmy + *NUMBER_20_INTEGER, text, texts);

                    // Destroy terminated text.
                    deallocate_array((void*) &text, (void*) &texts, (void*) CHARACTER_ARRAY);

                    /*
                    In the conventional 'XFontStruct' model, an X client opens
                    a font using 'XLoadQueryFont()', draws a string using
                    'XDrawString()', and closes the font using 'XFreeFont()'.
                    On the other hand, in the internationalised 'XFontSet'
                    model, an X client opens a font using 'XCreateFontSet()',
                    draws a string using 'XmbDrawString()', and closes the font
                    using 'XFreeFontSet()'.

                    Following is a concise list of substitutions:
                    - 'XFontStruct' -> 'XFontSet'
                    - 'XLoadQueryFont()' -> 'XCreateFontSet()'
                    - both of 'XDrawString()' and 'XDrawString16'
                      -> either of 'XmbDrawString()' or 'XwcDrawString()'
                    - both of 'XDrawImageString()' and 'XDrawImageString16'
                      -> either of 'XmbDrawImageString()' or 'XwcDrawImageString()'

                    Note that 'XFontStruct' is usually used as a pointer,
                    while 'XFontSet' itself is a pointer.

                    Some people (ISO-8859-1-language speakers) may think that
                    'XFontSet'-related functions are not 8-bit clean. This is wrong.
                    'XFontSet'-related functions work according to 'LC_CTYPE' locale.
                    The default LC_CTYPE locale uses ASCII. Thus, if a user doesn't
                    set the 'LANG', 'LC_CTYPE', nor 'LC_ALL' environmental variable,
                    'XFontSet'-related functions will use ASCII, i.e. are not 8-bit clean.
                    The user has to set the 'LANG', 'LC_CTYPE', or 'LC_ALL'
                    environmental variable properly (for example, 'LANG=en_US').

                    The upstream developers of X clients sometimes hate to
                    enforce users to set such environmental variables.
                    In such a case, The X clients should have two ways to
                    output text, i.e. the 'XFontStruct'-related conventional
                    way and the 'XFontSet'-related internationalized way.
                    If 'setlocale()' returns 'NULL', '"C"', or '"POSIX"', one
                    should use the 'XFontStruct' way, otherwise the 'XFontSet' way.
                    The author implemented this algorithm to a few window managers

                    [1] Though UTF-8 is an encoding with single CCS, the current
                    version of XFree86 (4.0.1) needs multiple fonts to handle UTF-8.
                    [2] All users will have to set LANG properly when UTF-8 will become popular.
                    */

/*??
                    //?? TODO: Move these before the coordinate calculation,
                    //?? in order to adapt the size of the drawn rectangle.

                    // Find text width in pixels, using the given font.
                    // The XTextWidth() function is used to "predict" the width
                    // of a given text string, as it will be drawn using a
                    // given font. This may be used to determine where to draw
                    // the left end of the string so it will look like it's
                    // occupying the middle of the window, for example.
                    int tw = XTextWidth(f, text, strlen(text));

                    // Find font height.
                    // A font has two attributes named "ascent" and "descent",
                    // used to specify the height of the font. Basically, a
                    // font's characters are drawn relative to some imaginary
                    // horizontal line. Part of a character is drawn above this
                    // line, and part of it is drawn below it. The highest
                    // letter is drawn at most "font->ascent" pixels above the
                    // line, while the letter with the lowest part is drawn at
                    // most "font->descent" pixels below that line. Thus, the
                    // sum of these two numbers determines the height of the font.
                    int fh = f->ascent + f->descent;
*/
                }

/*??
                //XDrawImageString (e.xexpose.display, e.xexpose.window, gc, 50, 50, Anwendung.menu_bar1.Datei.name, strlen(Anwendung.menu_bar1.Datei.name));
                //XDrawImageString (e.xexpose.display, e.xexpose.window, gc, 50, 50, str_test, strlen(str_test));
                //XDrawImageString (e.xexpose.display, e.xexpose.window, gc, 50, 50, Anwendung.menu_bar1.menu1.name, strlen(Anwendung.menu_bar1.menu1.name));

                indent_x = 0;
                indent_y = 0;
                indent_menu_item_x = 0;

                for (count_menu=0;count_menu<5;count_menu++) {

                    if (strlen(Anwendung.menu_bar1.menus[count_menu].name)>0) {

                        XDrawImageString (e.xexpose.display, e.xexpose.window, gc_menu_font, (5+indent_x), 16, Anwendung.menu_bar1.menus[count_menu].name, strlen(Anwendung.menu_bar1.menus[count_menu].name));

                        for (count_item=0; ((count_item<9) && (Anwendung.menu_bar1.menus[count_menu].angeklickt==1)); count_item++) {
                            if ((strlen(Anwendung.menu_bar1.menus[count_menu].menu_items[count_item].name)*6)+6 > indent_menu_item_x) {
                            indent_menu_item_x = (strlen(Anwendung.menu_bar1.menus[count_menu].menu_items[count_item].name)*6)+6;
                            }
                        }

                        for (count_item=0; ((count_item<9) && (Anwendung.menu_bar1.menus[count_menu].angeklickt==1)); count_item++) {

                            if (strlen(Anwendung.menu_bar1.menus[count_menu].menu_items[count_item].name)>0) {

                                indent_y = indent_y + 17;
                                //if ((strlen(Anwendung.menu_bar1.menus[count_menu].menu_items[count_item].name)*6)+6 > indent_menu_item_x) {
                                //  XFillRectangle (e.xexpose.display, e.xexpose.window, gc_menu_border_bottom, indent_menu_item_x, 20 + (count_item*17), (strlen(Anwendung.menu_bar1.menus[count_menu].menu_items[count_item].name)*6)+6, 19);
                                //  indent_menu_item_x = (strlen(Anwendung.menu_bar1.menus[count_menu].menu_items[count_item].name)*6)+6;
                                //
                                //}
                                //XFillRectangle (e.xexpose.display, e.xexpose.window, gc_menu, (5+indent_x), 20 + (count_item*17), (5+indent_x+50), 19);
                                XFillRectangle (e.xexpose.display, e.xexpose.window, gc_menu, (3+indent_x), 20 + (count_item*17), indent_menu_item_x, 19);
                                XDrawImageString (e.xexpose.display, e.xexpose.window, gc_menu_font, (5+indent_x), 33 + (count_item*17), Anwendung.menu_bar1.menus[count_menu].menu_items[count_item].name, strlen(Anwendung.menu_bar1.menus[count_menu].menu_items[count_item].name));
                            }
                        }

                        if (Anwendung.menu_bar1.menus[count_menu].angeklickt==1) {

                            XDrawLine(*di, **w, gc_menu_border_bottom, (3+indent_x), (21+indent_y), (3+indent_x+indent_menu_item_x), (21+indent_y));
                            XDrawLine(*di, **w, gc_menu_border_bottom, (3+indent_x+indent_menu_item_x), 20, (3+indent_x+indent_menu_item_x), (21+indent_y));
                            XDrawLine(*di, **w, gc_menu_border_top, (3+indent_x), 19, (3+indent_x+indent_menu_item_x), 19);
                            XDrawLine(*di, **w, gc_menu_border_top, (3+indent_x), 19, (3+indent_x), (20+indent_y));
                        }

                        indent_x = indent_x + (strlen(Anwendung.menu_bar1.menus[count_menu].name) * 6) + 10;
                    }
                }
*/

            } else {

                // The source part is a root window.
                log_message_debug("Debug: This is a root window.");

                // Move window to new position coordinates for part.
                XMoveWindow(*di, **w, *pmx, *pmy);
                // Resize window to new size coordinates for part.
                XResizeWindow(*di, **w, *smx, *smy);

                // Get source part title from details.
                get_universal_compound_element_by_name(*d, *dc,
                    (void*) GUI_TITLE_NAME, (void*) GUI_TITLE_NAME_COUNT,
                    (void*) &tn, (void*) &tnc, (void*) &tns,
                    (void*) &ta, (void*) &tac, (void*) &tas,
                    (void*) &tm, (void*) &tmc, (void*) &tms,
                    (void*) &td, (void*) &tdc, (void*) &tds,
                    p7, p8);
                // Get source part icon from details.
                get_universal_compound_element_by_name(*d, *dc,
                    (void*) GUI_ICON_NAME, (void*) GUI_ICON_NAME_COUNT,
                    (void*) &in, (void*) &inc, (void*) &ins,
                    (void*) &ia, (void*) &iac, (void*) &ias,
                    (void*) &im, (void*) &imc, (void*) &ims,
                    (void*) &id, (void*) &idc, (void*) &ids,
                    p7, p8);

                // The terminated title.
                tt = *NULL_POINTER;
                tts = *((int*) *tmc) + *NUMBER_1_INTEGER;
                // The terminated icon name.
                ti = *NULL_POINTER;
                tis = *((int*) *imc) + *NUMBER_1_INTEGER;

                // Create terminated title.
                allocate_array((void*) &tt, (void*) &tts, (void*) CHARACTER_ARRAY);
                // Create terminated icon name.
                allocate_array((void*) &ti, (void*) &tis, (void*) CHARACTER_ARRAY);

                // Set terminated title by first copying the actual name
                // and then adding the null termination character.
                set_array_elements(tt, (void*) NUMBER_0_INTEGER, *tm, *tmc, (void*) CHARACTER_ARRAY);
                set_array_elements(tt, *tmc, (void*) NULL_CONTROL_CHARACTER, (void*) PRIMITIVE_COUNT, (void*) CHARACTER_ARRAY);
                // Set terminated icon name by first copying the actual name
                // and then adding the null termination character.
                set_array_elements(ti, (void*) NUMBER_0_INTEGER, *im, *imc, (void*) CHARACTER_ARRAY);
                set_array_elements(ti, *imc, (void*) NULL_CONTROL_CHARACTER, (void*) PRIMITIVE_COUNT, (void*) CHARACTER_ARRAY);

                // Set terminated window title.
                XStoreName(*di, **w, (char*) tt);
                // Set terminated window icon.
                XSetIconName(*di, **w, (char*) ti);

                // Destroy terminated title.
                deallocate_array((void*) &tt, (void*) &tts, (void*) CHARACTER_ARRAY);
                // Destroy terminated icon name.
                deallocate_array((void*) &ti, (void*) &tis, (void*) CHARACTER_ARRAY);
            }

            // Reset comparison result.
            r = *NUMBER_0_INTEGER;

            compare_arrays(*a, *ac, (void*) COMPOUND_ABSTRACTION, (void*) COMPOUND_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

            if (r != *NUMBER_0_INTEGER) {

                // The part model is a compound.
                log_message_debug("Debug: The part model is a compound.");

                // Recursively call this procedure for compound part model.
                encode_x_window_system(p0, p1, p2, *m, *mc, *d, *dc, p7, p8);
            }

            // Reset source part name, abstraction, model, details.
            n = NULL_POINTER;
            nc = NULL_POINTER;
            ns = NULL_POINTER;
            a = NULL_POINTER;
            ac = NULL_POINTER;
            as = NULL_POINTER;
            m = NULL_POINTER;
            mc = NULL_POINTER;
            ms = NULL_POINTER;
            d = NULL_POINTER;
            dc = NULL_POINTER;
            ds = NULL_POINTER;
            // Reset source part layout.
            la = NULL_POINTER;
            lac = NULL_POINTER;
            las = NULL_POINTER;
            lm = NULL_POINTER;
            lmc = NULL_POINTER;
            lms = NULL_POINTER;
            ld = NULL_POINTER;
            ldc = NULL_POINTER;
            lds = NULL_POINTER;
            // Reset source part cell.
            ca = NULL_POINTER;
            cac = NULL_POINTER;
            cas = NULL_POINTER;
            cm = NULL_POINTER;
            cmc = NULL_POINTER;
            cms = NULL_POINTER;
            cd = NULL_POINTER;
            cdc = NULL_POINTER;
            cds = NULL_POINTER;
            // Reset source part position.
            pa = NULL_POINTER;
            pac = NULL_POINTER;
            pas = NULL_POINTER;
            pm = NULL_POINTER;
            pmc = NULL_POINTER;
            pms = NULL_POINTER;
            pd = NULL_POINTER;
            pdc = NULL_POINTER;
            pds = NULL_POINTER;
            // Reset source part size.
            sa = NULL_POINTER;
            sac = NULL_POINTER;
            sas = NULL_POINTER;
            sm = NULL_POINTER;
            smc = NULL_POINTER;
            sms = NULL_POINTER;
            sd = NULL_POINTER;
            sdc = NULL_POINTER;
            sds = NULL_POINTER;
            // The source part title and icon are not reset,
            // since only one window may be the root of all graphical parts
            // and further windows must not occur as part.

            // Reset source part position coordinates.
            pmx = (int*) *NULL_POINTER;
            pmy = (int*) *NULL_POINTER;
            pmz = (int*) *NULL_POINTER;
            // Reset source part size coordinates.
            smx = (int*) *NULL_POINTER;
            smy = (int*) *NULL_POINTER;
            smz = (int*) *NULL_POINTER;

            // Reset terminated title.
            tt = *NULL_POINTER;
            tts = *NUMBER_MINUS_1_INTEGER;
            // Reset terminated icon name.
            ti = *NULL_POINTER;
            tis = *NUMBER_MINUS_1_INTEGER;

            // Reset comparison result.
            r = *NUMBER_0_INTEGER;

            // Increment loop count.
            j++;
        }

    } else {

        log_message_debug("Could not encode x window system. The source count is null.");
    }
}

/* X_WINDOW_SYSTEM_CONVERTER_SOURCE */
#endif
