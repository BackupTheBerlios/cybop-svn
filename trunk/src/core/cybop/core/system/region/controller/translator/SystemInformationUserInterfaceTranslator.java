/*
 * $RCSfile: SystemInformationUserInterfaceTranslator.java,v $
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

import cybop.core.basic.String;
import cybop.core.model.*;
import cybop.core.model.model.*;
import cybop.core.model.model.user.*;
import cybop.core.model.organizer.*;
import cybop.core.model.unit.*;
import cybop.core.system.region.controller.*;

/**
 * This class represents a system information user interface translator.
 *
 * @version $Revision: 1.4 $ $Date: 2003-04-24 15:58:47 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class SystemInformationUserInterfaceTranslator extends Translator {

    //
    // Coding.
    //

    /**
     * Encodes the domain model.
     *
     * @param dm the domain model
     * @param m the encoded model
     * @exception NullPointerException if the system information user interface is null
     * @exception NullPointerException if the system information contents panel is null
     * @exception NullPointerException if the domain model is null
     */
    public void encode(DomainModel dm, Model m) throws NullPointerException {

        SystemInformationUserInterface ui = (SystemInformationUserInterface) m;

        if (ui != null) {
            
            SystemInformationContentsPanel p = (SystemInformationContentsPanel) ui.getChildItem(SystemInformationUserInterface.CONTENTS_PANEL);

            if (p != null) {

                if (dm != null) {

                    encodeHeadPanel((SystemInformation) dm.getChildItem(DomainModel.SYSTEM_INFORMATION), (HeadPanel) p.getChildItem(SystemInformationContentsPanel.HEAD_PANEL));
                    encodeTabbedPane((SystemInformation) dm.getChildItem(DomainModel.SYSTEM_INFORMATION), (TabbedPane) p.getChildItem(SystemInformationContentsPanel.TABBED_PANE));

                } else {

                    throw new NullPointerException("Could not encode domain model. The domain model is null.");
                }
    
            } else {

                throw new NullPointerException("Could not encode domain model. The system information contents panel is null.");
            }
    
        } else {

            throw new NullPointerException("Could not encode domain model. The system information user interface is null.");
        }
    }

    /**
     * Decodes the model.
     *
     * @param m the encoded model
     * @param dm the domain model
     */
    public void decode(Model m, DomainModel dm) {
    }

    //
    // Encoding.
    //

    /**
     * Encodes into the head panel.
     *
     * @param i the system information
     * @param p the head panel
     * @exception NullPointerException if the system information is null
     * @exception NullPointerException if the head panel is null
     */
    private void encodeHeadPanel(SystemInformation i, HeadPanel p) {

        if (i != null) {

            if (p != null) {

                encodeLabel((Label) p.getChildItem(HeadPanel.NAME_LABEL), (String) i.getChildItem(SystemInformation.NAME));
                encodeLabel((Label) p.getChildItem(HeadPanel.VERSION_LABEL), (String) i.getChildItem(SystemInformation.VERSION));
                encodeLabel((Label) p.getChildItem(HeadPanel.DATE_LABEL), (String) i.getChildItem(SystemInformation.DATE));
                encodeLabel((Label) p.getChildItem(HeadPanel.SLOGAN_LABEL), (String) i.getChildItem(SystemInformation.SLOGAN));

            } else {

                throw new NullPointerException("Could not encode into head panel. The head panel is null.");
            }
    
        } else {

            throw new NullPointerException("Could not encode into head panel. The system information is null.");
        }
    }

    /**
     * Encodes into the label.
     *
     * @param l the label
     * @param t the text
     * @exception NullPointerException if the label is null
     */
    private void encodeLabel(Label l, String text) {

        if (l != null) {

            l.setText(text);

        } else {

            throw new NullPointerException("Could not encode into label. The label is null.");
        }
    }

    /**
     * Encodes into the tabbed pane.
     *
     * @param i the system information
     * @param p the tabbed pane
     * @exception NullPointerException if the system information is null
     * @exception NullPointerException if the tabbed pane is null
     */
    private void encodeTabbedPane(SystemInformation i, TabbedPane p) {
    }
}

