/*
 * Copyright (C) 1999-2010. Christian Heller.
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
 * @version $RCSfile: x_window_system_converter.c,v $ $Revision: 1.33 $ $Date: 2009-10-06 21:25:27 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef X_WINDOW_SYSTEM_ENCODER_SOURCE
#define X_WINDOW_SYSTEM_ENCODER_SOURCE

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include "../../../constant/abstraction/cybol/text_cybol_abstraction.c"
#include "../../../constant/abstraction/memory/memory_abstraction.c"
#include "../../../constant/model/character_code/ascii/ascii_character_code_model.c"
#include "../../../constant/model/cybol/layout_cybol_model.c"
#include "../../../constant/model/memory/integer_memory_model.c"
#include "../../../constant/model/memory/pointer_memory_model.c"
#include "../../../constant/name/cybol/graphical_user_interface_cybol_name.c"
#include "../../../constant/name/memory/internal_memory_memory_name.c"
#include "../../../executor/accessor/getter.c"

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
void encode_x_window_system(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8) {

    if (p4 != *NULL_POINTER_MEMORY_MODEL) {

        int* sc = (int*) p4;

        log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Encode x window system.");

        // The display, which is a subsumption of
        // xserver, screens, hardware (input devices etc.).
        struct _XDisplay** di = (struct _XDisplay**) NULL_POINTER_MEMORY_MODEL;
        // The window.
        int** w = (int**) NULL_POINTER_MEMORY_MODEL;
        // The graphic context.
        struct _XGC** gc = (struct _XGC**) NULL_POINTER_MEMORY_MODEL;
        // The window attributes.
        XWindowAttributes wa;

        // Get x window system internals.
        get((void*) &di, p0, (void*) X_WINDOW_SYSTEM_DISPLAY_INTERNAL_MEMORY_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);
        get((void*) &w, p0, (void*) X_WINDOW_SYSTEM_WINDOW_INTERNAL_MEMORY_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);
        get((void*) &gc, p0, (void*) X_WINDOW_SYSTEM_GRAPHIC_CONTEXT_INTERNAL_MEMORY_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);

        // Get window attributes.
        XGetWindowAttributes(*di, **w, &wa);

        // The source whole size.
        void** wsn = NULL_POINTER_MEMORY_MODEL;
        void** wsnc = NULL_POINTER_MEMORY_MODEL;
        void** wsns = NULL_POINTER_MEMORY_MODEL;
        void** wsa = NULL_POINTER_MEMORY_MODEL;
        void** wsac = NULL_POINTER_MEMORY_MODEL;
        void** wsas = NULL_POINTER_MEMORY_MODEL;
        void** wsm = NULL_POINTER_MEMORY_MODEL;
        void** wsmc = NULL_POINTER_MEMORY_MODEL;
        void** wsms = NULL_POINTER_MEMORY_MODEL;
        void** wsd = NULL_POINTER_MEMORY_MODEL;
        void** wsdc = NULL_POINTER_MEMORY_MODEL;
        void** wsds = NULL_POINTER_MEMORY_MODEL;

        // The source whole size coordinates.
        int* wsmx = (int*) *NULL_POINTER_MEMORY_MODEL;
        int* wsmy = (int*) *NULL_POINTER_MEMORY_MODEL;
        int* wsmz = (int*) *NULL_POINTER_MEMORY_MODEL;

        // The original area position coordinates, set to the zero origo.
        int oapx = *NUMBER_0_INTEGER_MEMORY_MODEL;
        int oapy = *NUMBER_0_INTEGER_MEMORY_MODEL;
        int oapz = *NUMBER_0_INTEGER_MEMORY_MODEL;
        // The original area size coordinates, initialised with whole coordinates.
        int oasx = *NUMBER_0_INTEGER_MEMORY_MODEL;
        int oasy = *NUMBER_0_INTEGER_MEMORY_MODEL;
        int oasz = *NUMBER_0_INTEGER_MEMORY_MODEL;

        // The free area position coordinates, initialised with original area position coordinates.
        int fapx = oapx;
        int fapy = oapy;
        int fapz = oapz;
        // The free area size coordinates, initialised with original area position coordinates.
        int fasx = oasx;
        int fasy = oasy;
        int fasz = oasz;

        if (p5 != *NULL_POINTER_MEMORY_MODEL) {

            // Get source whole size from details.
            get_universal_compound_element_by_name(
                (void*) &wsn, (void*) &wsnc, (void*) &wsns,
                (void*) &wsa, (void*) &wsac, (void*) &wsas,
                (void*) &wsm, (void*) &wsmc, (void*) &wsms,
                (void*) &wsd, (void*) &wsdc, (void*) &wsds,
                p5, p6,
                (void*) SIZE_GRAPHICAL_USER_INTERFACE_CYBOL_NAME, (void*) SIZE_GRAPHICAL_USER_INTERFACE_CYBOL_NAME_COUNT,
                p7, p8);

            // Determine source whole size coordinates.
            get((void*) &wsmx, *wsm, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) INTEGER_MEMORY_ABSTRACTION, (void*) INTEGER_MEMORY_ABSTRACTION_COUNT);
            get((void*) &wsmy, *wsm, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) INTEGER_MEMORY_ABSTRACTION, (void*) INTEGER_MEMORY_ABSTRACTION_COUNT);
            get((void*) &wsmz, *wsm, (void*) NUMBER_2_INTEGER_MEMORY_MODEL, (void*) INTEGER_MEMORY_ABSTRACTION, (void*) INTEGER_MEMORY_ABSTRACTION_COUNT);

            // Set original area position coordinates, set to the zero origo.
            oapx = *NUMBER_0_INTEGER_MEMORY_MODEL;
            oapy = *NUMBER_0_INTEGER_MEMORY_MODEL;
            oapz = *NUMBER_0_INTEGER_MEMORY_MODEL;
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
        void** n = NULL_POINTER_MEMORY_MODEL;
        void** nc = NULL_POINTER_MEMORY_MODEL;
        void** ns = NULL_POINTER_MEMORY_MODEL;
        void** a = NULL_POINTER_MEMORY_MODEL;
        void** ac = NULL_POINTER_MEMORY_MODEL;
        void** as = NULL_POINTER_MEMORY_MODEL;
        void** m = NULL_POINTER_MEMORY_MODEL;
        void** mc = NULL_POINTER_MEMORY_MODEL;
        void** ms = NULL_POINTER_MEMORY_MODEL;
        void** d = NULL_POINTER_MEMORY_MODEL;
        void** dc = NULL_POINTER_MEMORY_MODEL;
        void** ds = NULL_POINTER_MEMORY_MODEL;
        // The source part layout name, abstraction, model, details.
        void** ln = NULL_POINTER_MEMORY_MODEL;
        void** lnc = NULL_POINTER_MEMORY_MODEL;
        void** lns = NULL_POINTER_MEMORY_MODEL;
        void** la = NULL_POINTER_MEMORY_MODEL;
        void** lac = NULL_POINTER_MEMORY_MODEL;
        void** las = NULL_POINTER_MEMORY_MODEL;
        void** lm = NULL_POINTER_MEMORY_MODEL;
        void** lmc = NULL_POINTER_MEMORY_MODEL;
        void** lms = NULL_POINTER_MEMORY_MODEL;
        void** ld = NULL_POINTER_MEMORY_MODEL;
        void** ldc = NULL_POINTER_MEMORY_MODEL;
        void** lds = NULL_POINTER_MEMORY_MODEL;
        // The source part cell name, abstraction, model, details.
        void** cn = NULL_POINTER_MEMORY_MODEL;
        void** cnc = NULL_POINTER_MEMORY_MODEL;
        void** cns = NULL_POINTER_MEMORY_MODEL;
        void** ca = NULL_POINTER_MEMORY_MODEL;
        void** cac = NULL_POINTER_MEMORY_MODEL;
        void** cas = NULL_POINTER_MEMORY_MODEL;
        void** cm = NULL_POINTER_MEMORY_MODEL;
        void** cmc = NULL_POINTER_MEMORY_MODEL;
        void** cms = NULL_POINTER_MEMORY_MODEL;
        void** cd = NULL_POINTER_MEMORY_MODEL;
        void** cdc = NULL_POINTER_MEMORY_MODEL;
        void** cds = NULL_POINTER_MEMORY_MODEL;
        // The source part position name, abstraction, model, details.
        void** pn = NULL_POINTER_MEMORY_MODEL;
        void** pnc = NULL_POINTER_MEMORY_MODEL;
        void** pns = NULL_POINTER_MEMORY_MODEL;
        void** pa = NULL_POINTER_MEMORY_MODEL;
        void** pac = NULL_POINTER_MEMORY_MODEL;
        void** pas = NULL_POINTER_MEMORY_MODEL;
        void** pm = NULL_POINTER_MEMORY_MODEL;
        void** pmc = NULL_POINTER_MEMORY_MODEL;
        void** pms = NULL_POINTER_MEMORY_MODEL;
        void** pd = NULL_POINTER_MEMORY_MODEL;
        void** pdc = NULL_POINTER_MEMORY_MODEL;
        void** pds = NULL_POINTER_MEMORY_MODEL;
        // The source part shape name, abstraction, model, details.
        void** shn = NULL_POINTER_MEMORY_MODEL;
        void** shnc = NULL_POINTER_MEMORY_MODEL;
        void** shns = NULL_POINTER_MEMORY_MODEL;
        void** sha = NULL_POINTER_MEMORY_MODEL;
        void** shac = NULL_POINTER_MEMORY_MODEL;
        void** shas = NULL_POINTER_MEMORY_MODEL;
        void** shm = NULL_POINTER_MEMORY_MODEL;
        void** shmc = NULL_POINTER_MEMORY_MODEL;
        void** shms = NULL_POINTER_MEMORY_MODEL;
        void** shd = NULL_POINTER_MEMORY_MODEL;
        void** shdc = NULL_POINTER_MEMORY_MODEL;
        void** shds = NULL_POINTER_MEMORY_MODEL;
        // The source part size name, abstraction, model, details.
        void** sn = NULL_POINTER_MEMORY_MODEL;
        void** snc = NULL_POINTER_MEMORY_MODEL;
        void** sns = NULL_POINTER_MEMORY_MODEL;
        void** sa = NULL_POINTER_MEMORY_MODEL;
        void** sac = NULL_POINTER_MEMORY_MODEL;
        void** sas = NULL_POINTER_MEMORY_MODEL;
        void** sm = NULL_POINTER_MEMORY_MODEL;
        void** smc = NULL_POINTER_MEMORY_MODEL;
        void** sms = NULL_POINTER_MEMORY_MODEL;
        void** sd = NULL_POINTER_MEMORY_MODEL;
        void** sdc = NULL_POINTER_MEMORY_MODEL;
        void** sds = NULL_POINTER_MEMORY_MODEL;
        // The source part title name, abstraction, model, details.
        void** tn = NULL_POINTER_MEMORY_MODEL;
        void** tnc = NULL_POINTER_MEMORY_MODEL;
        void** tns = NULL_POINTER_MEMORY_MODEL;
        void** ta = NULL_POINTER_MEMORY_MODEL;
        void** tac = NULL_POINTER_MEMORY_MODEL;
        void** tas = NULL_POINTER_MEMORY_MODEL;
        void** tm = NULL_POINTER_MEMORY_MODEL;
        void** tmc = NULL_POINTER_MEMORY_MODEL;
        void** tms = NULL_POINTER_MEMORY_MODEL;
        void** td = NULL_POINTER_MEMORY_MODEL;
        void** tdc = NULL_POINTER_MEMORY_MODEL;
        void** tds = NULL_POINTER_MEMORY_MODEL;
        // The source part icon name, abstraction, model, details.
        void** in = NULL_POINTER_MEMORY_MODEL;
        void** inc = NULL_POINTER_MEMORY_MODEL;
        void** ins = NULL_POINTER_MEMORY_MODEL;
        void** ia = NULL_POINTER_MEMORY_MODEL;
        void** iac = NULL_POINTER_MEMORY_MODEL;
        void** ias = NULL_POINTER_MEMORY_MODEL;
        void** im = NULL_POINTER_MEMORY_MODEL;
        void** imc = NULL_POINTER_MEMORY_MODEL;
        void** ims = NULL_POINTER_MEMORY_MODEL;
        void** id = NULL_POINTER_MEMORY_MODEL;
        void** idc = NULL_POINTER_MEMORY_MODEL;
        void** ids = NULL_POINTER_MEMORY_MODEL;

        // The terminated title.
        void* tt = *NULL_POINTER_MEMORY_MODEL;
        int ttc = *NUMBER_MINUS_1_INTEGER_MEMORY_MODEL;
        int tts = *NUMBER_MINUS_1_INTEGER_MEMORY_MODEL;
        // The terminated icon name.
        void* ti = *NULL_POINTER_MEMORY_MODEL;
        int tic = *NUMBER_MINUS_1_INTEGER_MEMORY_MODEL;
        int tis = *NUMBER_MINUS_1_INTEGER_MEMORY_MODEL;

        // The source part position coordinates.
        int* pmx = (int*) *NULL_POINTER_MEMORY_MODEL;
        int* pmy = (int*) *NULL_POINTER_MEMORY_MODEL;
        int* pmz = (int*) *NULL_POINTER_MEMORY_MODEL;
        // The source part size coordinates.
        int* smx = (int*) *NULL_POINTER_MEMORY_MODEL;
        int* smy = (int*) *NULL_POINTER_MEMORY_MODEL;
        int* smz = (int*) *NULL_POINTER_MEMORY_MODEL;

        // The loop count.
        int j = *NUMBER_0_INTEGER_MEMORY_MODEL;
        // The comparison result.
        int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

        // Iterate through compound parts.
        while (*NUMBER_1_INTEGER_MEMORY_MODEL) {

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
            get_universal_compound_element_by_name(
                (void*) &ln, (void*) &lnc, (void*) &lns,
                (void*) &la, (void*) &lac, (void*) &las,
                (void*) &lm, (void*) &lmc, (void*) &lms,
                (void*) &ld, (void*) &ldc, (void*) &lds,
                *d, *dc,
                (void*) LAYOUT_GRAPHICAL_USER_INTERFACE_CYBOL_NAME, (void*) LAYOUT_GRAPHICAL_USER_INTERFACE_CYBOL_NAME_COUNT,
                p7, p8);
            // Get source part cell from details.
            get_universal_compound_element_by_name(
                (void*) &cn, (void*) &cnc, (void*) &cns,
                (void*) &ca, (void*) &cac, (void*) &cas,
                (void*) &cm, (void*) &cmc, (void*) &cms,
                (void*) &cd, (void*) &cdc, (void*) &cds,
                *d, *dc,
                (void*) CELL_GRAPHICAL_USER_INTERFACE_CYBOL_NAME, (void*) CELL_GRAPHICAL_USER_INTERFACE_CYBOL_NAME_COUNT,
                p7, p8);
            // Get source part position from details.
            get_universal_compound_element_by_name(
                (void*) &pn, (void*) &pnc, (void*) &pns,
                (void*) &pa, (void*) &pac, (void*) &pas,
                (void*) &pm, (void*) &pmc, (void*) &pms,
                (void*) &pd, (void*) &pdc, (void*) &pds,
                *d, *dc,
                (void*) POSITION_GRAPHICAL_USER_INTERFACE_CYBOL_NAME, (void*) POSITION_GRAPHICAL_USER_INTERFACE_CYBOL_NAME_COUNT,
                p7, p8);
            // Get source part size from details.
            get_universal_compound_element_by_name(
                (void*) &sn, (void*) &snc, (void*) &sns,
                (void*) &sa, (void*) &sac, (void*) &sas,
                (void*) &sm, (void*) &smc, (void*) &sms,
                (void*) &sd, (void*) &sdc, (void*) &sds,
                *d, *dc,
                (void*) SIZE_GRAPHICAL_USER_INTERFACE_CYBOL_NAME, (void*) SIZE_GRAPHICAL_USER_INTERFACE_CYBOL_NAME_COUNT,
                p7, p8);

            // Get source part position coordinates.
            get((void*) &pmx, *pm, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) INTEGER_MEMORY_ABSTRACTION, (void*) INTEGER_MEMORY_ABSTRACTION_COUNT);
            get((void*) &pmy, *pm, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) INTEGER_MEMORY_ABSTRACTION, (void*) INTEGER_MEMORY_ABSTRACTION_COUNT);
            get((void*) &pmz, *pm, (void*) NUMBER_2_INTEGER_MEMORY_MODEL, (void*) INTEGER_MEMORY_ABSTRACTION, (void*) INTEGER_MEMORY_ABSTRACTION_COUNT);
            // Get source part size coordinates.
            get((void*) &smx, *sm, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) INTEGER_MEMORY_ABSTRACTION, (void*) INTEGER_MEMORY_ABSTRACTION_COUNT);
            get((void*) &smy, *sm, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) INTEGER_MEMORY_ABSTRACTION, (void*) INTEGER_MEMORY_ABSTRACTION_COUNT);
            get((void*) &smz, *sm, (void*) NUMBER_2_INTEGER_MEMORY_MODEL, (void*) INTEGER_MEMORY_ABSTRACTION, (void*) INTEGER_MEMORY_ABSTRACTION_COUNT);

/*??
    fwprintf(stdout, L"layout: %s\n", *lm);
    fwprintf(stdout, L"layout count: %i\n", *((int*) *lmc));
*/

            compare_equal_arrays((void*) &r, *lm, *lmc, (void*) ROOT_LAYOUT_CYBOL_MODEL, (void*) ROOT_LAYOUT_CYBOL_MODEL_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

            if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                // The source part is no root window.
                log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"This is not a root window.");

                // Calculate coordinates according to given layout.
/*??
                encode_x_window_system_layout(*pmx, *pmy, *pmz, *smx, *smy, *smz,
                    &fapx, &fapy, &fapz, &fasx, &fasy, &fasz,
                    &oapx, &oapy, &oapz, &oasx, &oasy, &oasz,
                    *cm, *cmc, *lm, *lmc);
*/

                // Draw graphical element using given coordinates.
                XDrawRectangle(*di, **w, *gc, *pmx, *pmy, *smx - *NUMBER_1_INTEGER_MEMORY_MODEL, *smy - *NUMBER_1_INTEGER_MEMORY_MODEL);

                // Reset comparison result.
                r = *NUMBER_0_INTEGER_MEMORY_MODEL;

                compare_equal_arrays((void*) &r, *a, *ac, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    // The terminated text.
                    char* text = (char*) *NULL_POINTER_MEMORY_MODEL;
                    int textc = *NUMBER_0_INTEGER_MEMORY_MODEL;
                    int texts = *NUMBER_0_INTEGER_MEMORY_MODEL;

                    // Create terminated text.
                    allocate_array((void*) &text, (void*) &texts, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    // Encode wide character name into text, which is a multibyte character array.
                    encode_utf_8_unicode_character_vector((void*) &text, (void*) &textc, (void*) &texts, *m, *mc);

                    if (texts <= textc) {

                        // Increase character array size to have place for the termination character.
                        texts = textc + *NUMBER_1_INTEGER_MEMORY_MODEL;

                        // Reallocate terminated file name as multibyte character array.
                        reallocate_array((void*) &text, (void*) &textc, (void*) &texts, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);
                    }

                    // Add null termination character to text.
                    set_array_elements(text, (void*) NULL_CONTROL_ASCII_CHARACTER_CODE_MODEL, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) &textc, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    //?? TODO: Create "text" as 2byte character array,
                    //?? since the xlib C library expects it that way.
                    //?? Introduce new array modules with functions for a 2byte character array!

                    // Draw the text (character vector/ string).
                    //
                    // CAUTION! The Xlib C Library offers a function "XDrawString16"
                    // to draw 2byte characters in a given drawable.
                    // However, standard utf-8 encoded characters are used here.
                    XDrawString(*di, **w, *gc, *pmx, *pmy + *NUMBER_20_INTEGER_MEMORY_MODEL, text, textc);

                    // Destroy terminated text.
                    deallocate_array((void*) &text, (void*) &texts, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

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
                    int tw = XTextWidth(f, text, wcslen(text));

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
                //XDrawImageString (e.xexpose.display, e.xexpose.window, gc, 50, 50, Anwendung.menu_bar1.Datei.name, wcslen(Anwendung.menu_bar1.Datei.name));
                //XDrawImageString (e.xexpose.display, e.xexpose.window, gc, 50, 50, str_test, wcslen(str_test));
                //XDrawImageString (e.xexpose.display, e.xexpose.window, gc, 50, 50, Anwendung.menu_bar1.menu1.name, wcslen(Anwendung.menu_bar1.menu1.name));

                indent_x = 0;
                indent_y = 0;
                indent_menu_item_x = 0;

                for (count_menu=0;count_menu<5;count_menu++) {

                    if (wcslen(Anwendung.menu_bar1.menus[count_menu].name)>0) {

                        XDrawImageString (e.xexpose.display, e.xexpose.window, gc_menu_font, (5+indent_x), 16, Anwendung.menu_bar1.menus[count_menu].name, wcslen(Anwendung.menu_bar1.menus[count_menu].name));

                        for (count_item=0; ((count_item<9) && (Anwendung.menu_bar1.menus[count_menu].angeklickt==1)); count_item++) {
                            if ((wcslen(Anwendung.menu_bar1.menus[count_menu].menu_items[count_item].name)*6)+6 > indent_menu_item_x) {
                            indent_menu_item_x = (wcslen(Anwendung.menu_bar1.menus[count_menu].menu_items[count_item].name)*6)+6;
                            }
                        }

                        for (count_item=0; ((count_item<9) && (Anwendung.menu_bar1.menus[count_menu].angeklickt==1)); count_item++) {

                            if (wcslen(Anwendung.menu_bar1.menus[count_menu].menu_items[count_item].name)>0) {

                                indent_y = indent_y + 17;
                                //if ((wcslen(Anwendung.menu_bar1.menus[count_menu].menu_items[count_item].name)*6)+6 > indent_menu_item_x) {
                                //  XFillRectangle (e.xexpose.display, e.xexpose.window, gc_menu_border_bottom, indent_menu_item_x, 20 + (count_item*17), (wcslen(Anwendung.menu_bar1.menus[count_menu].menu_items[count_item].name)*6)+6, 19);
                                //  indent_menu_item_x = (wcslen(Anwendung.menu_bar1.menus[count_menu].menu_items[count_item].name)*6)+6;
                                //
                                //}
                                //XFillRectangle (e.xexpose.display, e.xexpose.window, gc_menu, (5+indent_x), 20 + (count_item*17), (5+indent_x+50), 19);
                                XFillRectangle (e.xexpose.display, e.xexpose.window, gc_menu, (3+indent_x), 20 + (count_item*17), indent_menu_item_x, 19);
                                XDrawImageString (e.xexpose.display, e.xexpose.window, gc_menu_font, (5+indent_x), 33 + (count_item*17), Anwendung.menu_bar1.menus[count_menu].menu_items[count_item].name, wcslen(Anwendung.menu_bar1.menus[count_menu].menu_items[count_item].name));
                            }
                        }

                        if (Anwendung.menu_bar1.menus[count_menu].angeklickt==1) {

                            XDrawLine(*di, **w, gc_menu_border_bottom, (3+indent_x), (21+indent_y), (3+indent_x+indent_menu_item_x), (21+indent_y));
                            XDrawLine(*di, **w, gc_menu_border_bottom, (3+indent_x+indent_menu_item_x), 20, (3+indent_x+indent_menu_item_x), (21+indent_y));
                            XDrawLine(*di, **w, gc_menu_border_top, (3+indent_x), 19, (3+indent_x+indent_menu_item_x), 19);
                            XDrawLine(*di, **w, gc_menu_border_top, (3+indent_x), 19, (3+indent_x), (20+indent_y));
                        }

                        indent_x = indent_x + (wcslen(Anwendung.menu_bar1.menus[count_menu].name) * 6) + 10;
                    }
                }
*/

            } else {

                // The source part is a root window.
                log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"This is a root window.");

                // Move window to new position coordinates for part.
                XMoveWindow(*di, **w, *pmx, *pmy);
                // Resize window to new size coordinates for part.
                XResizeWindow(*di, **w, *smx, *smy);

                // Get source part title from details.
                get_universal_compound_element_by_name(
                    (void*) &tn, (void*) &tnc, (void*) &tns,
                    (void*) &ta, (void*) &tac, (void*) &tas,
                    (void*) &tm, (void*) &tmc, (void*) &tms,
                    (void*) &td, (void*) &tdc, (void*) &tds,
                    *d, *dc,
                    (void*) TITLE_GRAPHICAL_USER_INTERFACE_CYBOL_NAME, (void*) TITLE_GRAPHICAL_USER_INTERFACE_CYBOL_NAME_COUNT,
                    p7, p8);
                // Get source part icon from details.
                get_universal_compound_element_by_name(
                    (void*) &in, (void*) &inc, (void*) &ins,
                    (void*) &ia, (void*) &iac, (void*) &ias,
                    (void*) &im, (void*) &imc, (void*) &ims,
                    (void*) &id, (void*) &idc, (void*) &ids,
                    *d, *dc,
                    (void*) ICON_GRAPHICAL_USER_INTERFACE_CYBOL_NAME, (void*) ICON_GRAPHICAL_USER_INTERFACE_CYBOL_NAME_COUNT,
                    p7, p8);

                // The terminated title.
                tt = *NULL_POINTER_MEMORY_MODEL;
                ttc = *NUMBER_0_INTEGER_MEMORY_MODEL;
                tts = *NUMBER_0_INTEGER_MEMORY_MODEL;
                // The terminated icon name.
                ti = *NULL_POINTER_MEMORY_MODEL;
                tic = *NUMBER_0_INTEGER_MEMORY_MODEL;
                tis = *NUMBER_0_INTEGER_MEMORY_MODEL;

                // Create terminated title.
                allocate_array((void*) &tt, (void*) &tts, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);
                // Create terminated icon name.
                allocate_array((void*) &ti, (void*) &tis, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                // Encode wide character name into title, which is a multibyte character array.
                encode_utf_8_unicode_character_vector((void*) &tt, (void*) &ttc, (void*) &tts, *tm, *tmc);
                // Encode wide character name into icon name, which is a multibyte character array.
                encode_utf_8_unicode_character_vector((void*) &ti, (void*) &tic, (void*) &tis, *im, *imc);

                if (tts <= ttc) {

                    // Increase character array size to have place for the termination character.
                    tts = ttc + *NUMBER_1_INTEGER_MEMORY_MODEL;

                    // Reallocate title as multibyte character array.
                    reallocate_array((void*) &tt, (void*) &ttc, (void*) &tts, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);
                }

                if (tis <= tic) {

                    // Increase character array size to have place for the termination character.
                    tis = tic + *NUMBER_1_INTEGER_MEMORY_MODEL;

                    // Reallocate icon name as multibyte character array.
                    reallocate_array((void*) &ti, (void*) &tic, (void*) &tis, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);
                }

                // Add null termination character to title.
                set_array_elements(tt, (void*) NULL_CONTROL_ASCII_CHARACTER_CODE_MODEL, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) &ttc, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);
                // Add null termination character to icon name.
                set_array_elements(ti, (void*) NULL_CONTROL_ASCII_CHARACTER_CODE_MODEL, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) &tic, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                // Set terminated window title.
                //
                // CAUTION! If the string "tt" is not in the host portable
                // character encoding, the result is implementation-dependent.
                XStoreName(*di, **w, (char*) tt);
                // Set terminated window icon.
                XSetIconName(*di, **w, (char*) ti);

                // Destroy terminated title.
                deallocate_array((void*) &tt, (void*) &tts, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);
                // Destroy terminated icon name.
                deallocate_array((void*) &ti, (void*) &tis, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);
            }

            // Reset comparison result.
            r = *NUMBER_0_INTEGER_MEMORY_MODEL;

            compare_equal_arrays((void*) &r, *a, *ac, (void*) COMPOUND_MEMORY_ABSTRACTION, (void*) COMPOUND_MEMORY_ABSTRACTION_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

            if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                // The part model is a compound.
                log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"The part model is a compound.");

                // Recursively call this procedure for compound part model.
                encode_x_window_system(p0, p1, p2, *m, *mc, *d, *dc, p7, p8);
            }

            // Reset source part name, abstraction, model, details.
            n = NULL_POINTER_MEMORY_MODEL;
            nc = NULL_POINTER_MEMORY_MODEL;
            ns = NULL_POINTER_MEMORY_MODEL;
            a = NULL_POINTER_MEMORY_MODEL;
            ac = NULL_POINTER_MEMORY_MODEL;
            as = NULL_POINTER_MEMORY_MODEL;
            m = NULL_POINTER_MEMORY_MODEL;
            mc = NULL_POINTER_MEMORY_MODEL;
            ms = NULL_POINTER_MEMORY_MODEL;
            d = NULL_POINTER_MEMORY_MODEL;
            dc = NULL_POINTER_MEMORY_MODEL;
            ds = NULL_POINTER_MEMORY_MODEL;
            // Reset source part layout.
            la = NULL_POINTER_MEMORY_MODEL;
            lac = NULL_POINTER_MEMORY_MODEL;
            las = NULL_POINTER_MEMORY_MODEL;
            lm = NULL_POINTER_MEMORY_MODEL;
            lmc = NULL_POINTER_MEMORY_MODEL;
            lms = NULL_POINTER_MEMORY_MODEL;
            ld = NULL_POINTER_MEMORY_MODEL;
            ldc = NULL_POINTER_MEMORY_MODEL;
            lds = NULL_POINTER_MEMORY_MODEL;
            // Reset source part cell.
            ca = NULL_POINTER_MEMORY_MODEL;
            cac = NULL_POINTER_MEMORY_MODEL;
            cas = NULL_POINTER_MEMORY_MODEL;
            cm = NULL_POINTER_MEMORY_MODEL;
            cmc = NULL_POINTER_MEMORY_MODEL;
            cms = NULL_POINTER_MEMORY_MODEL;
            cd = NULL_POINTER_MEMORY_MODEL;
            cdc = NULL_POINTER_MEMORY_MODEL;
            cds = NULL_POINTER_MEMORY_MODEL;
            // Reset source part position.
            pa = NULL_POINTER_MEMORY_MODEL;
            pac = NULL_POINTER_MEMORY_MODEL;
            pas = NULL_POINTER_MEMORY_MODEL;
            pm = NULL_POINTER_MEMORY_MODEL;
            pmc = NULL_POINTER_MEMORY_MODEL;
            pms = NULL_POINTER_MEMORY_MODEL;
            pd = NULL_POINTER_MEMORY_MODEL;
            pdc = NULL_POINTER_MEMORY_MODEL;
            pds = NULL_POINTER_MEMORY_MODEL;
            // Reset source part size.
            sa = NULL_POINTER_MEMORY_MODEL;
            sac = NULL_POINTER_MEMORY_MODEL;
            sas = NULL_POINTER_MEMORY_MODEL;
            sm = NULL_POINTER_MEMORY_MODEL;
            smc = NULL_POINTER_MEMORY_MODEL;
            sms = NULL_POINTER_MEMORY_MODEL;
            sd = NULL_POINTER_MEMORY_MODEL;
            sdc = NULL_POINTER_MEMORY_MODEL;
            sds = NULL_POINTER_MEMORY_MODEL;
            // The source part title and icon are not reset,
            // since only one window may be the root of all graphical parts
            // and further windows must not occur as part.

            // Reset source part position coordinates.
            pmx = (int*) *NULL_POINTER_MEMORY_MODEL;
            pmy = (int*) *NULL_POINTER_MEMORY_MODEL;
            pmz = (int*) *NULL_POINTER_MEMORY_MODEL;
            // Reset source part size coordinates.
            smx = (int*) *NULL_POINTER_MEMORY_MODEL;
            smy = (int*) *NULL_POINTER_MEMORY_MODEL;
            smz = (int*) *NULL_POINTER_MEMORY_MODEL;

            // Reset terminated title.
            tt = *NULL_POINTER_MEMORY_MODEL;
            tts = *NUMBER_MINUS_1_INTEGER_MEMORY_MODEL;
            // Reset terminated icon name.
            ti = *NULL_POINTER_MEMORY_MODEL;
            tis = *NUMBER_MINUS_1_INTEGER_MEMORY_MODEL;

            // Reset comparison result.
            r = *NUMBER_0_INTEGER_MEMORY_MODEL;

            // Increment loop count.
            j++;
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not encode x window system. The source count is null.");
    }
}

/* X_WINDOW_SYSTEM_ENCODER_SOURCE */
#endif
