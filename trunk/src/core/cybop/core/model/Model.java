/*
 * $RCSfile: Model.java,v $
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

package cybop.core.model;

import cybop.core.basic.String;

/**
 * This class represents a model.
 *
 * Synonyms for <i>model</i> are <i>protocol</i> or <i>language</i>,
 * i.e. everything that defines a structure for how systems exchange data.
 *
 * @version $Revision: 1.3 $ $Date: 2003-02-20 15:35:14 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class Model extends cybop.core.system.Component {
    
    //?? Only temporary inheritance from Component!
    //?? The gui components need a signal handler which is set in the
    //?? globalize method of Component.
    //?? Remove this inheritance (replace with Item parent class),
    //?? as soon as no signal handler has to be forwarded anymore
    //?? (when CYBOP provides mouse/keyboard input handling itselfs.
}

