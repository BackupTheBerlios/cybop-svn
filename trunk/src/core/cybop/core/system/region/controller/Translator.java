/*
 * $RCSfile: Translator.java,v $
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

package cybop.core.system.region.controller;

import cybop.core.model.String;
import cybop.core.model.*;
import cybop.core.model.model.*;
import cybop.core.system.region.*;

/**
 * This class represents a translator.
 *
 * It can be used to translate models.
 * A domain model may be translated into another kind of data model (encoding)
 * and vice versa (decoding).
 *
 * An encoder corresponds to the motoric nerve system of a human being.
 * For example, the brain center for muscle control encodes abstract domain model data
 * of our brain into a specific data model controlling a muscle reaction.
 *
 * A decoder corresponds to the sensoric nerve system of a human being.
 * For example, the brain region for seeing decodes optical data into the
 * proper abstract domain model of our brain.
 *
 * Synonyms: Assembler, Mapper, Sensor, Motor, Encoder, Decoder 
 *
 * @version $Revision: 1.6 $ $Date: 2003-05-20 06:21:59 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class Translator extends ControllerRegion {

    //
    // Children names.
    //

    /** The formatter. */
    private java.util.logging.Formatter formatter;

    /** The output stream. */
    private java.io.OutputStream outputStream;

    /** The writer. */
    private java.io.Writer writer;

    //
    // Formatter.
    //

    /**
     * Creates a formatter.
     *
     * @return the formatter
     * @exception Exception if the formatter is null
     */
    public java.util.logging.Formatter createFormatter() throws Exception {

        java.util.logging.Formatter f = new java.util.logging.SimpleFormatter();

        if (f != null)
        {

//??            f.initialize();

        }
        else
        {

            throw new Exception("Could not create formatter. The formatter is null.");
        }

        return f;
    }

    /**
     * Destroys the formatter.
     *
     * @param f the formatter
     * @exception Exception if the formatter is null
     */
    public void destroyFormatter(java.util.logging.Formatter f) throws Exception
    {

        if (f != null)
        {

//??            f.finalizz();

        }
        else
        {

            throw new Exception("Could not destroy formatter. The formatter is null.");
        }
    }

    /**
     * Sets the formatter.
     *
     * @param f the formatter
     */
    public void setFormatter(java.util.logging.Formatter f)
    {

        this.formatter = f;
    }

    /**
     * Returns the formatter.
     *
     * @return the formatter
     */
    public java.util.logging.Formatter getFormatter()
    {

        return this.formatter;
    }

    //
    // Output stream.
    //

    /**
     * Creates an output stream.
     *
     * @return the output stream
     * @exception Exception if the output stream is null
     */
    public java.io.OutputStream createOutputStream() throws Exception
    {

        java.io.OutputStream s = java.lang.System.err; //?? new java.io.OutputStream();

        if (s != null)
        {

//??            s.initialize();

        }
        else
        {

            throw new Exception("Could not create output stream. The output stream is null.");
        }

        return s;
    }

    /**
     * Destroys the output stream.
     *
     * @param s the output stream
     * @exception Exception if the output stream is null
     */
    public void destroyOutputStream(java.io.OutputStream s) throws Exception
    {

        if (s != null)
        {

//??            s.finalizz();

        }
        else
        {

            throw new Exception("Could not destroy output stream. The output stream is null.");
        }
    }

    /**
     * Sets the output stream.
     *
     * @param s the output stream
     */
    public void setOutputStream(java.io.OutputStream s)
    {

        this.outputStream = s;
    }

    /**
     * Returns the output stream.
     *
     * @return the output stream
     */
    public java.io.OutputStream getOutputStream()
    {

        return this.outputStream;
    }

    //
    // Writer.
    //

    /**
     * Creates a writer.
     *
     * @return the writer
     * @exception Exception if the writer is null
     */
    public java.io.Writer createWriter() throws Exception
    {

        java.io.Writer w = new java.io.OutputStreamWriter(getOutputStream());

        if (w != null)
        {

//??            w.initialize();

        }
        else
        {

            throw new Exception("Could not create writer. The writer is null.");
        }

        return w;
    }

    /**
     * Destroys the writer.
     *
     * @param w the writer
     * @exception Exception if the writer is null
     */
    public void destroyWriter(java.io.Writer w) throws Exception
    {

        if (w != null)
        {

//??            w.finalizz();

        }
        else
        {

            throw new Exception("Could not destroy writer. The writer is null.");
        }
    }

    /**
     * Sets the writer.
     *
     * @param w the writer
     */
    public void setWriter(java.io.Writer w)
    {

        this.writer = w;
    }

    /**
     * Returns the writer.
     *
     * @return the writer
     */
    public java.io.Writer getWriter()
    {

        return this.writer;
    }

    //
    // Initialization.
    //

    /**
     * Initializes this translator.
     */
    public void initialize() throws Exception {

        super.initialize();

        setFormatter(createFormatter());
        setOutputStream(createOutputStream());
        setWriter(createWriter());
    }

    /**
     * Finalizes this translator.
     */
    public void finalizz() throws Exception {

        java.io.Writer writer = getWriter();
        setWriter(null);
        destroyWriter(writer);

        java.io.OutputStream outputStream = getOutputStream();
        setOutputStream(null);
        destroyOutputStream(outputStream);

        java.util.logging.Formatter formatter = getFormatter();
        setFormatter(null);
        destroyFormatter(formatter);

        super.finalizz();
    }

    //
    // Encoding.
    //

    /**
     * Encodes the domain model.
     *
     * @param dm the domain model
     * @param m the encoded model
     */
    public void encode(DomainModel dm, Model m) {
    }

    //
    // Decoding.
    //
    
    /**
     * Decodes the model.
     *
     * @param m the encoded model
     * @param dm the domain model
     */
    public void decode(Model m, DomainModel dm) {
    }

    //
    // Driving the motoric process.
    //

    /**
     * Drives the log record output.
     *
     * @param r the log record
     * @exception Exception if the formatter is null
     * @exception Exception if the writer is null
     */
/*??
    public void drive(LogRecord r) throws Exception {

        java.util.logging.Formatter f = getFormatter();

        if (f != null) {

            String msg = "Empty test log message."; //?? f.format(r);
            java.io.Writer w = getWriter();

            if (w != null) {

//??                w.write(f.getHead(this));
                w.write(msg);
                w.flush();
                w.close();

            } else {

                throw new Exception("Could not drive log record output. The writer is null.");
            }
        
        } else {

            throw new Exception("Could not drive log record output. The formatter is null.");
        }
    }
*/
}

