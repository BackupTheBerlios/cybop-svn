/*
 * $RCSfile: AdvancedAssembler.java,v $
 *
 * Copyright (c) 1999-2002. Christian Heller. All rights reserved.
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

package org.resmedicinae.application.healthcare.reform.region;

import org.resmedicinae.resmedlib.region.Assembler;
import org.resmedicinae.resmedlib.component.configuration.ConfigurationManager;
import org.resmedicinae.application.healthcare.reform.xml.Patient;
import org.resmedicinae.application.healthcare.reform.xml.PatientIndex;
import org.resmedicinae.application.healthcare.reform.xml.LoadedPatients;

/**
 * This class represents an assembler.<br><br>
 *
 * An assembler is responsible for 'translating' one model into another.
 * The <code>DomainModel</code> is considered the actual original from/to
 * where other models can be assembled/disassembled.<br><br>
 * Possible assemblers include:
 *  <ul>
 *      <li>ViewModelAssembler</li>
 *      <li>ExtendedMarkupLanguageModelAssembler</li>
 *      <li>EntityRelationshipModelAssembler</li>
 *      <li>DataTransferModelAssembler</li>
 *  </ul>
 *
 * @version $Revision: 1.1 $ $Date: 2003-03-06 23:39:46 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class AdvancedAssembler extends Assembler
{
    public static String ASSEMBLER_KEY = "ADVANCED_ASSEMBLER_KEY";
    protected ConfigurationManager configurationManager = null;

    public void initialize() throws Exception
    {
        try
        {
            super.initialize();
        }
        catch (Exception e)
        {
            throw new Exception(e);
        }
    }
    public void importPatient()
    {
    }

    public void importPatientDirectory()
    {
    }

    public void saveDataAs()
    {
    }

    public void loadPatientIndex()
    {
    }

    public void savePatientIndex(PatientIndex patientIndex)
    {
    }
/*
    public Patient loadPatient(String patientId)
    {
        return new Patient();
    }
*/
    public void savePatient(Patient patient)
    {
    }

    public void saveAllPatients(LoadedPatients loadedPatients)
    {
    }

    public void removePatient(String patientId)
    {
    }
}

