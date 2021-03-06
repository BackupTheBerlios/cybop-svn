/*
 * $RCSfile: PortalToolBar.java,v $
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

package cybop.core.screen.region.toolbar;

import cybop.core.model.*;
import cybop.core.screen.component.*;
import cybop.core.screen.region.*;

/**
 * This class represents a portal tool bar.
 *
 * @version $Revision: 1.4 $ $Date: 2003-06-20 13:44:24 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class PortalToolBar extends ToolBar {

    //
    // Initialization.
    //

    /**
     * Initializes this item.
     */
    public void initialize() throws Exception {

        super.initialize();
        
/*??
        add(createShowApplicationTreeButton());
        addSeparator();
        add(createConfigureApplicationTreeButton());
        add(createConfigureResMedicinaeButton());
        addSeparator();
        add(createShowHelpContentsButton());
        add(createLinkToWebsiteButton());
        add(createAboutDialogControllerButton());

        setOrientation(MainApplicationToolBar.HORIZONTAL);
        setFloatable(true);
        setBorderPainted(true);
*/
    }

    /**
     * Finalizes this item.
     */
    public void finalizz() throws Exception {
        
        super.finalizz();
    }

    /**
     * Creates the show application tree button.
     *
     * @return the show application tree button
     * @exception Exception if the button is null
     * @exception Exception if the image icon is null
     */
    public Button createShowApplicationTreeButton() throws Exception {

        Button b = new Button();

        if (b != null) {

/*??
            String file = "show_application_tree.gif";
            URL location = getClass().getResource(file);

            b.setIcon(new ResImageIcon(location));
            b.setActionCommand(MainApplication.SHOW_APPLICATION_TREE_CONTROL_ID);
*/

        } else {

            throw new Exception("Could not create show application tree button. The button is null.");
        }

        return b;
    }

    /**
     * Creates the configure application tree button.
     *
     * @return the configure application tree button
     * @exception Exception if the button is null
     * @exception Exception if the image icon is null
     */
    public Button createConfigureApplicationTreeButton() throws Exception {

        Button b = new Button();

        if (b != null) {

/*??
            String file = "configure_application_tree.gif";
            URL location = getClass().getResource(file);

            b.setIcon(new ResImageIcon(location));
            b.setActionCommand(MainApplication.CONFIGURE_APPLICATION_TREE_CONTROL_ID);
*/

        } else {

            throw new Exception("Could not create configure application tree button. The button is null.");
        }

        return b;
    }

    /**
     * Creates the configure Res Medicinae button.
     *
     * @return the configure Res Medicinae button
     * @exception Exception if the button is null
     * @exception Exception if the image icon is null
     */
    public Button createConfigureResMedicinaeButton() throws Exception {

        Button b = new Button();

        if (b != null) {

/*??
            String file = "configure_res_medicinae.gif";
            URL location = getClass().getResource(file);

            b.setIcon(new ResImageIcon(location));
            b.setActionCommand(MainApplication.CONFIGURE_RES_MEDICINAE_CONTROL_ID);
*/

        } else {

            throw new Exception("Could not create configure Res Medicinae button. The button is null.");
        }

        return b;
    }

    /**
     * Creates the show help contents button.
     *
     * @return the show help contents button
     * @exception Exception if the button is null
     * @exception Exception if the image icon is null
     */
    public Button createShowHelpContentsButton() throws Exception {

        Button b = new Button();

        if (b != null) {

/*??
            String file = "show_help_contents.gif";
            URL location = getClass().getResource(file);

            b.setIcon(new ResImageIcon(location));
            b.setActionCommand(MainApplication.SHOW_HELP_CONTENTS_CONTROL_ID);
*/

        } else {

            throw new Exception("Could not create show help contents button. The button is null.");
        }

        return b;
    }

    /**
     * Creates the link to website button.
     *
     * @return the link to website button
     * @exception Exception if the button is null
     * @exception Exception if the image icon is null
     */
    public Button createLinkToWebsiteButton() throws Exception {

        Button b = new Button();

        if (b != null) {

/*??
            String file = "link_to_website.gif";
            URL location = getClass().getResource(file);

            b.setIcon(new ResImageIcon(location));
            b.setActionCommand(MainApplication.LINK_TO_WEBSITE_CONTROL_ID);
*/

        } else {

            throw new Exception("Could not create link to website button. The button is null.");
        }

        return b;
    }

    /**
     * Creates the about dialog controller button.
     *
     * @return the about dialog controller button
     * @exception Exception if the button is null
     * @exception Exception if the image icon is null
     */
    public Button createAboutDialogControllerButton() throws Exception {

        Button b = new Button();

        if (b != null) {

/*??
//??            String file = "/opt/resmedicinae/src/application/main/resmedicinae/org/resmedicinae/application/main/resmedicinae/inform_about_res_medicinae.gif";
            String file = "inform_about_res_medicinae.gif";
            URL location = getClass().getResource(file);

            b.setIcon(new ResImageIcon(location));
            b.setActionCommand(AboutDialog.CREATE_ABOUT_DIALOG_CONTROL_ID);
*/

        } else {

            throw new Exception("Could not create about dialog controller button. The button is null.");
        }

        return b;
    }
}

