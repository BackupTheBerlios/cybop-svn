/*
 * $RCSfile: xml_translator.c,v $
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
 * This file contains the functionality to:
 * - encode a cyboi knowledge tree (compound) into an xml (dom) tree
 * - decode an xml (dom) tree into a cyboi knowledge tree (compound)
 *
 * @version $Revision: 1.1 $ $Date: 2004-07-28 22:46:28 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef XML_TRANSLATOR_SOURCE
#define XML_TRANSLATOR_SOURCE

#include "../array/array.c"
#include "../global/constant.c"
#include "../logger/logger.c"
#include "../state/compound.c"
#include "../state/xml_attribute.c"
#include "../state/xml_tag.c"

//
// Values.
//

/**
 * Interprets the name value.
 *
 * @param p0 the persistent value pointer
 * @param p1 the persistent value count
 */
void interpret_name_value(const void* p0, const void* p1) {
}

/**
 * Serializes the name value.
 *
 * @param p0 the persistent value pointer
 * @param p1 the persistent value count
 */
void serialize_name_value(const void* p0, const void* p1) {
}

/**
 * Interprets the abstraction value.
 *
 * @param p0 the persistent value pointer
 * @param p1 the persistent value count
 */
void interpret_abstraction_value(const void* p0, const void* p1) {
}

/**
 * Serializes the abstraction value.
 *
 * @param p0 the persistent value pointer
 * @param p1 the persistent value count
 */
void serialize_abstraction_value(const void* p0, const void* p1) {
}

/**
 * Interprets the location value.
 *
 * @param p0 the persistent value pointer
 * @param p1 the persistent value count
 */
void interpret_location_value(const void* p0, const void* p1) {
}

/**
 * Serializes the location value.
 *
 * @param p0 the persistent value pointer
 * @param p1 the persistent value count
 */
void serialize_location_value(const void* p0, const void* p1) {
}

/**
 * Interprets the model value.
 *
 * @param p0 the persistent value pointer
 * @param p1 the persistent value count
 */
void interpret_model_value(const void* p0, const void* p1) {
}

/**
 * Serializes the model value.
 *
 * @param p0 the persistent value pointer
 * @param p1 the persistent value count
 */
void serialize_model_value(const void* p0, const void* p1) {
}

/**
 * Interprets the constraint value.
 *
 * @param p0 the persistent value pointer
 * @param p1 the persistent value count
 */
void interpret_constraint_value(const void* p0, const void* p1) {
}

/**
 * Serializes the constraint value.
 *
 * @param p0 the persistent value pointer
 * @param p1 the persistent value count
 */
void serialize_constraint_value(const void* p0, const void* p1) {
}

/**
 * Interprets the position abstraction value.
 *
 * @param p0 the persistent value pointer
 * @param p1 the persistent value count
 */
void interpret_position_abstraction_value(const void* p0, const void* p1) {
}

/**
 * Serializes the position abstraction value.
 *
 * @param p0 the persistent value pointer
 * @param p1 the persistent value count
 */
void serialize_position_abstraction_value(const void* p0, const void* p1) {
}

/**
 * Interprets the position location value.
 *
 * @param p0 the persistent value pointer
 * @param p1 the persistent value count
 */
void interpret_position_location_value(const void* p0, const void* p1) {
}

/**
 * Serializes the position location value.
 *
 * @param p0 the persistent value pointer
 * @param p1 the persistent value count
 */
void serialize_position_location_value(const void* p0, const void* p1) {
}

/**
 * Interprets the position model value.
 *
 * @param p0 the persistent value pointer
 * @param p1 the persistent value count
 */
void interpret_position_model_value(const void* p0, const void* p1) {
}

/**
 * Serializes the position model value.
 *
 * @param p0 the persistent value pointer
 * @param p1 the persistent value count
 */
void serialize_position_model_value(const void* p0, const void* p1) {
}

/**
 * Interprets the position constraint value.
 *
 * @param p0 the persistent value pointer
 * @param p1 the persistent value count
 */
void interpret_position_constraint_value(const void* p0, const void* p1) {
}

/**
 * Serializes the position constraint value.
 *
 * @param p0 the persistent value pointer
 * @param p1 the persistent value count
 */
void serialize_position_constraint_value(const void* p0, const void* p1) {
}

//
// Attributes.
//

/**
 * Interprets super attributes.
 *
 * @param p0 the persistent attributes pointer
 * @param p1 the persistent attributes count
 */
void interpret_super_attributes(const void* p0, const void* p1) {

/*??
    if (p1 != NULL_POINTER) {

        int* pc = (int*) p1;

        if (p0 != NULL_POINTER) {

            void** p = (void**) p0;

            // The comparison result.
            int r = 0;
            // The current byte within the persistent model.
            void* b = *p;
            // The remaining bytes count.
            int bc = *pc;
            // The parse mode.
            int m = ZERO_PARSE_MODE;
            // The value begin pointer.
            void* v = NULL_POINTER;
            // The value count.
            int vc = 0;
            // The value begin count to be used for calculating the difference.
            int vb = 0;

            while (1) {

                if (bc <= 0) {

                    break;
                }

                //
                // Zero parse mode.
                //

                if (m == ZERO_PARSE_MODE) {

                    if (bc >= NAME_ATTRIBUTE_COUNT) {

                        compare_array_elements((void*) &b, (void*) &NAME_ATTRIBUTE, (void*) &CHARACTER_ARRAY, (void*) &NAME_ATTRIBUTE_COUNT, (void*) &r);

                        if (r == 1) {

                            // Move current byte pointer
                            // and remaining bytes count.
                            b = b + NAME_ATTRIBUTE_COUNT;
                            bc = bc - NAME_ATTRIBUTE_COUNT;

                            // Set value begin pointer and count.
                            v = b;
                            vb = bc;

                            // Set parse mode.
                            m = NAME_ATTRIBUTE_PARSE_MODE;
                        }
                    }
                }

                if (m == ZERO_PARSE_MODE) {

                    if (bc >= ABSTRACTION_ATTRIBUTE_COUNT) {

                        compare_array_elements((void*) &b, (void*) &ABSTRACTION_ATTRIBUTE, (void*) &CHARACTER_ARRAY, (void*) &ABSTRACTION_ATTRIBUTE_COUNT, (void*) &r);

                        if (r == 1) {

                            // Move current byte pointer
                            // and remaining bytes count.
                            b = b + ABSTRACTION_ATTRIBUTE_COUNT;
                            bc = bc - ABSTRACTION_ATTRIBUTE_COUNT;

                            // Set value begin pointer and count.
                            v = b;
                            vb = bc;

                            // Set parse mode.
                            m = ABSTRACTION_ATTRIBUTE_PARSE_MODE;
                        }
                    }
                }

                if (m == ZERO_PARSE_MODE) {

                    if (bc >= LOCATION_ATTRIBUTE_COUNT) {

                        compare_array_elements((void*) &b, (void*) &LOCATION_ATTRIBUTE, (void*) &CHARACTER_ARRAY, (void*) &LOCATION_ATTRIBUTE_COUNT, (void*) &r);

                        if (r == 1) {

                            // Move current byte pointer
                            // and remaining bytes count.
                            b = b + LOCATION_ATTRIBUTE_COUNT;
                            bc = bc - LOCATION_ATTRIBUTE_COUNT;

                            // Set value begin pointer and count.
                            v = b;
                            vb = bc;

                            // Set parse mode.
                            m = LOCATION_ATTRIBUTE_PARSE_MODE;
                        }
                    }
                }

                if (m == ZERO_PARSE_MODE) {

                    if (bc >= MODEL_ATTRIBUTE_COUNT) {

                        compare_array_elements((void*) &b, (void*) &MODEL_ATTRIBUTE, (void*) &CHARACTER_ARRAY, (void*) &MODEL_ATTRIBUTE_COUNT, (void*) &r);

                        if (r == 1) {

                            // Move current byte pointer
                            // and remaining bytes count.
                            b = b + MODEL_ATTRIBUTE_COUNT;
                            bc = bc - MODEL_ATTRIBUTE_COUNT;

                            // Set value begin pointer and count.
                            v = b;
                            vb = bc;

                            // Set parse mode.
                            m = MODEL_ATTRIBUTE_PARSE_MODE;
                        }
                    }
                }

                if (m == ZERO_PARSE_MODE) {

                    if (bc >= CONSTRAINT_ATTRIBUTE_COUNT) {

                        compare_array_elements((void*) &b, (void*) &CONSTRAINT_ATTRIBUTE, (void*) &CHARACTER_ARRAY, (void*) &CONSTRAINT_ATTRIBUTE_COUNT, (void*) &r);

                        if (r == 1) {

                            // Move current byte pointer
                            // and remaining bytes count.
                            b = b + CONSTRAINT_ATTRIBUTE_COUNT;
                            bc = bc - CONSTRAINT_ATTRIBUTE_COUNT;

                            // Set value begin pointer and count.
                            v = b;
                            vb = bc;

                            // Set parse mode.
                            m = CONSTRAINT_ATTRIBUTE_PARSE_MODE;
                        }
                    }
                }

                if (m == ZERO_PARSE_MODE) {

                    if (bc >= POSITION_ABSTRACTION_ATTRIBUTE_COUNT) {

                        compare_array_elements((void*) &b, (void*) &POSITION_ABSTRACTION_ATTRIBUTE, (void*) &CHARACTER_ARRAY, (void*) &POSITION_ABSTRACTION_ATTRIBUTE_COUNT, (void*) &r);

                        if (r == 1) {

                            // Move current byte pointer
                            // and remaining bytes count.
                            b = b + POSITION_ABSTRACTION_ATTRIBUTE_COUNT;
                            bc = bc - POSITION_ABSTRACTION_ATTRIBUTE_COUNT;

                            // Set value begin pointer and count.
                            v = b;
                            vb = bc;

                            // Set parse mode.
                            m = POSITION_ABSTRACTION_ATTRIBUTE_PARSE_MODE;
                        }
                    }
                }

                if (m == ZERO_PARSE_MODE) {

                    if (bc >= POSITION_LOCATION_ATTRIBUTE_COUNT) {

                        compare_array_elements((void*) &b, (void*) &POSITION_LOCATION_ATTRIBUTE, (void*) &CHARACTER_ARRAY, (void*) &POSITION_LOCATION_ATTRIBUTE_COUNT, (void*) &r);

                        if (r == 1) {

                            // Move current byte pointer
                            // and remaining bytes count.
                            b = b + POSITION_LOCATION_ATTRIBUTE_COUNT;
                            bc = bc - POSITION_LOCATION_ATTRIBUTE_COUNT;

                            // Set value begin pointer and count.
                            v = b;
                            vb = bc;

                            // Set parse mode.
                            m = POSITION_LOCATION_ATTRIBUTE_PARSE_MODE;
                        }
                    }
                }

                if (m == ZERO_PARSE_MODE) {

                    if (bc >= POSITION_MODEL_ATTRIBUTE_COUNT) {

                        compare_array_elements((void*) &b, (void*) &POSITION_MODEL_ATTRIBUTE, (void*) &CHARACTER_ARRAY, (void*) &POSITION_MODEL_ATTRIBUTE_COUNT, (void*) &r);

                        if (r == 1) {

                            // Move current byte pointer
                            // and remaining bytes count.
                            b = b + POSITION_MODEL_ATTRIBUTE_COUNT;
                            bc = bc - POSITION_MODEL_ATTRIBUTE_COUNT;

                            // Set value begin pointer and count.
                            v = b;
                            vb = bc;

                            // Set parse mode.
                            m = POSITION_MODEL_ATTRIBUTE_PARSE_MODE;
                        }
                    }
                }

                if (m == ZERO_PARSE_MODE) {

                    if (bc >= POSITION_CONSTRAINT_ATTRIBUTE_COUNT) {

                        compare_array_elements((void*) &b, (void*) &POSITION_CONSTRAINT_ATTRIBUTE, (void*) &CHARACTER_ARRAY, (void*) &POSITION_CONSTRAINT_ATTRIBUTE_COUNT, (void*) &r);

                        if (r == 1) {

                            // Move current byte pointer
                            // and remaining bytes count.
                            b = b + POSITION_CONSTRAINT_ATTRIBUTE_COUNT;
                            bc = bc - POSITION_CONSTRAINT_ATTRIBUTE_COUNT;

                            // Set value begin pointer and count.
                            v = b;
                            vb = bc;

                            // Set parse mode.
                            m = POSITION_CONSTRAINT_ATTRIBUTE_PARSE_MODE;
                        }
                    }
                }

                // If this block is reached, then no known term was found before.
                // The current byte pointer will just be incremented by one so
                // that new characters are read and compared in the next loop cycle.
                if (m == ZERO_PARSE_MODE) {

                    // Increment current byte within persistent model.
                    b++;
                    // Decrement remaining bytes count.
                    bc--;
                }

                //
                // Special parse modes.
                //
                // These conditions are linked with else-if because if one term
                // matches, the parse mode is switched back to ZERO_PARSE_MODE
                // and no further terms have to be compared here.
                //

                // Reset comparison result.
                // CAUTION! Do NOT delete this! One of the comparisons above
                // may have set the result to 1 so that it has to be reset here.
                r = 0;

                if (m == NAME_ATTRIBUTE_PARSE_MODE) {

                    if (bc >= ATTRIBUTE_END_COUNT) {

                        compare_array_elements((void*) &b, (void*) &ATTRIBUTE_END, (void*) &CHARACTER_ARRAY, (void*) &ATTRIBUTE_END_COUNT, (void*) &r);

                        if (r == 1) {

                            // Determine the value length as difference
                            // of the formerly stored value begin count
                            // and the current count.
                            vc = vb - bc;

                            // Interpret values.
                            // Hand over the formerly stored value begin pointer
                            // and its count.
                            interpret_name_value((void*) &v, (void*) &vc);

                            // Move current byte pointer
                            // and remaining bytes count.
                            b = b + ATTRIBUTE_END_COUNT;
                            bc = bc - ATTRIBUTE_END_COUNT;

                            // Reset values.
                            v = NULL_POINTER;
                            vc = 0;
                            vb = 0;

                            // Reset parse mode.
                            m = ZERO_PARSE_MODE;
                        }
                    }

                } else if (m == ABSTRACTION_ATTRIBUTE_PARSE_MODE) {

                    if (bc >= ATTRIBUTE_END_COUNT) {

                        compare_array_elements((void*) &b, (void*) &ATTRIBUTE_END, (void*) &CHARACTER_ARRAY, (void*) &ATTRIBUTE_END_COUNT, (void*) &r);

                        if (r == 1) {

                            // Determine the value length as difference
                            // of the formerly stored value begin count
                            // and the current count.
                            vc = vb - bc;

                            // Interpret values.
                            // Hand over the formerly stored value begin pointer
                            // and its count.
                            interpret_abstraction_value((void*) &v, (void*) &vc);

                            // Move current byte pointer
                            // and remaining bytes count.
                            b = b + ATTRIBUTE_END_COUNT;
                            bc = bc - ATTRIBUTE_END_COUNT;

                            // Reset values.
                            v = NULL_POINTER;
                            vc = 0;
                            vb = 0;

                            // Reset parse mode.
                            m = ZERO_PARSE_MODE;
                        }
                    }

                } else if (m == LOCATION_ATTRIBUTE_PARSE_MODE) {

                    if (bc >= ATTRIBUTE_END_COUNT) {

                        compare_array_elements((void*) &b, (void*) &ATTRIBUTE_END, (void*) &CHARACTER_ARRAY, (void*) &ATTRIBUTE_END_COUNT, (void*) &r);

                        if (r == 1) {

                            // Determine the value length as difference
                            // of the formerly stored value begin count
                            // and the current count.
                            vc = vb - bc;

                            // Interpret values.
                            // Hand over the formerly stored value begin pointer
                            // and its count.
                            interpret_location_value((void*) &v, (void*) &vc);

                            // Move current byte pointer
                            // and remaining bytes count.
                            b = b + ATTRIBUTE_END_COUNT;
                            bc = bc - ATTRIBUTE_END_COUNT;

                            // Reset values.
                            v = NULL_POINTER;
                            vc = 0;
                            vb = 0;

                            // Reset parse mode.
                            m = ZERO_PARSE_MODE;
                        }
                    }

                } else if (m == MODEL_ATTRIBUTE_PARSE_MODE) {

                    if (bc >= ATTRIBUTE_END_COUNT) {

                        compare_array_elements((void*) &b, (void*) &ATTRIBUTE_END, (void*) &CHARACTER_ARRAY, (void*) &ATTRIBUTE_END_COUNT, (void*) &r);

                        if (r == 1) {

                            // Determine the value length as difference
                            // of the formerly stored value begin count
                            // and the current count.
                            vc = vb - bc;

                            // Interpret values.
                            // Hand over the formerly stored value begin pointer
                            // and its count.
                            interpret_model_value((void*) &v, (void*) &vc);

                            // Move current byte pointer
                            // and remaining bytes count.
                            b = b + ATTRIBUTE_END_COUNT;
                            bc = bc - ATTRIBUTE_END_COUNT;

                            // Reset values.
                            v = NULL_POINTER;
                            vc = 0;
                            vb = 0;

                            // Reset parse mode.
                            m = ZERO_PARSE_MODE;
                        }
                    }

                } else if (m == CONSTRAINT_ATTRIBUTE_PARSE_MODE) {

                    if (bc >= ATTRIBUTE_END_COUNT) {

                        compare_array_elements((void*) &b, (void*) &ATTRIBUTE_END, (void*) &CHARACTER_ARRAY, (void*) &ATTRIBUTE_END_COUNT, (void*) &r);

                        if (r == 1) {

                            // Determine the value length as difference
                            // of the formerly stored value begin count
                            // and the current count.
                            vc = vb - bc;

                            // Interpret values.
                            // Hand over the formerly stored value begin pointer
                            // and its count.
                            interpret_constraint_value((void*) &v, (void*) &vc);

                            // Move current byte pointer
                            // and remaining bytes count.
                            b = b + ATTRIBUTE_END_COUNT;
                            bc = bc - ATTRIBUTE_END_COUNT;

                            // Reset values.
                            v = NULL_POINTER;
                            vc = 0;
                            vb = 0;

                            // Reset parse mode.
                            m = ZERO_PARSE_MODE;
                        }
                    }

                } else if (m == POSITION_ABSTRACTION_ATTRIBUTE_PARSE_MODE) {

                    if (bc >= ATTRIBUTE_END_COUNT) {

                        compare_array_elements((void*) &b, (void*) &ATTRIBUTE_END, (void*) &CHARACTER_ARRAY, (void*) &ATTRIBUTE_END_COUNT, (void*) &r);

                        if (r == 1) {

                            // Determine the value length as difference
                            // of the formerly stored value begin count
                            // and the current count.
                            vc = vb - bc;

                            // Interpret values.
                            // Hand over the formerly stored value begin pointer
                            // and its count.
                            interpret_position_abstraction_value((void*) &v, (void*) &vc);

                            // Move current byte pointer
                            // and remaining bytes count.
                            b = b + ATTRIBUTE_END_COUNT;
                            bc = bc - ATTRIBUTE_END_COUNT;

                            // Reset values.
                            v = NULL_POINTER;
                            vc = 0;
                            vb = 0;

                            // Reset parse mode.
                            m = ZERO_PARSE_MODE;
                        }
                    }

                } else if (m == POSITION_LOCATION_ATTRIBUTE_PARSE_MODE) {

                    if (bc >= ATTRIBUTE_END_COUNT) {

                        compare_array_elements((void*) &b, (void*) &ATTRIBUTE_END, (void*) &CHARACTER_ARRAY, (void*) &ATTRIBUTE_END_COUNT, (void*) &r);

                        if (r == 1) {

                            // Determine the value length as difference
                            // of the formerly stored value begin count
                            // and the current count.
                            vc = vb - bc;

                            // Interpret values.
                            // Hand over the formerly stored value begin pointer
                            // and its count.
                            interpret_position_location_value((void*) &v, (void*) &vc);

                            // Move current byte pointer
                            // and remaining bytes count.
                            b = b + ATTRIBUTE_END_COUNT;
                            bc = bc - ATTRIBUTE_END_COUNT;

                            // Reset values.
                            v = NULL_POINTER;
                            vc = 0;
                            vb = 0;

                            // Reset parse mode.
                            m = ZERO_PARSE_MODE;
                        }
                    }

                } else if (m == POSITION_MODEL_ATTRIBUTE_PARSE_MODE) {

                    if (bc >= ATTRIBUTE_END_COUNT) {

                        compare_array_elements((void*) &b, (void*) &ATTRIBUTE_END, (void*) &CHARACTER_ARRAY, (void*) &ATTRIBUTE_END_COUNT, (void*) &r);

                        if (r == 1) {

                            // Determine the value length as difference
                            // of the formerly stored value begin count
                            // and the current count.
                            vc = vb - bc;

                            // Interpret values.
                            // Hand over the formerly stored value begin pointer
                            // and its count.
                            interpret_position_model_value((void*) &v, (void*) &vc);

                            // Move current byte pointer
                            // and remaining bytes count.
                            b = b + ATTRIBUTE_END_COUNT;
                            bc = bc - ATTRIBUTE_END_COUNT;

                            // Reset values.
                            v = NULL_POINTER;
                            vc = 0;
                            vb = 0;

                            // Reset parse mode.
                            m = ZERO_PARSE_MODE;
                        }
                    }

                } else if (m == POSITION_CONSTRAINT_ATTRIBUTE_PARSE_MODE) {

                    if (bc >= ATTRIBUTE_END_COUNT) {

                        compare_array_elements((void*) &b, (void*) &ATTRIBUTE_END, (void*) &CHARACTER_ARRAY, (void*) &ATTRIBUTE_END_COUNT, (void*) &r);

                        if (r == 1) {

                            // Determine the value length as difference
                            // of the formerly stored value begin count
                            // and the current count.
                            vc = vb - bc;

                            // Interpret values.
                            // Hand over the formerly stored value begin pointer
                            // and its count.
                            interpret_position_constraint_value((void*) &v, (void*) &vc);

                            // Move current byte pointer
                            // and remaining bytes count.
                            b = b + ATTRIBUTE_END_COUNT;
                            bc = bc - ATTRIBUTE_END_COUNT;

                            // Reset values.
                            v = NULL_POINTER;
                            vc = 0;
                            vb = 0;

                            // Reset parse mode.
                            m = ZERO_PARSE_MODE;
                        }
                    }
                }

                // Reset comparison result.
                r = 0;
            }

        } else {

//??            log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not interpret super attributes. The persistent attributes is null.");
        }

    } else {

//??        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not interpret super attributes. The persistent attributes count is null.");
    }
*/
}

/**
 * Serializes super attributes.
 *
 * @param p0 the persistent attributes pointer
 * @param p1 the persistent attributes count
 */
void serialize_super_attributes(const void* p0, const void* p1) {
}

/**
 * Initializes the part.
 *
 * @param p0 the transient model
 * @param p1 the transient model count
 * @param p2 the transient model size
 * @param p3 the persistent attributes pointer
 * @param p4 the persistent attributes count
 */
void initialize_part(void* p0, void* p1, void* p2, const void* p3, const void* p4) {

    if (p4 != NULL_POINTER) {

        int* pc = (int*) p4;

        if (p3 != NULL_POINTER) {

            void** p = (void**) p3;

        } else {

//??            log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not initialize part. The persistent attributes pointer is null.");
        }

    } else {

//??        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not initialize part. The persistent attributes count is null.");
    }
}

/**
 * Serializes part attributes.
 *
 * @param p0 the persistent attributes pointer
 * @param p1 the persistent attributes count
 */
void serialize_part_attributes(const void* p0, const void* p1) {
}

//
// Xml model.
//

/**
 * Encodes the xml model.
 *
 * @param p0 the knowledge model
 * @param p1 the knowledge model count
 * @param p2 the knowledge model size
 * @param p3 the xml model
 * @param p4 the xml model count
 */
void encode_xml(void* p0, void* p1, void* p2, const void* p3, const void* p4) {
}

/**
 * Decodes the xml model.
 *
 * @param p0 the knowledge model
 * @param p1 the knowledge model count
 * @param p2 the knowledge model size
 * @param p3 the xml model
 * @param p4 the xml model count
 */
void decode_xml(const void* p0, const void* p1, const void* p2, void* p3, void* p4) {
}

/* XML_TRANSLATOR_SOURCE */
#endif
