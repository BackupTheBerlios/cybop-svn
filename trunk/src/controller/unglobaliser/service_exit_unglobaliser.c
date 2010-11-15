/*
 * Copyright (C) 1999-2010. Christian Heller.
 *
 * This file is part of the Cybernetics Oriented Interpreter (CYBOI).
 *
 * CYBOI is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * CYBOI is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with CYBOI.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Cybernetics Oriented Programming (CYBOP) <http://www.cybop.org>
 * Christian Heller <christian.heller@tuxtax.de>
 *
 * @version $RCSfile: globaliser.c,v $ $Revision: 1.13 $ $Date: 2009-01-31 16:06:30 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef SERVICE_EXIT_UNGLOBALISER_SOURCE
#define SERVICE_EXIT_UNGLOBALISER_SOURCE

#include <stdlib.h>

/**
 * Deallocates service exit global variables.
 */
void unglobalise_service_exit() {

    // Free cyboi service thread exit flag.
    free((void*) CYBOI_SERVICE_EXIT);

    // Free gnu/linux console thread exit flag.
    free((void*) GNU_LINUX_CONSOLE_EXIT);

    // Free www service thread exit flag.
    free((void*) WWW_SERVICE_EXIT);

    // Free x window system thread exit flag.
    free((void*) X_WINDOW_SYSTEM_EXIT);
}

/* SERVICE_EXIT_UNGLOBALISER_SOURCE */
#endif
