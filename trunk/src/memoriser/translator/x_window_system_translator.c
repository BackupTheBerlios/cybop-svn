/*
 * $RCSfile: x_window_system_translator.c,v $
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
 * @version $Revision: 1.11 $ $Date: 2006-01-02 11:56:02 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef X_WINDOW_SYSTEM_TRANSLATOR_SOURCE
#define X_WINDOW_SYSTEM_TRANSLATOR_SOURCE

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include "../../globals/constants/abstraction_constants.c"
#include "../../globals/constants/model_constants.c"
#include "../../globals/constants/name_constants.c"
#include "../../globals/constants/structure_constants.c"
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
 * Encodes the source compound model layout into x window system coordinates.
 *
 * @param p0 the cell position x (of the part)
 * @param p1 the cell position y
 * @param p2 the cell position z
 * @param p3 the cell size x (of the part)
 * @param p4 the cell size y
 * @param p5 the cell size z
 * @param p6 the free area position x (remaining space within the whole)
 * @param p7 the free area position y
 * @param p8 the free area position z
 * @param p9 the free area size x (remaining space within the whole)
 * @param p10 the free area size y
 * @param p11 the free area size z
 * @param p12 the layout cell
 * @param p13 the layout cell count
 */
void encode_x_window_system_compass_layout(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5,
    void* p6, void* p7, void* p8, void* p9, void* p10, void* p11,
    void* p12, void* p13) {

    int* cpx = (int*) p0;
    int* cpy = (int*) p1;
    int* cpz = (int*) p2;
    int* csx = (int*) p3;
    int* csy = (int*) p4;
    int* csz = (int*) p5;
    int* fapx = (int*) p6;
    int* fapy = (int*) p7;
    int* fapz = (int*) p8;
    int* fasx = (int*) p9;
    int* fasy = (int*) p10;
    int* fasz = (int*) p11;

    // The comparison result.
    int r = 0;

    if (r == 0) {

        compare_arrays(p12, p13, (void*) NORTH_CELL_MODEL, (void*) NORTH_CELL_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            // Set cell coordinates.
            *cpx = *fapx;
            *cpy = *fapy;
            *cpz = *fapz;
            *csx = *fasx;
            *csy = 20;
            *csz = *fasz;
            // Set free area coordinates.
            *fapy = *fapy + *csy;
            *fasy = *fasy - *csy;
        }
    }

    if (r == 0) {

        compare_arrays(p12, p13, (void*) SOUTH_CELL_MODEL, (void*) SOUTH_CELL_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            // Set cell coordinates.
            *cpx = *fapx;
            *cpy = (*fasy - 20);
            *cpz = *fapz;
            *csx = *fasx;
            *csy = 20;
            *csz = *fasz;
            // Set free area coordinates.
            *fasy = *fasy - *csy;
        }
    }

    if (r == 0) {

        compare_arrays(p12, p13, (void*) WEST_CELL_MODEL, (void*) WEST_CELL_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            // Set cell coordinates.
            *cpx = *fapx;
            *cpy = *fapy;
            *cpz = *fapz;
            *csx = 20;
            *csy = *fasy;
            *csz = *fasz;
            // Set free area coordinates.
            *fapx = *fapx + *csx;
            *fasx = *fasx - *csx;
        }
    }

    if (r == 0) {

        compare_arrays(p12, p13, (void*) EAST_CELL_MODEL, (void*) EAST_CELL_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            // Set cell coordinates.
            *cpx = (*fasx - 20);
            *cpy = *fapy;
            *cpz = *fapz;
            *csx = 20;
            *csy = *fasy;
            *csz = *fasz;
            // Set free area coordinates.
            *fasx = *fasx - *csx;
        }
    }

    if (r == 0) {

        compare_arrays(p12, p13, (void*) CENTRE_CELL_MODEL, (void*) CENTRE_CELL_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            // Set cell coordinates.
            *cpx = *fapx;
            *cpy = *fapy;
            *cpz = *fapz;
            *csx = *fasx;
            *csy = *fasy;
            *csz = *fasz;
            // Set free area coordinates.
            *fasx = *fasx - *fasx;
            *fasy = *fasy - *fasy;
            *fasz = *fasz - *fasz;
        }
    }
}

/**
 * Encodes the source compound model layout into x window system coordinates.
 *
 * @param p0 the cell position x (of the part)
 * @param p1 the cell position y
 * @param p2 the cell position z
 * @param p3 the cell size x (of the part)
 * @param p4 the cell size y
 * @param p5 the cell size z
 * @param p6 the free area position x (remaining space within the whole)
 * @param p7 the free area position y
 * @param p8 the free area position z
 * @param p9 the free area size x (remaining space within the whole)
 * @param p10 the free area size y
 * @param p11 the free area size z
 * @param p12 the original area position x (of the whole)
 * @param p13 the original area position y
 * @param p14 the original area position z
 * @param p15 the original area size x (of the whole)
 * @param p16 the original area size y
 * @param p17 the original area size z
 * @param p18 the layout cell
 * @param p19 the layout cell count
 * @param p20 the layout
 * @param p21 the layout count
 */
void encode_x_window_system_layout(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5,
    void* p6, void* p7, void* p8, void* p9, void* p10, void* p11,
    void* p12, void* p13, void* p14, void* p15, void* p16, void* p17,
    void* p18, void* p19, void* p20, void* p21) {

    // The comparison result.
    int r = 0;

    if (r == 0) {

        compare_arrays(p20, p21, (void*) COORDINATES_LAYOUT_MODEL, (void*) COORDINATES_LAYOUT_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            // The position and size coordinates of the part are given directly
            // in the CYBOL knowledge template. So nothing is to be done here.
            // Nevertheless, this comparison is done in order to set the
            // comparison flag to true, thus to avoid further comparisons below.
        }
    }

    if (r == 0) {

        compare_arrays(p20, p21, (void*) COMPASS_LAYOUT_MODEL, (void*) COMPASS_LAYOUT_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            // Determine new position and size coordinates for part.
            encode_x_window_system_compass_layout(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p18, p19);
        }
    }
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
 */
void encode_x_window_system(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    if (p4 != NULL_POINTER) {

        int* sc = (int*) p4;

        log_message_debug("Encode compound into x window system model.");

        // The display, which is a subsumption of
        // xserver, screens, hardware (input devices etc.).
        struct _XDisplay** di = (struct _XDisplay**) &NULL_POINTER;
        // The window.
        int** w = NULL_POINTER;
        // The graphic context.
        struct _XGC** gc = (struct _XGC**) &NULL_POINTER;
        // The window attributes.
        XWindowAttributes wa;

        // Get x window system internals.
        get(p0, (void*) X_WINDOW_SYSTEM_DISPLAY_INTERNAL, (void*) &di, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        get(p0, (void*) X_WINDOW_SYSTEM_WINDOW_INTERNAL, (void*) &w, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        get(p0, (void*) X_WINDOW_SYSTEM_GRAPHIC_CONTEXT_INTERNAL, (void*) &gc, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

        // Get window attributes.
        XGetWindowAttributes(*di, **w, &wa);

        // The source whole size.
        void** wsa = &NULL_POINTER;
        void** wsac = &NULL_POINTER;
        void** wsas = &NULL_POINTER;
        void** wsm = &NULL_POINTER;
        void** wsmc = &NULL_POINTER;
        void** wsms = &NULL_POINTER;
        void** wsd = &NULL_POINTER;
        void** wsdc = &NULL_POINTER;
        void** wsds = &NULL_POINTER;

        // The source whole size coordinates.
        int** wsmx = (int**) &NULL_POINTER;
        int** wsmy = (int**) &NULL_POINTER;
        int** wsmz = (int**) &NULL_POINTER;

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

        if (p5 != NULL_POINTER) {

            // Get source whole size from details.
            get_compound_element_by_name(p5, p6,
                (void*) GUI_SIZE_NAME, (void*) GUI_SIZE_NAME_COUNT,
                (void*) &wsa, (void*) &wsac, (void*) &wsas,
                (void*) &wsm, (void*) &wsmc, (void*) &wsms,
                (void*) &wsd, (void*) &wsdc, (void*) &wsds);

            // Determine source whole size coordinates.
            get(*wsm, (void*) NUMBER_0_INTEGER, (void*) &wsmx, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
            get(*wsm, (void*) NUMBER_1_INTEGER, (void*) &wsmy, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
            get(*wsm, (void*) NUMBER_2_INTEGER, (void*) &wsmz, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

            // Set original area position coordinates, set to the zero origo.
            oapx = *NUMBER_0_INTEGER;
            oapy = *NUMBER_0_INTEGER;
            oapz = *NUMBER_0_INTEGER;
            // Set original area size coordinates, initialised with whole coordinates.
            oasx = **wsmx;
            oasy = **wsmy;
            oasz = **wsmz;

            // Set free area position coordinates, initialised with original area position coordinates.
            fapx = oapx;
            fapy = oapy;
            fapz = oapz;
            // Set free area size coordinates, initialised with original area position coordinates.
            fasx = oasx;
            fasy = oasy;
            fasz = oasz;
        }

        // The source part abstraction, model, details.
        void** a = &NULL_POINTER;
        void** ac = &NULL_POINTER;
        void** as = &NULL_POINTER;
        void** m = &NULL_POINTER;
        void** mc = &NULL_POINTER;
        void** ms = &NULL_POINTER;
        void** d = &NULL_POINTER;
        void** dc = &NULL_POINTER;
        void** ds = &NULL_POINTER;

        // The source part layout.
        void** la = &NULL_POINTER;
        void** lac = &NULL_POINTER;
        void** las = &NULL_POINTER;
        void** lm = &NULL_POINTER;
        void** lmc = &NULL_POINTER;
        void** lms = &NULL_POINTER;
        void** ld = &NULL_POINTER;
        void** ldc = &NULL_POINTER;
        void** lds = &NULL_POINTER;
        // The source part cell.
        void** ca = &NULL_POINTER;
        void** cac = &NULL_POINTER;
        void** cas = &NULL_POINTER;
        void** cm = &NULL_POINTER;
        void** cmc = &NULL_POINTER;
        void** cms = &NULL_POINTER;
        void** cd = &NULL_POINTER;
        void** cdc = &NULL_POINTER;
        void** cds = &NULL_POINTER;
        // The source part position.
        void** pa = &NULL_POINTER;
        void** pac = &NULL_POINTER;
        void** pas = &NULL_POINTER;
        void** pm = &NULL_POINTER;
        void** pmc = &NULL_POINTER;
        void** pms = &NULL_POINTER;
        void** pd = &NULL_POINTER;
        void** pdc = &NULL_POINTER;
        void** pds = &NULL_POINTER;
        // The source part size.
        void** sa = &NULL_POINTER;
        void** sac = &NULL_POINTER;
        void** sas = &NULL_POINTER;
        void** sm = &NULL_POINTER;
        void** smc = &NULL_POINTER;
        void** sms = &NULL_POINTER;
        void** sd = &NULL_POINTER;
        void** sdc = &NULL_POINTER;
        void** sds = &NULL_POINTER;
        // The source part title.
        void** ta = &NULL_POINTER;
        void** tac = &NULL_POINTER;
        void** tas = &NULL_POINTER;
        void** tm = &NULL_POINTER;
        void** tmc = &NULL_POINTER;
        void** tms = &NULL_POINTER;
        void** td = &NULL_POINTER;
        void** tdc = &NULL_POINTER;
        void** tds = &NULL_POINTER;
        // The source part icon.
        void** ia = &NULL_POINTER;
        void** iac = &NULL_POINTER;
        void** ias = &NULL_POINTER;
        void** im = &NULL_POINTER;
        void** imc = &NULL_POINTER;
        void** ims = &NULL_POINTER;
        void** id = &NULL_POINTER;
        void** idc = &NULL_POINTER;
        void** ids = &NULL_POINTER;

        // The terminated title.
        void* tt = NULL_POINTER;
        int tts = -1;
        // The terminated icon name.
        void* ti = NULL_POINTER;
        int tis = -1;

        // The source part position coordinates.
        int** pmx = (int**) &NULL_POINTER;
        int** pmy = (int**) &NULL_POINTER;
        int** pmz = (int**) &NULL_POINTER;
        // The source part size coordinates.
        int** smx = (int**) &NULL_POINTER;
        int** smy = (int**) &NULL_POINTER;
        int** smz = (int**) &NULL_POINTER;

        // The loop count.
        int j = 0;
        // The comparison result.
        int r = 0;

        // Iterate through compound parts.
        while (1) {

            if (j >= *sc) {

                break;
            }

            // Get source part at index j.
            get_compound_element_by_index(p3, p4, (void*) &j,
                (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms,
                (void*) &d, (void*) &dc, (void*) &ds);

            // Get source part layout from details.
            get_compound_element_by_name(*d, *dc,
                (void*) GUI_LAYOUT_NAME, (void*) GUI_LAYOUT_NAME_COUNT,
                (void*) &la, (void*) &lac, (void*) &las,
                (void*) &lm, (void*) &lmc, (void*) &lms,
                (void*) &ld, (void*) &ldc, (void*) &lds);
            // Get source part cell from details.
            get_compound_element_by_name(*d, *dc,
                (void*) GUI_CELL_NAME, (void*) GUI_CELL_NAME_COUNT,
                (void*) &ca, (void*) &cac, (void*) &cas,
                (void*) &cm, (void*) &cmc, (void*) &cms,
                (void*) &cd, (void*) &cdc, (void*) &cds);
            // Get source part position from details.
            get_compound_element_by_name(*d, *dc,
                (void*) GUI_POSITION_NAME, (void*) GUI_POSITION_NAME_COUNT,
                (void*) &pa, (void*) &pac, (void*) &pas,
                (void*) &pm, (void*) &pmc, (void*) &pms,
                (void*) &pd, (void*) &pdc, (void*) &pds);
            // Get source part size from details.
            get_compound_element_by_name(*d, *dc,
                (void*) GUI_SIZE_NAME, (void*) GUI_SIZE_NAME_COUNT,
                (void*) &sa, (void*) &sac, (void*) &sas,
                (void*) &sm, (void*) &smc, (void*) &sms,
                (void*) &sd, (void*) &sdc, (void*) &sds);

            // Determine source part position coordinates.
            get(*pm, (void*) NUMBER_0_INTEGER, (void*) &pmx, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
            get(*pm, (void*) NUMBER_1_INTEGER, (void*) &pmy, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
            get(*pm, (void*) NUMBER_2_INTEGER, (void*) &pmz, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
            // Determine source part size coordinates.
            get(*sm, (void*) NUMBER_0_INTEGER, (void*) &smx, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
            get(*sm, (void*) NUMBER_1_INTEGER, (void*) &smy, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
            get(*sm, (void*) NUMBER_2_INTEGER, (void*) &smz, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

            compare_arrays(*lm, *lmc, (void*) ROOT_LAYOUT_MODEL, (void*) ROOT_LAYOUT_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

            if (r == 0) {

                // The source part is no root window.

                // Calculate coordinates according to given layout.
                encode_x_window_system_layout(
                    *pmx, *pmy, *pmz, *smx, *smy, *smz,
                    &fapx, &fapy, &fapz, &fasx, &fasy, &fasz,
                    &oapx, &oapy, &oapz, &oasx, &oasy, &oasz,
                    *cm, *cmc, *lm, *lmc);

                // Draw graphical element using given coordinates.
                XDrawRectangle(*di, **w, *gc, **pmx, **pmy, **smx - 1, **smy - 1);

                // Reset comparison result.
                r = 0;

                compare_arrays(*a, *ac, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                if (r != 0) {

                    // The terminated text.
                    char* text = NULL_POINTER;
                    int texts = *((int*) *mc) + 1;

                    // Create terminated text.
                    allocate_array((void*) &text, (void*) &texts, (void*) CHARACTER_ARRAY);

                    // Set terminated text by first copying the actual name
                    // and then adding the null termination character.
                    set_array_elements(text, (void*) NUMBER_0_INTEGER, *m, *mc, (void*) CHARACTER_ARRAY);
                    set_array_elements(text, *mc, (void*) NULL_CONTROL_CHARACTER, (void*) CHARACTER_COUNT, (void*) CHARACTER_ARRAY);

                    // Draw the text (character vector / string).
                    XDrawString(*di, **w, *gc, **pmx, **pmy + 20, text, texts);

                    // Destroy terminated text.
                    deallocate_array((void*) &text, (void*) &texts, (void*) CHARACTER_ARRAY);

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

                // Move window to new position coordinates for part.
                XMoveWindow(*di, **w, **pmx, **pmy);
                // Resize window to new size coordinates for part.
                XResizeWindow(*di, **w, **smx, **smy);

                // Get source part title from details.
                get_compound_element_by_name(*d, *dc,
                    (void*) GUI_TITLE_NAME, (void*) GUI_TITLE_NAME_COUNT,
                    (void*) &ta, (void*) &tac, (void*) &tas,
                    (void*) &tm, (void*) &tmc, (void*) &tms,
                    (void*) &td, (void*) &tdc, (void*) &tds);
                // Get source part icon from details.
                get_compound_element_by_name(*d, *dc,
                    (void*) GUI_ICON_NAME, (void*) GUI_ICON_NAME_COUNT,
                    (void*) &ia, (void*) &iac, (void*) &ias,
                    (void*) &im, (void*) &imc, (void*) &ims,
                    (void*) &id, (void*) &idc, (void*) &ids);

                // The terminated title.
                tt = NULL_POINTER;
                tts = *((int*) *tmc) + 1;
                // The terminated icon name.
                ti = NULL_POINTER;
                tis = *((int*) *imc) + 1;

                // Create terminated title.
                allocate_array((void*) &tt, (void*) &tts, (void*) CHARACTER_ARRAY);
                // Create terminated icon name.
                allocate_array((void*) &ti, (void*) &tis, (void*) CHARACTER_ARRAY);

                // Set terminated title by first copying the actual name
                // and then adding the null termination character.
                set_array_elements(tt, (void*) NUMBER_0_INTEGER, *tm, *tmc, (void*) CHARACTER_ARRAY);
                set_array_elements(tt, *tmc, (void*) NULL_CONTROL_CHARACTER, (void*) CHARACTER_COUNT, (void*) CHARACTER_ARRAY);
                // Set terminated icon name by first copying the actual name
                // and then adding the null termination character.
                set_array_elements(ti, (void*) NUMBER_0_INTEGER, *im, *imc, (void*) CHARACTER_ARRAY);
                set_array_elements(ti, *imc, (void*) NULL_CONTROL_CHARACTER, (void*) CHARACTER_COUNT, (void*) CHARACTER_ARRAY);

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
            r = 0;

            compare_arrays(*a, *ac, (void*) CYBOL_ABSTRACTION, (void*) CYBOL_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

            if (r != 0) {

                // The part model is a compound.

                // Recursively call this procedure for compound part model.
                encode_x_window_system(p0, p1, p2, *m, (void*) *mc, *d, *dc);
            }

            // Reset source part abstraction, model, details.
            a = &NULL_POINTER;
            ac = &NULL_POINTER;
            as = &NULL_POINTER;
            m = &NULL_POINTER;
            mc = &NULL_POINTER;
            ms = &NULL_POINTER;
            d = &NULL_POINTER;
            dc = &NULL_POINTER;
            ds = &NULL_POINTER;

            // Reset source part layout.
            la = &NULL_POINTER;
            lac = &NULL_POINTER;
            las = &NULL_POINTER;
            lm = &NULL_POINTER;
            lmc = &NULL_POINTER;
            lms = &NULL_POINTER;
            ld = &NULL_POINTER;
            ldc = &NULL_POINTER;
            lds = &NULL_POINTER;
            // Reset source part cell.
            ca = &NULL_POINTER;
            cac = &NULL_POINTER;
            cas = &NULL_POINTER;
            cm = &NULL_POINTER;
            cmc = &NULL_POINTER;
            cms = &NULL_POINTER;
            cd = &NULL_POINTER;
            cdc = &NULL_POINTER;
            cds = &NULL_POINTER;
            // Reset source part position.
            pa = &NULL_POINTER;
            pac = &NULL_POINTER;
            pas = &NULL_POINTER;
            pm = &NULL_POINTER;
            pmc = &NULL_POINTER;
            pms = &NULL_POINTER;
            pd = &NULL_POINTER;
            pdc = &NULL_POINTER;
            pds = &NULL_POINTER;
            // Reset source part size.
            sa = &NULL_POINTER;
            sac = &NULL_POINTER;
            sas = &NULL_POINTER;
            sm = &NULL_POINTER;
            smc = &NULL_POINTER;
            sms = &NULL_POINTER;
            sd = &NULL_POINTER;
            sdc = &NULL_POINTER;
            sds = &NULL_POINTER;
            // The source part title and icon are not reset,
            // since only one window may be the root of all graphical parts
            // and further windows must not occur as part.

            // Reset source part position coordinates.
            pmx = (int**) &NULL_POINTER;
            pmy = (int**) &NULL_POINTER;
            pmz = (int**) &NULL_POINTER;
            // Reset source part size coordinates.
            smx = (int**) &NULL_POINTER;
            smy = (int**) &NULL_POINTER;
            smz = (int**) &NULL_POINTER;

            // Reset terminated title.
            tt = NULL_POINTER;
            tts = -1;
            // Reset terminated icon name.
            ti = NULL_POINTER;
            tis = -1;

            // Reset comparison result.
            r = 0;

            // Increment loop count.
            j++;
        }

    } else {

        log_message_debug("Could not encode x window system. The source count is null.");
    }
}

/* X_WINDOW_SYSTEM_TRANSLATOR_SOURCE */
#endif
