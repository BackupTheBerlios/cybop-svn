/*
 * $RCSfile: PortalToolBar.java,v $
 *
 * Copyright (c) 1999-2003. The Res Medicinae developers. All rights reserved.
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
 * http://www.resmedicinae.org
 * - Information in Medicine -
 */

package cybop.model.organizer;

import cybop.model.*;

/**
 * This class represents a portal tool bar.
 *
 * @version $Revision: 1.1 $ $Date: 2003-02-19 07:49:23 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class PortalToolBar extends ToolBar {

    //
    // Initializable.
    //

    /**
     * Initializes the tool bar.
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
     * Finalizes the tool bar.
     */
    public void finalizz() throws Exception {
        
        super.finalizz();
    }

    /**
     * Creates the show application tree button.
     *
     * @return the show application tree button
     * @exception NullPointerException if the button is null
     * @exception NullPointerException if the image icon is null
     */
    public Button createShowApplicationTreeButton() throws NullPointerException
    {

        Button b = new Button();

        if (b != null)
        {

/*??
            String file = "show_application_tree.gif";
            URL location = getClass().getResource(file);

            b.setIcon(new ResImageIcon(location));
            b.setActionCommand(MainApplication.SHOW_APPLICATION_TREE_CONTROL_ID);
*/

        }
        else
        {

            throw new NullPointerException("Could not create show application tree button. The button is null.");
        }

        return b;
    }

    /**
     * Creates the configure application tree button.
     *
     * @return the configure application tree button
     * @exception NullPointerException if the button is null
     * @exception NullPointerException if the image icon is null
     */
    public Button createConfigureApplicationTreeButton() throws NullPointerException
    {

        Button b = new Button();

        if (b != null)
        {

/*??
            String file = "configure_application_tree.gif";
            URL location = getClass().getResource(file);

            b.setIcon(new ResImageIcon(location));
            b.setActionCommand(MainApplication.CONFIGURE_APPLICATION_TREE_CONTROL_ID);
*/

        }
        else
        {

            throw new NullPointerException("Could not create configure application tree button. The button is null.");
        }

        return b;
    }

    /**
     * Creates the configure Res Medicinae button.
     *
     * @return the configure Res Medicinae button
     * @exception NullPointerException if the button is null
     * @exception NullPointerException if the image icon is null
     */
    public Button createConfigureResMedicinaeButton() throws NullPointerException
    {

        Button b = new Button();

        if (b != null)
        {

/*??
            String file = "configure_res_medicinae.gif";
            URL location = getClass().getResource(file);

            b.setIcon(new ResImageIcon(location));
            b.setActionCommand(MainApplication.CONFIGURE_RES_MEDICINAE_CONTROL_ID);
*/

        }
        else
        {

            throw new NullPointerException("Could not create configure Res Medicinae button. The button is null.");
        }

        return b;
    }

    /**
     * Creates the show help contents button.
     *
     * @return the show help contents button
     * @exception NullPointerException if the button is null
     * @exception NullPointerException if the image icon is null
     */
    public Button createShowHelpContentsButton() throws NullPointerException
    {

        Button b = new Button();

        if (b != null)
        {

/*??
            String file = "show_help_contents.gif";
            URL location = getClass().getResource(file);

            b.setIcon(new ResImageIcon(location));
            b.setActionCommand(MainApplication.SHOW_HELP_CONTENTS_CONTROL_ID);
*/

        }
        else
        {

            throw new NullPointerException("Could not create show help contents button. The button is null.");
        }

        return b;
    }

    /**
     * Creates the link to website button.
     *
     * @return the link to website button
     * @exception NullPointerException if the button is null
     * @exception NullPointerException if the image icon is null
     */
    public Button createLinkToWebsiteButton() throws NullPointerException
    {

        Button b = new Button();

        if (b != null)
        {

/*??
            String file = "link_to_website.gif";
            URL location = getClass().getResource(file);

            b.setIcon(new ResImageIcon(location));
            b.setActionCommand(MainApplication.LINK_TO_WEBSITE_CONTROL_ID);
*/

        }
        else
        {

            throw new NullPointerException("Could not create link to website button. The button is null.");
        }

        return b;
    }

    /**
     * Creates the about dialog controller button.
     *
     * @return the about dialog controller button
     * @exception NullPointerException if the button is null
     * @exception NullPointerException if the image icon is null
     */
    public Button createAboutDialogControllerButton() throws NullPointerException
    {

        Button b = new Button();

        if (b != null)
        {

/*??
//??            String file = "/opt/resmedicinae/src/application/main/resmedicinae/org/resmedicinae/application/main/resmedicinae/inform_about_res_medicinae.gif";
            String file = "inform_about_res_medicinae.gif";
            URL location = getClass().getResource(file);

            b.setIcon(new ResImageIcon(location));
            b.setActionCommand(AboutDialog.CREATE_ABOUT_DIALOG_CONTROL_ID);
*/

        }
        else
        {

            throw new NullPointerException("Could not create about dialog controller button. The button is null.");
        }

        return b;
    }
}

