/*
 * $RCSfile: SystemInformationDisplayTranslator.java,v $
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

package cybop.core.system.region.controller.translator;

import cybop.core.model.*;
import cybop.core.model.String;
import cybop.core.screen.component.*;
import cybop.core.screen.model.frame.*;
import cybop.core.screen.region.*;
import cybop.core.system.region.controller.*;
import cybop.core.systeminformation.*;

/**
 * This class represents a system information display translator.
 *
 * @version $Revision: 1.2 $ $Date: 2003-06-17 15:39:22 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class SystemInformationDisplayTranslator extends Translator {

    //
    // Coding.
    //

    /**
     * Encodes the knowledge model.
     *
     * @param dm the knowledge model
     * @param m the encoded model
     * @exception Exception if the system information display is null
     * @exception Exception if the system information contents panel is null
     * @exception Exception if the knowledge model is null
     */
    public void encode(Item dm, Item m) throws Exception {

        SystemInformationDisplay ui = (SystemInformationDisplay) m;

        if (ui != null) {
            
            SystemInformationPanel p = (SystemInformationPanel) ui.getChild(SystemInformationDisplay.CONTENTS_PANEL);

            if (p != null) {

                if (dm != null) {

                    encodeSystemVersionPanel((SystemInformationDisplay) dm.getChild(KnowledgeModel.SYSTEM_INFORMATION), (SystemVersionPanel) p.getChild(SystemInformationPanel.HEAD_PANEL));
                    encodeTabbedPane((SystemInformationDisplay) dm.getChild(KnowledgeModel.SYSTEM_INFORMATION), (TabbedPane) p.getChild(SystemInformationPanel.TABBED_PANE));

                } else {

                    throw new Exception("Could not encode knowledge model. The knowledge model is null.");
                }
    
            } else {

                throw new Exception("Could not encode knowledge model. The system information contents panel is null.");
            }
    
        } else {

            throw new Exception("Could not encode knowledge model. The system information display is null.");
        }
    }

    /**
     * Decodes the model.
     *
     * @param m the encoded model
     * @param dm the knowledge model
     */
    public void decode(Item m, Item dm) {
    }

    //
    // Encoding.
    //

    /**
     * Encodes into the head panel.
     *
     * @param i the system information
     * @param p the head panel
     * @exception Exception if the system information is null
     * @exception Exception if the head panel is null
     */
    private void encodeSystemVersionPanel(SystemInformationDisplay i, SystemVersionPanel p) {

        if (i != null) {

            if (p != null) {

                encodeLabel((Label) p.getChild(SystemVersionPanel.NAME_LABEL), (String) i.getChild(SystemInformationDisplay.NAME));
                encodeLabel((Label) p.getChild(SystemVersionPanel.VERSION_LABEL), (String) i.getChild(SystemInformationDisplay.VERSION));
                encodeLabel((Label) p.getChild(SystemVersionPanel.DATE_LABEL), (String) i.getChild(SystemInformationDisplay.DATE));
                encodeLabel((Label) p.getChild(SystemVersionPanel.SLOGAN_LABEL), (String) i.getChild(SystemInformationDisplay.SLOGAN));

            } else {

                throw new Exception("Could not encode into head panel. The head panel is null.");
            }
    
        } else {

            throw new Exception("Could not encode into head panel. The system information is null.");
        }
    }

    /**
     * Encodes into the label.
     *
     * @param l the label
     * @param t the text
     * @exception Exception if the label is null
     */
    private void encodeLabel(Label l, String text) {

        if (l != null) {

            l.setText(text);

        } else {

            throw new Exception("Could not encode into label. The label is null.");
        }
    }

    /**
     * Encodes into the tabbed pane.
     *
     * @param i the system information
     * @param p the tabbed pane
     * @exception Exception if the system information is null
     * @exception Exception if the tabbed pane is null
     */
    private void encodeTabbedPane(SystemInformationDisplay i, TabbedPane p) {
    }
}

