/*
 * $RCSfile: Cave.java,v $
 *
 * Copyright (c) 1999-2002. Jens Bohl. All rights reserved.
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
package org.resmedicinae.domain.healthcare.description;

import org.resmedicinae.domain.healthcare.Description;

public class Cave extends Description{
    protected org.resmedicinae.resmedlib.term.String name;

    protected org.resmedicinae.resmedlib.term.String timestamp;

    protected org.resmedicinae.resmedlib.term.String description;

    public org.resmedicinae.resmedlib.term.String getName() {
        return name;
    }

    public void setName(org.resmedicinae.resmedlib.term.String name) {
        this.name = name;
    }

    public org.resmedicinae.resmedlib.term.String getDescription() {
        return description;
    }

    public void setDescription(org.resmedicinae.resmedlib.term.String description) {
        this.description = description;
    }

    public org.resmedicinae.resmedlib.term.String getTimestamp() {
        return timestamp;
    }

    public void setTimestamp(org.resmedicinae.resmedlib.term.String timestamp) {
        this.timestamp = timestamp;
    }
}
