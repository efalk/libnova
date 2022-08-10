/*
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 *  
 *  Copyright (C) 2000 - 2005 Liam Girdwood  
 */

#ifndef _LN_DYNAMICAL_TIME_H
#define _LN_DYNAMICAL_TIME_H

#include <libnova/ln_types.h>

#ifdef __cplusplus
extern "C" {
#endif

/*!
* \defgroup dynamical Dynamical Time
* \brief Conversions related to dynamical time
*
* **Dynamical time** is the time defined by atomic clocks. It differs from
* universal time, which is defined by the mean rotation of the Earth, which
* can vary. Dynamical time is very steady.
*
* **Barycentric dynamical time**: the dynamnical time at the barycenter of the
* solar system.
*
* **Terrestrial dynamical time**: the dynamical time at the Earth.
* This can vary from barycentric dynamical time by as much as 0.0017
* second due to relatavistic effects of the Earth's orbit.
*
* The difference between these two dynamical times is so small that libnova
* does not distinguish them.
*
* `ln_get_dynamical_time_diff()` returns the difference between Universal
* Time and Dynamical Time for a given date.
*
* `ln_get_jde()` returns the dynamical time for a given date.
*/

/*! \fn double ln_get_dynamical_time_diff(double JD)
* \ingroup dynamical
* \brief Calculate approximate dynamical time difference from Julian day in seconds
*/
double LIBNOVA_EXPORT ln_get_dynamical_time_diff(double JD);

/*! \fn double ln_get_jde(double JD)
* \brief Calculate Julian ephemeris day(JDE)
* \ingroup dynamical 
*/
double LIBNOVA_EXPORT ln_get_jde(double JD);
	
#ifdef __cplusplus
};
#endif

#endif
