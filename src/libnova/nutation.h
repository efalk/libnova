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

/* taken from table 21.A pg 133 */

#ifndef _LN_NUTATION_H
#define _LN_NUTATION_H

#include <libnova/ln_types.h>

#ifdef __cplusplus
extern "C" {
#endif

/*! \defgroup nutation Nutation
* \brief Functions related to nutation
*
* Nutation is a periodic oscillation of the Earths rotational axis around its
* mean position. Nutation is primarily caused by the Moon, and
* has an 18.6 year period.
*
* All angles are expressed in degrees.
*/

/*! \fn void ln_get_nutation(double JD, struct ln_nutation *nutation);
* \ingroup nutation
* \brief Calculate nutation. 
*/
void LIBNOVA_EXPORT ln_get_nutation(double JD, struct ln_nutation *nutation);

/*! \fn void ln_get_equ_nut(struct ln_equ_posn *mean_position, double JD, struct ln_equ_posn *position);
* \brief Calculate equatorial coordinates with the effects of nutation.
* \ingroup nutation
*/
void LIBNOVA_EXPORT ln_get_equ_nut(const struct ln_equ_posn *mean_position, double JD, struct ln_equ_posn *position);
	
#ifdef __cplusplus
};
#endif

#endif
