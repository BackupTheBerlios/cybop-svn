/*
 * $RCSfile: SystemInformation.java,v $
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

package cybop.core.model.unit;

import cybop.core.basic.String;
import cybop.core.model.*;
import cybop.core.system.chain.*;

/**
 * This class represents a system information model.
 *
 * It contains information about a system.
 *
 * @version $Revision: 1.5 $ $Date: 2003-04-24 15:58:46 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class SystemInformation extends Unit {

    //
    // Children names.
    //

    /** The name. */
    public static final String NAME = new String("name");

    /** The version. */
    public static final String VERSION = new String("version");

    /** The date. */
    public static final String DATE = new String("date");

    /** The slogan id. */
    public static final String SLOGAN = new String("slogan");

    /** The logo. */
    public static final String LOGO = new String("logo");

    /** The copyright. */
    public static final String COPYRIGHT = new String("copyright");

    /** The contact. */
    public static final String CONTACT = new String("contact");

    /** The description id. */
    public static final String DESCRIPTION = new String("description");

    /** The authors. */
    public static final String AUTHORS = new String("authors");

    /** The helpers. */
    public static final String HELPERS = new String("helpers");

    /** The inspirations. */
    public static final String INSPIRATIONS = new String("inspirations");

    /** The license. */
    public static final String LICENSE = new String("license");

    //
    // Default children.
    //

    /**
     * Returns the default name.
     *
     * @return the default name
     */
    public String getDefaultName() {

        return new String("Res Medicinae");
    }

    /**
     * Returns the default version.
     *
     * @return the default version
     */
    public String getDefaultVersion() {

        return new String("0.0.5.0");
    }

    /**
     * Returns the default date.
     *
     * @return the default date
     */
    public String getDefaultDate() {

        return new String("31.01.2003");
    }

    /**
     * Returns the default slogan.
     *
     * @return the default slogan
     */
    public String getDefaultSlogan() {

        return new String("- Cybernetics Oriented Programming -");
    }

    /**
     * Returns the default logo.
     *
     * @return the default logo
     */
    public String getDefaultLogo() {

        return null;
    }

    /**
     * Returns the default copyright.
     *
     * @return the default copyright
     */
    public String getDefaultCopyright() {

        return new String("Copyright (c) 1999-2003. Christian Heller <christian.heller@tuxtax.de>. All rights reserved.");
    }

    /**
     * Returns the default contact.
     *
     * @return the default contact
     */
    public String getDefaultContact() {

        return new String("http://www.cybop.net");
    }

    /**
     * Returns the default description.
     *
     * @return the default description
     */
    public String getDefaultDescription() {

        return new String("Free Medical Information System");
    }

    /**
     * Returns the default authors.
     *
     * @return the default authors
     */
    public String getDefaultAuthors() {

        return new String("Unspecified Authors.\n"
            + "Try to contact these project administrators:\n\n"
            + "Christian Heller\n<christian.heller@tuxtax.de>\n\n"
            + "Karsten Hilbert\n<karsten.hilbert@gmx.net>");
    }

    /**
     * Returns the default helpers.
     *
     * @return the default helpers
     */
    public String getDefaultHelpers() {

        return new String("Helpers ...");
    }

    /**
     * Returns the default inspirations.
     *
     * @return the default inspirations
     */
    public String getDefaultInspirations() {

        return new String("Inspirations ...");
    }

    /**
     * Returns the default license.
     *
     * @return the default license
     */
    public String getDefaultLicense() {

        return new String("This software is published under the GPL GNU General Public License.\n"
            + "This program is free software; you can redistribute it and/or\n"
            + "modify it under the terms of the GNU General Public License\n"
            + "as published by the Free Software Foundation; either version 2\n"
            + "of the License, or (at your option) any later version.\n\n"
            + "This program is distributed in the hope that it will be useful,\n"
            + "but WITHOUT ANY WARRANTY; without even the implied warranty of\n"
            + "MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the\n"
            + "GNU General Public License for more details.\n\n"
            + "You should have received a copy of the GNU General Public License\n"
            + "along with this program; if not, write to the Free Software\n"
            + "Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.\n\n"
            + "Find the GPL license and more information at: http://www.gnu.org");
    }

    //
    // Initialization.
    //

    /**
     * Initializes this system information.
     *
     * @exception NullPointerException if the configuration is null
     */
    public void initialize() throws Exception, NullPointerException {

        super.initialize();

        Configuration c = (Configuration) getChildItem(SystemInformation.CONFIGURATION);

        if (c != null) {

            setChildItem(SystemInformation.NAME, getDefaultName());
            setChildItem(SystemInformation.VERSION, getDefaultVersion());
            setChildItem(SystemInformation.DATE, getDefaultDate());

            String slogan = (String) c.getChildItem(SystemInformation.SLOGAN, getDefaultSlogan());

            if ((slogan != null) && !slogan.equals("null")) {

                setChildItem(SystemInformation.SLOGAN, slogan);
            }

            setChildItem(SystemInformation.LOGO, getDefaultLogo());
            setChildItem(SystemInformation.COPYRIGHT, getDefaultCopyright());
            setChildItem(SystemInformation.CONTACT, getDefaultContact());

            String description = (String) c.getChildItem(SystemInformation.DESCRIPTION, getDefaultDescription());

            if ((description != null) && !description.equals("null")) {

                setChildItem(SystemInformation.DESCRIPTION, description);
            }

            setChildItem(SystemInformation.AUTHORS, getDefaultAuthors());
            setChildItem(SystemInformation.HELPERS, getDefaultHelpers());
            setChildItem(SystemInformation.INSPIRATIONS, getDefaultInspirations());
            setChildItem(SystemInformation.LICENSE, getDefaultLicense());

        } else {

            throw new NullPointerException("Could not initialize system information. The configuration is null.");
        }
    }

    /**
     * Finalizes this system.
     *
     * @exception NullPointerException if the configuration is null
     */
    public void finalizz() throws Exception, NullPointerException {

        Configuration c = (Configuration) getChildItem(SystemInformation.CONFIGURATION);

        if (c != null) {

            String license = (String) getChildItem(SystemInformation.LICENSE);
            removeChildItem(SystemInformation.LICENSE);
//??            destroyLicense(license);

            String inspirations = (String) getChildItem(SystemInformation.INSPIRATIONS);
            removeChildItem(SystemInformation.INSPIRATIONS);
//??            destroyInspirations(inspirations);

            String helpers = (String) getChildItem(SystemInformation.HELPERS);
            removeChildItem(SystemInformation.HELPERS);
//??            destroyHelpers(helpers);

            String authors = (String) getChildItem(SystemInformation.AUTHORS);
            removeChildItem(SystemInformation.AUTHORS);
//??            destroyAuthors(authors);

            String description = (String) getChildItem(SystemInformation.DESCRIPTION);
            c.setChildItem(SystemInformation.DESCRIPTION, description);
            removeChildItem(SystemInformation.DESCRIPTION);
//??            destroyDescription(description);

            String contact = (String) getChildItem(SystemInformation.CONTACT);
            removeChildItem(SystemInformation.CONTACT);
//??            destroyContact(contact);

            String copyright = (String) getChildItem(SystemInformation.COPYRIGHT);
            removeChildItem(SystemInformation.COPYRIGHT);
//??            destroyCopyright(copyright);

            String logo = (String) getChildItem(SystemInformation.LOGO);
            removeChildItem(SystemInformation.LOGO);
//??            destroyLogo(logo);

            String slogan = (String) getChildItem(SystemInformation.SLOGAN);
            c.setChildItem(SystemInformation.SLOGAN, slogan);
            removeChildItem(SystemInformation.SLOGAN);
//??            destroySlogan(slogan);

            String date = (String) getChildItem(SystemInformation.DATE);
            removeChildItem(SystemInformation.DATE);
//??            destroyDate(date);

            String version = (String) getChildItem(SystemInformation.VERSION);
            removeChildItem(SystemInformation.VERSION);
//??            destroyVersion(version);

            String name = (String) getChildItem(SystemInformation.NAME);
            removeChildItem(SystemInformation.NAME);
//??            destroyName(name);

        } else {

            throw new NullPointerException("Could not finalize system information. The configuration is null.");
        }

        super.finalizz();
    }
}

