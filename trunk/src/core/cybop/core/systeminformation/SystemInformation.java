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

package cybop.core.systeminformation;

import cybop.core.category.*;
import cybop.core.model.*;
import cybop.core.model.String;

/**
 * This class represents a system information.
 *
 * It contains information about a system.
 *
 * @version $Revision: 1.3 $ $Date: 2003-06-19 22:25:11 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class SystemInformation extends Item {

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
    // Default categories.
    //

    /**
     * Returns the default name category.
     *
     * @return the default name category
     */
    public String getDefaultNameCategory() {

        return new String("Res Medicinae");
    }

    /**
     * Returns the default version category.
     *
     * @return the default version category
     */
    public String getDefaultVersionCategory() {

        return new String("0.0.5.0");
    }

    /**
     * Returns the default date category.
     *
     * @return the default date category
     */
    public String getDefaultDateCategory() {

        return new String("31.01.2003");
    }

    /**
     * Returns the default slogan category.
     *
     * @return the default slogan category
     */
    public String getDefaultSloganCategory() {

        return new String("- Cybernetics Oriented Programming -");
    }

    /**
     * Returns the default logo category.
     *
     * @return the default logo category
     */
    public String getDefaultLogoCategory() {

        return null;
    }

    /**
     * Returns the default copyright category.
     *
     * @return the default copyright category
     */
    public String getDefaultCopyrightCategory() {

        return new String("Copyright (c) 1999-2003. Christian Heller <christian.heller@tuxtax.de>. All rights reserved.");
    }

    /**
     * Returns the default contact category.
     *
     * @return the default contact category
     */
    public String getDefaultContactCategory() {

        return new String("http://www.cybop.net");
    }

    /**
     * Returns the default description category.
     *
     * @return the default description category
     */
    public String getDefaultDescriptionCategory() {

        return new String("Free Medical Information System");
    }

    /**
     * Returns the default authors category.
     *
     * @return the default authors category
     */
    public String getDefaultAuthorsCategory() {

        return new String("Unspecified Authors.\n"
            + "Try to contact these project administrators:\n\n"
            + "Christian Heller\n<christian.heller@tuxtax.de>\n\n"
            + "Karsten Hilbert\n<karsten.hilbert@gmx.net>");
    }

    /**
     * Returns the default helpers category.
     *
     * @return the default helpers category
     */
    public String getDefaultHelpersCategory() {

        return new String("Helpers ...");
    }

    /**
     * Returns the default inspirations category.
     *
     * @return the default inspirations category
     */
    public String getDefaultInspirationsCategory() {

        return new String("Inspirations ...");
    }

    /**
     * Returns the default license category.
     *
     * @return the default license category
     */
    public String getDefaultLicenseCategory() {

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
    // Categorization.
    //

    /**
     * Categorizes this hierarchy.
     */
    public void categorize() throws Exception {

        super.categorize();

        setCategory(SystemInformation.NAME, getDefaultNameCategory());
        setCategory(SystemInformation.VERSION, getDefaultVersionCategory());
        setCategory(SystemInformation.DATE, getDefaultDateCategory());
        setCategory(SystemInformation.SLOGAN, getDefaultSloganCategory());
        setCategory(SystemInformation.LOGO, getDefaultLogoCategory());
        setCategory(SystemInformation.COPYRIGHT, getDefaultCopyrightCategory());
        setCategory(SystemInformation.CONTACT, getDefaultContactCategory());
        setCategory(SystemInformation.DESCRIPTION, getDefaultDescriptionCategory());
        setCategory(SystemInformation.AUTHORS, getDefaultAuthorsCategory());
        setCategory(SystemInformation.HELPERS, getDefaultHelpersCategory());
        setCategory(SystemInformation.INSPIRATIONS, getDefaultInspirationsCategory());
        setCategory(SystemInformation.LICENSE, getDefaultLicenseCategory());
    }

    /**
     * Decategorizes this hierarchy.
     */
    public void decategorize() throws Exception {

        removeCategory(SystemInformation.LICENSE);
        removeCategory(SystemInformation.INSPIRATIONS);
        removeCategory(SystemInformation.HELPERS);
        removeCategory(SystemInformation.AUTHORS);
        removeCategory(SystemInformation.DESCRIPTION);
        removeCategory(SystemInformation.CONTACT);
        removeCategory(SystemInformation.COPYRIGHT);
        removeCategory(SystemInformation.LOGO);
        removeCategory(SystemInformation.SLOGAN);
        removeCategory(SystemInformation.DATE);
        removeCategory(SystemInformation.VERSION);
        removeCategory(SystemInformation.NAME);

        super.decategorize();
    }

    //
    // Initialization.
    //

    /**
     * Initializes this item.
     */
    public void initialize() throws Exception {

        super.initialize();

        setChild(SystemInformation.NAME, (Item) getCategory(SystemInformation.NAME));
        setChild(SystemInformation.VERSION, (Item) getCategory(SystemInformation.VERSION));
        setChild(SystemInformation.DATE, (Item) getCategory(SystemInformation.DATE));
        setChild(SystemInformation.SLOGAN, (Item) getCategory(SystemInformation.SLOGAN));
        setChild(SystemInformation.LOGO, (Item) getCategory(SystemInformation.LOGO));
        setChild(SystemInformation.COPYRIGHT, (Item) getCategory(SystemInformation.COPYRIGHT));
        setChild(SystemInformation.CONTACT, (Item) getCategory(SystemInformation.CONTACT));
        setChild(SystemInformation.DESCRIPTION, (Item) getCategory(SystemInformation.DESCRIPTION));
        setChild(SystemInformation.AUTHORS, (Item) getCategory(SystemInformation.AUTHORS));
        setChild(SystemInformation.HELPERS, (Item) getCategory(SystemInformation.HELPERS));
        setChild(SystemInformation.INSPIRATIONS, (Item) getCategory(SystemInformation.INSPIRATIONS));
        setChild(SystemInformation.LICENSE, (Item) getCategory(SystemInformation.LICENSE));
    }

    /**
     * Finalizes this item.
     */
    public void finalizz() throws Exception {

        Item license = getChild(SystemInformation.LICENSE);
        removeChild(SystemInformation.LICENSE);
        destroyChild(license);

        Item inspirations = getChild(SystemInformation.INSPIRATIONS);
        removeChild(SystemInformation.INSPIRATIONS);
        destroyChild(inspirations);

        Item helpers = getChild(SystemInformation.HELPERS);
        removeChild(SystemInformation.HELPERS);
        destroyChild(helpers);

        Item authors = getChild(SystemInformation.AUTHORS);
        removeChild(SystemInformation.AUTHORS);
        destroyChild(authors);

        Item description = getChild(SystemInformation.DESCRIPTION);
        removeChild(SystemInformation.DESCRIPTION);
        destroyChild(description);

        Item contact = getChild(SystemInformation.CONTACT);
        removeChild(SystemInformation.CONTACT);
        destroyChild(contact);

        Item copyright = getChild(SystemInformation.COPYRIGHT);
        removeChild(SystemInformation.COPYRIGHT);
        destroyChild(copyright);

        Item logo = getChild(SystemInformation.LOGO);
        removeChild(SystemInformation.LOGO);
        destroyChild(logo);

        Item slogan = getChild(SystemInformation.SLOGAN);
        removeChild(SystemInformation.SLOGAN);
        destroyChild(slogan);

        Item date = getChild(SystemInformation.DATE);
        removeChild(SystemInformation.DATE);
        destroyChild(date);

        Item version = getChild(SystemInformation.VERSION);
        removeChild(SystemInformation.VERSION);
        destroyChild(version);

        Item name = getChild(SystemInformation.NAME);
        removeChild(SystemInformation.NAME);
        destroyChild(name);

        super.finalizz();
    }
}

