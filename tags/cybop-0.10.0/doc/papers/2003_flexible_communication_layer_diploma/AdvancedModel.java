/*
 * $RCSfile: AdvancedModel.java,v $
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

import org.resmedicinae.application.healthcare.reform.xml.LoadedPatients;
import org.resmedicinae.application.healthcare.reform.xml.Patient;
import org.resmedicinae.application.healthcare.reform.xml.PatientIndex;
import org.resmedicinae.resmedlib.component.configuration.ConfigurationManager;
import org.resmedicinae.resmedlib.region.Model;

/**
 * This class represents a model.
 *
 * It is the super class of the model level classes in the framework's ontology:<br>
 *  <ul>
 *      <li>Network</li>
 *      <li>Family</li>
 *      <li>System</li>
 *      <li>Block</li>
 *      <li>Region (History/Record)</li>
 *      <li>Component (Unit)</li>
 *      <li>Part (Heading)</li>
 *      <li>Chain (Combination/Description)</li>
 *      <li>Term (Principle)</li>
 *      <li>Sign</li>
 *      <li>Number</li>
 *      <li>Digit</li>
 *  </ul>
 *
 * @version $Revision: 1.1 $ $Date: 2003-03-06 23:39:46 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class AdvancedModel extends Model
{
    public static String MODEL_KEY = "ADVANCED_MODEL_KEY";
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

    public Patient loadPatient(String patientId)
    {
        return new Patient();
    }

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

