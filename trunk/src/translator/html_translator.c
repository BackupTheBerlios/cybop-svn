/*
 * $RCSfile: html_translator.c,v $
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
 * @version $Revision: 1.6 $ $Date: 2005-03-30 14:15:42 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef HTML_TRANSLATOR_SOURCE
#define HTML_TRANSLATOR_SOURCE

#include "../accessor/compound_accessor.c"
#include "../array/array.c"
#include "../global/name_constants.c"
#include "../logger/logger.c"

//
// Forward declarations.
//
void encode_html( void** dest, int* dest_count, int *dest_size,
                  const void* source_abstr, const int* source_abstr_count,
                  const void* source_model, const int* source_model_count,
                  const void* source_detail, const int* source_detail_count,
                  const void* know, const int* know_count );



/**
 * encodes the cybol model compound into a html string
 *
 * @param dest the destination (Hand over as reference!)
 * @param dest_count the destination count
 * @param dest_size the destination size
 * @param source_model the source model
 * @param source_model_count the source model count
 * @param source_detail the source detail
 * @param source_detail_count the source detail count
 * @param know the knowledge memeory
 * @param know_count the knowledge memeory count
 */
void encode_html_compound( void** dest, int* dest_count, int* dest_size,
                           const void* source_model, const int* source_model_count,
                           const void* source_detail, const int* source_detail_count,
                           const void* know, const int* know_count )
{

    // The compound abstraction.
    void** comp_abstr = POINTER_NULL_POINTER;
    void** comp_abstr_count = POINTER_NULL_POINTER;
    void** comp_abstr_size = POINTER_NULL_POINTER;
    // The compound model.
    void** comp_model = POINTER_NULL_POINTER;
    void** comp_model_count = POINTER_NULL_POINTER;
    void** comp_model_size = POINTER_NULL_POINTER;
    // The compound details.
    void** comp_detail = POINTER_NULL_POINTER;
    void** comp_detail_count = POINTER_NULL_POINTER;
    void** comp_detail_size = POINTER_NULL_POINTER;


    int comp_index = 0;

    while (1) {

        if (comp_index >= *source_model_count) {
            break;
        }

        get_compound_element_by_index(
            source_model, source_model_count, (void*) &comp_index,
            &comp_abstr, &comp_abstr_count, &comp_abstr_size,
            &comp_model, &comp_model_count, &comp_model_size,
            &comp_detail, &comp_detail_count, &comp_detail_size );

        encode_html( dest, dest_count, dest_size,
                     *comp_abstr, *comp_abstr_count,
                     *comp_model, *comp_model_count,
                     *comp_detail, *comp_detail_count,
                     know, know_count );

        comp_index++;
    }
}


/**
 * encodes the cybol model compound into a html string
 *
 * @param dest the destination (Hand over as reference!)
 * @param dest_count the destination count
 * @param dest_size the destination size
 * @param source_model the source model
 * @param source_model_count the source model count
 * @param source_detail the source detail
 * @param source_detail_count the source detail count
 * @param know the knowledge memeory
 * @param know_count the knowledge memeory count
 */
void encode_html_knowledgememory(
    void** dest, int* dest_count, int* dest_size,
    const void* source_model, const int* source_model_count,
    const void* source_detail, const int* source_detail_count,
    const void* know, const int* know_count )
{

    if ( (source_model!=NULL_POINTER) &&
         (source_model_count!=NULL_POINTER) )
    {

        // The compound abstraction.
        void** comp_abstr = POINTER_NULL_POINTER;
        void** comp_abstr_count = POINTER_NULL_POINTER;
        void** comp_abstr_size = POINTER_NULL_POINTER;
        // The compound model.
        void** comp_model = POINTER_NULL_POINTER;
        void** comp_model_count = POINTER_NULL_POINTER;
        void** comp_model_size = POINTER_NULL_POINTER;
        // The compound details.
        void** comp_detail = POINTER_NULL_POINTER;
        void** comp_detail_count = POINTER_NULL_POINTER;
        void** comp_detail_size = POINTER_NULL_POINTER;

        get_compound_element_by_name(
            know, know_count,
            source_model, source_model_count,
            &comp_abstr, &comp_abstr_count, &comp_abstr_size,
            &comp_model, &comp_model_count, &comp_model_size,
            &comp_detail, &comp_detail_count, &comp_detail_size );

        encode_html( dest, dest_count, dest_size,
                     *comp_abstr, *comp_abstr_count,
                     *comp_model, *comp_model_count,
                     *comp_detail, *comp_detail_count,
                     know, know_count );
    }
}


/**
 * encodes the cybol model string into a html string
 * in the source details look for the name html_tag
 * if the html_tag found
 * then ist the result for encode <html_tag>model</html_tag>
 * else only the model
 *
 * @param dest the destination (Hand over as reference!)
 * @param dest_count the destination count
 * @param dest_size the destination size
 * @param source_model the source model
 * @param source_model_count the source model count
 * @param source_detail the source detail
 * @param source_detail_count the source detail count
 */
void encode_html_string( void** dest, int* dest_count, int* dest_size,
                         const void* source_model, const int* source_model_count,
                         const void* source_detail, const int* source_detail_count)
{

    if ( (dest != NULL_POINTER ) &&
         (dest_count != NULL_POINTER ) &&
         (dest_size != NULL_POINTER ) )
    {

        //parse the model
        parse( dest, dest_count, dest_size,
               source_model, source_model_count,
               STRING_ABSTRACTION, STRING_ABSTRACTION_COUNT);
    }
}

/**
 * Encodes a model into a html string.
 *
 * destination ist ein String. In dem Steht der Vollst?ndige
 * html-Text, der aus dem model generiert werden kann, enthalten
 * in den properties von dem model steht der html_tag drinne.
 * Ist das model ein compound, so muss  dieses compound hierarchisch
 * aufgel??t werden.
 *
 * @param p0 the destination (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source model
 * @param p4 the source model count
 * @param p3 the source abstraction
 * @param p4 the source abstarction count
 */
void encode_html( void** dest, int* dest_count, int *dest_size,
                  const void* source_abstr, const int* source_abstr_count,
                  const void* source_model, const int* source_model_count,
                  const void* source_detail, const int* source_detail_count,
                  const void* know, const int* know_count )
{

    //check for destination
    if ( (dest != NULL_POINTER ) &&
         (dest_count != NULL_POINTER ) &&
         (dest_size != NULL_POINTER ) )
    {


        // The html tag abstraction.
        void** tag_abstr = POINTER_NULL_POINTER;
        void** tag_abstr_count = POINTER_NULL_POINTER;
        void** tag_abstr_size = POINTER_NULL_POINTER;
        // The html tag model.
        void** tag_model = POINTER_NULL_POINTER;
        void** tag_model_count = POINTER_NULL_POINTER;
        void** tag_model_size = POINTER_NULL_POINTER;
        // The html tag details.
        void** tag_detail = POINTER_NULL_POINTER;
        void** tag_detail_count = POINTER_NULL_POINTER;
        void** tag_detail_size = POINTER_NULL_POINTER;

        // The html tag abstraction.
        void** tag_prop_abstr = POINTER_NULL_POINTER;
        void** tag_prop_abstr_count = POINTER_NULL_POINTER;
        void** tag_prop_abstr_size = POINTER_NULL_POINTER;
        // The html tag_prop model.
        void** tag_prop_model = POINTER_NULL_POINTER;
        void** tag_prop_model_count = POINTER_NULL_POINTER;
        void** tag_prop_model_size = POINTER_NULL_POINTER;
        // The html tag_prop details.
        void** tag_prop_detail = POINTER_NULL_POINTER;
        void** tag_prop_detail_count = POINTER_NULL_POINTER;
        void** tag_prop_detail_size = POINTER_NULL_POINTER;

        //in the source detail look for html_tag
        if ( (source_detail != NULL_POINTER) &&
             (source_detail_count != NULL_POINTER) ) {

            get_compound_element_by_name(
                source_detail, source_detail_count,
                HTML_TAG_NAME_ABSTRACTION, HTML_TAG_NAME_ABSTRACTION_COUNT,
                &tag_abstr, &tag_abstr_count, &tag_abstr_size,
                &tag_model, &tag_model_count, &tag_model_size,
                &tag_detail, &tag_detail_count, &tag_detail_size
            );

            get_compound_element_by_name(
                source_detail, source_detail_count,
                HTML_TAG_PROPERTIES_NAME_ABSTRACTION,
                HTML_TAG_PROPERTIES_NAME_ABSTRACTION_COUNT,
                &tag_prop_abstr, &tag_prop_abstr_count, &tag_prop_abstr_size,
                &tag_prop_model, &tag_prop_model_count, &tag_prop_model_size,
                &tag_prop_detail, &tag_prop_detail_count, &tag_prop_detail_size
            );

        }

        //parse the begin tag
        if ( (tag_model != POINTER_NULL_POINTER) &&
             (tag_model_count != POINTER_NULL_POINTER) &&
             (tag_model_size != POINTER_NULL_POINTER)
           )
        {

            if ( (*tag_model!=NULL_POINTER) &&
                 (*tag_model_count!=NULL_POINTER) &&
                 (*tag_model_size!=NULL_POINTER)
               )
            {
                //parse the <
                parse( dest, dest_count, dest_size,
                       LESS_THAN_SIGN_CHARACTER, LESS_THAN_SIGN_CHARACTER_COUNT,
                       STRING_ABSTRACTION, STRING_ABSTRACTION_COUNT);

                //parse the html tag
                parse( dest, dest_count, dest_size,
                       *tag_model, *tag_model_count,
                       STRING_ABSTRACTION, STRING_ABSTRACTION_COUNT);

                //parse the tag properties
                if ( (tag_prop_model != POINTER_NULL_POINTER) &&
                     (tag_prop_model_count != POINTER_NULL_POINTER) &&
                     (tag_prop_model_size != POINTER_NULL_POINTER)
                   )
                {

                    //parse the space
                    parse( dest, dest_count, dest_size,
                           SPACE_CHARACTER, SPACE_CHARACTER_COUNT,
                           STRING_ABSTRACTION, STRING_ABSTRACTION_COUNT);

                    //parse the html tag properties
                    parse( dest, dest_count, dest_size,
                           *tag_prop_model, *tag_prop_model_count,
                           STRING_ABSTRACTION, STRING_ABSTRACTION_COUNT);
                }


                //parse the >
                parse( dest, dest_count, dest_size,
                       GREATER_THAN_SIGN_CHARACTER, GREATER_THAN_SIGN_CHARACTER_COUNT,
                       STRING_ABSTRACTION, STRING_ABSTRACTION_COUNT);

                //parse the line feed for better reading the html-source
                parse( dest, dest_count, dest_size,
                       LINE_FEED_CONTROL_CHARACTER, LINE_FEED_CONTROL_CHARACTER_COUNT,
                       STRING_ABSTRACTION, STRING_ABSTRACTION_COUNT);
            }
        }

        //encode the model
        int r = 0;

        if (r != 1) {

            compare_arrays( source_abstr, source_abstr_count,
                            (void*) COMPOUND_ABSTRACTION,
                            (void*) COMPOUND_ABSTRACTION_COUNT,
                            (void*) &r, (void*) CHARACTER_ARRAY);
            if (r == 1) {

                encode_html_compound( dest, dest_count, dest_size,
                                      source_model, source_model_count,
                                      source_detail, source_detail_count,
                                      know, know_count);
            }
        }

        if (r != 1) {

            compare_arrays(source_abstr, source_abstr_count, (void*) KNOWLEDGE_ABSTRACTION, (void*) KNOWLEDGE_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

            if (r == 1) {

                encode_html_knowledgememory(dest, dest_count, dest_size,
                    source_model, source_model_count,
                    source_detail, source_detail_count,
                    know, know_count);
            }
        }

        if (r != 1) {

            compare_arrays(source_abstr, source_abstr_count, (void*) CYBOL_ABSTRACTION, (void*) CYBOL_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

            if (r == 1) {

                encode_html_compound(dest, dest_count, dest_size,
                                     source_model, source_model_count,
                                     source_detail, source_detail_count,
                                     know, know_count);
            }
        }

        if (r != 1) {

            compare_arrays( source_abstr, source_abstr_count,
                            (void*) STRING_ABSTRACTION,
                            (void*) STRING_ABSTRACTION_COUNT,
                            (void*) &r, (void*) CHARACTER_ARRAY);
            if (r == 1) {

                encode_html_string( dest, dest_count, dest_size,
                                    source_model, source_model_count,
                                    source_detail, source_detail_count );
            }
        }

        //parse the line feed for better reading the html-source
        parse( dest, dest_count, dest_size,
               LINE_FEED_CONTROL_CHARACTER, LINE_FEED_CONTROL_CHARACTER_COUNT,
               STRING_ABSTRACTION, STRING_ABSTRACTION_COUNT);

        //parse the end tag
        if ( (tag_model != POINTER_NULL_POINTER) &&
             (tag_model_count != POINTER_NULL_POINTER) &&
             (tag_model_size != POINTER_NULL_POINTER)
           )
        {

            if ( (*tag_model!=NULL_POINTER) &&
                 (*tag_model_count!=NULL_POINTER) &&
                 (*tag_model_size!=NULL_POINTER)
               )
            {
                //parse the <
                parse( dest, dest_count, dest_size,
                       LESS_THAN_SIGN_CHARACTER, LESS_THAN_SIGN_CHARACTER_COUNT,
                       STRING_ABSTRACTION, STRING_ABSTRACTION_COUNT);

                //parse the /
                parse( dest, dest_count, dest_size,
                       SOLIDUS_CHARACTER, SOLIDUS_CHARACTER_COUNT,
                       STRING_ABSTRACTION, STRING_ABSTRACTION_COUNT);

                //parse the html tag
                parse( dest, dest_count, dest_size,
                       *tag_model, *tag_model_count,
                       STRING_ABSTRACTION, STRING_ABSTRACTION_COUNT);

                //parse the >
                parse( dest, dest_count, dest_size,
                       GREATER_THAN_SIGN_CHARACTER, GREATER_THAN_SIGN_CHARACTER_COUNT,
                       STRING_ABSTRACTION, STRING_ABSTRACTION_COUNT);

                //parse the line feed for better reading the html-source
                parse( dest, dest_count, dest_size,
                       LINE_FEED_CONTROL_CHARACTER, LINE_FEED_CONTROL_CHARACTER_COUNT,
                       STRING_ABSTRACTION, STRING_ABSTRACTION_COUNT);

            }
        }
    }  //check for destination
}

/* HTML_TRANSLATOR_SOURCE */
#endif
