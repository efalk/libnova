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

#ifndef _LN_PRECESSION_H
#define _LN_PRECESSION_H

#include <libnova/ln_types.h>

#ifdef __cplusplus
extern "C" {
#endif

/*! \defgroup precession Precession
* \brief functions related to the precession of the Earth's rotational axis
*
* Precession is the changing direction of the Earth's rotational axis over time and
* is due to the gravitational influence of the Sun and the Moon.
*
* Many measurements are made relative to the vernal equinox, AKA The
* First Point of Aries, which is the point where the ecliptic intersects
* the equator.  This point drifts constantly east due to precession.
* A full circle takes approximately 26,000 years.  The North pole is
* currently moving towards Polaris, and should be within 28 minutes
* about the year 2102.  Vega should become the pole star around the
* year 14000.
*
* The First Point of Aries was once in the constellation Aries, but
* hasn't been there in a very long time.
*
* All angles are expressed in degrees.
*/

/*! \fn void ln_get_equ_prec(struct ln_equ_posn *mean_position, double JD, struct ln_equ_posn *position);
* \brief Calculate the effects of precession on equatorial coordinates, convert J2000 to current.
* \ingroup precession
*/

/* Equ 20.2, 20.3, 20.4 pg 126 */
void LIBNOVA_EXPORT ln_get_equ_prec(struct ln_equ_posn *mean_position,
	double JD, struct ln_equ_posn *position);

/*! \fn void ln_get_equ_prec2(struct ln_equ_posn *mean_position, double fromJD, double toJD, struct ln_equ_posn *position);
* \brief Calculate the effects of precession on equatorial coordinates, between arbitary Jxxxx epochs.
* \ingroup precession
*/

/* Equ 20.2, 20.3, 20.4 pg 126 */
void LIBNOVA_EXPORT ln_get_equ_prec2(struct ln_equ_posn *mean_position,
	double fromJD, double toJD, struct ln_equ_posn *position);

/*! \fn void ln_get_ecl_prec(struct ln_lnlat_posn *mean_position, double JD, struct ln_lnlat_posn *position); 
* \brief Calculate the effects of precession on ecliptical coordinates.
* \ingroup precession
*/
/* Equ 20.5, 20.6 pg 128 */
void LIBNOVA_EXPORT ln_get_ecl_prec(struct ln_lnlat_posn *mean_position,
	double JD, struct ln_lnlat_posn *position);

#ifdef __cplusplus
};
#endif

#endif
